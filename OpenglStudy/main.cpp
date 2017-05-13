//
//  main.cpp
//  OpenglStudy
//
//  Created by 杨海鹏 on 2017/5/11.
//  Copyright © 2017年 杨海鹏. All rights reserved.
//

/*#include <iostream>

#define CLEW_STATIC
#include <GL/glew.h>


#include <GLFW/glfw3.h>



void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode);



 int main(int argc, const char * argv[]) {
    
    
    std::cout << "Starting CLFW context, OpenGL 3.3" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600,"LeanrnOpenGL",nullptr,nullptr);
    
    if(window == nullptr){
        
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    
    if(glewInit() != GLEW_OK){
    
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
        
    }
    
    int width,height;
    glfwGetFramebufferSize(window,&width,&height);
    glViewport(0,0,width,height);
    
    glfwSetKeyCallback(window,key_callback);
    
    while(!glfwWindowShouldClose(window)){
    
        //处理事件
        glfwPollEvents();
        
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        
    }
    
    glfwTerminate();
    return 0;
    

}


void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode){


    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window,GL_TRUE);
    
    }

}
*/



