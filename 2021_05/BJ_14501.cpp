#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int T[15];
	int P[15];
	vector<int> res(15);

	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = n-1; i >= 0; i--) {
		if (i + T[i] > n) res[i] = res[i + 1];
		else res[i] = max(res[i + 1], res[i + T[i]] + P[i]);
	}

	cout << res[0] << endl;
	return 0;
}
