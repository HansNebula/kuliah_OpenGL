#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    
    GLfloat vertices[] = {
        0.0f,  0.5f, 0.0f,  
        0.43f,  0.25f, 0.0f,  
        0.43f, -0.25f, 0.0f,  
        0.0f, -0.5f, 0.0f,  
        -0.43f, -0.25f, 0.0f,  
        -0.43f,  0.25f, 0.0f   
    };

    
    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,  
        0.0f, 1.0f, 0.0f,  
        0.0f, 0.0f, 1.0f,  
        1.0f, 1.0f, 0.0f,  
        1.0f, 0.0f, 1.0f,  
        0.0f, 1.0f, 1.0f   
    };

    
    GLubyte indices[] = {
        0, 1, 2,   
        0, 2, 3,   
        0, 3, 4,   
        0, 4, 5    
    };

    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, indices);

    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  
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
