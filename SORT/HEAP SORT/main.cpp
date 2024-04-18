#include <iostream>
using namespace std;

void heapify(int mas[], int n, int i){

    int maxi = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && mas[l] > mas[maxi])
        maxi = l;

    if (r < n && mas[r] > mas[maxi])
        maxi = r;

    if (maxi != i){
        swap(mas[i], mas[maxi]);
        heapify(mas, n, maxi);
    }
}

void hSort(int mas[], int n){

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(mas, n, i);

    for (int i = n - 1; i > 0; i--){
        swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    int mas[n];
    for (int i = 0; i < n; i++){cin >> mas[i];}

    hSort(mas, n);

    for (int i = 0; i < n; i++){cout << mas[i] << " ";}

    return 0;
}
