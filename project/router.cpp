#include <GL/glut.h> // OpenGL Utility Toolkit

// Variabel untuk rotasi
float angleX = 0.0f;
float angleY = 0.0f;

// Fungsi untuk menginisialisasi pencahayaan
void initLighting() {
    glEnable(GL_LIGHTING);   // Mengaktifkan sistem pencahayaan
    glEnable(GL_LIGHT0);     // Mengaktifkan lampu default

    // Mengatur posisi lampu
    GLfloat light_position[] = { 2.0f, 0.2f, 1.0f, 0.0f }; // Posisi lampu
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Mengatur intensitas cahaya (diffuse dan specular)
    GLfloat light_diffuse[] = { 1.5f, 1.5f, 1.5f, 1.0f };  // Cahaya diffuse lebih terang
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Cahaya specular (untuk highlight)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    // Menambahkan cahaya ambient (penerangan dasar seluruh scene)
    GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f }; // Cahaya ambient untuk membuat seluruh scene lebih terang
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
}

// Fungsi untuk menggambar kubus besar dengan material dan pencahayaan
void drawLargeCube() {
    GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };    // Cahaya ambient material
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };    // Warna putih (diffuse)
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   // Material specular untuk highlight
    GLfloat mat_shininess[] = { 50.0f };                   // Tingkat kekilauan material

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_QUADS);

    // Variabel untuk ukuran kubus besar
    float width = 1.0f;
    float height = 0.2f;
    float depth = 1.0f;

    // Sisi depan
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-width, -height, depth);
    glVertex3f(width, -height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(-width, height, depth);

    // Sisi belakang
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-width, -height, -depth);
    glVertex3f(-width, height, -depth);
    glVertex3f(width, height, -depth);
    glVertex3f(width, -height, -depth);

    // Sisi kiri
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-width, -height, -depth);
    glVertex3f(-width, -height, depth);
    glVertex3f(-width, height, depth);
    glVertex3f(-width, height, -depth);

    // Sisi kanan
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(width, -height, -depth);
    glVertex3f(width, height, -depth);
    glVertex3f(width, height, depth);
    glVertex3f(width, -height, depth);

    // Sisi atas
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-width, height, -depth);
    glVertex3f(-width, height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(width, height, -depth);

    // Sisi bawah
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-width, -height, -depth);
    glVertex3f(width, -height, -depth);
    glVertex3f(width, -height, depth);
    glVertex3f(-width, -height, depth);

    glEnd();
}

// Fungsi untuk menggambar kubus kecil di atas kubus besar
void drawSmallCube() {
    // Material kubus kecil
    GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };    // Cahaya ambient material
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };    // Warna putih (diffuse)
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   // Material specular untuk highlight
    GLfloat mat_shininess[] = { 50.0f };                  // Kekilauan tinggi

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix(); // Simpan transformasi awal
    glTranslatef(0.0f, 0.2f, 0.0f); // Pindahkan kubus kecil ke atas kubus besar

    glScalef(0.5f, 0.5f, 0.5f); // Perkecil ukuran kubus
    glBegin(GL_QUADS);

    // Variabel untuk ukuran kubus kecil
    float width = 1.5f;
    float height = 0.05f;
    float depth = 1.5f;

    // Sisi depan
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-width, -height, depth);
    glVertex3f(width, -height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(-width, height, depth);

    // Sisi belakang
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-width, -height, -depth);
    glVertex3f(-width, height, -depth);
    glVertex3f(width, height, -depth);
    glVertex3f(width, -height, -depth);

    // Sisi kiri
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-width, -height, -depth);
    glVertex3f(-width, -height, depth);
    glVertex3f(-width, height, depth);
    glVertex3f(-width, height, -depth);

    // Sisi kanan
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(width, -height, -depth);
    glVertex3f(width, height, -depth);
    glVertex3f(width, height, depth);
    glVertex3f(width, -height, depth);

    // Sisi atas
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-width, height, -depth);
    glVertex3f(-width, height, depth);
    glVertex3f(width, height, depth);
    glVertex3f(width, height, -depth);

    // Sisi bawah
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-width, -height, -depth);
    glVertex3f(width, -height, -depth);
    glVertex3f(width, -height, depth);
    glVertex3f(-width, -height, depth);

    glEnd();
    glPopMatrix(); // Kembalikan transformasi ke semula
}

