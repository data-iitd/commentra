
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def getX(self):
        return self.x
    
    def getY(self):
        return self.y
    
    def dominates(self, p1):
        return ((self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y))
    
    def __str__(self):
        return str(self.x) + " " + str(self.y)

class Main:
    def __init__(self):
        self.points = []
        
    def produceSubSkyLines(self, list):
        size = len(list)
        
        # Base case: if the list has only one element, return it
        if size == 1:
            return list
        
        # Base case: if the list has only two elements, check dominance and return the non-dominated point
        elif size == 2:
            if list[0].dominates(list[1]):
                list.remove(1) # remove the dominated point
            elif list[1].dominates(list[0]):
                list.remove(0) # remove the dominating point
            return list
        
        # Recursive case: divide the list into left and right halves and call produceSubSkyLines recursively
        leftHalf = list[:size // 2]
        rightHalf = list[size // 2:]
        leftSkyline = self.produceSubSkyLines(leftHalf) # produce sub skyline for left half
        rightSkyline = self.produceSubSkyLines(rightHalf) # produce sub skyline for right half
        return self.produceFinalSkyLine(leftSkyline, rightSkyline) # merge left and right sub sky lines to get the final skyline
    
    def produceFinalSkyLine(self, left, right):
        finalSkyline = []
        
        i = 0
        j = 0
        
        # Merge the smaller x-coordinate sub skyline into the final skyline
        while i < len(left) and j < len(right):
            if left[i].getX() < right[j].getX():
                finalSkyline.append(left[i]) # add point from left sub skyline
                i += 1
            elif left[i].getX() > right[j].getX():
                finalSkyline.append(right[j]) # add point from right sub skyline
                j += 1
            else: # if x-coordinates are equal, compare y-coordinates and add the dominating point
                finalSkyline.append(left[i].getY() < right[j].getY() and left[i] or right[j])
                i += 1
                j += 1
        
        # Add remaining points from left and right sub sky lines to the final skyline
        while i < len(left):
            finalSkyline.append(left[i])
            i += 1
        while j < len(right):
            finalSkyline.append(right[j])
            j += 1
        
        return finalSkyline

if __name__ == "__main__":
    scanner = Scanner(System.in) # initialize scanner to read input
    
    n = scanner.nextInt() # read number of points from input
    points = [] # initialize empty list to store points
    
    for i in range(n): # read x and y coordinates of each point and add it to the list
        x = scanner.nextInt()
        y = scanner.nextInt()
        points.append(Point(x, y))
    
    points.sort(key = lambda p: p.getX()) # sort points based on their x-coordinates
    
    skyline = Main() # create an instance of Main class
    result = skyline.produceSubSkyLines(points) # call produceSubSkyLines method to get the final skyline
    
    print("Final Skyline:") # print the header for final skyline
    
    for point in result: # print each point in the final skyline
        print(point)
    
    scanner.close() # close the scanner after reading input

