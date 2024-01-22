Key Features:

User Authentication:

Users can log in to the system using their name and password.
New users can sign up, and their login credentials are stored securely in a text file.

Binary Search Tree for Movie Data:

The movie data, including details such as index, name, rating, and genre, is organized using a binary search tree.
The tree is constructed by reading data from a CSV file and inserting nodes accordingly.

Operations on Movie Data:

Read all movie data from the CSV file and construct the binary search tree.
Search for movies based on their index or rating.
Update movie details such as name, rating, or genre.
Delete a movie record from the database.
Print all movie records in an in-order traversal manner.

User-Friendly Interface:

The system provides a user-friendly console interface with menu-driven options.
Users can navigate through different functionalities seamlessly.

Code Structure:

The program is organized into classes, including NodeBinary for the binary search tree node, List for user authentication, and BinaryTree for movie data operations.
The gotoxy function is used to position the cursor for better interface formatting.

Usage:

Compile and run the program using a C++ compiler.
Users can log in or sign up using their credentials.
Once logged in, users can perform operations such as reading, searching, updating, and deleting movie records.

Note:
This project serves as a basic movie database management system. For a more comprehensive and production-ready system, additional features, security measures, and scalability considerations would need to be addressed. Additionally, the project assumes a single-user environment and does not incorporate advanced authentication or database management features.
