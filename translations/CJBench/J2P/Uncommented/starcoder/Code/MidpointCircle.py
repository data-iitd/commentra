
import sys

def generateCirclePoints(centerX, centerY, radius):
    points = []
    if radius == 0:
        points.append([centerX, centerY])
        return points
    x = radius
    y = 0
    p = 1 - radius
    addSymmetricPoints(points, centerX, centerY, x, y)
    while x > y:
        y += 1
        if p <= 0:
            p = p + 2 * y + 1
        else:
            x -= 1
            p = p + 2 * y - 2 * x + 1
        addSymmetricPoints(points, centerX, centerY, x, y)
    return points

def addSymmetricPoints(points, centerX, centerY, x, y):
    points.append([centerX + x, centerY + y])
    points.append([centerX - x, centerY + y])
    points.append([centerX + x, centerY - y])
    points.append([centerX - x, centerY - y])
    points.append([centerX + y, centerY + x])
    points.append([centerX - y, centerY + x])
    points.append([centerX + y, centerY - x])
    points.append([centerX - y, centerY - x])

if __name__ == "__main__":
    try:
        centerX = int(sys.argv[1])
        centerY = int(sys.argv[2])
        radius = int(sys.argv[3])
        circlePoints = generateCirclePoints(centerX, centerY, radius)
        print("The points on the circumference of the circle are:")
        for point in circlePoints:
            print("(%d, %d)" % (point[0], point[1]))
    except Exception as e:
        print("Invalid input! Please enter integers.")

