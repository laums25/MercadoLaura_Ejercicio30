#include <iostream>
#include <cmath>

//Modificado de: https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/
//Guiado de: https://github.com/vostertag/solving-the-heat-equation/blob/master/computationalMethods/FTCS.cpp
//Guiado de: https://warwick.ac.uk/fac/cross_fac/complexity/study/msc_and_phd/co906/co906online/lecturenotes_2009/chap3.pdf

FILE *output;
int main (){
    int nx=30;
    int vax=50;
	int dax=100;
	double D=1.0;
	double deltax2=1.0/vax;
	double deltax3=1.0/dax;
	double deltat2=deltax2*deltax2/2*D;
	double deltat3=deltax3*deltax3/2*D;
    int nt=100;
	double m=0.5;
    double s=0.08;
    double deltax=1.0/nx;
    double deltat=deltax*deltax/2*D;
    double C[nx][nt];
	double N[vax][nt];
	double T[dax][nt];
    double x=0.0;
    int i=0;
	int j=0;
    
    output=fopen("Ejercicio29.dat", "w");

    for(i=0; i < nx; i++){                           
        x=i*deltax;
        C[i][0]=exp(-((x-m)*(x-m))/(2.0*(s*s)))/pow((2.0*M_PI*(s*s)),0.5);
    }
    C[0][0]=0.0;
    C[nx-1][0]=0.0;
                                           
    for(j = 0; j < nt - 1; j++){
        for(i=1; i<nx-1; i++){
            x=i*deltax;
            C[i][j+1] = C[i][j] + (D*deltat/(deltax*deltax))*(C[i+1][j-1] - 2*C[i][j-1] + C[i-1][j-1]);
        }                                             
        C[0][j+1]=0.0;                                      
        C[nx-1][j+1]=0.0;                          

    }

    for (i = 0; i < nx; ++i)
    {
        x = i * deltax;
        fprintf(output, "%e\t", x);
        for (j = 0; j < nt; ++j)
        {
            fprintf(output, "%e\t", C[i][j]);
            
        }
        fprintf(output, "\n");
    }                                             

    fflush(output);
    fclose(output);
    
    output=fopen("Ejer29.dat", "w");
    
    for(i=0; i < vax; i++){                           
        x=i*deltax2;
        N[i][0]=exp(-((x-m)*(x-m))/(2.0*(s*s)))/pow((2.0*M_PI*(s*s)),0.5);
    }
    N[0][0]=0.0;
    N[vax-1][0]=0.0;
                                           
    for(j = 0; j < nt - 1; j++){
        for(i=1; i<vax-1; i++){
            x=i*deltax2;
            N[i][j+1] = N[i][j] + (D*deltat2/(deltax2*deltax2))*(N[i+1][j-1] - 2*N[i][j-1] + N[i-1][j-1]);
        }                                             
        N[0][j+1]=0.0;                                      
        N[vax-1][j+1]=0.0;                          

    }

    for (i = 0; i < vax; ++i)
    {
        x = i * deltax2;
        fprintf(output, "%e\t", x);
        for (j = 0; j < nt; ++j)
        {
            fprintf(output, "%e\t", N[i][j]);
            
        }
        fprintf(output, "\n");
    }                                             

    fflush(output);
    fclose(output);
	
	output=fopen("Ej29.dat", "w");
    
    for(i=0; i < dax; i++){                           
        x=i*deltax3;
        T[i][0]=exp(-((x-m)*(x-m))/(2.0*(s*s)))/pow((2.0*M_PI*(s*s)),0.5);
    }
    T[0][0]=0.0;
    T[dax-1][0]=0.0;
                                           
    for(j = 0; j < nt - 1; j++){
        for(i=1; i<dax-1; i++){
            x=i*deltax3;
            T[i][j+1] = T[i][j] + (D*deltat3/(deltax3*deltax3))*(T[i+1][j-1] - 2*T[i][j-1] + T[i-1][j-1]);
        }                                             
        T[0][j+1]=0.0;                                      
        T[dax-1][j+1]=0.0;                          

    }

    for (i = 0; i < dax; ++i)
    {
        x = i * deltax3;
        fprintf(output, "%e\t", x);
        for (j = 0; j < nt; ++j)
        {
            fprintf(output, "%e\t", T[i][j]);
            
        }
        fprintf(output, "\n");
    }                                             

    fflush(output);
    fclose(output);



    return 0;                                     
}
