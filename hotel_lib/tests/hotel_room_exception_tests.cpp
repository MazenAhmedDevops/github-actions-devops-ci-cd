#include <gtest/gtest.h>
#include "HotelRoom.h"
#include "Reservation.h"

TEST(ReservationAdd, ThrowsOnOverlap) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-10", "2024-01-20"});

    EXPECT_THROW(
        room.addReservation({"Bob", "2024-01-15", "2024-01-18"}),
        std::invalid_argument
    );

    // Non-overlapping reservation should succeed
    EXPECT_NO_THROW(
        room.addReservation({"Carol", "2024-01-20", "2024-01-25"})
    );
}