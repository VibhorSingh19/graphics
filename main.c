#include <GL/glut.h>
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,1,0);
 glBegin(GL_TRIANGLES);
 glVertex2f(-0.5,-0.5);
 glVertex2f(0.5,-0.5);
 glVertex2f(0,0.5);
 glEnd();
 glColor3f(1,1,1);
 glRasterPos2f(-0.70,-0.70);
 //glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Vibhor Singh Roll no. 185");
 glFlush();
}
int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Green Triangle");

 
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
