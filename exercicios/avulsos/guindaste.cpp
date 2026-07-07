#include <GL/glut.h>

#include <stdlib.h>

int cam_view = 0;
int pos_base, rotArmGar = 0;
GLdouble rotX = 0, rotY = 0, rotZ = 0, rotArm = 0, rotAnte = 0;

void change_cam_view() {
  switch (cam_view) {
    case 0:
      gluLookAt(0, 10, 20, 0, 0, 0, 0, 1, 0);
       //gluLookAt(0, 30, 20, 0, 0, 0, 0, 1, 0);
      break;
    case 1:
      gluLookAt(40, 20, 0, 0, 0, 0, 0, 1, 0);
      break;
    case 2:
      gluLookAt(20, 40, 20, 0, 0, 0, 0, 1, 0);
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
    /*case 'a': baseAngle     += 5.0f; break;
    case 'd': baseAngle     -= 5.0f; break;
    case 's': shoulderAngle -= 5.0f; break;
    case 'q': elbowAngle    += 5.0f; break;
    case 'e': elbowAngle    -= 5.0f; break;
    case 'r': 
      baseAngle = shoulderAngle = elbowAngle = 0;
      break;*/
    case 'a': pos_base -= 2.5f; break;
    case 'd': pos_base += 2.5f; break;
    case 'q': rotArm -= 2.5f; break;
    case 'e': rotArm += 2.5f; break;
    case 'z': rotArmGar -= 2.5f; break;
    case 'c': rotArmGar += 2.5f; break;
  }
  glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    //change_cam_view();
    //gluLookAt(0,15,30, 0,0,0,0,1,0);
    gluLookAt(0, 0, 30, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
    glTranslatef(0, -10 , 0);

    //base
    glTranslatef(pos_base, 0, 0);

    glPushMatrix();
      glColor4f(0.8, 0.8, 0.8, 0.5);
      glScalef(10, 1, 1);
      glutSolidCube(1);
    glPopMatrix();

    //coluna
    glPushMatrix();
      glColor4f(0.8, 0.2, 0, 0.8);
      glTranslatef(0, 2, 0);
      glRotatef(rotArm, 0, 0, 1);
      glTranslatef(0, 2, 0);
      glScalef(1.1, 4.5, 0.1);
      glutSolidCube(1.);

    //braço da garra
    glPushMatrix();
        glColor4f(0.8, 0.2, 0, 0.8);
        glTranslatef(0, 1, 0);
        glRotatef(rotArmGar, 0, 0, 1);
        glTranslatef(0, 1, 0);
        glScalef(1, -2, 1);
        glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    glPopMatrix();

    /*
    =====================================

    IMPLEMENTAR 

    1) Base
    g

    2) Braço 1

    3) Braço 2

    4) Garra

    =====================================
    */

    glutSwapBuffers();
}

void init(void) {
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Guindaste Robotico 3D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutMainLoop();
  return 0;
}
