#include <GL/glut.h> // GLUT, includes glu.h and gl.h

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw a white rectangle (quad)
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glBegin(GL_QUADS);           // Start drawing a quad
        glVertex2f(-0.5f, -0.5f); // Bottom left
        glVertex2f( 0.5f, -0.5f); // Bottom right
        glVertex2f( 0.5f,  0.5f); // Top right
        glVertex2f(-0.5f,  0.5f); // Top left
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutCreateWindow("Hello OpenGL GLUT");          // Create a window
    glutInitWindowSize(500, 500);                   // Set the window size
    glutInitWindowPosition(100, 100);               // Set window position
    glutDisplayFunc(display);                       // Register display callback
    glutMainLoop();                                 // Enter the event-processing loop
    return 0;
}

