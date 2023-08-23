# include<iostream>
# include<cstdlib>

using namespace std;

void cargarInformacion(int vP[], int vS[], int* mayorVenta);
void puntoA(int vS[], int tam);
void puntoB(int vP[],int tam);
void pelicula(int vP[], int tam);

int main(){

    int opcion, mayorVenta;
    int vPeliculas[10]={0};
    int vSalas[20]={0};

    do{
        system("cls");
        cout<< "  MENU VENTAS CINE" << endl;
        cout<< "  --------------" << endl;
        cout<< "  1) CARGAR DATOS" << endl;
        cout<< "  2) PUNTO A" << endl;
        cout<< "  3) PUNTO B" << endl;
        cout<< "  4) PUNTO C" << endl;
        cout<< "  5) PUNTO D" << endl;
        cout<< "  --------------" << endl;
        cout<< "  0) SALIR" << endl;
        cin>> opcion;

        system("cls");
        switch(opcion){
            case 1:
                cargarInformacion(vPeliculas, vSalas, &mayorVenta);
                break;
            case 2:
                puntoA(vSalas, 20);
                break;
            case 3:
                puntoB(vPeliculas, 10);
                break;
            case 4:
                pelicula(vPeliculas, 10);
                break;
            case 5:
                cout<< "PUNTO D)"<< endl; ///PUNTO D
                cout<< "LA PELICULA CON MAYOR IMPORTE ENTRE TODAS LAS VENTAS DEL MES ES: ";
                cout<< mayorVenta;
                break;
            case 0: cout<< "Salir";
                break;
            default: cout<< "Opcion invalida"<< endl;
                break;
        }
        cout<< endl;
        system("pause");
        system("cls");
    }while(opcion!=0);

	cout<<endl;
	system("pause");
	return 0;
}

void cargarInformacion(int vP[], int vS[], int* mayorVenta){

    int venta, dia, sala, pelicula, entradas, mayor=0;
    float importe;

    cout<< "Ingrese el numero de venta: ";
    cin>> venta;
    while(venta>0){

        cout<< "Ingrese el dia: ";
        cin>> dia;
        cout<< "Ingrese el numero de sala (1 a 20): ";
        cin>> sala;
        cout<< "Ingrese el numero de pelicula (1 a 10): ";
        cin>> pelicula;
        cout<< "Ingrese la cantidad de localidades: ";
        cin>> entradas;
        cout<< "Ingrese el importe total: ";
        cin>> importe;

        vP[pelicula-1]+=entradas;
        vS[sala-1]+=entradas;

        if(importe>mayor){
            mayor=importe;
            *mayorVenta=pelicula;
        }
        cout<< "-----------------"<<endl;
        cout<< "Ingrese el numero de venta: ";
        cin>> venta;
    }
}
///PUNTO A
void puntoA(int vS[], int tam){
    int i, cantidad=0;

    for(i=0;i<tam;i++){
        if(vS[i]==1){
            cantidad+=1;
        }
    }
    cout<< "PUNTO A)"<< endl;
    cout<< "LA CANTIDAD DE VENTAS CON CANTIDAD DE LOCALIDADES IGUAL A 1: ";
    cout<< cantidad;

}

///PUNTO B
void puntoB(int vP[],int tam){
    int i, minimo=0, menor;
    for(i=0;i<tam;i++){
        if(vP[i]>0){
            if(minimo==0 || vP[i]<minimo) {
                minimo=vP[i];
                menor=i+1;
            }
        }
    }
    cout<< "PUNTO B)"<< endl;
    cout<< "LA PELICULA CON MENOS LOCALIDADES VENDIDAS ES LA: ";
    cout<< menor;
}
///PUNTO C
void pelicula(int vP[], int tam){
    int i, cantidad=0;
    for(i=0;i<tam;i++){
        if(vP[i]>0){
            cantidad+=1;
        }
    }
    cout<< "PUNTO C)"<< endl;
    cout<< "CANTIDAD PELICULAS QUE VENDIERON LOCALIDADES: ";
    cout<< cantidad;
}




