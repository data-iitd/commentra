import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        List<Integer> l = new ArrayList<>();
        
        String[] input = scanner.nextLine().split(" ");
        for (String s : input) {
            l.add(Integer.parseInt(s));
        }
        
        Collections.sort(l);
        
        boolean found = false;
        for (int i : l) {
            if (l.contains(i + 1) && l.contains(i + 2)) {
                System.out.println("YES");
                found = true;
                break;
            }
        }
        
        if (!found) {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
