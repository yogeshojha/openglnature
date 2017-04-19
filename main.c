#include <stdlib.h>
#include <GL/glut.h>
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  
  glFlush();
  glutSwapBuffers();
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Spin a color cube");
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0,1.0,1.0);
	glutMainLoop();
}