import math

def main():
    # Read input values for A, B, H, and M
    A, B, H, M = map(int, input().split())
    
    # Calculate the angles for the minute and hour hands in degrees
    mkaku = M * 6  # Minute hand angle
    hkaku = H * 30 + M / 2  # Hour hand angle
    
    # Calculate the difference between the two angles
    kaku = abs(mkaku - hkaku)
    
    # Convert the angle difference to radians
    dkaku = math.radians(kaku)
    
    # Calculate the cosine of the angle in radians
    cos_value = math.cos(dkaku)
    cos_value *= 2 * A * B
    
    # Calculate the distance using the cosine rule
    ans2 = A**2 + B**2 - cos_value
    
    # Calculate the square root of the distance
    ans = math.sqrt(ans2)
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()
