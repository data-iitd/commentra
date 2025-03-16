def main():
    # Read the number of pairs (n)
    n = int(input())
    
    # Initialize two lists to hold the pairs of integers
    a = []
    b = []
    
    # Loop to read pairs of integers into lists a and b
    for _ in range(n):
        ai, bi = map(int, input().split())
        a.append(ai)
        b.append(bi)
    
    # Initialize variables for processing
    temp = 0  # To track the current maximum value in list a
    q = 0     # To track the corresponding value in list b
    w = 0     # To track the maximum value in list a
    e = 0     # To track the corresponding value in list b
    f = False  # Flag to determine if the condition for "Happy Alex" is met

    # Loop through the pairs to find the condition for "Happy Alex"
    for i in range(n):
        # Check if the current value in a is greater than the previous maximum
        if temp < a[i]:
            # If the current b value is less than the previous b value, set flag to True
            if q > b[i]:
                f = True
            # Update q and temp with current values
            q = b[i]
            temp = a[i]
        
        # Check if the current value in a is less than the previous maximum
        if temp > a[i]:
            # If the current b value is greater than the previous b value, set flag to True
            if q < b[i]:
                f = True
            # Update q and temp with current values
            q = b[i]
            temp = a[i]
        
        # Update the maximum value in a and check conditions for b
        if a[i] > w:
            w = a[i]  # Update maximum value in a
            # If the current b value is less than the previous maximum b, set flag to True
            if b[i] < e:
                f = True
            e = b[i]  # Update corresponding value in b
        
        # Check if the current value in a is less than the maximum value
        if a[i] < w:
            # If the current b value is greater than the previous maximum b, set flag to True
            if b[i] > e:
                f = True
    
    # Output the result based on the flag value
    if f:
        print("Happy Alex")  # Condition met for "Happy Alex"
    else:
        print("Poor Alex")   # Condition not met, output "Poor Alex"

if __name__ == "__main__":
    main()
