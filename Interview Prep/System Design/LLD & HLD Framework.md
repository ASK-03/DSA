# ✅ Low-Level Design (LLD) — 8-Step Framework

> Focuses on **class-level design**, **OOP**, **data structures**, and **design patterns**.

### 🔹 **LLD Framework (8 steps)**

1. **Understand Requirements**
    
    - Functional (features)
        
    - Non-functional (scalability, latency not as relevant in LLD, but mention them if applicable)
        
2. **Clarify the Scope**
    
    - Ask: "Should I focus only on core logic? UI? Auth? Multi-user support?"
        
    - Get to a clean **MVP**
        
3. **Identify Core Entities**
    
    - Nouns in the problem become **classes**
        
    - Draw class diagrams or quickly list: `User`, `Booking`, `Ride`, `Cache`, etc.
        
4. **Define Class Responsibilities**
    
    - Use **SRP** (Single Responsibility Principle)
        
    - Include: properties, methods, interactions
        
    - e.g., `RideManager`, `NotificationService`, etc.
        
5. **Define Relationships**
    
    - Association, Aggregation, Composition
        
    - Use proper data structures (List, Set, Map)
        
6. **Design Key Workflows**
    
    - Think in **sequence diagrams** or **interactions**
        
    - e.g., “What happens when `bookRide()` is called?”
        
7. **Use Design Patterns (if applicable)**
    
    - Singleton (for config/logging/cache)
        
    - Factory (for object creation)
        
    - Strategy (for pluggable behavior)
        
    - Observer (for notifications)
        
8. **Thread Safety and Extensibility**
    
    - Mention `synchronized`, `locks`, or `ConcurrentHashMap` where needed
        
    - Highlight how it can scale or new features added
        

> 🔸 Use **UML notation** if asked.  
> 🔸 Don't code unless asked — focus on structure, communication, and clarity.

---

## 🏗️ High-Level Design (HLD) — 10-Step Framework

> Focuses on **system architecture**, **scalability**, **availability**, **APIs**, and **components**.

### 🔹 **HLD Framework (10 steps)**

1. **Clarify Requirements**
    
    - Functional (core features)
        
    - Non-functional (QPS, latency, consistency, availability)
        
    - Ask: “What is the expected scale? Users? Traffic?”
        
2. **Define High-Level Goals**
    
    - Eg: 1M daily users, 99.9% uptime, eventual consistency is okay, etc.
        
3. **API Design**
    
    - REST/gRPC
        
    - Sample endpoints: `POST /order`, `GET /price?id=BTC-INR`
        
    - Payload, success/failure responses
        
4. **Identify Core Components**
    
    - Auth Service, API Gateway, DB, Cache, Queue, Worker, etc.
        
    - Diagram box-wise modules
        
5. **Choose the Database(s)**
    
    - RDBMS vs NoSQL (justify)
        
    - Schema design (just one or two core tables)
        
6. **Caching Strategy**
    
    - What to cache (popular prices, product info, etc)
        
    - Where (Redis, Memcached)
        
7. **Asynchronous Processing**
    
    - Message queues: Kafka, RabbitMQ, SQS
        
    - Use for background jobs, notification, order processing, etc.
        
8. **Scalability & Load Handling**
    
    - Horizontal scaling
        
    - Load balancer
        
    - CDN (if frontend)
        
    - Rate limiting
        
9. **Data Consistency & Availability**
    
    - CAP theorem tradeoffs
        
    - Use of replication/sharding
        
    - Backup/recovery
        
10. **Security & Monitoring**
    

- TLS, encryption, token-based auth
    
- Logging (ELK), Metrics (Prometheus), Alerts (Grafana)
    

---

## 🎯 Pro Tips for Both LLD and HLD Interviews

|🔑 Tip|Why It Works|
|---|---|
|**Think aloud**|Shows your problem-solving style|
|**Ask questions early**|Clarifies scope + avoids wrong assumptions|
|**Keep it layered**|Start simple → evolve to complex|
|**Use analogies**|Helps explain components (e.g., Kafka = "postal service")|
|**Own the whiteboard**|Guide the interviewer through your thinking|

---

## 💬 Example Phrases to Use

- “Let’s start with clarifying the scope first.”
- “We can separate concerns using a service class here.”
- “This component can be a good candidate for caching.”
- “If we hit scale issues, we can shard this table by user ID.”
