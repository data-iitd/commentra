class Main:
    """
    Class representing an element in a heap.

    A heap element contains two attributes: a key used for ordering in the heap
    (which can be of type int or float) and an additional immutable object that can store
    any supplementary information the user desires. Note that using mutable objects may
    compromise the integrity of this information.

    The key attribute is used to determine the order of elements in the heap,
    while the additional_info attribute can carry user-defined data associated with the key.
    This class provides multiple constructors to accommodate various key types and includes
    methods to retrieve the key and additional information.
    """

    def __init__(self, key, additional_info=None):
        """
        Creates a Main with the specified key and additional information.

        :param key: the key of the element (object type float)
        :param additional_info: any immutable object containing additional information, may be None
        """
        self.key = key
        self.additional_info = additional_info

    def get_info(self):
        """
        Returns the object containing the additional information provided by the user.

        :return: the additional information
        """
        return self.additional_info

    def get_key(self):
        """
        Returns the key value of the element.

        :return: the key of the element
        """
        return self.key

    def __str__(self):
        """
        Returns a string representation of the heap element.

        :return: a string describing the key and additional information
        """
        return f"Key: {self.key} - {self.additional_info if self.additional_info is not None else 'No additional info'}"

    def __eq__(self, other):
        """
        Compares this Main object with another object.

        :param other: an object to compare with the current element
        :return: true if the keys on both elements are identical and the additional info objects are identical.
        """
        if isinstance(other, Main):
            return (self.key == other.key and
                    (self.additional_info == other.additional_info))
        return False

    def __hash__(self):
        """
        Returns a hash code value for the heap element.

        :return: a hash code value for this heap element
        """
        return hash((self.key, self.additional_info))

def main():
    import sys

    elements = []

    for line in sys.stdin:
        command = line.strip()
        if not command:
            break

        parts = command.split()
        operation = parts[0]

        try:
            if operation == "create":  # Create a new Main
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                element = Main(key, info) if info is not None else Main(key)
                elements.append(element)
                print(f"Created: {element}")

            elif operation == "getKey":  # Get the key of a specific element
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print(f"Error: Index {index} is out of bounds. Valid range: 0 to {len(elements) - 1}")
                else:
                    print(f"Key: {elements[index].get_key()}")

            elif operation == "getInfo":  # Get the additional info of a specific element
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print(f"Error: Index {index} is out of bounds. Valid range: 0 to {len(elements) - 1}")
                else:
                    print(f"Info: {elements[index].get_info()}")

            elif operation == "print":  # Print all elements
                for el in elements:
                    print(el)

            else:
                print(f"Unknown operation: {operation}")

        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
