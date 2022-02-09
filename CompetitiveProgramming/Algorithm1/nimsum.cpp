#include <bits/stdc++.h>
using namespace std;

//function called to find winner of a Nim game

string findWinner(int A[], int n){
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans ^= A[i];

  if (ans == 0 || n % 2 == 0)
    return "Alice wins";

  else
    return "Bob wins";
}

int main(){
  int A[] = {1, 4, 3, 5};
  int n = sizeof(A) / sizeof(A[0]);

  cout << "Winner: " << findWinner(A, n);
  return 0;
}
