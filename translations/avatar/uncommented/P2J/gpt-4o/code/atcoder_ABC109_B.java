import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        Map<String, Integer> s = new HashMap<>();
        List<String> l = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextLine());
        }
        
        String f = "Yes";
        int i = -1;
        
        for (String v : l) {
            s.put(v, s.getOrDefault(v, 0) + 1);
            if (s.get(v) >= 2) {
                f = "No";
            }
            if (i != -1 && l.get(i).charAt(l.get(i).length() - 1) != v.charAt(0)) {
                f = "No";
            }
            i++;
        }
        
        System.out.println(f);
        scanner.close();
    }
}

// <END-OF-CODE>
