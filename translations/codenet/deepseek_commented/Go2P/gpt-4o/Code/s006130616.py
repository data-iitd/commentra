def main():
    n, m, x = map(int, input().split())  # 1. Reading the number of courses, the number of skills, and the minimum required skill level.

    a = []  # 2. Dynamically allocating memory for the 2D list representing the cost of each course for each skill.
    p = []  # 3. Allocating memory for the list representing the cost of each course.
    
    for i in range(n):
        p.append(int(input()))  # 4. Reading the cost of each course.
        skills = list(map(int, input().split()))  # 5. Reading the skill levels for each course.
        a.append(skills)

    ans = 1200001  # 7. Initializing the answer with a large number. This will hold the minimum cost of courses that meet the skill requirement.
    
    for bits in range(1 << n):  # 10. Iterating through all possible combinations of courses using bitwise operations.
        tot = 0
        ok = True
        skill = [0] * m  # 11. Initializing a list to keep track of the total skill level for the current combination.
        
        for i in range(n):
            if (bits >> i) & 1 == 1:  # 12. Checking if the i-th course is included in the current combination.
                tot += p[i]
                for j in range(m):
                    skill[j] += a[i][j]  # 13. Updating the total skill level for each skill.

        for v in skill:  # 14. Checking if all skill levels are at least x.
            if v < x:
                ok = False
                break

        if ok:  # 15. If the current combination meets the skill requirement, updating the answer if the cost is lower.
            if ans > tot:
                ans = tot

    if ans != 1200001:  # 16. Printing the result.
        print(ans)
    else:
        print("-1")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
