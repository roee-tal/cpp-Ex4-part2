#include "Contessa.hpp"
using namespace std;
// const short MAX_COINS = 10;
namespace coup{

    Contessa::Contessa(Game& g, const string & name):Player(g,name, "Contessa"){
    }

    void Contessa:: block(Player& p){
        if(p.p_role != "Assassin"){
            throw invalid_argument("you can block only assassin");
        }
        if(p.last_action != "assassined"){
            throw invalid_argument("you can block only assassined player");
        }
        if(p.action_on_p == nullptr){
            throw invalid_argument("no one to block");
        }
        if(!p.isAlive){
            throw invalid_argument("The player already couped");
        }
        // this->g->add_Player(*p.action_on_p, this->g->pos);
        p.action_on_p->isAlive = true;
        p.action_on_p = nullptr;
    }

}