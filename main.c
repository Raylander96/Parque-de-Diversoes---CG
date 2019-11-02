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
	glRotatef(gw_spin, 0.0, 0.0, 1.0);
	draw_gwheel();
	glPopMatrix();
	
	
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

	if(key=='w')
	{
		movcord[0]+=5*cos(-1*x_r*3.14/180.0);
		movcord[2]+=5*sin(1*x_r*3.14/180.0);
	}
	if(key== 's')
	{
		movcord[0]-=5*cos(-1*x_r*3.14/180.0);
		movcord[2]-=5*sin(1*x_r*3.14/180.0);
	}
	if(key=='d') 
		x_r+=3;
	if(key=='a') 
		x_r-=3;
	if(key == 27){
		exit(0);
	}
	if(key == 'n'){

		if(fog){
			fog=0;
		}else{
			fog=1;
		}
		fogEnable();
	}

	display();
}

int main(int argc, char** argv){

   		SDL_Init (SDL_INIT_AUDIO);
    	atexit (SDL_Quit);
    	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);  

		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
		glutInitWindowSize(800,600);
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


