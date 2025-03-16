
import sys

def drawEllipse(centerX, centerY, a, b):
    points = [] # Create an empty list to store the ellipse points

    if a == 0 and b == 0: # Check if the ellipse has zero radius
        points.append([centerX, centerY]) # Add the center point to the list and return it
        return points

    if a == 0: # Check if the ellipse is a horizontal line
        for y in range(centerY - b, centerY + b + 1):
            points.append([centerX, y]) # Add each point on the horizontal line to the list
        return points

    if b == 0: # Check if the ellipse is a vertical line
        for x in range(centerX - a, centerX + a + 1):
            points.append([x, centerY]) # Add each point on the vertical line to the list
        return points

    computeEllipsePoints(points, centerX, centerY, a, b) # Call the computeEllipsePoints method to calculate the ellipse points
    return points

def computeEllipsePoints(points, centerX, centerY, a, b):
    x = 0 # Initialize the x variable for the ellipse points calculation
    y = b # Initialize the y variable for the ellipse points calculation

    d1 = b * b - a * a * b + 0.25 * a * a # Calculate the discriminant d1 for the ellipse points calculation

    dx = 2 * b * b * x # Calculate the temporary variable dx for the while loop condition
    dy = 2 * a * a * y # Calculate the temporary variable dy for the while loop condition

    while dx < dy: # Iterate through the major half of the ellipse
        addEllipsePoints(points, centerX, centerY, x, y) # Add the current ellipse point to the list

        if d1 < 0: # Check if the next point is on the left side of the ellipse
            x += 1 # Increment x and update dx
            dx += 2 * b * b
            d1 += dx + b * b
        else: # Check if the next point is on the right side of the ellipse
            x += 1 # Increment x
            y -= 1 # Decrement y and update dy
            dx += 2 * b * b
            dy -= 2 * a * a
            d1 += dx - dy + b * b

    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b # Calculate the discriminant d2 for the second half of the ellipse

    while y >= 0: # Iterate through the minor half of the ellipse
        addEllipsePoints(points, centerX, centerY, x, y) # Add the current ellipse point to the list

        if d2 > 0: # Check if the next point is below the ellipse
            y -= 1 # Decrement y and update dy
            dy -= 2 * a * a
            d2 += a * a - dy
        else: # Check if the next point is above the ellipse
            y -= 1 # Decrement y
            x += 1 # Increment x and update dx
            dx += 2 * b * b
            dy -= 2 * a * a
            d2 += dx - dy + a * a

def addEllipsePoints(points, centerX, centerY, x, y):
    points.append([centerX + x, centerY + y]) # Add the point with positive x and y coordinates to the list
    points.append([centerX - x, centerY + y]) # Add the point with negative x and positive y coordinates to the list
    points.append([centerX + x, centerY - y]) # Add the point with positive x and negative y coordinates to the list
    points.append([centerX - x, centerY - y]) # Add the point with negative x and negative y coordinates to the list

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    data = data[1:]
    x, y = data[0], data[1]
    a, b = data[2], data[3]
    points = drawEllipse(x, y, a, b)
    print(len(points))
    for point in points:
        print(*point)

