/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRGameOverController.h
 * Author: demensdeum
 *
 * Created on March 23, 2017, 10:17 PM
 */

#ifndef BRGAMEOVERCONTROLLER_H
#define BRGAMEOVERCONTROLLER_H

#include <FlameSteelEngineGameToolkit/Controllers/FSEGTController.h>

class BRGameOverController: public FSEGTController {
public:
    BRGameOverController();
    BRGameOverController(const BRGameOverController& orig);
    virtual ~BRGameOverController();
    
    void beforeStart();
    
    void step();
    
private:

};

#endif /* BRGAMEOVERCONTROLLER_H */

