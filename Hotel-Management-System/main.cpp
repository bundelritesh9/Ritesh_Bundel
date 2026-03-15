#include <iostream>
#include "Hotel.h"
#include "Customer.h"

using namespace std;

void showBanner()
{
    cout << "=====================================\n";
    cout << "       HOTEL MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "        Welcome to Grand Stay\n";
    cout << "=====================================\n\n";
}

void Hotel_Info()
{

    cout << "\n=====================================\n";
    cout << "           HOTEL INFORMATION\n";
    cout << "=====================================\n";
    cout << "Hotel Name      : Grand Stay Hotel\n";
    cout << "Location        : Jaipur, Rajasthan\n";
    cout << "Total Rooms     : 15\n";
    cout << "Room Types      : AC, NON-AC\n";
    cout << "Check-in Time   : 12:00 PM\n";
    cout << "Check-out Time  : 11:00 AM\n";
    cout << "Facilities      :\n";
    cout << "  - Free WiFi\n";
    cout << "  - 24/7 Reception\n";
    cout << "  - Room Service\n";
    cout << "  - Parking Available\n";
    cout << "=====================================\n";
}

int main()
{
    int program = 1;
    showBanner();
    while (program == 1)
    {
        Hotel hotel;
        Customer customer;
        Room room;
        hotel.menu();
        cout << "1) Show rooms" << endl;
        cout << "2) Cancel booking" << endl;
        cout << "3) Check Out" << endl;
        cout << "4) Information about guest" << endl;
        cout << "5) Information about hotel" << endl;
        cout << "6) Exit" << endl;
        cout << "Select one option" << endl;
        int select;
        cin >> select;
        if (select == 1)
        {
            room.showRooms();
            hotel.bookRoom();
        }

        else if (select == 2)
        {
            hotel.cancelBooking();
        }

        else if (select == 3)
        {
            hotel.checkOut();
        }
        else if (select == 4)
        {
            customer.Info();
        }
        else if (select == 5)
        {
            Hotel_Info();
        }

        else if(select == 6)
        {
            program = 0;
        }
        else{
            cout<<"Invalid option"<<endl;
        }
    }
    return 0;
}