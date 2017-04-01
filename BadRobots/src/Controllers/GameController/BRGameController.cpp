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
#include "FlameSteelEngineGameToolkit/AudioPlayer/FSEGTAudioPlayer.h"

#include <BadRobots/src/Const/BRConst.h>
#include <BadRobots/src/Controllers/MenuController/BRMenuController.h>
#include <BadRobots/src/Controllers/InGameController/BRInGameController.h>
#include <BadRobots/src/Controllers/CreditsController/BRCreditsController.h>
#include <BadRobots/src/Controllers/GameOverController/BRGameOverController.h>

#ifndef __EMSCRIPTEN__

#include <FlameSteelEngineGameToolkit/IOSystems/SDL/FSEGTIOSDLSystem.h>

#else

#include <FlameSteelEngineGameToolkitWeb/IOSystems/Web/FSEGTIOWebSystem.h>

#endif

#include <FlameSteelEngineGameToolkit/IOSystems/SDL/FSEGTIOSDLSystemParams.h>
#include <FlameSteelEngineGameToolkit/IOSystems/SDL/ResourcesLoader/FSEGTSDLResourcesLoader.h>

#include <FlameSteelEngine/FSEUtils.h>

#include <SDL/SDL_mixer.h>

#include <memory>

using namespace std;

BRGameController::BRGameController() {
    
    exitController = shared_ptr<BRExitController>(new BRExitController());
    
    gameScore = shared_ptr<BRGameScore>(new BRGameScore());
    
    // States

    auto creditsController = shared_ptr<BRCreditsController>(new BRCreditsController());
    this->setControllerForState(creditsController, BRStateCredits);
    
    auto menuController = shared_ptr<BRMenuController>(new BRMenuController());
    this->setControllerForState(menuController, BRStateMenu);
    
    auto inGameController = shared_ptr<BRInGameController>(new BRInGameController());
    this->setControllerForState(inGameController, BRStateIngame);
    inGameController->gameScore = gameScore;

    auto gameOverController = shared_ptr<BRGameOverController>(new BRGameOverController());
    this->setControllerForState(gameOverController, BRGameOver);
    gameOverController->gameScore = gameScore;
    
    // IO System

    auto ioSystemParams = shared_ptr<FSEGTIOSDLSystemParams>(new FSEGTIOSDLSystemParams());
    ioSystemParams->title = FSEUtils::localizedString(shared_ptr<string>(new string("Bad Robots")));
    ioSystemParams->width = BRGameControllerScreenWidth;
    ioSystemParams->height = BRGameControllerScreenHeight;
    
#ifndef __EMSCRIPTEN__

    auto ioSystem = shared_ptr<FSEGTIOSDLSystem>(new FSEGTIOSDLSystem());
    
#else
    
    auto ioSystem = shared_ptr<FSEGTIOWebSystem>(new FSEGTIOWebSystem());
    
#endif
    
    ioSystem->initialize(ioSystemParams);
    
    this->setIOSystem(ioSystem);
    
    exitController->setIOSystem(ioSystem);
    
    // Resources Manager
    
    resourcesLoader = shared_ptr<FSEGTSDLResourcesLoader>(new FSEGTSDLResourcesLoader());
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathSceneImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathRobotImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathCrosshairImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathDemensdeumLogoImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathFlameSteelEngineLogoImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathBadRobotsImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathGameOverImage)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFilePathEpicMusic)), resourcesManager);
    resourcesLoader->loadURL(shared_ptr<string>(new string(BRFont)), resourcesManager);
    
    // start music playing
    ioSystem->audioPlayer->play(shared_ptr<string>(new string(BRFilePathEpicMusic))); 
}

void BRGameController::controllerDidFinish(FSEGTController *controller) {
    
    if (controller->getClassIdentifier()->compare(BRCreditsControllerIdentifier) == 0) {
        
        this->switchToState(BRStateMenu);
        
    }
    else if (controller->getClassIdentifier()->compare(BRMenuControllerIdentifier) == 0) {
        
        this->switchToState(BRStateIngame);
        
    }
    else if (controller->getClassIdentifier()->compare(BRIngameControllerIdentifier) == 0) {
        
        this->switchToState(BRGameOver);
        
    }
    else if (controller->getClassIdentifier()->compare(BRGameOverControllerIdentifier) == 0) {
        
        this->switchToState(BRStateIngame);
        
    }
    else {
        
        this->switchToState(BRStateCredits);
    }
}

void BRGameController::step() {
    
    FSEGTGameController::step();
    
    exitController->step();
}

BRGameController::BRGameController(const BRGameController& orig) {
}

BRGameController::~BRGameController() {
}

