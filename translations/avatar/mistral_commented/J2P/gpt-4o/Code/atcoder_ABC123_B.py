# Importing the necessary modules
from collections import defaultdict

def main():
    a = [0] * 5  # Creating a list 'a' of size 5
    r = [0] * 5  # Creating a list 'r' of size 5
    map = {}  # Creating an empty dictionary to store integer keys and their corresponding integer values

    # Reading input elements of array 'a' and storing their remainders in array 'r'
    for i in range(len(a)):
        a[i] = int(input())  # Reading an integer value from the console and storing it in the 'i'th index of array 'a'
        r[i] = a[i] % 10  # Calculating the remainder of the 'i'th element of array 'a' and storing it in the 'i'th index of array 'r'

        b = 10  # Initializing 'b' to 10
        if r[i] != 0:  # Checking if the remainder of the 'i'th element of array 'a' is not zero
            b = 10 - r[i]  # Calculating the complement of the remainder and assigning it to 'b'
            map[b] = a[i]  # Storing the complement as a key and the corresponding integer value (the 'i'th element of array 'a') in the dictionary

    ans = 0  # Initializing 'ans' to zero

    # Checking if the dictionary is empty
    if len(map) == 0:
        for i in range(len(a)):  # Iterating through the list 'a'
            ans += a[i]  # Adding the 'i'th element of array 'a' to the sum 'ans'
        print(ans)  # Printing the sum of all elements in array 'a'
        return  # Exiting the method if the dictionary is empty

    last = map[max(map.keys())]  # Getting the last key (complement) from the dictionary and finding its corresponding value (the last element of array 'a')
    idx = 0  # Initializing 'idx' to zero

    # Finding the index of the last element in array 'a'
    for i in range(len(a)):
        if a[i] == last:  # Checking if the 'i'th element of array 'a' is equal to the last element
            idx = i  # If true, assigning the index to 'idx'
            break  # Exiting the loop

    # Calculating the sum of all elements in array 'a' except the last one
    for i in range(len(a)):
        if i != idx:  # Checking if the current index is not equal to 'idx'
            if a[i] % 10 == 0:  # Checking if the 'i'th element of array 'a' is a multiple of 10
                ans += a[i]  # If true, adding it to the sum 'ans'
            else:  # If the 'i'th element of array 'a' is not a multiple of 10
                ans += a[i] + (10 - r[i])  # Adding the 'i'th element of array 'a' and its complement to the sum 'ans'

    # Adding the last element of array 'a' to the sum 'ans'
    ans += last

    print(ans)  # Printing the final sum

if __name__ == "__main__":
    main()

# <END-OF-CODE>
