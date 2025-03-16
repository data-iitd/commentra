class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dominates(self, other):
        return (self.x < other.x and self.y <= other.y) or (self.x <= other.x and self.y < other.y)

    def __str__(self):
        return f"{self.x} {self.y}"


class Main:
    def __init__(self):
        self.points = []

    def produce_sub_sky_lines(self, points):
        size = len(points)

        # Base case: if the list has only one element, return it
        if size == 1:
            return points

        # Base case: if the list has only two elements, check dominance and return the non-dominated point
        elif size == 2:
            if points[0].dominates(points[1]):
                return [points[0]]  # return the dominating point
            elif points[1].dominates(points[0]):
                return [points[1]]  # return the dominating point
            else:
                return points  # both points are non-dominating

        # Recursive case: divide the list into left and right halves and call produce_sub_sky_lines recursively
        left_half = points[:size // 2]
        right_half = points[size // 2:]
        left_skyline = self.produce_sub_sky_lines(left_half)  # produce sub skyline for left half
        right_skyline = self.produce_sub_sky_lines(right_half)  # produce sub skyline for right half
        return self.produce_final_sky_line(left_skyline, right_skyline)  # merge left and right sub sky lines

    def produce_final_sky_line(self, left, right):
        final_skyline = []
        i, j = 0, 0  # initialize pointers for left and right sub sky lines

        # Merge the smaller x-coordinate sub skyline into the final skyline
        while i < len(left) and j < len(right):
            if left[i].x < right[j].x:
                final_skyline.append(left[i])  # add point from left sub skyline
                i += 1
            elif left[i].x > right[j].x:
                final_skyline.append(right[j])  # add point from right sub skyline
                j += 1
            else:  # if x-coordinates are equal, compare y-coordinates and add the dominating point
                final_skyline.append(left[i] if left[i].y < right[j].y else right[j])
                i += 1
                j += 1

        # Add remaining points from left and right sub sky lines to the final skyline
        while i < len(left):
            final_skyline.append(left[i])
            i += 1
        while j < len(right):
            final_skyline.append(right[j])
            j += 1

        return final_skyline


if __name__ == "__main__":
    n = int(input("Enter number of points: "))  # read number of points from input
    points = []  # initialize empty list to store points

    for _ in range(n):  # read x and y coordinates of each point and add it to the list
        x, y = map(int, input().split())
        points.append(Point(x, y))

    points.sort(key=lambda p: p.x)  # sort points based on their x-coordinates

    skyline = Main()  # create an instance of Main class
    result = skyline.produce_sub_sky_lines(points)  # call produce_sub_sky_lines method to get the final skyline

    print("Final Skyline:")  # print the header for final skyline
    for point in result:  # print each point in the final skyline
        print(point)

# <END-OF-CODE>
