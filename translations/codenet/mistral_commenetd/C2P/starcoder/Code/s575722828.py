#include <stdio.h>

# Read an integer from the standard input
S = int(input())

# Print the hours, minutes, and seconds of the given number of seconds
print(S // 3600, S % 3600 // 60, S % 60)

# Return 0 to indicate successful execution of the program
return 0

