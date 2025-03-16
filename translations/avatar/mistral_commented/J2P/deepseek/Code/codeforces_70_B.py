import sys

def main():
    n = int(sys.stdin.readline().strip())
    input_str = sys.stdin.readline().strip()

    max_length = -1
    msg_length = [0] * (len(input_str) // 2)
    count = 0
    idx = 0

    for i in range(len(input_str)):
        c = input_str[i]

        if c == '.' or c == '?' or c == '!':
            msg_length[idx] = count + 1
            idx += 1
            if count + 1 > max_length:
                max_length = count + 1
            count = 0
        else:
            count += 1

    if max_length > n:
        print("Impossible")
        return

    ans = 0

    i = 0
    while i < len(msg_length):
        l = msg_length[i]
        while i < len(msg_length) - 1 and l + msg_length[i + 1] + 1 <= n:
            l += msg_length[i + 1] + 1
            i += 1
        ans += 1
        i += 1

    print(ans)

if __name__ == "__main__":
    main()

