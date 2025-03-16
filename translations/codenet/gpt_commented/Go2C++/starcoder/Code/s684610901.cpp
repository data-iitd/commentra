#include <bits/stdc++.h>

using namespace std;

// Define a structure for sorting pairs
struct pair {
	int64_t index;
	int64_t p1, p2;
};

// Define a structure for sorting int64 slices
struct Int64Slice {
	int64_t *data;
	int64_t len;
};

// Utility functions for sorting int64 slices
void Int64s(Int64Slice a) {
	sort(a.data, a.data + a.len);
}

bool Int64sSliceAreSorted(Int64Slice a) {
	for (int64_t i = 0; i < a.len - 1; i++) {
		if (a.data[i] > a.data[i + 1]) {
			return false;
		}
	}
	return true;
}

// Utility functions for sorting pairs
bool pairCmp(pair a, pair b) {
	return a.index < b.index;
}

// Utility functions for sorting pairs
void pairs(pair *a, int64_t n) {
	sort(a, a + n, pairCmp);
}

// Utility functions for sorting pairs
bool pairCmp2(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	return a.p2 < b.p2;
}

// Utility functions for sorting pairs
void pairs2(pair *a, int64_t n) {
	sort(a, a + n, pairCmp2);
}

// Utility functions for sorting pairs
bool pairCmp3(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	return a.index < b.index;
}

// Utility functions for sorting pairs
void pairs3(pair *a, int64_t n) {
	sort(a, a + n, pairCmp3);
}

// Utility functions for sorting pairs
bool pairCmp4(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return false;
}

// Utility functions for sorting pairs
void pairs4(pair *a, int64_t n) {
	sort(a, a + n, pairCmp4);
}

// Utility functions for sorting pairs
bool pairCmp5(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return true;
}

// Utility functions for sorting pairs
void pairs5(pair *a, int64_t n) {
	sort(a, a + n, pairCmp5);
}

// Utility functions for sorting pairs
bool pairCmp6(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs6(pair *a, int64_t n) {
	sort(a, a + n, pairCmp6);
}

// Utility functions for sorting pairs
bool pairCmp7(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs7(pair *a, int64_t n) {
	sort(a, a + n, pairCmp7);
}

// Utility functions for sorting pairs
bool pairCmp8(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs8(pair *a, int64_t n) {
	sort(a, a + n, pairCmp8);
}

// Utility functions for sorting pairs
bool pairCmp9(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs9(pair *a, int64_t n) {
	sort(a, a + n, pairCmp9);
}

// Utility functions for sorting pairs
bool pairCmp10(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs10(pair *a, int64_t n) {
	sort(a, a + n, pairCmp10);
}

// Utility functions for sorting pairs
bool pairCmp11(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs11(pair *a, int64_t n) {
	sort(a, a + n, pairCmp11);
}

// Utility functions for sorting pairs
bool pairCmp12(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs12(pair *a, int64_t n) {
	sort(a, a + n, pairCmp12);
}

// Utility functions for sorting pairs
bool pairCmp13(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs13(pair *a, int64_t n) {
	sort(a, a + n, pairCmp13);
}

// Utility functions for sorting pairs
bool pairCmp14(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs14(pair *a, int64_t n) {
	sort(a, a + n, pairCmp14);
}

// Utility functions for sorting pairs
bool pairCmp15(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs15(pair *a, int64_t n) {
	sort(a, a + n, pairCmp15);
}

// Utility functions for sorting pairs
bool pairCmp16(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs16(pair *a, int64_t n) {
	sort(a, a + n, pairCmp16);
}

// Utility functions for sorting pairs
bool pairCmp17(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs17(pair *a, int64_t n) {
	sort(a, a + n, pairCmp17);
}

// Utility functions for sorting pairs
bool pairCmp18(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs18(pair *a, int64_t n) {
	sort(a, a + n, pairCmp18);
}

// Utility functions for sorting pairs
bool pairCmp19(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs19(pair *a, int64_t n) {
	sort(a, a + n, pairCmp19);
}

// Utility functions for sorting pairs
bool pairCmp20(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs20(pair *a, int64_t n) {
	sort(a, a + n, pairCmp20);
}

// Utility functions for sorting pairs
bool pairCmp21(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs21(pair *a, int64_t n) {
	sort(a, a + n, pairCmp21);
}

// Utility functions for sorting pairs
bool pairCmp22(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
		return true;
	}
	if (a.index > b.index) {
		return false;
	}
	return a.p1 < b.p1;
}

// Utility functions for sorting pairs
void pairs22(pair *a, int64_t n) {
	sort(a, a + n, pairCmp22);
}

// Utility functions for sorting pairs
bool pairCmp23(pair a, pair b) {
	if (a.p1 < b.p1) {
		return true;
	}
	if (a.p1 > b.p1) {
		return false;
	}
	if (a.p2 < b.p2) {
		return true;
	}
	if (a.p2 > b.p2) {
		return false;
	}
	if (a.index < b.index) {
