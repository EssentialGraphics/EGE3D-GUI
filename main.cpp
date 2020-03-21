 
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;


int main(void){
    
    
    if (!glfwInit()){
        // Initialization failed
        
        std::cout << "GLFW3 Init() : INITIALIZATION ERROR !" << std::endl;
    }else{
        std::cout << "GLFW3 Init(): DONE" << std::endl;
    }
    
    return 0;
    
}
