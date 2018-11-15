#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glext.h>

#include <GL/glut.h>
#include <stdio.h>

GLfloat xRotated, yRotated, zRotated;

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

    glRotatef(xRotated,1.0,0.0,0.0);  
    glRotatef(yRotated,0.0,1.0,0.0);  
    glRotatef(zRotated,0.0,0.0,1.0);  
    glBegin(GL_QUADS);        
 
    glColor3f(1.0,1.0,1.0);  
    glVertex3f( 4.0, 1.0,-1.0);
    glVertex3f(-1.0, 1.0,-1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f( 4.0, 1.0, 1.0);

    glColor3f(1.0,1.0,1.0);  
    glVertex3f( 4.0,-1.0, 1.0);
    glVertex3f(-1.0,-1.0, 1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f( 4.0,-1.0,-1.0);

    glColor3f(0.0,0.0,1.0);  
    glVertex3f( 4.0, 1.0, 1.0); 
    glVertex3f(-1.0, 1.0, 1.0); 
    glVertex3f(-1.0,-1.0, 1.0); 
    glVertex3f( 4.0,-1.0, 1.0); 

    glColor3f(0.0,0.0,1.0);  
    glVertex3f( 4.0,-1.0,-1.0); 
    glVertex3f(-1.0,-1.0,-1.0); 
    glVertex3f(-1.0, 1.0,-1.0); 
    glVertex3f( 4.0, 1.0,-1.0); 

    glColor3f(1.0,0.0,1.0);    
    glVertex3f(-1.0, 1.0, 1.0); 
    glVertex3f(-1.0, 1.0,-1.0); 
    glVertex3f(-1.0,-1.0,-1.0); 
    glVertex3f(-1.0,-1.0, 1.0); 
    
    glColor3f(1.0,0.0,1.0);    
    glVertex3f( 4.0, 1.0,-1.0);    
    glVertex3f( 4.0, 1.0, 1.0);    
    glVertex3f( 4.0,-1.0, 1.0);    
    glVertex3f( 4.0,-1.0,-1.0);    
    
    glEnd();     
    glFlush();
}


void animation(void)
{
     xRotated += 0.02;
     yRotated += 0.01;
     zRotated += 0.005;
     DrawCube();
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
    glutInitWindowSize (700, 500);
    glutCreateWindow("Cube");
    init();
    glutDisplayFunc(DrawCube);
    glutReshapeFunc(reshape);
    glutIdleFunc(animation);
    glutMainLoop();
    return 0;
}
