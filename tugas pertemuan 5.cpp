#include <iostream>
using namespace std;

// Membuat class bernama contoh
class contoh {
private:
    int nilai; // variabel private (tidak bisa diakses langsung dari luar)

public:
    // Constructor
    // Fungsi ini otomatis dipanggil saat objek dibuat
    contoh(int n) {
        nilai = n; // mengisi nilai dari parameter ke variabel
    }

    // Fungsi getter untuk mengambil nilai
    int getNum() {
        return nilai;
    }
};

int main() {
    // Membuat objek dengan nilai 10
    // Constructor otomatis dijalankan di sini
    contoh obj(10);

    // Menampilkan nilai
    cout << "nilai yang diinput: " << obj.getNum() << endl;

    return 0;
}
