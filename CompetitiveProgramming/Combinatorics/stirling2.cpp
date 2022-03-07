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
    int n, r;
    int mod = 1e9+7;
    cout << "Please enter 2 numbers next to each other separated by a single space" << endl;
    cin >> n >> r;
    ull res = stirling_two(n, r) % mod;
    cout << "There are a total of " << res << " ways to organize " << n << " distinct objects into " << r << " identical containers such that each container holds at least 1 object." << endl;
}