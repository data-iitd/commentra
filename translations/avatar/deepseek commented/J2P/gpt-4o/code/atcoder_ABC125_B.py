def str2list(s):
    # Helper function to convert a string of space-separated integers into a dictionary with index as key and integer value as value.
    v_arr_str = s.split(" ")
    ret = {}
    for key, val in enumerate(v_arr_str):
        ret[key] = int(val)
    return ret

def main():
    # Step 1: Read the input value `n` which represents the number of elements.
    n = int(input().strip())
    
    # Step 2: Read the values of `v` (values) and store them in a dictionary `v_list`.
    v_str = input().strip()
    v_list = str2list(v_str)
    
    # Step 3: Read the values of `c` (costs) and store them in a dictionary `c_list`.
    c_str = input().strip()
    c_list = str2list(c_str)
    
    # Step 4: Initialize a variable `max` to keep track of the maximum profit.
    max_profit = 0
    
    # Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for i in range(n):
        profit = v_list[i] - c_list[i]
        if profit > 0:
            max_profit += profit
    
    # Step 6: Print the maximum profit.
    print(max_profit)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
