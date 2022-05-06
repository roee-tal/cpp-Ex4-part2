#include "Ambassador.hpp"
using namespace std;
const short MAX_COINS = 10;
namespace coup{

    Ambassador::Ambassador(Game& g, const string & name):Player(g,name, "Ambassador"){

    }

    void Ambassador:: transfer(Player& p1, Player& p2){
        if(this->coin>=MAX_COINS){
            throw invalid_argument("you must coup");
        }
        g->myTurn(*this);
        if(!p1.isAlive || !p2.isAlive ){
            throw invalid_argument("The player already couped");
        }
        if(p1.coin < 1){
            throw invalid_argument("p1 has no money");
        }
        p1.coin--;
        p2.coin++;
        this->last_action = "transfer";
        g->nextTurn();
    }

    void Ambassador::block(Player &p){
        if(p.p_role!="Captain"){
            throw invalid_argument("you can block only captain");
        }
        if(p.last_action!="steal"){
            throw invalid_argument("you can block only steal");
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