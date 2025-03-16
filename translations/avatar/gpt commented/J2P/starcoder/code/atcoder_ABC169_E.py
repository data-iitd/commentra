
# Define a constant number for modulo operations
num = 998244353

# Initialize BufferedReader to read input from standard input
bf = BufferedReader(InputStreamReader(sys.stdin))

# Initialize PrintWriter to output results to standard output
out = PrintWriter(sys.stdout)

# Read the number of pairs (n) from input
n = int(bf.readline())

# Create two lists to store the two sets of integers
ai = []
bi = []

# Read n pairs of integers from input
for i in range(n):
    st = bf.readline().split()
    # Add the first integer of the pair to the first list
    ai.append(int(st[0]))
    # Add the second integer of the pair to the second list
    bi.append(int(st[1]))

# Sort both lists to prepare for median calculation
ai.sort()
bi.sort()

# Check if the number of elements is odd
if n % 2 == 1:
    # Calculate the result for odd n using the median values
    out.println(bi[len(bi) / 2] - ai[len(ai) / 2] + 1)
    out.close()
else:
    # Calculate the average of the two middle values for even n
    b = (ai[len(ai) / 2] + ai[len(ai) / 2 - 1] + 0.0) / 2
    c = (bi[len(bi) / 2] + bi[len(bi) / 2 - 1] + 0.0) / 2
    # Calculate the result for even n and print it
    out.println(int(2 * (c - b) + 1))
    out.close()

# 