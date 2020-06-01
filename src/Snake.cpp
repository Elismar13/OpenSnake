#include <GL/glut.h>
#include <GL/gl.h>

#define RESOLUCTION_X 600
#define RESOLUCTION_Y 640

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex2d( 0.05f,  0.05f);
		glVertex2d( 0.05f, -0.05f);
		glVertex2d(-0.05f, -0.05f);
		glVertex2d(-0.05f,  0.05f);
		
	glEnd();

	glutSwapBuffers();
}

void reshapeWindow(int widht, int height) {
	glutReshapeWindow(600)
}

void init () {
	glClearColor(1.0, 0, 0, 1);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 480);
    glutCreateWindow("Hello, World!");

	// register callbacks
	glutDisplayFunc(renderScene);
	init();
	// enter GLUT event processing cycle
	glutMainLoop();

    
    return 0;
}
