#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define MAX 10

class Queue {
private:
    int front, rear, count;
    string arr[MAX];

public:

    Queue() {
        front = 0;
        rear = MAX - 1;
        count = 0;
    }

    bool isFull() {
        return count == MAX;
    }
    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void enqueue(string x) {
        if (isFull()) {
            cout << ">> Maaf, Antrian penuh. Kapasitas loket sudah maksimal." << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        count++;
        cout << ">> Tiket " << x << " berhasil masuk ke dalam antrian." << endl;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << ">> Antrian kosong. Tidak ada pengunjung yang dipanggil." << endl;
            return "";
        }
        string x = arr[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }

    string peek() {
        if (isEmpty()) {
            cout << ">> Antrian kosong." << endl;
            return "";
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << ">> Antrian sedang kosong." << endl;
            return;
        }
        cout << ">> Daftar Pengunjung yang Menunggu:" << endl;
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << "   " << (j + 1) << ". " << arr[i] << endl;
            i = (i + 1) % MAX;
        }
    }
};

int main() {
    Queue q;
    int pilihan;
    int nomorUrut = 1;

    do {
        cout << "\n====================================================" << endl;
        cout << "      SISTEM ANTRIAN LOKET LAYANAN PUBLIK         " << endl;
        cout << "====================================================" << endl;
        cout << "1. Ambil Nomor Antrian (Enqueue)" << endl;
        cout << "2. Panggil Pengunjung (Dequeue)" << endl;
        cout << "3. Lihat Antrian Selanjutnya (Peek)" << endl;
        cout << "4. Tampilkan Semua Antrian (Display)" << endl;
        cout << "5. Cek Jumlah Antrian (Size)" << endl;
        cout << "6. Keluar Program" << endl;
        cout << "====================================================" << endl;
        cout << "Pilih Menu (1-6): ";
        cin >> pilihan;

        char buffer[10];
        sprintf(buffer, "A%03d", nomorUrut); 
        string idTiket = buffer;

        switch (pilihan) {
            case 1:
                if (!q.isFull()) {
                    q.enqueue(idTiket);
                    nomorUrut++;
                } else {
                    q.enqueue(idTiket);
                }
                break;
            case 2:
                {
                    string called = q.dequeue();
                    if (called != "") {
                        cout << ">> Petugas memanggil nomor antrian: [ " << called << " ]. Silakan menuju loket." << endl;
                    }
                }
                break;
            case 3:
                {
                    string next = q.peek();
                    if (next != "") {
                        cout << ">> Nomor antrian yang akan dipanggil selanjutnya: [ " << next << " ]" << endl;
                    }
                }
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << ">> Jumlah pengunjung dalam antrian saat ini: " << q.size() << " orang." << endl;
                if(q.isFull()) cout << ">> Status: Antrian PENUH!" << endl;
                else if(q.isEmpty()) cout << ">> Status: Antrian KOSONG!" << endl;
                break;
            case 6:
                cout << ">> Terima kasih. " << endl;
                break;
            default:
                cout << ">> Pilihan tidak Tersedia. " << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}
