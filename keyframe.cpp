#include <GL/glut.h>

float startX = -0.8f;   // Start position (keyframe 1)
float endX   = 0.8f;    // End position (keyframe 2)
float currentX = startX;
bool forward = true;    // Animation direction
float t = 0.0f;         // Interpolation factor (0.0 to 1.0)
float speed = 0.01f;    // Speed of animation

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(currentX, 0.0f, 0.0f); // Move rectangle based on interpolation

    // Draw rectangle
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
    // Linear interpolation: current = (1 - t) * start + t * end
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Keyframe Rectangle Animation");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D orthographic projection

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}

