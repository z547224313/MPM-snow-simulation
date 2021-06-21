#pragma once


#include <eigen3/Eigen/Core>

#include "camera.hpp"
#include "constants.hpp"
#include "grid.hpp"
#include "image.hpp"
#include "particle.hpp"
#include <memory>
#include <random>
#include <vector>

class Simulation {
public:
  explicit Simulation(const Constants &constants);

  void add_sphere(double radius, unsigned int edge_length,
                  const Eigen::Vector3d &position,
                  const Eigen::Vector3d &velocity, double mass);
  void Update(double dt);

  const Constants constants;

  std::vector<Particle> particles; //粒子
  std::vector<std::unique_ptr<CollisionObject>> collision_objects; // 碰撞物品
  Grid grid; // 栅格

  Camera camera;
  Image image;
  double render_depth_near = 1; // 渲染 附近深度
  double render_depth_far = 10; // 渲染附近远度

  void add_collision_object(std::unique_ptr<CollisionObject> ptr); // 增加碰撞物

  void render(int frame_index); // 每一帧的帧数

private:
  bool m_firstTick;
  std::mt19937 gen; //巨大随机数
};
