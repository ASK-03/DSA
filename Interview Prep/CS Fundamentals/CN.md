## ✅ 1. Introduction to Computer Networks

### 💡 Definition:

A computer network is a group of interconnected computing devices that exchange data and share resources using a communication protocol (e.g., TCP/IP) over physical (wired) or wireless mediums.

### 🔑 Key Features:

- **Scalability**: Easy to add/remove nodes.
- **Reliability**: Redundant paths, error correction.
- **Security**: Encrypted communication, access control.
- **Resource Sharing**: Shared storage, printers, cloud apps.

### 🧭 Types of Networks:

|Type|Scope|Example|
|---|---|---|
|PAN|~1 meter|Bluetooth keyboard|
|LAN|Room/building|Office Ethernet|
|MAN|City|College campus, Cable TV|
|WAN|Country/worldwide|Internet, MPLS|

---

### 🔍 Frequently Asked Interview Questions (FAANG-level):

- **Q1:** What are the pros and cons of using wireless vs wired networks?  
    **A:** Wireless is flexible but prone to interference; wired is more reliable and faster. For high-performance, use wired for backbone and wireless for edge devices.

- **Q2:** How does resource sharing reduce costs in networks?  
    **A:** Centralized resources (e.g., file servers) eliminate the need for duplication, reducing hardware, licensing, and maintenance costs.


---

## ✅ 2. OSI Model (7-Layer Reference Model)

### 💡 Purpose:

It standardizes how systems communicate in layers, making design, implementation, and troubleshooting modular.

### 📚 Layer Breakdown (Bottom-Up):

|Layer|Function|Protocols/Examples|
|---|---|---|
|1. Physical|Bit transmission|Ethernet, Cables|
|2. Data Link|MAC addressing, error correction|MAC, ARP, Switch|
|3. Network|Routing, addressing|IP, ICMP, Router|
|4. Transport|Reliability, flow control|TCP, UDP|
|5. Session|Session management|NetBIOS|
|6. Presentation|Data formatting/encryption|JPEG, SSL|
|7. Application|User-level protocols|HTTP, DNS, FTP|

### 🔗 Data Flow:

- Sender: Encapsulation at each layer.
- Receiver: Decapsulation in reverse.

---

### 🔍 Interview Questions:

- **Q:** Which layer handles fragmentation and reassembly?  
    **A:** Network Layer (IP handles fragmentation in IPv4).

- **Q:** Is the OSI model used in real life?  
    **A:** It's a theoretical model; real-world stacks like TCP/IP simplify it but still follow the layered principles.

- **Q:** What is MTU and where is it defined?  
    **A:** Maximum Transmission Unit; defined at Layer 2.

---

## ✅ 3. TCP/IP Model

### 💡 Definition:

A 4-layer practical model used in real-world networking (internet). Focused on protocol implementation.

### 🔁 Layers and Mapping:

|TCP/IP Layer|OSI Layers|Protocols|
|---|---|---|
|Application|5–7|HTTP, FTP, SMTP|
|Transport|4|TCP, UDP|
|Internet|3|IP, ICMP|
|Link|1–2|Ethernet, Wi-Fi|

---

### 🔍 Interview Questions:

- **Q:** What is the role of ICMP?  
    **A:** Error reporting and diagnostics (e.g., ping uses ICMP Echo).
    
- **Q:** Difference between TCP/IP and OSI?  
    **A:** TCP/IP is leaner, protocol-specific, and practical; OSI is academic.
    

---

## ✅ 4. IP Addressing and Subnetting

### 💡 Concepts:

- **IPv4:** 32-bit (e.g., 192.168.0.1).
- **IPv6:** 128-bit (e.g., 2001:db8::1).
- **Subnetting:** Divides networks for efficiency/security.
- **CIDR:** Classless Inter-Domain Routing (`/24`, `/20`, etc.).

---

### 🧠 Common Subnet Example:

```
CIDR: 192.168.1.0/24
Subnet Mask: 255.255.255.0
Host Range: 192.168.1.1 – 192.168.1.254
```

---

### 🔍 Interview Questions:

- **Q:** How do you calculate number of hosts in a subnet?  
    **A:** 2^(32 - subnet bits) - 2. For /26 → 2^6 - 2 = 62 usable IPs.
    
- **Q:** Why is subnetting useful?  
    **A:** Minimizes broadcast domains, enhances security and performance.
    
