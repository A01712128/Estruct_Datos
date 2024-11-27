# Proyecto: TaskMaster
TaskMaster es un proyecto de gestión de tareas en C++ que permite a los usuarios organizar y manejar tareas de manera sencilla, utilizando un sistema que categoriza las tareas en dos tipos: tareas simples y tareas programadas. 

Características principales:
Tareas Simples y Programadas
- Tareas Simples: Son tareas que no requieren una fecha específica para ser completadas.
- Tareas Programadas: Son tareas con una fecha de vencimiento que se pueden ordenar y gestionar según su fecha.

Almacenamiento en CSV:

Las tareas se guardan y cargan desde un archivo CSV (tareas.csv).
El archivo CSV contiene información como el ID de la tarea, la descripción, la prioridad y, si es una tarea programada, la fecha de vencimiento.

Ordenación de Tareas:
Las tareas pueden ser ordenadas de dos maneras
- Por prioridad: Las tareas con mayor prioridad se muestran primero.
- Por fecha: Las tareas se muestran de acuerdo a su fecha de vencimiento (de la más reciente a la más antigua).

Funcionalidad de Marcar Tareas como Completadas:

El usuario puede marcar tareas como completas, lo que las elimina de la lista activa y las mueve a una cola de tareas completadas. Esta operación se refleja  en la memoria y al momento de volver a seleccionar el mostrar tareas ya no aparece en la lista.

Interfaz de Usuario Sencilla:

El programa ofrece un menú interactivo donde el usuario puede seleccionar entre varias opciones las cuales son: agregar tareas, ver tareas por prioridad o fecha, marcar tareas como completas, y salir del programa.

Estructuras de Datos:
- Utiliza un vector (std::vector) para almacenar las tareas activas.
- Utiliza una cola (std::queue) para almacenar las tareas completadas.
- Implementa algoritmos de ordenación por merge sort para ordenar las tareas por prioridad o fecha de vencimiento.

## Descripción del avance 1
En el primer avance de TaskMaster, se implementaron las clases básicas para representar las tareas simples y programadas. Estas clases incluyen atributos como la descripción de la tarea, su importancia (un valor numérico), y, en el caso de las tareas programadas, una fecha de vencimiento. Se implementó la funcionalidad básica para que el usuario pueda ingresar las tareas y almacenarlas en una lista. Además, se utilizó el algoritmo Merge Sort para ordenar las tareas de acuerdo al grado de importancia.

## Descripción del avance 2
En este segundo avance, el gestor de tareas fue mejorado con nuevas funcionalidades y optimizaciones. Se añadió la capacidad de ordenar las tareas no solo por importancia, sino también por el tiempo estimado que requiere completar cada tarea. Además, se implementó el algoritmo Selection Sort como opción adicional para ordenar las tareas, ofreciendo más flexibilidad al usuario. También se introdujo una funcionalidad para pre-cargar un conjunto de tareas de ejemplo al iniciar el programa, lo que facilita la prueba del sistema sin necesidad de que el usuario ingrese datos manualmente.

### Cambios sobre el primer avance
Cambio 1: Adición de tiempo estimado a las tareas. Razón del cambio: Se incluyó el tiempo estimado como un atributo adicional en las tareas, para que los usuarios puedan gestionar mejor su tiempo y priorizar sus tareas en función de la duración estimada de las mismas.

Cambio 2: Implementación de un segundo algoritmo de ordenamiento (Selection Sort). Razón del cambio: Se agregó Selection Sort como una alternativa al algoritmo de ordenamiento existente (Merge Sort). Esto le ofrece al usuario más flexibilidad y le permite elegir el algoritmo de acuerdo con sus necesidades. Selection Sort fue elegido debido a su simplicidad.

Cambio 3: Pre-carga de tareas de ejemplo. Razón del cambio: Se añadió la capacidad de pre-cargar un conjunto de tareas de ejemplo al iniciar el programa. Esta mejora hace que el sistema sea más fácil de usar, ya que no requiere que el usuario ingrese tareas manualmente para probar el sistema.

