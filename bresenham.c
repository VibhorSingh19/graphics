#include <GL/glut.h>
#include <stdio.h>
void init()
{
    gluOrtho2D(-20,20,-20,20);
}
void display(void)
{
    float x1,y1,x2,y2,x,y; 
    printf("Enter x1,y1,x2,y2\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    x=x1;
    y=y1;
    double dx=(x2-x1);
    double dy=(y2-y1);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(x,y);
    if((dy/dx)<=1)
    {
    	double p0=2*dy-dx;
    	while(x<x2)
    	{
	     if(p0<=0)
	     p0+=2*dy;
	     else
	     {
	     p0+=2*dy-2*dx; 
	     y=y+1;
	     }
	     x=x+1;
	     glVertex2d(x,y);
    	}
    }
    else
    {
    double p0=2*dx-dy;
    	while(y<y2)
    	{
	     if(p0<=0)
	     p0+=2*dx;
	     else
	     {
	     p0+=2*dx-2*dy; 
	     x=x+1;
	     }
	     y=y+1;
	     glVertex2d(x,y);
    	}
    }
    glEnd();
    glFlush();
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return
 0;
}
