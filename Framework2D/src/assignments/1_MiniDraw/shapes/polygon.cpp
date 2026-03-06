# include <cmath>
# include <cstdlib>
# include "imgui.h"
# include "polygon.h"
#include <sys/_types/_u_int32_t.h>

namespace USTC_CG{

    void Polygon::draw(const Config& config) const
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    u_int32_t size = vertex.size();
    
    for(u_int32_t i = 0;i < size-1;i++){
        draw_list->AddLine(
            ImVec2(vertex[i].x+config.bias[0],vertex[i].y+config.bias[1]),
            ImVec2(vertex[i+1].x+config.bias[0],vertex[i+1].y+config.bias[1]),
            IM_COL32(
                config.line_color[0],
                config.line_color[1],
                config.line_color[2],
                config.line_color[3]),
            config.line_thickness);
    }

        draw_list->AddLine(
            ImVec2(vertex[size-1].x+config.bias[0],vertex[size-1].y+config.bias[1]),
            ImVec2(end_point_x_+config.bias[0],end_point_y_+config.bias[1]),
            IM_COL32(
                config.line_color[0],
                config.line_color[1],
                config.line_color[2],
                config.line_color[3]),
            config.line_thickness);
}

    void Polygon::update(float x, float y)
    {
        ImVec2 start = vertex.front();
        if(std::abs(x-start.x) < bound_ && std::abs(y-start.y) < bound_){
            end_point_x_ = start.x;
            end_point_y_ = start.y;
        }
        else{
            end_point_x_ = x;
            end_point_y_ = y;
        }
    }

    void Polygon::update_freehand(float x,float y)
    {
        end_point_x_ = x;
        end_point_y_ = y;
    }

    void Polygon::add_vertex(ImVec2 const & point){
        vertex.push_back(ImVec2(point.x,point.y));
    }

    bool Polygon::is_finish(ImVec2 const & end_point){
        ImVec2 start = vertex.front();

        if(std::abs(start.x - end_point.x)< bound_ 
        && std::abs(start.y - end_point.y) <bound_){
            return true;
        }
        
        return false;
    }

    ImVec2 Polygon::first_point(){
        if(vertex.size()!=0){
            return vertex[0];
        }
        
        throw("Polygon未初始化,不存在第一个值!");
    }
}