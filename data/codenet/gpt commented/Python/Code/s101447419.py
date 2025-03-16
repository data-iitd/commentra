#ABC111C
import collections

def main():
    # Read the number of elements
    n = int(input())
    
    # Read the list of integers and store them in a list
    v = list(map(int, input().split()))
    
    # Initialize lists to hold even-indexed and odd-indexed elements
    ve = []
    vo = []
    
    # Separate the input list into even-indexed and odd-indexed elements
    for i in range(n // 2):
        ve.append(v[2 * i])      # Append even-indexed elements to ve
        vo.append(v[2 * i + 1])  # Append odd-indexed elements to vo
    
    # Count the occurrences of each element in the even-indexed and odd-indexed lists
    ce = collections.Counter(ve)
    co = collections.Counter(vo)
    
    # Initialize the answer variable with the total number of elements
    ans = n
    
    # Check if the most common elements in both lists are different
    if ce.most_common()[0][0] != co.most_common()[0][0]:
        # If they are different, calculate the answer based on their counts
        ans = n - ce.most_common()[0][1] - co.most_common()[0][1]
    
    # Check if there is only one unique element in both lists
    elif len(ce) == 1 and len(co) == 1:
        # If both lists have only one unique element, adjust the answer accordingly
        ans = n - ce.most_common()[0][1]
    
    # Check if there is only one unique element in the even-indexed list
    elif len(ce) == 1:
        # Adjust the answer based on the counts of the most common elements
        ans = n - ce.most_common()[0][1] - co.most_common()[1][1]
    
    # Check if there is only one unique element in the odd-indexed list
    elif len(co) == 1:
        # Adjust the answer based on the counts of the most common elements
        ans = n - ce.most_common()[1][1] - co.most_common()[0][1]
    
    # If there are multiple unique elements in both lists
    else:
        # Calculate the minimum adjustments needed based on the counts of the most common elements
        ans = min(n - ce.most_common()[0][1] - co.most_common()[1][1], 
                  n - ce.most_common()[1][1] - co.most_common()[0][1])
    
    # Print the final answer
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()
