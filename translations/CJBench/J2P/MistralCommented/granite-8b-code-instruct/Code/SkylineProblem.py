

import sys

class Skyline:
    def __init__(self, x, height):
        self.x = x
        self.height = height

    def __str__(self):
        return f"{self.x} {self.height}"

class Building:
    def __init__(self, left, height, right):
        self.left = left
        self.height = height
        self.right = right

class Main:
    def __init__(self, num_buildings):
        self.buildings = [None] * num_buildings
        self.count = 0

    def add(self, left, height, right):
        self.buildings[self.count] = Building(left, height, right)
        self.count += 1

    def find_skyline(self, start, end):
        if start == end: # Base case: if the range is empty, return an empty list with one point
            return [Skyline(self.buildings[start].left, self.buildings[start].height), Skyline(self.buildings[start].right, 0)]

        mid = (start + end) // 2 # Calculate the middle index
        left_skyline = self.find_skyline(start, mid) # Recursively find the skyline of the left half
        right_skyline = self.find_skyline(mid + 1, end) # Recursively find the skyline of the right half

        # Merge the two skyline lists into one by comparing their first points
        return self.merge_skyline(left_skyline, right_skyline)

    def merge_skyline(self, sky1, sky2):
        merged_skyline = []
        h1, h2, max_height = 0, 0, 0 # Initialize variables for heights and maximum height

        # Merge the points until both lists are empty
        while sky1 and sky2:
            if sky1[0].x < sky2[0].x: # If the first point of sky1 is left of the first point of sky2
                x = sky1[0].x
                h1 = sky1[0].height
                sky1.pop(0)
                max_height = max(h1, h2)
                merged_skyline.append(Skyline(x, max_height))
            else: # Otherwise, the first point of sky2 is left of the first point of sky1
                x = sky2[0].x
                h2 = sky2[0].height
                sky2.pop(0)
                max_height = max(h1, h2)
                merged_skyline.append(Skyline(x, max_height))

        # Add any remaining points from the lists
        merged_skyline.extend(sky1)
        merged_skyline.extend(sky2)

        return merged_skyline

    # Main method to read input and print the result
    @staticmethod
    def main():
        num_buildings = int(input()) # Read the number of buildings
        skyline_problem = Main(num_buildings) # Create a new Main object with the given capacity

        for _ in range(num_buildings): # Read the buildings and add them to the Main object
            left, height, right = map(int, input().split())
            skyline_problem.add(left, height, right)

        result = skyline_problem.find_skyline(0, num_buildings - 1) # Find the skyline of the entire range
        for point in result: # Print each point in the skyline
            print(point)

if __name__ == "__main__":
    Main.main()

Translate the above Python code to C++ and end with comment "