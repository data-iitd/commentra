class Main:
    @staticmethod
    def is_main(word):
        return Main._is_main(word, False)

    @staticmethod
    def is_main_ignore_case(word):
        return Main._is_main(word, True)

    @staticmethod
    def _is_main(word, ignore_case):
        if word is None:
            return False
        if ignore_case:
            word = word.lower()
        for i in range(len(word) // 2):
            if word[i] != word[len(word) - 1 - i]:
                return False
        return True

    @staticmethod
    def remove_mains(string):
        words = string.split(", ")
        result = []
        for word in words:
            if not Main.is_main_ignore_case(word):
                result.append(word)
        return ", ".join(result)

    @staticmethod
    def remove_nth_main(string, n):
        words = string.split(", ")
        counter = 0
        result = []
        for word in words:
            if Main.is_main_ignore_case(word):
                counter += 1
                if counter == n:
                    continue
            result.append(word)
        return ", ".join(result)

    @staticmethod
    def longest_main_substring(s):
        result = s[0:1]
        for i in range(len(s)):
            for j in range(len(s) - 1, i + len(result), -1):
                current_string = s[i:j]
                if len(current_string) > len(result) and Main.is_main(current_string):
                    result = current_string
        return result

    @staticmethod
    def can_form_main(s):
        char_set = set()
        for ch in s:
            if ch not in char_set:
                char_set.add(ch)
            else:
                char_set.remove(ch)
        return len(char_set) <= 1

if __name__ == "__main__":
    option = int(input())
    if option == 1:
        word = input()
        print("Is Main:", Main.is_main(word))
    elif option == 2:
        string = input()
        print("String after removing palindromes:", Main.remove_mains(string))
    elif option == 3:
        string2 = input()
        n = int(input())
        print("String after removing nth palindrome:", Main.remove_nth_main(string2, n))
    elif option == 4:
        string3 = input()
        print("Longest Main Substring:", Main.longest_main_substring(string3))
    elif option == 5:
        string4 = input()
        print("Can form palindrome:", Main.can_form_main(string4))
    else:
        print("Invalid option")

# <END-OF-CODE>
