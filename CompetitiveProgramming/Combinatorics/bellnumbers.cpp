#include<iostream>
#include<array>
typedef unsigned long long ull;
using namespace std;
int main() {
    auto stirling_two = [](int n,int k) -> ull {
        int maxj = n-k;
        ull *arr = new ull[maxj+1];
        for (ull i = 0; i <= maxj; ++i)
            arr[i] = 1;
        for (ull i = 2; i <= k; ++i)
            for(ull j = 1; j <= maxj; ++j)
                arr[j] += i*arr[j-1];
        return arr[maxj];
    };
    auto bell = [stirling_two](int n) -> ull {
        int ans = 0;
        if (n <= 1) { return 1; }
        else { 
             for (ull i = 0; i <= n; ++i){
                ans += stirling_two(n, i);
            }
        }
        return ans - 1;
    };
    int n;
    int mod = 1e9+7;
    cin >> n;
    ull res = bell(n) % mod;
    cout << "There are a total of " << res << " ways to nest " << n << " matryoshka dolls" << endl;
} 