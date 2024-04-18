#include <iostream>
using namespace std;

bool rasadka(const int st[], int km, int kb, int mid) {

    int cnt = 1;
    int booked = st[0];

    for (int i = 1; i < km; i++) {
        if (st[i] - booked >= mid) {
            cnt++;
            booked = st[i];
        }
    }
    return cnt >= kb;

}

int binpoisk(int st[], int km, int kb) {

    int l = 0;
    int r = st[km - 1] - st[0] + 1;
    int itog;

    while (r - l != 1) {
        int mid = l + (r - l) / 2;
        if (rasadka(st, km, kb, mid)){
            l = mid;
            itog = mid;
        }
        else
            r = mid;
    }
    return itog;
}

int main() {

    int km, kb;
    cin >> km >> kb;
    int st[km];

    for (int i = 0; i < km; i++) { cin >> st[i]; }

    int itog = binpoisk(st, km, kb);

    cout << itog;

    return 0;
}
