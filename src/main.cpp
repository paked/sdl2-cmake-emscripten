#include <stdio.h>
#include <cmath>

#ifdef __EMSCRIPTEN__
  #include <emscripten/emscripten.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

// I can't be bothered to remember more digits of Pi right now.
#define DEGREES_TO_RADIANS(degrees) ((degrees) * 3.14159 / 180.0)

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int x = SCREEN_WIDTH/2;
int y = SCREEN_HEIGHT/2;

void tick() {
  SDL_SetRenderDrawColor(renderer, 100, 200, 100, 255);
  SDL_RenderClear(renderer);

  int imgSize = 64;
  x = SCREEN_WIDTH/2 + std::sin(DEGREES_TO_RADIANS(SDL_GetTicks()/10))*100;

  SDL_Rect dest = { .x = x - imgSize/2, .y = y - imgSize/2, .w = imgSize, .h = imgSize };

  SDL_RenderCopy(renderer, texture, NULL, &dest);

  SDL_RenderPresent(renderer);
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_CreateWindowAndRenderer(800, 800, 0, &window, &renderer);

  SDL_Surface *image = IMG_Load("assets/character.png");
  if (!image) {
    printf("Could not load image: %s\n", IMG_GetError());

    return 1;
  }

  texture = SDL_CreateTextureFromSurface(renderer, image);

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(tick, 60, 1);
#else
  SDL_Event event;
  bool quit = false;

  while (!quit) {
    tick();

    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      quit = true;

      break;
    }

    SDL_Delay(1.0/60.0);
  }
#endif

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);

  printf("Done\n");

  return 0;
}
