#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> num(n), res(n, -1);
	stack<int> s;
	for (int i = 0; i < n; i++) cin >> num[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty() && num[s.top()] < num[i]) {
			res[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) cout << res[i] << " ";
	return 0;
}
