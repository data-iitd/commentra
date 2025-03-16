import sys

class InputScanner:
    def __init__(self):
        self.input = sys.stdin.read().split()
        self.index = 0

    def next_int(self):
        value = int(self.input[self.index])
        self.index += 1
        return value

    def next_str(self):
        value = self.input[self.index]
        self.index += 1
        return value

def check_sub_numbers(N, P, S):
    if P in (2, 5):
        return check_two_or_five(N, P, S)
    else:
        return check_not_two_nor_five(N, P, S)

def check_two_or_five(N, P, S):
    answer = 0
    for i in range(N - 1, -1, -1):
        n = int(S[i])
        if n % P == 0:
            answer += i + 1
    return answer

def check_not_two_nor_five(N, P, S):
    multiplier = 1  # 10^i % P
    answer = 0
    remainder_lookup = [0] * P
    prev_remainder = -1

    for i in range(N - 1, -1, -1):
        digit = int(S[i])
        if prev_remainder == -1:  # first digit
            remainder = digit % P
        else:
            remainder = (multiplier * digit % P + prev_remainder) % P
        
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
    scanner = InputScanner()
    N = scanner.next_int()
    P = scanner.next_int()
    S = scanner.next_str()
    answer = check_sub_numbers(N, P, S)
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
