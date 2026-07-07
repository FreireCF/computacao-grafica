#include <GL/glut.h>

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex2f(-35, 10); //ESQ 

    glColor3f(0,0,1);
    glVertex2f(0, 50); //BASE

    glColor3f(1,0,0); 
    glVertex2f(35, 10); // DIR
  glEnd();

  glutSwapBuffers();
}

void init() {
    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-100, 100, -100, 100);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Casa");

    init();

    glutDisplayFunc(display);
    /*glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keyboard);*/

    glutMainLoop();

    return 0;
}