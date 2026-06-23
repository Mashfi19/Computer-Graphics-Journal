#include <windows.h>
#include <GL/glut.h>


void display ()
{
glClear (GL_COLOR_BUFFER_BIT);
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2f(0.0f,  1.0f);
        glVertex2f(0.0f, -1.0f);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f( 1.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0, 1, 0);
        glVertex2f(0.4,0.4);
        glVertex2f(0.8, 0.8);
    glEnd();

    glBegin(GL_POINTS);
        glColor3f(1, 1, 1);
        glVertex2f(-0.5,0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0, 0.5, 0.5);
        glVertex2f(0.6,-0.3);
        glVertex2f(0.4,-0.3);
        glVertex2f(0.6,-0.6);
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.51, 0.31, 0.31);
        glVertex2f(-0.8,-0.25);
        glVertex2f(-0.8,-0.75);
        glVertex2f(-0.4,-0.75);
        glVertex2f(-0.4,-0.25);

    glEnd();


glFlush();
}


    int main (int argc, char** argv) {
        glutInit(&argc, argv);
        glutCreateWindow("Vertex, Primitive & Color");
        glutInitWindowSize(350,350);
        glutDisplayFunc(display);
        glutMainLoop();


return 0;
}
