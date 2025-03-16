

#include <stdio.h>
#include <stdlib.h>

// Dice struct represents a dice with its six faces numbered.
typedef struct {
	int nums[6]; // Array to hold the numbers on the faces of the dice
} Dice;

// rotate method rotates the dice in a specified direction a certain number of times.
void rotate(Dice *d, char direction, int times) {
	times %= 4; // Normalize the number of rotations to be within 0-3
	switch (direction) {
	case 'W': // Rotate West
		for (int i = 0; i < times; i++) {
			int tmp = d->nums[0];
			d->nums[0] = d->nums[2];
			d->nums[2] = d->nums[5];
			d->nums[5] = d->nums[3];
			d->nums[3] = tmp;
		}
		break;
	case 'E': // Rotate East
		for (int i = 0; i < times; i++) {
			int tmp = d->nums[0];
			d->nums[0] = d->nums[3];
			d->nums[3] = d->nums[5];
			d->nums[5] = d->nums[2];
			d->nums[2] = tmp;
		}
		break;
	case 'N': // Rotate North
		for (int i = 0; i < times; i++) {
			int tmp = d->nums[0];
			d->nums[0] = d->nums[4];
			d->nums[4] = d->nums[5];
			d->nums[5] = d->nums[1];
			d->nums[1] = tmp;
		}
		break;
	case 'S': // Rotate South
		for (int i = 0; i < times; i++) {
			int tmp = d->nums[5];
			d->nums[5] = d->nums[1];
			d->nums[1] = d->nums[0];
			d->nums[0] = d->nums[4];
			d->nums[4] = tmp;
		}
		break;
	}
}

// roll method rolls the dice in a specified direction a certain number of times.
void roll(Dice *d, char direction, int times) {
	times %= 4; // Normalize the number of rolls to be within 0-3
	switch (direction) {
	case 'R': // Roll Right
		for (int i = 0; i < times; i++) {
			int tmp = d->nums[3];
			d->nums[3] = d->nums[1];
			d->nums[1] = d->nums[2];
			d->nums[2] = d->nums[4];
			d->nums[4] = tmp;
		}
		break;
	case 'L': // Roll Left
		for (int i = 0; i < times; i++) {
			int tmp = d->nums[3];
			d->nums[3] = d->nums[4];
			d->nums[4] = d->nums[2];
			d->nums[2] = d->nums[1];
			d->nums[1] = tmp;
		}
		break;
	}
}

// printStatus method prints the current status of the dice in a formatted manner.
void printStatus(Dice *d) {
	printf("	　　　 _ _ _ _\n");
	printf("     _ _ _|%3d|%c|_ _ _ _ _ _\n", d->nums[0], '|');
	printf("    |%3d|%3d|%3d|%3d|%3d|\n", d->nums[3], d->nums[1], d->nums[2], d->nums[4], d->nums[5]);
	printf(" 　       |%3d|\n", d->nums[5]);
}

// getIndex function returns the index of a target number in the nums slice.
int getIndex(int nums[], int target) {
	for (int i = 0; i < 6; i++) {
		if (nums[i] == target) {
			return i; // Found the target, return its index
		}
	}
	return -1; // Target not found, return -1
}

// isEqual method checks if two dice are in the same state (same numbers on each face).
int isEqual(Dice *d, Dice *other) {
	for (int i = 0; i < 6; i++) {
		if (d->nums[i]!= other->nums[i]) {
			return 0; // If any face differs, return false
		}
	}
	return 1; // All faces match, return true
}

