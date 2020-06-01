#include <GL/glut.h>
#include <GL/gl.h>

#include "game.h"

class Grid {
    private:
        int gridX, gridY;

    public:
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
            gridUnit(20, 20);
        }
};


