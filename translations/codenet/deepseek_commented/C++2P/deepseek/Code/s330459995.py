def main():
    # Read the dimensions of the rectangle and the circle from the input
    W, H, x, y, r = map(int, input().split())
    
    # Check if the circle is outside the rectangle
    if x - r < 0 or x + r > W or y - r < 0 or y + r > H:
        # If any part of the circle is outside the rectangle, print "No"
        print("No")
    else:
        # If the circle is completely inside the rectangle, print "Yes"
        print("Yes")

# Call the main function
main()

