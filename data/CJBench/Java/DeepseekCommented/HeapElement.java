import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // The key value associated with this object.
    private final double key;
    // Additional information associated with this object.
    private final Object additionalInfo;

    // Constructor that initializes both key and additionalInfo.
    public Main(double key, Object info) {
        this.key = key;
        this.additionalInfo = info;
    }

    // Constructor that initializes only the key, with additionalInfo set to null.
    public Main(double key) {
        this.key = key;
        this.additionalInfo = null;
    }

    // Getter method for retrieving the additional information.
    public Object getInfo() {
        return additionalInfo;
    }

    // Getter method for retrieving the key.
    public double getKey() {
        return key;
    }

    // Provides a string representation of the object, including the key and additional information if available.
    @Override
    public String toString() {
        return "Key: " + key + " - " + (additionalInfo != null ? additionalInfo.toString() : "No additional info");
    }

    // Compares this object with another for equality based on key and additionalInfo.
    @Override
    public boolean equals(Object o) {
        if (o instanceof Main otherMain) {
            return this.key == otherMain.key
                && (this.additionalInfo != null ? this.additionalInfo.equals(otherMain.additionalInfo) : otherMain.additionalInfo == null);
        }
        return false;
    }

    // Generates a hash code for this object based on key and additionalInfo.
    @Override
    public int hashCode() {
        int result = 31 * (int) key;
        result += (additionalInfo != null) ? additionalInfo.hashCode() : 0;
        return result;
    }

    // Main method to run the command-line interface for managing Main objects.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Main> elements = new ArrayList<>();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.isEmpty()) {
                break;
            }
            String[] parts = command.split(" ");
            String operation = parts[0];
            try {
                switch (operation) {
                    case "create": 
                        double key = Double.parseDouble(parts[1]);
                        String info = parts.length > 2 ? parts[2] : null;
                        Main element = info != null ? new Main(key, info) : new Main(key);
                        elements.add(element);
                        System.out.println("Created: " + element);
                        break;
                    case "getKey": 
                        int index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Key: " + elements.get(index).getKey());
                        }
                        break;
                    case "getInfo": 
                        index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Info: " + elements.get(index).getInfo());
                        }
                        break;
                    case "print": 
                        for (Main el : elements) {
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
