### 1. **Introduction to DBMS**

- **Definition**: A Database Management System (DBMS) is software that enables users to define, create, maintain, and control access to databases. It acts as an interface between the database and end-users or application programs, ensuring data consistency, integrity, and security.
- **Key Features**: Data abstraction, data independence, concurrency control, recovery from failures, and support for multiple users.
- **Types of DBMS**: Hierarchical, Network, Relational (RDBMS like MySQL, Oracle), Object-oriented, NoSQL (e.g., MongoDB for non-relational data).

**Frequently Asked Interview Questions:**

- **Q: What is the difference between DBMS and RDBMS?**
A: DBMS stores data in files without strict relationships, while RDBMS (Relational DBMS) stores data in tables with relationships enforced via keys. RDBMS supports ACID properties and normalization, e.g., MySQL is RDBMS, while a simple file system is DBMS.
- **Q: Why use DBMS over flat files?**
A: DBMS provides data integrity, security, concurrent access, crash recovery, and query optimization, unlike flat files which lack these and lead to redundancy and inconsistency.


### 2. **Data Models**

- **Definition**: A data model is a conceptual representation of data, its relationships, and constraints in a database.
- **Types**:
    - **Entity-Relationship (ER) Model**: Uses entities, attributes, and relationships (e.g., one-to-many).
Example ER Diagram (textual representation):
Entity: Student (Attributes: ID, Name)
Relationship: Enrolls in Course (one-to-many).
    - **Relational Model**: Data stored in tables (relations) with rows (tuples) and columns (attributes). Based on set theory.
    - **Hierarchical Model**: Tree-like structure (e.g., IMS by IBM).
    - **Network Model**: Graph-like with multiple parent-child relationships.

**Frequently Asked Interview Questions:**

- **Q: Explain the ER Model with an example.**
A: ER Model represents real-world entities and their relationships. Example: "Student" entity with attributes (ID, Name) related to "Course" entity via "Enrolls" (a many-to-many relationship). It's used in database design to create schemas.
- **Q: What are the advantages of the Relational Model?**
A: It supports data integrity through keys, allows complex queries via SQL, reduces redundancy via normalization, and ensures scalability.


### 3. **SQL Basics**

- **Definition**: Structured Query Language (SQL) is a standard language for managing and manipulating relational databases. It's divided into DDL (Data Definition Language), DML (Data Manipulation Language), DCL (Data Control Language), and TCL (Transaction Control Language).
- **Key Commands**:
    - DDL: CREATE, ALTER, DROP (e.g., `CREATE TABLE Students (ID INT PRIMARY KEY, Name VARCHAR(50));`).
    - DML: SELECT, INSERT, UPDATE, DELETE (e.g., `INSERT INTO Students (ID, Name) VALUES (1, 'Alice');`).
    - DCL: GRANT, REVOKE (for permissions).
    - TCL: COMMIT, ROLLBACK (for transactions).

**Example SQL Query**:

```sql
-- Select all students
SELECT * FROM Students WHERE Age > 20;
```

**Frequently Asked Interview Questions:**

- **Q: What is the difference between SQL and NoSQL?**
A: SQL databases are relational, schema-based, and use structured queries (e.g., MySQL). NoSQL are non-relational, schema-flexible, and handle unstructured data (e.g., MongoDB for big data).
- **Q: Explain DDL vs DML with examples.**
A: DDL defines database structure (e.g., CREATE TABLE). DML manipulates data (e.g., INSERT INTO TABLE). DDL is used for schema changes, DML for data operations.


### 4. **Keys in DBMS**

- **Definition**: Keys are attributes or sets of attributes used to uniquely identify records in a table and establish relationships.
- **Types**:
    - **Primary Key**: Unique and non-null (e.g., Student ID).
    - **Foreign Key**: References primary key in another table for relationships.
    - **Candidate Key**: Potential primary keys.
    - **Super Key**: Superset of candidate keys.
    - **Composite Key**: Combination of multiple attributes.

**Example**:

```sql
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);
```

**Frequently Asked Interview Questions:**

- **Q: What is a Foreign Key and why is it used?**
A: A Foreign Key is a field in one table that links to the Primary Key in another, ensuring referential integrity. It prevents invalid data (e.g., no orphan records) and enforces relationships.
- **Q: Can a table have multiple Primary Keys?**
A: No, a table can have only one Primary Key, but it can be composite (multiple columns). Multiple Candidate Keys can exist, from which one is chosen as Primary.


