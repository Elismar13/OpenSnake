#include <GL/glut.h>
#include <GL/gl.h>

#include "Grid.cpp"
#include "Canvas.hpp"
#include "Snake.cpp"
#include "Food.cpp"

#include <iostream>
#include <unistd.h>

Grid* grid = new Grid();
Snake* player = new Snake();
Food* food = new Food();


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
	food->foodController();

	int foodPositionX = food->getFoodX();
	int foodPositionY = food->getFoodY();

	glColor3f(0.8, 0.8, 0.1);
	glRectd(foodPositionX, foodPositionY, foodPositionX+1, foodPositionY+1);
}

void gridInit() {
    glClearColor(0.0,0.0,0.0,1.0);
	grid->initGrid(40, 40);
}

void renderScene() {
	static short int renderNextEndingFrame = 0;

    glClear(GL_COLOR_BUFFER_BIT);
    
	grid->drawGrid();

	player->drawSnake();

	renderFood();

	if(player->getSnakeHeader().posX == food->getFoodX() 
		&& player->getSnakeHeader().posY == food->getFoodY()) 
		{
			food->setCollider(false);
			player->incrementPoints();

			cout << player->getPoints() << endl;
		}

	// chama o proxímo frame
	if(!player->isOver())
    	glutSwapBuffers();
	else{
		if(!renderNextEndingFrame) {
			glutSwapBuffers();
			renderNextEndingFrame++;
			if(renderNextEndingFrame > 0) {
				cout << "Acabou!" << endl
					 << "Sua pontuação: " << player->getPoints() << endl;
				sleep(2);
				exit(1);
			}
		} 
	}
		
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
    glutTimerFunc(1000/FPS, frameTime, 0);
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

    glutTimerFunc(0, frameTime, 0);
    glutMainLoop();
}

