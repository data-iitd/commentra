
import re

def isMain(word):
    return isMain(word, False)

def isMainIgnoreCase(word):
    return isMain(word, True)

def isMain(word, ignoreCase):
    if word == None:
        return False
    if ignoreCase:
        word = word.lower()

    for i in range(0, len(word) / 2):
        if word[i]!= word[len(word) - 1 - i]:
            return False
    return True

def removeMains(string):
    words = re.split(",?\\s+", string)
    result = ""

    for word in words:
        if not isMainIgnoreCase(word):
            if result!= "":
                result += ", "
            result += word

    return result

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

def longestMainSubstring(str):
    result = str[0:1]

    for i in range(0, len(str)):
        for j in range(len(str) - 1, i + len(result) + 1, -1):
            currentString = str[i:j]
            if len(currentString) > len(result) and isMain(currentString):
                result = currentString

    return result

def canFormMain(str):
    set = set()
    for ch in str:
        if not ch in set:
            set.add(ch)
        else:
            set.remove(ch)

    return len(set) <= 1

def main():
    option = int(input())
    input() # Consume the newline character

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

if __name__ == "__main__":
    main()