- **Q:** What is NAT?  
    **A:** Network Address Translation maps private IPs to a public IP, conserving IPv4 addresses.
    

---

## ✅ 5. TCP vs UDP

### 💡 Comparison Table:

|Feature|TCP|UDP|
|---|---|---|
|Connection|Yes (3-way handshake)|No|
|Reliability|Guaranteed|Best effort|
|Speed|Slower|Faster|
|Use Cases|HTTP, FTP, Email|VoIP, DNS, Streaming|

---

### 🔁 TCP Handshake:

```
Client -> SYN
Server -> SYN+ACK
Client -> ACK
Connection Established
```

---

### 🔍 Interview Questions:

- **Q:** What is the TCP sliding window?  
    **A:** Flow control mechanism to manage in-flight data.

- **Q:** Can TCP lose packets?  
    **A:** Yes, but it detects and retransmits them.

- **Q:** Is UDP really faster than TCP?  
    **A:** Yes, due to no overhead of reliability or connection management.


---

## ✅ 6. Network Devices

|Device|OSI Layer|Function|
|---|---|---|
|Hub|Layer 1|Broadcasts to all|
|Switch|Layer 2|MAC-based forwarding|
|Router|Layer 3|IP-based routing|
|Modem|Layer 1|Modulation/demodulation|
|Firewall|L3/L4|Packet filtering/security|

---

### 🔍 Interview Questions:

- **Q:** What happens when a switch receives a frame with an unknown MAC?  
    **A:** It floods the frame to all ports (except the source).

- **Q:** How does a router decide where to send a packet?  
    **A:** Looks up routing table using destination IP.

---

## ✅ 7. DNS

### 💡 Flow:

1. Browser -> Resolver
2. Resolver -> Root server
3. -> TLD (.com)
4. -> Authoritative DNS
5. <- IP Address returned

---

### 🔍 Interview Questions:

- **Q:** What is TTL in DNS?  
    **A:** Time-to-live for caching DNS results.
    
- **Q:** Difference between CNAME and A record?  
    **A:** A maps to IP; CNAME is an alias to another domain.
    

---

## ✅ 8. HTTP vs HTTPS

|Feature|HTTP|HTTPS|
|---|---|---|
|Port|80|443|
|Encryption|No|TLS|
|Secure?|No|Yes|
|Use|Static websites|Banking, login, APIs|

---

### 🔍 Interview Questions:

- **Q:** How does TLS work?  
    **A:** Client and server exchange keys, validate certs, and establish encrypted tunnel.
    
- **Q:** Can HTTP be secure?  
    **A:** No. Always use HTTPS with HSTS and secure headers.
    

---

## ✅ 9. Socket Programming

### 💡 Core APIs:

- `socket()`
- `bind()`
- `listen()`
- `accept()`
- `connect()`
- `send()/recv()`

---

### 🔍 Interview Questions:

- **Q:** What is a port?  
    **A:** Logical endpoint for communication, combined with IP to form socket.
    
- **Q:** What is the difference between bind() and connect()?  
    **A:** `bind()` associates a socket with a local port (used by servers). `connect()` initiates a connection (clients).
    

---

## ✅ 10. Congestion and Flow Control

|Feature|Congestion Control|Flow Control|
|---|---|---|
|Goal|Avoid network overload|Avoid overwhelming receiver|
|Level|Network-wide|End-to-end|
|Example|TCP Tahoe, Reno|TCP Sliding Window|

---

### 🔍 Interview Questions:

- **Q:** How does TCP detect congestion?  
    **A:** Packet loss (timeout or duplicate ACKs).
    
- **Q:** What is exponential backoff?  
    **A:** Increases wait time exponentially on retransmission to reduce congestion.
    

---

## ✅ 11. Network Security Basics

### 💡 Components:

- **Authentication**: Verifying identity (OAuth, JWT)
- **Encryption**: Securing data (TLS, AES)
- **Firewalls**: Packet filtering
- **IDS/IPS**: Detect/prevent intrusions
- **VPNs**: Encrypted tunnels

---

### 🔍 Interview Questions:

- **Q:** What is a man-in-the-middle (MITM) attack?  
    **A:** Attacker intercepts traffic between two parties. Prevention: TLS, cert pinning.

- **Q:** What’s the difference between symmetric and asymmetric encryption?  
    **A:** Symmetric: one key (faster). Asymmetric: public/private key pair (used in TLS handshake).