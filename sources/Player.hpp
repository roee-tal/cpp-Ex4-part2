#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#ifndef MY_SYMBOL_H 
#define MY_SYMBOL_H 
#include "Game.hpp"


// #pragma once

namespace coup{
    class Game;
    class Player{


        public:
            Game* g;
            std::string name;
            int coin;
            std::string p_role;
            std::string last_action;
            Player * action_on_p;
            Player * stolenP;
            bool isAlive;
            Player(Game& g, const std::string & name, std::string p_role);
            void income();
            void foreign_aid();
            virtual void coup(Player & p);
            std::string role() const;
            int coins()const;
           
    };
}
#endif /* MY_SYMBOL_H */ 
