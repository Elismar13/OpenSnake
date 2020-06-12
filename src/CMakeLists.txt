#adding all cpp and hpp files
add_library( Snake
    Canvas.cpp
    Canvas.hpp
    Grid.cpp
    Grid.hpp
    Snake.cpp
    Snake.hpp
)

#Linking to GL library
target_link_libraries(Snake -lGL)
target_link_libraries(Snake -lGLU)
target_link_libraries(Snake -lglut)

#target_link_libraries()
add_executable(OpenSnake main.cpp)
target_link_libraries(OpenSnake Snake)