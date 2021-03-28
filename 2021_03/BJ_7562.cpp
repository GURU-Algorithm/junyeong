// https://www.acmicpc.net/problem/7562

#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int size, start_x, start_y, end_x, end_y;
		cin >> size >> start_x >> start_y >> end_x >> end_y;

		vector<vector<int>> res(size, vector<int>(size));
		queue<pair<int, int>> q;
		q.push(make_pair(start_x, start_y));
		res[start_x][start_y] = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == end_x && y == end_y) {
				cout << res[end_x][end_y] << endl;
				break;
			}

			for (int i = 0; i < 8; i++) {
				int rx = x + dx[i];
				int ry = y + dy[i];

				if (rx >= 0 && ry >= 0 && rx < size && ry < size) {
					if (res[rx][ry] == 0) {
						q.push(make_pair(rx, ry));
						res[rx][ry] = res[x][y] + 1;
					}
				}
			}
		}
	}

	return 0;
}
