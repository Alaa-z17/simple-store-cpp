# 🛒 Simple Store — C++

A console-based Simple Store app built in **C++** demonstrating
core concepts of **Functional & Procedural Programming**.

---

## 🎬 Video Walkthrough

[![Simple Store in C++](https://img.youtube.com/vi/SHM9Vwhrvv8/0.jpg)](https://youtu.be/SHM9Vwhrvv8)

> Click the image above to watch the full project walkthrough on YouTube.

## 🎯 Learning Objectives

- Structuring a program using functions (Procedural Programming)
- Separating logic, data, and display layers
- Using `enum` and `struct` as data models
- Passing data between functions cleanly
- Using `setw` for console UI alignment

---

## 🕹️ How to Use

1. Run the program
2. Browse the product list
3. Enter Product ID to add to cart
4. Enter quantity
5. Keep adding or checkout
6. Get your invoice with discount applied!

> 💰 Discounts applied automatically:
>
> - $100+ → 5% off
> - $200+ → 10% off
> - $500+ → 15% off
> - $1000+ → 20% off

---

## 🏗️ Project Architecture

```
main()
 └── StartStore()
      └── RunStore()
           ├── LoadProductList()
           │    └── CreateProduct()
           ├── PrintProductList()
           ├── AddItemToCart()
           │    ├── ReadProductID()
           │    ├── FindProductByID()
           │    └── ReadProductQuantity()
           ├── PrintCart()
           ├── ApplyDiscount()
           │    └── GetDiscount()
           └── PrintInvoice()
                └── GetDiscountText()
```

---

## 💡 Key Concepts

| Concept                  | Where in Code                          |
| ------------------------ | -------------------------------------- |
| Enums as named constants | `enCategory`                           |
| Structs as data models   | `stProduct`, `stCartItem`, `stInvoice` |
| Pure logic functions     | `GetDiscount()`, `FindProductByID()`   |
| Display functions        | `PrintProductList()`, `PrintInvoice()` |
| UI alignment             | `setw` from `<iomanip>`                |
| Store loop               | `StartStore()`, `RunStore()`           |

---

## 🔧 Build & Run

**Open in Visual Studio**

```
double click: simple-store-cpp.slnx
Ctrl + F5
```

**Windows (MinGW / g++)**

```bash
g++ simple-store-cpp.cpp -o store.exe
./store.exe
```

---

## 📁 File Structure

```
simple-store-cpp/
├── .gitignore
├── README.md
├── LICENSE
├── simple-store-cpp.slnx
└── simple-store-cpp/
    ├── simple-store-cpp.cpp
    ├── simple-store-cpp.vcxproj
    └── simple-store-cpp.vcxproj.filters
```

---

## 👤 Author

Built as a learning exercise in C++ Procedural Programming.

---

## 📄 License

MIT License
