<img src="Wireframelogo.png" width="200"/> <br/>
# Wireframe 

### A powerful 0 cost no GUI game engine that provides control and speed to the programmer, while also providing ease of use. (similar to LWJGL)

<details><summary><h3>Click here for why you should choose Wireframe as the catalyst for your next project (gamedev or not)</h3></summary>
C++ is the ideal language for game development, which has only been further proven by its longevity in the game dev department. This is due to its speed, libraries, support, community, reliability, great features, and of course its portability as it's supported on nearly every gaming and not gaming system out there. One common problem with this though is that although nearly all gaming platforms are united with their use of C++, their graphics and audio libraries are not. Another common problem is that the optimizations of C++ are oftentimes overshadowed by the sheer unbridled use of resources that have to be carefully manipulated in the settings of multiple other game engines, most of which is not only hard to understand, but basically shut off from the end user, which is you. Wireframe aims to solve all of these problems. With a simple unified system for graphics and audio it guarantees that everyone is open to the developers, guaranteeing speed as long as you know how to program properly in C++ due to the sheer readability, simplicity and openeness of all of the different systems in Wireframe. Also due to this simplified system, nearly any platform can be added to this game engine, whether it's a console like the PS2 or Nintendo 64, to something like the PS5 or Xbox series X. This simplified and unified system offers some clear benefits in opposition to the more complex and hard to grapple systems of closed off game engines like Unreal or Unity. While there are open source engines like Godot, they are often too complex to not only port to other platforms, but to modify for the typical programmer, unless you want to spend days, weeks or even months on end studying the intricate layout of it. There are of course fantasy retro consoles, like for example the widely adored PICO-8 fantasy console. While these are simple and elegant in nature and I won't deny they're perfect if you want to create something like an NES game and are fine with the limitations, like PICO-8's restricting limits on sprites, amount of code and other things, most of which is something that you don't want to have to deal with in your projects. Wireframe encourages you to poke around in a comfortable envirnoment, not the other way around. Plus, with the extension system you can easily find the best libraries to use in your project and even add some of your own! These extensions are open source and easy to work with, multiple of which are header files that can simply be read through and changed to your liking, with multiple of them being built in a way that can be easily ported! Wireframe also uses a nice Object Oriented system for managing your code (there are also static functions in case you don't want to do that of course, looking at you C devs right now) which means autocomplete in IDEs that support it, which is something missing from traditional OpenGL due to its API. Wireframe serves to eccentrify and boost, rather than ignore and supress these key features of the language we all know and love as C++, and to prioritize openess, speed and simplicity. These are just some of the reasons you might want to choose Wireframe for your next project (even if it isn't game dev). Again, any contributions to the engine are welcome.
</details>

There currently isn't any direct documentation since the header files + OpenGL & OpenAL documentation should be enough since Wireframe is designed to be very very similar to them except C++ and with an extra layer so that different APIs can be used too.

First, clone this project with git and using the --recursive argument. Compile this with CMake. (This comes with a demo of how to use this in Example, for which you'll have to drag the files from the Audio subdirectory next to the generated executable, and drag the files from the Shaders subdirectory next to the generated executable. There's also a precompiled version of the demo for Windows x64 at https://randomgamingdev.itch.io/pong)

You can download an x64 Windows executable for the demo at https://randomgamingdev.itch.io/pong.

You can find extensions (basically just small pieces of code that you can include in your project to make developing stuff easier) in the extensions subdirectory! Just plop them into a folder that you can include stuff from and include them!
Here are the currently available extensions(, and just like with the rest of the project I will be happy to except more extesions or changes to extesions):<br/>
- Pixy (Credit to Nyaaborn for the name, you can find his github here: https://github.com/Nyaaboron)
    Pixy is for rendering directly from an array on the CPU, allowing you to make retro games similarly to how they were actually made.
- Pixelator
    Pixelator is made for rendering to a lower quality (or higher quality, but it wouldn't really do much of anything) FBO, allowing you to easily pixelate your game quickly and easily and/or spend less processing power on graphics since there would be less pixels to process.
- [BasicECS](https://github.com/RandomGamingDev/BasicECS)
    BasicECS is a super simple and easy to use header only ECS library, perfect for whatever your needs are
- [flecs](https://github.com/SanderMertens/flecs)
    flecs is an ECS system for easily dealing with and using ECS in a monitorable and debuggable way in your own project
- [Flecs Explorer](https://github.com/flecs-hub/explorer)
    Flecs Explorer is a way to easily monitor and switch on and off or change different parts of your code that rely in flecs while the project's running
- [OBJ-Loader](https://github.com/Bly7/OBJ-Loader)
    OBJ-Loader is a simple header only obj file loader
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