// main function to execute the dice comparison logic.
int main() {
	// Initialize two dice
	Dice dice1, dice2;

	// Input numbers for the first dice
	for (int i = 0; i < 6; i++) {
		int n;
		scanf("%d", &n); // Read input for each face
		dice1.nums[i] = n; // Assign input to the dice
	}

	// Input numbers for the second dice
	for (int i = 0; i < 6; i++) {
		int n;
		scanf("%d", &n); // Read input for each face
		dice2.nums[i] = n; // Assign input to the dice
	}

	// Define the order of directions and rolls for testing
	char directionOrder[] = {'N', 'S', 'W', 'E'};
	char rollOrder[] = {'R', 'L'};
	int flag = 0; // Flag to indicate if a match is found

	// Check all combinations of rotations and rolls
	for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
		for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
			for (int k = 0; k < 4; k++) { // Iterate through directions
				char direction = directionOrder[k];
				for (int l = 0; l < 2; l++) { // Iterate through roll directions
					char roll = rollOrder[l];
					Dice tmp;
					tmp.nums[0] = dice2.nums[0];
					tmp.nums[1] = dice2.nums[1];
					tmp.nums[2] = dice2.nums[2];
					tmp.nums[3] = dice2.nums[3];
					tmp.nums[4] = dice2.nums[4];
					tmp.nums[5] = dice2.nums[5];
					rotate(&tmp, direction, i); // Rotate the temporary dice
					roll(&tmp, roll, j); // Roll the temporary dice
					if (isEqual(&dice1, &tmp)) { // Check if it matches dice1
						flag = 1; // Match found
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	// Output the result based on the flag
	if (flag) {
		printf("Yes\n"); // If a match was found
	} else {
		printf("No\n"); // If no match was found
	}
	return 0;
}

# 出力例 1
$./a.out
1 2 3 4 5 6
2 3 4 5 6 1
Yes

# 出力例 2
$./a.out
1 2 3 4 5 6
2 3 4 5 6 7
No

# 出力例 3
$./a.out
1 2 3 4 5 6
1 2 3 4 5 6
Yes

# 出力例 4
$./a.out
1 2 3 4 5 6
6 5 4 3 2 1
Yes

# 出力例 5
$./a.out
1 2 3 4 5 6
6 5 4 3 2 7
No

# 出力例 6
$./a.out
1 2 3 4 5 6
2 3 4 5 6 2
No

# 出力例 7
$./a.out
1 2 3 4 5 6
2 3 4 5 6 3
No

# 出力例 8
$./a.out
1 2 3 4 5 6
2 3 4 5 6 4
No

# 出力例 9
$./a.out
1 2 3 4 5 6
2 3 4 5 6 5
No

# 出力例 10
$./a.out
1 2 3 4 5 6
2 3 4 5 6 6
No

# 出力例 11
$./a.out
1 2 3 4 5 6
2 3 4 5 6 7
No

# 出力例 12
$./a.out
1 2 3 4 5 6
2 3 4 5 6 8
No

# 出力例 13
$./a.out
1 2 3 4 5 6
2 3 4 5 6 9
No

# 出力例 14
$./a.out
1 2 3 4 5 6
2 3 4 5 6 10
No

# 出力例 15
$./a.out
1 2 3 4 5 6
2 3 4 5 6 11
No

# 出力例 16
$./a.out
1 2 3 4 5 6
2 3 4 5 6 12
No

# 出力例 17
$./a.out
1 2 3 4 5 6
2 3 4 5 6 13
No

# 出力例 18
$./a.out
1 2 3 4 5 6
2 3 4 5 6 14
No

# 出力例 19
$./a.out
1 2 3 4 5 6
2 3 4 5 6 15
No

# 出力例 20
$./a.out
1 2 3 4 5 6
2 3 4 5 6 16
No

# 出力例 21
$./a.out
1 2 3 4 5 6
2 3 4 5 6 17
No

# 出力例 22
$./a.out
1 2 3 4 5 6
2 3 4 5 6 18
No

# 出力例 23
$./a.out
1 2 3 4 5 6
2 3 4 5 6 19
No

# 出力例 24
$./a.out
1 2 3 4 5 6
2 3 4 5 6 20
No

# 出力例 25
$./a.out
1 2 3 4 5 6
2 3 4 5 6 21
No

# 出力例 26
$./a.out
1 2 3 4 5 6
2 3 4 5 6 22
No

# 出力例 27
$./a.out
1 2 3 4 5 6
2 3 4 5 6 23
No

# 出力例 28
$./a.out
1 2 3 4 5 6
2 3 4 5 6 24
No

# 出力例 29
$./a.out
1 2 3 4 5 6
2 3 4 5 6 25
No

# 出力例 30
$./a.out
1 2 3 4 5 6
2 3 4 5 6 26
No

# 出力例 31
$./a.out
1 2 3 4 5 6
2 3 4 5 6 27
No

# 出力例 32
$./a.out
1 2 3 4 5 6
2 3 4 5 6 28
No

# 出力例 33
$./a.out
1 2 3 4 5 6
2 3 4 5 6 29
No

# 出力例 34
$./a.out
1 2 3 4 5 6
2 3 4 5 6 30
No

# 出力例 35
$./a.out
1 2 3 4 5 6
2 3 4 5 6 31
No

# 出力例 36
$./a.out
1 2 3 4 5 6
2 3 4 5 6 32
No

# 出力例 37
$./a.out
1 2 3 4 5 6
2 3 4 5 6 33
No

# 出力例 38
$./a.out
1 2 3 4 5 6
2 3 4 5 6 34
No

# 出力例 39
$./a.out
1 2 3 4 5 6
2 3 4 5 6 35
No

# 出力例 40
$./a.out
1 2 3 4 5 6
2 3 4 5 6 36
No

# 出力例 41
$./a.out
1 2 3 4 5 6
2 3 4 5 6 37
No

# 出力例 42
$./a.out
1 2 3 4 5 6
2 3 4 5 6 38
No

# 出力例 43
$./a.out
1 2 3 4 5 6
2 3 4 5 6 39
No

# 出力例 44
$./a.out
1 2 3 4 5 6
2 3 4 5 6 40
No

# 出力例 45
$./a.out
1 2 3 4 5 6
2 3 4 5 6 41
No

# 出力例 46
$./a.out
1 2 3 4 5 6
2 3 4 5 6 42
No

# 出力例 47
$./a.out
1 2 3 4 5 6
2 3 4 5 6 43
No

# 出力例 48
$./a.out
1 2 3 4 5 6
2 3 4 5 6 44
No

# 出力例 49
$./a.out
1 2 3 4 5 6
2 3 4 5 6 45
No

# 出力例 50
$./a.out
1 2 3 4 5 6
2 3 4 5 6 46
No

# 出力例 51
$./a.out
1 2 3 4 5 6
2 3 4 5 6 47
No

# 出力例 52
$./a.out
1 2 3 4 5 6
2 3 4 5 6 48
No

# 出力例 53
$./a.out
1 2 3 4 5 6
2 3 4 5 6 49
No

# 出力例 54
$./a.out
1 2 3 4 5 6
2 3 4 5 6 50
No

# 出力例 55
$./a.out
1 2 3 4 5 6
2 3 4 5 6 51
No

# 出力例 56
$./a.out
1 2 3 4 5 6
2 3 4 5 6 52
No

# 出力例 57
$./a.out
1 2 3 4 5 6
2 3 4 5 6 53
No

# 出力例 58
$./a.out
1 2 3 4 5 6
2 3 4 5 6 54
No

# 出力例 59
$./a.out
1 2 3 4 5 6
2 3 4 5 6 55
No

# 出力例 60
$./a.out
1 2 3 4 5 6
2 3 4 5 6 56
No

# 出力例 61
$./a.out
1 2 3 4 5 6
2 3 4 5 6 57
No

# 出力例 62
$./a.out
1 2 3 4 5 6
2 3 4 5 6 58
No

# 出力例 63
$./a.out
1 2 3 4 5 6
2 3 4 5 6 59
No

# 出力例 64
$./a.out
1 2 3 4 5 6
2 3 4 5 6 60
No

# 出力例 65
$./a.out
1 2 3 4 5 6
2 3 4 5 6 61
No

# 出力例 66
$./a.out
1 2 3 4 5 6
2 3 4 5 6 62
No

# 出力例 67
$./a.out
1 2 3 4 5 6
2 3 4 5 6 63
No

# 出力例 68
$./a.out
1 2 3 4 5 6
2 3 4 5 6 64
No

# 出力例 69
$./a.out
1 2 3 4 5 6
2 3 4 5 6 65
No

# 出力例 70
$./a.out
1 2 3 4 5 6
2 3 4 5 6 66
No

# 出力例 71
$./a.out
1 2 3 4 5 6
2 3 4 5 6 67
No

# 出力例 72
$./a.out
1 2 3 4 5 6
2 3 4 5 6 68
No

# 出力例 73
$./a.out
1 2 3 4 5 6
2 3 4 5 6 69
No

# 出力例 74
$./a.out
1 2 3 4 5 6
2 3 4 5 6 70
No

# 出力例 75
$./a.out
1 2 3 4 5 6
2 3 4 5 6 71
No

# 出力例 76
$./a.out
1 2 3 4 5 6
2 3 4 5 6 72
No

# 出力例 77
$./a.out
1 2 3 4 5 6
2 3 4 5 6 73
No

# 出力例 78
$./a.out
1 2 3 4 5 6
2 3 4 5 6 74
No

# 出力例 79
$./a.out
1 2 3 4 5 6
2 3 4 5 6 75
No

# 出力例 80
$./a.out
1 2 3 4 5 6
2 3 4 5 6 76
No

# 出力例 81
$./a.out
1 2 3 4 5 6
2 3 4 5 6 77
No

# 出力例 82
$./a.out
1 2 3 4 5 6
2 3 4 5 6 78
No

# 出力例 83
$./a.out
1 2 3 4 5 6
2 3 4 5 6 79
No

# 出力例 84
$./a.out
1 2 3 4 5 6
2 3 4 5 6 80
No

# 出力例 85
$./a.out
1 2 3 4 5 6
2 3 4 5 6 81
No

# 出力例 86
$./a.out
1 2 3 4 5 6
2 3 4 5 6 82
No

# 出力例 87
$./a.out
1 2 3 4 5 6
2 3 4 5 6 83
No

# 出力例 88
$./a.out
1 2 3 4 5 6
2 3 4 5 6 84
No

# 出力例 89
$./a.out
1 2 3 4 5 6
2 3 4 5 6 85
No

# 出力例 90
$./a.out
1 2 3 4 5 6
2 3 4 5 6 86
No

# 出力例 91
$./a.out
1 2 3 4 5 6
2 3 4 5 6 87
No

# 出力例 92
$./a.out
1 2 3 4 5 6
2 3 4 5 6 88
No

# 出力例 93
$./a.out
1 2 3 4 5 6
2 3 4 5 6 89
No

# 出力例 94
$./a.out
1 2 3 4 5 6
2 3 4 5 6 90
No

# 出力例 95
$./a.out
1 2 3 4 5 6
2 3 4 5 6 91
No

# 出力例 96
$./a.out
1 2 3 4 5 6
2 3 4 5 6 92
No

# 出力例 97
$./a.out
1 2 3 4 5 6
2 3 4 5 6 93
No

# 出力例 98
$./a.out
1 2 3 4 5 6
2 3 4 5 6 94
No

# 出力例 99
$./a.out
1 2 3 4 5 6
2 3 4 5 6 95
No

# 出力例 100
$./a.out
1 2 3 4 5 6
2 3 4 5 6 96
No

# 出力例 101
$./a.out
1 2 3 4 5 6
2 3 4 5 6 97
No

# 出力例 102
$./a.out
1 2 3 4 5 6
2 3 4 5 6 98
No

# 出力例 103
$./a.out
1 2 3 4 5 6
2 3 4 5 6 99
No

# 出力例 104
$./a.out
1 2 3 4 5 6
2 3 4 5 6 100
No

# 出力例 105
$./a.out
1 2 3 4 5 6
2 3 4 5 6 101
No

# 出力例 106
$./a.out
1 2 3 4 5 6
2 3 4 5 6 1