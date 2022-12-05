#include <eigen3/Eigen/Eigen>
#define MY_PI 3.1415926

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0],
        0, 1, 0, -eye_pos[1],
        0, 0, 1, -eye_pos[2],
        0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float angle)
{
    Eigen::Matrix4f rotation;
    angle = angle * MY_PI / 180.f;
    rotation << cos(angle), 0, sin(angle), 0,
        0, 1, 0, 0,
        -sin(angle), 0, cos(angle), 0,
        0, 0, 0, 1;

    Eigen::Matrix4f scale;
    scale << 2.5, 0, 0, 0,
        0, 2.5, 0, 0,
        0, 0, 2.5, 0,
        0, 0, 0, 1;

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    return translate * rotation * scale;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float zNear, float zFar)
{
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f M_trans;
    Eigen::Matrix4f M_persp;
    Eigen::Matrix4f M_ortho;
    M_persp << zNear, 0, 0, 0,
        0, zNear, 0, 0,
        0, 0, zNear + zFar, -zFar * zNear,
        0, 0, 1, 0;

    float alpha = 0.5 * eye_fov * MY_PI / 180.0f;
    float yTop = -zNear * std::tan(alpha);
    float yBottom = -yTop;
    float xRight = yTop * aspect_ratio;
    float xLeft = -xRight;

    M_trans << 1, 0, 0, -(xLeft + xRight) / 2,
        0, 1, 0, -(yTop + yBottom) / 2,
        0, 0, 1, -(zNear + zFar) / 2,
        0, 0, 0, 1;
    M_ortho << 2 / (xRight - xLeft), 0, 0, 0,
        0, 2 / (yTop - yBottom), 0, 0,
        0, 0, 2 / (zNear - zFar), 0,
        0, 0, 0, 1;

    M_ortho = M_ortho * M_trans;
    projection = M_ortho * M_persp * projection;
    return projection;
}
