#include <iostream>
using namespace std;

class Book;

class Author
{
    string name;
    string email;
    char gender;

public:
    Author(const string &name = "", const string &email = "", char gender = 'n')
    {
        this->name = name;
        this->email = email;
        this->gender = gender;
    }

    string getName() const
    {
        return name;
    }

    string getEmail() const
    {
        return email;
    }

    char getGender() const
    {
        return gender;
    }

    void setEmail(const string &email)
    {
        this->email = email;
    }

    void print() const
    {
        cout << name << " (" << gender << ") at " << email << endl;
    }
};

class Book
{
    string name;
    Author author;
    double price;
    int qtyInStock;

public:
    Book(string name, Author author, double price, int qtyInStock = 0)
    {
        this->name = name;
        this->author = author;
        this->price = price;
        this->qtyInStock = qtyInStock;
    }

    string getName()
    {
        return name;
    }

    Author &getAuthor()
    {
        return author;
    }

    double getPrice()
    {
        return price;
    }

    int getQtyInStock()
    {
        return qtyInStock;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    void setQtyInStock(int qtyInStock)
    {
        this->qtyInStock = qtyInStock;
    }

    void print()
    {
        cout << "'" << name << "' by ";
        author.print();
    }

    string getAuthorName()
    {
        return author.getName();
    }
};

int main()
{
    Author peter("Peter Jones", "peter@somewhere.com", 'm');
    peter.print();
    Book book("C++ for Dummies", peter, 19.99);
    book.print();
    peter.setEmail("peter@xyz.com");
    peter.print();
    book.print();
    book.getAuthor().setEmail("peter@abc.com");
    book.print();
    return 0;
}
