#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int location[50][50];

void solution(int x, int y, int m, int n) {
	if (location[x][y] == 0) {
		return;
	}

	else {
		location[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int rx = x + dx[i];
			int ry = y + dy[i];

			if (rx >= 0 && ry >= 0 && rx < m && ry < n) {
				solution(rx, ry, m, n);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int n, m, loc;
		memset(location, 0, sizeof(location));
		cin >> n >> m >> loc;
		
		for (int i = 0; i < loc; i++) {
			int x, y;
			cin >> x >> y;
			location[x][y] = 1;
		}

		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (location[j][i] == 1) {
					res++;
					solution(j, i, n, m);
				}
			}
		}

		cout << res << endl;
	}
	return 0;
}
