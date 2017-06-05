//including all headers
#include <GL/glut.h>
//testing and debugging purpose ***remove at release ***
#include <stdio.h>
#include <string.h>

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
char distance[20] = "Distance Travelled";
char oops[100] = "OOPS!! you are going outside of college boundry   Move Left";
char oops_r[100] = "OOPS!! you are going outside of college boundry   Move Right";
int mouse_status = 0;
int distance_km = 0;
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

void woman()
{
	//face
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540,495,0);
	//glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
	glPushMatrix();
	glTranslatef(540,494,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540,494);
 		glVertex2i(540,490); //nose
  		glVertex2i(531,498);
		glVertex2i(532,499);
 		glVertex2i(532,499);
		glVertex2i(537,498);//eyebrow
  	    glVertex2i(549,498);
		glVertex2i(548,499);
		glVertex2i(548,499);
 		glVertex2i(543,498);//eyebrow
 	glEnd();
	//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14,494+1);
	glVertex2i(540-14,490+1);
	glVertex2i(538-14,489+1);
	glVertex2i(538-14,495+1);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554,495);
	glVertex2i(556,496);
	glVertex2i(556,491);
	glVertex2i(554,490);
	glEnd();
	//ear ring right
	glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(539-14,492);
	glVertex2i(542-14,485);
	glVertex2i(536-14,485);

	glEnd();
	//ear ring left
   glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(551,485);
	glVertex2i(555,492);
	glVertex2i(558,485);
	glEnd();

//hair
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(525,499);
	glVertex2i(549,509);
	glVertex2i(540,512);
	glVertex2i(528,507);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(540,507);
	glVertex2i(549,509);
	glVertex2i(552,507);
	glVertex2i(555,499);
	glEnd();
	// eyes
        glBegin(GL_POLYGON);
 		glVertex2i(533,496);
 		glVertex2i(535,496);
 		glVertex2i(535,494);
 		glVertex2i(533,494);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545,496);
 		glVertex2i(547,496);
     	glVertex2i(547,494);
 		glVertex2i(545,494);
glEnd();
//mouth
glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
        glVertex2i(534,487);
 		glVertex2i(540,484);
 		glVertex2i(546,487);
 		glVertex2i(540,485);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(160,150,250);
        glVertex2i(529,480);
 		glVertex2i(551,480);
 		glVertex2i(566,469);
 		glVertex2i(561,460);
 		glVertex2i(556,465);
        glVertex2i(556,445);
 		glVertex2i(524,445);
 		glVertex2i(524,465);
 		glVertex2i(519,460);
 		glVertex2i(514,469);
glEnd();
//neck
    glBegin(GL_POLYGON);
        glColor3ub(255,190,128);
        glVertex2i(533,480);
        glVertex2i(547,480);
        glVertex2i(545,471);
        glVertex2i(535,471);
    glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565,468);
 		glVertex2i(575,453);
 		glVertex2i(567,454);
 		glVertex2i(562,462);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575,453);
 		glVertex2i(556,438);
 		glVertex2i(556,445);
 		glVertex2i(567,454);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515,468);
 		glVertex2i(505,453);
 		glVertex2i(513,454);
 		glVertex2i(518,462);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505,453);
   		glVertex2i(524,438);
   		glVertex2i(524,445);
   		glVertex2i(513,454);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(10,120,130);
 		glVertex2i(556,445);
 		glVertex2i(524,445);
 		glVertex2i(524,440);
 		glVertex2i(556,440);
glEnd();


	/// leg
glBegin(GL_POLYGON);
		glColor3ub(255,190,128);
glVertex2i(555,440);
glVertex2i(525,440);
glVertex2i(520,405);
glVertex2i(530,405);
glVertex2i(533,438);
glVertex2i(550,405);
glVertex2i(560,405);
	glEnd();
//skirt
    glBegin(GL_POLYGON);
	    glColor3ub(180,80,90);
		glVertex2i(524,440);
		glVertex2i(556,440);
		glVertex2i(566,410);
		glVertex2i(514,410);
    glEnd();
	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(530,405);
	glVertex2i(530,396);
	glVertex2i(528,396);
	glVertex2i(528,404);
	glVertex2i(522,396);
	glVertex2i(512,396);
	glVertex2i(520,405);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(550,405);
	glVertex2i(550,396);
	glVertex2i(552,396);
	glVertex2i(552,404);
	glVertex2i(558,396);
	glVertex2i(568,396);
	glVertex2i(560,405);
	glEnd();

}



void man()
{
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,495+76,0);
	glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540-220,495+76,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540-220,495+76);
 		glVertex2i(540-220,490+76); //nose
  		glVertex2i(531-220,500+76);
 		glVertex2i(537-220,500+76);//eyebrow
  		glVertex2i(543-220,500+76);
 		glVertex2i(549-220,500+76);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14-220,494+1+76);
	glVertex2i(540-14-220,490+1+76);
	glVertex2i(538-14-220,489+1+76);
	glVertex2i(538-14-220,495+1+76);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554-220,495+76);
	glVertex2i(556-220,496+76);
	glVertex2i(556-220,491+76);
	glVertex2i(554-220,490+76);
	glEnd();
