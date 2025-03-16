
import java.util.*; // Import the Scanner and ArrayList classes

public class s623008479{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a Scanner object
		int n = sc.nextInt(); // Read the value of n from the input
		int k = sc.nextInt(); // Read the value of k from the input
		ArrayList<Integer> l = new ArrayList<Integer>(); // Create an ArrayList of size n
		for(int i = 0; i < n; i++){
			l.add(sc.nextInt()); // Read the elements of the ArrayList l
		}

		Collections.sort(l); // Sort the ArrayList l in ascending order

		int ans = 0; // Initialize ans to 0
		for(int i = 0; i < k; i++){
			ans += l.get(n - 1 - i); // Sum the last k elements of the sorted ArrayList
		}
		System.out.println(ans); // Print the result
		sc.close(); // Close the Scanner object
	}
}
