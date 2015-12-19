This is a very basic example project to demonstrate use of [Spriter2dX](https://github.com/jeremyjh/Spriter2dX).

This is based on (shamelessly robbed from) the example provided in [SpriterPlusPlus](https://github.com/lucidspriter/SpriterPlusPlus).

Presently Spriter2dX only supports cmake projects and has only been tested on Linux.

I have not found a good way to distribute a ready-to-run Cocos2d-X project, as it
includes its entire source directory and installs lots of third party binary dependencies.

So for now, follow the instructions for [installation](https://github.com/cocos2d/cocos2d-x) of Cocos2d-X and creating a new game 
using the `cocos` utility (e.g. `cocos new MyGame -p com.your_company.mygame -l cpp -d NEW_PROJECTS_DIR`)

Then, you can copy/move the cocos2d folder (e.g. MyGame/cocos2d) into the root of this repository, to provide the cocos2d/ folder 
it expects to find there with all the required dependencies.
