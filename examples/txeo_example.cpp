#include "txeo/detail/utils.h"
#include <iostream>

#include <tensorflow/core/framework/tensor.h>
#include <tensorflow/core/framework/types.pb.h>

void create_tensor() {
  tf::Tensor S(tf::DT_DOUBLE, tf::TensorShape({}));
  auto scal = S.scalar<double>();
  scal() = 10;
  std::cout << "Scalar: " << scal << std::endl;
  std::cout << "Scalar dimensions: " << scal.NumDimensions << std::endl;

  tf::Tensor V(tf::DT_DOUBLE, tf::TensorShape({3}));
  auto vec = V.vec<double>();
  vec(0) = 1;
  vec(1) = 2;
  vec(2) = 3;
  std::cout << "Vector: " << vec << std::endl;
  std::cout << "Vector dimensions: " << vec.NumDimensions << std::endl;

  tf::Tensor M(tf::DT_DOUBLE, tf::TensorShape({3, 3}));
  auto mat = M.matrix<double>();
  mat(0, 0) = 1.0;
  mat(1, 0) = 2.0;
  mat(2, 0) = 3.0;
  mat(0, 1) = 4.0;
  mat(1, 1) = 5.0;
  mat(2, 1) = 6.0;
  mat(0, 2) = 7.0;
  mat(1, 2) = 8.0;
  mat(2, 2) = 9.0;
  std::cout << "Matrix: \n" << mat << std::endl;
  std::cout << "Matrix dimensions: " << mat.NumDimensions << std::endl;

  tf::Tensor M1(tf::DT_DOUBLE, tf::TensorShape({2, 3}));
  auto mat1 = M1.matrix<double>();
  mat1.setZero();
  std::cout << "Zero Matrix: \n" << mat1 << std::endl;

  tf::Tensor M2(tf::DT_DOUBLE, tf::TensorShape({4, 2}));
  auto mat2 = M2.matrix<double>();
  mat2.setConstant(2.6);
  std::cout << "Value Matrix: \n" << mat2 << std::endl;
}

int main() {

  tf::Tensor S(txeo::detail::get_tf_dtype<double>(), tf::TensorShape({}));
  auto scal = S.scalar<double>();
  scal() = 10;
  std::cout << "Scalar: " << scal << std::endl;
  std::cout << "Scalar dimensions: " << scal.NumDimensions << std::endl;

  txeo::detail::cpp_type<tf::DT_DOUBLE> number = 100.2;

  std::cout << "Scalar: " << number << std::endl;

  return 0;
}
