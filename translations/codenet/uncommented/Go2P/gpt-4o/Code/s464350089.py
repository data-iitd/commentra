import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    h = int(data[0])
    n = int(data[1])
    a = sum(int(data[i + 2]) for i in range(n))  # data[2] to data[n+1] are the integers

    if h > a:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
