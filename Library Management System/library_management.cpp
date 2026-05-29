#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// Book Class
class Book {
private:
    int bookID;
    char title[100];
    char author[100];
    char isbn[20];
    int quantity;
    int availableQuantity;
    double price;
    
public:
    // Constructor
    Book() {
        bookID = 0;
        strcpy(title, "");
        strcpy(author, "");
        strcpy(isbn, "");
        quantity = 0;
        availableQuantity = 0;
        price = 0.0;
    }
    
    // Setters
    void setBookID(int id) { bookID = id; }
    void setTitle(const char* t) { strncpy(title, t, 99); title[99] = '\0'; }
    void setAuthor(const char* a) { strncpy(author, a, 99); author[99] = '\0'; }
    void setISBN(const char* isbn_num) { strncpy(isbn, isbn_num, 19); isbn[19] = '\0'; }
    void setQuantity(int q) { quantity = q; }
    void setAvailableQuantity(int aq) { availableQuantity = aq; }
    void setPrice(double p) { price = p; }
    
    // Getters
    int getBookID() const { return bookID; }
    const char* getTitle() const { return title; }
    const char* getAuthor() const { return author; }
    const char* getISBN() const { return isbn; }
    int getQuantity() const { return quantity; }
    int getAvailableQuantity() const { return availableQuantity; }
    double getPrice() const { return price; }
    
    // Book operations
    bool issueBook() {
        if (availableQuantity > 0) {
            availableQuantity--;
            return true;
        }
        return false;
    }
    
    bool returnBook() {
        if (availableQuantity < quantity) {
            availableQuantity++;
            return true;
        }
        return false;
    }
    
    void displayBook() const {
        cout << "\n\t" << string(80, '=') << endl;
        cout << "\tBook ID      : " << bookID << endl;
        cout << "\tTitle        : " << title << endl;
        cout << "\tAuthor       : " << author << endl;
        cout << "\tISBN         : " << isbn << endl;
        cout << "\tTotal Copies : " << quantity << endl;
        cout << "\tAvailable    : " << availableQuantity << endl;
        cout << "\tPrice        : Rs. " << fixed << setprecision(2) << price << endl;
        cout << "\t" << string(80, '=') << endl;
    }
    
    void displayBookSummary() const {
        cout << "\t" << setw(5) << bookID 
             << setw(35) << title 
             << setw(25) << author 
             << setw(8) << availableQuantity << "/" << quantity << endl;
    }
};

// Member Class
class Member {
private:
    int memberID;
    char name[100];
    char email[100];
    char phone[15];
    char address[150];
    char membershipDate[20];
    int booksIssued;
    
public:
    // Constructor
    Member() {
        memberID = 0;
        strcpy(name, "");
        strcpy(email, "");
        strcpy(phone, "");
        strcpy(address, "");
        strcpy(membershipDate, "");
        booksIssued = 0;
    }
    
    // Setters
    void setMemberID(int id) { memberID = id; }
    void setName(const char* n) { strncpy(name, n, 99); name[99] = '\0'; }
    void setEmail(const char* e) { strncpy(email, e, 99); email[99] = '\0'; }
    void setPhone(const char* p) { strncpy(phone, p, 14); phone[14] = '\0'; }
    void setAddress(const char* a) { strncpy(address, a, 149); address[149] = '\0'; }
    void setMembershipDate(const char* d) { strncpy(membershipDate, d, 19); membershipDate[19] = '\0'; }
    void setBooksIssued(int b) { booksIssued = b; }
    
    // Getters
    int getMemberID() const { return memberID; }
    const char* getName() const { return name; }
    const char* getEmail() const { return email; }
    const char* getPhone() const { return phone; }
    const char* getAddress() const { return address; }
    const char* getMembershipDate() const { return membershipDate; }
    int getBooksIssued() const { return booksIssued; }
    
    // Member operations
    void issueBook() {
        if (booksIssued < 3) {  // Max 3 books per member
            booksIssued++;
        }
    }
    
    void returnBook() {
        if (booksIssued > 0) {
            booksIssued--;
        }
    }
    
