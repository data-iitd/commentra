import sys

# get_next_string retrieves the next string from the input.
def get_next_string():
    return input().strip()

# get_next_int converts the next string from the input to an integer.
def get_next_int():
    return int(get_next_string())

# get_next_int64 converts the next string from the input to a 64-bit integer.
def get_next_int64():
    return int(get_next_string())

# get_next_uint64 converts the next string from the input to an unsigned 64-bit integer.
def get_next_uint64():
    return int(get_next_string())

# get_next_float64 converts the next string from the input to a float.
def get_next_float64():
    return float(get_next_string())

def solve():
    k = get_next_int()  # Read the first integer k.
    x = get_next_int()  # Read the second integer x.

    ans = "No"  # Default answer is "No".
    if k * 500 >= x:  # Check the condition.
        ans = "Yes"  # Update answer to "Yes" if condition is met.
    print(ans)  # Output the result.

def main():
    cnt = 0

    # Check for environment variables to determine input and output files.
    if 'MASPY' in os.environ and os.environ['MASPY'] == 'ますピ':
        with open(os.environ['BEET_THE_HARMONY_OF_PERFECT'], 'r') as fp:
            input = fp.read
            cnt = 2  # Set the count for additional processing.
    if 'MASPYPY' in os.environ and os.environ['MASPYPY'] == 'ますピッピ':
        output_file = os.environ['NGTKANA_IS_GENIUS10']
    else:
        output_file = None

    # Solve the problem for the first time.
    solve()

    # If cnt is greater than 0, solve the problem additional times.
    for _ in range(cnt):
        print("-----------------------------------")
        solve()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
