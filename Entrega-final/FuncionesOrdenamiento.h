#ifndef FUNCIONESORDENAMIENTO_H
#define FUNCIONESORDENAMIENTO_H

#include <vector>
#include "Tarea.h"

// Funcion para ordenar tareas por prioridad (de mayor a menor)
void mergeSortPorPrioridad(std::vector<Tarea*>& tareas, int left, int right) {
    if (left >= right) return;  // Caso base, si la lista tiene 1 o menos elementos
    int mid = (left + right) / 2;
    mergeSortPorPrioridad(tareas, left, mid);  // Ordenar la mitad izquierda
    mergeSortPorPrioridad(tareas, mid + 1, right);  // Ordenar la mitad derecha

    std::vector<Tarea*> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        // Comparar y ordenar por prioridad
        if (tareas[i]->getPrioridad() >= tareas[j]->getPrioridad()) {
            temp.push_back(tareas[i++]);
        } else {
            temp.push_back(tareas[j++]);
        }
    }
    while (i <= mid) temp.push_back(tareas[i++]);  // Copiar el resto de la mitad izquierda
    while (j <= right) temp.push_back(tareas[j++]);  // Copiar el resto de la mitad derecha
    for (int k = left; k <= right; ++k) {
        tareas[k] = temp[k - left];  // Reemplazar los elementos originales con los ordenados
    }
}

// Funcion para ordenar tareas por fecha (de mas reciente a mas antiguo)
void mergeSortPorFecha(std::vector<Tarea*>& tareas, int left, int right) {
    if (left >= right) return;  // Caso base, si la lista tiene 1 o menos elementos
    int mid = (left + right) / 2;
    mergeSortPorFecha(tareas, left, mid);  // Ordenar la mitad izquierda
    mergeSortPorFecha(tareas, mid + 1, right);  // Ordenar la mitad derecha

    std::vector<Tarea*> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        // Comparar y ordenar por fecha
        if (tareas[i]->getFechaOrden() >= tareas[j]->getFechaOrden()) {
            temp.push_back(tareas[i++]);
        } else {
            temp.push_back(tareas[j++]);
        }
    }
    while (i <= mid) temp.push_back(tareas[i++]);  // Copiar el resto de la mitad izquierda
    while (j <= right) temp.push_back(tareas[j++]);  // Copiar el resto de la mitad derecha
    for (int k = left; k <= right; ++k) {
        tareas[k] = temp[k - left];  // Reemplazar los elementos originales con los ordenados
    }
}

#endif
