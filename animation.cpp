#include<GL/glut.h>
float startX = -0.8f;
float endX = 0.8f;
float currentX = startX;
bool forward = true;
float t = 0.0f;  // interpolation
float speed = 0.01f;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(currentX, 0.0f, 0.0f);
    glColor3f(0.2f, 0.6f, 1.0f); // Light blue
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();
    glutSwapBuffers();
}
void update(int value) {
    currentX = (1 - t) * startX + t * endX;
    if (forward)
        t += speed;
    else
        t -= speed;

    // Reverse direction at ends
    if (t >= 1.0f) {
        t = 1.0f;
        forward = false;
    } else if (t <= 0.0f) {
        t = 0.0f;
        forward = true;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Keyframe Rectangle Animation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
	return 0;
}
