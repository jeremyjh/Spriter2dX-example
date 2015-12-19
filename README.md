This is a very basic example project to demonstrate use of [Spriter2dX](https://github.com/jeremyjh/Spriter2dX).

This is based on (shamelessly robbed from) the example provided in [SpriterPlusPlus](https://github.com/lucidspriter/SpriterPlusPlus).

Presently Spriter2dX only supports cmake projects and has only been tested on Linux.

This repository has a lot of files due to the standard project template for Cocos2d - you may just want to take a look at the [relevant code](https://github.com/jeremyjh/Spriter2dX-example/blob/master/Classes/HelloWorldScene.cpp).

To download and build this start by cloning it and initializing its sub-repositories:

```bash
git clone https://github.com/jeremyjh/Spriter2dX-example
git submodule update --init --recursive 
```

Now we need to satisfy the expected cocos2d/ dependency.

I have not found a good way to distribute a ready-to-run Cocos2d-X project, as it includes its entire source directory and installs lots of third party binary dependencies for the development platform you are using.

So we have to do something a little bit convoluted. Suggestions welcome on this by the way.

The easiest thing is just copy the cocos2d/ folder from an existing game you have into Spriter2dX-example/, to make the example project whole. This example template was built using Cocos2d-X 3.8.1. 

If you don't already have Cocos2d installed follow the instructions for [installation](https://github.com/cocos2d/cocos2d-x) of Cocos2d-X and creating a new game  using the `cocos` utility. `cocos new MyTemplate -p com.your_company.mygame -l cpp -d Template`

Then, you can copy/move the Template/cocos2d folder into the root of Spriter2dX-example repository, to provide the cocos2d/ folder it expects to find there with all the required dependencies.

Then you can build with cmake or cocos utility (e.g. `cocos compile -s ./ -p linux`).
