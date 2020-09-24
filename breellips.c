
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



void bresenham_ellipse() {

    float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = ry; 
  
    // Region 1
    d1 = (ry * ry) - (rx * rx * ry) + ((1/4) * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
   
    while (dx < dy) {  
        draw_point( x + xc, y + yc); 
        draw_point( -x + xc, y + yc); 
        draw_point( x + xc, -y + yc); 
        draw_point( -x + xc, -y + yc); 
  
        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        } 
    } 
    // Region 2 
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry); 
  
    while (y >= 0) { 

        draw_point( x + xc, y + yc); 
        draw_point( -x + xc, y + yc); 
        draw_point( x + xc, -y + yc); 
        draw_point( -x + xc, -y + yc); 
  
        if (d2 > 0) { 
            y--; 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + (rx * rx) - dy; 
        } 
        else { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        } 
    } 
    
}


void display() {

    bresenham_ellipse();
    glFlush();

}



int main(int argc, char **argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700, 900);


    printf("Enter center co-ordinates: ");
    scanf("%d %d", &xc, &yc);

    
        glutInitWindowSize(1200, 1200);
        printf("Enter Major and Minor axis: ");
        scanf("%d %d", &rx, &ry);

    glutCreateWindow("LAB - 5");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
