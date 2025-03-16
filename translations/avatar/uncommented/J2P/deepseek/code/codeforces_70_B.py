import sys

def main():
    n = int(input().strip())
    input_str = input().strip()
    max_length = -1
    msg_lengths = [0] * (len(input_str) // 2)
    count = 0
    idx = 0
    
    for i in range(len(input_str)):
        c = input_str[i]
        if c == '.' or c == '?' or c == '!':
            msg_lengths[idx] = count + 1
            idx += 1
            if count + 1 > max_length:
                max_length = count + 1
            count = 0
            i += 1
        else:
            count += 1
    
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
