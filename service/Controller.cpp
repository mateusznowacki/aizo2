////
//// Created by matty on 08.06.2024.
////
//
//#include "Controller.h"
//#include "../Algorithms.h"
//#include "ConsoleManager.h"
//#include "../utlis/DataGenerator.h"
//#include "../utlis/FileManager.h"
//
//
//ConsoleManager console;
//Algorithms algorithm;
//DataGenerator generator;
//FileManager fileManager;
//
//
///*  // Metoda do pobierania danych od użytkownika w celu sortowania
//  void Controller::getUserDataForSorting() {
//      int choice = 0;
//      console.printAvailableDataSources(); // Wyświetlenie dostępnych źródeł danych
//      cin >> choice;
//      if (choice == 1) {
//          generateOwnDataAndSort(); // Generowanie własnych danych i sortowanie
//      } else if (choice == 2) {
//          getDataFromFileAndSort(); // Pobieranie danych z pliku i sortowanie
//      }
//  }
//
//  // Metoda do pobierania danych z pliku i sortowania
//
//  void Controller::getDataFromFileAndSort() {
//      string filename = console.printGetFilename(); // Pobranie nazwy pliku od użytkownika
//      int type = console.getTypeOptions(); // Wybór typu danych
//      bool printArray = console.askIfPrintArray(); // Zapytanie, czy wyświetlić tablicę przed i po sortowaniu
//
//      switch (type) {
//          case 1: { // Obsługa danych typu int
//              int *intArray = fileManager.getArrayFromFile<int>(filename); // Pobranie tablicy z pliku
//              int size = fileManager.getArraySizeFromFile(filename); // Pobranie rozmiaru tablicy
//              int *intArrayCopy = new int[size]; // Utworzenie kopii tablicy
//
//              do {
//                  copy(intArray, intArray + size, intArrayCopy); // Skopiowanie tablicy przed sortowaniem
//                  int algorithmType = console.printSortingAlgorithmsOptions(); // Wybór algorytmu sortowania
//                  runSortingAlgorithmVerification<int>(intArrayCopy, size, algorithmType,
//                                                       printArray); // Uruchomienie sortowania i weryfikacja
//              } while (console.askIfWantToCheckOtherAlgorithm()); // Sprawdzenie, czy użytkownik chce przetestować inny algorytm
//
//              delete[] intArray; // Zwolnienie pamięci
//              delete[] intArrayCopy; // Zwolnienie pamięci
//              break;
//          }
//          case 2: { // Analogicznie dla pozostałych typów danych
//              double *doubleArray = fileManager.getArrayFromFile<double>(filename);
//              int size = fileManager.getArraySizeFromFile(filename);
//              double *doubleArrayCopy = new double[size];
//
//              do {
//                  copy(doubleArray, doubleArray + size, doubleArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<double>(doubleArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//              delete[] doubleArray;
//              delete[] doubleArrayCopy;
//              break;
//          }
//          case 3: {
//              float *floatArray = fileManager.getArrayFromFile<float>(filename);
//              int size = fileManager.getArraySizeFromFile(filename);
//              float *floatArrayCopy = new float[size];
//
//
//              do {
//                  copy(floatArray, floatArray + size, floatArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<float>(floatArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//              delete[] floatArray;
//              delete[] floatArrayCopy;
//              break;
//          }
//          case 4: {
//              char *charArray = fileManager.getArrayFromFile<char>(filename);
//              int size = fileManager.getArraySizeFromFile(filename);
//              char *charArrayCopy = new char[size];
//
//              do {
//                  copy(charArray, charArray + size, charArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<char>(charArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//              delete[] charArray;
//              delete[] charArrayCopy;
//              break;
//          }
//      }
//  }
//
//  // Metoda do generowania własnych danych i sortowania
//  void Controller::generateOwnDataAndSort() {
//      // Analogicznie jak getDataFromFileAndSort(), ale dane generowane przez użytkownika
//      int type = console.getTypeOptions();
//      int size = console.printGetArraySize();
//      int arrayType = console.printSortedArrayType();
//      bool printArray = console.askIfPrintArray();
//      switch (type) {
//          case 1: {
//              int *intArray = getArray<int>(size, arrayType);
//              int *intArrayCopy = new int[size];
//
//              do {
//                  copy(intArray, intArray + size, intArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<int>(intArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//
//              delete[] intArray;
//              delete[] intArrayCopy;
//              break;
//          }
//          case 2: {
//              double *doubleArray = getArray<double>(size, arrayType);
//              double *doubleArrayCopy = new double[size];
//
//              do {
//                  copy(doubleArray, doubleArray + size, doubleArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<double>(doubleArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//              delete[] doubleArray;
//              delete[] doubleArrayCopy;
//              break;
//          }
//          case 3: {
//              float *floatArray = getArray<float>(size, arrayType);
//              float *floatArrayCopy = new float[size];
//
//              do {
//                  copy(floatArray, floatArray + size, floatArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<float>(floatArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//              delete[] floatArray;
//              delete[] floatArrayCopy;
//              break;
//          }
//          case 4: {
//              char *charArray = getArray<char>(size, arrayType);
//              char *charArrayCopy = new char[size];
//
//              do {
//                  copy(charArray, charArray + size, charArrayCopy);
//                  int algorithmType = console.printSortingAlgorithmsOptions();
//                  runSortingAlgorithmVerification<char>(charArrayCopy, size, algorithmType, printArray);
//
//              } while (console.askIfWantToCheckOtherAlgorithm());
//
//              delete[] charArray;
//              delete[] charArrayCopy;
//              break;
//          }
//      }
//  }
//
//  // Metoda do generowania tablicy o określonym typie i typie sortowania
//  template<typename T>
//  void Controller::*getArray(int size, int arrayType) {
//      // Wykorzystanie obiektu generatora do generowania tablicy
//      switch (arrayType) {
//          case 1:
//              return generator.generate33SortedArray<T>(size);
//          case 2:
//              return generator.generate66SortedArray<T>(size);
//          case 3:
//              return generator.generateAllRandomArray<T>(size);
//          default:
//              cerr << "Invalid array type." << std::endl;
//              return nullptr;
//      }
//  }
//
//  // Metoda do uruchamiania sortowania i weryfikacji jego poprawności
//  template<typename T>
//  void Controller::runSortingAlgorithmVerification(T *array, int size, int algorithmType, bool printArray) {
//      // Wykorzystanie obiektu algorytmu do wykonania sortowania
//      switch (algorithmType) {
//          case 1: {
//              printArray ? console.printArray(array, size) : void();
//              algorithm.insertionSort(array, size);
//              printArray ? console.printArray(array, size) : void();
//              console.printIfCorrectlySorted(algorithm.isSorted(array, size));
//              break;
//          }
//          case 2: {
//              printArray ? console.printArray(array, size) : void();
//              algorithm.insertionSortBinary(array, size);
//              printArray ? console.printArray(array, size) : void();
//              console.printIfCorrectlySorted(algorithm.isSorted(array, size));
//              break;
//          }
//          case 3: {
//              printArray ? console.printArray(array, size) : void();
//              algorithm.mergeSort(array, size);
//              printArray ? console.printArray(array, size) : void();
//              console.printIfCorrectlySorted(algorithm.isSorted(array, size));
//              break;
//          }
//          case 4: {
//              printArray ? console.printArray(array, size) : void();
//              algorithm.bubbleSort(array, size);
//              printArray ? console.printArray(array, size) : void();
//              console.printIfCorrectlySorted(algorithm.isSorted(array, size));
//              break;
//          }
//          case 5: {
//              printArray ? console.printArray(array, size) : void();
//              algorithm.heapSort(array, size);
//              printArray ? console.printArray(array, size) : void();
//              console.printIfCorrectlySorted(algorithm.isSorted(array, size));
//              break;
//          }
//          case 6: {
//              printArray ? console.printArray(array, size) : void();
//              algorithm.quickSort(array, size);
//              printArray ? console.printArray(array, size) : void();
//              console.printIfCorrectlySorted(algorithm.isSorted(array, size));
//              break;
//          }
//      }
//  }
//
//  // Metoda do uruchamiania sortowania i zwracania czasu jego wykonania
//  template<typename T>
//  auto Controller::runSortingAlgorithm(T *array, int size, int algorithmType) {
//      // Wykorzystanie obiektu algorytmu do wykonania sortowania i pomiaru czasu
//      chrono::high_resolution_clock::time_point start, end;
//
//      switch (algorithmType) {
//          case 1: {
//              start = chrono::high_resolution_clock::now();
//              algorithm.insertionSort(array, size);
//              end = chrono::high_resolution_clock::now();
//              break;
//          }
//          case 2: {
//              start = chrono::high_resolution_clock::now();
//              algorithm.insertionSortBinary(array, size);
//              end = chrono::high_resolution_clock::now();
//              break;
//          }
//          case 3: {
//              start = chrono::high_resolution_clock::now();
//              algorithm.mergeSort(array, size);
//              end = chrono::high_resolution_clock::now();
//              break;
//          }
//          case 4: {
//              start = chrono::high_resolution_clock::now();
//              algorithm.bubbleSort(array, size);
//              end = chrono::high_resolution_clock::now();
//              break;
//          }
//          case 5: {
//              start = chrono::high_resolution_clock::now();
//              algorithm.heapSort(array, size);
//              end = chrono::high_resolution_clock::now();
//              break;
//          }
//          case 6: {
//              start = chrono::high_resolution_clock::now();
//              algorithm.quickSort(array, size);
//              end = chrono::high_resolution_clock::now();
//              break;
//          }
//      }
//      chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
//      return duration; // Zwróć czas trwania sortowania
//  }*/
//
//// Metoda do generowania grafow i zapisywania ich do pliku
//void Controller::generateGraphsToFile() {
//    int vertexCount = console.printGetVertexCount(); // Pobranie liczby wierzchołków
//    int density = console.printGetDensity(); // Pobranie gęstości grafu
//
//    generator.generateRandomDirGraph(vertexCount, density);
//}