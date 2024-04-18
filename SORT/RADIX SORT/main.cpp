#include <iostream>
#include <string>
using namespace std;

void Sort(string mes[], int kmes, int dmes, int kb) {

    const int al = 256;
    string tmp[kmes];

    for (int d = dmes - 1; d >= dmes - kb; d--) {

        int count[al] = {0};

        for (int i = 0; i < kmes; i++) {
            int bukv = (int)(mes[i][d]) + 1;
            count[bukv]++;
        }

        int itog = 0;

        for (int j = 0; j < al; j++) {
            int tmpc = count[j];
            count[j] = itog;
            itog += tmpc;
        }

        for (int a = 0; a < kmes; a++) {
            int bukv = (int)(mes[a][d]) + 1;
            tmp[count[bukv]++] = mes[a];
        }

        for (int i = 0; i < kmes; i++) {
            mes[i] = tmp[i];
        }
    }
}

int main() {

    int kmes, dmes, kb;
    cin >> kmes >> dmes >> kb;

    string mes[kmes];

    for (int i = 0; i < kmes; i++) {
        cin >> mes[i];
    }

    Sort(mes, kmes, dmes, kb);

    for (int i = 0; i < kmes; i++) {
        cout << mes[i] << "\n";
    }
}