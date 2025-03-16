
import socket
import sys

def ipv4_to_ipv6(ipv4_address):
    if not ipv4_address:
        raise socket.gaierror("IPv4 address is empty.")
    segments = ipv4_address.split(".")
    if len(segments) != 4:
        raise socket.gaierror("Invalid IPv4 address format.")
    for segment in segments:
        value = int(segment)
        if value < 0 or value > 255:
            raise socket.gaierror("Invalid IPv4 address segment: " + segment)
    return "::ffff:" + ipv4_address

def ipv6_to_ipv4(ipv6_address):
    if not ipv6_address:
        raise socket.gaierror("IPv6 address is empty.")
    if not ipv6_address.startswith("::ffff:"):
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")
    parts = ipv6_address.split(":")
    if len(parts) < 3 or not parts[2].count("."):
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")
    return parts[2]

if __name__ == "__main__":
    operation = sys.stdin.readline().strip()
    try:
        if operation.lower() == "ipv4-to-ipv6":
            ipv4_address = sys.stdin.readline().strip()
            ipv6_address = ipv4_to_ipv6(ipv4_address)
            print("IPv6-mapped IPv6 Address: " + ipv6_address)
        elif operation.lower() == "ipv6-to-ipv4":
            ipv6_address = sys.stdin.readline().strip()
            ipv4_address = ipv6_to_ipv4(ipv6_address)
            print("Extracted IPv4 Address: " + ipv4_address)
        else:
            print("Invalid operation.")
    except (socket.gaierror, ValueError) as e:
        print("Error: " + str(e))
    finally:
        sys.stdin.close()

