#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Hotel.h"
#include "Room.h"
#include "Customer.h"

string roomType(int n)
{
    if (n == 1)
    {
        return "AC";
    }
    else
    {
        return "NONAC";
    }
}

void Room::showRooms()
{
    ifstream file("bookings.txt");
    cout << "1) AC" << endl;
    cout << "2) NON AC" << endl;
    int choice;
    cin >> choice;

    cout << "Available Rooms:\n"
         << endl;

    Room r;
    Customer c;
    cout << left << setw(12) << "Room No"
         << setw(12) << "Type"
         << setw(12) << "Price/night"
         << endl;

    cout << "------------------------------------" << endl;

    while (file >> r.roomNumber >> r.status >> r.type >> r.price >> c.days >> c.name >> c.age)
    {
        if (r.status == 0 && roomType(choice) == r.type)
        {
            cout << left << setw(12) << r.roomNumber
                 << setw(12) << r.type
                 << setw(12) << r.price
                 << endl;
        }
    }
    file.close();
}
