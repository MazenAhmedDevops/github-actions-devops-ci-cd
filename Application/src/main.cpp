#include "main.h"

// Prints usage/help
void printHelp() {
    std::cout <<
        "Hotel CLI Application\n"
        "Version: " << APP_VERSION << "\n\n"
        "Usage:\n"
        "  hotel_app --help\n"
        "  hotel_app --version\n"
        "  hotel_app add-room <number> <floor> <type>\n"
        "  hotel_app book <roomNumber> <customer> <checkIn> <checkOut>\n"
        "  hotel_app available <checkIn> <checkOut>\n";
}

void printCommandLengthTooLongOrTooShort() {
    std::cout << 
        "Command is either too short or too long.\n" 
        "Try --help for further instructions \n"
        "on how to use the Hotel CLI Application\n";
}
void printCommandNotFound() {
    std::cout << 
        "Command not found. Try again\n"
        "Try --help for further instructions \n"
        "on how to use the Hotel CLI Application\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printCommandLengthTooLongOrTooShort();
        return ExitCode::INVALID_ARGUMENTS;
    }

    std::string command = argv[1];

    // ---- Global options ----
    if (command == "--help") {
        printHelp();
        return ExitCode::OK;
    }

    if (command == "--version") {
        std::cout << APP_VERSION << "\n";
        return ExitCode::OK;
    }

    // ---- Load hotel data ----
    Hotel hotel;

    // For demo purposes (next step: persistence)
    hotel.addRoom(HotelRoom(101, 1, "Single"));
    hotel.addRoom(HotelRoom(102, 1, "Double"));


    try {
        if (command == "add-room") {
            if (argc != 5) {
                printCommandLengthTooLongOrTooShort();
                return ExitCode::INVALID_ARGUMENTS;
            }

            int number = std::stoi(argv[2]);
            int floor  = std::stoi(argv[3]);
            std::string type = argv[4];

            hotel.addRoom(HotelRoom(number, floor, type));
            std::cout << "Room added successfully\n";
        }
        else if (command == "book") {
            if (argc != 6) {
                printCommandLengthTooLongOrTooShort();
                return ExitCode::INVALID_ARGUMENTS;
            }

            int roomNumber = std::stoi(argv[2]);
            std::string customer = argv[3];
            std::string checkIn = argv[4];
            std::string checkOut = argv[5];

            for (auto& room : hotel.getAllRooms()) {
                if (room.getNumber() == roomNumber) {
                    room.addReservation({customer, checkIn, checkOut});
                    std::cout << "Reservation added\n";
                    return ExitCode::OK;
                }
            }

            std::cerr << "Room not found\n";
            return ExitCode::INVALID_ARGUMENTS;

        }
        else if (command == "available") {
            if (argc != 4) {
                printCommandLengthTooLongOrTooShort();
                return ExitCode::INVALID_ARGUMENTS;
            }

            std::string start = argv[2];
            std::string end = argv[3];

            auto available = hotel.getAvailableRooms(start, end);

            std::cout << "Available rooms:\n";
            for (const auto& room : available) {
                std::cout << "- Room " << room.getNumber()
                          << " (" << room.getType() << ")\n";
            }
        }
        else {
            printCommandNotFound();
            return ExitCode::INVALID_ARGUMENTS;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return ExitCode::RUNTIME_ERROR;
    }
}
