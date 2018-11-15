#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glut.h>

void drawScene(void);
void setMatrix(void);
void resize(int w, int h);
void drawWireframe(int face);
void drawFilled(int face);

void specialKeys();
double rotate_x=0; 
double rotate_y=0;
double rotate_z=0;

float ax, ay, az;     

GLfloat xRotated, yRotated, zRotated;

static GLfloat cube[8][3] = {0.0, 0.0, 0.0,  1.0, 0.0, 0.0,  1.0, 0.0, 0.7,  0.0, 0.0, 0.7,
				     1.0, 0.2, 0.0,  1.0, 0.2, 0.7,  0.0, 0.2, 0.7,  0.0, 0.2, 0.0};

static int faceIndex[6][4] = {0, 1, 2, 3,  1, 4, 5, 2,  4, 7, 6, 5,
					7, 0, 3, 6,  3, 2, 5, 6,  7, 4, 1, 0};
int main(int argc, char **argv)
{

  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition (100, 100);
  glutInitWindowSize (1000, 800);
  glutCreateWindow("Cube");
 
  glEnable(GL_DEPTH_TEST);
 
  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);

    glutSpecialFunc(specialKeys);
    glutMainLoop();

   return 0;             
}

void specialKeys( int key, int x, int y ) {
 
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  else if (key == GLUT_KEY_PAGE_UP)
    rotate_z += 5;

  else if (key == GLUT_KEY_PAGE_DOWN)
    rotate_z -= 5;

  glutPostRedisplay();
 
}

void drawWireframe(int face)
{
  int i;
  glBegin(GL_LINE_LOOP);
  for (i = 0; i < 4; i++)
    glVertex3fv((GLfloat *) cube[faceIndex[face][i]]);
  glEnd();
}

void drawFilled(int face)
{
  int i;
  glBegin(GL_POLYGON);
  for (i = 0; i < 4; i++)
	glVertex3fv((GLfloat *) cube[faceIndex[face][i]]);
  glEnd();

  
}

void drawScene(void)
{

  int i;
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  glRotatef( rotate_x, 0.1, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 0.1, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 0.1 );
	
  glColor3f(0.0, 0.0, 1.0);
  for (i = 0; i < 6; i++)
  {
    drawWireframe(i);

    glColor3f(0.0, 0.0, 1.0);
    drawFilled(i);

    glColor3f(0.0, 0.0, 1.0);

    glColor3f(1.0, 0.0, 1.0);
    drawWireframe(i);
  }
  glPopMatrix();


  glutSwapBuffers();
}

void setMatrix(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void resize(int w, int h)
{
  glViewport(0, 0, w, h);
  setMatrix();
}
