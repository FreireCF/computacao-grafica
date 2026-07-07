#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>

int cam_view = 0;

float baseAngle    = 0.0f;   // rotacao da base (eixo Y)
float shoulderAngle = 0.0f;  // rotacao do ombro (eixo Z)
float elbowAngle   = 0.0f;   // rotacao do cotovelo (eixo Z)

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  // Base (fixo na origem)
  glPushMatrix();
  glColor3f(0.4f, 0.4f, 0.4f);
    glRotatef(baseAngle, 0, 1, 0);
    glPushMatrix();
      glScalef(6.0f, 1.0f, 6.0f);  
      glutSolidCube(1.0f);
    glPopMatrix();

  //braço
  glPushMatrix();
    glRotatef(shoulderAngle, 0, 0, 1);
    glTranslatef(0, 4, 0);
    glColor3f(0.8, 0.3, 0.1);
  glPushMatrix();
    glScalef(1.0, 8.0, 1.0);
    glutSolidCube(1.0f);
  glPopMatrix();
    
   //ante braço
  glPushMatrix();
    glColor3f(0.9, 0.5, 0.1);
    //glRotatef(baseAngle, 0, 1, 0);
    //glRotatef(shoulderAngle, 0, 0, 1);
    glTranslatef(0, 3, 0);
    glRotatef(elbowAngle, 0, 0, 1);
    glTranslatef(0, 3.5, 0);
    glScalef(0.8, 5.0, 0.8);
    glutSolidCube(1.0f);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

  glutSwapBuffers();
}

void change_cam_view() {
  switch (cam_view) {
    case 0:
      gluLookAt(0, 20, 40, 0, 8, 0, 0, 1, 0);
      break;
    case 1:
      gluLookAt(40, 20, 0, 0, 8, 0, 0, 1, 0);
      break;
    case 2:
      gluLookAt(20, 40, 20, 0, 8, 0, 0, 1, 0);
      break;
  }
}

void configView() {
  glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
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
    case 27:  exit(0); break;
    case 32:  cam_view = (++cam_view % 3); configView(); break;
    case 'a': baseAngle     += 5.0f; break;
    case 'd': baseAngle     -= 5.0f; break;
    case 'w': shoulderAngle += 5.0f; break;
    case 's': shoulderAngle -= 5.0f; break;
    case 'q': elbowAngle    += 5.0f; break;
    case 'e': elbowAngle    -= 5.0f; break;
    case 'r': 
      baseAngle = shoulderAngle = elbowAngle = 0;
      break;
  }
  glutPostRedisplay();
}

void init(void) {
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Braco Robotico 3D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutMainLoop();
  return 0;
}
