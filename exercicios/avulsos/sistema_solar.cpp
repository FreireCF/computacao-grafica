#include <GL/glut.h>

#include <stdlib.h>
#include <cmath>

GLfloat angTerra = 0;
GLfloat angLua = 0;
GLfloat rotTerra = 0;
GLfloat rotLua = 0;
GLfloat velOrbita = 1;

void init() {
    //glClearColor(0.6, 0.6, 0.6, 1);
    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluOrtho2D(-5, 5, -5, 5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void update(int value) {
    angTerra += 1.0f * velOrbita;   
    angLua += 3.0f * velOrbita;   
    rotTerra += 2.0f * velOrbita;   
    rotLua += 1.5f * velOrbita;   

    if (angTerra >= 360) {
      angTerra -= 360;
    }
    if (angLua >= 360) {
      angLua -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  //sol
  glPushMatrix();
    glColor3f(1,1,0);
    //efeito de rotação diagonal no sil
    //glRotatef(rotTerra, 1, 0, 0); 
    glRotatef(rotTerra, 1, 1, 0);
    glutWireSphere(1.0, 20, 16);
  glPopMatrix();

  //terra
  glPushMatrix();
    glColor3f(0,0.3,1);

    glRotatef(angTerra, 0, 0, 1); //translação
    glTranslatef(4, 0, 0);
    
    glPushMatrix();
      glRotatef(rotTerra, 0, 1, 0); //rotação
      glutWireSphere(0.4, 20, 16);
    glPopMatrix();
  
    //lua
    glColor3f(1, 1, 1);

    glRotatef(angLua, 0, 0, 1);
    glTranslatef(1, 0.3, 0.3);

    
    glRotatef(rotLua, 0, 1,0);

    glutWireSphere(0.12, 20, 16);
  glPopMatrix();

  //jupiter
  glPushMatrix(); 
    glColor3f(1, 0.5, 0);

    glRotatef(angTerra, 0, 0, 1);
    glTranslatef(7,0,0);
  
    glPushMatrix();
      glRotatef(rotTerra, 0, 1, 0);
      glutWireSphere(0.7, 20, 16);
    glPopMatrix();
  
    //lua de jupiter
    glColor3f(0.89, 0.8, 0.8);

    glRotatef(angLua, 0, 0, 1);
    glTranslatef(1.9, 0.3, 0.3);
    glRotatef(rotLua, 0, 1,0);
    
    glutWireSphere(0.12, 20, 16);
  glPopMatrix();

  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {

        case 'a':
          velOrbita += 0.5f;
          break;

        case 'd':
          velOrbita -= 0.5f;
          break;
        
        case 's':
          velOrbita = 0;
          break;

        case 27:
          exit(0);
          break;
    }

    glutPostRedisplay();
}


void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, w / (h * 1.0), 1.0, 20.0);
  gluLookAt(0.0, 0.0, 18.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1000, 800);
    glutCreateWindow("Sistema solar");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}