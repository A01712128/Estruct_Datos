# TaskMaster
Este proyecto consiste en un gestor de tareas que permite al usuario agregar y organizar dos tipos de tareas: tareas simples (sin fecha de vencimiento) y tareas programadas (con fecha de vencimiento). El sistema permite ingresar, almacenar y ordenar estas tareas por su grado de importancia usando el algoritmo de Merge Sort.

## Descripción del avance 1
n este primer avance, se implementaron las clases para representar las tareas simples y las programadas, con un sistema para que el usuario ingrese las tareas, las almacene en una lista y las ordene de acuerdo al grado de importancia. El programa utiliza Merge Sort para realizar el ordenamiento de las tareas. También se añadió la funcionalidad de mostrar las tareas ordenadas con un formato más legible, añadiendo un espacio entre ellas.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Las entradas del proyecto son los datos que el usuario proporciona para cada tarea. Estos datos incluyen:
- Descripción de la tarea (cadena de texto).
- Grado de importancia (un número entre 1 y 5, donde 1 es menos importante y 5 es más importante).
- En el caso de las tareas programadas, también se incluye una fecha de vencimiento en el formato DD-MM-YYYY.

Ejemplo de entradas:
- Tarea simple - Descripción: Hacer la compra, Importancia: 3
- Tarea programada - Descripción: Entrega de proyecto, Importancia: 5, Fecha de vencimiento: 20-09-2024

## Descripción de las salidas del avance de proyecto
El programa, tras la ejecución, devuelve la lista de tareas ingresadas por el usuario ordenadas por su grado de importancia. Las tareas se muestran con la descripción, grado de importancia y, si es una tarea programada, su fecha de vencimiento. Cada tarea se muestra en una nueva línea y se separa de la siguiente por un espacio en blanco para mejorar la legibilidad.

# Desarrollo de competencias
## SICT0301: Evalúa los componentes
Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo de Merge Sort fue seleccionado porque garantiza un tiempo de ejecución de O(n log n) en el peor de los casos, lo cual es más eficiente que otros algoritmos como el Bubble Sort o el Insertion Sort, que tienen una complejidad de O(n²). 
Merge Sort es ideal cuando se requiere un algoritmo estable que mantenga el orden relativo de elementos iguales y que funcione bien con listas grandes. 
El análisis de su complejidad está correctamente aplicado, ya que para ordenar las tareas por importancia, es fundamental que el algoritmo mantenga la eficiencia independientemente del número de tareas ingresadas.

## SICT0302: Toma decisiones
Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se eligió Merge Sort por su desempeño consistente y su capacidad de manejar listas grandes con eficiencia. 
Además, su implementación divide las tareas en sublistas más pequeñas, lo que facilita el proceso de ordenamiento, y al ser un algoritmo estable, preserva el orden de las tareas con igual importancia. 
El uso de Merge Sort se observa en la función mergeSort que se implementó para ordenar las tareas, y su correcta aplicación se refleja en los resultados al mostrar las tareas en orden de importancia.
