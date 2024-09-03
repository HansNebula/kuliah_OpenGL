#include <GL/glut.h>

void display() {
    // Set the background color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to black for the square fill
    glColor3f(0.0f, 0.0f, 0.0f);

    // Draw a filled square
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f); // Bottom left corner
        glVertex2f(0.5f, -0.5f);  // Bottom right corner
        glVertex2f(0.5f, 0.5f);   // Top right corner
        glVertex2f(-0.5f, 0.5f);  // Top left corner
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Square with White Background");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
