#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;

void convertToGrayscaleThread(Mat& image, int startRow, int endRow) {
    int cols = image.cols;
    for (int r = startRow; r < endRow; r++) {
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

    // Definir el número de hilos a utilizar
    int numThreads = 4; // por ejemplo, 4 hilos

    // Dividir la imagen en partes iguales
    int rows = image.rows;
    int rowsPerThread = rows / numThreads;
    vector<thread> threads;
    for (int i = 0; i < numThreads; i++) {
        int startRow = i * rowsPerThread;
        int endRow = (i == numThreads - 1) ? rows : (i + 1) * rowsPerThread;
        threads.emplace_back(convertToGrayscaleThread, ref(image), startRow, endRow);
    }

    // Esperar a que todos los hilos terminen
    for (auto &t : threads) {
        t.join();
    }

    // Guardar la imagen resultante
    imwrite("imagen_modificada_thread.jpg", image);

    // Detener el temporizador y calcular el tiempo total de ejecución
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // Imprimir el tiempo total de ejecución
    cout << "Total time spent in seconds is " << time_taken << endl;

    return 0;
}

