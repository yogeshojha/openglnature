//including all headers
#include <GL/glut.h>
//testing and debugging purpose ***remove at release ***
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>       /* time */
void resize(int, int);
//default height and width of screen
#define DEFAULT_WIDTH 1440
#define DEFAULT_HEIGHT 900
int height = DEFAULT_HEIGHT;
int width = DEFAULT_WIDTH;
//define colors used
GLfloat  SkyBlue[3]={0.196078,0.6,0.8};
GLfloat  GrassColor[3]={0.196078,0.8,0.19};
GLfloat black[3] = {1.0,1.0,1.0};
GLint veh_xpos = 40;
int status_mov_veh_light = 1;
char college_name[20] = "EAST POINT COLLEGE";
char parking[20] = "Parking";
char oops[100] = "OOPS!! you are going outside of college boundry   Move Left";
char oops_r[100] = "OOPS!! you are going outside of college boundry   Move Right";
char help1[100] = "Press LEFT ARROW <<-- to move car left or Click LEFT Mouse";
char help2[100] = "Press RIGHT ARROW -->> to move car RIGHT or Click RIGHT Mouse";
char help3[100] = "DO NOT MOVE CAR OUT OF BOUNDRY";
char help4[100] = "PRESS [SPACE] KEY to move football randomly";
char help5[100] = "PRESS [C] KEY to Close This message";
char help7[100] = "PRESS [P] KEY to Park and Unpark the car";
char help[100] = "PRESS [H] KEY for help and [ESC] to Close";
char help6[100] = "PRESS [I] and [L] KEY to change the lane of the car";
char stolen[100] = "CAR IS STOLEN, CALL THE POLICE!!!!!";
int mouse_status = 0;
GLint default_start_walk = 1000;
GLint default_start_walk_player1_yco = 380;
GLint default_start_walk_player2_xco = 380;
int status_football_player1_crossed = 0;
int status_football_player2_crossed = 0;
int status_football_goalkeeper_crossed = 0;
int status_football_lady_crossed = 0;
int status_crossed = 0;
int rand_speed;
GLint football_goalkeeper_xco = 190;
GLint football_lady_xco = 500;
GLint football_xco = 110;
GLint football_yco = 360;
int help_pressed = 0;
GLint mov_veh_xpos = 100;
GLint mov_veh1_xpos = 0;
GLint car_ypos = 140;
int parking_status = 1;
GLint parking_car_xcod = 0;
GLint parking_car_ycod = 27;
int parking_pressed_already = 1;
void init()
{
	glClearColor(SkyBlue[0],SkyBlue[1],SkyBlue[2],1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,width,0,height);
	football_xco = 110 + (rand() % ( 470 - 110 + 1 ) );
	football_yco = 360 + (rand() % ( 800 - 360 + 1 ) );
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
void wheel(GLint x, GLint y)
{
	for(GLint i = 0; i<= 20;i++)
		circle_draw(x,y,i);
}
void vehicle(GLint x, GLint y, int status, GLfloat col1, GLfloat col2, GLfloat col3,GLfloat col4, GLfloat col5, GLfloat col6)
{
	glColor3f(col1,col2,col3);
	glBegin(GL_POLYGON);
	glVertex2d(x,y);
	glVertex2d(x+200,y);
	glVertex2d(x+200,y+50);
	glVertex2d(x,y+50);
	glEnd();
	glColor3f(col4,col5,col6);
	glBegin(GL_POLYGON);
	glVertex2d(x+20,y+50);
	glVertex2d(x+60,y+90);
	glVertex2d(x+140,y+90);
	glVertex2d(x+180,y+50);
	glEnd();
	
	//light
	if(status == 1)
	{		
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2d(x+200,y+50);
		glVertex2d(x+250,y+90);
		glVertex2d(x+250,y-30);
		glVertex2d(x+200,y);
		glEnd();
	}
	glColor3f(1,1,1);
	wheel(x+50,y);
	wheel(x+150,y);

}

void woman(GLint x, GLint y,GLfloat tcolor1,GLfloat tcolor2,GLfloat tcolor3, GLfloat scolor1,GLfloat scolor2,GLfloat scolor3)
{
	//face
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(x,y,0);
	glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
	glPushMatrix();
	glTranslatef(x,y-1,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
	glVertex2i(x,y-1);
 		glVertex2i(x,y-5); //nose
 		glVertex2i(x-9,y+3);
 		glVertex2i(x-8,y+4);
 		glVertex2i(x-8,y+4);
		glVertex2i(x-7,y+3);//eyebrow
		glVertex2i(x+9,y+3);
		glVertex2i(x+8,y+4);
		glVertex2i(x+8,y+4);
 		glVertex2i(x+3,y+3);//eyebrow
 		glEnd();
	//ear right
 		glBegin(GL_POLYGON);
 		glColor3ub(255,191,128);
 		glVertex2i(x-14,y-1+1);
 		glVertex2i(x-14,y-5+1);
 		glVertex2i(x-2-14,y-6+1);
 		glVertex2i(x-2-14,y+1);
 		glEnd();
	//ear left
 		glBegin(GL_POLYGON);
 		glColor3ub(255,191,128);
 		glVertex2i(x+14,y);
 		glVertex2i(x+16,y+1);
 		glVertex2i(x+16,y-4);
 		glVertex2i(x+14,y-5);
 		glEnd();
	//ear ring right
 		glBegin(GL_POLYGON);
 		glColor3ub(255,85,90);
 		glVertex2i(x-1-14,y-3);
 		glVertex2i(x+2-14,y-10);
 		glVertex2i(x-4-14,y-10);

 		glEnd();
	//ear ring left
 		glBegin(GL_POLYGON);
 		glColor3ub(255,85,90);
 		glVertex2i(x+11,y-10);
 		glVertex2i(x+15,y-3);
 		glVertex2i(x+18,y-10);
 		glEnd();

//hair
 		glBegin(GL_POLYGON);
 		glColor3ub(0,0,0);
 		glVertex2i(x-15,y+4);
 		glVertex2i(x+9,y+14);
 		glVertex2i(x,y+17);
 		glVertex2i(x-12,y+12);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glColor3ub(0,0,0);
 		glVertex2i(x,y+12);
 		glVertex2i(x+9,y+14);
 		glVertex2i(x+12,y+12);
 		glVertex2i(x+15,y+4);
 		glEnd();
	// eyes
 		glBegin(GL_POLYGON);
 		glVertex2i(x-7,y+1);
 		glVertex2i(x-5,y+1);
 		glVertex2i(x-5,y-1);
 		glVertex2i(x-7,y-1);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x+5,y+1);
 		glVertex2i(x+7,y+1);
 		glVertex2i(x-7,y-1);
 		glVertex2i(x+5,y-1);
 		glEnd();
//mouth
 		glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
 		glVertex2i(x-6,y-8);
 		glVertex2i(x,y-11);
 		glVertex2i(x+6,y-8);
 		glVertex2i(x,y-10);
 		glEnd();
//shirt
 		glBegin(GL_POLYGON);
 		glColor3f(tcolor1,tcolor2,tcolor3);
 		glVertex2i(x-11,y-15);
 		glVertex2i(x+11,y-15);
 		glVertex2i(x+26,y-26);
 		glVertex2i(x+21,y-25);
 		glVertex2i(x+16,y-30);
 		glVertex2i(x+16,y-50);
 		glVertex2i(x-16,y-50);
 		glVertex2i(x-16,y-30);
 		glVertex2i(x-21,y-25);
 		glVertex2i(x-26,y-26);
 		glEnd();
//neck
 		glBegin(GL_POLYGON);
 		glColor3ub(255,190,128);
 		glVertex2i(x-7,y-15);
 		glVertex2i(x+7,y-15);
 		glVertex2i(x+5,y-24);
 		glVertex2i(x-5,y-24);
 		glEnd();
//hands
 		glBegin(GL_POLYGON);
 		glColor3ub(255,191,128);
 		glVertex2i(x+25,y-27);
 		glVertex2i(x+35,y-42);
 		glVertex2i(x+27,y-41);
 		glVertex2i(x+22,y-33);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x+35,y-42);
 		glVertex2i(x+16,y-57);
 		glVertex2i(x+16,y-50);
 		glVertex2i(x+27,y-41);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x-25,y-27);
 		glVertex2i(x-35,y-42);
 		glVertex2i(x-27,y-41);
 		glVertex2i(x-22,y-33);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x-35,y-42);
 		glVertex2i(x-16,y-57);
 		glVertex2i(x-16,y-50);
 		glVertex2i(x-27,y-41);
 		glEnd();
