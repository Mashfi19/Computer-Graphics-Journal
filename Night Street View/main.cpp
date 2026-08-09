#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

void display()
{
    glClearColor(0.02,0.02,0.15,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.6);

    float x = 0.75;
    float y = 0.75;
    float r = 0.10;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x,y);
        for(int i=0;i<=100;i++)
        {
            float angle = 2*PI*i/100;
            glVertex2f(x+r*cos(angle), y+r*sin(angle));
        }
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POINTS);

        glVertex2f(-0.80,0.85);
        glVertex2f(-0.55,0.70);
        glVertex2f(-0.20,0.90);
        glVertex2f(0.20,0.75);
        glVertex2f(0.45,0.90);
        glVertex2f(0.90,0.55);

    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);

        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1,-0.45);
        glVertex2f(-1,-0.45);

    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);

        glVertex2f(-0.80,-0.73);
        glVertex2f(-0.60,-0.73);
        glVertex2f(-0.60,-0.70);
        glVertex2f(-0.80,-0.70);

        glVertex2f(-0.30,-0.73);
        glVertex2f(-0.10,-0.73);
        glVertex2f(-0.10,-0.70);
        glVertex2f(-0.30,-0.70);

        glVertex2f(0.20,-0.73);
        glVertex2f(0.40,-0.73);
        glVertex2f(0.40,-0.70);
        glVertex2f(0.20,-0.70);

        glVertex2f(0.70,-0.73);
        glVertex2f(0.90,-0.73);
        glVertex2f(0.90,-0.70);
        glVertex2f(0.70,-0.70);

    glEnd();

    glColor3f(0.25,0.25,0.25);
    glBegin(GL_QUADS);

        glVertex2f(-0.90,-0.45);
        glVertex2f(-0.60,-0.45);
        glVertex2f(-0.60,0.45);
        glVertex2f(-0.90,0.45);

    glEnd();

    glBegin(GL_QUADS);

        glVertex2f(-0.35,-0.45);
        glVertex2f(0.00,-0.45);
        glVertex2f(0.00,0.65);
        glVertex2f(-0.35,0.65);

    glEnd();

    glBegin(GL_QUADS);

        glVertex2f(0.35,-0.45);
        glVertex2f(0.80,-0.45);
        glVertex2f(0.80,0.35);
        glVertex2f(0.35,0.35);

    glEnd();

    glColor3f(1.0,1.0,0.0);
    for(float i=-0.85;i<-0.65;i+=0.10)
    {
        for(float j=-0.30;j<0.35;j+=0.18)
        {
            glBegin(GL_QUADS);
            glVertex2f(i,j);
            glVertex2f(i+0.05,j);
            glVertex2f(i+0.05,j+0.08);
            glVertex2f(i,j+0.08);
            glEnd();
        }
    }

    for(float y = 0.18; y >= -0.22; y -= 0.20)
    {
        for(float x = 0.42; x <= 0.60; x += 0.18)
        {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x+0.06, y);
            glVertex2f(x+0.06, y-0.08);
            glVertex2f(x, y-0.08);
            glEnd();
        }
    }

    glColor3f(0,0,0);
    glBegin(GL_QUADS);

        glVertex2f(-0.20,-0.45);
        glVertex2f(-0.18,-0.45);
        glVertex2f(-0.18,0.10);
        glVertex2f(-0.20,0.10);

    glEnd();

    glColor3f(1,1,0.5);
    glBegin(GL_TRIANGLE_FAN);

        float lx=-0.19, ly=0.15, lr=0.04;

        glVertex2f(lx,ly);

        for(int i=0;i<=40;i++)
        {
            float angle=2*PI*i/40;
            glVertex2f(lx+lr*cos(angle),ly+lr*sin(angle));
        }

    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);

        glVertex2f(0.25,-0.45);
        glVertex2f(0.27,-0.45);
        glVertex2f(0.27,0.10);
        glVertex2f(0.25,0.10);

    glEnd();

    glColor3f(1,1,0.5);

    glBegin(GL_TRIANGLE_FAN);

        lx=0.26;
        ly=0.15;

        glVertex2f(lx,ly);

        for(int i=0;i<=40;i++)
        {
            float angle=2*PI*i/40;
            glVertex2f(lx+lr*cos(angle),ly+lr*sin(angle));
        }

    glEnd();

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(900,650);
    glutCreateWindow("Night Modern Street");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
