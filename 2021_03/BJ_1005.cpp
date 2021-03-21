#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N, K;
		cin >> N >> K;

		vector<int> structure(N + 1);
		for (int i = 1; i <= N; i++) cin >> structure[i];

		int n, m;
		vector<int> rules[1001];
		vector<int> pre_struct(1001);
		for (int i = 0; i < K; i++) {
			cin >> n >> m;
			rules[n].push_back(m);	// 연관 규칙
			pre_struct[m]++;		// m 빌딩 이전에 설치되어야 하는 빌딩의 개수
		}

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (pre_struct[i] == 0)	// 가장 먼저 세워야 하는 빌딩부터 차근차근
				q.push(i);
		}
		
		int target;
		cin >> target;

		// target building 이전에 건설할 건물이 없으면 break하고 빠져나옴
		vector<int> result(N + 1);
		while (pre_struct[target] > 0) {
			int num = q.front();
			q.pop();

			for (auto item : rules[num]) {
				// 기존 시간보다 더 많이 걸리면 기다려야함
				result[item] = max(result[item], result[num] + structure[num]);
				if(--pre_struct[item] == 0) q.push(item);
			}
		}

		cout << result[target] + structure[target] << endl;
	}

	return 0;
}
