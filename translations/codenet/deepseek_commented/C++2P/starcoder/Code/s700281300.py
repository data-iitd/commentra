
# Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.
n = int(input())

# Step 2: Processing Each Test Case - The outer loop rep(i,n) iterates over each test case.
for i in range(n):
    s = input() # For each test case, the program reads a string s.

    st = set() # Step 3: Generating Substrings and Checking for Palindromes - A set st is used to store unique substrings.
    st.add(s) # The first substring is inserted into the set.

    # The inner loop REP(j,1,s.size()) iterates over possible split points in the string s.
    for j in range(1,len(s)):
        res = s[:j] # The first part of the string is extracted and reversed.
        res = res[::-1]

        res2 = s[j:] # The second part of the string is extracted and reversed.
        res2 = res2[::-1]

        t = res + res2 # The first part is concatenated with the reversed second part in both orders and added to the set.
        st.add(t)
        t = res2 + res
        st.add(t)

        t = res + s[j:] # The first part is concatenated with the reversed first part and added to the set.
        st.add(t)
        t = s[j:] + res
        st.add(t)

        t = s[:j] + res2 # The reversed first part is concatenated with the second part and added to the set.
        st.add(t)
        t = res2 + s[:j]
        st.add(t)

        t = s[:j] + s[j:] # The reversed first and second parts are concatenated in both orders and added to the set.
        st.add(t)
        t = s[j:] + s[:j]
        st.add(t)

    print(len(st)) # Step 4: Outputting the Result - After processing all split points for a string, the size of the set st is printed.

# Step 5: End of Program - The program ends with return 0.
return 0

