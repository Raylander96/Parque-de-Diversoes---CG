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
#include "libs/modelo.h"
GLuint elephant;
float elephantrot;
char ch='1';
struct modelo *modelo, *modelo1;

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
	//glColor3f(1.0, 1.0, 1.0);

	
	glPushMatrix();
		glTranslatef(80,0,165);
		glPopMatrix();
			glTranslatef(co_x, co_y, -co_z);
		glPopMatrix();
	glPushMatrix();
		glTranslatef(gw_x, gw_y, -gw_z);
		glRotatef(gw_spin, 0.0, 0.0, 1.0);
		draw_gwheel();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(co_x, co_y, -co_z);
		glScalef(2, 2, 2);
		glEnable(GL_LIGHTING);
		desenhaModelo(modelo);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(co_x, co_y, co_z);
		glScalef(2, 2, 2);
		glEnable(GL_LIGHTING);
		desenhaModelo(modelo1);
		glDisable(GL_LIGHTING);
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

void setup() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // branco
    glCullFace(GL_BACK);
    // habilita o depth buffer para que a coordenada Z seja usada
    glEnable(GL_DEPTH_TEST);

    // habilita anti-aliasing para desenhar as linhas de forma suave
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable( GL_LINE_SMOOTH );

    // habilita blending para que transparências (e.g., linhas suaves) funcionem
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // modelo de iluminação
    glEnable(GL_LIGHT0);
    vetor direcaoLuz[] = { -1.0, 2.0, 2.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, direcaoLuz);
    glEnable(GL_LIGHT1);
    vetor direcaoLuz2[] = { 2.0, 4.0, -2.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, direcaoLuz2);

    glShadeModel(GL_FLAT);

    
}

void loadModels(){
	// carrega o modelo
   	modelo = carregaModelo("porsche.obj");
	modelo1 = carregaModelo("flowers.obj");
    //modelo = carregaModelo("arvore.obj");
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
		//setup();
		loadModels();
  		glutDisplayFunc(display);
	 	glutReshapeFunc(displayReshape);
	 	glutKeyboardFunc(keyboard);
		glutIdleFunc(idle);
		
		
		glutMainLoop();
		return 0;
}


