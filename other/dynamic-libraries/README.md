# Dynamic Libraries

> [Static Libraries](../static-libraries) explains things that I'll ignore here.

The following example will use Visual Studio:

1. `Project Properties -> C++ -> General -> Additional Include Directories` should include the folder that contains the library's header files.
2. `Project Properties -> Linker -> Input -> Additional Dependencies` should include `glfw3dll.lib`.
3. Place the `glfw3.dll` file along with your builded executable (i.e., `Projects\YourProject\Debug`) or configure another path for that.
