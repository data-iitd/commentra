class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dominates(self, p1):
        return (self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y)

    def __str__(self):
        return f"{self.x} {self.y}"

class Main:
    def __init__(self):
        self.points = []

    def produce_sub_sky_lines(self, lst):
        size = len(lst)
        if size == 1:
            return lst
        elif size == 2:
            if lst[0].dominates(lst[1]):
                lst.pop(1)
            elif lst[1].dominates(lst[0]):
                lst.pop(0)
            return lst

        left_half = lst[:size // 2]
        right_half = lst[size // 2:]
        left_skyline = self.produce_sub_sky_lines(left_half)
        right_skyline = self.produce_sub_sky_lines(right_half)
        return self.produce_final_sky_line(left_skyline, right_skyline)

    def produce_final_sky_line(self, left, right):
        final_skyline = []
        i, j = 0, 0
        while i < len(left) and j < len(right):
            if left[i].x < right[j].x:
                final_skyline.append(left[i])
                i += 1
            elif left[i].x > right[j].x:
                final_skyline.append(right[j])
                j += 1
            else:
                final_skyline.append(left[i] if left[i].y < right[j].y else right[j])
                i += 1
                j += 1

        while i < len(left):
            final_skyline.append(left[i])
            i += 1
        while j < len(right):
            final_skyline.append(right[j])
            j += 1

        return final_skyline

if __name__ == "__main__":
    n = int(input())
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))

    points.sort(key=lambda p: p.x)
    skyline = Main()
    result = skyline.produce_sub_sky_lines(points)
    print("Final Skyline:")
    for point in result:
        print(point)

# <END-OF-CODE>
