
import java.util.ArrayList;
import java.util.Scanner;
public class HeapElement {
    private final double key;
    private final Object additionalInfo;
    public HeapElement(double key, Object info) {
        this.key = key;
        this.additionalInfo = info;
    }
    public HeapElement(double key) {
        this.key = key;
        this.additionalInfo = null;
    }
    public Object getInfo() {
        return additionalInfo;
    }
    public double getKey() {
        return key;
    }
    @Override
    public String toString() {
        return "Key: " + key + " - " + (additionalInfo != null ? additionalInfo.toString() : "No additional info");
    }
    @Override
    public boolean equals(Object o) {
        if (o instanceof HeapElement otherHeapElement) {
            return this.key == otherHeapElement.key
                && (this.additionalInfo != null ? this.additionalInfo.equals(otherHeapElement.additionalInfo) : otherHeapElement.additionalInfo == null);
        }
        return false;
    }
    @Override
    public int hashCode() {
        int result = 31 * (int) key;
        result += (additionalInfo != null) ? additionalInfo.hashCode() : 0;
        return result;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<HeapElement> elements = new ArrayList<>();
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.isEmpty()) {
                break;
            }
            String[] parts = command.split(" ");
            String operation = parts[0];
            try {
                switch (operation) {
                    case "create": 
                        double key = Double.parseDouble(parts[1]);
                        String info = parts.length > 2 ? parts[2] : null;
                        HeapElement element = info != null ? new HeapElement(key, info) : new HeapElement(key);
                        elements.add(element);
                        System.out.println("Created: " + element);
                        break;
                    case "getKey": 
                        int index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Key: " + elements.get(index).getKey());
                        }
                        break;
                    case "getInfo": 
                        index = Integer.parseInt(parts[1]);
                        if (index < 0 || index >= elements.size()) {
                            System.out.println("Error: Index " + index + " is out of bounds. Valid range: 0 to " + (elements.size() - 1));
                        } else {
                            System.out.println("Info: " + elements.get(index).getInfo());
                        }
                        break;
                    case "print": 
                        for (HeapElement el : elements) {
                            System.out.println(el);
                        }
                        break;
                    default:
                        System.out.println("Unknown operation: " + operation);
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
