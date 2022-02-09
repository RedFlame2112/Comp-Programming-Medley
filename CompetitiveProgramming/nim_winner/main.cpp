#include <bits/stdc++.h>
using namespace std;

string getWinner(int n, string pile[])
{

	int p = 0, d = 0;
	for (int i = 0; i < n; ++i) {
		int l = pile[i].length();
		if (pile[i][0] == pile[i][l - 1] && pile[i][0] == '1')
			p++; //check for ending and starting with 1

		if (pile[i][0] == pile[i][l - 1] && pile[i][0] == '0')
			d++; //check for ending and starting with 0
	}
	if (p <= d) //IG"s non-strict inequality
		return "Diana wins.";
	else
		return "Paco wins.";
}

// Driver code
int main()
{

	int n = 4;
	string pile[4] = { "0110", "1101", "1100", "1001" };

	cout << getWinner(n, pile);

	return 0;
}
