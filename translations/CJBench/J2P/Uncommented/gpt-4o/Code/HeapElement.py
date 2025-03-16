class Main:
    def __init__(self, key, info=None):
        self.key = key
        self.additional_info = info

    def get_info(self):
        return self.additional_info

    def get_key(self):
        return self.key

    def __str__(self):
        return f"Key: {self.key} - {self.additional_info if self.additional_info is not None else 'No additional info'}"

    def __eq__(self, other):
        if isinstance(other, Main):
            return (self.key == other.key and
                    (self.additional_info == other.additional_info if self.additional_info is not None else other.additional_info is None))
        return False

    def __hash__(self):
        result = 31 * int(self.key)
        result += hash(self.additional_info) if self.additional_info is not None else 0
        return result


def main():
    elements = []
    while True:
        command = input().strip()
        if not command:
            break
        parts = command.split(" ")
        operation = parts[0]
        try:
            if operation == "create":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                element = Main(key, info) if info is not None else Main(key)
                elements.append(element)
                print(f"Created: {element}")
            elif operation == "getKey":
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print(f"Error: Index {index} is out of bounds. Valid range: 0 to {len(elements) - 1}")
                else:
                    print(f"Key: {elements[index].get_key()}")
            elif operation == "getInfo":
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print(f"Error: Index {index} is out of bounds. Valid range: 0 to {len(elements) - 1}")
                else:
                    print(f"Info: {elements[index].get_info()}")
            elif operation == "print":
                for el in elements:
                    print(el)
            else:
                print(f"Unknown operation: {operation}")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
