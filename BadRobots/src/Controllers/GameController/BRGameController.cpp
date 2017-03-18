/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameController.cpp
 * Author: demensdeum
 * 
 * Created on March 8, 2017, 10:29 AM
 */

#include "BRGameController.h"

#include <BadRobots/src/Const/BRConst.h>
#include <BadRobots/src/Controllers/InGameController/BRInGameController.h>

#include <FlameSteelEngineGameToolkit/IOSystems/SDL/FSEGTIOSDLSystem.h>
#include <FlameSteelEngineGameToolkit/IOSystems/SDL/FSEGTIOSDLSystemParams.h>
#include <FlameSteelEngineGameToolkit/IOSystems/SDL/ResourcesLoader/FSEGTSDLResourcesLoader.h>

#include <FlameSteelEngine/FSEUtils.h>

#include <memory>

using namespace std;

BRGameController::BRGameController() {

    // Resources Manager
    
    resourcesLoader = shared_ptr<FSEGTSDLResourcesLoader>(new FSEGTSDLResourcesLoader());
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathSceneImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathRobotImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathCrosshairImage)), resourcesManager);
    
    // States

    auto inGameController = shared_ptr<BRInGameController>(new BRInGameController());
    this->setControllerForState(inGameController, BRStateIngame);

    // IO System

    auto ioSystemParams = shared_ptr<FSEGTIOSDLSystemParams>(new FSEGTIOSDLSystemParams());
    ioSystemParams->title = FSEUtils::localizedString(shared_ptr<string>(new string("Bad Robots")));
    ioSystemParams->width = BRGameControllerScreenWidth;
    ioSystemParams->height = BRGameControllerScreenHeight;
    
    auto ioSystem = shared_ptr<FSEGTIOSDLSystem>(new FSEGTIOSDLSystem());
    ioSystem->initialize(ioSystemParams);
    
    this->setIOSystem(ioSystem);
}

BRGameController::BRGameController(const BRGameController& orig) {
}

BRGameController::~BRGameController() {
}

