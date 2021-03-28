// 다이나믹 프로그래밍 -> bora 코드 참고

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
using namespace std;

int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> score(n, vector<int>(m));
    bool check[1001][1001];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            score[i][j] = 0;
            check[i][j] = false;
        }
    }

    score[0][0] = map[0][0];
    check[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx >= 0 && ry >= 0 && rx < n && ry < m) {
                if (check[rx][ry] == false) {
                    q.push(make_pair(rx, ry));
                    check[rx][ry] = true;
                    score[rx][ry] = score[x][y] + map[rx][ry];
                }

                else if (score[rx][ry] < score[x][y] + map[rx][ry]) {
                    q.push(make_pair(rx, ry));
                    score[rx][ry] = score[x][y] + map[rx][ry];
                }
            }
        }
    }

    cout << score[n - 1][m - 1] << endl;
    return 0;
}
