#include <iostream>
#include <string>
using namespace std;

class House
{
private:
    string Owner;
    string Address;
    int Bedrooms;
    float Price;

public:
    // Default constructor
    House() : Owner(""), Address(""), Bedrooms(0), Price(0.0) {}

    // Parameterized constructor
    House(string o, string a, int b, float p) : Owner(o), Address(a), Bedrooms(b), Price(p) {}

    // Setter methods
    void set_Owner(string owner) { Owner = owner; }
    void set_Address(string address) { Address = address; }
    void set_Bedrooms(int bedrooms) { Bedrooms = bedrooms; }
    void set_Price(float price) { Price = price; }

    // Getter methods
    string get_Owner() { return Owner; }
    string get_Address() { return Address; }
    int get_Bedrooms() { return Bedrooms; } // Fixed typo here
    float get_Price() { return Price; }
};

void findhouse(House houses[], int size)
{
    string city;
    float maxPrice;
    int minBedrooms;

    cout << "Enter Max Price for House (enter 0 if no preference): ";
    cin >> maxPrice;

    cout << "Enter Min Number of Bedrooms (enter 0 if no preference): ";
    cin >> minBedrooms;

    cout << "Enter city of preference (enter 'none' if no preference): ";
    cin >> city;

    for (int i = 0; i < size; i++)
    {
        if ((houses[i].get_Price() <= maxPrice || maxPrice == 0) &&
            (houses[i].get_Bedrooms() >= minBedrooms || minBedrooms == 0) &&
            (houses[i].get_Address().find(city) != string::npos || city == "none"))
        {
            cout << "Owner: " << houses[i].get_Owner() << ", Address: " << houses[i].get_Address()
                << ", Bedrooms: " << houses[i].get_Bedrooms() << ", Price: " << houses[i].get_Price() << endl;
        }
    }
}

int main()
{
    House available[100];
    int count = 0;
    string owner, address;
    int bedrooms;
    char choice;
    float price;
    bool condition = true;

    while (condition)
    {
        cout << "Enter Owner: ";
        getline(cin, owner);
        available[count].set_Owner(owner);

        cout << "Enter Address: ";
        getline(cin, address);
        available[count].set_Address(address);

        cout << "Number of Bedrooms: ";
        cin >> bedrooms;
        available[count].set_Bedrooms(bedrooms);

        cout << "Price: ";
        cin >> price;
        available[count].set_Price(price);

        cout << "Enter Another House? (Y/N): ";
        cin >> choice;
        cin.ignore(); // To clear the input buffer for getline()

        if (choice == 'N' || choice == 'n')
        {
            condition = false;
        }
        else if (choice == 'Y' || choice == 'y')
        {
            count++;
        }
    }

    // Display all houses
    cout << "\nOwner\tAddress\tBedrooms\tPrice" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << available[i].get_Owner() << "\t"
            << available[i].get_Address() << "\t"
            << available[i].get_Bedrooms() << "\t"
            << available[i].get_Price() << endl;
    }

    return 0;
}
