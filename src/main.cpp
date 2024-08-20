#include <stdio.h>
#include <memory>

#include "flecs.h"
#include "raylib.h"

struct Velocity
{
    Vector2 velocity;
};

struct Position
{
    Vector2 position;
};

int main()
{
    flecs::world world;

    flecs::entity e = world.entity();

    e.add<Velocity>();

    e.set<Position>({.position{10, 20}})
        .set<Velocity>({.velocity{1, 2}});

    const std::reference_wrapper<const Position> p = std::ref(*e.get<Position>());

    printf("position: %f %f\n", p.get().position.x, p.get().position.y);

    e.remove<Position>();

    flecs::entity pos_e = world.entity<Position>();
    const EcsComponent *c = pos_e.get<flecs::Component>();

    printf("Name: %s\n", pos_e.name().c_str());
    printf("Component Size: %d\n", c->size);
}
