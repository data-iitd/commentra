#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int nums[6];
} Dice;

void rotate(Dice *dice, char direction, int times) {
	times %= 4;
	switch (direction) {
	case 'W':
		for (int i = 0; i < times; i++) {
			int tmp = dice->nums[0];
			dice->nums[0] = dice->nums[2];
			dice->nums[2] = dice->nums[5];
			dice->nums[5] = dice->nums[3];
			dice->nums[3] = tmp;
		}
		break;
	case 'E':
		for (int i = 0; i < times; i++) {
			int tmp = dice->nums[0];
			dice->nums[0] = dice->nums[3];
			dice->nums[3] = dice->nums[5];
			dice->nums[5] = dice->nums[2];
			dice->nums[2] = tmp;
		}
		break;
	case 'N':
		for (int i = 0; i < times; i++) {
			int tmp = dice->nums[0];
			dice->nums[0] = dice->nums[4];
			dice->nums[4] = dice->nums[5];
			dice->nums[5] = dice->nums[1];
			dice->nums[1] = tmp;
		}
		break;
	case 'S':
		for (int i = 0; i < times; i++) {
			int tmp = dice->nums[5];
			dice->nums[5] = dice->nums[1];
			dice->nums[1] = dice->nums[0];
			dice->nums[0] = dice->nums[4];
			dice->nums[4] = tmp;
		}
		break;
	}
}

void roll(Dice *dice, char direction, int times) {
	times %= 4;
	switch (direction) {
	case 'R':
		for (int i = 0; i < times; i++) {
			int tmp = dice->nums[3];
			dice->nums[3] = dice->nums[1];
			dice->nums[1] = dice->nums[2];
			dice->nums[2] = dice->nums[4];
			dice->nums[4] = tmp;
		}
		break;
	case 'L':
		for (int i = 0; i < times; i++) {
			int tmp = dice->nums[3];
			dice->nums[3] = dice->nums[4];
			dice->nums[4] = dice->nums[2];
			dice->nums[2] = dice->nums[1];
			dice->nums[1] = tmp;
		}
		break;
	}
}

void printStatus(Dice *dice) {
	printf("	　　　 _ _ _ _\n");
	printf("     _ _ _|%3d|%c|_ _ _ _ _ _\n", dice->nums[0], '|');
	printf("    |%3d|%3d|%3d|%3d|%3d|\n", dice->nums[3], dice->nums[1], dice->nums[2], dice->nums[4], dice->nums[5]);
	printf(" 　       |%3d|\n", dice->nums[5]);
}

int getIndex(int *nums, int target) {
	for (int i = 0; i < 6; i++) {
		if (target == nums[i]) {
			return i;
		}
	}
	return -1;
}

int isEqual(Dice *dice1, Dice *dice2) {
	for (int i = 0; i < 6; i++) {
		if (dice1->nums[i]!= dice2->nums[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	Dice dice1;
	Dice dice2;
	for (int i = 0; i < 6; i++) {
		scanf("%d", &dice1.nums[i]);
	}
	for (int i = 0; i < 6; i++) {
		scanf("%d", &dice2.nums[i]);
	}

	char directionOrder[4] = {'N', 'S', 'W', 'E'};
	char rollOrder[2] = {'R', 'L'};
	int flag = 0;

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 2; l++) {
					Dice tmp;
					tmp.nums[0] = dice2.nums[0];
					tmp.nums[1] = dice2.nums[1];
					tmp.nums[2] = dice2.nums[2];
					tmp.nums[3] = dice2.nums[3];
					tmp.nums[4] = dice2.nums[4];
					tmp.nums[5] = dice2.nums[5];
					rotate(&tmp, directionOrder[k], i);
					roll(&tmp, rollOrder[l], j);
					if (isEqual(&tmp, &dice1)) {
						flag = 1;
						break;
					}
				}
			}
		}
	}
	if (flag) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

