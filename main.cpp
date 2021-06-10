#include <iostream>
#include <adder.hpp>
#include <GLFW/glfw3.h>

int main(int, char**) {
    std::cout << "Hello, world in C++ !\n";
    std::cout << add(34.1f, 43.1f) << "\n";

    GLFWwindow* window;
    
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    
    window = glfwCreateWindow( 600, 600, "CMake How To", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    
    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        //draw();

        // Update animation
        //animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
}
