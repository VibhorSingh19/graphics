
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

void bresenham_circle() {

    int x = 0, y = radius;
    int pk = 3 - (2 * radius);

    plot_point(x, y);
    int k;
    while(x < y) {
        x = x + 1;
        if(pk < 0)
            pk = pk + 2 * x + 1;
        else {
            y = y - 1;
            pk = pk + 2 * (x - y) + 1;
        }
        plot_point(x, y);
    }
    glFlush();

}




void display() {

    
    bresenham_circle();

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
