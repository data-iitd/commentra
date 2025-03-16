
# Read the number of test cases
n = int(input())

# Process each test case
for i in range(n):
    s = input()

    # Initialize a set to store unique combinations of strings
    st = set()
    # Insert the original string into the set
    st.add(s)

    # Generate combinations by splitting the string at different positions
    for j in range(1, len(s)):
        # Create the first part of the split string
        res = ""
        for k in range(j):
            res += s[k]
        # Create the second part of the split string
        res2 = ""
        for k in range(j, len(s)):
            res2 += s[k]

        # Create reversed versions of both parts
        t = res
        res = res[::-1] # Reverse the first part
        t2 = res2
        res2 = res2[::-1] # Reverse the second part

        # Insert various combinations of the parts and their reverses into the set
        st.add(t + t2) # Original order
        st.add(t2 + t) # Reversed order

        st.add(t + res2) # First part + second part
        st.add(res2 + t) # Second part + first part

        st.add(res + t2) # First part + reversed second part
        st.add(t2 + res) # Reversed second part + first part

        st.add(res + res2) # First part + second part (both original)
        st.add(res2 + res) # Second part + first part (both original)

    # Output the number of unique combinations generated
    print(len(st))

# 