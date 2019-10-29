void teclado(unsigned char key, int x, int y)
{
   	int a, b;

    switch (key) {
      case 27:
          exit(0);
          break;

      case 32:
        pula = 1;
        vel = 1;
        altura = 0;
        glutPostRedisplay();
        break;

      case 'C':
      case 'c':
        if (camera == 0)
        {
            camera = 1;
            angle = 3.1415/2.5 + (angulo*3.1415*-1)/180;
        }
        else
        {
            camera = 0;
            angle = (angulo*3.1415*-1)/180;
        }

        glutPostRedisplay();
        break;

      case 'R':
      case 'r':
        if (cheater == 0)
          cheater = 1;
        else
          cheater = 0;
        glutPostRedisplay();
        break;

      case 'A':
      case 'a':
        angle -= 0.1;
        angulo += (0.1*180)/3.1415;
        glutPostRedisplay();
        break;

      case 'D':
      case 'd':
        angle += 0.1;
        angulo -= (0.1*180)/3.1415;
        glutPostRedisplay();
        break;

      case 'W':
      case 'w':
            a = inix + 0.5 + sin((angulo*3.1415)/180)*z;
            b = (iniz - 1 + cos((angulo*3.1415)/180)*z) * -1;

              anguloPernaDireita = (anguloPernaDireita + 20) % 40;
              anguloPernaEsquerda = (anguloPernaEsquerda - 20) % 40;

              if (ang != angulo)
              {
                inix += sin((ang*3.1415)/180)*z;
                iniz += cos((ang*3.1415)/180)*z;
                z = 0;
              }

              ang = angulo;
              z -= 0.5;

              if (anguloPernaDireita == 20)
              {
                  depthPD = -0.6;
                  depthPE = 0.6;
              }

              else
              {
                  depthPD = 0;
                  depthPE = 0;
              }
           
        glutPostRedisplay();
        break;

      case 'S':
      case 's':
            a = inix + 0.5 + sin((angulo*3.1415)/180)*z;
            b = (iniz + 1 + cos((angulo*3.1415)/180)*z) * -1;

              anguloPernaDireita = (anguloPernaDireita - 20) % 40;
              anguloPernaEsquerda = (anguloPernaEsquerda + 20) % 40;

              if (ang != angulo)
              {
                inix += sin((ang*3.1415)/180)*z;
                iniz += cos((ang*3.1415)/180)*z;
                z = 0;
              }

              ang = angulo;
              z += 0.5;

              if (anguloPernaEsquerda == 20)
              {
                  depthPD = 0.6;
                  depthPE = -0.6;
              }

              else
              {
                  depthPD = 0;
                  depthPE = 0;
              }
            
        glutPostRedisplay();
        break;

      case 'N':
      case 'n':
         anguloCutuvelo = 0;
         glutPostRedisplay();
         break;

      default:
         break;
    }
}