    bool canIssueBook() const {
        return booksIssued < 3;
    }
    
    void displayMember() const {
        cout << "\n\t" << string(80, '=') << endl;
        cout << "\tMember ID        : " << memberID << endl;
        cout << "\tName             : " << name << endl;
        cout << "\tEmail            : " << email << endl;
        cout << "\tPhone            : " << phone << endl;
        cout << "\tAddress          : " << address << endl;
        cout << "\tMembership Date  : " << membershipDate << endl;
        cout << "\tBooks Currently  : " << booksIssued << "/3" << endl;
        cout << "\t" << string(80, '=') << endl;
    }
    
    void displayMemberSummary() const {
        cout << "\t" << setw(5) << memberID 
             << setw(30) << name 
             << setw(25) << email 
             << setw(8) << booksIssued << "/3" << endl;
    }
};

// Issue Record Class
class IssueRecord {
private:
    int recordID;
    int memberID;
    int bookID;
    char issueDate[20];
    char dueDate[20];
    char returnDate[20];
    bool isReturned;
    
public:
    // Constructor
    IssueRecord() {
        recordID = 0;
        memberID = 0;
        bookID = 0;
        strcpy(issueDate, "");
        strcpy(dueDate, "");
        strcpy(returnDate, "");
        isReturned = false;
    }
    
    // Setters
    void setRecordID(int id) { recordID = id; }
    void setMemberID(int mid) { memberID = mid; }
    void setBookID(int bid) { bookID = bid; }
    void setIssueDate(const char* date) { strncpy(issueDate, date, 19); issueDate[19] = '\0'; }
    void setDueDate(const char* date) { strncpy(dueDate, date, 19); dueDate[19] = '\0'; }
    void setReturnDate(const char* date) { strncpy(returnDate, date, 19); returnDate[19] = '\0'; }
    void setReturned(bool r) { isReturned = r; }
    
    // Getters
    int getRecordID() const { return recordID; }
    int getMemberID() const { return memberID; }
    int getBookID() const { return bookID; }
    const char* getIssueDate() const { return issueDate; }
    const char* getDueDate() const { return dueDate; }
    const char* getReturnDate() const { return returnDate; }
    bool getReturned() const { return isReturned; }
    
    void displayRecord() const {
        cout << "\n\tIssue Record ID : " << recordID << endl;
        cout << "\tMember ID       : " << memberID << endl;
        cout << "\tBook ID         : " << bookID << endl;
        cout << "\tIssue Date      : " << issueDate << endl;
        cout << "\tDue Date        : " << dueDate << endl;
        cout << "\tReturn Date     : " << (isReturned ? returnDate : "Not Returned") << endl;
        cout << "\tStatus          : " << (isReturned ? "Returned" : "Issued") << endl;
    }
};

// Library Management System Class
class LibrarySystem {
private:
    const char* bookFile = "books.dat";
    const char* memberFile = "members.dat";
    const char* issueFile = "issues.dat";
    
    void drawHeader(const char* title) {
        cout << "\n\n";
        cout << "\t" << string(80, '*') << endl;
        cout << "\t*" << string(78, ' ') << "*" << endl;
        cout << "\t*" << setw(50) << title << string(28, ' ') << "*" << endl;
        cout << "\t*" << string(78, ' ') << "*" << endl;
        cout << "\t" << string(80, '*') << endl;
    }
    
