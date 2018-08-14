#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;

void llenar_Matriz(int tablero[][9], char *datos)
{
    int hola, numeros[3],cont=-1;;
    string cadena=datos;
    char s;

     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
         {
             tablero[i][j]=0;
          }
      }
    
     for(int i=0;i<cadena.length();i++)
     {
         s=cadena[i];
         hola=s;
         if(hola>47 && hola<58)
         {
             numeros[++cont]=hola-48;
         }
         if(cont==2)
         {
             tablero[numeros[0]][numeros[1]]=numeros[2];
             cont=-1;
         }
     
     }
}

int comprobar_Datos(char *datos)
{
    int dato=1,hola,chao=0,numeros[3],cont=-1;
    char s;
    string cadena=datos;
    for(int i=0;i<cadena.length();i++)
     {
         s=cadena[i];
         hola=s;
         if(hola>47 && hola<58 || hola==91 || hola==93 || hola==59)
         {
            if((chao>47 && chao<58) && (hola>47 && hola<58))
            {
                i=cadena.length();
                dato=0;
            }
            chao=hola;
         }
         else
         {
            i=cadena.length();
            dato=0;
         }
     
     }

     if(dato==1)
     {
        for(int i=0;i<cadena.length();i++)
        {
             s=cadena[i];
             hola=s;
             if(hola>47 && hola<58)
             {
                 numeros[++cont]=hola-48;
             }
             if(cont==2)
             {
                 cont=-1;
                 if(numeros[0]>-1 && numeros[0]<9 && numeros[1]>-1 && numeros[1]<9 && numeros[2]>0 && numeros[2]<10)
                 {

                 }
                 else
                 {
                    i=cadena.length();
                    dato=0;
                 }
             }
     
        }
     }
     return dato;
}

void mostrar_Matriz(int tablero[][9])
{
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
        {
            cout<<"--------------------"<<endl;
        }
        for(int j=0;j<9;j++)
        {
            if(j%3==0)
            {
                cout<<"|";
            }
            cout<<tablero[i][j]<<" ";

        }
        cout<<endl;
    }
}


int main(int argc, char* argv[])
{

    int  tablero[9][9];
    if(argc<2)
    {
        cout<<"Ingresa los datos"<<endl;
    }
    else
    {
        if(comprobar_Datos(argv[1])==1)
        {
            llenar_Matriz(tablero,argv[1]);
            mostrar_Matriz(tablero);
        }
        else
        {
            cout<<"Datos ingresados erroneos"<<endl;
        }
    }
    return 0;
}