#include <SDL3/SDL.h>
#include <stdio.h>

void processEvents(bool *running) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      *running = false;
      break;
    }
  }
}

int main() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    printf("SDL_Init failed: %s\n", SDL_GetError());
    return 1;
  };

  SDL_Window *window =
      SDL_CreateWindow("Voxel Engine", 1920 / 2, 1080 / 2,
                       SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  if (!window || !renderer) {
    printf("SDL_CreateWindow or SDL_CreateRenderer failed: %s\n",
           SDL_GetError());
    return 1;
  }

  bool running = true;
  while (running) {
    processEvents(&running);
  }

  return 0;
}
