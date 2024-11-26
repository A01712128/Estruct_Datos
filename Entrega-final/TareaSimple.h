#ifndef TAREASIMPLE_H
#define TAREASIMPLE_H

#include "Tarea.h"
#include <climits>  // Incluir para usar INT_MAX

// Clase para las tareas simples (sin fecha)
class TareaSimple : public Tarea {
public:
    TareaSimple(int id, const std::string& descripcion, int prioridad)
        : Tarea(id, descripcion, prioridad) {}

    int getFechaOrden() const override {
        return INT_MAX;  // No tiene fecha, se coloca al final al ordenar por fecha
    }
};

#endif
