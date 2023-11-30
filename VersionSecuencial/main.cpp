#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;

int main() {
    // Inicializar el temporizador
    auto start = chrono::high_resolution_clock::now();

    // Leer la imagen
    Mat image = imread("imagen.jpg", IMREAD_COLOR);

    // Verificar si la imagen se ha cargado correctamente
    if (image.empty()) {
        cout << "No se pudo leer la imagen" << endl;
        return -1;
    }

    // Obtener las dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;

    // Iterar sobre la matriz de la imagen y aplicar la conversión a escala de grises
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            int gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            pixel[0] = pixel[1] = pixel[2] = gray;
            image.at<Vec3b>(r, c) = pixel;
        }
    }

    // Guardar la imagen resultante
    imwrite("imagen_modificada_secuencial.jpg", image);

    // Detener el temporizador y calcular el tiempo total de ejecución
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // Imprimir el tiempo total de ejecución
    cout << "Total time spent in seconds is " << time_taken << endl;

    return 0;
}
