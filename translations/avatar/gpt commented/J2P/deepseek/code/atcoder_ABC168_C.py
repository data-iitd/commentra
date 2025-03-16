import math

def main():
    # Read integer inputs A, B, H, and M from the user
    A, B, H, M = map(int, input().split())
    
    # Calculate the angle of the minute hand in degrees
    mkaku = M * 6
    
    # Calculate the angle of the hour hand in degrees
    hkaku = H * 30 + M / 2
    
    # Calculate the difference in angles between the two hands
    kaku = abs(mkaku - hkaku)
    
    # Convert the angle difference from degrees to radians
    dkaku = math.radians(kaku)
    
    # Calculate the cosine of the angle difference and adjust for the formula
    DD = math.cos(dkaku) * 2 * A * B
    
    # Calculate the final result using the derived formula
    ans2 = A**2 + B**2 - DD
    
    # Calculate the square root of the result
    ans = math.sqrt(ans2)
    
    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()
