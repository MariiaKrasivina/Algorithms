#include <iostream>
using namespace std;

void quicksort(int mas[], int l, int r){
    if (l > r)
        return;
    int mid;
    if ((mas[l] >= mas[r] && mas[l] <= mas[(l + r)/2]) || (mas[l] <= mas[r] && mas[l] >= mas[(l + r)/2]))
        mid = mas[l];
    if ((mas[r] >= mas[l] && mas[r] <= mas[(l+r)/2]) || (mas[r] <= mas[l] && mas[r] >= mas[(l+r)/2]))
        mid = mas[r];
    if ((mas[(l+r)/2] >= mas[r] && mas[(l+r)/2] <= mas[l]) || (mas[(l+r)/2] <= mas[r] && mas[(l+r)/2] >= mas[l]))
        mid = mas[(l + r)/2];
    int i = l, j = r;
    while (i <= j) {
        while (mas[i] < mid)
            i++;
        while (mas[j] > mid)
            j--;
        if (i <= j) {
            swap(mas[i], mas[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(mas, l, j);
    if (r > i)
        quicksort(mas, i, r);
}

int main() {
    int n;
    cin >> n;

    int mas[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];

    quicksort (mas, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";

    return 0;
}