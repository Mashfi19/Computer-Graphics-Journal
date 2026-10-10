#include <windows.h>
#include <GL/glut.h>

GLfloat position1X = -1.20f;
GLfloat position1Y = -0.65f;

GLfloat position2X = 1.20f;
GLfloat position2Y = 0.65f;

GLfloat speed1 = 0.02f;
GLfloat speed2 = 0.02f;

int moveAircraft1 = 1;
int moveAircraft2 = 1;

void update(int value)
{
    if(moveAircraft1 == 1)
    {
        position1X += speed1;
        position1Y += speed1;

        if(position1X > 1.25f || position1Y > 1.0f)
        {
            position1X = -1.25f;
            position1Y = -0.70f;
        }
    }

    if(moveAircraft2 == 1)
    {
        position2X -= speed2;
        position2Y -= speed2;

        if(position2X < -1.25f || position2Y < -0.90f)
        {
            position2X = 1.25f;
            position2Y = 0.80f;
        }
    }


    glutPostRedisplay();

    glutTimerFunc(30, update, 0);
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
        case 'W':
            moveAircraft1 = 1;
            break;

        case 's':
        case 'S':
            moveAircraft1 = 0;
            break;
    }

    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        switch(button)
        {
            case GLUT_RIGHT_BUTTON:
                moveAircraft2 = 1;
                break;

            case GLUT_LEFT_BUTTON:
                moveAircraft2 = 0;
                break;
        }
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.35f, 0.60f, 0.85f, 1.0f);
}

void aircraft()
{
    glColor3f(0.92f, 0.92f, 0.92f);
    glBegin(GL_QUADS);

        glVertex2f(-0.22f, -0.035f);
        glVertex2f( 0.22f, -0.035f);
        glVertex2f( 0.22f,  0.035f);
        glVertex2f(-0.22f,  0.035f);

    glEnd();


    glColor3f(0.85f, 0.85f, 0.88f);
    glBegin(GL_TRIANGLES);

        glVertex2f(0.22f, -0.035f);
        glVertex2f(0.38f,  0.0f);
        glVertex2f(0.22f,  0.035f);

    glEnd();


    glColor3f(0.20f, 0.35f, 0.65f);
    glBegin(GL_TRIANGLES);

        glVertex2f(-0.02f, 0.03f);
        glVertex2f(-0.18f, 0.20f);
        glVertex2f(0.10f, 0.03f);

    glEnd();


    glBegin(GL_TRIANGLES);

        glVertex2f(-0.02f, -0.03f);
        glVertex2f(-0.18f, -0.20f);
        glVertex2f(0.10f, -0.03f);

    glEnd();

    glColor3f(0.85f, 0.15f, 0.12f);
    glBegin(GL_TRIANGLES);

        glVertex2f(-0.18f, 0.035f);
        glVertex2f(-0.28f, 0.14f);
        glVertex2f(-0.08f, 0.035f);

    glEnd();


    glColor3f(0.05f, 0.20f, 0.35f);
    glBegin(GL_QUADS);

        glVertex2f(-0.12f, 0.01f);
        glVertex2f(-0.08f, 0.01f);
        glVertex2f(-0.08f, 0.035f);
        glVertex2f(-0.12f, 0.035f);

        glVertex2f(-0.05f, 0.01f);
        glVertex2f(-0.01f, 0.01f);
        glVertex2f(-0.01f, 0.035f);
        glVertex2f(-0.05f, 0.035f);

        glVertex2f(0.02f, 0.01f);
        glVertex2f(0.06f, 0.01f);
        glVertex2f(0.06f, 0.035f);
        glVertex2f(0.02f, 0.035f);

        glVertex2f(0.09f, 0.01f);
        glVertex2f(0.13f, 0.01f);
        glVertex2f(0.13f, 0.035f);
        glVertex2f(0.09f, 0.035f);

    glEnd();

    glColor3f(0.35f, 0.35f, 0.38f);
    glBegin(GL_QUADS);

        glVertex2f(-0.02f, -0.10f);
        glVertex2f(0.05f, -0.10f);
        glVertex2f(0.08f, -0.035f);
        glVertex2f(0.00f, -0.035f);

    glEnd();
}

