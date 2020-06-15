#include <GL/glut.h>
#include <GL/gl.h>

#include <iostream>

#include "Snake.hpp"

using namespace std;

Snake :: Snake () {
    setSnakePosition(20, 20);
    setInitialPoints(5);
    snakeDirection = RIGHT;
    this->gameOver = false;
}

SnakeBody Snake :: getSnakeHeader() {
    return this->body[0];
}
bool Snake :: endGame() {
    this->gameOver = true;
}

bool Snake :: isOver() {
    return this->gameOver;
}


bool Snake :: setSnakePosition(int positionX, int positionY) {

    for (int i = 2; i < getPoints(); i++) {
        if(this->body[0].posX == this->body[i].posX && this->body[0].posY == this->body[i].posY )
            this->endGame();
    }

    if(positionX > 0 && positionX < 39 && positionY > 0 && positionY < 39) {
        this->body[0].posX = positionX;
        this->body[0].posY = positionY;
        return true;
    } 
    else {
        //cout << positionY << ' ' << positionX << endl;
        this->endGame();
        return false;
    }
}  

short int Snake :: getSnakeDirection() {
    return this->snakeDirection;
}

void Snake :: setSnakeDirection(Direction direction) {
    if(direction >= 0 && direction <= 4)
        this->snakeDirection = direction;
}

void Snake :: setInitialPoints(int initialPoints) {
    this->points = initialPoints;
}

void Snake :: incrementPoints() {
    this->points++; // pontos += 1 
}

unsigned int Snake :: getPoints() {
    return this->points;
}

void Snake :: drawSnake() {
    const short int direction = (const short) this->getSnakeDirection();
    int posX = this->body[0].posX;
    int posY = this->body[0].posY;

    for (int i = getPoints(); i > 0; i--) {
        // i for 1
        this->body[i] = this->body[i-1];
    }

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

    for (int snakeIndex = 0; snakeIndex < points; snakeIndex++) {
        SnakeBody position = this->body[snakeIndex];
        if(snakeIndex <= 1) 
            glColor3f(0.1, 0.485, 0.9);
        else 
            glColor3f(0.45, 0.45, 0.45);
        glRectd(position.posX, position.posY, position.posX+1, position.posY+1);
    }


    bool Collider = setSnakePosition(posX, posY);
}

