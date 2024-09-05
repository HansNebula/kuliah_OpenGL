#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a circle
    float radius = 0.5f; // Radius of the circle
    int num_segments = 100; // Number of segments to approximate the circle

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Angle for this segment
        float x = radius * cosf(theta); // x coordinate
        float y = radius * sinf(theta); // y coordinate
        glVertex2f(x, y); // Specify the vertex
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Circle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
