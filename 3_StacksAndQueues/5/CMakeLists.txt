set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILE
    main.cc
    ../stack.cc
    )
add_executable(exec ${SOURCE_FILE})
