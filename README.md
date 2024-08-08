## Game scratch by sdl
----

### Summary
Learn Sample game frame by sdl.

### Ubuntu develop environment.
```
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev
```

### Document
- docs/SDL Game Development.pdf

#### Install Dependent Repository
```
git submodule init
git submodule update
```

### Compile
```
cmake -B build -S .
cmake --build build -j
```

### Run
```
./build/Gamedebug
```

- [cmake sdl2-cmake-modules](https://github.com/aminosbh/sdl2-cmake-modules)
- [using-sdl2-image-with-cmake](https://trenki2.github.io/blog/2017/07/04/using-sdl2-image-with-cmake/)
