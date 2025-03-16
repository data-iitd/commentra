# Python code to achieve the same functionality as the provided Go code

import sys
from collections import defaultdict

# input_scanner type is a custom class for reading input
class input_scanner:
    def __init__(self, enabled_scan_words=True, size_in_kb=256):
        self.enabled_scan_words = enabled_scan_words
        self.size_in_kb = size_in_kb
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next_int(self):
        return int(self.next_str())

    def next_uint64(self):
        return int(self.next_str())

    def next_str(self):
        if self.index >= len(self.buffer):
            self.buffer = sys.stdin.read().split()
            self.index = 0
        result = self.buffer[self.index]
        self.index += 1
        return result

# Main function
def main():
    sc = input_scanner(True, 256)
    N, P, S = sc.next_int(), sc.next_int(), sc.next_str()
    answer = check_sub_numbers(N, P, S)
    print(answer)

# Function to check if any subnumber of given string S is divisible by prime number P
def check_sub_numbers(N, P, S):
    if P == 2 or P == 5:
        return check_two_or_five(N, P, S)
    else:
        return check_not_two_nor_five(N, P, S)

# Function to check if any subnumber of given string S is divisible by prime number P equal to 2 or 5
def check_two_or_five(N, P, S):
    answer = 0
    for i in range(N - 1, -1, -1):
        n = int(S[i])
        if n % P == 0:
            answer += i + 1
    return answer

# Function to check if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
def check_not_two_nor_five(N, P, S):
    multiplier = 1
    answer = 0
    remainder_lookup = defaultdict(int)
    prev_remainder = -1
    for i in range(N - 1, -1, -1):
        digit = int(S[i])
        if prev_remainder == -1:
            remainder = digit % P
        else:
            remainder = ((multiplier * digit) % P + prev_remainder) % P
        if remainder == 0:
            answer += 1
        answer += remainder_lookup[remainder]
        remainder_lookup[remainder] += 1
        prev_remainder = remainder
        multiplier = (multiplier * 10) % P
    return answer

# Call the main function
main()
