#include <GL/glut.h>

float scale = 0.1f;  // Variabel skala awal
float scaleIncrement = 0.01f;  // Besar perubahan skala di setiap frame

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Mengaktifkan array vertex dan warna
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Vertex dari square annulus
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,   // Kiri bawah
         0.5f, -0.5f, 0.0f,   // Kanan bawah
         0.5f,  0.5f, 0.0f,   // Kanan atas
        -0.5f,  0.5f, 0.0f    // Kiri atas
    };

    // Warna untuk setiap vertex
    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,  // Merah
        0.0f, 1.0f, 0.0f,  // Hijau
        0.0f, 0.0f, 1.0f,  // Biru
        1.0f, 1.0f, 0.0f   // Kuning
    };

    // Indeks untuk menggambar persegi
    GLubyte indices[] = {0, 1, 2, 3};

    // Skala objek secara dinamis
    glPushMatrix();
    glScalef(scale, scale, 1.0f);  // Menerapkan skala ke objek

    // Memasukkan data vertex dan warna
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    // Menggambar persegi
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices);

    glPopMatrix();

    // Nonaktifkan array
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();

    // Update skala untuk animasi
    scale += scaleIncrement;
    if (scale >= 2.0f || scale <= 0.1f) {
        scaleIncrement = -scaleIncrement;  // Balik arah skala saat mencapai batas
    }

    glutPostRedisplay();  // Meminta frame baru untuk digambar
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
    glutCreateWindow("Animasi Square Annulus");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
