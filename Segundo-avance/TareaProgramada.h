#ifndef TAREAPROGRAMADA_H
#define TAREAPROGRAMADA_H

#include "Tarea.h"
#include <iostream>
using namespace std;

// Clase derivada TareaProgramada
class TareaProgramada : public Tarea {
private:
    string fechaVencimiento;

public:
    TareaProgramada(string descripcion, int importancia, string fechaVencimiento, int tiempoEstimado)
        : Tarea(descripcion, importancia, tiempoEstimado), fechaVencimiento(fechaVencimiento) {}

    void mostrarInformacion() const override {
        cout << "Tarea programada - Descripción: " << descripcion 
             << ", Importancia: " << importancia 
             << ", Fecha de vencimiento: " << fechaVencimiento 
             << ", Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
    }
};

#endif
