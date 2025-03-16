import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        List<Integer> L = new ArrayList<>();
        
        // Read the first input (not used)
        scanner.nextLine();
        
        int r = 1;
        String[] input1 = scanner.nextLine().split(" ");
        for (String k : input1) {
            int count = Integer.parseInt(k);
            for (int i = 0; i < count; i++) {
                L.add(r);
            }
            r++;
        }
        
        // Read the second input (not used)
        scanner.nextLine();
        
        String[] input2 = scanner.nextLine().split(" ");
        for (String j : input2) {
            int index = Integer.parseInt(j) - 1;
            System.out.println(L.get(index));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
