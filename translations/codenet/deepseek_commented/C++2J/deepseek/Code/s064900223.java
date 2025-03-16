public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Step 4: Read the input value for `n`
        int[] p = new int[n]; // Step 5: Create an array `p` of size `n`
        for(int i = 0; i < n; i++){ // Step 6: Read values into the array `p`
            p[i] = scanner.nextInt();
        }
        int ans = 0; // Step 7: Initialize `ans` to 0
        for(int i = 0; i < n - 1; i++){ // Step 8: Loop through the array `p`
            if(p[i] == i + 1){ // If the current element `p[i]` is equal to `i+1`
                p[i + 1] = p[i]; // Set the next element `p[i+1]` to `p[i]`
                ans += 1; // Increment `ans`
            }
        }
        if(p[n - 1] == n){ // Step 9: Check the last element
            ans += 1; // Increment `ans` if the last element is equal to `n`
        }
        System.out.println(ans); // Step 10: Output the result
    }
}
