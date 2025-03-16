import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

public class Main {
    // List to hold the items of type T
    private List<T> list;
    // List to hold actions that will be applied to the stream
    private List<Action<T>> actions = new ArrayList<>();

    // Constructor to initialize the list
    public Main(List<T> list) {
        this.list = list;
    }

    // Method to filter the list based on a given predicate
    public Main<T> filter(Predicate<T> predicate) {
        // Add a new action to the list of actions
        actions.add(stream -> {
            List<T> result = new ArrayList<>();
            // Iterate through the items in the stream's list
            for (T item : stream.list) {
                // If the item matches the predicate, add it to the result list
                if (predicate.test(item)) {
                    result.add(item);
                }
            }
            // Update the stream's list to the filtered result
            stream.list = result;
        });
        return this; // Return the current instance for method chaining
    }

    // Method to map the items in the list to a different type R
    public <R> Main<R> map(Function<T, R> mapper) {
        List<R> mappedList = new ArrayList<>();
        // Iterate through the items in the current list
        for (T item : this.list) {
            // Apply the mapper function to each item and add to the mapped list
            mappedList.add(mapper.apply(item));
        }
        // Return a new Main instance containing the mapped list
        return new Main<>(mappedList);
    }

    // Method to collect the results into a list after applying all actions
    public List<T> collectToList() {
        // Apply each action in the actions list to the current stream
        for (Action<T> action : actions) {
            action.apply(this);
        }
        // Return the final list after all actions have been applied
        return list;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of items to be processed
        int n = scanner.nextInt();
        List<Item> list = new ArrayList<>();
        // Read each item and add it to the list
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            list.add(new Item(x, y));
        }
        // Create a Main instance with the list of items
        Main<Item> stream = new Main<>(list);
        // Filter items where y > 10, map to x values, and collect the results
        List<Integer> result = stream
                .filter(item -> item.getY() > 10) // Filter condition
                .map(Item::getX) // Mapping function to get x values
                .collectToList(); // Collect the results into a list
        // Print the resulting list of integers
        System.out.println(result);
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Functional interface for actions to be applied to the stream
    @FunctionalInterface
    interface Action<T> {
        void apply(Main<T> stream);
    }

    // Class representing an item with two integer properties
    public static class Item {
        private int x;
        private int y;

        // Constructor to initialize the item with x and y values
        public Item(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Getter for x value
        public int getX() {
            return x;
        }

        // Getter for y value
        public int getY() {
            return y;
        }

        // Override toString method for better representation of Item
        @Override
        public String toString() {
            return "Item{" + "x=" + x + ", y=" + y + '}';
        }
    }
}
