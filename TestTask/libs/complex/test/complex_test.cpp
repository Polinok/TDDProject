#include <gtest/gtest.h>
#include "complex/complex.h"
#include <iostream>

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованы и с созданием объекта всё ок.
 */
TEST(Complex_Tests, Creating) {
    std::cout << "... Complex test ...\n";
}

TEST(Complex_Tests, CheckAbswoReIm) {
    Complex<double> T;

    ASSERT_EQ(T.abs(), 0);
}

TEST(Complex_Tests, CheckAbsOnlyRe) {
    Complex<double> T(5);

    ASSERT_EQ(T.abs(), 5);
}

TEST(Complex_Tests, CheckAbsReIm) {
    Complex<double> T(3, -4);

    ASSERT_EQ(T.abs(), 5);
}

TEST(Complex_Tests, CheckConjRe) {
    Complex<double> T1(3, -4);
    Complex<double> T2 = conj(T1);

    ASSERT_EQ(T2.Re, 3);
}

TEST(Complex_Tests, CheckConjIm) {
    Complex<double> T1(3, -4);
    Complex<double> T2 = conj(T1);

    ASSERT_EQ(T2.Im, 4);
}

TEST(Complex_Tests, CheckOperatorPlusRe) {
    Complex<double> T1(3, -4);
    Complex<double> T2(-5, 6);
    Complex<double> T3 = T1 + T2;

    ASSERT_EQ(T3.Re, -2);
}

TEST(Complex_Tests, CheckOperatorPlusIm) {
    Complex<double> T1(3, -4);
    Complex<double> T2(-5, 6);
    Complex<double> T3 = T1 + T2;

    ASSERT_EQ(T3.Im, 2);
}

TEST(Complex_Tests, CheckOperatorMinusRe) {
    Complex<double> T1(3, -4);
    Complex<double> T2(-5, 6);
    Complex<double> T3 = T1 - T2;

    ASSERT_EQ(T3.Re, 8);
}

TEST(Complex_Tests, CheckOperatorMinusIm) {
    Complex<double> T1(3, -4);
    Complex<double> T2(-5, 6);
    Complex<double> T3 = T1 - T2;

    ASSERT_EQ(T3.Im, -10);
}

TEST(Complex_Tests, CheckOperatorProdRe) {
    Complex<double> T1(3, 1);
    Complex<double> T2(2, -3);
    Complex<double> T3 = T1 * T2;

    ASSERT_EQ(T3.Re, 9);
}

TEST(Complex_Tests, CheckOperatorProdIm) {
    Complex<double> T1(3, 1);
    Complex<double> T2(2, -3);
    Complex<double> T3 = T1 * T2;

    ASSERT_EQ(T3.Im, -7);
}

TEST(Complex_Tests, CheckOperatorDivRe) {
    Complex<double> T1(-1, -3);
    Complex<double> T2(1, -2);
    Complex<double> T3 = T1 / T2;

    ASSERT_EQ(T3.Re, 1);
}

TEST(Complex_Tests, CheckOperatorDivIm) {
    Complex<double> T1(-1, -3);
    Complex<double> T2(1, -2);
    Complex<double> T3 = T1 / T2;

    ASSERT_EQ(T3.Im, -1);
}

/*
TEST(Complex_Tests, CheckOstream) {
    Complex<double> T(5, -3);

    ASSERT_EQ(std::cout << T, "5 - 3i \n");
}

TEST(Complex_Tests, CheckAddRe) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = add(T1, T2);

    ASSERT_EQ(T3.Re, -2);
}

TEST(Complex_Tests, CheckAddIm) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = add(T1, T2);

    ASSERT_EQ(T3.Im, 2);
}

TEST(Complex_Tests, CheckDifRe) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = dif(T1, T2);

    ASSERT_EQ(T3.Re, 8);
}

TEST(Complex_Tests, CheckDifIm) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = dif(T1, T2);

    ASSERT_EQ(T3.Im, -10);
}
*/
