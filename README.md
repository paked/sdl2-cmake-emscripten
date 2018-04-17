# SDL2, CMake, and Emscripten

This is an example project which combines SDL2 (and SDL2_image), CMake and Emscripten. It can build to a native platform (tested Ubuntu) and Emscripten (AKA web).

## To build

Native:

`mkdir build`
`cmake ..`
`make`
`./main`

Web:

`mkdir build`
`emcmake cmake ..`
`make`
`python3 -m http.module` (or start a HTTP server some other way, running that command serves $CWD on localhos:8000)
