#pragma once

#include <eigen3/Eigen/Core>

class Constants {
public:
  const double grid_cell_size = 0.1;
  const double hardening_coefficient = 10; // 硬化系数 越大越脆，越小越韧
  const double critical_compression = 2.5e-3; // 临界压缩 越大越难裂开 块状  越小 越容易 粉状
  //  const double critical_compression = 1.9e-2;
  const double critical_stretch = 7.5e-4; // 临界拉伸
  //  const double critical_stretch = 5.0e-3;
  const double flip_alpha = 0.95; // 翻转

  const Eigen::Vector3d gravity = Eigen::Vector3d(0.0, -9.81, 0.0); // 重力加速度

  const double youngs_modulus = 1.4e5; // 杨氏模量是描述固体材料抵抗形变能力的物理量
  const double poissons_ratio = 0.2; //材料的横向应变与纵向应变之比就是泊松比。

  // These must be after youngs_modulus and poissons_ratio, so they are
  // initialized after
  const double mu;
  const double lambda;

  Constants();
};