## Descripción del avance 3
El tercer avance se centra en la optimización de la gestión de las tareas y en la mejora de la visualización de los resultados. Se implementaron mejoras adicionales en la ordenación de las tareas y se permitió guardar las tareas en un archivo CSV al final del programa, lo que asegura que los datos de las tareas se mantengan entre sesiones del programa. Se también hizo un análisis de complejidad del sistema para asegurar que las operaciones de ordenamiento y gestión de las tareas fueran eficientes.

### Cambios sobre el segundo avance
Cambio 1: Mejora en el algoritmo de ordenamiento. Razón del cambio: Se optimizó el uso de los algoritmos de ordenamiento, garantizando que tanto Merge Sort como Selection Sort funcionaran correctamente con grandes cantidades de datos.

Cambio 2: Implementación de la funcionalidad para guardar las tareas en un archivo CSV. Razón del cambio: Se añadió la capacidad de guardar las tareas en un archivo CSV, lo que permite la persistencia de los datos entre ejecuciones del programa. Esto facilita el almacenamiento y recuperación de las tareas sin necesidad de reingresarlas cada vez.

## Entrega final
La versión final del proyecto presenta una herramienta interactiva y eficiente para gestionar tareas, incorporando características de organización utilizando estructuras de datos como merge sort para ordenación y queue para manejo de tareas completadas.

Interfaz de Usuario:

Menú Principal: Al ejecutar el programa, el usuario verá un menú con opciones para agregar, ordenar y completar tareas:
1. Agregar tarea simple: Permite agregar tareas sin fecha de vencimiento, proporcionando solo una descripción y prioridad.
2. Agregar tarea programada: Permite agregar tareas con una fecha específica de vencimiento, junto con descripción y prioridad.
3. Mostrar tareas por prioridad: Muestra todas las tareas ordenadas por prioridad, de mayor a menor, utilizando merge sort.
4. Mostrar tareas por fecha: Muestra todas las tareas programadas ordenadas por su fecha de vencimiento, de la más reciente a la más antigua, utilizando merge sort.
5. Marcar tarea como completa: Permite marcar una tarea como completada, moviéndola a una queue de tareas completadas, y eliminándola de la lista activa. 
6. Salir: Finaliza el programa.

Funcionalidad Específica:

Agregar Tareas: El usuario puede agregar dos tipos de tareas:
- Tareas Simples: Tareas sin fecha, solo con prioridad y descripción.
- Tareas Programadas: Tareas con fecha de vencimiento que permiten ordenar las tareas por fecha.

Ordenación de Tareas con merge sort:
- Por Prioridad: Las tareas se ordenan de mayor a menor prioridad utilizando merge sort, un algoritmo eficiente de ordenación.
- Por Fecha: Las tareas programadas se ordenan de acuerdo a la fecha de vencimiento utilizando también merge sort, organizando las tareas de la más reciente a la más antigua.

Uso de queue para tareas completadas:

Al marcar una tarea como completada, esta se mueve a una queue de tareas completadas (tareasCompletadas), lo que permite gestionarlas de forma separada.
Las tareas completadas se eliminan de la lista activa, asegurando que solo se muestren las tareas pendientes en las vistas principales.
El queue ayuda a almacenar las tareas completadas de manera eficiente, pero no las mantiene en la vista principal del programa.

Manejo de Errores:

Si el usuario intenta completar una tarea que no existe o ingresa un valor inválido, el programa mostrará un mensaje de error adecuado y permitirá al usuario intentar nuevamente.

### Cambios sobre el tercer avance avance
1. Implementación de Merge Sort

En la versión final, se reemplazó el uso de priority_queue y sort por merge sort para ordenar las tareas. Esto se aplica tanto para ordenar las tareas por prioridad como por fecha.

2. Introducción de la Cola (queue) para Tareas Completadas

