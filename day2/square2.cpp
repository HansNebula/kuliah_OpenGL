#include <GL/glut.h>

void display() {
    // Atur warna latar belakang menjadi putih
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Atur warna kotak menjadi hitam
    glColor3f(0.0f, 0.0f, 0.0f);

    // Kotak pertama
    glBegin(GL_POLYGON);
    glVertex3f(20.0, 20.0, 0.0);
    glVertex3f(80.0, 20.0, 0.0);
    glVertex3f(80.0, 80.0, 0.0);
    glVertex3f(20.0, 80.0, 0.0);
    glEnd();

    // Kotak kedua
    glBegin(GL_POLYGON);
    glVertex3f(120.0, 120.0, 0.0);
    glVertex3f(180.0, 120.0, 0.0);
    glVertex3f(180.0, 180.0, 0.0);
    glVertex3f(120.0, 180.0, 0.0);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0); // Menyesuaikan viewport agar kedua kotak terlihat
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dua Kotak");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
