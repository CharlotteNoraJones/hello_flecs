#include <stdio.h>

#include "flecs.h"

int main()
{
    flecs::world world;

    flecs::entity e = world.entity("Bob");

    printf("Entity Name: %s\n", e.name().c_str());

    flecs::entity bobAgain = world.lookup("Bob");

    printf("Another bob's Name: %s\n", bobAgain.name().c_str());
}
