import sys

def out(*args):
    print(*args)

# Function to read an integer from standard input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from standard input
def get_string():
    return sys.stdin.readline().strip()

# Function to find the maximum of two integers
def max_val(a, b):
    return a if a > b else b

# Function to find the minimum of two integers
def min_val(a, b):
    return a if a < b else b

# Function to find the absolute value of an integer
def abs_val(a):
    return a if a >= 0 else -a

# Main function
def main():
    # Read input: N, C, K
    N, C, K = map(int, sys.stdin.readline().strip().split())

    # Initialize list t of size N
    t = [get_int() for _ in range(N)]

    # Sort list t in ascending order
    t.sort()

    # Initialize variables: answer counter ans, counter cnt, and end index end
    ans = 1
    cnt = 1
    end = t[0] + K

    # Iterate through list t from index 1 to N-1
    for i in range(1, N):
        # If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
        if cnt < C and t[i] <= end:
            cnt += 1
        else:
            # Reset counter cnt and update end index end to the current element t[i] plus K
            cnt = 1
            end = t[i] + K
            # Increment answer counter ans
            ans += 1

    # Print the final answer
    out(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