// belt
 		glBegin(GL_POLYGON);
 		glColor3ub(10,120,130);
 		glVertex2i(x+16,y-50);
 		glVertex2i(x-16,y-50);
 		glVertex2i(x-16,y-55);
 		glVertex2i(x+16,y-55);
 		glEnd();


	/// leg
 		glBegin(GL_POLYGON);
 		glColor3ub(255,190,128);
 		glVertex2i(x+15,y-55);
 		glVertex2i(x-15,y-55);
 		glVertex2i(x-20,y-90);
 		glVertex2i(x-10,y-90);
 		glVertex2i(x-7,y-57);
 		glVertex2i(x+10,y-90);
 		glVertex2i(x+20,y-90);
 		glEnd();
//skirt
 		glBegin(GL_POLYGON);
 		glColor3f(scolor1,scolor2,scolor3);
 		glVertex2i(x-16,y-55);
 		glVertex2i(x+16,y-55);
 		glVertex2i(x+26,y-85);
 		glVertex2i(x-26,y-85);
 		glEnd();
	//shoe left
 		glBegin(GL_POLYGON);
 		glColor3ub(180,0,0);
 		glVertex2i(x-10,y-90);
 		glVertex2i(x-10,y-99);
 		glVertex2i(x-12,y-99);
 		glVertex2i(x-12,y-91);
 		glVertex2i(x-18,y-99);
 		glVertex2i(x-28,y-99);
 		glVertex2i(x-20,y-90);

 		glEnd();
	//shoe right
 		glBegin(GL_POLYGON);
 		glColor3ub(180,0,0);
 		glVertex2i(x+10,y-90);
 		glVertex2i(x+10,y-99);
 		glVertex2i(x+12,y-99);
 		glVertex2i(x+12,y-91);
 		glVertex2i(x+18,y-99);
 		glVertex2i(x+28,y-99);
 		glVertex2i(x+20,y-90);
 		glEnd();

 	}


 	void man(GLint x, GLint y, GLfloat tcolor1, GLfloat tcolor2,GLfloat tcolor3, GLfloat pcolor1, GLfloat pcolor2,GLfloat pcolor3)
 	{

 		glColor3ub(0,0,0);
 		glPushMatrix();
 		glTranslatef(x-220,y+76,0);
 		glutSolidTorus(1,10,100,90);
 		glPopMatrix();
 		glColor3ub(255,191,128);
 		glPushMatrix();
 		glTranslatef(x-220,y+76,0);
 		glutSolidTorus(7,7,100,90);
 		glPopMatrix();
 		glColor3ub(0,0,0);
 		glBegin(GL_LINES);
 		glVertex2i(x-220,y+76);
 		glVertex2i(x-220,y-5+76); //nose
 		glVertex2i(x-9-220,y+5+76);
 		glVertex2i(x-3-220,y+5+76);//eyebrow
 		glVertex2i(x+3-220,y+5+76);
 		glVertex2i(x+9-220,y+5+76);//eyebrow
 		glEnd();
//ear right
 		glBegin(GL_POLYGON);
 		glColor3ub(255,191,128);
 		glVertex2i(x-14-220,y-1+1+76);
 		glVertex2i(x-14-220,y-5+1+76);
 		glVertex2i(x-2-14-220,y-6+1+76);
 		glVertex2i(x-2-14-220,y+1+76);
 		glEnd();
	//ear left
 		glBegin(GL_POLYGON);
 		glColor3ub(255,191,128);
 		glVertex2i(x+14-220,y+76);
 		glVertex2i(x+16-220,y+1+76);
 		glVertex2i(x+16-220,y-4+76);
 		glVertex2i(x+14-220,y-5+76);
 		glEnd();
//hair
 		glBegin(GL_POLYGON);
 		glColor3ub(0,0,0);
 		glVertex2i(x-13-220,y+8+76);
 		glVertex2i(x+13-220,y+8+76);
 		glVertex2i(x+7-220,y+14+76);
 		glVertex2i(x-7-220,y+14+76);
 		glEnd();


	// eyes
 		glBegin(GL_POLYGON);
 		glVertex2i(x-7-220,y+3+76);
 		glVertex2i(x-5-220,y+3+76);
 		glVertex2i(x-5-220,y+1+76);
 		glVertex2i(x-7-220,y+1+76);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x+5-220,y+3+76);
 		glVertex2i(x+7-220,y+3+76);
 		glVertex2i(x+7-220,y+1+76);
 		glVertex2i(x+5-220,y+1+76);
 		glEnd();
 	// mouth
 		glBegin(GL_POLYGON);
 		glVertex2i(x-5-220,y-8+76);
 		glVertex2i(x-220,y-10+76);
 		glVertex2i(x+5-220,y-8+76);
 		glVertex2i(x-220,y-8+76);
 		glEnd();
