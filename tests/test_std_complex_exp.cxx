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

  auto ninf = std::numeric_limits<TypeParam>::infinity() * -1;
  auto pinf = std::numeric_limits<TypeParam>::infinity();
  auto nan = std::numeric_limits<TypeParam>::quiet_NaN();

  auto x = CT(4.42, 2.02);
  auto y = CT(nan, pinf);

  auto pow_result = std::pow(x, y);
  auto exp_log_result = std::exp(y * std::log(x));

  EXPECT_EQ(pow_result, exp_log_result);
}
