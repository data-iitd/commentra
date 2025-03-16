
import re

def is_main(word):
    return is_main(word, False)

def is_main_ignore_case(word):
    return is_main(word, True)

def is_main(word, ignore_case):
    if word is None:
        return False
    if ignore_case:
        word = word.lower()

    for i in range(len(word) // 2):
        if word[i] != word[len(word) - 1 - i]:
            return False
    return True

def remove_mains(string):
    words = string.split(",?\s+")
    result = ""

    for word in words:
        if not is_main_ignore_case(word):
            if result != "":
                result += ", "
            result += word

    return result

def remove_nth_main(string, n):
    words = string.split(",?\s+")
    counter = 0
    result = ""

    for word in words:
        if is_main_ignore_case(word):
            counter += 1
            if counter == n:
                continue
        if result != "":
            result += ", "
        result += word

    return result

def longest_main_substring(str):
    result = str[0]

    for i in range(len(str)):
        for j in range(len(str) - 1, i + len(result), -1):
            current_string = str[i:j]
            if len(current_string) > len(result) and is_main(current_string):
                result = current_string

    return result

def can_form_main(str):
    set = set()
    for ch in str:
        if ch not in set:
            set.add(ch)
        else:
            set.remove(ch)

    return len(set) <= 1

if __name__ == "__main__":
    option = int(input())
    if option == 1:
        word = input()
        print("Is Main: " + str(is_main(word)))
    elif option == 2:
        string = input()
        print("String after removing palindromes: " + remove_mains(string))
    elif option == 3:
        string = input()
        n = int(input())
        print("String after removing nth palindrome: " + remove_nth_main(string, n))
    elif option == 4:
        string = input()
        print("Longest Main Substring: " + longest_main_substring(string))
    elif option == 5:
        string = input()
        print("Can form palindrome: " + str(can_form_main(string)))
    else:
        print("Invalid option")

