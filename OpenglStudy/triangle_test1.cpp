//
//  triangle_test1.cpp
//  OpenglStudy

//  添加更多顶点到数据中，使用glDrawArrays，尝试绘制两个彼此相连的三角形。

//  Created by 杨海鹏 on 2017/5/13.
//  Copyright © 2017年 杨海鹏. All rights reserved.
//

/*#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include<GLFW/glfw3.h>


void key_callback(GLFWwindow* window,int key,int scancode,int action, int mode);

const GLuint WIDTH = 800,HEIGHT = 600;


const GLchar* vertexShaderSource = "#version 330 core\n"

"layout (location = 0) in vec3 position; \n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x,position.y,position.z,1.0);\n"
"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\n\0";



int main(){

    glfwInit();
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(WIDTH,HEIGHT,"Triangle", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    glfwSetKeyCallback(window,key_callback);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    int width,height;
    glfwGetFramebufferSize(window,&width,&height);
    glViewport(0,0,width,height);
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);
    
    GLint success;
    GLchar infoLog[512];
    
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success){
        
        glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    
    if(!success){
        
        glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    
    glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
    
    if(!success){
        
        glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
        std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    GLfloat vertices[] = {
        
        //第一个三角形
        -0.5f,0.0f,0.0f,
        0.0f,0.5f,0.0f,
        0.0f,-0.5f,0.0f,
        
        //第二个三角形
        0.5f,0.0f,0.0f,
        0.0f,0.5f,0.0f,
        0.0f,-0.5f,0.0f
    };
    
    GLuint VBO,VAO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    
    //绑定VAO
    glBindVertexArray(VAO);
    
    //把顶点数组复制到缓冲区中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    //设置顶点属性指针
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    
    //解绑VAO
    glBindVertexArray(0);
    
    while(!glfwWindowShouldClose(window)){
        
        glfwPollEvents();
        
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        //画第一个三角形
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        
        //设置线框模式
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        
        //第二个参数制定了顶点数组的起始索引，最后一个参数指定我们打算绘制多少个顶点
        glDrawArrays(GL_TRIANGLES,0,6);
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
        
    }
    
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    
    glfwTerminate();
    
    return 0;
    
}



void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode){
    
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        
        glfwSetWindowShouldClose(window,GL_TRUE);
        
    }


}*/

