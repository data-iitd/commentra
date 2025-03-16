
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Class representing an element in a heap.
 *
 * <p>
 * A heap element contains two attributes: a key used for ordering in the heap
 * (which can be of type int or double, either as primitive types or as wrapper objects)
 * and an additional immutable object that can store any supplementary information the user desires.
 * Note that using mutable objects may compromise the integrity of this information.
 * </p>
 *
 * <p>
 * The key attribute is used to determine the order of elements in the heap,
 * while the additionalInfo attribute can carry user-defined data associated with the key.
 * </p>
 *
 * <p>
 * This class provides multiple constructors to accommodate various key types and includes
 * methods to retrieve the key and additional information.
 * </p>
 *
 * @author Nicolas Renard
 */
public class HeapElement {

    private final double key;
    private final Object additionalInfo;

    /**
     * Creates a HeapElement with the specified key and additional information.
     *
     * @param key  the key of the element (object type Double)
     * @param info any immutable object containing additional information, may be null
     */
    public HeapElement(double key, Object info) {
        this.key = key;
        this.additionalInfo = info;
    }

    /**
     * Creates a HeapElement with the specified key.
     *
     * @param key the key of the element (object type Double)
     */
    public HeapElement(double key) {
        this.key = key;
        this.additionalInfo = null;
    }

    // Getters
    /**
     * Returns the object containing the additional information provided by the user.
     *
     * @return the additional information
     */
    public Object getInfo() {
        return additionalInfo;
    }

    /**
     * Returns the key value of the element.
     *
     * @return the key of the element
     */
    public double getKey() {
        return key;
    }

    // Overridden object methods
    /**
     * Returns a string representation of the heap element.
     *
     * @return a string describing the key and additional information
     */
    @Override
    public String toString() {
        return "Key: " + key + " - " + (additionalInfo != null ? additionalInfo.toString() : "No additional info");
    }

    /**
     * @param o : an object to compare with the current element
     * @return true if the keys on both elements are identical and the
     * additional info objects are identical.
     */
    @Override
    public boolean equals(Object o) {
        if (o instanceof HeapElement otherHeapElement) {
            return this.key == otherHeapElement.key
                && (this.additionalInfo != null ? this.additionalInfo.equals(otherHeapElement.additionalInfo) : otherHeapElement.additionalInfo == null);
        }
        return false;
    }

    /**
     * Returns a hash code value for the heap element.
     *
     * @return a hash code value for this heap element
     */
    @Override
    public int hashCode() {
        int result = 31 * (int) key;
        result += (additionalInfo != null) ? additionalInfo.hashCode() : 0;
        return result;
    }

    // Main method for input processing
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<HeapElement> elements = new ArrayList<>();

        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.isEmpty()) {
                break;
            }

            String[] parts = command.split(" ");
            String operation = parts[0];

            try {
                switch (operation) {
                    case "create": // Create a new HeapElement
                        double key = Double.parseDouble(parts[1]);
                        String info = parts.length > 2 ? parts[2] : null;
                        HeapElement element = info != null ? new HeapElement(key, info) : new HeapElement(key);
                        elements.add(element);
                        System.out.println("Created: " + element);
                        break;

                    case "getKey": // Get the key of a specific element
                        int index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Key: " + elements.get(index).getKey());
                        }
                        break;

                    case "getInfo": // Get the additional info of a specific element
                        index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Info: " + elements.get(index).getInfo());
                        }
                        break;

                    case "print": // Print all elements
                        for (HeapElement el : elements) {
                            System.out.println(el);
                        }
                        break;

                    default:
                        System.out.println("Unknown operation: " + operation);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close();
    }
}
