#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

void tambah(Node*& root, int angka) {
    if (root == nullptr) {
        root = new Node();
        root->data = angka;
        root->kiri = nullptr;
        root->kanan = nullptr;
        return;
    }

    if (angka < root->data) {
        tambah(root->kiri, angka);
    } else {
        tambah(root->kanan, angka);
    }
}

int cari(Node* root, int angka) {
    if (root == nullptr) {
        return -1;
    }

    if (root->data == angka) {
        return root->data;
    } else if (angka < root->data) {
        return cari(root->kiri, angka);
    } else {
        return cari(root->kanan, angka);
    }
}

void hapusBST(Node* root) {
    if (root != nullptr) {
        hapusBST(root->kiri);
        hapusBST(root->kanan);
        delete root;
    }
}

struct NodeAntrean {
    string nama;
    NodeAntrean* next;
};

void enqueue(NodeAntrean*& front, NodeAntrean*& rear, string nama) {
    NodeAntrean* nodeBaru = new NodeAntrean();

    nodeBaru->nama = nama;
    nodeBaru->next = nullptr;

    if (front == nullptr) {
        front = nodeBaru;
        rear = nodeBaru;
    } else {
        rear->next = nodeBaru;
        rear = nodeBaru;
    }
}

void dequeue(NodeAntrean*& front, NodeAntrean*& rear) {
    if (front == nullptr) {
        cout << "Antrean kosong!" << endl;
        return;
    }

    NodeAntrean* hapus = front;
    cout << "Dilayani : " << front->nama << endl;

    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }

    delete hapus;
}

void tampilAntrean(NodeAntrean* front) {
    if (front == nullptr) {
        cout << "Antrean kosong";
        return;
    }
    while (front != nullptr) {
        cout << front->nama << " | ";
        front = front->next;
    }
}

void hapusAntrean(NodeAntrean*& front, NodeAntrean*& rear) {
    while (front != nullptr) {
        NodeAntrean* hapus = front;
        front = front->next;
        delete hapus;
    }
    rear = nullptr;
}

struct NodeStack {
    int idBuku;
    NodeStack* next;
};

void push(NodeStack*& top, int id) {
    NodeStack* nodeBaru = new NodeStack();

    nodeBaru->idBuku = id;
    nodeBaru->next = top;

    top = nodeBaru;
}

void pop(NodeStack*& top) {
    if (top == nullptr) {
        cout << "Riwayat kosong!" << endl;
        return;
    }
    NodeStack* hapus = top;
    cout << "Pop : " << top->idBuku << endl;

    top = top->next;
    delete hapus;
}

void tampilStack(NodeStack* top) {
    if (top == nullptr) {
        cout << "Riwayat kosong";
        return;
    }
    while (top != nullptr) {
        cout << top->idBuku << " ";
        top = top->next;
    }
}

void hapusStack(NodeStack*& top) {
    while (top != nullptr) {
        NodeStack* hapus = top;
        top = top->next;
        delete hapus;
    }
}

int inputAngka(string pesan, int minimal) {
    int angka;

    while (true) {
        cout << pesan;

        if (cin >> angka && angka >= minimal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return angka;
        }
        cout << "Input tidak valid! Masukkan angka minimal "
             << minimal << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    Node* root = nullptr;
    int angka;

    cout << "\n===== ID BUKU =====" << endl; 
    cout << "Masukkan ID buku (0 untuk berhenti)" << endl;

    while (true) {
        angka = inputAngka("ID buku : ", 0);
        if (angka == 0) {
            break;
        }
        tambah(root, angka);
    }

    cout << "\nPre Order : ";
    preOrder(root);

    cout << "\nIn Order : ";
    inOrder(root);

    cout << "\nPost Order : ";
    postOrder(root);

    cout << endl;

    int cariId = inputAngka(
        "\nMasukkan ID buku yang dicari : ", 1
    );

    int hasilCari = cari(root, cariId);

    if (hasilCari != -1) {
        cout << "Buku ditemukan!" << endl;
    } else {
        cout << "Buku tidak ditemukan!" << endl;
    }

    cout << "\n===== ANTREAN PEMINJAMAN =====" << endl;

    NodeAntrean* front = nullptr;
    NodeAntrean* rear = nullptr;

    int jumlahAntrean = inputAngka(
        "Berapa mahasiswa yang antre : ", 0
    );

    for (int i = 1; i <= jumlahAntrean; i++) {
        string nama;

        cout << "Nama mahasiswa ke-" << i << " : ";
        getline(cin, nama);
        while (nama.empty()) {
            cout << "Nama tidak boleh kosong. Masukkan lagi : ";
            getline(cin, nama);
        }
        enqueue(front, rear, nama);
    }

    cout << "\nIsi antrean : ";
    tampilAntrean(front);
    cout << endl;

    cout << "\n===== PEMINJAMAN BUKU =====" << endl;

    while (front != nullptr) {
        dequeue(front, rear);

        cout << "Sisa antrean : ";
        tampilAntrean(front);
        cout << endl;
    }

    cout << "\n===== RIWAYAT PENGEMBALIAN =====" << endl;

    NodeStack* top = nullptr;

    int jumlahKembali = inputAngka(
        "Berapa buku yang dikembalikan : ", 0
    );

    for (int i = 1; i <= jumlahKembali; i++) {
        int idKembali = inputAngka(
            "ID buku yang dikembalikan ke-" + to_string(i) + " : ",
            1
        );
        push(top, idKembali);
    }

    cout << "\nRiwayat pengembalian : ";
    tampilStack(top);
    cout << endl;

    cout << "\n===== PROSES POP =====" << endl;

    pop(top);

    cout << "Riwayat setelah pop : ";
    tampilStack(top);
    cout << endl;

    hapusBST(root);
    hapusAntrean(front, rear);
    hapusStack(top);

    cout << "\nProgram selesai. Semua memori telah dibersihkan."
         << endl;

    return 0;
}
