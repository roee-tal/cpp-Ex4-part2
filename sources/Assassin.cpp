#include "Assassin.hpp"
using namespace std;
const short ASSASSIN_PRICE = 3;
const short COUP_PRICE = 7;
namespace coup{

    Assassin::Assassin(Game& g, const string & name):Player(g,name, "Assassin"){

    }
    void Assassin::coup(Player & p){
        g->myTurn(*this);
        if (this->coin < ASSASSIN_PRICE){
            throw invalid_argument("you must have at least 3 coins");
        }
        if(!p.isAlive){
            throw invalid_argument("The player already couped");
        }
        if (this->coin >= ASSASSIN_PRICE && this->coin < COUP_PRICE){
            this->coin -=ASSASSIN_PRICE;
            this->last_action = "assassined";
            this->action_on_p = &p;
            // this->g->pos = find_pos(p);
            // g->killPlayer(p);
            p.isAlive = false;
            g->nextTurn();
        }
        else{
            this->coin -=COUP_PRICE;
            this->last_action = "killed";
            // g->killPlayer(p);
            p.isAlive = false;
            g->nextTurn();
        }
        
    }

    // int Assassin::find_pos(Player & p){
    //     int ans;
    //     for(int i=0;i<this->g->playing.size();i++){
    //         if((p.name) == (this->g->playing.at((unsigned long)(i))->name)){
    //             ans = i;
    //         }
    //         }
    //     return ans;
    
    
    // }
}