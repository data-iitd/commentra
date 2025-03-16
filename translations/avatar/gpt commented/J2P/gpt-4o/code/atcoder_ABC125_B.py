def str2list(s):
    # Convert a space-separated string of integers into a dictionary
    v_arr_str = s.split(" ")
    ret = {}
    for key, val in enumerate(v_arr_str):
        ret[key] = int(val)
    return ret

def main():
    # Read the number of items (n) from the input
    n = int(input().strip())
    
    # Read the values (vStr) from the input and convert to a dictionary
    v_str = input().strip()
    v_list = str2list(v_str)
    
    # Read the costs (cStr) from the input and convert to a dictionary
    c_str = input().strip()
    c_list = str2list(c_str)
    
    # Initialize a variable to keep track of the maximum profit
    max_profit = 0
    
    # Calculate the profit for each item and sum up the positive profits
    for i in range(n):
        profit = v_list[i] - c_list[i]
        # Only add to max if the profit is positive
        if profit > 0:
            max_profit += profit
    
    # Output the total maximum profit
    print(max_profit)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
