#include "Hotel.h"

void Hotel::addRoom(const HotelRoom& HotelRoom) {
    HotelRooms.push_back(HotelRoom);
}

std::vector<HotelRoom> Hotel::getAllRooms() const
{
    return HotelRooms;
}


std::vector<HotelRoom> Hotel::getAvailableRooms(const std::string& startDate,
                                             const std::string& endDate) const{
    std::vector<HotelRoom> availableRooms;

    for (const auto& Room : HotelRooms) {
        if (Room.isAvailable(startDate,endDate)) {
            availableRooms.push_back(Room);
        }
    }
    return availableRooms;
}
