# Proyecto: TaskMaster
TaskMaster es un gestor de tareas diseñado para ayudar a los usuarios a organizar sus actividades diarias. El programa permite agregar y organizar dos tipos de tareas: simples (sin fecha de vencimiento) y programadas (con fecha de vencimiento). Los usuarios pueden ordenar las tareas por su grado de importancia o por el tiempo estimado que requieren para completarlas. 

## Descripción del avance 1
En el primer avance de TaskMaster, se implementaron las clases básicas para representar las tareas simples y programadas. Estas clases incluyen atributos como la descripción de la tarea, su importancia (un valor numérico), y, en el caso de las tareas programadas, una fecha de vencimiento. Se implementó la funcionalidad básica para que el usuario pueda ingresar las tareas y almacenarlas en una lista. Además, se utilizó el algoritmo Merge Sort para ordenar las tareas de acuerdo al grado de importancia.

## Descripción del avance 2
En este segundo avance, el gestor de tareas fue mejorado con nuevas funcionalidades y optimizaciones. Se añadió la capacidad de ordenar las tareas no solo por importancia, sino también por el tiempo estimado que requiere completar cada tarea. Además, se implementó el algoritmo Selection Sort como opción adicional para ordenar las tareas, ofreciendo más flexibilidad al usuario. También se introdujo una funcionalidad para pre-cargar un conjunto de tareas de ejemplo al iniciar el programa, lo que facilita la prueba del sistema sin necesidad de que el usuario ingrese datos manualmente.

### Cambios sobre el primer avance
Cambio 1: Adición de tiempo estimado a las tareas.
Razón del cambio: Se incluyó el tiempo estimado como un atributo adicional en las tareas, para que los usuarios puedan gestionar mejor su tiempo y priorizar sus tareas en función de la duración estimada de las mismas.

Cambio 2: Implementación de un segundo algoritmo de ordenamiento (Selection Sort).
Razón del cambio: Se agregó Selection Sort como una alternativa al algoritmo de ordenamiento existente (Merge Sort). Esto le ofrece al usuario más flexibilidad y le permite elegir el algoritmo de acuerdo con sus necesidades. Selection Sort fue elegido debido a su simplicidad.

Cambio 3: Pre-carga de tareas de ejemplo.
Razón del cambio: Se añadió la capacidad de pre-cargar un conjunto de tareas de ejemplo al iniciar el programa. Esta mejora hace que el sistema sea más fácil de usar, ya que no requiere que el usuario ingrese tareas manualmente para probar el sistema.

## Descripción del avance 3
El tercer avance se centra en la optimización de la gestión de las tareas y en la mejora de la visualización de los resultados. Se implementaron mejoras adicionales en la ordenación de las tareas y se permitió guardar las tareas en un archivo CSV al final del programa, lo que asegura que los datos de las tareas se mantengan entre sesiones del programa. Se también hizo un análisis de complejidad del sistema para asegurar que las operaciones de ordenamiento y gestión de las tareas fueran eficientes.

### Cambios sobre el segundo avance
Cambio 1: Mejora en el algoritmo de ordenamiento.
Razón del cambio: Se optimizó el uso de los algoritmos de ordenamiento, garantizando que tanto Merge Sort como Selection Sort funcionaran correctamente con grandes cantidades de datos.

Cambio 2: Implementación de la funcionalidad para guardar las tareas en un archivo CSV.
Razón del cambio: Se añadió la capacidad de guardar las tareas en un archivo CSV, lo que permite la persistencia de los datos entre ejecuciones del programa. Esto facilita el almacenamiento y recuperación de las tareas sin necesidad de reingresarlas cada vez.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
tipo,descripcion,importancia,tiempoEstimado,fechaVencimiento
### Ejemplo de entrada:
* simple,Estudiar C++,5,60
* programada,Reunión de equipo,4,30,12-12-2024
* simple,Hacer compras,3,45

Las tareas simples no tienen fechaVencimiento.

Las tareas programadas deben incluir una fechaVencimiento.


## Descripción de las salidas del avance de proyecto
La salida del programa incluye:

- La visualización de las tareas ordenadas por importancia o tiempo estimado.
- La visualización de tareas por tipo (simples y programadas).
- El almacenamiento de las tareas en un archivo CSV al finalizar el programa para su posterior uso.
- Los resultados se presentan en la consola, mostrando las tareas ordenadas y organizadas de acuerdo con los criterios seleccionados.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se realizó un análisis detallado de los algoritmos de ordenamiento utilizados. El algoritmo Merge Sort tiene una complejidad de O(n log n) en todos los casos (mejor, promedio y peor). El algoritmo Selection Sort, por su parte, tiene una complejidad de O(n²) en todos los casos. Ambos algoritmos fueron evaluados en el contexto de las tareas y se eligieron para cumplir con las necesidades del sistema, considerando tanto la eficiencia como la simplicidad.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Las tareas se almacenan en un vector. Las operaciones de inserción y eliminación de tareas tienen una complejidad de O(1), mientras que la ordenación de las tareas por importancia o tiempo estimado (dependiendo del algoritmo) tiene una complejidad de O(n log n) con Merge Sort o O(n²) con Selection Sort.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
El análisis completo indica que la complejidad final del programa está dominada por el algoritmo de ordenamiento utilizado y que el rendimiento general dependerá del número de tareas ingresadas, con una complejidad de O(n log n) en el caso de Merge Sort y O(n²) en el caso de Selection Sort.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El algoritmo de ordenamiento adecuado fue Merge Sort debido a su eficiencia para ordenar grandes cantidades de datos en O(n log n). Además, se implementó Selection Sort como opción adicional para ofrecer flexibilidad en el ordenamiento, con un coste más alto de O(n²).

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
La estructura de datos elegida para almacenar las tareas es el vector. Este tipo de estructura es eficiente para almacenar y acceder a las tareas, permitiendo realizar ordenamientos rápidos y fáciles de manejar, especialmente cuando se combina con algoritmos de ordenamiento como Merge Sort.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El sistema permite consultar las tareas mediante el uso de un menú interactivo que permite mostrar las tareas por tipo (simples o programadas) y por orden de importancia o tiempo estimado.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El archivo CSV es leído correctamente mediante la función cargarTareasDesdeArchivo, que carga las tareas en las estructuras correspondientes (simples o programadas).

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Se implementó una función para guardar las tareas en un archivo CSV, lo que permite la persistencia de los datos. Al finalizar el programa, las tareas se almacenan en el archivo CSV para que el usuario pueda continuar trabajando con los mismos datos en futuras ejecuciones.
