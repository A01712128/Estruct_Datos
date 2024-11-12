#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "TareaSimple.h"
#include "TareaProgramada.h"

using namespace std;

// Clase para comparar tareas por prioridad
class CompararTareas {
public:
    bool operator()(Tarea* t1, Tarea* t2) {
        return t1->obtenerImportancia() < t2->obtenerImportancia(); // Mayor prioridad primero
    }
};

// Funcion para cargar tareas desde el archivo CSV
void cargarTareasDesdeArchivo(priority_queue<Tarea*, vector<Tarea*>, CompararTareas>& colaTareas,
    vector<Tarea*>& tareasSimples, vector<Tarea*>& tareasProgramadas, const string& archivo) {

    ifstream file(archivo);
    string line;

    // Leer cada línea del archivo CSV
    while (getline(file, line)) {
        stringstream ss(line);
        string tipo, descripcion, fechaVencimiento;
        int importancia;

        getline(ss, tipo, ',');
        getline(ss, descripcion, ',');
        ss >> importancia;
        ss.ignore(); 
        if (tipo == "simple") {
            TareaSimple* tareaSimple = new TareaSimple(descripcion, importancia);
            tareasSimples.push_back(tareaSimple);
            colaTareas.push(tareaSimple); // Agregar tambien a la cola de prioridad
        } else if (tipo == "programada") {
            getline(ss, fechaVencimiento, ',');
            TareaProgramada* tareaProgramada = new TareaProgramada(descripcion, importancia, fechaVencimiento);
            tareasProgramadas.push_back(tareaProgramada);
            colaTareas.push(tareaProgramada); // Agregar tambien a la cola de prioridad
        }
    }

    file.close();
}

int main() {
    priority_queue<Tarea*, vector<Tarea*>, CompararTareas> colaTareas; // Cola de prioridad para tareas
    vector<Tarea*> tareasSimples;  // Vector para tareas simples
    vector<Tarea*> tareasProgramadas;  // Vector para tareas programadas
    int opcion;

    // Cargar las tareas desde el archivo CSV al iniciar
    cargarTareasDesdeArchivo(colaTareas, tareasSimples, tareasProgramadas, "tareas.csv");

    while (true) {
        cout << "\nSeleccione la opcion que desea:\n";
        cout << "1. Agregar tarea simple\n";
        cout << "2. Agregar tarea programada\n";
        cout << "3. Mostrar tareas por orden de prioridad (todas)\n";
        cout << "4. Mostrar tareas simples por orden de prioridad\n";
        cout << "5. Mostrar tareas programadas por orden de prioridad\n";
        cout << "6. Mostrar tareas por tiempo estimado (ordenadas por fecha)\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string descripcion;
            int importancia;
            cout << "Ingrese la descripcion de la tarea: ";
            cin.ignore();
            getline(cin, descripcion);
            cout << "Ingrese el grado de importancia (1 a 5): ";
            cin >> importancia;
            TareaSimple* nuevaTareaSimple = new TareaSimple(descripcion, importancia);
            tareasSimples.push_back(nuevaTareaSimple);
            colaTareas.push(nuevaTareaSimple);  // Agregar tambien a la cola de prioridad

        } else if (opcion == 2) {
            string descripcion, fechaVencimiento;
            int importancia;
            cout << "Ingrese la descripcion de la tarea: ";
            cin.ignore();
            getline(cin, descripcion);
            cout << "Ingrese el grado de importancia (1 a 5): ";
            cin >> importancia;
            cout << "Ingrese la fecha de vencimiento (DD-MM-YYYY): ";
            cin.ignore();
            getline(cin, fechaVencimiento);
            TareaProgramada* nuevaTareaProgramada = new TareaProgramada(descripcion, importancia, fechaVencimiento);
            tareasProgramadas.push_back(nuevaTareaProgramada);
            colaTareas.push(nuevaTareaProgramada);  // Agregar tambien a la cola de prioridad

        } else if (opcion == 3) {
            cout << "\nTareas ordenadas por prioridad (de mayor a menor):\n";
            priority_queue<Tarea*, vector<Tarea*>, CompararTareas> colaTareasCopia = colaTareas;
            
            // Mostrar todas las tareas de la cola de prioridad
            while (!colaTareasCopia.empty()) {
                Tarea* tarea = colaTareasCopia.top(); // Acceder al elemento con la mayor prioridad
                tarea->mostrarInformacion();
                colaTareasCopia.pop(); // Eliminar la tarea después de mostrarla
                cout << endl; 
            }

            // Complejidad de esta opcion:
            // Mejor caso: O(1), si hay solo una tarea en la cola.
            // Promedio y peor caso: O(n log n), ya que cada `pop` de la cola toma O(log n) y tenemos que hacer n pops en total.

        } else if (opcion == 4) {
            cout << "\nTareas simples ordenadas por prioridad:\n";
            // Ordenar las tareas simples por prioridad usando la cola de prioridad
            priority_queue<Tarea*, vector<Tarea*>, CompararTareas> colaSimples;
            for (Tarea* tarea : tareasSimples) {
                colaSimples.push(tarea);
            }

            // Mostrar las tareas simples ordenadas
            while (!colaSimples.empty()) {
                Tarea* tarea = colaSimples.top();
                tarea->mostrarInformacion();
                colaSimples.pop();
                cout << endl;
            }

            // Complejidad de esta opcion:
            // Mejor caso: O(1), si hay solo una tarea simple.
            // Promedio y peor caso: O(n log n), ya que cada `push` y `pop` toma O(log n), y tenemos n tareas.

        } else if (opcion == 5) {
            cout << "\nTareas programadas ordenadas por prioridad:\n";
            // Ordenar las tareas programadas por prioridad usando la cola de prioridad
            priority_queue<Tarea*, vector<Tarea*>, CompararTareas> colaProgramadas;
            for (Tarea* tarea : tareasProgramadas) {
                colaProgramadas.push(tarea);
            }

            // Mostrar las tareas programadas ordenadas
            while (!colaProgramadas.empty()) {
                Tarea* tarea = colaProgramadas.top();
                tarea->mostrarInformacion();
                colaProgramadas.pop();
                cout << endl;
            }

            // Complejidad de esta opcion:
            // Mejor caso: O(1), si hay solo una tarea programada.
            // Promedio y peor caso: O(n log n), similar a la parte anterior de tareas simples.

        } else if (opcion == 6) {
            cout << "\nTareas ordenadas por tiempo estimado (fecha de vencimiento):\n";
            // Ordenar las tareas programadas por fecha de vencimiento
            sort(tareasProgramadas.begin(), tareasProgramadas.end(), 
                [](TareaProgramada* t1, TareaProgramada* t2) {
                    return t1->obtenerFechaVencimiento() < t2->obtenerFechaVencimiento();
                });

            // Mostrar las tareas programadas ordenadas por fecha de vencimiento
            for (Tarea* tarea : tareasProgramadas) {
                tarea->mostrarInformacion();
                cout << endl;
            }

            // Complejidad de esta opcion:
            // Mejor caso: O(n log n) si las tareas ya están en orden, ya que `sort` tiene una complejidad de O(n log n).
            // Promedio y peor caso: O(n log n) debido al algoritmo de ordenación `sort`.

        } else if (opcion == 7) {
            break;
        } else {
            cout << "Opción no valida. Intente de nuevo.\n";
        }
    }

    return 0;
}
