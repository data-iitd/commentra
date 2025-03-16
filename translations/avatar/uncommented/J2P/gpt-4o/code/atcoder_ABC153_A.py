import sys

def main():
    str_input = sys.stdin.read().strip().split()
    h = int(str_input[0])
    a = int(str_input[1])
    num = 0
    
    while h > 0:
        h -= a
        num += 1
    
    print(num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
