#include "Sender.h"
#include <gtest/gtest.h>

TEST(SenderTest, GenerateReadings) {
    Sender sender;
    sender.generateReadings();
    ASSERT_EQ(sender.getReadings().size(), 50);
}

TEST(SenderTest, SendReadings) {
    Sender sender;
    sender.generateReadings();
    testing::internal::CaptureStdout();
    sender.sendReadings();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
