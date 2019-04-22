/*
 * Cameron Mims
 * Personal Project - Blackjack
 * Date(Started): 4/22/19
 */

#include <iostream>
#include <array>
#include <random>
using namespace std;

void game_loop(); //Function prototype for game_loop()

//Enumeration for Card Suit
enum Suit{
    SUIT_CLUB,
    SUIT_SPADE,
    SUIT_DIAMOND,
    SUIT_HEART,
    MAX_SUIT
};

//Enumeration for Card Rank
enum Rank{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANK
};

/**
 * Card Class
 * Class that represents and acts as a Card
 */
class Card{
private:
    char rank;
    string suit;
    int value;
public:
    Card() = default; //default constructor

    /**
     * Card Constructor
     * @param card_rank
     * @param card_suit
     * @param card_value
     */
    Card(char card_rank, string card_suit, int card_value){
        rank = card_rank;
        suit = card_suit;
        value = card_value;
    }
    /**
     * Getter method for Card Rank
     * @return rank(char)
     */
    char get_rank(){
        return rank;
    }
    /**
     * Getter method for Card Suit
     * @return suit(string)
     */
    string get_suit(){
        return suit;
    }
    /**
     * Getter method for Card Value
     * @return value(int)
     */
    int get_value(){
        return value;
    }
    /**
     * Setter method for Card Rank
     * @param s_card_rank
     */
    void set_rank(char s_card_rank){
        rank = s_card_rank;
    }
    /**
     * Setter method for Card Suit
     * @param s_card_suit
     */
    void set_suit(string s_card_suit){
        suit = s_card_suit;
    }
    /**
     * Setter method for Card Value
     * @param s_card_value
     */
    void set_value(int s_card_value){
        value = s_card_value;
    }
    /**
     * Card to_string
     */
    void to_string(){
        cout << rank << "-" << suit << endl;
    }
};

/**
 * Deck Class
 * Class the represents and acts as a deck
 * Contains Card objects
 */
class Deck{
private:
    array<Card, 52> deck_cards; //array to hold Card objects
public:
    Deck() = default; //Default constructor
    /**
     * Deck Constructor
     * @param card_deck
     */
    Deck(const array<Card, 52> &card_deck){
        deck_cards = card_deck;
    }
    /**
     * Method that shuffles the contents(Cards) in the Deck
     */
    void shuffle_deck(){
        random_device shuffle_rd;
        mt19937 shuffle_eng(shuffle_rd());
        uniform_int_distribution<> shuffle_distr(0, 52);
        int ran_num = shuffle_distr(shuffle_eng);

        for(int i = 0; i < deck_cards.size(); i++){
            swap(deck_cards[i], deck_cards[ran_num]);
            ran_num = shuffle_distr(shuffle_eng);
        }
    }
    /**
     * Method that picks a random card from the deck and returns it
     * @return Card
     */
    Card deal_card(){
        random_device shuffle_rd;
        mt19937 shuffle_eng(shuffle_rd());
        uniform_int_distribution<> shuffle_distr(0, 52);
        int ran_num = shuffle_distr(shuffle_eng);

        return deck_cards[ran_num];
    }
    /**
     * Method that deals a hand(3 cards) and returns it
     * @return vector
     */
    vector<Card> deal_hand(){
        random_device shuffle_rd;
        mt19937 shuffle_eng(shuffle_rd());
        uniform_int_distribution<> shuffle_distr(0, 52);
        int ran_num = shuffle_distr(shuffle_eng);

        vector<Card> deal_hand;
        for(int i = 0; i < 3; i++){
            deal_hand.push_back(deck_cards[ran_num]);
            ran_num = shuffle_distr(shuffle_eng);
        }
        return deal_hand;
    }
    /**
     * Deck to_string
     */
    void to_string(){
        for(int i = 0; i < deck_cards.size(); i++){
            cout << deck_cards[i].get_rank() << "-" << deck_cards[i].get_suit() << "-" << deck_cards[i].get_value() << endl;
            //cout << deck_cards[i].get_rank() << endl;
        }
    }
};

/**
 * Player Class
 * Class that represents any sort of "Player"
 */
