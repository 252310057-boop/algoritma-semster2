#include <iostream>
#include <iomanip> 
using namespace std;


class Elektronik {
protected:
    string merk, warna;
    double harga;
    int ram;

public:
    Elektronik(string m, double h, string w, int r) 
        : merk(m), harga(h), warna(w), ram(r) {}

    
    virtual void tampilInfo() {
        cout << fixed << setprecision(0);
        cout << "Merk  : " << merk << "\nHarga : Rp" << harga << endl;
    }

    
    void status() {
        cout << "Status: Perangkat " << merk << " berfungsi normal.\n";
    }
};


class TV : public Elektronik {
public:
    TV(string m, double h, string w, int r) : Elektronik(m, h, w, r) {}

    void tampilInfo() override {
        cout << fixed << setprecision(0);
        cout << "\n=== DATA TV ===" << endl;
        cout << "Merk  : " << merk << endl;
        cout << "Harga : Rp" << harga << endl;
        cout << "Warna : " << warna << endl;
        cout << "RAM   : " << ram << " GB" << endl;
    }
};


class HP : public Elektronik {
public:
    HP(string m, double h, string w, int r) : Elektronik(m, h, w, r) {}

    void tampilInfo() override {
        cout << fixed << setprecision(0);
        cout << "\n=== DATA HP ===" << endl;
        cout << "Merk  : " << merk << endl;
        cout << "Harga : Rp" << harga << endl;
        cout << "Warna : " << warna << endl;
        cout << "RAM   : " << ram << " GB" << endl;
    }
};

int main() {
    
    TV tvSatu("Samsung UHD", 4500000, "Hitam", 2);
    HP hpSatu("Xiaomi 13", 7000000, "Silver", 12);

    
    tvSatu.tampilInfo();
    tvSatu.status();

    
    hpSatu.tampilInfo();
    hpSatu.status();

    return 0;
}
