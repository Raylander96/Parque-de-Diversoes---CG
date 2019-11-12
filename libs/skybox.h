
void Draw_Skybox(float x, float y, float z, float width, float height, float length){

	glDisable(GL_DEPTH_TEST);
	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_UP]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x+width, y+height, z);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x+width, y+height, z+length);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x,		  y+height,	z+length);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x,		  y+height,	z); 
	glEnd();

	glBindTexture(GL_TEXTURE_2D,skybox[SKY_FRONT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x+width, y,		z);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x+width, y,		z+length);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x+width, y+height,	z+length); 
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x+width, y+height,	z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,skybox[SKY_BACK]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x, y+height,	z);	
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x,y+height,z+length); 
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x,y,z+length);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x,y,	z);		
	glEnd();

	glBindTexture(GL_TEXTURE_2D,skybox[SKY_RIGHT]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x+width, y,z);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x+width, y+height, z); 
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x,y+height,z);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x,y,z);
	glEnd();
 
	glBindTexture(GL_TEXTURE_2D,skybox[SKY_LEFT]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x,y,z+length);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x,y+height, z+length);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x+width, y+height, z+length); 
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x+width, y,z+length);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,skybox[SKY_DOWN]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x+width, y,z+length); 
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f(x+width, y,z);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f(x,y,z);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(x,y,	z+length);
	glEnd();
 	glDisable(GL_TEXTURE_2D);

}

void initSky(){

	glShadeModel(GL_SMOOTH);							
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				
	glClearDepth(1.0f);									
	glEnable(GL_DEPTH_TEST);														
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	skybox[SKY_DOWN] = LoadBMP("images/down.bmp");
	skybox[SKY_FRONT] = LoadBMP("images/front.bmp");
	skybox[SKY_BACK] = LoadBMP("images/back.bmp");
	skybox[SKY_RIGHT] = LoadBMP("images/right.bmp");
	skybox[SKY_LEFT] = LoadBMP("images/left.bmp");
	skybox[SKY_UP] = LoadBMP("images/up.bmp");
	floor_park=LoadBMP("images/floor.bmp");
	
	
}


void draw_floor(){
			
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,floor_park);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(5000,-10,5000);
	glTexCoord2f(800.0f, 0.0f); 
	glVertex3f(5000,-10,-5000);
	glTexCoord2f(800.0f, 800.0f); 
	glVertex3f(-5000,-10,-5000);
	glTexCoord2f(0.0f, 800.0f); 
	glVertex3f(-5000,-10,5000);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glLineWidth(5.0);
	glTranslatef(0.0, -2, 0.0);
	glTranslatef(0.0, 2, 0.0);
}