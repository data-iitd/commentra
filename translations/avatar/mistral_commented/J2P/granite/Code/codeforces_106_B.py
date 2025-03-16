
import sys

def main():
    n = int(input()) # Reading the number of items from the input

    vec = [] # Creating an empty list to store the items

    # Initializing the list with input values
    for i in range(n):
        vec.append(list(map(int, input().split()))) # Reading the elements of the current item and appending them to the list

    ans = 500 # Initializing answer variables with default values
    ansprice = 20000

    # Finding the answer by comparing all items and keeping track of the minimum price item found so far
    for i in range(n):
        flag = True # Initializing a flag variable to check if the current item is smaller than all other items

        for j in range(n):
            if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]:
                flag = False # If the current item is smaller than the other item, set the flag to False
                break # Exit the inner loop as we don't need to check further if the current item is smaller

        if flag: # If the current item is not smaller than any other item, check if its price is lower than the current answer
            if vec[i][3] < ansprice:
                ansprice = vec[i][3] # Update the answer price if the current item's price is lower
                ans = i + 1 # Update the answer index

    # Printing the answer
    print(ans)

if __name__ == "__main__":
    main()

