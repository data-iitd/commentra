import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

public class Main {
    private List<T> list; // The list of items being processed
    private List<Action<T>> actions = new ArrayList<>(); // List to store actions (filters, maps)

    // Constructor to initialize the list of items
    public Main(List<T> list) {
        this.list = list;
    }

    // Filter method to apply a predicate to the list
    public Main<T> filter(Predicate<T> predicate) {
        actions.add(stream -> { // Add a new action to the list
            List<T> result = new ArrayList<>(); // Create a new list to store filtered results
            for (T item : stream.list) { // Iterate over the list
                if (predicate.test(item)) { // Apply the predicate
                    result.add(item); // Add item to the result if it passes the predicate
                }
            }
            stream.list = result; // Update the list with the filtered results
        });
        return this; // Return the current instance to allow method chaining
    }

    // Map method to apply a function to each element in the list
    public <R> Main<R> map(Function<T, R> mapper) {
        List<R> mappedList = new ArrayList<>(); // Create a new list to store mapped results
        for (T item : this.list) { // Iterate over the list
            mappedList.add(mapper.apply(item)); // Apply the function and add to the new list
        }
        return new Main<>(mappedList); // Return a new Main instance with the mapped list
    }

    // Collect to List method to execute all stored actions and return the final list
    public List<T> collectToList() {
        for (Action<T> action : actions) { // Iterate over all stored actions
            action.apply(this); // Apply each action to the stream
        }
        return list; // Return the final list
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of items
        List<Item> list = new ArrayList<>(); // Create a list to store items
        for (int i = 0; i < n; i++) { // Read each item
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            list.add(new Item(x, y));
        }
        Main<Item> stream = new Main<>(list); // Create a Main stream instance
        List<Integer> result = stream
                .filter(item -> item.getY() > 10) // Filter items with y > 10
                .map(Item::getX) // Map items to their x values
                .collectToList(); // Collect the final list
        System.out.println(result); // Print the result
        scanner.close(); // Close the scanner
    }

    // Functional interface to represent actions that can be applied to the stream
    @FunctionalInterface
    interface Action<T> {
        void apply(Main<T> stream);
    }

    // Item class representing an item with x and y fields
    public static class Item {
        private int x;
        private int y;

        // Constructor to initialize the item
        public Item(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Getter for x
        public int getX() {
            return x;
        }

        // Getter for y
        public int getY() {
            return y;
        }

        // Override toString method for easy printing
        @Override
        public String toString() {
            return "Item{" + "x=" + x + ", y=" + y + '}';
        }
    }
}
