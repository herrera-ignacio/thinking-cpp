
/**
Create a makefile for one of the previous exercises (of your choice) that allows you
to type make for a production build of the program, and make debug for a build of the
program including debugging information.
**/

#include <iostream>

int main() {
    #ifdef DEBUG
        std::cout << "[DEBUG VERSION]" << std::endl;
    #endif // DEBUG

    std::cout << "My program" << std::endl;
}