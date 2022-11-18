<img src="Wireframelogo.png" width="200"/> <br/>
# Wireframe 

### A powerful 0 cost no GUI game engine that provides control and speed to the programmer, while also providing ease of use.

Compile this with CMake. (This comes with a demo of how to use this in Example, for which you'll have to drag the files from the Audio subdirectory next to the generated executable, and drag the files from the Shaders subdirectory next to the generated executable. There's also a precompiled version of the demo for Windows x64 at https://randomgamingdev.itch.io/pong)

You can find extensions (basically just small pieces of code that you can include in your project to make developing stuff easier) in the extensions subdirectory! Just plop them into a folder that you can include stuff from and include them!
Here are the currently available extensions(, and just like with the rest of the project I will be happy to except more extesions or changes to extesions):<br/>
- Pixy (Credit to Nyaaborn for the name, you can find his github here: https://github.com/Nyaaboron)
    Pixy is for rendering directly from an array on the CPU, allowing you to make retro games similarly to how they were actually made.
- [box2d](https://github.com/erincatto/box2d)
    box2d is for 2d physics
- [tmxlite](https://github.com/fallahn/tmxlite)
    tmxlite is for interacting with Tiled tilemaps
- [bullet3](https://github.com/bulletphysics/bullet3)
    bullet3 is for 3d physics
- [glm](https://github.com/Groovounet/glm)
    glm is for mathematics and types commonly required when dealing with graphics
- [fmt](https://github.com/fmtlib/fmt)
    fmt is for formatting text
- [ImGui](https://github.com/ocornut/imgui)
    ImGui is for creating a GUI in your application window
- [lua](https://github.com/lua/lua)
    lua is for adding scripting to your application
- [json](https://github.com/nlohmann/json)
    json is for interacting with JSON files
- [stb](https://github.com/nothings/stb)
    stb is for interacting with images
- [asio](https://github.com/chriskohlhoff/asio)
    asio is for networking
- [boost](https://github.com/boostorg/boost)
    boost is a collection of C++ libraries for practically everything
- [soci](https://github.com/SOCI/soci)
    soci is for dealing with databases
- [FlatBuffers](https://github.com/google/flatbuffers)
    FlatBuffers is for serialization
- [Firebase C++ SDK](https://github.com/firebase/firebase-cpp-sdk)
    Firebase C++ SDK is for communicating with the Firebase API for its different features, some common examples are ads, analytics, verification and databases.
- [OIS](https://github.com/wgois/OIS)
    OIS is for nice cross-platform input.

This project relies on: <br/>
EzAL: https://github.com/RandomGamingDev/EzAL <br/>
EzGL: https://github.com/RandomGamingDev/EzGL

To see the dependencies just click the links!

Just like the EzAL, and EzGL, I'd be glad to accept additions to Wireframe to improve the library since I want to support more libraries, APIs, platforms, and more, and generally improve this project.
