#include "complex.hpp"
#include <cmath>

Complex::Complex(const double& _re): re(_re), im(0.0) {}

Complex::Complex(const double& _re, const double& _im): re(_re), im(_im) {}

const double& Complex::real() const {
  return re;
}

const double& Complex::imag() const {
  return im;
}

Complex Complex::conj() const {
  return Complex(re, -im);
}

double Complex::norm() const {
  return std::sqrt(norm2());
}

double Complex::norm2() const {
  return re*re + im*im;
}

bool operator==(Complex const& a, Complex const& b) {
  return (a.re == b.re) && (a.im == b.im);
}
bool operator!=(Complex const& a, Complex const& b) {
  return !(a == b);
}

Complex operator+(Complex const& a, Complex const& b) {
  return Complex(a.re + b.re, a.im + b.im);
}

Complex operator-(Complex const& a, Complex const& b) {
  return Complex(a.re - b.re, a.im - b.im);
}

Complex operator*(Complex const& a, Complex const& b) {
  return Complex(a.re*b.re-a.im*b.im, a.re*b.im+a.im*b.re);
  // (a + ib)*(c + id) == (a*c - b*d) + i(b*c + a*d)
}

Complex operator/(Complex const& a, Complex const& b) {

  double denominator = b.re * b.re + b.im * b.im;
  return Complex((a.re * b.re + a.im * b.im) / denominator,
                 (a.im * b.re - a.re * b.im) / denominator);
}

Complex operator*(Complex const& a, int const& b)
{
  return Complex(b*a.re,b*a.im); 
}

Complex operator/(Complex const& a, int const& b)
{
  return Complex(a.re/b,a.im/b);
}

Complex operator-(Complex const& a) {
  return Complex(-a.re, -a.im);
}
