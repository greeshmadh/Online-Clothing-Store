# Clothing Store Management System

This C++ program is a simple clothing store management system that allows users to either sell or buy products. It includes functionality for sellers to add products to the store, display available products, and exit. For buyers, it provides options to display available products, add items to the cart, display cart items, delete items from the cart, and complete the purchase.

## Table of Contents
- [Features](#features)
- [File Handling](#file-handling)
- [Classes](#classes)
- [Main Function](#main-function)

## Features
1. **Seller Functionality:**
   - Add new products to the store or update existing product quantities.
   - Display the list of available products.
   - Save changes and exit.

2. **Buyer Functionality:**
   - Display the available products.
   - Add products to the cart with specified quantities.
   - Display the items in the cart.
   - Delete items from the cart, either by specifying the quantity or removing all.
   - Complete the purchase, displaying the total amount and updating product quantities.
   - Save changes and exit.

## File Handling
- The program reads and writes product information to a file named `products.txt`.
- Upon exiting, the program saves any changes made by sellers or buyers.

## Classes
1. **Product Class:**
   - Represents a product with attributes such as name, price, and quantity.

2. **Cart Class:**
   - Represents an item in the buyer's cart with attributes like product name, price, and quantity.

## Main Function
- The `main()` function initializes the program by welcoming the user and prompting them to choose between seller and buyer modes.
- It reads the existing product information from the file `products.txt` and provides a loop for users to interact with the system.
- Sellers and buyers can perform their respective actions, and the program saves changes to the file upon exit.

Feel free to explore and enhance this code as needed for your specific requirements!
