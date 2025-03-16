import sys

class TaskC:
    def solve(self, test_number, input_stream, output_stream):
        n = int(input_stream.readline().strip())  # Read the number of test cases

        cnt = [0] * 5  # Initialize a list of size 5 to store counts

        for _ in range(n):
            # Loop through each test case
            str_input = input_stream.readline().strip()  # Read a string from input

            if str_input[0] == 'M':
                cnt[0] += 1  # Increment the count of 'M'
            elif str_input[0] == 'A':
                cnt[1] += 1  # Increment the count of 'A'
            elif str_input[0] == 'R':
                cnt[2] += 1  # Increment the count of 'R'
            elif str_input[0] == 'C':
                cnt[3] += 1  # Increment the count of 'C'
            elif str_input[0] == 'H':
                cnt[4] += 1  # Increment the count of 'H'

        res = (cnt[0] * cnt[1] * cnt[2] +  # Calculate the first product
               cnt[0] * cnt[1] * cnt[3] +  # Calculate the second product
               cnt[0] * cnt[1] * cnt[4] +  # Calculate the third product
               cnt[0] * cnt[2] * cnt[3] +  # Calculate the fourth product
               cnt[0] * cnt[2] * cnt[4] +  # Calculate the fifth product
               cnt[0] * cnt[3] * cnt[4] +  # Calculate the sixth product
               cnt[1] * cnt[2] * cnt[3] +  # Calculate the seventh product
               cnt[1] * cnt[2] * cnt[4] +  # Calculate the eighth product
               cnt[1] * cnt[3] * cnt[4] +  # Calculate the ninth product
               cnt[2] * cnt[3] * cnt[4])   # Calculate the tenth product

        output_stream.write(str(res) + '\n')  # Write the result to the output

def main():
    input_stream = sys.stdin  # Input stream from standard input
    output_stream = sys.stdout  # Output stream to standard output

    solver = TaskC()  # Create an instance of the TaskC class
    solver.solve(1, input_stream, output_stream)  # Call the solve method

if __name__ == "__main__":
    main()

# <END-OF-CODE>
