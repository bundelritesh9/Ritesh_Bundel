#ifndef ROOM_H
#define ROOM_H
#include <string>
using namespace std;
class Room{
    public:
    int roomNumber;
    bool isBooked;
    bool status;
    string type;
    int price;
    void showRooms();
};

#endif