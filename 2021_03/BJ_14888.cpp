#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int nummax = -1000000001;
int nummin = 1000000001;
int number[100];
int sachic[4];

void solution(int res, int idx, int size) {
	if (idx == size) {
		if (res >= nummax) nummax = res;
		if (res <= nummin) nummin = res;
		return;
	}
	
	else {
		for (int i = 0; i < 4; i++) {
			if (sachic[i] != 0) {
				sachic[i]--;
				if (i == 0) solution(res + number[idx], idx + 1, size);
				else if (i == 1) solution(res - number[idx], idx + 1, size);
				else if (i == 2) solution(res * number[idx], idx + 1, size);
				else if (i == 3) solution(res / number[idx], idx + 1, size);
				sachic[i]++;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, plus, minus, multi, div;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> number[i];
	cin >> sachic[0] >> sachic[1] >> sachic[2] >> sachic[3];

	solution(number[0], 1, n);
	cout << nummax << endl << nummin << endl;
	return 0;
}
