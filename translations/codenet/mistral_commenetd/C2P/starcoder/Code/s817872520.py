#include <stdio.h>
#include <stdlib.h>

#define INF 0x5fffffff
int a[100002]; // array to store input numbers
int b[100002]; // array to store the minimum number of steps to reach from the start or end

char buf[700002], *p; // buffer to read input from stdin

#define getint() (fgets(p=buf, 10, stdin), getint())

int main()
{
	int w, i, k, f, close, ans; // declare variables

	// read the number of elements in the array 'a'
	fgets(p=buf, 10, stdin);
	w = getint();

	// read the elements of array 'a'
	fgets(p=buf, sizeof(buf), stdin);
	for (ans = 0, f = 0, i = 1; i <= w; i++) {
		// read an element of array 'a'
		k = getint();
		p++;

		// check if the current element is zero
		if (!k) {
			f |= 1; // set flag 'f' if there is an element with zero value
			continue;
		}

		// if the current element is negative, update the 'close' variable
		// and set flag 'f' to -2 if all elements are negative
		if (k < 0) {
			if (f < 0 || close - (i-f) > -k) close = -k, f = i;
			if (f < 0) f = -2;
		}

		// update the 'ans' variable
		ans += k;
	}

	// check if the sum of all positive elements is zero or if flag 'f' is 1
	if (!ans ||!(f & 1)) {
		puts("0"); // print 0 if the condition is true
		return 0;
	}

	// if all elements are not negative, calculate the minimum number of steps to reach from the start or end
	if (!(f & 2)) {
		printf("%d\n", ans); // print the answer
		return 0;
	}

	// initialize variables for the second loop
	for (close = 0, f = w, i = w; i >= 1; i--) {
		// read an element of array 'a'
		if (!a[i]) {
			close = INF;
			f = -1;
			continue;
		}

		if (a[i] < 0) {
			// if the current element is negative, update the 'close' variable
			// and set flag 'f' to the index of the current element
			if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i;
		} else {
			// if the current element is positive, update the 'b' array
			b[i] = INF;
			if (f >= 0) {
				int k = close - (f-i); // calculate the minimum number of steps to reach from the start to the current index
				if (k < 0) k = 0; // if the number is negative, set it to zero
				b[i] = k; // update the 'b' array
			}
		}
	}

	// initialize variables for the third loop
	for (close = 0, f = w, i = 1; i <= w; i++) {
		// read an element of array 'a'
		if (a[i] > 0) {
			// if the current element is positive, update the 'ans' variable
			if (b[i] > a[i]) ans += a[i];
			else             ans += b[i];
		}
	}

	// print the answer
	printf("%d\n", ans);
	return 0;
}

