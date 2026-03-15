#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Hotel.h"
#include "Room.h"
#include "Customer.h"

using namespace std;

void Hotel::menu()
{
    cout << "\nHotel Reservation System Menu\n"
         << endl;
}

void Hotel::bookRoom()
{
    cout << endl;
    cout << "Enter guest age: ";
    int ask_age;
    cin >> ask_age;
    if(ask_age>=18){

        cout << "Enter room number to book: ";
        int ask_room;
        cin >> ask_room;
        ifstream file("bookings.txt");
        ofstream temp("temp.txt");
        Room r;
        Customer c;
        
        while (file >> r.roomNumber >> r.status >> r.type >> r.price >> c.days >> c.name >> c.age)
        {
            
            if (ask_room == r.roomNumber && r.status == 0)
            {
                r.status = 1;
                c.age = ask_age;
                cout << "Enter guest name: ";
                cin >> c.name;
                cout << "Enter number of days to stay : ";
                cin >> c.days;
                cout << "Room " << r.roomNumber << " is successfully booked" << endl;
            }
            temp << r.roomNumber << " " << r.status << " " << r.type << " " << r.price << " " << c.days << " " << c.name << " " << c.age << endl;
        }
        file.close();
        temp.close();
        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");
       
    }
    else{
        cout<<"Sorry, booking is only allowed for 18 years or older";
    }
}

void Hotel::cancelBooking()
{

    ifstream file("bookings.txt");
    ofstream temp("temp.txt");
    cout << "Enter room number to cancel" << endl;
    int choice;
    cin >> choice;

    Room r;
    Customer c;
    while (file >> r.roomNumber >> r.status >> r.type >> r.price >> c.days >> c.name >> c.age)
    {
        if (choice == r.roomNumber && r.status == 1)
        {
            r.status = 0;
            c.days = 0;
            c.name = "NIL";
            c.age = 0;
            cout << "Room " << r.roomNumber << " is successfully cancelled" << endl;
        }
        temp << r.roomNumber << " " << r.status << " " << r.type << " " << r.price << " " << c.days << " " << c.name << " " << c.age << endl;
    }
    file.close();
    temp.close();
    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");
}

void Hotel ::checkOut()
{
    ifstream file("bookings.txt");
    ofstream temp("temp.txt");
    cout << "Enter the room number for check out : ";
    int room_no;
    cin >> room_no;
    Room r;
    Customer c;
    while (file >> r.roomNumber >> r.status >> r.type >> r.price >> c.days >> c.name >> c.age)
    {
        if (room_no == r.roomNumber)
        {
            cout << "\n----------Final Bill----------\n";
            cout << "Name       " << left << setw(5) <<" "<<":"<< setw(5)<<" "<< c.name << endl
                 << "Age        " << setw(5) <<" "<<":"<<setw(5)<<" "<< c.age << endl
                 << "Room Number"<< setw(5) <<" "<<":"<<setw(5)<<" "<< r.roomNumber << endl
                 << "Type       "<< setw(5) <<" "<<":"<<setw(5)<<" "<< r.type << endl
                 << "Total stay "<< setw(5) <<" "<<":"<<setw(5)<<" "<< c.days<<" days"<< endl
                 << "Price/night"<< setw(5) <<" "<<":"<<setw(5)<<" "<<"Rs. "<< r.price << endl
                 << "Total Bill "<< setw(5) <<" "<<":"<<setw(5)<<" "<<"Rs. "<< c.days * r.price << endl
                 << "\nCheckout succesful."
                 << endl;
            cout << "Thank you for staying with us!"<<endl;
            r.status = 0;
            c.days = 0;
            c.name = "NIL";
            c.age = 0;
        }
        temp << r.roomNumber << " " << r.status << " " << r.type << " " << r.price << " " << c.days << " " << c.name << " " << c.age << endl;
    }
    file.close();
    temp.close();
    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");
}
