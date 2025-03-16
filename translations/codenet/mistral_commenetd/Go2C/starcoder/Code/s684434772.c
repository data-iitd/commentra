
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

// The maximum value of an integer64.
#define INT64_MAX ((int64_t)(9223372036854775807))

// The maximum value of an integer.
#define INT_MAX ((int)(2147483647))

// The maximum value of an unsigned integer.
#define UINT_MAX ((uint)(4294967295))

// The maximum value of an unsigned integer64.
#define UINT64_MAX ((uint64_t)(18446744073709551615))

// The maximum value of a size_t.
#define SIZE_MAX ((size_t)(18446744073709551615))

// The maximum value of a ssize_t.
#define SSIZE_MAX ((ssize_t)(9223372036854775807))

// The maximum value of a ptrdiff_t.
#define PTRDIFF_MAX ((ptrdiff_t)(9223372036854775807))

// The maximum value of an unsigned ptrdiff_t.
#define PTRDIFF_MAX ((ptrdiff_t)(9223372036854775807))

// The maximum value of a char.
#define CHAR_MAX ((char)(127))

// The maximum value of an unsigned char.
#define UCHAR_MAX ((unsigned char)(255))

// The maximum value of a short.
#define SHRT_MAX ((short)(32767))

// The maximum value of an unsigned short.
#define USHRT_MAX ((unsigned short)(65535))

// The maximum value of an int.
#define INT_MAX ((int)(2147483647))

// The maximum value of an unsigned int.
#define UINT_MAX ((unsigned int)(4294967295))

// The maximum value of a long.
#define LONG_MAX ((long)(9223372036854775807))

// The maximum value of an unsigned long.
#define ULONG_MAX ((unsigned long)(18446744073709551615))

// The maximum value of a long long.
#define LLONG_MAX ((long long)(9223372036854775807))

// The maximum value of an unsigned long long.
#define ULLONG_MAX ((unsigned long long)(18446744073709551615))

// The maximum value of a float.
#define FLT_MAX ((float)(3.40282346638528860e+38))

// The maximum value of a double.
#define DBL_MAX ((double)(1.79769313486231571e+308))

// The maximum value of a long double.
#define LDBL_MAX ((long double)(1.79769313486231571e+308))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned long long int.
#define ULLONG_MAX ((unsigned long long int)(18446744073709551615))

// The maximum value of a long long int.
#define LLONG_MAX ((long long int)(9223372036854775807))

// The maximum value of an unsigned lon