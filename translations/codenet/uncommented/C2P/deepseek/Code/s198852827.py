def can_reach_all_points(N, points):
    nx, ny, nt = 0, 0, 0
    
    for t, x, y in points:
        distance = abs(x - nx) + abs(y - ny)
        time_diff = t - nt - distance
        
        if time_diff < 0 or time_diff % 2 != 0:
            return "No"
        
        nx, ny, nt = x, y, t
    
    return "Yes"

# Read input
N = int(input())
points = [tuple(map(int, input().split())) for _ in range(N)]

# Output the result
print(can_reach_all_points(N, points))
