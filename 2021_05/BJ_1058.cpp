#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int map[51][51];
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			if (temp[j] == 'N') map[i][j] = 0;
			else if (temp[j] == 'Y') map[i][j] = 1;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				else if (map[i][k] == 1 && map[k][j] == 1 && map[i][j] == 0) {
					map[i][j] = map[j][i] = 2;
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0)
				sum++;
		}
		
		if (max < sum)
			max = sum;		
	}

	cout << max;
	return 0;
}
