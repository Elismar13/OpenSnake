#include <GL/glut.h>
#include <GL/gl.h>

#include "Grid.cpp"
#include "Canvas.hpp"
#include "Snake.cpp"

#include <time.h>

#include <iostream>

Grid* grid = new Grid();
Snake* player = new Snake();


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

void renderFood() {
	static bool onScreen = false;

	static short foodPostionX = 0;
	static short foodPostionY = 0;

	 //cout << "Numero aleatorio=" << foodPostion << endl;

	//cout << onScreen << endl;

	if(!onScreen) {
		foodPostionX = (rand() % 38) + 1;
		foodPostionY = (rand() % 38) + 1;
		onScreen = true;
	}

	glColor3f(0.6, 0.8, 0.1);
	glRectd(foodPostionX, foodPostionY, foodPostionX+1, foodPostionY+1);
}

void gridInit() {
    glClearColor(0.0,0.0,0.0,1.0);
	grid->initGrid(40, 40);
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    
	grid->drawGrid();

	player->drawSnake();

	renderFood();

    glutSwapBuffers();
}

void reshapeWindow(int width, int height) {
    glViewport(0,0,(GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 40, 0.0, 40, -1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void frameTime(int) {
    glutPostRedisplay();
    glutTimerFunc(100/GAME_FPS,frameTime, 0);
}

void canvasInit(int argc,char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB || GLUT_SINGLE);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenSnake");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshapeWindow);
	glutSpecialFunc(keyboardController);
    gridInit();

	srand(time(NULL));

    glutTimerFunc(0, frameTime, 0);
    glutMainLoop();
}

