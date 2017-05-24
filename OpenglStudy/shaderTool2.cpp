//
//  shaderTool2.cpp
//  OpenglStudy
//
//  Created by 杨海鹏 on 2017/5/14.
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
"layout (location = 1) in vec3 color;"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x,-position.y,position.z,1.0);\n"  //上下颠倒
"ourColor = color;\n"
"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"in vec3 ourColor;"
"out vec4 color;"
"void main()\n"
"{\n"
"color = vec4(ourColor,1.0f);\n"
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
    
    //创建第一个片段着色器
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
        
        -0.5f,-0.5f,0.0f,  1.0f,0.0f,0.0f,
        0.5f,-0.5f,0.0f,   0.0f,1.0f,0.0f,
        0.0f,0.5f,0.0f,    0.0f,0.0f,1.0f
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
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    //颜色属性
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    
    //解绑VAO
    glBindVertexArray(0);
    
    
    while(!glfwWindowShouldClose(window)){
        
        glfwPollEvents();
        
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        glUseProgram(shaderProgram);
        
        //绘制三角形
        glBindVertexArray(VAO);
        
        //第二个参数制定了顶点数组的起始索引，最后一个参数指定我们打算绘制多少个顶点
        glDrawArrays(GL_TRIANGLES,0,3);
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
