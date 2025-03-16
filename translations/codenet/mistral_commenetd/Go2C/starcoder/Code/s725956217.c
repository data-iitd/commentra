
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <netpacket/udp.h>
#include <resolv.h>
#include <glob.h>
#include <fnmatch.h>
#include <grp.h>
#include <pwd.h>
#include <shadow.h>
#include <aio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <netpacket/udp.h>
#include <resolv.h>
#include <glob.h>
#include <fnmatch.h>
#include <grp.h>
#include <pwd.h>
#include <shadow.h>
#include <aio.h>
#include <fcntl.h>

// Function out is used for printing output to the console
void out(int x,...) {
	va_list args;
	va_start(args, x);
	for (int i = 0; i < x; i++) {
		printf("%d ", va_arg(args, int));
	}
	printf("\n");
	va_end(args);
}

// Variable sc is used for reading input from the standard input stream
char *sc;

// Function getInt is used for reading an integer value from the standard input
int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function getString is used for reading a string value from the standard input
char *getString() {
	char *x;
	scanf("%s", x);
	return x;
}

// Function max returns the maximum value between two integers
int max(int a, int b) {
	// If the first integer is greater than the second integer, return the first integer
	if (a > b) {
		return a;
	}
	// Otherwise, return the second integer
	return b;
}

// Function min returns the minimum value between two integers
int min(int a, int b) {
	// If the first integer is less than the second integer, return the first integer
	if (a < b) {
		return a;
	}
	// Otherwise, return the second integer
	return b;
}

// Function asub returns the absolute difference between two integers
int asub(int a, int b) {
	// If the first integer is greater than the second integer, return the difference
	if (a > b) {
		return a - b;
	}
	// Otherwise, return the negative difference
	return b - a;
}

// Function abs returns the absolute value of an integer
int abs(int a) {
	// If the integer is greater than or equal to zero, return the integer itself
	if (a >= 0) {
		return a;
	}
	// Otherwise, return the negative of the integer
	return -a;
}

// Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
int lowerBound(int *a, int x, int n) {
	// Initialize the left and right indices
	int l = 0, r = n - 1;
	// Loop until the left index is greater than or equal to the right index
	for (int i = 0; i < n; i++) {
		// If the element at the left index is greater than or equal to the given value
		if (a[l] >= x) {
			// Return the left index
			return l;
		}
		// Otherwise, if the element at the right index is greater than the given value
		if (a[r] > x) {
			// Return the right index
			return r;
		}
		// Otherwise, if the element at the left index is less than the element at the right index
		if (a[l] < a[r]) {
			// Increase the left index by one
			l++;
		} else {
			// Otherwise, increase the right index by one
			r--;
		}
	}
	// Return the left index
	return l;
}

// Function upperBound returns the index of the first element in the slice that is greater than the given value
int upperBound(int *a, int x, int n) {
	// Initialize the left and right indices
	int l = 0, r = n - 1;
	// Loop until the left index is greater than or equal to the right index
	for (int i = 0; i < n; i++) {
		// If the element at the left index is greater than the given value
		if (a[l] > x) {
			// Return the left index
			return l;
		}
		// Otherwise, if the element at the right index is greater than or equal to the given value
		if (a[r] >= x) {
			// Return the right index
			return r;
		}
		// Otherwise, if the element at the left index is less than the element at the right index
		if (a[l] < a[r]) {
			// Increase the left index by one
			l++;
		} else {
			// Otherwise, increase the right index by one
			r--;
		}
	}
	// Return the left index
	return l;
}

// Type shop represents a data structure for storing two integers
struct shop {
	int a, b;
};

// Type Datas is a slice of shop data structures
struct Datas {
	struct shop *data;
	int len, cap;
};

// Function newDatas creates a new slice of shop data structures
struct Datas *newDatas(int n) {
	// Allocate a new slice of shop data structures
	struct Datas *p = malloc(sizeof(struct Datas));
	// Initialize the length and capacity of the slice
	p->len = 0;
	p->cap = n;
	// Allocate a new array of shop data structures
	p->data = malloc(n * sizeof(struct shop));
	// Return the new slice
	return p;
}

// Function freeDatas frees the memory of a slice of shop data structures
void freeDatas(struct Datas *p) {
	// If the slice is not null
	if (p!= NULL) {
		// If the array of shop data structures is not null
		if (p->data!= NULL) {
			// Free the array
			free(p->data);
		}
		// Free the slice
		free(p);
	}
}

// Function appendDatas appends a new shop data structure to a slice of shop data structures
void appendDatas(struct Datas *p, struct shop x) {
	// If the length of the slice is equal to the capacity of the slice
	if (p->len == p->cap) {
		// Double the capacity of the slice
		p->cap *= 2;
		// Reallocate the array of shop data structures
		p->data = realloc(p->data, p->cap * sizeof(struct shop));
	}
	// Copy the shop data structure to the last position of the array
	p->data[p->len] = x;
	// Increase the length of the slice by one
	p->len++;
}

// Function sortDatas sorts a slice of shop data structures in ascending order based on the 'a' field of each shop
void sortDatas(struct Datas *p) {
	// If the length of the slice is greater than one
	if (p->len > 1) {
		// Initialize a variable named i to store the index of the first shop in the slice
		int i = 0;
		// Initialize a variable named j to store the index of the last shop in the slice
		int j = p->len - 1;
		// Initialize a variable named x to store the value of the pivot
		int x = p->data[i].a;
		// Loop until the index of the first shop is greater than or equal to the index of the last shop
		for (int k = 0; k < p->len; k++) {
			// If the value of the pivot is greater than the value of the shop at the index of the last shop
			if (x > p->data[j].a) {
				// Swap the shop at the index of the last shop with the shop at the index of the first shop
				struct shop tmp = p->data[i];
				p->data[i] = p->data[j];
				p->data[j] = tmp;
				// Increase the index of the first shop by one
				i++;
			} else {
				// Otherwise, if the value of the shop at the index of the first shop is greater than the value of the pivot
				if (p->data[i].a > x) {
					// Swap the shop at the index of the last shop with the shop at the index of the first shop
					struct shop tmp = p->data[i];
					p->data[i] = p->data[j];
					p->data[j] = tmp;
					// Decrease the index of the last shop by one
					j--;
				} else {
					// Otherwise, increase the index of the first shop by one
					i++;
				}
			}
		}
		// Sort the slice of shop data structures in ascending order based on the 'a' field of each shop
		sortDatas(p);
		// Sort the slice of shop data structures in ascending order based on the 'b' field of each shop
		sortDatas(p);
	}
}

// Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
int lowerBound(struct Datas *p, int x) {
	// Initialize the left and right indices
	int l = 0, r = p->len - 1;
	// Loop until the left index is greater than or equal to the right index
	for (int i = 0; i < p->len; i++) {
		// If the element at the left index is greater than or equal to the given value
		if (p->data[l].a >= x) {
			// Return the left index
			return l;
		}
		// Otherwise, if the element at the right index is greater than the given value
		if (p->data[r].a > x) {
			// Return the right index
			return r;
		}
		// Otherwise, if the element at the left index is less than the element at the right index
		if (p->data[l].a < p->data[r].a) {
			// Increase the left index by one
			l++;
		} else {
			// Otherwise, increase the right index by one
			r--;
		}
	}
	// Return the left index
	return l;
}

// Function upperBound returns the index of the first element in the slice that is greater than the given value
int upperBound(struct Datas *p, int x) {
	// Initialize the left and right indices
	int l = 0, r = p->len - 1;
	// Loop until the left index is greater than or equal to the right index
	for (i