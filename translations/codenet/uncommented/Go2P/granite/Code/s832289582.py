
import sys

def check_sub_numbers(N, P, S):
    if P == 2 or P == 5:
        return check_two_or_five(N, P, S)
    else:
        return check_not_two_nor_five(N, P, S)

def check_two_or_five(N, P, S):
    answer = 0
    n = 0
    for i in range(N - 1, -1, -1):
        n = int(S[i])
        if n % P == 0:
            answer += i + 1
    return answer

def check_not_two_nor_five(N, P, S):
    multiplier = 1 # 10^i % P
    answer = 0
    remainder_lookup = [0] * P
    prev_remainder = -1
    digit = 0
    remainder = 0
    count = 0
    for i in range(N - 1, -1, -1):
        digit = int(S[i])
        if prev_remainder == -1: # first digit
            remainder = digit % P
        else:
            remainder = (((multiplier * digit) % P) + prev_remainder) % P
        if remainder == 0:
            answer += 1
        count = remainder_lookup[remainder]
        answer += count
        count += 1
        remainder_lookup[remainder] = count
        prev_remainder = remainder
        multiplier = (multiplier * 10) % P
    return answer

def main():
    sc = InputScanner(True, 256)
    N, P, S = sc.nextInt(), sc.nextInt(), sc.nextStr()
    answer = check_sub_numbers(N, P, S)
    print(answer)

class InputScanner:
    def __init__(self, enabled_scan_words, size_in_KB):
        self.scanner = bufio.Scanner(sys.stdin)
        if enabled_scan_words:
            self.scanner.word_chars = '.'
        capacity = size_in_KB * 1024
        buf = bytearray(capacity)
        self.scanner.buffer = buf, capacity

    def nextInt(self):
        i = int(self.nextStr())
        return i

    def nextUInt64(self):
        i = int(self.nextStr())
        return i

    def nextStr(self):
        self.scanner.scan()
        return self.scanner.string()

if __name__ == "__main__":
    main()

