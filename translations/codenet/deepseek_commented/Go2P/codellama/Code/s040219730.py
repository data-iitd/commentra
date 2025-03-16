
#!/usr/bin/env python3

import sys
import math

#
# 1. Read from stdin, and write to stdout.
#

#
# 2. Read integers from stdin.
#
def read_int():
    return int(sys.stdin.readline().rstrip())

def read_ints():
    return list(map(int, sys.stdin.readline().split()))

#
# 3. Print integers to stdout.
#
def print_int(x):
    print(x)

def print_ints(xs):
    print(*xs, sep=' ')

#
# 4. Read a line from stdin, and return a string.
#
def read_line():
    return sys.stdin.readline().rstrip()

#
# 5. Print a line to stdout.
#
def print_line(s):
    print(s)

#
# 6. Read a line from stdin, and return a list of integers.
#
def read_int_list():
    return list(map(int, sys.stdin.readline().split()))

#
# 7. Read a line from stdin, and return a list of strings.
#
def read_string_list():
    return sys.stdin.readline().rstrip().split()

#
# 8. Read a line from stdin, and return a list of integers.
#
def read_int_matrix():
    return [list(map(int, sys.stdin.readline().split())) for _ in range(read_int())]

#
# 9. Read a line from stdin, and return a list of strings.
#
def read_string_matrix():
    return [sys.stdin.readline().rstrip().split() for _ in range(read_int())]

#
# 10. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list():
    return [read_int_matrix() for _ in range(read_int())]

#
# 11. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list():
    return [read_string_matrix() for _ in range(read_int())]

#
# 12. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list():
    return [[read_int_list() for _ in range(read_int())] for _ in range(read_int())]

#
# 13. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list():
    return [[read_string_list() for _ in range(read_int())] for _ in range(read_int())]

#
# 14. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list():
    return [[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 15. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list():
    return [[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 16. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list():
    return [[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 17. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list():
    return [[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 18. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list():
    return [[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 19. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list():
    return [[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 20. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list():
    return [[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 21. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list():
    return [[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 22. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list():
    return [[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 23. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list_list():
    return [[[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 24. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list_list():
    return [[[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 25. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list_list_list():
    return [[[[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 26. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 27. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 28. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 29. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 30. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 31. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 32. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 33. Read a line from stdin, and return a list of lists of strings.
#
def read_string_matrix_list_list_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[[[read_line() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 34. Read a line from stdin, and return a list of lists of integers.
#
def read_int_matrix_list_list_list_list_list_list_list_list_list_list_list_list_list():
    return [[[[[[[[[[[[[read_int() for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())] for _ in range(read_int())]

#
# 35. Re