class Player{
private:
    //array<Card, 3> hand;
    vector<Card> hand; //Player hand(vector) of Cards
public:
    Player() = default; //Default Constructor
    /**
     * Player Contructor
     * @param set_hand
     */
    Player(vector<Card> set_hand){
        hand = set_hand;
    }
    /**
     * Method that returns the current value of the Player's hand
     * @return sum(int)
     */
    int get_hand_value(){
        int sum = 0;
        for(int i = 0; i < hand.size(); i++){
            sum += hand.at(i).get_value();
        }
        return sum;
    }
    /**
     * Getter Method that returns the current player's hand
     * @return vector
     */
    vector<Card> get_hand(){
        return hand;
    }
    /**
     * Setter Method that sets the hand of the Player
     * @param hand_set
     */
    void set_hand(vector<Card> hand_set){
        hand = hand_set;
    }
    /**
     * Method that adds a Card to the current Player's hand
     * @param card_hit
     */
    void add_to_hand(Card card_hit){
        hand.push_back(card_hit);
    }
    /**
     * Method that Checks(or to_string) that current hand of the Player
     */
    void check_hand(){
        for(int i = 0; i < hand.size(); i++){
            cout << hand.at(i).get_rank() << "-" << hand.at(i).get_suit() << "-" << hand.at(i).get_value() << endl;
        }
    }
};

/**
 * Helper? Method that returns a Card Suit(string) from being enumerated
 * @param card_suit
 * @return suit(string)
 */
string assign_suit(Suit card_suit){
    switch (card_suit){
        case SUIT_CLUB: return "Club";
        case SUIT_DIAMOND: return "Diamond";
        case SUIT_HEART: return "Heart";
        case SUIT_SPADE: return "Spade";
    }
}

/**
 * Helper? Method that returns a Card Rank(char) from being enumerated
 * @param card_rank
 * @return
 */
char assign_rank(Rank card_rank){
    switch (card_rank){
        case RANK_2: return '2';
        case RANK_3: return '3';
        case RANK_4: return '4';
        case RANK_5: return '5';
        case RANK_6: return '6';
        case RANK_7: return '7';
        case RANK_8: return '8';
        case RANK_9: return '9';
        case RANK_10: return 'T';
        case RANK_JACK: return 'J';
        case RANK_QUEEN: return 'Q';
        case RANK_KING: return 'K';
        case RANK_ACE: return 'A';
    }
}

/**
 * Helper? Method that returns a Card Rank(int) from being enumerated
 * @param card_rank
 * @return
 */
int assign_value(Rank card_rank){
    switch (card_rank){
        case RANK_2: return 2;
        case RANK_3: return 3;
        case RANK_4: return 4;
        case RANK_5: return 5;
        case RANK_6: return 6;
        case RANK_7: return 7;
        case RANK_8: return 8;
        case RANK_9: return 9;
        case RANK_10: return 10;
        case RANK_JACK: return 10;
        case RANK_QUEEN: return 10;
        case RANK_KING: return 10;
        case RANK_ACE: return 11;
    }
}

/**
 * Method that implements the deck
 * @return array<Card>
 */
array<Card, 52> implement_deck(){
    Suit SUIT_MAX = MAX_SUIT;
    Rank RANK_MAX = MAX_RANK;
    array<Card, 52> deck;
    int deck_index = 0;

    for(int i = 0; i < SUIT_MAX; i++){
        Suit incr_suit = (Suit)i;
        for(int j = 0; j < RANK_MAX; j++){
            Rank incr_rank = (Rank)j;
            Card card = {assign_rank(incr_rank), assign_suit(incr_suit), assign_value(incr_rank)};
            //card.to_string();
            deck[deck_index] = card;
            deck_index++;
        }
    }
    return deck;
}

int RUNNING = 1; //While loop controller

/**
 * Method to break or re-establish game loop
 */
void play_again(){
    string command;
    cout << "Would you like to play again? ";
    cin >> command;

    if(command == "YES"){
        game_loop();
    }
    if(command == "NO"){
        cout << "Exiting Blackjack...." << endl;
        cout << "Thank you for playing!" << endl;
        RUNNING = 0;
    }
}

