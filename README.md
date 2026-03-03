# 🚀 Thread-Safe Circular Buffer in C++

A modern **C++17** implementation of a thread-safe circular buffer using:

* `std::mutex`
* `std::condition_variable`
* RAII-based locking
* Blocking `push()` / `pop()` operations

This project demonstrates a clean, production-ready implementation suitable for:

* Producer–Consumer systems
* Embedded Linux applications
* Logging pipelines
* Streaming systems
* Multithreaded back-end services

---

## 📌 Features

* ✅ Fixed-size circular buffer
* ✅ Fully thread-safe
* ✅ Blocking `push()` when buffer is full
* ✅ Blocking `pop()` when buffer is empty
* ✅ Condition-variable–based synchronization
* ✅ Exception-safe design
* ✅ Clean and modern C++17 implementation

---

## 🧠 Design Overview

The buffer maintains the following internal state:

* `head_` → Read index
* `tail_` → Write index
* `size_` → Current number of elements
* `capacity_` → Maximum buffer size

### 🔄 Wrap-Around Logic

```cpp
index = (index + 1) % capacity_;
```

This ensures efficient circular traversal without shifting elements.

### 🔒 Thread Safety Mechanism

Thread safety is guaranteed using:

* `std::mutex` for mutual exclusion
* `std::condition_variable` for blocking synchronization

The implementation follows RAII principles using `std::unique_lock` to ensure safe lock management.

---

## 🏗 Build Instructions

### 🔧 Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

### ▶️ Run the Application

```bash
./main
```

### 🧪 Run Tests (if available)

```bash
./test
```

---

## 📂 Project Structure

```
.
├── include/
│   └── circular_buffer.hpp
├── src/
│   └── main.cpp
├── test/
│   └── test_circular_buffer.cpp
├── CMakeLists.txt
└── README.md
```

---

## 🎯 Use Cases

This implementation is well-suited for:

* Real-time logging systems
* Message queues
* Sensor data pipelines
* Network packet buffering
* Embedded Linux multi-threaded systems

---

## 📜 License

MIT License (or specify your license here).

---

## 👨‍💻 Author

Pravin Khillare
Embedded & System Software Engineer

---
