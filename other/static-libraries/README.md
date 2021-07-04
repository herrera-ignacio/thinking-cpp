# Static Libraries

For our examples we'll use:

* Visual Studio
* https://www.glfw.org/ pre-compiled binaries

## Third-Party compiled binaries `.lib`

We'll be dealing with libraries as binaries. 

Follow this boilerplate steps and you'll get the dependencies running in your project:

1. Create a simple hello world solution.
2. Inside the project root folder, create a `Dependencies` folder.
3. Inside the just created `Dependencies` folder, create a folder named `GLFW` and put in there the pre-compiled binaries.
  * Include the GLFW's `include` folder which contains header files.
  * Include the latest binaries folder, in my case it was `lib-vc2019` which contains a `.lib` file that's the static libraries, and both `.dll` and `dll.lib` as dynamic library.
4. Right click on Project -> `Properties -> C/C++ -> General -> Additional Include Directories`, that would be the include directory that contains the header files.
  * You can check `All Configurations` if desired.
  * You should use a relative path: `$(SolutionDir)\Dependencies\GLFW\include`.
5. If everything is done correcty, you should be able to do `#include <GLFW/glfw3.h>`.
6. You still need to link the library to find the correct implementation.
   1. Right click on Project -> `Properties -> Linker -> Input -> AdditionalDependencies`.
   2. We want to include `glfw3.lib` static library file.
   3. You should set `Linker -> General -> Additional Library Directories` relative path to the included library directory.

## Same Solution

1. From the project that's going to import, include in `C++ -> General -> Additional Include Directories` the project from which you want to import dependencies.
2. You should be able to include header files `#include "YourHeader.h"` or `#include <Engine.h>`.
3. You still need to include the built library `.lib`, right click `Project` and then `Add -> Reference`, then select the project from which you want to import the `.lib` files. You could also set this up from `Linker` configuration, but it's not recommended.
4. You can now directly build the project and it will also build dependencies/references.
