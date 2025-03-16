import socket

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

# 