// https://www.acmicpc.net/problem/1022

#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int max = 0, size = 0;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			int dx = i - r1, dy = j - c1;
			
			if (i < j) {
				if (i + j < 0) map[dx][dy] = (4 * i * i + i + 1) - j;
				else map[dx][dy] = (4 * j * j - 3 * j + 1) - i;
			}

			else if (i >= j) {
				if (i + j < 0) map[dx][dy] = (4 * j * j - j + 1) + i;
				else map[dx][dy] = (4 * i * i + 3 * i + 1) + j;
			}

			if (map[dx][dy] > max) max = map[dx][dy];
		}
	}

	size = to_string(max).size() + 1;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			
			for (int k = 1; k < size - to_string(map[i][j]).size(); k++) {
				cout << " ";
			}
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
