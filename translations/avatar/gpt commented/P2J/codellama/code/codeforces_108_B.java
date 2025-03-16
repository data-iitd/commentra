public class Main {
    public static void main(String[] args) {
        // Read an input line (not used in the logic)
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        
        // Read a line of integers, split by spaces, and convert them to a list of integers
        List<Integer> a = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        
        // Sort the list of integers in ascending order
        Collections.sort(a);
        
        // Iterate through the sorted list starting from the second element
        for (int i = 1; i < a.size(); i++) {
            // Check if the current element is different from the previous one
            // and if it is less than double the previous element
            if (!a.get(i).equals(a.get(i - 1)) && a.get(i) < a.get(i - 1) * 2) {
                // If the condition is met, print 'YES'
                System.out.println("YES");
                return;
            }
        }
        
        // If no such pair is found, print 'NO'
        System.out.println("NO");
    }
}

// 