#include <complex>
#include <iostream>

#include <limits>

#include <gtest/gtest.h>

template <typename T>
class ComplexExpTest : public testing::Test
{};

using FpTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(ComplexExpTest, FpTypes);

TYPED_TEST(ComplexExpTest, nan_pinf_exp)
{
  using CT = std::complex<TypeParam>;

  auto pinf = std::numeric_limits<TypeParam>::infinity();
  auto nan = std::numeric_limits<TypeParam>::quiet_NaN();

  auto x = CT(4.42, 2.02);
  auto y = CT(nan, pinf);

  auto pow_result = std::pow(x, y);
  auto exp_log_result = std::exp(y * std::log(x));
  auto expected_result = CT(0, 0);

  EXPECT_EQ(pow_result, expected_result);
  EXPECT_EQ(exp_log_result, expected_result);
}

TYPED_TEST(ComplexExpTest, ninf_pinf_exp)
{
  using CT = std::complex<TypeParam>;

  auto ninf = std::numeric_limits<TypeParam>::infinity() * -1;
  auto pinf = std::numeric_limits<TypeParam>::infinity();

  auto x = CT(4.42, 2.02);
  auto y = CT(ninf, pinf);

  auto pow_result = std::pow(x, y);
  auto exp_log_result = std::exp(y * std::log(x));
  auto expected_result = CT(0, 0);

  EXPECT_EQ(pow_result, expected_result);
  EXPECT_EQ(exp_log_result, expected_result);
}