//beard
 		glBegin(GL_POLYGON);
 		glColor3ub(0,0,0);
 		glVertex2i(x-2-220,y-15+76);
 		glVertex2i(x+2-220,y-15+76);
 		glVertex2i(x+2-220,y-11+76);
 		glVertex2i(x-2-220,y-11+76);
 		glEnd();
//shirt
 		glBegin(GL_POLYGON);
 		glColor3f(tcolor1,tcolor2,tcolor3);
 		glVertex2i(x-11-220,y-15+76);
 		glVertex2i(x+11-220,y-15+76);
 		glVertex2i(x+26-220,y-26+76);
 		glVertex2i(x+21-220,y-34+76);
 		glVertex2i(x+16-220,y-30+76);
 		glVertex2i(x+16-220,y-50+76);
 		glVertex2i(x-16-220,y-50+76);
 		glVertex2i(x-16-220,y-30+76);
 		glVertex2i(x-21-220,y-35+76);
 		glVertex2i(x-26-220,y-26+76);
 		glEnd();
//hands
 		glBegin(GL_POLYGON);
 		glColor3ub(255,191,128);
 		glVertex2i(x+25-220,y-27+76);
 		glVertex2i(x+35-220,y-42+76);
 		glVertex2i(x+27-220,y-41+76);
 		glVertex2i(x+22-220,y-33+76);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x+35-220,y-42+76);
 		glVertex2i(x+16-220,y-57+76);
 		glVertex2i(x+16-220,y-50+76);
 		glVertex2i(x+27-220,y-41+76);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x-25-220,y-27+76);
 		glVertex2i(x-35-220,y-42+76);
 		glVertex2i(x-27-220,y-41+76);
 		glVertex2i(x-22-220,y-33+76);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2i(x-35-220,y-42+76);
 		glVertex2i(x-16-220,y-57+76);
 		glVertex2i(x-16-220,y-50+76);
 		glVertex2i(x-27-220,y-41+76);
 		glEnd();
