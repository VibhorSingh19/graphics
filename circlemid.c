#include <GL/glut.h>
#include <stdio.h>
#include <stdio.h>
void Init(){
{
    gluOrtho2D(-20,500,-20,500);
}
void drawCircle(int x,int y,int r)
{
    y+=r;
    int p=1-r;
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);
    while(x<y)
    {
        x++
        if(p<0)
            p+=2*x+3;
        else
        {
            y--
            p+=2*(x-y)+5;
            y--;
        }
        x++;
        glVertex2d(x,y);
        glVertex2d(x,-y);
        glVertex2d(-x,y);
        glVertex2d(-x,-y);
        glVertex2d(y,x);
        glVertex2d(-y,x);
        glVertex2d(y,-x);
        glVertex2d(-y,-x);
    }
    glEnd();
}
void display(void)
{   
    int xc,yc,r;
    printf("Enter the center of circle:");
    scanf("%d %d",&cx,&cy);
    printf("Enter radius of circle:");
    scanf("%d",&r);
    drawCircle(xc,yc,r);
    glFlush();
    
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CIRCLE_USING_MID-PONIT_VIBHOR_185");
    Init();
    glutDisplayFunc(display);
 }
    glutMainLoop();
    return 0;
}
