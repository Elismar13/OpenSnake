#include <GL/glut.h>
#include <GL/gl.h>

#include "Grid.hpp"

void Grid :: initGrid(int x, int y) {
    this->gridX = x;
    this->gridY = y;
}

void Grid :: gridUnit(int x, int y, bool isBorder) {
    glLineWidth(1.0);
    isBorder ? 
        glColor3f(0.2, 0.9, 0.1):
        glColor3f(0.5, 0.0, 0.6);

    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);
    glEnd();
}

void Grid :: drawGrid() {
    for(int x = 0; x < this->gridX; x++) {
        for(int y = 0; y < this->gridY; y++) {
            if((x < 1 || x > this->gridX - 2) || (y < 1 || y > this-> gridY - 2))
                this->gridUnit(x, y, true);
            else 
                this->gridUnit(x, y, false);
        }
    }
}



