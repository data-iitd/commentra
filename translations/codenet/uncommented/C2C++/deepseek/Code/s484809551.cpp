#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

std::string strrstr(const std::string &string, const std::string &pattern) {
	size_t offset = 0;
	std::string lastP = "";

	std::string searchResult;
	while ((searchResult = string.substr(offset).find(pattern)) != std::string::npos && string[offset] != '\0') {
		lastP = searchResult;
		offset++;
	}

	return lastP;
}

int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b) ? -1 : 1;
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

	while (m%n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

int main(void) {
	const std::string patternBase = "keyence";
	std::string top, bottom;
	std::string S;

	std::cin >> S;

	const size_t len = S.length();
	bool found = false;

	for (size_t offset = 0; offset < patternBase.length(); offset++) {
		top = patternBase.substr(0, offset);
		bottom = patternBase.substr(offset);

		auto topSearch = S.find(top);
		if (topSearch != std::string::npos) {
			auto bottomSearch = strrstr(S.substr(topSearch + offset), bottom);
			if (bottomSearch != std::string::npos) {
				size_t sepCount = 0;

				if (topSearch != 0) {
					sepCount++;
				}
				if (topSearch + offset != bottomSearch) {
					sepCount++;
				}
				if (bottomSearch + bottom.length() != S.length()) {
					sepCount++;
				}

				if (sepCount <= 1) {
					found = true;
					break;
				}
			}
		}
	}

	std::cout << (found ? "YES" : "NO") << std::endl;

	return 0;
}
