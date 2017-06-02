//including all headers
#include <GL/glut.h>
//testing and debugging purpose ***remove at release ***
#include <stdio.h>


//default height and width of screen
#define DEFAULT_WIDTH 1440
#define DEFAULT_HEIGHT 900
int height = DEFAULT_HEIGHT;
int width = DEFAULT_WIDTH;

//define colors used
GLfloat  SkyBlue[3]={0.196078,0.6,0.8};
GLfloat  GrassColor[3]={0.196078,0.8,0.19};
GLfloat black[3] = {1.0,1.0,1.0};

void init()
{
	glClearColor(SkyBlue[0],SkyBlue[1],SkyBlue[2],1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,width,0,height);
}
void fencebar(GLint a, GLint b)
{
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2d(a,b);
		glVertex2d(a,b+5);
		glVertex2d(a+1400,b+5);
		glVertex2d(a+1400,b);
	glEnd();
}
void fence(GLint xco,GLint yco)
{
	fencebar(0,yco+60);
	fencebar(0,yco+40);
	fencebar(0,yco+20);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2d(xco,yco);
		glVertex2d(xco,yco+130);
		glVertex2d(xco+15,yco+150);
		glVertex2d(xco+30,yco+130);
		glVertex2d(xco+30,yco);
	glEnd();

}

void makebuilding()
{
	glColor3f(0.647059,0.164706,0.164706);
	glBegin(GL_POLYGON);
		glVertex2d(800,360);
		glVertex2d(800,380);
		glVertex2d(1360,380);
		glVertex2d(1360,360);
	glEnd();
}
void blacktarroad()
{
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);
		glVertex2d(0,0);
		glVertex2d(0,195);
		glVertex2d(width,195);
		glVertex2d(width,0);
	glEnd();
}
void tarlines(GLint xco, GLint yco)
{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2d(xco,yco);
		glVertex2d(xco,yco+5);
		glVertex2d(xco+50,yco+5);
		glVertex2d(xco+50,yco);
	glEnd();
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  for(GLint x = 0; x <= 1450; x+=50)
		fence(x,200);
  makebuilding();
  blacktarroad();
  for(GLint i = 0; i <= width; i+=70)
 	 tarlines(i,95);
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width,height);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGlNature");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}