#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int n, k;
		cin >> n >> k;

		vector<int> score(n);
		for (int i = 0; i < n; i++) {
			cin >> score[i];
		}

		int res = 0;
		sort(score.begin(), score.end(), greater<int>());
		for (int i = 0; i < k; i++) {
			res += score[i];
		}
		cout << "#" << test_case << " " << res << endl;
	}

	return 0;
}
