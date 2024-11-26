#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include "FuncionesOrdenamiento.h"

// Vector para almacenar las tareas
std::vector<Tarea*> tareas;
// Cola para almacenar las tareas completadas
std::queue<Tarea*> tareasCompletadas;
// Variable para generar un ID unico para cada tarea
int siguienteId = 1;

// Funcion para leer tareas desde el archivo CSV
void leerTareasCSV() {
    std::ifstream file("tareas.csv");  // Abrir archivo CSV
    std::string line;
    while (std::getline(file, line)) {  // Leer linea por linea
        std::stringstream ss(line);  // Convertir la linea en un stringstream para separar los datos
        int id, prioridad, dia, mes, anio;
        std::string descripcion, tipo;
        char coma;

        // Leer los datos de la linea CSV
        ss >> id >> coma;
        std::getline(ss, descripcion, ',');
        ss >> prioridad >> coma;
        ss >> tipo;

        // Crear tarea simple o programada segun el tipo
        if (tipo == "simple") {
            tareas.push_back(new TareaSimple(id, descripcion, prioridad));
        } else {
            ss >> dia >> coma >> mes >> coma >> anio;
            tareas.push_back(new TareaProgramada(id, descripcion, prioridad, dia, mes, anio));
        }

        // Actualizar el siguiente ID para las tareas nuevas
        siguienteId = id + 1;
    }
}

// Funcion para guardar las tareas en el archivo CSV
void guardarTareasCSV() {
    std::ofstream file("tareas.csv");  // Abrir archivo CSV para escribir
    for (Tarea* tarea : tareas) {  // Iterar sobre todas las tareas
        file << tarea->getId() << "," << tarea->getDescripcion() << ","
             << tarea->getPrioridad() << ",";
        if (TareaProgramada* tp = dynamic_cast<TareaProgramada*>(tarea)) {
            // Si es tarea programada, escribir la fecha
            file << "programada," << tp->getDia() << "," << tp->getMes() << "," << tp->getAnio();
        } else {
            // Si es tarea simple, escribir "simple"
            file << "simple";
        }
        file << "\n";
    }
}

// Funcion para agregar una tarea simple
void agregarTareaSimple() {
    std::string descripcion;
    int prioridad;
    std::cout << "Descripción de la tarea: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);  // Leer descripcion de la tarea
    std::cout << "Prioridad: ";
    std::cin >> prioridad;  // Leer la prioridad de la tarea
    // Crear la tarea simple y agregarla al vector
    tareas.push_back(new TareaSimple(siguienteId++, descripcion, prioridad));
    guardarTareasCSV();  // Guardar las tareas actualizadas en el CSV
}

// Funcion para agregar una tarea programada
void agregarTareaProgramada() {
    std::string descripcion;
    int prioridad, dia, mes, anio;
    std::cout << "Descripción de la tarea: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);  // Leer descripcion de la tarea
    std::cout << "Prioridad: ";
    std::cin >> prioridad;  // Leer la prioridad de la tarea
    std::cout << "Fecha (DD MM AAAA): ";
    std::cin >> dia >> mes >> anio;  // Leer la fecha de la tarea
    // Crear la tarea programada y agregarla al vector
    tareas.push_back(new TareaProgramada(siguienteId++, descripcion, prioridad, dia, mes, anio));
    guardarTareasCSV();  // Guardar las tareas actualizadas en el CSV
}

// Funcion para mostrar las tareas ordenadas por prioridad
void mostrarTareasPorPrioridad() {
    mergeSortPorPrioridad(tareas, 0, tareas.size() - 1);  // Ordenar las tareas por prioridad
    // Mostrar las tareas ordenadas
    for (Tarea* tarea : tareas) {
        std::cout << "ID: " << tarea->getId() << ", Descripción: " << tarea->getDescripcion()
                  << ", Prioridad: " << tarea->getPrioridad() << std::endl;
    }
}

// Funcion para mostrar las tareas ordenadas por fecha
void mostrarTareasPorFecha() {
    mergeSortPorFecha(tareas, 0, tareas.size() - 1);  // Ordenar las tareas por fecha
    // Mostrar las tareas ordenadas
    for (Tarea* tarea : tareas) {
        std::cout << "ID: " << tarea->getId() << ", Descripción: " << tarea->getDescripcion()
                  << ", Fecha: " << tarea->getFechaOrden() << std::endl;
    }
}

// Funcion para marcar una tarea como completa y eliminarla de la lista
void marcarTareaComoCompleta() {
    int id;
    std::cout << "Ingrese el ID de la tarea a marcar como completa: ";
    std::cin >> id;
    // Buscar la tarea por ID
    for (auto it = tareas.begin(); it != tareas.end(); ++it) {
        if ((*it)->getId() == id) {
            tareasCompletadas.push(*it);  // Mover la tarea a la cola de tareas completadas
            tareas.erase(it);  // Eliminar la tarea de la lista principal
            guardarTareasCSV();  // Guardar las tareas actualizadas en el CSV
            std::cout << "Tarea marcada como completa y eliminada." << std::endl;
            return;
        }
    }
    std::cout << "Tarea no encontrada." << std::endl;  // Si no se encuentra la tarea
}

int main() {
    leerTareasCSV();  // Cargar tareas desde el archivo CSV al inicio

    int opcion;
    do {
        // Mostrar el menú de opciones
        std::cout << "1. Agregar tarea simple\n"
                  << "2. Agregar tarea programada\n"
                  << "3. Mostrar tareas por prioridad\n"
                  << "4. Mostrar tareas por fecha\n"
                  << "5. Marcar tarea como completa\n"
                  << "6. Salir\n";
        std::cout << "Elija una opción: ";
        std::cin >> opcion;

        // Ejecutar la opción seleccionada
        switch(opcion) {
            case 1:
                agregarTareaSimple();
                break;
            case 2:
                agregarTareaProgramada();
                break;
            case 3:
                mostrarTareasPorPrioridad();
                break;
            case 4:
                mostrarTareasPorFecha();
                break;
            case 5:
                marcarTareaComoCompleta();
                break;
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 6);  // Repetir el menu hasta que el usuario elija salir

    return 0;
}
