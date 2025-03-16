import sys

class TaskC:
    def solve(self, test_number, input_stream, output_stream):
        n = int(input_stream.readline().strip())
        cnt = [0] * 5
        # Read the number of strings and initialize the count array.

        for _ in range(n):
            str_input = input_stream.readline().strip()
            if str_input[0] == 'M':
                cnt[0] += 1
            elif str_input[0] == 'A':
                cnt[1] += 1
            elif str_input[0] == 'R':
                cnt[2] += 1
            elif str_input[0] == 'C':
                cnt[3] += 1
            elif str_input[0] == 'H':
                cnt[4] += 1
        # Count the occurrences of each character at the start of the strings.

        res = (cnt[0] * cnt[1] * cnt[2] + 
                cnt[0] * cnt[1] * cnt[3] + 
                cnt[0] * cnt[1] * cnt[4] + 
                cnt[0] * cnt[2] * cnt[3] + 
                cnt[0] * cnt[2] * cnt[4] + 
                cnt[0] * cnt[3] * cnt[4] + 
                cnt[1] * cnt[2] * cnt[3] + 
                cnt[1] * cnt[2] * cnt[4] + 
                cnt[1] * cnt[3] * cnt[4] + 
                cnt[2] * cnt[3] * cnt[4])
        output_stream.write(str(res) + '\n')
        # Calculate the number of combinations and print the result.

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = TaskC()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
