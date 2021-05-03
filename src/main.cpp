
#include "../inc/world.h"

using namespace std;

int main()
{
    World *world = new World();
    while(world->IsOpen())
        world->Redraw();
    delete world;
    return 0;
}
