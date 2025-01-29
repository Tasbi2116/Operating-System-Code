# 🖥️ Operating-System-Code 🖥️
Welcome to the **Operating-System-Code** repository! This project contains various **Operating System** concepts implemented in **C++** as part of the **CSE-2206** course. The course is worth **1.50 credits**, and this repository includes practical implementations of key OS algorithms and techniques like **process scheduling**, **memory management**, **deadlock handling**, and more!
## 🚀 Project Overview
This repository covers the following OS concepts:
- **Process Scheduling Algorithms**:
  - First-Come, First-Served (FCFS)
  - Non-Preemptive Shortest Job First (Non-prem-SJF)
  - Non-Preemptive Priority Scheduling
  - Round Robin Scheduling
  - Shortest Job Next (SJFN)
- **Memory Management**:
  - Paging
  - Page Replacement Algorithms
- **Deadlock**:
  - Deadlock Detection
  - Deadlock Handling
- **Segmentation**
## 📂 File Descriptions
Here’s a list of the C++ files and their functionality:
### 1. **Deadlock.cpp**  
   🛑 A basic implementation of **deadlock detection**, checking for deadlocks in a system by analyzing resource allocation.
### 2. **Deadlock_Detection.cpp**  
   🚨 A more detailed **deadlock detection** algorithm that uses matrix-based approaches to identify deadlocks in the system.
### 3. **FCFS.cpp**  
   ⏳ Implements **First-Come, First-Served (FCFS)** scheduling, where processes are executed in the order they arrive.
### 4. **Non-prem-SJF.cpp**  
   ⏱️ Implements **Non-Preemptive Shortest Job First (SJF)** scheduling, where the process with the shortest burst time is executed next.
### 5. **Non-premPriority.cpp**  
   ⚖️ Implements **Non-Preemptive Priority Scheduling**, where processes with higher priority are executed first.
### 6. **Page_Replacement.cpp**  
   🗃️ Implements **page replacement algorithms** like FIFO and LRU, to manage pages in memory.
### 7. **Paging.cpp**  
   💾 Implements **paging** for memory management, splitting memory into fixed-size pages for better management and allocation.
### 8. **RoundRobin.cpp**  
   🔄 Implements the **Round Robin (RR)** scheduling algorithm, where processes are executed in a cyclic manner with a fixed time quantum.
### 9. **Segmentation.cpp**  
   🧩 Implements **segmentation**, dividing memory into variable-sized segments, providing better memory allocation for programs.
### 10. **SJFN.cpp**  
   📉 Implements **Shortest Job Next (SJFN)** scheduling, where the process with the shortest burst time gets executed first.
## 🛠️ How to Use
To get started with any of the algorithms, follow these simple steps:
1. **Clone the repository** to your local machine:
   ```bash
   git clone https://github.com/Tasbi2116/Operating-System-Code.git
2. Navigate to the directory for the desired algorithm and **compile** the corresponding `.cpp` file. For example, to run **FCFS.cpp**, use the following commands:
   ```bash
   cd FCFS
   g++ FCFS.cpp -o FCFS
   ./FCFS
   ```
3. **Repeat** the above steps for other algorithms (just replace the filenames accordingly).
## 🔧 Prerequisites
- **C++ Compiler** (preferably **g++**)
- Basic knowledge of **Operating System** concepts and algorithms
## 📝 Output
Each file will display output based on the respective algorithm. For example:
- **FCFS.cpp** will output the order in which processes are executed.
- **Deadlock.cpp** and **Deadlock_Detection.cpp** will output whether a deadlock is detected or not.
## 📄 Example Output
#### 🔹 FCFS Scheduling Output:
```
Process Order: P1 → P2 → P3 → P4
Waiting Time: P1 = 0, P2 = 4, P3 = 6, P4 = 10
```
#### 🔹 Deadlock Detection Output:
```
Deadlock Detected: Yes
```
## 🏆 Acknowledgments
This project is part of the **CSE-2206: Operating Systems Lab** course, designed to provide hands-on experience with key OS concepts like scheduling, memory management, and deadlock handling.
## 📧 Contact
Have any questions? Reach out via:
- **GitHub Issues**: [Submit an issue](../../issues)
- **Email**: [tasbi2116@cseku.ac.bd](tasbi2116@cseku.ac.bd)
## 📝 License
This repository is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more information.
```
This `README.md` now includes fun emojis and colorfully highlights the functionality and usage of the project. Feel free to adjust any part based on your needs!
