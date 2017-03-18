/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRObjectsPickerController.h
 * Author: demensdeum
 *
 * Created on March 18, 2017, 7:37 PM
 */

#ifndef BROBJECTSPICKERCONTROLLER_H
#define BROBJECTSPICKERCONTROLLER_H

#include <memory>

#include "BRObjectsPickerControllerDelegate.h"

#include <FlameSteelEngineGameToolkit/Data/FSEGTGameData.h>
#include <FlameSteelEngineGameToolkit/Input/FSEGTInputController.h>


using namespace std;

class BRObjectsPickerController {
public:
    BRObjectsPickerController();
    BRObjectsPickerController(const BRObjectsPickerController& orig);
    virtual ~BRObjectsPickerController();
    
    BRObjectsPickerControllerDelegate *delegate;
    
    void step(shared_ptr<FSEGTInputController> inputController, shared_ptr<FSEGTGameData> gameData);
    
private:

};

#endif /* BROBJECTSPICKERCONTROLLER_H */

