#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_CreateWindowAndRenderer(800, 800, 0, &window, &renderer);

  int res = 0;

  SDL_SetRenderDrawColor(renderer, 100, 200, 100, 255);
  SDL_RenderClear(renderer);

  SDL_Surface *image = IMG_Load("assets/character.png");
  if (!image) {
    printf("Could not load image: %s\n", IMG_GetError());

    return 1;
  }

  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, image);

  int offset = (800 - 640) / 2;
  SDL_Rect dest = { .x = offset, .y = offset, .w = 640, .h = 640 };

  SDL_RenderCopy(renderer, tex, NULL, &dest);

  SDL_DestroyTexture(tex);
  SDL_FreeSurface(image);

  SDL_RenderPresent(renderer);

  printf("Should have displayed an image!\n");

  return 0;
}
