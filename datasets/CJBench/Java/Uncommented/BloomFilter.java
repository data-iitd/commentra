
import java.util.BitSet;
import java.util.Scanner;
public class BloomFilter<T> {
    private final int numberOfHashFunctions;
    private final BitSet bitArray;
    private final Hash<T>[] hashFunctions;
    public BloomFilter(int numberOfHashFunctions, int bitArraySize) {
        if (numberOfHashFunctions < 1 || bitArraySize < 1) {
            throw new IllegalArgumentException("Number of hash functions and bit array size must be greater than 0");
        }
        this.numberOfHashFunctions = numberOfHashFunctions;
        this.bitArray = new BitSet(bitArraySize);
        this.hashFunctions = new Hash[numberOfHashFunctions];
        initializeHashFunctions();
    }
    private void initializeHashFunctions() {
        for (int i = 0; i < numberOfHashFunctions; i++) {
            hashFunctions[i] = new Hash<>(i);
        }
    }
    public void insert(T key) {
        for (Hash<T> hash : hashFunctions) {
            int position = Math.abs(hash.compute(key) % bitArray.size());
            bitArray.set(position);
        }
    }
    public boolean contains(T key) {
        for (Hash<T> hash : hashFunctions) {
            int position = Math.abs(hash.compute(key) % bitArray.size());
            if (!bitArray.get(position)) {
                return false;
            }
        }
        return true;
    }
    private static class Hash<T> {
        private final int index;
        Hash(int index) {
            this.index = index;
        }
        public int compute(T key) {
            return index * asciiString(String.valueOf(key));
        }
        private int asciiString(String word) {
            int sum = 0;
            for (char c : word.toCharArray()) {
                sum += c;
            }
            return sum;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfHashFunctions = scanner.nextInt();
        int bitArraySize = scanner.nextInt();
        int numberOfElements = scanner.nextInt();
        BloomFilter<String> bloomFilter = new BloomFilter<>(numberOfHashFunctions, bitArraySize);
        for (int i = 0; i < numberOfElements; i++) {
            String element = scanner.next();
            bloomFilter.insert(element);
        }
        String query = scanner.next();
        boolean result = bloomFilter.contains(query);
        System.out.println("Element might be in the set: " + result);
    }
}
