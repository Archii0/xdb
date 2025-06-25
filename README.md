# Experimental Debugger

Because debuggers are kinda unusual and complex in an interesting way

## To build (Ninja)

- Create and enter the build directory (only once)
```
mkdir -p build
cd build
```

- Generate build files with CMake (run anytime you change CMakeLists.txt)
```
cmake -G Ninja ..
```

- Build the project with Ninja
```
ninja
```