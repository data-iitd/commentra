import sys

def main():
    N = int(input())
    values = []
    for i in range(N):
        values.append(float(input()))
    values.sort()
    generated = 0
    for i in range(N-1):
        generated = (values[i] + values[i+1]) / 2
        values[i+1] = generated
    print(generated)

if __name__ == "__main__":
    main()

