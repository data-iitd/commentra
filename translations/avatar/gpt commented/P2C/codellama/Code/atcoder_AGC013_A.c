#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <assert.h>

// Define a constant for infinity
#define INF (1000000000)

// Define a constant for the modulo value
#define mod (1000000007)

// Define a constant for the number of elements
#define N (100000)

// Define a constant for the maximum value
#define MAX (1000000000)

// Define a constant for the minimum value
#define MIN (-1000000000)

// Define a constant for the maximum double value
#define MAX_DOUBLE (1.7976931348623158e+308)

// Define a constant for the minimum double value
#define MIN_DOUBLE (2.2250738585072014e-308)

// Define a constant for the maximum float value
#define MAX_FLOAT (3.4028234663852886e+38)

// Define a constant for the minimum float value
#define MIN_FLOAT (1.1754943508222875e-38)

// Define a constant for the maximum long double value
#define MAX_LONG_DOUBLE (1.18973149535723176502e+4932)

// Define a constant for the minimum long double value
#define MIN_LONG_DOUBLE (3.36210314311209350626e-4932)

// Define a constant for the maximum unsigned long long value
#define MAX_UNSIGNED_LONG_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long long value
#define MIN_UNSIGNED_LONG_LONG (0)

// Define a constant for the maximum long long value
#define MAX_LONG_LONG (9223372036854775807)

// Define a constant for the minimum long long value
#define MIN_LONG_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned long value
#define MAX_UNSIGNED_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long value
#define MIN_UNSIGNED_LONG (0)

// Define a constant for the maximum long value
#define MAX_LONG (9223372036854775807)

// Define a constant for the minimum long value
#define MIN_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned int value
#define MAX_UNSIGNED_INT (4294967295)

// Define a constant for the minimum unsigned int value
#define MIN_UNSIGNED_INT (0)

// Define a constant for the maximum int value
#define MAX_INT (2147483647)

// Define a constant for the minimum int value
#define MIN_INT (-2147483648)

// Define a constant for the maximum unsigned short value
#define MAX_UNSIGNED_SHORT (65535)

// Define a constant for the minimum unsigned short value
#define MIN_UNSIGNED_SHORT (0)

// Define a constant for the maximum short value
#define MAX_SHORT (32767)

// Define a constant for the minimum short value
#define MIN_SHORT (-32768)

// Define a constant for the maximum unsigned char value
#define MAX_UNSIGNED_CHAR (255)

// Define a constant for the minimum unsigned char value
#define MIN_UNSIGNED_CHAR (0)

// Define a constant for the maximum char value
#define MAX_CHAR (127)

// Define a constant for the minimum char value
#define MIN_CHAR (-128)

// Define a constant for the maximum signed char value
#define MAX_SIGNED_CHAR (127)

// Define a constant for the minimum signed char value
#define MIN_SIGNED_CHAR (-128)

// Define a constant for the maximum unsigned long long value
#define MAX_UNSIGNED_LONG_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long long value
#define MIN_UNSIGNED_LONG_LONG (0)

// Define a constant for the maximum long long value
#define MAX_LONG_LONG (9223372036854775807)

// Define a constant for the minimum long long value
#define MIN_LONG_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned long value
#define MAX_UNSIGNED_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long value
#define MIN_UNSIGNED_LONG (0)

// Define a constant for the maximum long value
#define MAX_LONG (9223372036854775807)

// Define a constant for the minimum long value
#define MIN_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned int value
#define MAX_UNSIGNED_INT (4294967295)

// Define a constant for the minimum unsigned int value
#define MIN_UNSIGNED_INT (0)

// Define a constant for the maximum int value
#define MAX_INT (2147483647)

// Define a constant for the minimum int value
#define MIN_INT (-2147483648)

// Define a constant for the maximum unsigned short value
#define MAX_UNSIGNED_SHORT (65535)

// Define a constant for the minimum unsigned short value
#define MIN_UNSIGNED_SHORT (0)

// Define a constant for the maximum short value
#define MAX_SHORT (32767)

// Define a constant for the minimum short value
#define MIN_SHORT (-32768)

// Define a constant for the maximum unsigned char value
#define MAX_UNSIGNED_CHAR (255)

// Define a constant for the minimum unsigned char value
#define MIN_UNSIGNED_CHAR (0)

// Define a constant for the maximum char value
#define MAX_CHAR (127)

// Define a constant for the minimum char value
#define MIN_CHAR (-128)

// Define a constant for the maximum signed char value
#define MAX_SIGNED_CHAR (127)

