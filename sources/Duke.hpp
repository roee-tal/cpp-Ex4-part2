#include "Player.hpp"

namespace coup{

    class Duke: public Player{
        public:
            Duke(Game& g, const std::string & name);
            static void block(Player & p);
            void tax();
    };
}
