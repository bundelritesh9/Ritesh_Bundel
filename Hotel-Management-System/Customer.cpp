#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Hotel.h"
#include "Room.h"
#include "Customer.h"

void Customer ::Info()
{
    ifstream file("bookings.txt");

    Customer c, c1;
    cout << "Enter guest name : ";
    cin >> c1.name;
    cout << endl;
    Room r, r2;
    cout << "Enter room number : ";
    cin >> r2.roomNumber;
    int match = 0;
    while (file >> r.roomNumber >> r.status >> r.type >> r.price >> c.days >> c.name >> c.age)
    {
        if (r2.roomNumber == r.roomNumber && c1.name == c.name)
        {
            match = 1;
            cout << "\n----------Information----------\n";
            cout << "Name       " << left << setw(5) <<" "<<":"<< setw(5)<<" "<< c.name << endl
                 << "Age        " << setw(5) <<" "<<":"<<setw(5)<<" "<< c.age << endl
                 << "Room Number"<< setw(5) <<" "<<":"<<setw(5)<<" "<< r.roomNumber << endl
                 << "Type       "<< setw(5) <<" "<<":"<<setw(5)<<" "<< r.type << endl
                 << "Total stay "<< setw(5) <<" "<<":"<<setw(5)<<" "<< c.days<<" days"<< endl
                 << "Price/night"<< setw(5) <<" "<<":"<<setw(5)<<" "<<"Rs. "<< r.price << endl
                 << endl;
            cout << "\n";
        }
        
    }
    if(!match){
            cout<<"Invalid name or room number"<<endl;
        }
    file.close();
}