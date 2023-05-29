# Testing finite state machines in C++

This repository contains the source code for the test methodology introduced in [this article](https://dev.to/twendt97/testing-finite-state-machines-in-c-44aa). The project pulls in [catch2](https://github.com/catchorg/Catch2) and [FakeIt](https://github.com/eranpeer/FakeIt) as dependencies through CMake. In order to compile the project carry out the following steps in the root directory of the repository:

```bash
cmake -B build .
cd build
make
make test
```

Tests can be executed through the ``make test`` target.