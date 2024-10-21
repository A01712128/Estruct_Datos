#ifndef TAREA_H
#define TAREA_H

#include <string>
using namespace std;

// Clase base Tarea
class Tarea {
protected:
    string descripcion;
    int importancia;

public:
    Tarea(string descripcion, int importancia) : descripcion(descripcion), importancia(importancia) {}

    virtual ~Tarea() {} // Destructor virtual

    int obtenerImportancia() const {
        return importancia;
    }

    virtual void mostrarInformacion() const = 0; // Método virtual puro
};

#endif
