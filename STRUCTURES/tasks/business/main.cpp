#include <iostream>
using namespace std;


struct Shaurmen{
    long zp;
    long time;
};

void siftdown(Shaurmen a[], long n, long i){
    while (2*i + 1 < n){
        long r = 2*i + 1;

        if ((2*i + 2 < n) && (a[2*i + 2].zp < a[2*i + 1].zp))
            r = 2*i + 2;
        if (a[r].zp < a[i].zp){
            swap(a[r], a[i]);
            i = r;
        }
        else
            break;
    }
}

void timesiftdown(Shaurmen a[], long n, long i){
    while (2*i + 1 < n){
        long r = 2*i + 1;

        if ((2*i + 2 < n) && (a[2*i + 2].time < a[2*i + 1].time))
            r = 2*i + 2;
        if (a[r].time < a[i].time){
            swap(a[r], a[i]);
            i = r;
        }
        else
            break;
    }
}

void siftup(Shaurmen a[], long i){
    while ((i > 0) && (a[(i - 1) / 2].zp > a[i].zp)){
        swap(a[(i - 1) / 2], a[i]);
        i = (i - 1) / 2;
    }
}

void timesiftup(Shaurmen a[], long i){
    while ((i > 0) && (a[(i - 1) / 2].time > a[i].time)){
        swap(a[(i - 1) / 2], a[i]);
        i = (i - 1) / 2;
    }
}

void insert(Shaurmen a[], long &n, Shaurmen key){
    n++;
    long i = n - 1;
    a[i] = key;
    siftup(a, i);
}

void timeinsert(Shaurmen a[], long &n, Shaurmen key){
    n++;
    long i = n - 1;
    a[i] = key;
    timesiftup(a, i);
}

Shaurmen extractMin(Shaurmen a[], long &n){
    Shaurmen mini = a[0];
    a[0] = a[n - 1];
    n--;
    siftdown(a, n, 0);
    return mini;
}

Shaurmen timeextractMin(Shaurmen a[], long &n){
    Shaurmen mini = a[0];
    a[0] = a[n - 1];
    n--;
    timesiftdown(a, n, 0);
    return mini;
}


int main(){
    long kshaurmistov, kzakazov;
    cin >> kshaurmistov >> kzakazov;

    long kfs = 0;
    Shaurmen freeshaurman[kshaurmistov];
    for (long i = 0; i < kshaurmistov; i++){
        long tmp;
        cin >> tmp;
        Shaurmen newsh;
        newsh.zp = tmp;
        newsh.time = 0;
        insert(freeshaurman, kfs, newsh);
    }

    long sum = 0;
    long kbs = 0;
    Shaurmen busyshaurman[kshaurmistov];

    for (long i = 0; i < kzakazov; i++){
        long timeofgetting, cooking;
        cin >> timeofgetting >> cooking;

        while (kbs != 0){
            if (timeofgetting - busyshaurman[0].time >= 0){
                Shaurmen tmp3 = timeextractMin(busyshaurman, kbs);
                tmp3.time = 0;
                insert(freeshaurman, kfs, tmp3);
            }
            else
                break;
        }

        if (kfs > 0) {
            Shaurmen tmp = extractMin(freeshaurman, kfs);
            Shaurmen tmpq1 = freeshaurman[0];
            sum += tmp.zp * cooking;
            tmp.time = timeofgetting + cooking;
            timeinsert(busyshaurman, kbs, tmp);
            Shaurmen tmp2 = busyshaurman[0];
        }
        else
            continue;
    }

    cout << "\n" << sum;

    return 0;
}
