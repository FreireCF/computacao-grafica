#include <GL/glut.h>
#include <math.h>
#include <cmath>

GLfloat posTanque = 0;
GLfloat rotTorre = 0;
GLfloat rotCanhao = 0;
GLfloat rotRodas = 0;

void init() {
    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-100, 100, -100, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    // CORPO
    glPushMatrix();
    glTranslatef(posTanque, 0, 0);
    glColor3f(0, 0.5, 0);
    glBegin(GL_QUADS);
        glVertex2f(-40, -10);
        glVertex2f(-40, 10);
        glVertex2f(40, 10);
        glVertex2f(40, -10);
    glEnd();

    // TORRE
    glPushMatrix();
    glColor3f(0, 0.7, 0);
    glTranslatef(0, 20, 0);
    glRotatef(rotTorre, 0, 0, 1);
    glTranslatef(0, -20, 0);
    glBegin(GL_QUADS);
        glVertex2f(-15, 10);
        glVertex2f(-15, 30);
        glVertex2f(15, 30);
        glVertex2f(15, 10);
    glEnd();

    // CANHÃO
    glColor3f(0.2, 0.2, 0.2);
    glTranslatef(15, 20 ,0);
    glRotatef(rotCanhao, 0, 0, 1);
    glTranslatef(-15, -20, 0);
    glBegin(GL_QUADS);
        glVertex2f(15, 18);
        glVertex2f(15, 22);
        glVertex2f(60, 22);
        glVertex2f(60, 18);
    glEnd();
    glPopMatrix();

    //RODA ESQ
    glPushMatrix();
      glColor3f(0, 0, 0);
      glTranslatef(-25, -18, 0);
      glutSolidTorus(1.7, 8, 20, 30);
    glPopMatrix();

    // RODA DIR
    glPushMatrix();
      glColor3f(0, 0, 0);
      glTranslatef(25, -18, 0);
      glutSolidTorus(1.7, 8, 20, 30);
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}


void specialkeys(int key, int x, int y) {

    switch (key) {

        case GLUT_KEY_UP:
          rotCanhao += 5;
          break;

        case GLUT_KEY_DOWN:
          rotCanhao -= 5;
          break;

        case GLUT_KEY_LEFT:
          posTanque -= 5;
          posTanque = (posTanque > 30) ? 30 : posTanque;
          rotRodas -= 5;
          break;

        case GLUT_KEY_RIGHT:
          posTanque += 5;
          posTanque = (posTanque > 30) ? 30 : posTanque;
          rotRodas += 5;
          break;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {

        case 'a':
            rotTorre += 5;
            break;

        case 'd':
            rotTorre -= 5;
            break;

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Braco Robotico");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}