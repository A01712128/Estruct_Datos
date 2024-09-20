#ifndef FUNCIONESORDENAMIENTO_H
#define FUNCIONESORDENAMIENTO_H

#include "Tarea.h"
#include <vector>
using namespace std;

void fusionar(vector<Tarea*>& tareas, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    vector<Tarea*> izquierda(n1);
    vector<Tarea*> derecha(n2);

    for (int i = 0; i < n1; i++)
        izquierda[i] = tareas[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = tareas[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (izquierda[i]->obtenerImportancia() >= derecha[j]->obtenerImportancia()) {
            tareas[k] = izquierda[i];
            i++;
        } else {
            tareas[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tareas[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2) {
        tareas[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Tarea*>& tareas, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        mergeSort(tareas, inicio, medio);
        mergeSort(tareas, medio + 1, fin);
        fusionar(tareas, inicio, medio, fin);
    }
}

#endif
