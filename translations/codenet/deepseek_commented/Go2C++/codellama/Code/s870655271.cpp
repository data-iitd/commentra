// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
	int N, M;
	int ans = 0;
	cin >> N >> M;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}

	cout << ans << endl;
	return 0;
}

/*  ----------------------------------------  */

// This function returns the maximum value among the given integers.
int max(int x, int y) { return x > y ? x : y; }

// This function returns the minimum value among the given integers.
int min(int x, int y) { return x < y ? x : y; }

// This function returns x raised to the power of y.
int pow(int x, int y) { return (int)pow(x, y); }

// This function returns the absolute value of x.
int abs(int x) { return x < 0 ? -x : x; }

// This function returns the floor value of x.
int floor(int x) { return (int)floor(x); }

// This type is a vector of integers that can be sorted by their absolute values.
struct SortBy {
	vector<int> v;
	bool operator<(const SortBy& other) const {
		return abs(v[0]) < abs(other.v[0]);
	}
};

// This function returns the maximum value among the given integers.
int max(vector<int> x) {
	int res = x[0];
	for (int i = 1; i < x.size(); i++) {
		res = max(res, x[i]);
	}
	return res;
}

// This function returns the minimum value among the given integers.
int min(vector<int> x) {
	int res = x[0];
	for (int i = 1; i < x.size(); i++) {
		res = min(res, x[i]);
	}
	return res;
}

// This function returns x raised to the power of y.
int pow(int x, int y) { return (int)pow(x, y); }

// This function returns the absolute value of x.
int abs(int x) { return x < 0 ? -x : x; }

// This function returns the floor value of x.
int floor(int x) { return (int)floor(x); }

// This function returns the number of cells in the grid.
int get_cells(int N, int M) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X, int Y) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X, int Y, int Z) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X, int Y, int Z, int A) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X, int Y, int Z, int A, int B) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X, int Y, int Z, int A, int B, int C) {
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}
	return ans;
}

// This function returns the number of cells in the grid.
int get_cells(int N, int M, int K, int L, int R, int S, int T, int U, int V, int W, int X, int Y, int Z, int A, int B, int C, int D) {
	int ans = 0;
	// If both N and M are 1, there is only on