
import java.util.* ;  // Importing the utility package for collections
import java.util.Map.* ; // Importing the Map interface

public class Main {
    private static int[] colors; // Declaring an integer array 'colors' to store colors of points

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the console
        int n = sc.nextInt(); // Reading the number of points 'n' from the console
        int m = n - 1; // Calculating the number of friendships 'm'
        colors = new int[n]; // Initializing the 'colors' array with '-1' to represent unvisited points
        Point[] points = new Point[n]; // Creating an array of 'Point' objects with size 'n'

        for (int i = 0; i < n; i++) { // Initializing the 'points' array with 'Point' objects
            points[i] = new Point(i);
        }

        while (m-- > 0) { // Reading and processing friendships between points
            int me = sc.nextInt() - 1; // Reading the index of the first point
            int you = sc.nextInt() - 1; // Reading the index of the second point
            int length = sc.nextInt(); // Reading the length of the friendship
            points[me].becomeFriend(points[you], length); // Establishing friendship between 'points[me]' and 'points[you]'
            points[you].becomeFriend(points[me], length); // Establishing friendship between 'points[you]' and 'points[me]'
        }

        dfs(points[0], 0); // Starting Depth-First Search from the first point

        for (int c : colors) { // Printing the colors of all points
            System.out.println(c);
        }
    }

    public static void dfs(Point p, int length) { // Depth-First Search function
        boolean alreadyKnown = colors[p.name] != -1; // Checking if the current point is already visited
        if (alreadyKnown) return; // Returning if the current point is already visited

        if (length % 2 == 0) { // Assigning color '0' to even-length friendships
            colors[p.name] = 0;
        } else { // Assigning color '1' to odd-length friendships
            colors[p.name] = 1;
        }

        for (Entry<Point, Integer> entry : p.friends.entrySet()) { // Iterating through the friends of the current point
            Point friend = entry.getKey(); // Getting the friend point
            int length2 = entry.getValue(); // Getting the length of the friendship
            dfs(friend, length + length2); // Recursively calling DFS on the friend point
        }
    }

    public static class Point { // Definition of the 'Point' class
        int name; // The name of the point
        Map<Point, Integer> friends; // The map to store friends and their friendship lengths

        Point(int name) { // Constructor of the 'Point' class
            this.name = name;
            this.friends = new HashMap<Point, Integer>(); // Initializing the 'friends' map
        }

        void becomeFriend(Point p, int length) { // Function to establish a friendship between two points
            this.friends.put(p, length); // Adding the friend and their friendship length to the 'friends' map
        }
    }
}

