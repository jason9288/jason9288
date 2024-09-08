#include <iostream>
#include <vector>
using namespace std;

int n, k, in;
int cntr = 0;

// void print_arr(vector<int> v) {
//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";   
//     }
//     cout << "\n";
//     cout << "cntr : " << cntr << endl;
// }
int insertion_sort(vector<int> v, int k) {
    int loc, cur, temp = -1;
    for (int i = 1; i < n; i++) {
        loc = i-1;
        cur = v[i];

        while (0 <= loc && cur < v[loc]) {
            v[loc+1] = v[loc];
            cntr++;
            // cout << cntr << "번째 저장되는 수 : " << v[loc] << endl;
            if (cntr == k) temp = v[loc];
            // print_arr(v);
            loc--;
        }
        if (loc+1 != i) {
            v[loc+1] = cur;
            cntr++;
            // cout << cntr << "번째 저장되는 수 : " << cur << endl;
            if (cntr == k) temp = cur;
            // print_arr(v);
        }    
    }
    return temp;
}

int main() {
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> in;
        v[i] = in;
    }
    int sol = insertion_sort(v, k);
    cout << sol;
}