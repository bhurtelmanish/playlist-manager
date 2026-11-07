#include <gtest/gtest.h>
#include <sstream>
#include "playlist.h"
TEST(DurationTests, DefaultsToZero) { EXPECT_EQ(Duration().total_seconds(), 0); }
TEST(DurationTests, CarriesSeconds) { EXPECT_EQ(Duration(0, 75).total_seconds(), 75); }
TEST(DurationTests, ClampsNegativeTotal) {
    EXPECT_EQ(Duration(0, -5).total_seconds(), 0);
    EXPECT_EQ(Duration(-2, 10).total_seconds(), 0);
    EXPECT_EQ(Duration(1, -30).total_seconds(), 30);
}
TEST(DurationTests, AddsWithoutChangingOperands) {
    Duration first(1, 30), second(0, 45);
    EXPECT_EQ((first + second).total_seconds(), 135);
    EXPECT_EQ(first.total_seconds(), 90);
}
TEST(DurationTests, ComparesTotals) { EXPECT_TRUE(Duration(1, 15) == Duration(0, 75)); }
TEST(DurationTests, PrintsWithTwoSecondDigits) {
    std::ostringstream out;
    out << Duration(3, 5) << " " << Duration();
    EXPECT_EQ(out.str(), "3:05 0:00");
}
TEST(PlaylistTests, MinimumCapacityIsOne) {
    Playlist playlist(0);
    EXPECT_TRUE(playlist.add_track({"First", Duration()}));
    EXPECT_FALSE(playlist.add_track({"Second", Duration()}));
}
TEST(PlaylistTests, RefusesEmptyTitle) {
    Playlist playlist(2);
    EXPECT_FALSE(playlist.add_track({"", Duration(1, 0)}));
    EXPECT_EQ(playlist.size(), 0);
}
TEST(PlaylistTests, RefusesWhenFull) {
    Playlist playlist(1);
    EXPECT_TRUE(playlist.add_track({"A", Duration(1, 0)}));
    EXPECT_FALSE(playlist.add_track({"B", Duration(2, 0)}));
    EXPECT_EQ(playlist.size(), 1);
}
TEST(PlaylistTests, EmptyTotalIsZero) {
    Playlist playlist(2);
    EXPECT_TRUE(playlist.total_length() == Duration());
}
TEST(PlaylistTests, SumsLengths) {
    Playlist playlist(2);
    playlist.add_track({"A", Duration(1, 30)});
    playlist.add_track({"B", Duration(2, 45)});
    EXPECT_TRUE(playlist.total_length() == Duration(4, 15));
}
TEST(PlaylistTests, FindsExactTitleOrNull) {
    Playlist playlist(2);
    playlist.add_track({"Static", Duration(2, 58)});
    ASSERT_NE(playlist.find_track("Static"), nullptr);
    EXPECT_EQ(playlist.find_track("Static")->length.total_seconds(), 178);
    EXPECT_EQ(playlist.find_track("static"), nullptr);
    EXPECT_EQ(playlist.find_track("Missing"), nullptr);
}
