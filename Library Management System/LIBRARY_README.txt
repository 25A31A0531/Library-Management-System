Library Management System - C++ Application

Overview
A complete library management application built with C++ that efficiently manages books, members, and borrowing records using object-oriented programming and file handling for persistent data storage.


Key Features

1. Book Management
   - Add new books to library inventory
   - Display all books with availability status
   - Search books by title
   - Search books by author
   - Track book quantity and availability
   - Store book details (Title, Author, ISBN, Price)

2. Member Management
   - Register new library members
   - Display all registered members
   - Track member details (Name, Email, Phone, Address)
   - Limit members to 3 books maximum per member
   - Track membership dates

3. Issue and Return Operations
   - Issue books to members with validation
   - Return books to library
   - Generate issue records with issue and due dates
   - Track borrowing history
   - Automatic 14-day due date calculation
   - View all currently issued books

4. Search Functionality
   - Search books by title (partial match supported)
   - Search books by author (partial match supported)
   - Display search results with availability status

5. Data Persistence
   - All data stored in binary files
   - Automatic file creation and management
   - Persistent storage across application restarts


Object-Oriented Design

The application uses three main classes:

1. Book Class
   - Encapsulates book data
   - Attributes: bookID, title, author, ISBN, quantity, availableQuantity, price
   - Methods: issueBook(), returnBook(), displayBook()

2. Member Class
   - Encapsulates member information
   - Attributes: memberID, name, email, phone, address, membershipDate, booksIssued
   - Methods: issueBook(), returnBook(), canIssueBook()

3. IssueRecord Class
   - Tracks borrowing transactions
   - Attributes: recordID, memberID, bookID, issueDate, dueDate, returnDate, isReturned
   - Methods: displayRecord()

4. LibrarySystem Class
   - Manages all library operations
   - Handles file I/O
   - Provides CRUD operations for books and members
   - Manages issue/return operations


Compilation Instructions

Windows (MinGW/GCC):
   g++ library_management.cpp -o library_management.exe
   library_management.exe

Windows (MSVC):
   cl library_management.cpp
   library_management.exe

Linux/Mac:
   g++ library_management.cpp -o library_management
   ./library_management


File Structure

The application creates three binary data files:

1. books.dat - Stores book records
   - Fields: bookID, title, author, ISBN, quantity, availableQuantity, price

2. members.dat - Stores member records
   - Fields: memberID, name, email, phone, address, membershipDate, booksIssued

3. issues.dat - Stores borrowing records
   - Fields: recordID, memberID, bookID, issueDate, dueDate, returnDate, isReturned


User Guide

BOOK MANAGEMENT

Add New Book:
   - Select option 1
   - Enter book title
   - Enter author name
   - Enter ISBN
   - Enter quantity of copies
   - Enter price
   - System generates unique Book ID automatically

Display All Books:
   - Select option 2
   - View list of all books with availability status
   - Shows: Book ID, Title, Author, Available/Total copies

Search Book by Title:
   - Select option 3
   - Enter partial or complete title
   - Displays all matching books with full details
   - Supports partial match search

Search Book by Author:
   - Select option 4
   - Enter author name (partial or complete)
   - Lists all books by that author
   - Shows availability for each book

MEMBER MANAGEMENT

Register New Member:
   - Select option 5
   - Enter member name
   - Enter email address
   - Enter phone number
   - Enter address
   - System assigns unique Member ID
   - Membership date recorded automatically

Display All Members:
   - Select option 6
   - View list of all registered members
   - Shows: Member ID, Name, Email, Books Currently Issued

ISSUE AND RETURN OPERATIONS

Issue Book:
   - Select option 7
   - Enter member ID
   - System verifies member exists and has not exceeded 3-book limit
   - Enter book ID
   - System checks book availability
   - Issue record created with 14-day due date
   - Book availability decremented
   - Member's issued book count incremented

Return Book:
   - Select option 8
   - Enter issue record ID
   - System verifies record is valid and not already returned
   - Book availability incremented
   - Member's issued book count decremented
   - Return date recorded
   - Issue record marked as returned

View Issued Books:
   - Select option 9
   - Displays all currently issued books
   - Shows: Issue Record ID, Member ID, Book ID, Issue Date, Due Date


Technical Details

Language: C++ (Standard C++11 or higher)
File Format: Binary (.dat files)
Data Storage: Automatic file creation in application directory
Auto-generated IDs:
   - Book ID: Starting from 1001
   - Member ID: Starting from 2001
   - Issue Record ID: Starting from 5001
Maximum Books per Member: 3
Book Issue Duration: 14 days
Date Format: DD-MM-YYYY


Sample Workflow

1. Start the application
2. Add books:
   - Add "The Great Gatsby" by F. Scott Fitzgerald (5 copies, 250 Rs)
   - Add "1984" by George Orwell (3 copies, 300 Rs)

