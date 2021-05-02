#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> res(n + 1);
    vector<int> track(n + 1);

    for (int i = 2; i <= n; i++) {
        res[i] = res[i - 1] + 1;
        track[i] = i - 1;

        if (i % 2 == 0 && res[i] > res[i / 2] + 1) {
            res[i] = res[i / 2] + 1;
            track[i] = i / 2;

        }

        if (i % 3 == 0 && res[i] > res[i / 3] + 1) {
            res[i] = res[i / 3] + 1;
            track[i] = i / 3;
        }
    }

    cout << res[n] << endl;

    cout << n << " ";
    while (n != 1) {
        cout << track[n] << " ";
        n = track[n];
    }


    return 0;
}
