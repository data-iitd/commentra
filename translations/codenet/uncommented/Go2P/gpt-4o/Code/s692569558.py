import sys

def main():
    input_lines = sys.stdin.read().strip().splitlines()
    ds = input_lines[1]  # The second line contains the numbers

    dn = list(map(int, ds.split()))

    sum_result = 0
    for i in range(len(dn)):
        for j in range(i + 1, len(dn)):
            sum_result += dn[i] * dn[j]

    print(sum_result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
