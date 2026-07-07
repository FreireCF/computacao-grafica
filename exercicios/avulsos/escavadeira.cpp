#include <GL/glut.h>
#include <stdlib.h>

GLfloat rotBraco = 0;
GLfloat rotAntebraco = 0;
GLfloat rotGarra = 0;

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

    glLoadIdentity();

    // TODO: implementar as transformações
    glPushMatrix();

    // BASE
    glRotatef(rotBraco, 0, 0, 1);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
        glVertex2f(-20, -80);
        glVertex2f(-20, -60);
        glVertex2f(20, -60);
        glVertex2f(20, -80);
    glEnd();

    // BRAÇO SUPERIOR
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(-5, -60);
        glVertex2f(-5, 0);
        glVertex2f(5, 0);
        glVertex2f(5, -60);
    glEnd();

    // ANTEBRAÇO
    glRotatef(rotAntebraco, 0, 0, 1);
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
        glVertex2f(-5, 0);
        glVertex2f(-5, 50);
        glVertex2f(5, 50);
        glVertex2f(5, 0);
    glEnd();

    // GARRA ESQ
    glPushMatrix();
    glRotatef(rotGarra, 0, 0, 1);
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
      glVertex2f(-15, 50);
      glVertex2f(-15, 70);
      glVertex2f(-10, 70);
      glVertex2f(-10, 50);
    glEnd();
    glPopMatrix();

    // GARRA DIR
    glPushMatrix();
    glRotatef(-rotGarra, 0, 0, 1);
    glBegin(GL_QUADS);
        glVertex2f(10, 50);
        glVertex2f(10, 70);
        glVertex2f(15, 70);
        glVertex2f(15, 50);
    glEnd();
    glPopMatrix();
  
    glPopMatrix();

    glutSwapBuffers();
}

void specialkeys(int key, int x, int y) {

    switch (key) {

        case GLUT_KEY_UP:
            rotAntebraco += 5;
            break;

        case GLUT_KEY_DOWN:
            rotAntebraco -= 5;
            break;

        case GLUT_KEY_LEFT:
            rotBraco -= 5;
            break;

        case GLUT_KEY_RIGHT:
            rotBraco += 5;
            break;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {

        case 'a':
            rotGarra += 5;
            break;

        case 'd':
            rotGarra -= 5;
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
    glutCreateWindow("Escavadeira");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}