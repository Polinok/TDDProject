#include <gtest/gtest.h>
#include "complex_0110/complex_0110.h"

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованы и с созданием объекта всё ок.
 */
TEST(Complex_0110_Tests, Creating) {
    std::cout << "... Complex_0110 test ...\n";
}

TEST(Complex_0110_Tests, CheckAbswoReIm) {
    Complex_0110 T;

    ASSERT_EQ(T.abs(), 0);
}

TEST(Complex_0110_Tests, CheckAbsOnlyRe) {
    Complex_0110 T(5);

    ASSERT_EQ(T.abs(), 5);
}

TEST(Complex_0110_Tests, CheckAbsReIm) {
    Complex_0110 T(3, -4);

    ASSERT_EQ(T.abs(), 5);
}

/*
TEST(Complex_0110_Tests, CheckAdd) {
    Complex_0110 T1(3, -4);
    Complex_0110 T2(-5, 6);

    ASSERT_EQ(add(T1, T2), 5);
}
*/
