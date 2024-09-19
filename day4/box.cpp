#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>


    // Move the object into the view (Z axis back).
    // glTranslatef(0.0, 0.0, -15.0);

    // glTranslatef(0.0, 0.0, -10.0);
    // glTranslatef(0.0, 0.0, -5.0);
    // glTranslatef(0.0, 0.0, -25.0);
    // glTranslatef(10.0, 10.0, -15.0);

// Drawing routine.

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Black color for the wireframe
    glLoadIdentity();

    // glTranslatef(0.0, 0.0, -10.0);
    // glTranslatef(0.0, 0.0, -5.0);
    // glTranslatef(0.0, 0.0, -25.0);
    glTranslatef(10.0, 10.0, -15.0);

    glutWireCube(5.0);

    glFlush();
    glutSwapBuffers();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set background color to white.
    glEnable(GL_DEPTH_TEST);          // Enable depth testing for 3D.
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0); // Perspective projection.

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // Escape key.
        exit(0);
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    // Use a double-buffered display with depth buffering and RGBA color.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Wireframe Cube");

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glutMainLoop();
    return 0;
}
