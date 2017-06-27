#pragma once

namespace syscalls {
	typedef char* string;
	typedef float* vector;

	typedef void (*map_t)(string eventString, string contextString, string commandString);
	// maps input event to command, in that context.  See input mapper design.doc for more details.
	extern const map_t map;

	typedef void (*echo_t)(string stringMessage);
	// sends a message to the console output
	extern const echo_t echo;

	typedef void (*echoLocalized_t)(int stringID);
	// sets the game status text from a string in the string resource.
	extern const echoLocalized_t echoLocalized;

	typedef void (*echoNum_t)(int stringMessage);
	// sends a number to the console output
	extern const echoNum_t echoNum;

	typedef void (*IMEEnable_t)(bool);
	// enables or disables IME
	extern const IMEEnable_t IMEEnable;

	typedef void (*console_t)();
	// toggles the state of the console dialog
	extern const console_t console;

	typedef void (*pause_t)(int integerState, bool checkForAllowPause);
	// with no arg, toggles pause state on/off.  otherwise, sets pause state
	extern const pause_t pause;

	typedef void (*pause2_t)(int integerState);
	// with no arg, toggles pause state on/off.  otherwise, sets pause state
	extern const pause2_t pause2;

	typedef void (*unpauseNoChecks_t)();
	// forces the game to unpause
	extern const unpauseNoChecks_t unpauseNoChecks;

	typedef void (*exit_t)(bool);
	// exits the game
	extern const exit_t exit;

	typedef void (*screenshot_t)();
	// take a screen shot
	extern const screenshot_t screenshot;

	typedef void (*hackscreenshot_t)(int);
	// take a screen shot
	extern const hackscreenshot_t hackscreenshot;

	typedef void (*res_t)(int integerXRes, int integerYRes);
	// changes screen resolution.
	extern const res_t res;

	typedef void (*resbpp_t)(int integerXRes, int integerYRes, int integerBPP);
	// changes screen resolution and bit depth.
	extern const resbpp_t resbpp;

	typedef void (*undo_t)();
	// undoes the last editing operation.
	extern const undo_t undo;

	typedef void (*redo_t)();
	// Re-does the last undone operation.
	extern const redo_t redo;

	typedef void (*alignResources_t)();
	// realigns all resources in the world to tile boundaries
	extern const alignResources_t alignResources;

	typedef void (*alignSelectedUnits_t)();
	// realigns all selected units to tile boundaries
	extern const alignSelectedUnits_t alignSelectedUnits;

	typedef void (*outputBlankLine_t)();
	// Dumps a blank line to the output.
	extern const outputBlankLine_t outputBlankLine;

	typedef void (*resourceMarket_t)(int intPlayerID, string stringResourceTo, float floatAmount, string stringResourceFrom);
	// Sends out a market use command for the given player, resource and amount.  Negative means selling.
	extern const resourceMarket_t resourceMarket;

	typedef void (*resourceTrade_t)(int intPlayerID, string stringResourceTo, float floatAmountTo, string stringResourceFrom, float resourceAmountFrom);
	// Sends out a trade resource command for the given player, resource and amount.
	extern const resourceTrade_t resourceTrade;

	typedef void (*unitData_t)(int intUnitID);
	// spews database values on the specified unit or the selected unit (if no argument).
	extern const unitData_t unitData;

	typedef void (*unitSetVariation_t)(int Variation, int UnitID);
	// Sets the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	extern const unitSetVariation_t unitSetVariation;

	typedef void (*unitIncVariation_t)(int UnitID);
	// Increments the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	extern const unitIncVariation_t unitIncVariation;

	typedef void (*unitDecVariation_t)(int);
	// Decrements the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	extern const unitDecVariation_t unitDecVariation;

	typedef void (*unitSetStanceAggressive_t)();
	// Sets the unit stance for all selected units to aggressive.
	extern const unitSetStanceAggressive_t unitSetStanceAggressive;

	typedef void (*unitSetStanceDefensive_t)();
	// Sets the unit stance for all selected units to defensive.
	extern const unitSetStanceDefensive_t unitSetStanceDefensive;

	typedef void (*unitSetStancePassive_t)();
	// Sets the unit stance for all selected units to passive.
	extern const unitSetStancePassive_t unitSetStancePassive;

	typedef void (*unitSetTactic_t)(string);
	// Sets the tactic for this unit.
	extern const unitSetTactic_t unitSetTactic;

	typedef void (*unitToggleStealth_t)();
	// Toggles stealth mode for this unit.
	extern const unitToggleStealth_t unitToggleStealth;

	typedef void (*squadMode_t)(int, int);
	// Sets the mode for a squad.
	extern const squadMode_t squadMode;

	typedef void (*setSquadMode_t)(string);
	// Sets the mode for a squad.
	extern const setSquadMode_t setSquadMode;

	typedef void (*squadWheel_t)(float angle, int squadID);
	// Wheels the squad.
	extern const squadWheel_t squadWheel;

	typedef void (*unitTownBell_t)();
	// Issues a town bell for the selected unit(s).
	extern const unitTownBell_t unitTownBell;

	typedef void (*unitReturnToWork_t)();
	// Issues a return to work for the selected unit(s).
	extern const unitReturnToWork_t unitReturnToWork;

	typedef void (*obscuredUnitToggle_t)();
	// Toggles between different ways obscured units are shown.
	extern const obscuredUnitToggle_t obscuredUnitToggle;

	typedef void (*configDump_t)(string);
	// sends to output a list of all current config vars
	extern const configDump_t configDump;

	typedef void (*configSet_t)(string stringName, string stringValue);
	// sets a particular config var to a string value
	extern const configSet_t configSet;

	typedef void (*configSetInt_t)(string stringName, int integerValue);
	// sets a config var to an integer value
	extern const configSetInt_t configSetInt;

	typedef void (*configSetFloat_t)(string stringName, float floatValue);
	// sets a config var to a floating point value
	extern const configSetFloat_t configSetFloat;

	typedef void (*configDef_t)(string stringName);
	// defines a config variable
	extern const configDef_t configDef;

	typedef void (*configUndef_t)(string stringName);
	// un-defines a config variable
	extern const configUndef_t configUndef;

	typedef void (*configToggle_t)(string stringName);
	// defined var becomes undefined, and vice versa
	extern const configToggle_t configToggle;

	typedef void (*config_t)(string stringToken);
	// changes config state just like a .cfg line
	extern const config_t config;

	typedef void (*configGetByID_t)(int intValue);
	// look up config by enum ID
	extern const configGetByID_t configGetByID;

	typedef void (*configHelp_t)(string symbolFilter);
	// show all formally defined config variables that contain the filter string, or use no parameters for a full list.
	extern const configHelp_t configHelp;

	typedef void (*configHelpPrefix_t)(string symbolFilter);
	// show all formally defined config variables that start with the filter string, or use no parameters for a full list.
	extern const configHelpPrefix_t configHelpPrefix;

	typedef void (*saveGame_t)(string stringFilename);
	// saves out a game in progress.
	extern const saveGame_t saveGame;

	typedef void (*saveScenario_t)(string stringFilename);
	// saves out a scenario file.
	extern const saveScenario_t saveScenario;

	typedef void (*loadGame_t)(string stringFilename);
	// loads in a saved game.
	extern const loadGame_t loadGame;

	typedef void (*loadScenario_t)(string stringFilename);
	// loads in a scenario file.
	extern const loadScenario_t loadScenario;

	typedef void (*loadTutorial_t)(string stringFilename, int loadMode, string loadImage, int textID, bool isAge3Scenario);
	// loads in a tutorial scenario file.
	extern const loadTutorial_t loadTutorial;

	typedef void (*loadCampaignScenario_t)(string stringFilename);
	// loads in a campaign scenario file.
	extern const loadCampaignScenario_t loadCampaignScenario;

	typedef void (*loadRecentFile_t)(string stringFilename);
	// loads the file named, interpreting whether it is a scenario, savegame, etc. dynamically
	extern const loadRecentFile_t loadRecentFile;

	typedef void (*saveCamera_t)(string stringFilename);
	// save camera to file.
	extern const saveCamera_t saveCamera;

	typedef void (*saveCurrentHomeCityCamera_t)();
	// save camera to file.
	extern const saveCurrentHomeCityCamera_t saveCurrentHomeCityCamera;

	typedef void (*saveCurrentHomeCityWidescreenCamera_t)();
	// save widescreen camera to file.
	extern const saveCurrentHomeCityWidescreenCamera_t saveCurrentHomeCityWidescreenCamera;

	typedef void (*loadCamera_t)(string stringFilename);
	// load camera from file.
	extern const loadCamera_t loadCamera;

	typedef void (*restart_t)();
	// re-launch current scenario.
	extern const restart_t restart;

	typedef void (*terrainFilter_t)();
	// filters the entire terrain.
	extern const terrainFilter_t terrainFilter;

	typedef void (*terrainFilterArea_t)(int integerX1, int integerY1, int integerX2, int integerY2);
	// filters a sub-area of the terrain.
	extern const terrainFilterArea_t terrainFilterArea;

	typedef void (*terrainFlatten_t)(float);
	// flattens the entire terrain.
	extern const terrainFlatten_t terrainFlatten;

	typedef void (*terrainFlattenArea_t)(int integerX1, int integerY1, int integerX2, int integerY2);
	// flattens a sub-area of the terrain.
	extern const terrainFlattenArea_t terrainFlattenArea;

	typedef void (*terrainSetType_t)(int integerType);
	// sets the terrain type to paint.
	extern const terrainSetType_t terrainSetType;

	typedef void (*terrainSetSubtype_t)(int integerType);
	// sets the terrain subtype to paint.
	extern const terrainSetSubtype_t terrainSetSubtype;

	typedef void (*terrainSetMix_t)(int integerType);
	// sets the terrain mix to paint.
	extern const terrainSetMix_t terrainSetMix;

	typedef void (*terrainPaint_t)(string);
	// paint whole terrain with given texture.
	extern const terrainPaint_t terrainPaint;

	typedef void (*terrainPaintMix_t)(string);
	// paint whole terrain with given mix.
	extern const terrainPaintMix_t terrainPaintMix;

	typedef void (*terrainAmbient_t)(int integerR, int integerG, int integerB);
	// Set terrain ambient reflectivity to the given RGB (0-255)
	extern const terrainAmbient_t terrainAmbient;

	typedef void (*terrainGetAmbient_t)();
	// Get terrain ambient reflectivity
	extern const terrainGetAmbient_t terrainGetAmbient;

	typedef void (*terrainAdjustGlobalHeight_t)(float meters);
	// adjusts (raise/lower) the terrain height by the specified meters.
	extern const terrainAdjustGlobalHeight_t terrainAdjustGlobalHeight;

	typedef void (*cameraRotate_t)(int integerState);
	// sets whether camera limiting is on.
	extern const cameraRotate_t cameraRotate;

	typedef void (*cameraNice_t)();
	// puts the camera in a reasonable orientation.
	extern const cameraNice_t cameraNice;

	typedef void (*cameraForward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera forward key has gone up or down.
	extern const cameraForward_t cameraForward;

	typedef void (*cameraWorldForward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera world forward key has gone up or down.
	extern const cameraWorldForward_t cameraWorldForward;

	typedef void (*cameraWorldForwardLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera world forward & left key has gone up or down.
	extern const cameraWorldForwardLeft_t cameraWorldForwardLeft;

	typedef void (*cameraWorldForwardRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera world forward & right key has gone up or down.
	extern const cameraWorldForwardRight_t cameraWorldForwardRight;

	typedef void (*cameraBackward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera backward key has gone up or down.
	extern const cameraBackward_t cameraBackward;

	typedef void (*cameraWorldBackward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera world backward key has gone up or down.
	extern const cameraWorldBackward_t cameraWorldBackward;

	typedef void (*cameraWorldBackwardLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera world backward & left key has gone up or down.
	extern const cameraWorldBackwardLeft_t cameraWorldBackwardLeft;

	typedef void (*cameraWorldBackwardRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera world backward & right key has gone up or down.
	extern const cameraWorldBackwardRight_t cameraWorldBackwardRight;

	typedef void (*cameraRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera right key has gone up or down.
	extern const cameraRight_t cameraRight;

	typedef void (*cameraLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera left key has gone up or down.
	extern const cameraLeft_t cameraLeft;

	typedef void (*cameraUp_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera up key has gone up or down.
	extern const cameraUp_t cameraUp;

	typedef void (*cameraDown_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera down key has gone up or down.
	extern const cameraDown_t cameraDown;

	typedef void (*cameraPitchForward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera pitch forward key has gone up or down.
	extern const cameraPitchForward_t cameraPitchForward;

	typedef void (*cameraPitchBackward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera pitch backward key has gone up or down.
	extern const cameraPitchBackward_t cameraPitchBackward;

	typedef void (*cameraRollLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera roll left key has gone up or down.
	extern const cameraRollLeft_t cameraRollLeft;

	typedef void (*cameraRollRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera roll right key has gone up or down.
	extern const cameraRollRight_t cameraRollRight;

	typedef void (*cameraYawRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera yaw right key has gone up or down.
	extern const cameraYawRight_t cameraYawRight;

	typedef void (*cameraYawLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera yaw left key has gone up or down.
	extern const cameraYawLeft_t cameraYawLeft;

	typedef void (*cameraLocalYawRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera 'Local Yaw right' key has gone up or down.
	extern const cameraLocalYawRight_t cameraLocalYawRight;

	typedef void (*cameraLocalYawLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that camera 'Local Yaw left' key has gone up or down.
	extern const cameraLocalYawLeft_t cameraLocalYawLeft;

	typedef void (*cameraDump_t)();
	// debug command to spew info about the current state of the game camera
	extern const cameraDump_t cameraDump;

	typedef void (*trackLoad_t)(string stringFilename);
	// loads a camera track and makes it current
	extern const trackLoad_t trackLoad;

	typedef void (*trackSave_t)(string stringFilename);
	// saves the current camera track
	extern const trackSave_t trackSave;

	typedef void (*trackClear_t)();
	// clears all tracks.
	extern const trackClear_t trackClear;

	typedef void (*trackStepForward_t)();
	// steps the current camera track 1 step forward.
	extern const trackStepForward_t trackStepForward;

	typedef void (*trackStepBackward_t)();
	// steps the current camera track 1 step backward.
	extern const trackStepBackward_t trackStepBackward;

	typedef void (*trackToggleShow_t)();
	// toggles rendering of the camera track on and off.
	extern const trackToggleShow_t trackToggleShow;

	typedef void (*trackAddWaypoint_t)();
	// adds the camera's current position and orientation to the current camera track.
	extern const trackAddWaypoint_t trackAddWaypoint;

	typedef void (*trackEditWaypoint_t)();
	// edits the currently selected camera track.
	extern const trackEditWaypoint_t trackEditWaypoint;

	typedef void (*trackSetSelectedWaypoint_t)(int index);
	// sets the current waypoint to the button with the same index.
	extern const trackSetSelectedWaypoint_t trackSetSelectedWaypoint;

	typedef void (*trackGotoSelectedWaypoint_t)(int index);
	// moves the camera to the current waypoint.
	extern const trackGotoSelectedWaypoint_t trackGotoSelectedWaypoint;

	typedef void (*trackRemoveWaypoint_t)();
	// removes the most recently added track waypoint from the current camera track.
	extern const trackRemoveWaypoint_t trackRemoveWaypoint;

	typedef void (*trackInsert_t)();
	// adds a new camera track.
	extern const trackInsert_t trackInsert;

	typedef void (*trackRemove_t)();
	// removes selected track.
	extern const trackRemove_t trackRemove;

	typedef void (*trackPlay_t)(float duration, int eventID);
	// plays a track file (otherwise if "none" than plays the current track.) with no arg uses current duration, otherwise sets duration
	extern const trackPlay_t trackPlay;

	typedef void (*trackPause_t)();
	// pauses the current camera track.
	extern const trackPause_t trackPause;

	typedef void (*trackStop_t)();
	// stops the current camera track.
	extern const trackStop_t trackStop;

	typedef void (*trackAdvance_t)(float);
	// advances the camera track to a specific location.
	extern const trackAdvance_t trackAdvance;

	typedef void (*trackGotoSelectedEvent_t)(int index);
	// moves the camera to the current event.
	extern const trackGotoSelectedEvent_t trackGotoSelectedEvent;

	typedef void (*areaIncrementAreaToRender_t)(int playerID);
	// increments the area to render.
	extern const areaIncrementAreaToRender_t areaIncrementAreaToRender;

	typedef void (*toggleShadows_t)();
	// toggle shadows on/off
	extern const toggleShadows_t toggleShadows;

	typedef void (*setShadowQuality_t)(int qualityLevel);
	// set the quality level of shadows
	extern const setShadowQuality_t setShadowQuality;

	typedef void (*setShadowBiasMul_t)(float biasMultiplier);
	// set the shadow buffer bias multipler (supaScreenshot only)
	extern const setShadowBiasMul_t setShadowBiasMul;

	typedef void (*setShadowSnapping_t)(int);
	// controls shadow matrix snapping
	extern const setShadowSnapping_t setShadowSnapping;

	typedef void (*setShadowRotationOp_t)(int);
	// controls shadow projection rotation optimization
	extern const setShadowRotationOp_t setShadowRotationOp;

	typedef void (*renderWindow_t)(int integerState);
	// with no arg, toggles window/fullscreen.  otherwise, sets mode to window(1)/fullscreen(0)
	extern const renderWindow_t renderWindow;

	typedef void (*renderRefresh_t)(int integerState);
	// with no arg, changes refresh rate to 75hz in fullscreen.  otherwise, sets fullscreen refresh to value
	extern const renderRefresh_t renderRefresh;

	typedef void (*renderBaseID_t)(int playerID, int areaID, int integerState);
	// sets the render state of the given base (no integerState toggles).
	extern const renderBaseID_t renderBaseID;

	typedef void (*renderAreas_t)(int playerID, int integerState);
	// sets the render state for all areas (no arg toggles).
	extern const renderAreas_t renderAreas;

	typedef void (*renderAreaDangerLevels_t)(int playerID, int state);
	// draws areas and color-codes them by danger level.
	extern const renderAreaDangerLevels_t renderAreaDangerLevels;

	typedef void (*renderAreaID_t)(int playerID, int areaID, int integerState);
	// sets the render state of the given area (no integerState toggles).
	extern const renderAreaID_t renderAreaID;

	typedef void (*renderAreaGroupID_t)(int playerID, int areaGroupID, int integerState);
	// sets the render state of the given area (no integerState toggles).
	extern const renderAreaGroupID_t renderAreaGroupID;

	typedef void (*renderAnisotropic_t)(int integerState);
	// sets desired anisotropy
	extern const renderAnisotropic_t renderAnisotropic;

	typedef void (*setHDRMultisampleFactor_t)(int);
	// sets HDR multisample factor [1,8] - 1 is disabled
	extern const setHDRMultisampleFactor_t setHDRMultisampleFactor;

	typedef void (*setSuperSampleFactors_t)(float floatX, float floatY);
	// sets HDR supersampling factors (1.0 to 2.0, both 1.0 is off)
	extern const setSuperSampleFactors_t setSuperSampleFactors;

	typedef void (*setSuperSampleFilterScales_t)(float floatX, float floatY);
	// sets supersample kernel scales(1.0 = normal, less = blurrier, higher = sharper)
	extern const setSuperSampleFilterScales_t setSuperSampleFilterScales;

	typedef void (*setSuperSampleFilterIndex_t)(int);
	// sets supersample filter kernel
	extern const setSuperSampleFilterIndex_t setSuperSampleFilterIndex;

	typedef void (*renderTrilinear_t)(int integerState);
	// sets trilinear filtering on/off
	extern const renderTrilinear_t renderTrilinear;

	typedef void (*renderFriendOrFoe_t)(int integerState);
	// with no arg, toggles friend or foe colors.  otherwise, sets it
	extern const renderFriendOrFoe_t renderFriendOrFoe;

	typedef void (*ambientColor_t)(int integerR, int integerG, int integerB);
	// Set ambient color to given RGB (0-255)
	extern const ambientColor_t ambientColor;

	typedef void (*ambientGetColor_t)();
	// Get ambient color
	extern const ambientGetColor_t ambientGetColor;

	typedef void (*resetAmbientColor_t)();
	// reset the sun color to full
	extern const resetAmbientColor_t resetAmbientColor;

	typedef void (*ambientColor2_t)(int integerR, int integerG, int integerB);
	// Set ambient color 2 to given RGB (0-255)
	extern const ambientColor2_t ambientColor2;

	typedef void (*shadowDarkness_t)(float integerDarkness, float pcfFilterScalar, float biasNV, float biasATI, float slope);
	// Set shadow darkness (0-255) - (PCF Filter Sclar 0-16)
	extern const shadowDarkness_t shadowDarkness;

	typedef void (*sunColor_t)(int integerR, int integerG, int integerB);
	// Set sun color to given RGB (0-255)
	extern const sunColor_t sunColor;

	typedef void (*sunGetColor_t)();
	// Get sun color
	extern const sunGetColor_t sunGetColor;

	typedef void (*resetSunColor_t)();
	// reset the sun color to full
	extern const resetSunColor_t resetSunColor;

	typedef void (*fakeSunParams_t)(float intensity, float specIntensity, float specPower, float inclination, float rotation);
	// Set fake sun params for water
	extern const fakeSunParams_t fakeSunParams;

	typedef void (*setHemiLight_t)(float topColorR, float topColorG, float topColorB, float bottomColorR, float bottomColorG, float bottomColorB, float axisYaw, float axisPitch, float intensity, float unitIntensity, float terrainIntensity);
	// sets a hemilight
	extern const setHemiLight_t setHemiLight;

	typedef void (*setSceneLightParams_t)(float sunIntensity, float power, float specIntensity, float metalness, float fogColorR, float fogColorG, float fogColorB, float fogDensity, float fogStart);
	// sets scene light params
	extern const setSceneLightParams_t setSceneLightParams;

	typedef void (*setFogParams_t)(float planarfogColorR, float planarfogColorG, float planarfogColorB, float planarfogDensity, float planarfogHeight);
	// set Planar Height Params
	extern const setFogParams_t setFogParams;

	typedef void (*setBumpScale_t)(float scale);
	// sets scene bump scale
	extern const setBumpScale_t setBumpScale;

	typedef void (*unitPlayerFakify_t)(int fakePlayerIndex);
	// sets the selected units to use the fake player indicated.
	extern const unitPlayerFakify_t unitPlayerFakify;

	typedef void (*unitPlayerDefakify_t)();
	// sets the selected units to stop using a fake player.
	extern const unitPlayerDefakify_t unitPlayerDefakify;

	typedef void (*setToneMapParams_t)(float exposure, float dispGamma, float greyFStops, float kneeLow, float kneeHigh, float ditherNoiseInten);
	// sets tonemap params
	extern const setToneMapParams_t setToneMapParams;

	typedef void (*setBloomParams_t)(float bloomThreshold, float bloomColorR, float bloomColorG, float bloomColorB, float bloomIntensity, float bloomPass, float bloomSigma);
	// sets tonemap params
	extern const setBloomParams_t setBloomParams;

	typedef void (*setLDRBloomParams_t)(float bloomColorR, float bloomColorG, float bloomColorB, float bloomIntensity, float bloomSigma);
	// sets LDR Bloom params
	extern const setLDRBloomParams_t setLDRBloomParams;

	typedef void (*setBloomStreakParams_t)(float streakCount, float Passes, float ElementOffset, float Exposure, float Intensity, float Falloff, float streakRed, float streakGreen, float streakBlue, float threshold);
	// sets bloom streak params
	extern const setBloomStreakParams_t setBloomStreakParams;

	typedef void (*setBloomFeedbackParams_t)(float currentFrameContribution, float lastFrameContribution);
	// sets bloom feedback params
	extern const setBloomFeedbackParams_t setBloomFeedbackParams;

	typedef void (*setTerrainLightingParams_t)(float bumpScale, float specularPower, float specularIntensity, float terrainMetalness);
	// sets Terrain Lighting Params
	extern const setTerrainLightingParams_t setTerrainLightingParams;

	typedef void (*applyLightingSet_t)(string name);
	// Applies a Lighting set
	extern const applyLightingSet_t applyLightingSet;

	typedef void (*saveLightingSet_t)(string name);
	// Saves the current status of lighting values as a set
	extern const saveLightingSet_t saveLightingSet;

	typedef void (*loadLightingSet_t)(string name, bool apply);
	// loads the specified lighting set
	extern const loadLightingSet_t loadLightingSet;

	typedef void (*brushSize_t)(int integerSize);
	// sets brush size.
	extern const brushSize_t brushSize;

	typedef void (*brushCircularSize_t)(float floatValue);
	// sets the circular brush size
	extern const brushCircularSize_t brushCircularSize;

	typedef void (*musicStop_t)();
	// stop playing music
	extern const musicStop_t musicStop;

	typedef void (*musicSetVolume_t)(float);
	// set the current music volume (0.0f-1.0f)
	extern const musicSetVolume_t musicSetVolume;

	typedef void (*musicPlaySong_t)(string songname, float fadetime);
	// play a sound as if it were a music track
	extern const musicPlaySong_t musicPlaySong;

	typedef void (*musicToggleBattleMode_t)();
	// toggles between battle mode and normal mode
	extern const musicToggleBattleMode_t musicToggleBattleMode;

	typedef void (*displayType_t)(int integerState);
	// with no arg, cycles through the various status display modes.  otherwise sets display type
	extern const displayType_t displayType;

	typedef void (*display_t)(int integerState);
	// with no arg, toggles display on/off.  otherwise, sets display
	extern const display_t display;

	typedef void (*player_t)(int integerPlayer);
	// with no arg, outputs current player.  otherwise, sets current player to given argument
	extern const player_t player;

	typedef void (*fog_t)(int integerState);
	// toggles or sets LOS fog.
	extern const fog_t fog;

	typedef void (*blackmap_t)(int integerState);
	// toggles or sets unexplored black map rendering.
	extern const blackmap_t blackmap;

	typedef void (*modeEnter_t)(string stringMode);
	// enters the named mode.
	extern const modeEnter_t modeEnter;

	typedef void (*startCampaign_t)(string campaignName);
	// starts the given campaign.
	extern const startCampaign_t startCampaign;

	typedef void (*uiEnterGameMenuModeIfNotResigned_t)();
	// Wrapper that enters GameMenu mode if the player isn't resigned.
	extern const uiEnterGameMenuModeIfNotResigned_t uiEnterGameMenuModeIfNotResigned;

	typedef void (*modeToggleBetweenIfNotMP_t)(string stringMode1, string stringMode2);
	// toggles between the two modes only if we're not in a BMultiplayer game.
	extern const modeToggleBetweenIfNotMP_t modeToggleBetweenIfNotMP;

	typedef void (*helpPrefix_t)(string commandPrefix);
	// Lists all of the commands that start with the given prefix
	extern const helpPrefix_t helpPrefix;

	typedef void (*help_t)(string commandSubstring);
	// Lists all of the commands that contain the given substring
	extern const help_t help;

	typedef void (*helpText_t)(string helptextSubstring);
	// Lists all of the commands that contain the given substring in their help text.
	extern const helpText_t helpText;

	typedef void (*lookAt_t)(float x, float z);
	// looks at given x,z location on terrain.
	extern const lookAt_t lookAt;

	typedef void (*lookAtArmy_t)(int playerID, string armyName);
	// looks at given kb army.
	extern const lookAtArmy_t lookAtArmy;

	typedef void (*resetDefaultPlayerColors_t)();
	// reloads the player colors from the XML file
	extern const resetDefaultPlayerColors_t resetDefaultPlayerColors;

	typedef void (*setMinimapUnitFilter_t)(int);
	// sets the minimap filter for units
	extern const setMinimapUnitFilter_t setMinimapUnitFilter;

	typedef void (*setGraphicDetail_t)(int detailLevel);
	// Sets the graphic detail.  (0 = HIGH, 1 = MEDIUM, 2 = LOW)
	extern const setGraphicDetail_t setGraphicDetail;

	typedef void (*setWorldDifficulty_t)(int v);
	// Sets the world difficulty level.
	extern const setWorldDifficulty_t setWorldDifficulty;

	typedef void (*startAutoPatcher_t)(bool manualMode);
	// Start the auto patcher.
	extern const startAutoPatcher_t startAutoPatcher;

	typedef void (*cancelAutoPatcher_t)();
	// Cancel the auto patcher.
	extern const cancelAutoPatcher_t cancelAutoPatcher;

	typedef void (*confirmAutoPatcher_t)();
	// Used to tell autpatcher user pressed OK on exit or error dialog.
	extern const confirmAutoPatcher_t confirmAutoPatcher;

	typedef void (*playMovie_t)(string);
	// Plays movies from a playlist in the AVI directory
	extern const playMovie_t playMovie;

	typedef void (*toggleHomeCityView_t)();
	// Toggles home city view for the current player.
	extern const toggleHomeCityView_t toggleHomeCityView;

	typedef void (*toggleHomeCityViewTech_t)();
	// Toggles tech home city view for the current player.
	extern const toggleHomeCityViewTech_t toggleHomeCityViewTech;

	typedef void (*lookAtHomeCityBuilding_t)(int building);
	// View the specific home city building.
	extern const lookAtHomeCityBuilding_t lookAtHomeCityBuilding;

	typedef void (*homeCityTrain_t)(int playerID, int buildingID, int puid);
	// Trains the given PUID from the given home city building.
	extern const homeCityTrain_t homeCityTrain;

	typedef void (*homeCityTrain2_t)(int playerID, int cardIndex);
	// Sends the given HC card in the home city.
	extern const homeCityTrain2_t homeCityTrain2;

	typedef void (*homeCityTransport_t)(int playerID);
	// Transports units from the home city.
	extern const homeCityTransport_t homeCityTransport;

	typedef void (*fourOfAKind_t)();
	// starts the four of a kind victory if valid.
	extern const fourOfAKind_t fourOfAKind;

	typedef void (*relicCapture_t)();
	// starts the Relic Capture victory if valid.
	extern const relicCapture_t relicCapture;

	typedef void (*kothVictory_t)();
	// starts the King of the Hill victory if valid.
	extern const kothVictory_t kothVictory;

	typedef void (*tradeRouteCommand_t)(int playerID, int tradeRoutUnit, int commandID);
	// Adds the given command to the trade post bucket.
	extern const tradeRouteCommand_t tradeRouteCommand;

	typedef void (*tradeRouteTrain_t)(int playerID, int tradeRoutUnit, int puid);
	// Trains the given PUID from the given trade post on the trade route.
	extern const tradeRouteTrain_t tradeRouteTrain;

	typedef void (*commandResearch_t)(int commandID, int unitID, int, int);
	// Researches the given command from the given unit.
	extern const commandResearch_t commandResearch;

	typedef void (*mercTrain_t)(int playerID, int buildingID, int puid);
	// Trains the given merc from the given home city building.
	extern const mercTrain_t mercTrain;

	typedef void (*homeCityShipEject_t)(int playerID, int buildingID, int puid, int index);
	// Cancels the given unit out of the ship.
	extern const homeCityShipEject_t homeCityShipEject;

	typedef void (*loadGrouping_t)(string groupingName);
	// Loads a grouping.  No parameter pops up dialog.
	extern const loadGrouping_t loadGrouping;

	typedef void (*loadUserDefinedGrouping_t)(string groupingName);
	// Loads a grouping from the user writable grouping directory.
	extern const loadUserDefinedGrouping_t loadUserDefinedGrouping;

	typedef void (*loadGroupingUnicode_t)(string);
	// For UI use only.
	extern const loadGroupingUnicode_t loadGroupingUnicode;

	typedef void (*loadGroupingUnicodeLUA_t)(int, string);
	// For UI use only.
	extern const loadGroupingUnicodeLUA_t loadGroupingUnicodeLUA;

	typedef void (*repairUnit_t)(int unitID);
	// Starts the auto repair on the specified unit.
	extern const repairUnit_t repairUnit;

	typedef void (*cancelRepairUnit_t)(int unitID);
	// Cancels the auto repair on the specified unit.
	extern const cancelRepairUnit_t cancelRepairUnit;

	typedef void (*setHomeCityGatherUnit_t)(int unitID);
	// Sets the home city gather point to the specified unit.
	extern const setHomeCityGatherUnit_t setHomeCityGatherUnit;

	typedef void (*convertCoveredWagon_t)();
	// Convert a covered wagon into a Town Center
	extern const convertCoveredWagon_t convertCoveredWagon;

	typedef void (*breakTreaty_t)();
	// break your treaties
	extern const breakTreaty_t breakTreaty;

	typedef void (*ransomExplorer_t)();
	// ransoms your explorer
	extern const ransomExplorer_t ransomExplorer;

	typedef void (*toggleWorldTooltipClipRect_t)();
	// Toggles whether or not world tooltips are using the restricted screen rectangle.
	extern const toggleWorldTooltipClipRect_t toggleWorldTooltipClipRect;

	typedef void (*drawWorldTooltipClipRect_t)();
	// Toggles whether or not to draw the world tooltip restricted screen rectangle.
	extern const drawWorldTooltipClipRect_t drawWorldTooltipClipRect;

	typedef void (*setWorldTooltipRectDims1024_t)(int minX, int minY, int maxX, int maxY);
	// Sets the world tooltip restricted screen rectangle to the given dimensions relative to 1024x768 resolution.
	extern const setWorldTooltipRectDims1024_t setWorldTooltipRectDims1024;

	typedef void (*upgradeTradeRoute_t)(int unitID);
	// UI use - upgrade the trade route associated with this unit.
	extern const upgradeTradeRoute_t upgradeTradeRoute;

	typedef void (*spawnUnits_t)(string protoname, int count, int unitID);
	// Spawn Units from the UnitID building.
	extern const spawnUnits_t spawnUnits;

	typedef void (*ability_t)(int abilityId, int unitID, bool doWhenNotSelected);
	// Explorer Abilities use.
	extern const ability_t ability;

	typedef void (*doAbilityInType_t)(string protoPowerName, string);
	// use ability in proto unit type if the player has one
	extern const doAbilityInType_t doAbilityInType;

	typedef void (*doAbilityInSelected_t)(string protoPowerName);
	// use ability in current unit selection.
	extern const doAbilityInSelected_t doAbilityInSelected;

	typedef void (*doCommandInSelected_t)(string);
	// use command in current unit selection.
	extern const doCommandInSelected_t doCommandInSelected;

	typedef void (*specialPower_t)(int playerID, int powerEntryIndex, int powerID);
	// Special power use.
	extern const specialPower_t specialPower;

	typedef void (*vsync_t)(int state);
	// Set vertical syncing (-1 toggles, 0 is off, 1 is on).
	extern const vsync_t vsync;

	typedef void (*startMoviePlayback_t)(string filename, int sizing, float fadeIn, float fadeOut);
	// Start fullscreen playback of a movie.
	extern const startMoviePlayback_t startMoviePlayback;

	typedef void (*trainReinforcement_t)(int armyID);
	// Trains a reinforcement.
	extern const trainReinforcement_t trainReinforcement;

	typedef void (*cancelTrainReinforcement_t)(int armyID);
	// Cancel training of a reinforcement.
	extern const cancelTrainReinforcement_t cancelTrainReinforcement;

	typedef void (*setDropDefaultMips_t)(int num);
	// Set mip levels to skip for default category textures.
	extern const setDropDefaultMips_t setDropDefaultMips;

	typedef void (*setDropTerrainMips_t)(int num);
	// Set mip levels to skip for terrain category textures.
	extern const setDropTerrainMips_t setDropTerrainMips;

	typedef void (*showSPCNote_t)(string title, string text);
	// Display's the SPC Note Dialog with the specified title and text.
	extern const showSPCNote_t showSPCNote;

	typedef void (*renderForceReset_t)();
	// forces the renderer to reset.
	extern const renderForceReset_t renderForceReset;

	typedef void (*editorSetTechStatus_t)(string techToActivate, bool active);
	// Editor only function that activates/deactivates a given tech
	extern const editorSetTechStatus_t editorSetTechStatus;

	typedef void (*editorUpdateUnitVisuals_t)();
	// Editor only functions. goes thru all the units and updates thier visuals.
	extern const editorUpdateUnitVisuals_t editorUpdateUnitVisuals;

	typedef void (*editorSetAllTradeRoutesToDef_t)(string newDefName);
	// Editor use - sets all trade route definitons to the spedified definition.
	extern const editorSetAllTradeRoutesToDef_t editorSetAllTradeRoutesToDef;

	typedef void (*researchByID_t)(int TechID, int ResearchingUnitID, int Player, bool);
	// Start the research of TechID from ResearchingUnitID for the current player (if no player is specified)
	extern const researchByID_t researchByID;

	typedef void (*researchTechInSelected_t)(string techName);
	// research a tech in current unit selection.
	extern const researchTechInSelected_t researchTechInSelected;

	typedef void (*trainByID_t)(int ProtoUnitID, int TrainingUnitID, int Player);
	// Start the training of a unit of ProtoUnitID from TrainingUnitID for the current player (if no player is specified)
	extern const trainByID_t trainByID;

	typedef void (*trainInSelected_t)(string stringProtoName, int traincount);
	// tries to train the selected unit type in any valid selected unit
	extern const trainInSelected_t trainInSelected;

	typedef void (*cancelTrainInSelected_t)(int ProtoUnitID, bool All);
	// cancel training of a unit type in any valid selected unit
	extern const cancelTrainInSelected_t cancelTrainInSelected;

	typedef void (*cancelResearchInSelected_t)(int TechID);
	// cancel researching of a tech in any valid selected unit
	extern const cancelResearchInSelected_t cancelResearchInSelected;

	typedef void (*tis_t)(string stringProtoName, int traincount);
	// just like train in selected, but more abbreviated
	extern const tis_t tis;

	typedef void (*trainInSelectedByID_t)(int protoID, int traincount);
	// just like train in selected, but fastAr because it takes a protoID
	extern const trainInSelectedByID_t trainInSelectedByID;

	typedef void (*click_t)();
	// plays the default UI click sound.
	extern const click_t click;

	typedef void (*homeCityResearch_t)(int playerID, string techName);
	// Researches the given home city tech.
	extern const homeCityResearch_t homeCityResearch;

	typedef void (*homeCityResearchByID_t)(int playerID, int techName);
	// Researches the given home city tech.
	extern const homeCityResearchByID_t homeCityResearchByID;

	typedef void (*homeCityMakeActiveByID_t)(int playerID, int techName);
	// Activates the given home city tech.
	extern const homeCityMakeActiveByID_t homeCityMakeActiveByID;

	typedef void (*homeCityResearchByIDOutsideGame_t)(int playerID, int techName);
	// Researches the given home city tech when a game is not active.
	extern const homeCityResearchByIDOutsideGame_t homeCityResearchByIDOutsideGame;

	typedef void (*homeCityResearchByIDPregame_t)(int techID);
	// Researches the given home city tech when you are *really* completely out side of the game.
	extern const homeCityResearchByIDPregame_t homeCityResearchByIDPregame;

	typedef void (*editMode_t)(string symbolModeName);
	// changes the edit mode
	extern const editMode_t editMode;

	typedef void (*uiBuildAtPointer_t)();
	// instructs the currently selected unit(s) to build the current proto unit cursor building type at the pointer location.
	extern const uiBuildAtPointer_t uiBuildAtPointer;

	typedef void (*uiFormationOrientation_t)();
	// Sets the orientation of a formation.
	extern const uiFormationOrientation_t uiFormationOrientation;

	typedef void (*uiBuildWallAtPointer_t)(bool);
	// instructs the currently selected unit(s) to build the current proto unit cursor building type at the pointer location, with wall-like endpoint behavior.
	extern const uiBuildWallAtPointer_t uiBuildWallAtPointer;

	typedef void (*uiCreateRiverToggleWaypointMode_t)();
	// .
	extern const uiCreateRiverToggleWaypointMode_t uiCreateRiverToggleWaypointMode;

	typedef void (*uiPlaceRiverWaypoint_t)();
	// .
	extern const uiPlaceRiverWaypoint_t uiPlaceRiverWaypoint;

	typedef void (*uiRemoveRiverWaypoint_t)();
	// .
	extern const uiRemoveRiverWaypoint_t uiRemoveRiverWaypoint;

	typedef void (*uiCreateRiver_t)();
	// .
	extern const uiCreateRiver_t uiCreateRiver;

	typedef void (*uiCreateRandomRiver_t)();
	// .
	extern const uiCreateRandomRiver_t uiCreateRandomRiver;

	typedef void (*uiPlaceRiverShallow_t)();
	// .
	extern const uiPlaceRiverShallow_t uiPlaceRiverShallow;

	typedef void (*uiRemoveRiverShallow_t)();
	// .
	extern const uiRemoveRiverShallow_t uiRemoveRiverShallow;

	typedef void (*uiWheelRotateRiverShallow_t)(int);
	// intended for ui use only.  Rotate river shallow with wheel -- i.e. intended to be mapped to wheel
	extern const uiWheelRotateRiverShallow_t uiWheelRotateRiverShallow;

	typedef void (*uiSetGatherPointAtPointer_t)(bool homeCity, bool water);
	// Sets the gather points for the selected unit(s) to the pointer position.
	extern const uiSetGatherPointAtPointer_t uiSetGatherPointAtPointer;

	typedef void (*uiSetHomeCityWaterSpawnPointAtPointer_t)();
	// Sets the HC spawn point.
	extern const uiSetHomeCityWaterSpawnPointAtPointer_t uiSetHomeCityWaterSpawnPointAtPointer;

	typedef void (*uiClearGatherPoint_t)();
	// Clears the gather point for the selected unit(s), returning it to a default state.
	extern const uiClearGatherPoint_t uiClearGatherPoint;

	typedef void (*uiTransformSelectedUnit_t)(string);
	// transforms the selected unit into the specified proto unit.
	extern const uiTransformSelectedUnit_t uiTransformSelectedUnit;

	typedef void (*uiFlareAtPointer_t)();
	// Sends out a flare at the pointer position.
	extern const uiFlareAtPointer_t uiFlareAtPointer;

	typedef void (*uiCommsFlareAtPointer_t)();
	// Used when flaring a position for player comms dialog.
	extern const uiCommsFlareAtPointer_t uiCommsFlareAtPointer;

	typedef void (*uiHelpAtPointer_t)();
	// Sends out a Help at the pointer position.
	extern const uiHelpAtPointer_t uiHelpAtPointer;

	typedef void (*uiGarrisonToPointer_t)();
	// Commands the selected unit(s) to garrison in a building at the pointer position.
	extern const uiGarrisonToPointer_t uiGarrisonToPointer;

	typedef void (*uiRepairAtPointer_t)();
	// Commands the selected unit(s) to repair the target building at the pointer position.
	extern const uiRepairAtPointer_t uiRepairAtPointer;

	typedef void (*uiEmpowerAtPointer_t)();
	// Commands the selected unit(s) to Empower the target building at the pointer position.
	extern const uiEmpowerAtPointer_t uiEmpowerAtPointer;

	typedef void (*uiSetProtoCursor_t)(string stringProtoName, bool setPlacement);
	// sets the cursor to a proto-unit.
	extern const uiSetProtoCursor_t uiSetProtoCursor;

	typedef void (*uiSetProtoCursorID_t)(int integerProtoID);
	// sets the cursor to a proto-unit.
	extern const uiSetProtoCursorID_t uiSetProtoCursorID;

	typedef void (*uiEnterContext_t)(string stringContext);
	// enters the specified UI context.
	extern const uiEnterContext_t uiEnterContext;

	typedef void (*uiLeaveContext_t)(string stringContext);
	// leaves the specified UI context.
	extern const uiLeaveContext_t uiLeaveContext;

	typedef void (*uiClearCursor_t)();
	// resets the cursor to the basic pointer.
	extern const uiClearCursor_t uiClearCursor;

	typedef void (*uiYawUnitRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the yaw unit right key has gone up/down.
	extern const uiYawUnitRight_t uiYawUnitRight;

	typedef void (*uiYawUnitLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the yaw unit left key has gone up/down.
	extern const uiYawUnitLeft_t uiYawUnitLeft;

	typedef void (*uiPitchUnitUp_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the pitch unit up key has gone up/down.
	extern const uiPitchUnitUp_t uiPitchUnitUp;

	typedef void (*uiPitchUnitDown_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the pitch unit down key has gone up/down.
	extern const uiPitchUnitDown_t uiPitchUnitDown;

	typedef void (*uiRollUnitRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the roll unit right key has gone up/down.
	extern const uiRollUnitRight_t uiRollUnitRight;

	typedef void (*uiRollUnitLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the roll unit left key has gone up/down.
	extern const uiRollUnitLeft_t uiRollUnitLeft;

	typedef void (*uiMoveUnitForward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the move unit forward key has gone up/down.
	extern const uiMoveUnitForward_t uiMoveUnitForward;

	typedef void (*uiMoveUnitBackward_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the move unit backward key has gone up/down.
	extern const uiMoveUnitBackward_t uiMoveUnitBackward;

	typedef void (*uiMoveUnitRight_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the move unit right key has gone up/down.
	extern const uiMoveUnitRight_t uiMoveUnitRight;

	typedef void (*uiMoveUnitLeft_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the move unit left key has gone up/down.
	extern const uiMoveUnitLeft_t uiMoveUnitLeft;

	typedef void (*uiMoveUnitUp_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the move unit up key has gone up/down.
	extern const uiMoveUnitUp_t uiMoveUnitUp;

	typedef void (*uiMoveUnitDown_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the move unit down key has gone up/down.
	extern const uiMoveUnitDown_t uiMoveUnitDown;

	typedef void (*uiWheelRotatePlacedUnit_t)(int);
	// intended for ui use only.  Rotate placed unit with wheel -- i.e. intended to be mapped to wheel
	extern const uiWheelRotatePlacedUnit_t uiWheelRotatePlacedUnit;

	typedef void (*uiSelectWaterAtPointer_t)();
	// intended for ui use only.  Selects water at pointer location.
	extern const uiSelectWaterAtPointer_t uiSelectWaterAtPointer;

	typedef void (*uiUnSelectWater_t)();
	// intended for ui use only.  Unselects currently selected water.
	extern const uiUnSelectWater_t uiUnSelectWater;

	typedef void (*uiPaintWaterObjects_t)();
	// Paint objects on the currently selected water.
	extern const uiPaintWaterObjects_t uiPaintWaterObjects;

	typedef void (*uiRaiseWater_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the raise water button has gone up/down.
	extern const uiRaiseWater_t uiRaiseWater;

	typedef void (*uiLowerWater_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the lower water button has gone up/down.
	extern const uiLowerWater_t uiLowerWater;

	typedef void (*uiRotateWaterLeft_t)(int);
	// intended for ui use only.  Indicates that the rotate water left button has gone up/down.
	extern const uiRotateWaterLeft_t uiRotateWaterLeft;

	typedef void (*uiRotateWaterRight_t)(int);
	// intended for ui use only.  Indicates that the rotate water right button has gone up/down.
	extern const uiRotateWaterRight_t uiRotateWaterRight;

	typedef void (*uiSelectionButtonDown_t)();
	// intended for ui use only.  Indicates that selection button has been pressed.
	extern const uiSelectionButtonDown_t uiSelectionButtonDown;

	typedef void (*uiSelectionButtonUp_t)();
	// intended for ui use only.  Indicates that selection button has been released.
	extern const uiSelectionButtonUp_t uiSelectionButtonUp;

	typedef void (*uiCreateNumberGroup_t)(int integerGroup);
	// creates a number group with the currently selected units.
	extern const uiCreateNumberGroup_t uiCreateNumberGroup;

	typedef void (*uiClearNumberGroup_t)(int integerGroup);
	// erases the given number group.
	extern const uiClearNumberGroup_t uiClearNumberGroup;

	typedef void (*uiSelectNumberGroup_t)(int integerGroup);
	// selects the units in the given number group.
	extern const uiSelectNumberGroup_t uiSelectNumberGroup;

	typedef void (*uiAddSelectNumberGroup_t)(int integerGroup);
	// adds the units in the given number group to current selection.
	extern const uiAddSelectNumberGroup_t uiAddSelectNumberGroup;

	typedef void (*uiRemoveFromAnyNumberGroup_t)();
	// removes current selection from any army.
	extern const uiRemoveFromAnyNumberGroup_t uiRemoveFromAnyNumberGroup;

	typedef void (*uiDoubleClickSelect_t)(int integerAdd, bool checkAction);
	// intended for ui use only.  Double click select at pointer location.
	extern const uiDoubleClickSelect_t uiDoubleClickSelect;

	typedef void (*uiAddSelectionButtonDown_t)();
	// intended for ui use only.  Indicates that the add selection button has been pressed.
	extern const uiAddSelectionButtonDown_t uiAddSelectionButtonDown;

	typedef void (*uiAddSelectionButtonUp_t)();
	// intended for ui use only.  Indicates that the add selection button has been released.
	extern const uiAddSelectionButtonUp_t uiAddSelectionButtonUp;

	typedef void (*uiToggleSelectionButton_t)();
	// intended for ui use only.  
	extern const uiToggleSelectionButton_t uiToggleSelectionButton;

	typedef void (*uiRotateSelection_t)(int);
	// intended for ui use only.  rotates the selected UNIT.
	extern const uiRotateSelection_t uiRotateSelection;

	typedef void (*uiMoveSelectionButtonDown_t)();
	// intended for ui use only.  Indicates that selection button has been pressed.
	extern const uiMoveSelectionButtonDown_t uiMoveSelectionButtonDown;

	typedef void (*uiMoveSelectionButtonUp_t)();
	// intended for ui use only.  Indicates that selection button has been released.
	extern const uiMoveSelectionButtonUp_t uiMoveSelectionButtonUp;

	typedef void (*uiMoveSelectionAddButtonDown_t)();
	// intended for ui use only.  Indicates that selection button has been pressed.
	extern const uiMoveSelectionAddButtonDown_t uiMoveSelectionAddButtonDown;

	typedef void (*uiMoveSelectionAddButtonUp_t)();
	// intended for ui use only.  Indicates that selection button has been released.
	extern const uiMoveSelectionAddButtonUp_t uiMoveSelectionAddButtonUp;

	typedef void (*uiWorkAtPointer_t)();
	// intended for ui use only.  Issues "work" at pointer location.
	extern const uiWorkAtPointer_t uiWorkAtPointer;

	typedef void (*uiWheelRotate_t)(int);
	// intended for ui use only.  Rotate with wheel -- i.e. intended to be mapped to wheel
	extern const uiWheelRotate_t uiWheelRotate;

	typedef void (*uiWheelRotateCamera_t)(int);
	// intended for ui use only.  Rotate with wheel -- i.e. intended to be mapped to wheel
	extern const uiWheelRotateCamera_t uiWheelRotateCamera;

	typedef void (*uiChangeElevationToSample_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the change elevation to sample button has gone up/down.
	extern const uiChangeElevationToSample_t uiChangeElevationToSample;

	typedef void (*uiSampleElevationAtPointer_t)();
	// intended for ui use only.  Samples elevation height at pointer.
	extern const uiSampleElevationAtPointer_t uiSampleElevationAtPointer;

	typedef void (*uiSampleCliffElevationAtPointer_t)();
	// intended for ui use only.  Samples Cliff elevation height at pointer.
	extern const uiSampleCliffElevationAtPointer_t uiSampleCliffElevationAtPointer;

	typedef void (*uiPaintTerrainToSample_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the sample terrain button has gone up/down.
	extern const uiPaintTerrainToSample_t uiPaintTerrainToSample;

	typedef void (*uiSampleTerrainAtPointer_t)();
	// intended for ui use only.  Samples terrain type at pointer.
	extern const uiSampleTerrainAtPointer_t uiSampleTerrainAtPointer;

	typedef void (*uiDeleteSelectedUnit_t)();
	// deletes selected unit.
	extern const uiDeleteSelectedUnit_t uiDeleteSelectedUnit;

	typedef void (*uiDeleteSelectedUnit2_t)();
	// deletes selected unit.
	extern const uiDeleteSelectedUnit2_t uiDeleteSelectedUnit2;

	typedef void (*uiDeleteAllSelectedUnits_t)();
	// deletes all selected unit.
	extern const uiDeleteAllSelectedUnits_t uiDeleteAllSelectedUnits;

	typedef void (*uiRemoveSelectedUnit_t)(int unitID);
	// Removes specified unit, or selected unit if not ID is specified.
	extern const uiRemoveSelectedUnit_t uiRemoveSelectedUnit;

	typedef void (*uiStopSelectedUnits_t)();
	// stop selected units.
	extern const uiStopSelectedUnits_t uiStopSelectedUnits;

	typedef void (*uiRaiseElevation_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the raise elevation button has gone up/down.
	extern const uiRaiseElevation_t uiRaiseElevation;

	typedef void (*uiLowerElevation_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the lower elevation button has gone up/down.
	extern const uiLowerElevation_t uiLowerElevation;

	typedef void (*uiUniformRaiseElevation_t)(int);
	// raises the terrain height uniformly in the brush region
	extern const uiUniformRaiseElevation_t uiUniformRaiseElevation;

	typedef void (*uiUniformLowerElevation_t)(int);
	// lowers the terrain height uniformly in the brush region
	extern const uiUniformLowerElevation_t uiUniformLowerElevation;

	typedef void (*uiSmooth_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the smooth button has gone up/down.
	extern const uiSmooth_t uiSmooth;

	typedef void (*uiPaintWater_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the paint water button has gone up/down.
	extern const uiPaintWater_t uiPaintWater;

	typedef void (*uiPaintWaterArea_t)(int integerKeyState);
	// intended for ui use only. Painting water area.
	extern const uiPaintWaterArea_t uiPaintWaterArea;

	typedef void (*uiPaintCliff_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the paint cliff button has gone up/down.
	extern const uiPaintCliff_t uiPaintCliff;

	typedef void (*uiTerrainSelection_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the terrain selection button has gone up/down.
	extern const uiTerrainSelection_t uiTerrainSelection;

	typedef void (*uiRaiseTerrainSelection_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the raise terrain selection button has gone up/down.
	extern const uiRaiseTerrainSelection_t uiRaiseTerrainSelection;

	typedef void (*uiLowerTerrainSelection_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the lower terrain selection button has gone up/down.
	extern const uiLowerTerrainSelection_t uiLowerTerrainSelection;

	typedef void (*uiFlattenTerrainSelection_t)();
	// flatten the current terrain selection.
	extern const uiFlattenTerrainSelection_t uiFlattenTerrainSelection;

	typedef void (*uiFilterTerrainSelection_t)();
	// filter the current terrain selection.
	extern const uiFilterTerrainSelection_t uiFilterTerrainSelection;

	typedef void (*uiOpenScenarioBrowser_t)(string);
	// open a scenario from the scenario directory
	extern const uiOpenScenarioBrowser_t uiOpenScenarioBrowser;

	typedef void (*uiSaveScenarioBrowser_t)(string);
	// save a scenario to the scenario directory
	extern const uiSaveScenarioBrowser_t uiSaveScenarioBrowser;

	typedef void (*uiSaveAsScenarioBrowser_t)(string);
	// save a scenario to the scenario directory
	extern const uiSaveAsScenarioBrowser_t uiSaveAsScenarioBrowser;

	typedef void (*uiOpenGrandConquestBrowser_t)(string);
	// opens a Grand Conquest saved game
	extern const uiOpenGrandConquestBrowser_t uiOpenGrandConquestBrowser;

	typedef void (*uiScenarioLoad_t)();
	// load a scenario, checking dirty bit on world.
	extern const uiScenarioLoad_t uiScenarioLoad;

	typedef void (*uiStartScenarioTest_t)();
	// test a scenario.
	extern const uiStartScenarioTest_t uiStartScenarioTest;

	typedef void (*uiStopScenarioTest_t)();
	// test a scenario.
	extern const uiStopScenarioTest_t uiStopScenarioTest;

	typedef void (*uiStartBuildCinematic_t)();
	// test a scenario.
	extern const uiStartBuildCinematic_t uiStartBuildCinematic;

	typedef void (*uiStopBuildCinematic_t)();
	// test a scenario.
	extern const uiStopBuildCinematic_t uiStopBuildCinematic;

	typedef void (*uiClearCinematicInfo_t)();
	// clears cinematic trigger info.
	extern const uiClearCinematicInfo_t uiClearCinematicInfo;

	typedef void (*uiClearAllCinematicInfo_t)();
	// clears all cinematic info including model/texture precache info.
	extern const uiClearAllCinematicInfo_t uiClearAllCinematicInfo;

	typedef void (*uiOpenCameraTrackBrowser_t)(string);
	// open a camera track from the data directory
	extern const uiOpenCameraTrackBrowser_t uiOpenCameraTrackBrowser;

	typedef void (*uiSaveCameraTrackBrowser_t)(string);
	// save a camera track to the data directory
	extern const uiSaveCameraTrackBrowser_t uiSaveCameraTrackBrowser;

	typedef void (*uiOpenSavedGameBrowser_t)(string);
	// open a game from the saved game directory
	extern const uiOpenSavedGameBrowser_t uiOpenSavedGameBrowser;

	typedef void (*uiSaveSavedGameBrowser_t)(string);
	// save a game to the saved game directory
	extern const uiSaveSavedGameBrowser_t uiSaveSavedGameBrowser;

	typedef void (*uiZoomToProto_t)(string stringProto);
	// zooms to the first instance of proto unit X owned by the current player.
	extern const uiZoomToProto_t uiZoomToProto;

	typedef void (*uiOpenRecordGameBrowser_t)(string);
	// open a record game from the saved game directory
	extern const uiOpenRecordGameBrowser_t uiOpenRecordGameBrowser;

	typedef void (*uiLookAtSelection_t)();
	// moves the camera to see the first selected unit.
	extern const uiLookAtSelection_t uiLookAtSelection;

	typedef void (*uiLookAtUnit_t)(int);
	// moves the camera to see the specified Unit.
	extern const uiLookAtUnit_t uiLookAtUnit;

	typedef void (*uiLookAtBattle_t)(int);
	// moves the camera to see the specified battle.
	extern const uiLookAtBattle_t uiLookAtBattle;

	typedef void (*uiLookAtAndSelectUnit_t)(int);
	// moves the camera to see the specified unit and selects it.
	extern const uiLookAtAndSelectUnit_t uiLookAtAndSelectUnit;

	typedef void (*uiLookAtUnitByName_t)(string scenarioName);
	// moves the camera to see the specified Unit.
	extern const uiLookAtUnitByName_t uiLookAtUnitByName;

	typedef void (*uiLookAtProto_t)(string);
	// moves the camera to see the first instance of proto unit X owned by the current player.
	extern const uiLookAtProto_t uiLookAtProto;

	typedef void (*uiLookAtNumberGroup_t)(int integerGroup);
	// moves the camera to see the given number group.
	extern const uiLookAtNumberGroup_t uiLookAtNumberGroup;

	typedef void (*uiRoughen_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the roughen button has gone up/down.
	extern const uiRoughen_t uiRoughen;

	typedef void (*uiDeleteUnits_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the delete units button has gone up/down.
	extern const uiDeleteUnits_t uiDeleteUnits;

	typedef void (*uiPaint_t)(bool integerKeyState, bool);
	// intended for ui use only.  Indicates that the paint button has gone up/down.
	extern const uiPaint_t uiPaint;

	typedef void (*uiPaintForest_t)(bool paint, bool offset);
	// intended for ui use only.  Indicates that the paint button has gone up/down.
	extern const uiPaintForest_t uiPaintForest;

	typedef void (*uiPaintTerrainOverlay_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the paint terrain overlay button has gone up/down.
	extern const uiPaintTerrainOverlay_t uiPaintTerrainOverlay;

	typedef void (*uiRemoveTerrainOverlay_t)();
	// intended for ui use only.  Removes the painted terrain overlay at the given mouse position.
	extern const uiRemoveTerrainOverlay_t uiRemoveTerrainOverlay;

	typedef void (*uiSetTerrainOverlayColor_t)(float, float, float);
	// intended for ui use only.  Sets the terrain overlay color to the given (R,G,B) color.
	extern const uiSetTerrainOverlayColor_t uiSetTerrainOverlayColor;

	typedef void (*uiPlaceAtPointer_t)(bool boolChangeVariation);
	// intended for ui use only.  Places unit at pointer location.
	extern const uiPlaceAtPointer_t uiPlaceAtPointer;

	typedef void (*uiSetProtoID_t)(int integerType);
	// sets the proto ID to place.
	extern const uiSetProtoID_t uiSetProtoID;

	typedef void (*uiIncPlaceVariation_t)();
	// increments the variation to place.
	extern const uiIncPlaceVariation_t uiIncPlaceVariation;

	typedef void (*uiDecPlaceVariation_t)();
	// decrements the variation to place.
	extern const uiDecPlaceVariation_t uiDecPlaceVariation;

	typedef void (*uiBuildMode_t)(int integerType);
	// does and editMode and setProtoID, after verifying sufficient resources for the current player.
	extern const uiBuildMode_t uiBuildMode;

	typedef void (*uiFindIdleType_t)(string typeName);
	// finds the next idle unit of the given type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern const uiFindIdleType_t uiFindIdleType;

	typedef void (*uiFindAllOfSelectedType_t)();
	// finds all units of the same type as the selected unit
	extern const uiFindAllOfSelectedType_t uiFindAllOfSelectedType;

	typedef void (*uiFindAllOfType_t)(string);
	// finds all units of the same type
	extern const uiFindAllOfType_t uiFindAllOfType;

	typedef void (*uiFindAllOfTypeIdle_t)(string);
	// finds all idle units of the same type
	extern const uiFindAllOfTypeIdle_t uiFindAllOfTypeIdle;

	typedef void (*uiHandleIdleBanner_t)(string typeName);
	// does the right thing.
	extern const uiHandleIdleBanner_t uiHandleIdleBanner;

	typedef void (*uiFindTownBellTC_t)(string);
	// finds the next town center that has the town bell active, so that it can be called repeatedly to cycle.
	extern const uiFindTownBellTC_t uiFindTownBellTC;

	typedef void (*uiFindType_t)(string typeName);
	// finds the next unit (idle or not) of the given type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern const uiFindType_t uiFindType;

	typedef void (*uiCycleGadget_t)(int integerDelta);
	// cycles through the 'active' child gadget of a deluxe gadget.
	extern const uiCycleGadget_t uiCycleGadget;

	typedef void (*uiCloseFieldSet_t)();
	// closes (as if clicked on the close button) any active field set
	extern const uiCloseFieldSet_t uiCloseFieldSet;

	typedef void (*uiCloseDialog_t)();
	// closes (as if clicked on the close button) any active dialog
	extern const uiCloseDialog_t uiCloseDialog;

	typedef void (*uiMessageBox_t)(string stringText, string stringCommand);
	// pops up a message box with text that activated the cmd when the ok button is hit
	extern const uiMessageBox_t uiMessageBox;

	typedef void (*uiMessageBox2_t)(int stringID, string stringCommand);
	// pops up a message box with text that activated the cmd when the ok button is hit
	extern const uiMessageBox2_t uiMessageBox2;

	typedef void (*uiCopyToClipboard_t)();
	// copies the brush selection to the clipboard.
	extern const uiCopyToClipboard_t uiCopyToClipboard;

	typedef void (*uiPasteFromClipboard_t)();
	// pastes the contents of the clipboard to the brush selection.
	extern const uiPasteFromClipboard_t uiPasteFromClipboard;

	typedef void (*uiSetClipboardRotation_t)(float degrees);
	// sets the clipboard rotation amount.
	extern const uiSetClipboardRotation_t uiSetClipboardRotation;

	typedef void (*uiRotateClipboard_t)(int degrees);
	// rotate the clipboard by amount.
	extern const uiRotateClipboard_t uiRotateClipboard;

	typedef void (*uiEjectGarrisonedUnits_t)();
	// intended for UI use only.  Sends an ejection command for the selected unit.
	extern const uiEjectGarrisonedUnits_t uiEjectGarrisonedUnits;

	typedef void (*uiEjectAtPointer_t)();
	// intended for UI use only.  Sends an ejection command with waypoint for the selected unit.
	extern const uiEjectAtPointer_t uiEjectAtPointer;

	typedef void (*uiPatrolAtPointer_t)();
	// intended for UI use only.  Sends an patrol order.
	extern const uiPatrolAtPointer_t uiPatrolAtPointer;

	typedef void (*uiGuardAtPointer_t)();
	// intended for UI use only.  Sends an guard order.
	extern const uiGuardAtPointer_t uiGuardAtPointer;

	typedef void (*uiApplyLightingSet_t)(int integerIndex);
	// intended for UI use only.  Applies a Lighting Set
	extern const uiApplyLightingSet_t uiApplyLightingSet;

	typedef void (*uiSetBrushType_t)(string name, float p1, float p2, float p3, float p4);
	// makes the current brush based on the name and parameters.
	extern const uiSetBrushType_t uiSetBrushType;

	typedef void (*uiChangeBrushType_t)(string name);
	// changes the brush to the named type
	extern const uiChangeBrushType_t uiChangeBrushType;

	typedef void (*uiChangeBrushSize_t)(float p1, float p2, float p3, float p4);
	// changes the size of the current brush
	extern const uiChangeBrushSize_t uiChangeBrushSize;

	typedef void (*uiScrollBrushSize_t)(int);
	// intended for ui use only. Increament the size of the current brush up/down
	extern const uiScrollBrushSize_t uiScrollBrushSize;

	typedef void (*uiChangeBrushCornerMode_t)(int);
	// changes the ability to modify corner tiles: 0-All, 1-Corners only, 2-No corners
	extern const uiChangeBrushCornerMode_t uiChangeBrushCornerMode;

	typedef void (*uiChangeCliffModMode_t)(int);
	// changes the ability to modify vertices on cliff edges: 0-No clamping, 1-Clamp Low Edge, 2-Clamp High Edge, 3 - Clamp All Edges
	extern const uiChangeCliffModMode_t uiChangeCliffModMode;

	typedef void (*uiScrollCliffHeight_t)(int);
	// intended for ui use only. Increment the height of the cliff brush up/down
	extern const uiScrollCliffHeight_t uiScrollCliffHeight;

	typedef void (*uiIgnoreNextKey_t)();
	// used when activating a text box with a key to avoid having that key go into the text box too.
	extern const uiIgnoreNextKey_t uiIgnoreNextKey;

	typedef void (*uiCycleCurrentActivate_t)();
	// acts like the current cycle gadget has been pressed
	extern const uiCycleCurrentActivate_t uiCycleCurrentActivate;

	typedef void (*uiClearMenu_t)(string);
	// removes any dangling child menus off of the given gadget
	extern const uiClearMenu_t uiClearMenu;

	typedef void (*uiClearSelection_t)();
	// deselects all selected units
	extern const uiClearSelection_t uiClearSelection;

	typedef void (*uiDumpKeyMappings_t)(string stringContext);
	// spews all key mappings out to the console.
	extern const uiDumpKeyMappings_t uiDumpKeyMappings;

	typedef void (*uiDumpAllUnitHotKeyMappings_t)(string);
	// spews all hot key mappings that create units to the console
	extern const uiDumpAllUnitHotKeyMappings_t uiDumpAllUnitHotKeyMappings;

	typedef void (*uiDumpUnmappedKeys_t)(string stringContext);
	// spews all empty keys out to the console
	extern const uiDumpUnmappedKeys_t uiDumpUnmappedKeys;

	typedef void (*uiFindKeyMapping_t)(string stringKeyname);
	// finds all key mappings for a given key
	extern const uiFindKeyMapping_t uiFindKeyMapping;

	typedef void (*uiHandleUserTab_t)(int listSel, int parent);
	// handles toggle of user textures
	extern const uiHandleUserTab_t uiHandleUserTab;

	typedef void (*uiCoverTerrainWithWater_t)(float floatWaterHeight, float floatDepth, string waterName);
	// flattens terrain and paints water over the entire map.
	extern const uiCoverTerrainWithWater_t uiCoverTerrainWithWater;

	typedef bool (*uiSetCliffType_t)(string stringCliffName);
	// sets the cliff type by name.
	extern const uiSetCliffType_t uiSetCliffType;

	typedef bool (*uiSetCliffTypeNum_t)(int longCliffType);
	// sets the cliff type by index.
	extern const uiSetCliffTypeNum_t uiSetCliffTypeNum;

	typedef bool (*uiSetWaterType_t)(string stringWaterName);
	// sets the water type by name.
	extern const uiSetWaterType_t uiSetWaterType;

	typedef bool (*uiSetWaterTypeNum_t)(int longWaterType);
	// sets the water type by index.
	extern const uiSetWaterTypeNum_t uiSetWaterTypeNum;

	typedef bool (*uiSetForestType_t)(string stringForestName);
	// sets the forest type by name.
	extern const uiSetForestType_t uiSetForestType;

	typedef bool (*uiSetForestTypeNum_t)(int);
	// sets the forest type by index.
	extern const uiSetForestTypeNum_t uiSetForestTypeNum;

	typedef void (*uiSelectForestAtPointer_t)();
	// selects the forest under the pointer.
	extern const uiSelectForestAtPointer_t uiSelectForestAtPointer;

	typedef void (*uiUnselectForest_t)();
	// de-selects the forest under the pointer.
	extern const uiUnselectForest_t uiUnselectForest;

	typedef void (*uiSelectCliffAtPointer_t)();
	// selects the cliff under the pointer.
	extern const uiSelectCliffAtPointer_t uiSelectCliffAtPointer;

	typedef void (*uiUnselectCliff_t)();
	// de-selects the forest under the pointer.
	extern const uiUnselectCliff_t uiUnselectCliff;

	typedef void (*uiToggleCliff_t)();
	// toggles cliff pieces on or off under the pointer.
	extern const uiToggleCliff_t uiToggleCliff;

	typedef void (*gadgetScrollUp_t)(string);
	// scrolls the gadget up one unit
	extern const gadgetScrollUp_t gadgetScrollUp;

	typedef void (*gadgetScrollDown_t)(string);
	// scrolls the gadget up one unit
	extern const gadgetScrollDown_t gadgetScrollDown;

	typedef void (*gadgetScrollLeft_t)(string);
	// scrolls the gadget to the left one unit
	extern const gadgetScrollLeft_t gadgetScrollLeft;

	typedef void (*gadgetScrollRight_t)(string);
	// scrolls the gadget to the Right one unit
	extern const gadgetScrollRight_t gadgetScrollRight;

	typedef void (*gadgetWheelScroll_t)(string, int);
	// ui use.  Scrolling function for hooking wheel to gadget scrolling
	extern const gadgetWheelScroll_t gadgetWheelScroll;

	typedef void (*gadgetReal_t)(string stringName);
	// makes real the named gadget.
	extern const gadgetReal_t gadgetReal;

	typedef void (*gadgetUnreal_t)(string stringName);
	// makes un-real the named gadget.
	extern const gadgetUnreal_t gadgetUnreal;

	typedef void (*gadgetRealIfNotMP_t)(string stringName);
	// makes real the named gadget.
	extern const gadgetRealIfNotMP_t gadgetRealIfNotMP;

	typedef void (*gadgetToggle_t)(string stringName);
	// toggles the reality of the named gadget.
	extern const gadgetToggle_t gadgetToggle;

	typedef void (*gadgetToggleIfNotMP_t)(string);
	// toggles the reality of the named gadget.
	extern const gadgetToggleIfNotMP_t gadgetToggleIfNotMP;

	typedef void (*gadgetRefresh_t)(string stringName);
	// refresh the contents of the named gadget.
	extern const gadgetRefresh_t gadgetRefresh;

	typedef void (*gadgetFlash_t)(string stringName, bool flash);
	// turns gadget flashing on/off.
	extern const gadgetFlash_t gadgetFlash;

	typedef void (*techFlash_t)(int techID, bool flash);
	// turns gadget flashing on/off.
	extern const techFlash_t techFlash;

	typedef void (*trainFlash_t)(int protoID, bool flash);
	// turns gadget flashing on/off.
	extern const trainFlash_t trainFlash;

	typedef void (*categoryFlash_t)(int ID, bool flash);
	// turns gadget flashing on/off.
	extern const categoryFlash_t categoryFlash;

	typedef void (*fadeToColor_t)(int r, int g, int b, int duration, int delay, bool inout);
	// fade in/out using color specified.
	extern const fadeToColor_t fadeToColor;

	typedef void (*setGameFadeIn_t)(int r, int g, int b, int duration, int delay, bool inout);
	// turn fade in on/off, set color duration.
	extern const setGameFadeIn_t setGameFadeIn;

	typedef void (*uiLoadTriggers_t)(string);
	// load some triggers.
	extern const uiLoadTriggers_t uiLoadTriggers;

	typedef void (*uiSaveTriggers_t)(string);
	// save some triggers.
	extern const uiSaveTriggers_t uiSaveTriggers;

	typedef void (*uiImportTriggers_t)(string);
	// load some triggers.
	extern const uiImportTriggers_t uiImportTriggers;

	typedef void (*doTriggerImport_t)(string);
	// load some triggers.
	extern const doTriggerImport_t doTriggerImport;

	typedef void (*uiExportTriggers_t)(string);
	// save some triggers.
	extern const uiExportTriggers_t uiExportTriggers;

	typedef void (*uiTriggerSelectLocation_t)();
	extern const uiTriggerSelectLocation_t uiTriggerSelectLocation;

	typedef void (*uiTriggerResetParameters_t)();
	extern const uiTriggerResetParameters_t uiTriggerResetParameters;

	typedef void (*uiTriggerResetSounds_t)();
	extern const uiTriggerResetSounds_t uiTriggerResetSounds;

	typedef void (*uiExportGrouping_t)(string);
	// save a group.
	extern const uiExportGrouping_t uiExportGrouping;

	typedef void (*uiSaveGrouping_t)(string);
	// save some groups.
	extern const uiSaveGrouping_t uiSaveGrouping;

	typedef void (*uiSaveGroupingLUA_t)(int, string);
	// save some groups.
	extern const uiSaveGroupingLUA_t uiSaveGroupingLUA;

	typedef void (*uiHideCursor_t)(bool);
	// testing only
	extern const uiHideCursor_t uiHideCursor;

	typedef void (*uiLeaveModeOnUnshift_t)();
	// causes game to return to editMode none when shift hotkey is released
	extern const uiLeaveModeOnUnshift_t uiLeaveModeOnUnshift;

	typedef void (*uiToggleBrushMask_t)(int);
	// This is not what you are looking for.
	extern const uiToggleBrushMask_t uiToggleBrushMask;

	typedef void (*uiToggleTerrainPasteMode_t)(int);
	// This is not what you are looking for.
	extern const uiToggleTerrainPasteMode_t uiToggleTerrainPasteMode;

	typedef void (*uiUnitDetailHelp_t)(int protoID, int civID);
	// brings up the detail help UI for the given proto ID, or -1 for current unit selection proto.
	extern const uiUnitDetailHelp_t uiUnitDetailHelp;

	typedef void (*uiTechDetailHelp_t)(int techID);
	// brings up the detail help UI for the given tech node ID
	extern const uiTechDetailHelp_t uiTechDetailHelp;

	typedef void (*uiTechCivDetailHelp_t)(int, int);
	// brings up the detail help UI for the given tech node ID
	extern const uiTechCivDetailHelp_t uiTechCivDetailHelp;

	typedef void (*uiTopicDetailHelp_t)(string topicName);
	// brings up the detail help UI for the given help topic
	extern const uiTopicDetailHelp_t uiTopicDetailHelp;

	typedef void (*uiLastDetailHelp_t)();
	// goes back to the most recent help entry.
	extern const uiLastDetailHelp_t uiLastDetailHelp;

	typedef void (*AIDebugInfoRefresh_t)();
	// shows the ai debug menu with new data.
	extern const AIDebugInfoRefresh_t AIDebugInfoRefresh;

	typedef void (*AIDebugInfoToggle_t)();
	// toggles whether the ai debug menu is up, refreshing if first showing.
	extern const AIDebugInfoToggle_t AIDebugInfoToggle;

	typedef void (*AIDebugOutputToggle_t)();
	// toggles whether the ai output window is up, refreshing if first showing.
	extern const AIDebugOutputToggle_t AIDebugOutputToggle;

	typedef void (*AIDebugGathererToggle_t)();
	// toggles whether the ai gatherer distribution window is up, refreshing if first showing.
	extern const AIDebugGathererToggle_t AIDebugGathererToggle;

	typedef void (*AIDebugPopToggle_t)();
	// toggles whether the ai pop distribution window is up, refreshing if first showing.
	extern const AIDebugPopToggle_t AIDebugPopToggle;

	typedef void (*AIDebugPastResourceNeedToggle_t)();
	// toggles whether the ai past resource needs window is up, refreshing if first showing.
	extern const AIDebugPastResourceNeedToggle_t AIDebugPastResourceNeedToggle;

	typedef void (*AIDebugTimedStatsToggle_t)();
	// toggles whether the kb timed stats window is up, refreshing if first showing.
	extern const AIDebugTimedStatsToggle_t AIDebugTimedStatsToggle;

	typedef void (*AIDebugShowBasesToggle_t)();
	// toggles the display of bases
	extern const AIDebugShowBasesToggle_t AIDebugShowBasesToggle;

	typedef void (*AIDebugShowOpportunitiesToggle_t)();
	// toggles the display of opps.
	extern const AIDebugShowOpportunitiesToggle_t AIDebugShowOpportunitiesToggle;

	typedef void (*AIDebugShowChatHistoryToggle_t)();
	// toggles the display of chat history.
	extern const AIDebugShowChatHistoryToggle_t AIDebugShowChatHistoryToggle;

	typedef void (*AIDebugShowBattlesToggle_t)();
	// toggles the display of AI Battles.
	extern const AIDebugShowBattlesToggle_t AIDebugShowBattlesToggle;

	typedef void (*AIDebugShowPlansToggle_t)();
	// toggles the display of plans.
	extern const AIDebugShowPlansToggle_t AIDebugShowPlansToggle;

	typedef void (*AIDebugToggleBPText_t)();
	// toggles the showing of Building placement value text.
	extern const AIDebugToggleBPText_t AIDebugToggleBPText;

	typedef void (*uiShowAIDebugInfoPlan_t)(int);
	// brings up the plan debug text for the given plan ID
	extern const uiShowAIDebugInfoPlan_t uiShowAIDebugInfoPlan;

	typedef void (*uiShowAIDebugInfoPlacement_t)(int);
	// brings up the building placement info for the given ID
	extern const uiShowAIDebugInfoPlacement_t uiShowAIDebugInfoPlacement;

	typedef void (*uiShowAIDebugInfoProgression_t)(int);
	// brings up the progression info for the given ID
	extern const uiShowAIDebugInfoProgression_t uiShowAIDebugInfoProgression;

	typedef void (*uiShowAIDebugInfoKBUnit_t)(int);
	// brings up the kbunit info for the given ID
	extern const uiShowAIDebugInfoKBUnit_t uiShowAIDebugInfoKBUnit;

	typedef void (*uiShowAIDebugInfoBase_t)(int);
	// brings up the base info for the given ID
	extern const uiShowAIDebugInfoBase_t uiShowAIDebugInfoBase;

	typedef void (*uiShowAIDebugInfoArea_t)(int);
	// brings up the area info for the given ID
	extern const uiShowAIDebugInfoArea_t uiShowAIDebugInfoArea;

	typedef void (*uiShowAIDebugInfoAreaGroup_t)(int, int);
	// brings up the area info for the given ID
	extern const uiShowAIDebugInfoAreaGroup_t uiShowAIDebugInfoAreaGroup;

	typedef void (*uiSetKBAttackRouteRender_t)(int, bool);
	// render the attackRoute info for the given ID
	extern const uiSetKBAttackRouteRender_t uiSetKBAttackRouteRender;

	typedef void (*uiShowAIDebugInfoAttackRoute_t)(int);
	// brings up the attackRoute info for the given ID
	extern const uiShowAIDebugInfoAttackRoute_t uiShowAIDebugInfoAttackRoute;

	typedef void (*uiSetKBResourceRender_t)(int resID, bool set);
	// render the kbResource info for the given ID. If not set given, will not render the resource.
	extern const uiSetKBResourceRender_t uiSetKBResourceRender;

	typedef void (*uiShowAIDebugInfoKBResource_t)(int);
	// brings up the kbResource info for the given ID
	extern const uiShowAIDebugInfoKBResource_t uiShowAIDebugInfoKBResource;

	typedef void (*uiSetKBArmyRender_t)(int id, bool set);
	// render the kbArmy info for the given ID. If not set given, will not render the army.
	extern const uiSetKBArmyRender_t uiSetKBArmyRender;

	typedef void (*uiShowAIDebugInfoKBArmy_t)(int);
	// brings up the kbArmy info for the given ID
	extern const uiShowAIDebugInfoKBArmy_t uiShowAIDebugInfoKBArmy;

	typedef void (*uiShowAIDebugInfoKBUnitPick_t)(int);
	// brings up the kbUnitPick info for the given ID
	extern const uiShowAIDebugInfoKBUnitPick_t uiShowAIDebugInfoKBUnitPick;

	typedef void (*uiShowAIDebugInfoEscrow_t)(int);
	// brings up the escrow info for the given ID
	extern const uiShowAIDebugInfoEscrow_t uiShowAIDebugInfoEscrow;

	typedef void (*uiSetBuildingPlacementRender_t)(int id, bool on);
	// controls rendering of the building placement info for the given ID
	extern const uiSetBuildingPlacementRender_t uiSetBuildingPlacementRender;

	typedef void (*uiChatScrollBack_t)(int integerKeyState);
	// Scrolls chat back one.
	extern const uiChatScrollBack_t uiChatScrollBack;

	typedef void (*uiChatScrollForward_t)(int integerKeyState);
	// Scrolls chat forward one.
	extern const uiChatScrollForward_t uiChatScrollForward;

	typedef void (*uiChatDisplayModeToggle_t)();
	// Toggles the chat display mode.
	extern const uiChatDisplayModeToggle_t uiChatDisplayModeToggle;

	typedef void (*uiChatDisplayModeToRecent_t)();
	// Toggles the chat display mode to recent mode.
	extern const uiChatDisplayModeToRecent_t uiChatDisplayModeToRecent;

	typedef void (*uiChatDisplayModeToHistory_t)();
	// Toggles the chat display mode to history mode.
	extern const uiChatDisplayModeToHistory_t uiChatDisplayModeToHistory;

	typedef void (*uiClearChat_t)(bool clearOnly);
	// Clears the chat and resets to recent mode.  clearOnly == true if you don't want it to populate the chat, but only clear it.
	extern const uiClearChat_t uiClearChat;

	typedef void (*uiAddChatNotification_t)(int, int, int, int);
	// Adds a notification to the game's chat output, can play a sound too.
	extern const uiAddChatNotification_t uiAddChatNotification;

	typedef void (*uiSetHCNotifyText_t)(int, int);
	// Adds notify text, can play a sound too.
	extern const uiSetHCNotifyText_t uiSetHCNotifyText;

	typedef void (*uiShowChatWindow_t)();
	extern const uiShowChatWindow_t uiShowChatWindow;

	typedef void (*uiReleaseDownKeys_t)();
	// pops up all downed keys.
	extern const uiReleaseDownKeys_t uiReleaseDownKeys;

	typedef void (*uiSpewDownKeys_t)();
	// spews all down keys.
	extern const uiSpewDownKeys_t uiSpewDownKeys;

	typedef void (*uiShowVoteDialog_t)();
	extern const uiShowVoteDialog_t uiShowVoteDialog;

	typedef void (*uiSendIngameChat_t)();
	// used direcly by UI
	extern const uiSendIngameChat_t uiSendIngameChat;

	typedef void (*uiPoliticianUI_t)(int, int, bool);
	// Used to activate the politician UI
	extern const uiPoliticianUI_t uiPoliticianUI;

	typedef void (*uiPoliticianUIInSelected_t)(string);
	// Used to activate the politician UI in current selection
	extern const uiPoliticianUIInSelected_t uiPoliticianUIInSelected;

	typedef void (*uiConsulateUI_t)(int, int);
	// Used to activate the consulate UI
	extern const uiConsulateUI_t uiConsulateUI;

	typedef void (*uiConsulateUIInSelected_t)();
	// Used to activate the consulate UI from hotkeys
	extern const uiConsulateUIInSelected_t uiConsulateUIInSelected;

	typedef void (*enterAttackMoveMode_t)();
	extern const enterAttackMoveMode_t enterAttackMoveMode;

	typedef void (*uiShowObjectivesDialog_t)();
	extern const uiShowObjectivesDialog_t uiShowObjectivesDialog;

	typedef void (*uiExpireCurrentObjectiveNotification_t)(bool);
	// Causes the currently displaying objective notification to fade out (or disappear), depending on the param passed in.
	extern const uiExpireCurrentObjectiveNotification_t uiExpireCurrentObjectiveNotification;

	typedef void (*uiPlaceTradeRouteWaypoint_t)();
	extern const uiPlaceTradeRouteWaypoint_t uiPlaceTradeRouteWaypoint;

	typedef void (*uiRemoveTradeRouteWaypoint_t)();
	extern const uiRemoveTradeRouteWaypoint_t uiRemoveTradeRouteWaypoint;

	typedef void (*uiSelectTransportUnit_t)();
	extern const uiSelectTransportUnit_t uiSelectTransportUnit;

	typedef void (*uiFindResourceGatherers_t)(string typeName);
	// finds the next resource gatherer unit of the given resource type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern const uiFindResourceGatherers_t uiFindResourceGatherers;

	typedef void (*uiFindGatherersNotGathering_t)();
	// finds the gatherer unit that's not gathering in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern const uiFindGatherersNotGathering_t uiFindGatherersNotGathering;

	typedef void (*uiFindDancers_t)();
	// finds the next native settler dancing at the firepit in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern const uiFindDancers_t uiFindDancers;

	typedef void (*uiSelectFirepit_t)();
	// selects the users firepit if it exists
	extern const uiSelectFirepit_t uiSelectFirepit;

	typedef void (*uiFindAlliedNatives_t)();
	// finds allied natives of the current player in order, so that it can be called repeatedly to cycle.
	extern const uiFindAlliedNatives_t uiFindAlliedNatives;

	typedef void (*uiVPAccelClick_t)(int unitID);
	// Shows the VP accel building from the unitID.
	extern const uiVPAccelClick_t uiVPAccelClick;

	typedef void (*incrementUSP2SelectedUnitStack_t)();
	extern const incrementUSP2SelectedUnitStack_t incrementUSP2SelectedUnitStack;

	typedef void (*decrementUSP2SelectedUnitStack_t)();
	extern const decrementUSP2SelectedUnitStack_t decrementUSP2SelectedUnitStack;

	typedef void (*uiSetCameraStartLoc_t)();
	extern const uiSetCameraStartLoc_t uiSetCameraStartLoc;

	typedef void (*uiShowCameraStartLoc_t)();
	extern const uiShowCameraStartLoc_t uiShowCameraStartLoc;

	typedef void (*uiDeleteCameraStartLoc_t)();
	extern const uiDeleteCameraStartLoc_t uiDeleteCameraStartLoc;

	typedef void (*uiCameraScroll_t)(bool fast, float x, float y);
	// Scrolls the game view.
	extern const uiCameraScroll_t uiCameraScroll;

	typedef void (*uiCameraControl_t)(float x, float y);
	// Controls camera with gamepad stick.
	extern const uiCameraControl_t uiCameraControl;

	typedef void (*uiMapPointerControl_t)(float x, float y, bool doGoto);
	// Moves the map pointer.
	extern const uiMapPointerControl_t uiMapPointerControl;

	typedef void (*uiMapPointerGoto_t)(bool activeCheck);
	// Jump to map pointer location.
	extern const uiMapPointerGoto_t uiMapPointerGoto;

	typedef void (*uiCircleSelect_t)(bool on, bool doubleClick, bool leaveSelected);
	// Start/stop circle selection.
	extern const uiCircleSelect_t uiCircleSelect;

	typedef void (*uiCircleSelectResize_t)(float x, float y);
	// Circle selection resizing.
	extern const uiCircleSelectResize_t uiCircleSelectResize;

	typedef void (*uiCenterPointer_t)();
	// Centers mouse pointer.
	extern const uiCenterPointer_t uiCenterPointer;

	typedef void (*uiForceShift_t)(bool on);
	// Force shift key on or off.
	extern const uiForceShift_t uiForceShift;

	typedef void (*uiScreenSelect_t)(bool modifier);
	// screen selection.
	extern const uiScreenSelect_t uiScreenSelect;

	typedef void (*uiResetScreenSelect_t)();
	// resets screen selection.
	extern const uiResetScreenSelect_t uiResetScreenSelect;

	typedef void (*uiFindCrowd_t)(int findType, bool noLookAt);
	extern const uiFindCrowd_t uiFindCrowd;

	typedef void (*uiResetFindCrowd_t)();
	extern const uiResetFindCrowd_t uiResetFindCrowd;

	typedef void (*uiToggleAdvancedHUD_t)();
	extern const uiToggleAdvancedHUD_t uiToggleAdvancedHUD;

	typedef void (*uiShowStatPanel_t)();
	extern const uiShowStatPanel_t uiShowStatPanel;

	typedef void (*uiShowDetailedHelp_t)();
	extern const uiShowDetailedHelp_t uiShowDetailedHelp;

	typedef void (*uiShowCommandPanel_t)();
	extern const uiShowCommandPanel_t uiShowCommandPanel;

	typedef void (*uiMinimizeStats_t)();
	extern const uiMinimizeStats_t uiMinimizeStats;

	typedef void (*uiMoveAllMilitaryAtPointer_t)();
	// Moves all military units to the pointer position.
	extern const uiMoveAllMilitaryAtPointer_t uiMoveAllMilitaryAtPointer;

	typedef void (*sendAttackSentence_t)(int sendingPlayer, int receivingPlayer, int targetPlayer, int targetUnit, float xPos, float zPos);
	// send attack sentence from one player to another; specify targetPlayer, or targetUnit, or xPos and zPos.
	extern const sendAttackSentence_t sendAttackSentence;

	typedef void (*sendDefendSentence_t)(int sendingPlayer, int receivingPlayer, float xPos, float zPos);
	// send defend sentence from one player to another; specify target xPos and zPos.
	extern const sendDefendSentence_t sendDefendSentence;

	typedef void (*sendTributeSentence_t)(int sendingPlayer, int receivingPlayer, int resourceID);
	// send tribute sentence from one player to another; specify desired resource.
	extern const sendTributeSentence_t sendTributeSentence;

	typedef void (*sendPromptType_t)(int sendingPlayer, int promptType);
	// send AIChat to current player from sendingPlayer; specify desired AIChatPromptType.
	extern const sendPromptType_t sendPromptType;

	typedef void (*startRandomGame_t)(bool);
	// begins a new random game.
	extern const startRandomGame_t startRandomGame;

	typedef void (*startRandomGame2_t)(string filename, int players, int random, string seed, bool scenarioFilename, int debug, int teamCount, int mapsize, bool resources);
	// begins a new random game with the given parms.
	extern const startRandomGame2_t startRandomGame2;

	typedef void (*startRandomGameMapCode_t)(string mapcode);
	// Generates a random map game with the given map code.
	extern const startRandomGameMapCode_t startRandomGameMapCode;

	typedef void (*startRandomGameAgeAndMapCode_t)(int startingage, bool nomad, string mapcode);
	// Generates a random map game with the given starting age, nomad start(true/false), and map code.
	extern const startRandomGameAgeAndMapCode_t startRandomGameAgeAndMapCode;

	typedef void (*restartCurrentGame_t)();
	// restarts current game.
	extern const restartCurrentGame_t restartCurrentGame;

	typedef void (*leaveGame_t)(int, int);
	// destroys the world and returns to main menu.
	extern const leaveGame_t leaveGame;

	typedef void (*handlePostGame_t)();
	// does what needs to be done.
	extern const handlePostGame_t handlePostGame;

	typedef void (*showGameFromPostGame_t)();
	// does what needs to be done.
	extern const showGameFromPostGame_t showGameFromPostGame;

	typedef void (*postGamePlayAgain_t)();
	// does what needs to be done.
	extern const postGamePlayAgain_t postGamePlayAgain;

	typedef void (*minimapZoomDelta_t)(float floatZoomDelta);
	// changes the zoom factor of the minimap up or down by that amount (remaining centered on the current view)
	extern const minimapZoomDelta_t minimapZoomDelta;

	typedef void (*minimapZoom_t)(float floatZoom);
	// sets the zoom factor of the minimap.
	extern const minimapZoom_t minimapZoom;

	typedef void (*minimapRotateMode_t)(int integerMode);
	// changes the minimap rotation mode.  No arg means toggle.
	extern const minimapRotateMode_t minimapRotateMode;

	typedef void (*chat_t)(string stringText, int integerPlayer);
	// adds a line of chat text from the given player (current if not provided.
	extern const chat_t chat;

	typedef void (*uiSpecialPowerAtPointer_t)();
	// intended for ui use only.  Use a special power at targeted location.
	extern const uiSpecialPowerAtPointer_t uiSpecialPowerAtPointer;

	typedef void (*uiToggleGame_t)();
	// turns off and on the game UI.
	extern const uiToggleGame_t uiToggleGame;

	typedef void (*uiToggleEditor_t)();
	// turns off and on the scenario editor UI.
	extern const uiToggleEditor_t uiToggleEditor;

	typedef void (*uiZoomToMinimapEvent_t)();
	// zooms to the most recent minimap event
	extern const uiZoomToMinimapEvent_t uiZoomToMinimapEvent;

	typedef void (*uiZoomToMinimapEvent2_t)();
	// zooms to the most recent minimap event
	extern const uiZoomToMinimapEvent2_t uiZoomToMinimapEvent2;

	typedef void (*uiRefreshEditorMenu_t)();
	// reconstitutes the entire editor menu
	extern const uiRefreshEditorMenu_t uiRefreshEditorMenu;

	typedef void (*uiShowTributeDialog_t)();
	// minimizes main UI and brings up the minimized UI
	extern const uiShowTributeDialog_t uiShowTributeDialog;

	typedef void (*uiHideTributeDialog_t)();
	// maximizes main UI
	extern const uiHideTributeDialog_t uiHideTributeDialog;

	typedef void (*uiShowPlayerSummaryDialog_t)();
	// Shows the player summary dialog.
	extern const uiShowPlayerSummaryDialog_t uiShowPlayerSummaryDialog;

	typedef void (*uiHidePlayerSummaryDialog_t)();
	// Hides the player summary dialog.
	extern const uiHidePlayerSummaryDialog_t uiHidePlayerSummaryDialog;

	typedef void (*uiNewScenario_t)();
	// creates a new blank scenario
	extern const uiNewScenario_t uiNewScenario;

	typedef void (*sunIncreaseInclination_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the increase sun inclination key has gone up/down.
	extern const sunIncreaseInclination_t sunIncreaseInclination;

	typedef void (*sunDecreaseInclination_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the decrease sun inclination key has gone up/down.
	extern const sunDecreaseInclination_t sunDecreaseInclination;

	typedef void (*sunIncreaseRotation_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the increase sun rotation key has gone up/down.
	extern const sunIncreaseRotation_t sunIncreaseRotation;

	typedef void (*sunDecreaseRotation_t)(int integerKeyState);
	// intended for ui use only.  Indicates that the decrease sun rotation key has gone up/down.
	extern const sunDecreaseRotation_t sunDecreaseRotation;

	typedef void (*setSunPosition_t)(float integerSunInclination, float integerSunRotation, bool boolRelative);
	// sets the sun height above the horizon and position in the world, The bool tells if the changes are relative
	extern const setSunPosition_t setSunPosition;

	typedef void (*campaignStart_t)(string);
	// add help string.
	extern const campaignStart_t campaignStart;

	typedef void (*campaignAdvance_t)();
	// add help string.
	extern const campaignAdvance_t campaignAdvance;

	typedef void (*campaignPlayCurrent_t)();
	// add help string.
	extern const campaignPlayCurrent_t campaignPlayCurrent;

	typedef void (*campaignQuit_t)();
	// add help string.
	extern const campaignQuit_t campaignQuit;

	typedef void (*campaignResume_t)();
	// add help string.
	extern const campaignResume_t campaignResume;

	typedef void (*campaignResetCurScenario_t)();
	// add help string.
	extern const campaignResetCurScenario_t campaignResetCurScenario;

	typedef void (*abortCinematic_t)();
	// abort the current cinematic.
	extern const abortCinematic_t abortCinematic;

	typedef void (*scoreUpdate_t)();
	// causes score to update even if it isn't supposed to yet, time wise
	extern const scoreUpdate_t scoreUpdate;

	typedef void (*toggleScore_t)();
	// handles the score toggling
	extern const toggleScore_t toggleScore;

	typedef void (*toggleTime_t)();
	// handles the time display toggling
	extern const toggleTime_t toggleTime;

	typedef void (*toggleDebugTime_t)();
	// handles the time display toggling
	extern const toggleDebugTime_t toggleDebugTime;

	typedef void (*doSPSetup_t)(bool);
	// Enter Single player setup.
	extern const doSPSetup_t doSPSetup;

	typedef void (*doMPSetup_t)(bool useESO);
	// Enter BMultiplayer setup.
	extern const doMPSetup_t doMPSetup;

	typedef void (*exitMPSetupSubScreen_t)();
	// Leave the current MP screen and return to the MP setup menu.
	extern const exitMPSetupSubScreen_t exitMPSetupSubScreen;

	typedef void (*enterRecordGameMode_t)(string name);
	// 
	extern const enterRecordGameMode_t enterRecordGameMode;

	typedef void (*enterGCGameMode_t)(string name);
	// 
	extern const enterGCGameMode_t enterGCGameMode;

	typedef void (*enterCampaignMode_t)(string name);
	// 
	extern const enterCampaignMode_t enterCampaignMode;

	typedef void (*mpCustomScreenSetSavegame_t)(string name);
	// UI used only
	extern const mpCustomScreenSetSavegame_t mpCustomScreenSetSavegame;

	typedef void (*showCampaignDialog_t)(string name, string msg);
	// UI used only
	extern const showCampaignDialog_t showCampaignDialog;

	typedef void (*playerResign_t)();
	// resigns the currently controlled player.
	extern const playerResign_t playerResign;

	typedef void (*showGameMenu_t)();
	// show the in-game menu.
	extern const showGameMenu_t showGameMenu;

	typedef void (*hideGameMenu_t)(bool);
	// hide the in-game menu.
	extern const hideGameMenu_t hideGameMenu;

	typedef void (*uiSaveCampaignGameBrowser_t)();
	// show the in-game menu.
	extern const uiSaveCampaignGameBrowser_t uiSaveCampaignGameBrowser;

	typedef void (*uiInitOptionsScreenProfileEditDialog_t)();
	// initializes the Profile Edit Dialog inside the OptionsScreen
	extern const uiInitOptionsScreenProfileEditDialog_t uiInitOptionsScreenProfileEditDialog;

	typedef void (*uiBMultiplayerSave_t)();
	// stop playing stupid music at 11pm.
	extern const uiBMultiplayerSave_t uiBMultiplayerSave;

	typedef void (*dropToMainMenu_t)();
	// drop back to the main menu
	extern const dropToMainMenu_t dropToMainMenu;

	typedef bool (*modelLoad_t)(string XMLFileName);
	extern const modelLoad_t modelLoad;

	typedef void (*modelSetAnim_t)(int animIndex);
	extern const modelSetAnim_t modelSetAnim;

	typedef void (*modelDestroyAll_t)();
	extern const modelDestroyAll_t modelDestroyAll;

	typedef void (*changeCliffType_t)(string cliffName);
	// change the cliff type for all cliffs on the map
	extern const changeCliffType_t changeCliffType;

	typedef void (*uiCommandPanelControl_t)(bool on);
	// turn on/off gamepad command panel control.
	extern const uiCommandPanelControl_t uiCommandPanelControl;

	typedef void (*uiCommandPanelMove_t)(float x, float y);
	// move between selections in the command panel.
	extern const uiCommandPanelMove_t uiCommandPanelMove;

	typedef void (*uiCommandPanelExecute_t)(bool);
	// gamepad command panel execute.
	extern const uiCommandPanelExecute_t uiCommandPanelExecute;

	typedef void (*uiCommandCircleMenu_t)(bool on);
	// turn on/off gamepad command panel circle menu.
	extern const uiCommandCircleMenu_t uiCommandCircleMenu;

	typedef void (*uiPowerCircleMenu_t)(bool on);
	// turn on/off gamepad power panel circle menu.
	extern const uiPowerCircleMenu_t uiPowerCircleMenu;

	typedef void (*winScenario_t)();
	// executes the trYouWin trigger func, allowing you to win the scenario.
	extern const winScenario_t winScenario;

	typedef void (*xsDisableRule_t)(string ruleName);
	// Disables the given rule.
	extern const xsDisableRule_t xsDisableRule;

	typedef void (*xsDisableSelf_t)();
	// Disables the current rule.
	extern const xsDisableSelf_t xsDisableSelf;

	typedef void (*xsEnableRule_t)(string ruleName);
	// Enables the given rule.
	extern const xsEnableRule_t xsEnableRule;

	typedef bool (*xsIsRuleEnabled_t)(string ruleName);
	// Returns true if the rule is enabled.
	extern const xsIsRuleEnabled_t xsIsRuleEnabled;

	typedef void (*xsSetRulePriority_t)(string ruleName, int priority);
	// Sets the priority of the given rule.
	extern const xsSetRulePriority_t xsSetRulePriority;

	typedef void (*xsSetRulePrioritySelf_t)(int priority);
	// Sets the priority of the current rule.
	extern const xsSetRulePrioritySelf_t xsSetRulePrioritySelf;

	typedef void (*xsSetRuleMinInterval_t)(string ruleName, int interval);
	// Sets the min interval of the given rule.
	extern const xsSetRuleMinInterval_t xsSetRuleMinInterval;

	typedef void (*xsSetRuleMinIntervalSelf_t)(int interval);
	// Sets the min interval of the current rule.
	extern const xsSetRuleMinIntervalSelf_t xsSetRuleMinIntervalSelf;

	typedef void (*xsSetRuleMaxInterval_t)(string ruleName, int interval);
	// Sets the max interval of the given rule.
	extern const xsSetRuleMaxInterval_t xsSetRuleMaxInterval;

	typedef void (*xsSetRuleMaxIntervalSelf_t)(int interval);
	// Sets the max interval of the current rule.
	extern const xsSetRuleMaxIntervalSelf_t xsSetRuleMaxIntervalSelf;

	typedef void (*xsEnableRuleGroup_t)(string ruleGroupName);
	// Enables all rule in the given rule group.
	extern const xsEnableRuleGroup_t xsEnableRuleGroup;

	typedef void (*xsDisableRuleGroup_t)(string ruleGroupName);
	// Disables all rules in the given rule group.
	extern const xsDisableRuleGroup_t xsDisableRuleGroup;

	typedef void (*xsIsRuleGroupEnabled_t)(string ruleGroupName);
	// Returns true if the rule group is enabled.
	extern const xsIsRuleGroupEnabled_t xsIsRuleGroupEnabled;

	typedef float (*xsVectorGetX_t)(vector v);
	// Returns the x component of the given vector.
	extern const xsVectorGetX_t xsVectorGetX;

	typedef float (*xsVectorGetY_t)(vector v);
	// Returns the y component of the given vector.
	extern const xsVectorGetY_t xsVectorGetY;

	typedef float (*xsVectorGetZ_t)(vector v);
	// Returns the z component of the given vector.
	extern const xsVectorGetZ_t xsVectorGetZ;

	typedef vector (*xsVectorSetX_t)(vector, vector v, float x);
	// Set the x component of the given vector, returns the new vector.
	extern const xsVectorSetX_t xsVectorSetX;

	typedef vector (*xsVectorSetY_t)(vector, vector v, float y);
	// Set the y component of the given vector, returns the new vector.
	extern const xsVectorSetY_t xsVectorSetY;

	typedef vector (*xsVectorSetZ_t)(vector, vector v, float z);
	// Set the z component of the given vector, returns the new vector.
	extern const xsVectorSetZ_t xsVectorSetZ;

	typedef vector (*xsVectorSet_t)(vector, float x, float y, float z);
	// Set the 3 components into a vector, returns the new vector.
	extern const xsVectorSet_t xsVectorSet;

	typedef float (*xsVectorLength_t)(vector v);
	// Returns the length of the given vector.
	extern const xsVectorLength_t xsVectorLength;

	typedef vector (*xsVectorNormalize_t)(vector, vector v);
	// Returns the normalized version of the given vector.
	extern const xsVectorNormalize_t xsVectorNormalize;

	typedef int (*xsArrayCreateInt_t)(int size, int defaultValue, string name);
	// creates a sized and named integer array, returning an arrayID.
	extern const xsArrayCreateInt_t xsArrayCreateInt;

	typedef bool (*xsArraySetInt_t)(int arrayID, int index, int value);
	// Sets a value at the specified index in the requested array.
	extern const xsArraySetInt_t xsArraySetInt;

	typedef int (*xsArrayGetInt_t)(int arrayID, int index);
	// Gets the value at the specified index in the requested array.
	extern const xsArrayGetInt_t xsArrayGetInt;

	typedef int (*xsArrayCreateFloat_t)(int size, float defaultValue, string name);
	// creates a sized and named float array, returning an arrayID.
	extern const xsArrayCreateFloat_t xsArrayCreateFloat;

	typedef bool (*xsArraySetFloat_t)(int arrayID, int index, float value);
	// Sets a value at the specified index in the requested array.
	extern const xsArraySetFloat_t xsArraySetFloat;

	typedef float (*xsArrayGetFloat_t)(int arrayID, int index);
	// Gets the value at the specified index in the requested array.
	extern const xsArrayGetFloat_t xsArrayGetFloat;

	typedef int (*xsArrayCreateBool_t)(int size, bool defaultValue, string name);
	// creates a sized and named boolean array, returning an arrayID.
	extern const xsArrayCreateBool_t xsArrayCreateBool;

	typedef bool (*xsArraySetBool_t)(int arrayID, int index, bool value);
	// Sets a value at the specified index in the requested array.
	extern const xsArraySetBool_t xsArraySetBool;

	typedef bool (*xsArrayGetBool_t)(int, int);
	// Gets the value at the specified index in the requested array.
	extern const xsArrayGetBool_t xsArrayGetBool;

	typedef int (*xsArrayCreateString_t)(int size, string defaultValue, string name);
	// creates a sized and named string array, returning an arrayID.
	extern const xsArrayCreateString_t xsArrayCreateString;

	typedef bool (*xsArraySetString_t)(int arrayID, int index, string value);
	// Sets a value at the specified index in the requested array.
	extern const xsArraySetString_t xsArraySetString;

	typedef string (*xsArrayGetString_t)(int arrayID, int index);
	// Gets the value at the specified index in the requested array.
	extern const xsArrayGetString_t xsArrayGetString;

	typedef int (*xsArrayCreateVector_t)(int size, vector defaultValue, string name);
	// creates a sized and named vector array, returning an arrayID.
	extern const xsArrayCreateVector_t xsArrayCreateVector;

	typedef bool (*xsArraySetVector_t)(int arrayID, int index, vector value);
	// Sets a value at the specified index in the requested array.
	extern const xsArraySetVector_t xsArraySetVector;

	typedef vector (*xsArrayGetVector_t)(vector, int arrayID, int index);
	// Gets the value at the specified index in the requested array.
	extern const xsArrayGetVector_t xsArrayGetVector;

	typedef int (*xsArrayGetSize_t)(int arrayID);
	// Gets the specified array's size.
	extern const xsArrayGetSize_t xsArrayGetSize;

	typedef void (*xsDumpArrays_t)();
	// blogs out all XS arrays.
	extern const xsDumpArrays_t xsDumpArrays;

	typedef int (*xsGetContextPlayer_t)();
	// Returns the current context player ID.
	extern const xsGetContextPlayer_t xsGetContextPlayer;

	typedef void (*xsSetContextPlayer_t)(int playerID);
	// Sets the current context player ID (DO NOT DO THIS IF YOU DO NOT KNOW WHAT YOU ARE DOING).
	extern const xsSetContextPlayer_t xsSetContextPlayer;

	typedef int (*xsGetTime_t)();
	// Returns the current gametime (in milliseconds).
	extern const xsGetTime_t xsGetTime;

	typedef bool (*xsAddRuntimeEvent_t)(string foo, string bar, int something);
	// Setups a runtime event.  Don't use this.
	extern const xsAddRuntimeEvent_t xsAddRuntimeEvent;

	typedef int (*xsGetFunctionID_t)(string);
	// Runs the secret XSFID for the function. USE WITH CAUTION.
	extern const xsGetFunctionID_t xsGetFunctionID;

	typedef void (*rmEchoWarning_t)(string echoString);
	// Random map echo.
	extern const rmEchoWarning_t rmEchoWarning;

	typedef void (*rmEchoError_t)(string echoString);
	// Random map echo.
	extern const rmEchoError_t rmEchoError;

	typedef void (*rmEchoInfo_t)(string echoString);
	// Random map echo.
	extern const rmEchoInfo_t rmEchoInfo;

	typedef float (*rmRandFloat_t)(float min, float max);
	// Returns a random float between min and max.
	extern const rmRandFloat_t rmRandFloat;

	typedef int (*rmRandInt_t)(int min, int max);
	// Returns a random integer between min and max.
	extern const rmRandInt_t rmRandInt;

	typedef bool (*rmGetNomadStart_t)();
	// Returns true if this map is to place a covered wagon instead of a town center.
	extern const rmGetNomadStart_t rmGetNomadStart;

	typedef bool (*rmGetIsFFA_t)();
	// Returns true if this map is set to be a FFA game which means each player on their own team.
	extern const rmGetIsFFA_t rmGetIsFFA;

	typedef bool (*rmGetIsRelicCapture_t)();
	// Returns true if this map is set to be a relic game..
	extern const rmGetIsRelicCapture_t rmGetIsRelicCapture;

	typedef bool (*rmGetIsKOTH_t)();
	// Returns true if this map is set to be a King of the Hill game.
	extern const rmGetIsKOTH_t rmGetIsKOTH;

	typedef bool (*rmSetMapSize_t)(float x, float z);
	// Sets the size of the map.
	extern const rmSetMapSize_t rmSetMapSize;

	typedef int (*rmGetMapXSize_t)();
	// Returns the X size of the map.
	extern const rmGetMapXSize_t rmGetMapXSize;

	typedef int (*rmGetMapZSize_t)();
	// Returns the Z size of the map.
	extern const rmGetMapZSize_t rmGetMapZSize;

	typedef void (*rmSetSeaLevel_t)(float);
	// Sets the sea level for the map.
	extern const rmSetSeaLevel_t rmSetSeaLevel;

	typedef float (*rmGetSeaLevel_t)();
	// Gets the sea level for the map.
	extern const rmGetSeaLevel_t rmGetSeaLevel;

	typedef bool (*rmSetSeaType_t)(string name);
	// Sets the sea type for the map.  This is used if terrain is initialized to water.
	extern const rmSetSeaType_t rmSetSeaType;

	typedef bool (*rmSetMapElevationParameters_t)(int type, float freq, int octaves, float persistence, float variation);
	// Sets up terrain for initializing with a noise layer.
	extern const rmSetMapElevationParameters_t rmSetMapElevationParameters;

	typedef bool (*rmSetBaseTerrainMix_t)(string mixName);
	// Initializes the base terrain with the requested mix.  Call before rmTerrainInitialize.
	extern const rmSetBaseTerrainMix_t rmSetBaseTerrainMix;

	typedef bool (*rmAddMapTerrainByHeightInfo_t)(string terrain, float minHeight, float maxHeight, float outerRange);
	// Adds a terrain to paint between the specified heights, modified by a random number between 0.0 and outerRange.
	extern const rmAddMapTerrainByHeightInfo_t rmAddMapTerrainByHeightInfo;

	typedef bool (*rmAddMapTerrainByAngleInfo_t)(string terrain, float minSlope, float maxSlope, float outerRange);
	// Adds a terrain to paint on tiles that are sloped between the specified angles (0 degrees is flat terrain, 90 degrees is sheer terrain), modified by a random number between 0.0 and outerRange.
	extern const rmAddMapTerrainByAngleInfo_t rmAddMapTerrainByAngleInfo;

	typedef bool (*rmSetMapElevationHeightBlend_t)(int blend);
	// Sets how much to smooth the overall terrain after initializing with noise.
	extern const rmSetMapElevationHeightBlend_t rmSetMapElevationHeightBlend;

	typedef bool (*rmPlaceMapClusters_t)(string terrain, string protounit);
	// place object clusters (of the specified protounit) around the map, and also optionally paint with the specified terrain.
	extern const rmPlaceMapClusters_t rmPlaceMapClusters;

	typedef bool (*rmSetMapClusteringPlacementParams_t)(float paintThreshold, float placeMinVal, float placeMaxVal, int type);
	// sets up cluster system; valid ranges are from -1.0 to 1.0 and are compared to the internal noise field for deciding where to paint terrain and place clusters. Type is cClusterLand, or cClusterWater, or cClusterShallowWater, or cClusterEverywhere.
	extern const rmSetMapClusteringPlacementParams_t rmSetMapClusteringPlacementParams;

	typedef bool (*rmSetMapClusteringObjectParams_t)(int minObjectCount, int maxObjectCount, float maxPosOffset);
	// sets up cluster system; min/max objects per tile (default: 0-3), and max random offset when placing (default: 0.5 tiles).
	extern const rmSetMapClusteringObjectParams_t rmSetMapClusteringObjectParams;

	typedef bool (*rmSetMapClusteringNoiseParams_t)(float minFrequency, int octaves, float persistence);
	// sets up cluster system; standard inputs to noise generator used to determine cluster placement.
	extern const rmSetMapClusteringNoiseParams_t rmSetMapClusteringNoiseParams;

	typedef int (*rmAreaFractionToTiles_t)(float fraction);
	// Converts an area from fraction of the map to tile count.
	extern const rmAreaFractionToTiles_t rmAreaFractionToTiles;

	typedef float (*rmAreaTilesToFraction_t)(int tiles);
	// Converts area tile count to fraction of map.
	extern const rmAreaTilesToFraction_t rmAreaTilesToFraction;

	typedef int (*rmXFractionToTiles_t)(float fraction);
	// Converts an fraction of the map in the x direction to tile count.
	extern const rmXFractionToTiles_t rmXFractionToTiles;

	typedef float (*rmXTilesToFraction_t)(int tiles);
	// Converts tile count in the x direction to fraction of map.
	extern const rmXTilesToFraction_t rmXTilesToFraction;

	typedef int (*rmZFractionToTiles_t)(float fraction);
	// Converts an fraction of the map in the z direction to tile count.
	extern const rmZFractionToTiles_t rmZFractionToTiles;

	typedef float (*rmZTilesToFraction_t)(int tiles);
	// Converts tile count in the z direction to fraction of map.
	extern const rmZTilesToFraction_t rmZTilesToFraction;

	typedef float (*rmDegreesToRadians_t)(float degrees);
	// Converts an angle in degrees to radians.
	extern const rmDegreesToRadians_t rmDegreesToRadians;

	typedef int (*rmMetersToTiles_t)(float meters);
	// Converts a distance in meters to a number of tiles.
	extern const rmMetersToTiles_t rmMetersToTiles;

	typedef float (*rmTilesToMeters_t)(int tiles);
	// Converts a number of tiles to a distance in meters.
	extern const rmTilesToMeters_t rmTilesToMeters;

	typedef float (*rmXMetersToFraction_t)(float meters);
	// Converts meters into a fraction of the map in the x direction.
	extern const rmXMetersToFraction_t rmXMetersToFraction;

	typedef float (*rmZMetersToFraction_t)(float meters);
	// Converts meters into a fraction of the map in the z direction.
	extern const rmZMetersToFraction_t rmZMetersToFraction;

	typedef float (*rmXFractionToMeters_t)(float meters);
	// Converts a fraction of the map in the x direction to meters.
	extern const rmXFractionToMeters_t rmXFractionToMeters;

	typedef float (*rmZFractionToMeters_t)(float meters);
	// Converts meters a fraction of the map in the z direction to meters.
	extern const rmZFractionToMeters_t rmZFractionToMeters;

	typedef int (*rmCreateArea_t)(string name, int parentAreaID);
	// Creates an area.
	extern const rmCreateArea_t rmCreateArea;

	typedef bool (*rmSetAreaSize_t)(int minFraction, float maxFraction, float);
	// Set the area size to a min/max fraction of the map.
	extern const rmSetAreaSize_t rmSetAreaSize;

	typedef bool (*rmSetAreaEdgeFilling_t)(int areaID, int borderSize);
	// Enable edge filling and set a border search size (for Carolina and similar maps with a big continent).
	extern const rmSetAreaEdgeFilling_t rmSetAreaEdgeFilling;

	typedef bool (*rmSetAreaLocation_t)(int areaID, float xFraction, float zFraction);
	// Set the area location.
	extern const rmSetAreaLocation_t rmSetAreaLocation;

	typedef bool (*rmSetAreaLocPlayer_t)(int areaID, int playerID);
	// Set the area location to player's location.
	extern const rmSetAreaLocPlayer_t rmSetAreaLocPlayer;

	typedef bool (*rmSetAreaLocTeam_t)(int areaID, int teamID);
	// Set the area location to team's location.
	extern const rmSetAreaLocTeam_t rmSetAreaLocTeam;

	typedef bool (*rmBuildArea_t)(int areaID);
	// Builds the specified area.
	extern const rmBuildArea_t rmBuildArea;

	typedef int (*rmBuildAllAreas_t)();
	// Simulatenously builds all unbuilt areas.
	extern const rmBuildAllAreas_t rmBuildAllAreas;

	typedef bool (*rmSetAreaTerrainType_t)(int areaID, string terrainTypeName);
	// Sets the terrain type for an area.
	extern const rmSetAreaTerrainType_t rmSetAreaTerrainType;

	typedef bool (*rmSetAreaMix_t)(int areaID, string mixName);
	// Sets the mix for an area.  Overrides terrain type if it is also set.
	extern const rmSetAreaMix_t rmSetAreaMix;

	typedef bool (*rmPaintAreaTerrain_t)(int areaID);
	// Paints the terrain for a specified area.
	extern const rmPaintAreaTerrain_t rmPaintAreaTerrain;

	typedef bool (*rmPaintAreaTerrainByHeight_t)(int areaID, string terrain, float minHeight, float maxHeight, float outerRange);
	// Paints the area's tiles in the specified height range with specified terrain (with outerRange buffer if feathering is desired).
	extern const rmPaintAreaTerrainByHeight_t rmPaintAreaTerrainByHeight;

	typedef bool (*rmPaintAreaTerrainByAngle_t)(int areaID, string terrain, float minAngle, float maxAngle, float outerRange);
	// Paints the area's tiles in the specified angle range with specified terrain (with outerRange buffer if feathering is desired).
	extern const rmPaintAreaTerrainByAngle_t rmPaintAreaTerrainByAngle;

	typedef bool (*rmSetAreaBaseHeight_t)(int areaID, float height);
	// Sets the base height for an area.
	extern const rmSetAreaBaseHeight_t rmSetAreaBaseHeight;

	typedef bool (*rmSetAreaWarnFailure_t)(int areaID, bool warn);
	// Sets whether the area build process will warn if it fails.
	extern const rmSetAreaWarnFailure_t rmSetAreaWarnFailure;

	typedef bool (*rmSetAreaForestType_t)(int areaID, string forestName);
	// Sets the forest type for an area.
	extern const rmSetAreaForestType_t rmSetAreaForestType;

	typedef bool (*rmSetAreaForestDensity_t)(int areaID, float density);
	// Sets the forest density for an area.
	extern const rmSetAreaForestDensity_t rmSetAreaForestDensity;

	typedef bool (*rmSetAreaForestClumpiness_t)(int areaID, float density);
	// Sets the forest density for an area.
	extern const rmSetAreaForestClumpiness_t rmSetAreaForestClumpiness;

	typedef bool (*rmSetAreaForestUnderbrush_t)(int areaID, float density);
	// Sets the forest density for an area.
	extern const rmSetAreaForestUnderbrush_t rmSetAreaForestUnderbrush;

	typedef bool (*rmSetAreaWaterType_t)(int areaID, string waterName);
	// Sets the water type for an area.
	extern const rmSetAreaWaterType_t rmSetAreaWaterType;

	typedef vector (*rmGetAreaClosestPoint_t)(vector, int areaID, vector point, float pullback, int constraintID);
	// Returns the point in areaID that's closest to the given point, optionally requiring that it pass the given constraint.
	extern const rmGetAreaClosestPoint_t rmGetAreaClosestPoint;

	typedef bool (*rmSetAreaCliffType_t)(int areaID, string cliffName);
	// Sets the cliff type for an area.
	extern const rmSetAreaCliffType_t rmSetAreaCliffType;

	typedef bool (*rmSetAreaCliffPainting_t)(int areaID, bool paintGround, bool paintOutsideEdge, bool paintSide, float minSideHeight, bool paintInsideEdge);
	// Set cliff painting options for an area.
	extern const rmSetAreaCliffPainting_t rmSetAreaCliffPainting;

	typedef bool (*rmSetAreaCliffEdge_t)(int areaID, int count, float size, float variance, float spacing, int mapEdge);
	// Set cliff edge parameters for an area.
	extern const rmSetAreaCliffEdge_t rmSetAreaCliffEdge;

	typedef bool (*rmSetAreaCliffHeight_t)(int areaID, float val, float variance, float ramp);
	// Set an area's cliff height.
	extern const rmSetAreaCliffHeight_t rmSetAreaCliffHeight;

	typedef bool (*rmAddAreaCliffEdgeAvoidClass_t)(int areaID, int avoidID, float minDist);
	// Adds a class for an area's cliff edge to avoid.
	extern const rmAddAreaCliffEdgeAvoidClass_t rmAddAreaCliffEdgeAvoidClass;

	typedef int (*rmRiverCreate_t)(int areaID, string waterType, int breaks, int offset, int minR, int maxR);
	// make a river dude.
	extern const rmRiverCreate_t rmRiverCreate;

	typedef bool (*rmRiverSetConnections_t)(int riverID, float start, float end, float, float);
	extern const rmRiverSetConnections_t rmRiverSetConnections;

	typedef bool (*rmRiverConnectRiver_t)(int riverID, int river2ID, float pct, float end, float);
	extern const rmRiverConnectRiver_t rmRiverConnectRiver;

	typedef bool (*rmRiverAddWaypoint_t)(int riverID, float xFraction, float zFraction);
	// Add waypoint to a river.  Don't mix with rmRiverSetConnections or rmRiverConnectRiver
	extern const rmRiverAddWaypoint_t rmRiverAddWaypoint;

	typedef bool (*rmRiverSetBankNoiseParams_t)(int riverID, float octaves, int persistence, float sineLength, float sineAmt, float variation, float);
	extern const rmRiverSetBankNoiseParams_t rmRiverSetBankNoiseParams;

	typedef bool (*rmRiverSetShallowRadius_t)(int riverID, int radius);
	extern const rmRiverSetShallowRadius_t rmRiverSetShallowRadius;

	typedef bool (*rmRiverAddShallow_t)(int riverID, float distancePct);
	extern const rmRiverAddShallow_t rmRiverAddShallow;

	typedef bool (*rmRiverAddShallows_t)(int riverID, int count, int radius);
	extern const rmRiverAddShallows_t rmRiverAddShallows;

	typedef bool (*rmRiverAvoid_t)(int riverID, int river2ID, float minDist);
	extern const rmRiverAvoid_t rmRiverAvoid;

	typedef bool (*rmRiverBuild_t)(int);
	extern const rmRiverBuild_t rmRiverBuild;

	typedef bool (*rmRiverReveal_t)(int riverID, int extraTiles);
	// reveals a river plus the specified number of extra tiles around it.
	extern const rmRiverReveal_t rmRiverReveal;

	typedef bool (*rmSetRiverFoundationParams_t)(int tileBuffer, float heightOffset);
	// the terrain buffer around the river, and the height of the banks above water level
	extern const rmSetRiverFoundationParams_t rmSetRiverFoundationParams;

	typedef bool (*rmSetWorldCircleConstraint_t)(bool constrain);
	// sets whether RM activities should be constrained to the main world circle.
	extern const rmSetWorldCircleConstraint_t rmSetWorldCircleConstraint;

	typedef bool (*rmSetAreaObeyWorldCircleConstraint_t)(int areaID, bool constrain);
	// Determines whether an area obeys world circle constraint.
	extern const rmSetAreaObeyWorldCircleConstraint_t rmSetAreaObeyWorldCircleConstraint;

	typedef bool (*rmAddAreaTerrainLayer_t)(int areaID, string terrain, float minDist, float maxDist);
	// Adds a terrain layer to an area.
	extern const rmAddAreaTerrainLayer_t rmAddAreaTerrainLayer;

	typedef bool (*rmSetAreaTerrainLayerVariance_t)(int areaID, bool variance);
	// Specifies if the area should vary the terrain layer edges.
	extern const rmSetAreaTerrainLayerVariance_t rmSetAreaTerrainLayerVariance;

	typedef bool (*rmSetAreaMinBlobs_t)(int areaID, int blobs);
	// Sets minimum number of area blobs.
	extern const rmSetAreaMinBlobs_t rmSetAreaMinBlobs;

	typedef bool (*rmSetAreaMaxBlobs_t)(int areaID, int blobs);
	// Sets maximum number of area blobs.
	extern const rmSetAreaMaxBlobs_t rmSetAreaMaxBlobs;

	typedef bool (*rmSetAreaMinBlobDistance_t)(int areaID, float dist);
	// Sets minimum blob distance.
	extern const rmSetAreaMinBlobDistance_t rmSetAreaMinBlobDistance;

	typedef bool (*rmSetAreaMaxBlobDistance_t)(int areaID, float dist);
	// Sets maximum blob distance.
	extern const rmSetAreaMaxBlobDistance_t rmSetAreaMaxBlobDistance;

	typedef bool (*rmSetAreaCoherence_t)(int areaID, float coherence);
	// Sets area coherence (0-1).
	extern const rmSetAreaCoherence_t rmSetAreaCoherence;

	typedef bool (*rmSetAreaSmoothDistance_t)(int areaID, int smoothDistance);
	// Sets area edge smoothing distance (distance is number of neighboring points to consider in each direction).
	extern const rmSetAreaSmoothDistance_t rmSetAreaSmoothDistance;

	typedef bool (*rmSetAreaHeightBlend_t)(int areaID, int heightBlend);
	// Sets how smoothly area height blends into surroundings.
	extern const rmSetAreaHeightBlend_t rmSetAreaHeightBlend;

	typedef int (*rmAreaID_t)(string name);
	// Gets area ID for given area name.
	extern const rmAreaID_t rmAreaID;

	typedef bool (*rmAddAreaInfluencePoint_t)(int areaID, float xFraction, float zFraction);
	// Adds an area influence point.
	extern const rmAddAreaInfluencePoint_t rmAddAreaInfluencePoint;

	typedef bool (*rmAddAreaInfluenceSegment_t)(int areaID, float xFraction1, float zFraction1, float xFraction2, float zFraction2);
	// Adds an area influence segment.
	extern const rmAddAreaInfluenceSegment_t rmAddAreaInfluenceSegment;

	typedef bool (*rmAddAreaRemoveType_t)(int areaID, string typeName);
	// Add an unit type that the specified area removes.
	extern const rmAddAreaRemoveType_t rmAddAreaRemoveType;

	typedef bool (*rmAddAreaTerrainReplacement_t)(int areaID, string terrainTypeName, string newTypeName);
	// Adds a terrain replacement rule to the area.
	extern const rmAddAreaTerrainReplacement_t rmAddAreaTerrainReplacement;

	typedef bool (*rmSetAreaElevationType_t)(int areaID, int type);
	// Sets the area elevation variation type (cElevNormal, cElevFractalSum, cElevTurbulence).
	extern const rmSetAreaElevationType_t rmSetAreaElevationType;

	typedef bool (*rmSetAreaElevationMinFrequency_t)(int areaID, float freq);
	// Sets the area elevation variation noise frequency (best >0 and <1).
	extern const rmSetAreaElevationMinFrequency_t rmSetAreaElevationMinFrequency;

	typedef bool (*rmSetAreaElevationOctaves_t)(int areaID, int octaves);
	// Sets the area elevation variation noise octaves.
	extern const rmSetAreaElevationOctaves_t rmSetAreaElevationOctaves;

	typedef bool (*rmSetAreaElevationPersistence_t)(int areaID, float persistence);
	// Sets the area elevation variation noise persistence (best >0 and <1).
	extern const rmSetAreaElevationPersistence_t rmSetAreaElevationPersistence;

	typedef bool (*rmSetAreaElevationVariation_t)(int areaID, float variation);
	// Sets the area elevation variation height (amount to vary +- from area base height).
	extern const rmSetAreaElevationVariation_t rmSetAreaElevationVariation;

	typedef bool (*rmSetAreaElevationEdgeFalloffDist_t)(int areaID, float dist);
	// Sets the area elevation noise to falloff as it gets closer to the area edge.
	extern const rmSetAreaElevationEdgeFalloffDist_t rmSetAreaElevationEdgeFalloffDist;

	typedef bool (*rmSetAreaElevationNoiseBias_t)(int areaID, float bias);
	// Sets the area elevation variation noise bias (-1 means down only, 0 means +- equally, 1 means up only.)
	extern const rmSetAreaElevationNoiseBias_t rmSetAreaElevationNoiseBias;

	typedef bool (*rmSetAreaReveal_t)(int areaID, int tiles);
	// Sets the area to be revealed (-1 means don't reveal, 0 means reveal, >0 means reveal plus that number of extra tiles.
	extern const rmSetAreaReveal_t rmSetAreaReveal;

	typedef void (*rmSetGlobalSnow_t)(float percent);
	// sets the global snow percent.
	extern const rmSetGlobalSnow_t rmSetGlobalSnow;

	typedef void (*rmSetGlobalRain_t)(float percent);
	// sets the global rain percent.
	extern const rmSetGlobalRain_t rmSetGlobalRain;

	typedef void (*rmSetGlobalStormLength_t)(int length, int timeBetweenStorms);
	// sets storm length and time between storm in seconds.
	extern const rmSetGlobalStormLength_t rmSetGlobalStormLength;

	typedef void (*rmSetWindMagnitude_t)(float magnitude);
	// sets the global wind magnitude (1.0f is default).
	extern const rmSetWindMagnitude_t rmSetWindMagnitude;

	typedef void (*rmTerrainInitialize_t)(string baseTerrain, float height);
	// Initializes the terrain to the base type and height.
	extern const rmTerrainInitialize_t rmTerrainInitialize;

	typedef void (*rmFillMapCorners_t)();
	// Fill map corners with blackmap.
	extern const rmFillMapCorners_t rmFillMapCorners;

	typedef void (*rmSetLightingSet_t)(string name);
	// Sets a lighting set
	extern const rmSetLightingSet_t rmSetLightingSet;

	typedef void (*rmDoLightingFade_t)(string lightSetName, float fadeTime);
	//  applies a lighting set fade.
	extern const rmDoLightingFade_t rmDoLightingFade;

	typedef void (*rmDoLightingEffect_t)(string lightSetName, float blendInTime, float effectTime, float blendOutTime);
	//  applies a lighting set effect.
	extern const rmDoLightingEffect_t rmDoLightingEffect;

	typedef void (*rmSetGaiaCiv_t)(int civ);
	// Sets Gaia's civilization
	extern const rmSetGaiaCiv_t rmSetGaiaCiv;

	typedef bool (*rmAllocateSubCivs_t)(int number);
	// Allocates the number of sub civs in the world.
	extern const rmAllocateSubCivs_t rmAllocateSubCivs;

	typedef bool (*rmSetSubCiv_t)(int index, string civName, bool big);
	// Sets a given sub civ in the world.
	extern const rmSetSubCiv_t rmSetSubCiv;

	typedef int (*rmGetCivID_t)(string civName);
	// Returns the civ ID.
	extern const rmGetCivID_t rmGetCivID;

	typedef int (*rmAddMerc_t)(string unitName, float count, float minCount, float maxCount, float countIncrement, bool multipleUses);
	// Adds mercs of to the merc manager for this game.
	extern const rmAddMerc_t rmAddMerc;

	typedef bool (*rmSetPlayerLocation_t)(int playerID, float xFraction, float zFraction);
	// Manually sets a player's starting location.
	extern const rmSetPlayerLocation_t rmSetPlayerLocation;

	typedef void (*rmSetPlayerPlacementArea_t)(float minX, float minZ, float maxX, float maxZ);
	// Sets the area of the map to use for player placement.
	extern const rmSetPlayerPlacementArea_t rmSetPlayerPlacementArea;

	typedef void (*rmSetTeamSpacingModifier_t)(float modifier);
	// Sets the team spacing modifier.
	extern const rmSetTeamSpacingModifier_t rmSetTeamSpacingModifier;

	typedef void (*rmSetPlacementTeam_t)(int teamID);
	// Sets the team to place.
	extern const rmSetPlacementTeam_t rmSetPlacementTeam;

	typedef void (*rmSetPlacementSection_t)(float fromPercent, float toPercent);
	// Sets the section of the placement line to use.
	extern const rmSetPlacementSection_t rmSetPlacementSection;

	typedef bool (*rmPlacePlayersCircular_t)(float minFraction, float maxFraction, float angleVariation);
	// Makes a circle of player locations.
	extern const rmPlacePlayersCircular_t rmPlacePlayersCircular;

	typedef bool (*rmPlacePlayersSquare_t)(float dist, float distVariation, float spacingVariationfloat);
	// Makes a square of player locations.
	extern const rmPlacePlayersSquare_t rmPlacePlayersSquare;

	typedef bool (*rmPlacePlayersLine_t)(float x1, float z1, float x2, float z2, float distVariation, float spacingVariation);
	// Makes a line of player locations.
	extern const rmPlacePlayersLine_t rmPlacePlayersLine;

	typedef bool (*rmPlacePlayersRiver_t)(int riverID, float distVariation, float spacingVariation, float edgeDistance);
	// Makes a line of player locations along the specified river.
	extern const rmPlacePlayersRiver_t rmPlacePlayersRiver;

	typedef bool (*rmPlacePlayer_t)(int playerID, float xFraction, float zFraction);
	// Sets one player location.
	extern const rmPlacePlayer_t rmPlacePlayer;

	typedef bool (*rmSetPlayerArea_t)(int playerID, int areaID);
	// Sets a player's 'official' area.
	extern const rmSetPlayerArea_t rmSetPlayerArea;

	typedef float (*rmPlayerLocXFraction_t)(int playerID);
	// Gets a player's start location x fraction.
	extern const rmPlayerLocXFraction_t rmPlayerLocXFraction;

	typedef float (*rmPlayerLocZFraction_t)(int playerID);
	// Gets a player's start location z fraction.
	extern const rmPlayerLocZFraction_t rmPlayerLocZFraction;

	typedef int (*rmAddFairLoc_t)(string unitName, bool forward, bool inside, float minPlayerDist, float maxPlayerDist, float locDist, float edgeDist, bool playerArea, bool teamArea);
	// Adds some fairLoc placement info.
	extern const rmAddFairLoc_t rmAddFairLoc;

	typedef bool (*rmPlaceFairLocs_t)(int);
	// Sets fairLoc placement locations.
	extern const rmPlaceFairLocs_t rmPlaceFairLocs;

	typedef void (*rmResetFairLocs_t)();
	// Resets fairLoc placment info.
	extern const rmResetFairLocs_t rmResetFairLocs;

	typedef int (*rmGetNumberFairLocs_t)(int playerID);
	// Gets a player's number of fairLocs.
	extern const rmGetNumberFairLocs_t rmGetNumberFairLocs;

	typedef float (*rmFairLocXFraction_t)(int playerID, int index);
	// Gets a player's fairLoc x fraction.
	extern const rmFairLocXFraction_t rmFairLocXFraction;

	typedef float (*rmFairLocZFraction_t)(int playerID, int index);
	// Gets a player's fairLoc z fraction.
	extern const rmFairLocZFraction_t rmFairLocZFraction;

	typedef bool (*rmSetPlayerResource_t)(int playerID, string resourceName, float amount);
	// Sets a player's resource amount.
	extern const rmSetPlayerResource_t rmSetPlayerResource;

	typedef bool (*rmAddPlayerResource_t)(int playerID, string resourceName, float amount);
	// Adds to a player's resource amount.
	extern const rmAddPlayerResource_t rmAddPlayerResource;

	typedef bool (*rmMultiplyPlayerResource_t)(int playerID, string resourceName, float factor);
	// Multiplys a player's resource amount by the given factor.
	extern const rmMultiplyPlayerResource_t rmMultiplyPlayerResource;

	typedef string (*rmGetPlayerName_t)(int playerID);
	// Gets a player's name.
	extern const rmGetPlayerName_t rmGetPlayerName;

	typedef int (*rmGetPlayerTeam_t)(int playerID);
	// Gets the team the specified player is on.
	extern const rmGetPlayerTeam_t rmGetPlayerTeam;

	typedef int (*rmGetPlayerCiv_t)(int playerID);
	// Gets the civilization the specified player is on.
	extern const rmGetPlayerCiv_t rmGetPlayerCiv;

	typedef int (*rmGetPlayerCulture_t)(int playerID);
	// Gets the culture the specified player is on.
	extern const rmGetPlayerCulture_t rmGetPlayerCulture;

	typedef int (*rmGetNumberPlayersOnTeam_t)(int teamID);
	// Gets the number of players on the given team.
	extern const rmGetNumberPlayersOnTeam_t rmGetNumberPlayersOnTeam;

	typedef bool (*rmSetTeamArea_t)(int teamID, int areaID);
	// Sets a team's 'official' area.
	extern const rmSetTeamArea_t rmSetTeamArea;

	typedef int (*rmCreateBoxConstraint_t)(string name, float startX, float startZ, float endX, float endZ, float bufferFraction);
	// Make a box constraint.
	extern const rmCreateBoxConstraint_t rmCreateBoxConstraint;

	typedef int (*rmCreatePieConstraint_t)(string name, float xFraction, float zFraction, float insideRadius, float outsideRadius, float minAngle, float maxAngle, float bufferFraction);
	// Makes a 'pie' constraint.
	extern const rmCreatePieConstraint_t rmCreatePieConstraint;

	typedef int (*rmCreateAreaOverlapConstraint_t)(string name, int areaID);
	// Make an area overlap constraint.
	extern const rmCreateAreaOverlapConstraint_t rmCreateAreaOverlapConstraint;

	typedef int (*rmCreateAreaConstraint_t)(string name, int areaID);
	// Make a constraint that forces something to remain within an area.
	extern const rmCreateAreaConstraint_t rmCreateAreaConstraint;

	typedef int (*rmCreateAreaDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area distance constraint.
	extern const rmCreateAreaDistanceConstraint_t rmCreateAreaDistanceConstraint;

	typedef int (*rmCreateAreaMaxDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area max distance constraint.
	extern const rmCreateAreaMaxDistanceConstraint_t rmCreateAreaMaxDistanceConstraint;

	typedef int (*rmCreateEdgeConstraint_t)(string name, int areaID);
	// Make a constraint that forces something to remain within an area's edge.
	extern const rmCreateEdgeConstraint_t rmCreateEdgeConstraint;

	typedef int (*rmCreateEdgeDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area edge distance constraint.
	extern const rmCreateEdgeDistanceConstraint_t rmCreateEdgeDistanceConstraint;

	typedef int (*rmCreateEdgeMaxDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area edge max distance constraint.
	extern const rmCreateEdgeMaxDistanceConstraint_t rmCreateEdgeMaxDistanceConstraint;

	typedef int (*rmCreateCliffEdgeConstraint_t)(string name, int areaID);
	// Make a constraint that forces something to remain within an area's cliff edge.
	extern const rmCreateCliffEdgeConstraint_t rmCreateCliffEdgeConstraint;

	typedef int (*rmCreateCliffEdgeDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area cliff edge distance constraint.
	extern const rmCreateCliffEdgeDistanceConstraint_t rmCreateCliffEdgeDistanceConstraint;

	typedef int (*rmCreateCliffEdgeMaxDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area cliff edge max distance constraint.
	extern const rmCreateCliffEdgeMaxDistanceConstraint_t rmCreateCliffEdgeMaxDistanceConstraint;

	typedef int (*rmCreateCliffRampConstraint_t)(string name, int areaID);
	// Make a constraint that forces something to remain within an area's cliff ramp edge.
	extern const rmCreateCliffRampConstraint_t rmCreateCliffRampConstraint;

	typedef int (*rmCreateCliffRampDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area cliff ramp edge distance constraint.
	extern const rmCreateCliffRampDistanceConstraint_t rmCreateCliffRampDistanceConstraint;

	typedef int (*rmCreateCliffRampMaxDistanceConstraint_t)(string name, int areaID, float distance);
	// Make an area cliff ramp edge max distance constraint.
	extern const rmCreateCliffRampMaxDistanceConstraint_t rmCreateCliffRampMaxDistanceConstraint;

	typedef int (*rmCreateClassDistanceConstraint_t)(string name, int classID, float distance);
	// Make a class distance constraint.
	extern const rmCreateClassDistanceConstraint_t rmCreateClassDistanceConstraint;

	typedef int (*rmCreateTypeDistanceConstraint_t)(string name, string classID, float distance);
	// Make a type distance constraint.
	extern const rmCreateTypeDistanceConstraint_t rmCreateTypeDistanceConstraint;

	typedef int (*rmCreateTerrainDistanceConstraint_t)(string name, string type, bool passable, float distance);
	// Make a constraint to avoid terrain with certain a passability.
	extern const rmCreateTerrainDistanceConstraint_t rmCreateTerrainDistanceConstraint;

	typedef int (*rmCreateTerrainMaxDistanceConstraint_t)(string name, string type, bool passable, float distance);
	// Make a constraint to be close to terrain with certain a passability.
	extern const rmCreateTerrainMaxDistanceConstraint_t rmCreateTerrainMaxDistanceConstraint;

	typedef int (*rmCreateCornerConstraint_t)(string name, int corner, bool outside);
	// Make a constraint to pass if in or out of a corner.
	extern const rmCreateCornerConstraint_t rmCreateCornerConstraint;

	typedef int (*rmCreateTradeRouteDistanceConstraint_t)(string name, float minDistance);
	// Make a constraint to avoid trade routes.
	extern const rmCreateTradeRouteDistanceConstraint_t rmCreateTradeRouteDistanceConstraint;

	typedef bool (*rmAddAreaConstraint_t)(int areaID, int constraintID);
	// Add specified constraint to an area.
	extern const rmAddAreaConstraint_t rmAddAreaConstraint;

	typedef bool (*rmCreateHCGPConstraint_t)(string name, float minDistance);
	// Create home city gather point constraint to avoid all HCGPs.
	extern const rmCreateHCGPConstraint_t rmCreateHCGPConstraint;

	typedef bool (*rmCreateHCGPSelfConstraint_t)(string name, int playerID, float minDistance);
	// Create home city gather point constraint to avoid given player's HCGP.
	extern const rmCreateHCGPSelfConstraint_t rmCreateHCGPSelfConstraint;

	typedef bool (*rmCreateHCGPAllyConstraint_t)(string name, int playerID, float minDistance);
	// Create home city gather point constraint to avoid given player's ally's HCGPs.
	extern const rmCreateHCGPAllyConstraint_t rmCreateHCGPAllyConstraint;

	typedef bool (*rmCreateHCGPEnemyConstraint_t)(string name, int playerID, float minDistance);
	// Create home city gather point constraint to avoid given player's enemy's HCGPs.
	extern const rmCreateHCGPEnemyConstraint_t rmCreateHCGPEnemyConstraint;

	typedef int (*rmCreateMaxHeightConstraint_t)(string name, float height);
	// Make an max height constraint (terrain must be less than given height).
	extern const rmCreateMaxHeightConstraint_t rmCreateMaxHeightConstraint;

	typedef bool (*rmAddFairLocConstraint_t)(int fairLocID, int constraintID);
	// Add specified constraint to a fairLoc placement.
	extern const rmAddFairLocConstraint_t rmAddFairLocConstraint;

	typedef bool (*rmAddObjectDefConstraint_t)(int defID, int constraintID);
	// Add specified constraint to given object def.
	extern const rmAddObjectDefConstraint_t rmAddObjectDefConstraint;

	typedef int (*rmDefineClass_t)(string className);
	// Define a class with the given name.
	extern const rmDefineClass_t rmDefineClass;

	typedef bool (*rmAddAreaToClass_t)(int areaID, int classID);
	// Add given area to specified class.
	extern const rmAddAreaToClass_t rmAddAreaToClass;

	typedef bool (*rmAddObjectDefToClass_t)(int objectDefID, int classID);
	// Add given object def to specified class.
	extern const rmAddObjectDefToClass_t rmAddObjectDefToClass;

	typedef int (*rmClassID_t)(string name);
	// Gets class ID for given class name.
	extern const rmClassID_t rmClassID;

	typedef int (*rmConstraintID_t)(string name);
	// Gets constraint ID for given constraint name.
	extern const rmConstraintID_t rmConstraintID;

	typedef int (*rmCreateObjectDef_t)(string name);
	// Creates an object definition.
	extern const rmCreateObjectDef_t rmCreateObjectDef;

	typedef int (*rmCreateStartingUnitsObjectDef_t)(float clusterDistance);
	// Creates special object definition for starting units with the given cluster distance.
	extern const rmCreateStartingUnitsObjectDef_t rmCreateStartingUnitsObjectDef;

	typedef bool (*rmSetObjectDefMinDistance_t)(int defID, float dist);
	// Set the minimum distance for the object definition (in meters).
	extern const rmSetObjectDefMinDistance_t rmSetObjectDefMinDistance;

	typedef bool (*rmSetObjectDefMaxDistance_t)(int defID, float dist);
	// Set the maximum distance for the object definition (in meters).
	extern const rmSetObjectDefMaxDistance_t rmSetObjectDefMaxDistance;

	typedef bool (*rmSetObjectDefGarrisonSecondaryUnits_t)(int defID, bool on);
	// Turn on the garrison secondary units flag.
	extern const rmSetObjectDefGarrisonSecondaryUnits_t rmSetObjectDefGarrisonSecondaryUnits;

	typedef bool (*rmSetObjectDefGarrisonStartingUnits_t)(int defID, bool on);
	// Turn on the garrison starting units flag.
	extern const rmSetObjectDefGarrisonStartingUnits_t rmSetObjectDefGarrisonStartingUnits;

	typedef bool (*rmSetObjectDefCreateHerd_t)(int defID, bool on);
	// Creates a herd out of all units placed in this object def.
	extern const rmSetObjectDefCreateHerd_t rmSetObjectDefCreateHerd;

	typedef bool (*rmSetObjectDefHerdAngle_t)(int defID, float angle);
	// Set a herd angle(clockwise from +z) in the object def.
	extern const rmSetObjectDefHerdAngle_t rmSetObjectDefHerdAngle;

	typedef bool (*rmSetObjectDefAllowOverlap_t)(int defID, bool on);
	// Lets objects overlap within this object def.
	extern const rmSetObjectDefAllowOverlap_t rmSetObjectDefAllowOverlap;

	typedef bool (*rmSetObjectDefForceFullRotation_t)(int defID, bool on);
	// Forces things in this object def to get full arbitrary rotation.
	extern const rmSetObjectDefForceFullRotation_t rmSetObjectDefForceFullRotation;

	typedef bool (*rmAddObjectDefItem_t)(int defID, string unitName, int count, float clusterDistance);
	// Add item to object definition.
	extern const rmAddObjectDefItem_t rmAddObjectDefItem;

	typedef bool (*rmAddObjectDefItemByTypeID_t)(int defID, int unitTypeID, int count, float clusterDistance);
	// Add item to object definition.
	extern const rmAddObjectDefItemByTypeID_t rmAddObjectDefItemByTypeID;

	typedef int (*rmPlaceObjectDefAtLoc_t)(int defID, int playerID, float xFraction, float zFraction, int placeCount);
	// Place object definition at specific location for given player.
	extern const rmPlaceObjectDefAtLoc_t rmPlaceObjectDefAtLoc;

	typedef int (*rmPlaceObjectDefAtPoint_t)(int defID, int playerID, vector point, int placeCount);
	// Place object definition at specific point for given player.
	extern const rmPlaceObjectDefAtPoint_t rmPlaceObjectDefAtPoint;

	typedef int (*rmSetObjectDefTradeRouteID_t)(int defID, int tradeRouteID);
	// Set the trade route for all objects in this object definition.
	extern const rmSetObjectDefTradeRouteID_t rmSetObjectDefTradeRouteID;

	typedef int (*rmPlaceObjectDefPerPlayer_t)(int defID, bool playerOwned, int placeCount);
	// Place object definition per player.
	extern const rmPlaceObjectDefPerPlayer_t rmPlaceObjectDefPerPlayer;

	typedef int (*rmPlaceObjectDefAtAreaLoc_t)(int defID, int playerID, int areaID, int placeCount);
	// Place object definition for the player at the given area's location.
	extern const rmPlaceObjectDefAtAreaLoc_t rmPlaceObjectDefAtAreaLoc;

	typedef int (*rmPlaceObjectDefInArea_t)(int defID, int playerID, int areaID, int placeCount);
	// Place object definition for the player in the given area.
	extern const rmPlaceObjectDefInArea_t rmPlaceObjectDefInArea;

	typedef int (*rmPlaceObjectDefAtRandomAreaOfClass_t)(int defID, int playerID, int classID, int placeCount);
	// Place object definition for the player at the location of a random area in the given class.
	extern const rmPlaceObjectDefAtRandomAreaOfClass_t rmPlaceObjectDefAtRandomAreaOfClass;

	typedef int (*rmPlaceObjectDefInRandomAreaOfClass_t)(int defID, int playerID, int classID, int placeCount);
	// Place object definition for the player in a random area in the given class.
	extern const rmPlaceObjectDefInRandomAreaOfClass_t rmPlaceObjectDefInRandomAreaOfClass;

	typedef int (*rmCreateConnection_t)(string name);
	// Creates an connection.
	extern const rmCreateConnection_t rmCreateConnection;

	typedef int (*rmSetConnectionType_t)(int connectionID, int connectionType, bool connectAll, float connectPercentage);
	// Sets the connection type.
	extern const rmSetConnectionType_t rmSetConnectionType;

	typedef bool (*rmAddConnectionArea_t)(int connectionID, int areaID);
	// Adds an area to the connection.
	extern const rmAddConnectionArea_t rmAddConnectionArea;

	typedef bool (*rmSetConnectionPositionVariance_t)(int connectionID, float variance);
	// Sets the position variance of a connection.
	extern const rmSetConnectionPositionVariance_t rmSetConnectionPositionVariance;

	typedef bool (*rmSetConnectionWidth_t)(int connectionID, float width, float variance);
	// Sets the width of a connection.
	extern const rmSetConnectionWidth_t rmSetConnectionWidth;

	typedef bool (*rmSetConnectionBaseHeight_t)(int connectionID, float width);
	// Sets the base height of a connection.
	extern const rmSetConnectionBaseHeight_t rmSetConnectionBaseHeight;

	typedef bool (*rmSetConnectionCoherence_t)(int connectionID, float width);
	// Sets area coherence (0-1).
	extern const rmSetConnectionCoherence_t rmSetConnectionCoherence;

	typedef bool (*rmSetConnectionWarnFailure_t)(int connectionID, bool warn);
	// Sets whether a connection warns on failure.
	extern const rmSetConnectionWarnFailure_t rmSetConnectionWarnFailure;

	typedef bool (*rmSetConnectionHeightBlend_t)(int connectionID, int width);
	// Sets how smoothly connection height blends into surroundings.
	extern const rmSetConnectionHeightBlend_t rmSetConnectionHeightBlend;

	typedef bool (*rmSetConnectionSmoothDistance_t)(int connectionID, int width);
	// Sets connection edge smoothing distance (distance is number of neighboring points to consider in each direction).
	extern const rmSetConnectionSmoothDistance_t rmSetConnectionSmoothDistance;

	typedef bool (*rmAddConnectionTerrainReplacement_t)(int connectionID, string terrainTypeName, string newTypeName);
	// Adds a terrain replacement rule to the connection.
	extern const rmAddConnectionTerrainReplacement_t rmAddConnectionTerrainReplacement;

	typedef bool (*rmSetConnectionTerrainCost_t)(int connectionID, string terrainTypeName, float cost);
	// Sets the terrain cost for a connection.
	extern const rmSetConnectionTerrainCost_t rmSetConnectionTerrainCost;

	typedef bool (*rmSetConnectionBaseTerrainCost_t)(int connectionID, float cost);
	// Sets the base terrain cost for a connection.
	extern const rmSetConnectionBaseTerrainCost_t rmSetConnectionBaseTerrainCost;

	typedef bool (*rmBuildConnection_t)(int connectionID);
	// Builds the given connection.
	extern const rmBuildConnection_t rmBuildConnection;

	typedef bool (*rmAddConnectionToClass_t)(int connectionID, int classID);
	// Adds the connection to specified class.
	extern const rmAddConnectionToClass_t rmAddConnectionToClass;

	typedef bool (*rmAddConnectionConstraint_t)(int connectionID, int constraintID);
	// Add specified constraint to a connection.
	extern const rmAddConnectionConstraint_t rmAddConnectionConstraint;

	typedef bool (*rmAddConnectionStartConstraint_t)(int connectionID, int constraintID);
	// Add specified constraint for a connection start point.
	extern const rmAddConnectionStartConstraint_t rmAddConnectionStartConstraint;

	typedef bool (*rmAddConnectionEndConstraint_t)(int connectionID, int constraintID);
	// Add specified constraint for a connection end point.
	extern const rmAddConnectionEndConstraint_t rmAddConnectionEndConstraint;

	typedef void (*rmSetStatusText_t)(string status, float progress);
	// Sets the friendly cool loading screen text.
	extern const rmSetStatusText_t rmSetStatusText;

	typedef float (*rmSqrt_t)(float x);
	// Returns the square root of x.
	extern const rmSqrt_t sqrt;

	typedef void (*rmSetVPFile_t)(string filename);
	extern const rmSetVPFile_t rmSetVPFile;

	typedef int (*rmCreateTrigger_t)(string triggerName);
	extern const rmCreateTrigger_t rmCreateTrigger;

	typedef bool (*rmSwitchToTrigger_t)(int triggerID);
	extern const rmSwitchToTrigger_t rmSwitchToTrigger;

	typedef int (*rmTriggerID_t)(string triggerName);
	extern const rmTriggerID_t rmTriggerID;

	typedef int (*rmSetTriggerPriority_t)(int priority);
	extern const rmSetTriggerPriority_t rmSetTriggerPriority;

	typedef int (*rmSetTriggerActive_t)(bool active);
	extern const rmSetTriggerActive_t rmSetTriggerActive;

	typedef int (*rmSetTriggerRunImmediately_t)(bool runImmediately);
	extern const rmSetTriggerRunImmediately_t rmSetTriggerRunImmediately;

	typedef int (*rmSetTriggerLoop_t)(bool loop);
	extern const rmSetTriggerLoop_t rmSetTriggerLoop;

	typedef int (*rmAddTriggerCondition_t)(string conditionType);
	extern const rmAddTriggerCondition_t rmAddTriggerCondition;

	typedef bool (*rmSetTriggerConditionParam_t)(string paramName, string value, bool add);
	extern const rmSetTriggerConditionParam_t rmSetTriggerConditionParam;

	typedef bool (*rmSetTriggerConditionParamInt_t)(string paramName, int value, bool add);
	extern const rmSetTriggerConditionParamInt_t rmSetTriggerConditionParamInt;

	typedef bool (*rmSetTriggerConditionParamFloat_t)(string paramName, float value, bool add);
	extern const rmSetTriggerConditionParamFloat_t rmSetTriggerConditionParamFloat;

	typedef bool (*rmSetTriggerConditionParamArmy_t)(string paramName, int playerID, int armyID, bool add);
	extern const rmSetTriggerConditionParamArmy_t rmSetTriggerConditionParamArmy;

	typedef bool (*rmAddTriggerEffect_t)(string effectType);
	extern const rmAddTriggerEffect_t rmAddTriggerEffect;

	typedef int (*rmSetTriggerEffectParam_t)(string paramName, string value, bool add);
	extern const rmSetTriggerEffectParam_t rmSetTriggerEffectParam;

	typedef bool (*rmSetTriggerEffectParamInt_t)(string paramName, int value, bool add);
	extern const rmSetTriggerEffectParamInt_t rmSetTriggerEffectParamInt;

	typedef bool (*rmSetTriggerEffectParamFloat_t)(string paramName, float value, bool add);
	extern const rmSetTriggerEffectParamFloat_t rmSetTriggerEffectParamFloat;

	typedef bool (*rmSetTriggerEffectParamArmy_t)(string paramName, int playerID, int armyID, bool add);
	extern const rmSetTriggerEffectParamArmy_t rmSetTriggerEffectParamArmy;

	typedef int (*rmCreateArmy_t)(int playerID, string armyName);
	extern const rmCreateArmy_t rmCreateArmy;

	typedef bool (*rmAddUnitsToArmy_t)(int playerID, int armyID, int objectDefID);
	extern const rmAddUnitsToArmy_t rmAddUnitsToArmy;

	typedef int (*rmGetNumberUnitsPlaced_t)(int objectDefID);
	extern const rmGetNumberUnitsPlaced_t rmGetNumberUnitsPlaced;

	typedef int (*rmGetUnitPlaced_t)(int objectDefID, int index);
	extern const rmGetUnitPlaced_t rmGetUnitPlaced;

	typedef int (*rmGetUnitPlacedOfPlayer_t)(int, int);
	extern const rmGetUnitPlacedOfPlayer_t rmGetUnitPlacedOfPlayer;

	typedef bool (*rmDefineConstant_t)(string name, int value);
	extern const rmDefineConstant_t rmDefineConstant;

	typedef void (*rmSetIgnoreForceToGaia_t)(bool val);
	extern const rmSetIgnoreForceToGaia_t rmSetIgnoreForceToGaia;

	typedef int (*rmCreateGrouping_t)(string name, string filename);
	// Creates a grouping.
	extern const rmCreateGrouping_t rmCreateGrouping;

	typedef bool (*rmAddGroupingConstraint_t)(int GroupingID, int constraintID);
	// Add specified constraint to a grouping.
	extern const rmAddGroupingConstraint_t rmAddGroupingConstraint;

	typedef int (*rmPlaceGroupingAtLoc_t)(int groupingID, int playerID, float xFraction, float zFraction, int placeCount);
	// Place grouping at specified location.
	extern const rmPlaceGroupingAtLoc_t rmPlaceGroupingAtLoc;

	typedef int (*rmPlaceGroupingAtPoint_t)(int groupingID, int playerID, vector point, int placeCount);
	// Place grouping at specified point.
	extern const rmPlaceGroupingAtPoint_t rmPlaceGroupingAtPoint;

	typedef int (*rmPlaceGroupingInArea_t)(int groupingID, int playerID, int areaID, int placeCount);
	// Place grouping for the player in the given area.
	extern const rmPlaceGroupingInArea_t rmPlaceGroupingInArea;

	typedef bool (*rmSetGroupingMinDistance_t)(int defID, float dist);
	// Set the minimum distance for the grouping (in meters).
	extern const rmSetGroupingMinDistance_t rmSetGroupingMinDistance;

	typedef bool (*rmSetGroupingMaxDistance_t)(int defID, float dist);
	// Set the maximum distance for the grouping (in meters).
	extern const rmSetGroupingMaxDistance_t rmSetGroupingMaxDistance;

	typedef bool (*rmAddGroupingToClass_t)(int GroupingID, int classID);
	// Add given grouping to specified class.
	extern const rmAddGroupingToClass_t rmAddGroupingToClass;

	typedef int (*rmCreateTradeRoute_t)();
	// Creates a trade route.
	extern const rmCreateTradeRoute_t rmCreateTradeRoute;

	typedef bool (*rmAddTradeRouteWaypoint_t)(int tradeRouteID, float xFraction, float zFraction);
	// Adds the given waypoint to the specified trade route.
	extern const rmAddTradeRouteWaypoint_t rmAddTradeRouteWaypoint;

	typedef bool (*rmAddTradeRouteWaypointVector_t)(int tradeRouteID, vector v);
	// Adds the given waypoint to the specified trade route.
	extern const rmAddTradeRouteWaypointVector_t rmAddTradeRouteWaypointVector;

	typedef bool (*rmAddRandomTradeRouteWaypoints_t)(int tradeRouteID, float endXFraction, float endZFraction, int count, float maxVariation);
	// Adds random waypoints to the specified trade route.
	extern const rmAddRandomTradeRouteWaypoints_t rmAddRandomTradeRouteWaypoints;

	typedef bool (*rmAddRandomTradeRouteWaypointsVector_t)(int tradeRouteID, vector v, int count, float maxVariation);
	// Adds random waypoints to the specified trade route.
	extern const rmAddRandomTradeRouteWaypointsVector_t rmAddRandomTradeRouteWaypointsVector;

	typedef bool (*rmCreateTradeRouteWaypointsInArea_t)(int tradeRouteID, int areaID, float length);
	// Creates a trade route in the specified area.
	extern const rmCreateTradeRouteWaypointsInArea_t rmCreateTradeRouteWaypointsInArea;

	typedef vector (*rmGetTradeRouteWayPoint_t)(vector, int tradeRouteID, float fraction);
	// Retrieves a waypoint along the trade route based on the fraction.
	extern const rmGetTradeRouteWayPoint_t rmGetTradeRouteWayPoint;

	typedef bool (*rmBuildTradeRoute_t)(int tradeRouteID, string terrainTypeName);
	// Builds the trade route with the given terrain type.
	extern const rmBuildTradeRoute_t rmBuildTradeRoute;

	typedef bool (*rmSetHomeCityGatherPoint_t)(int playerID, vector point);
	// Sets the HCGP for the given player.
	extern const rmSetHomeCityGatherPoint_t rmSetHomeCityGatherPoint;

	typedef bool (*rmSetHomeCityWaterSpawnPoint_t)(int playerID, vector point);
	// Sets the HCWSP for the given player.
	extern const rmSetHomeCityWaterSpawnPoint_t rmSetHomeCityWaterSpawnPoint;

	typedef int (*rmGetLowHomeCityLevel_t)();
	// Returns the lowest HC Level of the players in the game.
	extern const rmGetLowHomeCityLevel_t rmGetLowHomeCityLevel;

	typedef int (*rmGetAverageHomeCityLevel_t)();
	// Returns the average (rounded down) HC Level of the players in the game.
	extern const rmGetAverageHomeCityLevel_t rmGetAverageHomeCityLevel;

	typedef int (*rmGetHighHomeCityLevel_t)();
	// Returns the highest HC Level of the players in the game.
	extern const rmGetHighHomeCityLevel_t rmGetHighHomeCityLevel;

	typedef int (*rmGetHomeCityLevel_t)(int playerID);
	// Returns the HC Level of the given player.
	extern const rmGetHomeCityLevel_t rmGetHomeCityLevel;

	typedef vector (*rmGetUnitPosition_t)(vector, int unitID);
	// Returns the position of the unit.
	extern const rmGetUnitPosition_t rmGetUnitPosition;

	typedef void (*rmSetMapType_t)(string type);
	// Indicates that this map is of a certain type (it can be multiple types simultaneously.
	extern const rmSetMapType_t rmSetMapType;

	typedef bool (*rmIsMapType_t)(string type);
	// Returns true if the map belongs to the given type.
	extern const rmIsMapType_t rmIsMapType;

	typedef void (*rmEnableLocalWater_t)(bool enable);
	// Enables / disables local water disturbances.
	extern const rmEnableLocalWater_t rmEnableLocalWater;

	typedef bool (*rmAddClosestPointConstraint_t)(int constraintID);
	// Adds constraint to closest point finder.
	extern const rmAddClosestPointConstraint_t rmAddClosestPointConstraint;

	typedef void (*rmClearClosestPointConstraints_t)();
	// Clears constraints for closest point finder.
	extern const rmClearClosestPointConstraints_t rmClearClosestPointConstraints;

	typedef vector (*rmFindClosestPoint_t)(vector, float xFraction, float zFraction, float maxDistance);
	// Finds closest point satisfying the preset constraints.
	extern const rmFindClosestPoint_t rmFindClosestPoint;

	typedef vector (*rmFindClosestPointVector_t)(vector, vector, float);
	// Finds closest point satisfying the preset constraints.
	extern const rmFindClosestPointVector_t rmFindClosestPointVector;

	typedef int (*rmFindCloserArea_t)(float xFraction, float zFraction, int area1, int area2);
	// Returns which area is closer.
	extern const rmFindCloserArea_t rmFindCloserArea;

	typedef bool (*rmAddAreaCliffWaypoint_t)(int areaID, float xFraction, float zFraction);
	// Adds the given waypoint to the specified cliff area (for valleys).
	extern const rmAddAreaCliffWaypoint_t rmAddAreaCliffWaypoint;

	typedef bool (*rmAddAreaCliffRandomWaypoints_t)(int areaID, float endXFraction, float endZFraction, int count, float maxVariation);
	// Adds random waypoints to the specified cliff valley area.
	extern const rmAddAreaCliffRandomWaypoints_t rmAddAreaCliffRandomWaypoints;

	typedef void (*rmSetNuggetDifficulty_t)(int minLevel, int maxLevel);
	// Sets the min/max difficulty levels for placing nuggets.
	extern const rmSetNuggetDifficulty_t rmSetNuggetDifficulty;

	typedef void (*rmSetOceanReveal_t)(bool);
	// Sets whether or not to reveal oceans.
	extern const rmSetOceanReveal_t rmSetOceanReveal;

	typedef void (*hcEcho_t)(string echoString);
	// HC echo.
	extern const hcEcho_t hcEcho;

	typedef void (*hcErrorMessage_t)(string errorString);
	// HC error.
	extern const hcErrorMessage_t hcErrorMessage;

	typedef bool (*hcSetXSHandler_t)(string handlerFunctionName, int type);
	// Sets the handler for given type of event.
	extern const hcSetXSHandler_t hcSetXSHandler;

	typedef bool (*hcSetUnitXSHandler_t)(int unitID, string handlerFunctionName, int type);
	// Sets the handler for a unit for a given type of event.
	extern const hcSetUnitXSHandler_t hcSetUnitXSHandler;

	typedef int (*hcRandInt_t)(int max);
	// Returns a random number (mod'ed by max if provided).
	extern const hcRandInt_t hcRandInt;

	typedef vector (*hcRandPosition_t)(vector);
	// Returns a random position guaranteed to be on the map.
	extern const hcRandPosition_t hcRandPosition;

	typedef int (*hcGetMyUnitID_t)();
	// Returns the HomeCity Unit ID for this unit.
	extern const hcGetMyUnitID_t hcGetMyUnitID;

	typedef int (*hcUnitGetGroupID_t)(int unitID);
	// Returns the HomeCity group ID for this unit.
	extern const hcUnitGetGroupID_t hcUnitGetGroupID;

	typedef vector (*hcUnitGetPosition_t)(vector, int unitID);
	// Returns the position of the unit.
	extern const hcUnitGetPosition_t hcUnitGetPosition;

	typedef int (*hcUnitGetActionType_t)(int unitID);
	// Returns the action type of the unit.
	extern const hcUnitGetActionType_t hcUnitGetActionType;

	typedef bool (*hcUnitGoIdle_t)(int unitID, bool queue);
	// Makes the unit go into idle mode forever.
	extern const hcUnitGoIdle_t hcUnitGoIdle;

	typedef string (*hcUnitGetScript_t)(int unitID);
	// Returns the script for the unit.
	extern const hcUnitGetScript_t hcUnitGetScript;

	typedef int (*hcGetNumUnlockedUnits_t)(bool regularUnits, bool performerUnits);
	// Returns the number of unlocked units available.
	extern const hcGetNumUnlockedUnits_t hcGetNumUnlockedUnits;

	typedef int (*hcGetUnlockedUnitProtoUnitID_t)(int unitIndex, bool regularUnits, bool performerUnits);
	// Returns the proto unit ID for an unlocked unit.
	extern const hcGetUnlockedUnitProtoUnitID_t hcGetUnlockedUnitProtoUnitID;

	typedef string (*hcGetUnlockedUnitVisualFilename_t)(int unitIndex, bool regularUnits, bool performerUnits);
	// Returns the visual file name for an unlocked unit.
	extern const hcGetUnlockedUnitVisualFilename_t hcGetUnlockedUnitVisualFilename;

	typedef string (*hcGetUnlockedUnitScriptFilename_t)(int unitIndex, bool regularUnits, bool performerUnits);
	// Returns the script file name for an unlocked unit.
	extern const hcGetUnlockedUnitScriptFilename_t hcGetUnlockedUnitScriptFilename;

	typedef vector (*hcUnitGetPerformPosFromGroup_t)(vector, int groupID, int unitID);
	// Returns the performance position for a unit.
	extern const hcUnitGetPerformPosFromGroup_t hcUnitGetPerformPosFromGroup;

	typedef vector (*hcUnitGetPerformForwardFromGroup_t)(vector, int groupID, int unitID);
	// Returns the performance forward vector for a unit.
	extern const hcUnitGetPerformForwardFromGroup_t hcUnitGetPerformForwardFromGroup;

	typedef int (*hcUnitCreateUsingPos_t)(int protoUnitID, string visualFilename, string aiFilename, vector position, vector forward, bool visible);
	// Creates a unit; specify either protoUnitID or visualFilename; returns the new unit's ID.
	extern const hcUnitCreateUsingPos_t hcUnitCreateUsingPos;

	typedef int (*hcUnitCreate_t)(int protoUnitID, string visualFilename, string aiFilename, int waypoint);
	// Creates a unit; specify either protoUnitID or visualFilename; returns the new unit's ID.
	extern const hcUnitCreate_t hcUnitCreate;

	typedef int (*hcUnitCreateAtBone_t)(int protoUnitID, string visualFilename, string aiFilename, string boneName);
	// Creates a unit at the bone position; specify either protoUnitID or visualFilename; returns the new unit's ID.
	extern const hcUnitCreateAtBone_t hcUnitCreateAtBone;

	typedef void (*hcPopulateHomeCity_t)();
	// Populates the home city with all units needed.
	extern const hcPopulateHomeCity_t hcPopulateHomeCity;

	typedef float (*hcUnitGetInitialPauseTime_t)(int unitID);
	// Gets the initial time a unit should pause before spawning.
	extern const hcUnitGetInitialPauseTime_t hcUnitGetInitialPauseTime;

	typedef void (*hcUnitSetInitialPauseTime_t)(int unitID, float pauseTime);
	// Sets the initial time a unit should pause before spawning.
	extern const hcUnitSetInitialPauseTime_t hcUnitSetInitialPauseTime;

	typedef bool (*hcUnitSetFlag_t)(int unitID, int unitFlag, bool enable, bool queue);
	// Enables / disables a unit's flag.
	extern const hcUnitSetFlag_t hcUnitSetFlag;

	typedef int (*hcCreatePerformerGroup_t)(int numPerformers, float attentionRadius);
	// Creates a performer group.
	extern const hcCreatePerformerGroup_t hcCreatePerformerGroup;

	typedef bool (*hcReservePerformerArea_t)(int groupID);
	// Reserves a performer area.
	extern const hcReservePerformerArea_t hcReservePerformerArea;

	typedef int (*hcGetNumPerformerGroups_t)();
	// Returns how many performer groups are currently playing.
	extern const hcGetNumPerformerGroups_t hcGetNumPerformerGroups;

	typedef void (*hcAddUnitToPerformerGroup_t)(int groupID, int unitID);
	// Adds a unit to a group of performers.
	extern const hcAddUnitToPerformerGroup_t hcAddUnitToPerformerGroup;

	typedef bool (*hcUnitExit_t)(int unitID, bool queue);
	// Exits the unit (this will kill the unit).
	extern const hcUnitExit_t hcUnitExit;

	typedef void (*hcUnitDestroyAll_t)();
	// Nukes all HC units.
	extern const hcUnitDestroyAll_t hcUnitDestroyAll;

	typedef bool (*hcUnitPlayAnim_t)(int unitID, string animation, float seconds, int loop, bool queue);
	// Plays the anim for the unit.
	extern const hcUnitPlayAnim_t hcUnitPlayAnim;

	typedef bool (*hcUnitMoveToWPID_t)(int unitID, int startWPID, int goalWPID, float speed, float goalTolerance, bool queue);
	// Walks the unit to the WPID.
	extern const hcUnitMoveToWPID_t hcUnitMoveToWPID;

	typedef bool (*hcUnitMoveToPos_t)(int unitID, int startWPID, vector BVector, float goalPos, float speed, bool goalTolerance);
	// Walks the unit to the position.
	extern const hcUnitMoveToPos_t hcUnitMoveToPos;

	typedef bool (*hcUnitTurn_t)(int unitID, vector BVector, float forward, bool turnRateInDegreesPerSec);
	// Turns the unit towards the forward vector.
	extern const hcUnitTurn_t hcUnitTurn;

	typedef bool (*hcUnitTeleportToWPID_t)(int unitID, int WPID);
	// Moves the unit to the given waypoint immediately.
	extern const hcUnitTeleportToWPID_t hcUnitTeleportToWPID;

	typedef bool (*hcUnitFollow_t)(int unitID, int unitToFollowID, float speed, bool queue);
	// Unit follows another unit.
	extern const hcUnitFollow_t hcUnitFollow;

	typedef bool (*hcUnitExitBuilding_t)(int unitID, int buildingID, float pauseTime, float speed, bool queue);
	// Unit exits a building.
	extern const hcUnitExitBuilding_t hcUnitExitBuilding;

	typedef bool (*hcUnitEnterBuilding_t)(int unitID, int buildingID, float speed, bool queue);
	// Unit enters a building.
	extern const hcUnitEnterBuilding_t hcUnitEnterBuilding;

	typedef bool (*hcUnitSetVisible_t)(int unitID, bool state, bool queue);
	// Makes unit visible/invisible.
	extern const hcUnitSetVisible_t hcUnitSetVisible;

	typedef bool (*hcUnitWait_t)(int unitID, float pauseTime, bool queue);
	// Makes script wait a number of seconds
	extern const hcUnitWait_t hcUnitWait;

	typedef void (*hcUnitFreeWPID_t)(int unitID, int wpid, bool queue);
	// Frees the given waypoint.
	extern const hcUnitFreeWPID_t hcUnitFreeWPID;

	typedef void (*hcOccupyWPID_t)(int wpid);
	// Occupies the given waypoint.
	extern const hcOccupyWPID_t hcOccupyWPID;

	typedef int (*hcGetNumberUnitsWithAI_t)(string aiFilename);
	// Returns the number of units with a given AI filename.
	extern const hcGetNumberUnitsWithAI_t hcGetNumberUnitsWithAI;

	typedef int (*hcGetUnitWithAI_t)(string aiFilename, int index);
	// Returns the index-th unit with the given AI filename.
	extern const hcGetUnitWithAI_t hcGetUnitWithAI;

	typedef int (*hcGetPerformerInProximity_t)(int unitID);
	// Returns the index-th performer unit in the proximity.
	extern const hcGetPerformerInProximity_t hcGetPerformerInProximity;

	typedef int (*hcGetNumberWaypoints_t)();
	// Returns the number of waypoints.
	extern const hcGetNumberWaypoints_t hcGetNumberWaypoints;

	typedef vector (*hcGetWaypointPos_t)(vector, int waypoint);
	// Returns the position for a waypoint.
	extern const hcGetWaypointPos_t hcGetWaypointPos;

	typedef vector (*hcGetWaypointDir_t)(vector, int waypoint);
	// Returns the direction for a waypoint.
	extern const hcGetWaypointDir_t hcGetWaypointDir;

	typedef int (*hcGetNearestWPID_t)(vector position);
	// Returns the WPID closest to the position.
	extern const hcGetNearestWPID_t hcGetNearestWPID;

	typedef int (*hcGetRandomWPID_t)(int waypointMask);
	// Returns the WPID of a random waypoint.
	extern const hcGetRandomWPID_t hcGetRandomWPID;

	typedef int (*hcGetRandomFreeWPID_t)(int waypointMask);
	// Returns the WPID of a random waypoint.
	extern const hcGetRandomFreeWPID_t hcGetRandomFreeWPID;

	typedef int (*hcGetBuildingIDByName_t)(string buildingName);
	// Returns the ID for a building with the specified name.
	extern const hcGetBuildingIDByName_t hcGetBuildingIDByName;

	typedef void (*aiEcho_t)(string echoString);
	// CP AI echo.
	extern const aiEcho_t aiEcho;

	typedef void (*aiErrorMessage_t)(string errorString);
	// CP AI error.
	extern const aiErrorMessage_t aiErrorMessage;

	typedef void (*aiRandSetSeed_t)(int seed);
	// Sets the seed of the random number generator.
	extern const aiRandSetSeed_t aiRandSetSeed;

	typedef int (*aiRandInt_t)(int max);
	// Returns a random number (mod'ed by max if provided).
	extern const aiRandInt_t aiRandInt;

	typedef vector (*aiRandLocation_t)(vector);
	// Returns a random location guaranteed to be on the map.
	extern const aiRandLocation_t aiRandLocation;

	typedef void (*aiSet_t)(string filename, int playerID);
	// Sets playerID's AI to the given filename.
	extern const aiSet_t aiSet;

	typedef void (*aiBreakpointSet_t)(int, string, int, bool);
	// Sets a breakpoint.
	extern const aiBreakpointSet_t aiBreakpointSet;

	typedef void (*aiBreakpointGo_t)(int);
	// Restart XS execution after the current breakpoint.
	extern const aiBreakpointGo_t aiBreakpointGo;

	typedef string (*aiGetPersonality_t)();
	// Gets the player's personality.
	extern const aiGetPersonality_t aiGetPersonality;

	typedef float (*aiPersonalityGetRushBoom_t)();
	// Returns the rush boom scale for this ai.
	extern const aiPersonalityGetRushBoom_t aiPersonalityGetRushBoom;

	typedef int (*aiPersonalityGetNumberPlayerHistories_t)();
	// Returns the number of player's in the Personality's history.
	extern const aiPersonalityGetNumberPlayerHistories_t aiPersonalityGetNumberPlayerHistories;

	typedef int (*aiPersonalityCreatePlayerHistory_t)(string);
	// Creates are player history for the given playername.
	extern const aiPersonalityCreatePlayerHistory_t aiPersonalityCreatePlayerHistory;

	typedef bool (*aiPersonalityResetPlayerHistory_t)(int playerHistoryIndex);
	// Resets the given player history.
	extern const aiPersonalityResetPlayerHistory_t aiPersonalityResetPlayerHistory;

	typedef string (*aiPersonalityGetPlayerHistoryName_t)(int index);
	// Returns the name of the index'th player in the Personality's history.
	extern const aiPersonalityGetPlayerHistoryName_t aiPersonalityGetPlayerHistoryName;

	typedef int (*aiPersonalityGetPlayerHistoryIndex_t)(string searchPlayerName);
	// Returns a playerHistoryIndex if this personality has played searchPlayerName before.
	extern const aiPersonalityGetPlayerHistoryIndex_t aiPersonalityGetPlayerHistoryIndex;

	typedef float (*aiPersonalityGetPlayerUserVar_t)(int playerHistoryIndex, string userVarName);
	// Returns the user value, given the playerHistoryIndex and the userVarName.
	extern const aiPersonalityGetPlayerUserVar_t aiPersonalityGetPlayerUserVar;

	typedef bool (*aiPersonalitySetPlayerUserVar_t)(int playerHistoryIndex, string userVarName, float val);
	// sets the value, given the playerHistoryIndex, userVarName (max 255 chars), and value.
	extern const aiPersonalitySetPlayerUserVar_t aiPersonalitySetPlayerUserVar;

	typedef int (*aiPersonalityGetPlayerGamesPlayed_t)(int playerHistoryIndex, int playerRelation);
	// Returns the number of games played against/with the given the playerHistoryIndex.
	extern const aiPersonalityGetPlayerGamesPlayed_t aiPersonalityGetPlayerGamesPlayed;

	typedef float (*aiPersonalityGetGameResource_t)(int playerHistoryIndex, int gameIndex, int resourceID);
	// Returns the given resource from the gameIndex game. If gameIndex is -1, this will return the avg of all games played.
	extern const aiPersonalityGetGameResource_t aiPersonalityGetGameResource;

	typedef bool (*aiPersonalityGetDidIWinLastGameVS_t)(int playerHistoryIndex);
	extern const aiPersonalityGetDidIWinLastGameVS_t aiPersonalityGetDidIWinLastGameVS;

	typedef int (*aiPersonalityGetGameUnitCount_t)(int playerHistoryIndex, int gameIndex, int unitType);
	// Returns the unit count from the gameIndex game. If gameIndex is -1, this will return the avg of all games played.
	extern const aiPersonalityGetGameUnitCount_t aiPersonalityGetGameUnitCount;

	typedef int (*aiPersonalityGetGameFirstAttackTime_t)(int playerHistoryIndex, int gameIndex);
	// Returns the 1st attacktime from the gameIndex game.
	extern const aiPersonalityGetGameFirstAttackTime_t aiPersonalityGetGameFirstAttackTime;

	typedef int (*aiPersonalityGetTotalGameWins_t)(int playerHistoryIndex, int playerRelation);
	// Returns the total games the given player has won against this AI
	extern const aiPersonalityGetTotalGameWins_t aiPersonalityGetTotalGameWins;

	typedef int (*aiGetMostHatedPlayerID_t)();
	// Returns the script-defined most hated player ID for this player.
	extern const aiGetMostHatedPlayerID_t aiGetMostHatedPlayerID;

	typedef int (*aiCalculateMostHatedPlayerID_t)(int comparePlayerID);
	// Returns the playerID for the player the AI thinks it should be attacking.
	extern const aiCalculateMostHatedPlayerID_t aiCalculateMostHatedPlayerID;

	typedef void (*aiSetMostHatedPlayerID_t)(int v);
	// Sets the script-defined most hated player ID for this player.
	extern const aiSetMostHatedPlayerID_t aiSetMostHatedPlayerID;

	typedef int (*aiGetAvailableEconomyPop_t)();
	// Returns the available economy pop for this player.
	extern const aiGetAvailableEconomyPop_t aiGetAvailableEconomyPop;

	typedef int (*aiGetCurrentEconomyPop_t)();
	// Returns the current economy pop for this player.
	extern const aiGetCurrentEconomyPop_t aiGetCurrentEconomyPop;

	typedef int (*aiGetEconomyPop_t)();
	// Returns the script-defined economy pop for this player.
	extern const aiGetEconomyPop_t aiGetEconomyPop;

	typedef void (*aiSetEconomyPop_t)(int v);
	// Set the script-defined economy pop for this player.
	extern const aiSetEconomyPop_t aiSetEconomyPop;

	typedef int (*aiGetAvailableMilitaryPop_t)();
	// Returns the script-defined military pop for this player.
	extern const aiGetAvailableMilitaryPop_t aiGetAvailableMilitaryPop;

	typedef int (*aiGetMilitaryPop_t)();
	// Returns the script-defined military pop for this player.
	extern const aiGetMilitaryPop_t aiGetMilitaryPop;

	typedef void (*aiSetMilitaryPop_t)(int v);
	// Set the script-defined military pop for this player.
	extern const aiSetMilitaryPop_t aiSetMilitaryPop;

	typedef float (*aiGetEconomyPercentage_t)();
	// Returns the economy priority percentage.
	extern const aiGetEconomyPercentage_t aiGetEconomyPercentage;

	typedef void (*aiSetEconomyPercentage_t)(float v);
	// Set the economy priority percentage.
	extern const aiSetEconomyPercentage_t aiSetEconomyPercentage;

	typedef float (*aiGetMilitaryPercentage_t)();
	// Returns the militarypriority percentage.
	extern const aiGetMilitaryPercentage_t aiGetMilitaryPercentage;

	typedef void (*aiSetMilitaryPercentage_t)(float v);
	// Set the military priority percentage.
	extern const aiSetMilitaryPercentage_t aiSetMilitaryPercentage;

	typedef float (*aiGetAttackResponseDistance_t)();
	// Returns the attack response distance.
	extern const aiGetAttackResponseDistance_t aiGetAttackResponseDistance;

	typedef void (*aiSetAttackResponseDistance_t)(float v);
	// Set the attack response distance.
	extern const aiSetAttackResponseDistance_t aiSetAttackResponseDistance;

	typedef int (*aiGoalGetNumber_t)(int goalType, int goalState, bool active);
	// Returns the number of matching goals.
	extern const aiGoalGetNumber_t aiGoalGetNumber;

	typedef int (*aiGoalGetIDByIndex_t)(int goalType, int goalState, bool active, int index);
	// Returns the ID of matching goal.
	extern const aiGoalGetIDByIndex_t aiGoalGetIDByIndex;

	typedef int (*aiPlanGetNumber_t)(int planType, int planState, bool active);
	// Returns the number of matching plans.
	extern const aiPlanGetNumber_t aiPlanGetNumber;

	typedef int (*aiPlanGetIDByIndex_t)(int planType, int planState, bool active, int index);
	// Returns the ID of matching plan.
	extern const aiPlanGetIDByIndex_t aiPlanGetIDByIndex;

	typedef int (*aiPlanCreate_t)(string planName, int typeName);
	// Creates a plan of the given name and type.
	extern const aiPlanCreate_t aiPlanCreate;

	typedef bool (*aiPlanDestroy_t)(int planID);
	// Destroys the given plan.
	extern const aiPlanDestroy_t aiPlanDestroy;

	typedef bool (*aiPlanDestroyByName_t)(string name);
	// Destroys the plan of the given name.
	extern const aiPlanDestroyByName_t aiPlanDestroyByName;

	typedef int (*aiPlanGetID_t)(string name);
	// Returns the ID of the plan with the given name.
	extern const aiPlanGetID_t aiPlanGetID;

	typedef int (*aiPlanGetIDSubStr_t)(string searchStr);
	// Returns the ID of the first plan containing the given string in its name.
	extern const aiPlanGetIDSubStr_t aiPlanGetIDSubStr;

	typedef int (*aiPlanGetIDByTypeAndVariableType_t)(int planType, int varType, int varID, bool active);
	// Returns the ID of the plan with the given parms.
	extern const aiPlanGetIDByTypeAndVariableType_t aiPlanGetIDByTypeAndVariableType;

	typedef int (*aiPlanGetIDByActiveIndex_t)(int activeIndex);
	// Returns the ID of the plan with the given active index.
	extern const aiPlanGetIDByActiveIndex_t aiPlanGetIDByActiveIndex;

	typedef string (*aiPlanGetName_t)(int planID);
	// Returns the name of the given plan.
	extern const aiPlanGetName_t aiPlanGetName;

	typedef int (*aiPlanGetType_t)(int planID);
	// Returns the type of the given plan.
	extern const aiPlanGetType_t aiPlanGetType;

	typedef int (*aiPlanGetState_t)(int planID);
	// Returns the state of the given plan.
	extern const aiPlanGetState_t aiPlanGetState;

	typedef int (*aiPlanGetActualPriority_t)(int planID);
	// Returns the priority of the given plan.
	extern const aiPlanGetActualPriority_t aiPlanGetActualPriority;

	typedef int (*aiPlanGetDesiredPriority_t)(int planID);
	// Returns the priority of the given plan.
	extern const aiPlanGetDesiredPriority_t aiPlanGetDesiredPriority;

	typedef bool (*aiPlanSetDesiredPriority_t)(int planID, int priority);
	// Sets the priority of the given plan.
	extern const aiPlanSetDesiredPriority_t aiPlanSetDesiredPriority;

	typedef bool (*aiPlanAddUnitType_t)(int planID, int unitTypeID, int numberNeed, int numberWant, int numberMax);
	// Adds a unit type to the plan.
	extern const aiPlanAddUnitType_t aiPlanAddUnitType;

	typedef int (*aiPlanGetNumberUnits_t)(int planID, int unitTypeID);
	// Returns the number of units currently assigned in the given plan.
	extern const aiPlanGetNumberUnits_t aiPlanGetNumberUnits;

	typedef bool (*aiPlanAddUnit_t)(int planID, int unitID);
	// Adds a unit to the plan.
	extern const aiPlanAddUnit_t aiPlanAddUnit;

	typedef vector (*aiPlanGetLocation_t)(vector, int planID);
	// Returns the location for this plan.
	extern const aiPlanGetLocation_t aiPlanGetLocation;

	typedef vector (*aiPlanGetInitialPosition_t)(vector, int planID);
	// Returns the initial positon that was set for this plan.
	extern const aiPlanGetInitialPosition_t aiPlanGetInitialPosition;

	typedef void (*aiPlanSetInitialPosition_t)(int planID, vector initialPosition);
	// Sets the initial positon for this plan.
	extern const aiPlanSetInitialPosition_t aiPlanSetInitialPosition;

	typedef bool (*aiPlanSetWaypoints_t)(int planID, int pathID);
	// Sets the waypoints of the given plan to the waypoints of the given path.
	extern const aiPlanSetWaypoints_t aiPlanSetWaypoints;

	typedef bool (*aiPlanAddWaypoint_t)(int planID, vector waypoint);
	// Adds the waypoint to the given plan.
	extern const aiPlanAddWaypoint_t aiPlanAddWaypoint;

	typedef int (*aiPlanGetNumberVariableValues_t)(int planID, int planVariableIndex);
	// Returns the number of values for this variable index.
	extern const aiPlanGetNumberVariableValues_t aiPlanGetNumberVariableValues;

	typedef bool (*aiPlanSetNumberVariableValues_t)(int planID, int planVariableIndex, int numberValues, bool clearCurrentValues);
	// Sets the number of values for this variable.
	extern const aiPlanSetNumberVariableValues_t aiPlanSetNumberVariableValues;

	typedef bool (*aiPlanRemoveVariableValue_t)(int planID, int planVariableIndex, int variableIndex);
	// Removes the index-th value of the variable.
	extern const aiPlanRemoveVariableValue_t aiPlanRemoveVariableValue;

	typedef bool (*aiPlanSetVariableInt_t)(int planID, int planVariableIndex, int valueIndex, int value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetVariableInt_t aiPlanSetVariableInt;

	typedef int (*aiPlanGetVariableInt_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetVariableInt_t aiPlanGetVariableInt;

	typedef bool (*aiPlanSetVariableFloat_t)(int planID, int planVariableIndex, int valueIndex, float value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetVariableFloat_t aiPlanSetVariableFloat;

	typedef float (*aiPlanGetVariableFloat_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetVariableFloat_t aiPlanGetVariableFloat;

	typedef bool (*aiPlanSetVariableVector_t)(int planID, int planVariableIndex, int valueIndex, vector value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetVariableVector_t aiPlanSetVariableVector;

	typedef vector (*aiPlanGetVariableVector_t)(vector, int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetVariableVector_t aiPlanGetVariableVector;

	typedef bool (*aiPlanSetVariableBool_t)(int planID, int planVariableIndex, int valueIndex, bool value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetVariableBool_t aiPlanSetVariableBool;

	typedef bool (*aiPlanGetVariableBool_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetVariableBool_t aiPlanGetVariableBool;

	typedef bool (*aiPlanSetVariableString_t)(int planID, int planVariableIndex, int valueIndex, string value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetVariableString_t aiPlanSetVariableString;

	typedef string (*aiPlanGetVariableString_t)(int planID, int planVariableIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetVariableString_t aiPlanGetVariableString;

	typedef int (*aiPlanGetNumberUserVariableValues_t)(int planID, int planVariableIndex);
	// Returns the number of values for this variable index.
	extern const aiPlanGetNumberUserVariableValues_t aiPlanGetNumberUserVariableValues;

	typedef bool (*aiPlanSetNumberUserVariableValues_t)(int planID, int planVariableIndex, int numberValues, bool clearCurrentValues);
	// Sets the number of values for this variable.
	extern const aiPlanSetNumberUserVariableValues_t aiPlanSetNumberUserVariableValues;

	typedef bool (*aiPlanRemoveUserVariables_t)(int planID);
	// Removes all of the user variables from the given plan.
	extern const aiPlanRemoveUserVariables_t aiPlanRemoveUserVariables;

	typedef bool (*aiPlanRemoveUserVariable_t)(int planID, int planVariableIndex);
	// Removes the user variable.
	extern const aiPlanRemoveUserVariable_t aiPlanRemoveUserVariable;

	typedef bool (*aiPlanRemoveUserVariableValue_t)(int planID, int planVariableIndex, int variableIndex);
	// Removes the index-th value of the user variable.
	extern const aiPlanRemoveUserVariableValue_t aiPlanRemoveUserVariableValue;

	typedef bool (*aiPlanAddUserVariableInt_t)(int planID, int planVariableIndex, string name, int numberValues);
	// Adds the variable to the given plan.
	extern const aiPlanAddUserVariableInt_t aiPlanAddUserVariableInt;

	typedef bool (*aiPlanSetUserVariableInt_t)(int planID, int planVariableIndex, int valueIndex, int value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetUserVariableInt_t aiPlanSetUserVariableInt;

	typedef int (*aiPlanGetUserVariableInt_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetUserVariableInt_t aiPlanGetUserVariableInt;

	typedef bool (*aiPlanAddUserVariableFloat_t)(int planID, int planVariableIndex, string name, int numberValues);
	// Adds the variable to the given plan.
	extern const aiPlanAddUserVariableFloat_t aiPlanAddUserVariableFloat;

	typedef bool (*aiPlanSetUserVariableFloat_t)(int planID, int planVariableIndex, int valueIndex, float value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetUserVariableFloat_t aiPlanSetUserVariableFloat;

	typedef float (*aiPlanGetUserVariableFloat_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetUserVariableFloat_t aiPlanGetUserVariableFloat;

	typedef bool (*aiPlanAddUserVariableVector_t)(int planID, int planVariableIndex, string name, int numberValues);
	// Adds the variable to the given plan.
	extern const aiPlanAddUserVariableVector_t aiPlanAddUserVariableVector;

	typedef bool (*aiPlanSetUserVariableVector_t)(int planID, int planVariableIndex, int valueIndex, vector value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetUserVariableVector_t aiPlanSetUserVariableVector;

	typedef vector (*aiPlanGetUserVariableVector_t)(vector, int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetUserVariableVector_t aiPlanGetUserVariableVector;

	typedef bool (*aiPlanAddUserVariableBool_t)(int planID, int planVariableIndex, string name, int numberValues);
	// Adds the variable to the given plan.
	extern const aiPlanAddUserVariableBool_t aiPlanAddUserVariableBool;

	typedef bool (*aiPlanSetUserVariableBool_t)(int planID, int planVariableIndex, int valueIndex, bool value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetUserVariableBool_t aiPlanSetUserVariableBool;

	typedef bool (*aiPlanGetUserVariableBool_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetUserVariableBool_t aiPlanGetUserVariableBool;

	typedef bool (*aiPlanAddUserVariableString_t)(int planID, int planVariableIndex, string name, int numberValues);
	// Adds the variable to the given plan.
	extern const aiPlanAddUserVariableString_t aiPlanAddUserVariableString;

	typedef bool (*aiPlanSetUserVariableString_t)(int planID, int planVariableIndex, int valueIndex, string value);
	// Sets the given variable of the given plan.
	extern const aiPlanSetUserVariableString_t aiPlanSetUserVariableString;

	typedef string (*aiPlanGetUserVariableString_t)(int planID, int planVariableIndex, int valueIndex);
	// Gets the given variable of the given plan.
	extern const aiPlanGetUserVariableString_t aiPlanGetUserVariableString;

	typedef bool (*aiPlanGetActive_t)(int planID);
	// Gets the active-ness of the given plan.
	extern const aiPlanGetActive_t aiPlanGetActive;

	typedef bool (*aiPlanSetActive_t)(int planID, bool active);
	// Sets active on/off for the given plan.
	extern const aiPlanSetActive_t aiPlanSetActive;

	typedef bool (*aiPlanGetNoMoreUnits_t)(int planID);
	// Gets the noMoreUnits-ness of the given plan.
	extern const aiPlanGetNoMoreUnits_t aiPlanGetNoMoreUnits;

	typedef bool (*aiPlanSetNoMoreUnits_t)(int planID, bool v);
	// Sets noMoreUnits on/off for the given plan.
	extern const aiPlanSetNoMoreUnits_t aiPlanSetNoMoreUnits;

	typedef bool (*aiPlanGetOrphan_t)(int planID);
	// Gets the orphan-ness of the given plan.
	extern const aiPlanGetOrphan_t aiPlanGetOrphan;

	typedef bool (*aiPlanSetOrphan_t)(int planID, bool orphan);
	// Sets orphan on/off for the given plan.
	extern const aiPlanSetOrphan_t aiPlanSetOrphan;

	typedef bool (*aiPlanGetAllowUnderAttackResponse_t)(int planID);
	// Gets the UA response-ness of the given plan.
	extern const aiPlanGetAllowUnderAttackResponse_t aiPlanGetAllowUnderAttackResponse;

	typedef bool (*aiPlanSetAllowUnderAttackResponse_t)(int planID, bool uAR);
	// Sets under attack response on/off for the given plan.
	extern const aiPlanSetAllowUnderAttackResponse_t aiPlanSetAllowUnderAttackResponse;

	typedef int (*aiPlanGetUnitStance_t)(int planID);
	// Gets the unit stance of the given plan.
	extern const aiPlanGetUnitStance_t aiPlanGetUnitStance;

	typedef bool (*aiPlanSetUnitStance_t)(int planID, int stance);
	// Sets unit stance for the given plan.
	extern const aiPlanSetUnitStance_t aiPlanSetUnitStance;

	typedef bool (*aiPlanSetRequiresAllNeedUnits_t)(int planID, bool rANU);
	// Sets 'requiresAllNeedUnits' on/off for the given plan.
	extern const aiPlanSetRequiresAllNeedUnits_t aiPlanSetRequiresAllNeedUnits;

	typedef bool (*aiPlanSetEventHandler_t)(int planID, int eventType, string handlerName);
	// Sets event handler function for the given plan and event.
	extern const aiPlanSetEventHandler_t aiPlanSetEventHandler;

	typedef bool (*aiPlanSetEscrowID_t)(int planID, int escrowID);
	// Sets the escrow for the plan.
	extern const aiPlanSetEscrowID_t aiPlanSetEscrowID;

	typedef int (*aiPlanGetEscrowID_t)(int planID);
	// Gets the escrow for the plan.
	extern const aiPlanGetEscrowID_t aiPlanGetEscrowID;

	typedef bool (*aiPlanGetEconomy_t)(int planID);
	// Gets the economy flag of the given plan.
	extern const aiPlanGetEconomy_t aiPlanGetEconomy;

	typedef bool (*aiPlanSetEconomy_t)(int planID, bool v);
	// Sets economy on/off for the given plan.
	extern const aiPlanSetEconomy_t aiPlanSetEconomy;

	typedef bool (*aiPlanGetMilitary_t)(int planID);
	// Gets the military flag of the given plan.
	extern const aiPlanGetMilitary_t aiPlanGetMilitary;

	typedef bool (*aiPlanSetMilitary_t)(int planID, bool v);
	// Sets military on/off for the given plan.
	extern const aiPlanSetMilitary_t aiPlanSetMilitary;

	typedef bool (*aiPlanGetAttack_t)(int planID);
	// Gets the attack flag of the given plan.
	extern const aiPlanGetAttack_t aiPlanGetAttack;

	typedef bool (*aiPlanSetAttack_t)(int planID, bool v);
	// Sets attack flag on/off for the given plan.
	extern const aiPlanSetAttack_t aiPlanSetAttack;

	typedef bool (*aiPlanSetBaseID_t)(int planID, int baseID);
	// sets the plan's base id.
	extern const aiPlanSetBaseID_t aiPlanSetBaseID;

	typedef int (*aiPlanGetBaseID_t)(int planID);
	// gets the plan's base id.
	extern const aiPlanGetBaseID_t aiPlanGetBaseID;

	typedef int (*aiGetNumberIdlePlans_t)(int planType);
	// Gets the of idle plans of the given type.
	extern const aiGetNumberIdlePlans_t aiGetNumberIdlePlans;

	typedef float (*aiPlanGetUnitCost_t)(int planID, bool considerHitPoints);
	// gets total aiCost of plan's units, weighted for HP if requested.
	extern const aiPlanGetUnitCost_t aiPlanGetUnitCost;

	typedef void (*aiCommsAllowChat_t)(bool flag);
	// enables or disables the chats from this ai player.
	extern const aiCommsAllowChat_t aiCommsAllowChat;

	typedef int (*aiCommsSendStatement_t)(int targetPlayerID, int promptType);
	// Sends a statement to the designated player.
	extern const aiCommsSendStatement_t aiCommsSendStatement;

	typedef int (*aiCommsSendStatementWithVector_t)(int targetPlayerID, int promptType, vector v);
	// Sends a statement to the designated player. Adds a location flare.
	extern const aiCommsSendStatementWithVector_t aiCommsSendStatementWithVector;

	typedef bool (*aiCommsSetEventHandler_t)(string handlerFunctionName);
	// Sets the handler for the communications system (invalid name unsets the handler).
	extern const aiCommsSetEventHandler_t aiCommsSetEventHandler;

	typedef int (*aiCommsGetSendingPlayer_t)(int sentenceID);
	// get sending player for specified sentence.
	extern const aiCommsGetSendingPlayer_t aiCommsGetSendingPlayer;

	typedef int (*aiCommsGetChatVerb_t)(int sentenceID);
	// get chat verb for specified sentence.
	extern const aiCommsGetChatVerb_t aiCommsGetChatVerb;

	typedef int (*aiCommsGetChatTargetType_t)(int sentenceID);
	// get target type for specified sentence.
	extern const aiCommsGetChatTargetType_t aiCommsGetChatTargetType;

	typedef int (*aiCommsGetTargetListCount_t)(int sentenceID);
	// get number of items in target list for specified sentence.
	extern const aiCommsGetTargetListCount_t aiCommsGetTargetListCount;

	typedef int (*aiCommsGetTargetListItem_t)(int sentenceID, int index);
	// get index item from specified sentence.
	extern const aiCommsGetTargetListItem_t aiCommsGetTargetListItem;

	typedef vector (*aiCommsGetTargetLocation_t)(vector, int sentenceID);
	// get target location from specified sentence.
	extern const aiCommsGetTargetLocation_t aiCommsGetTargetLocation;

	typedef void (*aiCommsSendReply_t)(int sentenceID, int responseID);
	// send a reply to a sentence.
	extern const aiCommsSendReply_t aiCommsSendReply;

	typedef bool (*aiSetHandler_t)(string handlerFunctionName, int type);
	// Sets the handler for given type of event.
	extern const aiSetHandler_t aiSetHandler;

	typedef bool (*aiTaskUnitMove_t)(int unitID, vector position);
	// Does a lightweight (no plan) move tasking of the given unit to the given location.
	extern const aiTaskUnitMove_t aiTaskUnitMove;

	typedef bool (*aiTaskUnitWork_t)(int unitID, int targetUnitID);
	// Does a lightweight (no plan) work tasking of the given unit on the given target unit.
	extern const aiTaskUnitWork_t aiTaskUnitWork;

	typedef bool (*aiTaskUnitBuild_t)(int unitID, int buildingTypeID, vector position);
	// Does a lightweight (no plan) build tasking of the given unit to build the given building.
	extern const aiTaskUnitBuild_t aiTaskUnitBuild;

	typedef bool (*aiTaskUnitTrain_t)(int unitID, int unitTypeID);
	// Does a lightweight (no plan) train tasking of the given unit for the given target unit type.
	extern const aiTaskUnitTrain_t aiTaskUnitTrain;

	typedef bool (*aiTaskUnitResearch_t)(int unitID, int techID);
	// Does a lightweight (no plan) research tasking of the given unit for the given tech ID.
	extern const aiTaskUnitResearch_t aiTaskUnitResearch;

	typedef bool (*aiTaskUnitSpecialPower_t)(int unitID, int powerID, vector position);
	// Does a lightweight (no plan) research tasking of the given unit for the given special power.
	extern const aiTaskUnitSpecialPower_t aiTaskUnitSpecialPower;

	typedef bool (*aiTaskUnitDelete_t)(int unitID);
	// Deletes the given unit.
	extern const aiTaskUnitDelete_t aiTaskUnitDelete;

	typedef bool (*aiTribute_t)(int playerID, int resourceID, float amount);
	// Tributes the given player.
	extern const aiTribute_t aiTribute;

	typedef bool (*aiSellResourceOnMarket_t)(int resourceID);
	// sells (+100) the given resource.
	extern const aiSellResourceOnMarket_t aiSellResourceOnMarket;

	typedef bool (*aiBuyResourceOnMarket_t)(int resourceID);
	// buys (+100) the given resource.
	extern const aiBuyResourceOnMarket_t aiBuyResourceOnMarket;

	typedef float (*aiGetMarketBuyCost_t)(int resourceID);
	// Returns the amount required to buy 100 units of the given resource.
	extern const aiGetMarketBuyCost_t aiGetMarketBuyCost;

	typedef float (*aiGetMarketSellCost_t)(int resourceID);
	// Returns the amount received for selling 100 units of the given resource.
	extern const aiGetMarketSellCost_t aiGetMarketSellCost;

	typedef float (*aiGetResourceGathererPercentageWeight_t)(int rgpIndex);
	// Returns the RGP weight.
	extern const aiGetResourceGathererPercentageWeight_t aiGetResourceGathererPercentageWeight;

	typedef void (*aiSetResourceGathererPercentageWeight_t)(int rgpIndex, float weight);
	// Sets the RGP weight.
	extern const aiSetResourceGathererPercentageWeight_t aiSetResourceGathererPercentageWeight;

	typedef void (*aiNormalizeResourceGathererPercentageWeights_t)();
	// Normalizes all of the resource gatherer percentages weights to 1.0.
	extern const aiNormalizeResourceGathererPercentageWeights_t aiNormalizeResourceGathererPercentageWeights;

	typedef float (*aiGetResourceGathererPercentage_t)(int resourceID, int rgpIndex);
	// Returns the resource gatherer percentage for the given resource.
	extern const aiGetResourceGathererPercentage_t aiGetResourceGathererPercentage;

	typedef void (*aiSetResourceGathererPercentage_t)(int resourceID, float value, bool normalize, int rgpIndex);
	// Sets the resource gatherer percentage for the given resource (if normalized is true, the percentages will be normalized to 1.0).
	extern const aiSetResourceGathererPercentage_t aiSetResourceGathererPercentage;

	typedef void (*aiNormalizeResourceGathererPercentages_t)(int rgpIndex);
	// Normalizes all of the resource gatherer percentages to 1.0.
	extern const aiNormalizeResourceGathererPercentages_t aiNormalizeResourceGathererPercentages;

	typedef int (*aiGetResourceBreakdownNumberPlans_t)(int resourceTypeID, int resourceSubTypeID, int baseID);
	// Gets the number of plans for the given breakdown.
	extern const aiGetResourceBreakdownNumberPlans_t aiGetResourceBreakdownNumberPlans;

	typedef int (*aiGetResourceBreakdownPlanPriority_t)(int resourceTypeID, int resourceSubTypeID, int baseID);
	// Gets the priority of the plans for the given breakdown.
	extern const aiGetResourceBreakdownPlanPriority_t aiGetResourceBreakdownPlanPriority;

	typedef float (*aiGetResourceBreakdownPercentage_t)(int resourceTypeID, int resourceSubTypeID, int baseID);
	// Gets the percentage for the given breakdown.
	extern const aiGetResourceBreakdownPercentage_t aiGetResourceBreakdownPercentage;

	typedef bool (*aiSetResourceBreakdown_t)(int resourceTypeID, int resourceSubTypeID, int numberPlans, int planPriority, float percentage, int baseID);
	// Sets a subtype breakdown for a resource.
	extern const aiSetResourceBreakdown_t aiSetResourceBreakdown;

	typedef bool (*aiRemoveResourceBreakdown_t)(int resourceTypeID, int resourceSubTypeID, int baseID);
	// Removes the given breakdown.
	extern const aiRemoveResourceBreakdown_t aiRemoveResourceBreakdown;

	typedef int (*aiGetAutoGatherEscrowID_t)();
	// Returns the auto gather escrow ID.
	extern const aiGetAutoGatherEscrowID_t aiGetAutoGatherEscrowID;

	typedef void (*aiSetAutoGatherEscrowID_t)(int escrowID);
	// Sets the auto gather escrow ID.
	extern const aiSetAutoGatherEscrowID_t aiSetAutoGatherEscrowID;

	typedef int (*aiGetAutoFarmEscrowID_t)();
	// Returns the auto Farm escrow ID.
	extern const aiGetAutoFarmEscrowID_t aiGetAutoFarmEscrowID;

	typedef void (*aiSetAutoFarmEscrowID_t)(int escrowID);
	// Sets the auto Farm escrow ID.
	extern const aiSetAutoFarmEscrowID_t aiSetAutoFarmEscrowID;

	typedef int (*aiGetFarmLimit_t)();
	// Returns the per plan farm build limit.
	extern const aiGetFarmLimit_t aiGetFarmLimit;

	typedef void (*aiSetFarmLimit_t)(int limit);
	// Sets the per plan farm build limit.
	extern const aiSetFarmLimit_t aiSetFarmLimit;

	typedef bool (*aiGetAllowBuildings_t)();
	// Returns allow buildings on/off.
	extern const aiGetAllowBuildings_t aiGetAllowBuildings;

	typedef void (*aiSetAllowBuildings_t)(bool v);
	// Sets allow buildings on/off.
	extern const aiSetAllowBuildings_t aiSetAllowBuildings;

	typedef void (*aiChat_t)(int playerID, string chatString);
	// CP AI chat to playerID.
	extern const aiChat_t aiChat;

	typedef void (*aiSendChatToEveryone_t)(string chatString);
	// CP AI chat to everyone.
	extern const aiSendChatToEveryone_t aiSendChatToEveryone;

	typedef void (*aiSendChatToAllies_t)(string chatString);
	// CP AI chat to allies.
	extern const aiSendChatToAllies_t aiSendChatToAllies;

	typedef void (*aiSendChatToEnemies_t)(string chatString);
	// CP AI chat to enemies.
	extern const aiSendChatToEnemies_t aiSendChatToEnemies;

	typedef int (*aiNumberUnassignedUnits_t)(int typeID);
	// Returns the number of unassigned units of the given type.
	extern const aiNumberUnassignedUnits_t aiNumberUnassignedUnits;

	typedef int (*aiNumberUnassignedUnitsByGoal_t)(int goalID);
	// Returns the number of unassigned units based on the goal's unit type(s).
	extern const aiNumberUnassignedUnitsByGoal_t aiNumberUnassignedUnitsByGoal;

	typedef int (*aiCreateOpportunity_t)(int type, int targettype, int targetID, int targetPlayerID, int source);
	// adds an opportunity to the list and returns the id.
	extern const aiCreateOpportunity_t aiCreateOpportunity;

	typedef void (*aiActivateOpportunity_t)(int opportunityID, bool flag);
	// activates or deactivates an opportunity on the player's opp list.
	extern const aiActivateOpportunity_t aiActivateOpportunity;

	typedef void (*aiDestroyOpportunity_t)(int opportunityID);
	// remove an opportunity on the player's opp list.
	extern const aiDestroyOpportunity_t aiDestroyOpportunity;

	typedef void (*aiFindBestOpportunity_t)();
	// finds the best currently scored opp.
	extern const aiFindBestOpportunity_t aiFindBestOpportunity;

	typedef int (*aiGetOpportunitySourceID_t)(int opportunityID);
	// gets the source id from this opportunity
	extern const aiGetOpportunitySourceID_t aiGetOpportunitySourceID;

	typedef int (*aiGetOpportunitySourceType_t)(int opportunityID);
	// gets the source type from this opportunity
	extern const aiGetOpportunitySourceType_t aiGetOpportunitySourceType;

	typedef float (*aiGetOpportunityRadius_t)(float opportunityID);
	// gets the radius from this opportunity
	extern const aiGetOpportunityRadius_t aiGetOpportunityRadius;

	typedef int (*aiGetOpportunityTargetPlayerID_t)(int opportunityID);
	// gets the target playerID from this opportunity
	extern const aiGetOpportunityTargetPlayerID_t aiGetOpportunityTargetPlayerID;

	typedef int (*aiGetOpportunityTargetType_t)(int opportunityID);
	// gets the target type from this opportunity
	extern const aiGetOpportunityTargetType_t aiGetOpportunityTargetType;

	typedef int (*aiGetOpportunityType_t)(int opportunityID);
	// gets the type from this opportunity
	extern const aiGetOpportunityType_t aiGetOpportunityType;

	typedef vector (*aiGetOpportunityLocation_t)(vector, int opportunityID);
	// gets the location from this opportunity
	extern const aiGetOpportunityLocation_t aiGetOpportunityLocation;

	typedef int (*aiGetOpportunityTargetID_t)(int opportunityID);
	// gets the target id from this opportunity
	extern const aiGetOpportunityTargetID_t aiGetOpportunityTargetID;

	typedef void (*aiSetOpportunityTargetType_t)(int opportunityID, int targetType);
	// sets the target type for this opp.
	extern const aiSetOpportunityTargetType_t aiSetOpportunityTargetType;

	typedef void (*aiSetOpportunityTargetID_t)(int opportunityID, int targetType);
	// sets the target id for this opp.
	extern const aiSetOpportunityTargetID_t aiSetOpportunityTargetID;

	typedef void (*aiSetOpportunityRadius_t)(int opportunityID, float radius);
	// sets the radius for this opp.
	extern const aiSetOpportunityRadius_t aiSetOpportunityRadius;

	typedef void (*aiSetOpportunityLocation_t)(int opportunityID, vector location);
	// sets the location for this opp.
	extern const aiSetOpportunityLocation_t aiSetOpportunityLocation;

	typedef bool (*aiSetOpportunityScore_t)(int oppID, int permission, float affordable, float classscore, float instance, float total);
	// sets the score for this opp.
	extern const aiSetOpportunityScore_t aiSetOpportunityScore;

	typedef bool (*aiCastGodPowerAtPosition_t)(int godPowerTechID, vector pos);
	// Casts the given God power tech, at the specified position.
	extern const aiCastGodPowerAtPosition_t aiCastGodPowerAtPosition;

	typedef bool (*aiCastGodPowerAtUnit_t)(int godPowerTechID, int unitID);
	// Casts the given God power tech, at the specified unit.
	extern const aiCastGodPowerAtUnit_t aiCastGodPowerAtUnit;

	typedef int (*aiGetGodPowerTechIDForSlot_t)(int slotID);
	// Get the god power tech id from the given slot.
	extern const aiGetGodPowerTechIDForSlot_t aiGetGodPowerTechIDForSlot;

	typedef int (*aiGetGodPowerProtoIDForTechID_t)(int techID);
	// translate a granted tech id into a protopower id
	extern const aiGetGodPowerProtoIDForTechID_t aiGetGodPowerProtoIDForTechID;

	typedef int (*aiGetGodPowerType_t)(int protoPowerID);
	// get the type for a ProtoPower
	extern const aiGetGodPowerType_t aiGetGodPowerType;

	typedef int (*aiFindBestAttackGodPowerPlan_t)();
	// find a valid god power plan to attach to an attack plan
	extern const aiFindBestAttackGodPowerPlan_t aiFindBestAttackGodPowerPlan;

	typedef int (*aiFindBestTownDefenseGodPowerPlan_t)();
	// find a valid god power plan to use for town defense
	extern const aiFindBestTownDefenseGodPowerPlan_t aiFindBestTownDefenseGodPowerPlan;

	typedef int (*aiGetWorldDifficulty_t)();
	// Returns the world difficulty level.
	extern const aiGetWorldDifficulty_t aiGetWorldDifficulty;

	typedef void (*aiSetWorldDifficulty_t)(int v);
	// Sets the world difficulty level.
	extern const aiSetWorldDifficulty_t aiSetWorldDifficulty;

	typedef string (*aiGetWorldDifficultyName_t)(int level);
	// Returns the name of the level.
	extern const aiGetWorldDifficultyName_t aiGetWorldDifficultyName;

	typedef int (*aiGetGameMode_t)();
	// Returns the game's mode.
	extern const aiGetGameMode_t aiGetGameMode;

	typedef int (*aiGetCaptainPlayerID_t)(int playerID);
	// Returns the captain for the given player's team.
	extern const aiGetCaptainPlayerID_t aiGetCaptainPlayerID;

	typedef void (*aiAutoSavegame_t)(string filename);
	// Saves the auto, debugging savegames (THIS DOESN'T REALLY DO ANYTHING).
	extern const aiAutoSavegame_t aiAutoSavegame;

	typedef bool (*aiGetAutosaveOn_t)();
	// returns whether or not its cool to turn ai autosaves on.
	extern const aiGetAutosaveOn_t aiGetAutosaveOn;

	typedef float (*aiGetCurrentResourceNeed_t)(int resourceID);
	// returns the current resource need for the given resource.
	extern const aiGetCurrentResourceNeed_t aiGetCurrentResourceNeed;

	typedef bool (*aiSetAutoGatherMilitaryUnits_t)(bool v);
	// Turns auto gathering of military units at bases on/off.
	extern const aiSetAutoGatherMilitaryUnits_t aiSetAutoGatherMilitaryUnits;

	typedef bool (*aiSetExploreDangerThreshold_t)(float value);
	// sets the ai's Explore Danger Threshold value.
	extern const aiSetExploreDangerThreshold_t aiSetExploreDangerThreshold;

	typedef float (*aiGetExploreDangerThreshold_t)();
	// gets the ai's Explore Danger Threshold value.
	extern const aiGetExploreDangerThreshold_t aiGetExploreDangerThreshold;

	typedef void (*aiSetRandomMap_t)(bool v);
	// Sets the RM bool in the AI.
	extern const aiSetRandomMap_t aiSetRandomMap;

	typedef void (*aiSetPauseAllAgeUpgrades_t)(bool v);
	// sets the pause all age upgrades flag in the AI.
	extern const aiSetPauseAllAgeUpgrades_t aiSetPauseAllAgeUpgrades;

	typedef bool (*aiGetPauseAllAgeUpgrades_t)(bool);
	// gets the pause all age upgrades flag from the AI.
	extern const aiGetPauseAllAgeUpgrades_t aiGetPauseAllAgeUpgrades;

	typedef void (*aiSetMinArmySize_t)(int v);
	// sets the min number of units in an attack army.
	extern const aiSetMinArmySize_t aiSetMinArmySize;

	typedef void (*aiSetMinNumberNeedForGatheringAggressvies_t)(int v);
	// sets the min number of needed units to gather aggressive animals.
	extern const aiSetMinNumberNeedForGatheringAggressvies_t aiSetMinNumberNeedForGatheringAggressvies;

	typedef int (*aiGetMinNumberNeedForGatheringAggressives_t)();
	// gets the min number of needed units to gather aggressive animals.
	extern const aiGetMinNumberNeedForGatheringAggressives_t aiGetMinNumberNeedForGatheringAggressives;

	typedef void (*aiSetMinNumberWantForGatheringAggressives_t)(int v);
	// sets the min number of wanted units to gather aggressive animals.
	extern const aiSetMinNumberWantForGatheringAggressives_t aiSetMinNumberWantForGatheringAggressives;

	typedef int (*aiGetMinNumberWantForGatheringAggressives_t)();
	// gets the min number of wanted units to gather aggressive animals.
	extern const aiGetMinNumberWantForGatheringAggressives_t aiGetMinNumberWantForGatheringAggressives;

	typedef void (*aiResign_t)();
	// reigns the current player..
	extern const aiResign_t aiResign;

	typedef void (*aiAttemptResign_t)(int);
	// asks the player if its ok to resign
	extern const aiAttemptResign_t aiAttemptResign;

	typedef void (*aiSetMaxLOSProtoUnitLimit_t)(int limit);
	// sets the limit for how many LOS Protounits the AI can build
	extern const aiSetMaxLOSProtoUnitLimit_t aiSetMaxLOSProtoUnitLimit;

	typedef int (*aiGetMaxLOSProtoUnitLimit_t)();
	// gets the limit for how many LOS Protounits the AI can build
	extern const aiGetMaxLOSProtoUnitLimit_t aiGetMaxLOSProtoUnitLimit;

	typedef int (*aiGetPopNeeds_t)();
	// gets the current Pop needs of all the plans.
	extern const aiGetPopNeeds_t aiGetPopNeeds;

	typedef void (*aiSwitchMainBase_t)(int newBaseID, bool force);
	// switch the newBaseID to be the main base.
	extern const aiSwitchMainBase_t aiSwitchMainBase;

	typedef void (*aiSetDefaultStance_t)(int defaultStance);
	// Sets your default stance for all of your units.
	extern const aiSetDefaultStance_t aiSetDefaultStance;

	typedef void (*aiSetWaterMap_t)(bool v);
	// Tells the AI if this is a water map or not.
	extern const aiSetWaterMap_t aiSetWaterMap;

	typedef bool (*aiGetWaterMap_t)();
	// Tells us if the AI thinks this is a water map or not.
	extern const aiGetWaterMap_t aiGetWaterMap;

	typedef bool (*aiIsMapType_t)(string);
	// Is this a certain maptype or not. (AIFishingUseful, AITransportRequired, AITransportUseful)
	extern const aiIsMapType_t aiIsMapType;

	typedef int (*aiHCCardsGetTotal_t)();
	// Returns the number of cards in the Current HC.
	extern const aiHCCardsGetTotal_t aiHCCardsGetTotal;

	typedef bool (*aiHCCardsIsCardBought_t)(int cardIndex);
	// Has the cardindex been bought yet?
	extern const aiHCCardsIsCardBought_t aiHCCardsIsCardBought;

	typedef bool (*aiHCCardsCanIBuyThisCard_t)(int deckIndex, int cardIndex);
	// Can I buy this card now?
	extern const aiHCCardsCanIBuyThisCard_t aiHCCardsCanIBuyThisCard;

	typedef bool (*aiHCCardsBuyCard_t)(int cardIndex);
	// Buy this card now
	extern const aiHCCardsBuyCard_t aiHCCardsBuyCard;

	typedef int (*aiHCCardsGetCardAgePrereq_t)(int cardIndex);
	// For this cardIndex, get the age prereq.
	extern const aiHCCardsGetCardAgePrereq_t aiHCCardsGetCardAgePrereq;

	typedef int (*aiHCCardsGetCardLevel_t)(int cardIndex);
	// For this cardIndex, get the age prereq.
	extern const aiHCCardsGetCardLevel_t aiHCCardsGetCardLevel;

	typedef int (*aiHCCardsGetCardTechID_t)(int);
	// For this cardIndex, get the TechID.
	extern const aiHCCardsGetCardTechID_t aiHCCardsGetCardTechID;

	typedef int (*aiHCCardsGetCardUnitType_t)(int);
	// For this cardIndex, get the UnitType.
	extern const aiHCCardsGetCardUnitType_t aiHCCardsGetCardUnitType;

	typedef int (*aiHCCardsGetCardUnitCount_t)(int);
	// For this cardIndex, get the UnitCount.
	extern const aiHCCardsGetCardUnitCount_t aiHCCardsGetCardUnitCount;

	typedef int (*aiHCCardsGetCardCount_t)(int);
	// For this cardIndex, get the CardCount, -1 is Infinite.
	extern const aiHCCardsGetCardCount_t aiHCCardsGetCardCount;

	typedef int (*aiHCCardsFindBestCard_t)(int cardType, int levelPref, int resourcePref);
	// Get the best card using the optional cardtype and optional resourcePreference
	extern const aiHCCardsFindBestCard_t aiHCCardsFindBestCard;

	typedef int (*aiHCGetNumberDecks_t)();
	// Returns the number of decks in the Current HC.
	extern const aiHCGetNumberDecks_t aiHCGetNumberDecks;

	typedef int (*aiHCDeckCreate_t)(string);
	// Create a new HC Deck with the given name.
	extern const aiHCDeckCreate_t aiHCDeckCreate;

	typedef bool (*aiHCDeckActivate_t)(int deckIndex);
	// Makes the deckIndex the current active HC deck.
	extern const aiHCDeckActivate_t aiHCDeckActivate;

	typedef bool (*aiHCDeckAddCardToDeck_t)(int deckIndex, int cardIndex);
	// Adds the card given to the givenHC Deck.
	extern const aiHCDeckAddCardToDeck_t aiHCDeckAddCardToDeck;

	typedef int (*aiHCDeckGetNumberCards_t)(int deckIndex);
	// Returns the number of cards in the Current HC Deck.
	extern const aiHCDeckGetNumberCards_t aiHCDeckGetNumberCards;

	typedef bool (*aiHCDeckPlayCard_t)(int cardIndex);
	// play this card.
	extern const aiHCDeckPlayCard_t aiHCDeckPlayCard;

	typedef int (*aiHCDeckGetCardAgePrereq_t)(int deckIndex, int cardIndex);
	// For this card, get the age prereq
	extern const aiHCDeckGetCardAgePrereq_t aiHCDeckGetCardAgePrereq;

	typedef int (*aiHCDeckGetCardLevel_t)(int deckIndex, int cardIndex);
	// For this card, get the level
	extern const aiHCDeckGetCardLevel_t aiHCDeckGetCardLevel;

	typedef int (*aiHCDeckGetCardTechID_t)(int deckIndex, int cardIndex);
	// For this card, get the techID
	extern const aiHCDeckGetCardTechID_t aiHCDeckGetCardTechID;

	typedef int (*aiHCDeckGetCardUnitType_t)(int deckIndex, int cardIndex);
	// For this card, get the unitType
	extern const aiHCDeckGetCardUnitType_t aiHCDeckGetCardUnitType;

	typedef int (*aiHCDeckGetCardUnitCount_t)(int deckIndex, int cardIndex);
	// For this card, get the unit Count
	extern const aiHCDeckGetCardUnitCount_t aiHCDeckGetCardUnitCount;

	typedef bool (*aiHCDeckCanPlayCard_t)(int cardIndex);
	// Can we play this card from the given deck?
	extern const aiHCDeckCanPlayCard_t aiHCDeckCanPlayCard;

	typedef int (*aiHCDeckCardGetCardCount_t)(int deskIndex, int cardIndex);
	// Gets how many cards of this type we can send. -1 mean infinite.
	extern const aiHCDeckCardGetCardCount_t aiHCDeckCardGetCardCount;

	typedef vector (*aiGetHCGatherPoint_t)(vector);
	// Returns the HCGP.
	extern const aiGetHCGatherPoint_t aiGetHCGatherPoint;

	typedef bool (*aiSetHCGatherPoint_t)();
	// Sets the HCGP.
	extern const aiSetHCGatherPoint_t aiSetHCGatherPoint;

	typedef int (*aiGetScore_t)(int playerID);
	// returns the score for the given player.
	extern const aiGetScore_t aiGetScore;

	typedef int (*aiGetNumberTeams_t)();
	// returns the number of teams in the game.
	extern const aiGetNumberTeams_t aiGetNumberTeams;

	typedef void (*aiQueueAutoSavegame_t)(int saveNumber);
	// Queues the auto savegame.
	extern const aiQueueAutoSavegame_t aiQueueAutoSavegame;

	typedef bool (*aiIsMultiplayer_t)();
	// returns true, if this is a multiplayer game.
	extern const aiIsMultiplayer_t aiIsMultiplayer;

	typedef int (*aiGetFallenExplorerID_t)();
	// returns the ID of the fallen explorer; if there isn't one, returns -1
	extern const aiGetFallenExplorerID_t aiGetFallenExplorerID;

	typedef bool (*aiRansomExplorer_t)(int explorerID, int escrowID, int sourceBuildingID);
	// ransoms the specified explorer using funds from the specified escrow account and spawns it from the specified building.
	extern const aiRansomExplorer_t aiRansomExplorer;

	typedef bool (*aiBuildWall_t)(int buildingID, int escrowID);
	// builds walls around the specified building's colony using the specified escrow.
	extern const aiBuildWall_t aiBuildWall;

	typedef bool (*aiCanBuildWall_t)(int buildingID, int escrowID);
	// returns whether it is allowed to build a wall around the specified building's colony, and whether the player can afford it from the specified escrow.
	extern const aiCanBuildWall_t aiCanBuildWall;

	typedef float (*aiGetWallRadius_t)(int buildingID);
	// returns the wall radius for the specified building's colony.
	extern const aiGetWallRadius_t aiGetWallRadius;

	typedef bool (*aiDoesWallExist_t)(int buildingID);
	// returns whether a wall exists around the specified building's colony.
	extern const aiDoesWallExist_t aiDoesWallExist;

	typedef int (*aiGetGameType_t)();
	// returns the current game type (e.g., cGameTypeScenario, cGameTypeRandom, etc).
	extern const aiGetGameType_t aiGetGameType;

	typedef bool (*aiUnitSetTactic_t)(int unitID, int tacticID);
	// sets the specified tactic on the specified unit.
	extern const aiUnitSetTactic_t aiUnitSetTactic;

	typedef int (*aiUnitGetTactic_t)(int unitID);
	// gets the specified unit's current tactic.
	extern const aiUnitGetTactic_t aiUnitGetTactic;

	typedef void (*aiResourceLock_t)(int resourceID);
	// Prevent a resource from being spent by the AI.
	extern const aiResourceLock_t aiResourceLock;

	typedef void (*aiResourceUnlock_t)(int resourceID);
	// Allow a resource to be spent by the AI.
	extern const aiResourceUnlock_t aiResourceUnlock;

	typedef bool (*aiResourceIsLocked_t)(int resourceID);
	// Is this Escrow resource locked.
	extern const aiResourceIsLocked_t aiResourceIsLocked;

	typedef bool (*aiBreakTreaty_t)(int escrowID);
	// breaks the treaty using funds from the given escrow.
	extern const aiBreakTreaty_t aiBreakTreaty;

	typedef bool (*aiTreatyActive_t)();
	// checks whether the given player has a treaty.
	extern const aiTreatyActive_t aiTreatyActive;

	typedef void (*aiSetPoliticianChoice_t)(int age, int puid);
	// Sets the scripts choice for the AgeX Politician.
	extern const aiSetPoliticianChoice_t aiSetPoliticianChoice;

	typedef int (*aiGetPoliticianChoice_t)(int age);
	// Gets the scripts choice for the AgeX Politician.
	extern const aiGetPoliticianChoice_t aiGetPoliticianChoice;

	typedef bool (*aiPopulatePoliticianList_t)();
	// Call this to make the AI fill out what Politicians are available.
	extern const aiPopulatePoliticianList_t aiPopulatePoliticianList;

	typedef int (*aiGetPoliticianListCount_t)(int age);
	// Gets the number of Politicans avaiable for AgeX.
	extern const aiGetPoliticianListCount_t aiGetPoliticianListCount;

	typedef int (*aiGetPoliticianListByIndex_t)(int age, int index);
	// Gets the index'th Politicans avaiable for AgeX.
	extern const aiGetPoliticianListByIndex_t aiGetPoliticianListByIndex;

	typedef int (*aiGetLastCollectedNuggetType_t)(int playerID);
	// Gets the last collected nugget's type
	extern const aiGetLastCollectedNuggetType_t aiGetLastCollectedNuggetType;

	typedef int (*aiGetLastCollectedNuggetEffect_t)(int playerID);
	// Gets the last collected nugget's effect
	extern const aiGetLastCollectedNuggetEffect_t aiGetLastCollectedNuggetEffect;

	typedef int (*aiGetNumberTradePostsControlled_t)(int teamID);
	// Gets the number of tradeposts controlled by this team (for monopoly victory).
	extern const aiGetNumberTradePostsControlled_t aiGetNumberTradePostsControlled;

	typedef int (*aiGetNumberTradePostsNeededForMonopoly_t)();
	// Gets the number of tradeposts needed to make a monopoly win possible.
	extern const aiGetNumberTradePostsNeededForMonopoly_t aiGetNumberTradePostsNeededForMonopoly;

	typedef bool (*aiReadyForTradeMonopoly_t)();
	// Returns true if the monopoly command can be given now.  Does not check cost.
	extern const aiReadyForTradeMonopoly_t aiReadyForTradeMonopoly;

	typedef bool (*aiDoTradeMonopoly_t)();
	// Executes a trade monopoly command, returns false if it fails.
	extern const aiDoTradeMonopoly_t aiDoTradeMonopoly;

	typedef bool (*aiIsMonopolyAllowed_t)();
	// Returns true if a trade monopoly is possible in this game type.
	extern const aiIsMonopolyAllowed_t aiIsMonopolyAllowed;

	typedef int (*aiGetNumberRelicsControlled_t)(int teamID);
	// Gets the number of relics controlled by this team (for relic victory).
	extern const aiGetNumberRelicsControlled_t aiGetNumberRelicsControlled;

	typedef int (*aiGetNumberRelicsNeededForVictory_t)();
	// Gets the number of relics needed to make a relic win possible.
	extern const aiGetNumberRelicsNeededForVictory_t aiGetNumberRelicsNeededForVictory;

	typedef bool (*aiIsRelicCaptureAllowed_t)();
	// Returns true if a relic capture victory is possible in this game type.
	extern const aiIsRelicCaptureAllowed_t aiIsRelicCaptureAllowed;

	typedef bool (*aiIsKOTHAllowed_t)();
	// Returns true if a King of the Hill victory is possible in this game type.
	extern const aiIsKOTHAllowed_t aiIsKOTHAllowed;

	typedef int (*aiGetKOTHController_t)();
	// Gets the team that is king of the hill.
	extern const aiGetKOTHController_t aiGetKOTHController;

	typedef bool (*aiIsTeamKOTH_t)(int teamID);
	// Returns true if this team is king of the hill.
	extern const aiIsTeamKOTH_t aiIsTeamKOTH;

	typedef void (*kbDump_t)(int player1, int player2);
	// KB dump for player2's units from player1's perspective.
	extern const kbDump_t kbDump;

	typedef void (*kbDumpType_t)(int player1, int player2, string typeName);
	// KB dump for player2's units of the given type from player1's perspective.
	extern const kbDumpType_t kbDumpType;

	typedef void (*kbLookAtAllUnitsOnMap_t)();
	// Cheats and looks at all of the units on the map.  This will format your harddrive if you're not authorized to use it.
	extern const kbLookAtAllUnitsOnMap_t kbLookAtAllUnitsOnMap;

	typedef int (*kbGetPop_t)();
	// Returns the current population for the player.
	extern const kbGetPop_t kbGetPop;

	typedef int (*kbGetPopCap_t)();
	// Returns the current population cap for the player.
	extern const kbGetPopCap_t kbGetPopCap;

	typedef int (*kbGetAge_t)();
	// Returns the current age for the current player.
	extern const kbGetAge_t kbGetAge;

	typedef int (*kbGetAgeForPlayer_t)(int id);
	// Returns the current age for the player specified.
	extern const kbGetAgeForPlayer_t kbGetAgeForPlayer;

	typedef int (*kbGetCulture_t)();
	// Returns the culture for the player.
	extern const kbGetCulture_t kbGetCulture;

	typedef int (*kbGetCultureForPlayer_t)(int);
	// Returns the culture for the given player.
	extern const kbGetCultureForPlayer_t kbGetCultureForPlayer;

	typedef string (*kbGetCultureName_t)(int);
	// Returns the culture name for the given culture.
	extern const kbGetCultureName_t kbGetCultureName;

	typedef int (*kbGetCiv_t)();
	// Returns the civilization for the player.
	extern const kbGetCiv_t kbGetCiv;

	typedef int (*kbGetCivForPlayer_t)(int);
	// Returns the civ for the given player.
	extern const kbGetCivForPlayer_t kbGetCivForPlayer;

	typedef string (*kbGetCivName_t)(int civID);
	// Returns the civ name for the given civ.
	extern const kbGetCivName_t kbGetCivName;

	typedef int (*kbUnitQueryCreate_t)(string name);
	// Creates a unit query, returns the query ID.
	extern const kbUnitQueryCreate_t kbUnitQueryCreate;

	typedef bool (*kbUnitQueryResetData_t)(int queryID);
	// Resets the given unit query data AND results.
	extern const kbUnitQueryResetData_t kbUnitQueryResetData;

	typedef bool (*kbUnitQueryResetResults_t)(int queryID);
	// Resets the given unit query results.
	extern const kbUnitQueryResetResults_t kbUnitQueryResetResults;

	typedef bool (*kbUnitQueryDestroy_t)(int queryID);
	// Destroys the given unit query.
	extern const kbUnitQueryDestroy_t kbUnitQueryDestroy;

	typedef int (*kbUnitQueryNumberResults_t)(int queryID);
	// Returns the number of results in the current query.
	extern const kbUnitQueryNumberResults_t kbUnitQueryNumberResults;

	typedef int (*kbUnitQueryGetResult_t)(int queryID, int index);
	// Returns the UnitID of the index-th result in the current query.
	extern const kbUnitQueryGetResult_t kbUnitQueryGetResult;

	typedef bool (*kbUnitQuerySetPlayerID_t)(int queryID, int playerID, bool resetQueryData);
	// Sets query data.
	extern const kbUnitQuerySetPlayerID_t kbUnitQuerySetPlayerID;

	typedef bool (*kbUnitQuerySetPlayerRelation_t)(int queryID, int playerRelation);
	// Sets query data.
	extern const kbUnitQuerySetPlayerRelation_t kbUnitQuerySetPlayerRelation;

	typedef bool (*kbUnitQuerySetUnitType_t)(int queryID, int unitTypeID);
	// Sets query data.
	extern const kbUnitQuerySetUnitType_t kbUnitQuerySetUnitType;

	typedef bool (*kbUnitQuerySetActionType_t)(int queryID, int actionTypeID);
	// Sets query data.
	extern const kbUnitQuerySetActionType_t kbUnitQuerySetActionType;

	typedef bool (*kbUnitQuerySetState_t)(int queryID, int state);
	// Sets query data.
	extern const kbUnitQuerySetState_t kbUnitQuerySetState;

	typedef bool (*kbUnitQuerySetPosition_t)(int queryID, vector v);
	// Sets query data.
	extern const kbUnitQuerySetPosition_t kbUnitQuerySetPosition;

	typedef bool (*kbUnitQuerySetMaximumDistance_t)(int queryID, float distance);
	// Sets query data.
	extern const kbUnitQuerySetMaximumDistance_t kbUnitQuerySetMaximumDistance;

	typedef bool (*kbUnitQuerySetIgnoreKnockedOutUnits_t)(int queryID, bool v);
	// Sets query data.
	extern const kbUnitQuerySetIgnoreKnockedOutUnits_t kbUnitQuerySetIgnoreKnockedOutUnits;

	typedef bool (*kbUnitQuerySetAscendingSort_t)(int queryID, bool v);
	// If parm is true, results are sorted in ascending distance order from the query position.
	extern const kbUnitQuerySetAscendingSort_t kbUnitQuerySetAscendingSort;

	typedef bool (*kbUnitQuerySetBaseID_t)(int queryID, int baseID);
	// Sets query data.
	extern const kbUnitQuerySetBaseID_t kbUnitQuerySetBaseID;

	typedef bool (*kbUnitQuerySetAreaID_t)(int queryID, int areaID);
	// Sets query data.
	extern const kbUnitQuerySetAreaID_t kbUnitQuerySetAreaID;

	typedef bool (*kbUnitQuerySetAreaGroupID_t)(int queryID, int areaGroupID);
	// Sets query data.
	extern const kbUnitQuerySetAreaGroupID_t kbUnitQuerySetAreaGroupID;

	typedef bool (*kbUnitQuerySetArmyID_t)(int queryID, int armyID);
	// Sets query data.
	extern const kbUnitQuerySetArmyID_t kbUnitQuerySetArmyID;

	typedef bool (*kbUnitQuerySetSeeableOnly_t)(int queryID, bool seeableOnly);
	// Sets query data.
	extern const kbUnitQuerySetSeeableOnly_t kbUnitQuerySetSeeableOnly;

	typedef int (*kbUnitQueryExecute_t)(int queryID);
	// Executes the current query; returns number of results.
	extern const kbUnitQueryExecute_t kbUnitQueryExecute;

	typedef int (*kbUnitQueryExecuteOnQuery_t)(int currentQueryID, int previousQueryID);
	// Executes the current query on the previous query's results; returns the new number of results.
	extern const kbUnitQueryExecuteOnQuery_t kbUnitQueryExecuteOnQuery;

	typedef int (*kbUnitQueryExecuteOnQueryByName_t)(int currentQueryID, string previousQueryName);
	// Executes the current query on the previous query's results; returns the new number of results.
	extern const kbUnitQueryExecuteOnQueryByName_t kbUnitQueryExecuteOnQueryByName;

	typedef float (*kbUnitQueryGetUnitCost_t)(int queryID, bool considerHealth);
	// gets total aiCost of query's units, weighted for HP if requested.
	extern const kbUnitQueryGetUnitCost_t kbUnitQueryGetUnitCost;

	typedef float (*kbUnitQueryGetUnitHitpoints_t)(int queryID, bool considerHealth);
	// gets HP of query's units, using current HP if requested.
	extern const kbUnitQueryGetUnitHitpoints_t kbUnitQueryGetUnitHitpoints;

	typedef int (*kbUnitGetPlayerID_t)(int unitID);
	// Returns the player ID for this unit ID.
	extern const kbUnitGetPlayerID_t kbUnitGetPlayerID;

	typedef int (*kbUnitGetPlanID_t)(int unitID);
	// Returns the plan ID for this unit ID.
	extern const kbUnitGetPlanID_t kbUnitGetPlanID;

	typedef int (*kbUnitGetBaseID_t)(int unitID);
	// Returns the base ID for this unit ID.
	extern const kbUnitGetBaseID_t kbUnitGetBaseID;

	typedef int (*kbUnitGetAreaID_t)(int unitID);
	// Returns the area ID for this unit ID.
	extern const kbUnitGetAreaID_t kbUnitGetAreaID;

	typedef int (*kbUnitGetArmyID_t)(int unitID);
	// Returns the army ID for this unit ID.
	extern const kbUnitGetArmyID_t kbUnitGetArmyID;

	typedef int (*kbUnitGetMovementType_t)(int unitTypeID);
	// Returns the movementType for this unitTypeID.
	extern const kbUnitGetMovementType_t kbUnitGetMovementType;

	typedef float (*kbUnitGetCurrentHitpoints_t)(int unitID);
	// Returns the current hitpoints for this unit ID.
	extern const kbUnitGetCurrentHitpoints_t kbUnitGetCurrentHitpoints;

	typedef float (*kbUnitGetMaximumHitpoints_t)(int unitID);
	// Returns the maximum hitpoints for this unit ID.
	extern const kbUnitGetMaximumHitpoints_t kbUnitGetMaximumHitpoints;

	typedef float (*kbUnitGetHealth_t)(int unitID);
	// Returns the health for this unit ID.
	extern const kbUnitGetHealth_t kbUnitGetHealth;

	typedef float (*kbUnitGetCurrentAICost_t)(int unitID);
	// Returns the current AI cost (worth) for this unit ID.
	extern const kbUnitGetCurrentAICost_t kbUnitGetCurrentAICost;

	typedef float (*kbUnitGetMaximumAICost_t)(int unitID);
	// Returns the maximum AI cost (worth) for this unit ID.
	extern const kbUnitGetMaximumAICost_t kbUnitGetMaximumAICost;

	typedef vector (*kbUnitGetPosition_t)(vector, int unitID);
	// Returns the position for this unit ID.
	extern const kbUnitGetPosition_t kbUnitGetPosition;

	typedef bool (*kbUnitIsType_t)(int unitID, int unitTypeID);
	// Returns true if the unit is of the unitTypeID.
	extern const kbUnitIsType_t kbUnitIsType;

	typedef int (*kbUnitGetActionType_t)(int unitID);
	// Returns the actionTypeID of the unit.
	extern const kbUnitGetActionType_t kbUnitGetActionType;

	typedef int (*kbUnitGetTargetUnitID_t)(int unitID);
	// Returns the target unit ID of the given unit.
	extern const kbUnitGetTargetUnitID_t kbUnitGetTargetUnitID;

	typedef int (*kbUnitGetNumberWorkers_t)(int unitID);
	// Returns the number of units currently working on the given unit.
	extern const kbUnitGetNumberWorkers_t kbUnitGetNumberWorkers;

	typedef int (*kbUnitGetWorkerID_t)(int unitID, int index);
	// Returns the index-th worker unit ID.
	extern const kbUnitGetWorkerID_t kbUnitGetWorkerID;

	typedef int (*kbGetBuildLimit_t)(int player, int unitTypeID);
	// Returns the number of the unit type you are allowed to have (ONLY WORKS ON BASE UNIT TYPES); returns -1 if there is no limit.
	extern const kbGetBuildLimit_t kbGetBuildLimit;

	typedef int (*kbGetPopCapAddition_t)(int player, int unitTypeID);
	// Returns amount of pop cap addition provided by the given unit type (ONLY WORKS ON BASE UNIT TYPES).
	extern const kbGetPopCapAddition_t kbGetPopCapAddition;

	typedef int (*kbGetPopSlots_t)(int player, int unitTypeID);
	// Returns the number of pop slots this unit takes (ONLY WORKS ON BASE UNIT TYPES).
	extern const kbGetPopSlots_t kbGetPopSlots;

	typedef int (*kbGetPopulationSlotsByUnitTypeID_t)(int playerID, int unitTypeID);
	// Returns the number of pop slots currently occupied by this unit type.
	extern const kbGetPopulationSlotsByUnitTypeID_t kbGetPopulationSlotsByUnitTypeID;

	typedef int (*kbGetPopulationSlotsByQueryID_t)(int queryID);
	// Returns the number of pop slots currently occupied by the results in the given query.
	extern const kbGetPopulationSlotsByQueryID_t kbGetPopulationSlotsByQueryID;

	typedef int (*kbUnitCount_t)(int player, int unitTypeID, int stateID);
	// Returns a quick unit count of units for a player.
	extern const kbUnitCount_t kbUnitCount;

	typedef void (*kbUnitCountConsole_t)(int playerID1, int playerID2, string unitType, string state);
	// Returns a quick unit count of player2's units from player1's perspective.
	extern const kbUnitCountConsole_t kbUnitCountConsole;

	typedef vector (*kbGetMapCenter_t)(vector);
	// Returns the center vector of the map.
	extern const kbGetMapCenter_t kbGetMapCenter;

	typedef float (*kbGetMapXSize_t)();
	// Returns the X size of the map.
	extern const kbGetMapXSize_t kbGetMapXSize;

	typedef float (*kbGetMapZSize_t)();
	// Returns the Z size of the map.
	extern const kbGetMapZSize_t kbGetMapZSize;

	typedef void (*kbAreaCalculate_t)(float, bool, vector, vector, vector, vector);
	// Creates areas and area groups. DO THIS BEFORE ANYTHING ELSE IN YOUR SCRIPT.
	extern const kbAreaCalculate_t kbAreaCalculate;

	typedef int (*kbAreaGetNumber_t)();
	// Returns the number of areas.
	extern const kbAreaGetNumber_t kbAreaGetNumber;

	typedef int (*kbAreaGetIDByPosition_t)(vector position);
	// Returns the ID of the given area.
	extern const kbAreaGetIDByPosition_t kbAreaGetIDByPosition;

	typedef int (*kbAreaGroupGetIDByPosition_t)(vector position);
	// Returns the ID of the given area group.
	extern const kbAreaGroupGetIDByPosition_t kbAreaGroupGetIDByPosition;

	typedef vector (*kbAreaGroupGetCenter_t)(vector, int groupID);
	// Returns the center of the given areaGroup.
	extern const kbAreaGroupGetCenter_t kbAreaGroupGetCenter;

	typedef vector (*kbAreaGetCenter_t)(vector, int areaID);
	// Returns the center of the given area.
	extern const kbAreaGetCenter_t kbAreaGetCenter;

	typedef int (*kbAreaGetNumberTiles_t)(int areaID);
	// Returns the number of tiles in the given area.
	extern const kbAreaGetNumberTiles_t kbAreaGetNumberTiles;

	typedef int (*kbAreaGetNumberBlackTiles_t)(int areaID);
	// Returns the number of black tiles in the given area.
	extern const kbAreaGetNumberBlackTiles_t kbAreaGetNumberBlackTiles;

	typedef int (*kbAreaGetNumberVisibleTiles_t)(int areaID);
	// Returns the number of visible tiles in the given area.
	extern const kbAreaGetNumberVisibleTiles_t kbAreaGetNumberVisibleTiles;

	typedef int (*kbAreaGetNumberFogTiles_t)(int areaID);
	// Returns the number of fog tiles in the given area.
	extern const kbAreaGetNumberFogTiles_t kbAreaGetNumberFogTiles;

	typedef int (*kbAreaGetVisibilityChangeTime_t)(int areaID);
	// Returns the gametime of the last visibility change for the given area.
	extern const kbAreaGetVisibilityChangeTime_t kbAreaGetVisibilityChangeTime;

	typedef int (*kbAreaGetNumberUnits_t)(int areaID);
	// Returns the number of units in the given area.
	extern const kbAreaGetNumberUnits_t kbAreaGetNumberUnits;

	typedef int (*kbAreaGetUnitID_t)(int areaID, int index);
	// Returns the Unit ID of the index-th unit in the given area.
	extern const kbAreaGetUnitID_t kbAreaGetUnitID;

	typedef int (*kbAreaGetNumberBorderAreas_t)(int areaID);
	// Returns the number of border areas for the given area.
	extern const kbAreaGetNumberBorderAreas_t kbAreaGetNumberBorderAreas;

	typedef int (*kbAreaGetBorderAreaID_t)(int areaID, int index);
	// Returns the Area ID of the index-th border area in the given area.
	extern const kbAreaGetBorderAreaID_t kbAreaGetBorderAreaID;

	typedef int (*kbAreaGetType_t)(int areaID);
	// Returns the Type of area.
	extern const kbAreaGetType_t kbAreaGetType;

	typedef int (*kbAreaGetVPSiteID_t)(int areaID);
	// returns an area's VP site ID (-1 if an area doesn't have a VP site).
	extern const kbAreaGetVPSiteID_t kbAreaGetVPSiteID;

	typedef int (*kbVPSiteQuery_t)(int scoreType, int playerRelationOrID, int siteState);
	// returns ID for an array containing VP site IDs that match the specified parameters.
	extern const kbVPSiteQuery_t kbVPSiteQuery;

	typedef void (*kbDumpVPSiteInfo_t)();
	// blogs out info about all VP sites.
	extern const kbDumpVPSiteInfo_t kbDumpVPSiteInfo;

	typedef int (*kbVPSiteGetType_t)(int siteID);
	// returns the specified VP site's type (e.g., native, trade, etc).
	extern const kbVPSiteGetType_t kbVPSiteGetType;

	typedef vector (*kbVPSiteGetLocation_t)(vector, int siteID);
	// returns the specified VP site's world location.
	extern const kbVPSiteGetLocation_t kbVPSiteGetLocation;

	typedef int (*kbVPSiteGetOwnerPlayerID_t)(int siteID);
	// returns the specified VP site's owning player.
	extern const kbVPSiteGetOwnerPlayerID_t kbVPSiteGetOwnerPlayerID;

	typedef int (*kbVPSiteGetState_t)(int siteID);
	// returns the specified VP site's state.
	extern const kbVPSiteGetState_t kbVPSiteGetState;

	typedef int (*kbGetVPGeneratorByScoreType_t)(int siteType);
	// returns the protounit ID for the VP generator that corresponds to this type of VP site.
	extern const kbGetVPGeneratorByScoreType_t kbGetVPGeneratorByScoreType;

	typedef int (*kbAreaFindBestGatherAreaID_t)(int unitTypeID);
	// Returns the Area ID of the best area to gather the given unit type.
	extern const kbAreaFindBestGatherAreaID_t kbAreaFindBestGatherAreaID;

	typedef int (*kbAreaGetClosetArea_t)(vector position, int areaType, int areaType1, float minDistance);
	// Returns the Area ID of the closest area, of the given types, to given postion.
	extern const kbAreaGetClosetArea_t kbAreaGetClosetArea;

	typedef int (*kbPathCreate_t)(string name);
	// Creates a path with the given name.
	extern const kbPathCreate_t kbPathCreate;

	typedef bool (*kbPathDestroy_t)(int pathID);
	// Destroys the given path.
	extern const kbPathDestroy_t kbPathDestroy;

	typedef int (*kbPathGetNumber_t)();
	// Returns the number of paths.
	extern const kbPathGetNumber_t kbPathGetNumber;

	typedef int (*kbPathGetIDByIndex_t)(int index);
	// Returns the index-th path ID.
	extern const kbPathGetIDByIndex_t kbPathGetIDByIndex;

	typedef string (*kbPathGetName_t)(int pathID);
	// Returns the name of the given path.
	extern const kbPathGetName_t kbPathGetName;

	typedef float (*kbPathGetLength_t)(int pathID);
	// Returns the length of the given path.
	extern const kbPathGetLength_t kbPathGetLength;

	typedef int (*kbPathGetNumberWaypoints_t)(int pathID);
	// Returns the number of waypoints in the given path.
	extern const kbPathGetNumberWaypoints_t kbPathGetNumberWaypoints;

	typedef bool (*kbPathAddWaypoint_t)(int pathID, vector waypoint);
	// Adds the waypoint to the given path.
	extern const kbPathAddWaypoint_t kbPathAddWaypoint;

	typedef vector (*kbPathGetWaypoint_t)(vector, int pathID, int waypointNumber);
	// Returns the appropriate waypoint from the given path.
	extern const kbPathGetWaypoint_t kbPathGetWaypoint;

	typedef bool (*kbCanSimPath_t)(vector pointA, vector pointB, int protoUnitTypeID, float range);
	// Returns true if the given unit type can path from pointA to pointB.
	extern const kbCanSimPath_t kbCanSimPath;

	typedef bool (*kbCanPath2_t)(vector pointA, vector pointB, int protoUnitTypeID, float range);
	// Returns true if the given unit type can path from pointA to pointB.
	extern const kbCanPath2_t kbCanPath2;

	typedef int (*kbCreateAttackRoute_t)(string name, int startAreaID, int goalAreaID, int numInitialRoutes);
	// Returns the Route ID if successful.
	extern const kbCreateAttackRoute_t kbCreateAttackRoute;

	typedef int (*kbCreateAttackRouteWithPath_t)(string name, vector startPt, vector endPt);
	// Returns the Route ID if successful.
	extern const kbCreateAttackRouteWithPath_t kbCreateAttackRouteWithPath;

	typedef bool (*kbDestroyAttackRoute_t)(int routeID);
	// Returns true if the route was deleted.
	extern const kbDestroyAttackRoute_t kbDestroyAttackRoute;

	typedef bool (*kbAddAttackRouteSector_t)(int sector);
	// add a new sector to path to.
	extern const kbAddAttackRouteSector_t kbAddAttackRouteSector;

	typedef bool (*kbAddAttackRouteIgnoreID_t)(int ignoreAreaID);
	// ignore this area when finding the route.
	extern const kbAddAttackRouteIgnoreID_t kbAddAttackRouteIgnoreID;

	typedef bool (*kbAddAttackRouteIgnoreType_t)(int ignoreAreaTypeID);
	// ignore this areatype when finding the route.
	extern const kbAddAttackRouteIgnoreType_t kbAddAttackRouteIgnoreType;

	typedef bool (*kbAttackRouteAddPath_t)(int attackRouteID, int pathID);
	// Rreturns true if path was added to attack route.
	extern const kbAttackRouteAddPath_t kbAttackRouteAddPath;

	typedef bool (*kbMakeAttackRoutes_t)();
	// find all the paths to the sector specified.
	extern const kbMakeAttackRoutes_t kbMakeAttackRoutes;

	typedef int (*kbGetNumAttackRoutes_t)(int startAreaID, int goalAreaID);
	// Returns num paths from start to goal area.
	extern const kbGetNumAttackRoutes_t kbGetNumAttackRoutes;

	typedef int (*kbGetAttackRouteID_t)(int startAreaID, int goalAreaID);
	// Returns the id of the routes from area1 to area2.
	extern const kbGetAttackRouteID_t kbGetAttackRouteID;

	typedef int (*kbEscrowCreate_t)(string name, int resourceID, float percentage, int parentID);
	// Creates an escrow.
	extern const kbEscrowCreate_t kbEscrowCreate;

	typedef bool (*kbEscrowDestroy_t)(int escrowID, bool promoteChildren);
	// Destroys an escrow.
	extern const kbEscrowDestroy_t kbEscrowDestroy;

	typedef int (*kbEscrowGetID_t)(string name);
	// Returns the ID of the named escrow.
	extern const kbEscrowGetID_t kbEscrowGetID;

	typedef float (*kbEscrowGetPercentage_t)(int escrowID, int resourceID);
	// Returns the percentage of the escrow.
	extern const kbEscrowGetPercentage_t kbEscrowGetPercentage;

	typedef bool (*kbEscrowSetPercentage_t)(int escrowID, int resourceID, float percentage);
	// Sets the percentage of the escrow.
	extern const kbEscrowSetPercentage_t kbEscrowSetPercentage;

	typedef bool (*kbEscrowSetCap_t)(int escrowID, int resourceID, float cap);
	// Sets the cap of the escrow.
	extern const kbEscrowSetCap_t kbEscrowSetCap;

	typedef float (*kbEscrowGetAmount_t)(int escrowID, int resourceID);
	// Returns the amount of credits in the given escrow for the given resource.
	extern const kbEscrowGetAmount_t kbEscrowGetAmount;

	typedef bool (*kbEscrowFlush_t)(int escrowID, int resourceID, bool flushChildren);
	// Removes all credits (and puts them into the root escrow) of the given resource type from the given escrow.
	extern const kbEscrowFlush_t kbEscrowFlush;

	typedef bool (*kbEscrowAllocateCurrentResources_t)();
	// Reallocates the current resource stockpile into the escrows.
	extern const kbEscrowAllocateCurrentResources_t kbEscrowAllocateCurrentResources;

	typedef int (*kbBuildingPlacementCreate_t)(string name);
	// Creates a building placement; returns the ID.
	extern const kbBuildingPlacementCreate_t kbBuildingPlacementCreate;

	typedef bool (*kbBuildingPlacementDestroy_t)(int id);
	// Destroys the given building placement.
	extern const kbBuildingPlacementDestroy_t kbBuildingPlacementDestroy;

	typedef bool (*kbBuildingPlacementResetResults_t)();
	// Resets the current building placement.
	extern const kbBuildingPlacementResetResults_t kbBuildingPlacementResetResults;

	typedef bool (*kbBuildingPlacementSelect_t)(int id);
	// Selects the given building placement.
	extern const kbBuildingPlacementSelect_t kbBuildingPlacementSelect;

	typedef bool (*kbBuildingPlacementSetEventHandler_t)(int eventType, string handlerName);
	// Sets event handler function for the current BP and event.
	extern const kbBuildingPlacementSetEventHandler_t kbBuildingPlacementSetEventHandler;

	typedef bool (*kbBuildingPlacementSetBuildingType_t)(int buildingTypeID);
	// Sets the building type for the current building placement.
	extern const kbBuildingPlacementSetBuildingType_t kbBuildingPlacementSetBuildingType;

	typedef bool (*kbBuildingPlacementSetBaseID_t)(int baseID, int locationPref);
	// Sets the base ID and location preference for the current building placement.
	extern const kbBuildingPlacementSetBaseID_t kbBuildingPlacementSetBaseID;

	typedef bool (*kbBuildingPlacementAddAreaID_t)(int areaID, int numberBorderAreaLayers, bool addCenterInfluence);
	// Adds the Area ID to the current BP (with the given number of border area layers), addCenterInfluence - adds a positional influence from the area center.
	extern const kbBuildingPlacementAddAreaID_t kbBuildingPlacementAddAreaID;

	typedef bool (*kbBuildingPlacementAddAreaGroupID_t)(int areaGroupID);
	// Adds the AreaGroup ID to the current BP.
	extern const kbBuildingPlacementAddAreaGroupID_t kbBuildingPlacementAddAreaGroupID;

	typedef bool (*kbBuildingPlacementSetCenterPosition_t)(vector position, float distance, float obstructionRadius);
	// Sets up center position-based BP.
	extern const kbBuildingPlacementSetCenterPosition_t kbBuildingPlacementSetCenterPosition;

	typedef bool (*kbBuildingPlacementAddUnitInfluence_t)(int typeID, float value, float distance, int kbResourceID);
	// Adds the unit influence for the current building placement.
	extern const kbBuildingPlacementAddUnitInfluence_t kbBuildingPlacementAddUnitInfluence;

	typedef bool (*kbBuildingPlacementAddPositionInfluence_t)(vector position, float value, float distance);
	// Adds the position influence for the current building placement.
	extern const kbBuildingPlacementAddPositionInfluence_t kbBuildingPlacementAddPositionInfluence;

	typedef bool (*kbBuildingPlacementSetMinimumValue_t)(float minimumValue);
	// Sets the minimum acceptable value for evaluated spots in the BP.
	extern const kbBuildingPlacementSetMinimumValue_t kbBuildingPlacementSetMinimumValue;

	typedef bool (*kbBuildingPlacementStart_t)();
	// Starts the placement of current building.
	extern const kbBuildingPlacementStart_t kbBuildingPlacementStart;

	typedef vector (*kbBuildingPlacementGetResultPosition_t)(vector, int bpID);
	// Returns the vector result position for given BP ID.
	extern const kbBuildingPlacementGetResultPosition_t kbBuildingPlacementGetResultPosition;

	typedef float (*kbBuildingPlacementGetResultValue_t)(int bpID);
	// Returns the result value for given BP ID.
	extern const kbBuildingPlacementGetResultValue_t kbBuildingPlacementGetResultValue;

	typedef int (*kbTargetSelectorCreate_t)(string name);
	// Creates a target selector; returns the ID.
	extern const kbTargetSelectorCreate_t kbTargetSelectorCreate;

	typedef bool (*kbTargetSelectorDestroy_t)(int id);
	// Destroys the given target selector.
	extern const kbTargetSelectorDestroy_t kbTargetSelectorDestroy;

	typedef bool (*kbTargetSelectorResetResults_t)();
	// Resets the current target selector.
	extern const kbTargetSelectorResetResults_t kbTargetSelectorResetResults;

	typedef bool (*kbTargetSelectorSelect_t)(int id);
	// Selects the given target selector.
	extern const kbTargetSelectorSelect_t kbTargetSelectorSelect;

	typedef bool (*kbTargetSelectorAddUnitType_t)(int protoUnitTypeID);
	// Add the UAIT for the given BASE unit type as a filter.
	extern const kbTargetSelectorAddUnitType_t kbTargetSelectorAddUnitType;

	typedef bool (*kbTargetSelectorAddQueryResults_t)(int queryID);
	// Sets the list of potential targets to the results in the given query.
	extern const kbTargetSelectorAddQueryResults_t kbTargetSelectorAddQueryResults;

	typedef int (*kbTargetSelectorGetNumberResults_t)();
	// Returns the number of results in the given target selector.
	extern const kbTargetSelectorGetNumberResults_t kbTargetSelectorGetNumberResults;

	typedef int (*kbTargetSelectorGetResultValue_t)(int index);
	// Returns the result value for given index of the current target selector.
	extern const kbTargetSelectorGetResultValue_t kbTargetSelectorGetResultValue;

	typedef bool (*kbTargetSelectorStart_t)();
	// Starts the current target selector.
	extern const kbTargetSelectorStart_t kbTargetSelectorStart;

	typedef bool (*kbSetupForResource_t)(int baseID, int resourceID, float distance, float amount);
	// Returns true if amount of resource is within distance of a dropsite.
	extern const kbSetupForResource_t kbSetupForResource;

	typedef int (*kbGetHCLevel_t)(int playerID);
	// Returns the current HomeCity Level of the given player.
	extern const kbGetHCLevel_t kbGetHCLevel;

	typedef int (*kbResourceGetXP_t)(int playerID);
	// Returns the current amount XP the given player has.
	extern const kbResourceGetXP_t kbResourceGetXP;

	typedef float (*kbResourceGet_t)(int resourceID);
	// Returns the current amount of the given resource.
	extern const kbResourceGet_t kbResourceGet;

	typedef float (*kbMaximumResourceGet_t)(int resourceID);
	// Returns the maximum amount of the given resource you can have.
	extern const kbMaximumResourceGet_t kbMaximumResourceGet;

	typedef float (*kbTotalResourceGet_t)(int resourceID);
	// Returns the total amount of the given resource gathered to this point in the game.
	extern const kbTotalResourceGet_t kbTotalResourceGet;

	typedef int (*kbGetNumberValidResourcesByPlan_t)(int planID, int baseID);
	// Returns the number of valid KB resources for the given plan/base.
	extern const kbGetNumberValidResourcesByPlan_t kbGetNumberValidResourcesByPlan;

	typedef int (*kbGetNumberValidResources_t)(int baseID, int resourceTypeID, int resourceSubTypeID, float distance);
	// Returns the number of valid KB resources for the resource types.
	extern const kbGetNumberValidResources_t kbGetNumberValidResources;

	typedef float (*kbGetAmountValidResources_t)(int baseID, int resourceTypeID, int resourceSubTypeID, float distance);
	// Returns the resource amount of valid KB resources for the resource types.
	extern const kbGetAmountValidResources_t kbGetAmountValidResources;

	typedef float (*kbGetResourceIncome_t)(int resourceID, float seconds, bool relative);
	// Returns the resource income over the last X seconds.
	extern const kbGetResourceIncome_t kbGetResourceIncome;

	typedef bool (*kbProtoUnitAvailable_t)(int protoUnitID);
	// Returns true if the protoUnit is currently available.
	extern const kbProtoUnitAvailable_t kbProtoUnitAvailable;

	typedef int (*kbGetProtoUnitID_t)(string name);
	// Returns the ID of the protounit.
	extern const kbGetProtoUnitID_t kbGetProtoUnitID;

	typedef int (*kbUnitGetProtoUnitID_t)(int unitID);
	// Returns the unit's protounit ID.
	extern const kbUnitGetProtoUnitID_t kbUnitGetProtoUnitID;

	typedef bool (*kbCanAffordUnit_t)(int protoUnitTypeID, int escrowID);
	// Returns true if the player can afford the proto unit.
	extern const kbCanAffordUnit_t kbCanAffordUnit;

	typedef float (*kbUnitCostPerResource_t)(int protoUnitID, int resourceID);
	// returns the cost of the protounit for the given resource.
	extern const kbUnitCostPerResource_t kbUnitCostPerResource;

	typedef bool (*kbCanAffordTech_t)(int techID, int escrowID);
	// Returns true if the player can afford the tech.
	extern const kbCanAffordTech_t kbCanAffordTech;

	typedef float (*kbTechCostPerResource_t)(int techID, int resourceID);
	// returns the cost of the tech for the given resource.
	extern const kbTechCostPerResource_t kbTechCostPerResource;

	typedef bool (*kbProtoUnitIsType_t)(int playerID, int protoUnitID, int unitTypeID);
	// Returns true if the protounit is of the unitTypeID.
	extern const kbProtoUnitIsType_t kbProtoUnitIsType;

	typedef int (*kbTechGetStatus_t)(int techID);
	// Returns the current tech status for the current player of the requested tech.
	extern const kbTechGetStatus_t kbTechGetStatus;

	typedef float (*kbGetTechPercentComplete_t)(int techID);
	// Returns the percent complete for the the requested tech of the current player.
	extern const kbGetTechPercentComplete_t kbGetTechPercentComplete;

	typedef float (*kbGetCombatEfficiency_t)(int playerID1, int unitTypeID1, int playerID2, int unitTypeID2);
	// Returns the combat efficiency of the comparison (in terms of playerID1's units).
	extern const kbGetCombatEfficiency_t kbGetCombatEfficiency;

	typedef float (*kbGetAICostWeight_t)(int resourceID);
	// Returns the AI cost weight for the given resource.
	extern const kbGetAICostWeight_t kbGetAICostWeight;

	typedef bool (*kbSetAICostWeight_t)(int resourceID, float weight);
	// Sets the weight this resource type is given during AI cost calculuations.
	extern const kbSetAICostWeight_t kbSetAICostWeight;

	typedef float (*kbGetProtoUnitAICost_t)(int protoUnitTypeID);
	// Returns the AI cost for the given protoUnit type ID.
	extern const kbGetProtoUnitAICost_t kbGetProtoUnitAICost;

	typedef float (*kbGetTechAICost_t)(int techID);
	// Returns the AI cost for the given tech ID.
	extern const kbGetTechAICost_t kbGetTechAICost;

	typedef bool (*kbIsPlayerResigned_t)(int playerID);
	// Returns the player's resigned status.
	extern const kbIsPlayerResigned_t kbIsPlayerResigned;

	typedef bool (*kbHasPlayerLost_t)(int playerID);
	// Returns the player's lost status.
	extern const kbHasPlayerLost_t kbHasPlayerLost;

	typedef int (*kbGetPlayerTeam_t)(int playerID);
	// Returns the player's team number.
	extern const kbGetPlayerTeam_t kbGetPlayerTeam;

	typedef string (*kbGetPlayerName_t)(int playerID);
	// Returns the player's name.
	extern const kbGetPlayerName_t kbGetPlayerName;

	typedef bool (*kbIsPlayerEnemy_t)(int playerID);
	// Returns true if the given player is an enemy.
	extern const kbIsPlayerEnemy_t kbIsPlayerEnemy;

	typedef bool (*kbIsPlayerNeutral_t)(int playerID);
	// Returns true if the given player is a neutral player.
	extern const kbIsPlayerNeutral_t kbIsPlayerNeutral;

	typedef bool (*kbIsPlayerAlly_t)(int playerID);
	// Returns true if the given player is an ally.
	extern const kbIsPlayerAlly_t kbIsPlayerAlly;

	typedef bool (*kbIsPlayerMutualAlly_t)(int playerID);
	// Returns true if the given player is a mutual ally.
	extern const kbIsPlayerMutualAlly_t kbIsPlayerMutualAlly;

	typedef int (*kbGetNumberMutualAllies_t)();
	// Returns the number of mutual allies.
	extern const kbGetNumberMutualAllies_t kbGetNumberMutualAllies;

	typedef bool (*kbIsPlayerValid_t)(int playerID);
	// Returns true if the given player is a valid player (i.e. it exists in the game).
	extern const kbIsPlayerValid_t kbIsPlayerValid;

	typedef bool (*kbIsPlayerHuman_t)(int playerID);
	// Returns true if the given player is a a human player.
	extern const kbIsPlayerHuman_t kbIsPlayerHuman;

	typedef float (*kbGetPlayerHandicap_t)(int playerID);
	// Returns the player's handicap multiplier (ie., 1.0 = no handicap).
	extern const kbGetPlayerHandicap_t kbGetPlayerHandicap;

	typedef void (*kbSetPlayerHandicap_t)(int playerID, float handicap);
	// Sets the indicated player's handicap multiplier (ie., 1.0 = no handicap).
	extern const kbSetPlayerHandicap_t kbSetPlayerHandicap;

	typedef bool (*kbIsGameOver_t)();
	// Returns whether the game is over or not.
	extern const kbIsGameOver_t kbIsGameOver;

	typedef vector (*kbGetTownLocation_t)(vector);
	// Returns the location of the main town.
	extern const kbGetTownLocation_t kbGetTownLocation;

	typedef int (*kbGetTownAreaID_t)();
	// Returns the area ID of the main town.
	extern const kbGetTownAreaID_t kbGetTownAreaID;

	typedef bool (*kbSetTownLocation_t)(vector location);
	// Sets the location of the main town.
	extern const kbSetTownLocation_t kbSetTownLocation;

	typedef bool (*kbGetAutoBaseCreate_t)();
	// Returns the auto base creation value.
	extern const kbGetAutoBaseCreate_t kbGetAutoBaseCreate;

	typedef void (*kbSetAutoBaseCreate_t)(bool v);
	// Sets the auto base creation value.
	extern const kbSetAutoBaseCreate_t kbSetAutoBaseCreate;

	typedef float (*kbGetAutoBaseCreateDistance_t)();
	// Returns the auto base creation distance.
	extern const kbGetAutoBaseCreateDistance_t kbGetAutoBaseCreateDistance;

	typedef void (*kbSetAutoBaseCreateDistance_t)(float v);
	// Sets the auto base creation distance.
	extern const kbSetAutoBaseCreateDistance_t kbSetAutoBaseCreateDistance;

	typedef bool (*kbGetAutoBaseDetect_t)();
	// Returns the auto base detection value.
	extern const kbGetAutoBaseDetect_t kbGetAutoBaseDetect;

	typedef void (*kbSetAutoBaseDetect_t)(bool v);
	// Sets the auto base detection value.
	extern const kbSetAutoBaseDetect_t kbSetAutoBaseDetect;

	typedef float (*kbGetAutoBaseDetectDistance_t)();
	// Returns the auto base creation distance.
	extern const kbGetAutoBaseDetectDistance_t kbGetAutoBaseDetectDistance;

	typedef void (*kbSetAutoBaseDetectDistance_t)(float v);
	// Sets the auto base creation distance.
	extern const kbSetAutoBaseDetectDistance_t kbSetAutoBaseDetectDistance;

	typedef int (*kbFindClosestBase_t)(int playerRelation, vector location);
	// gets the nearest base of player relation from the location.
	extern const kbFindClosestBase_t kbFindClosestBase;

	typedef int (*kbBaseGetNextID_t)();
	// Returns the ID of the next base that will be created.
	extern const kbBaseGetNextID_t kbBaseGetNextID;

	typedef int (*kbBaseGetNumber_t)(int playerID);
	// Returns the number of bases for the given player.
	extern const kbBaseGetNumber_t kbBaseGetNumber;

	typedef int (*kbBaseGetIDByIndex_t)(int playerID, int index);
	// Returns the BaseID for the given base.
	extern const kbBaseGetIDByIndex_t kbBaseGetIDByIndex;

	typedef int (*kbBaseCreate_t)(int playerID, string name, vector position, float distance);
	// Creates a base.
	extern const kbBaseCreate_t kbBaseCreate;

	typedef int (*kbBaseFindCreateResourceBase_t)(int resourceType, int resourceSubType, int parentBaseID);
	// Finds/Creates a resource base.
	extern const kbBaseFindCreateResourceBase_t kbBaseFindCreateResourceBase;

	typedef int (*kbBaseFindForwardMilitaryBase_t)(int, int, int);
	// Finds/Creates a 'forward' military base against the given enemy base.
	extern const kbBaseFindForwardMilitaryBase_t kbBaseFindForwardMilitaryBase;

	typedef bool (*kbBaseDestroy_t)(int playerID, int baseID);
	// Destroys the given base.
	extern const kbBaseDestroy_t kbBaseDestroy;

	typedef void (*kbBaseDestroyAll_t)(int playerID);
	// Destroys all of the bases for the given player.
	extern const kbBaseDestroyAll_t kbBaseDestroyAll;

	typedef vector (*kbBaseGetLocation_t)(vector, int playerID, int baseID);
	// Gets the location of the base.
	extern const kbBaseGetLocation_t kbBaseGetLocation;

	typedef vector (*kbBaseGetLastKnownDamageLocation_t)(vector, int, int);
	// Gets the last known damage location of the base.
	extern const kbBaseGetLastKnownDamageLocation_t kbBaseGetLastKnownDamageLocation;

	typedef int (*kbBaseGetOwner_t)(int baseID);
	// Returns the player ID of the specified base's owner.
	extern const kbBaseGetOwner_t kbBaseGetOwner;

	typedef bool (*kbBaseSetFrontVector_t)(int playerID, int baseID, vector frontVector);
	// Sets the front (and back) of the base.
	extern const kbBaseSetFrontVector_t kbBaseSetFrontVector;

	typedef vector (*kbBaseGetFrontVector_t)(vector, int playerID, int baseID);
	// Gets the front vector of the base.
	extern const kbBaseGetFrontVector_t kbBaseGetFrontVector;

	typedef vector (*kbBaseGetBackVector_t)(vector, int playerID, int baseID);
	// Gets the back vector of the base.
	extern const kbBaseGetBackVector_t kbBaseGetBackVector;

	typedef int (*kbBaseGetTimeUnderAttack_t)(int playerID, int baseID);
	// Returns the number of continuous seconds the base has been under attack.
	extern const kbBaseGetTimeUnderAttack_t kbBaseGetTimeUnderAttack;

	typedef bool (*kbBaseGetUnderAttack_t)(int playerID, int baseID);
	// Gets the under attack flag of the base.
	extern const kbBaseGetUnderAttack_t kbBaseGetUnderAttack;

	typedef bool (*kbBaseSetActive_t)(int playerID, int baseID, bool active);
	// Sets the active flag of the base.
	extern const kbBaseSetActive_t kbBaseSetActive;

	typedef bool (*kbBaseGetActive_t)(int playerID, int baseID);
	// Gets the active flag of the base.
	extern const kbBaseGetActive_t kbBaseGetActive;

	typedef int (*kbBaseGetMainID_t)(int playerID);
	// Gets the main base ID for the player.
	extern const kbBaseGetMainID_t kbBaseGetMainID;

	typedef bool (*kbBaseSetMain_t)(int playerID, int baseID, bool main);
	// Sets the main flag of the base.
	extern const kbBaseSetMain_t kbBaseSetMain;

	typedef bool (*kbBaseGetMain_t)(int playerID, int baseID);
	// Gets the main flag of the base.
	extern const kbBaseGetMain_t kbBaseGetMain;

	typedef bool (*kbBaseSetForward_t)(int playerID, int baseID, bool forward);
	// Sets the forward flag of the base.
	extern const kbBaseSetForward_t kbBaseSetForward;

	typedef bool (*kbBaseGetForward_t)(int playerID, int baseID);
	// Gets the forward flag of the base.
	extern const kbBaseGetForward_t kbBaseGetForward;

	typedef bool (*kbBaseSetSettlement_t)(int playerID, int baseID, bool settlement);
	// Sets the settlement flag of the base.
	extern const kbBaseSetSettlement_t kbBaseSetSettlement;

	typedef bool (*kbBaseGetSettlement_t)(int playerID, int baseID);
	// Gets the settlement flag of the base.
	extern const kbBaseGetSettlement_t kbBaseGetSettlement;

	typedef bool (*kbBaseSetMilitary_t)(int playerID, int baseID, bool military);
	// Sets the military flag of the base.
	extern const kbBaseSetMilitary_t kbBaseSetMilitary;

	typedef bool (*kbBaseGetMilitary_t)(int playerID, int baseID);
	// Gets the military flag of the base.
	extern const kbBaseGetMilitary_t kbBaseGetMilitary;

	typedef vector (*kbBaseGetMilitaryGatherPoint_t)(vector, int playerID, int baseID);
	// Gets the military gather point of the base.
	extern const kbBaseGetMilitaryGatherPoint_t kbBaseGetMilitaryGatherPoint;

	typedef bool (*kbBaseSetMilitaryGatherPoint_t)(int playerID, int baseID, vector gatherPoint);
	// Sets the military gather point of the base.
	extern const kbBaseSetMilitaryGatherPoint_t kbBaseSetMilitaryGatherPoint;

	typedef bool (*kbBaseSetEconomy_t)(int playerID, int baseID, bool Economy);
	// Sets the economy flag of the base.
	extern const kbBaseSetEconomy_t kbBaseSetEconomy;

	typedef bool (*kbBaseGetEconomy_t)(int playerID, int baseID);
	// Gets the economy flag of the base.
	extern const kbBaseGetEconomy_t kbBaseGetEconomy;

	typedef float (*kbBaseGetMaximumResourceDistance_t)(int playerID, int baseID);
	// Gets the maximum resource distance of the base.
	extern const kbBaseGetMaximumResourceDistance_t kbBaseGetMaximumResourceDistance;

	typedef void (*kbBaseSetMaximumResourceDistance_t)(int playerID, int baseID, float distance);
	// Sets the maximum resource distance of the base.
	extern const kbBaseSetMaximumResourceDistance_t kbBaseSetMaximumResourceDistance;

	typedef bool (*kbBaseAddUnit_t)(int playerID, int baseID, int unitID);
	// Adds the given unit to the base.
	extern const kbBaseAddUnit_t kbBaseAddUnit;

	typedef bool (*kbBaseRemoveUnit_t)(int playerID, int baseID, int unitID);
	// Removes the given unit to the base.
	extern const kbBaseRemoveUnit_t kbBaseRemoveUnit;

	typedef int (*kbBaseGetNumberUnits_t)(int playerID, int baseID, int relation, int unitTypeID);
	// Returns the number of units that match the criteria.
	extern const kbBaseGetNumberUnits_t kbBaseGetNumberUnits;

	typedef bool (*kbUnitVisible_t)(int unitID);
	// Returns true if the unit is currently visible to the player.
	extern const kbUnitVisible_t kbUnitVisible;

	typedef bool (*kbLocationVisible_t)(vector location);
	// Returns true if the location is currently visible to the player.
	extern const kbLocationVisible_t kbLocationVisible;

	typedef vector (*kbGetBlockPosition_t)(vector, string blockName);
	// Returns the position of the cinematic block.
	extern const kbGetBlockPosition_t kbGetBlockPosition;

	typedef int (*kbGetBlockID_t)(string blockName);
	// Returns the UnitID of the cinematic block.
	extern const kbGetBlockID_t kbGetBlockID;

	typedef int (*kbGetRandomEnabledPUID_t)(int unitTypeID, int escrowID);
	// Returns a random, valid PUID that's of the given type.
	extern const kbGetRandomEnabledPUID_t kbGetRandomEnabledPUID;

	typedef int (*kbUnitPickCreate_t)(string name);
	// Creates a unit pick.
	extern const kbUnitPickCreate_t kbUnitPickCreate;

	typedef bool (*kbUnitPickDestroy_t)(int upID);
	// Destroys the given unit pick.
	extern const kbUnitPickDestroy_t kbUnitPickDestroy;

	typedef bool (*kbUnitPickResetAll_t)(int upID);
	// Resets all of the unit pick data.
	extern const kbUnitPickResetAll_t kbUnitPickResetAll;

	typedef bool (*kbUnitPickResetResults_t)(int upID);
	// Resets the unit pick results.
	extern const kbUnitPickResetResults_t kbUnitPickResetResults;

	typedef float (*kbUnitPickGetPreferenceWeight_t)(int upID);
	// Gets the unit pick preference weight.
	extern const kbUnitPickGetPreferenceWeight_t kbUnitPickGetPreferenceWeight;

	typedef bool (*kbUnitPickSetPreferenceWeight_t)(int upID, float v);
	// Sets the unit pick preference weight.
	extern const kbUnitPickSetPreferenceWeight_t kbUnitPickSetPreferenceWeight;

	typedef bool (*kbUnitPickSetEnemyPlayerID_t)(int upID, int playerID);
	// Sets the unit pick enemy player ID.
	extern const kbUnitPickSetEnemyPlayerID_t kbUnitPickSetEnemyPlayerID;

	typedef bool (*kbUnitPickSetCombatEfficiencyWeight_t)(int upID, float);
	// Sets the unit pick combat efficiency weight.
	extern const kbUnitPickSetCombatEfficiencyWeight_t kbUnitPickSetCombatEfficiencyWeight;

	typedef bool (*kbUnitPickResetCombatEfficiencyTypes_t)(int upID);
	// Resets the enemy unit typeIDs for the unit pick combat efficiency calculation.
	extern const kbUnitPickResetCombatEfficiencyTypes_t kbUnitPickResetCombatEfficiencyTypes;

	typedef bool (*kbUnitPickAddCombatEfficiencyType_t)(int upID, int typeID, float weight);
	// Adds an enemy unit typeID to the unit pick combat efficiency calculation.
	extern const kbUnitPickAddCombatEfficiencyType_t kbUnitPickAddCombatEfficiencyType;

	typedef bool (*kbUnitPickSetCostWeight_t)(int upID, float);
	// Sets the unit pick cost weight.
	extern const kbUnitPickSetCostWeight_t kbUnitPickSetCostWeight;

	typedef bool (*kbUnitPickSetMovementType_t)(int upID, int movementType);
	// Sets the unit pick movement type.
	extern const kbUnitPickSetMovementType_t kbUnitPickSetMovementType;

	typedef bool (*kbUnitPickSetDesiredNumberUnitTypes_t)(int upID, int number, int numberBuildings, bool degradeNumberBuildings);
	// Sets the unit pick desired number unit types.
	extern const kbUnitPickSetDesiredNumberUnitTypes_t kbUnitPickSetDesiredNumberUnitTypes;

	typedef int (*kbUnitPickGetDesiredNumberUnitTypes_t)(int upID);
	// Gets the unit pick desired number unit types.
	extern const kbUnitPickGetDesiredNumberUnitTypes_t kbUnitPickGetDesiredNumberUnitTypes;

	typedef bool (*kbUnitPickSetDesiredNumberBuildings_t)(int upID, int index, int numberBuildings);
	// Sets the unit pick desired number buildings for the index-th unit type.
	extern const kbUnitPickSetDesiredNumberBuildings_t kbUnitPickSetDesiredNumberBuildings;

	typedef int (*kbUnitPickGetDesiredNumberBuildings_t)(int upID, int index);
	// gets the unit pick desired number buildings for the index-th unit type.
	extern const kbUnitPickGetDesiredNumberBuildings_t kbUnitPickGetDesiredNumberBuildings;

	typedef bool (*kbUnitPickSetMinimumNumberUnits_t)(int upID, int number);
	// Sets the unit pick desired number unit types.
	extern const kbUnitPickSetMinimumNumberUnits_t kbUnitPickSetMinimumNumberUnits;

	typedef int (*kbUnitPickGetMinimumNumberUnits_t)(int upID);
	// Gets the unit pick minimum number units.
	extern const kbUnitPickGetMinimumNumberUnits_t kbUnitPickGetMinimumNumberUnits;

	typedef bool (*kbUnitPickSetMaximumNumberUnits_t)(int upID, int number);
	// Sets the unit pick desired number unit types.
	extern const kbUnitPickSetMaximumNumberUnits_t kbUnitPickSetMaximumNumberUnits;

	typedef int (*kbUnitPickGetMaximumNumberUnits_t)(int upID);
	// Gets the unit pick maximum number units.
	extern const kbUnitPickGetMaximumNumberUnits_t kbUnitPickGetMaximumNumberUnits;

	typedef bool (*kbUnitPickSetMinimumPop_t)(int upID, int number);
	// Sets the unit pick desired min pop.
	extern const kbUnitPickSetMinimumPop_t kbUnitPickSetMinimumPop;

	typedef int (*kbUnitPickGetMinimumPop_t)(int upID);
	// Gets the unit pick minimum pop.
	extern const kbUnitPickGetMinimumPop_t kbUnitPickGetMinimumPop;

	typedef bool (*kbUnitPickSetMaximumPop_t)(int upID, int number);
	// Sets the unit pick desired max pop.
	extern const kbUnitPickSetMaximumPop_t kbUnitPickSetMaximumPop;

	typedef int (*kbUnitPickGetMaximumPop_t)(int upID);
	// Gets the unit pick maximum pop.
	extern const kbUnitPickGetMaximumPop_t kbUnitPickGetMaximumPop;

	typedef bool (*kbUnitPickSetAttackUnitType_t)(int upID, int type);
	// Sets the unit pick attack unit type.
	extern const kbUnitPickSetAttackUnitType_t kbUnitPickSetAttackUnitType;

	typedef int (*kbUnitPickGetAttackUnitType_t)(int upID);
	// Gets the unit pick attack unit type.
	extern const kbUnitPickGetAttackUnitType_t kbUnitPickGetAttackUnitType;

	typedef bool (*kbUnitPickSetGoalCombatEfficiencyType_t)(int upID, int type);
	// Sets the unit pick attack unit type.
	extern const kbUnitPickSetGoalCombatEfficiencyType_t kbUnitPickSetGoalCombatEfficiencyType;

	typedef int (*kbUnitPickGetGoalCombatEfficiencyType_t)(int upID);
	// Gets the unit pick attack unit type.
	extern const kbUnitPickGetGoalCombatEfficiencyType_t kbUnitPickGetGoalCombatEfficiencyType;

	typedef bool (*kbUnitPickSetPreferenceFactor_t)(int upID, int unitTypeID, float preferenceFactor);
	// Sets the preferenceFactor for that unit type.
	extern const kbUnitPickSetPreferenceFactor_t kbUnitPickSetPreferenceFactor;

	typedef bool (*kbUnitPickAdjustPreferenceFactor_t)(int upID, int unitTypeID, float baseFactorAdjustment);
	// Adjusts the preferenceFactor for that unit type (uses 50.0 as the base if the UP doesn't exist yet).
	extern const kbUnitPickAdjustPreferenceFactor_t kbUnitPickAdjustPreferenceFactor;

	typedef int (*kbUnitPickRun_t)(int upID);
	// Runs the unit pick.
	extern const kbUnitPickRun_t kbUnitPickRun;

	typedef int (*kbUnitPickGetNumberResults_t)(int upID);
	// Returns the number of unit pick results.
	extern const kbUnitPickGetNumberResults_t kbUnitPickGetNumberResults;

	typedef int (*kbUnitPickGetResult_t)(int upID, int index);
	// Returns the index-th ProtoUnitID.
	extern const kbUnitPickGetResult_t kbUnitPickGetResult;

	typedef int (*kbFindAreaGroup_t)(int groupType, float surfaceAreaRatio, int compareAreaID);
	// returns the visible area group that matches the given criteria.
	extern const kbFindAreaGroup_t kbFindAreaGroup;

	typedef int (*kbFindAreaGroupByLocation_t)(int groupType, float relativeX, float relativeZ);
	// returns the visible area group that matches the given criteria.
	extern const kbFindAreaGroupByLocation_t kbFindAreaGroupByLocation;

	typedef int (*kbFindBestBuildingToRepair_t)(vector position, float distance, float healthRatio, int repairUnderAttackUnitTypeID);
	// returns the id of the best building to repair.
	extern const kbFindBestBuildingToRepair_t kbFindBestBuildingToRepair;

	typedef void (*kbSetForwardBasePosition_t)(vector position);
	// set the explicit position that every forward base will use.
	extern const kbSetForwardBasePosition_t kbSetForwardBasePosition;
	typedef void (*kbSetTargetSelectorFactor_t)(int type, float val);
	// sets the TargetSelector Factor value.
	extern const kbSetTargetSelectorFactor_t kbSetTargetSelectorFactor;

	typedef float (*kbGetTargetSelectorFactor_t)(int type);
	// gets the TargetSelector Factor value.
	extern const kbGetTargetSelectorFactor_t kbGetTargetSelectorFactor;

	typedef string (*kbGetTechName_t)(int techID);
	// Returns the name of the tech ID.
	extern const kbGetTechName_t kbGetTechName;

	typedef string (*kbGetProtoUnitName_t)(int protoUnitTypeID);
	// Returns the name of the protounit ID.
	extern const kbGetProtoUnitName_t kbGetProtoUnitName;

	typedef int (*kbGetUnitBaseTypeID_t)(int unitID);
	// Returns the base type ID of the unit.
	extern const kbGetUnitBaseTypeID_t kbGetUnitBaseTypeID;

	typedef string (*kbGetUnitTypeName_t)(int unitTypeID);
	// Returns the name of the unit type.
	extern const kbGetUnitTypeName_t kbGetUnitTypeName;

	typedef int (*kbCreateUnitProgression_t)(string unitName, string name);
	// Creates a unit progression of the given name.
	extern const kbCreateUnitProgression_t kbCreateUnitProgression;

	typedef int (*kbCreateTechProgression_t)(string techName, string name);
	// Creates a tech progression of the given name.
	extern const kbCreateTechProgression_t kbCreateTechProgression;

	typedef int (*kbTechTreeGetCheapestUnitUpgrade_t)(int unitTypeID);
	// gets cheapest researchable unit upgrade, optionally for specified unit/unit line.
	extern const kbTechTreeGetCheapestUnitUpgrade_t kbTechTreeGetCheapestUnitUpgrade;

	typedef int (*kbTechTreeGetCheapestEconUpgrade_t)(int resourceUnitTypeID);
	// gets cheapest researchable econ upgrade, optionally for specified resource unit type.
	extern const kbTechTreeGetCheapestEconUpgrade_t kbTechTreeGetCheapestEconUpgrade;

	typedef void (*kbTechTreeDump_t)();
	// Dumps the current state of the KBTT.
	extern const kbTechTreeDump_t kbTechTreeDump;

	typedef int (*kbProgressionGetTotalNodes_t)(int progressionID);
	// Returns the total number of steps to complete the progression.
	extern const kbProgressionGetTotalNodes_t kbProgressionGetTotalNodes;

	typedef float (*kbProgessionGetTotalResourceCost_t)(int progressionID, int resourceID);
	// Returns the total cost of the given resource for this progressionID. A resourceID of -1 will return the total Cost.
	extern const kbProgessionGetTotalResourceCost_t kbProgessionGetTotalResourceCost;

	typedef int (*kbProgressionGetNodeType_t)(int progressionID, int nodeIndex);
	// Returns the type of node at the given index, either Unit type or Tech type.
	extern const kbProgressionGetNodeType_t kbProgressionGetNodeType;

	typedef int (*kbProgressionGetNodeData_t)(int progressionID, int nodeIndex);
	// Returns the data at nodeIndex, either UnitID or TechID, depending on the type.
	extern const kbProgressionGetNodeData_t kbProgressionGetNodeData;

	typedef void (*trEcho_t)(string echoString);
	// Trigger echo.
	extern const trEcho_t trEcho;

	typedef void (*trDelayedRuleActivation_t)(string rulename);
	// adds a rule to the runtime to be activated on the next update.
	extern const trDelayedRuleActivation_t trDelayedRuleActivation;

	typedef int (*trTime_t)();
	// Returns the current gametime in Seconds.
	extern const trTime_t trTime;

	typedef int (*trTimeMS_t)();
	// Returns the current gametime in Milliseconds.
	extern const trTimeMS_t trTimeMS;

	typedef void (*trUnitSelectClear_t)();
	// Clears the units in the trigger selection system.
	extern const trUnitSelectClear_t trUnitSelectClear;

	typedef void (*trUnitSelect_t)(string unitScenarioName);
	// 'Selects' the unit in the trigger selection system.
	extern const trUnitSelect_t trUnitSelect;

	typedef void (*trUnitSelectByID_t)(int unitID);
	// 'Selects' the unit in the trigger selection system.
	extern const trUnitSelectByID_t trUnitSelectByID;

	typedef bool (*trPlayerControlsSocket_t)(int playerID, string objectScenarioName);
	// Returns true if the specified player is built on the specified socket.
	extern const trPlayerControlsSocket_t trPlayerControlsSocket;

	typedef bool (*trIsPlayerVisitingHC_t)(int targetHCPlayerID);
	// Returns true if the current player is looking at (visiting) the home city of the player specified by the player ID passed in.
	extern const trIsPlayerVisitingHC_t trIsPlayerVisitingHC;

	typedef bool (*trIsPlayerSelectingHCBuilding_t)(string hcBuildingName);
	// Returns true if the current player is selecting the building in their HC which has the specified name.
	extern const trIsPlayerSelectingHCBuilding_t trIsPlayerSelectingHCBuilding;

	typedef bool (*trHasPlayerSentHCShipment_t)(int targetHCPlayerID);
	// Returns true when the player has sent a shipment from the home city.
	extern const trHasPlayerSentHCShipment_t trHasPlayerSentHCShipment;

	typedef bool (*trIsPlayerSendingHCShipment_t)(int targetHCPlayerID);
	// Returns true when the player sends a shipment from home city.
	extern const trIsPlayerSendingHCShipment_t trIsPlayerSendingHCShipment;

	typedef bool (*trObjectGettingWorked_t)(string objectScenarioName);
	// Returns true if the object is currently being worked.
	extern const trObjectGettingWorked_t trObjectGettingWorked;

	typedef bool (*trUnitMoveToPoint_t)(float x, float y, float z, int eventID, bool bAttackMove, bool bUnitRun, float runSpeedMultiplier);
	// Moves the selected unit(s) to the given position.
	extern const trUnitMoveToPoint_t trUnitMoveToPoint;

	typedef bool (*trUnitMoveToUnit_t)(string unitScenarioName, int eventID, bool bAttackMove, bool bUnitRun, float runSpeedMultiplier);
	// Moves the selected unit(s) to the spot occupied by the given unit.
	extern const trUnitMoveToUnit_t trUnitMoveToUnit;

	typedef void (*trSetRevealerActiveState_t)(string revealerName, bool active);
	// Finds the specified revealer and sets it to active or inactive.
	extern const trSetRevealerActiveState_t trSetRevealerActiveState;

	typedef void (*trCreateRevealer_t)(int playerID, string revealerName, vector position, float revealerLOS, bool blackmapOnly);
	// Creates a revealer with the given attributes.
	extern const trCreateRevealer_t trCreateRevealer;

	typedef bool (*trUnitMoveFromArea_t)(float x, float y, float z, int eventID, bool bAttackMove, int player, string unitType, float radius);
	// Moves all matching units near the selected unit(s) to the given position.
	extern const trUnitMoveFromArea_t trUnitMoveFromArea;

	typedef bool (*trUnitBuildUnit_t)(string protoUnitName, vector BVector);
	// Selects units and makes the build a unit at specified location
	extern const trUnitBuildUnit_t trUnitBuildUnit;

	typedef bool (*trUnitDoWorkOnUnit_t)(string unitScenarioName, int eventID);
	// Tasks the selected unit(s) to perform work on the given unit.
	extern const trUnitDoWorkOnUnit_t trUnitDoWorkOnUnit;

	typedef void (*trShowDamage_t)(string, string, string, string);
	extern const trShowDamage_t trShowDamage;

	typedef bool (*trUnitGarrison_t)(string unitScenarioName, int eventID);
	// Tasks the selected unit(s) to garrision into another unit.
	extern const trUnitGarrison_t trUnitGarrison;

	typedef void (*trPlayerSetAge_t)(int playerID, int age, bool displayEffect);
	// Sets the age of the specified player.
	extern const trPlayerSetAge_t trPlayerSetAge;

	typedef void (*trPlayerSetHCAccess_t)(int playerID, bool hcAccess);
	// Sets whether the player has access to the HC.
	extern const trPlayerSetHCAccess_t trPlayerSetHCAccess;

	typedef void (*trShowHCView_t)(int playerID);
	// Sets the view to the HC if the player specified is the current player.
	extern const trShowHCView_t trShowHCView;

	typedef void (*trShowWorldView_t)(int playerID);
	// Sets the view to the world if the player specified is the current player.
	extern const trShowWorldView_t trShowWorldView;

	typedef bool (*trImmediateUnitGarrison_t)(string unitScenarioName);
	// Instantly garrisons units inside another unit without considering distance.
	extern const trImmediateUnitGarrison_t trImmediateUnitGarrison;

	typedef float (*trUnitDistanceToPoint_t)(float x, float y, float z);
	// Returns the shortest distance between the trRT units and the point.
	extern const trUnitDistanceToPoint_t trUnitDistanceToPoint;

	typedef float (*trUnitDistanceToUnit_t)(string unitScenarioName);
	// Returns the shortest distance between the trRT units and the given unit.
	extern const trUnitDistanceToUnit_t trUnitDistanceToUnit;

	typedef float (*trUnitDistanceToUnitID_t)(int unitID);
	// Returns the shortest distance between the trRT units and the given unit.
	extern const trUnitDistanceToUnitID_t trUnitDistanceToUnitID;

	typedef float (*trCountUnitsInArea_t)(string centerUnit, int matchPlayer, string matchType, float range);
	extern const trCountUnitsInArea_t trCountUnitsInArea;

	typedef void (*trUnitCinematicRemoveControlAction_t)();
	// Removes the current control action so the next thing can take effect immediately.  (For IGC)
	extern const trUnitCinematicRemoveControlAction_t trUnitCinematicRemoveControlAction;

	typedef bool (*trUnitSetAnimation_t)(string AnimName, int versionIndex, bool loop, int eventID, bool destroyOnNextControlAction);
	// Sets the cinematic animation version for the selected unit(s).
	extern const trUnitSetAnimation_t trUnitSetAnimation;

	typedef bool (*trUnitAlive_t)();
	// Returns true if all selected units are alive.
	extern const trUnitAlive_t trUnitAlive;

	typedef bool (*trUnitDead_t)();
	// Returns true if all selected units are dead.
	extern const trUnitDead_t trUnitDead;

	typedef bool (*trUnitDelete_t)(bool remove);
	// removes or kills the selected unit(s).
	extern const trUnitDelete_t trUnitDelete;

	typedef void (*trUnitDestroy_t)();
	// destroys the selected unit(s).
	extern const trUnitDestroy_t trUnitDestroy;

	typedef bool (*trUnitCreate_t)(string protoName, string scenarioName, float x, float y, float z, int heading, int playerID);
	// creates a new unit.
	extern const trUnitCreate_t trUnitCreate;

	typedef int (*trUnitGetHeading_t)(string scenarioName);
	// returns the units heading.
	extern const trUnitGetHeading_t trUnitGetHeading;

	typedef bool (*trUnitSetHeading_t)(int degrees);
	// sets the units heading.
	extern const trUnitSetHeading_t trUnitSetHeading;

	typedef int (*trUnitSetHP_t)(float hitpoints);
	// set the hitpoints for all selected units.
	extern const trUnitSetHP_t trUnitSetHP;

	typedef bool (*trUnitVisToPlayer_t)();
	// returns true if the player can see the selected unit, and it is on screen.
	extern const trUnitVisToPlayer_t trUnitVisToPlayer;

	typedef bool (*trUnitHasLOS_t)(int playerID);
	// returns true if the player can see the selected unit, otherwise returns false.
	extern const trUnitHasLOS_t trUnitHasLOS;

	typedef void (*trUnitConvert_t)(int playerID);
	// converts the selected units to player.
	extern const trUnitConvert_t trUnitConvert;

	typedef int (*trUnitPercentComplete_t)();
	// returns the percent complete as 0 to 100
	extern const trUnitPercentComplete_t trUnitPercentComplete;

	typedef int (*trUnitPercentDamaged_t)();
	// returns the percent damaged as 0 to 100
	extern const trUnitPercentDamaged_t trUnitPercentDamaged;

	typedef void (*trUnitTeleport_t)(float, float, float);
	// moves units from current position to position specified
	extern const trUnitTeleport_t trUnitTeleport;

	typedef void (*trUnitHighlight_t)(float seconds, bool);
	// does something to highlight the units selected.
	extern const trUnitHighlight_t trUnitHighlight;

	typedef void (*trUnitChangeProtoUnit_t)(string);
	// changes the proto unit for a given set of units.
	extern const trUnitChangeProtoUnit_t trUnitChangeProtoUnit;

	typedef int (*trUnitGetContained_t)();
	// returns the number of units contained.
	extern const trUnitGetContained_t trUnitGetContained;

	typedef bool (*trUnitGetIsContained_t)(string protounit);
	// returns true if this unit is contained by the specified protounit.
	extern const trUnitGetIsContained_t trUnitGetIsContained;

	typedef int (*trUnitEjectContained_t)();
	// ejects all contained units.
	extern const trUnitEjectContained_t trUnitEjectContained;

	typedef bool (*trUnitIsSelected_t)();
	// returns if the specified unit is selected.
	extern const trUnitIsSelected_t trUnitIsSelected;

	typedef bool (*trUnitTypeIsSelected_t)(string);
	// returns if the specified unit is selected.
	extern const trUnitTypeIsSelected_t trUnitTypeIsSelected;

	typedef bool (*trUnitIsOwnedBy_t)(int playerID);
	// determines if the selected units are owned by the player specified.
	extern const trUnitIsOwnedBy_t trUnitIsOwnedBy;

	typedef void (*trUnitSetStance_t)(string);
	// set the stance for the given set of units.
	extern const trUnitSetStance_t trUnitSetStance;

	typedef void (*trCameraCut_t)(vector pos, vector dir, vector up, vector right);
	// puts the camera in the specified location.
	extern const trCameraCut_t trCameraCut;

	typedef void (*trWaypointClear_t)();
	// Clears the waypoints in the trigger selection system.
	extern const trWaypointClear_t trWaypointClear;

	typedef void (*trWaypointAddPoint_t)(vector);
	// Adds the waypoint into the trigger selection system.
	extern const trWaypointAddPoint_t trWaypointAddPoint;

	typedef void (*trWaypointAddUnit_t)(string unitScenarioName);
	// Adds the unit's position as a waypoint in the trigger selection system.
	extern const trWaypointAddUnit_t trWaypointAddUnit;

	typedef int (*trCurrentPlayer_t)();
	// returns the current player.
	extern const trCurrentPlayer_t trCurrentPlayer;

	typedef void (*trSetCurrentPlayerStatus_t)(bool active);
	// sets the current player as active or inactive.
	extern const trSetCurrentPlayerStatus_t trSetCurrentPlayerStatus;

	typedef void (*trSetUserControls_t)(bool active);
	// sets the player controls on or off.
	extern const trSetUserControls_t trSetUserControls;

	typedef int (*trPlayerUnitCount_t)(int playerID);
	// returns the number of units for the player.
	extern const trPlayerUnitCount_t trPlayerUnitCount;

	typedef int (*trPlayerBuildingCount_t)(int playerID);
	// returns the number of buildings for the player.
	extern const trPlayerBuildingCount_t trPlayerBuildingCount;

	typedef int (*trPlayerUnitAndBuildingCount_t)(int playerID);
	// returns the number of units and buildings for the player.
	extern const trPlayerUnitAndBuildingCount_t trPlayerUnitAndBuildingCount;

	typedef int (*trPlayerUnitCountSpecific_t)(int playerID, string protoName);
	// returns the number of units for the player.
	extern const trPlayerUnitCountSpecific_t trPlayerUnitCountSpecific;

	typedef int (*trPlayerTribute_t)(int from, string resource, int amount, int to);
	// tributes resources to a player.
	extern const trPlayerTribute_t trPlayerTribute;

	typedef void (*trPlayerToggleAllowTCSpawning_t)(int playerID, bool allowSpawning);
	// Toggles whether the player's TC can spawn units.
	extern const trPlayerToggleAllowTCSpawning_t trPlayerToggleAllowTCSpawning;

	typedef void (*trPlayerToggleAllowNewCWSpawning_t)(int playerID, bool allowSpawning);
	// Toggles whether the player can spawn new covered wagons.
	extern const trPlayerToggleAllowNewCWSpawning_t trPlayerToggleAllowNewCWSpawning;

	typedef int (*trPlayerResourceCount_t)(int playerID, string resource);
	// returns the number of resources for the player.
	extern const trPlayerResourceCount_t trPlayerResourceCount;

	typedef int (*trPlayerCurrentXPCount_t)(int playerID);
	// Returns the current (not total) XP for the player.
	extern const trPlayerCurrentXPCount_t trPlayerCurrentXPCount;

	typedef bool (*trPlayerDefeated_t)(int playerID);
	// returns true/false if the player has been defeated.
	extern const trPlayerDefeated_t trPlayerDefeated;

	typedef bool (*trPlayerActive_t)(int playerID);
	// returns true/false if the player is active.
	extern const trPlayerActive_t trPlayerActive;

	typedef void (*trSetPlayerDefeated_t)(int);
	// call this when a player is defeated on the local machine (meaning that this func must be called synchronously on all machines, it will not pass around a command.)
	extern const trSetPlayerDefeated_t trSetPlayerDefeated;

	typedef void (*trSetPlayerWon_t)(int);
	// call this when a player has won on the local machine (meaning that this func must be called synchronously on all machines, it will not pass around a command.)
	extern const trSetPlayerWon_t trSetPlayerWon;

	typedef void (*trEndGame_t)();
	// Signal that the game has ended.
	extern const trEndGame_t trEndGame;

	typedef void (*trPlayerSetDiplomacy_t)(int playerID, int player2ID, string status);
	// sets the diplomacy status between players.
	extern const trPlayerSetDiplomacy_t trPlayerSetDiplomacy;

	typedef string (*trPlayerGetDiplomacy_t)(int playerID, int player2ID);
	// gets the diplomacy status between players.
	extern const trPlayerGetDiplomacy_t trPlayerGetDiplomacy;

	typedef void (*trPlayerModifyLOS_t)(int, bool, int);
	// Adds/removes LOS between players.
	extern const trPlayerModifyLOS_t trPlayerModifyLOS;

	typedef int (*trPlayerCountBuildingInProgress_t)(int playerID, string protoname);
	// returns true if building is being built.
	extern const trPlayerCountBuildingInProgress_t trPlayerCountBuildingInProgress;

	typedef bool (*trBuildingIsOnCursor_t)(string protoname);
	// Returns true if the proto unit specified is on the cursor and is a building.
	extern const trBuildingIsOnCursor_t trBuildingIsOnCursor;

	typedef int (*trPlayerSetActive_t)(int playerID);
	// sets the active player.
	extern const trPlayerSetActive_t trPlayerSetActive;

	typedef void (*trObjectiveComplete_t)(int objectiveID, bool forceComplete, bool playSound);
	// Completes the specified objective.  Forces a reoccurring objective complete if forceComplete is true.
	extern const trObjectiveComplete_t trObjectiveComplete;

	typedef void (*trObjectiveHide_t)(int objectiveID);
	// Hides the specified objective on the UI.
	extern const trObjectiveHide_t trObjectiveHide;

	typedef void (*trObjectiveShow_t)(int objectiveID);
	// Shows the specified objective on the UI.
	extern const trObjectiveShow_t trObjectiveShow;

	typedef void (*trObjectiveDiscover_t)(int objectiveID, bool playSound);
	// 'Discovers' a previously unknown (to the player) objective.
	extern const trObjectiveDiscover_t trObjectiveDiscover;

	typedef bool (*trPlayerAtPopCap_t)(int playerID);
	// returns true if player is at pop cap.
	extern const trPlayerAtPopCap_t trPlayerAtPopCap;

	typedef int (*trPlayerGetPopulation_t)(int playerID);
	// returns the player population.
	extern const trPlayerGetPopulation_t trPlayerGetPopulation;

	typedef void (*trSetCinematicUnitSpeaking_t)(string objectScenarioName, bool speaking, int duration);
	// Sets the unit as speaking or not.
	extern const trSetCinematicUnitSpeaking_t trSetCinematicUnitSpeaking;

	typedef bool (*trEventSetHandler_t)(int eventID, string handler);
	// sets a handler function for an event id.
	extern const trEventSetHandler_t trEventSetHandler;

	typedef void (*trEventFire_t)(int eventID);
	// cause an event to occur.
	extern const trEventFire_t trEventFire;

	typedef void (*trSetUnitIdleProcessing_t)(bool);
	// Sets whether or not units can do their idle processing.
	extern const trSetUnitIdleProcessing_t trSetUnitIdleProcessing;

	typedef void (*trSetObscuredUnits_t)(bool);
	// Sets whether or not units can be drawn obscured or not.
	extern const trSetObscuredUnits_t trSetObscuredUnits;

	typedef void (*trLetterBox_t)(bool onOff);
	// Turns letter box mode on or off.
	extern const trLetterBox_t trLetterBox;

	typedef void (*trSoundPlayFN_t)(string filename, string, int, string, string);
	// Plays the sound associated with the filename.
	extern const trSoundPlayFN_t trSoundPlayFN;

	typedef void (*trSoundPlayPaused_t)(string filename, string, int, string, string);
	// Plays the sound associated with the filename.
	extern const trSoundPlayPaused_t trSoundPlayPaused;

	typedef void (*trSoundTimer_t)(int milliseconds, int eventID);
	// creates a high performance sound timer and passes the eventID as data.
	extern const trSoundTimer_t trSoundTimer;

	typedef void (*trFadeOutMusic_t)(float duration);
	// Fades out current music over a given duration.
	extern const trFadeOutMusic_t trFadeOutMusic;

	typedef void (*trPlayNextMusicTrack_t)();
	// Plays the next song in the music play list.
	extern const trPlayNextMusicTrack_t trPlayNextMusicTrack;

	typedef void (*trFadeOutAllSounds_t)(float duration);
	// Fades out all sounds over a given duration
	extern const trFadeOutAllSounds_t trFadeOutAllSounds;

	typedef void (*trBlockAllSounds_t)(bool excludeDialog);
	// Blocks all sounds from playing from this point forward
	extern const trBlockAllSounds_t trBlockAllSounds;

	typedef void (*trUnblockAllSounds_t)();
	// Unblocks all sounds that were previously blocked from playing
	extern const trUnblockAllSounds_t trUnblockAllSounds;

	typedef void (*trBlockAllAmbientSounds_t)();
	// blocks all ambient sounds from this point forward
	extern const trBlockAllAmbientSounds_t trBlockAllAmbientSounds;

	typedef void (*trUnBlockAllAmbientSounds_t)();
	// Unblocks all ambient sounds that were previously blocked from playing
	extern const trUnBlockAllAmbientSounds_t trUnBlockAllAmbientSounds;

	typedef void (*trSoundPlayDialog_t)(string filename, string event, int ignoreOnAbort, bool subtitle, string portrait, string);
	// Plays the sound associated with the filename.
	extern const trSoundPlayDialog_t trSoundPlayDialog;

	typedef void (*trSoundPlayDialogue_t)(string stringID, int eventID, bool ignoreOnAbort, int seconds);
	// Plays the sound associated with the dialogue.
	extern const trSoundPlayDialogue_t trSoundPlayDialogue;

	typedef void (*trMusicPlay_t)(string filename, string duration, float);
	// Plays the music file.
	extern const trMusicPlay_t trMusicPlay;

	typedef void (*trMusicPlayCurrent_t)();
	// Plays the current music.
	extern const trMusicPlayCurrent_t trMusicPlayCurrent;

	typedef void (*trMusicStop_t)();
	// Stops the current music.
	extern const trMusicStop_t trMusicStop;

	typedef void (*trMusicSetCurrentMusicSet_t)(int);
	// sets the current music set.
	extern const trMusicSetCurrentMusicSet_t trMusicSetCurrentMusicSet;

	typedef void (*trMusicSetMood_t)(int moodID);
	// Changes the music to mood associated with mood id.
	extern const trMusicSetMood_t trMusicSetMood;

	typedef void (*trCamTrackLoad_t)(string filename);
	// Loads a camera track.
	extern const trCamTrackLoad_t trCamTrackLoad;

	typedef void (*trCamTrackPlay_t)(float duration, int eventID);
	// plays the current camera track.
	extern const trCamTrackPlay_t trCamTrackPlay;

	typedef void (*trMessageSetText_t)(string text, int timeout);
	// displays the message text.
	extern const trMessageSetText_t trMessageSetText;

	typedef void (*trChatSetStatus_t)(bool onOff);
	// Changes the chat status.
	extern const trChatSetStatus_t trChatSetStatus;

	typedef void (*trChatSend_t)(int fromID, string message);
	// Changes the chat status.
	extern const trChatSend_t trChatSend;

	typedef void (*trChatSendToPlayer_t)(int fromID, int toID, string message);
	// Changes the chat status for one specific player.
	extern const trChatSendToPlayer_t trChatSendToPlayer;

	typedef void (*trChatSendSpoofed_t)(int fromID, string message);
	// Changes the chat status, but does not append player.
	extern const trChatSendSpoofed_t trChatSendSpoofed;

	typedef void (*trChatSendSpoofedToPlayer_t)(int fromID, int toID, string message);
	// Changes the chat status, but does not append player.  Goes to specific player.
	extern const trChatSendSpoofedToPlayer_t trChatSendSpoofedToPlayer;

	typedef void (*trWriteToLog_t)(string message);
	// Writes text to the Age3Log
	extern const trWriteToLog_t trWriteToLog;

	typedef void (*trGamePause_t)(bool);
	// pause or unpause the game.
	extern const trGamePause_t trGamePause;

	typedef void (*trGameLoadScenario_t)(string scenario);
	// start a game using scenario.
	extern const trGameLoadScenario_t trGameLoadScenario;

	typedef void (*trBranchScenario_t)(string);
	// pop up a dialog allowing choice to load a scenario.
	extern const trBranchScenario_t trBranchScenario;

	typedef bool (*trTechStatusActive_t)(int playerID, int techID);
	// returns true if tech is active for player.
	extern const trTechStatusActive_t trTechStatusActive;

	typedef bool (*trTechStatusResearching_t)(int playerID, int techID);
	// returns true if tech is being researched for player.
	extern const trTechStatusResearching_t trTechStatusResearching;

	typedef bool (*trTechStatusCheck_t)(int playerID, int techID, int techStatus);
	// returns true if tech's status is techStatus.
	extern const trTechStatusCheck_t trTechStatusCheck;

	typedef void (*trTechSetStatus_t)(int playerID, int techID, int status);
	// sets the tech status for the player.
	extern const trTechSetStatus_t trTechSetStatus;

	typedef void (*trYouWin_t)(bool directToMenu);
	// player wins.  If you set directToMenu to true, you go directly to Campaign Menu.
	extern const trYouWin_t trYouWin;

	typedef void (*trYouLose_t)(string text);
	// player loses, specifies message.
	extern const trYouLose_t trYouLose;

	typedef void (*trShowWinLose_t)(string text, string soundfile, string, bool);
	// message and sound.
	extern const trShowWinLose_t trShowWinLose;

	typedef void (*trShowCampaignDlg_t)(string NextCampaign, string);
	// .
	extern const trShowCampaignDlg_t trShowCampaignDlg;

	typedef void (*trRenderSky_t)(bool, string skyName);
	// turn sky rendering on/off and set which sky to use.
	extern const trRenderSky_t trRenderSky;

	typedef void (*trRenderSnow_t)(float percent);
	// controls snow rendering.
	extern const trRenderSnow_t trRenderSnow;

	typedef void (*trRenderRain_t)(float percent);
	// controls rain rendering.
	extern const trRenderRain_t trRenderRain;

	typedef void (*trSetFogAndBlackmap_t)(bool, bool);
	// turn fog and black map on/off.
	extern const trSetFogAndBlackmap_t trSetFogAndBlackmap;

	typedef void (*trStartGameRecord_t)(string);
	// add help string.
	extern const trStartGameRecord_t trStartGameRecord;

	typedef void (*trStopGameRecord_t)();
	// add help string.
	extern const trStopGameRecord_t trStopGameRecord;

	typedef void (*trArmySelect_t)(string army);
	// selects the units in the army specified.
	extern const trArmySelect_t trArmySelect;

	typedef void (*trArmySelectInt_t)(int playerID, int armyID);
	// selects the units in the army specified.
	extern const trArmySelectInt_t trArmySelectInt;

	typedef bool (*trArmyDispatch_t)(string parameters, string, int, float, float, float, int, bool);
	// creates the units in the army specified.
	extern const trArmyDispatch_t trArmyDispatch;

	typedef void (*trSetLighting_t)(string setname, float fadetime);
	// fades to the specified lighting set over fadetime.
	extern const trSetLighting_t trSetLighting;

	typedef void (*trCounterAddTime_t)(string name, int start, int stop, string message, int event);
	// start a counter that may or may not fire an event.
	extern const trCounterAddTime_t trCounterAddTime;

	typedef void (*trCounterAddTimeMs_t)(string name, int start, int stop, string message, int event);
	// start a counter that may or may not fire an event.
	extern const trCounterAddTimeMs_t trCounterAddTimeMs;

	typedef void (*trCounterAddUnit_t)(string name, int playerid, int count, string protounit, string message, int event);
	// start a counter that may or may not fire an event.
	extern const trCounterAddUnit_t trCounterAddUnit;

	typedef void (*trCounterAddXP_t)(string, int, int, string, int);
	// start a counter that may or may not fire an event.
	extern const trCounterAddXP_t trCounterAddXP;

	typedef void (*trCounterAbort_t)(string name);
	// abort a counter.
	extern const trCounterAbort_t trCounterAbort;

	typedef bool (*trCinematicAbort_t)();
	// returns the abort cinematic status.
	extern const trCinematicAbort_t trCinematicAbort;

	typedef void (*trCinematicDoAbort_t)();
	// aborts the cinematic.
	extern const trCinematicDoAbort_t trCinematicDoAbort;

	typedef void (*trForceNonCinematicModels_t)(bool);
	// forces models to be in non cinematic mode
	extern const trForceNonCinematicModels_t trForceNonCinematicModels;

	typedef void (*trFormationScale_t)(float scale);
	// scales the formation size of formations in the game.
	extern const trFormationScale_t trFormationScale;

	typedef int (*trGetNumberNuggetsGathered_t)(int);
	// Returns the number of nuggets gathered by the specified player.
	extern const trGetNumberNuggetsGathered_t trGetNumberNuggetsGathered;

	typedef bool (*trHasNuggetBeenCollected_t)(string, int);
	// Returns true if the nugget has been collected, the playerID is an optional parameter for querying if the specific player has collected it.
	extern const trHasNuggetBeenCollected_t trHasNuggetBeenCollected;

	typedef void (*trUIFlash_t)(string gadget, int name, float flashLimit, float colorR, float colorG);
	// flashes a UI element.
	extern const trUIFlash_t trUIFlash;

	typedef void (*trUIStopFlash_t)(string gadget);
	// stops the flashing of a UI element.
	extern const trUIStopFlash_t trUIStopFlash;

	typedef void (*trUIFlashTech_t)(int, bool);
	// flashes a UI element (maybe).
	extern const trUIFlashTech_t trUIFlashTech;

	typedef void (*trUIFlashTrain_t)(string, bool);
	// flashes a UI element (maybe).
	extern const trUIFlashTrain_t trUIFlashTrain;

	typedef void (*trUIFlashCategory_t)(int category, bool flash);
	// flashes a UI element (maybe).
	extern const trUIFlashCategory_t trUIFlashCategory;

	typedef void (*trUIFadeToColor_t)(int r, int g, int b, int duration, int delay, bool inout, int);
	// fade in/out using color specified.
	extern const trUIFadeToColor_t trUIFadeToColor;

	typedef void (*trRateConstruction_t)(float rate);
	// modify construction rate.
	extern const trRateConstruction_t trRateConstruction;

	typedef void (*trRateTrain_t)(float rate);
	// modify training rate.
	extern const trRateTrain_t trRateTrain;

	typedef void (*trRateResearch_t)(float rate);
	// modify research rate.
	extern const trRateResearch_t trRateResearch;

	typedef void (*trRatesNormal_t)();
	// restore all rates to normal.
	extern const trRatesNormal_t trRatesNormal;

	typedef void (*trMinimapFlare_t)(int playerID, float duration, vector position, bool flash);
	// Sends a Minimap flare to a certain player.
	extern const trMinimapFlare_t trMinimapFlare;

	typedef void (*trCameraShake_t)(float duration, float strength);
	// Makes the camera shake.
	extern const trCameraShake_t trCameraShake;

	typedef void (*trPlayerResetBlackMap_t)(int playerID);
	// Resets the black map for a given HUMAN player.
	extern const trPlayerResetBlackMap_t trPlayerResetBlackMap;

	typedef void (*trPlayerResetBlackMapForAllPlayers_t)();
	// Resets the black map for all HUMAN players.
	extern const trPlayerResetBlackMapForAllPlayers_t trPlayerResetBlackMapForAllPlayers;

	typedef void (*trPlayerKillAllUnits_t)(int playerID);
	// Kills all of the units of a given player.
	extern const trPlayerKillAllUnits_t trPlayerKillAllUnits;

	typedef void (*trPlayerKillAllBuildings_t)(int playerID);
	// Kills all of the buildings of a given player.
	extern const trPlayerKillAllBuildings_t trPlayerKillAllBuildings;

	typedef bool (*trIsGadgetVisible_t)(string name);
	// returns true if gadget is real.
	extern const trIsGadgetVisible_t trIsGadgetVisible;

	typedef void (*trModeEnter_t)(string name);
	// enters the mode specified.
	extern const trModeEnter_t trModeEnter;

	typedef void (*trCampaignAdvance_t)();
	// advances the campaign (advance user profile, AND plays the next scenario).
	extern const trCampaignAdvance_t trCampaignAdvance;

	typedef void (*trCampaignAdvanceProgress_t)();
	// advances the user progress through the campaign.(updates user profile only)
	extern const trCampaignAdvanceProgress_t trCampaignAdvanceProgress;

	typedef void (*trCampaignPlayCurrent_t)();
	// plays the current scenario in the campaign
	extern const trCampaignPlayCurrent_t trCampaignPlayCurrent;

	typedef void (*trPlayerGrantResources_t)(int player, string resource, int amount);
	// advances the campaign.
	extern const trPlayerGrantResources_t trPlayerGrantResources;

	typedef void (*trUnitPlayerFakify_t)(int fakePlayerIndex);
	// Sets the selected unit as having the fake player with the specified index (0-7)
	extern const trUnitPlayerFakify_t trUnitPlayerFakify;

	typedef void (*trArmyPlayerFakify_t)(string armyname, int fakeplayerindex);
	// Fakifies the army to the specified fake player index.
	extern const trArmyPlayerFakify_t trArmyPlayerFakify;

	typedef void (*trUnitPlayerDefakify_t)();
	// Sets the selected unit as not having a fake player
	extern const trUnitPlayerDefakify_t trUnitPlayerDefakify;

	typedef void (*trArmyPlayerDefakify_t)(string armyname);
	// Defakifies the army.
	extern const trArmyPlayerDefakify_t trArmyPlayerDefakify;

	typedef void (*trAIFunc_t)(int playerID, string functionName, int param);
	// Makes the camera shake.
	extern const trAIFunc_t trAIFunc;

	typedef int (*trGetNumberSelectedUnitIDs_t)();
	extern const trGetNumberSelectedUnitIDs_t trGetNumberSelectedUnitIDs;

	typedef int (*trGetSelectedUnitID_t)(int index);
	extern const trGetSelectedUnitID_t trGetSelectedUnitID;

	typedef int (*trGetWorldDifficulty_t)();
	extern const trGetWorldDifficulty_t trGetWorldDifficulty;

	typedef bool (*trUnforbidProtounit_t)(int player, string protoname);
	// removes protounit from the forbidden list
	extern const trUnforbidProtounit_t trUnforbidProtounit;

	typedef bool (*trForbidProtounit_t)(int player, string protoname);
	// adds protounit to the forbidden list
	extern const trForbidProtounit_t trForbidProtounit;

	typedef void (*trSetPauseOnAgeUpgrade_t)(bool);
	extern const trSetPauseOnAgeUpgrade_t trSetPauseOnAgeUpgrade;

	typedef void (*trSetPauseInObjectiveWindow_t)(bool);
	extern const trSetPauseInObjectiveWindow_t trSetPauseInObjectiveWindow;

	typedef void (*trSetCounterDisplay_t)(string text);
	extern const trSetCounterDisplay_t trSetCounterDisplay;

	typedef void (*trClearCounterDisplay_t)();
	extern const trClearCounterDisplay_t trClearCounterDisplay;

	typedef void (*trPlayMovie_t)(string FileName);
	// plays movies from the AVI directory
	extern const trPlayMovie_t trPlayMovie;

	typedef bool (*trIsMovieNotPlaying_t)();
	// returns false if a movie is currently playing
	extern const trIsMovieNotPlaying_t trIsMovieNotPlaying;

	typedef void (*trRevealEntireMap_t)();
	// shows whole map, similar to how revealed mode works
	extern const trRevealEntireMap_t trRevealEntireMap;

	typedef void (*trUnitChangeName_t)(string name);
	// set an override name for a specific unit
	extern const trUnitChangeName_t trUnitChangeName;

	typedef bool (*trChatHistoryContains_t)(string text, int);
	// returns whether or not the current chat history has any instance (substring) of this text
	extern const trChatHistoryContains_t trChatHistoryContains;

	typedef void (*trChatHistoryClear_t)();
	// forces the chat history to reset
	extern const trChatHistoryClear_t trChatHistoryClear;

	typedef int (*trGetStatValue_t)(int player, int stat);
	// fetch a stat value from the KB
	extern const trGetStatValue_t trGetStatValue;

	typedef void (*trEchoStatValue_t)(int player, int stat);
	// fetch a stat value from the KB and echo to chat
	extern const trEchoStatValue_t trEchoStatValue;

	typedef void (*trShowImageDialog_t)(string texture, string subtitle);
	// displays a custom image in a dialog, with a subtitle
	extern const trShowImageDialog_t trShowImageDialog;

	typedef void (*trShowChoiceDialog_t)(string maintext, string choice1, int event1, string choice2, int event2);
	// displays dialog with 2 choices, and activates a trigger in response
	extern const trShowChoiceDialog_t trShowChoiceDialog;

	typedef void (*trModifyProtounit_t)(string unit, int player, int field, float delta);
	// modifies proto unit data for this scenario only.
	extern const trModifyProtounit_t trModifyProtounit;

	typedef void (*trDamageUnitPercent_t)(float percent);
	// does % percent of a unit's total HP in instant typeless damage.
	extern const trDamageUnitPercent_t trDamageUnitPercent;

	typedef void (*trDamageUnit_t)(float amt);
	// does a specific amount of damage to HP in instant typeless damage.
	extern const trDamageUnit_t trDamageUnit;

	typedef void (*trDamageUnitsInArea_t)(int player, string unitType, float dist, float damage);
	// All units within dist of the selected ref object that match type take dmg
	extern const trDamageUnitsInArea_t trDamageUnitsInArea;

	typedef void (*trOverlayText_t)(string message, float time, int x, int y, int width, string background);
	// puts up a big movie-credits style text overlay, optionally in a strange location, and now with a background
	extern const trOverlayText_t trOverlayText;

	typedef void (*trQuestVarSet_t)(string varname, float value);
	// sets one of the trigger scratch variables
	extern const trQuestVarSet_t trQuestVarSet;

	typedef void (*trQuestVarCopy_t)(string var1, string var2);
	// copies value of one of the trigger scratch variables
	extern const trQuestVarCopy_t trQuestVarCopy;

	typedef void (*trQuestVarSetFromRand_t)(string varname, float minval, float maxval, bool round);
	// sets one of the trigger scratch variables within a random range
	extern const trQuestVarSetFromRand_t trQuestVarSetFromRand;

	typedef float (*trQuestVarGet_t)(string varname);
	// retrieve value of a trigger scratch variable, returns zero if unset
	extern const trQuestVarGet_t trQuestVarGet;

	typedef void (*trQuestVarEcho_t)(string varname);
	// chats out the value of one of the trigger scratch variables
	extern const trQuestVarEcho_t trQuestVarEcho;

	typedef void (*trGrantVP_t)(int player, int number);
	// Grants a number of Scenario VP to a player
	extern const trGrantVP_t trGrantVP;

	typedef int (*trPlayerVPCount_t)(int playerID);
	// returns the number of victory points for the player.
	extern const trPlayerVPCount_t trPlayerVPCount;

	typedef void (*trVPAnnualAwards_t)(bool enable);
	// enables/disables the award of VP's each year.
	extern const trVPAnnualAwards_t trVPAnnualAwards;

	typedef void (*trCreateTreaty_t)(int, int, int, bool, bool, float, float, float);
	extern const trCreateTreaty_t trCreateTreaty;

	typedef int (*vcGetGameplayMode_t)();
	// returns the current gameplay mode index
	extern const vcGetGameplayMode_t vcGetGameplayMode;

	typedef bool (*vcCheckConquestVictory_t)();
	// checks for victory by being the last allied-unit alive
	extern const vcCheckConquestVictory_t vcCheckConquestVictory;

	typedef bool (*trUnitFaceUnit_t)(string unitScenarioName, int eventID);
	// Moves the selected unit(s) to face the given unit.
	extern const trUnitFaceUnit_t trUnitFaceUnit;

	typedef void (*trCameraLockOnUnit_t)(bool enable, int time, int to);
	// Orients the camera to the selected unit, and keeps it locked on that unit. ): puts the camera in the specified location.
	extern const trCameraLockOnUnit_t trCameraLockOnUnit;

	typedef void (*trCameraPanWithUnit_t)(bool enable, int trigger);
	// Moves the camera in the same direction that a particular unit moves.
	extern const trCameraPanWithUnit_t trCameraPanWithUnit;

	typedef void (*trDisableTrigger_t)(int eventID);
	// Disables (sets active = false) the trigger specified by the given eventID.
	extern const trDisableTrigger_t trDisableTrigger;

	typedef void (*trActivateTrigger_t)(int eventID);
	// Activates (sets active = true) the trigger specified by the given eventID.
	extern const trActivateTrigger_t trActivateTrigger;

	typedef void (*trUnitMakeInvulnerable_t)(bool enable);
	// Makes a unit invulnerable to damage.  Turn it off to return the unit to normal.
	extern const trUnitMakeInvulnerable_t trUnitMakeInvulnerable;

	typedef void (*trUnitSuspendAction_t)(string actionName, bool suspend);
	// Makes an action on a unit suspened or not.
	extern const trUnitSuspendAction_t trUnitSuspendAction;

	typedef void (*trCreateDefendPlan_t)(string armyName, string defendPlanName, float defendX, float defendY, float defendZ, float engageRange, int evaluationFrequency, float gatherdistance);
	// No help 
	extern const trCreateDefendPlan_t trCreateDefendPlan;

	typedef void (*trCreateAttackPlan_t)(string armyName, string PlanName, int attackPlayerID, float attackX, float attackY, float attackZ, float engageRange, int evaluationFrequency);
	// No help 
	extern const trCreateAttackPlan_t trCreateAttackPlan;

	typedef void (*trKillAIPlan_t)(int playerID, string planName);
	// No help 
	extern const trKillAIPlan_t trKillAIPlan;

	typedef void (*trAddArmyToPlan_t)(string armyname, string planname);
	// Adds the units in the specified army to the specified plan.
	extern const trAddArmyToPlan_t trAddArmyToPlan;

	typedef void (*trDefendUnits_t)(string srcArmyname, string defendedArmyname, string planname, int evaluationFrequency, float gatherdistance);
	// srcArmy units will defend defendedArmyUnits in the given planname.
	extern const trDefendUnits_t trDefendUnits;

	typedef void (*trAttackUnits_t)(string srcArmyname, string armyToAttack, string planname);
	// srcArmy units will attack armyToAttack in the given planname.
	extern const trAttackUnits_t trAttackUnits;

	typedef void (*trAICommsAttackUnits_t)(int playerID, string armyToAttack);
	// playerID will attack armyToAttack, sent via player Comms.
	extern const trAICommsAttackUnits_t trAICommsAttackUnits;

	typedef void (*trAICommsDefendPoint_t)(int playerID, float defendX, float defendY, float defendZ);
	// playerID will defend point(defendX, defendY, defendZ), sent via player Comms.
	extern const trAICommsDefendPoint_t trAICommsDefendPoint;

	typedef void (*trAICommsRequestTribute_t)(int fromPlayerID, string resource, float amount);
	// fromPlayerID will send resource of x amount, sent via player Comms.
	extern const trAICommsRequestTribute_t trAICommsRequestTribute;

	typedef void (*trAICommsCancelOrder_t)(int sendToPlayerID);
	// tell player sendToPlayerID to cancel order, sent via player Comms.
	extern const trAICommsCancelOrder_t trAICommsCancelOrder;

	typedef void (*trAICommsClaim_t)(int sendToPlayerID, float, float, float);
	// tell player sendToPlayerID to claim TradePost at (locX, locY, locZ), sent via player Comms.
	extern const trAICommsClaim_t trAICommsClaim;

	typedef void (*trAICommsTrain_t)(int sendToPlayerID, string unitTypeName);
	// tell player sendToPlayerID to train Units of type unitTypeName, sent via player Comms.
	extern const trAICommsTrain_t trAICommsTrain;

	typedef void (*trTradeRouteSetPosition_t)(int position, float);
	// Places train on a specified position on the route.
	extern const trTradeRouteSetPosition_t trTradeRouteSetPosition;

	typedef void (*trTradeRouteToggleState_t)(int position, bool);
	// Enable or disables the unit from showing.
	extern const trTradeRouteToggleState_t trTradeRouteToggleState;

	typedef void (*trTradeRouteSetLevel_t)(int traderouteindex, int level);
	// Sets the specified trade route to the specified level from a trigger.
	extern const trTradeRouteSetLevel_t trTradeRouteSetLevel;

	typedef void (*trSetShadowFarClip_t)(bool enable, float distance);
	// Enable or disables the shadow far clippping plane.
	extern const trSetShadowFarClip_t trSetShadowFarClip;

	typedef void (*trShowSPCNote_t)(string Title, string Text);
	// Displays the SPC Note Dlg with the specified title and text.
	extern const trShowSPCNote_t trShowSPCNote;

	typedef void (*trPlayerOverrideArtCulture_t)(int playerID, string culture);
	// Overrides the culture used for choosing the player's art.
	extern const trPlayerOverrideArtCulture_t trPlayerOverrideArtCulture;

	typedef void (*trPlayerOverrideSoundCiv_t)(int playerID, string civilization);
	// Overrides the civilization used for choosing the player's vocal sound effects.
	extern const trPlayerOverrideSoundCiv_t trPlayerOverrideSoundCiv;

	extern const int cUnitStanceAggressive;
	extern const int cUnitStanceDefensive;
	extern const int cUnitStancePassive;
	extern const int cUnitStanceStandGround;
	extern const int cGameModeSupremacy;
	extern const int cGameModeConquest;
	extern const int cGameModeLightning;
	extern const int cGameModeDeathmatch;
	extern const int cDifficultySandbox;
	extern const int cDifficultyEasy;
	extern const int cDifficultyModerate;
	extern const int cDifficultyHard;
	extern const int cDifficultyExpert;
	extern const int cAge1;
	extern const int cAge2;
	extern const int cAge3;
	extern const int cAge4;
	extern const int cAge5;
	extern const int cPlayerRelationAny;
	extern const int cPlayerRelationSelf;
	extern const int cPlayerRelationEnemy;
	extern const int cPlayerRelationAlly;
	extern const int cPlayerRelationEnemyNotGaia;
	extern const int cHCCardTypeEcon;
	extern const int cHCCardTypeMilitary;
	extern const int cHCCardTypeWagon;
	extern const int cHCCardTypeTeam;
	extern const int cRGPScript;
	extern const int cRGPCost;
	extern const int cRGPActual;
	extern const int cNuggetTypeAdjustResource;
	extern const int cNuggetTypeSpawnUnit;
	extern const int cNuggetTypeGiveLOS;
	extern const int cNuggetTypeAdjustSpeed;
	extern const int cNuggetTypeAdjustHP;
	extern const int cNuggetTypeConvertUnit;
	extern const int cNuggetTypeGiveTech;
	extern const int cAIResourceSubTypeEasy;
	extern const int cAIResourceSubTypeHerdable;
	extern const int cAIResourceSubTypeHunt;
	extern const int cAIResourceSubTypeHuntAggressive;
	extern const int cAIResourceSubTypeFarm;
	extern const int cAIResourceSubTypeFish;
	extern const int cAIResourceSubTypeTrade;
	extern const int cMaxSettlersPerMine;
	extern const int cMaxSettlersPerMill;
	extern const int cTSFactorDistance;
	extern const int cTSFactorPoint;
	extern const int cTSFactorTimeToDone;
	extern const int cTSFactorBase;
	extern const int cTSFactorDanger;
	extern const int cRootEscrowID;
	extern const int cEconomyEscrowID;
	extern const int cMilitaryEscrowID;
	extern const int cEmergencyEscrowID;
	extern const int cPlanMove;
	extern const int cPlanAttack;
	extern const int cPlanBuild;
	extern const int cPlanTrain;
	extern const int cPlanResearch;
	extern const int cPlanWork;
	extern const int cPlanGather;
	extern const int cPlanExplore;
	extern const int cPlanData;
	extern const int cPlanProgression;
	extern const int cPlanFarm;
	extern const int cPlanHunt;
	extern const int cPlanHuntAggressive;
	extern const int cPlanFish;
	extern const int cPlanHerd;
	extern const int cPlanTransport;
	extern const int cPlanAttackStrategy;
	extern const int cPlanRemoved1;
	extern const int cPlanDefend;
	extern const int cPlanReserve;
	extern const int cPlanGoal;
	extern const int cPlanGatherGoal;
	extern const int cPlanTrade;
	extern const int cPlanGatherNuggets;
	extern const int cPlanMission;
	extern const int cPlanBuildWall;
	extern const int cPlanTownBell;
	extern const int cPlanTower;
	extern const int cPlanNativeResearch;
	extern const int cOpportunitySourceAutoGenerated;
	extern const int cOpportunitySourceAllyRequest;
	extern const int cOpportunitySourceTrigger;
	extern const int cOpportunityTypeDestroy;
	extern const int cOpportunityTypeClaim;
	extern const int cOpportunityTypeRaid;
	extern const int cOpportunityTypeDefend;
	extern const int cOpportunityTypeRescueExplorer;
	extern const int cOpportunityTargetTypeBase;
	extern const int cOpportunityTargetTypeVPSite;
	extern const int cOpportunityTargetTypeResource;
	extern const int cOpportunityTargetTypePointRadius;
	extern const int cOpportunityTargetTypeUnitList;
	extern const int cMissionTypeNone;
	extern const int cMissionTypeAttack;
	extern const int cMissionTypeDefend;
	extern const int cMissionTypeClaim;
	extern const int cMissionTypeRaid;
	extern const int cPlanStateNone;
	extern const int cPlanStateDone;
	extern const int cPlanStateFailed;
	extern const int cPlanStateBuild;
	extern const int cPlanStateGather;
	extern const int cPlanStatePlace;
	extern const int cPlanStateExplore;
	extern const int cPlanStateTrain;
	extern const int cPlanStateResearch;
	extern const int cPlanStateAttack;
	extern const int cPlanStateGoto;
	extern const int cPlanStateEmpower;
	extern const int cPlanStateEnter;
	extern const int cPlanStateExit;
	extern const int cPlanStateEvaluate;
	extern const int cPlanStatePatrol;
	extern const int cPlanStateRetreat;
	extern const int cPlanStateWorking;
	extern const int cPlanStateTransport;
	extern const int cPlanStateDualPlace;
	extern const int cPlanStateWait;
	extern const int cPlanStateCast;
	extern const int cPlanStateVillagerAttack;
	extern const int cPlanStateClaimNugget;
	extern const int cPlanStateGatherResources;
	extern const int cPlanStateIdle;
	extern const int cPlanEventDone;
	extern const int cPlanEventFailed;
	extern const int cPlanEventPoll;
	extern const int cPlanEventIdle;
	extern const int cPlanEventStateChange;
	extern const int cGatherPlanKBResourceID;
	extern const int cGatherPlanResourceID;
	extern const int cGatherPlanResourceType;
	extern const int cGatherPlanResourceSubType;
	extern const int cGatherPlanBreakDownID;
	extern const int cGatherPlanResourceUnitTypeFilter;
	extern const int cGatherPlanFindNewResourceTimeOut;
	extern const int cBuildPlanBuildingPlacementID;
	extern const int cBuildPlanBuildingTypeID;
	extern const int cBuildPlanInfluenceUnitTypeID;
	extern const int cBuildPlanInfluenceUnitDistance;
	extern const int cBuildPlanInfluenceUnitValue;
	extern const int cBuildPlanInfluenceUnitFalloff;
	extern const int cBuildPlanAreaID;
	extern const int cBuildPlanCenterPosition;
	extern const int cBuildPlanCenterPositionDistance;
	extern const int cBuildPlanVPSiteID;
	extern const int cBuildPlanSocketID;
	extern const int cBuildPlanBuildUnitID;
	extern const int cBuildPlanFoundationID;
	extern const int cBuildPlanInfluencePosition;
	extern const int cBuildPlanInfluencePositionDistance;
	extern const int cBuildPlanInfluencePositionValue;
	extern const int cBuildPlanInfluencePositionFalloff;
	extern const int cBuildPlanDockPlacementPoint;
	extern const int cBuildPlanNumAreaBorderLayers;
	extern const int cBuildPlanBuildingBufferSpace;
	extern const int cBuildPlanFailOnUnaffordable;
	extern const int cBuildPlanInfluenceKBResourceID;
	extern const int cBuildPlanRandomBPValue;
	extern const int cBuildPlanInfluenceAtBuilderPosition;
	extern const int cBuildPlanInfluenceBuilderPositionValue;
	extern const int cBuildPlanInfluenceBuilderPositionDistance;
	extern const int cBuildPlanInfluenceBuilderPositionFalloff;
	extern const int cBuildPlanRetries;
	extern const int cBuildPlanMaxRetries;
	extern const int cBuildPlanPendingCommands;
	extern const int cBuildPlanFailureCause;
	extern const int cBuildPlanFailureCauseFloat;
	extern const int cBuildPlanMaxCanPaths;
	extern const int cBuildPlanCanPathStartIndex;
	extern const int cBuildPlanInfluenceVPSiteType;
	extern const int cBuildPlanInfluenceVPSiteTypeValue;
	extern const int cBuildPlanInfluenceVPSiteTypeDistance;
	extern const int cBuildPlanInfluenceVPSiteTypeFalloff;
	extern const int cTrainPlanBuildingID;
	extern const int cTrainPlanIntoArmyID;
	extern const int cTrainPlanIntoPlanID;
	extern const int cTrainPlanIntoBaseID;
	extern const int cTrainPlanNumberToTrain;
	extern const int cTrainPlanNumberToMaintain;
	extern const int cTrainPlanNumberTrained;
	extern const int cTrainPlanUnitType;
	extern const int cTrainPlanBuildFromType;
	extern const int cTrainPlanTrainedUnitID;
	extern const int cTrainPlanFrequency;
	extern const int cTrainPlanUseMultipleBuildings;
	extern const int cTrainPlanGatherPoint;
	extern const int cTrainPlanGatherTargetID;
	extern const int cTrainPlanMaintainBaseID;
	extern const int cTrainPlanMaintainAreaID;
	extern const int cTrainPlanBatchSize;
	extern const int cTrainPlanMaxQueueSize;
	extern const int cExplorePlanLOSMultiplier;
	extern const int cExplorePlanDoLoops;
	extern const int cExplorePlanDoneLoops;
	extern const int cExplorePlanNumberOfLoops;
	extern const int cExplorePlanPointsInLoop;
	extern const int cExplorePlanAvoidingAttackedAreas;
	extern const int cExplorePlanReExploreAreas;
	extern const int cExplorePlanLOSProtoUnitID;
	extern const int cExplorePlanBuildPosition;
	extern const int cExplorePlanBuilderUnitType;
	extern const int cExplorePlanCanBuildLOSProto;
	extern const int cExplorePlanHandleDamageTime;
	extern const int cExplorePlanHandleDamageFrequency;
	extern const int cExplorePlanQuitWhenPointIsVisible;
	extern const int cExplorePlanQuitWhenPointIsVisiblePt;
	extern const int cExplorePlanCurrentNuggetID;
	extern const int cExplorePlanNuggetsToGather;
	extern const int cExplorePlanOkToGatherNuggets;
	extern const int cResearchPlanBuildingID;
	extern const int cResearchPlanBuildingTypeID;
	extern const int cResearchPlanTechID;
	extern const int cResearchPlanBuildingAbstractTypeID;
	extern const int cAttackPlanPlayerID;
	extern const int cAttackPlanSpecificTargetID;
	extern const int cAttackPlanTargetTypeID;
	extern const int cAttackPlanQueryID;
	extern const int cAttackPlanAttackRouteID;
	extern const int cAttackPlanAttackRoutePattern;
	extern const int cAttackPlanGatherPoint;
	extern const int cAttackPlanGatherDistance;
	extern const int cAttackPlanTargetID;
	extern const int cAttackPlanMoveAttack;
	extern const int cAttackPlanNumberAttacks;
	extern const int cAttackPlanRefreshFrequency;
	extern const int cAttackPlanLastRefreshTime;
	extern const int cAttackPlanHandleDamageTime;
	extern const int cAttackPlanHandleDamageFrequency;
	extern const int cAttackPlanBaseAttackMode;
	extern const int cAttackPlanPathID;
	extern const int cAttackPlanFromGoalID;
	extern const int cAttackPlanRetreatMode;
	extern const int cAttackPlanTargetAreaGroups;
	extern const int cAttackPlanTeleportLocation;
	extern const int cAttackPlanAutoUseGPs;
	extern const int cAttackPlanPowerID;
	extern const int cAttackPlanGatherStartTime;
	extern const int cAttackPlanTargetResourceType;
	extern const int cAttackPlanAttackPoint;
	extern const int cAttackPlanAttackPointEngageRange;
	extern const int cAttackPlanAttackExplicitBaseID;
	extern const int cAttackPlanGatherWaitTime;
	extern const int cAttackPlanAttackRoutePatternLRU;
	extern const int cAttackPlanAttackRoutePatternMRU;
	extern const int cAttackPlanAttackRoutePatternRandom;
	extern const int cAttackPlanAttackRoutePatternBest;
	extern const int cAttackPlanBaseAttackModeNone;
	extern const int cAttackPlanBaseAttackModeWeakest;
	extern const int cAttackPlanBaseAttackModeStrongest;
	extern const int cAttackPlanBaseAttackModeLRU;
	extern const int cAttackPlanBaseAttackModeMRU;
	extern const int cAttackPlanBaseAttackModeRandom;
	extern const int cAttackPlanBaseAttackModeClosest;
	extern const int cAttackPlanBaseAttackModeFarthest;
	extern const int cAttackPlanBaseAttackModeExplicit;
	extern const int cAttackPlanRetreatModeNone;
	extern const int cAttackPlanRetreatModeOutnumbered;
	extern const int cAttackPlanRetreatModeWillLose;
	extern const int cProgressionPlanPollingTime;
	extern const int cProgressionPlanProgressionID;
	extern const int cProgressionPlanTrainUnitAtEnd;
	extern const int cProgressionPlanNumGoalUnitsToBuild;
	extern const int cProgressionPlanGoalUnitID;
	extern const int cProgressionPlanGoalTechID;
	extern const int cProgressionPlanBuildAreaID;
	extern const int cProgressionPlanCurrentGoalID;
	extern const int cProgressionPlanCurrentGoalType;
	extern const int cProgressionPlanCurrentStep;
	extern const int cProgressionPlanCurrentStepPlanID;
	extern const int cProgressionPlanPaused;
	extern const int cProgressionPlanAdvanceOneStep;
	extern const int cProgressionPlanRunInParallel;
	extern const int cProgressionPlanChildProgressions;
	extern const int cProgressionPlanBuildingPref;
	extern const int cHerdPlanBuildingID;
	extern const int cHerdPlanBuildingTypeID;
	extern const int cHerdPlanDistance;
	extern const int cFishPlanLandPoint;
	extern const int cFishPlanWaterPoint;
	extern const int cFishPlanLandGroupID;
	extern const int cFishPlanWaterGroupID;
	extern const int cFishPlanAutoTrainBoats;
	extern const int cFishPlanNumberInTraining;
	extern const int cFishPlanDockID;
	extern const int cFishPlanMaximumDockDist;
	extern const int cFishPlanPlaceRetries;
	extern const int cFishPlanMaxPlaceRetries;
	extern const int cFishPlanBuildDock;
	extern const int cTransportPlanTransportID;
	extern const int cTransportPlanTransportTypeID;
	extern const int cTransportPlanGatherPoint;
	extern const int cTransportPlanTargetPoint;
	extern const int cTransportPlanGatherAreaGroup;
	extern const int cTransportPlanTargetAreaGroup;
	extern const int cTransportPlanGatherArea;
	extern const int cTransportPlanTargetArea;
	extern const int cTransportPlanPathType;
	extern const int cTransportPlanPathPlanned;
	extern const int cTransportPlanReturnWhenDone;
	extern const int cTransportPlanMaximizeXportMovement;
	extern const int cTransportPlanUnitsMoved;
	extern const int cTransportPlanIgnoreAreaIDs;
	extern const int cTransportPlanBestDangerArea;
	extern const int cTransportPlanBestDangerValue;
	extern const int cTransportPlanDropOffPoint;
	extern const int cTransportPlanPersistent;
	extern const int cTransportPlanMiddleAreaGroups;
	extern const int cTransportPlanTakeMoreUnits;
	extern const int cTradePlanTargetUnitTypeID;
	extern const int cTradePlanTargetUnitID;
	extern const int cTradePlanStartPosition;
	extern const int cTradePlanTradeUnitType;
	extern const int cTradePlanTradeUnitTypeMax;
	extern const int cTradePlanMarketID;
	extern const int cTowerPlanCenterLocation;
	extern const int cTowerPlanAreaID;
	extern const int cTowerPlanDistanceFromCenter;
	extern const int cTowerPlanMaximizeLOS;
	extern const int cTowerPlanMaximizeAttack;
	extern const int cTowerPlanNumberToBuild;
	extern const int cTowerPlanBuildLocations;
	extern const int cTowerPlanProtoIDToBuild;
	extern const int cTowerPlanAttackLOSModifier;
	extern const int cTowerPlanLOSModifier;
	extern const int cAttackStrategyPlanPlayerID;
	extern const int cAttackStrategyPlanNumberTotalAttacks;
	extern const int cDefendPlanDefendTargetID;
	extern const int cDefendPlanDefendAreaID;
	extern const int cDefendPlanDefendBaseID;
	extern const int cDefendPlanDefendPoint;
	extern const int cDefendPlanEngageRange;
	extern const int cDefendPlanPatrol;
	extern const int cDefendPlanPatrolWaypoint;
	extern const int cDefendPlanCurrentWaypoint;
	extern const int cDefendPlanTargetID;
	extern const int cDefendPlanGatherDistance;
	extern const int cDefendPlanRefreshFrequency;
	extern const int cDefendPlanLastRefreshTime;
	extern const int cDefendPlanAttackTypeID;
	extern const int cDefendPlanGatherPercentage;
	extern const int cDefendPlanNoTargetTimeout;
	extern const int cDefendPlanNoTargetTimer;
	extern const int cDefendPlanStopTakingUnits;
	extern const int cDefendPlanStopTakingUnitTime;
	extern const int cNuggetPlanGatherDistance;
	extern const int cNuggetPlanGatherPercentage;
	extern const int cNuggetPlanMaxGuardianStrength;
	extern const int cNuggetPlanTargetNuggetID;
	extern const int cNuggetPlanTargetGatherPosition;
	extern const int cReservePlanPlanType;
	extern const int cGoalPlanGoalType;
	extern const int cGoalPlanGoalSubType;
	extern const int cGoalPlanMinTime;
	extern const int cGoalPlanMaxTime;
	extern const int cGoalPlanMinAge;
	extern const int cGoalPlanMaxAge;
	extern const int cGoalPlanRepeat;
	extern const int cGoalPlanExecuteCount;
	extern const int cGoalPlanDoneGoal;
	extern const int cGoalPlanFailGoal;
	extern const int cGoalPlanExecuteGoal;
	extern const int cGoalPlanAutoUpdateState;
	extern const int cGoalPlanAutoUpdateBase;
	extern const int cGoalPlanAutoUpdateAttackPlayerID;
	extern const int cGoalPlanTargetType;
	extern const int cGoalPlanTarget;
	extern const int cGoalPlanTargetPoint;
	extern const int cGoalPlanTargetNumber;
	extern const int cGoalPlanMinUnitNumber;
	extern const int cGoalPlanMaxUnitNumber;
	extern const int cGoalPlanUnitPickerID;
	extern const int cGoalPlanUnitPickerFrequency;
	extern const int cGoalPlanUnitPickerTime;
	extern const int cGoalPlanAttackPlayerID;
	extern const int cGoalPlanAttackStartFrequency;
	extern const int cGoalPlanAttackStartTime;
	extern const int cGoalPlanUnitTypeID;
	extern const int cGoalPlanBaseID;
	extern const int cGoalPlanAllowRetreat;
	extern const int cGoalPlanUpgradeBuilding;
	extern const int cGoalPlanSetAreaGroups;
	extern const int cGoalPlanIdleAttack;
	extern const int cGoalPlanAreaGroupID;
	extern const int cGoalPlanFunctionID;
	extern const int cGoalPlanFunctionParm;
	extern const int cGoalPlanBuildingTypeID;
	extern const int cGoalPlanBuildingPlacementID;
	extern const int cGoalPlanBuildingSearchID;
	extern const int cGoalPlanActiveHealthTypeID;
	extern const int cGoalPlanActiveHealth;
	extern const int cGoalPlanAttackRoutePatternType;
	extern const int cGoalPlanUpgradeFilterType;
	extern const int cGoalPlanReservePlanID;
	extern const int cGoalPlanFindBestOpp;
	extern const int cGoalPlanMinOppScoreForGo;
	extern const int cGoalPlanGoalTypeForwardBase;
	extern const int cGoalPlanGoalTypeCreateBase;
	extern const int cGoalPlanGoalTypeMainBase;
	extern const int cGoalPlanGoalTypeAttack;
	extern const int cGoalPlanGoalTypeDefend;
	extern const int cGoalPlanGoalTypeTrain;
	extern const int cGoalPlanGoalTypeMaintain;
	extern const int cGoalPlanGoalTypeResearch;
	extern const int cGoalPlanGoalTypeAge;
	extern const int cGoalPlanGoalTypeCallback;
	extern const int cGoalPlanGoalTypeBuilding;
	extern const int cGoalPlanGoalSubTypeEmpty1;
	extern const int cGoalPlanGoalSubTypeEmpty2;
	extern const int cGoalPlanTargetTypeArea;
	extern const int cGoalPlanTargetTypeAreaGroup;
	extern const int cGoalPlanTargetTypePoint;
	extern const int cGoalPlanTargetTypeUnitType;
	extern const int cGoalPlanTargetTypeUnit;
	extern const int cGoalPlanTargetTypePlayer;
	extern const int cGoalPlanTargetTypePlayerRelation;
	extern const int cGoalPlanTargetTypeTech;
	extern const int cGatherGoalPlanScriptRPGPct;
	extern const int cGatherGoalPlanCostRPGPct;
	extern const int cGatherGoalPlanGathererPct;
	extern const int cGatherGoalPlanNumFoodPlans;
	extern const int cGatherGoalPlanNumWoodPlans;
	extern const int cGatherGoalPlanNumGoldPlans;
	extern const int cGatherGoalPlanMinResourceAmt;
	extern const int cGatherGoalPlanResourceCostWeight;
	extern const int cGatherGoalPlanFarmLimitPerPlan;
	extern const int cGatherGoalPlanMaxFarmLimit;
	extern const int cGatherGoalPlanResourceSkew;
	extern const int cBuildWallPlanWallType;
	extern const int cBuildWallPlanWallStart;
	extern const int cBuildWallPlanWallEnd;
	extern const int cBuildWallPlanWallRingCenterPoint;
	extern const int cBuildWallPlanWallRingRadius;
	extern const int cBuildWallPlanNumberOfGates;
	extern const int cBuildWallPlanAreaIDs;
	extern const int cBuildWallPlanFoundationID;
	extern const int cBuildWallPlanGateIndices;
	extern const int cBuildWallPlanGateProtoIDs;
	extern const int cBuildWallPlanEdgeOfMapBuffer;
	extern const int cBuildWallPlanPieces;
	extern const int cBuildWallPlanPiecePositions;
	extern const int cBuildWallPlanPieceRotations;
	extern const int cBuildWallPlanEnRoute;
	extern const int cBuildWallPlanWallTypeStraight;
	extern const int cBuildWallPlanWallTypeRing;
	extern const int cBuildWallPlanWallTypeArea;
	extern const int cMissionPlanPlanID;
	extern const int cMissionPlanType;
	extern const int cMissionPlanStartTime;
	extern const int cMissionPlanTarget;
	extern const int cMissionPlanVector1;
	extern const int cMissionPlanVector2;
	extern const int cMissionPlanFloat1;
	extern const int cMissionPlanFloat2;
	extern const int cMissionPlanOpportunityID;
	extern const int cTransportPathTypePoints;
	extern const int cTransportPathTypeAreas;
	extern const int cNativeResearchPlanBuildingID;
	extern const int cNativeResearchPlanTacticID;
	extern const int cResignGatherers;
	extern const int cResignTeammates;
	extern const int cResignMilitaryPop;
	extern const int cMovementTypeNone;
	extern const int cMovementTypeLand;
	extern const int cMovementTypeWater;
	extern const int cMovementTypeAir;
	extern const int cMovementTypeNonSolid;
	extern const int cUnitStateNone;
	extern const int cUnitStateBuilding;
	extern const int cUnitStateAlive;
	extern const int cUnitStateDead;
	extern const int cUnitStateQueued;
	extern const int cUnitStateAny;
	extern const int cUnitStateABQ;
	extern const int cBuildingPlacementEventDone;
	extern const int cBuildingPlacementEventFailed;
	extern const int cUnitQueryNoArmy;
	extern const int cUnitQueryInvalidArmy;
	extern const int cBuildingPlacementPreferenceNone;
	extern const int cBuildingPlacementPreferenceBack;
	extern const int cBuildingPlacementPreferenceFront;
	extern const int cBuildingPlacementPreferenceLeft;
	extern const int cBPIFalloffLinear;
	extern const int cBPIFalloffNone;
	extern const int cBPIFalloffLinearInverse;
	extern const int cResourceGold;
	extern const int cResourceWood;
	extern const int cResourceFood;
	extern const int cResourceFame;
	extern const int cResourceSkillPoints;
	extern const int cResourceXP;
	extern const int cResourceShips;
	extern const int cResourceTrade;
	extern const int cAllResources;
	extern const int cTechStatusUnobtainable;
	extern const int cTechStatusObtainable;
	extern const int cTechStatusActive;
	extern const int cAttackRouteFrontRight;
	extern const int cAttackRouteRightFront;
	extern const int cAttackRouteRightBack;
	extern const int cAttackRouteBackRight;
	extern const int cAttackRouteBackLeft;
	extern const int cAttackRouteLeftBack;
	extern const int cAttackRouteLeftFront;
	extern const int cAttackRouteFrontLeft;
	extern const int cAreaTypeForest;
	extern const int cAreaTypeWater;
	extern const int cAreaTypeImpassableLand;
	extern const int cAreaTypeVPSite;
	extern const int cAreaGroupTypeLand;
	extern const int cAreaGroupTypeWater;
	extern const int cAreaGroupTypeImpassableLand;
	extern const int cXSAgeHandler;
	extern const int cXSPowerHandler;
	extern const int cXSRetreatHandler;
	extern const int cXSResignHandler;
	extern const int cXSBuildHandler;
	extern const int cXSHomeCityTransportArriveHandler;
	extern const int cXSHomeCityTransportReturnHandler;
	extern const int cXSHomeCityLevelUpHandler;
	extern const int cXSTreatyBrokenHandler;
	extern const int cXSShipResourceGranted;
	extern const int cXSAutoCreatePlanHandler;
	extern const int cXSNuggetHandler;
	extern const int cXSPlayerAgeHandler;
	extern const int cXSScoreOppHandler;
	extern const int cXSMissionStartHandler;
	extern const int cXSMissionEndHandler;
	extern const int cXSGameOverHandler;
	extern const int cXSMonopolyStartHandler;
	extern const int cXSMonopolyEndHandler;
	extern const int cXSWonderVictoryStartHandler;
	extern const int cXSWonderVictoryEndHandler;
	extern const int cXSRelicVictoryStartHandler;
	extern const int cXSRelicVictoryEndHandler;
	extern const int cXSKOTHVictoryStartHandler;
	extern const int cXSKOTHVictoryEndHandler;
	extern const int cPlayerChatVerbInvalid;
	extern const int cPlayerChatVerbAttack;
	extern const int cPlayerChatVerbDefend;
	extern const int cPlayerChatVerbTribute;
	extern const int cPlayerChatVerbFeed;
	extern const int cPlayerChatVerbCancel;
	extern const int cPlayerChatVerbClaim;
	extern const int cPlayerChatVerbTrain;
	extern const int cPlayerChatVerbStrategy;
	extern const int cPlayerChatTargetTypeInvalid;
	extern const int cPlayerChatTargetTypePlayers;
	extern const int cPlayerChatTargetTypeUnits;
	extern const int cPlayerChatTargetTypeUnitTypes;
	extern const int cPlayerChatTargetTypeResource;
	extern const int cPlayerChatTargetTypeLocation;
	extern const int cPlayerChatTargetStrategyInvalid;
	extern const int cPlayerChatTargetStrategyRush;
	extern const int cPlayerChatTargetStrategyBoom;
	extern const int cPlayerChatTargetStrategyTurtle;
	extern const int cPlayerChatResponseTypeYes;
	extern const int cPlayerChatResponseTypeNo;
	extern const int cVPInvalid;
	extern const int cVPAll;
	extern const int cVPNative;
	extern const int cVPSecret;
	extern const int cVPTrade;
	extern const int cVPConqueror;
	extern const int cVPGranted;
	extern const int cVPStateAny;
	extern const int cVPStateNone;
	extern const int cVPStateSite;
	extern const int cVPStateBuilding;
	extern const int cVPStateCompleted;
	extern const int cGameTypeScenario;
	extern const int cGameTypeSaved;
	extern const int cGameTypeRandom;
	extern const int cGameTypeCampaign;

	template<typename T>
	struct SyscallArray {
		T* Array;
		int Count;
	};

	struct SyscallCiv {
		int Reserved;
		char* Name;
	};

	inline int GetNumberPlayers() {
		return *(int*)(*(int*)(*(int*)0xc66234 + 0x13c) + 0x5c);
	}

	inline SyscallArray<SyscallCiv*>* GetCivs() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (SyscallArray<SyscallCiv*>*)(_this + 0x24);
	}

	inline SyscallArray<wchar_t*>* GetTechs() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (SyscallArray<wchar_t*>*)(_this + 0x3824);
	}

	inline SyscallArray<wchar_t*>* GetUnitTypes() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (SyscallArray<wchar_t*>*)(_this + 0x190);
	}

	inline SyscallArray<wchar_t*>* GetTactics() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (SyscallArray<wchar_t*>*)(_this + 0x1ff0);
	}
}