### 5. **Normalization**

- **Definition**: Normalization is the process of organizing data in a database to reduce redundancy and improve data integrity by dividing tables into smaller, related ones.
- **Normal Forms**:
    - **1NF**: Atomic values, no repeating groups.
    - **2NF**: 1NF + No partial dependencies (non-prime attributes depend on entire primary key).
    - **3NF**: 2NF + No transitive dependencies.
    - **BCNF**: Stricter 3NF, every determinant is a candidate key.

**Example**: Unnormalized: Table with Student and Courses in one row. Normalized (3NF): Separate Students and Courses tables with foreign keys.

**Frequently Asked Interview Questions:**

- **Q: Why is Normalization important?**
A: It minimizes data redundancy, prevents anomalies (insert, update, delete), and ensures data consistency. However, over-normalization can lead to performance issues due to more joins.
- **Q: Explain 3NF with an example.**
A: In 3NF, no non-prime attribute depends on another non-prime. Example: In a table with EmployeeID, Department, Location—if Location depends on Department, split into Employee and Department tables.


### 6. **ACID Properties**

- **Definition**: ACID (Atomicity, Consistency, Isolation, Durability) ensures reliable transaction processing in databases.
- **Details**:
    - **Atomicity**: All or nothing (e.g., via COMMIT/ROLLBACK).
    - **Consistency**: Database remains valid after transaction.
    - **Isolation**: Transactions don't interfere.
    - **Durability**: Committed changes persist even after failures.

**Example**:

```sql
BEGIN TRANSACTION;
UPDATE Account SET Balance = Balance - 100 WHERE ID = 1;
UPDATE Account SET Balance = Balance + 100 WHERE ID = 2;
COMMIT;
```

**Frequently Asked Interview Questions:**

- **Q: What are ACID properties? Give an example.**
A: ACID ensures transaction reliability. Example: In a bank transfer, Atomicity ensures both debit and credit happen or neither does.
- **Q: How does Isolation prevent issues in concurrent transactions?**
A: It uses levels like Serializable or Read Committed to avoid dirty reads, non-repeatable reads, or phantom reads.


### 7. **Transactions and Concurrency**

- **Definition**: A transaction is a unit of work treated as a single operation. Concurrency control manages multiple transactions executing simultaneously without conflicts.
- **Key Concepts**: Locking (shared/exclusive), Deadlocks, Two-Phase Commit for distributed systems.

**Example**:

```sql
START TRANSACTION;
-- Operations
COMMIT;  -- Or ROLLBACK on error
```

**Frequently Asked Interview Questions:**

- **Q: What is a Deadlock and how to avoid it?**
A: Deadlock occurs when two transactions wait for each other's resources. Avoid via deadlock detection, prevention (e.g., lock ordering), or timeouts.
- **Q: Explain Optimistic vs Pessimistic Concurrency Control.**
A: Optimistic assumes no conflicts and checks at commit. Pessimistic locks resources early to prevent conflicts.


### 8. **Joins in SQL**

- **Definition**: Joins combine rows from two or more tables based on related columns.
- **Types**:
    - **INNER JOIN**: Matching records.
    - **LEFT JOIN**: All from left table + matches from right.
    - **RIGHT JOIN**: All from right + matches from left.
    - **FULL OUTER JOIN**: All records from both.

**Example**:

```sql
SELECT Students.Name, Courses.Title
FROM Students
INNER JOIN Courses ON Students.CourseID = Courses.ID;
```

**Frequently Asked Interview Questions:**

- **Q: Difference between INNER JOIN and OUTER JOIN?**
A: INNER JOIN returns only matching rows. OUTER JOIN (LEFT/RIGHT/FULL) includes non-matching rows with NULLs.
- **Q: When would you use a SELF JOIN?**
A: To compare rows within the same table, e.g., finding employees reporting to the same manager.


### 9. **Indexes**

- **Definition**: An index is a data structure that improves query retrieval speed by allowing faster lookups, similar to a book's index.
- **Types**: Clustered (reorders physical data), Non-clustered (separate structure), Unique, Composite.

**Example**:

```sql
CREATE INDEX idx_name ON Students(Name);
```

**Frequently Asked Interview Questions:**

