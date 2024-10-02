#include <GL/glew.h>
#include <GL/freeglut.h>

// Display list ID for the stool leg.
GLuint legDisplayList;

// Function to create the leg display list as a cylinder.
void createLeg() {
    legDisplayList = glGenLists(1);
    glNewList(legDisplayList, GL_COMPILE);

    GLUquadric *quadric = gluNewQuadric();

    // Draw the side of the cylinder (brown).
    glColor3f(0.54f, 0.27f, 0.07f); // Brown color
    gluCylinder(quadric, 0.3, 0.3, 5.0, 32, 32);

    // Draw the top face (yellow).
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 5.0f); // Move to the top of the cylinder
    gluDisk(quadric, 0.0, 0.3, 32, 32); // Draw the top disk
    glPopMatrix();

    gluDeleteQuadric(quadric);
    glEndList();
}

// Function to draw the seat as a cylindrical shape.
void drawSeat() {
    GLUquadric *quadric = gluNewQuadric();

    glColor3f(0.54f, 0.27f, 0.07f); // Brown color for the seat
    glRotatef(80.0, 1.0, 0.0, 0.0);
    glRotatef(180.0, 1.0, 0.0, 0.0);
    gluCylinder(quadric, 2.0, 2.0, 0.5, 32, 32); // Cylindrical seat with the same diameter as the top and height of 0.5

    // Draw the top face of the seat.
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, -1.0f, 0.0f); // Move to the top of the seat
    // glRotatef(0.0, 1.0, 0.0, 0.0);
    gluDisk(quadric, 0.0, 1.8, 32, 32); // Top disk of the seat
    glPopMatrix();

    gluDeleteQuadric(quadric);
}

// Function to draw the stool.
void drawStool() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw the stool's seat (cylinder)
    glPushMatrix();
    glTranslatef(0.0, 2.5, 0.0); // Position above the legs
    drawSeat(); // Call the seat drawing function
    glPopMatrix();

    // Draw 3 legs
    for (int i = 0; i < 3; ++i) {
        glPushMatrix();
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glRotatef(i * 120.0, 0.0, 0.0, 1.0); // Rotate for each leg
        glTranslatef(0.0, -1.5, 1.0); // Move each leg to the correct position
        glCallList(legDisplayList); // Draw the leg
        glPopMatrix();
    }

    glutSwapBuffers();
}

// Initialization routine.
void setup(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set background color to white.
    glEnable(GL_DEPTH_TEST);          // Enable depth testing.

    // Create the leg display list.
    createLeg();
}

// OpenGL window reshape routine.
void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // Escape key.
        exit(0);
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Three-legged Stool with Cylindrical Seat and Legs");

    glewInit();
    setup();

    glutDisplayFunc(drawStool);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glutMainLoop();
    return 0;
}
