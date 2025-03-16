def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    s = data[1]
    
    rc = gc = bc = 0
    
    for char in s:
        if char == 'R':
            rc += 1
        elif char == 'G':
            gc += 1
        else:
            bc += 1
            
    result = rc * gc * bc
    
    for i in range(1, n + 1):
        for k in range(i + 1, n + 1):
            if (i + k) % 2 == 0:
                is_char = s[i - 1]
                ks_char = s[k - 1]
                js_char = s[(i + k) // 2 - 1]
                if is_char != ks_char and ks_char != js_char and js_char != is_char:
                    result -= 1
                    
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
