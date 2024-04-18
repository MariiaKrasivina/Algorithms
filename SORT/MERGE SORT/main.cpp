#include <iostream>
using namespace std;

int merge(int mas[], int l, int mid, int r) {
    int it1 = 0;
    int it2 = 0;
    int res[r - l];
    int cnt = 0;

    while ((l + it1 < mid) && (mid + it2 < r)) {
        if (mas[l + it1] <= mas[mid + it2]) {
            res[it1 + it2] = mas[l + it1];
            it1++;
        } else {
            res[it1 + it2] = mas[mid + it2];
            it2++;
            cnt += mid - (l + it1);
        }
    }

    while (l + it1 < mid) {
        res[it1 + it2] = mas[l + it1];
        it1++;
    }

    while (mid + it2 < r) {
        res[it1 + it2] = mas[mid + it2];
        it2++;
    }

    for (int i = 0; i < it1 + it2; i++) {
        mas[l + i] = res[i];
    }
}

int mergesort(int mas[], int l, int r) {
    if (l + 1 >= r)
        return 0;

    int mid = (l + r) / 2;
    int cnt = 0;

    cnt += mergesort(mas, l, mid);
    cnt += mergesort(mas, mid, r);

    cnt += merge(mas, l, mid, r);
    return cnt;
}

int main() {
    int n, cnt = 0;
    cin >> n;

    int mas[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];

    cnt = mergesort(mas, 0, n);

    cout << cnt;

    return 0;
}