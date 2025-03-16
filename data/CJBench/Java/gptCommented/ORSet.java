import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.UUID;

public class Main {
    // Set to store unique elements
    private final Set<Pair<T>> elements;
    // Set to store tombstones for removed elements
    private final Set<Pair<T>> tombstones;

    // Constructor to initialize the sets
    public Main() {
        this.elements = new HashSet<>();
        this.tombstones = new HashSet<>();
    }

    // Method to check if an element exists in the set
    public boolean contains(T element) {
        return elements.stream().anyMatch(pair -> pair.getElement().equals(element));
    }

    // Method to retrieve all elements in the set
    public Set<T> elements() {
        Set<T> result = new HashSet<>();
        elements.forEach(pair -> result.add(pair.getElement()));
        return result;
    }

    // Method to add a new element to the set
    public void add(T element) {
        // Generate a unique tag for the new element
        String n = generateUniqueTag();
        // Create a pair and add it to the set
        effect(element, n);
    }

    // Method to remove an element from the set
    public void remove(T element) {
        // Prepare the pairs to be removed based on the element
        Set<Pair<T>> pairsToRemove = prepare(element);
        // Perform the removal effect
        effect(pairsToRemove);
    }

    // Helper method to prepare a set of pairs to be removed
    private Set<Pair<T>> prepare(T element) {
        Set<Pair<T>> pairsToRemove = new HashSet<>();
        // Iterate through elements to find matches for removal
        for (Pair<T> pair : elements) {
            if (pair.getElement().equals(element)) {
                pairsToRemove.add(pair);
            }
        }
        return pairsToRemove;
    }

    // Helper method to add a new element with a unique tag
    private void effect(T element, String n) {
        Pair<T> pair = new Pair<>(element, n);
        elements.add(pair);
        // Clean up any tombstones from the elements set
        elements.removeAll(tombstones);
    }

    // Helper method to remove pairs and add them to tombstones
    private void effect(Set<Pair<T>> pairsToRemove) {
        elements.removeAll(pairsToRemove);
        tombstones.addAll(pairsToRemove);
    }

    // Method to generate a unique tag using UUID
    private String generateUniqueTag() {
        return UUID.randomUUID().toString();
    }

    // Inner class to represent a pair of an element and its unique tag
    public static class Pair<T> {
        private final T element;
        private final String uniqueTag;

        // Constructor for Pair
        public Pair(T element, String uniqueTag) {
            this.element = element;
            this.uniqueTag = uniqueTag;
        }

        // Getter for the element
        public T getElement() {
            return element;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main<String> orSet = new Main<>();
        // Read the number of operations to perform
        int operations = Integer.parseInt(scanner.nextLine());
        
        // Loop through each operation
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            String operation = input[0];
            String element = input[1];
            // Perform the corresponding operation based on user input
            if (operation.equalsIgnoreCase("ADD")) {
                orSet.add(element);
            } else if (operation.equalsIgnoreCase("REMOVE")) {
                orSet.remove(element);
            } else {
                System.out.println("Invalid operation: " + operation);
            }
        }
        
        // Check if a specific element is contained in the set
        String checkElement = scanner.nextLine();
        System.out.println("Contains " + checkElement + ": " + orSet.contains(checkElement));
        // Display all elements in the set
        System.out.println("Elements in Main: " + orSet.elements());
    }
}
