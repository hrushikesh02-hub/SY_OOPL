#include<iostream>
using namespace std;

class BookShop {
public:
    int stock, id;
    float price;
    string b_name, a_name, p_name;
    string c_name, city;
    long long m_num;

    BookShop() {
        stock = 0;
        price = 0;
        b_name = "";
        a_name = "";
        p_name = "";
        c_name = "";
        city = "";
        m_num = 0;
    }

    void setdata(int s, int ID, float pr, string a, string b, string p) {
        id = ID;
        stock = s;
        price = pr;
        b_name = b;
        a_name = a;
        p_name = p;
    }

    void display() {
        cout << "\n--- Book Details ---\n";
        cout << "Book ID: " << id << endl;
        cout << "Title: " << b_name << endl;
        cout << "Author: " << a_name << endl;
        cout << "Publisher: " << p_name << endl;
        cout << "Available Stock: " << stock << endl;
        cout << "Price: ₹" << price << endl;
    }

    void purchase() {
        int copies;
        string confirm;
        cout << "\n--- Purchase Book ---\n";
        cout << "Title: " << b_name << endl;
        cout << "Author: " << a_name << endl;
        cout << "Publisher: " << p_name << endl;
        cout << "Price: ₹" << price << endl;
        cout << "How many copies do you want? : ";
        cin >> copies;

        if (stock < copies) {
            cout << "Sorry, the requested number of copies is not available in stock!\n";
        } else {
            float total_cost = copies * price;
            cout << "Total cost for " << copies << " copies: ₹" << total_cost << endl;
            cout << "Do you want to proceed with the purchase? (yes/no): ";
            cin >> confirm;

            if (confirm == "yes") {
                cout << "\nEnter Your Details:\n";
                cout << "Name: ";
                cin >> c_name;
                cout << "Mobile Number: ";
                cin >> m_num;
                cout << "City: ";
                cin >> city;

                stock -= copies;
                cout << "Book purchased successfully!\n";
            } else {
                cout << "Purchase cancelled. Thank you for visiting!\n";
            }
        }
    }

    void c_details() {
        cout << "\n--- Customer Details ---\n";
        cout << "Name: " << c_name << endl;
        cout << "Mobile Number: " << m_num << endl;
        cout << "City: " << city << endl;
        cout << "Book Purchased: " << b_name << endl;
    }
};

int main() {
    int choice, total_books = 0, found;
    string bookname, authorname;
    string name;
    BookShop book[100];

    cout << "---------- Book Inventory System ----------\n";
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add New Book\n";
        cout << "2. Search Book\n";
        cout << "3. Purchase Book\n";
        cout << "4. Display Available Books\n";
        cout << "5. Display Customer Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        found = 0;

        switch (choice) {
            case 1:
                if (total_books >= 100) {
                    cout << "Book limit reached! Cannot add more books.\n";
                } else {
                    int stock, id;
                    float price;
                    string b_name, a_name, p_name;

                    cout << "\n--- Add New Book ---\n";
                    cout << "Enter Book ID: ";
                    cin >> id;
                    cout << "Enter Title: ";
                    cin >> b_name;
                    cout << "Enter Author: ";
                    cin >> a_name;
                    cout << "Enter Publisher: ";
                    cin >> p_name;
                    cout << "Enter Stock: ";
                    cin >> stock;
                    cout << "Enter Price: ";
                    cin >> price;

                    book[total_books].setdata(stock, id, price, a_name, b_name, p_name);
                    total_books++;
                    cout << "Book added successfully!\n";
                }
                break;

            case 2:
                cout << "\n--- Search Book ---\n";
                cout << "Enter Book Title: ";
                cin >> bookname;
                cout << "Enter Author Name: ";
                cin >> authorname;
                for (int i = 0; i < total_books; i++) {
                    if (book[i].b_name == bookname && book[i].a_name == authorname) {
                        found = 1;
                        book[i].display();
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found!\n";
                }
                break;

            case 3:
                cout << "\n--- Purchase Book ---\n";
                cout << "Enter Book Title: ";
                cin >> bookname;
                cout << "Enter Author Name: ";
                cin >> authorname;
                for (int i = 0; i < total_books; i++) {
                    if (book[i].b_name == bookname && book[i].a_name == authorname) {
                        found = 1;
                        book[i].purchase();
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found!\n";
                }
                break;

            case 4:
                cout << "\n--- Available Books ---\n";
                for (int i = 0; i < total_books; i++) {
                    book[i].display();
                }
                break;

            case 5:
                cout << "\n--- Customer Details ---\n";
                cout << "Enter Customer Name: ";
                cin >> name;
                for (int i = 0; i < total_books; i++) {
                    if (name == book[i].c_name) {
                        found = 1;
                        book[i].c_details();
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer not found!\n";
                }
                break;

            case 6:
                cout << "Thank you for using the Book Inventory System!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
