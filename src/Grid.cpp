#include <GL/glut.h>
#include <GL/gl.h>

#include "Grid.hpp"

void Grid :: initGrid(int x, int y) {
    this->gridX = x;
    this->gridY = y;
}

void Grid :: gridUnit(int x, int y, bool isBorder) {
    glLineWidth(1.0);

    // Desenha uma borda completa
    if(isBorder) {
        glColor3f(0.09, 0.97, 0.07); 	// #1bf913	(27,249,19)
        glRectd(x, y, x+1, y+1);
    } 
    
    //Desenha apenas as linhas
    else {
        glColor3f(0.96, 0.12, 1.0); // #f222ff	(242,34,255)
        glBegin(GL_LINE_LOOP);
            glVertex3d(x, y, 1);
            glVertex3d(x+1, y, 1);
            glVertex3d(x+1, y+1, 1);
            glVertex3d(x, y+1, 1);
        glEnd();
    }

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



