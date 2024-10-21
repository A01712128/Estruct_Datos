#ifndef TAREA_H
#define TAREA_H

#include <string>
using namespace std;

// Clase base Tarea
class Tarea {
protected:
    string descripcion;
    int importancia;
    int tiempoEstimado; // Tiempo estimado en minutos

public:
    Tarea(string descripcion, int importancia, int tiempoEstimado) 
        : descripcion(descripcion), importancia(importancia), tiempoEstimado(tiempoEstimado) {}

    virtual ~Tarea() {} // Destructor virtual

    int obtenerImportancia() const {
        return importancia;
    }

    int obtenerTiempoEstimado() const {
        return tiempoEstimado;
    }

    virtual void mostrarInformacion() const = 0; // Metodo virtual puro
};

#endif
