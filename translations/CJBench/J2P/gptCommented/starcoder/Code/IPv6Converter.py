import socket
import sys

# Class to convert an IPv4 address to an IPv6-mapped IPv6 address
class IPv4ToIPv6:
    # Constructor to initialize the IPv4 address
    def __init__(self, ipv4Address):
        # Check if the provided IPv4 address is null or empty
        if ipv4Address == None or ipv4Address.strip() == "":
            raise Exception("IPv4 address is empty.")
        
        # Split the IPv4 address into its segments
        segments = ipv4Address.split(".")
        
        # Validate that the IPv4 address has exactly 4 segments
        if len(segments)!= 4:
            raise Exception("Invalid IPv4 address format.")
        
        # Validate each segment of the IPv4 address
        for segment in segments:
            value = int(segment)
            # Check if the segment value is within the valid range (0-255)
            if value < 0 or value > 255:
                raise Exception("Invalid IPv4 address segment: " + segment)
        
        # Initialize the IPv6-mapped IPv6 address
        self.ipv6Address = "::ffff:" + ipv4Address
    
    # Method to return the IPv6-mapped IPv6 address
    def getIpv6Address(self):
        return self.ipv6Address

# Class to convert an IPv6-mapped IPv4 address to an IPv4 address
class IPv6ToIPv4:
    # Constructor to initialize the IPv6 address
    def __init__(self, ipv6Address):
        # Check if the provided IPv6 address is null or empty
        if ipv6Address == None or ipv6Address.strip() == "":
            raise Exception("IPv6 address is empty.")
        
        # Validate that the IPv6 address starts with the IPv6-mapped prefix
        if not ipv6Address.startswith("::ffff:"):
            raise Exception("Not a valid IPv6-mapped IPv4 address.")
        
        # Split the IPv6 address into its parts
        parts = ipv6Address.split(":")
        
        # Validate that the IPv6 address has the correct format
        if len(parts) < 3 or not parts[2].contains("."):
            raise Exception("Not a valid IPv6-mapped IPv4 address.")
        
        # Initialize the extracted IPv4 address
        self.ipv4Address = parts[2]
    
    # Method to return the extracted IPv4 address
    def getIpv4Address(self):
        return self.ipv4Address

# Main function
def main():
    # Check if the number of command line arguments is correct
    if len(sys.argv)!= 2:
        print("Usage: " + sys.argv[0] + " <ipv4-to-ipv6|ipv6-to-ipv4>")
        sys.exit(1)
    
    # Read the operation type (ipv4-to-ipv6 or ipv6-to-ipv4) from the command line
    operation = sys.argv[1]
    
    # Create a Scanner object to read input from the console
    scanner = Scanner(sys.stdin)
    
    # Check if the operation is to convert IPv4 to IPv6
    if operation.strip().lower() == "ipv4-to-ipv6":
        # Read the IPv4 address from user input
        ipv4Address = scanner.nextLine().strip()
        # Convert the IPv4 address to IPv6
        ipv6Address = IPv4ToIPv6(ipv4Address).getIpv6Address()
        # Output the converted IPv6 address
        print("IPv6-mapped IPv6 Address: " + ipv6Address)
    # Check if the operation is to convert IPv6 to IPv4
    elif operation.strip().lower() == "ipv6-to-ipv4":
        # Read the IPv6 address from user input
        ipv6Address = scanner.nextLine().strip()
        # Convert the IPv6 address to IPv4
        ipv4Address = IPv6ToIPv4(ipv6Address).getIpv4Address()
        # Output the extracted IPv4 address
        print("Extracted IPv4 Address: " + ipv4Address)
    # Handle invalid operation input
    else:
        print("Invalid operation.")

# Call the main function
if __name__ == "__main__":
    main()

