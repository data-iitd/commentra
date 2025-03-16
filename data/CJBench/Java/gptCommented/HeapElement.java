import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Instance variables to hold the key and additional information
    private final double key;
    private final Object additionalInfo;

    // Constructor to initialize key and additional information
    public Main(double key, Object info) {
        this.key = key;
        this.additionalInfo = info;
    }

    // Constructor to initialize key without additional information
    public Main(double key) {
        this.key = key;
        this.additionalInfo = null;
    }

    // Getter method to retrieve additional information
    public Object getInfo() {
        return additionalInfo;
    }

    // Getter method to retrieve the key
    public double getKey() {
        return key;
    }

    // Override toString method to provide a string representation of the object
    @Override
    public String toString() {
        return "Key: " + key + " - " + (additionalInfo != null ? additionalInfo.toString() : "No additional info");
    }

    // Override equals method to compare two Main objects based on key and additional info
    @Override
    public boolean equals(Object o) {
        if (o instanceof Main otherMain) {
            return this.key == otherMain.key
                && (this.additionalInfo != null ? this.additionalInfo.equals(otherMain.additionalInfo) : otherMain.additionalInfo == null);
        }
        return false;
    }

    // Override hashCode method to generate a hash code based on key and additional info
    @Override
    public int hashCode() {
        int result = 31 * (int) key;
        result += (additionalInfo != null) ? additionalInfo.hashCode() : 0;
        return result;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        // List to hold Main objects
        ArrayList<Main> elements = new ArrayList<>();

        // Loop to continuously read commands until an empty line is entered
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            // Exit the loop if the command is empty
            if (command.isEmpty()) {
                break;
            }

            // Split the command into parts for processing
            String[] parts = command.split(" ");
            String operation = parts[0];

            try {
                // Switch statement to handle different operations
                switch (operation) {
                    case "create": 
                        // Create a new Main object with the specified key and optional info
                        double key = Double.parseDouble(parts[1]);
                        String info = parts.length > 2 ? parts[2] : null;
                        Main element = info != null ? new Main(key, info) : new Main(key);
                        elements.add(element);
                        System.out.println("Created: " + element);
                        break;

                    case "getKey": 
                        // Retrieve and print the key of the Main object at the specified index
                        int index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Key: " + elements.get(index).getKey());
                        }
                        break;

                    case "getInfo": 
                        // Retrieve and print the additional info of the Main object at the specified index
                        index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Info: " + elements.get(index).getInfo());
                        }
                        break;

                    case "print": 
                        // Print all Main objects in the list
                        for (Main el : elements) {
                            System.out.println(el);
                        }
                        break;

                    default:
                        // Handle unknown operations
                        System.out.println("Unknown operation: " + operation);
                }
            } catch (Exception e) {
                // Print any errors that occur during command processing
                System.out.println("Error: " + e.getMessage());
            }
        }
        // Close the scanner to free resources
        scanner.close();
    }
}
