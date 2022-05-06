#include "Player.hpp"
#include "vector"
#include <string>
#include <stdexcept>
#ifndef MY_SYMBOL_HH 
#define MY_SYMBOL_HH 
// #pragma once
namespace coup{
    class Player;
    class Game{

        
        public:
        // std::vector<std::string> playing;
        std::vector<Player*> playing;
        unsigned int t;
        bool is_started;
            Game();
            std::vector<std::string> players();
            std::string turn();
            std::string winner(); 
            void myTurn(Player& p);
            void nextTurn();
            // void killPlayer(Player & p);
            // void add_Player(Player &p,int pos);
            bool is_game_over();
    };
}
#endif /* MY_SYMBOL_HH */ 
