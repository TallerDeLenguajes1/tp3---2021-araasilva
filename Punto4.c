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

void cargarCliente(Cliente *, int id);
void cargarProducto(Producto *, int);
float costoTotaldeUnProducto(Producto *);
Cliente cargarLosClientes(Cliente *, int);

int main(){
    int cant_clientes;
    Cliente *clientes=(Cliente *)malloc(sizeof(Cliente)*5);
    printf("Ingrese la cantidad de Clientes: ");
    scanf("%d", &cant_clientes);


    getchar();
    return 0;
}
void cargarProducto(Producto *producto, int id){
    producto->ProductoID= id;

    srand(time(0));
    producto->Cantidad= rand()%(10-1+1)+1;
    int ran= rand()%5+1;

    for(int i=0; i<producto->Cantidad; i++){
        strcpy(producto->TipoProducto, TiposProductos[ran]);
        producto->TipoProducto+i;
    }
    producto->PrecioUnitario=crand() % (100-10+1)+10;

}
void cargarCliente(Cliente *cliente, int id){
    srand(time(0));
    cliente->ClienteID= id;

    printf("Ingresar nombre del Cliente: ");
    gets(cliente->NombreCliente);
    
    cliente->CantidadProductosAPedir = rand()%(5)+1;

    for(int i=0; i<cliente->CantidadProductosAPedir; i++){
        cargarProducto(cliente->Productos, i+1);
    }
}
float costoTotaldeUnProducto(Producto *producto){
    float costo_total= producto->PrecioUnitario * producto->Cantidad;
    return costo_total;
}
Cliente cargarLosClientes(Cliente *, int cant){
    for(int i=0; i<cant; i++){
        
    }
}