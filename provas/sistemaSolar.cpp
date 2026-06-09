#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>

int cam_view = 0;
float earthOrbitAngle = 0.0f;
float earthRotAngle   = 0.0f;
float moonOrbitAngle  = 0.0f;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Sol (fixo na origem)
  glColor3f(1.0f, 1.0f, 0.0f);
//  glutSolidSphere(3.0, 30, 30);
  glutWireSphere(3.4, 30, 30);

  //terra
  glPushMatrix();
    glColor3f(0.2,0.4,1);

    glRotatef(earthOrbitAngle, 0, 1, 0);
    glTranslatef(20, 0, 0);

    glPushMatrix();
      glRotatef(earthRotAngle, 0, 1, 0);
      glutWireSphere(2.4, 30, 30);
    glPopMatrix();

    //lua 
    glPushMatrix();
      glColor3f(0.7, 0.7, 0.7);
      glRotatef(moonOrbitAngle, 0, 1, 0);
      glTranslatef(5.5, 0, 0);
      glutWireSphere(1.0, 30, 30);
    glPopMatrix();

  glPopMatrix();



  // TODO: Desenhar a Terra orbitando o Sol e girando em torno de si mesma
  // - A Terra deve orbitar o Sol a uma distancia de 20 unidades
  // - A Terra deve girar em torno de seu proprio eixo Y
  // - Use earthOrbitAngle para a orbita e earthRotAngle para a rotacao propria
  // - Raio da Terra: 1.2 unidades
  // - Cor da Terra: azul (0.2, 0.4, 1.0)

  // TODO: Desenhar a Lua orbitando a Terra
  // - A Lua deve orbitar a Terra a uma distancia de 3.5 unidades
  // - Use moonOrbitAngle para a orbita da Lua ao redor da Terra
  // - Raio da Lua: 0.4 unidades
  // - Cor da Lua: cinza (0.7, 0.7, 0.7)

  glutSwapBuffers();
}

void change_cam_view() {
  switch (cam_view) {
    case 0:
      // Vista de cima (topo)
      gluLookAt(0, 80, 0, 0, 0, 0, 1, 0, 0);
      break;
    case 1:
      // Vista lateral
      gluLookAt(-80, 30, 0, 0, 0, 0, 0, 1, 0);
      break;
    case 2:
      // Vista em perspectiva
      gluLookAt(-40, 40, 40, 0, 0, 0, 1, 0, 0);
      break;
  }
}

void configView() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 800 / 600.0, 0.5, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  change_cam_view();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
    case 32:
      cam_view = (++cam_view % 3);
      configView();
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void init(void) {
  glEnable(GL_DEPTH_TEST);
}

void update(int value) {
  earthOrbitAngle += 0.5f;
  earthRotAngle   += 3.0f;
  moonOrbitAngle  += 1.5f;

  if (earthOrbitAngle >= 360.0f) earthOrbitAngle -= 360.0f;
  if (earthRotAngle   >= 360.0f) earthRotAngle   -= 360.0f;
  if (moonOrbitAngle  >= 360.0f) moonOrbitAngle  -= 360.0f;

  glutPostRedisplay();
  glutTimerFunc(16, update, 0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Sistema Solar 3D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}
