import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    apple_num = next_int()
    piece_num = next_int()
    piece_num_made_from_apples = apple_num * 3
    total_piece = piece_num_made_from_apples + piece_num
    print(total_piece // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
