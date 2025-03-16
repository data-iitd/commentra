
import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

// Main class for handling a list of items and applying filters and transformations
public class Main {
    // Private instance variable for the list of items
    private List<T> list;
    // Private instance variable for the list of actions to be applied to the stream
    private List<Action<T>> actions = new ArrayList<>();

    // Constructor for initializing the Main object with the given list
    public Main(List<T> list) {
        this.list = list;
    }

    // Method for filtering the items based on a given predicate
    public <T> Main<T> filter(Predicate<T> predicate) {
        // Add an action to the list of actions to filter the items
        actions.add(stream -> {
            List<T> result = new ArrayList<>();
            // Iterate through each item in the list and add it to the result list if it satisfies the predicate
            for (T item : stream.list) {
                if (predicate.test(item)) {
                    result.add(item);
                }
            }
            // Replace the original list with the filtered list
            stream.list = result;
        });
        // Return the current Main object for method chaining
        return this;
    }

    // Method for transforming each item in the list using a given mapper function
    public <R> Main<R> map(Function<T, R> mapper) {
        // Create a new list to store the transformed items
        List<R> mappedList = new ArrayList<>();
        // Iterate through each item in the list and apply the mapper function to transform it
        for (T item : this.list) {
            // Apply the mapper function to the item and add the transformed result to the new list
            mappedList.add(mapper.apply(item));
        }
        // Return a new Main object with the transformed list
        return new Main<>(mappedList);
    }

    // Method for collecting the items in the list into a List
    public List<T> collectToList() {
        // Iterate through each action in the list of actions and apply it to the stream
        for (Action<T> action : actions) {
            action.apply(this);
        }
        // Return the original list after applying all the actions
        return list;
    }

    // Main method for running the program and demonstrating the usage of the Main class
    public static void main(String[] args) {
        // Create a Scanner object for reading input from the console
        Scanner scanner = new Scanner(System.in);
        // Read the number of items to be added to the list from the console
        int n = scanner.nextInt();
        // Create an ArrayList to store the items
        List<Item> list = new ArrayList<>();
        // Iterate through each item and add it to the list
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            // Create an Item object with the given x and y coordinates and add it to the list
            list.add(new Item(x, y));
        }
        // Create a Main object with the given list and apply filters and transformations to it
        Main<Item> stream = new Main<>(list);
        // Filter the items based on the y coordinate being greater than 10
        List<Integer> result = stream
                // Apply the filter method to the stream object
                .filter(item -> item.getY() > 10)
                // Map each filtered item to its x coordinate
                .map(Item::getX)
                // Collect the transformed items into a List
                .collectToList();
        // Print the result to the console
        System.out.println(result);
        // Close the Scanner object
        scanner.close();
    }

    // Functional interface for defining an action to be applied to the stream
    @FunctionalInterface
    interface Action<T> {
        // Define the apply method for applying the action to the stream
        void apply(Main<T> stream);
    }

    // Static inner class for defining the Item object
    public static class Item {
        // Private instance variables for storing the x and y coordinates
        private int x;
        private int y;

        // Constructor for initializing the Item object with the given x and y coordinates
        public Item(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Getter method for retrieving the x coordinate
        public int getX() {
            return x;
        }

        // Getter method for retrieving the y coordinate
        public int getY() {
            return y;
        }

        // Override the toString method for printing the Item object in a readable format
        @Override
        public String toString() {
            return "Item{" + "x=" + x + ", y=" + y + '}';
        }
    }
}