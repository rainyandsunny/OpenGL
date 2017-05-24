//
//  Shader.cpp
//  OpenglStudy
//
//  Created by 杨海鹏 on 2017/5/15.
//  Copyright © 2017年 杨海鹏. All rights reserved.
//

#ifndef SHADER_H
#define SHADER_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader
{

public:
    
    //程序ID
    GLuint Program;
    
    //构造器读取病构建着色器
    Shader(const GLchar* vartexPath, const GLchar* fragmentPath);
    
    //使用程序
    void Use();


};

#endif
