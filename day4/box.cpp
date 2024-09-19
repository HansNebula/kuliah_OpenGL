#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis

    glLoadIdentity();

    // Modeling transformations
    glTranslatef(0.0, 0.0, -15.0); // Pindahkan objek pada sumbu Z
    glScalef(0.6, 2.2, 0.6); // Skala untuk membuat persegi terdistorsi secara vertikal

    // Menggambar persegi yang sisi-sisinya tidak sejajar dengan sumbu koordinat
    glBegin(GL_LINE_LOOP);
    glVertex3f(4.0, 0.0, 0.0);  // Vertex 1
    glVertex3f(0.0, 4.0, 0.0);  // Vertex 2
    glVertex3f(-4.0, 0.0, 0.0); // Vertex 3
    glVertex3f(0.0, -4.0, 0.0); // Vertex 4
    glEnd();

    glFlush();
    glutSwapBuffers();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Background putih
    glEnable(GL_DEPTH_TEST);          // Aktifkan depth testing untuk 3D
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0); // Perspektif

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // Escape key untuk keluar
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

    // Gunakan double-buffered display dengan depth buffering dan RGBA color
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Box");

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glutMainLoop();
    return 0;
}
