#include "Player.hpp"
using namespace std;

const short INIT_COINS = 0;
const short MAX_COINS = 10;
const short COUP_PRICE = 7;
const short MAX_PLAYERS = 6;

namespace coup{

    Player::Player(Game& g, const string & name, string p_role):g(&g),name(name){
        if(this->g->playing.size()==MAX_PLAYERS){
            throw invalid_argument("This game is only for 6 people");
        }
        if(g.is_started){
            throw invalid_argument("This game already started, you cant join");
        }
        this->g->playing.push_back(this);
        this->p_role = std::move(p_role);
        this->coin = 0;
        this->isAlive = true;
        this->action_on_p = nullptr;
        this->stolenP = nullptr;
    }

    void Player:: income(){
        g->myTurn(*this);
        if(this->coin>=MAX_COINS){
            throw invalid_argument("you must coup");
        }
        if(g->playing.size()==1){
            throw invalid_argument("you cant play by yourself");
        }
        g->is_started = true;
        this->coin++;
        this->last_action = "income";
        g->nextTurn();
    }  

    void Player:: foreign_aid(){
        g->myTurn(*this);
        if(this->coin>=MAX_COINS){
            throw invalid_argument("you must coup");
        }
        if(g->playing.size()==1){
            throw invalid_argument("you cant play by yourself");
        }
        g->is_started = true;
        this->coin = this->coin+2;
        this->last_action = "foreign aid";
        g->nextTurn();
    }   
    
    void Player:: coup(Player & p){
        g->myTurn(*this);
        if(!p.isAlive){
            throw invalid_argument("The player already couped");
        }
        if(this->coin < COUP_PRICE){
            throw invalid_argument("you must have at least 7 coins");
        }
        this->coin -=COUP_PRICE;
        this->last_action = "killed";
        // g->killPlayer(p);
        p.isAlive = false;
        g->nextTurn();
    }
    int Player:: coins()const{
        return this->coin;
    }
    string Player:: role()const{
        return this->p_role;
    }

    
}