

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			return NULL;
		}
		if (c =='' || c == '\n' || c == '\t') {
			if (s!= NULL) {
				s[i] = '\0';
				return s;
			}
		} else {
			if (s == NULL) {
				s = (char*) malloc(sizeof(char) * 1000);
			}
			s[i] = c;
			i++;
		}
	}
}

// get_next_int reads the next integer from the input and returns it.
// It returns 0 if no more input is available.
int get_next_int(FILE* fp) {
	char* s = get_next_string(fp);
	if (s == NULL) {
		return 0;
	}
	int i = atoi(s);
	free(s);
	return i;
}

int main(int argc, char** argv) {
	// Open input file if provided.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Open output file if provided.
	FILE* wfp = stdout;
	if (argc > 2) {
		wfp = fopen(argv[2], "w");
	}

	// Read the number of integers to process.
	int n = get_next_int(fp);

	// Initialize the answer as "second" and check for odd integers.
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		int a = get_next_int(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(wfp, "%s\n", ans);

	// Close input and output files.
	if (fp!= stdin) {
		fclose(fp);
	}
	if (wfp!= stdout) {
		fclose(wfp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			return NULL;
		}
		if (c =='' || c == '\n' || c == '\t') {
			if (s!= NULL) {
				s[i] = '\0';
				return s;
			}
		} else {
			if (s == NULL) {
				s = (char*) malloc(sizeof(char) * 1000);
			}
			s[i] = c;
			i++;
		}
	}
}

// get_next_int reads the next integer from the input and returns it.
// It returns 0 if no more input is available.
int get_next_int(FILE* fp) {
	char* s = get_next_string(fp);
	if (s == NULL) {
		return 0;
	}
	int i = atoi(s);
	free(s);
	return i;
}

int main(int argc, char** argv) {
	// Open input file if provided.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Open output file if provided.
	FILE* wfp = stdout;
	if (argc > 2) {
		wfp = fopen(argv[2], "w");
	}

	// Read the number of integers to process.
	int n = get_next_int(fp);

	// Initialize the answer as "second" and check for odd integers.
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		int a = get_next_int(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(wfp, "%s\n", ans);

	// Close input and output files.
	if (fp!= stdin) {
		fclose(fp);
	}
	if (wfp!= stdout) {
		fclose(wfp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			return NULL;
		}
		if (c =='' || c == '\n' || c == '\t') {
			if (s!= NULL) {
				s[i] = '\0';
				return s;
			}
		} else {
			if (s == NULL) {
				s = (char*) malloc(sizeof(char) * 1000);
			}
			s[i] = c;
			i++;
		}
	}
}

// get_next_int reads the next integer from the input and returns it.
// It returns 0 if no more input is available.
int get_next_int(FILE* fp) {
	char* s = get_next_string(fp);
	if (s == NULL) {
		return 0;
	}
	int i = atoi(s);
	free(s);
	return i;
}

int main(int argc, char** argv) {
	// Open input file if provided.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Open output file if provided.
	FILE* wfp = stdout;
	if (argc > 2) {
		wfp = fopen(argv[2], "w");
	}

	// Read the number of integers to process.
	int n = get_next_int(fp);

	// Initialize the answer as "second" and check for odd integers.
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		int a = get_next_int(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(wfp, "%s\n", ans);

	// Close input and output files.
	if (fp!= stdin) {
		fclose(fp);
	}
	if (wfp!= stdout) {
		fclose(wfp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			return NULL;
		}
		if (c =='' || c == '\n' || c == '\t') {
			if (s!= NULL) {
				s[i] = '\0';
				return s;
			}
		} else {
			if (s == NULL) {
				s = (char*) malloc(sizeof(char) * 1000);
			}
			s[i] = c;
			i++;
		}
	}
}

// get_next_int reads the next integer from the input and returns it.
// It returns 0 if no more input is available.
int get_next_int(FILE* fp) {
	char* s = get_next_string(fp);
	if (s == NULL) {
		return 0;
	}
	int i = atoi(s);
	free(s);
	return i;
}

int main(int argc, char** argv) {
	// Open input file if provided.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Open output file if provided.
	FILE* wfp = stdout;
	if (argc > 2) {
		wfp = fopen(argv[2], "w");
	}

	// Read the number of integers to process.
	int n = get_next_int(fp);

	// Initialize the answer as "second" and check for odd integers.
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		int a = get_next_int(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(wfp, "%s\n", ans);

	// Close input and output files.
	if (fp!= stdin) {
		fclose(fp);
	}
	if (wfp!= stdout) {
		fclose(wfp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			return NULL;
		}
		if (c =='' || c == '\n' || c == '\t') {
			if (s!= NULL) {
				s[i] = '\0';
				return s;
			}
		} else {
			if (s == NULL) {
				s = (char*) malloc(sizeof(char) * 1000);
			}
			s[i] = c;
			i++;
		}
	}
}

// get_next_int reads the next integer from the input and returns it.
// It returns 0 if no more input is available.
int get_next_int(FILE* fp) {
	char* s = get_next_string(fp);
	if (s == NULL) {
		return 0;
	}
	int i = atoi(s);
	free(s);
	return i;
}

int main(int argc, char** argv) {
	// Open input file if provided.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Open output file if provided.
	FILE* wfp = stdout;
	if (argc > 2) {
		wfp = fopen(argv[2], "w");
	}

	// Read the number of integers to process.
	int n = get_next_int(fp);

	// Initialize the answer as "second" and check for odd integers.
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		int a = get_next_int(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(wfp, "%s\n", ans);

	// Close input and output files.
	if (fp!= stdin) {
		fclose(fp);
	}
	if (wfp!= stdout) {
		fclose(wfp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			return NULL;
		}
		if (c =='' || c == '\n' || c == '\t') {
			if (s!= NULL) {
				s[i] = '\0';
				return s;
			}
		} else {
			if (s == NULL) {
				s = (char*) malloc(sizeof(char) * 1000);
			}
			s[i] = c;
			i++;
		}
	}
}

// get_next_int reads the next integer from the input and returns it.
// It returns 0 if no more input is available.
int get_next_int(FILE* fp) {
	char* s = get_next_string(fp);
	if (s == NULL) {
		return 0;
	}
	int i = atoi(s);
	free(s);
	return i;
}

int main(int argc, char** argv) {
	// Open input file if provided.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Open output file if provided.
	FILE* wfp = stdout;
	if (argc > 2) {
		wfp = fopen(argv[2], "w");
	}

	// Read the number of integers to process.
	int n = get_next_int(fp);

	// Initialize the answer as "second" and check for odd integers.
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		int a = get_next_int(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(wfp, "%s\n", ans);

	// Close input and output files.
	if (fp!= stdin) {
		fclose(fp);
	}
	if (wfp!= stdout) {
		fclose(wfp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next string from the input and returns it.
// It returns NULL if no more input is available.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	int c = 0;
	int i = 0;
	wh