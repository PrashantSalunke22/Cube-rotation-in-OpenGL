#include <GL/glut.h>
#include <stdio.h>

GLfloat xRotated, yRotated, zRotated;

void specialKeys();
double rotate_x=0; 
double rotate_y=0;
double rotate_z=0;


void init(void)
{
    glClearColor(0,0,0,0);
 
}

void DrawCube(void)
{

    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
        glTranslatef(-0.2,0.1,-17.0);

    glRotatef(rotate_x,1.0,0.0,0.0);
    glRotatef(rotate_y,0.0,1.0,0.0);
    glRotatef(rotate_z,0.0,0.0,1.0);

    glBegin(GL_QUADS);        
    
    glColor3f(1.0,0.0,0.0);    // 1 0 0
    glVertex3f( 4.0, 1.0, 1.0); 
    glVertex3f(-1.0, 1.0, 1.0); 
    glVertex3f(-1.0,-1.0, 1.0); 
    glVertex3f( 4.0,-1.0, 1.0); 

    glColor3f(0.0,0.0,1.0);    // 1 1 0
    glVertex3f( 4.0,-1.0,-1.0); 
    glVertex3f(-1.0,-1.0,-1.0); 
    glVertex3f(-1.0, 1.0,-1.0); 
    glVertex3f( 4.0, 1.0,-1.0); 

    glColor3f(1.0,1.0,1.0);    // 0 0 1
    glVertex3f(-1.0, 1.0, 1.0); 
    glVertex3f(-1.0, 1.0,-1.0); 
    glVertex3f(-1.0,-1.0,-1.0); 
    glVertex3f(-1.0,-1.0, 1.0); 
    
    glColor3f(1.0,1.0,1.0);    // 1 0 1
    glVertex3f( 4.0, 1.0,-1.0);    
    glVertex3f( 4.0, 1.0, 1.0);    
    glVertex3f( 4.0,-1.0, 1.0);    
    glVertex3f( 4.0,-1.0,-1.0);    
    
    glEnd();     
    glFlush();
}

void specialKeys( int key, int x, int y ) 
{
 
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


void reshape(int x, int y)
{
    if (y == 0 || x == 0) 
       return;  

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
 
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y); 
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cube");
    init();
    glutDisplayFunc(DrawCube);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
