#include <bits/stdc++.h>

using namespace std;

// function to read an integer from the input buffer
int getint()
{
	int n = 0;
	if (*p == '-') { // check if the number is negative
		p++;
		while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf); // read the digits
		return -n; // return the negative number
	}
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf); // read the digits
	return n; // return the number
}

int main()
{
	int w, i, k, f, close, ans; // declare variables

	// read the number of elements in the array 'a'
	cin >> w;

	// read the elements of array 'a'
	for (ans = 0, f = 0, i = 1; i <= w; i++) {
		// read an element of array 'a'
		cin >> k;
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
		cout << "0" << endl; // print 0 if the condition is true
		return 0;
	}

	// if all elements are not negative, calculate the minimum number of steps to reach from the start or end
	if (!(f & 2)) {
		cout << ans << endl; // print the answer
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
	cout << ans << endl;
	return 0;
}

