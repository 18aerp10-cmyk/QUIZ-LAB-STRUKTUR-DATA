# Quiz Lab 4 Struktur Data

## Identitas

- **Nama** : Adinda Egia Rehulina Pelawi
- **NIM** : 251401143
- **Program Studi** : Ilmu Komputer
- **Lab** : 4

## Deskripsi Program

### 1. Quiz No. 1 – Dynamic Array, Linked List, dan Searching

Program ini mengelola data mahasiswa (NIM, nama, dan nilai) dengan beberapa struktur data dan algoritma :

- **Dynamic Array** : Menyimpan nilai mahasiswa dengan ukuran sesuai jumlah data yang diinput.
- **Linked List** : Menyimpan data mahasiswa (NIM, nama, nilai) dan menampilkannya dalam daftar bernomor.
- **Insertion Sort** : Mengurutkan data nilai secara ascending (terkecil ke terbesar).
- **Linear Search** : Mencari data mahasiswa berdasarkan NIM.
- **Binary Search** : Mencari nilai pada array yang telah diurutkan.
- **Manajemen Memori** : Seluruh memori (array dan node) dibebaskan di akhir program.

### 2. Quiz No. 2 – Binary Search Tree, Queue, dan Stack

Program ini mensimulasikan sistem perpustakaan dengan tiga struktur data :

- **Binary Search Tree (BST)** : Menyimpan ID buku, menampilkan traversal Preorder, Inorder, dan Postorder, serta mencari ID buku.
- **Queue** : Mengelola antrean peminjaman buku mahasiswa dengan prinsip FIFO (First In, First Out).
- **Stack** : Menyimpan riwayat pengembalian buku dengan prinsip LIFO (Last In, First Out) menggunakan operasi push dan pop.
- **Validasi Input** : Fungsi `inputAngka` memastikan input berupa angka yang valid.

### 3. Quiz No. 3 – Graph, BFS, DFS, dan Dijkstra

Program ini mengimplementasikan Graph tidak berarah dan berbobot dengan 6 vertex (A sampai F) menggunakan Adjacency Matrix.

Fitur yang tersedia :

- **BFS (Breadth-First Search)** : Melakukan penelusuran graph secara melebar.
- **DFS (Depth-First Search)** : Melakukan penelusuran graph secara mendalam.
- **Dijkstra** : Menentukan jarak terpendek dan menampilkan rute dari vertex awal ke vertex tujuan.
- **Validasi Input** : Memastikan vertex yang dimasukkan sesuai dengan vertex yang tersedia, yaitu A sampai F.

### 4. Quiz No. 4 – Hash Table dengan Double Hashing

Program ini mengimplementasikan Hash Table berukuran 20 slot dengan metode Double Hashing untuk menangani collision (tabrakan data).

Fitur yang tersedia :

- **Insert** : Menambahkan data mahasiswa ke dalam hash table berdasarkan NIM dan nama.
- **Search** : Mencari data mahasiswa berdasarkan NIM.
- **Remove** : Menghapus data mahasiswa berdasarkan NIM dengan penanda DELETED (lazy deletion).
- **Display** : Menampilkan isi hash table beserta status setiap slot, yaitu EMPTY, DELETED, atau data mahasiswa.
- **Double Hashing** : Menggunakan dua fungsi hash, yaitu `key % 20` untuk posisi awal dan `19 - (key % 19)` sebagai langkah lompatan ketika terjadi collision.

## Struktur Folder

```
Quiz-Lab-Struktur-Data/
│
├── Quiz_No_1.cpp
├── Quiz_No_2.cpp
├── Quiz_No_3.cpp
├── Quiz_No_4.cpp
│
└── README.md
```

## Cara Menjalankan Program

Pastikan komputer sudah memiliki compiler C++, seperti GCC/G++ (MinGW).

1. Buka folder repository menggunakan Visual Studio Code atau terminal.
2. Buka terminal pada folder tersebut:
   ```
   cd Quiz-Lab-Struktur-Data
   ```
3. Compile program yang ingin dijalankan.
4. Jalankan program yang sudah berhasil di-compile.

### Compile

**Quiz No. 1**
```
g++ Quiz_No_1.cpp -o quiz1
```

**Quiz No. 2**
```
g++ Quiz_No_2.cpp -o quiz2
```

**Quiz No. 3**
```
g++ Quiz_No_3.cpp -o quiz3
```

**Quiz No. 4**
```
g++ Quiz_No_4.cpp -o quiz4
```

### Menjalankan Program

**Windows (PowerShell / terminal VS Code)**
```
.\quiz1
```

**Windows (Command Prompt)**
```
quiz1
```

**Linux / macOS**
```
./quiz1
```

Ganti `quiz1` dengan `quiz2`, `quiz3`, atau `quiz4` sesuai program yang ingin dijalankan.

## Video Penjelasan

Video berisi penjelasan alur kerja program serta demonstrasi contoh eksekusi masing-masing program.

Link YouTube : https://youtu.be/VZfH8x75e9k](https://youtu.be/-wIZH6Sf7B4?si=CHO65OMMSsbmwPAZ
