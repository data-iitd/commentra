import sys

def main():
    input_array = sys.stdin.read().strip().split()
    result = 0
    for str in input_array:
        result += 1
        if str == "0":
            break
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
