#ifndef SNAKE_HPP
#define SNAKE_HPP

enum Direction {
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};

class Snake {
    private:
        int positionX, positionY;
        short int snakeDirection;
    public:
        Snake();
        
        bool setSnakePosition(int positionX, int positionY);

        int getSnakePositionX();

        int getSnakePositionY();

        short int getSnakeDirection();

        void setSnakeDirection(Direction);

        void drawSnake();
};

#endif