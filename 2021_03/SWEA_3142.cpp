#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int horns, animals;
		cin >> horns >> animals;

		int animals1 = 0, animals2 = animals;
		while (true) {
			if (animals1 + animals2 * 2 == horns) {
				cout << "#" << test_case << " " << animals1 << " " << animals2 << endl;
				break;
			}

			else if (animals1 + animals2 * 2 > horns) {
				animals2--;
				animals1++;
			}

			else {
				animals2++;
				animals1--;
			}
		}
	}
	return 0;
}
