#include <iostream>
#include <fstream>
#include <cmath>
#include <fstream>
using namespace std;

// Definición de mis constantes

const double pi = 2.0*asin(1.0); // el valor de pi como una constante global 
const double g = 9.8; //Aceleracion gravitacional
//const double k = 0.7; // el coeficiente 
const double h = 0.001; // variacion del tiempo entre cada instante
///// Se declaras las variables de la ecuacion que varian segun los puntos /////
const double tmax = 1.8; //el tiempo maximo con el que se trabajara
int N = (int) tmax/h; // el numero de iteraciones que se realizaran en el sisema

double fx0( double x1)
{
  return x1;
}


double fy0( double y1)
{
  return y1;
}

/* Funcion que describe el movimiento del proyectil 
Recibe la velocidad en x y la velocidad en y
*/
double fx1(double k,double vx, double vy)
{
	//Magnitud de la velocidad
	double mgv = sqrt(pow(vx,2)+pow(vy,2)); 
	//Ecuaciones de movimiento
	return -((k*vx*vx)/mgv);
}

/* Funcion que describe el movimiento del proyectil 
Recibe la velocidad en x y la velocidad en y
*/
double fy1(double k,double vx, double vy)
{
	//Magnitud de la velocidad
	double mgv = sqrt(pow(vx,2)+pow(vy,2));
	return -g-((k*vy*vy)/mgv);
}

/*
Función que calcula el movimiento con rk4 dado un angulo inicial
y una posicion x,y inicial
*/
double rk4(double k,double t,double & posx0, double  & posy0, double & vx0, double & vy0)
{
		
  double* mov = new double[2]; //vector donde se guardan las velocidades
	
  double k10x, k11x, k20x, k21x, k30x, k31x, k40x, k41x;
  double k10y, k11y, k20y, k21y, k30y, k31y, k40y, k41y;
	
  //Valor de K1 para la solucion
  k10x = h*fx0(vx0);
  k11x = h*fx1(k,vx0,vy0);
	
  k10y = h*fy0(vy0);
  k11y = h*fy1(k,vx0,vy0);	
	
  //Valor de K2 para la solucion
  k20x = h*fx0( vx0 + k10x/2);
  k21x = h*fx1( k,vx0 + k10x/2, vy0 + k11y/2);
	
  k20y = h*fy0( vy0 + k11y/2);
  k21y = h*fy1(k, vx0 + k10y/2, vy0 + k11x/2);
	
 //VaLor de k3 para la solucion	
  k30x = h*fx0( vx0 + k20x/2);
  k31x = h*fx1(k, vx0 + k20x/2, vy0 + k21y/2);
	
  k30y = h*fy0( vy0 + k21y/2);
  k31y = h*fy1(k, vx0 + k20y/2, vy0 + k21x/2);
	
//Valor de k4 para la solucion	
  k40x = h*fx0( vx0 + k30x);
  k41x = h*fx1(k, vx0 + k30y, vy0 + k31x);
	
  k40y = h*fy0( vy0 + k31y);
  k41y = h*fy1(k, vx0 + k30x, vy0 + k31y);
	
//Valores de posicion y velocidades	
  posx0 = posx0 + (1.0/6.0)*(k10x + 2*k20x + 2*k30x + k40x);
  vx0 = vx0 + (1.0/6.0)*(k11x + 2*k21x + 2*k31x + k41x);
	
  posy0 = posy0 + (1.0/6.0)*(k10y + 2*k20y + 2*k30y + k40y);
  vy0 = vy0 + (1.0/6.0)*(k11y + 2*k21y + 2*k31y + k41y);
		
		
}

int main (int argc, char **argv) 
{
	//Condiciones iniciales
	double time;
	double posx0 = 0.0;
	double posy0 = 0.0;
	double vx0 = 10;
	double vy0 = 10;
	double k1 = 0.0;
	
	if(atoi(argv[1])==1)
	{
		k1 = 0.7;
	}
	else
	{
		k1 = 0.0;
	}
	
  for(time = 0; time <= tmax; time += h) 
  {
    cout <<  posx0 << "\t" << vx0 << "\t"<< posy0<<"\t"<< vy0<< endl;	  
    rk4(k1,time, posx0, posy0,vx0,vy0);
  }
   return 0;
}

