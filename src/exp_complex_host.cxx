#include <complex>
#include <iostream>

#include <limits>

template <typename T>
void powtest(std::complex<T> x, std::complex<T> y)
{
  std::cout << "===================================" << std::endl;
  std::cout << "x      " << x << std::endl;
  std::cout << "y      " << y << std::endl;
  std::cout << "log(x) " << std::log(x) << std::endl;
  std::cout << "y * log(x) " << y * std::log(x) << std::endl;
  std::cout << "exp(y*log(x)) " << std::exp(y * std::log(x)) << std::endl;
  std::cout << "pow    " << std::pow(x, y) << std::endl;
}

int main(int argc, char** argv)
{
  int i;

  using T = double;
  T result;

  auto ninf = std::numeric_limits<T>::infinity() * -1;
  auto pinf = std::numeric_limits<T>::infinity();
  auto nan = std::numeric_limits<T>::quiet_NaN();

  // std::cout << "h exp -inf " << std::exp(ninf) << std::endl;
  // std::cout << "h exp  inf " << std::exp(pinf) << std::endl;

  std::complex<T> x = std::complex<T>(4.42, 2.02);
  std::complex<T> y = std::complex<T>(ninf, pinf);
  std::complex<T> y2 = std::complex<T>(nan, pinf);

  powtest(x, y);
  powtest(x, y2);

  return 0;
}
