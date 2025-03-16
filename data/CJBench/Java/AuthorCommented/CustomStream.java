import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

/**
 * Implement CustomStream class to make possible usage of filter() and map() operations like next expression:
 * stream.filter(item -> item.y > 10).map(Item::getX);
 * <p>
 * Add collectToList() method to CustomStream
 *
 * @see <a href="https://youtu.be/LvBjS17CatQ">Video solution part1</a>, <a href="https://youtu.be/iuzWoSzl1to">part2</a>
 */
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

        // Input the number of items
        int n = scanner.nextInt();
        List<Item> list = new ArrayList<>();

        // Input each item
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            list.add(new Item(x, y));
        }

        // Create CustomStream
        CustomStream<Item> stream = new CustomStream<>(list);

        // Filter and map based on conditions
        List<Integer> result = stream
                .filter(item -> item.getY() > 10) // Filter items where y > 10
                .map(Item::getX) // Map to 'x' values
                .collectToList();

        // Print the result
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
