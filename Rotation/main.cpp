#include <windows.h>
#include <GL/glut.h>

GLfloat angle = 0.0f;

void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Idle()
{
    angle += 0.15f;

    if(angle >= 360.0f)
        angle = 0.0f;

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);

        glVertex2f(-1.0f,0.0f);
        glVertex2f( 1.0f,0.0f);

        glVertex2f(0.0f,-1.0f);
        glVertex2f(0.0f, 1.0f);

    glEnd();

    glPushMatrix();

        glRotatef(angle,0.0f,0.0f,1.0f);
        glColor3f(0.5f,0.3f,0.80f);
        glBegin(GL_TRIANGLES);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.70f, 0.30f);
            glVertex2f(0.50f,0.60f);

        glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Triangle Rotation");
    initGL();
    glutDisplayFunc(display);
    glutIdleFunc(Idle);
    glutMainLoop();

    return 0;
}
