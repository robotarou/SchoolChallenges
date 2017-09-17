#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

static GLfloat ang = 0.0;
int n= 0, i = 0, i1 = 15;
double x, y, r = 5;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.2, 0.0);
  glBegin(GL_POLYGON);// ポリゴンの頂点記述開始
  glPushMatrix();
  //  glRectf( -15.0, -15.0, 15.0, 15.0);
  // 円周上の座標(x,y)を計算して円を描画
  for (i = 0; i < i1; i++) {
    x = r * cos(2.0 * 3.14 * ((double)i/i1) );
    y = r * sin(2.0 * 3.14 * ((double)i/i1) );
    glVertex3f(x, y, 0.0);// 頂点の座標
  }
  glEnd(); // ポリゴンの描画終了
  glFlush(); // OpenGLのコマンドを強制的に実行(描画終了)
  glTranslatef(0.1, 0.0, 0.0);
  // glRotatef(ang, 0.0, 0.0, 1.0);
  glPopMatrix();
  glutSwapBuffers();
}

void simu(void)
{
  ang = ang + 1;
  if ( ang > 360 )
    ang = ang - 360;
  glutPostRedisplay();
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
  glViewport(0, 0, w, h );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN)
      glutIdleFunc(simu);
    if(n < 20){
      n--;
    }else{
      n = 0;
    }
    break;
  case GLUT_RIGHT_BUTTON:
    if ( state == GLUT_DOWN)
      glutIdleFunc(NULL);
    n = 0;
    break;
  default:
    break;
  }
}

void keyboard(unsigned char key, int x, int y)
{
  if ( key == '\x1b') exit(0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (400, 400);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);
  init();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
