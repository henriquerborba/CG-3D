#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "canvas/gl_canvas2d.h"
#include "vectors/Vector2.h"
#include "windows/window.h"
#include "windows/draw/draw_window.h"
#include "windows/view/view_window.h"

using namespace std;

int screenWidth = 1368, screenHeight = 768; // largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY;                         // variaveis globais do mouse para poder exibir dentro da render().

Window *drawWindow = new DrawWindow(screenWidth / 2, screenHeight, Vector2(0, 0));                           // cria uma janela de desenho.
Window *viewWindow = new ViewWindow(screenWidth / 2, screenHeight, Vector2(screenWidth / 2, 0), drawWindow); // cria uma janela de visualização.

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   drawWindow->render();
   viewWindow->render();
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   switch (key)
   {
   // seta para esquerda
   case 200:
      break;
   // seta para cima
   case 201:
      break;
   // seta para direita
   case 202:
      break;
   // seta para baixo
   case 203:
      break;
   }
}

// funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d", key);
}

// funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; // guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;

   drawWindow->mouse(button, state, wheel, direction, x, y);
   viewWindow->mouse(button, state, wheel, direction, x, y);

   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction, x, y);
}

int main(void)
{
   CV::init(&screenWidth, &screenHeight, "Trabalho 4 - Henrique Rodrigues de Borba");
   CV::run();
}
