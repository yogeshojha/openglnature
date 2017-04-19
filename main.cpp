//including all headers
#include <GL/glut.h>

//testing and debugging purpose ***remove at release ***
#include <stdio.h>


//default height and width of screen
#define DEFAULT_WIDTH 1366
#define DEFAULT_HEIGHT 768
int height = DEFAULT_HEIGHT;
int width = DEFAULT_WIDTH;



//define colors used
GLfloat  SkyBlue[][3]={0.196078,0.6,0.8};


void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glFlush();
  glClearColor(SkyBlue[0][0],SkyBlue[0][1],SkyBlue[0][2],1);
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(width,height);
	glutCreateWindow("OpenGlNature");
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}