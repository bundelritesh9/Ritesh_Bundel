# Hotel Management System (C++)

A console-based hotel management system written in C++.  
This project demonstrates **Object-Oriented Programming (OOP)**, **file handling**, and a **menu-driven console application**.

---

## Features

- Show available rooms in a **tabular format**
- Book a room with **guest information and age validation (18+)**
- Cancel a booking
- Checkout and generate **total bill**
- Display **guest information**
- Display **hotel information**

---

## Technologies Used

- C++
- Object-Oriented Programming (Classes: Hotel, Room, Customer)
- File Handling (`bookings.txt`)
- Console-based User Interface

---

## How to Run

### Using g++ compiler:

1. Compile all `.cpp` files:

```bash
g++ main.cpp Hotel.cpp Room.cpp Customer.cpp -o hotel
