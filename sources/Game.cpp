#include "Game.hpp"
using namespace std;

namespace coup{

    Game::Game(){
        this->t = 0;
        this->is_started = false;
    }

    vector<string> Game:: players(){
        vector<string>names;
        for(Player *p:playing){
            if(p->isAlive){
                names.push_back(p->name);
            }
        }
        // return this->playing;
        return names;
    }

    string Game::turn(){
        return this->playing.at(t)->name;
    }

    string Game::winner(){
        if(!is_game_over()){
            throw invalid_argument("The game isnt over yet");
        }
        if(!is_started){
            throw invalid_argument("The game isnt begin");
        }
        for(Player *p:playing){
            if(p->isAlive){
                return p->name;
            }
        }
        return "sad";
    }

    void Game::myTurn(Player& p){
        if((p.name)!=(this->turn())){
            throw invalid_argument("This is not your turn");
        }
    }

    bool Game::is_game_over(){
        int counter = 0;
        for(Player *p:playing){
            if(p->isAlive){
                counter++;
            }
        }
         return counter ==1;
    }

     void Game::nextTurn(){
        // bool over = is_game_over();
        this->t = (this->t +1)%this->playing.size();
        if (!this->playing.at((unsigned long)t)->isAlive) {
            nextTurn();
            return;
        }
     }

    //  void Game::killPlayer(Player & p){
    //     for(int i=0;i<this->playing.size();i++){
    //         if((p.name) == (this->playing.at((unsigned long)(i))->name)){
    //             this->playing.erase(this->playing.begin()+i);
    //             break;
    //         }
    //     }
    // }
    //  void Game::add_Player(Player &p,int pos){
    //     //  this->playing.insert(this->playing.begin()+pos, p);
    //      auto itPos =  this->playing.begin() + this->pos;
    //     // Insert element with value 9 at 4th Position in vector
    //     auto newIt = this->playing.insert(itPos, &p);
    //     p.action_on_p = nullptr;
    
    //  }
}