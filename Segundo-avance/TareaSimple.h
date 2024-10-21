#ifndef TAREASIMPLE_H
#define TAREASIMPLE_H

#include "Tarea.h"
#include <iostream>
using namespace std;

// Clase derivada TareaSimple
class TareaSimple : public Tarea {
public:
    TareaSimple(string descripcion, int importancia, int tiempoEstimado) 
        : Tarea(descripcion, importancia, tiempoEstimado) {}

    void mostrarInformacion() const override {
        cout << "Tarea simple - Descripción: " << descripcion 
             << ", Importancia: " << importancia 
             << ", Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
    }
};

#endif
