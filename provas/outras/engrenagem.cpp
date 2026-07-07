#include <GL/glut.h>

#include <stdlib.h>

float angMain = 0;
float angSide = 0;
float slider_pos = 0;

void drawGear() {
    //glutSolidTorus(1, 5, 20, 20);

    // corpo da engrenagem
    glColor3f(0.7, 0.7, 0.7);
    glutSolidTorus(1, 6, 20, 20);

    // dentes (marcas visuais)
    for(int i = 0; i < 12; i++) {

        glPushMatrix();

        float angle = i * 30.0f; // 360 / 12

        glRotatef(angle, 0, 1, 0);
        glTranslatef(7, 0, 0);

        glColor3f(0.3, 0.3, 0.3);
        glutSolidCube(1);

        glPopMatrix();
    }
}

void drawMachine() {

    // eng central
    glPushMatrix();
      glColor3f(1, 0.8, 0);
      glRotatef(angMain, 0, 1, 0);
    drawGear();
    glPopMatrix();
   
    glPushMatrix();
      glColor3f(0.8, 0.2, 0.2);
      glTranslatef(-15, 0, 0);
      glRotatef(-angMain, 0, 1, 0);
      drawGear();
    glPopMatrix();

    // engr direita
    glPushMatrix();
      glColor3f(0.2, 0.2, 0.8);
      glTranslatef(15, 0, 0);
      glRotatef(-angMain, 0, 1, 0);
      drawGear();
    glPopMatrix();

    //peça
    glPushMatrix();
      glColor3f(0.2, 0.8, 0.2);
      glTranslatef(-60, 0, 0 );
      glTranslatef(slider_pos, -10, 0);
      glScalef(3, 1, 1);
      glutSolidCube(3);
    glPopMatrix();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
        0, 30, 60,
        0, 0, 0,
        0, 1, 0
    );

    drawMachine();

    glutSwapBuffers();
}

void update(int value) {

    angMain+=2;
    slider_pos+=1;

    if(slider_pos > 120){
      slider_pos = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

void keyboard(unsigned char key, int x, int y) {

    if(key == 27)
        exit(0);
}

void init() {

    glClearColor(0.1, 0.1, 0.1, 1);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {

    if(h == 0) h = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, (float)w/h, 1, 500);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);

    glutCreateWindow("Animador Mecânico 3D");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(30, update, 0);

    glutMainLoop();

    return 0;
}