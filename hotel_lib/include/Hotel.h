#pragma once
#include <vector>
#include "HotelRoom.h"

class Hotel {
public:
    void addRoom(const HotelRoom& HotelRoom);

    public: std::vector<HotelRoom> getAllRooms() const;

    public: std::vector<HotelRoom> getAvailableRooms(const std::string& startDate, const std::string& endDate) const;
    
private:
    std::vector<HotelRoom> HotelRooms;
};
