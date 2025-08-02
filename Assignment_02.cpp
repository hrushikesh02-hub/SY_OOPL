#include <iostream>
using namespace std;

class BookShop
{
public:
    int id;
    string title;
    string author;
    string publisher;
    float price;
    int stock;

    BookShop()
    {
        id = 0;
        title = "";
        author = "";
        publisher = "";
        price = 0;
        stock = 0;
    }

    void setData(int i, string t, string a, string p, float pr, int s)
    {
        id = i;
        title = t;
        author = a;
        publisher = p;
        price = pr;
        stock = s;
    }

    void display()
    {
        cout << "\nBook ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }

    void customerRequest()
    {
        int copies;
        cout << "\nBook Title: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "Book Publisher: " << publisher << endl;
        cout << "Book Price: " << price << endl;
        cout << "How many copies do you want? ";
        cin >> copies;

        if (stock < copies)
        {
            cout << "Required copies not in stock\n";
        }
        else
        {
            float total_cost = copies * price;
            cout << "The total cost for " << copies << " copies is: ₹" << total_cost << endl;
        }
    }
};

int main()
{
    int choice, total_books = 0;
    BookShop books[10];

    cout << "----------- Book Shop Inventory System -----------\n";
    while (true)
    {
        cout << "\n1. Add New Book" << endl;
        cout << "2. Search Book by ID" << endl;
        cout << "3. Display All Book Details" << endl;
        cout << "4. Request Book Copies (Purchase)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (total_books >= 10)
            {
                cout << "Book limit reached!" << endl;
                break;
            }

            int id, stock;
            float price;
            string title, author, publisher;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            cin >> title;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter Publisher: ";
            cin >> publisher;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Stock: ";
            cin >> stock;

            books[total_books].setData(id, title, author, publisher, price, stock);
            total_books++;
            cout << "Book added successfully!" << endl;
            break;
        }

        case 2:
        {
            int search_id;
            cout << "Enter Book ID to search: ";
            cin >> search_id;
            bool found = false;
            for (int i = 0; i < total_books; i++)
            {
                if (books[i].id == search_id)
                {
                    cout << "Book found:\n";
                    books[i].display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found!" << endl;
            break;
        }

        case 3:
        {
            if (total_books == 0)
            {
                cout << "No books in inventory!" << endl;
            }
            else
            {
                for (int i = 0; i < total_books; i++)
                {
                    books[i].display();
                }
            }
            break;
        }

        case 4:
        {
            int search_id;
            cout << "Enter Book ID to purchase: ";
            cin >> search_id;
            bool found = false;
            for (int i = 0; i < total_books; i++)
            {
                if (books[i].id == search_id)
                {
                    books[i].customerRequest();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found!" << endl;
            break;
        }

        case 5:
        {
            cout << "Exiting... Thank you!" << endl;
            return 0;
        }

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}
