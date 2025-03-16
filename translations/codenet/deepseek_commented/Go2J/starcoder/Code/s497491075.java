package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            new Main().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void run() throws IOException {
        Scanner sc = new Scanner(System.in);

        // Read the first line which contains two integers N and D.
        int[] a = sc.nextLine().split(" ");
        int N = Integer.parseInt(a[0]);
        int D = Integer.parseInt(a[1]);

        // Read the next N lines which contain pairs of integers representing points.
        String[] lines = sc.nextLine().split(" ");

        // Initialize a counter to keep track of points within the given distance.
        int count = 0;

        // Iterate over each point and calculate the distance from the origin.
        for (int i = 0; i < N; i++) {
            // Calculate the Euclidean distance of the point from the origin.
            double d = Math.sqrt(Math.pow(Integer.parseInt(lines[2*i]), 2) + Math.pow(Integer.parseInt(lines[2*i+1]), 2));
            // Check if the distance is within the given limit.
            if (D >= d) {
                count++;
            }
        }

        // Write the count of points within the distance to the writer.
        System.out.println(count);
    }
}

