#ifndef TAREA_H
#define TAREA_H

#include <string>
using namespace std;

class Tarea {
protected:
    string descripcion;
    int importancia;

public:
    Tarea(string descripcion, int importancia) : descripcion(descripcion), importancia(importancia) {}

    virtual ~Tarea() {}

    string obtenerDescripcion() const { return descripcion; }
    int obtenerImportancia() const { return importancia; }

    virtual void mostrarInformacion() const = 0;
};

#endif
