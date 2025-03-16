import sys
import math

def drawEllipse(centerX, centerY, a, b):
    points = []
    if a == 0 and b == 0:
        points.append([centerX, centerY])
        return points
    if a == 0:
        for y in range(centerY - b, centerY + b + 1):
            points.append([centerX, y])
        return points
    if b == 0:
        for x in range(centerX - a, centerX + a + 1):
            points.append([x, centerY])
        return points
    computeEllipsePoints(points, centerX, centerY, a, b)
    return points

def computeEllipsePoints(points, centerX, centerY, a, b):
    x = 0
    y = b
    d1 = b * b - a * a * b + 0.25 * a * a
    dx = 2 * b * b * x
    dy = 2 * a * a * y
    while dx < dy:
        addEllipsePoints(points, centerX, centerY, x, y)
        if d1 < 0:
            x += 1
            dx += 2 * b * b
            d1 += dx + b * b
        else:
            x += 1
            y -= 1
            dx += 2 * b * b
            dy -= 2 * a * a
            d1 += dx - dy + b * b
    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b
    while y >= 0:
        addEllipsePoints(points, centerX, centerY, x, y)
        if d2 > 0:
            y -= 1
            dy -= 2 * a * a
            d2 += a * a - dy
        else:
            y -= 1
            x += 1
            dx += 2 * b * b
            dy -= 2 * a * a
            d2 += dx - dy + a * a

def addEllipsePoints(points, centerX, centerY, x, y):
    points.append([centerX + x, centerY + y])
    points.append([centerX - x, centerY + y])
    points.append([centerX + x, centerY - y])
    points.append([centerX - x, centerY - y])

def main():
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    a = data[3::2]
    b = data[4::2]
    points = []
    for i in range(n):
        points.extend(drawEllipse(x[i], y[i], a[i], b[i]))
    for point in points:
        print(*point)

if __name__ == '__main__':
    main()

# 