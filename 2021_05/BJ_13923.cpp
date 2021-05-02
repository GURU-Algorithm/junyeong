#include<iostream>
#include<vector>
using namespace std;

// 알파벳 총 26개
// 아스키코드 'A' 는 17, Z'는 42

char seat[26][26]; // 좌석 배치
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // 팀의 개수
    while (cin >> n)
    {
        vector<int> rowsum(n);
        vector<int> colsum(n);
        string tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            for (int j = 0; j < n; j++) {
                seat[i][j] = tmp[j];
                rowsum[i] += tmp[j], colsum[j] += tmp[j];
            }
        }

        int goodSum, badrow = -1, badcol = -1;
        if (rowsum[0] != rowsum[1]) goodSum = rowsum[2];
        else goodSum = rowsum[0];

        for (int i = 0; i < n; i++)
            if (rowsum[i] != goodSum) badrow = i;
        for (int j = 0; j < n; j++)
            if (colsum[j] != goodSum) badcol = j;

        int badchar = seat[badrow][badcol];
        int badSum = rowsum[badrow];
        cout << badrow + 1 << " " << badcol + 1 << " " << (char)(goodSum - (badSum - badchar)) << endl;
    }

    return 0;
}
