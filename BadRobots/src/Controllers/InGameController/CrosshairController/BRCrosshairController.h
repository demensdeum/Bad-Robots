/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRCrosshairController.h
 * Author: demensdeum
 *
 * Created on March 18, 2017, 6:29 PM
 */

#ifndef BRCROSSHAIRCONTROLLER_H
#define BRCROSSHAIRCONTROLLER_H

#include <FlameSteelEngine/FSEController.h>

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <FlameSteelEngineGameToolkit/Input/FSEGTInputController.h>

class BRCrosshairController: FSEController {
public:
    BRCrosshairController();
    BRCrosshairController(const BRCrosshairController& orig);
    virtual ~BRCrosshairController();
    
    void step(shared_ptr<FSEGTInputController> inputController, shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* BRCROSSHAIRCONTROLLER_H */

