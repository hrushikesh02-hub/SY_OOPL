#include <iostream>
#include <stdexcept>
using namespace std;

class Television {
    int modelNo;
    float price;
    float screenSize;

public:
    void getData() {
        try {
            cout << "Enter Model Number: ";
            cin >> modelNo;
            if (modelNo > 9999)
                throw runtime_error("Invalid Model Number! Must be 4 digits or less.");

            cout << "Enter Price: ";
            cin >> price;
            if (price < 0 || price > 5000)
                throw runtime_error("Invalid Price! Must be between 0 and 5000.");

            cout << "Enter Screen Size (in inches): ";
            cin >> screenSize;
            if (screenSize < 12 || screenSize > 70)
                throw runtime_error("Invalid Screen Size! Must be between 12 and 70 inches.");
        }
        catch (runtime_error &e) {
            cout << "\nException: " << e.what() << endl;
            modelNo = 0;
            price = 0;
            screenSize = 0;
        }
    }

    void showData() {
        cout << "\n--- Television Details ---";
        cout << "\nModel Number: " << modelNo;
        cout << "\nPrice: " << price;
        cout << "\nScreen Size: " << screenSize << " inches\n";
    }
};

int main() {
    Television tv;
    cout << "===== Television Data Entry =====" << endl;

    tv.getData();
    tv.showData();

    return 0;
}
