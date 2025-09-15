### abit62

very small and efficient generator of random base62 strings

### installation

[download `abit62.hpp` from this repository](/src/abit62.hpp)

put it into your c++ project

done

### TL;DR: usage

```cpp
#include "abit62.hpp"
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

make char array (with size less or equal 256 for regular usage)

`char base62[17]{}` - 17 because i want 16 symbols and the last one needs to be the null terminator

then initialize rng with any pointer

`abit62::init(base62)` - it will use its address in memory as a seed

and then generate 16-char string

`abit62::string(base62,16)` - variable now contains a random base62 C-string

you can cout it if you want

`std::cout<<"result: "<<base62<<std::endl`

### performance

benchmarks on almost empty alpine linux VM:

```
255 symbols / 1'000'000 iters:
Mean time: 720.487 ns

16 symbols / 10'000'000 iters:
Mean time: 64.6329 ns

1 symbol / 100'000'000 iters:
Mean time: 24.4968 ns
```

the test program was built w/ static linking because w/o/ performance decreases

you can check it yourself

here is my compiler args:

`g++ -static -std=c++20 src/*.cpp -o ./debug/abit62`

here is my script for testing:

```cpp
#include <iostream>
#include <chrono>
#include "abit62.hpp"

int main() {
    using namespace std::chrono;

    const int iterations = 10'000'000;
    constexpr int count_of_symbols = 16;

    // test init
    char base62[count_of_symbols+1]{};
    abit62::init(base62);
    // end test init

    long long total_ns = 0;

    for (int i = 0; i < iterations; ++i) {
        auto start = high_resolution_clock::now();

        // test code
        abit62::string(base62,count_of_symbols);
        // end test code

        auto end = high_resolution_clock::now();
        total_ns += duration_cast<nanoseconds>(end - start).count();
    }

    // mean
    double mean = static_cast<double>(total_ns) / iterations;

    std::cout << "Mean time: " << mean << " ns\n";
    std::cout << "Result string: " << base62 << std::endl;

    return 0;
}
```
