GLuint LoadBMP(const char *fileName)
{
	FILE *file;
	unsigned char header[54];
	unsigned int dataPos,size,width, height;
	file = fopen(fileName, "rb");
	fread(header, 1, 54, file);				//Windows BMP begin with 54 byte header
	dataPos		= *(int*)&(header[0x0A]);	//dec10, Actual BMP data
	size		= *(int*)&(header[0x22]);	//dec34, BMP Size
	width		= *(int*)&(header[0x12]);	//dec18, Image Width
	height		= *(int*)&(header[0x16]);	//dec22, Image Height
	if (!size)
		size = width * height * 3;
	if (!dataPos)
		dataPos = 54;
	unsigned char *data [size];
	fread(data, 1, size, file);
	fclose(file);
	GLuint texture;
	glGenTextures(1, &texture);				//Generate (allocate) 1 texture name
	glBindTexture(GL_TEXTURE_2D, texture);	//Bind the 2D texture



	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);	//MAG filter
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	//MIN filter

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data); //target, level, internalFormat, width, height,border, format, type, data 
	return texture;
}