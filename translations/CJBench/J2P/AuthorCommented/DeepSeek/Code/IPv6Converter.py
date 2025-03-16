import socket

def ipv4_to_ipv6(ipv4_address):
    try:
        # Check if the IPv4 address is valid
        parts = ipv4_address.split('.')
        if len(parts) != 4:
            raise ValueError("Invalid IPv4 address format.")
        for part in parts:
            if not (0 <= int(part) <= 255):
                raise ValueError("Invalid IPv4 address segment.")
        
        # Construct the IPv6-mapped IPv6 address
        return "::ffff:" + ipv4_address
    except Exception as e:
        raise ValueError(str(e))

def ipv6_to_ipv4(ipv6_address):
    try:
        # Check if the IPv6 address is valid and a mapped IPv4 address
        if not ipv6_address.startswith("::ffff:"):
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")
        
        # Extract the IPv4 address from the mapped IPv6 address
        parts = ipv6_address.split(':')
        if len(parts) < 3 or '.' not in parts[2]:
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")
        
        return parts[2]
    except Exception as e:
        raise ValueError(str(e))

def main():
    operation = input().strip()
    
    try:
        if operation.lower() == "ipv4-to-ipv6":
            ipv4_address = input().strip()
            ipv6_address = ipv4_to_ipv6(ipv4_address)
            print("IPv6-mapped IPv6 Address:", ipv6_address)
        elif operation.lower() == "ipv6-to-ipv4":
            ipv6_address = input().strip()
            ipv4_address = ipv6_to_ipv4(ipv6_address)
            print("Extracted IPv4 Address:", ipv4_address)
        else:
            print("Invalid operation.")
    except ValueError as e:
        print("Error:", str(e))

if __name__ == "__main__":
    main()

