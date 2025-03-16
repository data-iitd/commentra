

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner to read input from standard input
struct Scanner {
	int* ptr;
	int cur;
	int len;
};

struct Scanner* newScanner(int* ptr, int len) {
	struct Scanner* s = malloc(sizeof(struct Scanner));
	s->ptr = ptr;
	s->cur = 0;
	s->len = len;
	return s;
}

int nextInt(struct Scanner* s) {
	int i = s->ptr[s->cur];
	s->cur++;
	return i;
}

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n = nextInt(newScanner(stdin, 100000));
	int m = nextInt(newScanner(stdin, 100000));

	// Create a slice to hold the heights and a slice to track which elements are "good"
	int* h = malloc(sizeof(int) * n);
	int* good = malloc(sizeof(int) * n);

	// Read the heights and initialize the good slice to true
	for (int i = 0; i < n; i++) {
		h[i] = nextInt(newScanner(stdin, 100000)); // Read height for each element
		good[i] = 1;   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai = nextInt(newScanner(stdin, 100000)) - 1; // Read the first index (0-based)
		int bi = nextInt(newScanner(stdin, 100000)) - 1; // Read the second index (0-based)

		// Compare the heights and update the good slice accordingly
		if (h[ai] > h[bi]) {
			good[bi] = 0; // If ai is taller, bi is not "good"
		} else if (h[ai] < h[bi]) {
			good[ai] = 0; // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = 0;
			good[bi] = 0;
		}
	}

	// Count the number of "good" elements
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++; // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	printf("%d\n", ans);
}

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner to read input from standard input
struct Scanner {
	int* ptr;
	int cur;
	int len;
};

struct Scanner* newScanner(int* ptr, int len) {
	struct Scanner* s = malloc(sizeof(struct Scanner));
	s->ptr = ptr;
	s->cur = 0;
	s->len = len;
	return s;
}

int nextInt(struct Scanner* s) {
	int i = s->ptr[s->cur];
	s->cur++;
	return i;
}

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n = nextInt(newScanner(stdin, 100000));
	int m = nextInt(newScanner(stdin, 100000));

	// Create a slice to hold the heights and a slice to track which elements are "good"
	int* h = malloc(sizeof(int) * n);
	int* good = malloc(sizeof(int) * n);

	// Read the heights and initialize the good slice to true
	for (int i = 0; i < n; i++) {
		h[i] = nextInt(newScanner(stdin, 100000)); // Read height for each element
		good[i] = 1;   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai = nextInt(newScanner(stdin, 100000)) - 1; // Read the first index (0-based)
		int bi = nextInt(newScanner(stdin, 100000)) - 1; // Read the second index (0-based)

		// Compare the heights and update the good slice accordingly
		if (h[ai] > h[bi]) {
			good[bi] = 0; // If ai is taller, bi is not "good"
		} else if (h[ai] < h[bi]) {
			good[ai] = 0; // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = 0;
			good[bi] = 0;
		}
	}

	// Count the number of "good" elements
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++; // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	printf("%d\n", ans);
}

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner to read input from standard input
struct Scanner {
	int* ptr;
	int cur;
	int len;
};

struct Scanner* newScanner(int* ptr, int len) {
	struct Scanner* s = malloc(sizeof(struct Scanner));
	s->ptr = ptr;
	s->cur = 0;
	s->len = len;
	return s;
}

int nextInt(struct Scanner* s) {
	int i = s->ptr[s->cur];
	s->cur++;
	return i;
}

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n = nextInt(newScanner(stdin, 100000));
	int m = nextInt(newScanner(stdin, 100000));

	// Create a slice to hold the heights and a slice to track which elements are "good"
	int* h = malloc(sizeof(int) * n);
	int* good = malloc(sizeof(int) * n);

	// Read the heights and initialize the good slice to true
	for (int i = 0; i < n; i++) {
		h[i] = nextInt(newScanner(stdin, 100000)); // Read height for each element
		good[i] = 1;   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai = nextInt(newScanner(stdin, 100000)) - 1; // Read the first index (0-based)
		int bi = nextInt(newScanner(stdin, 100000)) - 1; // Read the second index (0-based)

		// Compare the heights and update the good slice accordingly
		if (h[ai] > h[bi]) {
			good[bi] = 0; // If ai is taller, bi is not "good"
		} else if (h[ai] < h[bi]) {
			good[ai] = 0; // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = 0;
			good[bi] = 0;
		}
	}

	// Count the number of "good" elements
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++; // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	printf("%d\n", ans);
}

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner to read input from standard input
struct Scanner {
	int* ptr;
	int cur;
	int len;
};

