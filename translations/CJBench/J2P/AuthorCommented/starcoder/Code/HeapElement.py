
import java.util.ArrayList;
import java.util.Scanner;

class Main:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def getInfo(self):
        return self.info

    def getKey(self):
        return self.key

    def __str__(self):
        return "Key: " + str(self.key) + " - " + (self.info!= None and "Info: " + str(self.info) or "No additional info")

    def __eq__(self, other):
        return self.key == other.key and (self.info!= None and self.info == other.info or self.info == None and other.info == None)

    def __hash__(self):
        result = 31 * (int) self.key
        result += (self.info!= None) and self.info.hashCode() or 0
        return result

if __name__ == "__main__":
    scanner = Scanner(System.in)
    elements = ArrayList()

    while scanner.hasNextLine():
        command = scanner.nextLine().trim()
        if command.isEmpty():
            break

        parts = command.split(" ")
        operation = parts[0]

        try:
            if operation == "create": # Create a new Main
                key = Double.parseDouble(parts[1])
                info = parts.length > 2 and parts[2] or None
                element = info!= None and Main(key, info) or Main(key)
                elements.add(element)
                print("Created: " + element)
            elif operation == "getKey": # Get the key of a specific element
                index = Integer.parseInt(parts[1])
                if index < 0 or index >= elements.size():
                    print("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1))
                else:
                    print("Key: " + elements.get(index).getKey())
            elif operation == "getInfo": # Get the additional info of a specific element
                index = Integer.parseInt(parts[1])
                if index < 0 or index >= elements.size():
                    print("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1))
                else:
                    print("Info: " + elements.get(index).getInfo())
            elif operation == "print": # Print all elements
                for el in elements:
                    print(el)
            else:
                print("Unknown operation: " + operation)
        except Exception as e:
            print("Error: " + e.getMessage())

    scanner.close()

