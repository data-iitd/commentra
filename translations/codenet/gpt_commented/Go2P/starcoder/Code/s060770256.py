# <START-OF-CODE>

# solution calculates the product of (n-2) and (m-2) with adjustments for negative values.
def solution(n, m):
        # Decrease n and m by 2 to adjust for some offset
        n = n - 2
        m = m - 2
        
        # If the adjusted n is negative, set it to 1
        if n < 0:
                n = 1
        
        # If the adjusted m is negative, set it to 1
        if m < 0:
                m = 1
        
        # Return the product of the adjusted n and m
        return n * m

# 