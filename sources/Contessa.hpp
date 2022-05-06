#include "Player.hpp"

namespace coup{

    class Contessa: public Player{
        public:
            Contessa(Game& g, const std::string & name);
            static void block(Player & p);
            
    };
}