#include <GL/glut.h>

#include <stdlib.h>

int cam_view = 0;

float car1_pos = -50;
float car2_pos = 50;

int tempo = 0;
bool semaforo = false; // 0 verde, 1 vermelho

void drawRoad() {

    glColor3f(0.2, 0.2, 0.2);

    glPushMatrix();
    glScalef(20, 1, 300);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glScalef(300, 1, 20);
    glutSolidCube(1);
    glPopMatrix();
}

void drawCar(float x, float z, float r, float g, float b) {

    glPushMatrix();

    glTranslatef(x, 1, z);

    glColor3f(r, g, b);
    glScalef(5, 1, 3);
    glutSolidCube(2);

    glPopMatrix();
}

void drawTrafficLight() {

    glPushMatrix();
    glTranslatef(10, 5, 0);

    if(semaforo)
        glColor3f(0, 1, 0);
    else
        glColor3f(1, 0, 0);

    glutSolidCube(2);

    glPopMatrix();
}

void switch_cam_view() {
  switch(cam_view) {
    case 0:
      gluLookAt(80, 30, 80, 0, 0, 0, 0, 1, 0);
      break;
    case 1:
      gluLookAt(-100, 50, 0, 0, 0, 0, 1, 0, 0);
      break;
    case 2:
      gluLookAt(100, 100, 100, 0, 0, 0, 0, 1, 0);
      break;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 

    switch_cam_view();
    
    //gluLookAt(100, 50, 50, 0, 0, 0, 0, 1, 0);

    drawRoad();

    drawTrafficLight();

    drawCar(-car1_pos, -10, 1, 0, 0);
    drawCar(-car1_pos, 10, 0, 0, 1);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {

    if(key == 27)
        exit(0);

    if(key == 32)
        cam_view = (cam_view + 1) % 3;

    glutPostRedisplay();
}

void update(int value) {

    if(semaforo){
      car1_pos++;
      if(car1_pos > 100) car1_pos = -100;
    }

    if(tempo > 100){
      semaforo = !semaforo;  
      tempo = 0;
    }

    tempo++;

    /* += 1.0f * velOrbita;   
    angLua += 3.0f * velOrbita;   
    rotTerra += 2.0f * velOrbita;   
    rotLua += 1.5f * velOrbita;   

    if (angTerra >= 360) {
      angTerra -= 360;
    }
    if (angLua >= 360) {
      angLua -= 360;
*/
   
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}



void init() {

    glClearColor(0.7, 0.7, 0.7, 1);
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

    glutCreateWindow("Simulação de Tráfego 3D");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(30, update, 0);

    glutMainLoop();

    return 0;
}