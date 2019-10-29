#include "Bibliotecas/include.h"

void carregaImagens ()
{
    // Carrega a textura
    matoTexture = SOIL_load_OGL_texture
    (
        "Imagens/mato2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    boxRight = SOIL_load_OGL_texture
    (
        "Imagens/Skybox/right.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    boxLeft = SOIL_load_OGL_texture
    (
        "Imagens/Skybox/left.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    boxFront = SOIL_load_OGL_texture
    (
        "Imagens/Skybox/front.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    boxBack = SOIL_load_OGL_texture
    (
        "Imagens/Skybox/back.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    boxUp = SOIL_load_OGL_texture
    (
        "Imagens/Skybox/up.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    boxDown = SOIL_load_OGL_texture
    (
        "Imagens/Skybox/down.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
}

void carregaMusicas ()
{
    atexit(Mix_CloseAudio);
    theme = Mix_LoadMUS("Sons/Ambient_Song.mp3");
}

void inicializa()
{
  	int i, j, k, w = 0;

  	glClearColor (0, 0, 0, 1);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDifAndSpec1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightDifAndSpec1);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.01f);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    carregaImagens();
    carregaMusicas();

    // Não mostrar faces do lado de dentro
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   	glEnable(GL_DEPTH_TEST);
        desenhaPersonagem();
        //desenhabrinquedos();
        desenhaSkybox();    
	glDisable(GL_DEPTH_TEST);

    glutSwapBuffers();
}

void redimensiona(int w, int h)
{
   double ar = w/h;
    
    if (ar > 16/9)
    {
        new_w = (h/9) * 16;
        new_h = (h/9) * 9;
    }

    else
    {
        new_w = (w/16) * 16;
        new_h = (w/16) * 9;
    }

    glViewport((w-new_w)/2,(h-new_h)/2,new_w,new_h);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) new_w/(GLfloat) new_h, 1.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
    //inicializa o sdl_mixer
    SDL_Init (SDL_INIT_AUDIO);
    atexit (SDL_Quit);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);  

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1280, 720);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Harry Pottah");
   inicializa();

   glutDisplayFunc(desenha);
   glutReshapeFunc(redimensiona);
   glutKeyboardFunc(teclado);

   glutMainLoop();
   return 0;
}