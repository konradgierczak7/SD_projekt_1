#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//tworzenie struktury węzła
struct node {
    int value;
    struct node* next;
};

//funckja do dodawania elementu na początek listy
int addFirst(struct node** head, int value) {
    auto start = chrono::high_resolution_clock::now();
    struct node* newNode = new node;
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    return duration;
}

//funkcja do dodawania elementu na koniec listy 
int addLast(struct node** head, int value) {
    auto start = chrono::high_resolution_clock::now();
    struct node* newNode = new node;
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node* temporary = *head;
        while (temporary->next != NULL) {
            temporary = temporary->next;
        }
        temporary->next = newNode;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();

    return duration;
}

//funkcja do dodawania elementu na wybrany indeks
int addIndex(struct node** head, int value, int index) {
    auto start = chrono::high_resolution_clock::now();
    struct node* newNode = new node;
    newNode->value = value;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        return duration;
    }

    struct node* temporary = *head;
    int currentIndex = 0;

    while (temporary != NULL && currentIndex < index - 1) {
        temporary = temporary->next;
        currentIndex++;
    }

    if (temporary == NULL) {
        delete newNode;
        return -1;
    }

    newNode->next = temporary->next;
    temporary->next = newNode;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    return duration;
}


//funkcja do usuwania elementu z początku listy
int removeFirst(struct node** head) {
    auto start = chrono::high_resolution_clock::now();
    if (*head == NULL) return -1;

    struct node* temporary = *head;
    *head = (*head)->next;
    delete temporary;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    
    return duration;
}

//funckcja do usuwania elementu z końca listy
int removeLast(struct node** head) {
    auto start = chrono::high_resolution_clock::now();
    if (*head == NULL) return -1;
    struct node* temporary = *head;
    struct node* previous = NULL;

    while (temporary->next != NULL) {
        previous = temporary;
        temporary = temporary->next;
    }

    if (previous == NULL) {
        delete temporary;
        *head = NULL;
        delete temporary;
        previous->next = NULL;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    
    return duration;
}

//funkcja do usuwania elementu z wybranego indeksu
int removeIndex(struct node** head, int index) {
    auto start = chrono::high_resolution_clock::now();
    if (*head == NULL) return -1;
    struct node* temporary = *head;
    struct node* previous = NULL;
    int currentIndex = 0;


    while (temporary != NULL && currentIndex < index) {
        previous = temporary;
        temporary = temporary->next;
        currentIndex++;
    }


    if (temporary == NULL) return -1;


    if (previous == NULL) {
        *head = (*head)->next;
    }
    else {
        previous->next = temporary->next;
    }

    delete temporary;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    
    return duration;
}

//funkcja zwracająca indeks zadanego elementu
int getIndex(struct node** head, int value) {
    auto start = chrono::high_resolution_clock::now();
    struct node* temporary = *head;
    int index = 0;

    auto duration = 0;

    while (temporary != NULL) {
        if (temporary->value == value) {

            auto end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<nanoseconds>(end - start).count();

            return duration;
        }
        temporary = temporary->next;
        index++;
    }

    return duration;
}


//funkcja do wyświetlania listy
void printList(struct node* head) {
    struct node* temporary = head;

    while (temporary != NULL) {
        cout << temporary->value << " -> ";
        temporary = temporary->next;
    }

}

int main() {
    struct node* head = nullptr; // inicjalizacja wskaźnika głowy listy
    struct node* current = nullptr; // wskaźnik do bieżącego węzła

    //tworzenie listy wiązanej z i-elementami
    int size = 5000;
    for (int i = 0; i < size; i++) {

        struct node* newNode = new node;
        newNode->value = i;
        newNode->next = nullptr;

        if (head == nullptr) {

            head = newNode;
        }
        else {
            current->next = newNode;
        }


        current = newNode;
    }

    int sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += addFirst(&head, 2115);
    }
    sum /= 50;
    cout << "Sredni czas dodawania elementu na poczatek listy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += addLast(&head, 2115);
    }
    sum /= 50;
    cout << "Sredni czas dodawania elementu na koniec listy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += addIndex(&head, 2115, (size/2));
    }
    sum /= 50;
    cout << "Sredni czas dodawania elementu na wybrany (srodkowy) indeks listy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += removeFirst(&head);
    }
    sum /= 50;
    cout << "Sredni czas usuwania elementu na poczatku listy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += removeLast(&head);
    }
    sum /= 50;
    cout << "Sredni czas usuwania elementu na koncu listy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += removeIndex(&head, (size/2));
    }
    sum /= 50;
    cout << "Sredni czas usuwania elementu na wybranym (srodkowym) indeksie listy: " << sum << " ns" << "\n" << endl;

    sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += getIndex(&head, (size/2));
    }
    sum /= 50;
    cout << "Sredni czas wyszukiwania elementu o wybranej wartosci w listy: " << sum << " ns" << "\n" << endl;

    struct node* temporary = head;
    while (temporary != nullptr) {
        struct node* nextNode = temporary->next;
        delete temporary;
        temporary = nextNode;
    }

    return 0;
}

