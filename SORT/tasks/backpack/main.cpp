#include <iostream>
#include <deque>
using namespace std;

int main() {
    int vse;
    cin >> vse;

    int vmest;
    cin >> vmest;

    deque<int> rukz;

    if (vmest <= vse){

        for (int i = 0; i < vmest; i++) {
            int val;
            cin >> val;
            rukz.push_back(val);
        }
        for (int i = vmest; i < vse; i++) {
            int val;
            cin >> val;
            if ((rukz.front() <= rukz.back()) && (rukz.front() <= val)) {
                rukz.pop_front();
                if (rukz.back() >= val) {
                    rukz.push_front(rukz.back());
                    rukz.pop_back();
                    rukz.push_back(val);
                    rukz.push_back(rukz.front());
                    rukz.pop_front();
                } else {
                    rukz.push_back(val);
                }
            } else if ((rukz.back() <= rukz.front()) && (rukz.back() <= val)) {
                rukz.pop_back();
                if (rukz.front() > val) {
                    rukz.push_back(val);
                    rukz.push_back(rukz.front());
                    rukz.pop_front();
                } else {
                    rukz.push_back(rukz.front());
                    rukz.pop_front();
                    rukz.push_back(val);
                }
            } else {
                if (rukz.back() > rukz.front()) {
                    int tmp = rukz.back();
                    rukz.pop_back();
                    rukz.push_back(rukz.front());
                    rukz.pop_front();
                    rukz.push_back(tmp);

                } else {
                    rukz.push_back(rukz.front());
                    rukz.pop_front();
                }
            }
        }

        for (int i = 0; i < vmest; i++) {
            cout << rukz[i] << " ";
        }
    }

    if (vmest >= vse){

        for (int i = 0; i < vse; i++) {
            int val;
            cin >> val;
            rukz.push_back(val);
        }

        for (int i = 0; i < vse; i++) {
            cout << rukz[i] << " ";
        }
    }

    return 0;
}
