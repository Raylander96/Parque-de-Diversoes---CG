void set_colors(int name)
{
	if(name==0)
	{
		float materialGrey[]={0.8,0.8,0.8},materialWhite[]={0.2,0.2,0.2};
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,materialGrey);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,materialWhite);
	}

	if(name==GWHEEL_RING)
	{	float materialColours[][3]={{0.8,0.8,0.0},{0.33,0.33,0.33}, {0.9,0.4,0.4} ,{0.5450,0.27,0}, {0.36,0.36,0.36}},materialLightBr[][3]={{0,0,0},{0.3,0.3,0.3},{0,0,0},{0,0,0},{0.0,0.0,0.0}};
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,materialColours[gwheel_ring_color]);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,materialLightBr[gwheel_ring_color]);
	}
	if(name==GWHEEL_TROLLEY)
	{	float materialColours[][3]={{0.2,0.2,0.8},{0.8,0.8,0.0},{0.33,0.33,0.33}, {0.9,0.4,0.4} ,{0.5450,0.27,0}},materialLightBr[]={0.1,0.1,0.1};
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,materialColours[gwheel_trolley_color]);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,materialLightBr);
	}
}

void renderCylinder(float x1, float y1, float z1, float x2,float y2, float z2, float radius,int subdivisions,GLUquadricObj *quadric){

	float vx = x2-x1,vy = y2-y1,vz = z2-z1;
	if(vz == 0) vz = .0001;
	float v = sqrt( vx*vx + vy*vy + vz*vz );
	float ax = 57.2957795*acos( vz/v );
	if ( vz < 0.0 )
		ax = -ax;
	float rx = -vy*vz;
	float ry = vx*vz;
	glPushMatrix();
	glTranslatef( x1,y1,z1 );
	glRotatef(ax, rx, ry, 0.0);
	gluQuadricOrientation(quadric,GLU_OUTSIDE);
	gluCylinder(quadric, radius, radius, v, subdivisions, 1);
	gluQuadricOrientation(quadric,GLU_INSIDE);
	gluDisk( quadric, 0.0, radius, subdivisions, 1);
	glTranslatef( 0,0,v );
	gluQuadricOrientation(quadric,GLU_OUTSIDE);
	gluDisk( quadric, 0.0, radius, subdivisions, 1);
	glPopMatrix();

}

void draw_cyl(float x1, float y1, float z1, float x2,float y2, float z2, float radius,int subdivisions){
	GLUquadricObj *quadric=gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
	renderCylinder(x1,y1,z1,x2,y2,z2,radius,subdivisions,quadric);
	gluDeleteQuadric(quadric);
}