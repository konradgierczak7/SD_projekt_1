#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

struct node {
	int data;
	node *next;
};

node *head = NULL;

void dodajNaPoczatekListy(int data) {
	node *newNode = new node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void dodajNaKoniecListy(int data) {
	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return;
	}

	node *last = head;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newNode;
}

void dodajNaWybranyIndeksListy(int position, int data) {
	if (position < 0) {
		cout << "Wybrany indeks jest nieprawidlowy." << endl;
		return;
	}

	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (position == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}

	node *current = head;
	for (int i = 0; current != NULL && i < position - 1; i++) {
		current = current->next;
	}

	if (current == NULL) {
		cout << "Poprzedni wezel ma wartosc NULL." << endl;
		delete newNode;
		return;
	}

	newNode->next = current->next;
	current->next = newNode;
}

void usunNaPoczatkuListy() {
	if (head == NULL) return;
	node *temp = head;
	head = head->next;
	delete temp;
}

void usunNaKoncuListy() {
	if (head == NULL) return;

	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}

	node *secondLast = head;
	while (secondLast->next->next != NULL) {
		secondLast = secondLast->next;
	}

	delete secondLast->next;
	secondLast->next = NULL;
}

void usunNaWybranymIndeksieListy(int key) {
	node *current = head;
	node *prev = NULL;

	if (current != NULL && current->data == key) {
		head = current->next;
		delete current;
		return;
	}

	while (current != NULL && current->data != key) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) return;

	prev->next = current->next;
	delete current;
}

void wyszukiwanieZadanegoElementuListy(int key) {
	node *current = head;
	while (current != NULL) {
		if (current->data == key) {
			cout << "Zadany element " << key << " zostal znaleziony na indeksie numer: " << (key - 1) << endl;
			return;
		}
		current = current->next;
	}
	cout << "Zadany element " << key << " nie zostal znaleziony." << endl;
}

