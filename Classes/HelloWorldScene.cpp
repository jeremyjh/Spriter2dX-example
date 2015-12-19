#include "HelloWorldScene.h"
#include "AnimationNode.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //path to your scml in your Resources folder
    auto scml = FileUtils::getInstance()->fullPathForFilename("GreyGuy/player.scml");

    // create an array to hold instances of our character
    std::vector<SpriterEngine::EntityInstance*> instances;

    //A AnimationNode is a container which can play multiple animations sourced from a single model.
    auto spriter = Spriter2dX::AnimationNode::create(scml);

    // add more instances until there are 100
    while (instances.size()<100)
    {
        // create an instance of the entity named "Player"
        instances.push_back(spriter->createEntity("Player"));
        SpriterEngine::EntityInstance* inst = instances.back();

        if (inst)
        {
            // set the instance's animation to "walk"
            inst->setCurrentAnimation("walk");

            // set the instance's scale, position, and angle to something random
            SpriterEngine::real scale = ((rand() % 1500) + 500) / 1000.0;
            inst->setScale(SpriterEngine::point(scale, scale));

            inst->setPosition(SpriterEngine::point(rand() % int(visibleSize.width), rand() % int(visibleSize.height)));

            inst->setAngle(SpriterEngine::toRadians(rand() % 360));
        }
    }

    //createEntity gives you a SpriterEngine::EntityInstance that you can do whatever you want with
    //(refer to SpriterPlusPlus API)
    auto entity = spriter->createEntity("Player");
    entity->setCurrentAnimation("walk");

    /*
      Adding this node to a displayed layer will automatically activate its update loop.
      no further maintenance is required, use the EntityInstance to stop/start/switch
      your animations and call createEntity again to setup a new animation in the
      same layer.
    */
    this->addChild(spriter,1);
    spriter->setPosition(Vec2(origin.x,visibleSize.height));

    return true;
}

