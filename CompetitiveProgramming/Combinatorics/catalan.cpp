#include<iostream>
#include<unordered_map>
typedef long long ll;
#define mod 1000000007;
using namespace std;
unordered_map<int, ll> dp;
int catalan(int n) {
   if (n <= 1) return 1;
   if (dp.find(n) != dp.end()) {
       //do not repeat dupes
       return dp[n];
   }
   int ans = 0;
   for (int i = 0; i < n; ++i){
       ans += catalan(i)*catalan(n - i - 1);
   }
   dp[n] = ans %= mod;
   return ans;
}
int main() {
    int n;
    cin >> n;
    cout << catalan(n) << endl;
    return 0;
}
