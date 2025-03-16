import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String operation = scanner.nextLine().trim(); // Read the operation type from the user input and trim any extra spaces.
        try {
            if (operation.equalsIgnoreCase("ipv4-to-ipv6")) { // Check if the operation is "ipv4-to-ipv6".
                String ipv4Address = scanner.nextLine().trim(); // Read the IPv4 address from the user input.
                String ipv6Address = ipv4ToIpv6(ipv4Address); // Convert the IPv4 address to an IPv6 address.
                System.out.println("IPv6-mapped IPv6 Address: " + ipv6Address); // Print the result.
            } else if (operation.equalsIgnoreCase("ipv6-to-ipv4")) { // Check if the operation is "ipv6-to-ipv4".
                String ipv6Address = scanner.nextLine().trim(); // Read the IPv6 address from the user input.
                String ipv4Address = ipv6ToIpv4(ipv6Address); // Convert the IPv6 address to an IPv4 address.
                System.out.println("Extracted IPv4 Address: " + ipv4Address); // Print the result.
            } else {
                System.out.println("Invalid operation."); // Print an error message if the operation is invalid.
            }
        } catch (UnknownHostException | IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage()); // Print an error message if an exception occurs.
        } finally {
            scanner.close(); // Ensure the Scanner object is closed after the operations are completed.
        }
    }

    public static String ipv4ToIpv6(String ipv4Address) throws UnknownHostException {
        if (ipv4Address == null || ipv4Address.isEmpty()) { // Check if the IPv4 address is empty.
            throw new UnknownHostException("IPv4 address is empty."); // Throw an exception if the IPv4 address is empty.
        }
        String[] segments = ipv4Address.split("\\."); // Split the IPv4 address into segments.
        if (segments.length != 4) { // Check if the number of segments is 4.
            throw new UnknownHostException("Invalid IPv4 address format."); // Throw an exception if the format is invalid.
        }
        for (String segment : segments) { // Loop through each segment to check if it is a valid IPv4 segment.
            int value = Integer.parseInt(segment);
            if (value < 0 || value > 255) {
                throw new UnknownHostException("Invalid IPv4 address segment: " + segment); // Throw an exception if the segment is invalid.
            }
        }
        return "::ffff:" + ipv4Address; // Return the IPv6-mapped IPv6 address.
    }

    public static String ipv6ToIpv4(String ipv6Address) throws UnknownHostException {
        if (ipv6Address == null || ipv6Address.isEmpty()) { // Check if the IPv6 address is empty.
            throw new UnknownHostException("IPv6 address is empty."); // Throw an exception if the IPv6 address is empty.
        }
        if (!ipv6Address.startsWith("::ffff:")) { // Check if the IPv6 address starts with "::ffff:".
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address."); // Throw an exception if the address is not valid.
        }
        String[] parts = ipv6Address.split(":"); // Split the IPv6 address into parts.
        if (parts.length < 3 || !parts[2].contains(".")) { // Check if the parts length is at least 3 and if the third part contains a ".".
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address."); // Throw an exception if the address is not valid.
        }
        return parts[2]; // Return the extracted IPv4 address.
    }
}
