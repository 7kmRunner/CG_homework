#pragma once

#include "imgui.h"
#include "shape.h"
#include <vector>

namespace USTC_CG {
class Polygon : public Shape
{
    public:
    Polygon() = delete;
    explicit Polygon(
        float start_point_x,
        float start_point_y,
        float end_point_x,
        float end_point_y)
        : 
          end_point_x_(end_point_x),
          end_point_y_(end_point_y)
    {
        vertex.push_back(ImVec2(start_point_x,start_point_y));
    }

    virtual ~Polygon() = default;

    void draw(const Config& config) const override;

    void update(float x, float y) override;

    void update_freehand(float x,float y);

    bool is_finish(ImVec2 const & end_point);

    void add_vertex(ImVec2 const & point);

    ImVec2 first_point();

    private:
        std:: vector<ImVec2> vertex;
        float end_point_x_ = 0.0f, end_point_y_ = 0.0f;
        float bound_ = 18;
};
}