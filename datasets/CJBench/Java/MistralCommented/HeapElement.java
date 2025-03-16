
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Constructor with key and additional info
    private final double key;
    private final Object additionalInfo;

    public Main(double key, Object info) {
        this.key = key;
        this.additionalInfo = info;
    }

    // Constructor with key only
    public Main(double key) {
        this.key = key;
        this.additionalInfo = null;
    }

    // Getter for additional info
    public Object getInfo() {
        return additionalInfo;
    }

    // Getter for key
    public double getKey() {
        return key;
    }

    // Override toString method to display key and additional info
    @Override
    public String toString() {
        return "Key: " + key + " - " + (additionalInfo != null ? additionalInfo.toString() : "No additional info");
    }

    // Override equals method to compare keys and additional info
    @Override
    public boolean equals(Object o) {
        if (o instanceof Main otherMain) {
            return this.key == otherMain.key
                    && (this.additionalInfo != null ? this.additionalInfo.equals(otherMain.additionalInfo) : otherMain.additionalInfo == null);
        }
        return false;
    }

    // Override hashCode method to include key and additional info
    @Override
    public int hashCode() {
        int result = 31 * (int) key;
        result += (additionalInfo != null) ? additionalInfo.hashCode() : 0;
        return result;
    }

    // Main method to read commands from user input and process them
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner to read user input
        ArrayList<Main> elements = new ArrayList<>(); // Initialize empty ArrayList to store Main objects

        while (scanner.hasNextLine()) { // Read user input line by line
            String command = scanner.nextLine().trim(); // Trim whitespaces from command

            if (command.isEmpty()) { // Check if command is empty
                break; // Exit the loop if command is empty
            }

            String[] parts = command.split(" "); // Split command into parts based on whitespaces
            String operation = parts[0]; // Get the operation from the first part

            try { // Begin try block to handle valid commands
                switch (operation) {
                    case "create": // Handle "create" command
                        double key = Double.parseDouble(parts[1]); // Parse key from command
                        String info = parts.length > 2 ? parts[2] : null; // Get additional info if it exists
                        Main element = info != null ? new Main(key, info) : new Main(key); // Create new Main object
                        elements.add(element); // Add new Main object to ArrayList
                        System.out.println("Created: " + element); // Print created Main object
                        break;
                    case "getKey": // Handle "getKey" command
                        int index = Integer.parseInt(parts[1]); // Parse index from command
                        if (index < 0 || index >= elements.size()) { // Check if index is valid
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1)); // Print error message if index is invalid
                        } else { // If index is valid
                            System.out.println("Key: " + elements.get(index).getKey()); // Print key of Main object at given index
                        }
                        break;
                    case "getInfo": // Handle "getInfo" command
                        index = Integer.parseInt(parts[1]); // Parse index from command
                        if (index < 0 || index >= elements.size()) { // Check if index is valid
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1)); // Print error message if index is invalid
                        } else { // If index is valid
                            System.out.println("Info: " + elements.get(index).getInfo()); // Print additional info of Main object at given index
                        }
                        break;
                    case "print": // Handle "print" command
                        for (Main el : elements) { // Iterate through ArrayList and print each Main object
                            System.out.println(el); // Print Main object
                        }
                        break;
                    default: // Handle invalid operation
                        System.out.println("Unknown operation: " + operation); // Print error message
                }
            } catch (Exception e) { // Catch exceptions thrown during command processing
                System.out.println("Error: " + e.getMessage()); // Print error message
            }
        }

        scanner.close(); // Close scanner after processing all user input
    }
}