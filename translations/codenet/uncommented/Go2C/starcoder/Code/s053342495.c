#include <stdio.h>

int main() {
	int day;
	scanf("%d", &day);

	switch (day) {
	case 25:
		printf("Christmas\n");
	case 24:
		printf("Christmas Eve\n");
	case 23:
		printf("Christmas Eve Eve\n");
	case 22:
		printf("Christmas Eve Eve Eve\n");
	}
}
