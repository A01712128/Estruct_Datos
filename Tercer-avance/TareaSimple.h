#ifndef TAREASIMPLE_H
#define TAREASIMPLE_H

#include "Tarea.h"
#include <iostream>
using namespace std;

class TareaSimple : public Tarea {
public:
    TareaSimple(string descripcion, int importancia) : Tarea(descripcion, importancia) {}

    void mostrarInformacion() const override {
        cout << "Tarea simple - Descripcion: " << descripcion 
             << ", Importancia: " << importancia << endl;
    }
};

#endif
