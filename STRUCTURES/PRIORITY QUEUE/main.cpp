#include <iostream>
using namespace std;
#include <vector>

void siftdown(vector <int> &a, int i){
    while (2*i + 1 < a.size()){
        int r = 2*i + 1;

        if ((2*i + 2 < a.size()) && (a[2*i + 2] < a[2*i + 1]))
            r = 2*i + 2;
        if (a[r] < a[i]){
            swap(a[r], a[i]);
            i = r;
        }
        else
            break;
    }
}

void siftup(vector <int> &a, int i){
    while ((i > 0) && (a[(i - 1) / 2] > a[i])){
        swap(a[(i - 1) / 2], a[i]);
        i = (i - 1) / 2;
    }
}

void insert(vector <vector <int>> &a, int k, int key){
    a[k].push_back(key);
    siftup(a[k], a[k].size() - 1);
}

int extractMin(vector <vector <int>> &a, int k){
    int mini = a[k][0];
    swap(a[k][0], a[k][a[k].size() - 1]);
    a[k].pop_back();
    siftdown(a[k], 0);
    return mini;
}

void merge(vector <vector <int>> &a, int k, int m){
    vector <int> b;

    for (int i = 0; i < a[k].size(); i++){
        b.push_back(a[k][i]);
        siftup(b, b.size() - 1);
    }

    for (int i = 0; i < a[m].size(); i++){
        b.push_back(a[m][i]);
        siftup(b, b.size() - 1);
    }

    a.push_back(b);

}

void decreasekey(vector <vector <int>> &a, int k, int x, int y){
    for (int i = 0; i < a[k].size(); i++){
        if (a[k][i] == x){
            a[k][i] = y;
            siftup(a[k], i);
            break;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector <vector <int>> que;
    string act;

    while (cin >> act){

        if (act == "create") {
            vector <int> ques;
            que.push_back(ques);
        }

        if (act == "insert"){
            int k, x;
            cin >> k >> x;
            insert(que, k, x);
        }

        if (act == "extract-min"){
            int k;
            cin >> k;
            if (que[k].size() == 0)
                cout << "\n" << "*";
            else {
                int p = extractMin(que, k);
                cout << "\n" << p;
            }
        }

        if (act == "merge") {
            int k, m;
            cin >> k >> m;
            merge(que, k, m);
        }

        if (act == "decrease-key"){
            int k, x, y;
            cin >> k >> x >> y;
            decreasekey(que, k, x, y);
        }
    }

    return 0;
};