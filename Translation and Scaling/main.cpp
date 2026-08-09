#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);

        glVertex2f(0.0,1.0);
        glVertex2f(0.0,-1.0);

        glVertex2f(-1.0,0.0);
        glVertex2f(1.0,0.0);

    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);

        glVertex2f(-0.8,-0.6);
        glVertex2f(-0.4,-0.6);
        glVertex2f(-0.6,-0.2);

    glEnd();

    glPushMatrix();

        glTranslatef(-0.1,0.5,0.5);
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_TRIANGLES);

            glVertex2f(-0.8,-0.2);
            glVertex2f(-0.4,-0.2);
            glVertex2f(-0.6,0.2);

        glEnd();

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0.50,0.50,0.50);
        glScalef(2.0,2.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);

            glVertex2f(-0.15,-0.10);
            glVertex2f( 0.15,-0.10);
            glVertex2f( 0.00, 0.15);

        glEnd();

    glPopMatrix();

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(700,700);
    glutCreateWindow("Translation and Scaling");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