    string getCurrentDate() {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        char date[20];
        sprintf(date, "%d-%02d-%d", timeinfo->tm_mday, 
                timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
        return string(date);
    }
    
    int generateBookID() {
        ifstream inFile(bookFile, ios::binary);
        if (!inFile) return 1001;
        
        int lastID = 1000;
        Book book;
        while (inFile.read((char*)&book, sizeof(Book))) {
            if (book.getBookID() > lastID)
                lastID = book.getBookID();
        }
        inFile.close();
        return lastID + 1;
    }
    
    int generateMemberID() {
        ifstream inFile(memberFile, ios::binary);
        if (!inFile) return 2001;
        
        int lastID = 2000;
        Member member;
        while (inFile.read((char*)&member, sizeof(Member))) {
            if (member.getMemberID() > lastID)
                lastID = member.getMemberID();
        }
        inFile.close();
        return lastID + 1;
    }
    
    int generateRecordID() {
        ifstream inFile(issueFile, ios::binary);
        if (!inFile) return 5001;
        
        int lastID = 5000;
        IssueRecord record;
        while (inFile.read((char*)&record, sizeof(IssueRecord))) {
            if (record.getRecordID() > lastID)
                lastID = record.getRecordID();
        }
        inFile.close();
        return lastID + 1;
    }
    
    bool bookExists(int bookID) {
        ifstream inFile(bookFile, ios::binary);
        if (!inFile) return false;
        
        Book book;
        while (inFile.read((char*)&book, sizeof(Book))) {
            if (book.getBookID() == bookID) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
    }
    
    bool memberExists(int memberID) {
        ifstream inFile(memberFile, ios::binary);
        if (!inFile) return false;
        
        Member member;
        while (inFile.read((char*)&member, sizeof(Member))) {
            if (member.getMemberID() == memberID) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
    }
    
    bool readBook(int bookID, Book& book) {
        ifstream inFile(bookFile, ios::binary);
        if (!inFile) return false;
        
        while (inFile.read((char*)&book, sizeof(Book))) {
            if (book.getBookID() == bookID) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
    }
    
    bool readMember(int memberID, Member& member) {
        ifstream inFile(memberFile, ios::binary);
        if (!inFile) return false;
        
        while (inFile.read((char*)&member, sizeof(Member))) {
            if (member.getMemberID() == memberID) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
    }
    
    void updateBook(const Book& book) {
        fstream file(bookFile, ios::binary | ios::in | ios::out);
        if (!file) return;
        
        Book tempBook;
        while (file.read((char*)&tempBook, sizeof(Book))) {
            if (tempBook.getBookID() == book.getBookID()) {
                int pos = -1 * (int)sizeof(Book);
                file.seekp(pos, ios::cur);
                file.write((char*)&book, sizeof(Book));
                break;
            }
        }
        file.close();
    }
    
    void updateMember(const Member& member) {
        fstream file(memberFile, ios::binary | ios::in | ios::out);
        if (!file) return;
        
        Member tempMember;
        while (file.read((char*)&tempMember, sizeof(Member))) {
            if (tempMember.getMemberID() == member.getMemberID()) {
                int pos = -1 * (int)sizeof(Member);
                file.seekp(pos, ios::cur);
                file.write((char*)&member, sizeof(Member));
                break;
            }
        }
        file.close();
    }
    
public:
    // Book Management
    void addBook() {
        drawHeader("ADD NEW BOOK");
        
        Book book;
        char title[100], author[100], isbn[20];
        int quantity;
        double price;
        
        int bookID = generateBookID();
        book.setBookID(bookID);
        
        cout << "\n\tEnter Book Title: ";
        cin.ignore();
        cin.getline(title, 100);
        book.setTitle(title);
        
        cout << "\tEnter Author Name: ";
        cin.getline(author, 100);
        book.setAuthor(author);
        
        cout << "\tEnter ISBN: ";
        cin.getline(isbn, 20);
        book.setISBN(isbn);
        
        cout << "\tEnter Quantity: ";
        cin >> quantity;
        book.setQuantity(quantity);
        book.setAvailableQuantity(quantity);
        
        cout << "\tEnter Price (Rs.): ";
        cin >> price;
        book.setPrice(price);
        
        ofstream outFile(bookFile, ios::binary | ios::app);
        outFile.write((char*)&book, sizeof(Book));
        outFile.close();
        
        cout << "\n\t" << string(50, '=') << endl;
        cout << "\tBook Added Successfully!" << endl;
        cout << "\tBook ID: " << bookID << endl;
        cout << "\t" << string(50, '=') << endl;
    }
    
    void displayAllBooks() {
        drawHeader("ALL BOOKS IN LIBRARY");
        
        ifstream inFile(bookFile, ios::binary);
        if (!inFile) {
            cout << "\n\tNo books found!" << endl;
            return;
        }
        
        Book book;
        bool found = false;
        
        cout << "\n\t" << string(80, '-') << endl;
        cout << "\t" << setw(5) << "ID" 
             << setw(35) << "Title" 
             << setw(25) << "Author" 
             << setw(15) << "Available" << endl;
        cout << "\t" << string(80, '-') << endl;
        
        while (inFile.read((char*)&book, sizeof(Book))) {
            book.displayBookSummary();
            found = true;
        }
        
        if (!found) {
            cout << "\tNo books in library!" << endl;
        }
        
        cout << "\t" << string(80, '-') << endl;
        inFile.close();
    }
    
    void searchBookByTitle() {
        drawHeader("SEARCH BOOK BY TITLE");
        
        char searchTitle[100];
        cout << "\n\tEnter Book Title to Search: ";
        cin.ignore();
        cin.getline(searchTitle, 100);
        
        ifstream inFile(bookFile, ios::binary);
        if (!inFile) {
            cout << "\n\tNo books found!" << endl;
            return;
        }
        
        Book book;
        bool found = false;
        
        while (inFile.read((char*)&book, sizeof(Book))) {
            if (strstr(book.getTitle(), searchTitle) != NULL) {
                book.displayBook();
                found = true;
            }
        }
        
        if (!found) {
            cout << "\n\tBook with title '" << searchTitle << "' not found!" << endl;
        }
        
        inFile.close();
    }
    
    void searchBookByAuthor() {
        drawHeader("SEARCH BOOK BY AUTHOR");
        
        char searchAuthor[100];
        cout << "\n\tEnter Author Name to Search: ";
        cin.ignore();
        cin.getline(searchAuthor, 100);
        
        ifstream inFile(bookFile, ios::binary);
        if (!inFile) {
            cout << "\n\tNo books found!" << endl;
            return;
        }
        
        Book book;
        bool found = false;
        
        cout << "\n\t" << string(80, '-') << endl;
        cout << "\tBooks by " << searchAuthor << ":" << endl;
        cout << "\t" << string(80, '-') << endl;
        
        while (inFile.read((char*)&book, sizeof(Book))) {
            if (strstr(book.getAuthor(), searchAuthor) != NULL) {
                cout << "\n\tBook ID: " << book.getBookID() << endl;
                cout << "\tTitle: " << book.getTitle() << endl;
                cout << "\tAvailable Copies: " << book.getAvailableQuantity() 
                     << "/" << book.getQuantity() << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "\tNo books by author '" << searchAuthor << "' found!" << endl;
        }
        
        cout << "\t" << string(80, '-') << endl;
        inFile.close();
    }
    
    // Member Management
    void addMember() {
        drawHeader("REGISTER NEW MEMBER");
        
        Member member;
        char name[100], email[100], phone[15], address[150];
        
        int memberID = generateMemberID();
        member.setMemberID(memberID);
        
        cout << "\n\tEnter Member Name: ";
        cin.ignore();
        cin.getline(name, 100);
        member.setName(name);
        
        cout << "\tEnter Email: ";
        cin.getline(email, 100);
        member.setEmail(email);
        
        cout << "\tEnter Phone Number: ";
        cin.getline(phone, 15);
        member.setPhone(phone);
        
        cout << "\tEnter Address: ";
        cin.getline(address, 150);
        member.setAddress(address);
        
        string currentDate = getCurrentDate();
        member.setMembershipDate(currentDate.c_str());
        member.setBooksIssued(0);
        
        ofstream outFile(memberFile, ios::binary | ios::app);
        outFile.write((char*)&member, sizeof(Member));
        outFile.close();
        
        cout << "\n\t" << string(50, '=') << endl;
        cout << "\tMember Registered Successfully!" << endl;
        cout << "\tMember ID: " << memberID << endl;
        cout << "\t" << string(50, '=') << endl;
    }
    
    void displayAllMembers() {
        drawHeader("ALL REGISTERED MEMBERS");
        
        ifstream inFile(memberFile, ios::binary);
        if (!inFile) {
            cout << "\n\tNo members found!" << endl;
            return;
        }
        
        Member member;
        bool found = false;
        
        cout << "\n\t" << string(80, '-') << endl;
        cout << "\t" << setw(5) << "ID" 
             << setw(30) << "Name" 
             << setw(25) << "Email" 
             << setw(8) << "Books" << endl;
        cout << "\t" << string(80, '-') << endl;
        
        while (inFile.read((char*)&member, sizeof(Member))) {
            member.displayMemberSummary();
            found = true;
        }
        
        if (!found) {
            cout << "\tNo members in system!" << endl;
        }
        
        cout << "\t" << string(80, '-') << endl;
        inFile.close();
    }
    
    // Issue and Return Operations
    void issueBook() {
        drawHeader("ISSUE BOOK");
        
        int memberID, bookID;
        
        cout << "\n\tEnter Member ID: ";
        cin >> memberID;
        
        if (!memberExists(memberID)) {
            cout << "\n\tMember not found!" << endl;
            return;
        }
        
        Member member;
        readMember(memberID, member);
        
        if (!member.canIssueBook()) {
            cout << "\n\tMember has already issued 3 books (maximum limit reached)!" << endl;
            return;
        }
        
        cout << "\tEnter Book ID: ";
        cin >> bookID;
        
        if (!bookExists(bookID)) {
            cout << "\n\tBook not found!" << endl;
            return;
        }
        
        Book book;
        readBook(bookID, book);
        
        if (!book.issueBook()) {
            cout << "\n\tBook is not available!" << endl;
            return;
        }
        
        // Create issue record
        IssueRecord record;
        record.setRecordID(generateRecordID());
        record.setMemberID(memberID);
        record.setBookID(bookID);
        
        string issueDate = getCurrentDate();
        record.setIssueDate(issueDate.c_str());
        
        // Due date is 14 days from issue date
        time_t now = time(0) + (14 * 24 * 60 * 60);
        tm* timeinfo = localtime(&now);
        char dueDate[20];
        sprintf(dueDate, "%d-%02d-%d", timeinfo->tm_mday, 
                timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
        record.setDueDate(dueDate);
        record.setReturned(false);
        
        // Update member
        member.issueBook();
        
        // Save issue record
        ofstream outFile(issueFile, ios::binary | ios::app);
        outFile.write((char*)&record, sizeof(IssueRecord));
        outFile.close();
        
        // Update book and member
        updateBook(book);
        updateMember(member);
        
        cout << "\n\t" << string(50, '=') << endl;
        cout << "\tBook Issued Successfully!" << endl;
        cout << "\tIssue Record ID: " << record.getRecordID() << endl;
        cout << "\tDue Date: " << dueDate << endl;
        cout << "\t" << string(50, '=') << endl;
    }
    
    void returnBook() {
        drawHeader("RETURN BOOK");
        
        int recordID;
        cout << "\n\tEnter Issue Record ID: ";
        cin >> recordID;
        
        fstream file(issueFile, ios::binary | ios::in | ios::out);
        if (!file) {
            cout << "\n\tNo records found!" << endl;
            return;
        }
        
        IssueRecord record;
        bool found = false;
        
        while (file.read((char*)&record, sizeof(IssueRecord))) {
            if (record.getRecordID() == recordID && !record.getReturned()) {
                found = true;
                
                // Return book
                Book book;
                readBook(record.getBookID(), book);
                book.returnBook();
                updateBook(book);
                
                // Update member
                Member member;
                readMember(record.getMemberID(), member);
                member.returnBook();
                updateMember(member);
                
                // Update record
                string returnDate = getCurrentDate();
                record.setReturnDate(returnDate.c_str());
                record.setReturned(true);
                
                int pos = -1 * (int)sizeof(IssueRecord);
                file.seekp(pos, ios::cur);
                file.write((char*)&record, sizeof(IssueRecord));
                
                cout << "\n\t" << string(50, '=') << endl;
                cout << "\tBook Returned Successfully!" << endl;
                cout << "\tReturn Date: " << returnDate.c_str() << endl;
                cout << "\t" << string(50, '=') << endl;
                break;
            }
        }
        
        if (!found) {
            cout << "\n\tIssue record not found or already returned!" << endl;
        }
        
        file.close();
    }
    
    void viewIssuedBooks() {
        drawHeader("CURRENTLY ISSUED BOOKS");
        
        ifstream inFile(issueFile, ios::binary);
        if (!inFile) {
            cout << "\n\tNo records found!" << endl;
            return;
        }
        
        IssueRecord record;
        bool found = false;
        
        cout << "\n\t" << string(100, '-') << endl;
        cout << "\t" << setw(8) << "RecID" 
             << setw(8) << "MID" 
             << setw(8) << "BID" 
             << setw(15) << "Issue Date" 
             << setw(15) << "Due Date"
             << setw(8) << "Status" << endl;
        cout << "\t" << string(100, '-') << endl;
        
        while (inFile.read((char*)&record, sizeof(IssueRecord))) {
            if (!record.getReturned()) {
                cout << "\t" << setw(8) << record.getRecordID()
                     << setw(8) << record.getMemberID()
                     << setw(8) << record.getBookID()
                     << setw(15) << record.getIssueDate()
                     << setw(15) << record.getDueDate()
                     << setw(8) << "Issued" << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "\tNo books currently issued!" << endl;
        }
        
        cout << "\t" << string(100, '-') << endl;
        inFile.close();
    }
};

// Main Menu
void displayMainMenu() {
    cout << "\n\n";
    cout << "\t" << string(80, '=') << endl;
    cout << "\t                LIBRARY MANAGEMENT SYSTEM - MAIN MENU" << endl;
    cout << "\t" << string(80, '=') << endl;
    cout << "\n\t                    BOOK MANAGEMENT" << endl;
    cout << "\t    1. Add New Book" << endl;
    cout << "\t    2. Display All Books" << endl;
    cout << "\t    3. Search Book by Title" << endl;
    cout << "\t    4. Search Book by Author" << endl;
    
    cout << "\n\t                   MEMBER MANAGEMENT" << endl;
    cout << "\t    5. Register New Member" << endl;
    cout << "\t    6. Display All Members" << endl;
    
    cout << "\n\t                 ISSUE/RETURN MANAGEMENT" << endl;
    cout << "\t    7. Issue Book to Member" << endl;
    cout << "\t    8. Return Book from Member" << endl;
    cout << "\t    9. View Currently Issued Books" << endl;
    
    cout << "\n\t    10. Exit" << endl;
    cout << "\t" << string(80, '=') << endl;
    cout << "\t    Enter your choice: ";
}

int main() {
    LibrarySystem library;
    int choice;
    
    cout << "\n\n";
    cout << "\t" << string(80, '*') << endl;
    cout << "\t*" << string(78, ' ') << "*" << endl;
    cout << "\t*" << setw(50) << "WELCOME TO LIBRARY MANAGEMENT SYSTEM" 
         << string(28, ' ') << "*" << endl;
    cout << "\t*" << string(78, ' ') << "*" << endl;
    cout << "\t" << string(80, '*') << endl;
    
    do {
        displayMainMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayAllBooks();
                break;
            case 3:
                library.searchBookByTitle();
                break;
            case 4:
                library.searchBookByAuthor();
                break;
            case 5:
                library.addMember();
                break;
            case 6:
                library.displayAllMembers();
                break;
            case 7:
                library.issueBook();
                break;
            case 8:
                library.returnBook();
                break;
            case 9:
                library.viewIssuedBooks();
                break;
            case 10:
                cout << "\n\t" << string(80, '=') << endl;
                cout << "\t    Thank you for using Library Management System!" << endl;
                cout << "\t" << string(80, '=') << endl;
                break;
            default:
                cout << "\n\tInvalid choice! Please try again." << endl;
        }
        
        if (choice != 10) {
            cout << "\n\tPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while(choice != 10);
    
    return 0;
}
