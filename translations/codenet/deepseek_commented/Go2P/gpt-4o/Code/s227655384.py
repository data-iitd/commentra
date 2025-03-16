import sys

def read_long_lines(times):
    result = []
    for _ in range(times):
        line = sys.stdin.readline().rstrip('\n')
        result.append(line)
    return result

class Console:
    def __init__(self):
        self.buffer = []

    def printf(self, format_str, *args):
        self.buffer.append(format_str % args)

    def println(self, s):
        self.buffer.append(s)

    def flush(self):
        print(''.join(self.buffer), end='')
        self.buffer.clear()

def print_list(lst):
    con = Console()
    for i in range(len(lst)):
        if i == 0:
            con.printf("%d", lst[i])
        else:
            con.printf(" %d", lst[i])
    con.println("")
    con.flush()

def main():
    con = Console()

    # Create a set to store unique elements.
    unique_elements = set()
    lines = read_long_lines(4)

    # Split the second line into individual elements and add them to the set.
    a = lines[1].split()
    for num in a:
        unique_elements.add(int(num))

    # Process the fourth line to toggle the presence of elements in the set.
    result = []
    b = lines[3].split()
    for num in b:
        n = int(num)
        if n in unique_elements:
            unique_elements.remove(n)
        else:
            unique_elements.add(n)

    # Extract the unique elements from the set and sort them.
    result = sorted(unique_elements)

    # Print the sorted list of unique elements.
    for j in result:
        con.printf("%d\n", j)
    con.flush()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
