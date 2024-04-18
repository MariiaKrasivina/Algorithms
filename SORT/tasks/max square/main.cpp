#include <iostream>
using namespace std;

void quicksort(long v[], long l, long r){
    if (l > r)
        return;
    long mid;
    if ((v[l] >= v[r] && v[l] <= v[(l + r)/2]) || (v[l] <= v[r] && v[l] >= v[(l + r)/2]))
        mid = v[l];
    if ((v[r] >= v[l] && v[r] <= v[(l+r)/2]) || (v[r] <= v[l] && v[r] >= v[(l+r)/2]))
        mid = v[r];
    if ((v[(l+r)/2] >= v[r] && v[(l+r)/2] <= v[l]) || (v[(l+r)/2] <= v[r] && v[(l+r)/2] >= v[l]))
        mid = v[(l + r)/2];
    long i = l, j = r;
    while (i <= j) {
        while (v[i] > mid)
            i++;
        while (v[j] < mid)
            j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(v, l, j);
    if (r > i)
        quicksort(v, i, r);
}

int main() {
    long n;
    cin >> n;

    long v[n];
    for (long i = 0; i < n; i++)
        cin >> v[i];

    quicksort (v, 0, n - 1);

    long sum = 0, i = 1, ps = 0, vs = 0;

    if (n > 3 && n <= 1000000) {
        while (i <= n){
            if ((v[i - 1] == v[i]) || (v[i - 1] - 1 == v[i])){
                if (ps == 0) {
                    ps = v[i];
                }
                else{
                    vs = v[i];
                    sum += ps * vs;
                    ps = 0;
                    vs = 0;
                }
                i+=2;
            }
            else
                i++;
        }
    }

    cout << sum;

    return 0;
}

