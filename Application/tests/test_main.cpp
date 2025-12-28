#include <gtest/gtest.h>
#include <cstdlib>

#include <array>
#include <memory>

// Helper to run command and capture output
std::string run(const std::string& cmd) {
    std::array<char, 256> buffer;
    std::string result;

    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "";

    while (fgets(buffer.data(), buffer.size(), pipe)) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}


TEST(AppBasic, RunsWithoutCrash) {
    int result = std::system("./hotel_app");
    EXPECT_NE(result, 0); // Should fail but not crash
}

TEST(AppBasic, UnknownCommandFails) {
    int result = std::system("./hotel_app unknown");
    EXPECT_NE(result, 0);
}


TEST(AppOutput, HelpContainsUsage) {
    std::string cmd = std::string(APP_EXECUTABLE_PATH) + " --help";

    testing::internal::CaptureStdout();
    int ret = std::system(cmd.c_str());
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_EQ(ret, 0);
    EXPECT_NE(out.find("Usage:"), std::string::npos);
}

TEST(AppOutput, VersionPrinted) {

    std::string cmd = std::string(APP_EXECUTABLE_PATH) + " --version";

    testing::internal::CaptureStdout();
    int ret = std::system(cmd.c_str());
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_EQ(ret, 0);
    EXPECT_NE(out.find("1.0.0"), std::string::npos);
}

TEST(AppIntegration, AvailableRoomsCommand) {
    std::string cmd = std::string(APP_EXECUTABLE_PATH) + " available 2025-01-01 2025-01-02";

    testing::internal::CaptureStdout();
    int ret = std::system(cmd.c_str());
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_EQ(ret, 0);
    EXPECT_NE(out.find("Room"), std::string::npos);
}
