
#include <stdio.h>
#include <math.h>

int walkOnMultiplicationTable(int num) {

	int div = 0;
	for (int i = sqrt(num); i > 1; i--) {
		if (num%i == 0) {
			div = i;
			break;
		}
	}
	if (div == 0) {
		return num - 1;
	}
	return div + num/div - 2;

}

int main() {
	int a;
	scanf("%d", &a);
	printf("%d\n", walkOnMultiplicationTable(a));
	return 0;
}
