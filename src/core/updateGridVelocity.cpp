#include "core/updateGridVelocity.hpp"

void UpdateGridVelocity(Grid& grid, double dt)
{
  for (auto& node : grid)
  {
	Grid::NodeData& data = node.second;
	data.m_velocity = data.m_velocity + dt * data.m_force / data.m_mass;
  }
}