#include <iostream>
#include <iomanip>

using namespace std;

struct Producto
{
    char nombre[20];
    float precio;
    int cantidad;
};

void menu();
int altaProducto(Producto p[], int cont);
void ventaProducto(Producto p[], int cont);
void imprimeInventario(const Producto p[], const int cont);

int main()
{
    Producto listaProductos[10];
    int contProducto = 0;
    char opcion;

    do {
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            contProducto = altaProducto(listaProductos, contProducto);
            break;

        case '2':
            ventaProducto(listaProductos, contProducto);
            break;

        case '3':
            imprimeInventario(listaProductos, contProducto);
            break;

        case '4':
            cout << "\n\nFIN DEL PROGRAMA" << endl;
            break;

        default:
            cout << "\n\nOPCION NO VALIDA" << endl;
            break;
        }

    } while (opcion != '4');

    return 0;
}

void menu()
{
    cout << "\n         MUEBLES"
        << "\n==========================="
        << "\n1.- Alta Producto "
        << "\n2.- Venta Producto"
        << "\n3.- Impresion de Inventario"
        << "\n4.- Salir"
        << "\n==========================="
        << "\nOPCION (1-4): ";
}

int altaProducto(Producto p[], int cont)
{
    if (cont < 10)
    {
        cin.ignore(80, '\n');
        cout << "\nNombre: "; cin.getline(p[cont].nombre, 50);
        cout << "Precio: "; cin >> p[cont].precio;
        cout << "Cantidad: "; cin >> p[cont].cantidad;

        cont++;
    }
    else
        cout << "\n\nESPACIO INSUFICIENTE" << endl;

    return cont;
}

void ventaProducto(Producto p[], int cont)
{
    int numero, cantidad;

    cout << "\nNumero o Codigo del Producto: ";
    cin >> numero;

    if (numero >= cont)
        cout << "\n\nEL PRIDUCTO NO EXISTE" << endl;
    else
    {
        cout << "Cantidad: "; cin >> cantidad;

        if (cantidad > p[numero].cantidad)
            cout << "\n\nEXISTENCIA INSUFICIENTE" << endl;
        else
        {
            p[numero].cantidad -= cantidad;

            cout << endl << p[numero].nombre << " " << cantidad << " vendido" << endl;
            cout << "Existencias: " << p[numero].cantidad << endl;
        }

    }
}

void imprimeInventario(const Producto p[], int cont)
{
    cout << "\n             INVENTARIO"
        << "\n========================================="
        << "\n" << setw(20) << "NOMBRE" << setw(10) << "PRECIO" << setw(10) << "CANTIDAD"
        << "\n=========================================" << endl;


    for (int i = 0; i < cont; i++)
    {
        cout << resetiosflags(ios::right);
        cout << setiosflags(ios::left) << setw(20) << p[i].nombre;
        cout << setiosflags(ios::right) << setw(8) << p[i].precio << setw(8) << p[i].cantidad << endl;
    }
}