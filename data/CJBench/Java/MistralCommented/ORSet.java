
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.UUID;

public class Main<T> {
    // Initialize two empty HashSets for storing elements and tombstones
    private final Set<Pair<T>> elements;
    private final Set<Pair<T>> tombstones;

    public Main() {
        this.elements = new HashSet<>();
        this.tombstones = new HashSet<>();
        // Constructor initializes the elements and tombstones as empty HashSets
    }

    public boolean contains(T element) {
        // Check if the given element exists in the elements HashSet
        return elements.stream().anyMatch(pair -> pair.getElement().equals(element));
    }

    public Set<T> elements() {
        // Create a new HashSet and add all elements from the elements HashSet to it
        Set<T> result = new HashSet<>();
        elements.forEach(pair -> result.add(pair.getElement()));
        // Return the result HashSet containing all elements from the elements HashSet
        return result;
    }

    public void add(T element) {
        // Generate a unique tag for the new element
        String n = generateUniqueTag();
        // Add the new element-tag pair to the elements HashSet and remove all tombstones with the same element
        effect(element, n);
        // Print a message to the console indicating the addition of the new element
        System.out.println("Added " + element);
    }

    public void remove(T element) {
        // Find all elements in the elements HashSet with the given element
        Set<Pair<T>> pairsToRemove = prepare(element);
        // Remove the found elements and their tombstones from the HashSets
        effect(pairsToRemove);
        // Print a message to the console indicating the removal of the element
        System.out.println("Removed " + element);
    }

    private Set<Pair<T>> prepare(T element) {
        // Create an empty HashSet to store the pairs to be removed
        Set<Pair<T>> pairsToRemove = new HashSet<>();
        // Iterate through all pairs in the elements HashSet and remove the ones with the given element
        for (Pair<T> pair : elements) {
            if (pair.getElement().equals(element)) {
                pairsToRemove.add(pair);
            }
        }
        // Return the pairsToRemove HashSet
        return pairsToRemove;
    }

    private void effect(T element, String n) {
        // Create a new Pair with the given element and tag
        Pair<T> pair = new Pair<>(element, n);
        // Add the new pair to the elements HashSet and remove all tombstones with the same element
        elements.add(pair);
        elements.removeAll(tombstones);
    }

    private void effect(Set<Pair<T>> pairsToRemove) {
        // Remove the given pairs from the elements HashSet and add them to the tombstones HashSet
        elements.removeAll(pairsToRemove);
        tombstones.addAll(pairsToRemove);
    }

    private String generateUniqueTag() {
        // Generate a unique tag using UUID.randomUUID() method
        return UUID.randomUUID().toString();
    }

    public static class Pair<T> {
        // Initialize the element and uniqueTag fields
        private final T element;
        private final String uniqueTag;

        public Pair(T element, String uniqueTag) {
            this.element = element;
            this.uniqueTag = uniqueTag;
        }

        // Getter method for the element field
        public T getElement() {
            return element;
        }
    }

    public static void main(String[] args) {
        // Initialize a Scanner object for reading input from the console
        Scanner scanner = new Scanner(System.in);
        // Create a new instance of the Main class for strings
        Main<String> orSet = new Main<>();
        // Read the number of operations from the console
        int operations = Integer.parseInt(scanner.nextLine());
        // Iterate through the operations and perform the corresponding ADD or REMOVE operation
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            String operation = input[0];
            String element = input[1];
            if (operation.equalsIgnoreCase("ADD")) {
                orSet.add(element);
            } else if (operation.equalsIgnoreCase("REMOVE")) {
                orSet.remove(element);
            } else {
                // Print an error message for invalid operations
                System.out.println("Invalid operation: " + operation);
            }
        }
        // Read the element to check from the console
        String checkElement = scanner.nextLine();
        // Print the result of the contains() method call for the given element
        System.out.println("Contains " + checkElement + ": " + orSet.contains(checkElement));
        // Print the elements in the Main HashSet
        System.out.println("Elements in Main: " + orSet.elements());
        // Close the Scanner object
        scanner.close();
    }
}