#include <iostream>

using namespace std;


struct Nodo{
    int dato;
    Nodo* sig;
    Nodo* ant;
}*first , *last;

void insertar(){
    Nodo*nuevo = new Nodo();
    cin>>nuevo->dato;
    if(first==NULL){
        first=nuevo;
        first->sig=NULL;
        first->ant=NULL;
        last=first;
    }
    else{
        last->sig=nuevo;
        nuevo->sig=NULL;
        nuevo->ant=last;
        last=nuevo;
    }
}

void imprimir(){
    Nodo*actual=new Nodo();
    actual=first;
    if(first!=NULL){
        while(actual != NULL){
            cout<<actual->dato <<"->";
            actual=actual->sig;
        }
    }
}

void borrarPrimero() {
    if (first == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    Nodo* aux = first;
    first = first->sig;
    if (first != nullptr) {
        first->ant = nullptr;
    } else {
        last = nullptr;
    }

    delete aux;
}
void borrarUltimo() {
    if (first == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    Nodo* aux = last;
    if (first == last) {
        first = nullptr;
    } else {
        last = last->ant;
        last->sig = nullptr;
    }

    delete aux;
}


int main()
{
    int opcion;

    cout << "1. Pilas" << endl;
    cout << "2. Colas" << endl;
    cout << "Elige una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            while (true) {
                cout <<endl<< "1. Insertar" << endl;
                cout << "2. Dar salida" << endl;
                cout << "0. Salir" << endl;
                cout << "Elige una opción: ";
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        cout<<"inserta el dato: ";
                        insertar();
                        imprimir();
                        break;
                    case 2:
                        borrarUltimo();
                        imprimir();
                        break;
                    case 0:
                        return 0;
                    default:
                        cout << "Opción no válida" << endl;
                        break;
                }
            }
        case 2:

            while (true) {
                
                cout <<endl<< "1. Insertar" << endl;
                cout << "2. Dar salida" << endl;
                cout << "0. Salir" << endl;
                cout << "Elige una opción: ";
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        cout<<"inserta el dato: ";
                        insertar();
                        imprimir();
                        break;
                    case 2:
                        borrarPrimero();
                        imprimir();
                        break;
                    case 0:
                        return 0;
                    default:
                        cout << "Opción no válida" << endl;
                        break;
                }
            }
        default:
            cout << "Opción no válida" << endl;
            break;
    }

    return 0;
}
