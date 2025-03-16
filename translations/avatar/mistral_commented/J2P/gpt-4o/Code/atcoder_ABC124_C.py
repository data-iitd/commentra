import sys

class CColoringColorfully:
    def solve(self, test_number, input_stream, output_stream):
        x = input_stream.readline().strip()  # Read the input string
        a = list(x)  # Create a list 'a' with the same characters as 'x'
        b = list(x)  # Create a list 'b' with the same characters as 'x'
        a1 = 0  # Initialize counter for number of consecutive '1's in list 'a'
        a2 = 0  # Initialize counter for number of consecutive '1's in list 'b'

        # Loop through each character in list 'a' starting from index 1
        for i in range(1, len(x)):
            if a[i] == a[i - 1]:  # Check if current character is same as previous character
                a[i] = '0' if a[i] == '1' else '1'  # Toggle the character
                a1 += 1  # Increment counter for number of consecutive '1's

        # Loop through each character in list 'b' starting from the last character
        for i in range(len(x) - 1, 0, -1):
            if b[i] == b[i - 1]:  # Check if current character is same as previous character
                b[i - 1] = '0' if b[i - 1] == '1' else '1'  # Toggle the character
                a2 += 1  # Increment counter for number of consecutive '1's

        # Print the minimum number of consecutive '1's in lists 'a' and 'b'
        output_stream.write(str(min(a1, a2)) + '\n')

def main():
    input_stream = sys.stdin  # Input stream to read input from standard input
    output_stream = sys.stdout  # Output stream to write output to standard output
    solver = CColoringColorfully()  # Initialize solver object
    solver.solve(1, input_stream, output_stream)  # Solve the problem and print the output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
