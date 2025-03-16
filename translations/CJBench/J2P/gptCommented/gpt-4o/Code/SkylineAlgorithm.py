class Point:
    def __init__(self, x, y):
        self.x = x  # x-coordinate
        self.y = y  # y-coordinate

    def dominates(self, other):
        return (self.x < other.x and self.y <= other.y) or (self.x <= other.x and self.y < other.y)

    def __str__(self):
        return f"{self.x} {self.y}"


class Main:
    def __init__(self):
        self.points = []  # List to store points representing the skyline

    def produce_sub_sky_lines(self, points):
        size = len(points)

        # Base case: if there's only one point, return it as the skyline
        if size == 1:
            return points
        # Base case: if there are two points, determine which one dominates the other
        elif size == 2:
            if points[0].dominates(points[1]):
                return [points[0]]  # Keep the dominating point
            elif points[1].dominates(points[0]):
                return [points[1]]  # Keep the dominating point
            else:
                return points  # Neither dominates

        # Split the list into left and right halves
        mid = size // 2
        left_half = points[:mid]
        right_half = points[mid:]

        # Recursively compute the skyline for both halves
        left_skyline = self.produce_sub_sky_lines(left_half)
        right_skyline = self.produce_sub_sky_lines(right_half)

        # Merge the two skylines into a final skyline
        return self.produce_final_sky_line(left_skyline, right_skyline)

    def produce_final_sky_line(self, left, right):
        final_skyline = []
        i, j = 0, 0

        # Merge points from left and right skylines based on x-coordinates
        while i < len(left) and j < len(right):
            if left[i].x < right[j].x:
                final_skyline.append(left[i])
                i += 1
            elif left[i].x > right[j].x:
                final_skyline.append(right[j])
                j += 1
            else:
                # If x-coordinates are equal, add the point with the smaller y-coordinate
                final_skyline.append(left[i] if left[i].y < right[j].y else right[j])
                i += 1
                j += 1

        # Add remaining points from the left skyline
        while i < len(left):
            final_skyline.append(left[i])
            i += 1

        # Add remaining points from the right skyline
        while j < len(right):
            final_skyline.append(right[j])
            j += 1

        return final_skyline  # Return the merged final skyline


# Main execution
if __name__ == "__main__":
    n = int(input("Enter the number of points: "))
    points = []

    # Read each point's coordinates and add to the list
    for _ in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))

    # Sort points based on x-coordinate
    points.sort(key=lambda p: p.x)

    # Create an instance of Main to compute the skyline
    skyline = Main()

    # Produce the final skyline from the list of points
    result = skyline.produce_sub_sky_lines(points)

    # Print the final skyline points
    print("Final Skyline:")
    for point in result:
        print(point)

# <END-OF-CODE>
