#include <GL/glut.h>
#include <GL/gl.h>

#include "game.h"

class Grid {
    private:
        int gridX, gridY;

    public:
        Grid() {
            
        }

        void initGrid(int x, int y) {
            this->gridX = x;
            this->gridY = y;
        }

        void gridUnit(int x, int y) {
            glLineWidth(1.0);
            glColor3f(1.0, 1.0, 1.0);

            glBegin(GL_LINE_LOOP);
                glVertex2f(x, y);
                glVertex2f(x+1, y);
                glVertex2f(x+1, y+1);
                glVertex2f(x, y+1);
            glEnd();
        }

        void drawGrid() {
            for(int x = 0; x < this->gridX; x++) {
                for(int y = 0; y < this->gridY; y++) {
                    this->gridUnit(x, y);
                }
            }
        }
};


