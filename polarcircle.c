
#include<stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

int xc, yc, radius, rx, ry;
int choice;

void init() {
  gluOrtho2D(0, 300, 0, 300);
}

void draw_point(int x, int y) {
   glBegin(GL_POINTS);
        glVertex2i(x, y);
   glEnd();
   glFlush();
}

void plot_point(int x, int y) {

    glBegin(GL_POINTS);
        glVertex2i(x+xc, y+yc);  
        glVertex2i(x+xc, -y+yc);  
        glVertex2i(-x+xc, -y+yc);  
        glVertex2i(-x+xc, y+yc);  
        glVertex2i(y+xc, x+yc);  
        glVertex2i(y+xc, -x+yc);  
        glVertex2i(-y+xc, -x+yc);  
        glVertex2i(-y+xc, x+yc);  
    glEnd();

}



void polar_circle() {
    
    glBegin(GL_POINTS);
        for (float angle = 1.0; angle < 361.0; angle += 0.2){
            float x2 = xc + sin(angle) * radius;
            float y2 = yc + cos(angle) * radius;
            glVertex2f(x2,y2);
        }
    glEnd();
}



void display() {

    polar_circle();
    glFlush();

}

int main(int argc, char **argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700, 900);

    printf("Enter center co-ordinates: ");
    scanf("%d %d", &xc, &yc);

    
        glutInitWindowSize(700, 900);
        printf("Enter radius value: ");
        scanf("%d", &radius);
        
    glutCreateWindow("LAB - 5");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
