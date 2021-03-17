#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int num_values[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(num_values, -1, sizeof(num_values));

	int n, value;
	cin >> n;

        // 각 숫자를 사는데 드는 비용이 작은 숫자부터 주어진다 -> "각 숫자를 사는데 드는 비용이" "작은 숫자부터" 주어진다. 
        // 즉, 인덱스가 0인 수부터 차례대로 주어진다는 뜻. (가격이 오름차순으로 주어진다는 뜻이 아님.)
	vector<pair<int, int>> values(n);
	for (int i = 0; i < n; i++) {
		cin >> value;
		num_values[i] = value;
		values[i] = { value, i };
	}
	sort(values.begin(), values.end()); // 가격 순으로 오름차순 정렬
	
	int score, i = 0;
	cin >> score;
	
        // 정렬했을 때 가장 작은 숫자가 0일 경우, 1로 증가
	vector<int> res; 
        if (!values[i].second) {
            if (n == 1 || values[i + 1].first > score) { // 이때, 배열 크기가 0이거나 그 다음으로 작은 비용이 드는 수를 살 수 없으면 0 출력
                cout << 0;
                return 0;
            }
            i++;
        }

        // 두 번째로 작은 숫자를 먼저 삼 -> 이후엔 가장 작은 비용이 드는 숫자를 모두 사서 자릿수를 확보
	res.push_back(values[i].second);
	score -= values[i].first;
	while (score >= values[0].first) {
		res.push_back(values[0].second);
		score -= values[0].first;
	}

        // 확보된 자리수에 이보다 더 큰 비용이 드는 숫자를 들 수 있는지 비교
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 10; ++j) {
			if (num_values[j] == -1) continue;

			int cur = res[i];
			int diff = num_values[j] - num_values[cur];

			if (j > res[i] && score >= diff) {
				res[i] = j;
				score -= diff;
			}
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	return 0;
}