- **Q: Why use Indexes? What are the downsides?**
A: Indexes speed up SELECT queries but slow down INSERT/UPDATE due to maintenance overhead. They also consume storage.
- **Q: Difference between Clustered and Non-Clustered Index?**
A: Clustered alters table's physical order (one per table). Non-Clustered is a separate structure pointing to data (multiple allowed).


### 10. **Views, Triggers, and Stored Procedures**

- **View**: Virtual table based on a query (e.g., `CREATE VIEW ActiveStudents AS SELECT * FROM Students WHERE Active=1;`).
- **Trigger**: Automatically executes on events like INSERT (e.g., audit logs).
- **Stored Procedure**: Precompiled SQL code for reuse (e.g., `CREATE PROCEDURE GetStudents() BEGIN SELECT * FROM Students; END;`).

**Frequently Asked Interview Questions:**

- **Q: What is a View and its benefits?**
A: A View is a virtual table for simplified queries and security (hides base tables). It doesn't store data but improves abstraction.
- **Q: When to use Triggers?**
A: For automatic actions like validation or logging, e.g., updating a counter on INSERT.


### 11. **NoSQL Databases**

- **Definition**: NoSQL databases handle unstructured data, scalability, and flexibility, unlike rigid SQL schemas.
- **Types**: Document (MongoDB), Key-Value (Redis), Column (Cassandra), Graph (Neo4j).

**Frequently Asked Interview Questions:**

- **Q: When to choose NoSQL over SQL?**
A: For big data, high scalability, or unstructured data (e.g., social media). SQL for transactions Ascending for complex queries.
- **Q: Difference between CAP Theorem's Consistency and Availability?**
A: CAP states a distributed system can't guarantee all three: Consistency (all nodes see same data), Availability (every request gets a response), Partition Tolerance (handles network failures). Systems prioritize two, e.g., eventual consistency in NoSQL for availability.

---

