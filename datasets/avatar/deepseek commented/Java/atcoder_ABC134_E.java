import java.util.*; // Importing the utility package for using Scanner and TreeMap

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in); // Initializing a Scanner object to read input
        int n = sc.nextInt(); // Reading the integer n from the input
        TreeMap<Integer, Integer> map = new TreeMap<>(); // Initializing a TreeMap to store the frequency of numbers

        // Looping n times to read n numbers
        while (n-- > 0) {
            int num = sc.nextInt(); // Reading the next integer from the input

            // Checking if there is no key less than the current number
            if (map.lowerKey(num) == null) {
                // Incrementing the frequency of the current number
                int val = map.getOrDefault(num, 0); // Getting the current frequency or defaulting to 0
                map.put(num, ++val); // Updating the frequency in the map
            } else {
                // Finding the largest key less than the current number
                int key = map.lowerKey(num);
                // Decrementing the frequency of the found key and removing it if frequency becomes zero
                int val = map.get(key);
                if (val == 1) {
                    map.remove(key);
                } else {
                    map.put(key, --val);
                }
                // Incrementing the frequency of the current number
                val = map.getOrDefault(num, 0);
                map.put(num, ++val);
            }
        }

        // Calculating the sum of all frequencies in the map
        int ans = 0;
        for (Integer key : map.keySet()) {
            int val = map.get(key);
            ans += val;
        }

        // Printing the sum of frequencies
        System.out.println(ans);
    }
}
