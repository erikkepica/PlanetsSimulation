#include"Game.h"

int main()
{
    std::unique_ptr<Game> game = std::make_unique<Game>("Sim");

    while (game->open)
    {
        game->Update();
    }

    return 0;
}
