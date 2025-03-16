def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Step 1: Read the input value `n` which represents the number of elements.
    n = int(data[0])
    
    # Step 2: Read the values of `v` (values) and store them in a list `vList`.
    vList = list(map(int, data[1:n+1]))
    
    # Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    cList = list(map(int, data[n+1:]))
    
    # Step 4: Initialize a variable `max` to keep track of the maximum profit.
    max_profit = 0
    
    # Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for i in range(n):
        profit = vList[i] - cList[i]
        if profit > 0:
            max_profit += profit
    
    # Step 6: Print the maximum profit.
    print(max_profit)

if __name__ == "__main__":
    main()
