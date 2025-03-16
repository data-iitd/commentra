
import math

def main():
    try:
        input = float(input())
        countOdd = math.floor(input / 2)
        result = countOdd / input
        print(round(result, 10))
    except ValueError:
        print("ValueError")
    except ZeroDivisionError:
        print("ZeroDivisionError")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
    print("