// Define a constant for the minimum signed char value
#define MIN_SIGNED_CHAR (-128)

// Define a constant for the maximum unsigned long long value
#define MAX_UNSIGNED_LONG_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long long value
#define MIN_UNSIGNED_LONG_LONG (0)

// Define a constant for the maximum long long value
#define MAX_LONG_LONG (9223372036854775807)

// Define a constant for the minimum long long value
#define MIN_LONG_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned long value
#define MAX_UNSIGNED_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long value
#define MIN_UNSIGNED_LONG (0)

// Define a constant for the maximum long value
#define MAX_LONG (9223372036854775807)

// Define a constant for the minimum long value
#define MIN_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned int value
#define MAX_UNSIGNED_INT (4294967295)

// Define a constant for the minimum unsigned int value
#define MIN_UNSIGNED_INT (0)

// Define a constant for the maximum int value
#define MAX_INT (2147483647)

// Define a constant for the minimum int value
#define MIN_INT (-2147483648)

// Define a constant for the maximum unsigned short value
#define MAX_UNSIGNED_SHORT (65535)

// Define a constant for the minimum unsigned short value
#define MIN_UNSIGNED_SHORT (0)

// Define a constant for the maximum short value
#define MAX_SHORT (32767)

// Define a constant for the minimum short value
#define MIN_SHORT (-32768)

// Define a constant for the maximum unsigned char value
#define MAX_UNSIGNED_CHAR (255)

// Define a constant for the minimum unsigned char value
#define MIN_UNSIGNED_CHAR (0)

// Define a constant for the maximum char value
#define MAX_CHAR (127)

// Define a constant for the minimum char value
#define MIN_CHAR (-128)

// Define a constant for the maximum signed char value
#define MAX_SIGNED_CHAR (127)

// Define a constant for the minimum signed char value
#define MIN_SIGNED_CHAR (-128)

// Define a constant for the maximum unsigned long long value
#define MAX_UNSIGNED_LONG_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long long value
#define MIN_UNSIGNED_LONG_LONG (0)

// Define a constant for the maximum long long value
#define MAX_LONG_LONG (9223372036854775807)

// Define a constant for the minimum long long value
#define MIN_LONG_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned long value
#define MAX_UNSIGNED_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long value
#define MIN_UNSIGNED_LONG (0)

// Define a constant for the maximum long value
#define MAX_LONG (9223372036854775807)

// Define a constant for the minimum long value
#define MIN_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned int value
#define MAX_UNSIGNED_INT (4294967295)

// Define a constant for the minimum unsigned int value
#define MIN_UNSIGNED_INT (0)

// Define a constant for the maximum int value
#define MAX_INT (2147483647)

// Define a constant for the minimum int value
#define MIN_INT (-2147483648)

// Define a constant for the maximum unsigned short value
#define MAX_UNSIGNED_SHORT (65535)

// Define a constant for the minimum unsigned short value
#define MIN_UNSIGNED_SHORT (0)

// Define a constant for the maximum short value
#define MAX_SHORT (32767)

// Define a constant for the minimum short value
#define MIN_SHORT (-32768)

// Define a constant for the maximum unsigned char value
#define MAX_UNSIGNED_CHAR (255)

// Define a constant for the minimum unsigned char value
#define MIN_UNSIGNED_CHAR (0)

// Define a constant for the maximum char value
#define MAX_CHAR (127)

// Define a constant for the minimum char value
#define MIN_CHAR (-128)

// Define a constant for the maximum signed char value
#define MAX_SIGNED_CHAR (127)

// Define a constant for the minimum signed char value
#define MIN_SIGNED_CHAR (-128)

// Define a constant for the maximum unsigned long long value
#define MAX_UNSIGNED_LONG_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long long value
#define MIN_UNSIGNED_LONG_LONG (0)

// Define a constant for the maximum long long value
#define MAX_LONG_LONG (9223372036854775807)

// Define a constant for the minimum long long value
#define MIN_LONG_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned long value
#define MAX_UNSIGNED_LONG (18446744073709551615)

// Define a constant for the minimum unsigned long value
#define MIN_UNSIGNED_LONG (0)

// Define a constant for the maximum long value
#define MAX_LONG (9223372036854775807)

// Define a constant for the minimum long value
#define MIN_LONG (-9223372036854775808)

// Define a constant for the maximum unsigned int value
#define MAX_UNSIGNED_INT (4294967295)

// Define a constant for the minimum unsigned int value
#define MIN_UNSIGNED_INT (0)

// Define a constant for the maximum int value
#define MAX_INT (214748364