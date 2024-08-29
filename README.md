Prerequisites

To build and run this project, you need to have the following libraries installed:

    GLEW: The OpenGL Extension Wrangler Library.
    SDL: Simple DirectMedia Layer for window management and input handling.
    OpenGL: Open Graphics Library for rendering 2D and 3D graphics.
    libstb-dev: A collection of STB single-file libraries, specifically for image loading.

Installation Instructions

You can install these libraries on a Debian-based system (e.g., Ubuntu) using the following commands:



    apt update
    sudo apt install libglew-dev libsdl2-dev libgl1-mesa-dev libstb-dev

Building the Project

    Clone the Repository: If you haven’t already, clone the repository:


git clone repository-url

cd repository-directory

CMake Configuration: Use the provided CMakeLists.txt file to configure and generate the build files.

```bash

mkdir build
cd build
cmake ..
```

Build the Project: Compile the project using make:


    make

Running the Tests

The project includes a main.cpp file which you can use to test and modify the implementation. Once you’ve built the project, you can run the executable to see the results:


    ./executable-name

Replace executable-name with the name of the output file specified in your CMakeLists.txt.
Modifying and Testing

    Modify: Edit the main.cpp file or other source files as needed for your tests and modifications.
    Rebuild: After making changes, rebuild the project by running make in the build directory.
    Test: Run the executable to test your changes.

For additional customization and configuration, refer to the CMakeLists.txt file and adjust as necessary.
