/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BRConst.h
 * Author: demensdeum
 *
 * Created on March 8, 2017, 8:55 AM
 */

#ifndef BRCONST_H
#define BRCONST_H

#include <string>

using namespace std;

// states

enum BRState {
    
    BRStateCredits,
    BRStateMenu,
    BRStateIngame,
    BRGameOver
    
};

static int BRCrosshairWidth = 64;
static int BRCrosshairHeight = 64;

static int BRGameSceneTop = 250;

static int BRGameControllerScreenWidth = 720;
static int BRGameControllerScreenHeight = 405;

static int BRRobotWidth = 68;

// controllers identifiers

const string BRCreditsControllerIdentifier = "BRCreditsController";
const string BRMenuControllerIdentifier = "BRMenuController";
const string BRIngameControllerIdentifier = "BRIngameController";
const string BRGameOverControllerIdentifier = "BRGameOverController";

// object identifiers

const string BRObjectClassIdentifierRobot = "Bad Robots Robot";
const string BRObjectClassIdentifierScene = "Bad Robots Scene Background";
const string BRObjectClassIdentifierCrosshair = "Bad Robots Crosshair";
const string BRObjectClassIdentifierDemensdeumLogo = "Bad Robots Demensdeum Logo";
const string BRObjectClassIdentifierFlameSteelEngineLogo = "Bad Robots Flame Steel Engine Logo";
const string BRObjectClassIdentifierGameScore = "Bad Robots Game Score";

// file paths

const string BRFilePathDemensdeumLogoImage = "data/graphics/demensdeumLogo.png";
const string BRFilePathFlameSteelEngineLogoImage = "data/graphics/flameSteelEngineLogo.png";
const string BRFilePathBadRobotsImage = "data/graphics/badRobotsMenu.png";
const string BRFilePathGameOverImage = "data/graphics/gameOver.png";

const string BRFilePathSceneImage = "data/graphics/scene.png";
const string BRFilePathRobotImage = "data/graphics/robot.png";
const string BRFilePathCrosshairImage = "data/graphics/crosshair.png";

const string BRFilePathEpicMusic = "data/music/epic-music.ogg";

const string BRFont = "data/fonts/ChelseaMarket-Regular.ttf";

#endif /* BRCONST_H */

