#include "header.hpp"
#include <vector>
#include <list>
#include "SheepConfigs.hpp"
#include "live.hpp"
class Player{
    private:
        vector<Sheeps> sheeps;
        vector<Sheeps> sheeps_ready_to_attack;
        int type_player = 1;
        live my_live;

    public:
    Player(float x, int color);
    void add_sheeps(Sheeps sheep);
    void set_type_player(int x);
    void set_list_sheeps();
    void update_list_sheeps();
    void draw(RenderWindow &window);
};