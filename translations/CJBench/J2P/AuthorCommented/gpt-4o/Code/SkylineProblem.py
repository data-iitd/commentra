class Building:
    def __init__(self, left, height, right):
        self.left = left
        self.height = height
        self.right = right


class Skyline:
    def __init__(self, x, height):
        self.x = x
        self.height = height

    def __str__(self):
        return f"{self.x} {self.height}"


class Main:
    def __init__(self, num_buildings):
        self.buildings = []
        self.count = 0

    def add(self, left, height, right):
        self.buildings.append(Building(left, height, right))
        self.count += 1

    def find_skyline(self, start, end):
        if start == end:
            return [Skyline(self.buildings[start].left, self.buildings[start].height),
                    Skyline(self.buildings[start].right, 0)]

        mid = (start + end) // 2
        left_skyline = self.find_skyline(start, mid)
        right_skyline = self.find_skyline(mid + 1, end)
        return self.merge_skyline(left_skyline, right_skyline)

    def merge_skyline(self, sky1, sky2):
        merged_skyline = []
        h1 = h2 = max_height = 0
        i = j = 0

        while i < len(sky1) and j < len(sky2):
            if sky1[i].x < sky2[j].x:
                x = sky1[i].x
                h1 = sky1[i].height
                i += 1
            else:
                x = sky2[j].x
                h2 = sky2[j].height
                j += 1

            max_height = max(h1, h2)
            self.add_skyline_point(merged_skyline, x, max_height)

        while i < len(sky1):
            merged_skyline.append(sky1[i])
            i += 1

        while j < len(sky2):
            merged_skyline.append(sky2[j])
            j += 1

        return merged_skyline

    def add_skyline_point(self, skyline, x, height):
        if not skyline or skyline[-1].height != height:
            skyline.append(Skyline(x, height))


if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()
    num_buildings = int(data[0])
    skyline_problem = Main(num_buildings)

    for i in range(1, num_buildings + 1):
        left, height, right = map(int, data[i].split())
        skyline_problem.add(left, height, right)

    result = skyline_problem.find_skyline(0, num_buildings - 1)

    for point in result:
        print(point)

# <END-OF-CODE>
