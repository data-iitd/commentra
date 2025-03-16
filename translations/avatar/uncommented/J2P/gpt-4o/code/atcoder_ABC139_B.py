import sys

def main():
    sc = sys.stdin.read
    data = sc().split()
    A = int(data[0])
    B = int(data[1])
    
    amari = 0
    result = 0
    result = (B - 1) // (A - 1)
    amari = (B - 1) % (A - 1)
    
    if amari != 0:
        result += 1
    
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
