
#include<stdio.h>

// Represents a cube with six faces, each face having an integer value.
typedef struct {
	int f[6];
} Cube;

// Rotates the cube around the z-axis.
void roll_z(Cube *c) { roll(c, 1, 2, 4, 3); }

// Rotates the cube around the y-axis.
void roll_y(Cube *c) { roll(c, 0, 2, 5, 3); }

// Rotates the cube around the x-axis.
void roll_x(Cube *c) { roll(c, 0, 1, 5, 4); }

// Helper method to rotate the cube by swapping the values of the faces.
void roll(Cube *c, int i, int j, int k, int l) {
	int t = c->f[i]; c->f[i] = c->f[j]; c->f[j] = c->f[k]; c->f[k] = c->f[l]; c->f[l] = t;
}

// Returns true if the two cubes are the same, false otherwise.
bool is_same(Cube *c1, Cube *c2) {
	for (int i = 0; i < 6; i++) {
		if (c1->f[i]!= c2->f[i]) {
			return false;
		}
	}
	return true;
}

// Returns true if the cube is solved, false otherwise.
bool is_solved(Cube *c) {
	for (int i = 0; i < 6; i++) {
		if (c->f[i]!= i + 1) {
			return false;
		}
	}
	return true;
}

// Prints the cube in a human-readable format.
void print_cube(Cube *c) {
	printf("   %d\n", c->f[0]);
	printf(" %d %d\n", c->f[1], c->f[5]);
	printf("%d %d %d\n", c->f[2], c->f[4], c->f[3]);
}

// Returns the number of moves required to solve the cube.
int solve_cube(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v2(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v3(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v4(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v5(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v6(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v7(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v8(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v9(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v10(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() to check if two cubes are the same.
		// You can use a loop to perform multiple moves until the cube is solved.
		// Increment the moves variable to keep track of the number of moves.
		// You can use the provided print_cube() function to print the cube at each step.
		// You can also use the provided is_solved() function to check if the cube is solved.
		// Once the cube is solved, return the number of moves required.
		// If the cube cannot be solved, return -1.
	}
	return moves;
}

// Returns the number of moves required to solve the cube.
int solve_cube_v11(Cube *c) {
	int moves = 0;
	while (!is_solved(c)) {
		// Implement the algorithm to solve the cube here.
		// You can use the provided functions to rotate the cube.
		// For example, you can use roll_z(), roll_y(), and roll_x() to rotate the cube.
		// You can also use is_same() t