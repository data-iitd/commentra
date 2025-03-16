
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.UUID;
public class ORSet<T> {
    private final Set<Pair<T>> elements;
    private final Set<Pair<T>> tombstones;
    public ORSet() {
        this.elements = new HashSet<>();
        this.tombstones = new HashSet<>();
    }
    public boolean contains(T element) {
        return elements.stream().anyMatch(pair -> pair.getElement().equals(element));
    }
    public Set<T> elements() {
        Set<T> result = new HashSet<>();
        elements.forEach(pair -> result.add(pair.getElement()));
        return result;
    }
    public void add(T element) {
        String n = generateUniqueTag();
        effect(element, n);
    }
    public void remove(T element) {
        Set<Pair<T>> pairsToRemove = prepare(element);
        effect(pairsToRemove);
    }
    private Set<Pair<T>> prepare(T element) {
        Set<Pair<T>> pairsToRemove = new HashSet<>();
        for (Pair<T> pair : elements) {
            if (pair.getElement().equals(element)) {
                pairsToRemove.add(pair);
            }
        }
        return pairsToRemove;
    }
    private void effect(T element, String n) {
        Pair<T> pair = new Pair<>(element, n);
        elements.add(pair);
        elements.removeAll(tombstones);
    }
    private void effect(Set<Pair<T>> pairsToRemove) {
        elements.removeAll(pairsToRemove);
        tombstones.addAll(pairsToRemove);
    }
    private String generateUniqueTag() {
        return UUID.randomUUID().toString();
    }
    public static class Pair<T> {
        private final T element;
        private final String uniqueTag;
        public Pair(T element, String uniqueTag) {
            this.element = element;
            this.uniqueTag = uniqueTag;
        }
        public T getElement() {
            return element;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ORSet<String> orSet = new ORSet<>();
        int operations = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < operations; i++) {
            String[] input = scanner.nextLine().split(" ");
            String operation = input[0];
            String element = input[1];
            if (operation.equalsIgnoreCase("ADD")) {
                orSet.add(element);
            } else if (operation.equalsIgnoreCase("REMOVE")) {
                orSet.remove(element);
            } else {
                System.out.println("Invalid operation: " + operation);
            }
        }
        String checkElement = scanner.nextLine();
        System.out.println("Contains " + checkElement + ": " + orSet.contains(checkElement));
        System.out.println("Elements in ORSet: " + orSet.elements());
    }
}
