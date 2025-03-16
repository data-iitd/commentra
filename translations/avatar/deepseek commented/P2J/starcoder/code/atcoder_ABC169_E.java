import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of pairs
        int n = sc.nextInt();
        
        // Initialize lists to store the lower and higher values of each pair
        List<Integer> low = new ArrayList<Integer>();
        List<Integer> high = new ArrayList<Integer>();
        
        // Loop to read each pair and append values to the lists
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            low.add(a);
            high.add(b);
        }
        
        // Sort the lists
        Collections.sort(low);
        Collections.sort(high);
        
        // Check if the number of pairs is odd or even
        if (n % 2) {
            // If odd, calculate the range between the middle elements
            System.out.println(high.get((n + 1) / 2 - 1) - low.get((n + 1) / 2 - 1) + 1);
        } else {
            // If even, calculate the average of the middle elements and print the range
            int hh = (high.get(n / 2 - 1) + high.get(n / 2)) / 2;
            int ll = (low.get(n / 2 - 1) + low.get(n / 2)) / 2;
            System.out.println((hh - ll) * 2 + 1);
        }
    }
}

