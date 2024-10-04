#include <gtest/gtest.h>
#include "complex/complex.h"

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованы и с созданием объекта всё ок.
 */
TEST(Complex_Tests, Creating) {
    std::cout << "... Complex test ...\n";
}

TEST(Complex_Tests, CheckAbswoReIm) {
    Complex T;

    ASSERT_EQ(T.abs(), 0);
}

TEST(Complex_Tests, CheckAbsOnlyRe) {
    Complex T(5);

    ASSERT_EQ(T.abs(), 5);
}

TEST(Complex_Tests, CheckAbsReIm) {
    Complex T(3, -4);

    ASSERT_EQ(T.abs(), 5);
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

TEST(Complex_Tests, CheckConjRe) {
    Complex T1(3, -4);
    Complex T2 = conj(T1);

    ASSERT_EQ(T2.Re, 3);
}

TEST(Complex_Tests, CheckConjIm) {
    Complex T1(3, -4);
    Complex T2 = conj(T1);

    ASSERT_EQ(T2.Im, 4);
}

TEST(Complex_Tests, CheckOperatorPlusRe) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = T1 + T2;

    ASSERT_EQ(T3.Re, -2);
}

TEST(Complex_Tests, CheckOperatorPlusIm) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = T1 + T2;

    ASSERT_EQ(T3.Im, 2);
}

TEST(Complex_Tests, CheckOperatorMinusRe) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = T1 - T2;

    ASSERT_EQ(T3.Re, 8);
}

TEST(Complex_Tests, CheckOperatorMinusIm) {
    Complex T1(3, -4);
    Complex T2(-5, 6);
    Complex T3 = T1 - T2;

    ASSERT_EQ(T3.Im, -10);
}

TEST(Complex_Tests, CheckOperatorProdRe) {
    Complex T1(3, 1);
    Complex T2(2, -3);
    Complex T3 = T1 * T2;

    ASSERT_EQ(T3.Re, 9);
}

TEST(Complex_Tests, CheckOperatorProdIm) {
    Complex T1(3, 1);
    Complex T2(2, -3);
    Complex T3 = T1 * T2;

    ASSERT_EQ(T3.Im, -7);
}

TEST(Complex_Tests, CheckOperatorDivRe) {
    Complex T1(-1, -3);
    Complex T2(1, -2);
    Complex T3 = T1 / T2;

    ASSERT_EQ(T3.Re, 1);
}

TEST(Complex_Tests, CheckOperatorDivIm) {
    Complex T1(-1, -3);
    Complex T2(1, -2);
    Complex T3 = T1 / T2;

    ASSERT_EQ(T3.Im, -1);
}
