from collections import defaultdict  # Importing defaultdict from collections

def main():  # Defining the main function
    n = int(input())  # Reading the number of test cases from the console

    freq_map = defaultdict(int)  # Creating a defaultdict to store the frequency of each number

    for _ in range(n):  # Loop through each test case
        num = int(input())  # Reading the number from the console

        if not freq_map or (max(freq_map.keys()) < num):  # If the number is not present in the freq_map
            freq_map[num] += 1  # Increment the value of the number in the freq_map
        else:  # If the number is already present in the freq_map
            lower_key = max(k for k in freq_map.keys() if k < num)  # Get the largest key less than num
            val = freq_map[lower_key]  # Get the value (frequency) of the previous number from the freq_map

            if val == 1:  # If the frequency of the previous number is 1
                del freq_map[lower_key]  # Remove the previous number from the freq_map
            else:  # If the frequency of the previous number is greater than 1
                freq_map[lower_key] -= 1  # Decrement the frequency of the previous number in the freq_map

            freq_map[num] += 1  # Increment the value of the current number in the freq_map

    ans = sum(freq_map.values())  # Summing up the frequencies of all numbers in the freq_map

    print(ans)  # Printing the answer to the console

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
