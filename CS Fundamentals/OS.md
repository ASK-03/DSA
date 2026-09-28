### 1. **Introduction to Operating Systems**

- **Definition**: An Operating System (OS) is system software that manages computer hardware, software resources, and provides common services for computer programs. It acts as an intermediary between users and hardware, enabling efficient resource allocation and execution of applications.
- **Key Functions**: Process management, Memory management, File system management, Device management, Security, and User interface.
- **Types of OS**:
    - Batch OS (e.g., early mainframes).
    - Time-sharing OS (e.g., UNIX).
    - Distributed OS (e.g., for networked systems).
    - Real-time OS (e.g., RTOS for embedded systems like VxWorks).
    - Examples: Windows, Linux, macOS, Android.

**Frequently Asked Interview Questions:**

- **Q: What is the difference between Kernel and User mode?**
A: Kernel mode (privileged mode) allows full access to hardware and system resources, used by the OS core. User mode restricts access to prevent crashes; applications run here and make system calls to switch to kernel mode for privileged operations.
- **Q: Explain the role of the OS in resource management.**
A: The OS allocates CPU time (scheduling), memory (allocation/deallocation), I/O devices (buffering/spooling), and ensures fair sharing while preventing conflicts like deadlocks.


### 2. **Process Management**

- **Definition**: A process is a program in execution, including code, data, and resources like registers and stack. The OS manages processes from creation to termination.
- **Process States**: New, Ready, Running, Waiting, Terminated.
- **Process Control Block (PCB)**: A data structure storing process info (PID, state, CPU registers, memory limits, etc.).
- **Context Switching**: The process of saving the state of a running process and loading another; involves overhead but enables multitasking.

Pseudocode for Process Creation:

```
fork() {  // System call to create a child process
    if (child) {
        // Child process code
    } else {
        // Parent process code
    }
}
```

**Frequently Asked Interview Questions:**

- **Q: What is the difference between a process and a program?**
A: A program is a static set of instructions on disk. A process is a dynamic instance of a program in memory, with its own address space, resources, and execution state.
- **Q: Why is context switching expensive?**
A: It requires saving/loading CPU registers, updating PCB, flushing caches (e.g., TLB), and potential page faults, leading to performance overhead (typically 1-1000 microseconds).


### 3. **Threads**

- **Definition**: A thread is the smallest unit of execution within a process, sharing the process's resources (memory, files) but having its own stack, registers, and program counter. Enables concurrency.
- **Types**: User-level threads (managed by libraries, e.g., pthreads) vs. Kernel-level threads (managed by OS, more overhead but better scheduling).
- **Multithreading Models**: Many-to-One, One-to-One, Many-to-Many.

Pseudocode Example (using pthreads in C):

```c
#include <pthread.h>

void* threadFunc(void* arg) {
    // Thread code
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, threadFunc, NULL);
    pthread_join(thread, NULL);
    return 0;
}
```

**Frequently Asked Interview Questions:**

- **Q: Process vs. Thread – key differences?**
	A: Processes are independent with separate address spaces (heavier creation/switching). Threads share address space within a process (lighter, faster communication via shared memory, but risk of data corruption if not synchronized).
- **Q: When would you prefer multithreading over multiprocessing?**
	A: For tasks needing frequent communication (e.g., web servers handling requests) or when resource sharing is beneficial, as threads are cheaper to create and switch than processes.
- **Q: When would you prefer multiprocessing over multithreading?**  
    **A:** For CPU-bound tasks (e.g., image processing, data crunching) where true parallelism is needed, as multiprocessing bypasses Python’s GIL and utilizes multiple cores effectively.


### 4. **CPU Scheduling**

