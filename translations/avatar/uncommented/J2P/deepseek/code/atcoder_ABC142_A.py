import sys

def main():
    try:
        input_line = sys.stdin.readline().strip()
        input_value = float(input_line)
        count_odd = round(input_value / 2)
        result = count_odd / input_value
        print("{:.10f}".format(result))
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        sys.exit(1)
    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
