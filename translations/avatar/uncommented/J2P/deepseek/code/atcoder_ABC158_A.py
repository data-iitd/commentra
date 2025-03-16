def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    s = data[0]
    if 'A' in s and 'B' in s:
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    main()
