//
//  hello_window.cpp
//  OpenglStudy
//
//  Created by 杨海鹏 on 2017/5/11.
//  Copyright © 2017年 杨海鹏. All rights reserved.
//

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

int main(int argc, const char * argv[]){

    glewInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    
}
