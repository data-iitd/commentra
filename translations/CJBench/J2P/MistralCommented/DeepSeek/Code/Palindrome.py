import re

def is_main(word, ignore_case=False):
    if word is None:
        return False
    
    if ignore_case:
        word = word.lower()
    
    for i in range(len(word) // 2):
        if word[i] != word[-(i + 1)]:
            return False
    return True

def is_main_ignore_case(word):
    return is_main(word, True)

def remove_mains(string):
    result = []
    words = re.split(r',?\s+', string)
    
    for word in words:
        if not is_main_ignore_case(word):
            result.append(word)
    
    return ', '.join(result)

def remove_nth_main(string, n):
    result = []
    words = re.split(r',?\s+', string)
    counter = 0
    
    for word in words:
        if is_main_ignore_case(word):
            counter += 1
            if counter == n:
                continue
        result.append(word)
    
    return ', '.join(result)

def longest_main_substring(str):
    result = str[:1]
    
    for i in range(len(str)):
        for j in range(len(str) - 1, i + len(result), -1):
            current_string = str[i:j]
            if len(current_string) > len(result) and is_main(current_string):
                result = current_string
    
    return result

def can_form_main(str):
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
        print("Is Main:", is_main(word))
    elif option == 2:
        string = input()
        print("String after removing palindromes:", remove_mains(string))
    elif option == 3:
        string2 = input()
        n = int(input())
        print("String after removing nth palindrome:", remove_nth_main(string2, n))
    elif option == 4:
        string3 = input()
        print("Longest Main Substring:", longest_main_substring(string3))
    elif option == 5:
        string4 = input()
        print("Can form palindrome:", can_form_main(string4))
    else:
        print("Invalid option")

if __name__ == "__main__":
    main()
