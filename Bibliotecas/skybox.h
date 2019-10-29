void desenhaSkybox ()
{
	glColor3f(1,1,1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,boxUp);

	glPushMatrix();
		//glTranslatef(0, 49.15, 0);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 0); glVertex3f(50, 50, 0);
			glTexCoord2f(1, 0); glVertex3f(0, 50, 0);
			glTexCoord2f(1, 1); glVertex3f(0, 50, -50);
			glTexCoord2f(0, 1); glVertex3f(50, 50, -50);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,boxDown);
	glPushMatrix();
		//glTranslatef(0, -0.85, 0);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(50, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(50, 0, -50);
			glTexCoord2f(0, 1); glVertex3f(0, 0, -50);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,boxRight);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(0, 0, -50);
		glTexCoord2f(1, 1); glVertex3f(0, 50, -50);
		glTexCoord2f(1, 0); glVertex3f(0, 50, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,boxLeft);
	glPushMatrix();
		//glTranslatef(50, 0, 0);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 0); glVertex3f(50, 0, -50);
			glTexCoord2f(0, 1); glVertex3f(50, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(50, 50, 0);
			glTexCoord2f(1, 0); glVertex3f(50, 50, -50);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,boxFront);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(50, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
		glTexCoord2f(1, 1); glVertex3f(0, 50, 0);
		glTexCoord2f(1, 0); glVertex3f(50, 50, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,boxBack);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -50);
		glTexCoord2f(1, 0); glVertex3f(50, 0, -50);
		glTexCoord2f(1, 1); glVertex3f(50, 50, -50);
		glTexCoord2f(0, 1); glVertex3f(0, 50, -50);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}