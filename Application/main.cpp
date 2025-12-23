#include <iostream>
#include "HotelRoom.h"
#include "Hotel.h"

int main() {
    Hotel hotel;
    HotelRoom room(101, 1, "Single");

    hotel.addRoom(room);

    room.addReservation({"Alice", "2024-01-01", "2024-01-05"});

    if (room.isAvailable("2024-01-03", "2024-01-04")) {
        std::cout << "Room is available!\n";
        room.addReservation({"Bob", "2024-01-03", "2024-01-04"});
    } else {
        std::cout << "Room is occupied! Try with another dates\n";
    }

    return 0;
}