Se añadió una estructura de datos queue para manejar las tareas marcadas como completadas. 

3. Incorporación del Menú para Manejar Tareas Completas

En la versión final, se agregó una opción en el menú que permite marcar tareas como completas por su ID. Esta funcionalidad no existía en el tercer avance y fue implementada para mejorar la gestión de tareas. Una vez marcada como completa, se mueve a una cola (queue), lo que hace más dinámico el flujo del programa.

4. Uso de IDs para Identificar Tareas

Se introdujeron IDs únicos para identificar las tareas, lo que simplifica su manipulación, como marcarlas como completas. En el tercer avance, las tareas solo se diferenciaban por su descripción o tipo.


## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o final` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./final` 

## Descripción de las entradas del avance de proyecto
Archivo CSV (tareas.csv):

Es el archivo principal donde se almacenan las tareas. Este archivo contiene la información de las tareas que el usuario ha registrado, tanto simples como programadas. Cada fila del archivo representa una tarea con los siguientes campos separados por comas:

- ID (int): Identificador único de la tarea.
- Descripción (string): Texto descriptivo de la tarea.
- Prioridad (int): Número que indica la importancia de la tarea (valores más altos representan mayor prioridad).
- Tipo de tarea (string): Puede ser "simple" o "programada".
- Fecha (opcional): Si la tarea es programada, incluirá día, mes y año como tres valores separados por comas.

Ejemplo del csv:
- 1,Comprar leche,3,simple
- 2,Entregar reporte,5,programada,30,11,2024
- 3,Llamar al médico,4,simple
- 4,Vacaciones familiares,2,programada,15,12,2024


## Descripción de las salidas del avance de proyecto
Visualización de tareas ordenadas:
- Por prioridad: Lista de tareas ordenadas de mayor a menor prioridad, mostrando los siguientes datos:
    - ID
    - Descripción
    - Prioridad
- Por fecha: Lista de tareas programadas ordenadas de la más reciente a la más antigua, mostrando los siguientes datos:
    - ID
    - Descripción
    - Fecha (formato: DD/MM/AAAA)

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En este proyecto, se utilizó el algoritmo Merge Sort para ordenar las tareas por prioridad y por fecha. Este algoritmo es adecuado debido a su complejidad de tiempo de O(n log n) en el peor, promedio y mejor caso. Además, es estable, lo que significa que no cambia el orden relativo de las tareas con la misma clave.

Complejidad del Merge Sort:

- Tiempo: La división del array tiene una complejidad logarítmica (O(log n)), mientras que la combinación tiene una complejidad lineal (O(n)). Por lo tanto, el tiempo total es O(n log n).
- Espacio: La complejidad espacial es O(n) debido al uso de memoria adicional para las sublistas temporales.

Razón para elegir Merge Sort:

Es ideal para ordenar vectores grandes como el de tareas.
Al ser estable, mantiene el orden de las tareas con igual prioridad o fecha.
El análisis de complejidad para Merge Sort se observa en su implementación dentro del archivo FuncionesOrdenamiento.h.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
- Vector (std::vector):

Se utiliza para almacenar todas las tareas. Ofrece acceso aleatorio en O(1) y permite realizar búsquedas y modificaciones en O(n).

Justificación: El vector es adecuado para manejar una lista dinámica de tareas, ya que permite recorrerlas y ordenarlas de manera eficiente.

- Cola (std::queue):

Se emplea para almacenar las tareas completadas. Su operación principal es la inserción y extracción de elementos, con una complejidad de tiempo de O(1).

Justificación: La cola modela correctamente el flujo FIFO (primero en entrar, primero en salir), reflejando las tareas que han sido completadas.

Ejemplo práctico del uso de estructuras:
- La lista de tareas se ordena en O(n log n) con Merge Sort (vector).
- Las tareas completadas se manejan en tiempo constante con la cola (tareasCompletadas).


