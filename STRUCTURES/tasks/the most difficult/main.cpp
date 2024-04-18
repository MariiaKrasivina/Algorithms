#include <iostream>
using namespace std;

struct EasyDigits{
    long long val;
    long long stepen;
    long long original;
};

void siftdown(EasyDigits res[], long long n, long long i){
    while (2*i + 1 < n){
        long long l = 2*i + 1;
        long long r = 2*i + 2;
        long long j = l;

        if (r < n && res[r].val < res[l].val)
            j = r;

        if (res[i].val <= res[j].val)
            break;

        swap(res[i], res[j]);
        i = j;
    }
}


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    cin >> n;

    EasyDigits respch[n];
    long long cnt = 0;
    const long long sizemas = n * 15;
    long long mas[sizemas];
    for (long long i = 0; i < sizemas; i++) { mas[i] = i; }

    mas[1] = 0;
    long long i = 2;

    while (cnt != n) {
        if (mas[i] != 0) {
            respch[cnt].val = mas[i];
            respch[cnt].original = mas[i];
            respch[cnt].stepen = 1;
            cnt++;
            long long j = i + i;
            while (j < sizemas) {
                mas[j] = 0;
                j += i;
            }
        }
        i++;
    }

    cnt = 0;
    long long kelem = 0;
    EasyDigits tmpitog[n];

    while (cnt != n) {
        tmpitog[cnt] = respch[0];
        kelem += respch[0].stepen;
        respch[0].val = respch[0].val * respch[0].val;
        respch[0].stepen = respch[0].stepen + respch[0].stepen;
        siftdown(respch, n, 0);
        cnt++;
    }

    long long itog[kelem];
    cnt = 0;
    for (long long s = 0; s < kelem; s++){
        while (tmpitog[s].stepen > 0){
            itog[cnt] = tmpitog[s].original;
            cnt++;
            tmpitog[s].stepen--;
        }
    }

    for (long long j = 1; j < kelem; j++) {
        long long key = itog[j];
        long long d = j - 1;
        while (d >= 0 && itog[d] > key) {
            itog[d + 1] = itog[d];
            d--;
        }
        itog[d + 1] = key;
    }

    cout << kelem << "\n";

    for (long long u = 0; u < kelem; u++) {
        cout << itog[u] << " ";
    }


    return 0;
}
