#include <gtest/gtest.h>
#include "HotelRoom.h"


TEST(ReservationSorted, MaintainsSortedOrder) {
    HotelRoom room(101, 1, "Single");
    room.addReservation({"Carol", "2024-01-20", "2024-01-25"});
    room.addReservation({"Alice", "2024-01-10", "2024-01-15"});
    room.addReservation({"Bob", "2024-01-15", "2024-01-20"});

    const auto& res = room.getReservations();
    ASSERT_EQ(res.size(), 3u);

    EXPECT_EQ(res[0].customerName, "Alice");
    EXPECT_EQ(res[1].customerName, "Bob");
    EXPECT_EQ(res[2].customerName, "Carol");
}
