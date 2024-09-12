#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Warna hijau untuk daun
    glColor3f(0.0f, 1.0f, 0.0f); 

    // Menggambar tepi daun (Outline daun)
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 0.0f);   // Bagian bawah
    glVertex2f(0.2f, 0.4f);   // Kanan bawah
    glVertex2f(0.15f, 0.6f);  // Kanan atas
    glVertex2f(0.0f, 0.8f);   // Puncak
    glVertex2f(-0.15f, 0.6f); // Kiri atas
    glVertex2f(-0.2f, 0.4f);  // Kiri bawah
    glEnd();

    // Garis tengah (tulang utama daun)
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);  // Bawah
    glVertex2f(0.0f, 0.8f);  // Atas
    glEnd();

    // Garis-garis lateral kiri (Tulang daun kiri)
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.6f);  // Tengah-tengah kiri atas
    glVertex2f(-0.1f, 0.5f); // Keluar ke kiri bawah

    glVertex2f(0.0f, 0.4f);  // Tengah-tengah kiri bawah
    glVertex2f(-0.15f, 0.3f);// Keluar ke kiri bawah

    glVertex2f(0.0f, 0.2f);  // Tengah kiri bawah
    glVertex2f(-0.1f, 0.1f); // Keluar ke kiri bawah
    glEnd();

    // Garis-garis lateral kanan (Tulang daun kanan)
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.6f);  // Tengah-tengah kanan atas
    glVertex2f(0.1f, 0.5f);  // Keluar ke kanan bawah

    glVertex2f(0.0f, 0.4f);  // Tengah-tengah kanan bawah
    glVertex2f(0.15f, 0.3f); // Keluar ke kanan bawah

    glVertex2f(0.0f, 0.2f);  // Tengah kanan bawah
    glVertex2f(0.1f, 0.1f);  // Keluar ke kanan bawah
    glEnd();

    // Batang daun
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);   // Bawah daun
    glVertex2f(0.0f, -0.2f);  // Bawah batang
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang putih
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Sistem koordinat dari -1.0 hingga 1.0
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Daun");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
