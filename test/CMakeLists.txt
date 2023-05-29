include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.3.2
)

FetchContent_MakeAvailable(Catch2)


FetchContent_Declare(
    FakeIt
    GIT_REPOSITORY https://github.com/eranpeer/FakeIt.git
    GIT_TAG 2.4.0
)

FetchContent_MakeAvailable(FakeIt)

add_executable(TestStateBehavior
    ${CMAKE_CURRENT_SOURCE_DIR}/StateBehavior.cpp
)

target_link_libraries(TestStateBehavior
    PRIVATE
        Catch2::Catch2WithMain
        ${PROJECT_NAME}
)

target_include_directories(TestStateBehavior
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(TestStateIndependent
    ${CMAKE_CURRENT_SOURCE_DIR}/StateIndependent.cpp
)

target_link_libraries(TestStateIndependent
    PRIVATE
        Catch2::Catch2WithMain
        FakeIt::FakeIt-catch
        ${PROJECT_NAME}
)

target_include_directories(TestStateIndependent
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(TestStateTransition
    ${CMAKE_CURRENT_SOURCE_DIR}/StateTransition.cpp
)

target_link_libraries(TestStateTransition
    PRIVATE
        Catch2::Catch2WithMain
        ${PROJECT_NAME}
)