// belt
 		glBegin(GL_POLYGON);
 		glColor3ub(150,12,30);
 		glVertex2i(x+16-220,y-50+76);
 		glVertex2i(x-16-220,y-50+76);
 		glVertex2i(x-16-220,y-55+76);
 		glVertex2i(x-16-220,y-55+76);

 		glVertex2i(x+16-220,y-55+76);
 		glEnd();
// collar
 		glBegin(GL_POLYGON);
 		glColor3ub(200,140,110+76);
 		glVertex2i(x-11-220,y-15+76);
 		glVertex2i(x+11-220,y-15+76);
 		glVertex2i(x+6-220,y-25+76);
 		glVertex2i(x-6-220,y-25+76);
 		glEnd();

 		glBegin(GL_TRIANGLES);
 		glColor3ub(20,140,110);
 		glVertex2i(x-220,y-18+76);
 		glVertex2i(x+5-220,y-25+76);
 		glVertex2i(x-5-220,y-25+76);
 		glEnd();

// buttons
 		glColor3ub(0,0,0);
 		glPushMatrix();
 		glTranslatef(x-220,y-30+76,0);
 		glutSolidTorus(1,1,100,90);
 		glPopMatrix();
 		glPushMatrix();
 		glTranslatef(x-220,y-37+76,0);
 		glutSolidTorus(1,1,100,90);
 		glPopMatrix();
 		glPushMatrix();
 		glTranslatef(x-220,y-44+76,0);
 		glutSolidTorus(1,1,100,90);
 		glPopMatrix();

	/// pant
 		glBegin(GL_POLYGON);
 		glColor3f(pcolor1,pcolor2,pcolor3);
 		glVertex2i(x+15-220,y-55+76);
 		glVertex2i(x-15-220,y-55+76);
 		glVertex2i(x-20-220,y-90+76);
 		glVertex2i(x-10-220,y-90+76);
 		glVertex2i(x-7-220,y-57+76);
 		glVertex2i(x+10-220,y-90+76);
 		glVertex2i(x+20-220,y-90+76);
 		glEnd();
		//shoe left
 		glBegin(GL_POLYGON);
 		glColor3ub(100,10,10);
 		glVertex2i(x-10-220,y-90+76);
 		glVertex2i(x-10-220,y-99+76);
 		glVertex2i(x-28-220,y-99+76);
 		glVertex2i(x-20-220,y-90+76);

 		glEnd();
	//shoe right
 		glBegin(GL_POLYGON);
 		glColor3ub(100,10,10);
 		glVertex2i(x+10-220,y-90+76);
 		glVertex2i(x+10-220,y-99+76);
 		glVertex2i(x+28-220,y-99+76);
 		glVertex2i(x+20-220,y-90+76);
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
 	void shed()
 	{
 		glColor3f(0.89,0.47,0.2);
 		glBegin(GL_POLYGON);
 		glVertex2d(600,380);
 		glVertex2d(610,380);
 		glVertex2d(610,550);
 		glVertex2d(600,550);
 		glEnd();
 		glBegin(GL_POLYGON);
 		glVertex2d(890,380);
 		glVertex2d(900,380);
 		glVertex2d(900,550);
 		glVertex2d(890,550);
 		glEnd();
 		glColor3f(0.2,0.2,0.2);
 		glBegin(GL_POLYGON);
 		glVertex2d(600,550);
 		glVertex2d(900,550);
 		glVertex2d(900,600);
 		glVertex2d(600,600);
 		glEnd();
 		glColor3f(1,1,1);
 		glRasterPos2i(700,570);
 		for( int o=0;o<strlen(parking);o++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,parking[o]);
 		glColor3f(0.91,0.76,0.65);
 		for(GLint i = 0; i<=10; i++)
 			circle_draw(680,580,i);
 		for(GLint i = 0; i<=10; i++)
 			circle_draw(800,580,i);
 	}
 	static void SpecialKeyFunc( int Key, int x, int y )
 	{
 		switch ( Key )
 		{
 			case GLUT_KEY_RIGHT:
 			mouse_status = 7;
 			glutPostRedisplay();
 			break;
 			case GLUT_KEY_LEFT:
 			mouse_status = 1;
 			glutPostRedisplay();
 			break;
 			case GLUT_KEY_DOWN:
 			status_mov_veh_light = 0;
 			glutPostRedisplay();
 			break;
 			case GLUT_KEY_UP:
 			status_mov_veh_light = 1;
 			glutPostRedisplay();
 			break;
 		}
 	}
 	void mouse(int btn,int state,int x,int y)
 	{
 		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
 		{
 			mouse_status = 7;
 			glutPostRedisplay();

 		}
 		else if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
 		{
 			mouse_status = 1;
 			glutPostRedisplay();

 		}

 	}

 	void football()
 	{

	//field
 		glColor3f(1,1,1);
 		glBegin(GL_POLYGON);
 		glVertex2i(80,160);
 		glVertex2i(80,840);
 		glVertex2i(500,840);
 		glVertex2i(500,160);
 		glEnd();
	//green inside
 		glColor3f(0,0.4,0);
 		glBegin(GL_POLYGON);
 		glVertex2i(85,165);
 		glVertex2i(85,835);
 		glVertex2i(495,835);
 		glVertex2i(495,165);
 		glEnd();
	//mid line
 		glColor3f(1,1,1);
 		glBegin(GL_QUADS);
 		glVertex2i(80,540);
 		glVertex2i(80,545);
 		glVertex2i(500,545);
 		glVertex2i(500,540);
 		glEnd();
	//football post
 		glBegin(GL_LINES);
 		glVertex2i(240,840);
 		glVertex2i(240,760);

 		glVertex2i(340,760);
 		glVertex2i(340,840);

 		glVertex2i(240,760);
 		glVertex2i(340,760);


 		glEnd();
	//circle
 		glColor3f(1,1,1);
 		for(GLint i = 80; i>= 75; i--)
 			circle_draw(300,540,i);
 	}
 	void otherkeys(unsigned char key, int x, int y) {

      if (key == 27) // escape key
      	exit(0);
      if(key == 32)
      {
      	football_xco = 110 + (rand() % ( 470 - 110 + 1 ) );
      	football_yco = 360 + (rand() % ( 800 - 360 + 1 ) );
      	glutPostRedisplay();
      }
      if(key == 72 || key == 104)
      {
      	help_pressed = 1;
      	glutPostRedisplay();
      }
      if(key == 67 || key == 99)
      {
      	help_pressed = 0;
      	glutPostRedisplay();
      }
      if(key == 76 || key == 108)
      {
      	car_ypos = 27;
      	glutPostRedisplay();
      }
      if(key == 73 || key == 105)
      {
      	car_ypos = 140;
      	glutPostRedisplay();
      }
      if(key == 80 || key == 112)
      {
      	if (parking_pressed_already == 1)
      	{
      		parking_status = 0;
      		parking_pressed_already = 0;
      	}
      	else
      	{
      		parking_status = 1;
      		parking_pressed_already = 1;
      	}
      	
      }



  }
  void help_message()
  {
  	glColor3f(0,0,0);
  	glRasterPos2i(20,850);
  	for( int o=0;o<strlen(help);o++)
  		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help[o]);
  	if(help_pressed == 1)
  	{
  		glColor3f(1,0,0);
  		glBegin(GL_POLYGON);
  		glVertex2i(480,880);
  		glVertex2i(480,670);
  		glVertex2i(1250,670);
  		glVertex2i(1250,880);
  		glEnd();
  		glColor3f(1.0,1.0,1.0);
  		glRasterPos2i(510,850);
  		for( int o=0;o<strlen(help1);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help1[o]);
  		glRasterPos2i(510,820);
  		for( int o=0;o<strlen(help2);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help2[o]);
  		glRasterPos2i(510,790);
  		for( int o=0;o<strlen(help3);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help3[o]);
  		glRasterPos2i(510,760);
  		for( int o=0;o<strlen(help6);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help6[o]);
  		glRasterPos2i(510,730);
  		for( int o=0;o<strlen(help7);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help7[o]);
  		glRasterPos2i(510,700);
  		for( int o=0;o<strlen(help4);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help4[o]);
  		glRasterPos2i(510,670);
  		for( int o=0;o<strlen(help5);o++)
  			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,help5[o]);

  	}
  }
  void display(void)
  {
  	glClear(GL_COLOR_BUFFER_BIT);
  	help_message();
  	football();
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
	//football players
  	man(580,default_start_walk_player1_yco,1.0,0,0,0,0,1);
  	srand (time(NULL));
  	rand_speed = rand() % 10 + 3;
  	if(status_football_player1_crossed == 1)
  	{
  		default_start_walk_player1_yco-=rand_speed+rand() % 4 ;
  		if(default_start_walk_player1_yco <= 380)
  			status_football_player1_crossed = 0;
  	}
  	else if (status_football_player1_crossed == 0)
  	{
  		default_start_walk_player1_yco+=rand_speed+rand() % 4;
  		if(default_start_walk_player1_yco>=700)
  			status_football_player1_crossed = 1;
  	}
  	man(default_start_walk_player2_xco,default_start_walk_player2_xco,1.0,0,0,0,0,1);
  	srand (time(NULL));
  	rand_speed = rand() % 10 + 3;
  	if(status_football_player2_crossed == 1)
  	{
  		default_start_walk_player2_xco-=rand_speed;
  		if(default_start_walk_player2_xco <= 380)
  			status_football_player2_crossed = 0;
  	}
  	else if (status_football_player2_crossed == 0)
  	{
  		default_start_walk_player2_xco+=rand_speed;
  		if(default_start_walk_player2_xco>=700)
  			status_football_player2_crossed = 1;
  	}
  	woman(football_goalkeeper_xco,795,0.55,0.9,0.9,0.85,0.85,0.9);
  	srand (time(NULL));
  	rand_speed = rand() % 10 + 3;
  	if(status_football_goalkeeper_crossed == 1)
  	{
  		football_goalkeeper_xco-=rand_speed;
  		if(football_goalkeeper_xco <= 160)
  			status_football_goalkeeper_crossed = 0;
  	}
  	else if (status_football_goalkeeper_crossed == 0)
  	{
  		football_goalkeeper_xco+=rand_speed;
  		if(football_goalkeeper_xco>=460)
  			status_football_goalkeeper_crossed = 1;
  	}
  	woman(football_lady_xco,700,0.55,0.9,0.9,0.85,0.85,0.9);
  	if(status_football_lady_crossed == 1)
  	{
  		football_lady_xco-=10;
  		if(football_lady_xco <= 100)
  			status_football_lady_crossed = 0;
  	}
  	else if (status_football_lady_crossed == 0)
  	{
  		football_lady_xco+=10;
  		if(football_lady_xco>=480)
  			status_football_lady_crossed = 1;
  	}

	//ball
  	for(GLint i = 0; i<30; i++)
  		circle_draw(football_xco,football_yco,i);

	//others
  	man(1560,400,0.5,0,0,0,0,1);
  	man(1530,220,1.0,0.9,0,0.2,0,1);

  	woman(560,495,0.85,0.53,0.10,0.55,0.9,0.9);
  	woman(1390,295,1,0,0,0.737255,0.560784,0.560784);
  	woman(1190,495,0.13,0.5,0.31,0.5,0.5,1);
  	shed();
  	woman(default_start_walk,655,0.89,0.47,0.82,0.52,0.39,0.39);
  	if(status_crossed == 1)
  	{
  		default_start_walk-=10;
  		if(default_start_walk <= 1000)
  			status_crossed = 0;
  	}
  	else if (status_crossed == 0)
  	{
  		default_start_walk+=10;
  		if(default_start_walk>=1300)
  			status_crossed = 1;
  	}
  	glutPostRedisplay();
  	vehicle(veh_xpos,car_ypos,status_mov_veh_light,0.3,0.3,1,0.5,0.0,0.0);
  	if(parking_status == 1)
  	{
  		vehicle(650,380,0,0.52,0.37,0.26,0.5,0.0,0.0);
  	}
  	else
  	{
  		vehicle(parking_car_xcod,parking_car_ycod,1,0.52,0.37,0.26,0.5,0.0,0.0);
  		parking_car_xcod += 8;
  		if((rand()%3)+1==1)
  		{
  			parking_car_ycod = 27;
  		}
  		else
  			parking_car_ycod = 140;

  		if(parking_car_xcod >=1300)
  		{
  			glColor3f(1.0,0,0);
  			glRasterPos2i(510,870);
  			for( int o=0;o<strlen(stolen);o++)
  				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,stolen[o]);
  		}
  	}
  	vehicle(mov_veh_xpos,27,1,1,0.7,0.12,0,0.4,0.1);
  	mov_veh_xpos+=15;
  	if (mov_veh_xpos>=1700)
  	{
  		mov_veh_xpos = 0;
  	}



  	if(mouse_status==7)
  	{
  		veh_xpos+=10;
  		if(veh_xpos >= 1100)
  		{
  			glColor3f(1.0,1.0,1.0);
  			glRasterPos2i(495,850);
  			for( int o=0;o<strlen(oops);o++)
  				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,oops[o]);
  		}
  	}
  	else if(mouse_status == 1)
  	{
  		mouse_status = 0;
  		veh_xpos -=10;
  		if(veh_xpos <= 40)
  		{
  			glColor3f(1.0,1.0,1.0);
  			glRasterPos2i(495,850);
  			for( int o=0;o<strlen(oops_r);o++)
  				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,oops_r[o]);
  		}
  	}
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
  	glutMouseFunc(mouse);
  	glutSpecialFunc( SpecialKeyFunc );
  	glutKeyboardFunc( otherkeys );
  	glutMainLoop();
  	return 0;
  }
