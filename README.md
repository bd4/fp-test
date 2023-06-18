# fp-tests

Tests to compare floating point and complex floating point operations across
different compilers. Uses Googletest framework.

## Usage

    CXX=$(which clang++) cmake -S . -B build-clang
    cmake --build build-clang -v -t test

    CXX=$(which g++) cmake -S . -B build-gcc
    cmake --build build-gcc -v -t test

    source /opt/intel/oneapi/setvars.sh
    CXX=$(which icpx) cmake -S . -B build-oneapi
    cmake --build build-oneapi -v -t test
