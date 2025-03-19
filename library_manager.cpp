#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book
{
private:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    Book(int id, string bookTitle, string bookAuthor)
        : bookID(id), title(bookTitle), author(bookAuthor), isIssued(false) {}

    void displayBook()
    {
        cout << "Book ID: " << bookID << ", Title: " << title
             << ", Author: " << author
             << ", Issued: " << (isIssued ? "Yes" : "No") << endl;
    }

    int getID() { return bookID; }
    string getTitle() { return title; }
    bool isBookIssued() { return isIssued; }

    void issueBook()
    {
        if (!isIssued)
        {
            isIssued = true;
            cout << "Book \"" << title << "\" has been issued." << endl;
        }
        else
        {
            cout << "Book \"" << title << "\" is already issued!" << endl;
        }
    }
    void returnBook()
    {
        if (isIssued)
        {
            isIssued = false;
            cout << "Book \"" << title << "\" has been returned." << endl;
        }
        else
        {
            cout << "Book \"" << title << "\" was not issued!" << endl;
        }
    }
};
class Member
{
private:
    int memberID;
    string name;
    int booksIssued;

public:
    Member(int id, string memberName)
        : memberID(id), name(memberName), booksIssued(0) {}

    void displayMember()
    {
        cout << "Member ID: " << memberID << ", Name: " << name
             << ", Books Issued: " << booksIssued << endl;
    }

    int getID() { return memberID; }
    string getName() { return name; }

    void issueBook()
    {
        booksIssued++;
    }

    void returnBook()
    {
        if (booksIssued > 0)
        {
            booksIssued--;
        }
    }
};
class Library
{
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(Book book)
    {
        books.push_back(book);
        cout << "Book \"" << book.getTitle() << "\" added to the library." << endl;
    }

    void addMember(Member member)
    {
        members.push_back(member);
        cout << "Member \"" << member.getName() << "\" added to the library." << endl;
    }

    void displayBooks()
    {
        cout << "\nBooks in the Library:\n";
        for (auto &book : books)
        {
            book.displayBook();
        }
    }

    void displayMembers()
    {
        cout << "\nLibrary Members:\n";
        for (auto &member : members)
        {
            member.displayMember();
        }
    }
    void issueBook(int bookID, int memberID)
    {
        for (auto &book : books)
        {
            if (book.getID() == bookID)
            {
                if (!book.isBookIssued())
                {
                    for (auto &member : members)
                    {
                        if (member.getID() == memberID)
                        {
                            book.issueBook();
                            member.issueBook();
                            return;
                        }
                    }
                    cout << "Member ID not found." << endl;
                    return;
                }
                else
                {
                    cout << "Book is already issued!" << endl;
                    return;
                }
            }
        }
        cout << "Book ID not found." << endl;
    }
    void returnBook(int bookID, int memberID)
    {
        for (auto &book : books)
        {
            if (book.getID() == bookID)
            {
                if (book.isBookIssued())
                {
                    for (auto &member : members)
                    {
                        if (member.getID() == memberID)
                        {
                            book.returnBook();
                            member.returnBook();
                            return;
                        }
                    }
                    cout << "Member ID not found." << endl;
                    return;
                }
                else
                {
                    cout << "Book is not issued!" << endl;
                    return;
                }
            }
        }
        cout << "Book ID not found." << endl;
    }
};

int main()
{
    Library library;

    // // Adding books
    // library.addBook(Book(1, "1984", "George Orwell"));
    // library.addBook(Book(2, "To Kill a Mockingbird", "Harper Lee"));
    // library.addBook(Book(3, "The Great Gatsby", "F. Scott Fitzgerald"));

    // // Adding members
    // library.addMember(Member(101, "Alice"));
    // library.addMember(Member(102, "Bob"));

    // // Display books and members
    // library.displayBooks();
    // library.displayMembers();

    // // Issue and return books
    // cout << "\nIssuing and Returning Books:\n";
    // library.issueBook(1, 101);
    // library.issueBook(2, 102);
    // library.returnBook(1, 101);
    // library.returnBook(3, 102); // Non-issued book

    // // Display updated lists
    // library.displayBooks();
    // library.displayMembers();
    // created a run to checlk class working
    int n;
    cout << "emter number of books";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cout << "enter the title of book" << endl;
        getline(cin, s);
        cout << "enter the namae of author of book" << endl;
        getline(cin, t);
        library.addBook(Book(i, s, t));
    }
    int k;
    cout << "no of members you want to add";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string l;
        cout << "enter name of member";
        getline(cin, l);

        library.addMember(Member((100 + i), l));
    }
    // show initial number of books and members
    library.displayBooks();
    library.displayMembers();

    int o;
    cout << "enter number of books you want to get issued ";
    cin >> o;
    if (o > 0)
    {
        cout << "we will check our library and if we have the book you want we will issue it ";
        for (int i = 0; i < o; i++)
        {
            int w, l;
            cout << "enter book id ";
            cin >> w;
            cout << "enter member id ";
            cin >> l;
            library.issueBook(w, l);
        }
    }
    else
    {
        cout << "waiting for you to get  a book from us";
    }

    int f;
    cout << "enter number of books you want to get returned ";
    cin >> f;
    if (f > 0)
    {
        cout<<"We welcome you just enter the details to get book returned";
        for (int i = 0; i < f; i++)
        {
            int w, l;
            cout << "enter book id ";
            cin >> w;
            cout << "enter member id ";
            cin >> l;
            library.returnBook(w, l);
        }
    }
    else{
        cout<<"please return books after you have read";
    }

    // Display updated lists
    library.displayBooks();
    library.displayMembers();

    return 0;
}