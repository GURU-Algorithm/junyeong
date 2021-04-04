#include <iostream>
#include <string>  
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int map[25][25];
vector<int> res;
int numcount = 0;

void solution(int x, int y, int n) {
    if (map[x][y] == 0) {
        return;
    }

    else {
        map[x][y] = 0;
        numcount++;
        for (int i = 0; i < 4; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (rx >= 0 && ry >= 0 && rx < n && ry < n) {
                solution(rx, ry, n);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            map[i][j] = temp[j] - '0';
        }
    }

    int numres = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                numres++;
                solution(i, j, n);
                res.push_back(numcount);
                numcount = 0;
            }
        }
    }

    cout << numres + 1 << endl;
    sort(res.begin(), res.end());
    for (int i = 0; i < numres + 1; i++) cout << res[i] << endl;
    return 0;
}
