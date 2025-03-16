import re

def is_palindrome(word, ignore_case=False):
    if word is None:
        return False
    if ignore_case:
        word = word.lower()
    for i in range(len(word) // 2):
        if word[i] != word[-(i + 1)]:
            return False
    return True

def remove_palindromes(string):
    words = re.split(r'\s+', string)
    result = []
    for word in words:
        if not is_palindrome(word, True):
            result.append(word)
    return ' '.join(result)

def remove_nth_palindrome(string, n):
    words = re.split(r'\s+', string)
    counter = 0
    result = []
    for word in words:
        if is_palindrome(word, True):
            counter += 1
            if counter == n:
                continue
        result.append(word)
    return ' '.join(result)

def longest_palindrome_substring(str):
    result = str[0:1]
    for i in range(len(str)):
        for j in range(len(str) - 1, i + len(result), -1):
            current_string = str[i:j]
            if len(current_string) > len(result) and is_palindrome(current_string):
                result = current_string
    return result

def can_form_palindrome(str):
    char_set = set()
    for ch in str:
        if ch in char_set:
            char_set.remove(ch)
        else:
            char_set.add(ch)
    return len(char_set) <= 1

def main():
    option = int(input())
    if option == 1:
        word = input()
        print("Is Main:", is_palindrome(word))
    elif option == 2:
        string = input()
        print("String after removing palindromes:", remove_palindromes(string))
    elif option == 3:
        string = input()
        n = int(input())
        print("String after removing nth palindrome:", remove_nth_palindrome(string, n))
    elif option == 4:
        string = input()
        print("Longest Main Substring:", longest_palindrome_substring(string))
    elif option == 5:
        string = input()
        print("Can form palindrome:", can_form_palindrome(string))
    else:
        print("Invalid option")

if __name__ == "__main__":
    main()
