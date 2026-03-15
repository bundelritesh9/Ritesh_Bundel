#include<vector>
#include "Room.h"
using namespace std;
#ifndef HOTEL_H
#define HOTEL_H

class Hotel{
    private:
    public:
    vector<Room> rooms;
    void menu();
    void showRooms();
    void bookRoom();
    void checkOut();
    void cancelBooking();
};

#endif