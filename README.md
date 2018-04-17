# SDL2, CMake, and Emscripten

This is an example project which combines SDL2 (and SDL2_image), CMake and Emscripten. It can build to a native platform (tested Ubuntu) and Emscripten (AKA web).

## To build

Native:

1. `mkdir build`
2. `cmake ..`
3. `make`
4. `./main`

Web:

1. `mkdir build`
2. `emcmake cmake ..`
3. `make`
4. `python3 -m http.module` (or start a HTTP server some other way, running that command serves $CWD on localhos:8000)
