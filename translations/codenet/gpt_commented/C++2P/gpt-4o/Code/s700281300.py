def main():
    # Read the number of test cases
    n = int(input())

    # Process each test case
    for _ in range(n):
        s = input().strip()

        # Initialize a set to store unique combinations of strings
        st = set()
        # Insert the original string into the set
        st.add(s)

        # Generate combinations by splitting the string at different positions
        for j in range(1, len(s)):
            # Create the first part of the split string
            res = s[:j]  # First part of the string
            res2 = s[j:]  # Second part of the string

            # Create reversed versions of both parts
            t = res
            t2 = res2
            res = res[::-1]  # Reverse the first part
            res2 = res2[::-1]  # Reverse the second part

            # Insert various combinations of the parts and their reverses into the set
            st.add(t + t2)  # Original order
            st.add(t2 + t)  # Reversed order

            st.add(t + res2)  # First part + second part
            st.add(res2 + t)  # Second part + first part

            st.add(res + t2)  # First part + reversed second part
            st.add(t2 + res)  # Reversed second part + first part

            st.add(res + res2)  # First part + second part (both original)
            st.add(res2 + res)  # Second part + first part (both original)

        # Output the number of unique combinations generated
        print(len(st))

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
