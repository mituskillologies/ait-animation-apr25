#include <GL/glut.h>
#include <cmath>
#include <iostream>

float rotationAngle = 0.0f;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -2.0f); // Move the triangle back a bit
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Rotate around the Y-axis

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();

    glutSwapBuffers(); // Use double buffering for smoother animation
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void update(int value) {
    rotationAngle += 2.0f;
    if (rotationAngle > 360.0f)
        rotationAngle -= 360.0f;

    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, update, 0); // Call update again after ~16 milliseconds (approx. 60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffering and depth buffer
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rotating Triangle GLUT");

    glEnable(GL_DEPTH_TEST); // Enable depth testing for proper 3D rendering

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0); // Start the animation timer

    glutMainLoop();

    return 0;
}
