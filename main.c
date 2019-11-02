#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>
#include "libs/globais.h"
#include "libs/images.h"
#include "libs/skybox.h"
#include "libs/lights.h"
#include "libs/draw.h"
#include "libs/ferris_wheel.h"
#include "libs/song.h"

GLuint elephant;
float elephantrot;
char ch='1';

void display();



void idle(){

	gw_spin+=0.25;
	display();
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0,1.0,1.0,1.0);
	glLoadIdentity();	
	gluLookAt(viewer[0], viewer[1], viewer[2],camera[0], camera[1], camera[2],0, 1, 0);
	
	glRotatef(x_r, 0, 1, 0);
	Draw_Skybox(viewer[0]+(0.05*movcord[0]),viewer[1]+(0.05*movcord[1]),viewer[2]+(0.05*movcord[2]),250,250,250);

	glTranslatef(movcord[0],movcord[1],movcord[2]);
	draw_ground();  
	glPushMatrix();
		glTranslatef(80,0,165);
		glPopMatrix();
			glTranslatef(co_x, co_y, -co_z);
		glPopMatrix();
	glPushMatrix();
	glTranslatef(gw_x, gw_y, -gw_z);
	//drawElephant();
	glRotatef(gw_spin, 0.0, 0.0, 1.0);
	
	draw_gwheel();
	glPopMatrix();
	//glLoadIdentity();
    
	
	glutSwapBuffers();

}

void displayReshape(int width,int height){

	glViewport(0,0,width,height);						
	glMatrixMode(GL_PROJECTION);						
	glLoadIdentity();
	gluPerspective(65,(GLfloat)width/(GLfloat)height,0.01f,1000.0f);
	glMatrixMode(GL_MODELVIEW);						
	glLoadIdentity();			
}
void fogEnable(){

	if(fog){	
		GLfloat density = 0.009; //set the density to 0.3 which isacctually quite thick
		GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0}; //set the forcolor to grey

		glEnable (GL_DEPTH_TEST); 
		glEnable (GL_FOG); 
		glFogi (GL_FOG_MODE, GL_EXP2); 
		glFogfv (GL_FOG_COLOR, fogColor); 
		glFogf (GL_FOG_DENSITY, density); 
		glHint (GL_FOG_HINT, GL_NICEST); 
	
	}else{
		glDisable(GL_FOG);
	}
	
	
}
void keyboard(unsigned char key, int x, int y){
	if(key=='+') movcord[1]--;
	if(key=='-') movcord[1]++;
	if(key=='w'  || key == 'W')
	{
		movcord[0]+=5*cos(-1*x_r*3.14/180.0);
		movcord[2]+=5*sin(1*x_r*3.14/180.0);
	}
	if(key== 's'  || key == 'S')
	{
		movcord[0]-=5*cos(-1*x_r*3.14/180.0);
		movcord[2]-=5*sin(1*x_r*3.14/180.0);
	}
	if(key=='d' || key == 'D') 
		x_r+=3;
	if(key=='a' || key == 'A') 
		x_r-=3;
	if(key == 27){
		exit(0);
	}
	if(key == 'n' || key == 'N'){

		if(fog){
			fog=0;
		}else{
			fog=1;
		}
		fogEnable();
	}

	display();
}

void loadObj(char *fname)
{
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    elephant=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(5.0);
    glNewList(elephant, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read==4&&ch=='v')
            {
                glVertex3f(x,y,z);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}

void drawElephant()
{
    loadObj("images/al.obj");
    glPushMatrix();
    glTranslatef(0,-40.00,-105);
    glColor3f(1.0,0.23,0.27);
    glScalef(20.9,20.9,20.9);
    glRotatef(elephantrot,0,1,0);
    glCallList(elephant);
    glPopMatrix();
    elephantrot=elephantrot+0.6;
    if(elephantrot>360)elephantrot=elephantrot-360;
}

int main(int argc, char** argv){

   		SDL_Init (SDL_INIT_AUDIO);
    	atexit (SDL_Quit);
    	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);  

		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
		glutInitWindowSize(1500,1200);
		glutCreateWindow("Parque de Diversao");
		initLights();
		initSky();
		songPlay();
  		glutDisplayFunc(display);
	 	glutReshapeFunc(displayReshape);
	 	glutKeyboardFunc(keyboard);
		glutIdleFunc(idle);
		glutMainLoop();
		return 0;
}


