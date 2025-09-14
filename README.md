### abit62

very small and efficient generator of random base62 strings

### installation

[download `abit62.hpp` from this repository](/src/abit62.hpp)

put it into your c++ project

done

### TL;DR: usage

```cpp
#include "abit62.hpp"
#include <cstring>
int main() {
    char base62[17]{}; // array for a 16-char string
    abit62::init(base62); // initializing random with any pointer. returns bool as success/fail
    abit62::string(base62,16); // fills passed range (16 chars) with random base62. returns bool as success/fail
}
```

### dependencies

i made it with c++20 so c++20 recommended.

this library includes:
+ cstdint

### most regular usage

make char array (with size always less or equal 257)

`char base62[17]{}` - 17 because i want 16 symbols and the last one needs to be the null terminator

then initialize rng with any pointer

`abit62::init(base62)` - it will use its address in memory as a seed

and then generate 16-char string

`abit62::string(base62,16)` - variable now contains a random base62 C-string

you can cout it if you want

`std::cout<<"result: "<<base62<<std::endl`

### performance

on alpine linux VM with musl, generating a 16-symbol base62 random-string takes ~135µs; the test program was built w/ static linking because w/o/ performance decreases

you can check it yourself

here is my compiler args:

`g++ -static -std=c++20 src/*.cpp -o ./debug/abit62`

here is my script for testing:

```cpp
#include "abit62.hpp"
int main() {
    char test_string[17]{};
    abit62::init(test_string);
    abit62::string(test_string,16);
}
```

before testing: add cout to your script to be sure that it really works
