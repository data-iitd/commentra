import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Define a class to hold a person's name and their time
class Person {
    String name;  // Name of the person
    int time;     // Time associated with the person

    Person(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q;  // Number of people and query time
        int totalTime = 0;  // Total time served

        // Read the number of people and the query time
        n = scanner.nextInt();
        q = scanner.nextInt();
        Queue<Person> queue = new LinkedList<>();  // Queue to hold Person objects

        // Read each person's name and time, and enqueue them
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Person(name, time));  // Add the person to the queue
        }

        // Process the queue until all people have been served
        while (!queue.isEmpty()) {
            Person current = queue.poll();  // Remove the front person from the queue
            // Check if the person's time exceeds the query time
            if (current.time > q) {
                current.time -= q;  // Reduce their time by the query time
                totalTime += q;     // Add query time to total time
                queue.add(current);  // Re-enqueue the person with the remaining time
            } else {
                totalTime += current.time;  // Add the person's time to total time
                System.out.println(current.name + " " + totalTime);  // Print the person's name and total time
            }
        }

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