## 12. Transaction Isolation Levels
- **[Read Uncommitted](https://www.google.com/search?cs=1&sca_esv=a55f96b2117342bb&sxsrf=AE3TifM6yPe5lpv9Lok3dG5UcmOnpNi9CQ%3A1754159096501&q=Read+Uncommitted&sa=X&ved=2ahUKEwifk6Lu3-yOAxW6RmwGHYwyEAoQxccNegQIEBAB&mstk=AUtExfDZrUbKzhJH2F9aNjrjvMJasiD8vmRgqGh90HezTtkaGxteIWr7BznneCHAnEjkZtUsCir5cloZEOT8CdjIjeuypqjM2WTfW9aSBBkAOJz7-qtIDoStihdIy4_BKi00x33MqrWnuz2An8D_3LXq-LOS_uNB0GnuSwyWBwOnqu-Npq-G_bIFdwHWv-xjDmDgU8fuvjKyWxLMDjUEmmHjajJPSeD4Dln67uxCe7alzoFCsdYnLrf59ipYf86fP-xjhq6z9VzLcPBej2GIo3Ut9w0Y&csui=3):**
    The least restrictive level, allowing transactions to read uncommitted changes (dirty reads) made by other transactions. This can lead to inconsistent data being accessed, but it offers the best performance.
    
- **[Read Committed](https://www.google.com/search?cs=1&sca_esv=a55f96b2117342bb&sxsrf=AE3TifM6yPe5lpv9Lok3dG5UcmOnpNi9CQ%3A1754159096501&q=Read+Committed&sa=X&ved=2ahUKEwifk6Lu3-yOAxW6RmwGHYwyEAoQxccNegQIFRAB&mstk=AUtExfDZrUbKzhJH2F9aNjrjvMJasiD8vmRgqGh90HezTtkaGxteIWr7BznneCHAnEjkZtUsCir5cloZEOT8CdjIjeuypqjM2WTfW9aSBBkAOJz7-qtIDoStihdIy4_BKi00x33MqrWnuz2An8D_3LXq-LOS_uNB0GnuSwyWBwOnqu-Npq-G_bIFdwHWv-xjDmDgU8fuvjKyWxLMDjUEmmHjajJPSeD4Dln67uxCe7alzoFCsdYnLrf59ipYf86fP-xjhq6z9VzLcPBej2GIo3Ut9w0Y&csui=3):**
    Prevents dirty reads, meaning a transaction can only read data that has been  committed. This eliminates the problem of reading temporary or inconsistent data.
    
- **[Repeatable Read](https://www.google.com/search?cs=1&sca_esv=a55f96b2117342bb&sxsrf=AE3TifM6yPe5lpv9Lok3dG5UcmOnpNi9CQ%3A1754159096501&q=Repeatable+Read&sa=X&ved=2ahUKEwifk6Lu3-yOAxW6RmwGHYwyEAoQxccNegQIERAB&mstk=AUtExfDZrUbKzhJH2F9aNjrjvMJasiD8vmRgqGh90HezTtkaGxteIWr7BznneCHAnEjkZtUsCir5cloZEOT8CdjIjeuypqjM2WTfW9aSBBkAOJz7-qtIDoStihdIy4_BKi00x33MqrWnuz2An8D_3LXq-LOS_uNB0GnuSwyWBwOnqu-Npq-G_bIFdwHWv-xjDmDgU8fuvjKyWxLMDjUEmmHjajJPSeD4Dln67uxCe7alzoFCsdYnLrf59ipYf86fP-xjhq6z9VzLcPBej2GIo3Ut9w0Y&csui=3):**
    Guarantees that if a transaction reads a row multiple times, it will get the same value each time, even if another transaction modifies the row in between. This prevents [non-repeatable reads](https://www.google.com/search?cs=1&sca_esv=a55f96b2117342bb&sxsrf=AE3TifM6yPe5lpv9Lok3dG5UcmOnpNi9CQ%3A1754159096501&q=non-repeatable+reads&sa=X&ved=2ahUKEwifk6Lu3-yOAxW6RmwGHYwyEAoQxccNegQIExAB&mstk=AUtExfDZrUbKzhJH2F9aNjrjvMJasiD8vmRgqGh90HezTtkaGxteIWr7BznneCHAnEjkZtUsCir5cloZEOT8CdjIjeuypqjM2WTfW9aSBBkAOJz7-qtIDoStihdIy4_BKi00x33MqrWnuz2An8D_3LXq-LOS_uNB0GnuSwyWBwOnqu-Npq-G_bIFdwHWv-xjDmDgU8fuvjKyWxLMDjUEmmHjajJPSeD4Dln67uxCe7alzoFCsdYnLrf59ipYf86fP-xjhq6z9VzLcPBej2GIo3Ut9w0Y&csui=3).
    
- **[Serializable](https://www.google.com/search?cs=1&sca_esv=a55f96b2117342bb&sxsrf=AE3TifM6yPe5lpv9Lok3dG5UcmOnpNi9CQ%3A1754159096501&q=Serializable&sa=X&ved=2ahUKEwifk6Lu3-yOAxW6RmwGHYwyEAoQxccNegQIEhAB&mstk=AUtExfDZrUbKzhJH2F9aNjrjvMJasiD8vmRgqGh90HezTtkaGxteIWr7BznneCHAnEjkZtUsCir5cloZEOT8CdjIjeuypqjM2WTfW9aSBBkAOJz7-qtIDoStihdIy4_BKi00x33MqrWnuz2An8D_3LXq-LOS_uNB0GnuSwyWBwOnqu-Npq-G_bIFdwHWv-xjDmDgU8fuvjKyWxLMDjUEmmHjajJPSeD4Dln67uxCe7alzoFCsdYnLrf59ipYf86fP-xjhq6z9VzLcPBej2GIo3Ut9w0Y&csui=3):**
    The most restrictive level, ensuring that concurrent transactions are effectively executed serially, one after the other. This eliminates all concurrency anomalies, including [phantom reads](https://www.google.com/search?cs=1&sca_esv=a55f96b2117342bb&sxsrf=AE3TifM6yPe5lpv9Lok3dG5UcmOnpNi9CQ%3A1754159096501&q=phantom+reads&sa=X&ved=2ahUKEwifk6Lu3-yOAxW6RmwGHYwyEAoQxccNegQIGRAB&mstk=AUtExfDZrUbKzhJH2F9aNjrjvMJasiD8vmRgqGh90HezTtkaGxteIWr7BznneCHAnEjkZtUsCir5cloZEOT8CdjIjeuypqjM2WTfW9aSBBkAOJz7-qtIDoStihdIy4_BKi00x33MqrWnuz2An8D_3LXq-LOS_uNB0GnuSwyWBwOnqu-Npq-G_bIFdwHWv-xjDmDgU8fuvjKyWxLMDjUEmmHjajJPSeD4Dln67uxCe7alzoFCsdYnLrf59ipYf86fP-xjhq6z9VzLcPBej2GIo3Ut9w0Y&csui=3), but can have the biggest performance impact.