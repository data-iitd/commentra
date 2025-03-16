#include <iostream>
#include <string>

using namespace std;

int main() {
	string text;
	cin >> text;
	int limit = text.length();

	int start = 0;
	int middle = 0;
	int end = 0;
	bool firstPrinted = false;

	for (end = 0; end < limit; end++) {
		start = middle = end;
		while (start < limit && text[start] == 'R') {
			start++;
		}
		while (middle < limit && text[middle] == 'L') {
			middle++;
		}
		int len1 = middle - start;
		int len2 = end - middle;

		for (int i = start; i < middle-1; i++) {
			if (firstPrinted) {
				cout << " ";
			}
			cout << "0";
			firstPrinted = true;
		}

		int count1 = (len1+1)/2 + len2/2;
		int count2 = len1/2 + (len2+1)/2;

		if (firstPrinted) {
			cout << " ";
		}
		cout << count1 << " " << count2;
		firstPrinted = true;

		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) {
				cout << " ";
			}
			cout << "0";
			firstPrinted = true;
		}
		start = end;
		firstPrinted = true;
	}
	cout << endl;
}

