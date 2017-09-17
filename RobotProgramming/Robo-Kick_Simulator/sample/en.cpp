/* 引用元: http://gamepro.blog.jp/opengl/glut/%E5%86%86 */

#include <GL/glut.h>
#include <math.h>

void display(void)
{
  int i, n = 36;// 分割数n
  double x, y, r = 0.5;// 円周上の座標(x,y)と半径r
  glClearColor(1.0, 1.0, 1.0, 1.0);// 画面のクリア色(背景色)
  glClear(GL_COLOR_BUFFER_BIT);// バッファのクリア
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0xACF3);
  glBegin(GL_POLYGON);// ポリゴンの頂点記述開始
  glColor4f(1.0, 0.0, 0.0, 1.0);  // 円の色(RGBA)
  // 円周上の座標(x,y)を計算して円を描画
  for (i = 0; i < n; i++) {
    //x = r * cos(2.0 * 3.14 * ((double)i/n) );
    y = r * sin(2.0 * 3.14 * ((double)i/n) );
    glVertex3f(x, y, 0.0);// 頂点の座標
  }
  glEnd();// 頂点の記述終了
  glFlush();// コマンドの実行
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);// 画面の出現位置
  glutInitWindowSize(300, 300);// 画面サイズ(400*300px)
  glutInit(&argc, argv);// GLUTの初期化
  glutInitDisplayMode(GLUT_RGBA);// 画面のモード(RGBA色空間を使う)
  glutCreateWindow("en");// 画面の名前
  glutDisplayFunc(display);// GLUTの再描画関数を登録
  glutMainLoop();// イベントループを繰り返し実行
  return 0;
}
