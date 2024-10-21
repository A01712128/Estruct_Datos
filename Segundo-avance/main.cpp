#include <iostream>
#include <vector>
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include "FuncionesOrdenamiento.h"
using namespace std;

int main() {
    vector<Tarea*> listaTareas;

    // Datos precargados como ejemplo
    listaTareas.push_back(new TareaSimple("Comprar despensa", 3));
    listaTareas.push_back(new TareaProgramada("Presentacion del proyecto", 5, "25-10-2024"));
    listaTareas.push_back(new TareaSimple("Sacar a pasear al perro", 2));
    listaTareas.push_back(new TareaProgramada("Visita al dentista", 4, "30-10-2024"));

    int opcion;

    while (true) {
        cout << "\nSeleccione el tipo de tarea que desea agregar:\n";
        cout << "1. Tarea simple\n";
        cout << "2. Tarea programada\n";
        cout << "3. Mostrar y ordenar tareas por importancia\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string descripcion;
            int importancia;
            cout << "Ingrese la descripción de la tarea: ";
            cin.ignore();
            getline(cin, descripcion);
            cout << "Ingrese el grado de importancia (1 a 5): ";
            cin >> importancia;
            listaTareas.push_back(new TareaSimple(descripcion, importancia));

        } else if (opcion == 2) {
            string descripcion, fechaVencimiento;
            int importancia;
            cout << "Ingrese la descripción de la tarea: ";
            cin.ignore();
            getline(cin, descripcion);
            cout << "Ingrese el grado de importancia (1 a 5): ";
            cin >> importancia;
            cout << "Ingrese la fecha de vencimiento (DD-MM-YYYY): ";
            cin.ignore();
            getline(cin, fechaVencimiento);
            listaTareas.push_back(new TareaProgramada(descripcion, importancia, fechaVencimiento));

        } else if (opcion == 3) {
            if (listaTareas.empty()) {
                cout << "No hay tareas para mostrar.\n";
            } else {
                mergeSort(listaTareas, 0, listaTareas.size() - 1);
                cout << "\nTareas ordenadas por grado de importancia:\n";

                for (Tarea* tarea : listaTareas) {
                    tarea->mostrarInformacion();
                    cout << endl;  // Espacio entre tareas
                }
            }

        } else if (opcion == 4) {
            break;
        } else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    // Liberacion de memoria
    for (Tarea* tarea : listaTareas) {
        delete tarea;
    }

    return 0;
}
