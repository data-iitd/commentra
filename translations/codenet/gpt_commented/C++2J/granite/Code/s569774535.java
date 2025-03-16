
import java.util.*;

public class s569774535{
    public static void main(String[] args) {
        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize a list to store the elements
        List<Integer> a = new ArrayList<>();
        
        // Input the elements into the list
        for(int i = 0; i < n; i++){
            a.add(sc.nextInt());
        }

        // Initialize the answer counter and a flag for the loop
        int ans = 0;
        boolean ok = true;

        // Loop until an odd number is found in the list
        while(ok){
            // Check each element in the list
            for(int i = 0; i < n; i++){
                // If the current element is odd, print the answer and exit
                if(a.get(i) % 2 == 1){
                    System.out.println(ans);
                    return;
                }
                // If the current element is even, divide it by 2
                else{
                    a.set(i, a.get(i) / 2);
                }
            }
            // Increment the answer counter for each complete iteration
            ans++;
        }

        // Output the final count of divisions by 2 before encountering an odd number
        System.out.println(ans);
    }
}