void wypiszListe() {
	node* current = head;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void usunListe() {
	node* current = head;
	node* nextNode;
	while (current != NULL) {
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = NULL;
}

void listaWiazana() {
	int wybor;
	int wartosc;
	int indeks;

	for (int i = 1; i <= 10; ++i) {
		dodajNaKoniecListy(i);
	}

	while (true) {
		cout << "\n";
		cout << "Menu:\n";
		cout << "1. Dodaj na poczatek\n";
		cout << "2. Dodaj na koniec\n";
		cout << "3. Dodaj na wybrany indeks\n";
		cout << "4. Usun z poczatku\n";
		cout << "5. Usun z konca\n";
		cout << "6. Usun wybrana wartosc\n";
		cout << "7. Wyszukiwanie zadanego elementu\n";
		cout << "8. Wypisz liste\n";
		cout << "9. Usun liste\n";
		cout << "10. Zamknij program\n";
		cout << "Wybierz funckje: ";
		cin >> wybor;

		switch (wybor) {
		case 1:
			cout << "Wprowadz wartosc: ";
			cin >> wartosc;
			dodajNaPoczatekListy(wartosc);
			wypiszListe();
			break;
		case 2:
			cout << "Wprowadz wartosc: ";
			cin >> wartosc;
			dodajNaKoniecListy(wartosc);
			wypiszListe();
			break;
		case 3:
			cout << "Wprowadz indeks oraz wartosc: ";
			cin >> indeks >> wartosc;
			dodajNaWybranyIndeksListy(indeks, wartosc);
			wypiszListe();
			break;
		case 4:
			usunNaPoczatkuListy();
			wypiszListe();
			break;
		case 5:
			usunNaKoncuListy();
			wypiszListe();
			break;
		case 6:
			cout << "Wprowadz wartosc, ktora ma zostac usunieta: ";
			cin >> wartosc;
			usunNaWybranymIndeksieListy(wartosc);
			wypiszListe();
			break;
		case 7:
			cout << "Wprowadz wartosc do wyszukiwania: ";
			cin >> wartosc;
			wyszukiwanieZadanegoElementuListy(wartosc);
			break;
		case 8:
			wypiszListe();
			break;
		case 9:
			usunListe();
			cout << "Lista zostala usunieta." << endl;
			break;
		case 10:
			exit(0);
		default:
			cout << "Niepoprawny wybor." << endl;
		}
	}
}

void dodajNaPoczatekTablicy(int*& tablica, int& rozmiar, int& pojemnosc, int wartosc) {
	if (rozmiar == pojemnosc) {
		pojemnosc = pojemnosc == 0 ? 1 : pojemnosc * 2;
		int* nowaTablica = new int[pojemnosc];
		for (int i = 0; i < rozmiar; i++) {
			nowaTablica[i + 1] = tablica[i];
		}
		delete[] tablica;
		tablica = nowaTablica;
	}
	else {
		for (int i = rozmiar; i > 0; i--) {
			tablica[i] = tablica[i - 1];
		}
	}
	tablica[0] = wartosc;
	rozmiar++;
}


void dodajNaKoniecTablicy(int*& tablica, int& rozmiar, int& pojemnosc, int wartosc) {
	if (rozmiar == pojemnosc) {
		pojemnosc = pojemnosc == 0 ? 1 : pojemnosc * 2;
		int* nowaTablica = new int[pojemnosc];
		for (int i = 0; i < rozmiar; i++) {
			nowaTablica[i] = tablica[i];
		}
		delete[] tablica;
		tablica = nowaTablica;
	}
	tablica[rozmiar + 1] = wartosc;
}


void dodajNaWybranyIndeksTablicy(int*& tablica, int& rozmiar, int& pojemnosc, int indeks, int wartosc) {
	if (indeks < 0 || indeks > rozmiar) {
		cout << "Niepoprawny indeks." << endl;
		return;
	}

	if (rozmiar == pojemnosc) {
		pojemnosc = pojemnosc == 0 ? 1 : pojemnosc * 2;
		int* nowaTablica = new int[pojemnosc];
		for (int i = 0; i < indeks; i++) {
			nowaTablica[i] = tablica[i];
		}
		nowaTablica[indeks] = wartosc;
		for (int i = indeks; i < rozmiar; i++) {
			nowaTablica[i + 1] = tablica[i];
		}
		delete[] tablica;
		tablica = nowaTablica;
	}
	else {
		for (int i = rozmiar; i > indeks; i--) {
			tablica[i] = tablica[i - 1];
		}
		tablica[indeks] = wartosc;
	}
	rozmiar++;
}

void usunZPoczatkuTablicy(int*& tablica, int& rozmiar) {
	if (rozmiar == 0) return;
	int* nowaTablica = new int[rozmiar - 1];
	for (int i = 1; i < rozmiar; i++) {
		nowaTablica[i - 1] = tablica[i];
	}
	delete[] tablica;
	tablica = nowaTablica;
	rozmiar--;
}

void usunZKoncaTablicy(int*& tablica, int& rozmiar) {
	if (rozmiar == 0) return;
	int* nowaTablica = new int[rozmiar - 1];
	for (int i = 0; i < rozmiar - 1; i++) {
		nowaTablica[i] = tablica[i];
	}
	delete[] tablica;
	tablica = nowaTablica;
	rozmiar--;
}

void usunZWybranegoIndeksuTablicy(int*& tablica, int& rozmiar, int indeks) {
	if (indeks < 0 || indeks >= rozmiar) {
		cout << "Niepoprawny indeks." << endl;
		return;
	}
	int* nowaTablica = new int[rozmiar - 1];
	for (int i = 0; i < indeks; i++) {
		nowaTablica[i] = tablica[i];
	}
	for (int i = indeks + 1; i < rozmiar; i++) {
		nowaTablica[i - 1] = tablica[i];
	}
	delete[] tablica;
	tablica = nowaTablica;
	rozmiar--;
}

void wyszukiwanieZadanejWartosciTablicy(int* tablica, int rozmiar, int wartosc) {
	for (int i = 0; i < rozmiar; i++) {
		if (tablica[i] == wartosc) {
			cout << "Zadana wartosc " << wartosc << " zostala znaleziona indeksie numer: " << i << endl;
			return;
		}
	}
	cout << "Zadana wartosc " << wartosc << " nie zostala znaleziona." << endl;
}

void wyswietlTablice(int* tablica, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		cout << tablica[i] << " ";
	}
	cout << endl;
}

void tablicaDynamiczna() {
	int rozmiar = 0;
	int pojemnosc = 0;
	int* tablica = nullptr;

	int wybor, wartosc, indeks;

	for (int i = 1; i <= 10; ++i) {
		dodajNaKoniecTablicy(tablica, rozmiar, pojemnosc, i);
	}

	while (true) {
		cout << "\n";
		cout << "Menu:\n";
		cout << "1. Dodaj na poczatek\n";
		cout << "2. Dodaj na koniec\n";
		cout << "3. Dodaj na wybrany indeks\n";
		cout << "4. Usun z poczatku\n";
		cout << "5. Usun z konca\n";
		cout << "6. Usun z wybranego indeksu\n";
		cout << "7. Wypisz tablice\n";
		cout << "8. Wyszukaj wartosc\n";
		cout << "9. Usun cala tablice\n";
		cout << "10. Zakoncz program\n";
		cout << "Wybierz funkcje: ";
		cin >> wybor;

		switch (wybor) {
		case 1:
			cout << "Wprowadz wartosc: ";
			cin >> wartosc;
			dodajNaPoczatekTablicy(tablica, rozmiar, pojemnosc, wartosc);
			wyswietlTablice(tablica, rozmiar);
			break;
		case 2:
			cout << "Wprowadz wartosc: ";
			cin >> wartosc;
			dodajNaKoniecTablicy(tablica, rozmiar, pojemnosc, wartosc);
			wyswietlTablice(tablica, rozmiar);
			break;
		case 3:
			cout << "Wprowadz indeks oraz wartosc: ";
			cin >> indeks >> wartosc;
			dodajNaWybranyIndeksTablicy(tablica, rozmiar, pojemnosc, indeks, wartosc);
			wyswietlTablice(tablica, rozmiar);
			break;
		case 4:
			usunZPoczatkuTablicy(tablica, rozmiar);
			wyswietlTablice(tablica, rozmiar);
			break;
		case 5:
			usunZKoncaTablicy(tablica, rozmiar);
			wyswietlTablice(tablica, rozmiar);
			break;
		case 6:
			cout << "Wprowadz indeks: ";
			cin >> indeks;
			usunZWybranegoIndeksuTablicy(tablica, rozmiar, indeks);
			wyswietlTablice(tablica, rozmiar);
			break;
		case 7:
			cout << "Zawartosc tablicy: ";
			wyswietlTablice(tablica, rozmiar);
			break;
		case 8:
			cout << "Wprowadz wartosc do wyszukania: ";
			cin >> wartosc;
			wyszukiwanieZadanejWartosciTablicy(tablica, rozmiar, wartosc);
			break;
		case 9:
			delete[] tablica;
			tablica = nullptr;
			rozmiar = 0;
			pojemnosc = 0;
			cout << "Tablica zostala usunieta." << endl;
			break;
		case 10:
			delete[] tablica;
			exit(0);
		default:
			cout << "Niepoprawny wybor." << endl;
		}
	}
}

int main()
{
	int wyborStruktury;
	cout << "Wybierz strukture danych:\n";
	cout << "1. Lista wiazana\n";
	cout << "2. Tablica dynamiczna\n";
	cout << "Wybor struktury: ";
	cin >> wyborStruktury;
	switch (wyborStruktury) {
		case 1:
			listaWiazana();
			break;
		case 2:
			tablicaDynamiczna();
			break;
	}
}

