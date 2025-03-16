import socket

class IPAddressConverter:
    @staticmethod
    def ipv4_to_ipv6(ipv4_address):
        if not ipv4_address:
            raise socket.error("IPv4 address is empty.")

        segments = ipv4_address.split(".")
        if len(segments) != 4:
            raise socket.error("Invalid IPv4 address format.")

        for segment in segments:
            value = int(segment)
            if value < 0 or value > 255:
                raise socket.error(f"Invalid IPv4 address segment: {segment}")

        return "::ffff:" + ipv4_address

    @staticmethod
    def ipv6_to_ipv4(ipv6_address):
        if not ipv6_address:
            raise socket.error("IPv6 address is empty.")

        if not ipv6_address.startswith("::ffff:"):
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")

        parts = ipv6_address.split(":")
        if len(parts) < 3 or "." not in parts[2]:
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")

        return parts[2]

def main():
    operation = input().strip()

    try:
        if operation.lower() == "ipv4-to-ipv6":
            ipv4_address = input().strip()
            ipv6_address = IPAddressConverter.ipv4_to_ipv6(ipv4_address)
            print("IPv6-mapped IPv6 Address:", ipv6_address)
        elif operation.lower() == "ipv6-to-ipv4":
            ipv6_address = input().strip()
            ipv4_address = IPAddressConverter.ipv6_to_ipv4(ipv6_address)
            print("Extracted IPv4 Address:", ipv4_address)
        else:
            print("Invalid operation.")
    except (socket.error, ValueError) as e:
        print("Error:", e)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
