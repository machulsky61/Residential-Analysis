#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;

TEST(corregirRegionTEST, cuatroHogares) {

//                                                    Región
//                                                      v
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  1, 0,  1,  3,  1,  2},
                {31117, 2020,   3,  332870, 642475, 3,  1, 0,  1,  6,  6,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

//                                                            Región
//                                                             v
    eph_h esperado = {{22114, 2020,   3,  319611, 629088, 3,  43, 0,  1,  3,  1,  2},
                      {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                      {31117, 2020,   3,  332870, 642475, 3,  43, 0,  1,  6,  6,  2},
                      {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};

    ASSERT_TRUE(esEncuestaValida(th,ti));
    ASSERT_TRUE(esEncuestaValida(esperado,ti));

    corregirRegion(th, ti);

    // uso del sort para independizar las salidas del orden
    sort(th.begin(), th.end());
    sort(esperado.begin(), esperado.end());

    EXPECT_EQ( th, esperado );
}

// Test nuestros

TEST(corregirRegionTEST, dosHogaresPrimeroSinGbaYSegundoCon) {
    eph_h th = {{1, 2020,   3,  319611, 629088, 3,  4, 0,  1,  3,  1,  2},
                {22114, 2020,   3,  319611, 629088, 3,  GBA, 0,  1,  3,  1,  2}};
    th[0][REGION] = 4;
    th[0][HOGCODUSU] = 1;
    th[1][REGION] = GBA;
    eph_i ti = {{1, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {22114, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10}};
    ti[0][INDCODUSU] = 1;

    eph_h th_esperado = th;
    th_esperado[1][REGION] = PAMPEANA;

    corregirRegion(th, ti);

    EXPECT_EQ(th_esperado, th);
}