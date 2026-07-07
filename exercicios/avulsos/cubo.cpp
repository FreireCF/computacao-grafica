#include <GL/glut.h>
#include <stdlib.h>

// Variaveis de transformacao - UTILIZE ESTAS VARIAVEIS
GLdouble pos_x = 0;      // posicao no eixo X
GLdouble pos_y = 0;      // posicao no eixo Y
GLdouble escala = 1.0;   // fator de escala uniforme
GLdouble angulo = 0;     // angulo de rotacao em graus

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // =============================================
  // TODO: Aplique as transformacoes corretas e
  //       desenhe a cena conforme solicitado.
  //       Modifique apenas esta funcao e configView.
  // =============================================

  glPushMatrix();

    glScalef(escala, escala, escala);

    glTranslatef(0, pos_y, 0);
    
    glTranslatef(pos_x, 0,  0);

    glRotatef(angulo, 0, 1, 0);
    
    glColor3f(0, 0.22, 1);
    glutSolidCube(30);

  glPopMatrix();

  glutSwapBuffers();
}

void configView() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glViewport(0, 0, 800, 600);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // TODO: configure a projecao e a camera corretamente
  gluPerspective(45, 800 / 600.0, 0.5, 500);
  //glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(100, 80, 100, 0, 0, 0, 0, 1, 0);

  glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27: exit(0); break;
    case 'a': case 'A': pos_x -= 2; break;
    case 'd': case 'D': pos_x += 2; break;
    case 'w': case 'W': pos_y += 2; break;
    case 's': case 'S': pos_y -= 2; break;
    case '+': escala += 0.1; break;
    case '-': escala -= 0.1; if (escala < 0.1) escala = 0.1; break;
    case 'r': case 'R': angulo += 5; break;
    case 'l': case 'L': angulo -= 5; break;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Avaliacao CG - Transformacoes");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  glutMainLoop();
  return 0;
}