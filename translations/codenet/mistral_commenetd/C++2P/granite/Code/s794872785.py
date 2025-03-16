
import sys

def solve():
    maxsize = 0
    maxcnt = 0
    ans_num = -1
    ans_num2 = -1
    str_v = []  # Vector to store strings read from input

    # Read strings from input
    for in_ in sys.stdin:
        str_v.append(in_.strip())
        # Update maxsize if the current string is larger
        if maxsize < len(in_):
            maxsize = len(in_)
            ans_num = len(str_v) - 1

    # Find the string with maximum occurrences in the vector
    for i in range(len(str_v)):
        cnt = 0
        # Count the occurrences of the current string in the vector
        for j in range(len(str_v)):
            if str_v[i] == str_v[j]:
                cnt += 1
        # Update maxcnt and ans_num2 if the current string has more occurrences
        if maxcnt < cnt:
            maxcnt = cnt
            ans_num2 = i

    # Print the answer
    print(str_v[ans_num2], str_v[ans_num])

# Call the solve function
solve()

