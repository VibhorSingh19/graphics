#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init()
{
    gluOrtho2D(-20,20,-20,20);//1.0 1.0 1.0 
}
void display(void)
{
    float x1,y1,x2,y2; 
    printf("Enter x1,y1,x2,y2\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    double m = 0.0;             
    double c = (y1 - m*x1);     
    double j = y1;              
    if (x2-x1 == 0)
        m = 0;
    else 
        m = (y2-y1)/(x2-x1);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i=x1;i<x2;i++)
    {    
        j=(m*i+c);        
        glVertex2f(i,j);
    }
    glEnd();
    glFlush();
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    gluOrtho2D(-20,20,-20,20);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
