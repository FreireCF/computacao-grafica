#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // fundo branco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 256, 0, 256); // sistema de proj. ortogonal
}

void cartesiano(){
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
    // eixo X
    glVertex2f(0, 128);
    glVertex2f(256, 128);

    // eixo Y
    glVertex2f(128, 0);
    glVertex2f(128, 256);
  glEnd();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(10); 

  // triângulo do teto
  glColor3f(0.0, 1.0, 0.0); // verde
  glBegin(GL_TRIANGLES);
      glVertex2f(70, 178); //topo
      glVertex2f(40, 144); //v esq
      glVertex2f(100, 144); // v direito
  glEnd();

  //parede da porta
  glColor3f(0.670, 0.184, 0.094); //vermelho rosado (marrom
  glBegin(GL_QUADS);
    glVertex2f(40, 80); //esq inf
    glVertex2f(40, 144); // esq sup
    glVertex2f(100, 144); //dir sup
    glVertex2f(100, 80); // dir inf
  glEnd();

  //porta
  glColor3f(0.7686, 0, 0.6862); //rosa
  glBegin(GL_QUADS);
    glVertex2f(60, 80); //esq inf
    glVertex2f(60, 110); // esq sup
    glVertex2f(80, 110); //dir sup
    glVertex2f(80, 80); // dir inf
  glEnd();

  //sombra da porta
  glColor3f(0.07, 0.07, 0.07); //cinza 
  glBegin(GL_QUADS);
      glVertex2f(30, 60); //E I 
      glVertex2f(60, 80); //E S
      glVertex2f(80, 80); //D S
      glVertex2f(60, 60); //D I
  glEnd();

  //maçaneta
  glColor3f(0, 0, 1); //rosa
  glBegin(GL_QUADS);
    glVertex2f(62, 94); //esq inf
    glVertex2f(62, 97); // esq sup
    glVertex2f(64, 97); //dir sup
    glVertex2f(64, 94); // dir inf
  glEnd();

  //parede principal
  glColor3f(0.0015, 0.0509, 0.2784); //azul escuro
  glBegin(GL_QUAD_STRIP);
    glVertex2f(100, 144); // esq inf
    glVertex2f(100, 80); //esq sup
    glVertex2f(180, 144); //dir sup
    glVertex2f(180, 80); // dir inf
  glEnd();

  //janela 1
  glColor3f(0.5882, 0.7882, 0.3882); //verde claro
  glBegin(GL_QUADS);
    glVertex2f(110, 130); // esq inf
    glVertex2f(110, 110); //esq sup
    glVertex2f(130, 110); //dir sup
    glVertex2f(130, 130); // dir inf
  glEnd();

   //janela 2
  glBegin(GL_QUADS);
    glVertex2f(140, 130); // esq inf
    glVertex2f(140, 110); //esq sup
    glVertex2f(160, 110); //dir sup
    glVertex2f(160, 130); // dir inf
  glEnd();

  //linhas da janela 1
  glColor3f(0.0015, 0.0509, 0.2784); //azul escuro
  glBegin(GL_LINES);
    //vertical
    glVertex2f(150, 110);
    glVertex2f(150, 130);

    //horizontal
    glVertex2f(140,120);
    glVertex2f(160,120);
  glEnd();

  //linhas da janela 2
  glBegin(GL_LINES);
    //vertical
    glVertex2f(120, 110);
    glVertex2f(120, 130);

    //horizontal
    glVertex2f(110,120);
    glVertex2f(130,120);
  glEnd();
  //teto
  glColor3f(0, 0, 1); //azul
  glBegin(GL_QUAD_STRIP);
    glVertex2f(70, 178); // esq inf
    glVertex2f(100, 144); //esq sup
    //iguais:
    glVertex2f(160, 178); //dir sup
    glVertex2f(180, 144); // dir inf
  glEnd();

  //cartesiano();

  glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("casinha");
    init(); 
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}