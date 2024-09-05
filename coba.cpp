#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

void display() {
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << version << std::endl;
    exit(0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Version");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
