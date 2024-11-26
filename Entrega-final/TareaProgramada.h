#ifndef TAREAPROGRAMADA_H
#define TAREAPROGRAMADA_H

#include "Tarea.h"

// Clase para las tareas programadas (con fecha)
class TareaProgramada : public Tarea {
private:
    int dia, mes, anio;

public:
    TareaProgramada(int id, const std::string& descripcion, int prioridad, int dia, int mes, int anio)
        : Tarea(id, descripcion, prioridad), dia(dia), mes(mes), anio(anio) {}

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    int getFechaOrden() const override {
        return anio * 10000 + mes * 100 + dia;  // Retornar la fecha en formato AAAAMMDD
    }
};

#endif
