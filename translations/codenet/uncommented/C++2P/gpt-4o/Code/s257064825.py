def main():
    import sys
    input = sys.stdin.read
    str_num = input().strip()
    sum_digits = sum(int(x) for x in str_num)
    
    if sum_digits % 9 == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
