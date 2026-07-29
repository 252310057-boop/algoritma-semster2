#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur untuk menyimpan data inventori
struct InventoryItem {
    int key;
    string name;
    bool isOccupied = false;
};

// Fungsi untuk mengecek apakah sebuah angka adalah bilangan prima
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Fungsi untuk mencari bilangan prima atas
int getNextPrime(int n) {
    int prime = n + 1;
    while (!isPrime(prime)) {
        prime++;
    }
    return prime;
}

int main() {
    int inputSize;
    cout << "Masukkan jumlah data: ";
    cin >> inputSize;

    // Menentukan ukuran tabel dengan bilangan prima atas
    int hdt_boundary = getNextPrime(inputSize);
    cout << "Jumlah data telah diatur ulang menjadi " << hdt_boundary << " dengan prima atas." << endl << endl;

    vector<InventoryItem> table(hdt_boundary);
    int choice;

    do {
        cout << "- Inventori Manajemen Sederhana -" << endl;
        cout << "(1) Insert Item" << endl;
        cout << "(2) Hapus Item" << endl;
        cout << "(3) Lihat Item" << endl;
        cout << "(0) Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int key;
            cout << "Masukkan item yang ingin disimpan: ";
            cin.ignore();
            getline(cin, name);
            cout << "Masukkan key (berupa angka) untuk hash: ";
            cin >> key;

            int i = 0;
            bool inserted = false;

            while (!inserted && i < hdt_boundary) {
                int hashIndex = (key + i) % hdt_boundary;
                if (!table[hashIndex].isOccupied) {
                    table[hashIndex].key = key;
                    table[hashIndex].name = name;
                    table[hashIndex].isOccupied = true;
                    inserted = true;
                    cout << "Data di insert dengan i: " << i << endl;
                    cout << "Item berhasil disimpan." << endl;
                } else {
                    i++;
                }
            }

            if (!inserted) {
                cout << "Tabel hash sudah penuh!" << endl;
            }
            cout << endl;

        } else if (choice == 2) {
            int key;
            cout << "Masukkan key (berupa angka) untuk menghapus item: ";
            cin >> key;

            bool found = false;
            for (int i = 0; i < hdt_boundary; i++) {
                int hashIndex = (key + i) % hdt_boundary;
                if (table[hashIndex].isOccupied && table[hashIndex].key == key) {
                    table[hashIndex].isOccupied = false;
                    cout << "Item dengan key " << key << " berhasil dihapus." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item dengan key tersebut tidak ditemukan." << endl;
            }
            cout << endl;

        } else if (choice == 3) {
            int key, i;
            cout << "Masukkan key (berupa angka) untuk hash melihat item: ";
            cin >> key;
            cout << "Masukkan iterator (i) untuk melihat item: ";
            cin >> i;

            int hashIndex = (key + i) % hdt_boundary;
            if (table[hashIndex].isOccupied && table[hashIndex].key == key) {
                cout << "Item dengan key = " << key << " dan i = " << i << ": " << table[hashIndex].name << endl;
            } else {
                cout << "Item tidak ditemukan pada posisi tersebut." << endl;
            }
            cout << endl;
        }

    } while (choice != 0);

    cout << "Terima kasih telah menggunakan sistem inventori!" << endl;
    return 0;
}
