#include <GL/glut.h>
#include <GL/gl.h>

#include "Grid.cpp"
#include "Canvas.hpp"
#include "Snake.cpp"


Grid* grid = new Grid();
Snake* player = new Snake();

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	grid->drawGrid();

	player->drawSnake();
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

void gridInit () {
	glClearColor(0.0, 0.0, 0.0, 1);
	grid->initGrid(40, 40);
}

void frameTime(int time) {
    // Redesplay and force to continue rendering
    glutPostRedisplay();
    glutTimerFunc(1000/GAME_FPS, frameTime, 0);
}

void keyboardController(int key, int value1, int value2) {
	switch (key) {
		case GLUT_KEY_UP:
			if(player->getSnakeDirection() != DOWN)
				player->setSnakeDirection(UP);
			break;
		case GLUT_KEY_DOWN:
			if(player->getSnakeDirection() != UP)
				player->setSnakeDirection(DOWN);
			break;
		case GLUT_KEY_LEFT:
			if(player->getSnakeDirection() != RIGHT)
				player->setSnakeDirection(LEFT);
			break;
		case GLUT_KEY_RIGHT:
			if(player->getSnakeDirection() != LEFT)
				player->setSnakeDirection(RIGHT);
			break;
	}

}

void canvasInit(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(RESOLUCTION_X, RESOLUCTION_Y);
    glutCreateWindow("Hello, World!");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeWindow);
	gridInit();
    
    // Rendering in a defined time
    // First call
    glutTimerFunc(GAME_FPS, frameTime, 0);

	// enter GLUT event processing cycle
	glutMainLoop();
}
