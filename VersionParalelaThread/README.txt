Procesamiento Paralelo con Thread

Este código en C++ realiza el procesamiento secuencial de imágenes al leer una imagen, convertirla a escala de grises y guardar la imagen modificada. El código utiliza la biblioteca OpenCV para el manejo y procesamiento de imágenes.

Antes de ejecutar el código, debes considerar lo siguiente:

    - OpenCV: El código depende de la biblioteca OpenCV. Puedes instalarla mediante gestores de paquetes como apt o brew, o siguiendo las instrucciones en el sitio web de OpenCV (https://opencv.org/).
    - Imagen: Debes tener una imagen en formato .jpg dentro de la carpeta del codigo. Esta debe tener el nombre de "imagen" para poder ser reconocida correctamente.
    - Threads a utilizar: Para modificar la cantidad de hilos a utilizar, debes dirigirte a la línea 36 del código (int numThreads = 4;) y cambiar manualmente al número que deseas utilizar. Predefinidamente está con 4 threads.

Ejecución del Código

Compila y ejecuta el código utilizando un compilador C++ en un sistema operativo basado en Debian o devirados. 

Se debe escribir el comando "make" mediante terminal para compilar. Esto dejará un ejecutable llamado "App", el cual tendrá que ser ejecutado mediante el comando "./app", con esto procederá la ejecución del código.

Resultado

Después de ejecutar el código, encontrarás la imagen procesada guardada como "imagen_modificada_secuencial.jpg" en el directorio del proyecto.
También se dispondrá el tiempo de ejecución gracias a la libreria "chrono", dicho tiempo se verá mediante terminal una vez concluida la correcta ejecución del código.