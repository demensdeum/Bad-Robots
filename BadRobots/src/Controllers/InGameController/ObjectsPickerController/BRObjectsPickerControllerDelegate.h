/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRObjectsPickerControllerDelegate.h
 * Author: demensdeum
 *
 * Created on March 18, 2017, 8:35 PM
 */

#ifndef BROBJECTSPICKERCONTROLLERDELEGATE_H
#define BROBJECTSPICKERCONTROLLERDELEGATE_H

#include <BadRobots/src/Const/BRConst.h>

class BRObjectsPickerController;

#include <FlameSteelEngine/FSEObject.h>

#include <memory>

using namespace std;

class BRObjectsPickerControllerDelegate {
public:
    BRObjectsPickerControllerDelegate();
    BRObjectsPickerControllerDelegate(const BRObjectsPickerControllerDelegate& orig);
    virtual ~BRObjectsPickerControllerDelegate();
    
    virtual void objectsPickerDidPickerObject(BRObjectsPickerController *pickerController, shared_ptr<FSEObject> object);
    
private:

};

#endif /* BROBJECTSPICKERCONTROLLERDELEGATE_H */

