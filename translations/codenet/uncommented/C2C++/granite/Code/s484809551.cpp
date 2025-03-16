
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) > (b)? (a) : (b))
#define ABS(a) ((a) < 0? -(a) : (a))
#define ABSS(a, b) ((a) > (b)? (a) - (b) : (b) - (a))

static string strrstr(const string &string, const string &pattern) {
	size_t offset = 0;
	string lastP = "";

	string searchResult = "";
	while ((searchResult = string.substr(offset)).find(pattern)!= string::npos && string[offset]!= '\0') {
		lastP = searchResult;
		offset++;
	}

	return lastP;
}

int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b)? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

static uint64_t gcd(uint64_t m, uint64_t n)
{
	uint64_t temp;

	while (m%n!= 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

int main(void) {
	const string patternBase = "keyence";
	string top, bottom;
	string S;

	cin >> S;

	const size_t len = S.length();
	bool found = false;

	for (size_t offset = 0; offset < patternBase.length(); offset++) {
		top = patternBase.substr(0, offset);
		bottom = patternBase.substr(offset);

		const string *topSearch = &S;
		if ((topSearch = &strrstr(S, top))!= NULL) {
			const string *bottomSearch = &strrstr(*topSearch, bottom);
			if (bottomSearch!= NULL) {
				size_t sepCount = 0;

				if (topSearch!= &S) {
					sepCount++;
				}
				if (bottomSearch!= &S) {
					sepCount++;
				}
				if (bottomSearch->length()!= bottom.length()) {
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

