#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;

    long a[n+1];
    for (long i = 1; i <= n; i++){cin >> a[i];}

    int b = 1;
    for (long i = 1; i <= n; i++){
        if (2*i <= n && a[i] > a[2*i]) {
            b = 0;
            break;
        }
        if (2*i + 1 <= n && a[i] > a[2*i + 1]) {
            b = 0;
            break;
        }
    }

    if (b == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
