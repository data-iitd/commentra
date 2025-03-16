import sys
from collections import Counter

class Task:
    def solve(self, input_stream, output_stream):
        n = int(input_stream.readline().strip())  # Reading the number of elements
        elements = list(map(int, input_stream.readline().strip().split()))  # Reading the elements
        count = Counter(elements)  # Counting occurrences of each element
        count_max = max(count.values())  # Finding the maximum count

        if n % 2 == 0:  # Checking if n is even
            if count_max <= n // 2:  # Checking if the maximum count is less than or equal to half of n
                output_stream.write("YES\n")  # Printing "YES" if the condition is met
            else:
                output_stream.write("NO\n")  # Printing "NO" if the condition is not met
        else:  # If n is odd
            if count_max <= n // 2 + 1:  # Checking if the maximum count is less than or equal to half of n rounded up
                output_stream.write("YES\n")  # Printing "YES" if the condition is met
            else:
                output_stream.write("NO\n")  # Printing "NO" if the condition is not met

def main():
    input_stream = sys.stdin  # Setting up input stream
    output_stream = sys.stdout  # Setting up output stream
    solver = Task()  # Creating an instance of the Task class
    solver.solve(input_stream, output_stream)  # Calling the solve method of the Task class

if __name__ == "__main__":
    main()

# <END-OF-CODE>
