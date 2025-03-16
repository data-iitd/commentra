def main():
    while True:
        an = [0] * 20
        L = int(input("Enter a number and its length (0 to exit): "))
        if L == 0:
            break  # If L is 0, break out of the loop
        
        an[0] = L
        aj = an[0]
        end = 0
        k = 1
        
        while True:
            a1 = [0] * 6
            a2 = [0] * 6
            
            for i in range(L - 1, -1, -1):
                a1[i] = aj % 10
                a2[i] = aj % 10
                aj //= 10
            
            # Sort a1 in ascending order and a2 in descending order
            for i in range(1, L):
                for j in range(1, L):
                    if a1[j - 1] < a1[j]:
                        a1[j - 1], a1[j] = a1[j], a1[j - 1]
                    if a2[j - 1] > a2[j]:
                        a2[j - 1], a2[j] = a2[j], a2[j - 1]
            
            d = 1
            max_val = 0
            min_val = 0
            
            for i in range(L - 1, -1, -1):
                max_val += (a1[i] % 10) * d  # Calculate max by combining sorted digits
                min_val += (a2[i] % 10) * d  # Calculate min by combining sorted digits
                d *= 10
            
            def_val = max_val - min_val  # Calculate the difference def
            
            for i in range(k):
                if def_val == an[i]:  # Check if def has been seen before
                    print(f"{i} {def_val} {k - i}")  # Print the index, def, and steps taken
                    end = 1
                    break  # Set end to 1 to break out of the loop
            
            if end == 1:
                break  # If end is 1, break out of the loop
            
            an[k] = def_val  # Add def to an
            aj = def_val  # Update aj
            k += 1  # Increment k

if __name__ == "__main__":
    main()

# <END-OF-CODE>
