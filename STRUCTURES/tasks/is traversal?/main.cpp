#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


bool ispre(int pre[], int n) {
    stack <int> tmp;
    int root = INT_MIN;

    for (int i = 0; i < n; i++){
        if (pre[i] < root)
            return false;

        while ((!tmp.empty()) && (tmp.top() < pre[i])){
            root = tmp.top();
            tmp.pop();
        }

        tmp.push(pre[i]);
    }
    return true;
}

bool isin(int in[], int n){
    for (int i = 0; i < n - 1; i++){
        if (in[i] > in[i + 1])
            return false;
    }
    return true;
}

bool ispost(int post[], int n){
    stack <int> tmp;
    int root = INT_MAX;

    for (int i = n - 1; i >= 0; i--){
        if (post[i] > root) {
            return false;
        }

        while ((!tmp.empty()) && post[i] < (tmp.top())){
            root = tmp.top();
            tmp.pop();
        }
        tmp.push(post[i]);
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int pre[n], in[n], post[n];

    for (int i = 0; i < 3 * n; i++) {
        if (i < n){
            cin >> pre[i];
        }
        else if (i >= n && i < 2*n){
            cin >> in[i - n];
        }
        else {
            cin >> post[i - 2*n];
        }
    }

    if (ispre(pre, n) && isin(in, n) && ispost(post, n)) {

        sort(pre, pre + n);
        sort(post, post + n);
        bool same = true;

        for (int i = 0; i < n; i++){
            if (pre[i] != in[i] || in[i] != post[i] || pre[i] != post[i]) {
                same = false;
                break;
            }
        }

        if (!same)
            cout << "NO";
        else
            cout << "YES";
    }
    else
        cout << "NO";


    return 0;
}
