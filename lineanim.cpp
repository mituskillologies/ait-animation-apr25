#include <GL/glut.h>

float xPos = -1.0f; // Starting x position of the line

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(xPos, 0.0f, 0.0f); // Move the line along the x-axis

    glColor3f(0.0f, 1.0f, 0.0f); // Green line
    glBegin(GL_LINES);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f( 0.5f, 0.0f);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void update(int value) {
    xPos += 0.01f;
    if (xPos > 1.5f)
        xPos = -1.5f; // Reset to loop

    glutPostRedisplay();            // Redraw
    glutTimerFunc(16, update, 0);   // Approx. 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Double buffer
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simple Line Animation");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -1.0, 1.0); // 2D view

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
