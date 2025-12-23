#include <gtest/gtest.h>
#include "HotelRoom.h"
#include "Reservation.h"

// Test overlapping in the middle
TEST(ReservationOverlap, OverlappingMiddle) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-10", "2024-01-20"});
    EXPECT_FALSE(room.isAvailable("2024-01-15", "2024-01-18"));
}

// Test overlapping exactly at start
TEST(ReservationOverlap, OverlappingStart) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Bob", "2024-01-10", "2024-01-20"});
    EXPECT_FALSE(room.isAvailable("2024-01-05", "2024-01-12"));
}

// Test overlapping at end
TEST(ReservationOverlap, OverlappingEnd) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Carol", "2024-01-10", "2024-01-20"});
    EXPECT_FALSE(room.isAvailable("2024-01-18", "2024-01-25"));
}

// Test complete overlapping
TEST(ReservationOverlap, CompleteOverlapping) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Carol", "2024-01-10", "2024-01-20"});
    EXPECT_FALSE(room.isAvailable("2024-01-10", "2024-01-20"));
}

// Test complete overlapping plus few days
TEST(ReservationOverlap, CompleteOverlappingPlusFewDays) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Carol", "2024-01-10", "2024-01-20"});
    EXPECT_FALSE(room.isAvailable("2024-01-09", "2024-01-21"));
}

TEST(ReservationOverlap, AvailabilityAfterSeveralBookings) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-01", "2024-01-05"});
    room.addReservation({"Bob", "2024-01-10", "2024-01-15"});
    room.addReservation({"Carol", "2024-01-20", "2024-01-25"});

    // Check availability in gaps
    EXPECT_TRUE(room.isAvailable("2024-01-05", "2024-01-10"));
    EXPECT_TRUE(room.isAvailable("2024-01-15", "2024-01-20"));
}