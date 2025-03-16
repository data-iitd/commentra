# Import necessary libraries
from collections import defaultdict

# Main function starts here
def main():
    n = int(input())  # number of strings to be processed

    # Iterate through each string
    for _ in range(n):
        s = input()  # string to be processed

        # Create an empty set to store unique substrings
        st = set()

        # Process each substring of the string
        for j in range(1, len(s)):
            # Create the first substring
            res = s[:j]
            # Create the second substring
            res2 = s[j:]

            # Create two temporary strings by reversing the substrings
            t = res
            t2 = res2
            res_reversed = res[::-1]
            res2_reversed = res2[::-1]

            # Insert all possible combinations of the substrings and their reversed versions into the set
            st.add(t + t2)
            st.add(t2 + t)
            st.add(t + res2)
            st.add(res2 + t)
            st.add(res + t2)
            st.add(t2 + res)
            st.add(res + res2)
            st.add(res2 + res)

        # Print the size of the set, which represents the number of unique substrings
        print(len(st))

# Main function ends here
if __name__ == "__main__":
    main()

# <END-OF-CODE>
