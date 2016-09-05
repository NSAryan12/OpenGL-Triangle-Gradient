//
//  main.cpp
//  OpenGL-Triangle-Gradient
//
//  Created by Aryan Kashyap on 05/09/2016.
//  Copyright © 2016 Aryan Kashyap. All rights reserved.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void)
{
    GLFWwindow *window;
    
    // Initialize the library
    if (!glfwInit()) {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Triangle Gradient", NULL, NULL);
    
    
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent(window);
    
    // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glViewport(0.0f, 0.0f, screenWidth, screenHeight);
    
    // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glMatrixMode(GL_PROJECTION);
    
    // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glLoadIdentity();
    
    // essentially set coordinate system
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 600);
    
    // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glMatrixMode(GL_MODELVIEW);
    
    // same as above comment
    glLoadIdentity();
    
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
    
    GLfloat halfSideLength = 200;
    
    // Vertices for the triangle
    GLfloat vertices[] =
    {
        halfScreenWidth, halfScreenHeight + halfSideLength, 0.0, // top center vertex
        halfScreenWidth - halfSideLength, halfScreenHeight - halfSideLength, 0.0, // bottom left corner
        halfScreenWidth + halfSideLength, halfScreenHeight - halfSideLength, 0.0 // bottom right corner
    };
    
    // color value
    GLfloat colour[] =
    {
        255, 0, 0,
        0, 255, 0,
        0, 0, 255
    };
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose(window))
    {
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Render OpenGL here
        
        // tell OpenGL that you're using a vertex array for fixed-function attribute
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        
        // point to the vertices to be used
        glVertexPointer( 3, GL_FLOAT, 0, vertices );
        glColorPointer( 3, GL_FLOAT, 0, colour );
        
        // draw the vertixes
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glDisableClientState( GL_COLOR_ARRAY );
        
        // tell OpenGL that you're finished using the vertex array attribute
        glDisableClientState( GL_VERTEX_ARRAY );
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate();
    
    return 0;
}
