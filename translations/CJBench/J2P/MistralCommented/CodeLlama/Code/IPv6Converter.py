
import ipaddress
import socket
import sys

def ipv4_to_ipv6(ipv4_address):
    try:
        # Check if the IPv4 address is valid
        socket.inet_aton(ipv4_address)
    except socket.error:
        # Throw an exception if the IPv4 address is invalid
        raise ValueError("Invalid IPv4 address.")

    # Convert IPv4 address to IPv6-mapped IPv6 address
    return "::ffff:" + ipv4_address

def ipv6_to_ipv4(ipv6_address):
    try:
        # Check if the IPv6 address is valid
        ipaddress.IPv6Address(ipv6_address)
    except ipaddress.AddressValueError:
        # Throw an exception if the IPv6 address is invalid
        raise ValueError("Invalid IPv6 address.")

    # Convert IPv6-mapped IPv4 address to IPv4 address
    return ipv6_address.split(":")[2]

if __name__ == "__main__":
    # Read user operation from the command line
    operation = sys.stdin.readline().strip()

    try:
        # Check if the operation is valid
        if operation == "ipv4-to-ipv6":
            ipv4_address = sys.stdin.readline().strip()

            # Convert IPv4 address to IPv6-mapped IPv6 address
            ipv6_address = ipv4_to_ipv6(ipv4_address)

            # Print the result
            print("IPv6-mapped IPv6 Address: " + ipv6_address)
        elif operation == "ipv6-to-ipv4":
            ipv6_address = sys.stdin.readline().strip()

            # Convert IPv6-mapped IPv4 address to IPv4 address
            ipv4_address = ipv6_to_ipv4(ipv6_address)

            # Print the result
            print("Extracted IPv4 Address: " + ipv4_address)
        else:
            # Print an error message for invalid operation
            print("Invalid operation.")
    except ValueError as e:
        # Print an error message with the exception details
        print("Error: " + str(e))

# 