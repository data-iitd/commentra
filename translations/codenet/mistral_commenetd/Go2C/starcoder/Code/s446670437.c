#include <stdio.h>
#include <stdlib.h>

// Define a Dice struct with a Numbers slice to store the numbers on the dice.
typedef struct {
	int *Nums;
} Dice;

// Function to rotate the dice in a given direction by a given number of times.
void rotate(Dice *d, char direction, int times) {
	times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
	switch (direction) {
	case 'W': // West direction rotation logic
		for (int i = 0; i < times; i++) {
			int tmp = d->Nums[0];
			d->Nums[0] = d->Nums[2];
			d->Nums[2] = d->Nums[5];
			d->Nums[5] = d->Nums[3];
			d->Nums[3] = tmp;
		}
	case 'E': // East direction rotation logic
		for (int i = 0; i < times; i++) {
			int tmp = d->Nums[0];
			d->Nums[0] = d->Nums[3];
			d->Nums[3] = d->Nums[5];
			d->Nums[5] = d->Nums[2];
			d->Nums[2] = tmp;
		}
	case 'N': // North direction rotation logic
		for (int i = 0; i < times; i++) {
			int tmp = d->Nums[0];
			d->Nums[0] = d->Nums[4];
			d->Nums[4] = d->Nums[5];
			d->Nums[5] = d->Nums[1];
			d->Nums[1] = tmp;
		}
	case 'S': // South direction rotation logic
		for (int i = 0; i < times; i++) {
			int tmp = d->Nums[5];
			d->Nums[5] = d->Nums[1];
			d->Nums[1] = d->Nums[0];
			d->Nums[0] = d->Nums[4];
			d->Nums[4] = tmp;
		}
	}
}

// Function to roll the dice in a given direction by a given number of times.
void roll(Dice *d, char direction, int times) {
	times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
	switch (direction) {
	case 'R': // Right direction roll logic
		for (int i = 0; i < times; i++) {
			int tmp = d->Nums[3];
			d->Nums[3] = d->Nums[1];
			d->Nums[1] = d->Nums[2];
			d->Nums[2] = d->Nums[4];
			d->Nums[4] = tmp;
		}
	case 'L': // Left direction roll logic
		for (int i = 0; i < times; i++) {
			int tmp = d->Nums[3];
			d->Nums[3] = d->Nums[4];
			d->Nums[4] = d->Nums[2];
			d->Nums[2] = d->Nums[1];
			d->Nums[1] = tmp;
		}
	}
}

// Function to print the current status of the dice.
void printStatus(Dice *d) {
	printf("	　　　 _ _ _ _\n");
	printf("     _ _ _|%3d|%_ _ _ _ _ _\n", d->Nums[0]);
	printf("|%3d|%3d|%3d|%3d|%3d|\n", d->Nums[3], d->Nums[1], d->Nums[2], d->Nums[4], d->Nums[5]);
	printf("      |%3d|\n", d->Nums[1]);
	printf("\n");
}

// Function to get the index of a target number in a given slice.
int getIndex(int *nums, int target) {
	for (int i = 0; i < 6; i++) {
		if (nums[i] == target) {
			return i;
		}
	}
	return -1;
}

// Function to check if two dice have the same numbers.
bool isEqual(Dice *d, Dice other) {
	for (int i = 0; i < 6; i++) {
		if (d->Nums[i]!= other.Nums[i]) {
			return false;
		}
	}
	return true;
}

// Main function to read user input and check if two dice are the same after certain rotations and rolls.
int main() {
	Dice dice1;
	dice1.Nums = (int *)malloc(sizeof(int) * 6);
	for (int i = 0; i < 6; i++) {
		scanf("%d", &dice1.Nums[i]);
	}
	Dice dice2;
	dice2.Nums = (int *)malloc(sizeof(int) * 6);
	for (int i = 0; i < 6; i++) {
		scanf("%d", &dice2.Nums[i]);
	}

	char directionOrder[4] = {'N', 'S', 'W', 'E'}; // Order of directions to rotate
	char rollOrder[2] = {'R', 'L'};                 // Order of rolls
	bool flag = false;

	// Check all possible combinations of rotations and rolls to find if the dice are the same.
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k < 4; k++) {
				Dice tmp;
				tmp.Nums = (int *)malloc(sizeof(int) * 6);
				for (int l = 0; l < 6; l++) {
					tmp.Nums[l] = dice2.Nums[l];
				}
				rotate(&tmp, directionOrder[k], i);
				roll(&tmp, rollOrder[j], j);
				if (isEqual(&dice1, tmp)) {
					flag = true;
					break;
				}
			}
		}
	}
	if (flag) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}

