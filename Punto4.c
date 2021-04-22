#include <stdio.h>
#include <stdlib.h>

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

Cliente *cargarCliente(Cliente *);

int main(){

    int cant_clientes;
    printf("ingrese la cantidad de clientes: ");
    scanf("%d", &cant_clientes);

    Cliente *clientes= (Cliente *)malloc(sizeof(Cliente)*cant_clientes);
    Producto *productos= (Producto *)malloc(sizeof(Producto)* 10);

    for (int i = 0; i < cant_clientes; i++)
    {
        printf("----------Cargar cliente Num %d -----------\n",i+1);
        clientes+i = cargarCliente(clientes);
    }
    
    getchar();
    return 0;
}
Cliente *cargarCliente(Cliente *cliente){
    printf("Ingresar nombre del Cliente: ");
    gets(clientes->CliienteID);
    
    return cliente;
}