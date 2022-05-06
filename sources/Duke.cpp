#include "Duke.hpp"
using namespace std;
const short MAX_COINS = 10;
namespace coup{

    Duke::Duke(Game& g, const string & name):Player(g,name, "Duke"){

    }

    void Duke:: tax(){
        if(this->coin>=MAX_COINS){
            throw invalid_argument("you must coup");
        }
        if(g->playing.size()==1){
            throw invalid_argument("you cant play by yourself");
        }
        g->is_started = true;
        g->myTurn(*this);
        this->coin = this->coin+3;
        this->last_action = "tax";
        g->nextTurn();
    }    
    
    void Duke:: block(Player & p){
        if(!p.isAlive){
            throw invalid_argument("The player already couped");
        }
        if(p.last_action != "foreign aid"){
            throw invalid_argument("you can block only steal");
        }
        p.coin -=2;
    }

}