//hair
	glBegin(GL_POLYGON);
	  glColor3ub(0,0,0);
	  glVertex2i(527-220,503+76);
	  glVertex2i(553-220,503+76);
	  glVertex2i(547-220,509+76);
	  glVertex2i(533-220,509+76);
	glEnd();


	// eyes
 	glBegin(GL_POLYGON);
 		glVertex2i(533-220,498+76);
 		glVertex2i(535-220,498+76);
 		glVertex2i(535-220,496+76);
 		glVertex2i(533-220,496+76);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545-220,498+76);
 		glVertex2i(547-220,498+76);
 		glVertex2i(547-220,496+76);
 		glVertex2i(545-220,496+76);
glEnd();
 	// mouth
glBegin(GL_POLYGON);
 		glVertex2i(535-220,487+76);
 		glVertex2i(540-220,485+76);
 		glVertex2i(545-220,487+76);
 		glVertex2i(540-220,487+76);
glEnd();
//beard
glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(538-220,480+76);
	glVertex2i(542-220,480+76);
	glVertex2i(542-220,484+76);
	glVertex2i(538-220,484+76);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(55,50,70);
	    glVertex2i(529-220,480+76);
 		glVertex2i(551-220,480+76);
 		glVertex2i(566-220,469+76);
 		glVertex2i(561-220,461+76);
 		glVertex2i(556-220,465+76);
        glVertex2i(556-220,445+76);
 		glVertex2i(524-220,445+76);
 		glVertex2i(524-220,465+76);
 		glVertex2i(519-220,460+76);
 		glVertex2i(514-220,469+76);
glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565-220,468+76);
 		glVertex2i(575-220,453+76);
 		glVertex2i(567-220,454+76);
 		glVertex2i(562-220,462+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575-220,453+76);
 		glVertex2i(556-220,438+76);
 		glVertex2i(556-220,445+76);
 		glVertex2i(567-220,454+76);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515-220,468+76);
 		glVertex2i(505-220,453+76);
 		glVertex2i(513-220,454+76);
 		glVertex2i(518-220,462+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505-220,453+76);
   		glVertex2i(524-220,438+76);
   		glVertex2i(524-220,445+76);
   		glVertex2i(513-220,454+76);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(150,12,30);
 		glVertex2i(556-220,445+76);
 		glVertex2i(524-220,445+76);
 		glVertex2i(524-220,440+76);
		glVertex2i(524-220,440+76);

 		glVertex2i(556-220,440+76);
glEnd();
// collar
 	glBegin(GL_POLYGON);
		glColor3ub(200,140,110+76);
 		glVertex2i(529-220,480+76);
 		glVertex2i(551-220,480+76);
 		glVertex2i(546-220,470+76);
 		glVertex2i(534-220,470+76);
glEnd();

 	glBegin(GL_TRIANGLES);
		glColor3ub(20,140,110);
 		glVertex2i(540-220,477+76);
  		glVertex2i(545-220,470+76);
 		glVertex2i(535-220,470+76);
glEnd();

// buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,465+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,458+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,451+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();

	/// pant
glBegin(GL_POLYGON);
		glColor3ub(80,80,230);
glVertex2i(555-220,440+76);
glVertex2i(525-220,440+76);
glVertex2i(520-220,405+76);
glVertex2i(530-220,405+76);
glVertex2i(533-220,438+76);
glVertex2i(550-220,405+76);
glVertex2i(560-220,405+76);
	glEnd();
		//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(530-220,405+76);
	glVertex2i(530-220,396+76);
	glVertex2i(512-220,396+76);
	glVertex2i(520-220,405+76);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(550-220,405+76);
	glVertex2i(550-220,396+76);
	glVertex2i(568-220,396+76);
	glVertex2i(560-220,405+76);
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
			distance_km+=5;
        	glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
			distance_km-=5;
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
    	distance_km+=5;
    	glutPostRedisplay();

	}
	else if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
    	distance_km-=5;
    	mouse_status = 1;
    	glutPostRedisplay();

	}

}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,1.0,1.0);
		    glRasterPos2i(20,850);
		    for( int o=0;o<strlen(distance);o++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,distance[o]);
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
	man();
	woman();
	shed();
	vehicle(veh_xpos,140,status_mov_veh_light,0.3,0.3,1,0.5,0.0,0.0);
	vehicle(650,380,0,0.52,0.37,0.26,0.5,0.0,0.0);
	if(mouse_status!=1)
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
	else
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
	glutMainLoop();
	return 0;
}
