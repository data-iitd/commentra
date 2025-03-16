

import ipaddress

def ipv4_to_ipv6(ipv4_address):
    try:
        # Convert IPv4 address to IPv6-mapped IPv6 address
        ipv6_address = "::ffff:" + ipv4_address
        return ipv6_address
    except ValueError:
        # Print an error message if the IPv4 address is invalid
        print("Error: Invalid IPv4 address format.")

def ipv6_to_ipv4(ipv6_address):
    try:
        # Convert IPv6-mapped IPv4 address to IPv4 address
        if not ipv6_address.startswith("::ffff:"):
            # Throw an exception if the IPv6 address is not a valid IPv6-mapped IPv4 address
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")
        ipv4_address = ipv6_address.split(":")[2]
        return ipv4_address
    except (IndexError, ValueError):
        # Print an error message if the IPv6 address is invalid
        print("Error: Not a valid IPv6-mapped IPv4 address.")

# Read user operation from the command line
operation = input("Enter operation (ipv4-to-ipv6 or ipv6-to-ipv4): ")

# Read user input from the command line
input_address = input("Enter IPv4 or IPv6 address: ")

try:
    # Check if the operation is valid
    if operation.lower() == "ipv4-to-ipv6":
        # Convert IPv4 address to IPv6-mapped IPv6 address
        ipv6_address = ipv4_to_ipv6(input_address)
        print("IPv6-mapped IPv6 Address:", ipv6_address)
    elif operation.lower() == "ipv6-to-ipv4":
        # Convert IPv6-mapped IPv4 address to IPv4 address
        ipv4_address = ipv6_to_ipv4(input_address)
        print("Extracted IPv4 Address:", ipv4_address)
    else:
        # Print an error message for invalid operation
        print("Error: Invalid operation.")
except ValueError:
    # Print an error message with the exception details
    print("Error:", sys.exc_info()[1])

