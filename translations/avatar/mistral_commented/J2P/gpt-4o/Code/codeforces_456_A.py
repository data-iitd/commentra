class Main:
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        
        n = int(data[0])  # Read the first integer n
        a = [0] * n  # Create an integer list a with a length of n
        b = [0] * n  # Create an integer list b with a length of n
        
        temp = 0  # Initialize a variable temp to 0
        q = 0  # Initialize a variable q to 0
        w = float('-inf')  # Initialize a variable w to the smallest possible integer value
        e = float('-inf')  # Initialize a variable e to the smallest possible integer value
        f = False  # Initialize a boolean variable f to False
        
        index = 1
        for i in range(n):  # Start a for loop that iterates through the elements of lists a and b
            a[i] = int(data[index])  # Read the next integer value for a[i]
            b[i] = int(data[index + 1])  # Read the next integer value for b[i]
            index += 2
            
            if temp < a[i]:  # If the current value of temp is less than a[i]
                if q > b[i]:  # Check if the condition q > b[i] is satisfied
                    f = True  # If it is, set f to True
                q = b[i]  # Update q with the new value of b[i]
                temp = a[i]  # Update temp with the new value of a[i]
            
            if temp > a[i]:  # If the current value of temp is greater than a[i]
                if q < b[i]:  # Check if the condition q < b[i] is satisfied
                    f = True  # If it is, set f to True
                q = b[i]  # Update q with the new value of b[i]
                temp = a[i]  # Update temp with the new value of a[i]
            
            if a[i] > w:  # If the current value of a[i] is greater than w
                w = a[i]  # Update w with the new value of a[i]
                if b[i] < e:  # Check if the condition b[i] < e is satisfied
                    f = True  # If it is, set f to True
            
            if a[i] < w:  # If the current value of a[i] is less than w
                if b[i] > e:  # Check if the condition b[i] > e is satisfied
                    f = True  # If it is, set f to True
        
        if f:  # After the loop finishes, check the value of the boolean variable f
            print("Happy Alex")  # If it is true, print the message "Happy Alex"
        else:
            print("Poor Alex")  # Otherwise, print the message "Poor Alex"

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
