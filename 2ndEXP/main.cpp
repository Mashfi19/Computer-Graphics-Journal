#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex2f(0.0f,  1.0f);
        glVertex2f(0.0f, -1.0f);

        glVertex2f(-1.0f, 0.0f);
        glVertex2f( 1.0f, 0.0f);
    glEnd();



    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

        glVertex2f(-0.85, 0.75);
        glVertex2f(-0.45, 0.75);

        glVertex2f(-0.45, 0.75);
        glVertex2f(-0.45, 0.25);

        glVertex2f(-0.45, 0.25);
        glVertex2f(-0.85, 0.25);

        glVertex2f(-0.85, 0.25);
        glVertex2f(-0.85, 0.75);

    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.30,0.75);
        glVertex2f(0.70,0.75);
        glVertex2f(0.50,0.35);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);

        glVertex2f(-0.65,-0.10);
        glVertex2f(-0.45,-0.25);
        glVertex2f(-0.45,-0.55);
        glVertex2f(-0.65,-0.70);
        glVertex2f(-0.85,-0.55);
        glVertex2f(-0.85,-0.25);

    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);

        glVertex2f(0.25,-0.25);
        glVertex2f(0.75,-0.40);
        glVertex2f(0.25,-0.55);

    glEnd();

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(750,750);
    glutCreateWindow("Vertex, Primitive & Color");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