struct Scanner* newScanner(int* ptr, int len) {
	struct Scanner* s = malloc(sizeof(struct Scanner));
	s->ptr = ptr;
	s->cur = 0;
	s->len = len;
	return s;
}

int nextInt(struct Scanner* s) {
	int i = s->ptr[s->cur];
	s->cur++;
	return i;
}

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n = nextInt(newScanner(stdin, 100000));
	int m = nextInt(newScanner(stdin, 100000));

	// Create a slice to hold the heights and a slice to track which elements are "good"
	int* h = malloc(sizeof(int) * n);
	int* good = malloc(sizeof(int) * n);

	// Read the heights and initialize the good slice to true
	for (int i = 0; i < n; i++) {
		h[i] = nextInt(newScanner(stdin, 100000)); // Read height for each element
		good[i] = 1;   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai = nextInt(newScanner(stdin, 100000)) - 1; // Read the first index (0-based)
		int bi = nextInt(newScanner(stdin, 100000)) - 1; // Read the second index (0-based)

		// Compare the heights and update the good slice accordingly
		if (h[ai] > h[bi]) {
			good[bi] = 0; // If ai is taller, bi is not "good"
		} else if (h[ai] < h[bi]) {
			good[ai] = 0; // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = 0;
			good[bi] = 0;
		}
	}

	// Count the number of "good" elements
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++; // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	printf("%d\n", ans);
}

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner to read input from standard input
struct Scanner {
	int* ptr;
	int cur;
	int len;
};

struct Scanner* newScanner(int* ptr, int len) {
	struct Scanner* s = malloc(sizeof(struct Scanner));
	s->ptr = ptr;
	s->cur = 0;
	s->len = len;
	return s;
}

int nextInt(struct Scanner* s) {
	int i = s->ptr[s->cur];
	s->cur++;
	return i;
}

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n = nextInt(newScanner(stdin, 100000));
	int m = nextInt(newScanner(stdin, 100000));

	// Create a slice to hold the heights and a slice to track which elements are "good"
	int* h = malloc(sizeof(int) * n);
	int* good = malloc(sizeof(int) * n);

	// Read the heights and initialize the good slice to true
	for (int i = 0; i < n; i++) {
		h[i] = nextInt(newScanner(stdin, 100000)); // Read height for each element
		good[i] = 1;   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai = nextInt(newScanner(stdin, 100000)) - 1; // Read the first index (0-based)
		int bi = nextInt(newScanner(stdin, 100000)) - 1; // Read the second index (0-based)

		// Compare the heights and update the good slice accordingly
		if (h[ai] > h[bi]) {
			good[bi] = 0; // If ai is taller, bi is not "good"
		} else if (h[ai] < h[bi]) {
			good[ai] = 0; // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = 0;
			good[bi] = 0;
		}
	}

	// Count the number of "good" elements
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++; // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	printf("%d\n", ans);
}

#include <stdio.h>
#include <stdlib.h>

// Initialize a scanner to read input from standard input
struct Scanner {
	int* ptr;
	int cur;
	int len;
};

struct Scanner* newScanner(int* ptr, int len) {
	struct Scanner* s = malloc(sizeof(struct Scanner));
	s->ptr = ptr;
	s->cur = 0;
	s->len = len;
	return s;
}

int nextInt(struct Scanner* s) {
	int i = s->ptr[s->cur];
	s->cur++;
	return i;
}

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n = nextInt(newScanner(stdin, 100000));
	int m = nextInt(newScanner(stdin, 100000));

	// Create a slice to hold the heights and a slice to track which elements are "good"
	int* h = malloc(sizeof(int) * n);
	int* good = malloc(sizeof(int) * n);

	// Read the heights and initialize the good slice to true
	for (int i = 0; i < n; i++) {
		h[i] = nextInt(newScanner(stdin, 100000)); // Read height for each element
		good[i] = 1;   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai = nextInt(newScanner(stdin, 100000)) - 1; // Read the first index (0-based)
		int bi = nextInt(newScanner(stdin, 100000)) - 1; // Read the second index (0-bas