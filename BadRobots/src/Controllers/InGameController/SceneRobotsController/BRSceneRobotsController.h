/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRSceneRobotsController.h
 * Author: demensdeum
 *
 * Created on March 18, 2017, 10:20 AM
 */

#ifndef BRSCENEROBOTSCONTROLLER_H
#define BRSCENEROBOTSCONTROLLER_H

#include <FlameSteelEngine/FSEController.h>
#include <FlameSteelEngine/FSEObjects.h>

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>

class BRSceneRobotsController: FSEController {
public:
    BRSceneRobotsController();
    BRSceneRobotsController(const BRSceneRobotsController& orig);
    virtual ~BRSceneRobotsController();
    
    int gameplayDifficulty;
    
    void respawnRobot(shared_ptr<FSEObject> robot);
    
    void respawnRobotsIfNeeded(shared_ptr<FSEObjects> sceneObjects);
    
    virtual void step(shared_ptr<FSEGTGameData> gameData);
    
private:

    int randomRobotRespawnX();
    
};

#endif /* BRSCENEROBOTSCONTROLLER_H */

