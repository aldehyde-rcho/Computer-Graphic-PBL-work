#include <iostream>
#include <GL/glut.h>

int nearplane_width = 300;                        //视景体宽度
int nearplane_height = 300;                       //视景体高度
int nearplane_distance = 50;                      //视景体近平面与视点距离
int farplane_distance = nearplane_distance + 300; //视景体远平面与视点距离
int eye_x = 50;                                   //视点的x坐标
