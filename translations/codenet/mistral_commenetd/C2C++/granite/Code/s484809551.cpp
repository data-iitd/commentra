

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string patternBase = "keyence";
	string top, bottom;
	string S;

	cin >> S;

	bool found = false;

	for (size_t offset = 0; offset < patternBase.length(); offset++) {
		top = patternBase.substr(0, offset);
		bottom = patternBase.substr(offset);

		size_t topPos = S.find(top);

		if (topPos!= string::npos) {
			size_t bottomPos = S.rfind(bottom);

			if (bottomPos!= string::npos) {
				size_t sepCount = 0;

				if (topPos!= 0) {
					sepCount++;
				}

				if (topPos + offset!= bottomPos) {
					sepCount++;
				}

				if (bottomPos + bottom.length()!= S.length()) {
					sepCount++;
				}

				if (sepCount <= 1) {
					found = true;
					break;
				}
			}
		}
	}

	cout << (found? "YES" : "NO") << endl;

	return 0;
}

