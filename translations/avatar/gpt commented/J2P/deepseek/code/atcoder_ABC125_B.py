def str2list(s):
    # Split the input string into a list of strings
    values = s.split()
    # Create a dictionary to hold the integer values with their corresponding indices
    ret = {}
    for i, val in enumerate(values):
        ret[i] = int(val)
    return ret

def main():
    # Read the number of items (n) from the input
    n = int(input())
    
    # Read the values (vStr) from the input and convert to a list
    vStr = input()
    vList = str2list(vStr)
    
    # Read the costs (cStr) from the input and convert to a list
    cStr = input()
    cList = str2list(cStr)
    
    # Initialize a variable to keep track of the maximum profit
    max_profit = 0
    
    # Calculate the profit for each item and sum up the positive profits
    for i in range(n):
        profit = vList[i] - cList[i]
        # Only add to max_profit if the profit is positive
        if profit > 0:
            max_profit += profit
    
    # Output the total maximum profit
    print(max_profit)

if __name__ == "__main__":
    main()
