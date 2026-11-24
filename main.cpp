#include <SDL2/SDL.h>
#include <iostream>

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << SDL_GetError();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "NestCode",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        500,
        600,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        std::cout << SDL_GetError();
        SDL_Quit();
        return 1;
    }

    // Keep window open
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                running = false;
            }

        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
