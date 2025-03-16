import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().split(" ");
        
        List<Pair> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(new Pair(i + 1, Integer.parseInt(input[i])));
        }
        
        Collections.sort(A, Comparator.comparingInt(pair -> pair.value));
        
        for (int i = 0; i < A.size() - 1; i++) {
            System.out.print(A.get(i).index + " ");
        }
        System.out.println(A.get(A.size() - 1).index);
    }
    
    static class Pair {
        int index;
        int value;
        
        Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}
//<END-OF-CODE>
