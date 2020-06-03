#include <GL/glut.h>
#include <GL/gl.h>

#include "game.cpp"

#define RESOLUCTION_X 600
#define RESOLUCTION_Y 640

Grid grid;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	grid.drawGrid();

	// call the next frame 
	glutSwapBuffers();
}

void reshapeWindow(int widht, int height) {
	glutReshapeWindow(RESOLUCTION_X, RESOLUCTION_Y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Setting projections
	glOrtho(0, 40.0, 0, 40.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
}

void init () {
	glClearColor(0.0, 0.0, 0.0, 1);
	grid.initGrid(40, 40);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(RESOLUCTION_X, RESOLUCTION_Y);
    glutCreateWindow("Hello, World!");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeWindow);
	init();
	// enter GLUT event processing cycle
	glutMainLoop();

    
    return 0;
}
