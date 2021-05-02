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
		// 입력
		vector<int> xrow(4);
		vector<int> xcol(4);
		vector<int> xdiag(2);

		vector<int> orow(4);
		vector<int> ocol(4);
		vector<int> odiag(2);

		string tmp;
		bool xwin = false, owin = false, draw = true, not_complete = false;

		for (int i = 0; i < 4; i++) {
			cin >> tmp;
			for (int j = 0; j < 4; j++) {
				if (tmp[j] == 'X') {
					xrow[i]++, xcol[j]++;
					if (i == j) xdiag[0]++;
					else if (i == (3 - j)) xdiag[1]++;
				}

				else if (tmp[j] == 'O') {
					orow[i]++, ocol[j]++;
					if (i == j) odiag[0]++;
					else if (i == (3 - j)) odiag[1]++;
				}

				else if (tmp[j] == 'T') {
					xrow[i]++, orow[i]++, xcol[j]++, ocol[j]++;
					if (i == j) odiag[0]++, xdiag[0]++;
					else if (i == (3 - j)) odiag[1]++, xdiag[1]++;
				}

				else {
					draw = false;
					not_complete = true;
				}
			}
		}

		// 검사
		for (int i = 0; i < 4; i++) {
			if (xrow[i] == 4 || xcol[i] == 4) xwin = true;
			else if (orow[i] == 4 || ocol[i] == 4) owin = true;

			if (i < 2) {
				if (xdiag[i] == 4) xwin = true;
				else if (odiag[i] == 4) owin = true;
			}
		}

		// 출력

		if (xwin) cout << "#" << test_case << " X won" << endl;
		else if (owin) cout << "#" << test_case << " O won" << endl;
		else if (not_complete) cout << "#" << test_case << " Game has not completed" << endl;
		else if (draw) cout << "#" << test_case << " Draw" << endl;
	}
  
	return 0;
}
