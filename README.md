# 🚀 Thread-Safe Circular Buffer in C++

A modern C++17 implementation of a thread-safe circular buffer using:

- `std::mutex`
- `std::condition_variable`
- RAII locking
- Blocking push/pop operations

This project demonstrates a production-ready implementation suitable for:

- Producer–Consumer systems
- Embedded Linux applications
- Logging pipelines
- Streaming systems
- Multithreaded applications

---

## 📌 Features

✅ Fixed-size circular buffer  
✅ Thread-safe  
✅ Blocking push when full  
✅ Blocking pop when empty  
✅ Condition-variable based synchronization  
✅ Exception-safe  
✅ Clean C++17 implementation  

---

## 🧠 Design

The buffer maintains:

- `head_` → read index  
- `tail_` → write index  
- `size_` → number of elements  

Wrap-around logic:
