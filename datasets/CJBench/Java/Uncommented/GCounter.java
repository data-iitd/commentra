
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
class GCounter {
    private final Map<Integer, Integer> counterMap;
    private final int myId;
    private final int n;
    GCounter(int myId, int n) {
        this.myId = myId;
        this.n = n;
        this.counterMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            counterMap.put(i, 0);
        }
    }
    public void increment() {
        counterMap.put(myId, counterMap.get(myId) + 1);
    }
    public int value() {
        int sum = 0;
        for (int v : counterMap.values()) {
            sum += v;
        }
        return sum;
    }
    public boolean compare(GCounter other) {
        for (int i = 0; i < n; i++) {
            if (this.counterMap.get(i) > other.counterMap.get(i)) {
                return false;
            }
        }
        return true;
    }
    public void merge(GCounter other) {
        for (int i = 0; i < n; i++) {
            this.counterMap.put(i, Math.max(this.counterMap.get(i), other.counterMap.get(i)));
        }
    }
    public Map<Integer, Integer> getState() {
        return counterMap;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int myId = scanner.nextInt();
        GCounter counter = new GCounter(myId, n);
        int operations = scanner.nextInt();
        for (int i = 0; i < operations; i++) {
            int operation = scanner.nextInt();
            if (operation == 1) {
                counter.increment();
            } else if (operation == 2) {
                int mergeId = scanner.nextInt();
                GCounter otherCounter = new GCounter(mergeId, n);
                for (int j = 0; j < n; j++) {
                    otherCounter.counterMap.put(j, scanner.nextInt());
                }
                counter.merge(otherCounter);
            } else {
                System.out.println("Invalid operation.");
            }
        }
        System.out.println("Final counter value: " + counter.value());
        System.out.println("Final counter state: " + counter.getState());
    }
}
