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
