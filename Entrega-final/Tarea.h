#ifndef TAREA_H
#define TAREA_H

#include <string>

// Clase base para las tareas
class Tarea {
protected:
    int id;
    std::string descripcion;
    int prioridad;

public:
    Tarea(int id, const std::string& descripcion, int prioridad)
        : id(id), descripcion(descripcion), prioridad(prioridad) {}

    virtual ~Tarea() {}

    int getId() const { return id; }
    std::string getDescripcion() const { return descripcion; }
    int getPrioridad() const { return prioridad; }

    virtual int getFechaOrden() const = 0;  // Metodo virtual puro para obtener la fecha en formato ordenable
};

#endif
