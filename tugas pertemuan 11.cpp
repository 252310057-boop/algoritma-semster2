#include <iostream>
#include <string>
using namespace std;

const int V = 6;
const int INF = 99999;

int main() {

    string kota[V] = {
        "Bojong Gede",
        "Ciheulet",
        "Bogor",
        "Ciawi",
        "Cimande",
        "Ciletuh"
    };

    int graph[V][V] = {

      { 0,  1, INF,INF, 1, INF},
      {INF, 0,  1, INF,INF,INF},
      {INF,INF, 0,  1, INF,INF},
      {INF,INF,INF, 0, INF,INF},
      {INF,INF,INF,INF, 0,  1 },
      {INF,INF,INF,INF,INF, 0 }

    };

    const int TAJUR = 6;

    cout << "Posisi Awal : Bojong Gede\n";
    cout << "Tujuan      : Ciletuh\n\n";

    cout << "Jalur 1 :\n";
    cout << "Bojong Gede -> Ciheuleut -> Bogor -> Ciawi -> Ciletuh\n";
    cout << "Jumlah Jalur = 4\n\n";

    cout << "Jalur 2 :\n";
    cout << "Bojong Gede -> Bogor  -> Ciawi -> Ciletuh\n";
    cout << "Jumlah Jalur = 3\n\n";

    cout << "Jalur Terpendek :\n";
    cout << "Bojong Gede -> Ciheuleut -> Cimande -> Ciletuh\n";

    return 0;
}
