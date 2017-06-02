//including all headers
#include <GL/glut.h>
//testing and debugging purpose ***remove at release ***
#include <stdio.h>
#include <string.h>


//default height and width of screen
#define DEFAULT_WIDTH 1440
#define DEFAULT_HEIGHT 900
int height = DEFAULT_HEIGHT;
int width = DEFAULT_WIDTH;
//define colors used
GLfloat  SkyBlue[3]={0.196078,0.6,0.8};
GLfloat  GrassColor[3]={0.196078,0.8,0.19};
GLfloat black[3] = {1.0,1.0,1.0};

char college_name[20] = "EAST POINT COLLEGE";
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

void glasswindows(GLint x, GLint y)
{
	glColor3f(0.53,0.12,0.47);
	glBegin(GL_QUADS);
		glVertex2d(x,y);
		glVertex2d(x,y+40);
		glVertex2d(x+40,y+40);
		glVertex2d(x+40,y);
	glEnd();
	glColor3f(0.576471, 0.858824, 0.439216);
	glBegin(GL_QUADS);
		glVertex2d(x+5,y+5);
		glVertex2d(x+5,y+35);
		glVertex2d(x+35,y+35);
		glVertex2d(x+35,y+5);
	glEnd();
}
void draw_pixel(GLint cx,GLint cy)
{
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
		{
			plotpixels(h,k,x,y);
			if(d<0) d+=2*x+3;
			else
				{
					d+=2*(x-y)+5;
					--y;
				}
				++x;
			}
			plotpixels(h,k,x,y);
}
void door(GLint x, GLint y)
{
	glColor3f(0.62352,0.372549,0.623529);
	glBegin(GL_QUADS);
		glVertex2d(x,y);
		glVertex2d(x,y+100);
		glVertex2d(x+50,y+100);
		glVertex2d(x+50,y);
	glEnd();
	
}
void makebuilding()
{
	glColor3f(0.647059,0.164706,0.164706);
	glBegin(GL_POLYGON);
		glVertex2d(900,360);
		glVertex2d(900,380);
		glVertex2d(1360,380);
		glVertex2d(1360,360);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2d(930,380);
		glVertex2d(930,400);
		glVertex2d(1330,400);
		glVertex2d(1330,380);
	glEnd();
	//house
	glColor3f(0.917647,0.917647,0.678431);
	glBegin(GL_POLYGON);
		glVertex2d(950,400);
		glVertex2d(950,550);
		glVertex2d(1300,550);
		glVertex2d(1300,400);
	glEnd();
	//top floor
	glBegin(GL_POLYGON);
		glVertex2d(960,550);
		glVertex2d(960,670);
		glVertex2d(1290,670);
		glVertex2d(1290,550);
	glEnd();
	//banner
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);
		glVertex2d(930,670);
		glVertex2d(930,720);
		glVertex2d(1320,720);
		glVertex2d(1320,670);
	glEnd();
	//top door
	door(1215,560);
	glColor3f(1.0,1.0,1.0);
	for(GLint i = 0; i<=10; i++)
		circle_draw(1250,620,i);
	//top floor railing
	glColor3f(0.647059,0.164706,0.164706);
	glBegin(GL_POLYGON);
		glVertex2d(930,550);
		glVertex2d(930,560);
		glVertex2d(1330,560);
		glVertex2d(1330,550);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2d(930,580);
		glVertex2d(930,590);
		glVertex2d(1330,590);
		glVertex2d(1330,580);
	glEnd();
	//bars railing
	glColor3f(0.55,0.47,0.14);
	for(GLint i = 935; i<=1330; i+=20)
	{
		glBegin(GL_POLYGON);
			glVertex2d(i,560);
			glVertex2d(i,580);
			glVertex2d(i+5,580);
			glVertex2d(i+5,560);
		glEnd();
	}
	glasswindows(1000,500);
	glasswindows(1210,500);
	glasswindows(970,625);
	door(1100,400);
	glColor3f(1.0,1.0,1.0);
	for(GLint i = 0; i<=10; i++)
		circle_draw(1130,450,i);
	//two holes in banner
	glColor3f(0.91,0.76,0.65);
	for(GLint i = 0; i<=10; i++)
		circle_draw(1280,695,i);
	for(GLint i = 0; i<=10; i++)
		circle_draw(970,695,i);
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
  glColor3f(1.0,0.0,1.0);
  glRasterPos2i(995,685);
  for( int o=0;o<strlen(college_name);o++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,college_name[o]);
  //sun
	glColor3f(1.0,1.0,0.0);
	for(GLint i = 0; i<=70; i++)
	circle_draw(1330,820,i);
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