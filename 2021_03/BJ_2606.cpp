#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<int> map[101];
bool check[101];
int res = 0;

void solution(int n) {
    for (int i = 0; i < map[n].size(); i++) {
        if (!check[map[n][i]]) {
            check[map[n][i]] = true;
            res++;
            solution(map[n][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, n;
    cin >> size >> n;
    memset(check, false, sizeof(check));

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    check[1] = true;
    solution(1);
    cout << res << endl;
    return 0;
}
