#include "glad/src/glad.cpp"
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

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  int windowWidth = 1920 / 2;
  int windowHeight = 1080 / 2;
  SDL_Window *window =
      SDL_CreateWindow("Voxel Engine", windowWidth, windowHeight,
                       SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  SDL_GLContext glContext = SDL_GL_CreateContext(window);

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    printf("Failed to initialize GLAD\n");
    return 1;
  }

  if (!window || !glContext) {
    printf("SDL_CreateWindow or SDL_CreateRenderer failed: %s\n",
           SDL_GetError());
    return 1;
  }

  glViewport(0, 0, windowWidth, windowHeight);
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

  bool running = true;
  while (running) {
    processEvents(&running);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
  }

  return 0;
}
