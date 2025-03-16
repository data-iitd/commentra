
#ABC111C
import collections # Importing collections module for Counter function

def main(): # Defining the main function
    n = int(input()) # Taking input of number of elements in the list
    v = list(map(int, input().split())) # Creating a list 'v' from user input

    ve = [] # Initializing empty lists 've' and 'vo' for even and odd elements respectively
    vo = []

    for i in range(n // 2): # Iterating through half of the list
        ve.append(v[2 * i]) # Appending even elements to 've' list
        vo.append(v[2 * i + 1]) # Appending odd elements to 'vo' list

    ce = collections.Counter(ve) # Using Counter function to count frequency of each even element
    co = collections.Counter(vo) # Using Counter function to count frequency of each odd element

    ans = n # Initializing answer as the length of the list

    if ce.most_common()[0][0] != co.most_common()[0][0]: # Checking if most frequent even and odd elements are same or not
        ans = n - ce.most_common()[0][1] - co.most_common()[0][1] # If not, calculating answer as the difference between the count of most frequent even and odd elements
    elif len(ce) == 1 and len(co) == 1: # If both even and odd lists have only one element
        ans = n - ce.most_common()[0][1] # Calculating answer as the difference between the count of most frequent even element and the length of the list
    elif len(ce) == 1: # If only even list has one element
        ans = n - ce.most_common()[0][1] - co.most_common()[1][1] # Calculating answer as the difference between the count of most frequent even element and the count of most frequent odd element
    elif len(co) == 1: # If only odd list has one element
        ans = n - ce.most_common()[1][1] - co.most_common()[0][1] # Calculating answer as the difference between the count of most frequent odd element and the count of most frequent even element
    else: # If both even and odd lists have more than one element
        ans = min(n - ce.most_common()[0][1] - co.most_common()[1][1], n - ce.most_common()[1][1] - co.most_common()[0][1]) # Calculating answer as the minimum difference between the count of most frequent even and odd elements

    print(ans) # Printing the answer

if __name__=="__main__": # Running the main function if the script is executed directly
    main()