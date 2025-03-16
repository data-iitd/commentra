import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
public class CustomStream<T> {
    private List<T> list;
    private List<Action<T>> actions = new ArrayList<>();
    public CustomStream(List<T> list) {
        this.list = list;
    }
    public CustomStream<T> filter(Predicate<T> predicate) {
        actions.add(stream -> {
            List<T> result = new ArrayList<>();
            for (T item : stream.list) {
                if (predicate.test(item)) {
                    result.add(item);
                }
            }
            stream.list = result;
        });
        return this;
    }
    public <R> CustomStream<R> map(Function<T, R> mapper) {
        List<R> mappedList = new ArrayList<>();
        for (T item : this.list) {
            mappedList.add(mapper.apply(item));
        }
        return new CustomStream<>(mappedList);
    }
    public List<T> collectToList() {
        for (Action<T> action : actions) {
            action.apply(this);
        }
        return list;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Item> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            list.add(new Item(x, y));
        }
        CustomStream<Item> stream = new CustomStream<>(list);
        List<Integer> result = stream
                .filter(item -> item.getY() > 10) 
                .map(Item::getX) 
                .collectToList();
        System.out.println(result);
        scanner.close();
    }
    @FunctionalInterface
    interface Action<T> {
        void apply(CustomStream<T> stream);
    }
    public static class Item {
        private int x;
        private int y;
        public Item(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
        @Override
        public String toString() {
            return "Item{" + "x=" + x + ", y=" + y + '}';
        }
    }
}
