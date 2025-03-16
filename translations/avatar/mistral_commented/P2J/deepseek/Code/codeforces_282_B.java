public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take the first line as an input
        int firstline = Integer.parseInt(scanner.nextLine());
        
        // Initialize total and memory lists
        int total = 0;
        StringBuilder memory = new StringBuilder();
        
        // Loop through the given number of lines
        for (int x = 0; x < firstline; x++) {
            // Take two integers as input, A and G
            String[] input = scanner.nextLine().split(" ");
            int A = Integer.parseInt(input[0]);
            int G = Integer.parseInt(input[1]);
            
            // Check if adding A to the total memory usage is within the limit
            if (total + A <= 500) {
                // If yes, add A to the total and append 'A' to the memory list
                total += A;
                memory.append("A");
            } else {
                // If no, subtract G from the total and append 'G' to the memory list
                total -= G;
                memory.append("G");
            }
        }
        
        // Print the final memory state
        System.out.println(memory.toString());
    }
}
