 
#include<math.h>
#include <GL/glut.h>  
 
int day = 0;
int night = 0;
int check = 0;


void initGL() {
    
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 

    glEnable(GL_COLOR_MATERIAL);
}

void circle(float x, float y, double c){

    float x1, y1;
    glBegin(GL_POLYGON);
    for(int i = 0; i < 200; i++){
        float pi = 3.1416;
        float A = (1*2*pi)/25;
        x1 = x + ((c - 0.07) * cos(A));
        y1 = y + (c * sin(A));
        glVertex2f(x1, y1);
    }
    glEnd();
}
void mouseClicks(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON) 
         exit(0);
}

void keyboard(unsigned char key, int x, int y){

    
    if( key == 'n' || key == 'N') 
        night = 1;

}

void sky(){
    glColor4f(0.0, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-1.0, 0.2);
        glVertex2f(-1.0, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, 0.2);
    glEnd();
}

void river(){
    glColor3f(0.118, 0.565, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -1.0);
        glVertex2f(-1.0, -0.5);
        glVertex2f(1.0, -0.1);
        glVertex2f(1.0, -1.0);
    glEnd();
}

void field(){
    glColor3f(0.420, 0.557, 0.137);
    glBegin(GL_QUADS);
        glVertex2f(-1.0, 0.2);
        glVertex2f(-1.0, -0.5);
        glVertex2f(1.0, -0.1);
        glVertex2f(1.0, 0.2);
    glEnd();
}

void hill(){
    glColor3f(0.427, 0.322, 0.176);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, 0.2);
        glVertex2f(-0.38, 0.8);
        glVertex2f(-0.6, 0.2);
    glEnd();  

    glColor3f(0.427, 0.322, 0.176);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05, 0.2);
        glVertex2f(-0.38, 0.9);
        glVertex2f(-0.6, 0.2);
    glEnd();  

    

    

}





void house2(){

    glColor3f(0.427, 0.322, 0.176);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.15, 0.12);
        glVertex2f(0.51, 0.12);
        glVertex2f(0.33, 0.26);
    glEnd();  

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(0.19, -0.20);
        glVertex2f(0.19, 0.12);
        glVertex2f(0.47, 0.12);
        glVertex2f(0.47, -0.20);
    glEnd(); 

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(0.25, -0.20);
        glVertex2f(0.25, 0.05);
        glVertex2f(0.41, 0.05);
        glVertex2f(0.41, -0.20);
    glEnd(); 
}




void tree2(){

    glColor3f(0.38, 0.19, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05, -0.30);
        glVertex2f(-0.05, -0.12);
        glVertex2f(-0.07, -0.12);
        glVertex2f(-0.07, -0.30);
    glEnd();  

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.16, -0.12);
        glVertex2f(-0.06, 0.12);
        glVertex2f(0.06, -0.12);
    glEnd();  

    glBegin(GL_POLYGON);  
       glVertex2f(-0.16, -0.04);
        glVertex2f(-0.06, 0.20);
        glVertex2f(0.06, -0.04);
    glEnd();  

    glBegin(GL_POLYGON);
        glVertex2f(-0.16, 0.04);
        glVertex2f(-0.06, 0.20);
        glVertex2f(0.06, 0.04);
    glEnd();  

}


void sun(){

    float x1, y1, x2, y2;
    float angle;
    double radius = 0.1;

    x1 = 0.3,y1 = 0.4;
    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);

    for (angle = 1.0; angle < 361.0; angle += 0.2){
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2,y2);
    }

    glEnd();

}

void moon(){

    float x1, y1, x2, y2;
    float angle;
    double radius = 0.1;

    x1 = 0.3, y1 = 0.4;
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);

    for (angle = 1.0; angle < 361.0; angle += 0.2){
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2,y2);
    }

    glEnd();

}

void display() {
   glClear(GL_COLOR_BUFFER_BIT); 
   
   sky();
   field();
   river();
   hill();
      house2();
   tree2();
   sun();
   
    if(day == 1){
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        sun();
    }
    if(night == 1){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        moon();
    }
      
   glutSwapBuffers();
   glFlush();

}

void update(int value){
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);          
   glutCreateWindow("EXP 3");  
   glutInitWindowSize(1000, 1000);   
   glutInitWindowPosition(500, 500); 
   glutDisplayFunc(display); 
   glutKeyboardFunc(keyboard);  
   glutMouseFunc(mouseClicks);  
   initGL();         
   glutTimerFunc(25, update, 0);              
   glutMainLoop();               
   return 0;
}
