#include <iostream>
#include <array>
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
    auto factorial = [](int n) -> ull {
        ull fact = 1;
        for (ull i = 1; i <=n; ++i)
            fact *= i;
        return fact;
    };
    auto stirling_two_factorial = [=](int n, int k) -> ull {
        ull fact = factorial(k);
        ull stirling = stirling_two(n, k);
        ull res = fact * stirling;
        return res;
    };
    int mod = 1e9+7;
    cout << "Enter 2 positive numbers" << endl;
    int n, r;
    cin >> n >> r;
    ull ans = stirling_two_factorial(n, r) % mod;
    cout << ans << endl;
    return 0;
}