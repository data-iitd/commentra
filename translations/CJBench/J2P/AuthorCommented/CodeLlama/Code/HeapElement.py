
import sys

class Main:
    def __init__(self, key, additionalInfo=None):
        self.key = key
        self.additionalInfo = additionalInfo

    def getKey(self):
        return self.key

    def getInfo(self):
        return self.additionalInfo

    def __str__(self):
        return "Key: " + str(self.key) + " - " + (self.additionalInfo if self.additionalInfo else "No additional info")

    def __eq__(self, other):
        return self.key == other.key and self.additionalInfo == other.additionalInfo

    def __hash__(self):
        result = 31 * self.key
        result += self.additionalInfo.hashCode() if self.additionalInfo else 0
        return result

def main():
    elements = []
    while True:
        command = input().strip()
        if command == "":
            break

        parts = command.split(" ")
        operation = parts[0]

        try:
            if operation == "create":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                element = Main(key, info)
                elements.append(element)
                print("Created: " + str(element))
            elif operation == "getKey":
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print("Error: Index " + str(index) + " is out of bounds. Valid range: 0 to " + str(len(elements) - 1))
                else:
                    print("Key: " + str(elements[index].getKey()))
            elif operation == "getInfo":
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print("Error: Index " + str(index) + " is out of bounds. Valid range: 0 to " + str(len(elements) - 1))
                else:
                    print("Info: " + str(elements[index].getInfo()))
            elif operation == "print":
                for el in elements:
                    print(el)
            else:
                print("Unknown operation: " + operation)
        except Exception as e:
            print("Error: " + str(e))

if __name__ == "__main__":
    main()

