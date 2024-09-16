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
    House() : Owner(""), Address(""), Bedrooms(0), Price(0.0) {}

    House(string o, string a, int b, float p) : Owner(o), Address(a), Bedrooms(b), Price(p) {}

    void set_Owner(string owner) { Owner = owner; }
    void set_Address(string address) { Address = address; }
    void set_Bedrooms(int bedrooms) { Bedrooms = bedrooms; }
    void set_Price(float price) { Price = price; }

    string get_Owner() { return Owner; }
    string get_Address() { return Address; }
    int get_Bedrooms() { return Bedrooms; }
    float get_Price() { return Price; }
};

void findhouse(House houses[], int size)
{
    string foundPrice, foundBedrooms, foundCity;
    float maxPrice;
    int minBedrooms;
    string city;

    cout << "Enter maximum wanted price (? for no preference): ";
    cin >> foundPrice;
    cout << "Enter minimum wanted number of bedrooms (? for no preference): ";
    cin >> foundBedrooms;
    cout << "Enter wanted city (? for no preference): ";
    cin >> foundCity;

    // Convert the user input for price and bedrooms into usable formats
    maxPrice = (foundPrice != "?") ? stof(foundPrice) : 999999999.0; // No preference for price
    minBedrooms = (foundBedrooms != "?") ? stoi(foundBedrooms) : -1; // No preference for bedrooms
    city = (foundCity != "?") ? foundCity : ""; // No preference for city

    // Display filtered houses based on preferences
    cout << "\nOwner\tAddress\tBedrooms\tPrice\n";
    for (int i = 0; i < size; i++)
    {
        if ((houses[i].get_Price() <= maxPrice) &&
            (houses[i].get_Bedrooms() >= minBedrooms) &&
            (city == "" || houses[i].get_Address().find(city) != string::npos))
        {
            cout << houses[i].get_Owner() << "\t"
                << houses[i].get_Address() << "\t"
                << houses[i].get_Bedrooms() << "\t"
                << houses[i].get_Price() << endl;
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

    cout << "\nOwner\tAddress\tBedrooms\tPrice" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << available[i].get_Owner() << "\t"
            << available[i].get_Address() << "\t"
            << available[i].get_Bedrooms() << "\t"
            << available[i].get_Price() << endl;
    }

    findhouse(available, count);

    return 0;
}
