#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nim;
    string nama;
    int nilai;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertLast(string nim, string nama, int nilai) {
    Node* newNode = new Node;
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void tampilData() {
    Node* temp = head;
    int no = 1;

    while (temp != NULL) {
        cout << no << ". " << temp->nim << " | " << temp->nama << " | " << temp->nilai << endl;
        temp = temp->next;
        no++;
    }
}

void insertionSort(int data[], int n) {
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

Node* linearSearch(string nim) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->nim == nim) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int binarySearch(int data[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

void deleteAll() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    int* nilai = new int[n];

    for (int i = 0; i < n; i++) {
        string nim, nama;
        int nilaiMhs;

        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NIM   : ";
        cin >> nim;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Nilai : ";
        cin >> nilaiMhs;

        insertLast(nim, nama, nilaiMhs);
        nilai[i] = nilaiMhs;
    }

    cout << "\nData mahasiswa :" << endl;
    tampilData();

    insertionSort(nilai, n);

    cout << "\nNilai setelah diurutkan (terkecil - terbesar) : ";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl;

    string cariNim;
    cout << "\nMasukkan NIM yang dicari : ";
    cin >> cariNim;

    Node* hasilNim = linearSearch(cariNim);

    if (hasilNim != NULL) {
        cout << "Data ditemukan : " << hasilNim->nim << " | " << hasilNim->nama << " | " << hasilNim->nilai << endl;
    } else {
        cout << "Data dengan NIM " << cariNim << " tidak ditemukan" << endl;
    }

    int target;
    cout << "\nMasukkan nilai yang dicari : ";
    cin >> target;

    int hasil = binarySearch(nilai, n, target);

    if (hasil != -1) {
        cout << "Nilai " << target << " ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Nilai " << target << " tidak ditemukan" << endl;
    }

    delete[] nilai;
    deleteAll();

    return 0;
}