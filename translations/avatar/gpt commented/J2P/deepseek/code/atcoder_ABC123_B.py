import sys

def main():
    # Read 5 integers from the user
    a = []
    for _ in range(5):
        a.append(int(input()))
    
    # Calculate remainders and store them in a dictionary with adjustment values
    map_adjustments = {}
    for value in a:
        remainder = value % 10
        if remainder != 0:
            adjustment = 10 - remainder
            map_adjustments[adjustment] = value
    
    # If no adjustments are needed, sum all input values
    if not map_adjustments:
        print(sum(a))
        return
    
    # Get the largest adjustment value
    last_adjustment = max(map_adjustments.keys())
    last_value = map_adjustments[last_adjustment]
    
    # Calculate the final answer by adding values, adjusting as necessary
    ans = 0
    for value in a:
        if value == last_value:
            ans += value
        elif value % 10 != 0:
            ans += value + (10 - value % 10)
        else:
            ans += value
    
    # Print the final calculated answer
    print(ans)

if __name__ == "__main__":
    main()
