#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Mengaktifkan array vertex dan warna
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Vertex dari heksagon (6 sisi)
    GLfloat vertices[] = {
        0.0f,  0.5f, 0.0f,  // Puncak atas
        0.43f,  0.25f, 0.0f,  // Kanan atas
        0.43f, -0.25f, 0.0f,  // Kanan bawah
        0.0f, -0.5f, 0.0f,  // Bawah
        -0.43f, -0.25f, 0.0f,  // Kiri bawah
        -0.43f,  0.25f, 0.0f   // Kiri atas
    };

    // Warna untuk setiap vertex (gunakan warna berbeda untuk setiap titik)
    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,  // Merah
        0.0f, 1.0f, 0.0f,  // Hijau
        0.0f, 0.0f, 1.0f,  // Biru
        1.0f, 1.0f, 0.0f,  // Kuning
        1.0f, 0.0f, 1.0f,  // Ungu
        0.0f, 1.0f, 1.0f   // Cyan
    };

    // Indeks untuk menggambar poligon dengan menggunakan GL_TRIANGLES
    GLubyte indices[] = {
        0, 1, 2,   // Segitiga 1
        0, 2, 3,   // Segitiga 2
        0, 3, 4,   // Segitiga 3
        0, 4, 5    // Segitiga 4
    };

    // Memasukkan data vertex dan warna
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    // Menggambar heksagon
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, indices);

    // Nonaktifkan array
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Latar belakang putih
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Sistem koordinat
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Heksagon dengan Vertex Array");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
