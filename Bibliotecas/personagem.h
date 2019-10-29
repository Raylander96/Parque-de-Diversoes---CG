void desenhaPersonagem()
{
    int i;
    lx = sin(angle);
	lz = -cos(angle);

	if (pula == 2)
    {
    	altura -= (0.2*vel);
    	vel *= 1.3;

    	if (altura <= 0)
    	{
    		pula = 0;
    		vel = 1;
    	}
    }

    else if (pula == 1)
    {
    	altura += (0.2*vel);
    	vel /= 1.3;	

    	if (altura >= 0.85)
    	{
    		pula = 2;
    		vel *= 1.5;
    	}    		
    }

    if (music == 0)
    {
    	Mix_PlayMusic(theme, -1);
    	music = 1;
    }

    glLoadIdentity();

		if (camera == 0)
	    	gluLookAt(inix, altura+1, iniz+z,
					inix+lx, altura+1, iniz+z+lz,
					0, 1,  0);
		else
			gluLookAt(inix+(-1*lz*2), altura+1, iniz+z+(lx*2),
					inix+lx, altura+1, iniz+z+lz,
					0, 1, 0);

    glPushMatrix();
		//cabeça
   		glTranslatef (inix, altura+1, iniz+z);
	   	glRotatef ((GLfloat) angulo, 0, 1, 0);
	   	glScalef (0.1, 0.1, 0.1);
	   	glColor3f(1.0, 0.87, 0.68);
	   	glutSolidCube(1.0);

	   	//braço direito
	   	glPushMatrix();
		   	glTranslatef (1.25, -1.4, 0.0);
		   	glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
		   	glTranslatef (1.0, 0.0, 0.0);
		   	glColor3f (0.5, 0, 0);

		   	//antebraço direito
			glPushMatrix();
			   glScalef (2.75, 0.4, 1.0);
			   glutSolidCube (1.0);
		   	glPopMatrix();

			glTranslatef (1.0, 0.0, 0.0);
			glRotatef ((GLfloat) anguloCutuvelo, 0.0, 1.0, 0.0);
			glTranslatef (1.0, 0.0, 0.0);

			//braço direito
			glPushMatrix();
			   glScalef (2.0, 0.4, 1.0);
			   glutSolidCube (1.0);
		   	glPopMatrix();

		glPopMatrix();

		//braço esquerdo
		glPushMatrix();
			glRotatef(180, 0, 1, 0);

			glTranslatef (1.25, -1.4, 0.0);
		   	glRotatef (anguloOmbro, 0.0, 0.0, 1.0);
		   	glTranslatef (1.0, 0.0, 0.0);
		   	glColor3f (0.5, 0, 0);

		   	//antebraço esquerdo
			glPushMatrix();
			   glScalef (2.75, 0.4, 1.0);
			   glutSolidCube (1.0);
		   	glPopMatrix();

			glTranslatef (2.0, 0.0, 0.0);

			//braço esquerdo
			glPushMatrix();
			   glScalef (2.0, 0.4, 1.0);
			   glutSolidCube (1.0);
		   	glPopMatrix();
		glPopMatrix();

		//perna direita
		glColor3f (0, 0, 0);
		glPushMatrix();
		   	glTranslatef (-0.5, -6.75, depthPD);
		   	glRotatef((GLfloat) anguloPernaDireita, 1, 0, 0);

			glPushMatrix();
			   glScalef (0.9, 4.0, 0.9);
			   glutSolidCube (1.0);
		   	glPopMatrix();
		glPopMatrix();

		//perna esquerda
		glPushMatrix();
		   	glTranslatef (0.5, -6.75, depthPE);
		   	glRotatef((GLfloat) anguloPernaEsquerda, 1, 0, 0);
		   	
			glPushMatrix();
			   glScalef (0.9, 4.0, 0.9);
			   glutSolidCube (1.0);
		   	glPopMatrix();
		glPopMatrix();

		//tronco
		glPushMatrix();
		 	glTranslatef (0.0, -3.0, 0.0);
		   	glScalef (2.5, 4.0, 1.0);
		   	glColor3f (0.5, 0, 0);
		   	glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	glutPostRedisplay();
}