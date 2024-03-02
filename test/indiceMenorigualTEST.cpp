#include "../auxiliares.h"
#include "gtest/gtest.h"

TEST(indiceMenorigualTEST, repetidosPrincipio){
    vector<int> in = {1, 1, 1, 2, 4, 5, 10};
    ASSERT_EQ(2, indiceMenorigual(1, in));
}

TEST(indiceMenorigualTEST, repetidosFinal){
    vector<int> in = {1, 2, 4, 5, 10, 10, 10};
    ASSERT_EQ(6, indiceMenorigual(10, in));
}

TEST(indiceMenorigualTEST, repetidosMedio){
    vector<int> in = {1, 2, 4, 5, 5, 6, 10};
    ASSERT_EQ(4, indiceMenorigual(5, in));
}

TEST(indiceMenorigualTEST, todosRepetidos){
    vector<int> in = {1, 1, 1, 1, 1};
    ASSERT_EQ(4, indiceMenorigual(2, in));
}

TEST(indiceMenorigualTEST, todosMayores){
    vector<int> in = {2, 3, 4};
    ASSERT_EQ(-1, indiceMenorigual(1, in));
}

TEST(indiceMenorigualTEST, todosMenores){
    vector<int> in = {2, 3, 4};
    ASSERT_EQ(2, indiceMenorigual(5, in));
}

TEST(indiceMenorigualTEST, todosMenoresMix){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 4), make_pair(2, 3), make_pair(4, 5)};
    ASSERT_EQ(3, indiceMenorigual(6, in));
}

TEST(indiceMenorigualTEST, todosMayoresMix){
    vector<pair<int, int>> in = {make_pair(2, 2), make_pair(2, 4), make_pair(3, 3), make_pair(10, 5)};
    ASSERT_EQ(-1, indiceMenorigual(1, in));
}

TEST(indiceMenorigualTEST, repetidosMedioMix){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(2, 1), make_pair(2, 3), make_pair(4, 5)};
    ASSERT_EQ(2, indiceMenorigual(2, in));
}