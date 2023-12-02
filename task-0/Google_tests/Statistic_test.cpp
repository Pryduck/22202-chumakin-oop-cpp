#include "gtest/gtest.h"
#include "../Statistic.h"

TEST(Statistic, different_words) {
    Statistic stat_map;

    stat_map.adding("car");
    stat_map.adding("bon");
    stat_map.adding("ari");
    stat_map.adding("123");

    ASSERT_EQ(stat_map.get_number(), 4);
}

TEST(Statistic, recurring_words) {
Statistic stat_map;

stat_map.adding("car");
stat_map.adding("bon");
stat_map.adding("car");
stat_map.adding("car");
stat_map.adding("ari");
stat_map.adding("ari");
stat_map.adding("123");
stat_map.adding("123");
stat_map.adding("123");
stat_map.adding("123");
ASSERT_EQ(stat_map.get_number(), 10);

vector<pair<string, int>> sorted = stat_map.sorting();

ASSERT_EQ(sorted[0].first, "123");
ASSERT_EQ(sorted[0].second, 4);
ASSERT_EQ(sorted[1].first, "car");
ASSERT_EQ(sorted[1].second, 3);
ASSERT_EQ(sorted[2].first, "ari");
ASSERT_EQ(sorted[2].second, 2);
ASSERT_EQ(sorted[3].first, "bon");
ASSERT_EQ(sorted[3].second, 1);
}

TEST(Statistic, no_words) {
Statistic stat_map;

ASSERT_EQ(stat_map.get_number(), 0);
}