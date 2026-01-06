#include <gtest/gtest.h>
#include "HotelRoom.h"
#include "Reservation.h"

// Test no overlapping cases before existing reservation
TEST(ReservationNoOverlap, NoOverlappingBeforeExisting) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-10", "2024-01-20"});
    EXPECT_TRUE(room.isAvailable("2024-01-06", "2024-01-09"));
}

// Test no overlapping cases exactly before existing reservation
TEST(ReservationNoOverlap, NoOverlappingExactlyBeforeExisting) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-10", "2024-01-20"});
    EXPECT_TRUE(room.isAvailable("2024-01-06", "2024-01-10"));
}

// Test no overlapping cases after existing reservation
TEST(ReservationNoOverlap, NoOverlappingAfterExisting) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-10", "2024-01-20"});
    EXPECT_TRUE(room.isAvailable("2024-01-21", "2024-01-27"));
}

// Test no overlapping cases after before existing reservation
TEST(ReservationNoOverlap, NoOverlappingExactlyAfterExisting) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-10", "2024-01-20"});
    EXPECT_TRUE(room.isAvailable("2024-01-20", "2024-01-27"));
}

TEST(ReservationNoOverlap, AvailabilityAfterSeveralBookings) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Alice", "2024-01-01", "2024-01-05"});
    room.addReservation({"Bob", "2024-01-10", "2024-01-15"});
    room.addReservation({"Carol", "2024-01-20", "2024-01-25"});

    // Overlapping with any reservation should fail
    EXPECT_FALSE(room.isAvailable("2024-01-03", "2024-01-11"));
    EXPECT_FALSE(room.isAvailable("2024-01-14", "2024-01-21"));
}

TEST(ReservationNoOverlap, AllDatesAvailable) {
    HotelRoom room(101, 1, "Single");

    EXPECT_TRUE(room.isAvailable("2024-01-01", "2024-12-31"));
    EXPECT_NO_THROW(
        room.addReservation({"Alice", "2024-06-01", "2024-06-05"})
    );
}
