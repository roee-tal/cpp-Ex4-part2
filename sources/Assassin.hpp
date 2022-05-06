#include "Player.hpp"

namespace coup{

    class Assassin: public Player{
        public:
            Assassin(Game& g, const std::string & name);
            void coup(Player & p) override;
            // int find_pos(Player & p);
    };
}