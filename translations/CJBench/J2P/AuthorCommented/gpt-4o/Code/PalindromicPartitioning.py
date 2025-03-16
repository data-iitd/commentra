class PalindromePartitioning:
    @staticmethod
    def minimal_partitions(word: str) -> int:
        length = len(word)
        # We make two arrays to create a bottom-up solution.
        # minCuts[i] = Minimum number of cuts needed for palindrome partitioning of substring word[0..i]
        # isPalindrome[i][j] = True if substring word[i..j] is palindrome
        minCuts = [0] * length
        isPalindrome = [[False] * length for _ in range(length)]

        # Every substring of length 1 is a palindrome
        for i in range(length):
            isPalindrome[i][i] = True

        # Build the solution in bottom-up manner by considering all substrings of length starting from 2 to n.
        for subLen in range(2, length + 1):
            for i in range(length - subLen + 1):
                j = i + subLen - 1  # Ending index
                if subLen == 2:
                    isPalindrome[i][j] = (word[i] == word[j])
                else:
                    isPalindrome[i][j] = (word[i] == word[j]) and isPalindrome[i + 1][j - 1]

        # We find the minimum for each index
        for i in range(length):
            if isPalindrome[0][i]:
                minCuts[i] = 0
            else:
                minCuts[i] = float('inf')
                for j in range(i):
                    if isPalindrome[j + 1][i] and 1 + minCuts[j] < minCuts[i]:
                        minCuts[i] = 1 + minCuts[j]

        # Return the min cut value for complete string. i.e., word[0..n-1]
        return minCuts[length - 1]


if __name__ == "__main__":
    input_string = input("Enter a string: ")
    result = PalindromePartitioning.minimal_partitions(input_string)
    print("Minimum number of partitions required:", result)

# <END-OF-CODE>
