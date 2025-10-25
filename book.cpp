#include <iostream>
#include <cstring>
using namespace std;

class Books {
    char *title;
    char *author;
    char *publisher;
    float price;
    int stock;

public:
    // Constructor
    Books() {
        title = new char[50];
        author = new char[50];
        publisher = new char[50];
        price = 0.0;
        stock = 0;
    }

    // Input function
    void input() {
        cout << "\nEnter Book Title: ";
        cin.ignore();
        //Removes leftover newline from input buffer
        cin.getline(title, 50);
        //Reads full line(with spaces)
        cout << "Enter Author Name: ";
        cin.getline(author, 50);
        cout << "Enter Publisher Name: ";
        cin.getline(publisher, 50);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Stock (number of copies): ";
        cin >> stock;
    }

    // Search for book
    int search(char t[], char a[]) {
        if ((strcmp(title, t) == 0) && (strcmp(author, a) == 0))
        //comparing of strings
            return 1;
        else
            return 0;
    }

    // Display details
    void display() {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPublisher: " << publisher;
        cout << "\nPrice: " << price;
        cout << "\nStock: " << stock << endl;
    }

    // Function to buy book
    void buyBook() {
        int copies;
        cout << "Enter number of copies required: ";
        cin >> copies;

        if (copies <= stock) {
            cout << "Total cost = Rs. " << (price * copies) << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock!\n";
        }
    }
};

int main() {
    Books b[2]; // array of 2 objects
    cout << "----- Enter Book Details -----\n";
    for (int i = 0; i < 2; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        b[i].input();
    }

    int choice;
    char title[50], author[50];
    do {
        cout << "\n----- MENU -----";
        cout << "\n1. Search and Buy Book";
        cout << "\n2. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter Book Title to Search: ";
            cin.ignore();
            cin.getline(title, 50);
            cout << "Enter Author Name: ";
            cin.getline(author, 50);

            {
                int found = 0;
                for (int i = 0; i < 2; i++) {
                    if (b[i].search(title, author)) {
                        cout << "\nBook Found!";
                        b[i].display();
                        b[i].buyBook();
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "\nBook not available!\n";
            }
            break;

        case 2:
            cout << "\nExiting program...\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}
