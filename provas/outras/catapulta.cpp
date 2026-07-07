#include <GL/glut.h>

float angBraco = -40;
int cam_view = 0;

// void change_cam_view() {
//   switch (cam_view) {
//     case 0:
//       //gluLookAt(0, 100, 0, 0, 0, 0, 1, 0, 0);
//       gluLookAt(40, 30, 40, 0, 0, 0, 0, 1, 0);
//       break;
//     case 1:
//       //gluLookAt(-100, 50, 0, 0, 0, 0, 1, 0, 0);
//       break;
//     case 2:
//       //gluLookAt(-50, 50, 50, 0, 0, 0, 0, 1, 0);
//       break;
//   }
// }

void drawHelice() {
  glPushMatrix();
  // Centro da hélice
  glColor3f(0, 0, 0);
  glutSolidSphere(0.8, 20, 20);
  // 4 pás
  for(int i = 0; i < 4; i++) {
    glPushMatrix();
    glRotatef(i * 90, 0, 0, 1);
    // desloca a pá para longe do centro
    glTranslatef(0, 4, 0);
    glColor3f(1, 1, 1);

    glPushMatrix();
      glScalef(0.8, 8, 0.4);
      glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
    }

    glPopMatrix();
}


void drawProjectile() {

    glColor3f(0.3,0.3,0.3);
    glutSolidSphere(1.2,20,20);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //change_cam_view();
    gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);

    /*
    ====================================

    IMPLEMENTAR

    1) Base da catapulta
    */
    glPushMatrix();
      glColor3f(0, 0.6, 0.7);
      glTranslatef(0, -10, 0);
      glScalef(32, 1, 1);
      glutSolidCube(1);
    glPopMatrix();

    //glRotatef(90, 0, 0, 1);

    glTranslatef(5, 0, 0);

    glPushMatrix();
    glPushMatrix();
      glColor3f(0.8, 0.6, 0);
      glTranslatef(11, -10, 0);
      glRotatef(angBraco, 0, 0, 1);
      glTranslatef(-11, 0, 0);
      glScalef(22, 1, 1);
      glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
      glColor3f(1, 1, 1);
      glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();

    /*
    2) Eixo9
    

    3) Braço rotacionando

    4) Posicionar o projétil
       na ponta do braço

    ====================================
    */

    glutSwapBuffers();
}

void configView() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 800 / 600.0, 0.5, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // change_cam_view();
}

void resize(GLsizei w, GLsizei h) {
  if (h == 0) h = 1;
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
    case 32:
      //cam_view = (++cam_view % 3);
      //configView();
      break;
    case 'a':
      angBraco+=5;
      break;
    case 'd':
      angBraco-=5;
    break;
    default:
      break;
  }
  glutPostRedisplay();
}

void init(void) {
  glClearColor(0, 0, 0, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

void update(int value) {
  //angHelice+=25;
  glutPostRedisplay();
  glutTimerFunc(1000, update, 0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Moinho");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}
