def cout(str):
    print(str)

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    str = data[1]
    
    a = ""
    for i in range(n // 2):
        a += str[i]
    
    if str == a + a:
        cout("Yes")
    else:
        cout("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
