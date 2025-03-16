class Work:
    def __init__(self, time, limit):
        self.time = time
        self.limit = limit

def main():
    n = int(input())
    works = []
    
    for _ in range(n):
        a, n = map(int, input().split())
        works.append(Work(a, n))
    
    works.sort(key=lambda w: w.limit)

    total_time = 0
    for w in works:
        total_time += w.time
        if total_time > w.limit:
            print("No")
            return
    
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
