int anguloOmbro = -80, anguloCutuvelo = 0;
int anguloPernaDireita = 0, anguloPernaEsquerda = 0;
double depthPD = 0, depthPE = 0;
int camera = 0, cheater = 0;

float lightDifAndSpec1[] = { 0.88, 1, 1, 1.0 };
float globAmb[] = { 0.6, 0.6, 0.6, 1 };

float z = 0, angle = 0, lx, lz, angulo = 0;
int ang = 0, ang2 = 0;
float inix = 1, iniz = -1;
double altura = 0, vel = 1;
int pula = 0, inicio = 1;

int width, height, channels;
double new_w, new_h;

int matoTexture, music;
int boxRight, boxLeft, boxFront, boxBack, boxUp, boxDown;

Mix_Music *theme = NULL;

typedef struct coords {
  union {
      float v[4];
      struct {
          float x, y, z, w;
      };
      struct {
          float r, g, b, a;
      };
  };
} ponto, vetor, cor;

typedef struct material {
    cor ambiente;
    cor emissiva;
    cor difusa;
    cor especular;
    float brilhosidade[1];
} material;

material Parede,objetos,objetoSaida;