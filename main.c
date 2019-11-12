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
struct modelo *placa, *seat,*tower,*tree_1,*tree_2,*tree_3,*light,*bush,*home,*cup,*seat_park,*parking;

void display();



void idle(){
	
	gw_spin+=0.25;
	cup_spin+=2.5;

	if(tower_up_down==0){
		up=1;
	}
	if(tower_up_down==400){
		up=0;
	}

	if(up){
		tower_up_down+=1;
	}else{
		tower_up_down-=5;
	}
	
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
	draw_floor();
	//glColor3f(1.0, 1.0, 1.0);

	
	glPushMatrix();
		glTranslatef(80,0,165);
		glPopMatrix();
			glTranslatef(co_x, co_y, -co_z);
		glPopMatrix();
	glPushMatrix();
		glTranslatef(gw_x, gw_y, -10);
		glRotatef(gw_spin, 0.0, 0.0, 1.0);
		draw_gwheel();
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-180, -15, +400);
		glScalef(10, 10, 10);
		glEnable(GL_LIGHTING);
		desenhaModelo(placa);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(co_x, tower_up_down, co_z);
		glScalef(25, 25, 25);
		glEnable(GL_LIGHTING);
		desenhaModelo(seat);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(co_x-55, co_y-10, co_z+85);
		glScalef(25, 25, 25);
		glEnable(GL_LIGHTING);
		desenhaModelo(tower);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(-100, -15, +400);
		glScalef(10, 10, 10);
		glEnable(GL_LIGHTING);
		desenhaModelo(tree_1);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(-250, -15, +400);
		glScalef(10, 10, 10);
		glEnable(GL_LIGHTING);
		desenhaModelo(tree_2);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	float j = 390;
	for(int i=0 ; i <5; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(-220, -15, j);
			glScalef(10, 10, 10);
			glEnable(GL_LIGHTING);
			desenhaModelo(light);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		j=j-50;
	}

	j = 390;
	for(int i=0 ; i <5; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(-140, -15, j);
			glScalef(10, 10, 10);
			glEnable(GL_LIGHTING);
			desenhaModelo(light);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		j=j-50;
	}
	
	//Frente lado esquerdo
	float k = -220;
	for(int i=0 ; i <25; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(k, -15, +400);
			glScalef(20, 20, 20);
			glEnable(GL_LIGHTING);
			desenhaModelo(bush);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		k=k-15;
	}
	//lateral direita
	float l = 400;
	for(int i=0 ; i <50; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(k, -15, l);
			glScalef(20, 20, 20);
			glEnable(GL_LIGHTING);
			desenhaModelo(bush);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		l=l-15;
	}

	//Frente lado direito
	k = -140;
	for(int i=0 ; i <25; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(k, -15, +400);
			glScalef(20, 20, 20);
			glEnable(GL_LIGHTING);
			desenhaModelo(bush);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		k=k+15;
	}

	//lateral esquerdo
	l = 400;
	for(int i=0 ; i <50; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(k, -15, l);
			glScalef(20, 20, 20);
			glEnable(GL_LIGHTING);
			desenhaModelo(bush);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		l=l-15;
	}

	//fundo
	for(int i=0 ; i <56; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(k, -15, l);
			glScalef(20, 20, 20);
			glEnable(GL_LIGHTING);
			desenhaModelo(bush);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		k=k-15;
	}

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(-400, -15, +150);
		glScalef(0.4, 0.4, 0.4);
		glEnable(GL_LIGHTING);
		desenhaModelo(home);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(-430, -15, +190);
		glRotatef(cup_spin, 0.0, cup_spin, 0.0);
		glScalef(0.7, 0.7, 0.7);
		glEnable(GL_LIGHTING);
		desenhaModelo(cup);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(-430, -15, +120);
		glRotatef(cup_spin, 0.0, -cup_spin, 0.0);
		glScalef(0.7, 0.7, 0.7);
		glEnable(GL_LIGHTING);
		desenhaModelo(cup);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glTranslatef(-380, -15, +150);
		glRotatef(cup_spin, 0.0, -cup_spin, 0.0);
		glScalef(0.7, 0.7, 0.7);
		glEnable(GL_LIGHTING);
		desenhaModelo(cup);
		glDisable(GL_LIGHTING);
	glPopMatrix();

	//bancos lado esquerdo
	j = 365;
	for(int i=0 ; i <4; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(-220, -15, j);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.1, 0.1, 0.1);
			glEnable(GL_LIGHTING);
			desenhaModelo(seat_park);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		j=j-50;
	}

	//bancos lado direito
	j = 365;
	for(int i=0 ; i <4; i++){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(-140, -15, j);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glScalef(0.1, 0.1, 0.1);
			glEnable(GL_LIGHTING);
			desenhaModelo(seat_park);
			glDisable(GL_LIGHTING);
		glPopMatrix();
		j=j-50;
	}

	//Estacionamento
	glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glTranslatef(420, -15, -50);
			glScalef(5, 5, 5);
			glEnable(GL_LIGHTING);
			desenhaModelo(parking);
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
	//if(move){
		if(key=='w'  || key == 'W'){
		movcord[0]+=5*cos(-1*x_r*3.14/180.0);
		movcord[2]+=5*sin(1*x_r*3.14/180.0);
		}

		if(key== 's'  || key == 'S'){
			movcord[0]-=5*cos(-1*x_r*3.14/180.0);
			movcord[2]-=5*sin(1*x_r*3.14/180.0);
		}

		if(key=='d' || key == 'D') 
			x_r+=3;
		
		if(key=='a' || key == 'A') 
			x_r-=3;
	//}

	if(key==75){
		camw--;
		place_camera(camw);
	}
	if(key==77){
		camw++;
		place_camera(camw);
	}
	
	if(key == 27){
		exit(0);
	}

	if(key=='2'){
		move=0;
		place_camera(2);
	}
	if(key=='3'){
		move=0;
		place_camera(3);
	}

	if(key=='1'){
		move=1;
		place_camera(1);
	}

	if(key=='4'){
		move=1;
		place_camera(4);
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
   	placa = carregaModelo("objs/placa_2.obj");
	seat = carregaModelo("objs/seat.obj");
    tower = carregaModelo("objs/tower.obj");
	tree_1 = carregaModelo("objs/tree_1.obj");
	tree_2 = carregaModelo("objs/tree_2.obj");
	tree_3 = carregaModelo("objs/tree_3.obj");
	light = carregaModelo("objs/light_baseless.obj");
	bush = carregaModelo("objs/bush_1.obj");
	home = carregaModelo("objs/house.obj");
	cup = carregaModelo("objs/coffeMug1_free_obj.obj");
	seat_park = carregaModelo("objs/Cgtuts_Wood_Bench_OBJ.obj");
	parking = carregaModelo("objs/parking lot.obj");
}

void place_camera(int action)
{

	camw=action;
	//Primeira pessoa posicao inicial
	if(camw==1){
		viewer[1] = -0.0f;
		x_r=93;
		movcord[0]=0;
		movcord[1]=-10;
		movcord[2]=-520;
	}
	//Roda gigante
	if(camw==2){	
		viewer[1] = 0.5;
		x_r=93;
		movcord[0]=0;//Direira esquerda
		movcord[1]=-100;//Cima baixo
		movcord[2]=-30;//Frente traz=s
	}
	//Xicara maluca
	if(camw==3){
		viewer[1] = 0.5;
		x_r=362;	
		movcord[0]=8;
		movcord[1]=-100;
		movcord[2]=-80;
	}

	//tower
	if(camw==4){
		viewer[1] = 1.0;
		x_r=180;	
		movcord[0]=-80;
		movcord[1]=-300;
		movcord[2]=0;
	}

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


