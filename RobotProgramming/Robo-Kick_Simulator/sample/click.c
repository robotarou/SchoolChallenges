#include <stdio.h>
#include <GL/glut.h>

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void resize(int w, int h){
  /* ウィンドウ全体をビューボードにする */
  glViewport(0, 0, w, h);

  /*　変換行列の初期化 */
  glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
  switch (button){
  case GLUT_LEFT_BUTTON:
    printf("left");
    break;
  case GLUT_MIDDLE_BUTTON:
    printf("middle");
    break;
  case GLUT_RIGHT_BUTTON:
    printf("right");
    break;
  default:
    break;
  }

  printf(" button is ");

  switch (state){
  case GLUT_UP:
    printf("up");
    break;
  case GLUT_DOWN:
    printf("down");
    break;
  default:
    break;
  }

  printf(" at (%d, %d)\n", x, y);
}

void init(void){
  glClearColor(0.0, 0.0, 1.0, 1.0);
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  init();
  glutMainLoop();
}

