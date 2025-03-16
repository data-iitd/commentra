import sys

def main():
    # Create a scanner object to read input from the console
    scanner = sys.stdin
    
    # Read the number of points from the input
    n = int(scanner.readline())
    
    # Initialize a list to store the points
    points = []
    
    # Read each point's coordinates and add them to the list
    for i in range(n):
        x, y = map(int, scanner.readline().split())
        points.append((x, y))
    
    # Calculate the convex hull using the brute force method
    bruteForceHull = convexHullBruteForce(points)
    print("Convex Hull (Brute Force):")
    
    # Print the points in the convex hull obtained from brute force
    for p in bruteForceHull:
        print(p[0], p[1])
    
    # Calculate the convex hull using the recursive method
    recursiveHull = convexHullRecursive(points)
    print("Convex Hull (Recursive):")
    
    # Print the points in the convex hull obtained from the recursive method
    for p in recursiveHull:
        print(p[0], p[1])
    
    # Close the scanner to prevent resource leaks
    scanner.close()

def checkPointOrientation(i, j, k):
    detK = orientation(i, j, k)
    # Return true if k is on the left side of the line formed by i and j
    if detK > 0:
        return True
    # Return false if k is on the right side of the line formed by i and j
    elif detK < 0:
        return False
    # If k is collinear, check if it lies between i and j
    else:
        return k[0] >= i[0] and k[0] <= j[0] and k[1] >= i[1] and k[1] <= j[1]

def convexHullBruteForce(points):
    # Use a set to store unique points in the convex hull
    convexSet = set()
    
    # Iterate through all pairs of points to find the convex hull
    for i in range(len(points) - 1):
        for j in range(i + 1, len(points)):
            allPointsOnOneSide = True
            # Determine the orientation of the line segment formed by points i and j
            leftSide = checkPointOrientation(points[i], points[j], points[(i + 1) % len(points)])
            
            # Check if all other points are on the same side of the line segment
            for k in range(len(points)):
                if k != i and k != j and checkPointOrientation(points[i], points[j], points[k]) != leftSide:
                    allPointsOnOneSide = False
                    break
            
            # If all points are on one side, add the endpoints to the convex set
            if allPointsOnOneSide:
                convexSet.add(points[i])
                convexSet.add(points[j])
    
    # Return the convex hull as a list
    return list(convexSet)

def convexHullRecursive(points):
    # Sort the points to facilitate the construction of the convex hull
    points.sort()
    
    # Use a set to store unique points in the convex hull
    convexSet = set()
    
    # Identify the leftmost and rightmost points
    leftMostPoint = points[0]
    rightMostPoint = points[len(points) - 1]
    
    # Add the leftmost and rightmost points to the convex set
    convexSet.add(leftMostPoint)
    convexSet.add(rightMostPoint)
    
    # Lists to hold points for the upper and lower hulls
    upperHull = []
    lowerHull = []
    
    # Classify points into upper and lower hulls based on their orientation
    for i in range(1, len(points) - 1):
        det = orientation(leftMostPoint, rightMostPoint, points[i])
        if det > 0:
            upperHull.append(points[i])
        elif det < 0:
            lowerHull.append(points[i])
    
    # Construct the upper and lower hulls recursively
    constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet)
    constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet)
    
    # Prepare the result by converting the convex set to a list and sorting it
    result = list(convexSet)
    result.sort()
    return result

def constructHull(points, left, right, convexSet):
    if len(points) > 0:
        extremePoint = None
        extremePointDistance = -sys.maxsize
        candidatePoints = []
        
        # Find the point that is farthest from the line segment formed by left and right
        for p in points:
            det = orientation(left, right, p)
            if det > 0:
                candidatePoints.append(p)
                if det > extremePointDistance:
                    extremePointDistance = det
                    extremePoint = p
        
        # If an extreme point is found, recursively construct the hull
        if extremePoint is not None:
            constructHull(candidatePoints, left, extremePoint, convexSet)
            convexSet.add(extremePoint)
            constructHull(candidatePoints, extremePoint, right, convexSet)

def orientation(i, j, k):
    return (j[1] - i[1]) * (k[0] - j[0]) - (j[0] - i[0]) * (k[1] - j[1])

if __name__ == "__main__":
    main()

