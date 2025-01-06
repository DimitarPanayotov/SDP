#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;


struct Card {
    string suit; //Spades, Hearts, Diamonds, Clubs
    int rank; // 2 to 14

    Card(string s, int r) : suit(s), rank(r) {}

    void print() const {
        string rankStr;
        if(rank <= 10){
           rankStr = to_string(rank);
        }else if(rank == 11 ){
            rankStr = "Jack";
        }else if(rank == 12){
            rankStr = "Queen";
        }else if(rank == 13) {
            rankStr = "King";
        }else if(rank == 14){
            rankStr = "Ace";
        }
        cout<<rankStr<<" of "<<suit;
    }
};
int suitStrenght(const string& suit){
    if (suit == "Spades") return 4;
    if (suit == "Hearts") return 3;
    if (suit == "Diamonds") return 2;
    if (suit == "Clubs") return 1;
    return 0;
}
bool compareCards(const Card& a, const Card& b){
    if(a.rank != b.rank){
        return a.rank > b.rank; //returns TRUE if the first card is stronger than the second
    }
    return suitStrenght(a.suit) > suitStrenght(b.suit);
}

//initializing a deck
vector<Card> initializeDeck() {
    vector<Card> deck;
    vector<string> suits = {"Spades", "Hearts", "Diamonds", "Clubs"};
    for(const string& suit : suits) {
        for(int rank = 2; rank <= 14; ++rank){
            deck.emplace_back(suit, rank);
        }
    }
    return deck;
}

int main() {
    srand(time(0));

    vector<Card> deck = initializeDeck();
    random_shuffle(deck.begin(), deck.end());

    queue<Card> player1, player2;

    for(size_t i=0; i < deck.size(); ++i){
        if(i < deck.size()/2){
            player1.push(deck[i]);
        }else {
            player2.push(deck[i]);
        }
    }
    int round = 0;
    const int MAX_ROUNDS = 50;
    while(!player1.empty() && !player2.empty() && round <= MAX_ROUNDS) {
        ++round;
        Card card1 = player1.front();
        Card card2 = player2.front();
        player1.pop();
        player2.pop();

        cout << "Round " << round << endl;
        cout << "Player 1 plays: ";
        card1.print();
        cout << endl;
        cout << "Player 2 plays: ";
        card2.print();
        cout << endl;

        if (compareCards(card1, card2)) {
            cout << "Player 1 wins the round!" << endl;
            player1.push(card1);
            player1.push(card2);
        } else if (compareCards(card2, card1)) {
            cout << "Player 2 wins the round!" << endl;
            player2.push(card1);
            player2.push(card2);
        } else {
            cout << "TIE! Cards are discarded!";
        }
    }

    if(player1.empty()) {
        cout << "Player 2 wins the game!" <<endl;
    }else if(player2.empty()){
        cout << "Player 1 wins the game!" <<endl;
    } else {
        cout << "The game ends in a tie after "<<MAX_ROUNDS<<" rounds"<<endl;
    }

    return 0;
}
