
import sys

def check_sub_numbers(N, P, S):
    answer = 0
    for i in range(N - 1, -1, -1):
        if int(S[i]) % P == 0:
            answer += i + 1
    return answer

def check_not_two_nor_five(N, P, S):
    multiplier = 1
    answer = 0
    remainder_lookup = [0] * P
    prev_remainder = -1
    digit = 0
    remainder = 0
    count = 0
    for i in range(N - 1, -1, -1):
        digit = int(S[i])
        if prev_remainder == -1:
            remainder = digit % P
        else:
            remainder = ((multiplier * digit) % P + prev_remainder) % P
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
    sc = input_scanner(True, 256)
    N, P, S = sc.nextInt(), sc.nextInt(), sc.nextStr()
    answer = check_sub_numbers(N, P, S) if P in [2, 5] else check_not_two_nor_five(N, P, S)
    print(answer)

def input_scanner(enabled_scan_words, size_in_kb):
    scanner = bufio.Scanner(sys.stdin)
    if enabled_scan_words:
        scanner.word_chars = ''.join(c for c in scanner.word_chars if c!= '_')
        scanner.scan_words()
    capacity = size_in_kb * 1024
    buf = bytearray(capacity)
    scanner.buffer = buf, capacity
    return scanner

if __name__ == "__main__":
    main()

