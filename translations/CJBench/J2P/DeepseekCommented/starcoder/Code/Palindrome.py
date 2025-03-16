
import re

# Step 1: Define the `isMain` method
# This method checks if a given word is a palindrome.
def isMain(word):
    return isMain(word, False)

# Step 2: Define the `isMainIgnoreCase` method
# This method is a wrapper for `isMain` that ignores case.
def isMainIgnoreCase(word):
    return isMain(word, True)

# Step 3: Define the `isMain` method with a boolean to ignore case
# This private method checks if a given word is a palindrome, considering case sensitivity.
def isMain(word, ignoreCase):
    if word == None:
        return False
    if ignoreCase:
        word = word.lower()
    for i in range(0, len(word) / 2):
        if word[i]!= word[len(word) - 1 - i]:
            return False
    return True

# Step 4: Define the `removeMains` method
# This method removes all palindromic words from a given string.
def removeMains(string):
    words = re.split(",?\\s+", string)
    result = ""
    for word in words:
        if not isMainIgnoreCase(word):
            if result!= "":
                result += ", "
            result += word
    return result

# Step 5: Define the `removeNthMain` method
# This method removes the nth palindromic word from a given string.
def removeNthMain(string, n):
    words = re.split(",?\\s+", string)
    counter = 0
    result = ""
    for word in words:
        if isMainIgnoreCase(word):
            counter += 1
            if counter == n:
                continue
        if result!= "":
            result += ", "
        result += word
    return result

# Step 6: Define the `longestMainSubstring` method
# This method finds the longest substring that is a palindrome in a given string.
def longestMainSubstring(str):
    result = str[0:1]
    for i in range(0, len(str)):
        for j in range(len(str) - 1, i + len(result) + 1, -1):
            currentString = str[i:j]
            if len(currentString) > len(result) and isMain(currentString):
                result = currentString
    return result

# Step 7: Define the `canFormMain` method
# This method checks if a given string can be rearranged to form a palindrome.
def canFormMain(str):
    set = set()
    for ch in str:
        if not ch in set:
            set.add(ch)
        else:
            set.remove(ch)
    return len(set) <= 1

# Step 7: Implement the main method
# This method provides a menu-driven interface to interact with the user and call the appropriate methods based on the user's choice.
def main():
    option = int(input())
    if option == 1:
        word = input()
        print("Is Main: " + str(isMain(word)))
    elif option == 2:
        string = input()
        print("String after removing palindromes: " + removeMains(string))
    elif option == 3:
        string2 = input()
        n = int(input())
        print("String after removing nth palindrome: " + removeNthMain(string2, n))
    elif option == 4:
        string3 = input()
        print("Longest Main Substring: " + longestMainSubstring(string3))
    elif option == 5:
        string4 = input()
        print("Can form palindrome: " + str(canFormMain(string4)))
    else:
        print("Invalid option")

# Step 8: Call the main method
main()

# 