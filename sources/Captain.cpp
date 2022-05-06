#include "Captain.hpp"
using namespace std;
const short MAX_COINS = 10;
namespace coup{

    Captain::Captain(Game& g, const string & name):Player(g,name, "Captain"){

    }
    void Captain:: steal(Player& p){
        g->myTurn(*this);
        if(this->coin>= MAX_COINS){
            throw invalid_argument("you must coup");
        }
        if(!p.isAlive){
            throw invalid_argument("The player already couped");
        }
        if(p.coin <1){
            throw invalid_argument("he dont have money at all!");
        }
        if(p.coin == 1){
            this->coin = this->coin +1;
            p.coin = p.coin - 1;
            this->stolenP = &p;
        }
        else{
            this->coin = this->coin +2;
            p.coin = p.coin - 2;
            this->stolenP = &p;
        }
        g->nextTurn();
        this->last_action = "steal";
    }    
    
    void Captain:: block(Player& p){
        if(p.p_role!="Captain"){
            throw invalid_argument("you can block only captain");
        }
        if(p.last_action!="steal"){
            throw invalid_argument("you can block only steal");
        }
        if(p.stolenP == nullptr){
            throw invalid_argument("no one to block");
        }
        if(!p.isAlive){
            throw invalid_argument("The player already couped");
        }
        p.coin -=2;
        p.stolenP->coin+=2;
        this->last_action = "block";
        p.stolenP = nullptr;
    }
}