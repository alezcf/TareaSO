#include <chrono>
#include <vector>
#include <opencv2/opencv.hpp>
#include <omp.h>

using namespace cv;
using namespace std;

void convertToGrayscaleOpenMP(Mat& image) {
    int rows = image.rows;
    int cols = image.cols;
    omp_set_num_threads(4); // Establecer el número de hilos deseado
    #pragma omp parallel for
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            int gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            pixel[0] = pixel[1] = pixel[2] = gray;
            image.at<Vec3b>(r, c) = pixel;
        }
    }
}

int main() {
    // Inicializar el temporizador
    auto start = chrono::high_resolution_clock::now();

    // Leer la imagen
    Mat image = imread("imagen2.jpg", IMREAD_COLOR);

    // Verificar si la imagen se ha cargado correctamente
    if (image.empty()) {
        cout << "No se pudo leer la imagen" << endl;
        return -1;
    }

    // Llamar a la función de conversión a escala de grises con OpenMP
    convertToGrayscaleOpenMP(image);

    // Guardar la imagen resultante
    imwrite("imagen_modificada_openmp.jpg", image);

    // Detener el temporizador y calcular el tiempo total de ejecución
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // Imprimir el tiempo total de ejecución
    cout << "Tiempo total de ejecución en segundos: " << time_taken << endl;

    return 0;
}


