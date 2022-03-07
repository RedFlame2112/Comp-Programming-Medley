#include <iostream>
using namespace std;
int ncr(int n, int r) { 
    auto gcd = [](int a, int b) -> int {
        int c;
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    };
    if (r > n) return 0;
    if (r > n - r)
        r = n - r;
    int mod = 1e9+7;
    int store[r];
    for (int i = n - r + 1; i <= n; ++i){
        store[i + r - (n + 1) ] = i;
    }
    long int res = 1;
    for (int k = 1; k < r + 1; ++k) {
        int j = 0, i = k;
        while (j < r){
            int x = gcd(i, store[j]);
            if (x > 1){
                store[j] /= x;
                i /= x;
            }
            if (i == 1) break;
            j++;
        }
    }
    for (int i : store)
        res = (res * i) % mod;
    return (int)res;
}
int main(){
    auto starsAndBars = [](int n,int r) { return ncr(n + r - 1, r);};
    int n, r;
    cin >> n;
    cin >> r;
    cout << starsAndBars(n, r);
    return 0;
}
