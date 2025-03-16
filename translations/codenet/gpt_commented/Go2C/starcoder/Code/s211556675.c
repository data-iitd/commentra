

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
// Function to read input from stdin
int read_int(int *x) {
	scanf("%d", x);
	return 1;
}

// Function to read input from stdin
int read_ints(int *x, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	return 1;
}

// Function to write output to stdout
int write_int(int x) {
	printf("%d\n", x);
	return 1;
}

// Function to write output to stdout
int write_ints(int *x, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
	return 1;
}

// Function to write output to stdout
int write_floats(float *x, int n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f ", x[i]);
	}
	printf("\n");
	return 1;
}

// Function to write output to stdout
int write_float(float x) {
	printf("%.2f\n", x);
	return 1;
}

// Function to write output to stdout
int write_char(char x) {
	printf("%c\n", x);
	return 1;
}

// Function to write output to stdout
int write_str(char *x) {
	printf("%s\n", x);
	return 1;
}

// Function to write output to stdout
int write_strs(char **x, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", x[i]);
	}
	printf("\n");
	return 1;
}

// Function to write output to stdout
int write_strs_array(char **x, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", x[i]);
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size(char **x, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array(char **x, int n, int *m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array(char **x, int n, int **m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array(char **x, int n, int ***m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array(char **x, int n, int ****m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array(char **x, int n, int *****m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array(char **x, int n, int ******m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array(char **x, int n, int *******m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array(char **x, int n, int ********m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array(char **x, int n, int *********m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array(char **x, int n, int **********m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***********m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int *************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int **************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ****************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ****************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ****************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ****************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ****************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]; j++) {
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	return 1;
}

// Function to write output to stdout
int write_strs_array_size_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array_array(char **x, int n, int ***************m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0