import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input values: the first value is N (number of points), followed by the coordinates
        int N = sc.nextInt();
        int[] XY = new int[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            XY[i] = sc.nextInt();
        }
        
        // Pair the coordinates into a list of tuples (x, y)
        List<Pair<Integer, Integer>> XYList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            XYList.add(new Pair<>(XY[2 * i], XY[2 * i + 1]));
        }
        
        // Iterate over each point in the list with its index
        for (int i = 0; i < N; i++) {
            // Calculate angles from the current point (x, y) to all other points
            List<Double> D = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (i!= j) {
                    double x = XYList.get(j).getKey();
                    double y = XYList.get(j).getValue();
                    double d = Math.atan2(x - XYList.get(i).getKey(), y - XYList.get(i).getValue());
                    D.add(d);
                }
            }
            
            // Append the angle that wraps around (2*pi) to handle circularity
            D.add(D.get(0) + 2 * Math.PI);
            
            // Initialize the answer for the current point
            double ans = 0;
            
            // Calculate the gaps between consecutive angles
            for (int j = 0; j < D.size() - 1; j++) {
                double a = D.get(j);
                double b = D.get(j + 1);
                
                // Check if the gap is greater than or equal to pi
                if (b - a >= Math.PI) {
                    // Update the answer with the size of the gap minus pi
                    ans += (b - a) - Math.PI;
                }
            }
            
            // Print the normalized answer (as a fraction of 2*pi)
            System.out.println(ans / (2 * Math.PI));
        }
    }
}

Pair<Integer, Integer>

class Pair<K, V> {
    private K key;
    private V value;
    
    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
    
    public K getKey() {
        return key;
    }
    
    public V getValue() {
        return value;
    }
}

