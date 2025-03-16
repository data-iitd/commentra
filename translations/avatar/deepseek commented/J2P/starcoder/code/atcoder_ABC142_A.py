
import sys

# Import statements to handle input/output operations and mathematical calculations

def main():
    try:
        input = float(input())
        countOdd = round(input / 2)
        result = countOdd / input
        print(result)
    except IOError as e:
        print(e)
        sys.exit(0)
    except ValueError as e:
        print(e)
        sys.exit(0)
    except Exception as e:
        print(e)
        sys.exit(0)

if __name__ == "__main__":
    main()

