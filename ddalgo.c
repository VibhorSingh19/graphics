#include <GL/glut.h>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
void init()
{
    gluOrtho2D(-20,20,-20,20);
}
float roundOff(float v)
{
  return floor(v + 0.5);
}
void display(void)
{
    double step;
    float x1,y1,x2,y2; 
    printf("Enter x1,y1,x2,y2\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    double dx=(x2-x1);
    double dy=(y2-y1);
    float xInc,yInc,x=x1,y=y1;
    if(abs(dx)>abs(dy))
    step=abs(dx);
    else
    step=abs(dy);
    xInc=dx/(float)step;
    yInc=dy/(float)step;
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x,y);
    int i;
    for(i=0;i<step;i++)
    {
       x+=xInc;
       y+=yInc;
       glVertex2d(roundOff(x), roundOff(y));
  }
    glEnd();
    glFlush();
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DD_ALGO _VIBHOR_185");
    gluOrtho2D(-20,20,-20,20);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
