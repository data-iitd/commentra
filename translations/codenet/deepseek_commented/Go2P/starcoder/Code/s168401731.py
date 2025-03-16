import sys

# get_next_string reads the next word from the input.
def get_next_string():
    return sys.stdin.readline().strip()

# get_next_int reads the next word from the input and converts it to an integer.
def get_next_int():
    return int(get_next_string())

# get_next_int64 reads the next word from the input and converts it to an int64.
def get_next_int64():
    return int64(get_next_string())

# get_next_uint64 reads the next word from the input and converts it to an uint64.
def get_next_uint64():
    return uint64(get_next_string())

# get_next_float64 reads the next word from the input and converts it to an float64.
def get_next_float64():
    return float64(get_next_string())

# Main function handles file input/output operations.
def main():
    # Read the number of integers to process.
    n = get_next_int()

    # Initialize the answer to "second".
    ans = "second"
    for i in range(n):
        a = get_next_int()
        if a%2 == 1:
            ans = "first"
            break
    # Print the result based on the condition.
    print(ans)

# 