#include "HotelRoom.h"

/*
 * Constructor
 * Initializes a HotelRoom with its basic properties.
 */
HotelRoom::HotelRoom(int number,
           int floor,
           const std::string& type)
    : number(number),
      floor(floor),
      type(type)
      {

}

/*
 * Returns the HotelRoom number.
 */
int HotelRoom::getNumber() const {
    return number;
}

/*
 * Returns the floor on which the HotelRoom is located.
 */
int HotelRoom::getFloor() const {
    return floor;
}

/*
 * Returns the HotelRoom type (single, double, suite, etc.).
 */
std::string HotelRoom::getType() const {
    return type;
}

/*
 * Checks whether the HotelRoom is available for a given date range.
 * The HotelRoom is unavailable if ANY reservation overlaps
 * with the requested period.
 */
bool HotelRoom::isAvailable(const std::string& startDate,
                            const std::string& endDate) const {
    for (const auto& reservation : reservations) {
        // Overlap check using string dates (YYYY-MM-DD)
        if (!(endDate <= reservation.checkInDate || startDate >= reservation.checkOutDate)) {
            return false; // overlap found
        }
    }
    return true; // no overlaps
}

/*
 * Adds a reservation to the HotelRoom.
 * Ensures that reservations do NOT overlap.
 * Keeps the reservation list sorted by check-in date.
 * Throws std::invalid_argument if an overlap is detected.
 */
void HotelRoom::addReservation(const Reservation& reservation) {
    // Basic date plausibility check
    if (reservation.checkInDate >= reservation.checkOutDate) {
        throw std::invalid_argument("Invalid reservation dates.");
    }

    // Find insertion position (sorted by check-in date)
    auto it = std::lower_bound(
        reservations.begin(),
        reservations.end(),
        reservation,
        [](const Reservation& a, const Reservation& b) {
            return a.checkInDate < b.checkInDate;
        }
    );

    // Check overlap with previous reservation (if any)
    if (it != reservations.begin()) {
        const auto& prev = *(it - 1);
        if (reservation.checkInDate < prev.checkOutDate) {
            throw std::invalid_argument("Reservation overlaps with an existing booking.");
        }
    }

    // Check overlap with next reservation (if any)
    if (it != reservations.end()) {
        const auto& next = *it;
        if (reservation.checkOutDate > next.checkInDate) {
            throw std::invalid_argument("Reservation overlaps with an existing booking.");
        }
    }

    // Insert reservation if all checks pass
    reservations.insert(it, reservation);
}

/*
 * Returns a read-only reference to the HotelRoom's reservations.
 */
const std::vector<Reservation>& HotelRoom::getReservations() const {
    return reservations;
}