- **Definition**: CPU scheduling decides which process gets the CPU when multiple are ready, aiming to maximize CPU utilization, throughput, and minimize waiting time.
- **Key Concepts**: Preemptive (can interrupt) vs. Non-preemptive scheduling; Metrics: Turnaround time, Waiting time, Response time.
- **Scheduling Algorithms**:
    - FCFS (First-Come-First-Served): Simple, but convoy effect.
    - SJF (Shortest Job First): Optimal for waiting time, but starvation possible.
    - Priority Scheduling: Based on priority, can be preemptive.
    - Round Robin (RR): Time-slicing for fairness (quantum-based).

Pseudocode for Round Robin:

```
queue readyQueue;
int quantum = 4;  // Time slice

while (!readyQueue.empty()) {
    Process p = readyQueue.dequeue();
    if (p.remainingTime > quantum) {
        execute(p, quantum);
        p.remainingTime -= quantum;
        readyQueue.enqueue(p);
    } else {
        execute(p, p.remainingTime);
        // Process terminates
    }
}
```

**Frequently Asked Interview Questions:**

- **Q: What is starvation and how does aging prevent it?**
A: Starvation occurs when a low-priority process waits indefinitely. Aging increases priority over time, ensuring eventual execution (e.g., in priority scheduling).
- **Q: Compare SJF and RR scheduling.**
A: SJF minimizes average waiting time but requires burst time knowledge and can cause starvation. RR ensures fairness with time quanta but has higher context switching overhead for short quanta.


### 5. **Synchronization and Concurrency**

- **Definition**: Synchronization ensures that concurrent processes/threads access shared resources without conflicts (e.g., race conditions).
- **Key Mechanisms**: Mutex (binary semaphore for mutual exclusion), Semaphores (counting for resource control), Monitors (high-level abstraction).
- **Critical Section Problem**: Ensure only one process accesses shared data at a time; solutions must satisfy mutual exclusion, progress, and bounded waiting.

Pseudocode for Semaphore:

```
Semaphore s = 1;  // Initialized to 1 for mutex

void process() {
    wait(s);  // P operation: decrement if >0, else wait
    // Critical section
    signal(s);  // V operation: increment
}
```

**Frequently Asked Interview Questions:**

- **Q: What is a race condition? Give an example.**
	A: When multiple threads access shared data concurrently, leading to inconsistent results (e.g., two threads incrementing a counter without locks, resulting in lost updates).
- **Q: Mutex vs. Semaphore?**
	A: Mutex is for mutual exclusion (ownership-based, only unlockable by locker). Semaphore is a signaling mechanism (can be >1, no ownership, useful for producer-consumer problems).;


### 6. **Deadlocks**

- **Definition**: A deadlock occurs when two or more processes wait indefinitely for resources held by each other, forming a cycle.
- **Necessary Conditions**: Mutual exclusion, Hold and wait, No preemption, Circular wait.
- **Prevention/Avoidance**: Banker's Algorithm (safe state checking), Resource allocation graphs.

Pseudocode Snippet for Banker's Algorithm (Safe State Check):

```
bool isSafe() {
    // Simulate resource allocation
    // Check if all processes can finish without deadlock
    return (no cycle in resource graph);
}
```

**Frequently Asked Interview Questions:**

- **Q: How to detect and recover from deadlocks?**
A: Detection: Use wait-for graphs or Banker's checks. Recovery: Process termination (rollback), Resource preemption.
- **Q: Explain the Dining Philosophers problem.**
A: Classic synchronization issue where philosophers (processes) compete for forks (resources); solutions include semaphores or avoiding circular wait (e.g., one philosopher picks forks in reverse order).

Here’s the Markdown content structured cleanly for your documentation or notes, integrating everything you provided along with compact explanations:

---

### 7. **Memory Management**

- **Definition**: The Operating System manages allocation and deallocation of primary memory to processes. It ensures efficient usage, minimizes fragmentation, and maintains memory protection and isolation.
#### **Techniques**

- **Contiguous Allocation**:
    
    - **Fixed Partitioning**: Memory is divided into fixed-size blocks at startup. Simple but causes **internal fragmentation**.
    
    - **Variable Partitioning**: Memory is allocated as per process size. More flexible but leads to **external fragmentation**.
    
