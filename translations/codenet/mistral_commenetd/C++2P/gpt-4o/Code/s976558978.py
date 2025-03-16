import sys

def main():
    # Open the input file for reading
    with open("dataabc155A.txt", "r") as f:
        a = int(f.readline().strip())
        b = int(f.readline().strip())
    
    # If a is smaller than b, print a b times
    if a < b:
        print((str(a) + ' ') * b)
    else:
        # If b is smaller than a, print b a times
        print((str(b) + ' ') * a)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