void airport()
{
    glColor3f(0.65f, 0.68f, 0.72f);
    glBegin(GL_QUADS);

        glVertex2f(-0.85f, -0.45f);
        glVertex2f(0.10f, -0.45f);
        glVertex2f(0.10f, 0.05f);
        glVertex2f(-0.85f, 0.05f);

    glEnd();

    glColor3f(0.10f, 0.30f, 0.45f);
    glBegin(GL_QUADS);

        glVertex2f(-0.75f, -0.40f);
        glVertex2f(0.00f, -0.40f);
        glVertex2f(0.00f, -0.02f);
        glVertex2f(-0.75f, -0.02f);

    glEnd();

    glColor3f(0.75f, 0.80f, 0.85f);
    glBegin(GL_LINES);

        glVertex2f(-0.60f, -0.40f);
        glVertex2f(-0.60f, -0.02f);

        glVertex2f(-0.45f, -0.40f);
        glVertex2f(-0.45f, -0.02f);

        glVertex2f(-0.30f, -0.40f);
        glVertex2f(-0.30f, -0.02f);

        glVertex2f(-0.15f, -0.40f);
        glVertex2f(-0.15f, -0.02f);

    glEnd();

    glColor3f(0.25f, 0.27f, 0.30f);
    glBegin(GL_QUADS);

        glVertex2f(-0.90f, 0.05f);
        glVertex2f(0.15f, 0.05f);
        glVertex2f(0.08f, 0.15f);
        glVertex2f(-0.82f, 0.15f);

    glEnd();

    glColor3f(0.20f, 0.22f, 0.25f);
    glBegin(GL_QUADS);

        glVertex2f(-0.40f, -0.45f);
        glVertex2f(-0.22f, -0.45f);
        glVertex2f(-0.22f, -0.15f);
        glVertex2f(-0.40f, -0.15f);

    glEnd();

    glColor3f(0.55f, 0.58f, 0.62f);
    glBegin(GL_QUADS);

        glVertex2f(0.40f, -0.45f);
        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.55f, 0.45f);
        glVertex2f(0.40f, 0.45f);

    glEnd();

    glColor3f(0.08f, 0.25f, 0.38f);
    glBegin(GL_QUADS);

        glVertex2f(0.35f, 0.35f);
        glVertex2f(0.60f, 0.35f);
        glVertex2f(0.60f, 0.50f);
        glVertex2f(0.35f, 0.50f);

    glEnd();

    glColor3f(0.80f, 0.90f, 1.0f);
    glBegin(GL_QUADS);

        glVertex2f(0.38f, 0.38f);
        glVertex2f(0.43f, 0.38f);
        glVertex2f(0.43f, 0.47f);
        glVertex2f(0.38f, 0.47f);

        glVertex2f(0.46f, 0.38f);
        glVertex2f(0.51f, 0.38f);
        glVertex2f(0.51f, 0.47f);
        glVertex2f(0.46f, 0.47f);

        glVertex2f(0.54f, 0.38f);
        glVertex2f(0.58f, 0.38f);
        glVertex2f(0.58f, 0.47f);
        glVertex2f(0.54f, 0.47f);

    glEnd();


    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_QUADS);

        glVertex2f(-0.95f, -0.45f);
        glVertex2f(-0.93f, -0.45f);
        glVertex2f(-0.93f, -0.15f);
        glVertex2f(-0.95f, -0.15f);

        glVertex2f(0.75f, -0.45f);
        glVertex2f(0.77f, -0.45f);
        glVertex2f(0.77f, -0.12f);
        glVertex2f(0.75f, -0.12f);

    glEnd();

    glColor3f(1.0f, 0.90f, 0.30f);
    glBegin(GL_QUADS);

        glVertex2f(-0.98f, -0.15f);
        glVertex2f(-0.90f, -0.15f);
        glVertex2f(-0.90f, -0.08f);
        glVertex2f(-0.98f, -0.08f);

        glVertex2f(0.72f, -0.12f);
        glVertex2f(0.80f, -0.12f);
        glVertex2f(0.80f, -0.05f);
        glVertex2f(0.72f, -0.05f);

    glEnd();

    glColor3f(0.18f, 0.19f, 0.21f);
    glBegin(GL_QUADS);

        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.45f);
        glVertex2f(-1.0f, -0.45f);

    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

        glVertex2f(-0.90f, -0.74f);
        glVertex2f(-0.65f, -0.74f);
        glVertex2f(-0.65f, -0.70f);
        glVertex2f(-0.90f, -0.70f);

        glVertex2f(-0.50f, -0.74f);
        glVertex2f(-0.25f, -0.74f);
        glVertex2f(-0.25f, -0.70f);
        glVertex2f(-0.50f, -0.70f);

        glVertex2f(-0.10f, -0.74f);
        glVertex2f(0.15f, -0.74f);
        glVertex2f(0.15f, -0.70f);
        glVertex2f(-0.10f, -0.70f);

        glVertex2f(0.30f, -0.74f);
        glVertex2f(0.55f, -0.74f);
        glVertex2f(0.55f, -0.70f);
        glVertex2f(0.30f, -0.70f);

        glVertex2f(0.70f, -0.74f);
        glVertex2f(0.95f, -0.74f);
        glVertex2f(0.95f, -0.70f);
        glVertex2f(0.70f, -0.70f);

    glEnd();

    glColor3f(1.0f, 1.0f, 0.8f);
    glBegin(GL_LINES);

        glVertex2f(-1.0f, -0.48f);
        glVertex2f(1.0f, -0.48f);

        glVertex2f(-1.0f, -0.97f);
        glVertex2f(1.0f, -0.97f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    airport();

    glPushMatrix();

        glTranslatef(position1X, position1Y, 0.0f);
        aircraft();

    glPopMatrix();

    glPushMatrix();

        glTranslatef(position2X, position2Y, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
        aircraft();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(900, 700);

    glutCreateWindow("Airport - Aircraft Take Off and Landing");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(handleKeypress);

    glutMouseFunc(handleMouse);

    glutTimerFunc(30, update, 0);

    glutMainLoop();

    return 0;
}
