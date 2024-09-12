#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar kotak luar (biru)
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    glBegin(GL_POLYGON);
    glVertex3f(0.2f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.8f, 0.0f);
    glVertex3f(0.2f, 0.8f, 0.0f);
    glEnd();

    // Menggambar kotak dalam (putih)
    glColor3f(1.0, 1.0, 1.0); // Warna putih
    glBegin(GL_POLYGON);
    glVertex3f(0.4f, 0.4f, 0.0f);
    glVertex3f(0.6f, 0.4f, 0.0f);
    glVertex3f(0.6f, 0.6f, 0.0f);
    glVertex3f(0.4f, 0.6f, 0.0f);
    glEnd();

    // Menggambar garis di sekitar kotak luar
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.2f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.8f, 0.0f);
    glVertex3f(0.2f, 0.8f, 0.0f);
    glEnd();

    // Menggambar garis di sekitar kotak dalam
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.4f, 0.4f, 0.0f);
    glVertex3f(0.6f, 0.4f, 0.0f);
    glVertex3f(0.6f, 0.6f, 0.0f);
    glVertex3f(0.4f, 0.6f, 0.0f);
    glEnd();

    // Menggambar garis kipas dari sudut-sudut kotak luar ke kotak dalam
    glBegin(GL_LINES);
    
    // Dari sudut kiri bawah ke sudut-sudut kotak dalam
    glVertex3f(0.2f, 0.2f, 0.0f); // Kotak luar kiri bawah
    glVertex3f(0.4f, 0.4f, 0.0f); // Kotak dalam kiri bawah

    glVertex3f(0.2f, 0.2f, 0.0f); // Kotak luar kiri bawah
    glVertex3f(0.6f, 0.4f, 0.0f); // Kotak dalam kanan bawah

    glVertex3f(0.2f, 0.2f, 0.0f); // Kotak luar kiri bawah
    glVertex3f(0.6f, 0.6f, 0.0f); // Kotak dalam kanan atas

    glVertex3f(0.2f, 0.2f, 0.0f); // Kotak luar kiri bawah
    glVertex3f(0.4f, 0.6f, 0.0f); // Kotak dalam kiri atas

    // Dari sudut kanan bawah ke sudut-sudut kotak dalam
    glVertex3f(0.8f, 0.2f, 0.0f); // Kotak luar kanan bawah
    glVertex3f(0.4f, 0.4f, 0.0f); // Kotak dalam kiri bawah

    glVertex3f(0.8f, 0.2f, 0.0f); // Kotak luar kanan bawah
    glVertex3f(0.6f, 0.4f, 0.0f); // Kotak dalam kanan bawah

    glVertex3f(0.8f, 0.2f, 0.0f); // Kotak luar kanan bawah
    glVertex3f(0.6f, 0.6f, 0.0f); // Kotak dalam kanan atas

    glVertex3f(0.8f, 0.2f, 0.0f); // Kotak luar kanan bawah
    glVertex3f(0.4f, 0.6f, 0.0f); // Kotak dalam kiri atas

    // Dari sudut kanan atas ke sudut-sudut kotak dalam
    glVertex3f(0.8f, 0.8f, 0.0f); // Kotak luar kanan atas
    glVertex3f(0.4f, 0.4f, 0.0f); // Kotak dalam kiri bawah

    glVertex3f(0.8f, 0.8f, 0.0f); // Kotak luar kanan atas
    glVertex3f(0.6f, 0.4f, 0.0f); // Kotak dalam kanan bawah

    glVertex3f(0.8f, 0.8f, 0.0f); // Kotak luar kanan atas
    glVertex3f(0.6f, 0.6f, 0.0f); // Kotak dalam kanan atas

    glVertex3f(0.8f, 0.8f, 0.0f); // Kotak luar kanan atas
    glVertex3f(0.4f, 0.6f, 0.0f); // Kotak dalam kiri atas

    // Dari sudut kiri atas ke sudut-sudut kotak dalam
    glVertex3f(0.2f, 0.8f, 0.0f); // Kotak luar kiri atas
    glVertex3f(0.4f, 0.4f, 0.0f); // Kotak dalam kiri bawah

    glVertex3f(0.2f, 0.8f, 0.0f); // Kotak luar kiri atas
    glVertex3f(0.6f, 0.4f, 0.0f); // Kotak dalam kanan bawah

    glVertex3f(0.2f, 0.8f, 0.0f); // Kotak luar kiri atas
    glVertex3f(0.6f, 0.6f, 0.0f); // Kotak dalam kanan atas

    glVertex3f(0.2f, 0.8f, 0.0f); // Kotak luar kiri atas
    glVertex3f(0.4f, 0.6f, 0.0f); // Kotak dalam kiri atas

    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang putih
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);  // Mengatur sistem koordinat agar semuanya positif
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kotak dalam Kotak dengan Garis Kipas");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
