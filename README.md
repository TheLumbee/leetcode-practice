# What is this?

Just my attempt at leetcode questions.

## Can I use it?

GPL licensed so as long as that is met.

## How is it structured?

Each folder is the question number on leetcode. A link is in every main.cpp file.
Each question has its own *CMakeLists.txt* file so cmake is required to build.
I've tried to keep the code clean along with explaining logic when necessary.
In the *main()* function of each problem is the examples to run. All examples are tested before they are pushed.

## How do I build it?
As I said above, cmake is required so make sure that is installed.
To build, simply go to the question directory and run **./build.sh**, with an optional **release** or **debug** argument.
If neither are specified, both will be built.
The *build.sh* file may need permissions to run.
Once that is done, a release/debug folder will be created. The executable is in that folder.