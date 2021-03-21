// https://www.acmicpc.net/problem/1011

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int start, end, diff;
		cin >> start >> end;
		diff = end - start;

		int count = 0, jump = 1;
		while (diff > 0) {
			if (diff <= jump) {
				diff -= jump;
				count++;
			}
			
			else {
				diff -= jump * 2;
				count += 2;
			}

			jump++;
		}
		cout << count << endl;
	}

	return 0;
}
