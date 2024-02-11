# Electronic Orders System (C Implementation)

This C program is designed to facilitate electronic product orders with the following integrated functionalities:

## Functionality 1: User Registration (Signup)

The main function for user registration includes the following features:
- Input fields for username, age, phone number, email, password, and password confirmation.
- Data validation:
  - Username: Only letters are allowed.
  - Age: Must be greater than zero.
  - Email: Must contain "@".
  - Password and password confirmation must match.
  - Phone number: Should contain only numbers (no letters).

## Functionality 2: User Login

This function implements login features. Email and password are validated to ensure the user is registered. After successful login, users can choose to search for a store or electronic component.

## Functionality 3: Search for Store and Electronic Component

This feature allows users to place product orders after selecting a store. Once the store is chosen, the list of electronic products is displayed with their respective costs. After selecting the desired product(s), users need to proceed to the "Select Cart" option to view the total amount for the selected products.

## Getting Started

To run the program, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/electronic-orders-system.git
