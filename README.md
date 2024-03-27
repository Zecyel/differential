# Differential

## Generate

```sh
antlr4 -Dlanguage=Cpp Differential.g4 -o generated/
```

## Build

```sh
clang++ -std=c++11 main.cpp $(find generated -type f -name "*.cpp") -Igenerated -I/usr/local/include/antlr4-runtime -L/usr/local/lib/ -Wl,-rpath=/usr/local/lib/ -lantlr4-runtime -o main -std=c++17
```
