import sys

def main():
    # Reading the input values
    for line in sys.stdin:
        a, b, c, d, e, f = map(int, line.split())
        
        # Calculating the values of x and y
        y = (c * d - f * a) / (b * d - e * a)
        x = (c * e - f * b) / (a * e - d * b)
        
        # Adjusting the values of x and y if they are very close to zero
        if 0 < y <= 0.0005:
            y = 0
        if 0 < x <= 0.0005:
            x = 0
        
        # Printing the results
        print(f"{x:.3f} {y:.3f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
