//
//  triangle_test3.cpp
//  OpenglStudy
//  创建两个着色器程序，第二个程序使用与第一个不同的片段着色器，输出黄色；再次绘制这两个三角形，其中一个输出为黄色
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

const GLchar* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\n\0";

const GLchar* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
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
    GLuint fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader1,1,&fragmentShaderSource1,NULL);
    glCompileShader(fragmentShader1);
    
    glGetShaderiv(fragmentShader1,GL_COMPILE_STATUS,&success);
    
    if(!success){
        
        glGetShaderInfoLog(fragmentShader1,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    
    GLuint shaderProgram1 = glCreateProgram();
    glAttachShader(shaderProgram1,vertexShader);
    glAttachShader(shaderProgram1,fragmentShader1);
    glLinkProgram(shaderProgram1);
    
    glGetProgramiv(shaderProgram1,GL_LINK_STATUS,&success);
    
    if(!success){
        
        glGetProgramInfoLog(shaderProgram1,512,NULL,infoLog);
        std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    //创建第二个片段着色器
    GLuint fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2,1,&fragmentShaderSource2,NULL);
    glCompileShader(fragmentShader2);
    
    glGetShaderiv(fragmentShader2,GL_COMPILE_STATUS,&success);
    
    if(!success){
        
        glGetShaderInfoLog(fragmentShader2,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    
    GLuint shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2,vertexShader);
    glAttachShader(shaderProgram2,fragmentShader2);
    glLinkProgram(shaderProgram2);
    
    glGetProgramiv(shaderProgram2,GL_LINK_STATUS,&success);
    
    if(!success){
        
        glGetProgramInfoLog(shaderProgram2,512,NULL,infoLog);
        std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader1);
    glDeleteShader(fragmentShader2);
    
    
    
    GLfloat firstTriangle[] = {
        
        //第一个三角形
        -0.5f,0.0f,0.0f,
        0.0f,0.5f,0.0f,
        0.0f,-0.5f,0.0f,
        
        
    };
    
    GLfloat secondTriangle[] = {
        
        0.0f,-0.5f,0.0f,
        0.9f,-0.5f,0.0f,
        0.45f,0.5f,0.0f
        
    };

    GLuint VBOs[2],VAOs[2];
    glGenVertexArrays(2,VAOs);
    glGenBuffers(2,VBOs);
    
    
    //First Triangle setup ----------------------------
    //绑定VAO
    glBindVertexArray(VAOs[0]);
    
    //把顶点数组复制到缓冲区中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(firstTriangle),firstTriangle,GL_STATIC_DRAW);
    
    //设置顶点属性指针
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    
    //解绑VAO
    glBindVertexArray(0);
    
    //Second Triangle setup ---------------------------
    
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(secondTriangle),secondTriangle,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(GLvoid* )0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    

    while(!glfwWindowShouldClose(window)){
        
        glfwPollEvents();
        
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        //画第一个三角形
        glUseProgram(shaderProgram1);
        glBindVertexArray(VAOs[0]);
        
        //设置线框模式
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        
        //第二个参数制定了顶点数组的起始索引，最后一个参数指定我们打算绘制多少个顶点
        glDrawArrays(GL_TRIANGLES,0,6);
        
        //画第二个三角形
        
        glUseProgram(shaderProgram2);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES,0,3);
        
        
        glBindVertexArray(0);
        glfwSwapBuffers(window);
        
    }

    
    glDeleteVertexArrays(2,VAOs);
    glDeleteBuffers(2,VBOs);
    
    
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode){
    
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        
        glfwSetWindowShouldClose(window,GL_TRUE);
        
    }
}
*/
