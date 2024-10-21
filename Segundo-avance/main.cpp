#include <iostream>
#include <vector>
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include "FuncionesOrdenamiento.h" 

using namespace std;

int main() {
    vector<Tarea*> listaTareas;

    // Cargar tareas pre-cargadas
    listaTareas.push_back(new TareaSimple("Comprar despensa", 3, 30));
    listaTareas.push_back(new TareaProgramada("Presentación del proyecto", 5, "25-10-2024", 120));
    listaTareas.push_back(new TareaSimple("Sacar a pasear al perro", 2, 15));
    listaTareas.push_back(new TareaProgramada("Visita al dentista", 4, "15-10-2024", 45));

    int opcion;

    while (true) {
        cout << "\nSeleccione el tipo de tarea que desea agregar:\n";
        cout << "1. Tarea simple\n";
        cout << "2. Tarea programada\n";
        cout << "3. Mostrar y ordenar tareas por importancia\n";
        cout << "4. Mostrar y ordenar tareas por tiempo estimado\n";
        cout << "5. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string descripcion;
            int importancia, tiempoEstimado;
            cout << "Ingrese la descripción de la tarea: ";
            cin.ignore();
            getline(cin, descripcion);
            cout << "Ingrese el grado de importancia (1 a 5): ";
            cin >> importancia;
            cout << "Ingrese el tiempo estimado (en minutos): ";
            cin >> tiempoEstimado;
            listaTareas.push_back(new TareaSimple(descripcion, importancia, tiempoEstimado));

        } else if (opcion == 2) {
            string descripcion, fechaVencimiento;
            int importancia, tiempoEstimado;
            cout << "Ingrese la descripción de la tarea: ";
            cin.ignore();
            getline(cin, descripcion);
            cout << "Ingrese el grado de importancia (1 a 5): ";
            cin >> importancia;
            cout << "Ingrese la fecha de vencimiento (DD-MM-YYYY): ";
            cin.ignore();
            getline(cin, fechaVencimiento);
            cout << "Ingrese el tiempo estimado (en minutos): ";
            cin >> tiempoEstimado;
            listaTareas.push_back(new TareaProgramada(descripcion, importancia, fechaVencimiento, tiempoEstimado));

        } else if (opcion == 3) {
            if (listaTareas.empty()) {
                cout << "No hay tareas para mostrar.\n";
            } else {
                seleccionSort(listaTareas, false); // Ordenar por importancia
                cout << "\nTareas ordenadas por grado de importancia:\n";
                for (Tarea* tarea : listaTareas) {
                    tarea->mostrarInformacion();
                    cout << endl;
                }
            }

        } else if (opcion == 4) {
            if (listaTareas.empty()) {
                cout << "No hay tareas para mostrar.\n";
            } else {
                seleccionSort(listaTareas, true); // Ordenar por tiempo estimado
                cout << "\nTareas ordenadas por tiempo estimado:\n";
                for (Tarea* tarea : listaTareas) {
                    tarea->mostrarInformacion();
                    cout << endl;
                }
            }

        } else if (opcion == 5) {
            break;
        } else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    // Liberación de memoria
    for (Tarea* tarea : listaTareas) {
        delete tarea;
    }

    return 0;
}
