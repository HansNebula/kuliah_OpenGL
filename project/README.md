

# README: 3D Kubus Termodifikasi dengan Pencahayaan Menggunakan OpenGL


## Hatfan Sahrul Ramadhan (5223600004)
## Toriq Mardlatillah (5223600012)

## Fitur Utama:
<!-- - **Pencahayaan 3D**: Program ini menggunakan pencahayaan `GL_LIGHT0` untuk menambah efek cahaya pada kubus. -->
- **Interaksi Keyboard**: Pengguna dapat memutar objek dengan tombol panah atas, bawah, kiri, dan kanan.
- **Dua Kubus**: Terdapat kubus besar dan kubus kecil yang berada di atas kubus besar.
- **Efek LED**: Sebuah persegi kecil berwarna biru menyerupai LED berada di atas kubus kecil.
- **Rotasi Objek**: Objek dapat diputar di sepanjang sumbu X dan Y.


## Cara Menjalankan
1. **Kompilasi program** dengan perintah berikut:
   ```bash
   g++ -o cube_program cube_program.cpp -lGL -lGLU -lglut
   ```
2. **Jalankan program**:
   ```bash
   ./cube_program
   ```

## Penjelasan Kode

### 1. **Inisialisasi Pencahayaan**
```cpp
void initLighting() {
    glEnable(GL_LIGHTING); // Mengaktifkan sistem pencahayaan
    glEnable(GL_LIGHT0);   // Mengaktifkan lampu default
    ...
}
```
Bagian ini menginisialisasi pencahayaan pada scene. **GL_LIGHT0** digunakan sebagai sumber cahaya dengan intensitas dan posisi yang sudah diatur.

### 2. **Menggambar Kubus Besar**
```cpp
void drawLargeCube() {
    GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    ...
    glBegin(GL_QUADS);
    // Menggambar sisi-sisi kubus
    glEnd();
}
```
Fungsi ini menggambar kubus besar dengan ukuran yang sudah ditentukan. **Material kubus** diatur untuk memberikan efek cahaya yang realistis pada objek.

### 3. **Menggambar Kubus Kecil**
```cpp
void drawSmallCube() {
    ...
    glScalef(0.5f, 0.5f, 0.5f); // Perkecil ukuran kubus
    ...
}
```
Kubus kecil ini diletakkan di atas kubus besar dan diukur ulang menggunakan fungsi **glScalef()**.

### 4. **Menggambar LED Biru**
```cpp
void drawLED() {
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru
    glBegin(GL_QUADS);
    // Menggambar persegi kecil menyerupai LED
    glEnd();
}
```
Fungsi ini menggambar persegi kecil berwarna biru di atas kubus kecil. Persegi ini berfungsi sebagai "LED" dekoratif di dalam scene.

### 5. **Fungsi Display**
```cpp
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Membersihkan buffer
    ...
    drawLargeCube(); // Gambar kubus besar
    drawSmallCube(); // Gambar kubus kecil
    drawLED();       // Gambar LED biru
    ...
}
```
Fungsi ini bertanggung jawab untuk menggambar seluruh objek ke layar, termasuk kubus besar, kubus kecil, dan persegi LED.

### 6. **Interaksi Keyboard**
```cpp
void keyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:    // Rotasi ke atas
            angleX += 2.0f;
            break;
        case GLUT_KEY_DOWN:  // Rotasi ke bawah
            angleX -= 2.0f;
            break;
        case GLUT_KEY_LEFT:  // Rotasi ke kiri
            angleY -= 2.0f;
            break;
        case GLUT_KEY_RIGHT: // Rotasi ke kanan
            angleY += 2.0f;
            break;
    }
    glutPostRedisplay(); // Render ulang
}
```
Bagian ini memungkinkan pengguna untuk memutar kubus dengan menggunakan tombol panah pada keyboard. **GLUT_KEY_UP**, **GLUT_KEY_DOWN**, **GLUT_KEY_LEFT**, dan **GLUT_KEY_RIGHT** digunakan untuk mengatur rotasi pada sumbu X dan Y.

