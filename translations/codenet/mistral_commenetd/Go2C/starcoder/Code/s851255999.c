#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure named "work" with two fields: "time" and "limit" of type int
struct work {
	int time;
	int limit;
};

// Define a structure named "works" as a dynamic array of "work" structures
struct works {
	struct work *data;
	int size;
	int capacity;
};

// Initialize a "works" structure
struct works init_works(int capacity) {
	struct works w;
	w.data = (struct work *)malloc(capacity * sizeof(struct work));
	w.size = 0;
	w.capacity = capacity;
	return w;
}

// Add a work structure to the end of a "works" structure
void append_work(struct works *ws, struct work work) {
	if (ws->size == ws->capacity) {
		ws->capacity *= 2;
		ws->data = (struct work *)realloc(ws->data, ws->capacity * sizeof(struct work));
	}
	ws->data[ws->size++] = work;
}

// Sort a "works" structure based on the "limit" field of each work structure
void sort_works(struct works *ws) {
	qsort(ws->data, ws->size, sizeof(struct work), (int (*)(const void *, const void *))compare_works);
}

// Compare two work structures based on the "limit" field
int compare_works(const void *a, const void *b) {
	struct work *wa = (struct work *)a;
	struct work *wb = (struct work *)b;
	if (wa->limit < wb->limit) {
		return -1;
	} else if (wa->limit > wb->limit) {
		return 1;
	}
	return 0;
}

// Check if the total time spent on all works exceeds any work's limit
int check_works(struct works ws) {
	int sum = 0;
	for (int i = 0; i < ws.size; i++) {
		sum += ws.data[i].time;
		if (sum > ws.data[i].limit) {
			return 0;
		}
	}
	return 1;
}

// Main function is the entry point of our program
int main(int argc, char *argv[]) {
	// Declare variables and initialize them
	int n;
	scanf("%d", &n);

	// Create a "works" structure with a capacity of 10
	struct works ws = init_works(10);

	// Read input data for each work structure and store it in the "ws" structure
	for (int i = 0; i < n; i++) {
		int a, n;
		scanf("%d %d", &a, &n);
		struct work work = {a, n};
		append_work(&ws, work);
	}

	// Sort the "ws" structure based on the "limit" field of each work structure
	sort_works(&ws);

	// Check if the total time spent on all works exceeds any work's limit
	if (check_works(ws)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

