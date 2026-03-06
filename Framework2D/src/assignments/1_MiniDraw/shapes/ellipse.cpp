#include "ellipse.h"

#include <imgui.h>

namespace USTC_CG
{
// Draw the rectangle using ImGui
void Ellipse::draw(const Config& config) const
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    float start_x = config.bias[0] + start_point_x_;
    float start_y = config.bias[1] + start_point_y_;
    float end_x = config.bias[0] + end_point_x_;
    float end_y = config.bias[1] + end_point_y_;
    float mid_x = (start_x + end_x)/2;
    float mid_y = (start_y + end_y)/2;
    float length = (end_x > start_x)?(end_x - start_x)/2:(start_x-end_x)/2;
    float width = (start_y > end_y)?(start_y - end_y)/2:(end_y - start_y)/2;

    draw_list->AddEllipse(
        ImVec2(mid_x,mid_y),
        ImVec2(length,width),
        IM_COL32(
            config.line_color[0],
            config.line_color[1],
            config.line_color[2],
            config.line_color[3]),
        0.f,  // No rounding of corners
        ImDrawFlags_None,
        config.line_thickness);
}

void Ellipse::update(float x, float y)
{
    end_point_x_ = x;
    end_point_y_ = y;
}

}  // namespace USTC_CG
