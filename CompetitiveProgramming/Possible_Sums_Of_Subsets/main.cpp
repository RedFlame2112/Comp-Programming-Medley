#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

ll sumSubSequence(vector<ll> arr, ll len, ll m)
{
    
    ll sum = 0;
    for (auto x : arr)
    sum += x;

    vector<vector<ll> > dp(len + 1, vector<ll>(sum + 1, 0));

    for (ll i = 0; i <= len; i++)
        dp[i][0]++;

    for (ll i = 1; i <= len; i++) {

        dp[i][arr[i - 1]]++;
        for (ll j = 1; j <= sum; j++) {

            if (dp[i - 1][j] > 0) {
                dp[i][j]++;
                dp[i][j + arr[i - 1]]++;
            }
        }
    }

    ll res = 0;
    for (ll j = 1; j <= sum; j++)
        
        if (dp[len][j] > 0)

            if (j % m == 0)
                res += dp[len][j];

    return res;
}

// Driver Code
int main()
{
    vector<ll> arr{ factorial(1), factorial(2), factorial(3), 
                    factorial(4), factorial(5), factorial(6), 
                    factorial(7), factorial(8), factorial(9), factorial(10) };
    ll m = 9;
    int len = arr.size();
    cout << sumSubSequence(arr, len, m) + 1 << endl;
    return 0;
}