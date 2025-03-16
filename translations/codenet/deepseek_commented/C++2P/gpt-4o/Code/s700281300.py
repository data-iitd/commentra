def main():
    n = int(input())  # Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

    for _ in range(n):  # Step 2: Processing Each Test Case - The outer loop iterates over each test case.
        s = input()  # For each test case, the program reads a string s.

        st = set()  # Step 3: Generating Substrings and Checking for Palindromes - A set is used to store unique substrings.
        st.add(s)  # The first substring is inserted into the set.

        for j in range(1, len(s)):  # The inner loop iterates over possible split points in the string s.
            res = s[:j][::-1]  # The first part of the string is extracted and reversed.
            res2 = s[j:][::-1]  # The second part of the string is extracted and reversed.

            t = res  # The first part is concatenated with the reversed second part in both orders and added to the set.
            t2 = res2
            st.add(t + t2)
            st.add(t2 + t)

            st.add(t + res2)  # The first part is concatenated with the reversed first part and added to the set.
            st.add(res2 + t)

            st.add(res + t2)  # The reversed first part is concatenated with the second part and added to the set.
            st.add(t2 + res)

            st.add(res + res2)  # The reversed first and second parts are concatenated in both orders and added to the set.
            st.add(res2 + res)

        print(len(st))  # Step 4: Outputting the Result - After processing all split points for a string, the size of the set is printed.

if __name__ == "__main__":
    main()  # Step 5: End of Program - The program ends with the main function call.

# <END-OF-CODE>
