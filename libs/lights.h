void initLightsforGW(){

	GLfloat light_post1[]={0.0,50.0,0.0,1.0},whiteSpecularLight[] = {0.5, 0.5, 0.5},blackAmbientLight[] = {0.3, 0.3, 0.3},whiteDiffuseLight[] = {0.6, 0.6, 0.6},mShininess[] = {128},twoModel[]={GL_TRUE};
	glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, whiteSpecularLight);
   	glLightfv(GL_LIGHT1, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT1, GL_POSITION, light_post1);
}

void initLights()
{

	GLfloat whiteSpecularMaterial[] = {1.0,1.0,1.0},light_post0[]={0.0,0.0,10.0,1.0},whiteSpecularLight[] = {1.0, 1.0, 1.0},blackAmbientLight[] = {0.3, 0.3, 0.3},whiteDiffuseLight[] = {1.0, 1.0, 1.0},mShininess[] = {50},twoModel[]={GL_TRUE}; 
	glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
   	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, light_post0);
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, twoModel);
 	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpecularMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
}