#include <stdio.h>
#include <stdlib.h>

# Main function starts here
def main():
    a = 0
    while(a!= -1):
        a = int(input())
        if(a == -1):
            break
        b = a
        c = 0
        k = 0
        while(a!= 0):
            a = a - 1
            b = b - 1
            c = c + 1
            if(c == 3):
                k = k + 1
                c = 0
        print(k)

# Main function ends here
if __name__ == "__main__":
    main()