- **Non-Contiguous Allocation**:
    
    - **Paging**: Divides both memory and processes into fixed-size units (pages/frames). Solves **external fragmentation** by allowing non-contiguous allocation.
    
    - **Segmentation**: Divides memory based on logical segments like code, stack, and data. Provides modularity but suffers from **external fragmentation**.
#### **Fragmentation**

- **Internal Fragmentation**: Wasted space _inside_ allocated blocks (e.g., process doesn't fully use a fixed partition).

- **External Fragmentation**: Wasted space _outside_ allocated blocks due to scattered free chunks.
#### **Example: Fixed Partitioning Table**

```
Partition 1: 100KB (Process A: 80KB, Internal Frag: 20KB)
Partition 2: 200KB (Free)
```

### **Frequently Asked Interview Questions**

- **Q: What is paging and how does it solve external fragmentation?**  
    **A:** Paging divides memory into fixed-size pages (e.g., 4KB), mapping logical to physical memory via page tables. It allows non-contiguous allocation and completely eliminates external fragmentation.

- **Q: What is Belady’s Anomaly in page replacement?**  
    **A:** In FIFO page replacement, increasing the number of page frames can _increase_ the number of page faults — known as **Belady’s Anomaly**. This does **not** occur with algorithms like LRU or Optimal.

### 8. **Virtual Memory**

- **Definition**: Virtual memory abstracts physical memory, allowing processes to use more memory than available via demand paging (loading pages on demand).
- **Page Replacement Algorithms**: FIFO, LRU (Least Recently Used), Optimal.
- **Thrashing**: Excessive paging due to low frames, leading to high CPU overhead.

Pseudocode for LRU:

```
stack lruStack;

onPageFault(page) {
    if (page in memory) {
        moveToTop(lruStack, page);  // Mark as recently used
    } else {
        evict(lruStack.bottom());  // Remove least recently used
        load(page);
        push(lruStack, page);
    }
}
```

**Frequently Asked Interview Questions:**

- **Q: What is a page fault?**
A: Occurs when a requested page is not in memory; OS loads it from disk, updating page tables.
- **Q: Demand paging vs. Prepaging?**
A: Demand paging loads pages only when needed (lazy loading, efficient). Prepaging loads anticipated pages to reduce faults but risks unnecessary I/O.


### 9. **File Systems**

- **Definition**: Manages data storage, retrieval, and organization on secondary storage (e.g., disks).
- **File Allocation Methods**: Contiguous, Linked, Indexed (e.g., inodes in UNIX).
- **Directory Structure**: Single-level, Two-level, Tree-structured.

Example: Inode Structure (Simplified)

```
Inode {
    fileType;
    size;
    pointers[12];  // Direct blocks
    indirectPointer;  // For larger files
}
```

**Frequently Asked Interview Questions:**

- **Q: What is the difference between FAT and NTFS?**
A: FAT (File Allocation Table) is simple, used in older systems/USB, but lacks security. NTFS supports large files, journaling, encryption, and permissions.
- **Q: How does a file system handle disk space allocation?**
A: Via bitmaps/free lists for tracking free blocks; allocation methods balance speed and fragmentation (e.g., contiguous for sequential access).


### 10. **I/O Management**

- **Definition**: OS handles input/output operations, buffering, spooling, and device drivers for hardware interaction.
- **I/O Scheduling**: Algorithms like FCFS, SSTF (Shortest Seek Time First) for disk I/O to minimize seek time.
- **Buffering**: Temporarily stores data to match speed differences between devices.

**Frequently Asked Interview Questions:**

- **Q: Polling vs. Interrupts in I/O?**
A: Polling checks device status repeatedly (CPU wasteful). Interrupts notify CPU when ready (efficient, asynchronous).
- **Q: What is DMA?**
A: Direct Memory Access allows devices to transfer data to/from memory without CPU involvement, freeing CPU for other tasks.
