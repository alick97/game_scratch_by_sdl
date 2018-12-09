#include <SDL.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[]) {
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        // if succeeded create out window
        g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN);


        // if the window creation succeeded, then create our renderer
        if (g_pWindow != 0) {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
    else {
        return 1; // sdl could not initialize
    }

    // everything succeeded lets draw the window

    // set to back // this function expects Red, Green , Blue and
    // aplha as color values
    for (int i =0; i <= 250; i++) {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

        // clear the window to black
        SDL_RenderClear(g_pRenderer);

        // show the window
        SDL_RenderPresent(g_pRenderer);

        // sleep 1
        usleep(700000);

    }
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    // clear the window to black
    SDL_RenderClear(g_pRenderer);

    // show the window
    SDL_RenderPresent(g_pRenderer);

    // set a delay befor quitting
    SDL_Delay(5000);

    // clean up sdl
    SDL_Quit();

    return 0;
}