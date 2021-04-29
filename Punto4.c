#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;
typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;
char *TiposProductos[5]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

Producto *cargarProducto(int);
float mostrarProducto(Producto *);
void cargarLosClientes(Cliente *, int);
void mostrarCliente(Cliente *);
void mostrarTodosLosClientes(Cliente *, int);

int main(){
    srand(time(NULL));
    int cant_clientes;
    do{
        printf("Ingrese la cantidad de Clientes(entre 1y 5): ");
        scanf("%d", &cant_clientes);
    }while(cant_clientes>5);
    
    Cliente *clientes=(Cliente *)malloc(sizeof(Cliente)*cant_clientes);

    cargarLosClientes(clientes, cant_clientes);

    /*mostrarTodosLosClientes(clientes, cant_clientes);*/

    getchar();
    return 0;
}

Producto *cargarProducto(int cant_prod){

    Producto *producto= (Producto *)malloc(sizeof(Producto) * cant_prod); //Choco: Asignacion de memoria para el producto * la cantidad de productos
    int ran;
    for (int i = 0; i < cant_prod; i++)
    {
        (producto + i)->ProductoID = i+1;
        (producto + i)->Cantidad = rand() % 11;
        (producto + i)->PrecioUnitario = (float)(rand() % 91) / 10;
        aleatorio = rand()% 5;//Choco: va del 0 al maximo menos 1
        (producto + i)->TipoProducto = (char *)malloc(sizeof(char)*(strlen(TiposProductos[ran])-1));//Choco: se asigna memoria al TipoProducto con el tamaño del arreglo
        strcpy((producto + i)->TipoProducto, TiposProductos[ran]);
    }
    return producto;
}
void cargarLosClientes(Cliente *cliente, int cant){

    for(int i=0; i<cant; i++){
        (cliente + i)->ClienteID= i+1;
        (cliente + i)->NombreCliente=(char*)malloc(sizeof(char)*10);
        printf("Ingresar nombre del Cliente num %d: ",(cliente+i)->ClienteID);
        fflush(stdin);
        gets((cliente+i)->NombreCliente);
        (cliente+i)->CantidadProductosAPedir = rand()%6;
        (cliente+i)->Productos= cargarProducto((cliente+i)->CantidadProductosAPedir);
    }
}

float mostrarProducto(Producto *producto){
    printf("ID del producto: %d\n",producto->ProductoID);
    printf("Tipo de producto: %s\n",producto->TipoProducto);
    printf("Cantidad: %d",producto->Cantidad);
    printf("Precio por unidad: %.2f",producto->PrecioUnitario);
    float costo_total= producto->PrecioUnitario * producto->Cantidad;
    return costo_total;
}

void mostrarTodosLosClientes(Cliente *clientes, int cant){
    float costo_total_a_pagar=0;
    for(int i=0; i<cant; i++){
        printf("-------------Datos del cliente num %d-----------\n",(clientes+i)->ClienteID);
        printf("Nombre: %s\n",(clientes+i)->NombreCliente);
        printf("Productos pedidos : %d\n", (clientes+i)->CantidadProductosAPedir);
        printf("**Datos productos**\n");
        for (int j = 0; j < (clientes+i)->CantidadProductosAPedir; j++){
            costo_total_a_pagar+= mostrarProducto((clientes+i)->Productos+j);
        }
        printf("Costo total a pagar: %2.f", costo_total_a_pagar);
    }
}