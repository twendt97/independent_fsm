cmake_minimum_required(VERSION 3.15.0)
project(IndependentFsm VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_library(${PROJECT_NAME} SHARED
    src/DogImpl.cpp
    src/DogFactory.cpp
    src/States/StateImpl.cpp
    src/States/Factory.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(test)

include(CTest)
add_test(NAME StateBehavior COMMAND ./test/TestStateBehavior)
add_test(NAME StateIndependent COMMAND ./test/TestStateIndependent)
add_test(NAME StateTransition COMMAND ./test/TestStateTransition)