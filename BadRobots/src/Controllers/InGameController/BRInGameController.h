/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRInGameController.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 10:30 AM
 */

#ifndef BRINGAMECONTROLLER_H
#define BRINGAMECONTROLLER_H

#include <BadRobots/src/Controllers/InGameController/ObjectsPickerController/BRObjectsPickerController.h>
#include <BadRobots/src/Controllers/InGameController/SceneRobotsController/BRSceneRobotsController.h>
#include <BadRobots/src/Controllers/InGameController/CrosshairController/BRCrosshairController.h>
#include <FlameSteelEngineGameToolkit/Controllers/FSEGTSceneController.h>

#include <memory>

using namespace std;

class BRInGameController: public FSEGTSceneController, BRObjectsPickerControllerDelegate {
public:
    BRInGameController();
    BRInGameController(const BRInGameController& orig);    
    virtual ~BRInGameController();
    
    virtual void step();
    virtual void beforeStart();
    
    virtual void objectsPickerDidPickerObject(BRObjectsPickerController *pickerController, shared_ptr<FSEObject> object);
    
private:

    shared_ptr<BRSceneRobotsController> robotsController;
    shared_ptr<BRCrosshairController> crosshairController;
    shared_ptr<BRObjectsPickerController> objectsPickerController;
    
};

#endif /* BRINGAMECONTROLLER_H */