/**
 * Game Loop
 */
void game_loop(){
    cout << "Welcome to Blackjack" << endl;
    array<Card,52> impl_card_deck = implement_deck();
    Deck card_deck {impl_card_deck};
    card_deck.shuffle_deck();
    card_deck.shuffle_deck();

    cout <<"Dealing hands...." << endl;
    Player player {card_deck.deal_hand()};
    Player dealer {card_deck.deal_hand()};

    while(RUNNING){
        string command;
        cout << "Would you like to HIT, STAND, CHECK(hand) ? (Please type in command): ";
        cin >> command;

        if(command == "HIT"){
            player.add_to_hand(card_deck.deal_card());
        }
        if(command == "STAND"){
            cout << "Checking hand with dealer...." << endl;
            if(player.get_hand_value() == 21 && dealer.get_hand_value() == 21){
                cout << "Both player and dealer stand at 21. TIE GAME" << endl;
                play_again();
                break;
            }
            if(player.get_hand_value() != 21 && dealer.get_hand_value() == 21){
                cout << "Dealer's hand equals to 21, player's does not. YOU WIN!" << endl;
                play_again();
                break;
            }
            if(player.get_hand_value() == 21 && dealer.get_hand_value() != 21){
                cout << "Player's hand equals to 21, dealer's does not. YOU WIN!" << endl;
                play_again();
                break;
            }
            if(player.get_hand_value() > 21 && dealer.get_hand_value() < 21){
                cout << "Dealer's hand is below 21, player went above 21. YOU LOSE" << endl;
                play_again();
                break;
            }
            if(player.get_hand_value() < 21 && dealer.get_hand_value() > 21){
                cout << "Player's hand is below 21, dealer went above 21. YOU WIN!" << endl;
                play_again();
                break;
            }
            if(player.get_hand_value() < 21 && dealer.get_hand_value() < 21){
                cout << "Both Dealer and Player's hands were below than 21...." << endl;
                if(dealer.get_hand_value() > player.get_hand_value()){
                    cout << "Dealer's hand is greater than your's, YOU LOSE" << endl;
                    play_again();
                    break;
                }
                if(player.get_hand_value() > dealer.get_hand_value()){
                    cout << "Player's hand is greater than dealers, YOU WIN!" << endl;
                    play_again();
                    break;
                }
            }
            if(player.get_hand_value() > 21 && dealer.get_hand_value() > 21){
                cout << "Both Dealer and Player's hands were greater than 21...." << endl;
                if(dealer.get_hand_value() > player.get_hand_value()){
                    cout << "Dealer's hand is greater than your's, YOU LOSE" << endl;
                    play_again();
                    break;
                }
                if(player.get_hand_value() > dealer.get_hand_value()){
                    cout << "Player's hand is greater than dealers, YOU WIN!" << endl;
                    play_again();
                    break;
                }
            }
        }
        if(command == "CHECK"){
            string sub_command;

            //Check if Player's hand contains an ACE
            vector<Card> player_hand = player.get_hand();
            for(int i = 0; i < player_hand.size(); i++){
                if(player_hand.at(i).get_rank() == 'A'){
                    cout << "You have an ace, would you like this to count as 1 or 11? ";
                    cin >> sub_command;


                    if(sub_command == "1"){
                        cout << "Setting 1 as ACE value" << endl;
                        player_hand.at(i).set_value(1);
                        player_hand.at(i).set_rank('*'); //Change the rank value so the if does not repeat
                        player.set_hand(player_hand);
                    }
                    else if(sub_command == "11"){
                        cout << "Setting 11 as ACE value" << endl;
                        player_hand.at(i).set_value(11);
                        player_hand.at(i).set_rank('*'); //Change the rank value so the if does not repeat
                        player.set_hand(player_hand);
                    }
                    else{
                        cout << "!This is an invalid number!" << endl;
                    }
                }
            }
            player.check_hand();
            cout << "Hand value: " << player.get_hand_value() << endl;
        }
    }
}

int main() {
    game_loop();
    return 0;
}