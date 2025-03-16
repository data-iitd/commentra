def main():
    import sys
    input = sys.stdin.read
    number = int(input().strip())
    ans = -1
    value = 0
    mask = 2
    
    while value < number:
        s = bin(mask)[2:]  # Get binary representation and remove '0b' prefix
        mask += 1
        zeros = s.count('0')
        
        if zeros != len(s) - zeros:
            continue
        
        s = s.replace('0', '4').replace('1', '7')
        value = int(s)
    
    print(value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
