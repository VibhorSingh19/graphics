#include<GL/glut.h>
#include<GL/gl.h>

void display()
{
   glClear( GL_COLOR_BUFFER_BIT);
   glBegin(GL_POINTS);
   glColor3f( 1.0f,1.0f,1.0f );
   glVertex2f(-0.75f,0.75f);
   glVertex2f(-0.85f,0.65f );
   glVertex2f(-0.85f,0.5f );
   glVertex2f(-0.75f,0.48f );
   glVertex2f(-0.65f,0.5f);
   glVertex2f(-0.65f,0.65f);
   glEnd();

   glBegin(GL_LINE_STRIP);
   glColor3f(0.0f,1.0f,0.0f);
   glVertex2f(-0.45,0.65);
    glVertex2f(-0.25,0.65);
    glVertex2f(-0.08,0.75);
    glVertex2f(-0.25,0.5);
   glVertex2f(-0.5,0.5);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.5f,1.0f,0.5f);
   glVertex2f(0.65f,0.25f);
   glVertex2f(0.90f,-0.20f);
   glVertex2f(0.50f,-0.20f);
   glEnd();



   glBegin(GL_LINE_LOOP);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.78f,0.0f);
   glVertex2f(-0.75f,-0.15f);
   glVertex2f(-0.65f,-0.20f);
   glVertex2f(-0.50f,-0.15f);
   glVertex2f(-0.40f,0.0f);
   glVertex2f(-0.47f,0.20);
   glVertex2f(-0.60f,0.25);
   glVertex2f(-0.75f,0.15f);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3f(1.0f,0.5f,0.0f);
   glVertex2f(0.15f,0.45f);
   glVertex2f(0.40f,0.30f);
   glVertex2f(0.40f,0.0f);
   glVertex2f(0.15f,-0.15f);
   glVertex2f(-0.20f,0.0f);
   glVertex2f(-0.20f,0.25f);
   glEnd();
   
   


   glBegin(GL_QUADS);
   glColor3f(0.0f,0.0f,1.0f);
   glVertex2f(0.15f,0.75);
   glVertex2f(0.15f,0.5);
   glVertex2f(0.65f,0.5);
   glVertex2f(0.65f,0.75);
   glEnd();


   glFlush();
 }


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(200,200);
  glutCreateWindow("Primitives");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


