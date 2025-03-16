import sys

def main():
    n = int(sys.stdin.readline().strip())
    input_text = sys.stdin.readline().strip()

    max_length = -1
    msg_lengths = []
    count = 0
    idx = 0

    # Iterating through the input string to determine message lengths
    for i in range(len(input_text)):
        c = input_text[i]
        if c == '.' or c == '?' or c == '!':
            msg_lengths.append(count + 1)
            if count + 1 > max_length:
                max_length = count + 1
            i += 1
            count = 0
        else:
            count += 1

    # Checking if the maximum message length exceeds the allowed maximum
    if max_length > n:
        print("Impossible")
    else:
        ans = 0
        i = 0
        while i < len(msg_lengths):
            l = msg_lengths[i]
            while i < len(msg_lengths) - 1 and l + msg_lengths[i + 1] + 1 <= n:
                l += msg_lengths[i + 1] + 1
                i += 1
            ans += 1
            i += 1
        print(ans)

if __name__ == "__main__":
    main()
