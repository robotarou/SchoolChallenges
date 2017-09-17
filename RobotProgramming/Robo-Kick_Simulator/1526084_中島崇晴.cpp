#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define TIMESCALE 0.01                      /* フレームごとの時間 */

struct Asi {
  GLfloat x, x1, x2;
  GLfloat y, y1, y2;
};                                          /* 足座標             */

struct Asi asi;

static GLfloat frame = 0;                   /* 現在のフレーム数　 */
static GLfloat x = 0.0, y = 0.0;            /* ボール座標         */
static GLfloat vx = 1.5, vy = 10;           /* ボール速度         */
static GLfloat e = 0.8;                     /* 反発係数           */
static GLfloat u = 0.9;                     /* 摩擦係数           */
static GLfloat g = 9.8;                     /* 重力加速度         */
static GLfloat L1, L1_1, L1_2;              /* 足当たり判定       */
static GLfloat L2, L2_1, L2_2;
static GLfloat n = 0, n1 = 0, i = 0;

/* ボール */
void ball(void)
{
  int i = 0, n = 36;
  double x, y, r = 0.1;
  glEnable(GL_LINE_STIPPLE);
  glBegin(GL_POLYGON);
  glColor4f(1.0, 0.0, 0.0, 1.0);

  for (i = 0; i < n; i++) {
    x = r * cos(2.0 * 3.14 * ((double)i/n) );
    y = r * sin(2.0 * 3.14 * ((double)i/n) );
    glVertex3f(x, y, 0.0);
  }
  glEnd();
}

/* 足 */
void leg(void)
{
  glColor3d(1.0, 1.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex3f(asi.x,  asi.y, 0.0);
  glVertex3f(asi.x1, asi.y1, 0.0);
  glVertex3f(asi.x2, asi.y2, 0.0);
  glEnd();
}

void display(void)
{
  /* 壁表示 */
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(1.0, 1.0, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2d(-0.9, -0.9);
  glVertex2d(0.9, -0.9);
  glVertex2d(0.9, 0.9);
  glVertex2d(-0.9, 0.9);
  glEnd();
  
  /* 足表示 */
  glPushMatrix();
  leg();
  glPopMatrix();
  
  /* ボール表示 */
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(x, y, 0.0);
  ball();
  glPopMatrix();
  glutSwapBuffers();
}

void simu(void)
{
  double t = TIMESCALE * frame;         /* フレーム数から現在時刻を求める */
  static int r = 1.5, i = 0;

  asi.x = -0.3;
  asi.y =  0.2;
  
  /* 足先座標 */
  asi.x1 = asi.x + r * cos(2.0 * 3.14 * ((double)i/200) );
  asi.y1 = asi.y + r * sin(2.0 * 3.14 * ((double)i/200) );
  asi.x2 = asi.x + r * cos(2.0 * 3.14 * (((double)i+4)/200) );
  asi.y2 = asi.y + r * sin(2.0 * 3.14 * (((double)i+4)/200) );
  i++;

  /* 足当たり判定 */
  L1_1 = sqrt( pow( (asi.x1-asi.x), 2) + pow( (asi.y1-asi.y), 2) );
  L1_2 = sqrt( pow( (x-asi.x), 2 ) + pow( (y-asi.y), 2 ) );
  n = (asi.x1-asi.x)*(x-asi.x)+(asi.y1-asi.y)*(y-asi.y);

  L2_1 = sqrt( pow( (asi.x2-asi.x1), 2) + pow( (asi.y2-asi.y1), 2) );
  L2_2 = sqrt( pow( (x-asi.x1), 2 ) + pow( (y-asi.y1), 2 ) );
  n1 = (asi.x2-asi.x1)*(x-asi.x1)+(asi.y2-asi.y1)*(y-asi.y1);
  
  L1 = L1_1 * L1_2;
  L2 = L2_1 * L2_2;
  
  if (fabs(n - L1) < 0.02 && L1_1 >= L1_2) {
    vy = -vy * 1.1;
    vx = -vx * 1.1;
    if (vx == 0 && vy == 0) {
      vy = 100;
      vx = 10;
    }
    frame = 0;
  }

  if (fabs(n1 - L2) < 0.02 && L2_1 >= L2_2) {
    vy = -vy * 1.1;
    vx = -vx * 1.1;
    if (vx == 0 && vy == 0) {
      printf("2222222222222\n");
      vy = 100;
      vx = 10;
    }
    frame = 0;
  }
  
  /* 壁当たり判定 */
  x = x + vx * TIMESCALE;
  y = y + (vy-g*t) * TIMESCALE;
  if (y > 0.79) {
    vy = 0.0;
    y = 0.79;
  }
  if (y < -0.79) {
    vy = -(vy - g*t) * e;
    frame = 0;
    y = -0.79;
  }
  if (x > 0.79) {
    vx = -vx * e;
    x = 0.79;
  }
  if (x < -0.79) {
    vx = -vx * e;
    x = -0.79;
  }

  /* 摩擦係数 */
  if (y < -0.78) {
    vx = vx * u;
  }

  ++frame;
  
  printf("x = %lf, \ty = %lf\n", x, y);
 
  glutPostRedisplay();
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

/* マウス操作 */
void mouse(int button, int state, int x, int y)
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN)
      glutIdleFunc(simu);
    break;
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN)
      glutIdleFunc(NULL);
    break;
  default:
    break;
  }
}

/* キーボード操作 */
void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 'w':
    vy = 10;
    break;
  case 's':
    vy = -10;
    break;
  case 'a':
    vx = -3;
    break;
  case 'd':
    vx = 3;
    break;
  case 'q':
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitWindowSize (400, 400);
  glutCreateWindow("Robo-Kick_Simulator");
  init();
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
