
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Initialize a Scanner to read user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read user operation from the command line
        String operation = scanner.nextLine().trim();

        try {
            // Check if the operation is valid
            if (operation.equalsIgnoreCase("ipv4-to-ipv6")) {
                String ipv4Address = scanner.nextLine().trim();

                // Convert IPv4 address to IPv6-mapped IPv6 address
                String ipv6Address = ipv4ToIpv6(ipv4Address);

                // Print the result
                System.out.println("IPv6-mapped IPv6 Address: " + ipv6Address);
            } else if (operation.equalsIgnoreCase("ipv6-to-ipv4")) {
                String ipv6Address = scanner.nextLine().trim();

                // Convert IPv6-mapped IPv4 address to IPv4 address
                String ipv4Address = ipv6ToIpv4(ipv6Address);

                // Print the result
                System.out.println("Extracted IPv4 Address: " + ipv4Address);
            } else {
                // Print an error message for invalid operation
                System.out.println("Invalid operation.");
            }
        } catch (UnknownHostException | IllegalArgumentException e) {
            // Print an error message with the exception details
            System.out.println("Error: " + e.getMessage());
        } finally {
            // Close the Scanner to free system resources
            scanner.close();
        }
    }

    // Convert IPv4 address to IPv6-mapped IPv6 address
    public static String ipv4ToIpv6(String ipv4Address) throws UnknownHostException {
        if (ipv4Address == null || ipv4Address.isEmpty()) {
            // Throw an exception if the IPv4 address is empty
            throw new UnknownHostException("IPv4 address is empty.");
        }

        String[] segments = ipv4Address.split("\\.");
        if (segments.length != 4) {
            // Throw an exception if the IPv4 address has an incorrect number of segments
            throw new UnknownHostException("Invalid IPv4 address format.");
        }

        for (String segment : segments) {
            int value = Integer.parseInt(segment);
            if (value < 0 || value > 255) {
                // Throw an exception if any segment value is out of range
                throw new UnknownHostException("Invalid IPv4 address segment: " + segment);
            }
        }

        // Return the IPv6-mapped IPv6 address
        return "::ffff:" + ipv4Address;
    }

    // Convert IPv6-mapped IPv4 address to IPv4 address
    public static String ipv6ToIpv4(String ipv6Address) throws UnknownHostException {
        if (ipv6Address == null || ipv6Address.isEmpty()) {
            // Throw an exception if the IPv6 address is empty
            throw new UnknownHostException("IPv6 address is empty.");
        }

        if (!ipv6Address.startsWith("::ffff:")) {
            // Throw an exception if the IPv6 address is not a valid IPv6-mapped IPv4 address
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address.");
        }

        String[] parts = ipv6Address.split(":");
        if (parts.length < 3 || !parts[2].contains(".")) {
            // Throw an exception if the IPv6 address has an incorrect format
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address.");
        }

        // Return the IPv4 address
        return parts[2];
    }
}