
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char **argv) {
    // Define the input size and initialize an empty list for answers
    int q;
    scanf("%d", &q);
    int ans[2] = {0, 0};

    // Import stdio.h for printf and scanf
    #include <stdio.h>

    // Import stdlib.h for malloc and free
    #include <stdlib.h>

    // Import stdlib.h for qsort and bsearch
    #include <stdlib.h>

    // Import stddef.h for NULL
    #include <stddef.h>

    // Import stdbool.h for bool and true/false
    #include <stdbool.h>

    // Import string.h for strlen, strcmp, strcpy, and strcat
    #include <string.h>

    // Import math.h for sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh, exp, log, log10, pow, sqrt, and ceil
    #include <math.h>

    // Import time.h for time, clock_t, CLOCKS_PER_SEC, struct tm, struct timeval, struct timezone, mktime, localtime, gmtime, strftime, and difftime
    #include <time.h>

    // Import sys/time.h for struct timeval and gettimeofday
    #include <sys/time.h>

    // Import sys/resource.h for struct rusage, getrusage, and RUSAGE_SELF
    #include <sys/resource.h>

    // Import sys/times.h for struct tms, clock_t, times, and CLK_TCK
    #include <sys/times.h>

    // Import sys/types.h for pid_t, uid_t, gid_t, and mode_t
    #include <sys/types.h>

    // Import unistd.h for sysconf, _SC_CLK_TCK, getpid, getppid, getuid, geteuid, getgid, getegid, getgroups, setgroups, getlogin, and getpass
    #include <unistd.h>

    // Import errno.h for errno
    #include <errno.h>

    // Import assert.h for assert
    #include <assert.h>

    // Import limits.h for INT_MIN, INT_MAX, LONG_MIN, LONG_MAX, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX, UCHAR_MAX, SHRT_MIN, SHRT_MAX, USHRT_MAX, INT_MIN, INT_MAX, UINT_MAX, LONG_MIN, LONG_MAX, ULONG_MAX, FLOAT_MIN, FLOAT_MAX, DBL_MIN, DBL_MAX, LLONG_MIN, LLONG_MAX, ULLONG_MAX, and EOF
    #include <limits.h>

    // Import stdarg.h for va_list, va_start, va_end, and va_arg
    #include <stdarg.h>

    // Import inttypes.h for PRId8, PRId16, PRId32, PRId64, PRIdLEAST8, PRIdLEAST16, PRIdLEAST32, PRIdLEAST64, PRIdFAST8, PRIdFAST16, PRIdFAST32, PRIdFAST64, PRIdMAX, PRIdPTR, PRIi8, PRIi16, PRIi32, PRIi64, PRIiLEAST8, PRIiLEAST16, PRIiLEAST32, PRIiLEAST64, PRIiFAST8, PRIiFAST16, PRIiFAST32, PRIiFAST64, PRIiMAX, PRIiPTR, PRIo8, PRIo16, PRIo32, PRIo64, PRIoLEAST8, PRIoLEAST16, PRIoLEAST32, PRIoLEAST64, PRIoFAST8, PRIoFAST16, PRIoFAST32, PRIoFAST64, PRIoMAX, PRIoPTR, PRIu8, PRIu16, PRIu32, PRIu64, PRIuLEAST8, PRIuLEAST16, PRIuLEAST32, PRIuLEAST64, PRIuFAST8, PRIuFAST16, PRIuFAST32, PRIuFAST64, PRIuMAX, PRIuPTR, PRIx8, PRIx16, PRIx32, PRIx64, PRIxLEAST8, PRIxLEAST16, PRIxLEAST32, PRIxLEAST64, PRIxFAST8, PRIxFAST16, PRIxFAST32, PRIxFAST64, PRIxMAX, PRIxPTR, PRIX8, PRIX16, PRIX32, PRIX64, PRIXLEAST8, PRIXLEAST16, PRIXLEAST32, PRIXLEAST64, PRIXFAST8, PRIXFAST16, PRIXFAST32, PRIXFAST64, PRIXMAX, PRIXPTR, SCNd8, SCNd16, SCNd32, SCNd64, SCNdLEAST8, SCNdLEAST16, SCNdLEAST32, SCNdLEAST64, SCNdFAST8, SCNdFAST16, SCNdFAST32, SCNdFAST64, SCNdMAX, SCNdPTR, SCNi8, SCNi16, SCNi32, SCNi64, SCNiLEAST8, SCNiLEAST16, SCNiLEAST32, SCNiLEAST64, SCNiFAST8, SCNiFAST16, SCNiFAST32, SCNiFAST64, SCNiMAX, SCNiPTR, SCNo8, SCNo16, SCNo32, SCNo64, SCNoLEAST8, SCNoLEAST16, SCNoLEAST32, SCNoLEAST64, SCNoFAST8, SCNoFAST16, SCNoFAST32, SCNoFAST64, SCNoMAX, SCNoPTR, SCNu8, SCNu16, SCNu32, SCNu64, SCNuLEAST8, SCNuLEAST16, SCNuLEAST32, SCNuLEAST64, SCNuFAST8, SCNuFAST16, SCNuFAST32, SCNuFAST64, SCNuMAX, SCNuPTR, SCNx8, SCNx16, SCNx32, SCNx64, SCNxLEAST8, SCNxLEAST16, SCNxLEAST32, SCNxLEAST64, SCNxFAST8, SCNxFAST16, SCNxFAST32, SCNxFAST64, SCNxMAX, SCNxPTR, INT8_MIN, INT8_MAX, INT16_MIN, INT16_MAX, INT32_MIN, INT32_MAX, INT64_MIN, INT64_MAX, UINT8_MAX, UINT16_MAX, UINT32_MAX, UINT64_MAX, INT_LEAST8_MIN, INT_LEAST8_MAX, INT_LEAST16_MIN, INT_LEAST16_MAX, INT_LEAST32_MIN, INT_LEAST32_MAX, INT_LEAST64_MIN, INT_LEAST64_MAX, UINT_LEAST8_MAX, UINT_LEAST16_MAX, UINT_LEAST32_MAX, UINT_LEAST64_MAX, INT_FAST8_MIN, INT_FAST8_MAX, INT_FAST16_MIN, INT_FAST16_MAX, INT_FAST32_MIN, INT_FAST32_MAX, INT_FAST64_MIN, INT_FAST64_MAX, UINT_FAST8_MAX, UINT_FAST16_MAX, UINT_FAST32_MAX, UINT_FAST64_MAX, INTPTR_MIN, INTPTR_MAX, UINTPTR_MAX, INTMAX_MIN, INTMAX_MAX, UINTMAX_MAX, PTRDIFF_MIN, PTRDIFF_MAX, SIZE_MAX, SCHAR_MIN, SCHAR_MAX, UCHAR_MAX, CHAR_BIT, MB_LEN_MAX, CLK_TCK, EXIT_FAILURE, EXIT_SUCCESS, RAND_MAX, EOF, and NULL
    #include <inttypes.h>

    // Import stddef.h for NULL
    #include <stddef.h>

    // Import stdbool.h for bool and true/false
    #include <stdbool.h>

    // Import string.h for strlen, strcmp, strcpy, and strcat
    #include <string.h>

    // Import math.h for sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh, exp, log, log10, pow, sqrt, and ceil
    #include <math.h>

    // Import time.h for time, clock_t, CLOCKS_PER_SEC, struct tm, struct timeval, struct timezone, mktime, localtime, gmtime, strftime, and difftime
    #include <time.h>

    // Import sys/time.h for struct timeval and gettimeofday
    #include <sys/time.h>

    // Import sys/resource.h for struct rusage, getrusage, and RUSAGE_SELF
    #include <sys/resource.h>

    // Import sys/times.h for struct tms, clock_t, times, and CLK_TCK
    #include <sys/times.h>

    // Import sys/types.h for pid_t, uid_t, gid_t, and mode_t
    #include <sys/types.h>

    // Import unistd.h for sysconf, _SC_CLK_TCK, getpid, getppid, getuid, geteuid, getgid, getegid, getgroups, setgroups, getlogin, and getpass
    #include <unistd.h>

    // Import errno.h for errno
    #include <errno.h>

    // Import assert.h for assert
    #include <assert.h>

    // Import limits.h for INT_MIN, INT_MAX, LONG_MIN, LONG_MAX, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX, UCHAR_MAX, SHRT_MIN, SHRT_MAX, USHRT_MAX, INT_MIN, INT_MAX, UINT_MAX, LONG_MIN, LONG_MAX, ULONG_MAX, FLOAT_MIN, FLOAT_MAX, DBL_MIN, DBL_MAX, LLONG_MIN, LLONG_MAX, ULLONG_MAX, and EOF
    #include <limits.h>

    // Import stdarg.h for va_list, va_start, va_end, and va_arg
    #include <stdarg.h>

    // Import inttypes.h for PRId8, PRId16, PRId32, PRId64, PRIdLEAST8, PRIdLEAST16, PRIdLEAST32, PRIdLEAST64, PRIdFAST8, PRIdFAST16, PRIdFAST32, PRIdFAST64, PRIdMAX, PRIdPTR, PRIi8, PRIi16, PRIi32, PRIi64, PRIiLEAST8, PRIiLEAST16, PRIiLEAST32, PRIiLEAST64, PRIiFAST8, PRIiFAST16, PRIiFAST32, PRIiFAST64, PRIiMAX, PRIiPTR, PRIo8, PRIo16, PRIo32, PRIo64, PRIoLEAST8, PRIoLEAST16, PRIoLEAST32, PRIoLEAST64, PRIoFAST8, PRIoFAST16, PRIoFAST32, PRIoFAST64, PRIoMAX, PRIoPTR, PRIu8, PRIu16, PRIu32, PRIu64, PRIuLEAST8, PRIuLEAST16, PRIuLEAST32, PRIuLEAST64, PRIuFAST8, PRIuFAST16, PRIuFAST32, PRIuFAST64, PRIuMAX, PRIuPTR, PRIx8, PRIx16, PRIx32, PRIx64, PRIxLEAST8, PRIxLEAST16, PRIxLEAST32, PRIxLEAST64, PRIxFAST8, PRIxFAST16, PRIxFAST32, PRIxFAST64, PRIxMAX, PRIxPTR, PRIX8, PRIX16, PRIX32, PRIX64, PRIXLEAST8, PRIXLEAST16, PRIXLEAST32, PRIXLEAST64, PRIXFAST8, PRIXFAST16, PRIXFAST32, PRIXFAST64, PRIXMAX, PRIXPTR, SCNd8, SCNd16, SCNd32, SCNd64, SCNdLEAST8, SCNdLEAST16, SCNdLEAST32, SCNdLEAST64, SCNdFAST8, SCNdFAST16, SCNdFAST32, SCNdFAST64, SCNdMAX, SCNdPTR, SCNi8, SCNi16, SCNi32, SCNi64, SCNiLEAST8, SCNiLEAST16, SCNiLEAST32, SCNiLEAST64, SCNiFAST8, SCNiFAST16, SCNiFAST32, SCNiFAST64, SCNiMAX, SCNiPTR, SCNo8, SCNo16, SCNo32, SCNo64, SCNoLEAST8, SCNoLEAST16, SCNoLEAST32, SCNoLEAST64, SCNoFAST8, SCNoFAST16, SCNoFAST32, SCNoFAST64, SCNoMAX, SCNoPTR, SCNu8, SCNu16, SCNu32, SCNu64, SCNuLEAST8, SCNuLEAST16, SCNuLEAST32, SCNuLEAST64, SCNuFAST8, SCNuFAST16, SCNuFAST32, SCNuFAST64, SCNuMAX, SCNuPTR, SCNx8, SCNx16, SCNx32, SCNx64, SCNxLEAST8, SCNxLEAST16, SCNxLEAST32, SCNxLEAST64, SCNxFAST8, SCNxFAST16, SCNxFAST32, SCNxFAST64, SCNxMAX, SCNxPTR, INT8_MIN, INT8_MAX, INT16_MIN, INT16_MAX, INT32_MIN, INT32_MAX, INT64_MIN, INT64_MAX, UINT8_MAX, UINT16_MAX, UINT32_MAX, UINT64_MAX, INT_LEAST8_MIN, INT_LEAST8_MAX, INT_LEAST16_MIN, INT_LEAST16_MAX, INT_LEAST32_MIN, INT_LEAST32_MAX, INT_LEAST64_MIN, INT_LEAST64_MAX, UINT_LEAST8_MAX, UINT_LEAST16_MAX, UINT_LEAST32_MAX, UINT_LEAST64_MAX, INT_FAST8_MIN, INT_FAST8_MAX, INT_FAST16_MIN, INT_FAST16_MAX, INT_FAST32_MIN, INT_FAST32_MAX, INT_FAST64_MIN, INT_FAST64_MAX, UINT_FAST8_MAX, UINT_FAST16_MAX, UINT_FAST32_MAX, UINT_FAST64_MAX, INTPTR_MIN, INTPTR_MAX, UINTPTR_MAX, INTMAX_MIN, INTMAX_MAX, UINTMAX_MAX, PTRDIFF_MIN, PTRDIFF_MAX, SIZE_MAX, SCHAR_MIN, SCHAR_MAX, UCHAR_MAX, CHAR_BIT, MB_LEN_MAX, CLK_TCK, EXIT_FAILURE, EXIT_SUCCESS, RAND_MAX, EOF, and NULL
    #include <inttypes.h>

    // Import stddef.h for NULL
    #include <stddef.h>

    // Import stdbool.h for bool and true/false
    #include <stdbool.h>

    // Import string.h for strlen, strcmp, strcpy, and strcat
    #include <string.h>

    // Import math.h for sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh, exp, log, log10, pow, sqrt, and ceil
    #include <math.h>

    // Import time.h for time, clock_t, CLOCKS_PER_SEC, struct tm, struct timeval, struct timezone, mktime, localtime, gmtime, strftime, and difftime
    #include <time.h>

    // Import sys/time.h for struct timeval and gettimeofday
    #include <sys/time.h>

    // Import sys/resource.h for struct rusage, getrusage, and RUSAGE_SELF
    #include <sys/resource.h>

    // Import sys/times.h for struct tms, clock_t, and times
    #include <sys/times.h>

    // Import sys/types.h for pid_t, uid_t,