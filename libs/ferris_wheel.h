
void draw_seat()
{

glPushMatrix();
glEnable(GL_LIGHTING);
glTranslatef(1.0, 0.0, -1.0);
glRotatef(90.0, 0.0, 0.0, 1.0);
glTranslatef(0.0, 0.5, 0.0);
draw_cyl(-2.5,0.0,0.0,2.5,0.0,0.0,0.05,6);
glTranslatef(0.0,-0.5,0.0);
glNormal3f(0.0,1.0,0.0);
glScalef(4.0, 0.1, 1.0);
glutSolidCube(1.0);
glScalef(1/4.0, 1/0.1, 1.0);
glTranslatef(0.0, 0.5, -1.0);
glRotatef(80.0, 1.0, 0.0, 0.0);
glScalef(4.0, 0.1, 1.0);
glNormal3f(0.0,1.0,0.0);
glutSolidCube(1.0);
glScalef(1/4.0, 1/0.1, 1.0);
glPopMatrix();


}

void draw_wagon(){
	

	GLdouble wagon_size=5.0;
	double eqn[]={0.0, -1.0, 0.0, -3.5};
	glPushMatrix();
	glTranslatef(0.0, -5.0, 0.0);
	glEnable(GL_CLIP_PLANE0);
	glClipPlane(GL_CLIP_PLANE0, eqn);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glDisable(GL_CLIP_PLANE0);
	for(int c=0;c<4;c++)
	{
		glRotatef((90/4.0), 0.0, 1.0, 0.0);
		glNormal3f(1.0,0.0,0.0);
		glutWireCube(wagon_size*2.0);
	}
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glScalef(2.0, 3.0, 2.0);
	set_colors(0);
	draw_seat();
	set_colors(GWHEEL_TROLLEY);
	glScalef(1/2.0,1/3.0,1/2.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glPopMatrix();
	glTranslatef(0.0, wagon_size, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidCone(5.0, 5.0, 6,6);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -2*wagon_size, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	GLUquadricObj *quadric=gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluDisk(quadric, 0.0, 6.0, 16.0, 1.0);
	gluDeleteQuadric(quadric);
	glDisable(GL_LIGHTING);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

}
void draw_gwheel()
{
	int num=12;
	GLUquadricObj *quadric=gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
	
	glPushMatrix();
	
	initLightsforGW();
	GLfloat twoModel[]={GL_FALSE};
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, twoModel);
	set_colors(GWHEEL_RING);
	glTranslatef(0.0,0.0, gw_width);
	glRotatef(-gw_spin,0,0,1);
	draw_cyl(0,0,0,0,-55,20,1.5,8);
	glTranslatef(0.0,0.0, -gw_width*2);
	draw_cyl(0,0,0,0,-55,-20,1.5,8);
	glTranslatef(0.0,0.0, gw_width*2);
	glRotatef(gw_spin,0,0,1);
	glutSolidTorus(1.0, 35.0, 16, 64);

	twoModel[0]=GL_TRUE;
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, twoModel);
	gluDisk(quadric,0.0, 10.0, 10.0, 1);
	glTranslatef(0.0,0.0, -gw_width*2);
	glutSolidTorus(1.0, 35.0, 16, 64);
	gluDisk(quadric,0.0, 10.0, 10.0, 1);
	glTranslatef(0.0,0.0, gw_width); 

	twoModel[0]=GL_FALSE;
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, twoModel);

	for(int i=0; i<num; i++)
	{
		glEnable(GL_LIGHTING);	
		glPushMatrix();
		glRotatef(360*i/num, 0.0, 0.0, 1.0);
		glEnable(GL_DEPTH_TEST);
		glTranslatef(0.0,0.0, gw_width); 
		draw_cyl(0.0, 45.0, 0.0, 0.0, 45.0, -5.0, 1.0, 12);
		draw_cyl(0.0, 45.0, 0.0, 0.0, 2.0, 0.0, 1.0, 12);
		glTranslatef(0.0,0.0, -gw_width*2); 
		draw_cyl(0.0, 45.0, 0.0, 0.0, 2.0, 0.0, 1.0, 12);
		draw_cyl(0.0, 45.0, 0.0, 0.0, 45.0, 5.0, 1.0, 12);
		glTranslatef(0.0,0.0, gw_width); 
		glDisable(GL_LIGHTING);
		glTranslatef(0.0, -45.0, 0.0);
		glRotatef(-gw_spin-(360*i/num)-sin(gw_spin/10.0)*10.0, 0.0, 0.0, 1.0);
		set_colors(GWHEEL_TROLLEY);
		draw_wagon();
		set_colors(GWHEEL_RING);
		glTranslatef(0.0, 45.0, 0.0);
		glPopMatrix();

	}
	set_colors(0);
	glPopMatrix();
	glDisable(GL_LIGHT1);
}

