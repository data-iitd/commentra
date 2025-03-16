import sys

# out is a utility function to print multiple values with a newline.
def out(*args):
    # print(*args)
    pass

# next_int reads an integer from the input.
def next_int():
    return int(sys.stdin.readline().strip())

# next_string reads a string from the input.
def next_string():
    return sys.stdin.readline().strip()

# Data represents a structure holding a string.
class Data:
    def __init__(self, x):
        self.x = x

# The main function reads N strings, sorts them, and prints the concatenated result.
def main():
    N = next_int()
    L = next_int()
    s = []

    for _ in range(N):
        s.append(Data(next_string()))

    out(N, L, s)
    s.sort(key=lambda data: data.x)
    out(s)

    ans = ""
    for data in s:
        ans += data.x
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
