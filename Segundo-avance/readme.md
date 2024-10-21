# Proyecto: TaskMaster
Este proyecto consiste en un gestor de tareas que permite a los usuarios agregar, visualizar y ordenar tareas de forma eficiente. Las tareas pueden ser simples o programadas y se pueden clasificar según su importancia o el tiempo estimado que requieren. El sistema está diseñado para facilitar la organización del tiempo y mejorar la productividad.

## Descripción del avance 1
En el primer avance, se implementó la funcionalidad básica del gestor de tareas, que incluye la creación y visualización de tareas simples y programadas. Las tareas se almacenan en una lista y se pueden mostrar al usuario. También se implementó un algoritmo de ordenamiento (Merge Sort) para ordenar las tareas por importancia.

## Descripción del avance 2
En este segundo avance, se mejoró el gestor de tareas añadiendo nuevas características, incluyendo la opción de ordenar las tareas no solo por importancia, sino también por el tiempo estimado para completarlas. Además, se implementó un nuevo algoritmo de ordenamiento (Selection Sort) para esta funcionalidad. Se añadió la capacidad de pre-cargar un conjunto de tareas de ejemplo al iniciar el programa, facilitando así la prueba y uso del gestor.

### Cambios sobre el primer avance
1. Adición de tiempo estimado a las tareas
Razón del cambio: Permitir a los usuarios planificar mejor sus actividades y gestionar su tiempo de manera efectiva. Al incluir el tiempo estimado, se ofrece una opción adicional para organizar las tareas.

2. Implementación de un segundo algoritmo de ordenamiento (Selection Sort)
Razón del cambio: Este cambio permite a los usuarios elegir entre dos métodos de ordenamiento según sus necesidades. Selection Sort es fácil de entender y se ajusta a la simplicidad del proyecto.

3. Pre-carga de tareas de ejemplo
Razón del cambio: Facilitar la demostración del programa sin necesidad de que el usuario ingrese tareas manualmente al inicio. Esto mejora la experiencia del usuario y la presentación del proyecto.


## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Las entradas del programa son interacciones del usuario a través de la consola. Al iniciar, el programa muestra un menú con las siguientes opciones:

* Agregar una tarea simple (requiere descripción, grado de importancia y tiempo estimado).
* Agregar una tarea programada (requiere descripción, grado de importancia, fecha de vencimiento y tiempo estimado).
* Mostrar y ordenar tareas por importancia.
* Mostrar y ordenar tareas por tiempo estimado.
* Salir.

## Ejemplo de entrada para una tarea simple
- Ingrese la descripción de la tarea: Comprar despensa
- Ingrese el grado de importancia (1 a 5): 3
- Ingrese el tiempo estimado (en minutos): 30


## Descripción de las salidas del avance de proyecto
Las salidas del programa consisten en la visualización de las tareas en la consola. Al ejecutar el programa y elegir las opciones de mostrar tareas, se imprimen las tareas ordenadas según el criterio seleccionado (por importancia o tiempo estimado) con la siguiente información:

* Descripción de la tarea
* Grado de importancia
* Tiempo estimado en minutos
* Fecha de vencimiento (si aplica)

## Ejemplo de salida
Tareas ordenadas por grado de importancia:
- Tarea programada - Descripción: Presentación del proyecto, Importancia: 5, Fecha de vencimiento: 25-10-2024, Tiempo estimado: 120 minutos
- Tarea simple - Descripción: Comprar despensa, Importancia: 3, Tiempo estimado: 30 minutos


## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En este avance, se utilizó Merge Sort y Selection Sort. El tiempo de complejidad de Merge Sort es O(n log n), mientras que Selection Sort tiene una complejidad de O(n²). Esta comparación muestra una comprensión clara de los algoritmos y su aplicación en el contexto del programa.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Se utilizó un vector para almacenar las tareas, lo que permite un acceso rápido y dinámico. Las operaciones de agregar y acceder a elementos tienen una complejidad promedio de O(1) en un vector.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se eligieron dos algoritmos de ordenamiento: Merge Sort para su eficiencia en grandes conjuntos de datos y Selection Sort por su simplicidad y facilidad de implementación. Ambos se implementan correctamente en el programa, cumpliendo con las necesidades del proyecto.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Se utilizó un vector para almacenar las tareas debido a su flexibilidad y facilidad de uso. Esto se observa en la forma en que se añaden y gestionan las tareas en el programa.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Se implementaron métodos en las clases para mostrar información relevante sobre cada tarea, lo que permite una consulta eficiente de los datos.
