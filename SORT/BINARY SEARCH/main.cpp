#include <iostream>
using namespace std;

int binpoisk(int a[], int n, int isk){
    int l = 0;
    int r = n - 1;

    while (l <= r){
        int mid = l + (r - l) / 2;//так надо, чтоб ничего не переполнялось
        if (isk == a[mid])//если искомое равно серединному
            return mid;//возвращаем индекс
        else if (isk < a[mid])
            r = mid - 1;//отбрасываем правую часть тк она больше чем искомый и нет смысла там смотреть
        else if (isk > a[mid])
            l = mid + 1;
    }
    return -1;
}

int main() {
    const int n = 6;
    int a[n]{1,2,3,4,5,6};

    cout << binpoisk(a, n, 4); //выводит индекс искомого элемента

    return 0;
}
