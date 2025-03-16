import sys

class Main:
    # Private constructor to prevent instantiation of the Main class
    def __init__(self):
        pass

    # Main method
    def main(self):
        # Read the number of points from the input
        n = int(sys.stdin.readline().strip())
        
        # Initialize a list to store the points
        points = []
        
        # Read each point's coordinates and add them to the list
        for i in range(n):
            x, y = map(int, sys.stdin.readline().strip().split())
            points.append(Point(x, y))
        
        # Calculate the convex hull using the brute force method
        bruteForceHull = self.convexHullBruteForce(points)
        print("Convex Hull (Brute Force):")
        
        # Print the points in the convex hull obtained from brute force
        for p in bruteForceHull:
            print(p.x, p.y)
        
        # Calculate the convex hull using the recursive method
        recursiveHull = self.convexHullRecursive(points)
        print("Convex Hull (Recursive):")
        
        # Print the points in the convex hull obtained from the recursive method
        for p in recursiveHull:
            print(p.x, p.y)

    # Check the orientation of the triplet (i, j, k)
    def checkPointOrientation(self, i, j, k):
        detK = Point.orientation(i, j, k)
        # Return true if k is on the left side of the line formed by i and j
        if detK > 0:
            return True 
        # Return false if k is on the right side of the line formed by i and j
        elif detK < 0:
            return False 
        # If k is collinear, check if it lies between i and j
        else:
            return k.compareTo(i) >= 0 and k.compareTo(j) <= 0

    # Calculate the convex hull using a brute force approach
    def convexHullBruteForce(self, points):
        # Use a set to store unique points in the convex hull
        convexSet = set()
        
        # Iterate through all pairs of points to find the convex hull
        for i in range(len(points) - 1):
            for j in range(i + 1, len(points)):
                allPointsOnOneSide = True
                # Determine the orientation of the line segment formed by points i and j
                leftSide = self.checkPointOrientation(points[i], points[j], points[(i + 1) % len(points)])
                
                # Check if all other points are on the same side of the line segment
                for k in range(len(points)):
                    if k!= i and k!= j and self.checkPointOrientation(points[i], points[j], points[k])!= leftSide:
                        allPointsOnOneSide = False
                        break
                
                # If all points are on one side, add the endpoints to the convex set
                if allPointsOnOneSide:
                    convexSet.add(points[i])
                    convexSet.add(points[j])
        # Return the convex hull as a list
        return list(convexSet)

    # Calculate the convex hull using a recursive approach
    def convexHullRecursive(self, points):
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
            det = Point.orientation(leftMostPoint, rightMostPoint, points[i])
            if det > 0:
                upperHull.append(points[i])
            elif det < 0:
                lowerHull.append(points[i])
        
        # Construct the upper and lower hulls recursively
        self.constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet)
        self.constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet)
        
        # Prepare the result by converting the convex set to a list and sorting it
        result = list(convexSet)
        result.sort()
        return result

    # Recursively construct the convex hull from a set of candidate points
    def constructHull(self, points, left, right, convexSet):
        if len(points) > 0:
            extremePoint = None
            extremePointDistance = -sys.maxsize
            candidatePoints = []
            
            # Find the point that is farthest from the line segment formed by left and right
            for p in points:
                det = Point.orientation(left, right, p)
                if det > 0:
                    candidatePoints.append(p)
                    if det > extremePointDistance:
                        extremePointDistance = det
                        extremePoint = p
            # If an extreme point is found, recursively construct the hull
            if extremePoint!= None:
                self.constructHull(candidatePoints, left, extremePoint, convexSet)
                convexSet.add(extremePoint)
                self.constructHull(candidatePoints, extremePoint, right, convexSet)

# Point class representing a point in 2D space
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    # Calculate the orientation of the triplet (i, j, k)
    @staticmethod
    def orientation(i, j, k):
        return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)
    
    # Compare points for sorting based on x and y coordinates
    def compareTo(self, other):
        return (self.x == other.x) and (self.y == other.y)

# Main method
if __name__ == "__main__":
    Main().main()

# 