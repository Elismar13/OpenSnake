#include <GL/glut.h>
#include <GL/gl.h>

#include "Snake.hpp"

Snake :: Snake () {
    setSnakePosition(20, 20);
    snakeDirection = RIGHT;
}
        
bool Snake :: setSnakePosition(int positionX, int positionY) {
    if(positionX >= 0 && positionX <= 40 && positionX >= 0 && positionX <= 40) {
        this->positionX = positionX;
        this->positionY = positionY;
        return true;
    } 
    else return false;
}  

int Snake :: getSnakePositionX() {
    return this->positionX;
}

int Snake :: getSnakePositionY() {
    return this->positionY;
}

short int Snake :: getSnakeDirection() {
    return this->snakeDirection;
}

void Snake :: setSnakeDirection(Direction direction) {
    if(direction >= 0 && direction <= 4)
        this->snakeDirection = direction;
}

void Snake :: drawSnake() {
    const short int direction = (const short) this->getSnakeDirection();
    int posX = this->getSnakePositionX();
    int posY = this->getSnakePositionY();

    switch (direction)
    {
        case UP:
            posY++;
            break;

        case DOWN:
            posY--;
            break;

        case LEFT:
            posX--;
            break;

        case RIGHT:
            posX++;
            break;

        default:
            break;
    }

    glRectd(posX, posY, posX+1, posY+1);

    bool Collider = setSnakePosition(posX, posY);
}

