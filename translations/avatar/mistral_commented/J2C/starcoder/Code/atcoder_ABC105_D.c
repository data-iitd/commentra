
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define macros for handling errors
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define exitf(...) { eprintf(__VA_ARGS__); exit(EXIT_FAILURE); }

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros for handling overflow
#define INT_MAX 2147483647
#define INT64_MAX 9223372036854775807

// Define macros for handling bitwise operations
#define bit(x, i) ((x) & (1 << (i)))
#define setbit(x, i) ((x) |= (1 << (i)))
#define clearbit(x, i) ((x) &= ~(1 << (i)))
#define togglebit(x, i) ((x) ^= (1 << (i)))
#define is_set(x, i) ((x) & (1 << (i)))

// Define macros fo