#include <GL/glut.h>
#include <GL/gl.h>

#define RESOLUCTION_X 600
#define RESOLUCTION_Y 640

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex2d( 0.1f,  0.1f);
		glVertex2d( 0.1f, -0.1f);
		glVertex2d(-0.1f, -0.1f);
		glVertex2d(-0.1f,  0.1f);
		
	glEnd();

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
