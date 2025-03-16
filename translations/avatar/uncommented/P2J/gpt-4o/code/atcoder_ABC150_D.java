import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int num = scanner.nextInt();
        Set<Integer> numSet = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            numSet.add(scanner.nextInt());
        }
        
        Set<Integer> twoTimesSet = new HashSet<>();
        for (int i : numSet) {
            int temp = i;
            for (int j = 1; j < 30; j++) {
                temp /= 2;
                if (temp % 2 != 0) {
                    twoTimesSet.add(j);
                    break;
                }
            }
            if (twoTimesSet.size() != 1) {
                System.out.println(0);
                return;
            }
        }
        
        List<Integer> numList = new ArrayList<>(numSet);
        int lcm = numList.get(0);
        for (int i = 1; i < numList.size(); i++) {
            lcm = lcm * numList.get(i) / gcd(lcm, numList.get(i));
        }
        
        System.out.println((num - lcm / 2) / lcm + 1);
    }
    
    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

// <END-OF-CODE>
