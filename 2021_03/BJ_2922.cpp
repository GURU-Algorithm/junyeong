#include <iostream>
#include <string>
using namespace std;

string vowel = "AEIOU";
string consonant = "BCDFGHJKLMNPQRSTVWXYZ";

long long solution(int vowel_size, int con_size, int isinL, int index, string input) {
	if (vowel_size >= 3) return 0;
	if (con_size >= 3) return 0;

	if (index == input.size()) {
		if (isinL == 0) return 0;
		else return 1;
	}

	long long res = 0;

	if (input[index] != '_') {
		if (vowel.find(input[index]) != string::npos) {
			res = solution(vowel_size + 1, 0, isinL, index + 1, input);
		}

		else {
			if (input[index] == 'L') {
				res = solution(0, con_size + 1, isinL + 1, index + 1, input);
			}

			else {
				res = solution(0, con_size + 1, isinL, index + 1, input);
			}
		}
	}

	else {
		res += solution(vowel_size + 1, 0, isinL, index + 1, input) * 5;
		res += solution(0, con_size + 1, isinL, index + 1, input) * 20;
		res += solution(0, con_size + 1, isinL + 1, index + 1, input);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	cout << solution(0, 0, 0, 0, input) << endl;
	return 0;
}
