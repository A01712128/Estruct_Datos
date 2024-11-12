#ifndef TAREAPROGRAMADA_H
#define TAREAPROGRAMADA_H

#include "Tarea.h"
#include <iostream>
using namespace std;

class TareaProgramada : public Tarea {
private:
    string fechaVencimiento;

public:
    TareaProgramada(string descripcion, int importancia, string fecha)
        : Tarea(descripcion, importancia), fechaVencimiento(fecha) {}

    string obtenerFechaVencimiento() const { return fechaVencimiento; }

    void mostrarInformacion() const override {
        cout << "Tarea programada - Descripcion: " << descripcion 
             << ", Importancia: " << importancia 
             << ", Fecha de vencimiento: " << fechaVencimiento << endl;
    }
};

#endif
