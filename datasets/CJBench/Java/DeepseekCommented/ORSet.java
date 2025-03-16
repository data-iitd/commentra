import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.UUID;

public class Main {
    private final Set<Pair<T>> elements; // Initialize sets for elements and tombstones
    private final Set<Pair<T>> tombstones;

    public Main() {
        this.elements = new HashSet<>(); // Constructor initializes the sets
        this.tombstones = new HashSet<>();
    }

    public boolean contains(T element) {
        // Check if the element is present in the elements set
        return elements.stream().anyMatch(pair -> pair.getElement().equals(element));
    }

    public Set<T> elements() {
        // Return a set of all elements present in the elements set
        Set<T> result = new HashSet<>();
        elements.forEach(pair -> result.add(pair.getElement()));
        return result;
    }

    public void add(T element) {
        // Add a new element to the elements set by generating a unique tag
        String n = generateUniqueTag();
        effect(element, n);
    }

    public void remove(T element) {
        // Remove an element from the elements set and add it to the tombstones set
        Set<Pair<T>> pairsToRemove = prepare(element);
        effect(pairsToRemove);
    }

    private Set<Pair<T>> prepare(T element) {
        // Prepare a set of pairs to be removed from the elements set
        Set<Pair<T>> pairsToRemove = new HashSet<>();
        for (Pair<T> pair : elements) {
            if (pair.getElement().equals(element)) {
                pairsToRemove.add(pair);
            }
        }
        return pairsToRemove;
    }

    private void effect(T element, String n) {
        // Add a new pair to the elements set and remove tombstones
        Pair<T> pair = new Pair<>(element, n);
        elements.add(pair);
        elements.removeAll(tombstones);
    }

    private void effect(Set<Pair<T>> pairsToRemove) {
        // Remove pairs from the elements set and add them to the tombstones set
        elements.removeAll(pairsToRemove);
        tombstones.addAll(pairsToRemove);
    }

    private String generateUniqueTag() {
        // Generate a unique tag using UUID
        return UUID.randomUUID().toString();
    }

    public static class Pair<T> {
        // Nested class to hold an element and a unique tag
        private final T element;
        private final String uniqueTag;

        public Pair(T element, String uniqueTag) {
            this.element = element;
            this.uniqueTag = uniqueTag;
        }

        public T getElement() {
            return element;
        }
    }

    public static void main(String[] args) {
        // Main method to read input operations and elements, perform operations, and print results
        Scanner scanner = new Scanner(System.in);
        Main<String> orSet = new Main<>();
        int operations = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            String operation = input[0];
            String element = input[1];
            if (operation.equalsIgnoreCase("ADD")) {
                orSet.add(element);
            } else if (operation.equalsIgnoreCase("REMOVE")) {
                orSet.remove(element);
            } else {
                System.out.println("Invalid operation: " + operation);
            }
        }
        String checkElement = scanner.nextLine();
        System.out.println("Contains " + checkElement + ": " + orSet.contains(checkElement));
        System.out.println("Elements in Main: " + orSet.elements());
    }
}
