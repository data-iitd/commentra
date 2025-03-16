

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *sage;
	scanf("%s", &sage);
	switch (sage[0]) {
	case '1':
		printf("Hello World\n");
		break;
	case '2':
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			int num;
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
		break;
	}
}

