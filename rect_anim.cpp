#include<GL/glut.h>
// declare global variables
float startX = -0.8f;
float stopX = 0.8f;
float currentX = startX;
float t = 0.0f;
float speed = 0.01f;
bool forward = true;
// declare display function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(currentX, 0.0f, 0.0f);
	glColor3f(0.2f, 0.6f, 1.0f);
	glBegin(GL_QUADS);
	  glVertex2f(-0.1f, -0.1f);
	  glVertex2f(0.1f,  -0.1f);
	  glVertex2f(0.1f,   0.1f);
	  glVertex2f(-0.1f,  0.1f);
	glEnd();
	glutSwapBuffers();
}
void update(int value)
{
	currentX = (1-t) * startX + t * stopX;
	if (forward)
	  t += speed;
	else
	  t -= speed;
	  
	if (t >= 1.0f) {
	  t = 1.0f;
	  forward = false;
	}
	else if (t <= 0.0f){
	  t = 0.0f;
	  forward = true;
	}
	glutPostRedisplay();
	glutTimerFunc(16, update, 0);
}

// declare main
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Simple Animation");
	glClearColor(0.4f, 0.6f, 0.5f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(display);
	glutTimerFunc(0, update, 0);
	glutMainLoop();
	return 0;
}





