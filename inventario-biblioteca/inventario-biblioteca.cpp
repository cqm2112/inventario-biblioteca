#include <iostream>
#include <iomanip>

using namespace std;

struct Libro
{
  string nombre;
    float precio;
    int cantidad;
};

void menu();
int altaLibro(Libro p[], int cont);
void ventaLibro(Libro p[], int cont);
void imprimeInventario(const Libro p[], const int cont);
void modificarLibro(Libro p[], int cont);

int main()
{
    Libro listaLibros[10];
    int contLibro = 0;
    char opcion;

    do {
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            contLibro = altaLibro(listaLibros, contLibro);
            break;

        case '2':
            ventaLibro(listaLibros, contLibro);
            break;

        case '3':
            imprimeInventario(listaLibros, contLibro);
            break;

        case '4':
            cout << "\n\nFIN DEL PROGRAMA" << endl;
            break;
        case '5':
            modificarLibro(listaLibros, contLibro);
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
    cout << "\n         Biblioteca"
        << "\n==========================="
        << "\n1.- Agregar Libro"
        << "\n2.- Venta libro"
        << "\n3.- Consultar libros"
        << "\n4.- Salir"
        << "\n5.- modificar libros"
        << "\n==========================="
        << "\nO Seleccione una opcion(1-4): ";
}

int altaLibro(Libro p[], int cont)
{
    if (cont < 10)
    {
        cin.ignore(80, '\n');
        cout << "\nNombre: ";  cin >> p[cont].nombre;
        cout << "Precio: "; cin >> p[cont].precio;
        cout << "Cantidad: "; cin >> p[cont].cantidad;

        cont++;
    }
    else
        cout << "\n\nESPACIO INSUFICIENTE" << endl;

    return cont;
}

void ventaLibro(Libro p[], int cont)
{
    int numero, cantidad;

    cout << "\nNumero o Codigo del Libro: ";
    cin >> numero;

    if (numero >= cont)
        cout << "\n\nEL LIBRO NO SE ENCUENTRA" << endl;
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
void modificarLibro(Libro p[], int cont)
{
    int numero, cantidad, precio;
    string nombre;

    cout << "\nNumero o Codigo del Libro: ";
    cin >> numero;
    cout << "\nNombre a modificar: ";
    cin >> nombre;
    cout << "\nPrecio a modificar: ";
    cin >> precio;

    if (numero >= cont)
        cout << "\n\nEL LIBRO NO SE ENCUENTRA" << endl;
    else
    {
        cout << "Cantidad: "; cin >> cantidad;

        p[numero].nombre = nombre;
        p[numero].precio = precio;
        p[numero].cantidad =  cantidad;


          
            cout << "se ha modificado el registro numero: " << numero << endl;
        

    }
}

void imprimeInventario(const Libro p[], int cont)
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