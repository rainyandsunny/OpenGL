//
//  ShaderUtil.hpp
//  OpenglStudy
//
//  Created by 杨海鹏 on 2017/5/16.
//  Copyright © 2017年 杨海鹏. All rights reserved.
//

#ifndef ShaderUtil_hpp
#define ShaderUtil_hpp

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


#include <GL/glew.h>



class ShaderUtil
{
    
public:
    
    //程序ID
    GLuint Program;
    
    //构造器读取并构建着色器
    ShaderUtil(const GLchar* vertexPath, const GLchar* fragmentPath){
        
        //std::cout << "顶点着色器路径" << vertexPath << std::endl;
        //std::cout << "片段着色器路径" << fragmentPath << std::endl;
        //1. 从文件路径中获取顶点/片段着色器
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        
        //保证ifstream对象可以抛出异常
        vShaderFile.exceptions(std::ifstream::badbit);
        vShaderFile.exceptions(std::ifstream::badbit);
        
        try{
            
            //打开文件
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            
            //读取文件的缓冲内容到流中
            
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            
            //关闭文件
            vShaderFile.close();
            fShaderFile.close();
            
            //转换流至GLchar数组
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
            //std::cout <<"test" << vertexCode << std::endl;
            //std::cout << "test" << fragmentCode << std::endl;
            
        }catch(std::ifstream::failure e){
            
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            
        }
        
        const GLchar* vShaderCode = vertexCode.c_str();
        const GLchar* fShaderCode = fragmentCode.c_str();
        
        //2.编译着色器
        
        GLuint vertex,fragment;
        GLint success;
        GLchar infoLog[512];
        
        //顶点着色器
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex,1,&vShaderCode,NULL);
        glCompileShader(vertex);
        
        //打印编译错误
        glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
        if(!success){
            
            glGetShaderInfoLog(vertex,512,NULL,infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        };
        
        //片段着色器 ------------------------------------------
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment,1,&fShaderCode,NULL);
        glCompileShader(fragment);
        
        
        //打印编译错误
        glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
        if(!success){
            
            glGetShaderInfoLog(fragment,512,NULL,infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        };
        
        this->Program = glCreateProgram();
        glAttachShader(this->Program,vertex);
        glAttachShader(this->Program,fragment);
        glLinkProgram(this->Program);
        
        //打印链接错误
        glGetProgramiv(this->Program,GL_LINK_STATUS,&success);
        if(!success){
            
            glGetProgramInfoLog(this->Program,512,NULL,infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        
        //删除着色器，它们已经链接到我们的程序里面了，不再需要
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        
        
    }
    
    //使用程序
    void Use(){
        
        glUseProgram(this->Program);
    }
    
    
};



#endif /* ShaderUtil_hpp */