#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
- Lectura y escritura del archivo CSV:
    - La lectura de tareas desde el archivo tiene complejidad O(n), donde n es el número de líneas en el archivo.
    - La escritura al archivo también tiene complejidad O(n), ya que cada tarea debe ser convertida a texto y escrita en el archivo.

Agregar tarea:
- Inserción en el vector: O(1).
- Escritura al archivo CSV: O(n).

Marcar tarea como completa:
- Búsqueda de la tarea por ID en el vector: O(n).
- Inserción en la cola: O(1).

Complejidad final del programa:

La operación más costosa es el ordenamiento, con una complejidad de O(n log n).

Las demás operaciones, como agregar y completar tareas, tienen complejidad lineal O(n) en el peor caso.
Por lo tanto, la complejidad total destaca por el Merge Sort: O(n log n).


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se eligió Merge Sort por su estabilidad y su eficiencia incluso en listas grandes. Este algoritmo fue implementado de forma personalizada para ordenar por prioridad y por fecha. Las funciones mergeSortPorPrioridad y mergeSortPorFecha en FuncionesOrdenamiento.h muestran el uso correcto de este algoritmo.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
- Vector (std::vector):
Se eligió para almacenar las tareas activas debido a su flexibilidad en términos de tamaño dinámico y su integración con algoritmos de ordenamiento como Merge Sort.

Justificación: El acceso a los elementos del vector permite realizar operaciones como ordenar o buscar tareas de manera eficiente. Por ejemplo, al ordenar las tareas por prioridad o fecha, la estructura lineal del vector facilita la implementación del Merge Sort.

Ejemplo de uso correcto: Las funciones mergeSortPorPrioridad y mergeSortPorFecha demuestran cómo se utiliza el vector para organizar tareas.

- Cola (std::queue):
Se empleó para manejar las tareas completadas porque su comportamiento FIFO (First In, First Out) refleja el flujo lógico de las tareas terminadas.

Justificación: Las operaciones principales de la cola (inserción y extracción) tienen complejidad constante O(1), lo cual la hace eficiente para este propósito.

Ejemplo de uso correcto: Las tareas marcadas como completas se almacenan en tareasCompletadas asegurando un manejo secuencial y ordenado.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El programa permite consultar la información de las tareas de manera eficiente y clara:

- Tareas por prioridad: Se ordenan mediante el algoritmo Merge Sort, y se presentan de mayor a menor prioridad.
- Tareas por fecha: Las tareas programadas se ordenan de la más reciente a la más antigua.
- Consulta de detalles: Los métodos de las clases TareaSimple y TareaProgramada (como getDescripcion, getPrioridad, y getFechaOrden) proporcionan los datos relevantes de cada tarea.

Aprendizaje y evidencia:

La implementación demuestra un manejo correcto de las estructuras mediante funciones específicas que recorren el vector de tareas y extraen los datos relevantes. Esto se puede observar en las funciones mostrarTareasPorPrioridad y mostrarTareasPorFecha.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El programa incluye una función dedicada, leerTareasCSV, que:
- Lee las tareas desde un archivo CSV línea por línea.
- Identifica el tipo de tarea (simple o programada) y crea instancias de las clases TareaSimple o TareaProgramada.
- Almacena las tareas en un vector dinámico para su manejo posterior.

Aprendizaje y evidencia:

Este enfoque asegura que los datos del archivo se transformen correctamente en objetos de las clases correspondientes. En el archivo CSV se nos muestra la separación de campos con delimitadores como comas, y el manejo correcto de formatos específicos como fechas.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
El programa utiliza la función guardarTareasCSV para escribir todas las tareas activas en el archivo CSV:
- Recorre el vector de tareas activas.
- Determina si la tarea es simple o programada mediante dynamic_cast.
- Escribe los datos en el formato correcto, incluyendo prioridad y fecha si aplica.

Aprendizaje y evidencia:

Esto garantiza que las tareas se almacenen de manera segura, protegiendo su estado incluso después de que el programa finaliza. La escritura se realiza en un formato claro y reutilizable.
