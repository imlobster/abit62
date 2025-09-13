### abit62

very small and efficient generator of random base62 strings

### instalation

[download `abit62.hpp` from this repository](/src/abit62.hpp)

put it into your c++ project

now its done

### TL;DR: usage

```cpp
#include "abit62.hpp"
#include <cstring>
int main() {
    char base62[17]={}; // array for a 16-chars string
    abit62::init(base62); // initializing random with some pointer. returns bool
    memset(base62,1,16); // fill with non-zeros 16-chars keeping 17th as zero
    abit62::string(base62); // fills passed string with random base62. returns bool
}
```

### dependencies

i made it with c++20 so c++20 recommended.

this library includes:
+ cstdint

### most regular usage

make char array (with size always less or equal 256)

`char base62[17]={}` - 17 because i want 16 symbols and the last one always needs to be `'\0'`

fill it with something that not `'\0'` and keep the last element as `'\0'` so it will be a C-string

`memset(base62,1,16)` - just for an example i will fill it with 1

then initialize rng with some pointer

`abit62::init(base62)` - it will use its address in memory as a seed

and then generate your string

`abit62::string(base62)` - and now your variable now contains a random base62 C-string

you can cout it if you want

`std::cout<<"result: "<<base62<<std::endl`

### performance

on my linux VM it takes around ~145µs to generate one 16-symbols base62 string

you can check it yourself

here is my script for testing:

```cpp
#include "abit62.hpp"
int main() {
    char test_string[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
    abit62::init(test_string);
    abit62::string(test_string);
}
```

before testing: add cout to your script to be sure that it really works
