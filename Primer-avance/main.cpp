#include <iostream>
#include <vector>
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include "FuncionesOrdenamiento.h"
using namespace std;

int main() {
    vector<Tarea*> listaTareas;
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
            mergeSort(listaTareas, 0, listaTareas.size() - 1);
            cout << "\nTareas ordenadas por grado de importancia:\n";
            cout << endl;  // Espacio entre tareas

            for (Tarea* tarea : listaTareas) {
                tarea->mostrarInformacion();
                cout << endl;  // Espacio entre tareas
            }

        } else if (opcion == 4) {
            break;
        } else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    for (Tarea* tarea : listaTareas) {
        delete tarea;
    }

    return 0;
}
