#include <iostream>
#include <chrono>

using namespace std;

int addFirst(int** arr, int value, int& capacity, int& size) {
    auto start = chrono::high_resolution_clock::now();

    int* newArr;

    if (size >= capacity) {
        capacity *= 2;
        newArr = new int[capacity];
        cout << "Zmieniam rozmiar tablicy na: " << capacity << "\n" << endl;
    }
    else {
        newArr = new int[capacity];
    }
    newArr[0] = value;

    for (int i = 0; i < size; i++) {
        newArr[i + 1] = (*arr)[i];
    }

    delete[] * arr;
    *arr = newArr;
    size++;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}

int addLast(int** arr, int value, int& capacity, int& size) {

    auto start = chrono::high_resolution_clock::now();
    int* newArr;
    if (size >= capacity) {
        capacity *= 2;
        newArr = new int[capacity];
        cout << "Zmieniam rozmiar tablicy na: " << capacity << "\n" << endl;
    }
    else {
        newArr = new int[capacity];
    }

    for (int i = 0; i < size + 1; i++) {
        newArr[i] = (*arr)[i];
    }

    newArr[size] = value;

    delete[] * arr;
    *arr = newArr;
    size++;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}

int addIndex(int** arr, int value, int index, int& capacity, int& size) {

    auto start = chrono::high_resolution_clock::now();
    int* newArr;
    if (size >= capacity) {
        capacity *= 2;
        newArr = new int[capacity];
        cout << "Zmieniam rozmiar tablicy na: " << capacity << "\n" << endl;
    }
    else {
        newArr = new int[capacity];
    }

    for (int i = 0; i < index; i++) {
        newArr[i] = (*arr)[i];
    }

    newArr[index] = value;

    for (int i = index + 1; i < size + 1; i++) {
        newArr[i] = (*arr)[i - 1];
    }

    delete[] * arr;
    *arr = newArr;
    size++;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}

int removeFirst(int** arr, int& capacity, int& size) {

    auto start = chrono::high_resolution_clock::now();
    int* newArr = new int[capacity];

    for (int i = 0; i < size - 1; i++) {
        newArr[i] = (*arr)[i + 1];
    }

    delete[] * arr;
    *arr = newArr;
    size--;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}

int removeLast(int** arr, int& capacity, int& size) {

    auto start = chrono::high_resolution_clock::now();
    int* newArr = new int[capacity];

    for (int i = 0; i < size - 1; i++) {
        newArr[i] = (*arr)[i];
    }

    delete[] * arr;
    *arr = newArr;
    size--;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 
    return duration;
}

int removeIndex(int** arr, int index, int& capacity, int& size) {

    auto start = chrono::high_resolution_clock::now();
    int* newArr = new int[capacity];

    for (int i = 0; i < index; i++) {
        newArr[i] = (*arr)[i];
    }

    for (int i = index; i < size - 1; i++) {
        newArr[i] = (*arr)[i + 1];
    }

    delete[] * arr;
    *arr = newArr;
    size--;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}

int getIndex(int** arr, int value, int size) {

    auto start = chrono::high_resolution_clock::now();
    int index = -1;

    for (int i = 0; i < size; i++) {
        if ((*arr)[i] == value) {
            index = i;
            break;
        }
    }

    //if (index != -1) {
    //    cout << "Index elementu " << value << " to: " << index << endl;
    //}
    //else {
    //    cout << "Nie znaleziono elementu o zadanej wartosci." << endl;
    //}

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}



int main() {

    int capacity = 20000;
    int size = 20000;
    int* dynArr = new int[capacity];

    for (int i = 0; i < size; i++) {
        dynArr[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += addFirst(&dynArr, 2115, capacity, size);
    }
    sum /= 50;
    cout << "Sredni czas dodawania elementu na poczatek tablicy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += addLast(&dynArr, 2115, capacity, size);
    }
    sum /= 50;
    cout << "Sredni czas dodawania elementu na koniec tablicy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += addIndex(&dynArr, 2115, (size/2), capacity, size);
    }
    sum /= 50;
    cout << "Sredni czas dodawania elementu na wybrany (srodkowy) indeks tablicy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += removeFirst(&dynArr, capacity, size);
    }
    sum /= 50;
    cout << "Sredni czas usuwania elementu na poczatku tablicy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += removeLast(&dynArr, capacity, size);
    }
    sum /= 50;
    cout << "Sredni czas usuwania elementu na koncu tablicy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += removeIndex(&dynArr, (size/2), capacity, size);
    }
    sum /= 50;
    cout << "Sredni czas usuwania elementu na wybranym (srodkowym) indeksie tablicy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += getIndex(&dynArr, (size/2), size);
    }
    sum /= 50;
    cout << "Sredni czas wyszukiwania elementu o wybranej wartosci w tablicy: " << sum << " ns" << "\n" << endl;

    cout << "Aktualna pojemnosc (capacity): " << capacity << endl;

    delete[] dynArr;

    return 0;
}
