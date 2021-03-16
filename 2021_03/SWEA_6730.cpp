#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int n;
		cin >> n;

		vector<int> level(n);
		for (int i = 0; i < n; i++) cin >> level[i];

		int up = 0, down = 0;
		for (int i = 0; i < n - 1; i++) {
			if (level[i] < level[i + 1]) {
				up = max(up, level[i + 1] - level[i]);
			}

			else if (level[i] > level[i + 1]) {
				down = max(down, level[i] - level[i + 1]);
			}
		}

		cout << "#" << test_case << " " << up << " " << down << endl;
	}
}
