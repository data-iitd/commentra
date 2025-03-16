import sys

# get_next_string retrieves the next string from the input.
def get_next_string():
    return input().strip()

# get_next_int retrieves the next integer from the input.
def get_next_int():
    return int(get_next_string())

# get_next_int64 retrieves the next int64 from the input.
def get_next_int64():
    return int(get_next_string())

# get_next_uint64 retrieves the next uint64 from the input.
def get_next_uint64():
    return int(get_next_string())

# get_next_float64 retrieves the next float64 from the input.
def get_next_float64():
    return float(get_next_string())

# root function finds the root of the given index using path compression.
def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)  # Path compression
    return uni[i]

# MP class holds the string and its pattern matching table.
class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    # init initializes the pattern matching table for the string.
    def init(self, s):
        self.s = s
        n = len(s)
        table = [0] * (n + 1)
        table[0] = -1  # Initialize the first value of the table
        j = -1
        for i in range(n):
            while j >= 0 and s[i] != s[j]:
                j = table[j]  # Update j based on the table
            j += 1
            table[i + 1] = j  # Fill the table with the length of the longest prefix
        self.table = table  # Assign the completed table to the MP instance

def main():
    # Read two strings from input
    s = get_next_string()
    t = get_next_string()

    # Calculate lengths of the input strings
    ns = len(s)
    nt = len(t)

    # Create a list to hold repeated instances of string s
    ss = [s] * ((nt - 1) // ns + 1)

    # Concatenate the repeated strings to form a new string
    sss = ''.join(ss) + ''.join(ss)

    # Initialize a boolean list to track matches
    ok = [False] * ns

    # Initialize a unique index array and a pattern matching structure
    uni = list(range(ns))
    mp = MP()
    mp.init(t)  # Initialize the pattern matching table with string t
    m = 0

    # Check for matches of string t in the concatenated string sss
    for i in range(ns):
        o = True
        while m < nt:
            if t[m] != sss[i + m]:  # Compare characters
                o = False
                break
            m += 1
        ok[i] = o  # Store the result of the match
        if o:
            i += nt - mp.table[m]  # Update index based on the pattern table
            m = mp.table[m]  # Update match index
        while m >= 0 and t[m] != sss[i + m]:
            i += m - mp.table[m]  # Update index if mismatch occurs
            m = mp.table[m]  # Update match index
        i -= 1  # Adjust index for the next iteration
        m += 1  # Move to the next character

    # Calculate the answer based on the matches found
    ans = 0
    for i in range(ns):
        if not ok[i]:
            continue  # Skip if no match
        if not ok[(i + nt) % ns]:
            continue  # Skip if no match for the next index
        r = root(i, uni)  # Find the root of the current index
        rr = root((i + nt) % ns, uni)  # Find the root of the next index
        if rr == r:
            print(-1)  # Output -1 if they are in the same component
            return
        uni[rr] = r  # Union the two components

    # Count the number of matches for each unique root
    counter = [0] * ns
    for i in range(ns):
        r = root(i, uni)  # Find the root for the current index
        if not ok[r]:
            continue  # Skip if no match
        counter[r] += 1  # Increment the count for the root

    # Find the maximum count
    ans = max(counter)

    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
