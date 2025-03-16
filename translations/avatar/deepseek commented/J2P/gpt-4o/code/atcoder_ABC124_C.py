import sys

class CColoringColorfully:
    def solve(self, test_number, input_string):
        # Read the input string
        x = input_string.strip()
        # Create two lists to manipulate the string
        a = list(x)
        b = list(x)
        # Initialize counters for the number of changes needed
        a1 = 0
        a2 = 0

        # First loop to change characters to make the string colorful
        for i in range(1, len(x)):
            if a[i] == a[i - 1]:
                # Change the character to the opposite
                a[i] = '0' if a[i] == '1' else '1'
                # Increment the counter
                a1 += 1

        # Second loop to change characters to make the string colorful
        for i in range(len(x) - 1, 0, -1):
            if b[i] == b[i - 1]:
                # Change the character to the opposite
                b[i - 1] = '0' if b[i - 1] == '1' else '1'
                # Increment the counter
                a2 += 1

        # Output the minimum number of changes needed
        print(min(a1, a2))

def main():
    input_string = sys.stdin.read()
    solver = CColoringColorfully()
    solver.solve(1, input_string)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