3. Register members:
   - Register "Alice Johnson" (Member ID: 2001)
   - Register "Bob Smith" (Member ID: 2002)

4. Issue books:
   - Issue Book 1001 to Member 2001 (Record ID: 5001)
   - Issue Book 1002 to Member 2001 (Record ID: 5002)

5. View operations:
   - Display all books (shows availability decreased)
   - Display all members (shows books issued count)
   - View issued books (shows active borrowing records)

6. Return book:
   - Return Record 5001
   - Book availability increases
   - Member's issued count decreases

7. Exit and restart
   - All data persists


Key Validations

Book Operations:
   - Cannot issue unavailable books
   - Cannot issue if no books available
   - Cannot return non-existent books
   - ISBN stored for reference

Member Operations:
   - Cannot issue more than 3 books per member
   - Cannot issue to non-existent members
   - Email and phone validation performed on input

Issue/Return Operations:
   - Cannot issue to member exceeding 3-book limit
   - Cannot return already returned books
   - Automatic due date calculation (14 days)
   - Issue record tracking prevents duplicate operations


Features Explained

1. Partial Search Matching
   - Search for "Gatsby" finds "The Great Gatsby"
   - Search for "Scott" finds books by "F. Scott Fitzgerald"
   - Supports partial author and title matches

2. Automatic ID Generation
   - Book IDs auto-increment starting from 1001
   - Member IDs auto-increment starting from 2001
   - Issue Record IDs auto-increment starting from 5001
   - No duplicate IDs possible

3. Issue Tracking
   - Each borrowing transaction has unique record
   - Issue date recorded automatically
   - Due date set to 14 days from issue
   - Return date recorded when book returned
   - Status tracked (Issued/Returned)

4. Availability Management
   - Book availability updated on issue/return
   - Members cannot exceed 3-book limit
   - System prevents over-issuance

5. Date Management
   - Current system date used for issue date
   - Due date automatically calculated
   - Return date recorded on return
   - Dates stored in DD-MM-YYYY format


Advantages of This Design

- Modular structure with separate classes
- Efficient file-based storage
- Fast search operations
- Automatic ID generation
- Data persistence across sessions
- Complete transaction tracking
- Member borrowing limits prevent overuse
- Easy to extend with features like:
  - Fine calculation for overdue books
  - Book categories/genres
  - Member search functionality
  - Issue history per member
  - Book rating system


Limitations

- Single-user system (no concurrent access)
- No database (uses binary files)
- No fine calculation for overdue books
- No admin/user role separation
- Basic console interface
- No search by ISBN or price
- No book reservation system


Future Enhancements

- Database integration (SQLite/MySQL)
- Fine management for overdue books
- Book reservation system
- Member search and detailed history
- Admin login system
- Book categories and genres
- Member account balance tracking
- Advanced reporting features
- GUI interface
- Network support for remote access
- Email notifications for due dates


Testing Scenarios

1. Add multiple books with different authors
2. Register multiple members
3. Issue maximum (3) books to a member
4. Try to issue 4th book (should fail)
5. Return one book and issue another
6. Search by partial title
7. Search by author name
8. View all issued books
9. Exit and restart (verify data persistence)
10. Test invalid inputs (non-existent member/book IDs)


Error Handling

The system handles:
- Non-existent book IDs
- Non-existent member IDs
- Unavailable books
- Members exceeding 3-book limit
- Already returned books
- Invalid file operations
- Invalid input values


Important Notes

- Keep the application folder location stable (files created there)
- Do not manually edit .dat files
- Ensure write permissions in application directory
- Backup .dat files regularly for data safety
- Issue Record IDs needed for returns (keep track)
- Member can hold maximum 3 books at once
- Default due date is 14 days from issue


Troubleshooting

Problem: "File cannot be opened" error
Solution: Check write permissions in directory, ensure no other program uses the files

Problem: Cannot find previously added books
Solution: Ensure application is running from same directory, check if books.dat exists

Problem: Member ID not found
Solution: Verify member was registered before issuing books

Problem: Cannot compile
Solution: Ensure C++ compiler is installed and set in PATH


Data Backup

To backup library data:
1. Close the application
2. Copy books.dat, members.dat, and issues.dat to safe location
3. Keep regular backups before major operations


Security Considerations

- Binary file format prevents casual tampering
- No encryption (not suitable for production)
- Backup important data regularly
- Do not share .dat files directly


Educational Value

This project demonstrates:
- Object-Oriented Programming concepts
- File I/O operations with binary files
- Class design and encapsulation
- Data validation and error handling
- Menu-driven application development
- Automatic ID generation
- Data persistence
- Search and filtering operations


For more information or questions, refer to the source code comments in library_management.cpp
