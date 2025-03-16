import sys

def out(*args):
    # print(*args)

class Data:
    def __init__(self, x):
        self.x = x

class Datas:
    def __init__(self, data_list):
        self.data_list = data_list

    def __len__(self):
        return len(self.data_list)

    def __getitem__(self, index):
        return self.data_list[index]

    def sort(self):
        self.data_list.sort(key=lambda data: data.x)

def next_int():
    return int(sys.stdin.readline().strip())

def next_string():
    return sys.stdin.readline().strip()

def main():
    N = next_int()
    L = next_int()
    s = []

    for _ in range(N):
        s.append(Data(next_string()))

    out(N, L, s)
    data_collection = Datas(s)
    data_collection.sort()
    out(data_collection.data_list)

    ans = ''.join(data.x for data in data_collection.data_list)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
