

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for buffer sizes and modulo value
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1e9 + 7

// Function to read an integer from input
int getInt() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to read a string from input
char* getString() {
	char* str = malloc(sizeof(char) * 1000001);
	scanf("%s", str);
	return str;
}

// Function to return the absolute value of an integer
int abs(int a) {
	return a < 0? -a : a;
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
	int res = 1;
	while (q > 0) {
		if (q & 1) {
			res *= p;
		}
		p *= p;
		q >>= 1;
	}
	return res;
}

// Function to compute (n^p) % mod using exponentiation by squaring
int powMod(int n, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return (t * t) % MOD;
	} else {
		return (n * powMod(n, p - 1)) % MOD;
	}
}

// Function to find the minimum value among a variable number of integers
int min(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = res < nums[i]? res : nums[i];
	}
	return res;
}

// Function to find the maximum value among a variable number of integers
int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = res > nums[i]? res : nums[i];
	}
	return res;
}

// Function to check if a string exists in a slice of strings
int strSearch(char* a[], int n, char* b) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array in a formatted way
void printIntArray(int array[], int n) {
	char str[1000000];
	strcpy(str, "");
	strcat(str, "[");
	for (int i = 0; i < n; i++) {
		char temp[1000000];
		sprintf(temp, "%d", array[i]);
		strcat(str, temp);
		if (i < n - 1) {
			strcat(str, ", ");
		}
	}
	strcat(str, "]");
	printf("%s\n", str);
}

// Function to calculate x % mod
int calcMod(int x) {
	return x % MOD;
}

// Function to reverse a string
char* reverse(char* s) {
	char* res = malloc(sizeof(char) * strlen(s));
	int i = 0, j = strlen(s) - 1;
	while (i < j) {
		res[i] = s[j];
		res[j] = s[i];
		i++;
		j--;
	}
	res[i] = '\0';
	return res;
}

// Function to check if a number is prime
int isPrime(int n) {
	if (n < 2) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else if (n % 2 == 0) {
		return 0;
	}

	// Check for factors from 3 to the square root of n
	int sqrtN = (int) sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

// Function to find the integer square root of a number
int intSqrt(int n) {
	int l = 0, r = n;
	while (l <= r) {
		int m = (l + r) / 2;
		if (m * m <= n) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return l - 1;
}

// Function to find the integer cube root of a number
int intCbrt(int n) {
	int l = 0, r = n;
	while (l <= r) {
		int m = (l + r) / 2;
		if (m * m * m <= n) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return l - 1;
}

// Function to find the GCD of two numbers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

// Function to find the LCM of two numbers
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

// Function to find the factorial of a number
int factorial(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Function to find the number of digits in a number
int numDigits(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res++;
	}
	return res;
}

// Func