import math
import sys

def main():
    A = int(input().strip())
    B = int(input().strip())
    H = int(input().strip())
    M = int(input().strip())

    # Calculate the angles in degrees
    mkaku = M * 6
    hkaku = H * 30 + M * 0.5
    kaku = abs(mkaku - hkaku)

    # Convert to radians
    dkaku = math.radians(kaku)

    # Calculate the cos of the angle
    cos_kaku = math.cos(dkaku)

    # Calculate the distance squared
    distance_squared = A**2 + B**2 - 2 * A * B * cos_kaku

    # Calculate the distance
    distance = math.sqrt(distance_squared)

    # Print the result
    print("{:.20f}".format(distance))

if __name__ == "__main__":
    main()
