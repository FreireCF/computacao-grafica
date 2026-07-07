#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int, int);

void init (){
  glClearColor(0.2, 0.6, 1.0, 1.0 );
} 

int main (int argc, char **argv){
   
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB); //define o modo de exibição para Redd Green Blue

  glutInitWindowPosition(200, 100);  // posição onde a janela será aberta no monitor
  glutInitWindowSize(500, 500); // largura e altura da janela 

  glutCreateWindow("indiano lazarento"); //cria a janela com um nome após toda a sua configuração 

  glutDisplayFunc(display); //função de callback (api chama sempre que precisar) //deve ser definida após a criação da janel
  glutReshapeFunc(reshape);
  init();

  glutMainLoop(); //loop principal para o programa não encerrar sem instruções 
}

void display(){
  //limpar a área sempre que tiver uma nova chamada
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity(); //carrega a pilha identidade na pilha de transformações 
  
  glPointSize(3);
  
  glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex2f(0,5);
    glVertex2f(4,-3);
    glVertex2f(-4,-3);
  glEnd();
  
  glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(0,0);
  glEnd();

  glFlush(); //carrega os comandos e desenha
}

void reshape(int l, int a){
 
  glViewport(0, 0, l, a) ; //(0,0) é o ponto que a partir dele o viewport será traçado
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();   
  gluOrtho2D(-10, 10, -10, 10); //x esq e x dir, y inf e y sup
  glMatrixMode(GL_MODELVIEW); 
}