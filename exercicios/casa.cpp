#include <GL/glut.h>

GLdouble posCasa = 0;
GLdouble rotTelhado = 0;
GLdouble escalaPorta = 1.0;

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    // CASA
    glTranslatef(posCasa, 0, 0);

    // Corpo
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-30, -20);
        glVertex2f(-30, 20);
        glVertex2f(30, 20);
        glVertex2f(30, -20);
    glEnd();
    glPopMatrix();

    // Telhado
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(rotTelhado, 0, 0, 1);
    glBegin(GL_TRIANGLES);
      glVertex2f(-35, 20);
      glVertex2f(0, 50);
      glVertex2f(35, 20);
    glEnd();
    glPopMatrix();

    // Porta
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.0);
    glScalef(escalaPorta, escalaPorta, escalaPorta);
    glBegin(GL_QUADS);
      glVertex2f(-8, -20);
      glVertex2f(-8, 5);
      glVertex2f(8, 5);
      glVertex2f(8, -20);
    glEnd();
    glPopMatrix();    
    glutSwapBuffers();
    glPopMatrix();
}

void specialkeys(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_UP:
      rotTelhado += 5;
      break;
    case GLUT_KEY_DOWN:
      rotTelhado -= 5;
      break;
    case GLUT_KEY_LEFT:
      posCasa -= 5;
      posCasa = (posCasa < -30) ? -30 : posCasa;
      break;
    case GLUT_KEY_RIGHT:
      posCasa += 5;
      posCasa = (posCasa > 30) ? 30 : posCasa;
      break;
  }
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {

        case '+':
            escalaPorta += 0.1;
            break;

        case '-':
            escalaPorta -= 0.1;
            if(escalaPorta < 0.2)
                escalaPorta = 0.2;
            break;

        case 27:
            exit(0);
    }

    glutPostRedisplay();
}
void init() {

    glClearColor(1, 1, 1, 1);

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
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}