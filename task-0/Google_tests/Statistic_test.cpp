#include "gtest/gtest.h"
#include "../Statistic.h"

TEST(Statistic, DifferentWords) {
    Statistic statMap;

    statMap.add("car");
    statMap.add("bon");
    statMap.add("ari");
    statMap.add("123");

    ASSERT_EQ(statMap.getAmountOfWords(), 4);
}

TEST(Statistic, RecurringWords) {
Statistic statMap;

statMap.add("car");
statMap.add("bon");
statMap.add("car");
statMap.add("car");
statMap.add("ari");
statMap.add("ari");
statMap.add("123");
statMap.add("123");
statMap.add("123");
statMap.add("123");
ASSERT_EQ(statMap.getAmountOfWords(), 10);

vector<pair<string, int>> sorted = statMap.sort();

ASSERT_EQ(sorted[0].first, "123");
ASSERT_EQ(sorted[0].second, 4);
ASSERT_EQ(sorted[1].first, "car");
ASSERT_EQ(sorted[1].second, 3);
ASSERT_EQ(sorted[2].first, "ari");
ASSERT_EQ(sorted[2].second, 2);
ASSERT_EQ(sorted[3].first, "bon");
ASSERT_EQ(sorted[3].second, 1);
}

TEST(Statistic, NoWords) {
Statistic statMap;

ASSERT_EQ(statMap.getAmountOfWords(), 0);
}
