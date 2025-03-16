
# Python 3 program to count number of unique substrings
# of a given string

# Function to count number of unique substrings
# of a given string
def countUniqueSubstrings(s):

    # Create an empty set to store unique substrings
    st = set()

    # Process each substring of the string
    for j in range(1, len(s) + 1):

        # Create a stringstream to store the substring
        ss = ""

        # Iterate through the first j characters of the string
        for k in range(j):

            # Add the character to the stringstream
            ss += s[k]

        # Get the substring as a string from the stringstream
        res = ss

        # Create another stringstream to process the remaining characters of the string
        ss2 = ""

        # Iterate through the remaining characters of the string
        for k in range(j, len(s)):

            # Add the character to the stringstream
            ss2 += s[k]

        # Get the substring as a string from the stringstream
        res2 = ss2

        # Create two temporary strings by reversing the substrings
        t = res
        res = res[::-1]
        t2 = res2
        res2 = res2[::-1]

        # Insert all possible combinations of the substrings and their reversed versions into the set
        st.add(t + t2)
        st.add(t2 + t)
        st.add(t + res2)
        st.add(res2 + t)
        st.add(res + t2)
        st.add(t2 + res)
        st.add(res + res2)
        st.add(res2 + res)

    # Return the size of the set, which represents the number of unique substrings
    return len(st)

# Driver Code
if __name__ == '__main__':

    # Read the number of strings from the standard input
    n = int(input())

    # Iterate through each string
    for i in range(n):

        # Read the string from the standard input
        s = input()

        # Count the number of unique substrings
        print(countUniqueSubstrings(s))

