#ifndef SNAKE_HPP
#define SNAKE_HPP

enum Direction {
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};

typedef struct {
    int posX;
    int posY;
} SnakeBody;

class Snake {
    private:
        bool gameOver;
        short int snakeDirection;
        unsigned int points;
        SnakeBody body[50];

    public:
        Snake();
        
        SnakeBody getSnakeHeader();

        bool endGame();

        bool isOver();

        bool setSnakePosition(int positionX, int positionY);

        short int getSnakeDirection();

        void setSnakeDirection(Direction);

        void setInitialPoints(int initialPoints);

        void incrementPoints();

        unsigned int getPoints();

        void drawSnake();
};

#endif