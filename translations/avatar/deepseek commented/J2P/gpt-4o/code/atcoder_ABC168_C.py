import math

def main():
    # Read input values for A, B, H, and M
    A = int(input())
    B = int(input())
    H = int(input())
    M = int(input())
    
    # Calculate the angles for the minute and hour hands in degrees
    mkaku = M * 6  # Minute hand angle
    hkaku = H * 30  # Hour hand angle
    hkaku += M / 2  # Adjust hour hand angle for minutes
    
    # Calculate the difference between the two angles
    kaku = mkaku - hkaku
    
    # Convert the angle difference to radians
    dkaku = abs(math.radians(kaku))
    
    # Calculate the cosine of the angle in radians
    AA2 = A * A
    BB2 = B * B
    CC = AA2 + BB2
    DD = 2 * A * B * math.cos(dkaku)
    
    # Calculate the distance using the cosine rule
    ans2 = CC - DD
    
    # Calculate the square root of the distance
    ans = math.sqrt(ans2)
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