// Fungsi untuk menggambar persegi biru kecil di atas kubus kecil
void drawLED() {
    
    glEnable(GL_LIGHTING);
    GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };    // Cahaya ambient material
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };    // Warna putih (diffuse)
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   // Material specular untuk highlight
    GLfloat mat_shininess[] = { 30.0f };

    glPushMatrix(); // Simpan transformasi awal
    glTranslatef(0.0f, 0.25f, 0.5f); // Pindahkan persegi ke atas kubus kecil

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru

    // Ukuran persegi
    float squareSize = 0.05f;

    // Sisi depan
    glVertex3f(-squareSize, 0.0f, squareSize);
    glVertex3f(squareSize, 0.0f, squareSize);
    glVertex3f(squareSize, 0.0f, -squareSize);
    glVertex3f(-squareSize, 0.0f, -squareSize);

    glEnd();
    glPopMatrix(); // Kembalikan transformasi ke semula
}

// Fungsi display untuk render kubus
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Membersihkan buffer warna dan kedalaman
    glLoadIdentity(); // Mengatur ulang transformasi tampilan

    // Transformasi dan posisi kamera
    glTranslatef(0.0f, 0.0f, -7.0f); // Geser kubus ke dalam layar
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotasi kubus pada sumbu x
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotasi kubus pada sumbu y

    drawLargeCube();  // Gambar kubus besar
    drawSmallCube();  // Gambar kubus kecil di atasnya
    drawLED();

    glutSwapBuffers(); // Swap buffer untuk animasi smooth
}

// Fungsi untuk mengubah ukuran jendela
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // Set viewport ke ukuran jendela
    glMatrixMode(GL_PROJECTION); // Ubah ke mode proyeksi
    glLoadIdentity(); // Reset proyeksi
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f); // Perspektif proyeksi
    glMatrixMode(GL_MODELVIEW); // Kembali ke mode tampilan
}

// Fungsi untuk menangani input keyboard
void keyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:    // Jika tombol panah atas ditekan
            angleX += 2.0f; // Rotasi ke atas
            break;
        case GLUT_KEY_DOWN:  // Jika tombol panah bawah ditekan
            angleX -= 2.0f; // Rotasi ke bawah
            break;
        case GLUT_KEY_LEFT:  // Jika tombol panah kiri ditekan
            angleY -= 2.0f; // Rotasi ke kiri
            break;
        case GLUT_KEY_RIGHT: // Jika tombol panah kanan ditekan
            angleY += 2.0f; // Rotasi ke kanan
            break;
    }
    glutPostRedisplay(); // Meminta untuk merender ulang
}

// Inisialisasi OpenGL
void init() {
    glEnable(GL_DEPTH_TEST); // Aktifkan pengujian kedalaman (depth test)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Atur latar belakang hitam
    initLighting(); // Inisialisasi pencahayaan
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode (buffer ganda, RGB, depth)
    glutInitWindowSize(500, 500); // Set ukuran jendela
    glutCreateWindow("3D Modified Cube with Lighting"); // Membuat jendela dengan judul

    init(); // Inisialisasi OpenGL

    glutDisplayFunc(display); // Fungsi callback untuk rendering
    glutReshapeFunc(reshape); // Fungsi callback untuk perubahan ukuran jendela
    glutSpecialFunc(keyboard); // Fungsi callback untuk menangani input keyboard

    glutMainLoop(); // Memulai loop utama GLUT

    return 0;
}
