#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //indica que será usado um buffer para geração de imagens e cores no modo RGB 

glutInitWindowSize(150, 150); //define o tam. da janela de exibição em pixels
glutInitWindowPosition(100, 100); //especifica a coordenada sup esq da janela 




