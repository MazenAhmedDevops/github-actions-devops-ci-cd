#pragma once
#include <string>
#include <vector>
#include "Reservation.h"
#include <algorithm>
#include <stdexcept> // required for std::invalid_argument

class HotelRoom {
public:
    HotelRoom(int number, int floor, const std::string& type);

    int getNumber() const;
    int getFloor() const;
    std::string getType() const;

    // Checks if the room is available in the given date range
    bool isAvailable(const std::string& startDate, const std::string& endDate) const;

    // Adds a reservation (assumes availability is already checked)
    void addReservation(const Reservation& reservation);

    const std::vector<Reservation>& getReservations() const;

private:
    int number;
    int floor;
    std::string type;
    std::vector<Reservation> reservations;
};