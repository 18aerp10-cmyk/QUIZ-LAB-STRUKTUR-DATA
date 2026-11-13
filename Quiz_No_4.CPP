
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 20;

struct DataMahasiswa {
    int nim;
    string nama;
};

class HashTable {
    private:
        vector<DataMahasiswa> table;
        vector<int> status;

        int hash1(int key) {
            return key % 20;
        }

        int hash2(int key) {
            return 19 - (key % 19);
        }

    public:
        HashTable() {
            table.resize(TABLE_SIZE);
            status.resize(TABLE_SIZE, 0);
        }

        void insert(int key, string value) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            int deletedIndex = -1;

            while (true) {
                if (status[index] == 1 && table[index].nim == key) {
                    table[index].nama = value;
                    return;
                }

                if (status[index] == 2 && deletedIndex == -1) {
                    deletedIndex = index;
                }

                if (status[index] == 0) {
                    if (deletedIndex != -1) {
                        index = deletedIndex;
                    }

                    table[index].nim = key;
                    table[index].nama = value;
                    status[index] = 1;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            if (deletedIndex != -1) {
                table[deletedIndex].nim = key;
                table[deletedIndex].nama = value;
                status[deletedIndex] = 1;
            } else {
                cout << "Tabel penuh" << endl;
            }
        }

        void search(int key) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            while (status[index] != 0) {
                if (status[index] == 1 && table[index].nim == key) {
                    cout << "Data ditemukan : "
                         << table[index].nama << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            cout << "Data tidak ditemukan" << endl;
        }

        void remove(int key) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            while (status[index] != 0) {
                if (status[index] == 1 && table[index].nim == key) {
                    status[index] = 2;
                    cout << "Data berhasil dihapus" << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            cout << "Data tidak ditemukan" << endl;
        }

        void display() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << " : ";

                if (status[i] == 1) {
                    cout << table[i].nim << " - "
                         << table[i].nama;
                } else if (status[i] == 2) {
                    cout << "DELETED";
                } else {
                    cout << "EMPTY";
                }

                cout << endl;
            }
        }
};

int main() {
    HashTable ht;

    ht.insert(240710001, "Andi");
    ht.insert(240710002, "Budi");
    ht.insert(240710003, "Citra");
    ht.insert(240710004, "Dewi");
    ht.insert(240710005, "Eka");
    ht.insert(240710006, "Fajar");
    ht.insert(240710007, "Gita");
    ht.insert(240710008, "Hana");
    ht.insert(240710009, "Indra");
    ht.insert(240710010, "Joko");
    ht.insert(240710021, "Kiki");
    ht.insert(240710041, "Lina");
    ht.insert(240710061, "Maya");
    ht.insert(240710081, "Nanda");
    ht.insert(240710101, "Oscar");

    cout << "Isi hash table :" << endl;
    ht.display();

    int nim;

    cout << "\nMasukkan NIM yang ingin dicari : ";
    cin >> nim;
    ht.search(nim);

    cout << "\nMasukkan NIM yang ingin dihapus : ";
    cin >> nim;
    ht.remove(nim);

    cout << "\nMasukkan NIM yang ingin dicari kembali : ";
    cin >> nim;
    ht.search(nim);

    cout << "\nIsi hash table setelah penghapusan :" << endl;
    ht.display();

    return 0;
}