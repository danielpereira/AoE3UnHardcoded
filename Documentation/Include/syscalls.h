#pragma once

namespace syscalls
{
	typedef const char* string;

	class _vector
	{
	public:
		float x, y, z;

		_vector() {}
		_vector(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

		inline _vector operator+(const _vector& other) {
			_vector result;
			result.x = x + other.x;
			result.y = y + other.y;
			result.z = z + other.z;
			return result;
		}

		inline _vector operator-(const _vector& other) {
			_vector result;
			result.x = x - other.x;
			result.y = y - other.y;
			result.z = z - other.z;
			return result;
		}

		inline _vector& operator+=(const _vector& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		inline _vector& operator-=(const _vector& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		inline bool operator==(const _vector& other) const {
			return x == other.x && y == other.y && z == other.z;
		}
	};

	typedef _vector* vector;

	extern _vector* const cInvalidVector;
	extern _vector* const cOriginVector;

#ifdef UHC_SYSCALL_POINTERS
	// maps input event to command, in that context.  See input mapper design.doc for more details.
	extern void(*const map)(string eventString, string contextString, string commandString);

	// sends a message to the console output
	extern void(*const echo)(string stringMessage);

	// sets the game status text from a string in the string resource.
	extern void(*const echoLocalized)(int stringID);

	// sends a number to the console output
	extern void(*const echoNum)(int stringMessage);

	// enables or disables IME
	extern void(*const IMEEnable)(bool enable);

	// toggles the state of the console dialog
	extern void(*const console)();

	// with no arg, toggles pause state on/off.  otherwise, sets pause state
	extern void(*const pause)(int integerState, bool checkForAllowPause);

	// with no arg, toggles pause state on/off.  otherwise, sets pause state
	extern void(*const pause2)(int integerState);

	// forces the game to unpause
	extern void(*const unpauseNoChecks)();

	// exits the game
	extern void(*const exit)(bool a);

	// take a screen shot
	extern void(*const screenshot)();

	// take a screen shot
	extern void(*const hackscreenshot)(int a);

	// changes screen resolution.
	extern void(*const res)(int integerXRes, int integerYRes);

	// changes screen resolution and bit depth.
	extern void(*const resbpp)(int integerXRes, int integerYRes, int integerBPP);

	// undoes the last editing operation.
	extern void(*const undo)();

	// Re-does the last undone operation.
	extern void(*const redo)();

	// realigns all resources in the world to tile boundaries
	extern void(*const alignResources)();

	// realigns all selected units to tile boundaries
	extern void(*const alignSelectedUnits)();

	// Sends out a market use command for the given player, resource and amount.  Negative means selling.
	extern void(*const resourceMarket)(int intPlayerID, string stringResourceTo, float floatAmount, string stringResourceFrom);

	// spews database values on the specified unit or the selected unit (if no argument).
	extern void(*const unitData)(int intUnitID);

	// Sets the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	extern void(*const unitSetVariation)(int Variation, int UnitID);

	// Increments the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	extern void(*const unitIncVariation)(int UnitID);

	// Decrements the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	extern void(*const unitDecVariation)(int a);

	// Sets the unit stance for all selected units to aggressive.
	extern void(*const unitSetStanceAggressive)();

	// Sets the unit stance for all selected units to defensive.
	extern void(*const unitSetStanceDefensive)();

	// Sets the unit stance for all selected units to passive.
	extern void(*const unitSetStancePassive)();

	// Sets the tactic for this unit.
	extern void(*const unitSetTactic)(string a);

	// Toggles stealth mode for this unit.
	extern void(*const unitToggleStealth)();

	// Sets the mode for a squad.
	extern void(*const squadMode)(int a, int b);

	// Sets the mode for a squad.
	extern void(*const setSquadMode)(string a);

	// Wheels the squad.
	extern void(*const squadWheel)(float angle, int squadID);

	// Issues a town bell for the selected unit(s).
	extern void(*const unitTownBell)();

	// Issues a return to work for the selected unit(s).
	extern void(*const unitReturnToWork)();

	// Toggles between different ways obscured units are shown.
	extern void(*const obscuredUnitToggle)();

	// sends to output a list of all current config vars
	extern void(*const configDump)(string a);

	// sets a particular config var to a string value
	extern void(*const configSet)(string stringName, string stringValue);

	// sets a config var to an integer value
	extern void(*const configSetInt)(string stringName, int integerValue);

	// sets a config var to a floating point value
	extern void(*const configSetFloat)(string stringName, float floatValue);

	// defines a config variable
	extern void(*const configDef)(string stringName);

	// un-defines a config variable
	extern void(*const configUndef)(string stringName);

	// defined var becomes undefined, and vice versa
	extern void(*const configToggle)(string stringName);

	// changes config state just like a .cfg line
	extern void(*const config)(string stringToken);

	// look up config by enum ID
	extern void(*const configGetByID)(int intValue);

	// show all formally defined config variables that contain the filter string, or use no parameters for a full list.
	extern void(*const configHelp)(string symbolFilter);

	// show all formally defined config variables that start with the filter string, or use no parameters for a full list.
	extern void(*const configHelpPrefix)(string symbolFilter);

	// saves out a game in progress.
	extern void(*const saveGame)(string stringFilename);

	// saves out a scenario file.
	extern void(*const saveScenario)(string stringFilename);

	// loads in a saved game.
	extern void(*const loadGame)(string stringFilename);

	// loads in a scenario file.
	extern void(*const loadScenario)(string stringFilename);

	// loads in a tutorial scenario file.
	extern void(*const loadTutorial)(string stringFilename, int loadMode, string loadImage, int textID, bool isAge3Scenario);

	// loads in a campaign scenario file.
	extern void(*const loadCampaignScenario)(string stringFilename);

	// loads the file named, interpreting whether it is a scenario, savegame, etc. dynamically
	extern void(*const loadRecentFile)(string stringFilename);

	// save camera to file.
	extern void(*const saveCamera)(string stringFilename);

	// save camera to file.
	extern void(*const saveCurrentHomeCityCamera)();

	// save widescreen camera to file.
	extern void(*const saveCurrentHomeCityWidescreenCamera)();

	// load camera from file.
	extern void(*const loadCamera)(string stringFilename);

	// re-launch current scenario.
	extern void(*const restart)();

	// filters the entire terrain.
	extern void(*const terrainFilter)();

	// filters a sub-area of the terrain.
	extern void(*const terrainFilterArea)(int integerX1, int integerY1, int integerX2, int integerY2);

	// flattens the entire terrain.
	extern void(*const terrainFlatten)(float a);

	// flattens a sub-area of the terrain.
	extern void(*const terrainFlattenArea)(int integerX1, int integerY1, int integerX2, int integerY2);

	// sets the terrain type to paint.
	extern void(*const terrainSetType)(int integerType);

	// sets the terrain subtype to paint.
	extern void(*const terrainSetSubtype)(int integerType);

	// sets the terrain mix to paint.
	extern void(*const terrainSetMix)(int integerType);

	// paint whole terrain with given texture.
	extern void(*const terrainPaint)(string a);

	// paint whole terrain with given mix.
	extern void(*const terrainPaintMix)(string a);

	// Set terrain ambient reflectivity to the given RGB (0-255)
	extern void(*const terrainAmbient)(int integerR, int integerG, int integerB);

	// adjusts (raise/lower) the terrain height by the specified meters.
	extern void(*const terrainAdjustGlobalHeight)(float meters);

	// sets whether camera limiting is on.
	extern void(*const cameraRotate)(int integerState);

	// puts the camera in a reasonable orientation.
	extern void(*const cameraNice)();

	// intended for ui use only.  Indicates that camera forward key has gone up or down.
	extern void(*const cameraForward)(int integerKeyState);

	// intended for ui use only.  Indicates that camera world forward key has gone up or down.
	extern void(*const cameraWorldForward)(int integerKeyState);

	// intended for ui use only.  Indicates that camera world forward & left key has gone up or down.
	extern void(*const cameraWorldForwardLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that camera world forward & right key has gone up or down.
	extern void(*const cameraWorldForwardRight)(int integerKeyState);

	// intended for ui use only.  Indicates that camera backward key has gone up or down.
	extern void(*const cameraBackward)(int integerKeyState);

	// intended for ui use only.  Indicates that camera world backward key has gone up or down.
	extern void(*const cameraWorldBackward)(int integerKeyState);

	// intended for ui use only.  Indicates that camera world backward & left key has gone up or down.
	extern void(*const cameraWorldBackwardLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that camera world backward & right key has gone up or down.
	extern void(*const cameraWorldBackwardRight)(int integerKeyState);

	// intended for ui use only.  Indicates that camera right key has gone up or down.
	extern void(*const cameraRight)(int integerKeyState);

	// intended for ui use only.  Indicates that camera left key has gone up or down.
	extern void(*const cameraLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that camera up key has gone up or down.
	extern void(*const cameraUp)(int integerKeyState);

	// intended for ui use only.  Indicates that camera down key has gone up or down.
	extern void(*const cameraDown)(int integerKeyState);

	// intended for ui use only.  Indicates that camera pitch forward key has gone up or down.
	extern void(*const cameraPitchForward)(int integerKeyState);

	// intended for ui use only.  Indicates that camera pitch backward key has gone up or down.
	extern void(*const cameraPitchBackward)(int integerKeyState);

	// intended for ui use only.  Indicates that camera roll left key has gone up or down.
	extern void(*const cameraRollLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that camera roll right key has gone up or down.
	extern void(*const cameraRollRight)(int integerKeyState);

	// intended for ui use only.  Indicates that camera yaw right key has gone up or down.
	extern void(*const cameraYawRight)(int integerKeyState);

	// intended for ui use only.  Indicates that camera yaw left key has gone up or down.
	extern void(*const cameraYawLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that camera 'Local Yaw right' key has gone up or down.
	extern void(*const cameraLocalYawRight)(int integerKeyState);

	// intended for ui use only.  Indicates that camera 'Local Yaw left' key has gone up or down.
	extern void(*const cameraLocalYawLeft)(int integerKeyState);

	// debug command to spew info about the current state of the game camera
	extern void(*const cameraDump)();

	// loads a camera track and makes it current
	extern void(*const trackLoad)(string stringFilename);

	// saves the current camera track
	extern void(*const trackSave)(string stringFilename);

	// clears all tracks.
	extern void(*const trackClear)();

	// steps the current camera track 1 step forward.
	extern void(*const trackStepForward)();

	// steps the current camera track 1 step backward.
	extern void(*const trackStepBackward)();

	// toggles rendering of the camera track on and off.
	extern void(*const trackToggleShow)();

	// adds the camera's current position and orientation to the current camera track.
	extern void(*const trackAddWaypoint)();

	// edits the currently selected camera track.
	extern void(*const trackEditWaypoint)();

	// sets the current waypoint to the button with the same index.
	extern void(*const trackSetSelectedWaypoint)(int index);

	// moves the camera to the current waypoint.
	extern void(*const trackGotoSelectedWaypoint)(int index);

	// removes the most recently added track waypoint from the current camera track.
	extern void(*const trackRemoveWaypoint)();

	// adds a new camera track.
	extern void(*const trackInsert)();

	// removes selected track.
	extern void(*const trackRemove)();

	// plays a track file (otherwise if "none" than plays the current track.) with no arg uses current duration, otherwise sets duration
	extern void(*const trackPlay)(float duration, int eventID);

	// pauses the current camera track.
	extern void(*const trackPause)();

	// stops the current camera track.
	extern void(*const trackStop)();

	// advances the camera track to a specific location.
	extern void(*const trackAdvance)(float a);

	// moves the camera to the current event.
	extern void(*const trackGotoSelectedEvent)(int index);

	// increments the area to render.
	extern void(*const areaIncrementAreaToRender)(int playerID);

	// toggle shadows on/off
	extern void(*const toggleShadows)();

	// set the quality level of shadows
	extern void(*const setShadowQuality)(int qualityLevel);

	// set the shadow buffer bias multipler (supaScreenshot only)
	extern void(*const setShadowBiasMul)(float biasMultiplier);

	// controls shadow matrix snapping
	extern void(*const setShadowSnapping)(int a);

	// controls shadow projection rotation optimization
	extern void(*const setShadowRotationOp)(int a);

	// with no arg, toggles window/fullscreen.  otherwise, sets mode to window(1)/fullscreen(0)
	extern void(*const renderWindow)(int integerState);

	// sets the render state of the given base (no integerState toggles).
	extern void(*const renderBaseID)(int playerID, int areaID, int integerState);

	// sets the render state for all areas (no arg toggles).
	extern void(*const renderAreas)(int playerID, int integerState);

	// draws areas and color-codes them by danger level.
	extern void(*const renderAreaDangerLevels)(int playerID, int state);

	// sets the render state of the given area (no integerState toggles).
	extern void(*const renderAreaID)(int playerID, int areaID, int integerState);

	// sets the render state of the given area (no integerState toggles).
	extern void(*const renderAreaGroupID)(int playerID, int areaGroupID, int integerState);

	// sets desired anisotropy
	extern void(*const renderAnisotropic)(int integerState);

	// sets HDR multisample factor [1,8] - 1 is disabled
	extern void(*const setHDRMultisampleFactor)(int a);

	// sets HDR supersampling factors (1.0 to 2.0, both 1.0 is off)
	extern void(*const setSuperSampleFactors)(float floatX, float floatY);

	// sets supersample kernel scales(1.0 = normal, less = blurrier, higher = sharper)
	extern void(*const setSuperSampleFilterScales)(float floatX, float floatY);

	// sets supersample filter kernel
	extern void(*const setSuperSampleFilterIndex)(int a);

	// sets trilinear filtering on/off
	extern void(*const renderTrilinear)(int integerState);

	// with no arg, toggles friend or foe colors.  otherwise, sets it
	extern void(*const renderFriendOrFoe)(int integerState);

	// Set ambient color to given RGB (0-255)
	extern void(*const ambientColor)(int integerR, int integerG, int integerB);

	// Get ambient color
	extern void(*const ambientGetColor)();

	// reset the sun color to full
	extern void(*const resetAmbientColor)();

	// Set ambient color 2 to given RGB (0-255)
	extern void(*const ambientColor2)(int integerR, int integerG, int integerB);

	// Set shadow darkness (0-255) - (PCF Filter Sclar 0-16)
	extern void(*const shadowDarkness)(float integerDarkness, float pcfFilterScalar, float biasNV, float biasATI, float slope);

	// Set sun color to given RGB (0-255)
	extern void(*const sunColor)(int integerR, int integerG, int integerB);

	// Get sun color
	extern void(*const sunGetColor)();

	// reset the sun color to full
	extern void(*const resetSunColor)();

	// Set fake sun params for water
	extern void(*const fakeSunParams)(float intensity, float specIntensity, float specPower, float inclination, float rotation);

	// sets a hemilight
	extern void(*const setHemiLight)(float topColorR, float topColorG, float topColorB, float bottomColorR, float bottomColorG, float bottomColorB, float axisYaw, float axisPitch, float intensity, float unitIntensity, float terrainIntensity);

	// sets scene light params
	extern void(*const setSceneLightParams)(float sunIntensity, float power, float specIntensity, float metalness, float fogColorR, float fogColorG, float fogColorB, float fogDensity, float fogStart);

	// set Planar Height Params
	extern void(*const setFogParams)(float planarfogColorR, float planarfogColorG, float planarfogColorB, float planarfogDensity, float planarfogHeight);

	// sets scene bump scale
	extern void(*const setBumpScale)(float scale);

	// sets the selected units to use the fake player indicated.
	extern void(*const unitPlayerFakify)(int fakePlayerIndex);

	// sets the selected units to stop using a fake player.
	extern void(*const unitPlayerDefakify)();

	// sets tonemap params
	extern void(*const setToneMapParams)(float exposure, float dispGamma, float greyFStops, float kneeLow, float kneeHigh, float ditherNoiseInten);

	// sets tonemap params
	extern void(*const setBloomParams)(float bloomThreshold, float bloomColorR, float bloomColorG, float bloomColorB, float bloomIntensity, float bloomPass, float bloomSigma);

	// sets LDR Bloom params
	extern void(*const setLDRBloomParams)(float bloomColorR, float bloomColorG, float bloomColorB, float bloomIntensity, float bloomSigma);

	// sets bloom streak params
	extern void(*const setBloomStreakParams)(float streakCount, float Passes, float ElementOffset, float Exposure, float Intensity, float Falloff, float streakRed, float streakGreen, float streakBlue, float threshold);

	// sets bloom feedback params
	extern void(*const setBloomFeedbackParams)(float currentFrameContribution, float lastFrameContribution);

	// sets Terrain Lighting Params
	extern void(*const setTerrainLightingParams)(float bumpScale, float specularPower, float specularIntensity, float terrainMetalness);

	// Applies a Lighting set
	extern void(*const applyLightingSet)(string name);

	// Saves the current status of lighting values as a set
	extern void(*const saveLightingSet)(string name);

	// loads the specified lighting set
	extern void(*const loadLightingSet)(string name, bool apply);

	// sets the circular brush size
	extern void(*const brushCircularSize)(float floatValue);

	// stop playing music
	extern void(*const musicStop)();

	// set the current music volume (0.0 - 1.0)
	extern void(*const musicSetVolume)(float volume);

	// play a sound as if it were a music track
	extern void(*const musicPlaySong)(string songname, float fadetime);

	// toggles between battle mode and normal mode
	extern void(*const musicToggleBattleMode)();

	// with no arg, cycles through the various status display modes.  otherwise sets display type
	extern void(*const displayType)(int integerState);

	// with no arg, outputs current player.  otherwise, sets current player to given argument
	extern void(*const player)(int integerPlayer);

	// toggles or sets LOS fog.
	extern void(*const fog)(int integerState);

	// toggles or sets unexplored black map rendering.
	extern void(*const blackmap)(int integerState);

	// enters the named mode.
	extern void(*const modeEnter)(string stringMode);

	// starts the given campaign.
	extern void(*const startCampaign)(string campaignName);

	// Wrapper that enters GameMenu mode if the player isn't resigned.
	extern void(*const uiEnterGameMenuModeIfNotResigned)();

	// toggles between the two modes only if we're not in a BMultiplayer game.
	extern void(*const modeToggleBetweenIfNotMP)(string stringMode1, string stringMode2);

	// Lists all of the commands that start with the given prefix
	extern void(*const helpPrefix)(string commandPrefix);

	// Lists all of the commands that contain the given substring
	extern void(*const help)(string commandSubstring);

	// Lists all of the commands that contain the given substring in their help text.
	extern void(*const helpText)(string helptextSubstring);

	// looks at given x,z location on terrain.
	extern void(*const lookAt)(float x, float z);

	// looks at given kb army.
	extern void(*const lookAtArmy)(int playerID, string armyName);

	// reloads the player colors from the XML file
	extern void(*const resetDefaultPlayerColors)();

	// sets the minimap filter for units
	extern void(*const setMinimapUnitFilter)(int a);

	// Sets the graphic detail.  (0 = HIGH, 1 = MEDIUM, 2 = LOW)
	extern void(*const setGraphicDetail)(int detailLevel);

	// Sets the world difficulty level.
	extern void(*const setWorldDifficulty)(int v);

	// Start the auto patcher.
	extern void(*const startAutoPatcher)(bool manualMode);

	// Cancel the auto patcher.
	extern void(*const cancelAutoPatcher)();

	// Used to tell autpatcher user pressed OK on exit or error dialog.
	extern void(*const confirmAutoPatcher)();

	// Plays movies from a playlist in the AVI directory
	extern void(*const playMovie)(string a);

	// Toggles home city view for the current player.
	extern void(*const toggleHomeCityView)();

	// Toggles tech home city view for the current player.
	extern void(*const toggleHomeCityViewTech)();

	// View the specific home city building.
	extern void(*const lookAtHomeCityBuilding)(int building);

	// Trains the given PUID from the given home city building.
	extern void(*const homeCityTrain)(int playerID, int buildingID, int puid);

	// Sends the given HC card in the home city.
	extern void(*const homeCityTrain2)(int playerID, int cardIndex);

	// Transports units from the home city.
	extern void(*const homeCityTransport)(int playerID);

	// starts the four of a kind victory if valid.
	extern void(*const fourOfAKind)();

	// starts the Relic Capture victory if valid.
	extern void(*const relicCapture)();

	// starts the King of the Hill victory if valid.
	extern void(*const kothVictory)();

	// Adds the given command to the trade post bucket.
	extern void(*const tradeRouteCommand)(int playerID, int tradeRoutUnit, int commandID);

	// Trains the given PUID from the given trade post on the trade route.
	extern void(*const tradeRouteTrain)(int playerID, int tradeRoutUnit, int puid);

	// Researches the given command from the given unit.
	extern void(*const commandResearch)(int commandID, int unitID, int a, int b);

	// Trains the given merc from the given home city building.
	extern void(*const mercTrain)(int playerID, int buildingID, int puid);

	// Cancels the given unit out of the ship.
	extern void(*const homeCityShipEject)(int playerID, int buildingID, int puid, int index);

	// Loads a grouping.  No parameter pops up dialog.
	extern void(*const loadGrouping)(string groupingName);

	// Loads a grouping from the user writable grouping directory.
	extern void(*const loadUserDefinedGrouping)(string groupingName);

	// For UI use only.
	extern void(*const loadGroupingUnicode)(string a);

	// For UI use only.
	extern void(*const loadGroupingUnicodeLUA)(int a, string b);

	// Starts the auto repair on the specified unit.
	extern void(*const repairUnit)(int unitID);

	// Cancels the auto repair on the specified unit.
	extern void(*const cancelRepairUnit)(int unitID);

	// Sets the home city gather point to the specified unit.
	extern void(*const setHomeCityGatherUnit)(int unitID);

	// Convert a covered wagon into a Town Center
	extern void(*const convertCoveredWagon)();

	// break your treaties
	extern void(*const breakTreaty)();

	// ransoms your explorer
	extern void(*const ransomExplorer)();

	// Toggles whether or not world tooltips are using the restricted screen rectangle.
	extern void(*const toggleWorldTooltipClipRect)();

	// Toggles whether or not to draw the world tooltip restricted screen rectangle.
	extern void(*const drawWorldTooltipClipRect)();

	// Sets the world tooltip restricted screen rectangle to the given dimensions relative to 1024x768 resolution.
	extern void(*const setWorldTooltipRectDims1024)(int minX, int minY, int maxX, int maxY);

	// UI use - upgrade the trade route associated with this unit.
	extern void(*const upgradeTradeRoute)(int unitID);

	// Spawn Units from the UnitID building.
	extern void(*const spawnUnits)(string protoname, int count, int unitID);

	// Explorer Abilities use.
	extern void(*const ability)(int abilityId, int unitID, bool doWhenNotSelected);

	// use ability in proto unit type if the player has one
	extern void(*const doAbilityInType)(string protoPowerName, string a);

	// use ability in current unit selection.
	extern void(*const doAbilityInSelected)(string protoPowerName);

	// use command in current unit selection.
	extern void(*const doCommandInSelected)(string a);

	// Special power use.
	extern void(*const specialPower)(int playerID, int powerEntryIndex, int powerID);

	// Set vertical syncing (-1 toggles, 0 is off, 1 is on).
	extern void(*const vsync)(int state);

	// Start fullscreen playback of a movie.
	extern void(*const startMoviePlayback)(string filename, int sizing, float fadeIn, float fadeOut);

	// Trains a reinforcement.
	extern void(*const trainReinforcement)(int armyID);

	// Cancel training of a reinforcement.
	extern void(*const cancelTrainReinforcement)(int armyID);

	// Set mip levels to skip for default category textures.
	extern void(*const setDropDefaultMips)(int num);

	// Set mip levels to skip for terrain category textures.
	extern void(*const setDropTerrainMips)(int num);

	// Display's the SPC Note Dialog with the specified title and text.
	extern void(*const showSPCNote)(string title, string text);

	// forces the renderer to reset.
	extern void(*const renderForceReset)();

	// Editor only function that activates/deactivates a given tech
	extern void(*const editorSetTechStatus)(string techToActivate, bool active);

	// Editor only functions. goes thru all the units and updates thier visuals.
	extern void(*const editorUpdateUnitVisuals)();

	// Editor use - sets all trade route definitons to the spedified definition.
	extern void(*const editorSetAllTradeRoutesToDef)(string newDefName);

	// Start the research of TechID from ResearchingUnitID for the current player (if no player is specified)
	extern void(*const researchByID)(int TechID, int ResearchingUnitID, int Player, bool a);

	// research a tech in current unit selection.
	extern void(*const researchTechInSelected)(string techName);

	// Start the training of a unit of ProtoUnitID from TrainingUnitID for the current player (if no player is specified)
	extern void(*const trainByID)(int ProtoUnitID, int TrainingUnitID, int Player);

	// tries to train the selected unit type in any valid selected unit
	extern void(*const trainInSelected)(string stringProtoName, int traincount);

	// cancel training of a unit type in any valid selected unit
	extern void(*const cancelTrainInSelected)(int ProtoUnitID, bool All);

	// cancel researching of a tech in any valid selected unit
	extern void(*const cancelResearchInSelected)(int TechID);

	// just like train in selected, but fastAr because it takes a protoID
	extern void(*const trainInSelectedByID)(int protoID, int traincount);

	// plays the default UI click sound.
	extern void(*const click)();

	// Researches the given home city tech.
	extern void(*const homeCityResearch)(int playerID, string techName);

	// Researches the given home city tech.
	extern void(*const homeCityResearchByID)(int playerID, int techName);

	// Activates the given home city tech.
	extern void(*const homeCityMakeActiveByID)(int playerID, int techName);

	// Researches the given home city tech when a game is not active.
	extern void(*const homeCityResearchByIDOutsideGame)(int playerID, int techName);

	// Researches the given home city tech when you are *really* completely out side of the game.
	extern void(*const homeCityResearchByIDPregame)(int techID);

	// changes the edit mode
	extern void(*const editMode)(string symbolModeName);

	// instructs the currently selected unit(s) to build the current proto unit cursor building type at the pointer location.
	extern void(*const uiBuildAtPointer)();

	// Sets the orientation of a formation.
	extern void(*const uiFormationOrientation)();

	// instructs the currently selected unit(s) to build the current proto unit cursor building type at the pointer location, with wall-like endpoint behavior.
	extern void(*const uiBuildWallAtPointer)(bool a);
	
	extern void(*const uiCreateRiverToggleWaypointMode)();
	
	extern void(*const uiPlaceRiverWaypoint)();
	
	extern void(*const uiRemoveRiverWaypoint)();
	
	extern void(*const uiCreateRiver)();
	
	extern void(*const uiCreateRandomRiver)();
	
	extern void(*const uiPlaceRiverShallow)();
	
	extern void(*const uiRemoveRiverShallow)();

	// intended for ui use only.  Rotate river shallow with wheel -- i.e. intended to be mapped to wheel
	extern void(*const uiWheelRotateRiverShallow)(int a);

	// Sets the gather points for the selected unit(s) to the pointer position.
	extern void(*const uiSetGatherPointAtPointer)(bool homeCity, bool water);

	// Sets the HC spawn point.
	extern void(*const uiSetHomeCityWaterSpawnPointAtPointer)();

	// Clears the gather point for the selected unit(s), returning it to a default state.
	extern void(*const uiClearGatherPoint)();

	// transforms the selected unit into the specified proto unit.
	extern void(*const uiTransformSelectedUnit)(string a);

	// Sends out a flare at the pointer position.
	extern void(*const uiFlareAtPointer)();

	// Used when flaring a position for player comms dialog.
	extern void(*const uiCommsFlareAtPointer)();

	// Sends out a Help at the pointer position.
	extern void(*const uiHelpAtPointer)();

	// Commands the selected unit(s) to garrison in a building at the pointer position.
	extern void(*const uiGarrisonToPointer)();

	// Commands the selected unit(s) to repair the target building at the pointer position.
	extern void(*const uiRepairAtPointer)();

	// Commands the selected unit(s) to Empower the target building at the pointer position.
	extern void(*const uiEmpowerAtPointer)();

	// sets the cursor to a proto-unit.
	extern void(*const uiSetProtoCursor)(string stringProtoName, bool setPlacement);

	// sets the cursor to a proto-unit.
	extern void(*const uiSetProtoCursorID)(int integerProtoID);

	// enters the specified UI context.
	extern void(*const uiEnterContext)(string stringContext);

	// leaves the specified UI context.
	extern void(*const uiLeaveContext)(string stringContext);

	// resets the cursor to the basic pointer.
	extern void(*const uiClearCursor)();

	// intended for ui use only.  Indicates that the yaw unit right key has gone up/down.
	extern void(*const uiYawUnitRight)(int integerKeyState);

	// intended for ui use only.  Indicates that the yaw unit left key has gone up/down.
	extern void(*const uiYawUnitLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that the pitch unit up key has gone up/down.
	extern void(*const uiPitchUnitUp)(int integerKeyState);

	// intended for ui use only.  Indicates that the pitch unit down key has gone up/down.
	extern void(*const uiPitchUnitDown)(int integerKeyState);

	// intended for ui use only.  Indicates that the roll unit right key has gone up/down.
	extern void(*const uiRollUnitRight)(int integerKeyState);

	// intended for ui use only.  Indicates that the roll unit left key has gone up/down.
	extern void(*const uiRollUnitLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that the move unit forward key has gone up/down.
	extern void(*const uiMoveUnitForward)(int integerKeyState);

	// intended for ui use only.  Indicates that the move unit backward key has gone up/down.
	extern void(*const uiMoveUnitBackward)(int integerKeyState);

	// intended for ui use only.  Indicates that the move unit right key has gone up/down.
	extern void(*const uiMoveUnitRight)(int integerKeyState);

	// intended for ui use only.  Indicates that the move unit left key has gone up/down.
	extern void(*const uiMoveUnitLeft)(int integerKeyState);

	// intended for ui use only.  Indicates that the move unit up key has gone up/down.
	extern void(*const uiMoveUnitUp)(int integerKeyState);

	// intended for ui use only.  Indicates that the move unit down key has gone up/down.
	extern void(*const uiMoveUnitDown)(int integerKeyState);

	// intended for ui use only.  Rotate placed unit with wheel -- i.e. intended to be mapped to wheel
	extern void(*const uiWheelRotatePlacedUnit)(int a);

	// intended for ui use only.  Selects water at pointer location.
	extern void(*const uiSelectWaterAtPointer)();

	// intended for ui use only.  Unselects currently selected water.
	extern void(*const uiUnSelectWater)();

	// Paint objects on the currently selected water.
	extern void(*const uiPaintWaterObjects)();

	// intended for ui use only.  Indicates that the rotate water left button has gone up/down.
	extern void(*const uiRotateWaterLeft)(int a);

	// intended for ui use only.  Indicates that the rotate water right button has gone up/down.
	extern void(*const uiRotateWaterRight)(int a);

	// intended for ui use only.  Indicates that selection button has been pressed.
	extern void(*const uiSelectionButtonDown)();

	// intended for ui use only.  Indicates that selection button has been released.
	extern void(*const uiSelectionButtonUp)();

	// creates a number group with the currently selected units.
	extern void(*const uiCreateNumberGroup)(int integerGroup);

	// erases the given number group.
	extern void(*const uiClearNumberGroup)(int integerGroup);

	// selects the units in the given number group.
	extern void(*const uiSelectNumberGroup)(int integerGroup);

	// adds the units in the given number group to current selection.
	extern void(*const uiAddSelectNumberGroup)(int integerGroup);

	// removes current selection from any army.
	extern void(*const uiRemoveFromAnyNumberGroup)();

	// intended for ui use only.  Double click select at pointer location.
	extern void(*const uiDoubleClickSelect)(int integerAdd, bool checkAction);

	// intended for ui use only.  Indicates that the add selection button has been pressed.
	extern void(*const uiAddSelectionButtonDown)();

	// intended for ui use only.  Indicates that the add selection button has been released.
	extern void(*const uiAddSelectionButtonUp)();

	// intended for ui use only.  
	extern void(*const uiToggleSelectionButton)();

	// intended for ui use only.  rotates the selected UNIT.
	extern void(*const uiRotateSelection)(int a);

	// intended for ui use only.  Indicates that selection button has been pressed.
	extern void(*const uiMoveSelectionButtonDown)();

	// intended for ui use only.  Indicates that selection button has been released.
	extern void(*const uiMoveSelectionButtonUp)();

	// intended for ui use only.  Indicates that selection button has been pressed.
	extern void(*const uiMoveSelectionAddButtonDown)();

	// intended for ui use only.  Indicates that selection button has been released.
	extern void(*const uiMoveSelectionAddButtonUp)();

	// intended for ui use only.  Issues "work" at pointer location.
	extern void(*const uiWorkAtPointer)();

	// intended for ui use only.  Rotate with wheel -- i.e. intended to be mapped to wheel
	extern void(*const uiWheelRotate)(int a);

	// intended for ui use only.  Rotate with wheel -- i.e. intended to be mapped to wheel
	extern void(*const uiWheelRotateCamera)(int a);

	// intended for ui use only.  Indicates that the change elevation to sample button has gone up/down.
	extern void(*const uiChangeElevationToSample)(int integerKeyState);

	// intended for ui use only.  Samples elevation height at pointer.
	extern void(*const uiSampleElevationAtPointer)();

	// intended for ui use only.  Samples Cliff elevation height at pointer.
	extern void(*const uiSampleCliffElevationAtPointer)();

	// intended for ui use only.  Indicates that the sample terrain button has gone up/down.
	extern void(*const uiPaintTerrainToSample)(int integerKeyState);

	// intended for ui use only.  Samples terrain type at pointer.
	extern void(*const uiSampleTerrainAtPointer)();

	// deletes selected unit.
	extern void(*const uiDeleteSelectedUnit)();

	// deletes selected unit.
	extern void(*const uiDeleteSelectedUnit2)();

	// deletes all selected unit.
	extern void(*const uiDeleteAllSelectedUnits)();

	// Removes specified unit, or selected unit if not ID is specified.
	extern void(*const uiRemoveSelectedUnit)(int unitID);

	// stop selected units.
	extern void(*const uiStopSelectedUnits)();

	// intended for ui use only.  Indicates that the raise elevation button has gone up/down.
	extern void(*const uiRaiseElevation)(int integerKeyState);

	// intended for ui use only.  Indicates that the lower elevation button has gone up/down.
	extern void(*const uiLowerElevation)(int integerKeyState);

	// raises the terrain height uniformly in the brush region
	extern void(*const uiUniformRaiseElevation)(int a);

	// lowers the terrain height uniformly in the brush region
	extern void(*const uiUniformLowerElevation)(int a);

	// intended for ui use only.  Indicates that the smooth button has gone up/down.
	extern void(*const uiSmooth)(int integerKeyState);

	// intended for ui use only.  Indicates that the paint water button has gone up/down.
	extern void(*const uiPaintWater)(int integerKeyState);

	// intended for ui use only. Painting water area.
	extern void(*const uiPaintWaterArea)(int integerKeyState);

	// intended for ui use only.  Indicates that the paint cliff button has gone up/down.
	extern void(*const uiPaintCliff)(int integerKeyState);

	// intended for ui use only.  Indicates that the terrain selection button has gone up/down.
	extern void(*const uiTerrainSelection)(int integerKeyState);

	// intended for ui use only.  Indicates that the raise terrain selection button has gone up/down.
	extern void(*const uiRaiseTerrainSelection)(int integerKeyState);

	// intended for ui use only.  Indicates that the lower terrain selection button has gone up/down.
	extern void(*const uiLowerTerrainSelection)(int integerKeyState);

	// flatten the current terrain selection.
	extern void(*const uiFlattenTerrainSelection)();

	// filter the current terrain selection.
	extern void(*const uiFilterTerrainSelection)();

	// open a scenario from the scenario directory
	extern void(*const uiOpenScenarioBrowser)(string a);

	// save a scenario to the scenario directory
	extern void(*const uiSaveScenarioBrowser)(string a);

	// save a scenario to the scenario directory
	extern void(*const uiSaveAsScenarioBrowser)(string a);

	// opens a Grand Conquest saved game
	extern void(*const uiOpenGrandConquestBrowser)(string a);

	// load a scenario, checking dirty bit on world.
	extern void(*const uiScenarioLoad)();

	// test a scenario.
	extern void(*const uiStartScenarioTest)();

	// test a scenario.
	extern void(*const uiStopScenarioTest)();

	// test a scenario.
	extern void(*const uiStartBuildCinematic)();

	// test a scenario.
	extern void(*const uiStopBuildCinematic)();

	// clears cinematic trigger info.
	extern void(*const uiClearCinematicInfo)();

	// clears all cinematic info including model/texture precache info.
	extern void(*const uiClearAllCinematicInfo)();

	// open a camera track from the data directory
	extern void(*const uiOpenCameraTrackBrowser)(string a);

	// save a camera track to the data directory
	extern void(*const uiSaveCameraTrackBrowser)(string a);

	// open a game from the saved game directory
	extern void(*const uiOpenSavedGameBrowser)(string a);

	// save a game to the saved game directory
	extern void(*const uiSaveSavedGameBrowser)(string a);

	// zooms to the first instance of proto unit X owned by the current player.
	extern void(*const uiZoomToProto)(string stringProto);

	// open a record game from the saved game directory
	extern void(*const uiOpenRecordGameBrowser)(string a);

	// moves the camera to see the first selected unit.
	extern void(*const uiLookAtSelection)();

	// moves the camera to see the specified Unit.
	extern void(*const uiLookAtUnit)(int a);

	// moves the camera to see the specified battle.
	extern void(*const uiLookAtBattle)(int a);

	// moves the camera to see the specified unit and selects it.
	extern void(*const uiLookAtAndSelectUnit)(int a);

	// moves the camera to see the specified Unit.
	extern void(*const uiLookAtUnitByName)(string scenarioName);

	// moves the camera to see the first instance of proto unit X owned by the current player.
	extern void(*const uiLookAtProto)(string a);

	// moves the camera to see the given number group.
	extern void(*const uiLookAtNumberGroup)(int integerGroup);

	// intended for ui use only.  Indicates that the roughen button has gone up/down.
	extern void(*const uiRoughen)(int integerKeyState);

	// intended for ui use only.  Indicates that the delete units button has gone up/down.
	extern void(*const uiDeleteUnits)(int integerKeyState);

	// intended for ui use only.  Indicates that the paint button has gone up/down.
	extern void(*const uiPaint)(bool integerKeyState, bool a);

	// intended for ui use only.  Indicates that the paint button has gone up/down.
	extern void(*const uiPaintForest)(bool paint, bool offset);

	// intended for ui use only.  Indicates that the paint terrain overlay button has gone up/down.
	extern void(*const uiPaintTerrainOverlay)(int integerKeyState);

	// intended for ui use only.  Places unit at pointer location.
	extern void(*const uiPlaceAtPointer)(bool boolChangeVariation);

	// sets the proto ID to place.
	extern void(*const uiSetProtoID)(int integerType);

	// increments the variation to place.
	extern void(*const uiIncPlaceVariation)();

	// does and editMode and setProtoID, after verifying sufficient resources for the current player.
	extern void(*const uiBuildMode)(int integerType);

	// finds the next idle unit of the given type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern void(*const uiFindIdleType)(string typeName);

	// finds all units of the same type as the selected unit
	extern void(*const uiFindAllOfSelectedType)();

	// finds all units of the same type
	extern void(*const uiFindAllOfType)(string a);

	// finds all idle units of the same type
	extern void(*const uiFindAllOfTypeIdle)(string a);

	// does the right thing.
	extern void(*const uiHandleIdleBanner)(string typeName);

	// finds the next town center that has the town bell active, so that it can be called repeatedly to cycle.
	extern void(*const uiFindTownBellTC)(string a);

	// finds the next unit (idle or not) of the given type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern void(*const uiFindType)(string typeName);

	// cycles through the 'active' child gadget of a deluxe gadget.
	extern void(*const uiCycleGadget)(int integerDelta);

	// closes (as if clicked on the close button) any active field set
	extern void(*const uiCloseFieldSet)();

	// closes (as if clicked on the close button) any active dialog
	extern void(*const uiCloseDialog)();

	// pops up a message box with text that activated the cmd when the ok button is hit
	extern void(*const uiMessageBox)(string stringText, string stringCommand);

	// pops up a message box with text that activated the cmd when the ok button is hit
	extern void(*const uiMessageBox2)(int stringID, string stringCommand);

	// copies the brush selection to the clipboard.
	extern void(*const uiCopyToClipboard)();

	// pastes the contents of the clipboard to the brush selection.
	extern void(*const uiPasteFromClipboard)();

	// sets the clipboard rotation amount.
	extern void(*const uiSetClipboardRotation)(float degrees);

	// rotate the clipboard by amount.
	extern void(*const uiRotateClipboard)(int degrees);

	// intended for UI use only.  Sends an ejection command for the selected unit.
	extern void(*const uiEjectGarrisonedUnits)();

	// intended for UI use only.  Sends an ejection command with waypoint for the selected unit.
	extern void(*const uiEjectAtPointer)();

	// intended for UI use only.  Sends an patrol order.
	extern void(*const uiPatrolAtPointer)();

	// intended for UI use only.  Applies a Lighting Set
	extern void(*const uiApplyLightingSet)(int integerIndex);

	// makes the current brush based on the name and parameters.
	extern void(*const uiSetBrushType)(string name, float p1, float p2, float p3, float p4);

	// changes the brush to the named type
	extern void(*const uiChangeBrushType)(string name);

	// changes the size of the current brush
	extern void(*const uiChangeBrushSize)(float p1, float p2, float p3, float p4);

	// intended for ui use only. Increament the size of the current brush up/down
	extern void(*const uiScrollBrushSize)(int a);

	// changes the ability to modify corner tiles: 0-All, 1-Corners only, 2-No corners
	extern void(*const uiChangeBrushCornerMode)(int a);

	// changes the ability to modify vertices on cliff edges: 0-No clamping, 1-Clamp Low Edge, 2-Clamp High Edge, 3 - Clamp All Edges
	extern void(*const uiChangeCliffModMode)(int a);

	// intended for ui use only. Increment the height of the cliff brush up/down
	extern void(*const uiScrollCliffHeight)(int a);

	// used when activating a text box with a key to avoid having that key go into the text box too.
	extern void(*const uiIgnoreNextKey)();

	// acts like the current cycle gadget has been pressed
	extern void(*const uiCycleCurrentActivate)();

	// removes any dangling child menus off of the given gadget
	extern void(*const uiClearMenu)(string a);

	// deselects all selected units
	extern void(*const uiClearSelection)();

	// spews all key mappings out to the console.
	extern void(*const uiDumpKeyMappings)(string stringContext);

	// spews all hot key mappings that create units to the console
	extern void(*const uiDumpAllUnitHotKeyMappings)(string a);

	// spews all empty keys out to the console
	extern void(*const uiDumpUnmappedKeys)(string stringContext);

	// finds all key mappings for a given key
	extern void(*const uiFindKeyMapping)(string stringKeyname);

	// handles toggle of user textures
	extern void(*const uiHandleUserTab)(int listSel, int parent);

	// flattens terrain and paints water over the entire map.
	extern void(*const uiCoverTerrainWithWater)(float floatWaterHeight, float floatDepth, string waterName);

	// sets the cliff type by name.
	extern bool(*const uiSetCliffType)(string stringCliffName);

	// sets the cliff type by index.
	extern bool(*const uiSetCliffTypeNum)(int longCliffType);

	// sets the water type by name.
	extern bool(*const uiSetWaterType)(string stringWaterName);

	// sets the water type by index.
	extern bool(*const uiSetWaterTypeNum)(int longWaterType);

	// sets the forest type by name.
	extern bool(*const uiSetForestType)(string stringForestName);

	// sets the forest type by index.
	extern bool(*const uiSetForestTypeNum)(int a);

	// selects the forest under the pointer.
	extern void(*const uiSelectForestAtPointer)();

	// de-selects the forest under the pointer.
	extern void(*const uiUnselectForest)();

	// selects the cliff under the pointer.
	extern void(*const uiSelectCliffAtPointer)();

	// de-selects the forest under the pointer.
	extern void(*const uiUnselectCliff)();

	// toggles cliff pieces on or off under the pointer.
	extern void(*const uiToggleCliff)();

	// scrolls the gadget up one unit
	extern void(*const gadgetScrollUp)(string a);

	// scrolls the gadget up one unit
	extern void(*const gadgetScrollDown)(string a);

	// scrolls the gadget to the left one unit
	extern void(*const gadgetScrollLeft)(string a);

	// scrolls the gadget to the Right one unit
	extern void(*const gadgetScrollRight)(string a);

	// makes real the named gadget.
	extern void(*const gadgetReal)(string stringName);

	// makes un-real the named gadget.
	extern void(*const gadgetUnreal)(string stringName);

	// toggles the reality of the named gadget.
	extern void(*const gadgetToggle)(string stringName);

	// toggles the reality of the named gadget.
	extern void(*const gadgetToggleIfNotMP)(string a);

	// refresh the contents of the named gadget.
	extern void(*const gadgetRefresh)(string stringName);

	// turns gadget flashing on/off.
	extern void(*const gadgetFlash)(string stringName, bool flash);

	// turns gadget flashing on/off.
	extern void(*const techFlash)(int techID, bool flash);

	// turns gadget flashing on/off.
	extern void(*const trainFlash)(int protoID, bool flash);

	// turns gadget flashing on/off.
	extern void(*const categoryFlash)(int ID, bool flash);

	// fade in/out using color specified.
	extern void(*const fadeToColor)(int r, int g, int b, int duration, int delay, bool inout);

	// turn fade in on/off, set color duration.
	extern void(*const setGameFadeIn)(int r, int g, int b, int duration, int delay, bool inout);

	// load some triggers.
	extern void(*const uiLoadTriggers)(string a);

	// save some triggers.
	extern void(*const uiSaveTriggers)(string a);

	// load some triggers.
	extern void(*const uiImportTriggers)(string a);

	// load some triggers.
	extern void(*const doTriggerImport)(string a);

	// save some triggers.
	extern void(*const uiExportTriggers)(string a);

	extern void(*const uiTriggerSelectLocation)();

	extern void(*const uiTriggerResetParameters)();

	extern void(*const uiTriggerResetSounds)();

	// save a group.
	extern void(*const uiExportGrouping)(string a);

	// save some groups.
	extern void(*const uiSaveGrouping)(string a);

	// save some groups.
	extern void(*const uiSaveGroupingLUA)(int a, string b);

	// testing only
	extern void(*const uiHideCursor)(bool a);

	// causes game to return to editMode none when shift hotkey is released
	extern void(*const uiLeaveModeOnUnshift)();

	// This is not what you are looking for.
	extern void(*const uiToggleBrushMask)(int a);

	// This is not what you are looking for.
	extern void(*const uiToggleTerrainPasteMode)(int a);

	// brings up the detail help UI for the given proto ID, or -1 for current unit selection proto.
	extern void(*const uiUnitDetailHelp)(int protoID, int civID);

	// brings up the detail help UI for the given tech node ID
	extern void(*const uiTechDetailHelp)(int techID);

	// brings up the detail help UI for the given tech node ID
	extern void(*const uiTechCivDetailHelp)(int a, int b);

	// brings up the detail help UI for the given help topic
	extern void(*const uiTopicDetailHelp)(string topicName);

	// goes back to the most recent help entry.
	extern void(*const uiLastDetailHelp)();

	// shows the ai debug menu with new data.
	extern void(*const AIDebugInfoRefresh)();

	// toggles whether the ai debug menu is up, refreshing if first showing.
	extern void(*const AIDebugInfoToggle)();

	// toggles whether the ai output window is up, refreshing if first showing.
	extern void(*const AIDebugOutputToggle)();

	// toggles whether the ai gatherer distribution window is up, refreshing if first showing.
	extern void(*const AIDebugGathererToggle)();

	// toggles whether the ai pop distribution window is up, refreshing if first showing.
	extern void(*const AIDebugPopToggle)();

	// toggles whether the ai past resource needs window is up, refreshing if first showing.
	extern void(*const AIDebugPastResourceNeedToggle)();

	// toggles whether the kb timed stats window is up, refreshing if first showing.
	extern void(*const AIDebugTimedStatsToggle)();

	// toggles the display of bases
	extern void(*const AIDebugShowBasesToggle)();

	// toggles the showing of Building placement value text.
	extern void(*const AIDebugToggleBPText)();

	// brings up the plan debug text for the given plan ID
	extern void(*const uiShowAIDebugInfoPlan)(int a);

	// brings up the building placement info for the given ID
	extern void(*const uiShowAIDebugInfoPlacement)(int a);

	// brings up the progression info for the given ID
	extern void(*const uiShowAIDebugInfoProgression)(int a);

	// brings up the kbunit info for the given ID
	extern void(*const uiShowAIDebugInfoKBUnit)(int a);

	// brings up the base info for the given ID
	extern void(*const uiShowAIDebugInfoBase)(int a);

	// brings up the area info for the given ID
	extern void(*const uiShowAIDebugInfoArea)(int a);

	// brings up the area info for the given ID
	extern void(*const uiShowAIDebugInfoAreaGroup)(int a, int b);

	// render the attackRoute info for the given ID
	extern void(*const uiSetKBAttackRouteRender)(int a, bool b);

	// brings up the attackRoute info for the given ID
	extern void(*const uiShowAIDebugInfoAttackRoute)(int a);

	// render the kbResource info for the given ID. If not set given, will not render the resource.
	extern void(*const uiSetKBResourceRender)(int resID, bool set);

	// brings up the kbResource info for the given ID
	extern void(*const uiShowAIDebugInfoKBResource)(int a);

	// render the kbArmy info for the given ID. If not set given, will not render the army.
	extern void(*const uiSetKBArmyRender)(int id, bool set);

	// brings up the kbArmy info for the given ID
	extern void(*const uiShowAIDebugInfoKBArmy)(int a);

	// brings up the kbUnitPick info for the given ID
	extern void(*const uiShowAIDebugInfoKBUnitPick)(int a);

	// brings up the escrow info for the given ID
	extern void(*const uiShowAIDebugInfoEscrow)(int a);

	// controls rendering of the building placement info for the given ID
	extern void(*const uiSetBuildingPlacementRender)(int id, bool on);

	// Scrolls chat back one.
	extern void(*const uiChatScrollBack)(int integerKeyState);

	// Scrolls chat forward one.
	extern void(*const uiChatScrollForward)(int integerKeyState);

	// Toggles the chat display mode.
	extern void(*const uiChatDisplayModeToggle)();

	// Toggles the chat display mode to recent mode.
	extern void(*const uiChatDisplayModeToRecent)();

	// Toggles the chat display mode to history mode.
	extern void(*const uiChatDisplayModeToHistory)();

	// Clears the chat and resets to recent mode.  clearOnly == true if you don't want it to populate the chat, but only clear it.
	extern void(*const uiClearChat)(bool clearOnly);

	// Adds a notification to the game's chat output, can play a sound too.
	extern void(*const uiAddChatNotification)(int a, int b, int c, int d);

	// Adds notify text, can play a sound too.
	extern void(*const uiSetHCNotifyText)(int a, int b);

	extern void(*const uiShowChatWindow)();

	// pops up all downed keys.
	extern void(*const uiReleaseDownKeys)();

	// spews all down keys.
	extern void(*const uiSpewDownKeys)();

	extern void(*const uiShowVoteDialog)();

	// used direcly by UI
	extern void(*const uiSendIngameChat)();

	// Used to activate the politician UI
	extern void(*const uiPoliticianUI)(int a, int b, bool c);

	// Used to activate the politician UI in current selection
	extern void(*const uiPoliticianUIInSelected)(string a);

	// Used to activate the consulate UI
	extern void(*const uiConsulateUI)(int a, int b);

	// Used to activate the consulate UI from hotkeys
	extern void(*const uiConsulateUIInSelected)();

	extern void(*const enterAttackMoveMode)();

	extern void(*const uiShowObjectivesDialog)();

	// Causes the currently displaying objective notification to fade out (or disappear), depending on the param passed in.
	extern void(*const uiExpireCurrentObjectiveNotification)(bool a);

	extern void(*const uiPlaceTradeRouteWaypoint)();

	extern void(*const uiRemoveTradeRouteWaypoint)();

	extern void(*const uiSelectTransportUnit)();

	// finds the next resource gatherer unit of the given resource type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern void(*const uiFindResourceGatherers)(string typeName);

	// finds the gatherer unit that's not gathering in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern void(*const uiFindGatherersNotGathering)();

	// finds the next native settler dancing at the firepit in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	extern void(*const uiFindDancers)();

	// selects the users firepit if it exists
	extern void(*const uiSelectFirepit)();

	// finds allied natives of the current player in order, so that it can be called repeatedly to cycle.
	extern void(*const uiFindAlliedNatives)();

	// Shows the VP accel building from the unitID.
	extern void(*const uiVPAccelClick)(int unitID);

	extern void(*const incrementUSP2SelectedUnitStack)();

	extern void(*const decrementUSP2SelectedUnitStack)();

	extern void(*const uiSetCameraStartLoc)();

	extern void(*const uiShowCameraStartLoc)();

	extern void(*const uiDeleteCameraStartLoc)();

	// Scrolls the game view.
	extern void(*const uiCameraScroll)(bool fast, float x, float y);

	// Controls camera with gamepad stick.
	extern void(*const uiCameraControl)(float x, float y);

	// Moves the map pointer.
	extern void(*const uiMapPointerControl)(float x, float y, bool doGoto);

	// Jump to map pointer location.
	extern void(*const uiMapPointerGoto)(bool activeCheck);

	// Start/stop circle selection.
	extern void(*const uiCircleSelect)(bool on, bool doubleClick, bool leaveSelected);

	// Circle selection resizing.
	extern void(*const uiCircleSelectResize)(float x, float y);

	// Centers mouse pointer.
	extern void(*const uiCenterPointer)();

	// Force shift key on or off.
	extern void(*const uiForceShift)(bool on);

	// screen selection.
	extern void(*const uiScreenSelect)(bool modifier);

	// resets screen selection.
	extern void(*const uiResetScreenSelect)();

	extern void(*const uiFindCrowd)(int findType, bool noLookAt);

	extern void(*const uiResetFindCrowd)();

	extern void(*const uiShowStatPanel)();

	extern void(*const uiShowDetailedHelp)();

	extern void(*const uiShowCommandPanel)();

	extern void(*const uiMinimizeStats)();

	// Moves all military units to the pointer position.
	extern void(*const uiMoveAllMilitaryAtPointer)();

	// send attack sentence from one player to another; specify targetPlayer, or targetUnit, or xPos and zPos.
	extern void(*const sendAttackSentence)(int sendingPlayer, int receivingPlayer, int targetPlayer, int targetUnit, float xPos, float zPos);

	// send defend sentence from one player to another; specify target xPos and zPos.
	extern void(*const sendDefendSentence)(int sendingPlayer, int receivingPlayer, float xPos, float zPos);

	// send tribute sentence from one player to another; specify desired resource.
	extern void(*const sendTributeSentence)(int sendingPlayer, int receivingPlayer, int resourceID);

	// send AIChat to current player from sendingPlayer; specify desired AIChatPromptType.
	extern void(*const sendPromptType)(int sendingPlayer, int promptType);

	// begins a new random game.
	extern void(*const startRandomGame)(bool a);

	// begins a new random game with the given parms.
	extern void(*const startRandomGame2)(string filename, int players, int random, string seed, bool scenarioFilename, int debug, int teamCount, int mapsize, bool resources);

	// Generates a random map game with the given map code.
	extern void(*const startRandomGameMapCode)(string mapcode);

	// Generates a random map game with the given starting age, nomad start(true/false), and map code.
	extern void(*const startRandomGameAgeAndMapCode)(int startingage, bool nomad, string mapcode);

	// restarts current game.
	extern void(*const restartCurrentGame)();

	// destroys the world and returns to main menu.
	extern void(*const leaveGame)(int a, int b);

	// does what needs to be done.
	extern void(*const handlePostGame)();

	// does what needs to be done.
	extern void(*const showGameFromPostGame)();

	// does what needs to be done.
	extern void(*const postGamePlayAgain)();

	// changes the zoom factor of the minimap up or down by that amount (remaining centered on the current view)
	extern void(*const minimapZoomDelta)(float floatZoomDelta);

	// sets the zoom factor of the minimap.
	extern void(*const minimapZoom)(float floatZoom);

	// changes the minimap rotation mode.  No arg means toggle.
	extern void(*const minimapRotateMode)(int integerMode);

	// adds a line of chat text from the given player (current if not provided.
	extern void(*const chat)(string stringText, int integerPlayer);

	// intended for ui use only.  Use a special power at targeted location.
	extern void(*const uiSpecialPowerAtPointer)();

	// turns off and on the game UI.
	extern void(*const uiToggleGame)();

	// zooms to the most recent minimap event
	extern void(*const uiZoomToMinimapEvent)();

	// reconstitutes the entire editor menu
	extern void(*const uiRefreshEditorMenu)();

	// minimizes main UI and brings up the minimized UI
	extern void(*const uiShowTributeDialog)();

	// maximizes main UI
	extern void(*const uiHideTributeDialog)();

	// Shows the player summary dialog.
	extern void(*const uiShowPlayerSummaryDialog)();

	// Hides the player summary dialog.
	extern void(*const uiHidePlayerSummaryDialog)();

	// creates a new blank scenario
	extern void(*const uiNewScenario)();

	// intended for ui use only.  Indicates that the increase sun inclination key has gone up/down.
	extern void(*const sunIncreaseInclination)(int keyState);

	// intended for ui use only.  Indicates that the decrease sun inclination key has gone up/down.
	extern void(*const sunDecreaseInclination)(int keyState);

	// intended for ui use only.  Indicates that the increase sun rotation key has gone up/down.
	extern void(*const sunIncreaseRotation)(int keyState);

	// intended for ui use only.  Indicates that the decrease sun rotation key has gone up/down.
	extern void(*const sunDecreaseRotation)(int keyState);

	// sets the sun height above the horizon and position in the world, The bool tells if the changes are relative
	extern void(*const setSunPosition)(float sunInclination, float sunRotation, bool relative);

	// abort the current cinematic.
	extern void(*const abortCinematic)();

	// causes score to update even if it isn't supposed to yet, time wise
	extern void(*const scoreUpdate)();

	// handles the score toggling
	extern void(*const toggleScore)();

	// handles the time display toggling
	extern void(*const toggleTime)();

	// handles the time display toggling
	extern void(*const toggleDebugTime)();

	// Enter Single player setup.
	extern void(*const doSPSetup)(bool a);

	// Enter BMultiplayer setup.
	extern void(*const doMPSetup)(bool useESO);

	// Leave the current MP screen and return to the MP setup menu.
	extern void(*const exitMPSetupSubScreen)();

	// 
	extern void(*const enterRecordGameMode)(string name);

	// 
	extern void(*const enterGCGameMode)(string name);

	// UI used only
	extern void(*const showCampaignDialog)(string name, string msg);

	// resigns the currently controlled player.
	extern void(*const playerResign)();

	// show the in-game menu.
	extern void(*const showGameMenu)();

	// hide the in-game menu.
	extern void(*const hideGameMenu)(bool a);

	// show the in-game menu.
	extern void(*const uiSaveCampaignGameBrowser)();

	// initializes the Profile Edit Dialog inside the OptionsScreen
	extern void(*const uiInitOptionsScreenProfileEditDialog)();

	// stop playing stupid music at 11pm.
	extern void(*const uiBMultiplayerSave)();

	// drop back to the main menu
	extern void(*const dropToMainMenu)();

	extern bool(*const modelLoad)(string modelXMLFilename);

	// change the cliff type for all cliffs on the map
	extern void(*const changeCliffType)(string cliffName);

	// turn on/off gamepad command panel control.
	extern void(*const uiCommandPanelControl)(bool on);

	// move between selections in the command panel.
	extern void(*const uiCommandPanelMove)(float x, float y);

	// gamepad command panel execute.
	extern void(*const uiCommandPanelExecute)(bool a);

	// executes the trYouWin trigger func, allowing you to win the scenario.
	extern void(*const winScenario)();

	// Disables the given rule.
	extern void(*const xsDisableRule)(string ruleName);

	// Disables the current rule.
	extern void(*const xsDisableSelf)();

	// Enables the given rule.
	extern void(*const xsEnableRule)(string ruleName);

	// Returns true if the rule is enabled.
	extern bool(*const xsIsRuleEnabled)(string ruleName);

	// Sets the priority of the given rule.
	extern void(*const xsSetRulePriority)(string ruleName, int priority);

	// Sets the priority of the current rule.
	extern void(*const xsSetRulePrioritySelf)(int priority);

	// Sets the min interval of the given rule.
	extern void(*const xsSetRuleMinInterval)(string ruleName, int interval);

	// Sets the min interval of the current rule.
	extern void(*const xsSetRuleMinIntervalSelf)(int interval);

	// Sets the max interval of the given rule.
	extern void(*const xsSetRuleMaxInterval)(string ruleName, int interval);

	// Sets the max interval of the current rule.
	extern void(*const xsSetRuleMaxIntervalSelf)(int interval);

	// Enables all rule in the given rule group.
	extern void(*const xsEnableRuleGroup)(string ruleGroupName);

	// Disables all rules in the given rule group.
	extern void(*const xsDisableRuleGroup)(string ruleGroupName);

	// Returns true if the rule group is enabled.
	extern void(*const xsIsRuleGroupEnabled)(string ruleGroupName);

	// Returns the x component of the given vector.
	extern float(*const xsVectorGetX)(vector v);

	// Returns the y component of the given vector.
	extern float(*const xsVectorGetY)(vector v);

	// Returns the z component of the given vector.
	extern float(*const xsVectorGetZ)(vector v);

	// Set the x component of the given vector, returns the new vector.
	extern vector(*const xsVectorSetX)(vector result, vector v, float x);

	// Set the y component of the given vector, returns the new vector.
	extern vector(*const xsVectorSetY)(vector result, vector v, float y);

	// Set the z component of the given vector, returns the new vector.
	extern vector(*const xsVectorSetZ)(vector result, vector v, float z);

	// Set the 3 components into a vector, returns the new vector.
	extern vector(*const xsVectorSet)(vector result, float x, float y, float z);

	// Returns the length of the given vector.
	extern float(*const xsVectorLength)(vector v);

	// Returns the normalized version of the given vector.
	extern vector(*const xsVectorNormalize)(vector result, vector v);

	// creates a sized and named integer array, returning an arrayID.
	extern int(*const xsArrayCreateInt)(int size, int defaultValue, string name);

	// Sets a value at the specified index in the requested array.
	extern bool(*const xsArraySetInt)(int arrayID, int index, int value);

	// Gets the value at the specified index in the requested array.
	extern int(*const xsArrayGetInt)(int arrayID, int index);

	// creates a sized and named float array, returning an arrayID.
	extern int(*const xsArrayCreateFloat)(int size, float defaultValue, string name);

	// Sets a value at the specified index in the requested array.
	extern bool(*const xsArraySetFloat)(int arrayID, int index, float value);

	// Gets the value at the specified index in the requested array.
	extern float(*const xsArrayGetFloat)(int arrayID, int index);

	// creates a sized and named boolean array, returning an arrayID.
	extern int(*const xsArrayCreateBool)(int size, bool defaultValue, string name);

	// Sets a value at the specified index in the requested array.
	extern bool(*const xsArraySetBool)(int arrayID, int index, bool value);

	// Gets the value at the specified index in the requested array.
	extern bool(*const xsArrayGetBool)(int a, int b);

	// creates a sized and named string array, returning an arrayID.
	extern int(*const xsArrayCreateString)(int size, string defaultValue, string name);

	// Sets a value at the specified index in the requested array.
	extern bool(*const xsArraySetString)(int arrayID, int index, string value);

	// Gets the value at the specified index in the requested array.
	extern string(*const xsArrayGetString)(int arrayID, int index);

	// creates a sized and named vector array, returning an arrayID.
	extern int(*const xsArrayCreateVector)(int size, vector defaultValue, string name);

	// Sets a value at the specified index in the requested array.
	extern bool(*const xsArraySetVector)(int arrayID, int index, vector value);

	// Gets the value at the specified index in the requested array.
	extern vector(*const xsArrayGetVector)(vector result, int arrayID, int index);

	// Gets the specified array's size.
	extern int(*const xsArrayGetSize)(int arrayID);

	// blogs out all XS arrays.
	extern void(*const xsDumpArrays)();

	// Returns the current context player ID.
	extern int(*const xsGetContextPlayer)();

	// Sets the current context player ID (DO NOT DO THIS IF YOU DO NOT KNOW WHAT YOU ARE DOING).
	extern void(*const xsSetContextPlayer)(int playerID);

	// Returns the current gametime (in milliseconds).
	extern int(*const xsGetTime)();

	// Setups a runtime event.  Don't use this.
	extern bool(*const xsAddRuntimeEvent)(string foo, string bar, int something);

	// Runs the secret XSFID for the function. USE WITH CAUTION.
	extern int(*const xsGetFunctionID)(string a);

	// Random map echo.
	extern void(*const rmEchoWarning)(string echoString);

	// Random map echo.
	extern void(*const rmEchoError)(string echoString);

	// Returns a random float between min and max.
	extern float(*const rmRandFloat)(float min, float max);

	// Returns a random integer between min and max.
	extern int(*const rmRandInt)(int min, int max);

	// Returns true if this map is to place a covered wagon instead of a town center.
	extern bool(*const rmGetNomadStart)();

	// Returns true if this map is set to be a FFA game which means each player on their own team.
	extern bool(*const rmGetIsFFA)();

	// Returns true if this map is set to be a relic game..
	extern bool(*const rmGetIsRelicCapture)();

	// Returns true if this map is set to be a King of the Hill game.
	extern bool(*const rmGetIsKOTH)();

	// Sets the size of the map.
	extern bool(*const rmSetMapSize)(float x, float z);

	// Returns the X size of the map.
	extern int(*const rmGetMapXSize)();

	// Returns the Z size of the map.
	extern int(*const rmGetMapZSize)();

	// Sets the sea level for the map.
	extern void(*const rmSetSeaLevel)(float a);

	// Gets the sea level for the map.
	extern float(*const rmGetSeaLevel)();

	// Sets the sea type for the map.  This is used if terrain is initialized to water.
	extern bool(*const rmSetSeaType)(string name);

	// Sets up terrain for initializing with a noise layer.
	extern bool(*const rmSetMapElevationParameters)(int type, float freq, int octaves, float persistence, float variation);

	// Initializes the base terrain with the requested mix.  Call before rmTerrainInitialize.
	extern bool(*const rmSetBaseTerrainMix)(string mixName);

	// Adds a terrain to paint between the specified heights, modified by a random number between 0.0 and outerRange.
	extern bool(*const rmAddMapTerrainByHeightInfo)(string terrain, float minHeight, float maxHeight, float outerRange);

	// Adds a terrain to paint on tiles that are sloped between the specified angles (0 degrees is flat terrain, 90 degrees is sheer terrain), modified by a random number between 0.0 and outerRange.
	extern bool(*const rmAddMapTerrainByAngleInfo)(string terrain, float minSlope, float maxSlope, float outerRange);

	// Sets how much to smooth the overall terrain after initializing with noise.
	extern bool(*const rmSetMapElevationHeightBlend)(int blend);

	// place object clusters (of the specified protounit) around the map, and also optionally paint with the specified terrain.
	extern bool(*const rmPlaceMapClusters)(string terrain, string protounit);

	// sets up cluster system; valid ranges are from -1.0 to 1.0 and are compared to the internal noise field for deciding where to paint terrain and place clusters. Type is cClusterLand, or cClusterWater, or cClusterShallowWater, or cClusterEverywhere.
	extern bool(*const rmSetMapClusteringPlacementParams)(float paintThreshold, float placeMinVal, float placeMaxVal, int type);

	// sets up cluster system; min/max objects per tile (default: 0-3), and max random offset when placing (default: 0.5 tiles).
	extern bool(*const rmSetMapClusteringObjectParams)(int minObjectCount, int maxObjectCount, float maxPosOffset);

	// sets up cluster system; standard inputs to noise generator used to determine cluster placement.
	extern bool(*const rmSetMapClusteringNoiseParams)(float minFrequency, int octaves, float persistence);

	// Converts an area from fraction of the map to tile count.
	extern int(*const rmAreaFractionToTiles)(float fraction);

	// Converts area tile count to fraction of map.
	extern float(*const rmAreaTilesToFraction)(int tiles);

	// Converts an fraction of the map in the x direction to tile count.
	extern int(*const rmXFractionToTiles)(float fraction);

	// Converts tile count in the x direction to fraction of map.
	extern float(*const rmXTilesToFraction)(int tiles);

	// Converts an fraction of the map in the z direction to tile count.
	extern int(*const rmZFractionToTiles)(float fraction);

	// Converts tile count in the z direction to fraction of map.
	extern float(*const rmZTilesToFraction)(int tiles);

	// Converts an angle in degrees to radians.
	extern float(*const rmDegreesToRadians)(float degrees);

	// Converts a distance in meters to a number of tiles.
	extern int(*const rmMetersToTiles)(float meters);

	// Converts meters into a fraction of the map in the x direction.
	extern float(*const rmXMetersToFraction)(float meters);

	// Converts meters into a fraction of the map in the z direction.
	extern float(*const rmZMetersToFraction)(float meters);

	// Converts a fraction of the map in the x direction to meters.
	extern float(*const rmXFractionToMeters)(float meters);

	// Converts meters a fraction of the map in the z direction to meters.
	extern float(*const rmZFractionToMeters)(float meters);

	// Creates an area.
	extern int(*const rmCreateArea)(string name, int parentAreaID);

	// Set the area size to a min/max fraction of the map.
	extern bool(*const rmSetAreaSize)(int minFraction, float maxFraction, float a);

	// Enable edge filling and set a border search size (for Carolina and similar maps with a big continent).
	extern bool(*const rmSetAreaEdgeFilling)(int areaID, int borderSize);

	// Set the area location.
	extern bool(*const rmSetAreaLocation)(int areaID, float xFraction, float zFraction);

	// Set the area location to player's location.
	extern bool(*const rmSetAreaLocPlayer)(int areaID, int playerID);

	// Set the area location to team's location.
	extern bool(*const rmSetAreaLocTeam)(int areaID, int teamID);

	// Builds the specified area.
	extern bool(*const rmBuildArea)(int areaID);

	// Simulatenously builds all unbuilt areas.
	extern int(*const rmBuildAllAreas)();

	// Sets the terrain type for an area.
	extern bool(*const rmSetAreaTerrainType)(int areaID, string terrainTypeName);

	// Sets the mix for an area.  Overrides terrain type if it is also set.
	extern bool(*const rmSetAreaMix)(int areaID, string mixName);

	// Paints the terrain for a specified area.
	extern bool(*const rmPaintAreaTerrain)(int areaID);

	// Paints the area's tiles in the specified height range with specified terrain (with outerRange buffer if feathering is desired).
	extern bool(*const rmPaintAreaTerrainByHeight)(int areaID, string terrain, float minHeight, float maxHeight, float outerRange);

	// Paints the area's tiles in the specified angle range with specified terrain (with outerRange buffer if feathering is desired).
	extern bool(*const rmPaintAreaTerrainByAngle)(int areaID, string terrain, float minAngle, float maxAngle, float outerRange);

	// Sets the base height for an area.
	extern bool(*const rmSetAreaBaseHeight)(int areaID, float height);

	// Sets whether the area build process will warn if it fails.
	extern bool(*const rmSetAreaWarnFailure)(int areaID, bool warn);

	// Sets the forest type for an area.
	extern bool(*const rmSetAreaForestType)(int areaID, string forestName);

	// Sets the forest density for an area.
	extern bool(*const rmSetAreaForestDensity)(int areaID, float density);

	// Sets the forest density for an area.
	extern bool(*const rmSetAreaForestClumpiness)(int areaID, float density);

	// Sets the forest density for an area.
	extern bool(*const rmSetAreaForestUnderbrush)(int areaID, float density);

	// Sets the water type for an area.
	extern bool(*const rmSetAreaWaterType)(int areaID, string waterName);

	// Returns the point in areaID that's closest to the given point, optionally requiring that it pass the given constraint.
	extern vector(*const rmGetAreaClosestPoint)(vector result, int areaID, vector point, float pullback, int constraintID);

	// Sets the cliff type for an area.
	extern bool(*const rmSetAreaCliffType)(int areaID, string cliffName);

	// Set cliff painting options for an area.
	extern bool(*const rmSetAreaCliffPainting)(int areaID, bool paintGround, bool paintOutsideEdge, bool paintSide, float minSideHeight, bool paintInsideEdge);

	// Set cliff edge parameters for an area.
	extern bool(*const rmSetAreaCliffEdge)(int areaID, int count, float size, float variance, float spacing, int mapEdge);

	// Set an area's cliff height.
	extern bool(*const rmSetAreaCliffHeight)(int areaID, float val, float variance, float ramp);

	// Adds a class for an area's cliff edge to avoid.
	extern bool(*const rmAddAreaCliffEdgeAvoidClass)(int areaID, int avoidID, float minDist);

	// make a river dude.
	extern int(*const rmRiverCreate)(int areaID, string waterType, int breaks, int offset, int minR, int maxR);

	extern bool(*const rmRiverSetConnections)(int riverID, float startX, float startZ, float endX, float endZ);

	extern bool(*const rmRiverConnectRiver)(int riverID, int river2ID, float pct, float end, float e);

	// Add waypoint to a river.  Don't mix with rmRiverSetConnections or rmRiverConnectRiver
	extern bool(*const rmRiverAddWaypoint)(int riverID, float xFraction, float zFraction);

	extern bool(*const rmRiverSetBankNoiseParams)(int riverID, float frequency, int octaves, float persistence, float sineLength, float sineAmt, float variation);

	extern bool(*const rmRiverSetShallowRadius)(int riverID, int radius);

	extern bool(*const rmRiverAddShallow)(int riverID, float distancePct);

	extern bool(*const rmRiverAddShallows)(int riverID, int count, int radius);

	extern bool(*const rmRiverAvoid)(int riverID, int river2ID, float minDist);

	extern bool(*const rmRiverBuild)(int riverID);

	// reveals a river plus the specified number of extra tiles around it.
	extern bool(*const rmRiverReveal)(int riverID, int extraTiles);

	// the terrain buffer around the river, and the height of the banks above water level
	extern bool(*const rmSetRiverFoundationParams)(int tileBuffer, float heightOffset);

	// sets whether RM activities should be constrained to the main world circle.
	extern bool(*const rmSetWorldCircleConstraint)(bool constrain);

	// Determines whether an area obeys world circle constraint.
	extern bool(*const rmSetAreaObeyWorldCircleConstraint)(int areaID, bool constrain);

	// Adds a terrain layer to an area.
	extern bool(*const rmAddAreaTerrainLayer)(int areaID, string terrain, float minDist, float maxDist);

	// Specifies if the area should vary the terrain layer edges.
	extern bool(*const rmSetAreaTerrainLayerVariance)(int areaID, bool variance);

	// Sets minimum number of area blobs.
	extern bool(*const rmSetAreaMinBlobs)(int areaID, int blobs);

	// Sets maximum number of area blobs.
	extern bool(*const rmSetAreaMaxBlobs)(int areaID, int blobs);

	// Sets minimum blob distance.
	extern bool(*const rmSetAreaMinBlobDistance)(int areaID, float dist);

	// Sets maximum blob distance.
	extern bool(*const rmSetAreaMaxBlobDistance)(int areaID, float dist);

	// Sets area coherence (0-1).
	extern bool(*const rmSetAreaCoherence)(int areaID, float coherence);

	// Sets area edge smoothing distance (distance is number of neighboring points to consider in each direction).
	extern bool(*const rmSetAreaSmoothDistance)(int areaID, int smoothDistance);

	// Sets how smoothly area height blends into surroundings.
	extern bool(*const rmSetAreaHeightBlend)(int areaID, int heightBlend);

	// Gets area ID for given area name.
	extern int(*const rmAreaID)(string name);

	// Adds an area influence point.
	extern bool(*const rmAddAreaInfluencePoint)(int areaID, float xFraction, float zFraction);

	// Adds an area influence segment.
	extern bool(*const rmAddAreaInfluenceSegment)(int areaID, float xFraction1, float zFraction1, float xFraction2, float zFraction2);

	// Add an unit type that the specified area removes.
	extern bool(*const rmAddAreaRemoveType)(int areaID, string typeName);

	// Adds a terrain replacement rule to the area.
	extern bool(*const rmAddAreaTerrainReplacement)(int areaID, string terrainTypeName, string newTypeName);

	// Sets the area elevation variation type (cElevNormal, cElevFractalSum, cElevTurbulence).
	extern bool(*const rmSetAreaElevationType)(int areaID, int type);

	// Sets the area elevation variation noise frequency (best >0 and <1).
	extern bool(*const rmSetAreaElevationMinFrequency)(int areaID, float freq);

	// Sets the area elevation variation noise octaves.
	extern bool(*const rmSetAreaElevationOctaves)(int areaID, int octaves);

	// Sets the area elevation variation noise persistence (best >0 and <1).
	extern bool(*const rmSetAreaElevationPersistence)(int areaID, float persistence);

	// Sets the area elevation variation height (amount to vary +- from area base height).
	extern bool(*const rmSetAreaElevationVariation)(int areaID, float variation);

	// Sets the area elevation noise to falloff as it gets closer to the area edge.
	extern bool(*const rmSetAreaElevationEdgeFalloffDist)(int areaID, float dist);

	// Sets the area elevation variation noise bias (-1 means down only, 0 means +- equally, 1 means up only.)
	extern bool(*const rmSetAreaElevationNoiseBias)(int areaID, float bias);

	// Sets the area to be revealed (-1 means don't reveal, 0 means reveal, >0 means reveal plus that number of extra tiles.
	extern bool(*const rmSetAreaReveal)(int areaID, int tiles);

	// sets the global snow percent.
	extern void(*const rmSetGlobalSnow)(float percent);

	// sets the global rain percent.
	extern void(*const rmSetGlobalRain)(float percent);

	// sets storm length and time between storm in seconds.
	extern void(*const rmSetGlobalStormLength)(int length, int timeBetweenStorms);

	// sets the global wind magnitude (1.0f is default).
	extern void(*const rmSetWindMagnitude)(float magnitude);

	// Initializes the terrain to the base type and height.
	extern void(*const rmTerrainInitialize)(string baseTerrain, float height);

	// Fill map corners with blackmap.
	extern void(*const rmFillMapCorners)();

	//  applies a lighting set fade.
	extern void(*const rmDoLightingFade)(string lightSetName, float fadeTime);

	//  applies a lighting set effect.
	extern void(*const rmDoLightingEffect)(string lightSetName, float blendInTime, float effectTime, float blendOutTime);

	// Sets Gaia's civilization
	extern void(*const rmSetGaiaCiv)(int civ);

	// Allocates the number of sub civs in the world.
	extern bool(*const rmAllocateSubCivs)(int number);

	// Sets a given sub civ in the world.
	extern bool(*const rmSetSubCiv)(int index, string civName, bool big);

	// Returns the civ ID.
	extern int(*const rmGetCivID)(string civName);

	// Adds mercs of to the merc manager for this game.
	extern int(*const rmAddMerc)(string unitName, float count, float minCount, float maxCount, float countIncrement, bool multipleUses);

	// Manually sets a player's starting location.
	extern bool(*const rmSetPlayerLocation)(int playerID, float xFraction, float zFraction);

	// Sets the area of the map to use for player placement.
	extern void(*const rmSetPlayerPlacementArea)(float minX, float minZ, float maxX, float maxZ);

	// Sets the team spacing modifier.
	extern void(*const rmSetTeamSpacingModifier)(float modifier);

	// Sets the team to place.
	extern void(*const rmSetPlacementTeam)(int teamID);

	// Sets the section of the placement line to use.
	extern void(*const rmSetPlacementSection)(float fromPercent, float toPercent);

	// Makes a circle of player locations.
	extern bool(*const rmPlacePlayersCircular)(float minFraction, float maxFraction, float angleVariation);

	// Makes a square of player locations.
	extern bool(*const rmPlacePlayersSquare)(float dist, float distVariation, float spacingVariationfloat);

	// Makes a line of player locations.
	extern bool(*const rmPlacePlayersLine)(float x1, float z1, float x2, float z2, float distVariation, float spacingVariation);

	// Makes a line of player locations along the specified river.
	extern bool(*const rmPlacePlayersRiver)(int riverID, float distVariation, float spacingVariation, float edgeDistance);

	// Sets one player location.
	extern bool(*const rmPlacePlayer)(int playerID, float xFraction, float zFraction);

	// Sets a player's 'official' area.
	extern bool(*const rmSetPlayerArea)(int playerID, int areaID);

	// Gets a player's start location x fraction.
	extern float(*const rmPlayerLocXFraction)(int playerID);

	// Gets a player's start location z fraction.
	extern float(*const rmPlayerLocZFraction)(int playerID);

	// Adds some fairLoc placement info.
	extern int(*const rmAddFairLoc)(string unitName, bool forward, bool inside, float minPlayerDist, float maxPlayerDist, float locDist, float edgeDist, bool playerArea, bool teamArea);

	// Sets fairLoc placement locations.
	extern bool(*const rmPlaceFairLocs)(int a);

	// Resets fairLoc placment info.
	extern void(*const rmResetFairLocs)();

	// Gets a player's number of fairLocs.
	extern int(*const rmGetNumberFairLocs)(int playerID);

	// Gets a player's fairLoc x fraction.
	extern float(*const rmFairLocXFraction)(int playerID, int index);

	// Gets a player's fairLoc z fraction.
	extern float(*const rmFairLocZFraction)(int playerID, int index);

	// Sets a player's resource amount.
	extern bool(*const rmSetPlayerResource)(int playerID, string resourceName, float amount);

	// Adds to a player's resource amount.
	extern bool(*const rmAddPlayerResource)(int playerID, string resourceName, float amount);

	// Multiplys a player's resource amount by the given factor.
	extern bool(*const rmMultiplyPlayerResource)(int playerID, string resourceName, float factor);

	// Gets a player's name.
	extern string(*const rmGetPlayerName)(int playerID);

	// Gets the team the specified player is on.
	extern int(*const rmGetPlayerTeam)(int playerID);

	// Gets the civilization the specified player is on.
	extern int(*const rmGetPlayerCiv)(int playerID);

	// Gets the culture the specified player is on.
	extern int(*const rmGetPlayerCulture)(int playerID);

	// Gets the number of players on the given team.
	extern int(*const rmGetNumberPlayersOnTeam)(int teamID);

	// Sets a team's 'official' area.
	extern bool(*const rmSetTeamArea)(int teamID, int areaID);

	// Make a box constraint.
	extern int(*const rmCreateBoxConstraint)(string name, float startX, float startZ, float endX, float endZ, float bufferFraction);

	// Makes a 'pie' constraint.
	extern int(*const rmCreatePieConstraint)(string name, float xFraction, float zFraction, float insideRadius, float outsideRadius, float minAngle, float maxAngle, float bufferFraction);

	// Make an area overlap constraint.
	extern int(*const rmCreateAreaOverlapConstraint)(string name, int areaID);

	// Make a constraint that forces something to remain within an area.
	extern int(*const rmCreateAreaConstraint)(string name, int areaID);

	// Make an area distance constraint.
	extern int(*const rmCreateAreaDistanceConstraint)(string name, int areaID, float distance);

	// Make an area max distance constraint.
	extern int(*const rmCreateAreaMaxDistanceConstraint)(string name, int areaID, float distance);

	// Make a constraint that forces something to remain within an area's edge.
	extern int(*const rmCreateEdgeConstraint)(string name, int areaID);

	// Make an area edge distance constraint.
	extern int(*const rmCreateEdgeDistanceConstraint)(string name, int areaID, float distance);

	// Make an area edge max distance constraint.
	extern int(*const rmCreateEdgeMaxDistanceConstraint)(string name, int areaID, float distance);

	// Make a constraint that forces something to remain within an area's cliff edge.
	extern int(*const rmCreateCliffEdgeConstraint)(string name, int areaID);

	// Make an area cliff edge distance constraint.
	extern int(*const rmCreateCliffEdgeDistanceConstraint)(string name, int areaID, float distance);

	// Make an area cliff edge max distance constraint.
	extern int(*const rmCreateCliffEdgeMaxDistanceConstraint)(string name, int areaID, float distance);

	// Make a constraint that forces something to remain within an area's cliff ramp edge.
	extern int(*const rmCreateCliffRampConstraint)(string name, int areaID);

	// Make an area cliff ramp edge distance constraint.
	extern int(*const rmCreateCliffRampDistanceConstraint)(string name, int areaID, float distance);

	// Make an area cliff ramp edge max distance constraint.
	extern int(*const rmCreateCliffRampMaxDistanceConstraint)(string name, int areaID, float distance);

	// Make a class distance constraint.
	extern int(*const rmCreateClassDistanceConstraint)(string name, int classID, float distance);

	// Make a type distance constraint.
	extern int(*const rmCreateTypeDistanceConstraint)(string name, string classID, float distance);

	// Make a constraint to avoid terrain with certain a passability.
	extern int(*const rmCreateTerrainDistanceConstraint)(string name, string type, bool passable, float distance);

	// Make a constraint to be close to terrain with certain a passability.
	extern int(*const rmCreateTerrainMaxDistanceConstraint)(string name, string type, bool passable, float distance);

	// Make a constraint to pass if in or out of a corner.
	extern int(*const rmCreateCornerConstraint)(string name, int corner, bool outside);

	// Make a constraint to avoid trade routes.
	extern int(*const rmCreateTradeRouteDistanceConstraint)(string name, float minDistance);

	// Add specified constraint to an area.
	extern bool(*const rmAddAreaConstraint)(int areaID, int constraintID);

	// Create home city gather point constraint to avoid all HCGPs.
	extern bool(*const rmCreateHCGPConstraint)(string name, float minDistance);

	// Create home city gather point constraint to avoid given player's HCGP.
	extern bool(*const rmCreateHCGPSelfConstraint)(string name, int playerID, float minDistance);

	// Create home city gather point constraint to avoid given player's ally's HCGPs.
	extern bool(*const rmCreateHCGPAllyConstraint)(string name, int playerID, float minDistance);

	// Create home city gather point constraint to avoid given player's enemy's HCGPs.
	extern bool(*const rmCreateHCGPEnemyConstraint)(string name, int playerID, float minDistance);

	// Make an max height constraint (terrain must be less than given height).
	extern int(*const rmCreateMaxHeightConstraint)(string name, float height);

	// Add specified constraint to a fairLoc placement.
	extern bool(*const rmAddFairLocConstraint)(int fairLocID, int constraintID);

	// Add specified constraint to given object def.
	extern bool(*const rmAddObjectDefConstraint)(int defID, int constraintID);

	// Define a class with the given name.
	extern int(*const rmDefineClass)(string className);

	// Add given area to specified class.
	extern bool(*const rmAddAreaToClass)(int areaID, int classID);

	// Add given object def to specified class.
	extern bool(*const rmAddObjectDefToClass)(int objectDefID, int classID);

	// Gets class ID for given class name.
	extern int(*const rmClassID)(string name);

	// Gets constraint ID for given constraint name.
	extern int(*const rmConstraintID)(string name);

	// Creates an object definition.
	extern int(*const rmCreateObjectDef)(string name);

	// Creates special object definition for starting units with the given cluster distance.
	extern int(*const rmCreateStartingUnitsObjectDef)(float clusterDistance);

	// Set the minimum distance for the object definition (in meters).
	extern bool(*const rmSetObjectDefMinDistance)(int defID, float dist);

	// Set the maximum distance for the object definition (in meters).
	extern bool(*const rmSetObjectDefMaxDistance)(int defID, float dist);

	// Turn on the garrison secondary units flag.
	extern bool(*const rmSetObjectDefGarrisonSecondaryUnits)(int defID, bool on);

	// Turn on the garrison starting units flag.
	extern bool(*const rmSetObjectDefGarrisonStartingUnits)(int defID, bool on);

	// Creates a herd out of all units placed in this object def.
	extern bool(*const rmSetObjectDefCreateHerd)(int defID, bool on);

	// Set a herd angle(clockwise from +z) in the object def.
	extern bool(*const rmSetObjectDefHerdAngle)(int defID, float angle);

	// Lets objects overlap within this object def.
	extern bool(*const rmSetObjectDefAllowOverlap)(int defID, bool on);

	// Forces things in this object def to get full arbitrary rotation.
	extern bool(*const rmSetObjectDefForceFullRotation)(int defID, bool on);

	// Add item to object definition.
	extern bool(*const rmAddObjectDefItem)(int defID, string unitName, int count, float clusterDistance);

	// Add item to object definition.
	extern bool(*const rmAddObjectDefItemByTypeID)(int defID, int unitTypeID, int count, float clusterDistance);

	// Place object definition at specific location for given player.
	extern int(*const rmPlaceObjectDefAtLoc)(int defID, int playerID, float xFraction, float zFraction, int placeCount);

	// Place object definition at specific point for given player.
	extern int(*const rmPlaceObjectDefAtPoint)(int defID, int playerID, vector point, int placeCount);

	// Set the trade route for all objects in this object definition.
	extern int(*const rmSetObjectDefTradeRouteID)(int defID, int tradeRouteID);

	// Place object definition per player.
	extern int(*const rmPlaceObjectDefPerPlayer)(int defID, bool playerOwned, int placeCount);

	// Place object definition for the player at the given area's location.
	extern int(*const rmPlaceObjectDefAtAreaLoc)(int defID, int playerID, int areaID, int placeCount);

	// Place object definition for the player in the given area.
	extern int(*const rmPlaceObjectDefInArea)(int defID, int playerID, int areaID, int placeCount);

	// Place object definition for the player at the location of a random area in the given class.
	extern int(*const rmPlaceObjectDefAtRandomAreaOfClass)(int defID, int playerID, int classID, int placeCount);

	// Place object definition for the player in a random area in the given class.
	extern int(*const rmPlaceObjectDefInRandomAreaOfClass)(int defID, int playerID, int classID, int placeCount);

	// Creates an connection.
	extern int(*const rmCreateConnection)(string name);

	// Sets the connection type.
	extern int(*const rmSetConnectionType)(int connectionID, int connectionType, bool connectAll, float connectPercentage);

	// Adds an area to the connection.
	extern bool(*const rmAddConnectionArea)(int connectionID, int areaID);

	// Sets the position variance of a connection.
	extern bool(*const rmSetConnectionPositionVariance)(int connectionID, float variance);

	// Sets the width of a connection.
	extern bool(*const rmSetConnectionWidth)(int connectionID, float width, float variance);

	// Sets the base height of a connection.
	extern bool(*const rmSetConnectionBaseHeight)(int connectionID, float width);

	// Sets area coherence (0-1).
	extern bool(*const rmSetConnectionCoherence)(int connectionID, float width);

	// Sets whether a connection warns on failure.
	extern bool(*const rmSetConnectionWarnFailure)(int connectionID, bool warn);

	// Sets how smoothly connection height blends into surroundings.
	extern bool(*const rmSetConnectionHeightBlend)(int connectionID, int width);

	// Sets connection edge smoothing distance (distance is number of neighboring points to consider in each direction).
	extern bool(*const rmSetConnectionSmoothDistance)(int connectionID, int width);

	// Adds a terrain replacement rule to the connection.
	extern bool(*const rmAddConnectionTerrainReplacement)(int connectionID, string terrainTypeName, string newTypeName);

	// Sets the terrain cost for a connection.
	extern bool(*const rmSetConnectionTerrainCost)(int connectionID, string terrainTypeName, float cost);

	// Sets the base terrain cost for a connection.
	extern bool(*const rmSetConnectionBaseTerrainCost)(int connectionID, float cost);

	// Builds the given connection.
	extern bool(*const rmBuildConnection)(int connectionID);

	// Adds the connection to specified class.
	extern bool(*const rmAddConnectionToClass)(int connectionID, int classID);

	// Add specified constraint to a connection.
	extern bool(*const rmAddConnectionConstraint)(int connectionID, int constraintID);

	// Add specified constraint for a connection start point.
	extern bool(*const rmAddConnectionStartConstraint)(int connectionID, int constraintID);

	// Add specified constraint for a connection end point.
	extern bool(*const rmAddConnectionEndConstraint)(int connectionID, int constraintID);

	// Sets the friendly cool loading screen text.
	extern void(*const rmSetStatusText)(string status, float progress);

	// Returns the square root of x.
	extern float(*const sqrt)(float x);

	extern void(*const rmSetVPFile)(string filename);

	extern int(*const rmCreateTrigger)(string triggerName);

	extern bool(*const rmSwitchToTrigger)(int triggerID);

	extern int(*const rmTriggerID)(string triggerName);

	extern int(*const rmSetTriggerPriority)(int priority);

	extern int(*const rmSetTriggerActive)(bool active);

	extern int(*const rmSetTriggerRunImmediately)(bool runImmediately);

	extern int(*const rmSetTriggerLoop)(bool loop);

	extern int(*const rmAddTriggerCondition)(string conditionType);

	extern bool(*const rmSetTriggerConditionParam)(string paramName, string value, bool add);

	extern bool(*const rmSetTriggerConditionParamInt)(string paramName, int value, bool add);

	extern bool(*const rmSetTriggerConditionParamFloat)(string paramName, float value, bool add);

	extern bool(*const rmSetTriggerConditionParamArmy)(string paramName, int playerID, int armyID, bool add);

	extern bool(*const rmAddTriggerEffect)(string effectType);

	extern int(*const rmSetTriggerEffectParam)(string paramName, string value, bool add);

	extern bool(*const rmSetTriggerEffectParamInt)(string paramName, int value, bool add);

	extern bool(*const rmSetTriggerEffectParamFloat)(string paramName, float value, bool add);

	extern bool(*const rmSetTriggerEffectParamArmy)(string paramName, int playerID, int armyID, bool add);

	extern int(*const rmCreateArmy)(int playerID, string armyName);

	extern bool(*const rmAddUnitsToArmy)(int playerID, int armyID, int objectDefID);

	extern int(*const rmGetNumberUnitsPlaced)(int objectDefID);

	extern int(*const rmGetUnitPlaced)(int objectDefID, int index);

	extern int(*const rmGetUnitPlacedOfPlayer)(int objectDefID, int playerID);

	extern bool(*const rmDefineConstant)(string name, int value);

	extern void(*const rmSetIgnoreForceToGaia)(bool val);

	// Creates a grouping.
	extern int(*const rmCreateGrouping)(string name, string filename);

	// Add specified constraint to a grouping.
	extern bool(*const rmAddGroupingConstraint)(int GroupingID, int constraintID);

	// Place grouping at specified location.
	extern int(*const rmPlaceGroupingAtLoc)(int groupingID, int playerID, float xFraction, float zFraction, int placeCount);

	// Place grouping at specified point.
	extern int(*const rmPlaceGroupingAtPoint)(int groupingID, int playerID, vector point, int placeCount);

	// Place grouping for the player in the given area.
	extern int(*const rmPlaceGroupingInArea)(int groupingID, int playerID, int areaID, int placeCount);

	// Set the minimum distance for the grouping (in meters).
	extern bool(*const rmSetGroupingMinDistance)(int defID, float dist);

	// Set the maximum distance for the grouping (in meters).
	extern bool(*const rmSetGroupingMaxDistance)(int defID, float dist);

	// Add given grouping to specified class.
	extern bool(*const rmAddGroupingToClass)(int GroupingID, int classID);

	// Creates a trade route.
	extern int(*const rmCreateTradeRoute)();

	// Adds the given waypoint to the specified trade route.
	extern bool(*const rmAddTradeRouteWaypoint)(int tradeRouteID, float xFraction, float zFraction);

	// Adds the given waypoint to the specified trade route.
	extern bool(*const rmAddTradeRouteWaypointVector)(int tradeRouteID, vector v);

	// Adds random waypoints to the specified trade route.
	extern bool(*const rmAddRandomTradeRouteWaypoints)(int tradeRouteID, float endXFraction, float endZFraction, int count, float maxVariation);

	// Adds random waypoints to the specified trade route.
	extern bool(*const rmAddRandomTradeRouteWaypointsVector)(int tradeRouteID, vector v, int count, float maxVariation);

	// Creates a trade route in the specified area.
	extern bool(*const rmCreateTradeRouteWaypointsInArea)(int tradeRouteID, int areaID, float length);

	// Retrieves a waypoint along the trade route based on the fraction.
	extern vector(*const rmGetTradeRouteWayPoint)(vector result, int tradeRouteID, float fraction);

	// Builds the trade route with the given terrain type.
	extern bool(*const rmBuildTradeRoute)(int tradeRouteID, string terrainTypeName);

	// Sets the HCGP for the given player.
	extern bool(*const rmSetHomeCityGatherPoint)(int playerID, vector point);

	// Sets the HCWSP for the given player.
	extern bool(*const rmSetHomeCityWaterSpawnPoint)(int playerID, vector point);

	// Returns the lowest HC Level of the players in the game.
	extern int(*const rmGetLowHomeCityLevel)();

	// Returns the average (rounded down) HC Level of the players in the game.
	extern int(*const rmGetAverageHomeCityLevel)();

	// Returns the highest HC Level of the players in the game.
	extern int(*const rmGetHighHomeCityLevel)();

	// Returns the HC Level of the given player.
	extern int(*const rmGetHomeCityLevel)(int playerID);

	// Returns the position of the unit.
	extern vector(*const rmGetUnitPosition)(vector result, int unitID);

	// Indicates that this map is of a certain type (it can be multiple types simultaneously.
	extern void(*const rmSetMapType)(string type);

	// Returns true if the map belongs to the given type.
	extern bool(*const rmIsMapType)(string type);

	// Adds constraint to closest point finder.
	extern bool(*const rmAddClosestPointConstraint)(int constraintID);

	// Clears constraints for closest point finder.
	extern void(*const rmClearClosestPointConstraints)();

	// Finds closest point satisfying the preset constraints.
	extern vector(*const rmFindClosestPoint)(vector result, float xFraction, float zFraction, float maxDistance);

	// Finds closest point satisfying the preset constraints.
	extern vector(*const rmFindClosestPointVector)(vector result, vector a, float b);

	// Returns which area is closer.
	extern int(*const rmFindCloserArea)(float xFraction, float zFraction, int area1, int area2);

	// Adds the given waypoint to the specified cliff area (for valleys).
	extern bool(*const rmAddAreaCliffWaypoint)(int areaID, float xFraction, float zFraction);

	// Adds random waypoints to the specified cliff valley area.
	extern bool(*const rmAddAreaCliffRandomWaypoints)(int areaID, float endXFraction, float endZFraction, int count, float maxVariation);

	// Sets the min/max difficulty levels for placing nuggets.
	extern void(*const rmSetNuggetDifficulty)(int minLevel, int maxLevel);

	// Sets whether or not to reveal oceans.
	extern void(*const rmSetOceanReveal)(bool a);

	// Sets the handler for given type of event.
	extern bool(*const hcSetXSHandler)(string handlerFunctionName, int type);

	// Sets the handler for a unit for a given type of event.
	extern bool(*const hcSetUnitXSHandler)(int unitID, string handlerFunctionName, int type);

	// Returns a random number (mod'ed by max if provided).
	extern int(*const hcRandInt)(int max);

	// Returns a random position guaranteed to be on the map.
	extern vector(*const hcRandPosition)(vector result);

	// Returns the HomeCity Unit ID for this unit.
	extern int(*const hcGetMyUnitID)();

	// Returns the HomeCity group ID for this unit.
	extern int(*const hcUnitGetGroupID)(int unitID);

	// Returns the position of the unit.
	extern vector(*const hcUnitGetPosition)(vector result, int unitID);

	// Returns the action type of the unit.
	extern int(*const hcUnitGetActionType)(int unitID);

	// Makes the unit go into idle mode forever.
	extern bool(*const hcUnitGoIdle)(int unitID, bool queue);

	// Returns the script for the unit.
	extern string(*const hcUnitGetScript)(int unitID);

	// Returns the number of unlocked units available.
	extern int(*const hcGetNumUnlockedUnits)(bool regularUnits, bool performerUnits);

	// Returns the proto unit ID for an unlocked unit.
	extern int(*const hcGetUnlockedUnitProtoUnitID)(int unitIndex, bool regularUnits, bool performerUnits);

	// Returns the visual file name for an unlocked unit.
	extern string(*const hcGetUnlockedUnitVisualFilename)(int unitIndex, bool regularUnits, bool performerUnits);

	// Returns the script file name for an unlocked unit.
	extern string(*const hcGetUnlockedUnitScriptFilename)(int unitIndex, bool regularUnits, bool performerUnits);

	// Returns the performance position for a unit.
	extern vector(*const hcUnitGetPerformPosFromGroup)(vector result, int groupID, int unitID);

	// Returns the performance forward vector for a unit.
	extern vector(*const hcUnitGetPerformForwardFromGroup)(vector result, int groupID, int unitID);

	// Creates a unit; specify either protoUnitID or visualFilename; returns the new unit's ID.
	extern int(*const hcUnitCreateUsingPos)(int protoUnitID, string visualFilename, string aiFilename, vector position, vector forward, bool visible);

	// Creates a unit; specify either protoUnitID or visualFilename; returns the new unit's ID.
	extern int(*const hcUnitCreate)(int protoUnitID, string visualFilename, string aiFilename, int waypoint);

	// Creates a unit at the bone position; specify either protoUnitID or visualFilename; returns the new unit's ID.
	extern int(*const hcUnitCreateAtBone)(int protoUnitID, string visualFilename, string aiFilename, string boneName);

	// Populates the home city with all units needed.
	extern void(*const hcPopulateHomeCity)();

	// Gets the initial time a unit should pause before spawning.
	extern float(*const hcUnitGetInitialPauseTime)(int unitID);

	// Sets the initial time a unit should pause before spawning.
	extern void(*const hcUnitSetInitialPauseTime)(int unitID, float pauseTime);

	// Enables / disables a unit's flag.
	extern bool(*const hcUnitSetFlag)(int unitID, int unitFlag, bool enable, bool queue);

	// Creates a performer group.
	extern int(*const hcCreatePerformerGroup)(int numPerformers, float attentionRadius);

	// Reserves a performer area.
	extern bool(*const hcReservePerformerArea)(int groupID);

	// Returns how many performer groups are currently playing.
	extern int(*const hcGetNumPerformerGroups)();

	// Adds a unit to a group of performers.
	extern void(*const hcAddUnitToPerformerGroup)(int groupID, int unitID);

	// Exits the unit (this will kill the unit).
	extern bool(*const hcUnitExit)(int unitID, bool queue);

	// Nukes all HC units.
	extern void(*const hcUnitDestroyAll)();

	// Plays the anim for the unit.
	extern bool(*const hcUnitPlayAnim)(int unitID, string animation, float seconds, int loop, bool queue);

	// Walks the unit to the WPID.
	extern bool(*const hcUnitMoveToWPID)(int unitID, int startWPID, int goalWPID, float speed, float goalTolerance, bool queue);

	// Walks the unit to the position.
	extern bool(*const hcUnitMoveToPos)(int unitID, int startWPID, vector BVector, float goalPos, float speed, bool goalTolerance);

	// Turns the unit towards the forward vector.
	extern bool(*const hcUnitTurn)(int unitID, vector BVector, float forward, bool turnRateInDegreesPerSec);

	// Moves the unit to the given waypoint immediately.
	extern bool(*const hcUnitTeleportToWPID)(int unitID, int WPID);

	// Unit follows another unit.
	extern bool(*const hcUnitFollow)(int unitID, int unitToFollowID, float speed, bool queue);

	// Unit exits a building.
	extern bool(*const hcUnitExitBuilding)(int unitID, int buildingID, float pauseTime, float speed, bool queue);

	// Unit enters a building.
	extern bool(*const hcUnitEnterBuilding)(int unitID, int buildingID, float speed, bool queue);

	// Makes unit visible/invisible.
	extern bool(*const hcUnitSetVisible)(int unitID, bool state, bool queue);

	// Makes script wait a number of seconds
	extern bool(*const hcUnitWait)(int unitID, float pauseTime, bool queue);

	// Frees the given waypoint.
	extern void(*const hcUnitFreeWPID)(int unitID, int wpid, bool queue);

	// Occupies the given waypoint.
	extern void(*const hcOccupyWPID)(int wpid);

	// Returns the number of units with a given AI filename.
	extern int(*const hcGetNumberUnitsWithAI)(string aiFilename);

	// Returns the index-th unit with the given AI filename.
	extern int(*const hcGetUnitWithAI)(string aiFilename, int index);

	// Returns the index-th performer unit in the proximity.
	extern int(*const hcGetPerformerInProximity)(int unitID);

	// Returns the number of waypoints.
	extern int(*const hcGetNumberWaypoints)();

	// Returns the position for a waypoint.
	extern vector(*const hcGetWaypointPos)(vector result, int waypoint);

	// Returns the direction for a waypoint.
	extern vector(*const hcGetWaypointDir)(vector result, int waypoint);

	// Returns the WPID closest to the position.
	extern int(*const hcGetNearestWPID)(vector position);

	// Returns the WPID of a random waypoint.
	extern int(*const hcGetRandomWPID)(int waypointMask);

	// Returns the WPID of a random waypoint.
	extern int(*const hcGetRandomFreeWPID)(int waypointMask);

	// Returns the ID for a building with the specified name.
	extern int(*const hcGetBuildingIDByName)(string buildingName);

	// CP AI echo.
	extern void(*const aiEcho)(string echoString);

	// CP AI error.
	extern void(*const aiErrorMessage)(string errorString);

	// Sets the seed of the random number generator.
	extern void(*const aiRandSetSeed)(int seed);

	// Returns a random number (mod'ed by max if provided).
	extern int(*const aiRandInt)(int max);

	// Returns a random location guaranteed to be on the map.
	extern vector(*const aiRandLocation)(vector result);

	// Sets playerID's AI to the given filename.
	extern void(*const aiSet)(string filename, int playerID);

	// Sets a breakpoint.
	extern void(*const aiBreakpointSet)(int a, string b, int c, bool d);

	// Restart XS execution after the current breakpoint.
	extern void(*const aiBreakpointGo)(int a);

	// Gets the player's personality.
	extern string(*const aiGetPersonality)();

	// Returns the rush boom scale for this ai.
	extern float(*const aiPersonalityGetRushBoom)();

	// Returns the number of player's in the Personality's history.
	extern int(*const aiPersonalityGetNumberPlayerHistories)();

	// Creates are player history for the given playername.
	extern int(*const aiPersonalityCreatePlayerHistory)(string a);

	// Resets the given player history.
	extern bool(*const aiPersonalityResetPlayerHistory)(int playerHistoryIndex);

	// Returns the name of the index'th player in the Personality's history.
	extern string(*const aiPersonalityGetPlayerHistoryName)(int index);

	// Returns a playerHistoryIndex if this personality has played searchPlayerName before.
	extern int(*const aiPersonalityGetPlayerHistoryIndex)(string searchPlayerName);

	// Returns the user value, given the playerHistoryIndex and the userVarName.
	extern float(*const aiPersonalityGetPlayerUserVar)(int playerHistoryIndex, string userVarName);

	// sets the value, given the playerHistoryIndex, userVarName (max 255 chars), and value.
	extern bool(*const aiPersonalitySetPlayerUserVar)(int playerHistoryIndex, string userVarName, float val);

	// Returns the number of games played against/with the given the playerHistoryIndex.
	extern int(*const aiPersonalityGetPlayerGamesPlayed)(int playerHistoryIndex, int playerRelation);

	// Returns the given resource from the gameIndex game. If gameIndex is -1, this will return the avg of all games played.
	extern float(*const aiPersonalityGetGameResource)(int playerHistoryIndex, int gameIndex, int resourceID);

	extern bool(*const aiPersonalityGetDidIWinLastGameVS)(int playerHistoryIndex);

	// Returns the unit count from the gameIndex game. If gameIndex is -1, this will return the avg of all games played.
	extern int(*const aiPersonalityGetGameUnitCount)(int playerHistoryIndex, int gameIndex, int unitType);

	// Returns the 1st attacktime from the gameIndex game.
	extern int(*const aiPersonalityGetGameFirstAttackTime)(int playerHistoryIndex, int gameIndex);

	// Returns the total games the given player has won against this AI
	extern int(*const aiPersonalityGetTotalGameWins)(int playerHistoryIndex, int playerRelation);

	// Returns the script-defined most hated player ID for this player.
	extern int(*const aiGetMostHatedPlayerID)();

	// Returns the playerID for the player the AI thinks it should be attacking.
	extern int(*const aiCalculateMostHatedPlayerID)(int comparePlayerID);

	// Sets the script-defined most hated player ID for this player.
	extern void(*const aiSetMostHatedPlayerID)(int v);

	// Returns the available economy pop for this player.
	extern int(*const aiGetAvailableEconomyPop)();

	// Returns the current economy pop for this player.
	extern int(*const aiGetCurrentEconomyPop)();

	// Returns the script-defined economy pop for this player.
	extern int(*const aiGetEconomyPop)();

	// Set the script-defined economy pop for this player.
	extern void(*const aiSetEconomyPop)(int v);

	// Returns the script-defined military pop for this player.
	extern int(*const aiGetAvailableMilitaryPop)();

	// Returns the script-defined military pop for this player.
	extern int(*const aiGetMilitaryPop)();

	// Set the script-defined military pop for this player.
	extern void(*const aiSetMilitaryPop)(int v);

	// Returns the economy priority percentage.
	extern float(*const aiGetEconomyPercentage)();

	// Set the economy priority percentage.
	extern void(*const aiSetEconomyPercentage)(float v);

	// Returns the militarypriority percentage.
	extern float(*const aiGetMilitaryPercentage)();

	// Set the military priority percentage.
	extern void(*const aiSetMilitaryPercentage)(float v);

	// Returns the attack response distance.
	extern float(*const aiGetAttackResponseDistance)();

	// Set the attack response distance.
	extern void(*const aiSetAttackResponseDistance)(float v);

	// Returns the number of matching goals.
	extern int(*const aiGoalGetNumber)(int goalType, int goalState, bool active);

	// Returns the ID of matching goal.
	extern int(*const aiGoalGetIDByIndex)(int goalType, int goalState, bool active, int index);

	// Returns the number of matching plans.
	extern int(*const aiPlanGetNumber)(int planType, int planState, bool active);

	// Returns the ID of matching plan.
	extern int(*const aiPlanGetIDByIndex)(int planType, int planState, bool active, int index);

	// Creates a plan of the given name and type.
	extern int(*const aiPlanCreate)(string planName, int typeName);

	// Destroys the given plan.
	extern bool(*const aiPlanDestroy)(int planID);

	// Destroys the plan of the given name.
	extern bool(*const aiPlanDestroyByName)(string name);

	// Returns the ID of the plan with the given name.
	extern int(*const aiPlanGetID)(string name);

	// Returns the ID of the first plan containing the given string in its name.
	extern int(*const aiPlanGetIDSubStr)(string searchStr);

	// Returns the ID of the plan with the given parms.
	extern int(*const aiPlanGetIDByTypeAndVariableType)(int planType, int varType, int varID, bool active);

	// Returns the ID of the plan with the given active index.
	extern int(*const aiPlanGetIDByActiveIndex)(int activeIndex);

	// Returns the name of the given plan.
	extern string(*const aiPlanGetName)(int planID);

	// Returns the type of the given plan.
	extern int(*const aiPlanGetType)(int planID);

	// Returns the state of the given plan.
	extern int(*const aiPlanGetState)(int planID);

	// Returns the priority of the given plan.
	extern int(*const aiPlanGetActualPriority)(int planID);

	// Returns the priority of the given plan.
	extern int(*const aiPlanGetDesiredPriority)(int planID);

	// Sets the priority of the given plan.
	extern bool(*const aiPlanSetDesiredPriority)(int planID, int priority);

	// Adds a unit type to the plan.
	extern bool(*const aiPlanAddUnitType)(int planID, int unitTypeID, int numberNeed, int numberWant, int numberMax);

	// Returns the number of units currently assigned in the given plan.
	extern int(*const aiPlanGetNumberUnits)(int planID, int unitTypeID);

	// Adds a unit to the plan.
	extern bool(*const aiPlanAddUnit)(int planID, int unitID);

	// Returns the location for this plan.
	extern vector(*const aiPlanGetLocation)(vector result, int planID);

	// Returns the initial positon that was set for this plan.
	extern vector(*const aiPlanGetInitialPosition)(vector result, int planID);

	// Sets the initial positon for this plan.
	extern void(*const aiPlanSetInitialPosition)(int planID, vector initialPosition);

	// Sets the waypoints of the given plan to the waypoints of the given path.
	extern bool(*const aiPlanSetWaypoints)(int planID, int pathID);

	// Adds the waypoint to the given plan.
	extern bool(*const aiPlanAddWaypoint)(int planID, vector waypoint);

	// Returns the number of values for this variable index.
	extern int(*const aiPlanGetNumberVariableValues)(int planID, int planVariableIndex);

	// Sets the number of values for this variable.
	extern bool(*const aiPlanSetNumberVariableValues)(int planID, int planVariableIndex, int numberValues, bool clearCurrentValues);

	// Removes the index-th value of the variable.
	extern bool(*const aiPlanRemoveVariableValue)(int planID, int planVariableIndex, int variableIndex);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetVariableInt)(int planID, int planVariableIndex, int valueIndex, int value);

	// Gets the given variable of the given plan.
	extern int(*const aiPlanGetVariableInt)(int planID, int planVariableIndex, int valueIndex);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetVariableFloat)(int planID, int planVariableIndex, int valueIndex, float value);

	// Gets the given variable of the given plan.
	extern float(*const aiPlanGetVariableFloat)(int planID, int planVariableIndex, int valueIndex);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetVariableVector)(int planID, int planVariableIndex, int valueIndex, vector value);

	// Gets the given variable of the given plan.
	extern vector(*const aiPlanGetVariableVector)(vector result, int planID, int planVariableIndex, int valueIndex);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetVariableBool)(int planID, int planVariableIndex, int valueIndex, bool value);

	// Gets the given variable of the given plan.
	extern bool(*const aiPlanGetVariableBool)(int planID, int planVariableIndex, int valueIndex);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetVariableString)(int planID, int planVariableIndex, int valueIndex, string value);

	// Gets the given variable of the given plan.
	extern string(*const aiPlanGetVariableString)(int planID, int planVariableIndex);

	// Returns the number of values for this variable index.
	extern int(*const aiPlanGetNumberUserVariableValues)(int planID, int planVariableIndex);

	// Sets the number of values for this variable.
	extern bool(*const aiPlanSetNumberUserVariableValues)(int planID, int planVariableIndex, int numberValues, bool clearCurrentValues);

	// Removes all of the user variables from the given plan.
	extern bool(*const aiPlanRemoveUserVariables)(int planID);

	// Removes the user variable.
	extern bool(*const aiPlanRemoveUserVariable)(int planID, int planVariableIndex);

	// Removes the index-th value of the user variable.
	extern bool(*const aiPlanRemoveUserVariableValue)(int planID, int planVariableIndex, int variableIndex);

	// Adds the variable to the given plan.
	extern bool(*const aiPlanAddUserVariableInt)(int planID, int planVariableIndex, string name, int numberValues);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetUserVariableInt)(int planID, int planVariableIndex, int valueIndex, int value);

	// Gets the given variable of the given plan.
	extern int(*const aiPlanGetUserVariableInt)(int planID, int planVariableIndex, int valueIndex);

	// Adds the variable to the given plan.
	extern bool(*const aiPlanAddUserVariableFloat)(int planID, int planVariableIndex, string name, int numberValues);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetUserVariableFloat)(int planID, int planVariableIndex, int valueIndex, float value);

	// Gets the given variable of the given plan.
	extern float(*const aiPlanGetUserVariableFloat)(int planID, int planVariableIndex, int valueIndex);

	// Adds the variable to the given plan.
	extern bool(*const aiPlanAddUserVariableVector)(int planID, int planVariableIndex, string name, int numberValues);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetUserVariableVector)(int planID, int planVariableIndex, int valueIndex, vector value);

	// Gets the given variable of the given plan.
	extern vector(*const aiPlanGetUserVariableVector)(vector result, int planID, int planVariableIndex, int valueIndex);

	// Adds the variable to the given plan.
	extern bool(*const aiPlanAddUserVariableBool)(int planID, int planVariableIndex, string name, int numberValues);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetUserVariableBool)(int planID, int planVariableIndex, int valueIndex, bool value);

	// Gets the given variable of the given plan.
	extern bool(*const aiPlanGetUserVariableBool)(int planID, int planVariableIndex, int valueIndex);

	// Adds the variable to the given plan.
	extern bool(*const aiPlanAddUserVariableString)(int planID, int planVariableIndex, string name, int numberValues);

	// Sets the given variable of the given plan.
	extern bool(*const aiPlanSetUserVariableString)(int planID, int planVariableIndex, int valueIndex, string value);

	// Gets the given variable of the given plan.
	extern string(*const aiPlanGetUserVariableString)(int planID, int planVariableIndex, int valueIndex);

	// Gets the active-ness of the given plan.
	extern bool(*const aiPlanGetActive)(int planID);

	// Sets active on/off for the given plan.
	extern bool(*const aiPlanSetActive)(int planID, bool active);

	// Gets the noMoreUnits-ness of the given plan.
	extern bool(*const aiPlanGetNoMoreUnits)(int planID);

	// Sets noMoreUnits on/off for the given plan.
	extern bool(*const aiPlanSetNoMoreUnits)(int planID, bool v);

	// Gets the orphan-ness of the given plan.
	extern bool(*const aiPlanGetOrphan)(int planID);

	// Sets orphan on/off for the given plan.
	extern bool(*const aiPlanSetOrphan)(int planID, bool orphan);

	// Gets the UA response-ness of the given plan.
	extern bool(*const aiPlanGetAllowUnderAttackResponse)(int planID);

	// Sets under attack response on/off for the given plan.
	extern bool(*const aiPlanSetAllowUnderAttackResponse)(int planID, bool uAR);

	// Gets the unit stance of the given plan.
	extern int(*const aiPlanGetUnitStance)(int planID);

	// Sets unit stance for the given plan.
	extern bool(*const aiPlanSetUnitStance)(int planID, int stance);

	// Sets 'requiresAllNeedUnits' on/off for the given plan.
	extern bool(*const aiPlanSetRequiresAllNeedUnits)(int planID, bool rANU);

	// Sets event handler function for the given plan and event.
	extern bool(*const aiPlanSetEventHandler)(int planID, int eventType, string handlerName);

	// Sets the escrow for the plan.
	extern bool(*const aiPlanSetEscrowID)(int planID, int escrowID);

	// Gets the escrow for the plan.
	extern int(*const aiPlanGetEscrowID)(int planID);

	// Gets the economy flag of the given plan.
	extern bool(*const aiPlanGetEconomy)(int planID);

	// Sets economy on/off for the given plan.
	extern bool(*const aiPlanSetEconomy)(int planID, bool v);

	// Gets the military flag of the given plan.
	extern bool(*const aiPlanGetMilitary)(int planID);

	// Sets military on/off for the given plan.
	extern bool(*const aiPlanSetMilitary)(int planID, bool v);

	// Gets the attack flag of the given plan.
	extern bool(*const aiPlanGetAttack)(int planID);

	// Sets attack flag on/off for the given plan.
	extern bool(*const aiPlanSetAttack)(int planID, bool v);

	// sets the plan's base id.
	extern bool(*const aiPlanSetBaseID)(int planID, int baseID);

	// gets the plan's base id.
	extern int(*const aiPlanGetBaseID)(int planID);

	// Gets the of idle plans of the given type.
	extern int(*const aiGetNumberIdlePlans)(int planType);

	// gets total aiCost of plan's units, weighted for HP if requested.
	extern float(*const aiPlanGetUnitCost)(int planID, bool considerHitPoints);

	// enables or disables the chats from this ai player.
	extern void(*const aiCommsAllowChat)(bool flag);

	// Sends a statement to the designated player.
	extern int(*const aiCommsSendStatement)(int targetPlayerID, int promptType);

	// Sends a statement to the designated player. Adds a location flare.
	extern int(*const aiCommsSendStatementWithVector)(int targetPlayerID, int promptType, vector v);

	// Sets the handler for the communications system (invalid name unsets the handler).
	extern bool(*const aiCommsSetEventHandler)(string handlerFunctionName);

	// get sending player for specified sentence.
	extern int(*const aiCommsGetSendingPlayer)(int sentenceID);

	// get chat verb for specified sentence.
	extern int(*const aiCommsGetChatVerb)(int sentenceID);

	// get target type for specified sentence.
	extern int(*const aiCommsGetChatTargetType)(int sentenceID);

	// get number of items in target list for specified sentence.
	extern int(*const aiCommsGetTargetListCount)(int sentenceID);

	// get index item from specified sentence.
	extern int(*const aiCommsGetTargetListItem)(int sentenceID, int index);

	// get target location from specified sentence.
	extern vector(*const aiCommsGetTargetLocation)(vector result, int sentenceID);

	// send a reply to a sentence.
	extern void(*const aiCommsSendReply)(int sentenceID, int responseID);

	// Sets the handler for given type of event.
	extern bool(*const aiSetHandler)(string handlerFunctionName, int type);

	// Does a lightweight (no plan) move tasking of the given unit to the given location.
	extern bool(*const aiTaskUnitMove)(int unitID, vector position);

	// Does a lightweight (no plan) work tasking of the given unit on the given target unit.
	extern bool(*const aiTaskUnitWork)(int unitID, int targetUnitID);

	// Does a lightweight (no plan) build tasking of the given unit to build the given building.
	extern bool(*const aiTaskUnitBuild)(int unitID, int buildingTypeID, vector position);

	// Does a lightweight (no plan) train tasking of the given unit for the given target unit type.
	extern bool(*const aiTaskUnitTrain)(int unitID, int unitTypeID);

	// Does a lightweight (no plan) research tasking of the given unit for the given tech ID.
	extern bool(*const aiTaskUnitResearch)(int unitID, int techID);

	// Deletes the given unit.
	extern bool(*const aiTaskUnitDelete)(int unitID);

	// Tributes the given player.
	extern bool(*const aiTribute)(int playerID, int resourceID, float amount);

	// sells (+100) the given resource.
	extern bool(*const aiSellResourceOnMarket)(int resourceID);

	// buys (+100) the given resource.
	extern bool(*const aiBuyResourceOnMarket)(int resourceID);

	// Returns the amount required to buy 100 units of the given resource.
	extern float(*const aiGetMarketBuyCost)(int resourceID);

	// Returns the amount received for selling 100 units of the given resource.
	extern float(*const aiGetMarketSellCost)(int resourceID);

	// Returns the RGP weight.
	extern float(*const aiGetResourceGathererPercentageWeight)(int rgpIndex);

	// Sets the RGP weight.
	extern void(*const aiSetResourceGathererPercentageWeight)(int rgpIndex, float weight);

	// Normalizes all of the resource gatherer percentages weights to 1.0.
	extern void(*const aiNormalizeResourceGathererPercentageWeights)();

	// Returns the resource gatherer percentage for the given resource.
	extern float(*const aiGetResourceGathererPercentage)(int resourceID, int rgpIndex);

	// Sets the resource gatherer percentage for the given resource (if normalized is true, the percentages will be normalized to 1.0).
	extern void(*const aiSetResourceGathererPercentage)(int resourceID, float value, bool normalize, int rgpIndex);

	// Normalizes all of the resource gatherer percentages to 1.0.
	extern void(*const aiNormalizeResourceGathererPercentages)(int rgpIndex);

	// Gets the number of plans for the given breakdown.
	extern int(*const aiGetResourceBreakdownNumberPlans)(int resourceTypeID, int resourceSubTypeID, int baseID);

	// Gets the priority of the plans for the given breakdown.
	extern int(*const aiGetResourceBreakdownPlanPriority)(int resourceTypeID, int resourceSubTypeID, int baseID);

	// Gets the percentage for the given breakdown.
	extern float(*const aiGetResourceBreakdownPercentage)(int resourceTypeID, int resourceSubTypeID, int baseID);

	// Sets a subtype breakdown for a resource.
	extern bool(*const aiSetResourceBreakdown)(int resourceTypeID, int resourceSubTypeID, int numberPlans, int planPriority, float percentage, int baseID);

	// Removes the given breakdown.
	extern bool(*const aiRemoveResourceBreakdown)(int resourceTypeID, int resourceSubTypeID, int baseID);

	// Returns the auto gather escrow ID.
	extern int(*const aiGetAutoGatherEscrowID)();

	// Sets the auto gather escrow ID.
	extern void(*const aiSetAutoGatherEscrowID)(int escrowID);

	// Returns the auto Farm escrow ID.
	extern int(*const aiGetAutoFarmEscrowID)();

	// Sets the auto Farm escrow ID.
	extern void(*const aiSetAutoFarmEscrowID)(int escrowID);

	// Returns the per plan farm build limit.
	extern int(*const aiGetFarmLimit)();

	// Sets the per plan farm build limit.
	extern void(*const aiSetFarmLimit)(int limit);

	// Returns allow buildings on/off.
	extern bool(*const aiGetAllowBuildings)();

	// Sets allow buildings on/off.
	extern void(*const aiSetAllowBuildings)(bool v);

	// CP AI chat to playerID.
	extern void(*const aiChat)(int playerID, string chatString);

	// Returns the number of unassigned units of the given type.
	extern int(*const aiNumberUnassignedUnits)(int typeID);

	// Returns the number of unassigned units based on the goal's unit type(s).
	extern int(*const aiNumberUnassignedUnitsByGoal)(int goalID);

	// adds an opportunity to the list and returns the id.
	extern int(*const aiCreateOpportunity)(int type, int targettype, int targetID, int targetPlayerID, int source);

	// activates or deactivates an opportunity on the player's opp list.
	extern void(*const aiActivateOpportunity)(int opportunityID, bool flag);

	// remove an opportunity on the player's opp list.
	extern void(*const aiDestroyOpportunity)(int opportunityID);

	// finds the best currently scored opp.
	extern void(*const aiFindBestOpportunity)();

	// gets the source id from this opportunity
	extern int(*const aiGetOpportunitySourceID)(int opportunityID);

	// gets the source type from this opportunity
	extern int(*const aiGetOpportunitySourceType)(int opportunityID);

	// gets the radius from this opportunity
	extern float(*const aiGetOpportunityRadius)(float opportunityID);

	// gets the target playerID from this opportunity
	extern int(*const aiGetOpportunityTargetPlayerID)(int opportunityID);

	// gets the target type from this opportunity
	extern int(*const aiGetOpportunityTargetType)(int opportunityID);

	// gets the type from this opportunity
	extern int(*const aiGetOpportunityType)(int opportunityID);

	// gets the location from this opportunity
	extern vector(*const aiGetOpportunityLocation)(vector result, int opportunityID);

	// gets the target id from this opportunity
	extern int(*const aiGetOpportunityTargetID)(int opportunityID);

	// sets the target type for this opp.
	extern void(*const aiSetOpportunityTargetType)(int opportunityID, int targetType);

	// sets the target id for this opp.
	extern void(*const aiSetOpportunityTargetID)(int opportunityID, int targetType);

	// sets the radius for this opp.
	extern void(*const aiSetOpportunityRadius)(int opportunityID, float radius);

	// sets the location for this opp.
	extern void(*const aiSetOpportunityLocation)(int opportunityID, vector location);

	// sets the score for this opp.
	extern bool(*const aiSetOpportunityScore)(int oppID, int permission, float affordable, float classscore, float instance, float total);

	// Casts the given God power tech, at the specified position.
	extern bool(*const aiCastGodPowerAtPosition)(int godPowerTechID, vector pos);

	// Get the god power tech id from the given slot.
	extern int(*const aiGetGodPowerTechIDForSlot)(int slotID);

	// translate a granted tech id into a protopower id
	extern int(*const aiGetGodPowerProtoIDForTechID)(int techID);

	// get the type for a ProtoPower
	extern int(*const aiGetGodPowerType)(int protoPowerID);

	// find a valid god power plan to attach to an attack plan
	extern int(*const aiFindBestAttackGodPowerPlan)();

	// find a valid god power plan to use for town defense
	extern int(*const aiFindBestTownDefenseGodPowerPlan)();

	// Returns the world difficulty level.
	extern int(*const aiGetWorldDifficulty)();

	// Sets the world difficulty level.
	extern void(*const aiSetWorldDifficulty)(int v);

	// Returns the name of the level.
	extern string(*const aiGetWorldDifficultyName)(int level);

	// Returns the game's mode.
	extern int(*const aiGetGameMode)();

	// Returns the captain for the given player's team.
	extern int(*const aiGetCaptainPlayerID)(int playerID);

	// returns whether or not its cool to turn ai autosaves on.
	extern bool(*const aiGetAutosaveOn)();

	// returns the current resource need for the given resource.
	extern float(*const aiGetCurrentResourceNeed)(int resourceID);

	// Turns auto gathering of military units at bases on/off.
	extern bool(*const aiSetAutoGatherMilitaryUnits)(bool v);

	// sets the ai's Explore Danger Threshold value.
	extern bool(*const aiSetExploreDangerThreshold)(float value);

	// gets the ai's Explore Danger Threshold value.
	extern float(*const aiGetExploreDangerThreshold)();

	// Sets the RM bool in the AI.
	extern void(*const aiSetRandomMap)(bool v);

	// sets the pause all age upgrades flag in the AI.
	extern void(*const aiSetPauseAllAgeUpgrades)(bool v);

	// gets the pause all age upgrades flag from the AI.
	extern bool(*const aiGetPauseAllAgeUpgrades)(bool a);

	// sets the min number of units in an attack army.
	extern void(*const aiSetMinArmySize)(int v);

	// sets the min number of needed units to gather aggressive animals.
	extern void(*const aiSetMinNumberNeedForGatheringAggressvies)(int v);

	// gets the min number of needed units to gather aggressive animals.
	extern int(*const aiGetMinNumberNeedForGatheringAggressives)();

	// sets the min number of wanted units to gather aggressive animals.
	extern void(*const aiSetMinNumberWantForGatheringAggressives)(int v);

	// gets the min number of wanted units to gather aggressive animals.
	extern int(*const aiGetMinNumberWantForGatheringAggressives)();

	// reigns the current player..
	extern void(*const aiResign)();

	// asks the player if its ok to resign
	extern void(*const aiAttemptResign)(int a);

	// sets the limit for how many LOS Protounits the AI can build
	extern void(*const aiSetMaxLOSProtoUnitLimit)(int limit);

	// gets the limit for how many LOS Protounits the AI can build
	extern int(*const aiGetMaxLOSProtoUnitLimit)();

	// gets the current Pop needs of all the plans.
	extern int(*const aiGetPopNeeds)();

	// switch the newBaseID to be the main base.
	extern void(*const aiSwitchMainBase)(int newBaseID, bool force);

	// Sets your default stance for all of your units.
	extern void(*const aiSetDefaultStance)(int defaultStance);

	// Tells the AI if this is a water map or not.
	extern void(*const aiSetWaterMap)(bool v);

	// Tells us if the AI thinks this is a water map or not.
	extern bool(*const aiGetWaterMap)();

	// Is this a certain maptype or not. (AIFishingUseful, AITransportRequired, AITransportUseful)
	extern bool(*const aiIsMapType)(string mapType);

	// Returns the number of cards in the Current HC.
	extern int(*const aiHCCardsGetTotal)();

	// Has the cardindex been bought yet?
	extern bool(*const aiHCCardsIsCardBought)(int cardIndex);

	// Can I buy this card now?
	extern bool(*const aiHCCardsCanIBuyThisCard)(int deckIndex, int cardIndex);

	// Buy this card now
	extern bool(*const aiHCCardsBuyCard)(int cardIndex);

	// For this cardIndex, get the age prereq.
	extern int(*const aiHCCardsGetCardAgePrereq)(int cardIndex);

	// For this cardIndex, get the age prereq.
	extern int(*const aiHCCardsGetCardLevel)(int cardIndex);

	// For this cardIndex, get the TechID.
	extern int(*const aiHCCardsGetCardTechID)(int a);

	// For this cardIndex, get the UnitType.
	extern int(*const aiHCCardsGetCardUnitType)(int a);

	// For this cardIndex, get the UnitCount.
	extern int(*const aiHCCardsGetCardUnitCount)(int a);

	// For this cardIndex, get the CardCount, -1 is Infinite.
	extern int(*const aiHCCardsGetCardCount)(int a);

	// Get the best card using the optional cardtype and optional resourcePreference
	extern int(*const aiHCCardsFindBestCard)(int cardType, int levelPref, int resourcePref);

	// Returns the number of decks in the Current HC.
	extern int(*const aiHCGetNumberDecks)();

	// Create a new HC Deck with the given name.
	extern int(*const aiHCDeckCreate)(string a);

	// Makes the deckIndex the current active HC deck.
	extern bool(*const aiHCDeckActivate)(int deckIndex);

	// Adds the card given to the givenHC Deck.
	extern bool(*const aiHCDeckAddCardToDeck)(int deckIndex, int cardIndex);

	// Returns the number of cards in the Current HC Deck.
	extern int(*const aiHCDeckGetNumberCards)(int deckIndex);

	// play this card.
	extern bool(*const aiHCDeckPlayCard)(int cardIndex);

	// For this card, get the age prereq
	extern int(*const aiHCDeckGetCardAgePrereq)(int deckIndex, int cardIndex);

	// For this card, get the level
	extern int(*const aiHCDeckGetCardLevel)(int deckIndex, int cardIndex);

	// For this card, get the techID
	extern int(*const aiHCDeckGetCardTechID)(int deckIndex, int cardIndex);

	// For this card, get the unitType
	extern int(*const aiHCDeckGetCardUnitType)(int deckIndex, int cardIndex);

	// For this card, get the unit Count
	extern int(*const aiHCDeckGetCardUnitCount)(int deckIndex, int cardIndex);

	// Can we play this card from the given deck?
	extern bool(*const aiHCDeckCanPlayCard)(int cardIndex);

	// Gets how many cards of this type we can send. -1 mean infinite.
	extern int(*const aiHCDeckCardGetCardCount)(int deskIndex, int cardIndex);

	// Returns the HCGP.
	extern vector(*const aiGetHCGatherPoint)(vector result);

	// Sets the HCGP.
	extern bool(*const aiSetHCGatherPoint)();

	// returns the score for the given player.
	extern int(*const aiGetScore)(int playerID);

	// returns the number of teams in the game.
	extern int(*const aiGetNumberTeams)();

	// Queues the auto savegame.
	extern void(*const aiQueueAutoSavegame)(int saveNumber);

	// returns true, if this is a multiplayer game.
	extern bool(*const aiIsMultiplayer)();

	// returns the ID of the fallen explorer; if there isn't one, returns -1
	extern int(*const aiGetFallenExplorerID)();

	// ransoms the specified explorer using funds from the specified escrow account and spawns it from the specified building.
	extern bool(*const aiRansomExplorer)(int explorerID, int escrowID, int sourceBuildingID);

	// builds walls around the specified building's colony using the specified escrow.
	extern bool(*const aiBuildWall)(int buildingID, int escrowID);

	// returns whether it is allowed to build a wall around the specified building's colony, and whether the player can afford it from the specified escrow.
	extern bool(*const aiCanBuildWall)(int buildingID, int escrowID);

	// returns the wall radius for the specified building's colony.
	extern float(*const aiGetWallRadius)(int buildingID);

	// returns whether a wall exists around the specified building's colony.
	extern bool(*const aiDoesWallExist)(int buildingID);

	// returns the current game type (e.g., cGameTypeScenario, cGameTypeRandom, etc).
	extern int(*const aiGetGameType)();

	// sets the specified tactic on the specified unit.
	extern bool(*const aiUnitSetTactic)(int unitID, int tacticID);

	// gets the specified unit's current tactic.
	extern int(*const aiUnitGetTactic)(int unitID);

	// Prevent a resource from being spent by the AI.
	extern void(*const aiResourceLock)(int resourceID);

	// Allow a resource to be spent by the AI.
	extern void(*const aiResourceUnlock)(int resourceID);

	// Is this Escrow resource locked.
	extern bool(*const aiResourceIsLocked)(int resourceID);

	// breaks the treaty using funds from the given escrow.
	extern bool(*const aiBreakTreaty)(int escrowID);

	// checks whether the given player has a treaty.
	extern bool(*const aiTreatyActive)();

	// Sets the scripts choice for the AgeX Politician.
	extern void(*const aiSetPoliticianChoice)(int age, int puid);

	// Gets the scripts choice for the AgeX Politician.
	extern int(*const aiGetPoliticianChoice)(int age);

	// Call this to make the AI fill out what Politicians are available.
	extern bool(*const aiPopulatePoliticianList)();

	// Gets the number of Politicans avaiable for AgeX.
	extern int(*const aiGetPoliticianListCount)(int age);

	// Gets the index'th Politicans avaiable for AgeX.
	extern int(*const aiGetPoliticianListByIndex)(int age, int index);

	// Gets the last collected nugget's type
	extern int(*const aiGetLastCollectedNuggetType)(int playerID);

	// Gets the last collected nugget's effect
	extern int(*const aiGetLastCollectedNuggetEffect)(int playerID);

	// Gets the number of tradeposts controlled by this team (for monopoly victory).
	extern int(*const aiGetNumberTradePostsControlled)(int teamID);

	// Gets the number of tradeposts needed to make a monopoly win possible.
	extern int(*const aiGetNumberTradePostsNeededForMonopoly)();

	// Returns true if the monopoly command can be given now.  Does not check cost.
	extern bool(*const aiReadyForTradeMonopoly)();

	// Executes a trade monopoly command, returns false if it fails.
	extern bool(*const aiDoTradeMonopoly)();

	// Returns true if a trade monopoly is possible in this game type.
	extern bool(*const aiIsMonopolyAllowed)();

	// Gets the number of relics controlled by this team (for relic victory).
	extern int(*const aiGetNumberRelicsControlled)(int teamID);

	// Gets the number of relics needed to make a relic win possible.
	extern int(*const aiGetNumberRelicsNeededForVictory)();

	// Returns true if a relic capture victory is possible in this game type.
	extern bool(*const aiIsRelicCaptureAllowed)();

	// Returns true if a King of the Hill victory is possible in this game type.
	extern bool(*const aiIsKOTHAllowed)();

	// Gets the team that is king of the hill.
	extern int(*const aiGetKOTHController)();

	// Returns true if this team is king of the hill.
	extern bool(*const aiIsTeamKOTH)(int teamID);

	// KB dump for player2's units from player1's perspective.
	extern void(*const kbDump)(int player1, int player2);

	// KB dump for player2's units of the given type from player1's perspective.
	extern void(*const kbDumpType)(int player1, int player2, string typeName);

	// Cheats and looks at all of the units on the map.  This will format your harddrive if you're not authorized to use it.
	extern void(*const kbLookAtAllUnitsOnMap)();

	// Returns the current population for the player.
	extern int(*const kbGetPop)();

	// Returns the current population cap for the player.
	extern int(*const kbGetPopCap)();

	// Returns the current age for the current player.
	extern int(*const kbGetAge)();

	// Returns the current age for the player specified.
	extern int(*const kbGetAgeForPlayer)(int id);

	// Returns the culture for the player.
	extern int(*const kbGetCulture)();

	// Returns the culture for the given player.
	extern int(*const kbGetCultureForPlayer)(int a);

	// Returns the culture name for the given culture.
	extern string(*const kbGetCultureName)(int a);

	// Returns the civilization for the player.
	extern int(*const kbGetCiv)();

	// Returns the civ for the given player.
	extern int(*const kbGetCivForPlayer)(int a);

	// Returns the civ name for the given civ.
	extern string(*const kbGetCivName)(int civID);

	// Creates a unit query, returns the query ID.
	extern int(*const kbUnitQueryCreate)(string name);

	// Resets the given unit query data AND results.
	extern bool(*const kbUnitQueryResetData)(int queryID);

	// Resets the given unit query results.
	extern bool(*const kbUnitQueryResetResults)(int queryID);

	// Destroys the given unit query.
	extern bool(*const kbUnitQueryDestroy)(int queryID);

	// Returns the number of results in the current query.
	extern int(*const kbUnitQueryNumberResults)(int queryID);

	// Returns the UnitID of the index-th result in the current query.
	extern int(*const kbUnitQueryGetResult)(int queryID, int index);

	// Sets query data.
	extern bool(*const kbUnitQuerySetPlayerID)(int queryID, int playerID, bool resetQueryData);

	// Sets query data.
	extern bool(*const kbUnitQuerySetPlayerRelation)(int queryID, int playerRelation);

	// Sets query data.
	extern bool(*const kbUnitQuerySetUnitType)(int queryID, int unitTypeID);

	// Sets query data.
	extern bool(*const kbUnitQuerySetActionType)(int queryID, int actionTypeID);

	// Sets query data.
	extern bool(*const kbUnitQuerySetState)(int queryID, int state);

	// Sets query data.
	extern bool(*const kbUnitQuerySetPosition)(int queryID, vector v);

	// Sets query data.
	extern bool(*const kbUnitQuerySetMaximumDistance)(int queryID, float distance);

	// Sets query data.
	extern bool(*const kbUnitQuerySetIgnoreKnockedOutUnits)(int queryID, bool v);

	// If parm is true, results are sorted in ascending distance order from the query position.
	extern bool(*const kbUnitQuerySetAscendingSort)(int queryID, bool v);

	// Sets query data.
	extern bool(*const kbUnitQuerySetBaseID)(int queryID, int baseID);

	// Sets query data.
	extern bool(*const kbUnitQuerySetAreaID)(int queryID, int areaID);

	// Sets query data.
	extern bool(*const kbUnitQuerySetAreaGroupID)(int queryID, int areaGroupID);

	// Sets query data.
	extern bool(*const kbUnitQuerySetArmyID)(int queryID, int armyID);

	// Sets query data.
	extern bool(*const kbUnitQuerySetSeeableOnly)(int queryID, bool seeableOnly);

	// Executes the current query; returns number of results.
	extern int(*const kbUnitQueryExecute)(int queryID);

	// Executes the current query on the previous query's results; returns the new number of results.
	extern int(*const kbUnitQueryExecuteOnQuery)(int currentQueryID, int previousQueryID);

	// Executes the current query on the previous query's results; returns the new number of results.
	extern int(*const kbUnitQueryExecuteOnQueryByName)(int currentQueryID, string previousQueryName);

	// gets total aiCost of query's units, weighted for HP if requested.
	extern float(*const kbUnitQueryGetUnitCost)(int queryID, bool considerHealth);

	// gets HP of query's units, using current HP if requested.
	extern float(*const kbUnitQueryGetUnitHitpoints)(int queryID, bool considerHealth);

	// Returns the player ID for this unit ID.
	extern int(*const kbUnitGetPlayerID)(int unitID);

	// Returns the plan ID for this unit ID.
	extern int(*const kbUnitGetPlanID)(int unitID);

	// Returns the base ID for this unit ID.
	extern int(*const kbUnitGetBaseID)(int unitID);

	// Returns the area ID for this unit ID.
	extern int(*const kbUnitGetAreaID)(int unitID);

	// Returns the army ID for this unit ID.
	extern int(*const kbUnitGetArmyID)(int unitID);

	// Returns the movementType for this unitTypeID.
	extern int(*const kbUnitGetMovementType)(int unitTypeID);

	// Returns the current hitpoints for this unit ID.
	extern float(*const kbUnitGetCurrentHitpoints)(int unitID);

	// Returns the maximum hitpoints for this unit ID.
	extern float(*const kbUnitGetMaximumHitpoints)(int unitID);

	// Returns the health for this unit ID.
	extern float(*const kbUnitGetHealth)(int unitID);

	// Returns the current AI cost (worth) for this unit ID.
	extern float(*const kbUnitGetCurrentAICost)(int unitID);

	// Returns the maximum AI cost (worth) for this unit ID.
	extern float(*const kbUnitGetMaximumAICost)(int unitID);

	// Returns the position for this unit ID.
	extern vector(*const kbUnitGetPosition)(vector result, int unitID);

	// Returns true if the unit is of the unitTypeID.
	extern bool(*const kbUnitIsType)(int unitID, int unitTypeID);

	// Returns the actionTypeID of the unit.
	extern int(*const kbUnitGetActionType)(int unitID);

	// Returns the target unit ID of the given unit.
	extern int(*const kbUnitGetTargetUnitID)(int unitID);

	// Returns the number of units currently working on the given unit.
	extern int(*const kbUnitGetNumberWorkers)(int unitID);

	// Returns the index-th worker unit ID.
	extern int(*const kbUnitGetWorkerID)(int unitID, int index);

	// Returns the number of the unit type you are allowed to have (ONLY WORKS ON BASE UNIT TYPES); returns -1 if there is no limit.
	extern int(*const kbGetBuildLimit)(int player, int unitTypeID);

	// Returns amount of pop cap addition provided by the given unit type (ONLY WORKS ON BASE UNIT TYPES).
	extern int(*const kbGetPopCapAddition)(int player, int unitTypeID);

	// Returns the number of pop slots this unit takes (ONLY WORKS ON BASE UNIT TYPES).
	extern int(*const kbGetPopSlots)(int player, int unitTypeID);

	// Returns the number of pop slots currently occupied by this unit type.
	extern int(*const kbGetPopulationSlotsByUnitTypeID)(int playerID, int unitTypeID);

	// Returns the number of pop slots currently occupied by the results in the given query.
	extern int(*const kbGetPopulationSlotsByQueryID)(int queryID);

	// Returns a quick unit count of units for a player.
	extern int(*const kbUnitCount)(int player, int unitTypeID, int stateID);

	// Returns a quick unit count of player2's units from player1's perspective.
	extern void(*const kbUnitCountConsole)(int playerID1, int playerID2, string unitType, string state);

	// Returns the center vector of the map.
	extern vector(*const kbGetMapCenter)(vector result);

	// Returns the X size of the map.
	extern float(*const kbGetMapXSize)();

	// Returns the Z size of the map.
	extern float(*const kbGetMapZSize)();

	// Creates areas and area groups. DO THIS BEFORE ANYTHING ELSE IN YOUR SCRIPT.
	extern void(*const kbAreaCalculate)(float a, bool b, vector c, vector d, vector e, vector f);

	// Returns the number of areas.
	extern int(*const kbAreaGetNumber)();

	// Returns the ID of the given area.
	extern int(*const kbAreaGetIDByPosition)(vector position);

	// Returns the ID of the given area group.
	extern int(*const kbAreaGroupGetIDByPosition)(vector position);

	// Returns the center of the given areaGroup.
	extern vector(*const kbAreaGroupGetCenter)(vector result, int groupID);

	// Returns the center of the given area.
	extern vector(*const kbAreaGetCenter)(vector result, int areaID);

	// Returns the number of tiles in the given area.
	extern int(*const kbAreaGetNumberTiles)(int areaID);

	// Returns the number of black tiles in the given area.
	extern int(*const kbAreaGetNumberBlackTiles)(int areaID);

	// Returns the number of visible tiles in the given area.
	extern int(*const kbAreaGetNumberVisibleTiles)(int areaID);

	// Returns the number of fog tiles in the given area.
	extern int(*const kbAreaGetNumberFogTiles)(int areaID);

	// Returns the gametime of the last visibility change for the given area.
	extern int(*const kbAreaGetVisibilityChangeTime)(int areaID);

	// Returns the number of units in the given area.
	extern int(*const kbAreaGetNumberUnits)(int areaID);

	// Returns the Unit ID of the index-th unit in the given area.
	extern int(*const kbAreaGetUnitID)(int areaID, int index);

	// Returns the number of border areas for the given area.
	extern int(*const kbAreaGetNumberBorderAreas)(int areaID);

	// Returns the Area ID of the index-th border area in the given area.
	extern int(*const kbAreaGetBorderAreaID)(int areaID, int index);

	// Returns the Type of area.
	extern int(*const kbAreaGetType)(int areaID);

	// returns an area's VP site ID (-1 if an area doesn't have a VP site).
	extern int(*const kbAreaGetVPSiteID)(int areaID);

	// returns ID for an array containing VP site IDs that match the specified parameters.
	extern int(*const kbVPSiteQuery)(int scoreType, int playerRelationOrID, int siteState);

	// blogs out info about all VP sites.
	extern void(*const kbDumpVPSiteInfo)();

	// returns the specified VP site's type (e.g., native, trade, etc).
	extern int(*const kbVPSiteGetType)(int siteID);

	// returns the specified VP site's world location.
	extern vector(*const kbVPSiteGetLocation)(vector result, int siteID);

	// returns the specified VP site's owning player.
	extern int(*const kbVPSiteGetOwnerPlayerID)(int siteID);

	// returns the specified VP site's state.
	extern int(*const kbVPSiteGetState)(int siteID);

	// returns the protounit ID for the VP generator that corresponds to this type of VP site.
	extern int(*const kbGetVPGeneratorByScoreType)(int siteType);

	// Returns the Area ID of the closest area, of the given types, to given postion.
	extern int(*const kbAreaGetClosetArea)(vector position, int areaType, int areaType1, float minDistance);

	// Creates a path with the given name.
	extern int(*const kbPathCreate)(string name);

	// Destroys the given path.
	extern bool(*const kbPathDestroy)(int pathID);

	// Returns the number of paths.
	extern int(*const kbPathGetNumber)();

	// Returns the index-th path ID.
	extern int(*const kbPathGetIDByIndex)(int index);

	// Returns the name of the given path.
	extern string(*const kbPathGetName)(int pathID);

	// Returns the length of the given path.
	extern float(*const kbPathGetLength)(int pathID);

	// Returns the number of waypoints in the given path.
	extern int(*const kbPathGetNumberWaypoints)(int pathID);

	// Adds the waypoint to the given path.
	extern bool(*const kbPathAddWaypoint)(int pathID, vector waypoint);

	// Returns the appropriate waypoint from the given path.
	extern vector(*const kbPathGetWaypoint)(vector result, int pathID, int waypointNumber);

	// Returns true if the given unit type can path from pointA to pointB.
	extern bool(*const kbCanSimPath)(vector pointA, vector pointB, int protoUnitTypeID, float range);

	// Returns true if the given unit type can path from pointA to pointB.
	extern bool(*const kbCanPath2)(vector pointA, vector pointB, int protoUnitTypeID, float range);

	// Returns the Route ID if successful.
	extern int(*const kbCreateAttackRoute)(string name, int startAreaID, int goalAreaID, int numInitialRoutes);

	// Returns the Route ID if successful.
	extern int(*const kbCreateAttackRouteWithPath)(string name, vector startPt, vector endPt);

	// Returns true if the route was deleted.
	extern bool(*const kbDestroyAttackRoute)(int routeID);

	// add a new sector to path to.
	extern bool(*const kbAddAttackRouteSector)(int sector);

	// ignore this area when finding the route.
	extern bool(*const kbAddAttackRouteIgnoreID)(int ignoreAreaID);

	// ignore this areatype when finding the route.
	extern bool(*const kbAddAttackRouteIgnoreType)(int ignoreAreaTypeID);

	// Rreturns true if path was added to attack route.
	extern bool(*const kbAttackRouteAddPath)(int attackRouteID, int pathID);

	// find all the paths to the sector specified.
	extern bool(*const kbMakeAttackRoutes)();

	// Returns num paths from start to goal area.
	extern int(*const kbGetNumAttackRoutes)(int startAreaID, int goalAreaID);

	// Returns the id of the routes from area1 to area2.
	extern int(*const kbGetAttackRouteID)(int startAreaID, int goalAreaID);

	// Creates an escrow.
	extern int(*const kbEscrowCreate)(string name, int resourceID, float percentage, int parentID);

	// Destroys an escrow.
	extern bool(*const kbEscrowDestroy)(int escrowID, bool promoteChildren);

	// Returns the ID of the named escrow.
	extern int(*const kbEscrowGetID)(string name);

	// Returns the percentage of the escrow.
	extern float(*const kbEscrowGetPercentage)(int escrowID, int resourceID);

	// Sets the percentage of the escrow.
	extern bool(*const kbEscrowSetPercentage)(int escrowID, int resourceID, float percentage);

	// Sets the cap of the escrow.
	extern bool(*const kbEscrowSetCap)(int escrowID, int resourceID, float cap);

	// Returns the amount of credits in the given escrow for the given resource.
	extern float(*const kbEscrowGetAmount)(int escrowID, int resourceID);

	// Removes all credits (and puts them into the root escrow) of the given resource type from the given escrow.
	extern bool(*const kbEscrowFlush)(int escrowID, int resourceID, bool flushChildren);

	// Reallocates the current resource stockpile into the escrows.
	extern bool(*const kbEscrowAllocateCurrentResources)();

	// Creates a building placement; returns the ID.
	extern int(*const kbBuildingPlacementCreate)(string name);

	// Destroys the given building placement.
	extern bool(*const kbBuildingPlacementDestroy)(int id);

	// Resets the current building placement.
	extern bool(*const kbBuildingPlacementResetResults)();

	// Selects the given building placement.
	extern bool(*const kbBuildingPlacementSelect)(int id);

	// Sets event handler function for the current BP and event.
	extern bool(*const kbBuildingPlacementSetEventHandler)(int eventType, string handlerName);

	// Sets the building type for the current building placement.
	extern bool(*const kbBuildingPlacementSetBuildingType)(int buildingTypeID);

	// Sets the base ID and location preference for the current building placement.
	extern bool(*const kbBuildingPlacementSetBaseID)(int baseID, int locationPref);

	// Adds the Area ID to the current BP (with the given number of border area layers), addCenterInfluence - adds a positional influence from the area center.
	extern bool(*const kbBuildingPlacementAddAreaID)(int areaID, int numberBorderAreaLayers, bool addCenterInfluence);

	// Adds the AreaGroup ID to the current BP.
	extern bool(*const kbBuildingPlacementAddAreaGroupID)(int areaGroupID);

	// Sets up center position-based BP.
	extern bool(*const kbBuildingPlacementSetCenterPosition)(vector position, float distance, float obstructionRadius);

	// Adds the unit influence for the current building placement.
	extern bool(*const kbBuildingPlacementAddUnitInfluence)(int typeID, float value, float distance, int kbResourceID);

	// Adds the position influence for the current building placement.
	extern bool(*const kbBuildingPlacementAddPositionInfluence)(vector position, float value, float distance);

	// Sets the minimum acceptable value for evaluated spots in the BP.
	extern bool(*const kbBuildingPlacementSetMinimumValue)(float minimumValue);

	// Starts the placement of current building.
	extern bool(*const kbBuildingPlacementStart)();

	// Returns the vector result position for given BP ID.
	extern vector(*const kbBuildingPlacementGetResultPosition)(vector result, int bpID);

	// Returns the result value for given BP ID.
	extern float(*const kbBuildingPlacementGetResultValue)(int bpID);

	// Creates a target selector; returns the ID.
	extern int(*const kbTargetSelectorCreate)(string name);

	// Destroys the given target selector.
	extern bool(*const kbTargetSelectorDestroy)(int id);

	// Resets the current target selector.
	extern bool(*const kbTargetSelectorResetResults)();

	// Selects the given target selector.
	extern bool(*const kbTargetSelectorSelect)(int id);

	// Add the UAIT for the given BASE unit type as a filter.
	extern bool(*const kbTargetSelectorAddUnitType)(int protoUnitTypeID);

	// Sets the list of potential targets to the results in the given query.
	extern bool(*const kbTargetSelectorAddQueryResults)(int queryID);

	// Returns the number of results in the given target selector.
	extern int(*const kbTargetSelectorGetNumberResults)();

	// Returns the result value for given index of the current target selector.
	extern int(*const kbTargetSelectorGetResultValue)(int index);

	// Starts the current target selector.
	extern bool(*const kbTargetSelectorStart)();

	// Returns true if amount of resource is within distance of a dropsite.
	extern bool(*const kbSetupForResource)(int baseID, int resourceID, float distance, float amount);

	// Returns the current HomeCity Level of the given player.
	extern int(*const kbGetHCLevel)(int playerID);

	// Returns the current amount XP the given player has.
	extern int(*const kbResourceGetXP)(int playerID);

	// Returns the current amount of the given resource.
	extern float(*const kbResourceGet)(int resourceID);

	// Returns the maximum amount of the given resource you can have.
	extern float(*const kbMaximumResourceGet)(int resourceID);

	// Returns the total amount of the given resource gathered to this point in the game.
	extern float(*const kbTotalResourceGet)(int resourceID);

	// Returns the number of valid KB resources for the given plan/base.
	extern int(*const kbGetNumberValidResourcesByPlan)(int planID, int baseID);

	// Returns the number of valid KB resources for the resource types.
	extern int(*const kbGetNumberValidResources)(int baseID, int resourceTypeID, int resourceSubTypeID, float distance);

	// Returns the resource amount of valid KB resources for the resource types.
	extern float(*const kbGetAmountValidResources)(int baseID, int resourceTypeID, int resourceSubTypeID, float distance);

	// Returns the resource income over the last X seconds.
	extern float(*const kbGetResourceIncome)(int resourceID, float seconds, bool relative);

	// Returns true if the protoUnit is currently available.
	extern bool(*const kbProtoUnitAvailable)(int protoUnitID);

	// Returns the ID of the protounit.
	extern int(*const kbGetProtoUnitID)(string name);

	// Returns the unit's protounit ID.
	extern int(*const kbUnitGetProtoUnitID)(int unitID);

	// Returns true if the player can afford the proto unit.
	extern bool(*const kbCanAffordUnit)(int protoUnitTypeID, int escrowID);

	// returns the cost of the protounit for the given resource.
	extern float(*const kbUnitCostPerResource)(int protoUnitID, int resourceID);

	// Returns true if the player can afford the tech.
	extern bool(*const kbCanAffordTech)(int techID, int escrowID);

	// returns the cost of the tech for the given resource.
	extern float(*const kbTechCostPerResource)(int techID, int resourceID);

	// Returns true if the protounit is of the unitTypeID.
	extern bool(*const kbProtoUnitIsType)(int playerID, int protoUnitID, int unitTypeID);

	// Returns the current tech status for the current player of the requested tech.
	extern int(*const kbTechGetStatus)(int techID);

	// Returns the percent complete for the the requested tech of the current player.
	extern float(*const kbGetTechPercentComplete)(int techID);

	// Returns the combat efficiency of the comparison (in terms of playerID1's units).
	extern float(*const kbGetCombatEfficiency)(int playerID1, int unitTypeID1, int playerID2, int unitTypeID2);

	// Returns the AI cost weight for the given resource.
	extern float(*const kbGetAICostWeight)(int resourceID);

	// Sets the weight this resource type is given during AI cost calculuations.
	extern bool(*const kbSetAICostWeight)(int resourceID, float weight);

	// Returns the AI cost for the given protoUnit type ID.
	extern float(*const kbGetProtoUnitAICost)(int protoUnitTypeID);

	// Returns the AI cost for the given tech ID.
	extern float(*const kbGetTechAICost)(int techID);

	// Returns the player's resigned status.
	extern bool(*const kbIsPlayerResigned)(int playerID);

	// Returns the player's lost status.
	extern bool(*const kbHasPlayerLost)(int playerID);

	// Returns the player's team number.
	extern int(*const kbGetPlayerTeam)(int playerID);

	// Returns the player's name.
	extern string(*const kbGetPlayerName)(int playerID);

	// Returns true if the given player is an enemy.
	extern bool(*const kbIsPlayerEnemy)(int playerID);

	// Returns true if the given player is a neutral player.
	extern bool(*const kbIsPlayerNeutral)(int playerID);

	// Returns true if the given player is an ally.
	extern bool(*const kbIsPlayerAlly)(int playerID);

	// Returns true if the given player is a mutual ally.
	extern bool(*const kbIsPlayerMutualAlly)(int playerID);

	// Returns the number of mutual allies.
	extern int(*const kbGetNumberMutualAllies)();

	// Returns true if the given player is a valid player (i.e. it exists in the game).
	extern bool(*const kbIsPlayerValid)(int playerID);

	// Returns true if the given player is a a human player.
	extern bool(*const kbIsPlayerHuman)(int playerID);

	// Returns the player's handicap multiplier (ie., 1.0 = no handicap).
	extern float(*const kbGetPlayerHandicap)(int playerID);

	// Sets the indicated player's handicap multiplier (ie., 1.0 = no handicap).
	extern void(*const kbSetPlayerHandicap)(int playerID, float handicap);

	// Returns whether the game is over or not.
	extern bool(*const kbIsGameOver)();

	// Returns the location of the main town.
	extern vector(*const kbGetTownLocation)(vector result);

	// Returns the area ID of the main town.
	extern int(*const kbGetTownAreaID)();

	// Sets the location of the main town.
	extern bool(*const kbSetTownLocation)(vector location);

	// Returns the auto base creation value.
	extern bool(*const kbGetAutoBaseCreate)();

	// Sets the auto base creation value.
	extern void(*const kbSetAutoBaseCreate)(bool v);

	// Returns the auto base creation distance.
	extern float(*const kbGetAutoBaseCreateDistance)();

	// Sets the auto base creation distance.
	extern void(*const kbSetAutoBaseCreateDistance)(float v);

	// Returns the auto base detection value.
	extern bool(*const kbGetAutoBaseDetect)();

	// Sets the auto base detection value.
	extern void(*const kbSetAutoBaseDetect)(bool v);

	// Returns the auto base creation distance.
	extern float(*const kbGetAutoBaseDetectDistance)();

	// Sets the auto base creation distance.
	extern void(*const kbSetAutoBaseDetectDistance)(float v);

	// gets the nearest base of player relation from the location.
	extern int(*const kbFindClosestBase)(int playerRelation, vector location);

	// Returns the ID of the next base that will be created.
	extern int(*const kbBaseGetNextID)();

	// Returns the number of bases for the given player.
	extern int(*const kbBaseGetNumber)(int playerID);

	// Returns the BaseID for the given base.
	extern int(*const kbBaseGetIDByIndex)(int playerID, int index);

	// Creates a base.
	extern int(*const kbBaseCreate)(int playerID, string name, vector position, float distance);

	// Finds/Creates a resource base.
	extern int(*const kbBaseFindCreateResourceBase)(int resourceType, int resourceSubType, int parentBaseID);

	// Finds/Creates a 'forward' military base against the given enemy base.
	extern int(*const kbBaseFindForwardMilitaryBase)(int a, int b, int c);

	// Destroys the given base.
	extern bool(*const kbBaseDestroy)(int playerID, int baseID);

	// Destroys all of the bases for the given player.
	extern void(*const kbBaseDestroyAll)(int playerID);

	// Gets the location of the base.
	extern vector(*const kbBaseGetLocation)(vector result, int playerID, int baseID);

	// Gets the last known damage location of the base.
	extern vector(*const kbBaseGetLastKnownDamageLocation)(vector result, int a, int b);

	// Returns the player ID of the specified base's owner.
	extern int(*const kbBaseGetOwner)(int baseID);

	// Sets the front (and back) of the base.
	extern bool(*const kbBaseSetFrontVector)(int playerID, int baseID, vector frontVector);

	// Gets the front vector of the base.
	extern vector(*const kbBaseGetFrontVector)(vector result, int playerID, int baseID);

	// Gets the back vector of the base.
	extern vector(*const kbBaseGetBackVector)(vector result, int playerID, int baseID);

	// Returns the number of continuous seconds the base has been under attack.
	extern int(*const kbBaseGetTimeUnderAttack)(int playerID, int baseID);

	// Gets the under attack flag of the base.
	extern bool(*const kbBaseGetUnderAttack)(int playerID, int baseID);

	// Sets the active flag of the base.
	extern bool(*const kbBaseSetActive)(int playerID, int baseID, bool active);

	// Gets the active flag of the base.
	extern bool(*const kbBaseGetActive)(int playerID, int baseID);

	// Gets the main base ID for the player.
	extern int(*const kbBaseGetMainID)(int playerID);

	// Sets the main flag of the base.
	extern bool(*const kbBaseSetMain)(int playerID, int baseID, bool main);

	// Gets the main flag of the base.
	extern bool(*const kbBaseGetMain)(int playerID, int baseID);

	// Sets the forward flag of the base.
	extern bool(*const kbBaseSetForward)(int playerID, int baseID, bool forward);

	// Gets the forward flag of the base.
	extern bool(*const kbBaseGetForward)(int playerID, int baseID);

	// Sets the settlement flag of the base.
	extern bool(*const kbBaseSetSettlement)(int playerID, int baseID, bool settlement);

	// Gets the settlement flag of the base.
	extern bool(*const kbBaseGetSettlement)(int playerID, int baseID);

	// Sets the military flag of the base.
	extern bool(*const kbBaseSetMilitary)(int playerID, int baseID, bool military);

	// Gets the military flag of the base.
	extern bool(*const kbBaseGetMilitary)(int playerID, int baseID);

	// Gets the military gather point of the base.
	extern vector(*const kbBaseGetMilitaryGatherPoint)(vector result, int playerID, int baseID);

	// Sets the military gather point of the base.
	extern bool(*const kbBaseSetMilitaryGatherPoint)(int playerID, int baseID, vector gatherPoint);

	// Sets the economy flag of the base.
	extern bool(*const kbBaseSetEconomy)(int playerID, int baseID, bool Economy);

	// Gets the economy flag of the base.
	extern bool(*const kbBaseGetEconomy)(int playerID, int baseID);

	// Gets the maximum resource distance of the base.
	extern float(*const kbBaseGetMaximumResourceDistance)(int playerID, int baseID);

	// Sets the maximum resource distance of the base.
	extern void(*const kbBaseSetMaximumResourceDistance)(int playerID, int baseID, float distance);

	// Adds the given unit to the base.
	extern bool(*const kbBaseAddUnit)(int playerID, int baseID, int unitID);

	// Removes the given unit to the base.
	extern bool(*const kbBaseRemoveUnit)(int playerID, int baseID, int unitID);

	// Returns the number of units that match the criteria.
	extern int(*const kbBaseGetNumberUnits)(int playerID, int baseID, int relation, int unitTypeID);

	// Returns true if the unit is currently visible to the player.
	extern bool(*const kbUnitVisible)(int unitID);

	// Returns true if the location is currently visible to the player.
	extern bool(*const kbLocationVisible)(vector location);

	// Returns the position of the cinematic block.
	extern vector(*const kbGetBlockPosition)(vector result, string blockName);

	// Returns the UnitID of the cinematic block.
	extern int(*const kbGetBlockID)(string blockName);

	// Returns a random, valid PUID that's of the given type.
	extern int(*const kbGetRandomEnabledPUID)(int unitTypeID, int escrowID);

	// Creates a unit pick.
	extern int(*const kbUnitPickCreate)(string name);

	// Destroys the given unit pick.
	extern bool(*const kbUnitPickDestroy)(int upID);

	// Resets all of the unit pick data.
	extern bool(*const kbUnitPickResetAll)(int upID);

	// Resets the unit pick results.
	extern bool(*const kbUnitPickResetResults)(int upID);

	// Gets the unit pick preference weight.
	extern float(*const kbUnitPickGetPreferenceWeight)(int upID);

	// Sets the unit pick preference weight.
	extern bool(*const kbUnitPickSetPreferenceWeight)(int upID, float v);

	// Sets the unit pick enemy player ID.
	extern bool(*const kbUnitPickSetEnemyPlayerID)(int upID, int playerID);

	// Sets the unit pick combat efficiency weight.
	extern bool(*const kbUnitPickSetCombatEfficiencyWeight)(int upID, float a);

	// Resets the enemy unit typeIDs for the unit pick combat efficiency calculation.
	extern bool(*const kbUnitPickResetCombatEfficiencyTypes)(int upID);

	// Adds an enemy unit typeID to the unit pick combat efficiency calculation.
	extern bool(*const kbUnitPickAddCombatEfficiencyType)(int upID, int typeID, float weight);

	// Sets the unit pick cost weight.
	extern bool(*const kbUnitPickSetCostWeight)(int upID, float a);

	// Sets the unit pick movement type.
	extern bool(*const kbUnitPickSetMovementType)(int upID, int movementType);

	// Sets the unit pick desired number unit types.
	extern bool(*const kbUnitPickSetDesiredNumberUnitTypes)(int upID, int number, int numberBuildings, bool degradeNumberBuildings);

	// Gets the unit pick desired number unit types.
	extern int(*const kbUnitPickGetDesiredNumberUnitTypes)(int upID);

	// Sets the unit pick desired number buildings for the index-th unit type.
	extern bool(*const kbUnitPickSetDesiredNumberBuildings)(int upID, int index, int numberBuildings);

	// gets the unit pick desired number buildings for the index-th unit type.
	extern int(*const kbUnitPickGetDesiredNumberBuildings)(int upID, int index);

	// Sets the unit pick desired number unit types.
	extern bool(*const kbUnitPickSetMinimumNumberUnits)(int upID, int number);

	// Gets the unit pick minimum number units.
	extern int(*const kbUnitPickGetMinimumNumberUnits)(int upID);

	// Sets the unit pick desired number unit types.
	extern bool(*const kbUnitPickSetMaximumNumberUnits)(int upID, int number);

	// Gets the unit pick maximum number units.
	extern int(*const kbUnitPickGetMaximumNumberUnits)(int upID);

	// Sets the unit pick desired min pop.
	extern bool(*const kbUnitPickSetMinimumPop)(int upID, int number);

	// Gets the unit pick minimum pop.
	extern int(*const kbUnitPickGetMinimumPop)(int upID);

	// Sets the unit pick desired max pop.
	extern bool(*const kbUnitPickSetMaximumPop)(int upID, int number);

	// Gets the unit pick maximum pop.
	extern int(*const kbUnitPickGetMaximumPop)(int upID);

	// Sets the unit pick attack unit type.
	extern bool(*const kbUnitPickSetAttackUnitType)(int upID, int type);

	// Gets the unit pick attack unit type.
	extern int(*const kbUnitPickGetAttackUnitType)(int upID);

	// Sets the unit pick attack unit type.
	extern bool(*const kbUnitPickSetGoalCombatEfficiencyType)(int upID, int type);

	// Gets the unit pick attack unit type.
	extern int(*const kbUnitPickGetGoalCombatEfficiencyType)(int upID);

	// Sets the preferenceFactor for that unit type.
	extern bool(*const kbUnitPickSetPreferenceFactor)(int upID, int unitTypeID, float preferenceFactor);

	// Adjusts the preferenceFactor for that unit type (uses 50.0 as the base if the UP doesn't exist yet).
	extern bool(*const kbUnitPickAdjustPreferenceFactor)(int upID, int unitTypeID, float baseFactorAdjustment);

	// Runs the unit pick.
	extern int(*const kbUnitPickRun)(int upID);

	// Returns the number of unit pick results.
	extern int(*const kbUnitPickGetNumberResults)(int upID);

	// Returns the index-th ProtoUnitID.
	extern int(*const kbUnitPickGetResult)(int upID, int index);

	// returns the visible area group that matches the given criteria.
	extern int(*const kbFindAreaGroup)(int groupType, float surfaceAreaRatio, int compareAreaID);

	// returns the visible area group that matches the given criteria.
	extern int(*const kbFindAreaGroupByLocation)(int groupType, float relativeX, float relativeZ);

	// returns the id of the best building to repair.
	extern int(*const kbFindBestBuildingToRepair)(vector position, float distance, float healthRatio, int repairUnderAttackUnitTypeID);

	// set the explicit position that every forward base will use.
	extern void(*const kbSetForwardBasePosition)(vector position);

	// sets the TargetSelector Factor value.
	extern void(*const kbSetTargetSelectorFactor)(int type, float val);

	// gets the TargetSelector Factor value.
	extern float(*const kbGetTargetSelectorFactor)(int type);

	// Returns the name of the tech ID.
	extern string(*const kbGetTechName)(int techID);

	// Returns the name of the protounit ID.
	extern string(*const kbGetProtoUnitName)(int protoUnitTypeID);

	// Returns the base type ID of the unit.
	extern int(*const kbGetUnitBaseTypeID)(int unitID);

	// Returns the name of the unit type.
	extern string(*const kbGetUnitTypeName)(int unitTypeID);

	// Creates a unit progression of the given name.
	extern int(*const kbCreateUnitProgression)(string unitName, string name);

	// Creates a tech progression of the given name.
	extern int(*const kbCreateTechProgression)(string techName, string name);

	// gets cheapest researchable unit upgrade, optionally for specified unit/unit line.
	extern int(*const kbTechTreeGetCheapestUnitUpgrade)(int unitTypeID);

	// gets cheapest researchable econ upgrade, optionally for specified resource unit type.
	extern int(*const kbTechTreeGetCheapestEconUpgrade)(int resourceUnitTypeID);

	// Dumps the current state of the KBTT.
	extern void(*const kbTechTreeDump)();

	// Returns the total number of steps to complete the progression.
	extern int(*const kbProgressionGetTotalNodes)(int progressionID);

	// Returns the total cost of the given resource for this progressionID. A resourceID of -1 will return the total Cost.
	extern float(*const kbProgessionGetTotalResourceCost)(int progressionID, int resourceID);

	// Returns the type of node at the given index, either Unit type or Tech type.
	extern int(*const kbProgressionGetNodeType)(int progressionID, int nodeIndex);

	// Returns the data at nodeIndex, either UnitID or TechID, depending on the type.
	extern int(*const kbProgressionGetNodeData)(int progressionID, int nodeIndex);

	// adds a rule to the runtime to be activated on the next update.
	extern void(*const trDelayedRuleActivation)(string rulename);

	// Returns the current gametime in Seconds.
	extern int(*const trTime)();

	// Returns the current gametime in Milliseconds.
	extern int(*const trTimeMS)();

	// Clears the units in the trigger selection system.
	extern void(*const trUnitSelectClear)();

	// 'Selects' the unit in the trigger selection system.
	extern void(*const trUnitSelect)(string unitScenarioName);

	// 'Selects' the unit in the trigger selection system.
	extern void(*const trUnitSelectByID)(int unitID);

	// Returns true if the specified player is built on the specified socket.
	extern bool(*const trPlayerControlsSocket)(int playerID, string objectScenarioName);

	// Returns true if the current player is looking at (visiting) the home city of the player specified by the player ID passed in.
	extern bool(*const trIsPlayerVisitingHC)(int targetHCPlayerID);

	// Returns true if the current player is selecting the building in their HC which has the specified name.
	extern bool(*const trIsPlayerSelectingHCBuilding)(string hcBuildingName);

	// Returns true when the player has sent a shipment from the home city.
	extern bool(*const trHasPlayerSentHCShipment)(int targetHCPlayerID);

	// Returns true when the player sends a shipment from home city.
	extern bool(*const trIsPlayerSendingHCShipment)(int targetHCPlayerID);

	// Returns true if the object is currently being worked.
	extern bool(*const trObjectGettingWorked)(string objectScenarioName);

	// Moves the selected unit(s) to the given position.
	extern bool(*const trUnitMoveToPoint)(float x, float y, float z, int eventID, bool bAttackMove, bool bUnitRun, float runSpeedMultiplier);

	// Moves the selected unit(s) to the spot occupied by the given unit.
	extern bool(*const trUnitMoveToUnit)(string unitScenarioName, int eventID, bool bAttackMove, bool bUnitRun, float runSpeedMultiplier);

	// Finds the specified revealer and sets it to active or inactive.
	extern void(*const trSetRevealerActiveState)(string revealerName, bool active);

	// Creates a revealer with the given attributes.
	extern void(*const trCreateRevealer)(int playerID, string revealerName, vector position, float revealerLOS, bool blackmapOnly);

	// Moves all matching units near the selected unit(s) to the given position.
	extern bool(*const trUnitMoveFromArea)(float x, float y, float z, int eventID, bool bAttackMove, int player, string unitType, float radius);

	// Selects units and makes the build a unit at specified location
	extern bool(*const trUnitBuildUnit)(string protoUnitName, vector BVector);

	// Tasks the selected unit(s) to perform work on the given unit.
	extern bool(*const trUnitDoWorkOnUnit)(string unitScenarioName, int eventID);

	extern void(*const trShowDamage)(string a, string b, string c, string d);

	// Tasks the selected unit(s) to garrision into another unit.
	extern bool(*const trUnitGarrison)(string unitScenarioName, int eventID);

	// Sets the age of the specified player.
	extern void(*const trPlayerSetAge)(int playerID, int age, bool displayEffect);

	// Sets whether the player has access to the HC.
	extern void(*const trPlayerSetHCAccess)(int playerID, bool hcAccess);

	// Sets the view to the HC if the player specified is the current player.
	extern void(*const trShowHCView)(int playerID);

	// Sets the view to the world if the player specified is the current player.
	extern void(*const trShowWorldView)(int playerID);

	// Instantly garrisons units inside another unit without considering distance.
	extern bool(*const trImmediateUnitGarrison)(string unitScenarioName);

	// Returns the shortest distance between the trRT units and the point.
	extern float(*const trUnitDistanceToPoint)(float x, float y, float z);

	// Returns the shortest distance between the trRT units and the given unit.
	extern float(*const trUnitDistanceToUnit)(string unitScenarioName);

	// Returns the shortest distance between the trRT units and the given unit.
	extern float(*const trUnitDistanceToUnitID)(int unitID);

	extern float(*const trCountUnitsInArea)(string centerUnit, int matchPlayer, string matchType, float range);

	// Removes the current control action so the next thing can take effect immediately.  (For IGC)
	extern void(*const trUnitCinematicRemoveControlAction)();

	// Sets the cinematic animation version for the selected unit(s).
	extern bool(*const trUnitSetAnimation)(string AnimName, int versionIndex, bool loop, int eventID, bool destroyOnNextControlAction);

	// Returns true if all selected units are alive.
	extern bool(*const trUnitAlive)();

	// Returns true if all selected units are dead.
	extern bool(*const trUnitDead)();

	// removes or kills the selected unit(s).
	extern bool(*const trUnitDelete)(bool remove);

	// destroys the selected unit(s).
	extern void(*const trUnitDestroy)();

	// creates a new unit.
	extern bool(*const trUnitCreate)(string protoName, string scenarioName, float x, float y, float z, int heading, int playerID);

	// returns the units heading.
	extern int(*const trUnitGetHeading)(string scenarioName);

	// sets the units heading.
	extern bool(*const trUnitSetHeading)(int degrees);

	// set the hitpoints for all selected units.
	extern int(*const trUnitSetHP)(float hitpoints);

	// returns true if the player can see the selected unit, and it is on screen.
	extern bool(*const trUnitVisToPlayer)();

	// returns true if the player can see the selected unit, otherwise returns false.
	extern bool(*const trUnitHasLOS)(int playerID);

	// converts the selected units to player.
	extern void(*const trUnitConvert)(int playerID);

	// returns the percent complete as 0 to 100
	extern int(*const trUnitPercentComplete)();

	// returns the percent damaged as 0 to 100
	extern int(*const trUnitPercentDamaged)();

	// moves units from current position to position specified
	extern void(*const trUnitTeleport)(float a, float b, float c);

	// does something to highlight the units selected.
	extern void(*const trUnitHighlight)(float seconds, bool a);

	// changes the proto unit for a given set of units.
	extern void(*const trUnitChangeProtoUnit)(string a);

	// returns the number of units contained.
	extern int(*const trUnitGetContained)();

	// returns true if this unit is contained by the specified protounit.
	extern bool(*const trUnitGetIsContained)(string protounit);

	// ejects all contained units.
	extern int(*const trUnitEjectContained)();

	// returns if the specified unit is selected.
	extern bool(*const trUnitIsSelected)();

	// returns if the specified unit is selected.
	extern bool(*const trUnitTypeIsSelected)(string a);

	// determines if the selected units are owned by the player specified.
	extern bool(*const trUnitIsOwnedBy)(int playerID);

	// set the stance for the given set of units.
	extern void(*const trUnitSetStance)(string a);

	// puts the camera in the specified location.
	extern void(*const trCameraCut)(vector pos, vector dir, vector up, vector right);

	// Clears the waypoints in the trigger selection system.
	extern void(*const trWaypointClear)();

	// Adds the waypoint into the trigger selection system.
	extern void(*const trWaypointAddPoint)(vector a);

	// Adds the unit's position as a waypoint in the trigger selection system.
	extern void(*const trWaypointAddUnit)(string unitScenarioName);

	// returns the current player.
	extern int(*const trCurrentPlayer)();

	// sets the current player as active or inactive.
	extern void(*const trSetCurrentPlayerStatus)(bool active);

	// sets the player controls on or off.
	extern void(*const trSetUserControls)(bool active);

	// returns the number of units for the player.
	extern int(*const trPlayerUnitCount)(int playerID);

	// returns the number of buildings for the player.
	extern int(*const trPlayerBuildingCount)(int playerID);

	// returns the number of units and buildings for the player.
	extern int(*const trPlayerUnitAndBuildingCount)(int playerID);

	// returns the number of units for the player.
	extern int(*const trPlayerUnitCountSpecific)(int playerID, string protoName);

	// tributes resources to a player.
	extern int(*const trPlayerTribute)(int from, string resource, int amount, int to);

	// Toggles whether the player's TC can spawn units.
	extern void(*const trPlayerToggleAllowTCSpawning)(int playerID, bool allowSpawning);

	// Toggles whether the player can spawn new covered wagons.
	extern void(*const trPlayerToggleAllowNewCWSpawning)(int playerID, bool allowSpawning);

	// returns the number of resources for the player.
	extern int(*const trPlayerResourceCount)(int playerID, string resource);

	// Returns the current (not total) XP for the player.
	extern int(*const trPlayerCurrentXPCount)(int playerID);

	// returns true/false if the player has been defeated.
	extern bool(*const trPlayerDefeated)(int playerID);

	// returns true/false if the player is active.
	extern bool(*const trPlayerActive)(int playerID);

	// call this when a player is defeated on the local machine (meaning that this func must be called synchronously on all machines, it will not pass around a command.)
	extern void(*const trSetPlayerDefeated)(int a);

	// call this when a player has won on the local machine (meaning that this func must be called synchronously on all machines, it will not pass around a command.)
	extern void(*const trSetPlayerWon)(int a);

	// Signal that the game has ended.
	extern void(*const trEndGame)();

	// sets the diplomacy status between players.
	extern void(*const trPlayerSetDiplomacy)(int playerID, int player2ID, string status);

	// gets the diplomacy status between players.
	extern string(*const trPlayerGetDiplomacy)(int playerID, int player2ID);

	// Adds/removes LOS between players.
	extern void(*const trPlayerModifyLOS)(int a, bool b, int c);

	// returns true if building is being built.
	extern int(*const trPlayerCountBuildingInProgress)(int playerID, string protoname);

	// Returns true if the proto unit specified is on the cursor and is a building.
	extern bool(*const trBuildingIsOnCursor)(string protoname);

	// sets the active player.
	extern int(*const trPlayerSetActive)(int playerID);

	// Completes the specified objective.  Forces a reoccurring objective complete if forceComplete is true.
	extern void(*const trObjectiveComplete)(int objectiveID, bool forceComplete, bool playSound);

	// Hides the specified objective on the UI.
	extern void(*const trObjectiveHide)(int objectiveID);

	// Shows the specified objective on the UI.
	extern void(*const trObjectiveShow)(int objectiveID);

	// 'Discovers' a previously unknown (to the player) objective.
	extern void(*const trObjectiveDiscover)(int objectiveID, bool playSound);

	// returns true if player is at pop cap.
	extern bool(*const trPlayerAtPopCap)(int playerID);

	// returns the player population.
	extern int(*const trPlayerGetPopulation)(int playerID);

	// Sets the unit as speaking or not.
	extern void(*const trSetCinematicUnitSpeaking)(string objectScenarioName, bool speaking, int duration);

	// sets a handler function for an event id.
	extern bool(*const trEventSetHandler)(int eventID, string handler);

	// cause an event to occur.
	extern void(*const trEventFire)(int eventID);

	// Sets whether or not units can do their idle processing.
	extern void(*const trSetUnitIdleProcessing)(bool a);

	// Sets whether or not units can be drawn obscured or not.
	extern void(*const trSetObscuredUnits)(bool a);

	// Turns letter box mode on or off.
	extern void(*const trLetterBox)(bool onOff);

	// Plays the sound associated with the filename.
	extern void(*const trSoundPlayFN)(string filename, string a, int b, string c, string d);

	// Plays the sound associated with the filename.
	extern void(*const trSoundPlayPaused)(string filename, string a, int b, string c, string d);

	extern void(*const trSoundTimer)(int milliseconds, int eventID);

	// Fades out current music over a given duration.
	extern void(*const trFadeOutMusic)(float duration);

	// Plays the next song in the music play list.
	extern void(*const trPlayNextMusicTrack)();

	// Fades out all sounds over a given duration
	extern void(*const trFadeOutAllSounds)(float duration);

	// Blocks all sounds from playing from this point forward
	extern void(*const trBlockAllSounds)(bool excludeDialog);

	// Unblocks all sounds that were previously blocked from playing
	extern void(*const trUnblockAllSounds)();

	// blocks all ambient sounds from this point forward
	extern void(*const trBlockAllAmbientSounds)();

	// Unblocks all ambient sounds that were previously blocked from playing
	extern void(*const trUnBlockAllAmbientSounds)();

	// Plays the sound associated with the filename.
	extern void(*const trSoundPlayDialog)(string filename, string event, int ignoreOnAbort, bool subtitle, string portrait, string a);

	// Plays the sound associated with the dialogue.
	extern void(*const trSoundPlayDialogue)(string stringID, int eventID, bool ignoreOnAbort, int seconds);

	// Plays the music file.
	extern void(*const trMusicPlay)(string filename, string duration, float a);

	// Plays the current music.
	extern void(*const trMusicPlayCurrent)();

	// Stops the current music.
	extern void(*const trMusicStop)();

	// sets the current music set.
	extern void(*const trMusicSetCurrentMusicSet)(int a);

	// Changes the music to mood associated with mood id.
	extern void(*const trMusicSetMood)(int moodID);

	// Loads a camera track.
	extern void(*const trCamTrackLoad)(string filename);

	// plays the current camera track.
	extern void(*const trCamTrackPlay)(float duration, int eventID);

	// displays the message text.
	extern void(*const trMessageSetText)(string text, int timeout);

	// Changes the chat status.
	extern void(*const trChatSetStatus)(bool onOff);

	// Changes the chat status.
	extern void(*const trChatSend)(int fromID, string message);

	// Changes the chat status for one specific player.
	extern void(*const trChatSendToPlayer)(int fromID, int toID, string message);

	// Changes the chat status, but does not append player.
	extern void(*const trChatSendSpoofed)(int fromID, string message);

	// Changes the chat status, but does not append player.  Goes to specific player.
	extern void(*const trChatSendSpoofedToPlayer)(int fromID, int toID, string message);

	// Writes text to the Age3Log
	extern void(*const trWriteToLog)(string message);

	// pause or unpause the game.
	extern void(*const trGamePause)(bool pause);

	// start a game using scenario.
	extern void(*const trGameLoadScenario)(string scenario);

	// pop up a dialog allowing choice to load a scenario.
	extern void(*const trBranchScenario)(string a);

	// returns true if tech is active for player.
	extern bool(*const trTechStatusActive)(int playerID, int techID);

	// returns true if tech is being researched for player.
	extern bool(*const trTechStatusResearching)(int playerID, int techID);

	// returns true if tech's status is techStatus.
	extern bool(*const trTechStatusCheck)(int playerID, int techID, int techStatus);

	// sets the tech status for the player.
	extern void(*const trTechSetStatus)(int playerID, int techID, int status);

	// player wins.  If you set directToMenu to true, you go directly to Campaign Menu.
	extern void(*const trYouWin)(bool directToMenu);

	// player loses, specifies message.
	extern void(*const trYouLose)(string text);

	// message and sound.
	extern void(*const trShowWinLose)(string text, string soundfile, string a, bool b);

	// turn sky rendering on/off and set which sky to use.
	extern void(*const trRenderSky)(bool render, string skyName);

	// controls snow rendering.
	extern void(*const trRenderSnow)(float percent);

	// controls rain rendering.
	extern void(*const trRenderRain)(float percent);

	// turn fog and black map on/off.
	extern void(*const trSetFogAndBlackmap)(bool fog, bool blackMap);

	// add help string.
	extern void(*const trStartGameRecord)(string a);

	// add help string.
	extern void(*const trStopGameRecord)();

	// selects the units in the army specified.
	extern void(*const trArmySelect)(string army);

	// selects the units in the army specified.
	extern void(*const trArmySelectInt)(int playerID, int armyID);

	// creates the units in the army specified.
	extern bool(*const trArmyDispatch)(string parameters, string a, int b, float c, float d, float e, int f, bool g);

	// fades to the specified lighting set over fadetime.
	extern void(*const trSetLighting)(string setname, float fadetime);

	// start a counter that may or may not fire an event.
	extern void(*const trCounterAddTime)(string name, int start, int stop, string message, int event);

	// start a counter that may or may not fire an event.
	extern void(*const trCounterAddTimeMs)(string name, int start, int stop, string message, int event);

	// start a counter that may or may not fire an event.
	extern void(*const trCounterAddUnit)(string name, int playerid, int count, string protounit, string message, int event);

	// start a counter that may or may not fire an event.
	extern void(*const trCounterAddXP)(string a, int b, int c, string d, int e);

	// abort a counter.
	extern void(*const trCounterAbort)(string name);

	// returns the abort cinematic status.
	extern bool(*const trCinematicAbort)();

	// aborts the cinematic.
	extern void(*const trCinematicDoAbort)();

	// forces models to be in non cinematic mode
	extern void(*const trForceNonCinematicModels)(bool a);

	// scales the formation size of formations in the game.
	extern void(*const trFormationScale)(float scale);

	// Returns the number of nuggets gathered by the specified player.
	extern int(*const trGetNumberNuggetsGathered)(int a);

	// Returns true if the nugget has been collected, the playerID is an optional parameter for querying if the specific player has collected it.
	extern bool(*const trHasNuggetBeenCollected)(string a, int b);

	// flashes a UI element.
	extern void(*const trUIFlash)(string gadget, int name, float flashLimit, float colorR, float colorG);

	// stops the flashing of a UI element.
	extern void(*const trUIStopFlash)(string gadget);

	// flashes a UI element (maybe).
	extern void(*const trUIFlashTech)(int a, bool b);

	// flashes a UI element (maybe).
	extern void(*const trUIFlashTrain)(string a, bool b);

	// fade in/out using color specified.
	extern void(*const trUIFadeToColor)(int r, int g, int b, int duration, int delay, bool inout, int a);

	// modify construction rate.
	extern void(*const trRateConstruction)(float rate);

	// modify training rate.
	extern void(*const trRateTrain)(float rate);

	// modify research rate.
	extern void(*const trRateResearch)(float rate);

	// restore all rates to normal.
	extern void(*const trRatesNormal)();

	// Sends a Minimap flare to a certain player.
	extern void(*const trMinimapFlare)(int playerID, float duration, vector position, bool flash);

	// Makes the camera shake.
	extern void(*const trCameraShake)(float duration, float strength);

	// Resets the black map for a given HUMAN player.
	extern void(*const trPlayerResetBlackMap)(int playerID);

	// Resets the black map for all HUMAN players.
	extern void(*const trPlayerResetBlackMapForAllPlayers)();

	// Kills all of the units of a given player.
	extern void(*const trPlayerKillAllUnits)(int playerID);

	// Kills all of the buildings of a given player.
	extern void(*const trPlayerKillAllBuildings)(int playerID);

	// returns true if gadget is real.
	extern bool(*const trIsGadgetVisible)(string name);

	// enters the mode specified.
	extern void(*const trModeEnter)(string name);

	// advances the campaign.
	extern void(*const trPlayerGrantResources)(int player, string resource, int amount);

	// Sets the selected unit as having the fake player with the specified index (0-7)
	extern void(*const trUnitPlayerFakify)(int fakePlayerIndex);

	// Fakifies the army to the specified fake player index.
	extern void(*const trArmyPlayerFakify)(string armyname, int fakeplayerindex);

	// Sets the selected unit as not having a fake player
	extern void(*const trUnitPlayerDefakify)();

	// Defakifies the army.
	extern void(*const trArmyPlayerDefakify)(string armyname);

	// Makes the camera shake.
	extern void(*const trAIFunc)(int playerID, string functionName, int param);

	extern int(*const trGetNumberSelectedUnitIDs)();

	extern int(*const trGetSelectedUnitID)(int index);

	// removes protounit from the forbidden list
	extern bool(*const trUnforbidProtounit)(int player, string protoname);

	// adds protounit to the forbidden list
	extern bool(*const trForbidProtounit)(int player, string protoname);

	extern void(*const trSetPauseOnAgeUpgrade)(bool a);

	extern void(*const trSetPauseInObjectiveWindow)(bool a);

	extern void(*const trSetCounterDisplay)(string text);

	extern void(*const trClearCounterDisplay)();

	// plays movies from the AVI directory
	extern void(*const trPlayMovie)(string fileName);

	// returns false if a movie is currently playing
	extern bool(*const trIsMovieNotPlaying)();

	// shows whole map, similar to how revealed mode works
	extern void(*const trRevealEntireMap)();

	// set an override name for a specific unit
	extern void(*const trUnitChangeName)(string name);

	// returns whether or not the current chat history has any instance (substring) of this text
	extern bool(*const trChatHistoryContains)(string text, int a);

	// forces the chat history to reset
	extern void(*const trChatHistoryClear)();

	// fetch a stat value from the KB
	extern int(*const trGetStatValue)(int player, int stat);

	// fetch a stat value from the KB and echo to chat
	extern void(*const trEchoStatValue)(int player, int stat);

	// displays a custom image in a dialog, with a subtitle
	extern void(*const trShowImageDialog)(string texture, string subtitle);

	// displays dialog with 2 choices, and activates a trigger in response
	extern void(*const trShowChoiceDialog)(string maintext, string choice1, int event1, string choice2, int event2);

	// modifies proto unit data for this scenario only.
	extern void(*const trModifyProtounit)(string unit, int player, int field, float delta);

	// does % percent of a unit's total HP in instant typeless damage.
	extern void(*const trDamageUnitPercent)(float percent);

	// does a specific amount of damage to HP in instant typeless damage.
	extern void(*const trDamageUnit)(float amt);

	// All units within dist of the selected ref object that match type take dmg
	extern void(*const trDamageUnitsInArea)(int player, string unitType, float dist, float damage);

	// puts up a big movie-credits style text overlay, optionally in a strange location, and now with a background
	extern void(*const trOverlayText)(string message, float time, int x, int y, int width, string background);

	// sets one of the trigger scratch variables
	extern void(*const trQuestVarSet)(string varname, float value);

	// copies value of one of the trigger scratch variables
	extern void(*const trQuestVarCopy)(string var1, string var2);

	// sets one of the trigger scratch variables within a random range
	extern void(*const trQuestVarSetFromRand)(string varname, float minval, float maxval, bool round);

	// retrieve value of a trigger scratch variable, returns zero if unset
	extern float(*const trQuestVarGet)(string varname);

	// chats out the value of one of the trigger scratch variables
	extern void(*const trQuestVarEcho)(string varname);

	// Grants a number of Scenario VP to a player
	extern void(*const trGrantVP)(int player, int number);

	// returns the number of victory points for the player.
	extern int(*const trPlayerVPCount)(int playerID);

	// enables/disables the award of VP's each year.
	extern void(*const trVPAnnualAwards)(bool enable);

	extern void(*const trCreateTreaty)(int a, int b, int c, bool d, bool e, float f, float g, float h);

	// returns the current gameplay mode index
	extern int(*const vcGetGameplayMode)();

	// checks for victory by being the last allied-unit alive
	extern bool(*const vcCheckConquestVictory)();

	// Moves the selected unit(s) to face the given unit.
	extern bool(*const trUnitFaceUnit)(string unitScenarioName, int eventID);

	// Orients the camera to the selected unit, and keeps it locked on that unit. ): puts the camera in the specified location.
	extern void(*const trCameraLockOnUnit)(bool enable, int time, int to);

	// Moves the camera in the same direction that a particular unit moves.
	extern void(*const trCameraPanWithUnit)(bool enable, int trigger);

	// Disables (sets active = false) the trigger specified by the given eventID.
	extern void(*const trDisableTrigger)(int eventID);

	// Makes a unit invulnerable to damage.  Turn it off to return the unit to normal.
	extern void(*const trUnitMakeInvulnerable)(bool enable);

	// Makes an action on a unit suspened or not.
	extern void(*const trUnitSuspendAction)(string actionName, bool suspend);

	// No help 
	extern void(*const trCreateDefendPlan)(string armyName, string defendPlanName, float defendX, float defendY, float defendZ, float engageRange, int evaluationFrequency, float gatherdistance);

	// No help 
	extern void(*const trCreateAttackPlan)(string armyName, string PlanName, int attackPlayerID, float attackX, float attackY, float attackZ, float engageRange, int evaluationFrequency);

	// No help 
	extern void(*const trKillAIPlan)(int playerID, string planName);

	// Adds the units in the specified army to the specified plan.
	extern void(*const trAddArmyToPlan)(string armyname, string planname);

	// srcArmy units will defend defendedArmyUnits in the given planname.
	extern void(*const trDefendUnits)(string srcArmyname, string defendedArmyname, string planname, int evaluationFrequency, float gatherdistance);

	// srcArmy units will attack armyToAttack in the given planname.
	extern void(*const trAttackUnits)(string srcArmyname, string armyToAttack, string planname);

	// playerID will attack armyToAttack, sent via player Comms.
	extern void(*const trAICommsAttackUnits)(int playerID, string armyToAttack);

	// playerID will defend point(defendX, defendY, defendZ), sent via player Comms.
	extern void(*const trAICommsDefendPoint)(int playerID, float defendX, float defendY, float defendZ);

	// fromPlayerID will send resource of x amount, sent via player Comms.
	extern void(*const trAICommsRequestTribute)(int fromPlayerID, string resource, float amount);

	// tell player sendToPlayerID to cancel order, sent via player Comms.
	extern void(*const trAICommsCancelOrder)(int sendToPlayerID);

	// tell player sendToPlayerID to claim TradePost at (locX, locY, locZ), sent via player Comms.
	extern void(*const trAICommsClaim)(int sendToPlayerID, float a, float b, float c);

	// tell player sendToPlayerID to train Units of type unitTypeName, sent via player Comms.
	extern void(*const trAICommsTrain)(int sendToPlayerID, string unitTypeName);

	// Places train on a specified position on the route.
	extern void(*const trTradeRouteSetPosition)(int position, float a);

	// Enable or disables the unit from showing.
	extern void(*const trTradeRouteToggleState)(int position, bool a);

	// Sets the specified trade route to the specified level from a trigger.
	extern void(*const trTradeRouteSetLevel)(int traderouteindex, int level);

	// Enable or disables the shadow far clippping plane.
	extern void(*const trSetShadowFarClip)(bool enable, float distance);

	// Displays the SPC Note Dlg with the specified title and text.
	extern void(*const trShowSPCNote)(string Title, string Text);

	// Overrides the culture used for choosing the player's art.
	extern void(*const trPlayerOverrideArtCulture)(int playerID, string culture);

	// Overrides the civilization used for choosing the player's vocal sound effects.
	extern void(*const trPlayerOverrideSoundCiv)(int playerID, string civilization);

#else
	// maps input event to command, in that context.  See input mapper design.doc for more details.
	void map(string eventString = "None", string contextString = "None", string commandString = "None");

	// sends a message to the console output
	void echo(string stringMessage = "None");

	// sets the game status text from a string in the string resource.
	void echoLocalized(int stringID = -1);

	// sends a number to the console output
	void echoNum(int stringMessage = -1);

	// enables or disables IME
	void IMEEnable(bool enable = true);

	// toggles the state of the console dialog
	void console();

	// with no arg, toggles pause state on/off.  otherwise, sets pause state
	void pause(int integerState = -1, bool checkForAllowPause = true);

	// with no arg, toggles pause state on/off.  otherwise, sets pause state
	void pause2(int integerState = -1);

	// forces the game to unpause
	void unpauseNoChecks();

	// exits the game
	void exit(bool a = true);

	// take a screen shot
	void screenshot();

	// take a screen shot
	void hackscreenshot(int a = 0);

	// changes screen resolution.
	void res(int integerXRes = -1, int integerYRes = -1);

	// changes screen resolution and bit depth.
	void resbpp(int integerXRes = -1, int integerYRes = -1, int integerBPP = -1);

	// undoes the last editing operation.
	void undo();

	// Re-does the last undone operation.
	void redo();

	// realigns all resources in the world to tile boundaries
	void alignResources();

	// realigns all selected units to tile boundaries
	void alignSelectedUnits();

	// Sends out a market use command for the given player, resource and amount.  Negative means selling.
	void resourceMarket(int intPlayerID = -1, string stringResourceTo = "none", float floatAmount = -1, string stringResourceFrom = "none");

	// spews database values on the specified unit or the selected unit (if no argument).
	void unitData(int intUnitID = -1);

	// Sets the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	void unitSetVariation(int Variation = -1, int UnitID = -1);

	// Increments the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	void unitIncVariation(int UnitID = -1);

	// Decrements the current variation of the given UnitID (current selected unit(s) if UnitID is -1).
	void unitDecVariation(int a = -1);

	// Sets the unit stance for all selected units to aggressive.
	void unitSetStanceAggressive();

	// Sets the unit stance for all selected units to defensive.
	void unitSetStanceDefensive();

	// Sets the unit stance for all selected units to passive.
	void unitSetStancePassive();

	// Sets the tactic for this unit.
	void unitSetTactic(string a = "");

	// Toggles stealth mode for this unit.
	void unitToggleStealth();

	// Sets the mode for a squad.
	void squadMode(int a = 0, int b = -1);

	// Sets the mode for a squad.
	void setSquadMode(string a = "");

	// Wheels the squad.
	void squadWheel(float angle = 0.785398, int squadID = -1);

	// Issues a town bell for the selected unit(s).
	void unitTownBell();

	// Issues a return to work for the selected unit(s).
	void unitReturnToWork();

	// Toggles between different ways obscured units are shown.
	void obscuredUnitToggle();

	// sends to output a list of all current config vars
	void configDump(string a = "");

	// sets a particular config var to a string value
	void configSet(string stringName = "None", string stringValue = "None");

	// sets a config var to an integer value
	void configSetInt(string stringName = "None", int integerValue = -1);

	// sets a config var to a floating point value
	void configSetFloat(string stringName = "None", float floatValue = -1);

	// defines a config variable
	void configDef(string stringName = "None");

	// un-defines a config variable
	void configUndef(string stringName = "None");

	// defined var becomes undefined, and vice versa
	void configToggle(string stringName = "None");

	// changes config state just like a .cfg line
	void config(string stringToken = "None");

	// look up config by enum ID
	void configGetByID(int intValue = -1);

	// show all formally defined config variables that contain the filter string, or use no parameters for a full list.
	void configHelp(string symbolFilter = "");

	// show all formally defined config variables that start with the filter string, or use no parameters for a full list.
	void configHelpPrefix(string symbolFilter = "");

	// saves out a game in progress.
	void saveGame(string stringFilename = "None");

	// saves out a scenario file.
	void saveScenario(string stringFilename = "None");

	// loads in a saved game.
	void loadGame(string stringFilename = "None");

	// loads in a scenario file.
	void loadScenario(string stringFilename = "None");

	// loads in a tutorial scenario file.
	void loadTutorial(string stringFilename = "None", int loadMode = -1, string loadImage = "None", int textID = -1, bool isAge3Scenario = true);

	// loads in a campaign scenario file.
	void loadCampaignScenario(string stringFilename = "None");

	// loads the file named, interpreting whether it is a scenario, savegame, etc. dynamically
	void loadRecentFile(string stringFilename = "None");

	// save camera to file.
	void saveCamera(string stringFilename = "");

	// save camera to file.
	void saveCurrentHomeCityCamera();

	// save widescreen camera to file.
	void saveCurrentHomeCityWidescreenCamera();

	// load camera from file.
	void loadCamera(string stringFilename = "");

	// re-launch current scenario.
	void restart();

	// filters the entire terrain.
	void terrainFilter();

	// filters a sub-area of the terrain.
	void terrainFilterArea(int integerX1 = -1, int integerY1 = -1, int integerX2 = -1, int integerY2 = -1);

	// flattens the entire terrain.
	void terrainFlatten(float a = -999);

	// flattens a sub-area of the terrain.
	void terrainFlattenArea(int integerX1 = -1, int integerY1 = -1, int integerX2 = -1, int integerY2 = -1);

	// sets the terrain type to paint.
	void terrainSetType(int integerType = -1);

	// sets the terrain subtype to paint.
	void terrainSetSubtype(int integerType = -1);

	// sets the terrain mix to paint.
	void terrainSetMix(int integerType = -1);

	// paint whole terrain with given texture.
	void terrainPaint(string a = "None");

	// paint whole terrain with given mix.
	void terrainPaintMix(string a = "None");

	// Set terrain ambient reflectivity to the given RGB (0-255)
	void terrainAmbient(int integerR = -1, int integerG = -1, int integerB = -1);

	// adjusts (raise/lower) the terrain height by the specified meters.
	void terrainAdjustGlobalHeight(float meters = 0);

	// sets whether camera limiting is on.
	void cameraRotate(int integerState = -1);

	// puts the camera in a reasonable orientation.
	void cameraNice();

	// intended for ui use only.  Indicates that camera forward key has gone up or down.
	void cameraForward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera world forward key has gone up or down.
	void cameraWorldForward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera world forward & left key has gone up or down.
	void cameraWorldForwardLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera world forward & right key has gone up or down.
	void cameraWorldForwardRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera backward key has gone up or down.
	void cameraBackward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera world backward key has gone up or down.
	void cameraWorldBackward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera world backward & left key has gone up or down.
	void cameraWorldBackwardLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera world backward & right key has gone up or down.
	void cameraWorldBackwardRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera right key has gone up or down.
	void cameraRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera left key has gone up or down.
	void cameraLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera up key has gone up or down.
	void cameraUp(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera down key has gone up or down.
	void cameraDown(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera pitch forward key has gone up or down.
	void cameraPitchForward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera pitch backward key has gone up or down.
	void cameraPitchBackward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera roll left key has gone up or down.
	void cameraRollLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera roll right key has gone up or down.
	void cameraRollRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera yaw right key has gone up or down.
	void cameraYawRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera yaw left key has gone up or down.
	void cameraYawLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera 'Local Yaw right' key has gone up or down.
	void cameraLocalYawRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that camera 'Local Yaw left' key has gone up or down.
	void cameraLocalYawLeft(int integerKeyState = -1);

	// debug command to spew info about the current state of the game camera
	void cameraDump();

	// loads a camera track and makes it current
	void trackLoad(string stringFilename = "None");

	// saves the current camera track
	void trackSave(string stringFilename = "None");

	// clears all tracks.
	void trackClear();

	// steps the current camera track 1 step forward.
	void trackStepForward();

	// steps the current camera track 1 step backward.
	void trackStepBackward();

	// toggles rendering of the camera track on and off.
	void trackToggleShow();

	// adds the camera's current position and orientation to the current camera track.
	void trackAddWaypoint();

	// edits the currently selected camera track.
	void trackEditWaypoint();

	// sets the current waypoint to the button with the same index.
	void trackSetSelectedWaypoint(int index = -1);

	// moves the camera to the current waypoint.
	void trackGotoSelectedWaypoint(int index = -1);

	// removes the most recently added track waypoint from the current camera track.
	void trackRemoveWaypoint();

	// adds a new camera track.
	void trackInsert();

	// removes selected track.
	void trackRemove();

	// plays a track file (otherwise if "none" than plays the current track.) with no arg uses current duration, otherwise sets duration
	void trackPlay(float duration = -1, int eventID = -1);

	// pauses the current camera track.
	void trackPause();

	// stops the current camera track.
	void trackStop();

	// advances the camera track to a specific location.
	void trackAdvance(float a = -1);

	// moves the camera to the current event.
	void trackGotoSelectedEvent(int index = -1);

	// increments the area to render.
	void areaIncrementAreaToRender(int playerID = -1);

	// toggle shadows on/off
	void toggleShadows();

	// set the quality level of shadows
	void setShadowQuality(int qualityLevel = 0);

	// set the shadow buffer bias multipler (supaScreenshot only)
	void setShadowBiasMul(float biasMultiplier = 0);

	// controls shadow matrix snapping
	void setShadowSnapping(int a = 0);

	// controls shadow projection rotation optimization
	void setShadowRotationOp(int a = 0);

	// with no arg, toggles window/fullscreen.  otherwise, sets mode to window(1)/fullscreen(0)
	void renderWindow(int integerState = -1);

	// sets the render state of the given base (no integerState toggles).
	void renderBaseID(int playerID = -1, int areaID = -1, int integerState = -1);

	// sets the render state for all areas (no arg toggles).
	void renderAreas(int playerID = -1, int integerState = -1);

	// draws areas and color-codes them by danger level.
	void renderAreaDangerLevels(int playerID = -1, int state = -1);

	// sets the render state of the given area (no integerState toggles).
	void renderAreaID(int playerID = -1, int areaID = -1, int integerState = -1);

	// sets the render state of the given area (no integerState toggles).
	void renderAreaGroupID(int playerID = -1, int areaGroupID = -1, int integerState = -1);

	// sets desired anisotropy
	void renderAnisotropic(int integerState = -1);

	// sets HDR multisample factor [1,8] - 1 is disabled
	void setHDRMultisampleFactor(int a = 1);

	// sets HDR supersampling factors (1.0 to 2.0, both 1.0 is off)
	void setSuperSampleFactors(float floatX = 1, float floatY = 1);

	// sets supersample kernel scales(1.0 = normal, less = blurrier, higher = sharper)
	void setSuperSampleFilterScales(float floatX = 1, float floatY = 1);

	// sets supersample filter kernel
	void setSuperSampleFilterIndex(int a = 0);

	// sets trilinear filtering on/off
	void renderTrilinear(int integerState = -1);

	// with no arg, toggles friend or foe colors.  otherwise, sets it
	void renderFriendOrFoe(int integerState = -1);

	// Set ambient color to given RGB (0-255)
	void ambientColor(int integerR = 0, int integerG = 0, int integerB = 0);

	// Get ambient color
	void ambientGetColor();

	// reset the sun color to full
	void resetAmbientColor();

	// Set ambient color 2 to given RGB (0-255)
	void ambientColor2(int integerR = 0, int integerG = 0, int integerB = 0);

	// Set shadow darkness (0-255) - (PCF Filter Sclar 0-16)
	void shadowDarkness(float integerDarkness = 0, float pcfFilterScalar = 0, float biasNV = 0, float biasATI = 0, float slope = 0);

	// Set sun color to given RGB (0-255)
	void sunColor(int integerR = 0, int integerG = 0, int integerB = 0);

	// Get sun color
	void sunGetColor();

	// reset the sun color to full
	void resetSunColor();

	// Set fake sun params for water
	void fakeSunParams(float intensity = 0, float specIntensity = 0, float specPower = 0, float inclination = 0, float rotation = 0);

	// sets a hemilight
	void setHemiLight(float topColorR = 0, float topColorG = 0, float topColorB = 0, float bottomColorR = 0, float bottomColorG = 0, float bottomColorB = 0, float axisYaw = 0, float axisPitch = 0, float intensity = 0, float unitIntensity = 0, float terrainIntensity = 0);

	// sets scene light params
	void setSceneLightParams(float sunIntensity = 0, float power = 0, float specIntensity = 0, float metalness = 0, float fogColorR = 0, float fogColorG = 0, float fogColorB = 0, float fogDensity = 0, float fogStart = 0);

	// set Planar Height Params
	void setFogParams(float planarfogColorR = 0, float planarfogColorG = 0, float planarfogColorB = 0, float planarfogDensity = 0, float planarfogHeight = 0);

	// sets scene bump scale
	void setBumpScale(float scale = 0);

	// sets the selected units to use the fake player indicated.
	void unitPlayerFakify(int fakePlayerIndex = 0);

	// sets the selected units to stop using a fake player.
	void unitPlayerDefakify();

	// sets tonemap params
	void setToneMapParams(float exposure = 0, float dispGamma = 0, float greyFStops = 0, float kneeLow = 0, float kneeHigh = 0, float ditherNoiseInten = 0);

	// sets tonemap params
	void setBloomParams(float bloomThreshold = 0, float bloomColorR = 0, float bloomColorG = 0, float bloomColorB = 0, float bloomIntensity = 0, float bloomPass = 0, float bloomSigma = 0);

	// sets LDR Bloom params
	void setLDRBloomParams(float bloomColorR = 0, float bloomColorG = 0, float bloomColorB = 0, float bloomIntensity = 0, float bloomSigma = 0);

	// sets bloom streak params
	void setBloomStreakParams(float streakCount = 0, float Passes = 0, float ElementOffset = 0, float Exposure = 0, float Intensity = 0, float Falloff = 0, float streakRed = 0, float streakGreen = 0, float streakBlue = 0, float threshold = 0);

	// sets bloom feedback params
	void setBloomFeedbackParams(float currentFrameContribution = 0, float lastFrameContribution = 0);

	// sets Terrain Lighting Params
	void setTerrainLightingParams(float bumpScale = 0, float specularPower = 0, float specularIntensity = 0, float terrainMetalness = 0);

	// Applies a Lighting set
	void applyLightingSet(string name = "");

	// Saves the current status of lighting values as a set
	void saveLightingSet(string name = "");

	// loads the specified lighting set
	void loadLightingSet(string name = "", bool apply = true);

	// sets the circular brush size
	void brushCircularSize(float floatValue = 0);

	// stop playing music
	void musicStop();

	// set the current music volume (0.0 - 1.0)
	void musicSetVolume(float volume = 0);

	// play a sound as if it were a music track
	void musicPlaySong(string songname = "None", float fadetime = 0);

	// toggles between battle mode and normal mode
	void musicToggleBattleMode();

	// with no arg, cycles through the various status display modes.  otherwise sets display type
	void displayType(int integerState = -1);

	// with no arg, outputs current player.  otherwise, sets current player to given argument
	void player(int integerPlayer = -1);

	// toggles or sets LOS fog.
	void fog(int integerState = -1);

	// toggles or sets unexplored black map rendering.
	void blackmap(int integerState = -1);

	// enters the named mode.
	void modeEnter(string stringMode = "None");

	// starts the given campaign.
	void startCampaign(string campaignName = "");

	// Wrapper that enters GameMenu mode if the player isn't resigned.
	void uiEnterGameMenuModeIfNotResigned();

	// toggles between the two modes only if we're not in a BMultiplayer game.
	void modeToggleBetweenIfNotMP(string stringMode1 = "None", string stringMode2 = "None");

	// Lists all of the commands that start with the given prefix
	void helpPrefix(string commandPrefix = "");

	// Lists all of the commands that contain the given substring
	void help(string commandSubstring = "");

	// Lists all of the commands that contain the given substring in their help text.
	void helpText(string helptextSubstring = "");

	// looks at given x,z location on terrain.
	void lookAt(float x = 0, float z = 0);

	// looks at given kb army.
	void lookAtArmy(int playerID = -1, string armyName = "");

	// reloads the player colors from the XML file
	void resetDefaultPlayerColors();

	// sets the minimap filter for units
	void setMinimapUnitFilter(int a = 0);

	// Sets the graphic detail.  (0 = HIGH, 1 = MEDIUM, 2 = LOW)
	void setGraphicDetail(int detailLevel = 0);

	// Sets the world difficulty level.
	void setWorldDifficulty(int v = -1);

	// Start the auto patcher.
	void startAutoPatcher(bool manualMode = true);

	// Cancel the auto patcher.
	void cancelAutoPatcher();

	// Used to tell autpatcher user pressed OK on exit or error dialog.
	void confirmAutoPatcher();

	// Plays movies from a playlist in the AVI directory
	void playMovie(string a = "playlist.aom");

	// Toggles home city view for the current player.
	void toggleHomeCityView();

	// Toggles tech home city view for the current player.
	void toggleHomeCityViewTech();

	// View the specific home city building.
	void lookAtHomeCityBuilding(int building = -1);

	// Trains the given PUID from the given home city building.
	void homeCityTrain(int playerID = -1, int buildingID = -1, int puid = -1);

	// Sends the given HC card in the home city.
	void homeCityTrain2(int playerID = -1, int cardIndex = -1);

	// Transports units from the home city.
	void homeCityTransport(int playerID = -1);

	// starts the four of a kind victory if valid.
	void fourOfAKind();

	// starts the Relic Capture victory if valid.
	void relicCapture();

	// starts the King of the Hill victory if valid.
	void kothVictory();

	// Adds the given command to the trade post bucket.
	void tradeRouteCommand(int playerID = -1, int tradeRoutUnit = -1, int commandID = -1);

	// Trains the given PUID from the given trade post on the trade route.
	void tradeRouteTrain(int playerID = -1, int tradeRoutUnit = -1, int puid = -1);

	// Researches the given command from the given unit.
	void commandResearch(int commandID = -1, int unitID = -1, int a = -1, int b = -1);

	// Trains the given merc from the given home city building.
	void mercTrain(int playerID = -1, int buildingID = -1, int puid = -1);

	// Cancels the given unit out of the ship.
	void homeCityShipEject(int playerID = -1, int buildingID = -1, int puid = -1, int index = -1);

	// Loads a grouping.  No parameter pops up dialog.
	void loadGrouping(string groupingName = "");

	// Loads a grouping from the user writable grouping directory.
	void loadUserDefinedGrouping(string groupingName = "");

	// For UI use only.
	void loadGroupingUnicode(string a = "");

	// For UI use only.
	void loadGroupingUnicodeLUA(int a = -1, string b = "");

	// Starts the auto repair on the specified unit.
	void repairUnit(int unitID = -1);

	// Cancels the auto repair on the specified unit.
	void cancelRepairUnit(int unitID = -1);

	// Sets the home city gather point to the specified unit.
	void setHomeCityGatherUnit(int unitID = -1);

	// Convert a covered wagon into a Town Center
	void convertCoveredWagon();

	// break your treaties
	void breakTreaty();

	// ransoms your explorer
	void ransomExplorer();

	// Toggles whether or not world tooltips are using the restricted screen rectangle.
	void toggleWorldTooltipClipRect();

	// Toggles whether or not to draw the world tooltip restricted screen rectangle.
	void drawWorldTooltipClipRect();

	// Sets the world tooltip restricted screen rectangle to the given dimensions relative to 1024x768 resolution.
	void setWorldTooltipRectDims1024(int minX = -1, int minY = -1, int maxX = -1, int maxY = -1);

	// UI use - upgrade the trade route associated with this unit.
	void upgradeTradeRoute(int unitID = -1);

	// Spawn Units from the UnitID building.
	void spawnUnits(string protoname = "", int count = -1, int unitID = -1);

	// Explorer Abilities use.
	void ability(int abilityId = -1, int unitID = -1, bool doWhenNotSelected = false);

	// use ability in proto unit type if the player has one
	void doAbilityInType(string protoPowerName = "", string a = "");

	// use ability in current unit selection.
	void doAbilityInSelected(string protoPowerName = "");

	// use command in current unit selection.
	void doCommandInSelected(string a = "");

	// Special power use.
	void specialPower(int playerID = -1, int powerEntryIndex = -1, int powerID = -1);

	// Set vertical syncing (-1 toggles, 0 is off, 1 is on).
	void vsync(int state = -1);

	// Start fullscreen playback of a movie.
	void startMoviePlayback(string filename = "", int sizing = 0, float fadeIn = 0, float fadeOut = 0);

	// Trains a reinforcement.
	void trainReinforcement(int armyID = -1);

	// Cancel training of a reinforcement.
	void cancelTrainReinforcement(int armyID = -1);

	// Set mip levels to skip for default category textures.
	void setDropDefaultMips(int num = -1);

	// Set mip levels to skip for terrain category textures.
	void setDropTerrainMips(int num = -1);

	// Display's the SPC Note Dialog with the specified title and text.
	void showSPCNote(string title = "", string text = "");

	// forces the renderer to reset.
	void renderForceReset();

	// Editor only function that activates/deactivates a given tech
	void editorSetTechStatus(string techToActivate = "", bool active = true);

	// Editor only functions. goes thru all the units and updates thier visuals.
	void editorUpdateUnitVisuals();

	// Editor use - sets all trade route definitons to the spedified definition.
	void editorSetAllTradeRoutesToDef(string newDefName = "");

	// Start the research of TechID from ResearchingUnitID for the current player (if no player is specified)
	void researchByID(int TechID = -1, int ResearchingUnitID = -1, int Player = -1, bool a = true);

	// research a tech in current unit selection.
	void researchTechInSelected(string techName = "");

	// Start the training of a unit of ProtoUnitID from TrainingUnitID for the current player (if no player is specified)
	void trainByID(int ProtoUnitID = -1, int TrainingUnitID = -1, int Player = -1);

	// tries to train the selected unit type in any valid selected unit
	void trainInSelected(string stringProtoName = "None", int traincount = 1);

	// cancel training of a unit type in any valid selected unit
	void cancelTrainInSelected(int ProtoUnitID = -1, bool All = false);

	// cancel researching of a tech in any valid selected unit
	void cancelResearchInSelected(int TechID = -1);

	// just like train in selected, but fastAr because it takes a protoID
	void trainInSelectedByID(int protoID = -1, int traincount = 1);

	// plays the default UI click sound.
	void click();

	// Researches the given home city tech.
	void homeCityResearch(int playerID = -1, string techName = "");

	// Researches the given home city tech.
	void homeCityResearchByID(int playerID = -1, int techName = -1);

	// Activates the given home city tech.
	void homeCityMakeActiveByID(int playerID = -1, int techName = -1);

	// Researches the given home city tech when a game is not active.
	void homeCityResearchByIDOutsideGame(int playerID = -1, int techName = -1);

	// Researches the given home city tech when you are *really* completely out side of the game.
	void homeCityResearchByIDPregame(int techID = -1);

	// changes the edit mode
	void editMode(string symbolModeName = "None");

	// instructs the currently selected unit(s) to build the current proto unit cursor building type at the pointer location.
	void uiBuildAtPointer();

	// Sets the orientation of a formation.
	void uiFormationOrientation();

	// instructs the currently selected unit(s) to build the current proto unit cursor building type at the pointer location, with wall-like endpoint behavior.
	void uiBuildWallAtPointer(bool a = false);
	
	void uiCreateRiverToggleWaypointMode();
	
	void uiPlaceRiverWaypoint();
	
	void uiRemoveRiverWaypoint();
	
	void uiCreateRiver();
	
	void uiCreateRandomRiver();
	
	void uiPlaceRiverShallow();
	
	void uiRemoveRiverShallow();

	// intended for ui use only.  Rotate river shallow with wheel -- i.e. intended to be mapped to wheel
	void uiWheelRotateRiverShallow(int a = -1);

	// Sets the gather points for the selected unit(s) to the pointer position.
	void uiSetGatherPointAtPointer(bool homeCity = false, bool water = false);

	// Sets the HC spawn point.
	void uiSetHomeCityWaterSpawnPointAtPointer();

	// Clears the gather point for the selected unit(s), returning it to a default state.
	void uiClearGatherPoint();

	// transforms the selected unit into the specified proto unit.
	void uiTransformSelectedUnit(string a = "");

	// Sends out a flare at the pointer position.
	void uiFlareAtPointer();

	// Used when flaring a position for player comms dialog.
	void uiCommsFlareAtPointer();

	// Sends out a Help at the pointer position.
	void uiHelpAtPointer();

	// Commands the selected unit(s) to garrison in a building at the pointer position.
	void uiGarrisonToPointer();

	// Commands the selected unit(s) to repair the target building at the pointer position.
	void uiRepairAtPointer();

	// Commands the selected unit(s) to Empower the target building at the pointer position.
	void uiEmpowerAtPointer();

	// sets the cursor to a proto-unit.
	void uiSetProtoCursor(string stringProtoName = "None", bool setPlacement = false);

	// sets the cursor to a proto-unit.
	void uiSetProtoCursorID(int integerProtoID = -1);

	// enters the specified UI context.
	void uiEnterContext(string stringContext = "None");

	// leaves the specified UI context.
	void uiLeaveContext(string stringContext = "None");

	// resets the cursor to the basic pointer.
	void uiClearCursor();

	// intended for ui use only.  Indicates that the yaw unit right key has gone up/down.
	void uiYawUnitRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the yaw unit left key has gone up/down.
	void uiYawUnitLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the pitch unit up key has gone up/down.
	void uiPitchUnitUp(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the pitch unit down key has gone up/down.
	void uiPitchUnitDown(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the roll unit right key has gone up/down.
	void uiRollUnitRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the roll unit left key has gone up/down.
	void uiRollUnitLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the move unit forward key has gone up/down.
	void uiMoveUnitForward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the move unit backward key has gone up/down.
	void uiMoveUnitBackward(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the move unit right key has gone up/down.
	void uiMoveUnitRight(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the move unit left key has gone up/down.
	void uiMoveUnitLeft(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the move unit up key has gone up/down.
	void uiMoveUnitUp(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the move unit down key has gone up/down.
	void uiMoveUnitDown(int integerKeyState = -1);

	// intended for ui use only.  Rotate placed unit with wheel -- i.e. intended to be mapped to wheel
	void uiWheelRotatePlacedUnit(int a = -1);

	// intended for ui use only.  Selects water at pointer location.
	void uiSelectWaterAtPointer();

	// intended for ui use only.  Unselects currently selected water.
	void uiUnSelectWater();

	// Paint objects on the currently selected water.
	void uiPaintWaterObjects();

	// intended for ui use only.  Indicates that the rotate water left button has gone up/down.
	void uiRotateWaterLeft(int a = -1);

	// intended for ui use only.  Indicates that the rotate water right button has gone up/down.
	void uiRotateWaterRight(int a = -1);

	// intended for ui use only.  Indicates that selection button has been pressed.
	void uiSelectionButtonDown();

	// intended for ui use only.  Indicates that selection button has been released.
	void uiSelectionButtonUp();

	// creates a number group with the currently selected units.
	void uiCreateNumberGroup(int integerGroup = -1);

	// erases the given number group.
	void uiClearNumberGroup(int integerGroup = -1);

	// selects the units in the given number group.
	void uiSelectNumberGroup(int integerGroup = -1);

	// adds the units in the given number group to current selection.
	void uiAddSelectNumberGroup(int integerGroup = -1);

	// removes current selection from any army.
	void uiRemoveFromAnyNumberGroup();

	// intended for ui use only.  Double click select at pointer location.
	void uiDoubleClickSelect(int integerAdd = -1, bool checkAction = false);

	// intended for ui use only.  Indicates that the add selection button has been pressed.
	void uiAddSelectionButtonDown();

	// intended for ui use only.  Indicates that the add selection button has been released.
	void uiAddSelectionButtonUp();

	// intended for ui use only.  
	void uiToggleSelectionButton();

	// intended for ui use only.  rotates the selected UNIT.
	void uiRotateSelection(int a = -1);

	// intended for ui use only.  Indicates that selection button has been pressed.
	void uiMoveSelectionButtonDown();

	// intended for ui use only.  Indicates that selection button has been released.
	void uiMoveSelectionButtonUp();

	// intended for ui use only.  Indicates that selection button has been pressed.
	void uiMoveSelectionAddButtonDown();

	// intended for ui use only.  Indicates that selection button has been released.
	void uiMoveSelectionAddButtonUp();

	// intended for ui use only.  Issues "work" at pointer location.
	void uiWorkAtPointer();

	// intended for ui use only.  Rotate with wheel -- i.e. intended to be mapped to wheel
	void uiWheelRotate(int a = -1);

	// intended for ui use only.  Rotate with wheel -- i.e. intended to be mapped to wheel
	void uiWheelRotateCamera(int a = -1);

	// intended for ui use only.  Indicates that the change elevation to sample button has gone up/down.
	void uiChangeElevationToSample(int integerKeyState = -1);

	// intended for ui use only.  Samples elevation height at pointer.
	void uiSampleElevationAtPointer();

	// intended for ui use only.  Samples Cliff elevation height at pointer.
	void uiSampleCliffElevationAtPointer();

	// intended for ui use only.  Indicates that the sample terrain button has gone up/down.
	void uiPaintTerrainToSample(int integerKeyState = -1);

	// intended for ui use only.  Samples terrain type at pointer.
	void uiSampleTerrainAtPointer();

	// deletes selected unit.
	void uiDeleteSelectedUnit();

	// deletes selected unit.
	void uiDeleteSelectedUnit2();

	// deletes all selected unit.
	void uiDeleteAllSelectedUnits();

	// Removes specified unit, or selected unit if not ID is specified.
	void uiRemoveSelectedUnit(int unitID = -1);

	// stop selected units.
	void uiStopSelectedUnits();

	// intended for ui use only.  Indicates that the raise elevation button has gone up/down.
	void uiRaiseElevation(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the lower elevation button has gone up/down.
	void uiLowerElevation(int integerKeyState = -1);

	// raises the terrain height uniformly in the brush region
	void uiUniformRaiseElevation(int a = -1);

	// lowers the terrain height uniformly in the brush region
	void uiUniformLowerElevation(int a = 0);

	// intended for ui use only.  Indicates that the smooth button has gone up/down.
	void uiSmooth(int integerKeyState = 0);

	// intended for ui use only.  Indicates that the paint water button has gone up/down.
	void uiPaintWater(int integerKeyState = 0);

	// intended for ui use only. Painting water area.
	void uiPaintWaterArea(int integerKeyState = 0);

	// intended for ui use only.  Indicates that the paint cliff button has gone up/down.
	void uiPaintCliff(int integerKeyState = 0);

	// intended for ui use only.  Indicates that the terrain selection button has gone up/down.
	void uiTerrainSelection(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the raise terrain selection button has gone up/down.
	void uiRaiseTerrainSelection(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the lower terrain selection button has gone up/down.
	void uiLowerTerrainSelection(int integerKeyState = -1);

	// flatten the current terrain selection.
	void uiFlattenTerrainSelection();

	// filter the current terrain selection.
	void uiFilterTerrainSelection();

	// open a scenario from the scenario directory
	void uiOpenScenarioBrowser(string a = "");

	// save a scenario to the scenario directory
	void uiSaveScenarioBrowser(string a = "");

	// save a scenario to the scenario directory
	void uiSaveAsScenarioBrowser(string a = "");

	// opens a Grand Conquest saved game
	void uiOpenGrandConquestBrowser(string a = "");

	// load a scenario, checking dirty bit on world.
	void uiScenarioLoad();

	// test a scenario.
	void uiStartScenarioTest();

	// test a scenario.
	void uiStopScenarioTest();

	// test a scenario.
	void uiStartBuildCinematic();

	// test a scenario.
	void uiStopBuildCinematic();

	// clears cinematic trigger info.
	void uiClearCinematicInfo();

	// clears all cinematic info including model/texture precache info.
	void uiClearAllCinematicInfo();

	// open a camera track from the data directory
	void uiOpenCameraTrackBrowser(string a = "");

	// save a camera track to the data directory
	void uiSaveCameraTrackBrowser(string a = "");

	// open a game from the saved game directory
	void uiOpenSavedGameBrowser(string a = "");

	// save a game to the saved game directory
	void uiSaveSavedGameBrowser(string a = "");

	// zooms to the first instance of proto unit X owned by the current player.
	void uiZoomToProto(string stringProto = "None");

	// open a record game from the saved game directory
	void uiOpenRecordGameBrowser(string a = "");

	// moves the camera to see the first selected unit.
	void uiLookAtSelection();

	// moves the camera to see the specified Unit.
	void uiLookAtUnit(int a = -1);

	// moves the camera to see the specified battle.
	void uiLookAtBattle(int a = -1);

	// moves the camera to see the specified unit and selects it.
	void uiLookAtAndSelectUnit(int a = -1);

	// moves the camera to see the specified Unit.
	void uiLookAtUnitByName(string scenarioName = "none");

	// moves the camera to see the first instance of proto unit X owned by the current player.
	void uiLookAtProto(string a = "None");

	// moves the camera to see the given number group.
	void uiLookAtNumberGroup(int integerGroup = -1);

	// intended for ui use only.  Indicates that the roughen button has gone up/down.
	void uiRoughen(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the delete units button has gone up/down.
	void uiDeleteUnits(int integerKeyState = -1);

	// intended for ui use only.  Indicates that the paint button has gone up/down.
	void uiPaint(bool integerKeyState = true, bool a = false);

	// intended for ui use only.  Indicates that the paint button has gone up/down.
	void uiPaintForest(bool paint = true, bool offset = false);

	// intended for ui use only.  Indicates that the paint terrain overlay button has gone up/down.
	void uiPaintTerrainOverlay(int integerKeyState = -1);

	// intended for ui use only.  Places unit at pointer location.
	void uiPlaceAtPointer(bool boolChangeVariation = true);

	// sets the proto ID to place.
	void uiSetProtoID(int integerType = -1);

	// increments the variation to place.
	void uiIncPlaceVariation();

	// does and editMode and setProtoID, after verifying sufficient resources for the current player.
	void uiBuildMode(int integerType = -1);

	// finds the next idle unit of the given type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	void uiFindIdleType(string typeName = "None");

	// finds all units of the same type as the selected unit
	void uiFindAllOfSelectedType();

	// finds all units of the same type
	void uiFindAllOfType(string a = "None");

	// finds all idle units of the same type
	void uiFindAllOfTypeIdle(string a = "None");

	// does the right thing.
	void uiHandleIdleBanner(string typeName = "None");

	// finds the next town center that has the town bell active, so that it can be called repeatedly to cycle.
	void uiFindTownBellTC(string a = "None");

	// finds the next unit (idle or not) of the given type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	void uiFindType(string typeName = "None");

	// cycles through the 'active' child gadget of a deluxe gadget.
	void uiCycleGadget(int integerDelta = -1);

	// closes (as if clicked on the close button) any active field set
	void uiCloseFieldSet();

	// closes (as if clicked on the close button) any active dialog
	void uiCloseDialog();

	// pops up a message box with text that activated the cmd when the ok button is hit
	void uiMessageBox(string stringText = "None", string stringCommand = "None");

	// pops up a message box with text that activated the cmd when the ok button is hit
	void uiMessageBox2(int stringID = -1, string stringCommand = "None");

	// copies the brush selection to the clipboard.
	void uiCopyToClipboard();

	// pastes the contents of the clipboard to the brush selection.
	void uiPasteFromClipboard();

	// sets the clipboard rotation amount.
	void uiSetClipboardRotation(float degrees = 0);

	// rotate the clipboard by amount.
	void uiRotateClipboard(int degrees = -1);

	// intended for UI use only.  Sends an ejection command for the selected unit.
	void uiEjectGarrisonedUnits();

	// intended for UI use only.  Sends an ejection command with waypoint for the selected unit.
	void uiEjectAtPointer();

	// intended for UI use only.  Sends an patrol order.
	void uiPatrolAtPointer();

	// intended for UI use only.  Applies a Lighting Set
	void uiApplyLightingSet(int integerIndex = -1);

	// makes the current brush based on the name and parameters.
	void uiSetBrushType(string name = "None", float p1 = -1, float p2 = -1, float p3 = -1, float p4 = -1);

	// changes the brush to the named type
	void uiChangeBrushType(string name = "None");

	// changes the size of the current brush
	void uiChangeBrushSize(float p1 = -1, float p2 = -1, float p3 = -1, float p4 = -1);

	// intended for ui use only. Increament the size of the current brush up/down
	void uiScrollBrushSize(int a = -1);

	// changes the ability to modify corner tiles: 0-All, 1-Corners only, 2-No corners
	void uiChangeBrushCornerMode(int a = -1);

	// changes the ability to modify vertices on cliff edges: 0-No clamping, 1-Clamp Low Edge, 2-Clamp High Edge, 3 - Clamp All Edges
	void uiChangeCliffModMode(int a = -1);

	// intended for ui use only. Increment the height of the cliff brush up/down
	void uiScrollCliffHeight(int a = -1);

	// used when activating a text box with a key to avoid having that key go into the text box too.
	void uiIgnoreNextKey();

	// acts like the current cycle gadget has been pressed
	void uiCycleCurrentActivate();

	// removes any dangling child menus off of the given gadget
	void uiClearMenu(string a = "");

	// deselects all selected units
	void uiClearSelection();

	// spews all key mappings out to the console.
	void uiDumpKeyMappings(string stringContext = "");

	// spews all hot key mappings that create units to the console
	void uiDumpAllUnitHotKeyMappings(string a = "");

	// spews all empty keys out to the console
	void uiDumpUnmappedKeys(string stringContext = "");

	// finds all key mappings for a given key
	void uiFindKeyMapping(string stringKeyname = "");

	// handles toggle of user textures
	void uiHandleUserTab(int listSel = -1, int parent = -1);

	// flattens terrain and paints water over the entire map.
	void uiCoverTerrainWithWater(float floatWaterHeight = 3, float floatDepth = 3, string waterName = "pine");

	// sets the cliff type by name.
	bool uiSetCliffType(string stringCliffName = "pine");

	// sets the cliff type by index.
	bool uiSetCliffTypeNum(int longCliffType = 0);

	// sets the water type by name.
	bool uiSetWaterType(string stringWaterName = "pine");

	// sets the water type by index.
	bool uiSetWaterTypeNum(int longWaterType = 0);

	// sets the forest type by name.
	bool uiSetForestType(string stringForestName = "pine");

	// sets the forest type by index.
	bool uiSetForestTypeNum(int a = 0);

	// selects the forest under the pointer.
	void uiSelectForestAtPointer();

	// de-selects the forest under the pointer.
	void uiUnselectForest();

	// selects the cliff under the pointer.
	void uiSelectCliffAtPointer();

	// de-selects the forest under the pointer.
	void uiUnselectCliff();

	// toggles cliff pieces on or off under the pointer.
	void uiToggleCliff();

	// scrolls the gadget up one unit
	void gadgetScrollUp(string a = "None");

	// scrolls the gadget up one unit
	void gadgetScrollDown(string a = "None");

	// scrolls the gadget to the left one unit
	void gadgetScrollLeft(string a = "None");

	// scrolls the gadget to the Right one unit
	void gadgetScrollRight(string a = "None");

	// makes real the named gadget.
	void gadgetReal(string stringName = "None");

	// makes un-real the named gadget.
	void gadgetUnreal(string stringName = "None");

	// toggles the reality of the named gadget.
	void gadgetToggle(string stringName = "None");

	// toggles the reality of the named gadget.
	void gadgetToggleIfNotMP(string a = "None");

	// refresh the contents of the named gadget.
	void gadgetRefresh(string stringName = "None");

	// turns gadget flashing on/off.
	void gadgetFlash(string stringName = "None", bool flash = true);

	// turns gadget flashing on/off.
	void techFlash(int techID = -1, bool flash = true);

	// turns gadget flashing on/off.
	void trainFlash(int protoID = -1, bool flash = true);

	// turns gadget flashing on/off.
	void categoryFlash(int ID = -1, bool flash = true);

	// fade in/out using color specified.
	void fadeToColor(int r = 0, int g = 0, int b = 0, int duration = 1000, int delay = 0, bool inout = true);

	// turn fade in on/off, set color duration.
	void setGameFadeIn(int r = 0, int g = 0, int b = 0, int duration = 1000, int delay = 0, bool inout = true);

	// load some triggers.
	void uiLoadTriggers(string a = "None");

	// save some triggers.
	void uiSaveTriggers(string a = "None");

	// load some triggers.
	void uiImportTriggers(string a = "None");

	// load some triggers.
	void doTriggerImport(string a = "None");

	// save some triggers.
	void uiExportTriggers(string a = "None");

	void uiTriggerSelectLocation();

	void uiTriggerResetParameters();

	void uiTriggerResetSounds();

	// save a group.
	void uiExportGrouping(string a = "None");

	// save some groups.
	void uiSaveGrouping(string a = "None");

	// save some groups.
	void uiSaveGroupingLUA(int a = -1, string b = "None");

	// testing only
	void uiHideCursor(bool a = true);

	// causes game to return to editMode none when shift hotkey is released
	void uiLeaveModeOnUnshift();

	// This is not what you are looking for.
	void uiToggleBrushMask(int a = -1);

	// This is not what you are looking for.
	void uiToggleTerrainPasteMode(int a = -1);

	// brings up the detail help UI for the given proto ID, or -1 for current unit selection proto.
	void uiUnitDetailHelp(int protoID = -1, int civID = -1);

	// brings up the detail help UI for the given tech node ID
	void uiTechDetailHelp(int techID = -1);

	// brings up the detail help UI for the given tech node ID
	void uiTechCivDetailHelp(int a = -1, int b = -1);

	// brings up the detail help UI for the given help topic
	void uiTopicDetailHelp(string topicName = "");

	// goes back to the most recent help entry.
	void uiLastDetailHelp();

	// shows the ai debug menu with new data.
	void AIDebugInfoRefresh();

	// toggles whether the ai debug menu is up, refreshing if first showing.
	void AIDebugInfoToggle();

	// toggles whether the ai output window is up, refreshing if first showing.
	void AIDebugOutputToggle();

	// toggles whether the ai gatherer distribution window is up, refreshing if first showing.
	void AIDebugGathererToggle();

	// toggles whether the ai pop distribution window is up, refreshing if first showing.
	void AIDebugPopToggle();

	// toggles whether the ai past resource needs window is up, refreshing if first showing.
	void AIDebugPastResourceNeedToggle();

	// toggles whether the kb timed stats window is up, refreshing if first showing.
	void AIDebugTimedStatsToggle();

	// toggles the display of bases
	void AIDebugShowBasesToggle();

	// toggles the showing of Building placement value text.
	void AIDebugToggleBPText();

	// brings up the plan debug text for the given plan ID
	void uiShowAIDebugInfoPlan(int a = -1);

	// brings up the building placement info for the given ID
	void uiShowAIDebugInfoPlacement(int a = -1);

	// brings up the progression info for the given ID
	void uiShowAIDebugInfoProgression(int a = -1);

	// brings up the kbunit info for the given ID
	void uiShowAIDebugInfoKBUnit(int a = 0);

	// brings up the base info for the given ID
	void uiShowAIDebugInfoBase(int a = -1);

	// brings up the area info for the given ID
	void uiShowAIDebugInfoArea(int a = -1);

	// brings up the area info for the given ID
	void uiShowAIDebugInfoAreaGroup(int a = -1, int b = -1);

	// render the attackRoute info for the given ID
	void uiSetKBAttackRouteRender(int a = -1, bool b = false);

	// brings up the attackRoute info for the given ID
	void uiShowAIDebugInfoAttackRoute(int a = -1);

	// render the kbResource info for the given ID. If not set given, will not render the resource.
	void uiSetKBResourceRender(int resID = -1, bool set = false);

	// brings up the kbResource info for the given ID
	void uiShowAIDebugInfoKBResource(int a = -1);

	// render the kbArmy info for the given ID. If not set given, will not render the army.
	void uiSetKBArmyRender(int id = -1, bool set = false);

	// brings up the kbArmy info for the given ID
	void uiShowAIDebugInfoKBArmy(int a = -1);

	// brings up the kbUnitPick info for the given ID
	void uiShowAIDebugInfoKBUnitPick(int a = -1);

	// brings up the escrow info for the given ID
	void uiShowAIDebugInfoEscrow(int a = -1);

	// controls rendering of the building placement info for the given ID
	void uiSetBuildingPlacementRender(int id = -1, bool on = true);

	// Scrolls chat back one.
	void uiChatScrollBack(int integerKeyState = -1);

	// Scrolls chat forward one.
	void uiChatScrollForward(int integerKeyState = -1);

	// Toggles the chat display mode.
	void uiChatDisplayModeToggle();

	// Toggles the chat display mode to recent mode.
	void uiChatDisplayModeToRecent();

	// Toggles the chat display mode to history mode.
	void uiChatDisplayModeToHistory();

	// Clears the chat and resets to recent mode.  clearOnly == true if you don't want it to populate the chat, but only clear it.
	void uiClearChat(bool clearOnly = false);

	// Adds a notification to the game's chat output, can play a sound too.
	void uiAddChatNotification(int a = -1, int b = -1, int c = -1, int d = -1);

	// Adds notify text, can play a sound too.
	void uiSetHCNotifyText(int a = -1, int b = -1);

	void uiShowChatWindow();

	// pops up all downed keys.
	void uiReleaseDownKeys();

	// spews all down keys.
	void uiSpewDownKeys();

	void uiShowVoteDialog();

	// used direcly by UI
	void uiSendIngameChat();

	// Used to activate the politician UI
	void uiPoliticianUI(int a = -1, int b = -1, bool c = false);

	// Used to activate the politician UI in current selection
	void uiPoliticianUIInSelected(string a = "");

	// Used to activate the consulate UI
	void uiConsulateUI(int a = -1, int b = -1);

	// Used to activate the consulate UI from hotkeys
	void uiConsulateUIInSelected();

	void enterAttackMoveMode();

	void uiShowObjectivesDialog();

	// Causes the currently displaying objective notification to fade out (or disappear), depending on the param passed in.
	void uiExpireCurrentObjectiveNotification(bool a = true);

	void uiPlaceTradeRouteWaypoint();

	void uiRemoveTradeRouteWaypoint();

	void uiSelectTransportUnit();

	// finds the next resource gatherer unit of the given resource type in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	void uiFindResourceGatherers(string typeName = "None");

	// finds the gatherer unit that's not gathering in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	void uiFindGatherersNotGathering();

	// finds the next native settler dancing at the firepit in the arbitrary order of unit ID, so that it can be called repeatedly to cycle.
	void uiFindDancers();

	// selects the users firepit if it exists
	void uiSelectFirepit();

	// finds allied natives of the current player in order, so that it can be called repeatedly to cycle.
	void uiFindAlliedNatives();

	// Shows the VP accel building from the unitID.
	void uiVPAccelClick(int unitID = -1);

	void incrementUSP2SelectedUnitStack();

	void decrementUSP2SelectedUnitStack();

	void uiSetCameraStartLoc();

	void uiShowCameraStartLoc();

	void uiDeleteCameraStartLoc();

	// Scrolls the game view.
	void uiCameraScroll(bool fast = false, float x = 0, float y = 0);

	// Controls camera with gamepad stick.
	void uiCameraControl(float x = 0, float y = 0);

	// Moves the map pointer.
	void uiMapPointerControl(float x = 0, float y = 0, bool doGoto = false);

	// Jump to map pointer location.
	void uiMapPointerGoto(bool activeCheck = false);

	// Start/stop circle selection.
	void uiCircleSelect(bool on = false, bool doubleClick = false, bool leaveSelected = false);

	// Circle selection resizing.
	void uiCircleSelectResize(float x = 0, float y = 0);

	// Centers mouse pointer.
	void uiCenterPointer();

	// Force shift key on or off.
	void uiForceShift(bool on = false);

	// screen selection.
	void uiScreenSelect(bool modifier = false);

	// resets screen selection.
	void uiResetScreenSelect();

	void uiFindCrowd(int findType = 0, bool noLookAt = false);

	void uiResetFindCrowd();

	void uiShowStatPanel();

	void uiShowDetailedHelp();

	void uiShowCommandPanel();

	void uiMinimizeStats();

	// Moves all military units to the pointer position.
	void uiMoveAllMilitaryAtPointer();

	// send attack sentence from one player to another; specify targetPlayer, or targetUnit, or xPos and zPos.
	void sendAttackSentence(int sendingPlayer = -1, int receivingPlayer = -1, int targetPlayer = -1, int targetUnit = -1, float xPos = -1, float zPos = -1);

	// send defend sentence from one player to another; specify target xPos and zPos.
	void sendDefendSentence(int sendingPlayer = -1, int receivingPlayer = -1, float xPos = -1, float zPos = -1);

	// send tribute sentence from one player to another; specify desired resource.
	void sendTributeSentence(int sendingPlayer = -1, int receivingPlayer = -1, int resourceID = -1);

	// send AIChat to current player from sendingPlayer; specify desired AIChatPromptType.
	void sendPromptType(int sendingPlayer = -1, int promptType = -1);

	// begins a new random game.
	void startRandomGame(bool a = false);

	// begins a new random game with the given parms.
	void startRandomGame2(string filename = "none", int players = 0, int random = -1, string seed = "", bool scenarioFilename = false, int debug = 2, int teamCount = 0, int mapsize = 0, bool resources = false);

	// Generates a random map game with the given map code.
	void startRandomGameMapCode(string mapcode = "none");

	// Generates a random map game with the given starting age, nomad start(true/false), and map code.
	void startRandomGameAgeAndMapCode(int startingage = 0, bool nomad = false, string mapcode = "none");

	// restarts current game.
	void restartCurrentGame();

	// destroys the world and returns to main menu.
	void leaveGame(int a = 0, int b = 0);

	// does what needs to be done.
	void handlePostGame();

	// does what needs to be done.
	void showGameFromPostGame();

	// does what needs to be done.
	void postGamePlayAgain();

	// changes the zoom factor of the minimap up or down by that amount (remaining centered on the current view)
	void minimapZoomDelta(float floatZoomDelta = 0);

	// sets the zoom factor of the minimap.
	void minimapZoom(float floatZoom = 0);

	// changes the minimap rotation mode.  No arg means toggle.
	void minimapRotateMode(int integerMode = -1);

	// adds a line of chat text from the given player (current if not provided.
	void chat(string stringText = "None", int integerPlayer = 0);

	// intended for ui use only.  Use a special power at targeted location.
	void uiSpecialPowerAtPointer();

	// turns off and on the game UI.
	void uiToggleGame();

	// zooms to the most recent minimap event
	void uiZoomToMinimapEvent();

	// reconstitutes the entire editor menu
	void uiRefreshEditorMenu();

	// minimizes main UI and brings up the minimized UI
	void uiShowTributeDialog();

	// maximizes main UI
	void uiHideTributeDialog();

	// Shows the player summary dialog.
	void uiShowPlayerSummaryDialog();

	// Hides the player summary dialog.
	void uiHidePlayerSummaryDialog();

	// creates a new blank scenario
	void uiNewScenario();

	// intended for ui use only.  Indicates that the increase sun inclination key has gone up/down.
	void sunIncreaseInclination(int keyState = 0);

	// intended for ui use only.  Indicates that the decrease sun inclination key has gone up/down.
	void sunDecreaseInclination(int keyState = 0);

	// intended for ui use only.  Indicates that the increase sun rotation key has gone up/down.
	void sunIncreaseRotation(int keyState = 0);

	// intended for ui use only.  Indicates that the decrease sun rotation key has gone up/down.
	void sunDecreaseRotation(int keyState = 0);

	// sets the sun height above the horizon and position in the world, The bool tells if the changes are relative
	void setSunPosition(float sunInclination = 0, float sunRotation = 0, bool relative = false);

	// abort the current cinematic.
	void abortCinematic();

	// causes score to update even if it isn't supposed to yet, time wise
	void scoreUpdate();

	// handles the score toggling
	void toggleScore();

	// handles the time display toggling
	void toggleTime();

	// handles the time display toggling
	void toggleDebugTime();

	// Enter Single player setup.
	void doSPSetup(bool a = true);

	// Enter BMultiplayer setup.
	void doMPSetup(bool useESO = true);

	// Leave the current MP screen and return to the MP setup menu.
	void exitMPSetupSubScreen();

	// 
	void enterRecordGameMode(string name = "");

	// 
	void enterGCGameMode(string name = "");

	// UI used only
	void showCampaignDialog(string name = "", string msg = "");

	// resigns the currently controlled player.
	void playerResign();

	// show the in-game menu.
	void showGameMenu();

	// hide the in-game menu.
	void hideGameMenu(bool a = false);

	// show the in-game menu.
	void uiSaveCampaignGameBrowser();

	// initializes the Profile Edit Dialog inside the OptionsScreen
	void uiInitOptionsScreenProfileEditDialog();

	// stop playing stupid music at 11pm.
	void uiBMultiplayerSave();

	// drop back to the main menu
	void dropToMainMenu();

	bool modelLoad(string modelXMLFilename = "");

	// change the cliff type for all cliffs on the map
	void changeCliffType(string cliffName = "");

	// turn on/off gamepad command panel control.
	void uiCommandPanelControl(bool on = false);

	// move between selections in the command panel.
	void uiCommandPanelMove(float x = 0, float y = 0);

	// gamepad command panel execute.
	void uiCommandPanelExecute(bool a = false);

	// executes the trYouWin trigger func, allowing you to win the scenario.
	void winScenario();

	// Disables the given rule.
	void xsDisableRule(string ruleName = "");

	// Disables the current rule.
	void xsDisableSelf();

	// Enables the given rule.
	void xsEnableRule(string ruleName = "");

	// Returns true if the rule is enabled.
	bool xsIsRuleEnabled(string ruleName = "");

	// Sets the priority of the given rule.
	void xsSetRulePriority(string ruleName = "", int priority = 0);

	// Sets the priority of the current rule.
	void xsSetRulePrioritySelf(int priority = 0);

	// Sets the min interval of the given rule.
	void xsSetRuleMinInterval(string ruleName = "", int interval = 0);

	// Sets the min interval of the current rule.
	void xsSetRuleMinIntervalSelf(int interval = 0);

	// Sets the max interval of the given rule.
	void xsSetRuleMaxInterval(string ruleName = "", int interval = 0);

	// Sets the max interval of the current rule.
	void xsSetRuleMaxIntervalSelf(int interval = 0);

	// Enables all rule in the given rule group.
	void xsEnableRuleGroup(string ruleGroupName = "");

	// Disables all rules in the given rule group.
	void xsDisableRuleGroup(string ruleGroupName = "");

	// Returns true if the rule group is enabled.
	void xsIsRuleGroupEnabled(string ruleGroupName = "");

	// Returns the x component of the given vector.
	float xsVectorGetX(vector v = cOriginVector);

	// Returns the y component of the given vector.
	float xsVectorGetY(vector v = cOriginVector);

	// Returns the z component of the given vector.
	float xsVectorGetZ(vector v = cOriginVector);

	// Set the x component of the given vector, returns the new vector.
	vector xsVectorSetX(vector result, vector v = cOriginVector, float x = 0);

	// Set the y component of the given vector, returns the new vector.
	vector xsVectorSetY(vector result, vector v = cOriginVector, float y = 0);

	// Set the z component of the given vector, returns the new vector.
	vector xsVectorSetZ(vector result, vector v = cOriginVector, float z = 0);

	// Set the 3 components into a vector, returns the new vector.
	vector xsVectorSet(vector result, float x = 0, float y = 0, float z = 0);

	// Returns the length of the given vector.
	float xsVectorLength(vector v = cOriginVector);

	// Returns the normalized version of the given vector.
	vector xsVectorNormalize(vector result, vector v = cOriginVector);

	// creates a sized and named integer array, returning an arrayID.
	int xsArrayCreateInt(int size = -1, int defaultValue = 0, string name = "");

	// Sets a value at the specified index in the requested array.
	bool xsArraySetInt(int arrayID = -1, int index = -1, int value = -1);

	// Gets the value at the specified index in the requested array.
	int xsArrayGetInt(int arrayID = -1, int index = -1);

	// creates a sized and named float array, returning an arrayID.
	int xsArrayCreateFloat(int size = -1, float defaultValue = 0, string name = "");

	// Sets a value at the specified index in the requested array.
	bool xsArraySetFloat(int arrayID = -1, int index = -1, float value = -1);

	// Gets the value at the specified index in the requested array.
	float xsArrayGetFloat(int arrayID = -1, int index = -1);

	// creates a sized and named boolean array, returning an arrayID.
	int xsArrayCreateBool(int size = -1, bool defaultValue = false, string name = "");

	// Sets a value at the specified index in the requested array.
	bool xsArraySetBool(int arrayID = -1, int index = -1, bool value = false);

	// Gets the value at the specified index in the requested array.
	bool xsArrayGetBool(int a = -1, int b = -1);

	// creates a sized and named string array, returning an arrayID.
	int xsArrayCreateString(int size = -1, string defaultValue = "<default string>", string name = "");

	// Sets a value at the specified index in the requested array.
	bool xsArraySetString(int arrayID = -1, int index = -1, string value = "<default string>");

	// Gets the value at the specified index in the requested array.
	string xsArrayGetString(int arrayID = -1, int index = -1);

	// creates a sized and named vector array, returning an arrayID.
	int xsArrayCreateVector(int size = -1, vector defaultValue = cInvalidVector, string name = "");

	// Sets a value at the specified index in the requested array.
	bool xsArraySetVector(int arrayID = -1, int index = -1, vector value = cInvalidVector);

	// Gets the value at the specified index in the requested array.
	vector xsArrayGetVector(vector result, int arrayID = -1, int index = -1);

	// Gets the specified array's size.
	int xsArrayGetSize(int arrayID = -1);

	// blogs out all XS arrays.
	void xsDumpArrays();

	// Returns the current context player ID.
	int xsGetContextPlayer();

	// Sets the current context player ID (DO NOT DO THIS IF YOU DO NOT KNOW WHAT YOU ARE DOING).
	void xsSetContextPlayer(int playerID = -1);

	// Returns the current gametime (in milliseconds).
	int xsGetTime();

	// Setups a runtime event.  Don't use this.
	bool xsAddRuntimeEvent(string foo = "", string bar = "", int something = -1);

	// Runs the secret XSFID for the function. USE WITH CAUTION.
	int xsGetFunctionID(string a = "");

	// Random map echo.
	void rmEchoWarning(string echoString = "None");

	// Random map echo.
	void rmEchoError(string echoString = "None");

	// Returns a random float between min and max.
	float rmRandFloat(float min = 0, float max = 1);

	// Returns a random integer between min and max.
	int rmRandInt(int min = 0, int max = 1);

	// Returns true if this map is to place a covered wagon instead of a town center.
	bool rmGetNomadStart();

	// Returns true if this map is set to be a FFA game which means each player on their own team.
	bool rmGetIsFFA();

	// Returns true if this map is set to be a relic game..
	bool rmGetIsRelicCapture();

	// Returns true if this map is set to be a King of the Hill game.
	bool rmGetIsKOTH();

	// Sets the size of the map.
	bool rmSetMapSize(float x = -1, float z = -1);

	// Returns the X size of the map.
	int rmGetMapXSize();

	// Returns the Z size of the map.
	int rmGetMapZSize();

	// Sets the sea level for the map.
	void rmSetSeaLevel(float a = 0);

	// Gets the sea level for the map.
	float rmGetSeaLevel();

	// Sets the sea type for the map.  This is used if terrain is initialized to water.
	bool rmSetSeaType(string name = "");

	// Sets up terrain for initializing with a noise layer.
	bool rmSetMapElevationParameters(int type = 0, float freq = 0.1, int octaves = 4, float persistence = 0.1, float variation = 6);

	// Initializes the base terrain with the requested mix.  Call before rmTerrainInitialize.
	bool rmSetBaseTerrainMix(string mixName = "");

	// Adds a terrain to paint between the specified heights, modified by a random number between 0.0 and outerRange.
	bool rmAddMapTerrainByHeightInfo(string terrain = "", float minHeight = 0, float maxHeight = 0, float outerRange = 0);

	// Adds a terrain to paint on tiles that are sloped between the specified angles (0 degrees is flat terrain, 90 degrees is sheer terrain), modified by a random number between 0.0 and outerRange.
	bool rmAddMapTerrainByAngleInfo(string terrain = "", float minSlope = 0, float maxSlope = 0, float outerRange = 0);

	// Sets how much to smooth the overall terrain after initializing with noise.
	bool rmSetMapElevationHeightBlend(int blend = 0);

	// place object clusters (of the specified protounit) around the map, and also optionally paint with the specified terrain.
	bool rmPlaceMapClusters(string terrain = "", string protounit = "");

	// sets up cluster system; valid ranges are from -1.0 to 1.0 and are compared to the internal noise field for deciding where to paint terrain and place clusters. Type is cClusterLand, or cClusterWater, or cClusterShallowWater, or cClusterEverywhere.
	bool rmSetMapClusteringPlacementParams(float paintThreshold = 0.4, float placeMinVal = 0.4, float placeMaxVal = 1, int type = 0);

	// sets up cluster system; min/max objects per tile (default: 0-3), and max random offset when placing (default: 0.5 tiles).
	bool rmSetMapClusteringObjectParams(int minObjectCount = 0, int maxObjectCount = 3, float maxPosOffset = 0.5);

	// sets up cluster system; standard inputs to noise generator used to determine cluster placement.
	bool rmSetMapClusteringNoiseParams(float minFrequency = 0.2, int octaves = 4, float persistence = 0.15);

	// Converts an area from fraction of the map to tile count.
	int rmAreaFractionToTiles(float fraction = 0);

	// Converts area tile count to fraction of map.
	float rmAreaTilesToFraction(int tiles = 0);

	// Converts an fraction of the map in the x direction to tile count.
	int rmXFractionToTiles(float fraction = 0);

	// Converts tile count in the x direction to fraction of map.
	float rmXTilesToFraction(int tiles = 0);

	// Converts an fraction of the map in the z direction to tile count.
	int rmZFractionToTiles(float fraction = 0);

	// Converts tile count in the z direction to fraction of map.
	float rmZTilesToFraction(int tiles = 0);

	// Converts an angle in degrees to radians.
	float rmDegreesToRadians(float degrees = 0);

	// Converts a distance in meters to a number of tiles.
	int rmMetersToTiles(float meters = 0);

	// Converts meters into a fraction of the map in the x direction.
	float rmXMetersToFraction(float meters = 0);

	// Converts meters into a fraction of the map in the z direction.
	float rmZMetersToFraction(float meters = 0);

	// Converts a fraction of the map in the x direction to meters.
	float rmXFractionToMeters(float meters = 0);

	// Converts meters a fraction of the map in the z direction to meters.
	float rmZFractionToMeters(float meters = 0);

	// Creates an area.
	int rmCreateArea(string name = "", int parentAreaID = -1);

	// Set the area size to a min/max fraction of the map.
	bool rmSetAreaSize(int minFraction = -1, float maxFraction = 0, float a = 0);

	// Enable edge filling and set a border search size (for Carolina and similar maps with a big continent).
	bool rmSetAreaEdgeFilling(int areaID = -1, int borderSize = 0);

	// Set the area location.
	bool rmSetAreaLocation(int areaID = -1, float xFraction = 0, float zFraction = 0);

	// Set the area location to player's location.
	bool rmSetAreaLocPlayer(int areaID = -1, int playerID = -1);

	// Set the area location to team's location.
	bool rmSetAreaLocTeam(int areaID = -1, int teamID = -1);

	// Builds the specified area.
	bool rmBuildArea(int areaID = -1);

	// Simulatenously builds all unbuilt areas.
	int rmBuildAllAreas();

	// Sets the terrain type for an area.
	bool rmSetAreaTerrainType(int areaID = -1, string terrainTypeName = "");

	// Sets the mix for an area.  Overrides terrain type if it is also set.
	bool rmSetAreaMix(int areaID = -1, string mixName = "");

	// Paints the terrain for a specified area.
	bool rmPaintAreaTerrain(int areaID = -1);

	// Paints the area's tiles in the specified height range with specified terrain (with outerRange buffer if feathering is desired).
	bool rmPaintAreaTerrainByHeight(int areaID = -1, string terrain = "", float minHeight = 0, float maxHeight = 0, float outerRange = 0);

	// Paints the area's tiles in the specified angle range with specified terrain (with outerRange buffer if feathering is desired).
	bool rmPaintAreaTerrainByAngle(int areaID = -1, string terrain = "", float minAngle = 0, float maxAngle = 0, float outerRange = 0);

	// Sets the base height for an area.
	bool rmSetAreaBaseHeight(int areaID = -1, float height = 0);

	// Sets whether the area build process will warn if it fails.
	bool rmSetAreaWarnFailure(int areaID = -1, bool warn = true);

	// Sets the forest type for an area.
	bool rmSetAreaForestType(int areaID = -1, string forestName = "");

	// Sets the forest density for an area.
	bool rmSetAreaForestDensity(int areaID = -1, float density = 1);

	// Sets the forest density for an area.
	bool rmSetAreaForestClumpiness(int areaID = -1, float density = 0.5);

	// Sets the forest density for an area.
	bool rmSetAreaForestUnderbrush(int areaID = -1, float density = 0.5);

	// Sets the water type for an area.
	bool rmSetAreaWaterType(int areaID = -1, string waterName = "");

	// Returns the point in areaID that's closest to the given point, optionally requiring that it pass the given constraint.
	vector rmGetAreaClosestPoint(vector result, int areaID = -1, vector point = cInvalidVector, float pullback = 3, int constraintID = -1);

	// Sets the cliff type for an area.
	bool rmSetAreaCliffType(int areaID = -1, string cliffName = "");

	// Set cliff painting options for an area.
	bool rmSetAreaCliffPainting(int areaID = -1, bool paintGround = true, bool paintOutsideEdge = true, bool paintSide = true, float minSideHeight = 1.5, bool paintInsideEdge = true);

	// Set cliff edge parameters for an area.
	bool rmSetAreaCliffEdge(int areaID = -1, int count = 1, float size = 0.5, float variance = 0, float spacing = 1, int mapEdge = 0);

	// Set an area's cliff height.
	bool rmSetAreaCliffHeight(int areaID = -1, float val = 4, float variance = 0, float ramp = 0.5);

	// Adds a class for an area's cliff edge to avoid.
	bool rmAddAreaCliffEdgeAvoidClass(int areaID = -1, int avoidID = -1, float minDist = 0);

	// make a river dude.
	int rmRiverCreate(int areaID = -1, string waterType = "", int breaks = 5, int offset = 15, int minR = 5, int maxR = 10);

	bool rmRiverSetConnections(int riverID = -1, float startX = 0, float startZ = 0, float endX = 0, float endZ = 0);

	bool rmRiverConnectRiver(int riverID = -1, int river2ID = -1, float pct = 0, float end = 0, float e = 0);

	// Add waypoint to a river.  Don't mix with rmRiverSetConnections or rmRiverConnectRiver
	bool rmRiverAddWaypoint(int riverID = -1, float xFraction = 0, float zFraction = 0);

	bool rmRiverSetBankNoiseParams(int riverID = -1, float frequency = 0.05, int octaves = 5, float persistence = 0.5, float sineLength = 10, float sineAmt = 0.667, float variation = 0);

	bool rmRiverSetShallowRadius(int riverID = -1, int radius = 3);

	bool rmRiverAddShallow(int riverID = -1, float distancePct = 0);

	bool rmRiverAddShallows(int riverID = -1, int count = -1, int radius = 3);

	bool rmRiverAvoid(int riverID = -1, int river2ID = -1, float minDist = 0);

	bool rmRiverBuild(int riverID = -1);

	// reveals a river plus the specified number of extra tiles around it.
	bool rmRiverReveal(int riverID = -1, int extraTiles = 0);

	// the terrain buffer around the river, and the height of the banks above water level
	bool rmSetRiverFoundationParams(int tileBuffer = 8, float heightOffset = 0.5);

	// sets whether RM activities should be constrained to the main world circle.
	bool rmSetWorldCircleConstraint(bool constrain = false);

	// Determines whether an area obeys world circle constraint.
	bool rmSetAreaObeyWorldCircleConstraint(int areaID = -1, bool constrain = true);

	// Adds a terrain layer to an area.
	bool rmAddAreaTerrainLayer(int areaID = -1, string terrain = "", float minDist = 0, float maxDist = 0);

	// Specifies if the area should vary the terrain layer edges.
	bool rmSetAreaTerrainLayerVariance(int areaID = -1, bool variance = true);

	// Sets minimum number of area blobs.
	bool rmSetAreaMinBlobs(int areaID = -1, int blobs = 0);

	// Sets maximum number of area blobs.
	bool rmSetAreaMaxBlobs(int areaID = -1, int blobs = 0);

	// Sets minimum blob distance.
	bool rmSetAreaMinBlobDistance(int areaID = -1, float dist = 0);

	// Sets maximum blob distance.
	bool rmSetAreaMaxBlobDistance(int areaID = -1, float dist = 0);

	// Sets area coherence (0-1).
	bool rmSetAreaCoherence(int areaID = -1, float coherence = 0);

	// Sets area edge smoothing distance (distance is number of neighboring points to consider in each direction).
	bool rmSetAreaSmoothDistance(int areaID = -1, int smoothDistance = 0);

	// Sets how smoothly area height blends into surroundings.
	bool rmSetAreaHeightBlend(int areaID = -1, int heightBlend = 1);

	// Gets area ID for given area name.
	int rmAreaID(string name = "");

	// Adds an area influence point.
	bool rmAddAreaInfluencePoint(int areaID = -1, float xFraction = 0, float zFraction = 0);

	// Adds an area influence segment.
	bool rmAddAreaInfluenceSegment(int areaID = -1, float xFraction1 = 0, float zFraction1 = 0, float xFraction2 = 0, float zFraction2 = 0);

	// Add an unit type that the specified area removes.
	bool rmAddAreaRemoveType(int areaID = -1, string typeName = "");

	// Adds a terrain replacement rule to the area.
	bool rmAddAreaTerrainReplacement(int areaID = -1, string terrainTypeName = "", string newTypeName = "");

	// Sets the area elevation variation type (cElevNormal, cElevFractalSum, cElevTurbulence).
	bool rmSetAreaElevationType(int areaID = -1, int type = 0);

	// Sets the area elevation variation noise frequency (best >0 and <1).
	bool rmSetAreaElevationMinFrequency(int areaID = -1, float freq = 0.1);

	// Sets the area elevation variation noise octaves.
	bool rmSetAreaElevationOctaves(int areaID = -1, int octaves = 4);

	// Sets the area elevation variation noise persistence (best >0 and <1).
	bool rmSetAreaElevationPersistence(int areaID = -1, float persistence = 0.1);

	// Sets the area elevation variation height (amount to vary +- from area base height).
	bool rmSetAreaElevationVariation(int areaID = -1, float variation = 6);

	// Sets the area elevation noise to falloff as it gets closer to the area edge.
	bool rmSetAreaElevationEdgeFalloffDist(int areaID = -1, float dist = 0);

	// Sets the area elevation variation noise bias (-1 means down only, 0 means +- equally, 1 means up only.)
	bool rmSetAreaElevationNoiseBias(int areaID = -1, float bias = 6);

	// Sets the area to be revealed (-1 means don't reveal, 0 means reveal, >0 means reveal plus that number of extra tiles.
	bool rmSetAreaReveal(int areaID = -1, int tiles = -1);

	// sets the global snow percent.
	void rmSetGlobalSnow(float percent = -1);

	// sets the global rain percent.
	void rmSetGlobalRain(float percent = -1);

	// sets storm length and time between storm in seconds.
	void rmSetGlobalStormLength(int length = 20, int timeBetweenStorms = 60);

	// sets the global wind magnitude (1.0f is default).
	void rmSetWindMagnitude(float magnitude = 1);

	// Initializes the terrain to the base type and height.
	void rmTerrainInitialize(string baseTerrain = "", float height = 10);

	// Fill map corners with blackmap.
	void rmFillMapCorners();

	//  applies a lighting set fade.
	void rmDoLightingFade(string lightSetName = "None", float fadeTime = 0);

	//  applies a lighting set effect.
	void rmDoLightingEffect(string lightSetName = "None", float blendInTime = 0, float effectTime = 0, float blendOutTime = 0);

	// Sets Gaia's civilization
	void rmSetGaiaCiv(int civ = 0);

	// Allocates the number of sub civs in the world.
	bool rmAllocateSubCivs(int number = 0);

	// Sets a given sub civ in the world.
	bool rmSetSubCiv(int index = 0, string civName = "", bool big = false);

	// Returns the civ ID.
	int rmGetCivID(string civName = "");

	// Adds mercs of to the merc manager for this game.
	int rmAddMerc(string unitName = "", float count = 0, float minCount = 0, float maxCount = 30, float countIncrement = 2, bool multipleUses = true);

	// Manually sets a player's starting location.
	bool rmSetPlayerLocation(int playerID = -1, float xFraction = 0, float zFraction = 0);

	// Sets the area of the map to use for player placement.
	void rmSetPlayerPlacementArea(float minX = 0, float minZ = 0, float maxX = 1, float maxZ = 1);

	// Sets the team spacing modifier.
	void rmSetTeamSpacingModifier(float modifier = 1);

	// Sets the team to place.
	void rmSetPlacementTeam(int teamID = -1);

	// Sets the section of the placement line to use.
	void rmSetPlacementSection(float fromPercent = 0, float toPercent = 1);

	// Makes a circle of player locations.
	bool rmPlacePlayersCircular(float minFraction = 0, float maxFraction = 0, float angleVariation = 0);

	// Makes a square of player locations.
	bool rmPlacePlayersSquare(float dist = 0, float distVariation = 0, float spacingVariationfloat = 0);

	// Makes a line of player locations.
	bool rmPlacePlayersLine(float x1 = 0, float z1 = 0, float x2 = 0, float z2 = 0, float distVariation = 0, float spacingVariation = 0);

	// Makes a line of player locations along the specified river.
	bool rmPlacePlayersRiver(int riverID = -1, float distVariation = 0, float spacingVariation = 0, float edgeDistance = 0);

	// Sets one player location.
	bool rmPlacePlayer(int playerID = 0, float xFraction = 0, float zFraction = 0);

	// Sets a player's 'official' area.
	bool rmSetPlayerArea(int playerID = -1, int areaID = -1);

	// Gets a player's start location x fraction.
	float rmPlayerLocXFraction(int playerID = -1);

	// Gets a player's start location z fraction.
	float rmPlayerLocZFraction(int playerID = -1);

	// Adds some fairLoc placement info.
	int rmAddFairLoc(string unitName = "", bool forward = true, bool inside = true, float minPlayerDist = 0, float maxPlayerDist = 0, float locDist = 0, float edgeDist = 0, bool playerArea = false, bool teamArea = false);

	// Sets fairLoc placement locations.
	bool rmPlaceFairLocs(int a = -1);

	// Resets fairLoc placment info.
	void rmResetFairLocs();

	// Gets a player's number of fairLocs.
	int rmGetNumberFairLocs(int playerID = -1);

	// Gets a player's fairLoc x fraction.
	float rmFairLocXFraction(int playerID = -1, int index = -1);

	// Gets a player's fairLoc z fraction.
	float rmFairLocZFraction(int playerID = -1, int index = -1);

	// Sets a player's resource amount.
	bool rmSetPlayerResource(int playerID = -1, string resourceName = "", float amount = 0);

	// Adds to a player's resource amount.
	bool rmAddPlayerResource(int playerID = -1, string resourceName = "", float amount = 0);

	// Multiplys a player's resource amount by the given factor.
	bool rmMultiplyPlayerResource(int playerID = -1, string resourceName = "", float factor = 0);

	// Gets a player's name.
	string rmGetPlayerName(int playerID = -1);

	// Gets the team the specified player is on.
	int rmGetPlayerTeam(int playerID = -1);

	// Gets the civilization the specified player is on.
	int rmGetPlayerCiv(int playerID = -1);

	// Gets the culture the specified player is on.
	int rmGetPlayerCulture(int playerID = -1);

	// Gets the number of players on the given team.
	int rmGetNumberPlayersOnTeam(int teamID = -1);

	// Sets a team's 'official' area.
	bool rmSetTeamArea(int teamID = -1, int areaID = -1);

	// Make a box constraint.
	int rmCreateBoxConstraint(string name = "", float startX = 0, float startZ = 0, float endX = 0, float endZ = 0, float bufferFraction = 0.1);

	// Makes a 'pie' constraint.
	int rmCreatePieConstraint(string name = "", float xFraction = 0, float zFraction = 0, float insideRadius = 0, float outsideRadius = 0, float minAngle = 0, float maxAngle = 0, float bufferFraction = 0.1);

	// Make an area overlap constraint.
	int rmCreateAreaOverlapConstraint(string name = "", int areaID = -1);

	// Make a constraint that forces something to remain within an area.
	int rmCreateAreaConstraint(string name = "", int areaID = -1);

	// Make an area distance constraint.
	int rmCreateAreaDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make an area max distance constraint.
	int rmCreateAreaMaxDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make a constraint that forces something to remain within an area's edge.
	int rmCreateEdgeConstraint(string name = "", int areaID = -1);

	// Make an area edge distance constraint.
	int rmCreateEdgeDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make an area edge max distance constraint.
	int rmCreateEdgeMaxDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make a constraint that forces something to remain within an area's cliff edge.
	int rmCreateCliffEdgeConstraint(string name = "", int areaID = -1);

	// Make an area cliff edge distance constraint.
	int rmCreateCliffEdgeDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make an area cliff edge max distance constraint.
	int rmCreateCliffEdgeMaxDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make a constraint that forces something to remain within an area's cliff ramp edge.
	int rmCreateCliffRampConstraint(string name = "", int areaID = -1);

	// Make an area cliff ramp edge distance constraint.
	int rmCreateCliffRampDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make an area cliff ramp edge max distance constraint.
	int rmCreateCliffRampMaxDistanceConstraint(string name = "", int areaID = -1, float distance = -1);

	// Make a class distance constraint.
	int rmCreateClassDistanceConstraint(string name = "", int classID = -1, float distance = -1);

	// Make a type distance constraint.
	int rmCreateTypeDistanceConstraint(string name = "", string classID = "", float distance = -1);

	// Make a constraint to avoid terrain with certain a passability.
	int rmCreateTerrainDistanceConstraint(string name = "", string type = "", bool passable = false, float distance = -1);

	// Make a constraint to be close to terrain with certain a passability.
	int rmCreateTerrainMaxDistanceConstraint(string name = "", string type = "", bool passable = false, float distance = -1);

	// Make a constraint to pass if in or out of a corner.
	int rmCreateCornerConstraint(string name = "", int corner = -1, bool outside = true);

	// Make a constraint to avoid trade routes.
	int rmCreateTradeRouteDistanceConstraint(string name = "", float minDistance = 0);

	// Add specified constraint to an area.
	bool rmAddAreaConstraint(int areaID = -1, int constraintID = -1);

	// Create home city gather point constraint to avoid all HCGPs.
	bool rmCreateHCGPConstraint(string name = "", float minDistance = 0);

	// Create home city gather point constraint to avoid given player's HCGP.
	bool rmCreateHCGPSelfConstraint(string name = "", int playerID = -1, float minDistance = 0);

	// Create home city gather point constraint to avoid given player's ally's HCGPs.
	bool rmCreateHCGPAllyConstraint(string name = "", int playerID = -1, float minDistance = 0);

	// Create home city gather point constraint to avoid given player's enemy's HCGPs.
	bool rmCreateHCGPEnemyConstraint(string name = "", int playerID = -1, float minDistance = 0);

	// Make an max height constraint (terrain must be less than given height).
	int rmCreateMaxHeightConstraint(string name = "", float height = 0);

	// Add specified constraint to a fairLoc placement.
	bool rmAddFairLocConstraint(int fairLocID = -1, int constraintID = -1);

	// Add specified constraint to given object def.
	bool rmAddObjectDefConstraint(int defID = -1, int constraintID = -1);

	// Define a class with the given name.
	int rmDefineClass(string className = "");

	// Add given area to specified class.
	bool rmAddAreaToClass(int areaID = -1, int classID = -1);

	// Add given object def to specified class.
	bool rmAddObjectDefToClass(int objectDefID = -1, int classID = -1);

	// Gets class ID for given class name.
	int rmClassID(string name = "");

	// Gets constraint ID for given constraint name.
	int rmConstraintID(string name = "");

	// Creates an object definition.
	int rmCreateObjectDef(string name = "");

	// Creates special object definition for starting units with the given cluster distance.
	int rmCreateStartingUnitsObjectDef(float clusterDistance = 3);

	// Set the minimum distance for the object definition (in meters).
	bool rmSetObjectDefMinDistance(int defID = -1, float dist = 0);

	// Set the maximum distance for the object definition (in meters).
	bool rmSetObjectDefMaxDistance(int defID = -1, float dist = 0);

	// Turn on the garrison secondary units flag.
	bool rmSetObjectDefGarrisonSecondaryUnits(int defID = -1, bool on = true);

	// Turn on the garrison starting units flag.
	bool rmSetObjectDefGarrisonStartingUnits(int defID = -1, bool on = true);

	// Creates a herd out of all units placed in this object def.
	bool rmSetObjectDefCreateHerd(int defID = -1, bool on = true);

	// Set a herd angle(clockwise from +z) in the object def.
	bool rmSetObjectDefHerdAngle(int defID = -1, float angle = 45);

	// Lets objects overlap within this object def.
	bool rmSetObjectDefAllowOverlap(int defID = -1, bool on = true);

	// Forces things in this object def to get full arbitrary rotation.
	bool rmSetObjectDefForceFullRotation(int defID = -1, bool on = true);

	// Add item to object definition.
	bool rmAddObjectDefItem(int defID = -1, string unitName = "", int count = 0, float clusterDistance = 0);

	// Add item to object definition.
	bool rmAddObjectDefItemByTypeID(int defID = -1, int unitTypeID = -1, int count = 0, float clusterDistance = 0);

	// Place object definition at specific location for given player.
	int rmPlaceObjectDefAtLoc(int defID = -1, int playerID = -1, float xFraction = 0, float zFraction = 0, int placeCount = 1);

	// Place object definition at specific point for given player.
	int rmPlaceObjectDefAtPoint(int defID = -1, int playerID = -1, vector point = cInvalidVector, int placeCount = 1);

	// Set the trade route for all objects in this object definition.
	int rmSetObjectDefTradeRouteID(int defID = -1, int tradeRouteID = -1);

	// Place object definition per player.
	int rmPlaceObjectDefPerPlayer(int defID = -1, bool playerOwned = true, int placeCount = 1);

	// Place object definition for the player at the given area's location.
	int rmPlaceObjectDefAtAreaLoc(int defID = -1, int playerID = -1, int areaID = -1, int placeCount = 1);

	// Place object definition for the player in the given area.
	int rmPlaceObjectDefInArea(int defID = -1, int playerID = -1, int areaID = -1, int placeCount = 1);

	// Place object definition for the player at the location of a random area in the given class.
	int rmPlaceObjectDefAtRandomAreaOfClass(int defID = -1, int playerID = -1, int classID = -1, int placeCount = 1);

	// Place object definition for the player in a random area in the given class.
	int rmPlaceObjectDefInRandomAreaOfClass(int defID = -1, int playerID = -1, int classID = -1, int placeCount = 1);

	// Creates an connection.
	int rmCreateConnection(string name = "");

	// Sets the connection type.
	int rmSetConnectionType(int connectionID = -1, int connectionType = 0, bool connectAll = true, float connectPercentage = 1);

	// Adds an area to the connection.
	bool rmAddConnectionArea(int connectionID = -1, int areaID = -1);

	// Sets the position variance of a connection.
	bool rmSetConnectionPositionVariance(int connectionID = -1, float variance = 0);

	// Sets the width of a connection.
	bool rmSetConnectionWidth(int connectionID = -1, float width = 0, float variance = 0);

	// Sets the base height of a connection.
	bool rmSetConnectionBaseHeight(int connectionID = -1, float width = 0);

	// Sets area coherence (0-1).
	bool rmSetConnectionCoherence(int connectionID = -1, float width = 0);

	// Sets whether a connection warns on failure.
	bool rmSetConnectionWarnFailure(int connectionID = -1, bool warn = false);

	// Sets how smoothly connection height blends into surroundings.
	bool rmSetConnectionHeightBlend(int connectionID = -1, int width = 0);

	// Sets connection edge smoothing distance (distance is number of neighboring points to consider in each direction).
	bool rmSetConnectionSmoothDistance(int connectionID = -1, int width = 0);

	// Adds a terrain replacement rule to the connection.
	bool rmAddConnectionTerrainReplacement(int connectionID = -1, string terrainTypeName = "", string newTypeName = "");

	// Sets the terrain cost for a connection.
	bool rmSetConnectionTerrainCost(int connectionID = -1, string terrainTypeName = "", float cost = 1);

	// Sets the base terrain cost for a connection.
	bool rmSetConnectionBaseTerrainCost(int connectionID = -1, float cost = 1);

	// Builds the given connection.
	bool rmBuildConnection(int connectionID = -1);

	// Adds the connection to specified class.
	bool rmAddConnectionToClass(int connectionID = -1, int classID = -1);

	// Add specified constraint to a connection.
	bool rmAddConnectionConstraint(int connectionID = -1, int constraintID = -1);

	// Add specified constraint for a connection start point.
	bool rmAddConnectionStartConstraint(int connectionID = -1, int constraintID = -1);

	// Add specified constraint for a connection end point.
	bool rmAddConnectionEndConstraint(int connectionID = -1, int constraintID = -1);

	// Sets the friendly cool loading screen text.
	void rmSetStatusText(string status = "", float progress = 0);

	// Returns the square root of x.
	float sqrt(float x = 0);

	void rmSetVPFile(string filename = "");

	int rmCreateTrigger(string triggerName = "");

	bool rmSwitchToTrigger(int triggerID = -1);

	int rmTriggerID(string triggerName = "");

	int rmSetTriggerPriority(int priority = 2);

	int rmSetTriggerActive(bool active = true);

	int rmSetTriggerRunImmediately(bool runImmediately = false);

	int rmSetTriggerLoop(bool loop = false);

	int rmAddTriggerCondition(string conditionType = "");

	bool rmSetTriggerConditionParam(string paramName = "", string value = "", bool add = false);

	bool rmSetTriggerConditionParamInt(string paramName = "", int value = 0, bool add = false);

	bool rmSetTriggerConditionParamFloat(string paramName = "", float value = 0, bool add = false);

	bool rmSetTriggerConditionParamArmy(string paramName = "", int playerID = -1, int armyID = -1, bool add = false);

	bool rmAddTriggerEffect(string effectType = "");

	int rmSetTriggerEffectParam(string paramName = "", string value = "", bool add = false);

	bool rmSetTriggerEffectParamInt(string paramName = "", int value = 0, bool add = false);

	bool rmSetTriggerEffectParamFloat(string paramName = "", float value = 0, bool add = false);

	bool rmSetTriggerEffectParamArmy(string paramName = "", int playerID = -1, int armyID = -1, bool add = false);

	int rmCreateArmy(int playerID = -1, string armyName = "");

	bool rmAddUnitsToArmy(int playerID = -1, int armyID = -1, int objectDefID = -1);

	int rmGetNumberUnitsPlaced(int objectDefID = -1);

	int rmGetUnitPlaced(int objectDefID = -1, int index = -1);

	int rmGetUnitPlacedOfPlayer(int objectDefID = -1, int playerID = -1);

	bool rmDefineConstant(string name = "", int value = -1);

	void rmSetIgnoreForceToGaia(bool val = false);

	// Creates a grouping.
	int rmCreateGrouping(string name = "", string filename = "");

	// Add specified constraint to a grouping.
	bool rmAddGroupingConstraint(int GroupingID = -1, int constraintID = -1);

	// Place grouping at specified location.
	int rmPlaceGroupingAtLoc(int groupingID = -1, int playerID = -1, float xFraction = 0, float zFraction = 0, int placeCount = 1);

	// Place grouping at specified point.
	int rmPlaceGroupingAtPoint(int groupingID = -1, int playerID = -1, vector point = cInvalidVector, int placeCount = 1);

	// Place grouping for the player in the given area.
	int rmPlaceGroupingInArea(int groupingID = -1, int playerID = -1, int areaID = -1, int placeCount = 1);

	// Set the minimum distance for the grouping (in meters).
	bool rmSetGroupingMinDistance(int defID = -1, float dist = 0);

	// Set the maximum distance for the grouping (in meters).
	bool rmSetGroupingMaxDistance(int defID = -1, float dist = 0);

	// Add given grouping to specified class.
	bool rmAddGroupingToClass(int GroupingID = -1, int classID = -1);

	// Creates a trade route.
	int rmCreateTradeRoute();

	// Adds the given waypoint to the specified trade route.
	bool rmAddTradeRouteWaypoint(int tradeRouteID = -1, float xFraction = 0, float zFraction = 0);

	// Adds the given waypoint to the specified trade route.
	bool rmAddTradeRouteWaypointVector(int tradeRouteID = -1, vector v = cOriginVector);

	// Adds random waypoints to the specified trade route.
	bool rmAddRandomTradeRouteWaypoints(int tradeRouteID = -1, float endXFraction = 0, float endZFraction = 0, int count = 0, float maxVariation = 0);

	// Adds random waypoints to the specified trade route.
	bool rmAddRandomTradeRouteWaypointsVector(int tradeRouteID = -1, vector v = cOriginVector, int count = 0, float maxVariation = 0);

	// Creates a trade route in the specified area.
	bool rmCreateTradeRouteWaypointsInArea(int tradeRouteID = -1, int areaID = -1, float length = 0);

	// Retrieves a waypoint along the trade route based on the fraction.
	vector rmGetTradeRouteWayPoint(vector result, int tradeRouteID = -1, float fraction = 0);

	// Builds the trade route with the given terrain type.
	bool rmBuildTradeRoute(int tradeRouteID = -1, string terrainTypeName = "");

	// Sets the HCGP for the given player.
	bool rmSetHomeCityGatherPoint(int playerID = -1, vector point = cInvalidVector);

	// Sets the HCWSP for the given player.
	bool rmSetHomeCityWaterSpawnPoint(int playerID = -1, vector point = cInvalidVector);

	// Returns the lowest HC Level of the players in the game.
	int rmGetLowHomeCityLevel();

	// Returns the average (rounded down) HC Level of the players in the game.
	int rmGetAverageHomeCityLevel();

	// Returns the highest HC Level of the players in the game.
	int rmGetHighHomeCityLevel();

	// Returns the HC Level of the given player.
	int rmGetHomeCityLevel(int playerID = -1);

	// Returns the position of the unit.
	vector rmGetUnitPosition(vector result, int unitID = -1);

	// Indicates that this map is of a certain type (it can be multiple types simultaneously.
	void rmSetMapType(string type = "");

	// Returns true if the map belongs to the given type.
	bool rmIsMapType(string type = "");

	// Adds constraint to closest point finder.
	bool rmAddClosestPointConstraint(int constraintID = -1);

	// Clears constraints for closest point finder.
	void rmClearClosestPointConstraints();

	// Finds closest point satisfying the preset constraints.
	vector rmFindClosestPoint(vector result, float xFraction = 0, float zFraction = 0, float maxDistance = 0);

	// Finds closest point satisfying the preset constraints.
	vector rmFindClosestPointVector(vector result, vector a = cOriginVector, float b = 0);

	// Returns which area is closer.
	int rmFindCloserArea(float xFraction = 0, float zFraction = 0, int area1 = -1, int area2 = -1);

	// Adds the given waypoint to the specified cliff area (for valleys).
	bool rmAddAreaCliffWaypoint(int areaID = -1, float xFraction = 0, float zFraction = 0);

	// Adds random waypoints to the specified cliff valley area.
	bool rmAddAreaCliffRandomWaypoints(int areaID = -1, float endXFraction = 0, float endZFraction = 0, int count = 0, float maxVariation = 0);

	// Sets the min/max difficulty levels for placing nuggets.
	void rmSetNuggetDifficulty(int minLevel = 0, int maxLevel = 2147483647);

	// Sets whether or not to reveal oceans.
	void rmSetOceanReveal(bool a = true);

	// Sets the handler for given type of event.
	bool hcSetXSHandler(string handlerFunctionName = "", int type = -1);

	// Sets the handler for a unit for a given type of event.
	bool hcSetUnitXSHandler(int unitID = -1, string handlerFunctionName = "", int type = -1);

	// Returns a random number (mod'ed by max if provided).
	int hcRandInt(int max = -1);

	// Returns a random position guaranteed to be on the map.
	vector hcRandPosition(vector result);

	// Returns the HomeCity Unit ID for this unit.
	int hcGetMyUnitID();

	// Returns the HomeCity group ID for this unit.
	int hcUnitGetGroupID(int unitID = -1);

	// Returns the position of the unit.
	vector hcUnitGetPosition(vector result, int unitID = -1);

	// Returns the action type of the unit.
	int hcUnitGetActionType(int unitID = -1);

	// Makes the unit go into idle mode forever.
	bool hcUnitGoIdle(int unitID = -1, bool queue = false);

	// Returns the script for the unit.
	string hcUnitGetScript(int unitID = -1);

	// Returns the number of unlocked units available.
	int hcGetNumUnlockedUnits(bool regularUnits = true, bool performerUnits = true);

	// Returns the proto unit ID for an unlocked unit.
	int hcGetUnlockedUnitProtoUnitID(int unitIndex = -1, bool regularUnits = true, bool performerUnits = true);

	// Returns the visual file name for an unlocked unit.
	string hcGetUnlockedUnitVisualFilename(int unitIndex = -1, bool regularUnits = true, bool performerUnits = true);

	// Returns the script file name for an unlocked unit.
	string hcGetUnlockedUnitScriptFilename(int unitIndex = -1, bool regularUnits = true, bool performerUnits = true);

	// Returns the performance position for a unit.
	vector hcUnitGetPerformPosFromGroup(vector result, int groupID = -1, int unitID = -1);

	// Returns the performance forward vector for a unit.
	vector hcUnitGetPerformForwardFromGroup(vector result, int groupID = -1, int unitID = -1);

	// Creates a unit; specify either protoUnitID or visualFilename; returns the new unit's ID.
	int hcUnitCreateUsingPos(int protoUnitID = -1, string visualFilename = "", string aiFilename = "", vector position = cInvalidVector, vector forward = cInvalidVector, bool visible = true);

	// Creates a unit; specify either protoUnitID or visualFilename; returns the new unit's ID.
	int hcUnitCreate(int protoUnitID = -1, string visualFilename = "", string aiFilename = "", int waypoint = -1);

	// Creates a unit at the bone position; specify either protoUnitID or visualFilename; returns the new unit's ID.
	int hcUnitCreateAtBone(int protoUnitID = -1, string visualFilename = "", string aiFilename = "", string boneName = "");

	// Populates the home city with all units needed.
	void hcPopulateHomeCity();

	// Gets the initial time a unit should pause before spawning.
	float hcUnitGetInitialPauseTime(int unitID = -1);

	// Sets the initial time a unit should pause before spawning.
	void hcUnitSetInitialPauseTime(int unitID = -1, float pauseTime = 0);

	// Enables / disables a unit's flag.
	bool hcUnitSetFlag(int unitID = -1, int unitFlag = -1, bool enable = true, bool queue = false);

	// Creates a performer group.
	int hcCreatePerformerGroup(int numPerformers = -1, float attentionRadius = 10);

	// Reserves a performer area.
	bool hcReservePerformerArea(int groupID = -1);

	// Returns how many performer groups are currently playing.
	int hcGetNumPerformerGroups();

	// Adds a unit to a group of performers.
	void hcAddUnitToPerformerGroup(int groupID = -1, int unitID = -1);

	// Exits the unit (this will kill the unit).
	bool hcUnitExit(int unitID = -1, bool queue = false);

	// Nukes all HC units.
	void hcUnitDestroyAll();

	// Plays the anim for the unit.
	bool hcUnitPlayAnim(int unitID = -1, string animation = "", float seconds = 1, int loop = 0, bool queue = false);

	// Walks the unit to the WPID.
	bool hcUnitMoveToWPID(int unitID = -1, int startWPID = -1, int goalWPID = -1, float speed = 2, float goalTolerance = 2, bool queue = false);

	// Walks the unit to the position.
	bool hcUnitMoveToPos(int unitID = -1, int startWPID = -1, vector BVector = cInvalidVector, float goalPos = 2, float speed = 2, bool goalTolerance = false);

	// Turns the unit towards the forward vector.
	bool hcUnitTurn(int unitID = -1, vector BVector = cInvalidVector, float forward = 30, bool turnRateInDegreesPerSec = false);

	// Moves the unit to the given waypoint immediately.
	bool hcUnitTeleportToWPID(int unitID = -1, int WPID = -1);

	// Unit follows another unit.
	bool hcUnitFollow(int unitID = -1, int unitToFollowID = -1, float speed = 2, bool queue = false);

	// Unit exits a building.
	bool hcUnitExitBuilding(int unitID = -1, int buildingID = -1, float pauseTime = 0, float speed = 2, bool queue = false);

	// Unit enters a building.
	bool hcUnitEnterBuilding(int unitID = -1, int buildingID = -1, float speed = 2, bool queue = false);

	// Makes unit visible/invisible.
	bool hcUnitSetVisible(int unitID = -1, bool state = false, bool queue = false);

	// Makes script wait a number of seconds
	bool hcUnitWait(int unitID = -1, float pauseTime = 1, bool queue = false);

	// Frees the given waypoint.
	void hcUnitFreeWPID(int unitID = -1, int wpid = -1, bool queue = false);

	// Occupies the given waypoint.
	void hcOccupyWPID(int wpid = -1);

	// Returns the number of units with a given AI filename.
	int hcGetNumberUnitsWithAI(string aiFilename = "");

	// Returns the index-th unit with the given AI filename.
	int hcGetUnitWithAI(string aiFilename = "", int index = -1);

	// Returns the index-th performer unit in the proximity.
	int hcGetPerformerInProximity(int unitID = -1);

	// Returns the number of waypoints.
	int hcGetNumberWaypoints();

	// Returns the position for a waypoint.
	vector hcGetWaypointPos(vector result, int waypoint = -1);

	// Returns the direction for a waypoint.
	vector hcGetWaypointDir(vector result, int waypoint = -1);

	// Returns the WPID closest to the position.
	int hcGetNearestWPID(vector position = cInvalidVector);

	// Returns the WPID of a random waypoint.
	int hcGetRandomWPID(int waypointMask = 0);

	// Returns the WPID of a random waypoint.
	int hcGetRandomFreeWPID(int waypointMask = 0);

	// Returns the ID for a building with the specified name.
	int hcGetBuildingIDByName(string buildingName = "");

	// CP AI echo.
	void aiEcho(string echoString = "None");

	// CP AI error.
	void aiErrorMessage(string errorString = "None");

	// Sets the seed of the random number generator.
	void aiRandSetSeed(int seed = -1);

	// Returns a random number (mod'ed by max if provided).
	int aiRandInt(int max = -1);

	// Returns a random location guaranteed to be on the map.
	vector aiRandLocation(vector result);

	// Sets playerID's AI to the given filename.
	void aiSet(string filename = "None", int playerID = -1);

	// Sets a breakpoint.
	void aiBreakpointSet(int a = -1, string b = "", int c = -1, bool d = true);

	// Restart XS execution after the current breakpoint.
	void aiBreakpointGo(int a = -1);

	// Gets the player's personality.
	string aiGetPersonality();

	// Returns the rush boom scale for this ai.
	float aiPersonalityGetRushBoom();

	// Returns the number of player's in the Personality's history.
	int aiPersonalityGetNumberPlayerHistories();

	// Creates are player history for the given playername.
	int aiPersonalityCreatePlayerHistory(string a = "");

	// Resets the given player history.
	bool aiPersonalityResetPlayerHistory(int playerHistoryIndex = -1);

	// Returns the name of the index'th player in the Personality's history.
	string aiPersonalityGetPlayerHistoryName(int index = -1);

	// Returns a playerHistoryIndex if this personality has played searchPlayerName before.
	int aiPersonalityGetPlayerHistoryIndex(string searchPlayerName = "");

	// Returns the user value, given the playerHistoryIndex and the userVarName.
	float aiPersonalityGetPlayerUserVar(int playerHistoryIndex = -1, string userVarName = "");

	// sets the value, given the playerHistoryIndex, userVarName (max 255 chars), and value.
	bool aiPersonalitySetPlayerUserVar(int playerHistoryIndex = -1, string userVarName = "", float val = -1);

	// Returns the number of games played against/with the given the playerHistoryIndex.
	int aiPersonalityGetPlayerGamesPlayed(int playerHistoryIndex = -1, int playerRelation = -1);

	// Returns the given resource from the gameIndex game. If gameIndex is -1, this will return the avg of all games played.
	float aiPersonalityGetGameResource(int playerHistoryIndex = -1, int gameIndex = -1, int resourceID = -1);

	bool aiPersonalityGetDidIWinLastGameVS(int playerHistoryIndex = -1);

	// Returns the unit count from the gameIndex game. If gameIndex is -1, this will return the avg of all games played.
	int aiPersonalityGetGameUnitCount(int playerHistoryIndex = -1, int gameIndex = -1, int unitType = -1);

	// Returns the 1st attacktime from the gameIndex game.
	int aiPersonalityGetGameFirstAttackTime(int playerHistoryIndex = -1, int gameIndex = -1);

	// Returns the total games the given player has won against this AI
	int aiPersonalityGetTotalGameWins(int playerHistoryIndex = -1, int playerRelation = -1);

	// Returns the script-defined most hated player ID for this player.
	int aiGetMostHatedPlayerID();

	// Returns the playerID for the player the AI thinks it should be attacking.
	int aiCalculateMostHatedPlayerID(int comparePlayerID = -1);

	// Sets the script-defined most hated player ID for this player.
	void aiSetMostHatedPlayerID(int v = -1);

	// Returns the available economy pop for this player.
	int aiGetAvailableEconomyPop();

	// Returns the current economy pop for this player.
	int aiGetCurrentEconomyPop();

	// Returns the script-defined economy pop for this player.
	int aiGetEconomyPop();

	// Set the script-defined economy pop for this player.
	void aiSetEconomyPop(int v = 100);

	// Returns the script-defined military pop for this player.
	int aiGetAvailableMilitaryPop();

	// Returns the script-defined military pop for this player.
	int aiGetMilitaryPop();

	// Set the script-defined military pop for this player.
	void aiSetMilitaryPop(int v = 100);

	// Returns the economy priority percentage.
	float aiGetEconomyPercentage();

	// Set the economy priority percentage.
	void aiSetEconomyPercentage(float v = 0.5);

	// Returns the militarypriority percentage.
	float aiGetMilitaryPercentage();

	// Set the military priority percentage.
	void aiSetMilitaryPercentage(float v = 0.5);

	// Returns the attack response distance.
	float aiGetAttackResponseDistance();

	// Set the attack response distance.
	void aiSetAttackResponseDistance(float v = 50);

	// Returns the number of matching goals.
	int aiGoalGetNumber(int goalType = -1, int goalState = -1, bool active = true);

	// Returns the ID of matching goal.
	int aiGoalGetIDByIndex(int goalType = -1, int goalState = -1, bool active = true, int index = -1);

	// Returns the number of matching plans.
	int aiPlanGetNumber(int planType = -1, int planState = -1, bool active = true);

	// Returns the ID of matching plan.
	int aiPlanGetIDByIndex(int planType = -1, int planState = -1, bool active = true, int index = -1);

	// Creates a plan of the given name and type.
	int aiPlanCreate(string planName = "", int typeName = -1);

	// Destroys the given plan.
	bool aiPlanDestroy(int planID = -1);

	// Destroys the plan of the given name.
	bool aiPlanDestroyByName(string name = "");

	// Returns the ID of the plan with the given name.
	int aiPlanGetID(string name = "");

	// Returns the ID of the first plan containing the given string in its name.
	int aiPlanGetIDSubStr(string searchStr = "");

	// Returns the ID of the plan with the given parms.
	int aiPlanGetIDByTypeAndVariableType(int planType = -1, int varType = -1, int varID = -1, bool active = true);

	// Returns the ID of the plan with the given active index.
	int aiPlanGetIDByActiveIndex(int activeIndex = -1);

	// Returns the name of the given plan.
	string aiPlanGetName(int planID = -1);

	// Returns the type of the given plan.
	int aiPlanGetType(int planID = -1);

	// Returns the state of the given plan.
	int aiPlanGetState(int planID = -1);

	// Returns the priority of the given plan.
	int aiPlanGetActualPriority(int planID = -1);

	// Returns the priority of the given plan.
	int aiPlanGetDesiredPriority(int planID = -1);

	// Sets the priority of the given plan.
	bool aiPlanSetDesiredPriority(int planID = -1, int priority = -1);

	// Adds a unit type to the plan.
	bool aiPlanAddUnitType(int planID = -1, int unitTypeID = -1, int numberNeed = -1, int numberWant = -1, int numberMax = -1);

	// Returns the number of units currently assigned in the given plan.
	int aiPlanGetNumberUnits(int planID = -1, int unitTypeID = -1);

	// Adds a unit to the plan.
	bool aiPlanAddUnit(int planID = -1, int unitID = -1);

	// Returns the location for this plan.
	vector aiPlanGetLocation(vector result, int planID = -1);

	// Returns the initial positon that was set for this plan.
	vector aiPlanGetInitialPosition(vector result, int planID = -1);

	// Sets the initial positon for this plan.
	void aiPlanSetInitialPosition(int planID = -1, vector initialPosition = cInvalidVector);

	// Sets the waypoints of the given plan to the waypoints of the given path.
	bool aiPlanSetWaypoints(int planID = -1, int pathID = -1);

	// Adds the waypoint to the given plan.
	bool aiPlanAddWaypoint(int planID = -1, vector waypoint = cInvalidVector);

	// Returns the number of values for this variable index.
	int aiPlanGetNumberVariableValues(int planID = -1, int planVariableIndex = -1);

	// Sets the number of values for this variable.
	bool aiPlanSetNumberVariableValues(int planID = -1, int planVariableIndex = -1, int numberValues = -1, bool clearCurrentValues = true);

	// Removes the index-th value of the variable.
	bool aiPlanRemoveVariableValue(int planID = -1, int planVariableIndex = -1, int variableIndex = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetVariableInt(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, int value = -1);

	// Gets the given variable of the given plan.
	int aiPlanGetVariableInt(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetVariableFloat(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, float value = -1);

	// Gets the given variable of the given plan.
	float aiPlanGetVariableFloat(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetVariableVector(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, vector value = cInvalidVector);

	// Gets the given variable of the given plan.
	vector aiPlanGetVariableVector(vector result, int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetVariableBool(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, bool value = false);

	// Gets the given variable of the given plan.
	bool aiPlanGetVariableBool(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetVariableString(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, string value = "");

	// Gets the given variable of the given plan.
	string aiPlanGetVariableString(int planID = -1, int planVariableIndex = -1);

	// Returns the number of values for this variable index.
	int aiPlanGetNumberUserVariableValues(int planID = -1, int planVariableIndex = -1);

	// Sets the number of values for this variable.
	bool aiPlanSetNumberUserVariableValues(int planID = -1, int planVariableIndex = -1, int numberValues = -1, bool clearCurrentValues = true);

	// Removes all of the user variables from the given plan.
	bool aiPlanRemoveUserVariables(int planID = -1);

	// Removes the user variable.
	bool aiPlanRemoveUserVariable(int planID = -1, int planVariableIndex = -1);

	// Removes the index-th value of the user variable.
	bool aiPlanRemoveUserVariableValue(int planID = -1, int planVariableIndex = -1, int variableIndex = -1);

	// Adds the variable to the given plan.
	bool aiPlanAddUserVariableInt(int planID = -1, int planVariableIndex = -1, string name = "", int numberValues = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetUserVariableInt(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, int value = -1);

	// Gets the given variable of the given plan.
	int aiPlanGetUserVariableInt(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Adds the variable to the given plan.
	bool aiPlanAddUserVariableFloat(int planID = -1, int planVariableIndex = -1, string name = "", int numberValues = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetUserVariableFloat(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, float value = -1);

	// Gets the given variable of the given plan.
	float aiPlanGetUserVariableFloat(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Adds the variable to the given plan.
	bool aiPlanAddUserVariableVector(int planID = -1, int planVariableIndex = -1, string name = "", int numberValues = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetUserVariableVector(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, vector value = cInvalidVector);

	// Gets the given variable of the given plan.
	vector aiPlanGetUserVariableVector(vector result, int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Adds the variable to the given plan.
	bool aiPlanAddUserVariableBool(int planID = -1, int planVariableIndex = -1, string name = "", int numberValues = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetUserVariableBool(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, bool value = false);

	// Gets the given variable of the given plan.
	bool aiPlanGetUserVariableBool(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Adds the variable to the given plan.
	bool aiPlanAddUserVariableString(int planID = -1, int planVariableIndex = -1, string name = "", int numberValues = -1);

	// Sets the given variable of the given plan.
	bool aiPlanSetUserVariableString(int planID = -1, int planVariableIndex = -1, int valueIndex = -1, string value = "");

	// Gets the given variable of the given plan.
	string aiPlanGetUserVariableString(int planID = -1, int planVariableIndex = -1, int valueIndex = -1);

	// Gets the active-ness of the given plan.
	bool aiPlanGetActive(int planID = -1);

	// Sets active on/off for the given plan.
	bool aiPlanSetActive(int planID = -1, bool active = true);

	// Gets the noMoreUnits-ness of the given plan.
	bool aiPlanGetNoMoreUnits(int planID = -1);

	// Sets noMoreUnits on/off for the given plan.
	bool aiPlanSetNoMoreUnits(int planID = -1, bool v = true);

	// Gets the orphan-ness of the given plan.
	bool aiPlanGetOrphan(int planID = -1);

	// Sets orphan on/off for the given plan.
	bool aiPlanSetOrphan(int planID = -1, bool orphan = true);

	// Gets the UA response-ness of the given plan.
	bool aiPlanGetAllowUnderAttackResponse(int planID = -1);

	// Sets under attack response on/off for the given plan.
	bool aiPlanSetAllowUnderAttackResponse(int planID = -1, bool uAR = true);

	// Gets the unit stance of the given plan.
	int aiPlanGetUnitStance(int planID = -1);

	// Sets unit stance for the given plan.
	bool aiPlanSetUnitStance(int planID = -1, int stance = 0);

	// Sets 'requiresAllNeedUnits' on/off for the given plan.
	bool aiPlanSetRequiresAllNeedUnits(int planID = -1, bool rANU = true);

	// Sets event handler function for the given plan and event.
	bool aiPlanSetEventHandler(int planID = -1, int eventType = -1, string handlerName = "");

	// Sets the escrow for the plan.
	bool aiPlanSetEscrowID(int planID = -1, int escrowID = -1);

	// Gets the escrow for the plan.
	int aiPlanGetEscrowID(int planID = -1);

	// Gets the economy flag of the given plan.
	bool aiPlanGetEconomy(int planID = -1);

	// Sets economy on/off for the given plan.
	bool aiPlanSetEconomy(int planID = -1, bool v = true);

	// Gets the military flag of the given plan.
	bool aiPlanGetMilitary(int planID = -1);

	// Sets military on/off for the given plan.
	bool aiPlanSetMilitary(int planID = -1, bool v = true);

	// Gets the attack flag of the given plan.
	bool aiPlanGetAttack(int planID = -1);

	// Sets attack flag on/off for the given plan.
	bool aiPlanSetAttack(int planID = -1, bool v = true);

	// sets the plan's base id.
	bool aiPlanSetBaseID(int planID = -1, int baseID = -1);

	// gets the plan's base id.
	int aiPlanGetBaseID(int planID = -1);

	// Gets the of idle plans of the given type.
	int aiGetNumberIdlePlans(int planType = -1);

	// gets total aiCost of plan's units, weighted for HP if requested.
	float aiPlanGetUnitCost(int planID = -1, bool considerHitPoints = false);

	// enables or disables the chats from this ai player.
	void aiCommsAllowChat(bool flag = true);

	// Sends a statement to the designated player.
	int aiCommsSendStatement(int targetPlayerID = -1, int promptType = -1);

	// Sends a statement to the designated player. Adds a location flare.
	int aiCommsSendStatementWithVector(int targetPlayerID = -1, int promptType = -1, vector v = cInvalidVector);

	// Sets the handler for the communications system (invalid name unsets the handler).
	bool aiCommsSetEventHandler(string handlerFunctionName = "");

	// get sending player for specified sentence.
	int aiCommsGetSendingPlayer(int sentenceID = -1);

	// get chat verb for specified sentence.
	int aiCommsGetChatVerb(int sentenceID = -1);

	// get target type for specified sentence.
	int aiCommsGetChatTargetType(int sentenceID = -1);

	// get number of items in target list for specified sentence.
	int aiCommsGetTargetListCount(int sentenceID = -1);

	// get index item from specified sentence.
	int aiCommsGetTargetListItem(int sentenceID = -1, int index = -1);

	// get target location from specified sentence.
	vector aiCommsGetTargetLocation(vector result, int sentenceID = -1);

	// send a reply to a sentence.
	void aiCommsSendReply(int sentenceID = -1, int responseID = -1);

	// Sets the handler for given type of event.
	bool aiSetHandler(string handlerFunctionName = "", int type = -1);

	// Does a lightweight (no plan) move tasking of the given unit to the given location.
	bool aiTaskUnitMove(int unitID = -1, vector position = cOriginVector);

	// Does a lightweight (no plan) work tasking of the given unit on the given target unit.
	bool aiTaskUnitWork(int unitID = -1, int targetUnitID = -1);

	// Does a lightweight (no plan) build tasking of the given unit to build the given building.
	bool aiTaskUnitBuild(int unitID = -1, int buildingTypeID = -1, vector position = cOriginVector);

	// Does a lightweight (no plan) train tasking of the given unit for the given target unit type.
	bool aiTaskUnitTrain(int unitID = -1, int unitTypeID = -1);

	// Does a lightweight (no plan) research tasking of the given unit for the given tech ID.
	bool aiTaskUnitResearch(int unitID = -1, int techID = -1);

	// Deletes the given unit.
	bool aiTaskUnitDelete(int unitID = -1);

	// Tributes the given player.
	bool aiTribute(int playerID = -1, int resourceID = -1, float amount = -1);

	// sells (+100) the given resource.
	bool aiSellResourceOnMarket(int resourceID = -1);

	// buys (+100) the given resource.
	bool aiBuyResourceOnMarket(int resourceID = -1);

	// Returns the amount required to buy 100 units of the given resource.
	float aiGetMarketBuyCost(int resourceID = -1);

	// Returns the amount received for selling 100 units of the given resource.
	float aiGetMarketSellCost(int resourceID = -1);

	// Returns the RGP weight.
	float aiGetResourceGathererPercentageWeight(int rgpIndex = -1);

	// Sets the RGP weight.
	void aiSetResourceGathererPercentageWeight(int rgpIndex = -1, float weight = 0.5);

	// Normalizes all of the resource gatherer percentages weights to 1.0.
	void aiNormalizeResourceGathererPercentageWeights();

	// Returns the resource gatherer percentage for the given resource.
	float aiGetResourceGathererPercentage(int resourceID = -1, int rgpIndex = 0);

	// Sets the resource gatherer percentage for the given resource (if normalized is true, the percentages will be normalized to 1.0).
	void aiSetResourceGathererPercentage(int resourceID = -1, float value = 0, bool normalize = false, int rgpIndex = 0);

	// Normalizes all of the resource gatherer percentages to 1.0.
	void aiNormalizeResourceGathererPercentages(int rgpIndex = 0);

	// Gets the number of plans for the given breakdown.
	int aiGetResourceBreakdownNumberPlans(int resourceTypeID = -1, int resourceSubTypeID = -1, int baseID = -1);

	// Gets the priority of the plans for the given breakdown.
	int aiGetResourceBreakdownPlanPriority(int resourceTypeID = -1, int resourceSubTypeID = -1, int baseID = -1);

	// Gets the percentage for the given breakdown.
	float aiGetResourceBreakdownPercentage(int resourceTypeID = -1, int resourceSubTypeID = -1, int baseID = -1);

	// Sets a subtype breakdown for a resource.
	bool aiSetResourceBreakdown(int resourceTypeID = -1, int resourceSubTypeID = -1, int numberPlans = 0, int planPriority = 50, float percentage = 0, int baseID = -1);

	// Removes the given breakdown.
	bool aiRemoveResourceBreakdown(int resourceTypeID = -1, int resourceSubTypeID = -1, int baseID = -1);

	// Returns the auto gather escrow ID.
	int aiGetAutoGatherEscrowID();

	// Sets the auto gather escrow ID.
	void aiSetAutoGatherEscrowID(int escrowID = -1);

	// Returns the auto Farm escrow ID.
	int aiGetAutoFarmEscrowID();

	// Sets the auto Farm escrow ID.
	void aiSetAutoFarmEscrowID(int escrowID = -1);

	// Returns the per plan farm build limit.
	int aiGetFarmLimit();

	// Sets the per plan farm build limit.
	void aiSetFarmLimit(int limit = -1);

	// Returns allow buildings on/off.
	bool aiGetAllowBuildings();

	// Sets allow buildings on/off.
	void aiSetAllowBuildings(bool v = true);

	// CP AI chat to playerID.
	void aiChat(int playerID = -1, string chatString = "None");

	// Returns the number of unassigned units of the given type.
	int aiNumberUnassignedUnits(int typeID = -1);

	// Returns the number of unassigned units based on the goal's unit type(s).
	int aiNumberUnassignedUnitsByGoal(int goalID = -1);

	// adds an opportunity to the list and returns the id.
	int aiCreateOpportunity(int type = -1, int targettype = -1, int targetID = -1, int targetPlayerID = -1, int source = -1);

	// activates or deactivates an opportunity on the player's opp list.
	void aiActivateOpportunity(int opportunityID = -1, bool flag = true);

	// remove an opportunity on the player's opp list.
	void aiDestroyOpportunity(int opportunityID = -1);

	// finds the best currently scored opp.
	void aiFindBestOpportunity();

	// gets the source id from this opportunity
	int aiGetOpportunitySourceID(int opportunityID = -1);

	// gets the source type from this opportunity
	int aiGetOpportunitySourceType(int opportunityID = -1);

	// gets the radius from this opportunity
	float aiGetOpportunityRadius(float opportunityID = -1);

	// gets the target playerID from this opportunity
	int aiGetOpportunityTargetPlayerID(int opportunityID = -1);

	// gets the target type from this opportunity
	int aiGetOpportunityTargetType(int opportunityID = -1);

	// gets the type from this opportunity
	int aiGetOpportunityType(int opportunityID = -1);

	// gets the location from this opportunity
	vector aiGetOpportunityLocation(vector result, int opportunityID = -1);

	// gets the target id from this opportunity
	int aiGetOpportunityTargetID(int opportunityID = -1);

	// sets the target type for this opp.
	void aiSetOpportunityTargetType(int opportunityID = -1, int targetType = -1);

	// sets the target id for this opp.
	void aiSetOpportunityTargetID(int opportunityID = -1, int targetType = -1);

	// sets the radius for this opp.
	void aiSetOpportunityRadius(int opportunityID = -1, float radius = -1);

	// sets the location for this opp.
	void aiSetOpportunityLocation(int opportunityID = -1, vector location = cInvalidVector);

	// sets the score for this opp.
	bool aiSetOpportunityScore(int oppID = -1, int permission = -1, float affordable = -1, float classscore = -1, float instance = -1, float total = -1);

	// Casts the given God power tech, at the specified position.
	bool aiCastGodPowerAtPosition(int godPowerTechID = -1, vector pos = cOriginVector);

	// Get the god power tech id from the given slot.
	int aiGetGodPowerTechIDForSlot(int slotID = -1);

	// translate a granted tech id into a protopower id
	int aiGetGodPowerProtoIDForTechID(int techID = -1);

	// get the type for a ProtoPower
	int aiGetGodPowerType(int protoPowerID = -1);

	// find a valid god power plan to attach to an attack plan
	int aiFindBestAttackGodPowerPlan();

	// find a valid god power plan to use for town defense
	int aiFindBestTownDefenseGodPowerPlan();

	// Returns the world difficulty level.
	int aiGetWorldDifficulty();

	// Sets the world difficulty level.
	void aiSetWorldDifficulty(int v = -1);

	// Returns the name of the level.
	string aiGetWorldDifficultyName(int level = -1);

	// Returns the game's mode.
	int aiGetGameMode();

	// Returns the captain for the given player's team.
	int aiGetCaptainPlayerID(int playerID = -1);

	// returns whether or not its cool to turn ai autosaves on.
	bool aiGetAutosaveOn();

	// returns the current resource need for the given resource.
	float aiGetCurrentResourceNeed(int resourceID = -1);

	// Turns auto gathering of military units at bases on/off.
	bool aiSetAutoGatherMilitaryUnits(bool v = true);

	// sets the ai's Explore Danger Threshold value.
	bool aiSetExploreDangerThreshold(float value = -1);

	// gets the ai's Explore Danger Threshold value.
	float aiGetExploreDangerThreshold();

	// Sets the RM bool in the AI.
	void aiSetRandomMap(bool v = false);

	// sets the pause all age upgrades flag in the AI.
	void aiSetPauseAllAgeUpgrades(bool v = false);

	// gets the pause all age upgrades flag from the AI.
	bool aiGetPauseAllAgeUpgrades(bool a = false);

	// sets the min number of units in an attack army.
	void aiSetMinArmySize(int v = 5);

	// sets the min number of needed units to gather aggressive animals.
	void aiSetMinNumberNeedForGatheringAggressvies(int v = 0);

	// gets the min number of needed units to gather aggressive animals.
	int aiGetMinNumberNeedForGatheringAggressives();

	// sets the min number of wanted units to gather aggressive animals.
	void aiSetMinNumberWantForGatheringAggressives(int v = 0);

	// gets the min number of wanted units to gather aggressive animals.
	int aiGetMinNumberWantForGatheringAggressives();

	// reigns the current player..
	void aiResign();

	// asks the player if its ok to resign
	void aiAttemptResign(int a = -1);

	// sets the limit for how many LOS Protounits the AI can build
	void aiSetMaxLOSProtoUnitLimit(int limit = -1);

	// gets the limit for how many LOS Protounits the AI can build
	int aiGetMaxLOSProtoUnitLimit();

	// gets the current Pop needs of all the plans.
	int aiGetPopNeeds();

	// switch the newBaseID to be the main base.
	void aiSwitchMainBase(int newBaseID = -1, bool force = false);

	// Sets your default stance for all of your units.
	void aiSetDefaultStance(int defaultStance = -1);

	// Tells the AI if this is a water map or not.
	void aiSetWaterMap(bool v = true);

	// Tells us if the AI thinks this is a water map or not.
	bool aiGetWaterMap();

	// Is this a certain maptype or not. (AIFishingUseful, AITransportRequired, AITransportUseful)
	bool aiIsMapType(string mapType = "AIFishingUseful");

	// Returns the number of cards in the Current HC.
	int aiHCCardsGetTotal();

	// Has the cardindex been bought yet?
	bool aiHCCardsIsCardBought(int cardIndex = -1);

	// Can I buy this card now?
	bool aiHCCardsCanIBuyThisCard(int deckIndex = -1, int cardIndex = -1);

	// Buy this card now
	bool aiHCCardsBuyCard(int cardIndex = -1);

	// For this cardIndex, get the age prereq.
	int aiHCCardsGetCardAgePrereq(int cardIndex = -1);

	// For this cardIndex, get the age prereq.
	int aiHCCardsGetCardLevel(int cardIndex = -1);

	// For this cardIndex, get the TechID.
	int aiHCCardsGetCardTechID(int a = -1);

	// For this cardIndex, get the UnitType.
	int aiHCCardsGetCardUnitType(int a = -1);

	// For this cardIndex, get the UnitCount.
	int aiHCCardsGetCardUnitCount(int a = -1);

	// For this cardIndex, get the CardCount, -1 is Infinite.
	int aiHCCardsGetCardCount(int a = -1);

	// Get the best card using the optional cardtype and optional resourcePreference
	int aiHCCardsFindBestCard(int cardType = -1, int levelPref = -1, int resourcePref = -1);

	// Returns the number of decks in the Current HC.
	int aiHCGetNumberDecks();

	// Create a new HC Deck with the given name.
	int aiHCDeckCreate(string a = "AI Deck");

	// Makes the deckIndex the current active HC deck.
	bool aiHCDeckActivate(int deckIndex = -1);

	// Adds the card given to the givenHC Deck.
	bool aiHCDeckAddCardToDeck(int deckIndex = -1, int cardIndex = -1);

	// Returns the number of cards in the Current HC Deck.
	int aiHCDeckGetNumberCards(int deckIndex = -1);

	// play this card.
	bool aiHCDeckPlayCard(int cardIndex = -1);

	// For this card, get the age prereq
	int aiHCDeckGetCardAgePrereq(int deckIndex = -1, int cardIndex = -1);

	// For this card, get the level
	int aiHCDeckGetCardLevel(int deckIndex = -1, int cardIndex = -1);

	// For this card, get the techID
	int aiHCDeckGetCardTechID(int deckIndex = -1, int cardIndex = -1);

	// For this card, get the unitType
	int aiHCDeckGetCardUnitType(int deckIndex = -1, int cardIndex = -1);

	// For this card, get the unit Count
	int aiHCDeckGetCardUnitCount(int deckIndex = -1, int cardIndex = -1);

	// Can we play this card from the given deck?
	bool aiHCDeckCanPlayCard(int cardIndex = -1);

	// Gets how many cards of this type we can send. -1 mean infinite.
	int aiHCDeckCardGetCardCount(int deskIndex = -1, int cardIndex = -1);

	// Returns the HCGP.
	vector aiGetHCGatherPoint(vector result);

	// Sets the HCGP.
	bool aiSetHCGatherPoint();

	// returns the score for the given player.
	int aiGetScore(int playerID = -1);

	// returns the number of teams in the game.
	int aiGetNumberTeams();

	// Queues the auto savegame.
	void aiQueueAutoSavegame(int saveNumber = -1);

	// returns true, if this is a multiplayer game.
	bool aiIsMultiplayer();

	// returns the ID of the fallen explorer; if there isn't one, returns -1
	int aiGetFallenExplorerID();

	// ransoms the specified explorer using funds from the specified escrow account and spawns it from the specified building.
	bool aiRansomExplorer(int explorerID = -1, int escrowID = -1, int sourceBuildingID = -1);

	// builds walls around the specified building's colony using the specified escrow.
	bool aiBuildWall(int buildingID = -1, int escrowID = -1);

	// returns whether it is allowed to build a wall around the specified building's colony, and whether the player can afford it from the specified escrow.
	bool aiCanBuildWall(int buildingID = -1, int escrowID = -1);

	// returns the wall radius for the specified building's colony.
	float aiGetWallRadius(int buildingID = -1);

	// returns whether a wall exists around the specified building's colony.
	bool aiDoesWallExist(int buildingID = -1);

	// returns the current game type (e.g., cGameTypeScenario, cGameTypeRandom, etc).
	int aiGetGameType();

	// sets the specified tactic on the specified unit.
	bool aiUnitSetTactic(int unitID = -1, int tacticID = -1);

	// gets the specified unit's current tactic.
	int aiUnitGetTactic(int unitID = -1);

	// Prevent a resource from being spent by the AI.
	void aiResourceLock(int resourceID = -1);

	// Allow a resource to be spent by the AI.
	void aiResourceUnlock(int resourceID = -1);

	// Is this Escrow resource locked.
	bool aiResourceIsLocked(int resourceID = -1);

	// breaks the treaty using funds from the given escrow.
	bool aiBreakTreaty(int escrowID = -1);

	// checks whether the given player has a treaty.
	bool aiTreatyActive();

	// Sets the scripts choice for the AgeX Politician.
	void aiSetPoliticianChoice(int age = -1, int puid = -1);

	// Gets the scripts choice for the AgeX Politician.
	int aiGetPoliticianChoice(int age = -1);

	// Call this to make the AI fill out what Politicians are available.
	bool aiPopulatePoliticianList();

	// Gets the number of Politicans avaiable for AgeX.
	int aiGetPoliticianListCount(int age = -1);

	// Gets the index'th Politicans avaiable for AgeX.
	int aiGetPoliticianListByIndex(int age = -1, int index = -1);

	// Gets the last collected nugget's type
	int aiGetLastCollectedNuggetType(int playerID = -1);

	// Gets the last collected nugget's effect
	int aiGetLastCollectedNuggetEffect(int playerID = -1);

	// Gets the number of tradeposts controlled by this team (for monopoly victory).
	int aiGetNumberTradePostsControlled(int teamID = -1);

	// Gets the number of tradeposts needed to make a monopoly win possible.
	int aiGetNumberTradePostsNeededForMonopoly();

	// Returns true if the monopoly command can be given now.  Does not check cost.
	bool aiReadyForTradeMonopoly();

	// Executes a trade monopoly command, returns false if it fails.
	bool aiDoTradeMonopoly();

	// Returns true if a trade monopoly is possible in this game type.
	bool aiIsMonopolyAllowed();

	// Gets the number of relics controlled by this team (for relic victory).
	int aiGetNumberRelicsControlled(int teamID = -1);

	// Gets the number of relics needed to make a relic win possible.
	int aiGetNumberRelicsNeededForVictory();

	// Returns true if a relic capture victory is possible in this game type.
	bool aiIsRelicCaptureAllowed();

	// Returns true if a King of the Hill victory is possible in this game type.
	bool aiIsKOTHAllowed();

	// Gets the team that is king of the hill.
	int aiGetKOTHController();

	// Returns true if this team is king of the hill.
	bool aiIsTeamKOTH(int teamID = -1);

	// KB dump for player2's units from player1's perspective.
	void kbDump(int player1 = -1, int player2 = -1);

	// KB dump for player2's units of the given type from player1's perspective.
	void kbDumpType(int player1 = -1, int player2 = -1, string typeName = "Invalid");

	// Cheats and looks at all of the units on the map.  This will format your harddrive if you're not authorized to use it.
	void kbLookAtAllUnitsOnMap();

	// Returns the current population for the player.
	int kbGetPop();

	// Returns the current population cap for the player.
	int kbGetPopCap();

	// Returns the current age for the current player.
	int kbGetAge();

	// Returns the current age for the player specified.
	int kbGetAgeForPlayer(int id = -1);

	// Returns the culture for the player.
	int kbGetCulture();

	// Returns the culture for the given player.
	int kbGetCultureForPlayer(int a = -1);

	// Returns the culture name for the given culture.
	string kbGetCultureName(int a = -1);

	// Returns the civilization for the player.
	int kbGetCiv();

	// Returns the civ for the given player.
	int kbGetCivForPlayer(int a = -1);

	// Returns the civ name for the given civ.
	string kbGetCivName(int civID = -1);

	// Creates a unit query, returns the query ID.
	int kbUnitQueryCreate(string name = "DEFAULT");

	// Resets the given unit query data AND results.
	bool kbUnitQueryResetData(int queryID = -1);

	// Resets the given unit query results.
	bool kbUnitQueryResetResults(int queryID = -1);

	// Destroys the given unit query.
	bool kbUnitQueryDestroy(int queryID = -1);

	// Returns the number of results in the current query.
	int kbUnitQueryNumberResults(int queryID = -1);

	// Returns the UnitID of the index-th result in the current query.
	int kbUnitQueryGetResult(int queryID = -1, int index = -1);

	// Sets query data.
	bool kbUnitQuerySetPlayerID(int queryID = -1, int playerID = -1, bool resetQueryData = true);

	// Sets query data.
	bool kbUnitQuerySetPlayerRelation(int queryID = -1, int playerRelation = -1);

	// Sets query data.
	bool kbUnitQuerySetUnitType(int queryID = -1, int unitTypeID = -1);

	// Sets query data.
	bool kbUnitQuerySetActionType(int queryID = -1, int actionTypeID = -1);

	// Sets query data.
	bool kbUnitQuerySetState(int queryID = -1, int state = 255);

	// Sets query data.
	bool kbUnitQuerySetPosition(int queryID = -1, vector v = cOriginVector);

	// Sets query data.
	bool kbUnitQuerySetMaximumDistance(int queryID = -1, float distance = 0);

	// Sets query data.
	bool kbUnitQuerySetIgnoreKnockedOutUnits(int queryID = -1, bool v = true);

	// If parm is true, results are sorted in ascending distance order from the query position.
	bool kbUnitQuerySetAscendingSort(int queryID = -1, bool v = true);

	// Sets query data.
	bool kbUnitQuerySetBaseID(int queryID = -1, int baseID = -1);

	// Sets query data.
	bool kbUnitQuerySetAreaID(int queryID = -1, int areaID = -1);

	// Sets query data.
	bool kbUnitQuerySetAreaGroupID(int queryID = -1, int areaGroupID = -1);

	// Sets query data.
	bool kbUnitQuerySetArmyID(int queryID = -1, int armyID = -1);

	// Sets query data.
	bool kbUnitQuerySetSeeableOnly(int queryID = -1, bool seeableOnly = true);

	// Executes the current query; returns number of results.
	int kbUnitQueryExecute(int queryID = -1);

	// Executes the current query on the previous query's results; returns the new number of results.
	int kbUnitQueryExecuteOnQuery(int currentQueryID = -1, int previousQueryID = -1);

	// Executes the current query on the previous query's results; returns the new number of results.
	int kbUnitQueryExecuteOnQueryByName(int currentQueryID = -1, string previousQueryName = "");

	// gets total aiCost of query's units, weighted for HP if requested.
	float kbUnitQueryGetUnitCost(int queryID = -1, bool considerHealth = false);

	// gets HP of query's units, using current HP if requested.
	float kbUnitQueryGetUnitHitpoints(int queryID = -1, bool considerHealth = false);

	// Returns the player ID for this unit ID.
	int kbUnitGetPlayerID(int unitID = -1);

	// Returns the plan ID for this unit ID.
	int kbUnitGetPlanID(int unitID = -1);

	// Returns the base ID for this unit ID.
	int kbUnitGetBaseID(int unitID = -1);

	// Returns the area ID for this unit ID.
	int kbUnitGetAreaID(int unitID = -1);

	// Returns the army ID for this unit ID.
	int kbUnitGetArmyID(int unitID = -1);

	// Returns the movementType for this unitTypeID.
	int kbUnitGetMovementType(int unitTypeID = -1);

	// Returns the current hitpoints for this unit ID.
	float kbUnitGetCurrentHitpoints(int unitID = -1);

	// Returns the maximum hitpoints for this unit ID.
	float kbUnitGetMaximumHitpoints(int unitID = -1);

	// Returns the health for this unit ID.
	float kbUnitGetHealth(int unitID = -1);

	// Returns the current AI cost (worth) for this unit ID.
	float kbUnitGetCurrentAICost(int unitID = -1);

	// Returns the maximum AI cost (worth) for this unit ID.
	float kbUnitGetMaximumAICost(int unitID = -1);

	// Returns the position for this unit ID.
	vector kbUnitGetPosition(vector result, int unitID = -1);

	// Returns true if the unit is of the unitTypeID.
	bool kbUnitIsType(int unitID = -1, int unitTypeID = -1);

	// Returns the actionTypeID of the unit.
	int kbUnitGetActionType(int unitID = -1);

	// Returns the target unit ID of the given unit.
	int kbUnitGetTargetUnitID(int unitID = -1);

	// Returns the number of units currently working on the given unit.
	int kbUnitGetNumberWorkers(int unitID = -1);

	// Returns the index-th worker unit ID.
	int kbUnitGetWorkerID(int unitID = -1, int index = -1);

	// Returns the number of the unit type you are allowed to have (ONLY WORKS ON BASE UNIT TYPES); returns -1 if there is no limit.
	int kbGetBuildLimit(int player = -1, int unitTypeID = -1);

	// Returns amount of pop cap addition provided by the given unit type (ONLY WORKS ON BASE UNIT TYPES).
	int kbGetPopCapAddition(int player = -1, int unitTypeID = -1);

	// Returns the number of pop slots this unit takes (ONLY WORKS ON BASE UNIT TYPES).
	int kbGetPopSlots(int player = -1, int unitTypeID = -1);

	// Returns the number of pop slots currently occupied by this unit type.
	int kbGetPopulationSlotsByUnitTypeID(int playerID = -1, int unitTypeID = -1);

	// Returns the number of pop slots currently occupied by the results in the given query.
	int kbGetPopulationSlotsByQueryID(int queryID = -1);

	// Returns a quick unit count of units for a player.
	int kbUnitCount(int player = 0, int unitTypeID = -1, int stateID = 2);

	// Returns a quick unit count of player2's units from player1's perspective.
	void kbUnitCountConsole(int playerID1 = -1, int playerID2 = -1, string unitType = "", string state = "");

	// Returns the center vector of the map.
	vector kbGetMapCenter(vector result);

	// Returns the X size of the map.
	float kbGetMapXSize();

	// Returns the Z size of the map.
	float kbGetMapZSize();

	// Creates areas and area groups. DO THIS BEFORE ANYTHING ELSE IN YOUR SCRIPT.
	void kbAreaCalculate(float a = -1, bool b = true, vector c = cInvalidVector, vector d = cInvalidVector, vector e = cInvalidVector, vector f = cInvalidVector);

	// Returns the number of areas.
	int kbAreaGetNumber();

	// Returns the ID of the given area.
	int kbAreaGetIDByPosition(vector position = cOriginVector);

	// Returns the ID of the given area group.
	int kbAreaGroupGetIDByPosition(vector position = cOriginVector);

	// Returns the center of the given areaGroup.
	vector kbAreaGroupGetCenter(vector result, int groupID = -1);

	// Returns the center of the given area.
	vector kbAreaGetCenter(vector result, int areaID = -1);

	// Returns the number of tiles in the given area.
	int kbAreaGetNumberTiles(int areaID = -1);

	// Returns the number of black tiles in the given area.
	int kbAreaGetNumberBlackTiles(int areaID = -1);

	// Returns the number of visible tiles in the given area.
	int kbAreaGetNumberVisibleTiles(int areaID = -1);

	// Returns the number of fog tiles in the given area.
	int kbAreaGetNumberFogTiles(int areaID = -1);

	// Returns the gametime of the last visibility change for the given area.
	int kbAreaGetVisibilityChangeTime(int areaID = -1);

	// Returns the number of units in the given area.
	int kbAreaGetNumberUnits(int areaID = -1);

	// Returns the Unit ID of the index-th unit in the given area.
	int kbAreaGetUnitID(int areaID = -1, int index = -1);

	// Returns the number of border areas for the given area.
	int kbAreaGetNumberBorderAreas(int areaID = -1);

	// Returns the Area ID of the index-th border area in the given area.
	int kbAreaGetBorderAreaID(int areaID = -1, int index = -1);

	// Returns the Type of area.
	int kbAreaGetType(int areaID = -1);

	// returns an area's VP site ID (-1 if an area doesn't have a VP site).
	int kbAreaGetVPSiteID(int areaID = -1);

	// returns ID for an array containing VP site IDs that match the specified parameters.
	int kbVPSiteQuery(int scoreType = -1, int playerRelationOrID = -1, int siteState = -1);

	// blogs out info about all VP sites.
	void kbDumpVPSiteInfo();

	// returns the specified VP site's type (e.g., native, trade, etc).
	int kbVPSiteGetType(int siteID = -1);

	// returns the specified VP site's world location.
	vector kbVPSiteGetLocation(vector result, int siteID = -1);

	// returns the specified VP site's owning player.
	int kbVPSiteGetOwnerPlayerID(int siteID = -1);

	// returns the specified VP site's state.
	int kbVPSiteGetState(int siteID = -1);

	// returns the protounit ID for the VP generator that corresponds to this type of VP site.
	int kbGetVPGeneratorByScoreType(int siteType = -1);

	// Returns the Area ID of the closest area, of the given types, to given postion.
	int kbAreaGetClosetArea(vector position = cInvalidVector, int areaType = -1, int areaType1 = -1, float minDistance = -1);

	// Creates a path with the given name.
	int kbPathCreate(string name = "");

	// Destroys the given path.
	bool kbPathDestroy(int pathID = -1);

	// Returns the number of paths.
	int kbPathGetNumber();

	// Returns the index-th path ID.
	int kbPathGetIDByIndex(int index = -1);

	// Returns the name of the given path.
	string kbPathGetName(int pathID = -1);

	// Returns the length of the given path.
	float kbPathGetLength(int pathID = -1);

	// Returns the number of waypoints in the given path.
	int kbPathGetNumberWaypoints(int pathID = -1);

	// Adds the waypoint to the given path.
	bool kbPathAddWaypoint(int pathID = -1, vector waypoint = cOriginVector);

	// Returns the appropriate waypoint from the given path.
	vector kbPathGetWaypoint(vector result, int pathID = -1, int waypointNumber = -1);

	// Returns true if the given unit type can path from pointA to pointB.
	bool kbCanSimPath(vector pointA = cOriginVector, vector pointB = cOriginVector, int protoUnitTypeID = -1, float range = 0);

	// Returns true if the given unit type can path from pointA to pointB.
	bool kbCanPath2(vector pointA = cOriginVector, vector pointB = cOriginVector, int protoUnitTypeID = -1, float range = 0);

	// Returns the Route ID if successful.
	int kbCreateAttackRoute(string name = "BAD", int startAreaID = -1, int goalAreaID = -1, int numInitialRoutes = 3);

	// Returns the Route ID if successful.
	int kbCreateAttackRouteWithPath(string name = "BAD", vector startPt = cOriginVector, vector endPt = cOriginVector);

	// Returns true if the route was deleted.
	bool kbDestroyAttackRoute(int routeID = -1);

	// add a new sector to path to.
	bool kbAddAttackRouteSector(int sector = -1);

	// ignore this area when finding the route.
	bool kbAddAttackRouteIgnoreID(int ignoreAreaID = -1);

	// ignore this areatype when finding the route.
	bool kbAddAttackRouteIgnoreType(int ignoreAreaTypeID = -1);

	// Rreturns true if path was added to attack route.
	bool kbAttackRouteAddPath(int attackRouteID = -1, int pathID = -1);

	// find all the paths to the sector specified.
	bool kbMakeAttackRoutes();

	// Returns num paths from start to goal area.
	int kbGetNumAttackRoutes(int startAreaID = -1, int goalAreaID = -1);

	// Returns the id of the routes from area1 to area2.
	int kbGetAttackRouteID(int startAreaID = -1, int goalAreaID = -1);

	// Creates an escrow.
	int kbEscrowCreate(string name = "", int resourceID = -1, float percentage = 0, int parentID = -1);

	// Destroys an escrow.
	bool kbEscrowDestroy(int escrowID = -1, bool promoteChildren = false);

	// Returns the ID of the named escrow.
	int kbEscrowGetID(string name = "");

	// Returns the percentage of the escrow.
	float kbEscrowGetPercentage(int escrowID = -1, int resourceID = -1);

	// Sets the percentage of the escrow.
	bool kbEscrowSetPercentage(int escrowID = -1, int resourceID = -1, float percentage = 0);

	// Sets the cap of the escrow.
	bool kbEscrowSetCap(int escrowID = -1, int resourceID = -1, float cap = 0);

	// Returns the amount of credits in the given escrow for the given resource.
	float kbEscrowGetAmount(int escrowID = -1, int resourceID = -1);

	// Removes all credits (and puts them into the root escrow) of the given resource type from the given escrow.
	bool kbEscrowFlush(int escrowID = -1, int resourceID = -1, bool flushChildren = false);

	// Reallocates the current resource stockpile into the escrows.
	bool kbEscrowAllocateCurrentResources();

	// Creates a building placement; returns the ID.
	int kbBuildingPlacementCreate(string name = "");

	// Destroys the given building placement.
	bool kbBuildingPlacementDestroy(int id = -1);

	// Resets the current building placement.
	bool kbBuildingPlacementResetResults();

	// Selects the given building placement.
	bool kbBuildingPlacementSelect(int id = -1);

	// Sets event handler function for the current BP and event.
	bool kbBuildingPlacementSetEventHandler(int eventType = -1, string handlerName = "");

	// Sets the building type for the current building placement.
	bool kbBuildingPlacementSetBuildingType(int buildingTypeID = -1);

	// Sets the base ID and location preference for the current building placement.
	bool kbBuildingPlacementSetBaseID(int baseID = -1, int locationPref = -1);

	// Adds the Area ID to the current BP (with the given number of border area layers), addCenterInfluence - adds a positional influence from the area center.
	bool kbBuildingPlacementAddAreaID(int areaID = -1, int numberBorderAreaLayers = 0, bool addCenterInfluence = true);

	// Adds the AreaGroup ID to the current BP.
	bool kbBuildingPlacementAddAreaGroupID(int areaGroupID = -1);

	// Sets up center position-based BP.
	bool kbBuildingPlacementSetCenterPosition(vector position = cInvalidVector, float distance = -1, float obstructionRadius = 6);

	// Adds the unit influence for the current building placement.
	bool kbBuildingPlacementAddUnitInfluence(int typeID = -1, float value = -1, float distance = -1, int kbResourceID = -1);

	// Adds the position influence for the current building placement.
	bool kbBuildingPlacementAddPositionInfluence(vector position = cInvalidVector, float value = -1, float distance = -1);

	// Sets the minimum acceptable value for evaluated spots in the BP.
	bool kbBuildingPlacementSetMinimumValue(float minimumValue = -1);

	// Starts the placement of current building.
	bool kbBuildingPlacementStart();

	// Returns the vector result position for given BP ID.
	vector kbBuildingPlacementGetResultPosition(vector result, int bpID = -1);

	// Returns the result value for given BP ID.
	float kbBuildingPlacementGetResultValue(int bpID = -1);

	// Creates a target selector; returns the ID.
	int kbTargetSelectorCreate(string name = "");

	// Destroys the given target selector.
	bool kbTargetSelectorDestroy(int id = -1);

	// Resets the current target selector.
	bool kbTargetSelectorResetResults();

	// Selects the given target selector.
	bool kbTargetSelectorSelect(int id = -1);

	// Add the UAIT for the given BASE unit type as a filter.
	bool kbTargetSelectorAddUnitType(int protoUnitTypeID = -1);

	// Sets the list of potential targets to the results in the given query.
	bool kbTargetSelectorAddQueryResults(int queryID = -1);

	// Returns the number of results in the given target selector.
	int kbTargetSelectorGetNumberResults();

	// Returns the result value for given index of the current target selector.
	int kbTargetSelectorGetResultValue(int index = -1);

	// Starts the current target selector.
	bool kbTargetSelectorStart();

	// Returns true if amount of resource is within distance of a dropsite.
	bool kbSetupForResource(int baseID = -1, int resourceID = -1, float distance = 15, float amount = 500);

	// Returns the current HomeCity Level of the given player.
	int kbGetHCLevel(int playerID = -1);

	// Returns the current amount XP the given player has.
	int kbResourceGetXP(int playerID = -1);

	// Returns the current amount of the given resource.
	float kbResourceGet(int resourceID = -1);

	// Returns the maximum amount of the given resource you can have.
	float kbMaximumResourceGet(int resourceID = -1);

	// Returns the total amount of the given resource gathered to this point in the game.
	float kbTotalResourceGet(int resourceID = -1);

	// Returns the number of valid KB resources for the given plan/base.
	int kbGetNumberValidResourcesByPlan(int planID = -1, int baseID = -1);

	// Returns the number of valid KB resources for the resource types.
	int kbGetNumberValidResources(int baseID = -1, int resourceTypeID = -1, int resourceSubTypeID = -1, float distance = -1);

	// Returns the resource amount of valid KB resources for the resource types.
	float kbGetAmountValidResources(int baseID = -1, int resourceTypeID = -1, int resourceSubTypeID = -1, float distance = -1);

	// Returns the resource income over the last X seconds.
	float kbGetResourceIncome(int resourceID = -1, float seconds = 60, bool relative = false);

	// Returns true if the protoUnit is currently available.
	bool kbProtoUnitAvailable(int protoUnitID = -1);

	// Returns the ID of the protounit.
	int kbGetProtoUnitID(string name = "");

	// Returns the unit's protounit ID.
	int kbUnitGetProtoUnitID(int unitID = -1);

	// Returns true if the player can afford the proto unit.
	bool kbCanAffordUnit(int protoUnitTypeID = -1, int escrowID = -1);

	// returns the cost of the protounit for the given resource.
	float kbUnitCostPerResource(int protoUnitID = -1, int resourceID = -1);

	// Returns true if the player can afford the tech.
	bool kbCanAffordTech(int techID = -1, int escrowID = -1);

	// returns the cost of the tech for the given resource.
	float kbTechCostPerResource(int techID = -1, int resourceID = -1);

	// Returns true if the protounit is of the unitTypeID.
	bool kbProtoUnitIsType(int playerID = -1, int protoUnitID = -1, int unitTypeID = -1);

	// Returns the current tech status for the current player of the requested tech.
	int kbTechGetStatus(int techID = -1);

	// Returns the percent complete for the the requested tech of the current player.
	float kbGetTechPercentComplete(int techID = -1);

	// Returns the combat efficiency of the comparison (in terms of playerID1's units).
	float kbGetCombatEfficiency(int playerID1 = -1, int unitTypeID1 = -1, int playerID2 = -1, int unitTypeID2 = -1);

	// Returns the AI cost weight for the given resource.
	float kbGetAICostWeight(int resourceID = -1);

	// Sets the weight this resource type is given during AI cost calculuations.
	bool kbSetAICostWeight(int resourceID = -1, float weight = -1);

	// Returns the AI cost for the given protoUnit type ID.
	float kbGetProtoUnitAICost(int protoUnitTypeID = -1);

	// Returns the AI cost for the given tech ID.
	float kbGetTechAICost(int techID = -1);

	// Returns the player's resigned status.
	bool kbIsPlayerResigned(int playerID = -1);

	// Returns the player's lost status.
	bool kbHasPlayerLost(int playerID = -1);

	// Returns the player's team number.
	int kbGetPlayerTeam(int playerID = -1);

	// Returns the player's name.
	string kbGetPlayerName(int playerID = -1);

	// Returns true if the given player is an enemy.
	bool kbIsPlayerEnemy(int playerID = -1);

	// Returns true if the given player is a neutral player.
	bool kbIsPlayerNeutral(int playerID = -1);

	// Returns true if the given player is an ally.
	bool kbIsPlayerAlly(int playerID = -1);

	// Returns true if the given player is a mutual ally.
	bool kbIsPlayerMutualAlly(int playerID = -1);

	// Returns the number of mutual allies.
	int kbGetNumberMutualAllies();

	// Returns true if the given player is a valid player (i.e. it exists in the game).
	bool kbIsPlayerValid(int playerID = -1);

	// Returns true if the given player is a a human player.
	bool kbIsPlayerHuman(int playerID = -1);

	// Returns the player's handicap multiplier (ie., 1.0 = no handicap).
	float kbGetPlayerHandicap(int playerID = -1);

	// Sets the indicated player's handicap multiplier (ie., 1.0 = no handicap).
	void kbSetPlayerHandicap(int playerID = -1, float handicap = 1);

	// Returns whether the game is over or not.
	bool kbIsGameOver();

	// Returns the location of the main town.
	vector kbGetTownLocation(vector result);

	// Returns the area ID of the main town.
	int kbGetTownAreaID();

	// Sets the location of the main town.
	bool kbSetTownLocation(vector location = cInvalidVector);

	// Returns the auto base creation value.
	bool kbGetAutoBaseCreate();

	// Sets the auto base creation value.
	void kbSetAutoBaseCreate(bool v = true);

	// Returns the auto base creation distance.
	float kbGetAutoBaseCreateDistance();

	// Sets the auto base creation distance.
	void kbSetAutoBaseCreateDistance(float v = 50);

	// Returns the auto base detection value.
	bool kbGetAutoBaseDetect();

	// Sets the auto base detection value.
	void kbSetAutoBaseDetect(bool v = true);

	// Returns the auto base creation distance.
	float kbGetAutoBaseDetectDistance();

	// Sets the auto base creation distance.
	void kbSetAutoBaseDetectDistance(float v = 50);

	// gets the nearest base of player relation from the location.
	int kbFindClosestBase(int playerRelation = -1, vector location = cInvalidVector);

	// Returns the ID of the next base that will be created.
	int kbBaseGetNextID();

	// Returns the number of bases for the given player.
	int kbBaseGetNumber(int playerID = -1);

	// Returns the BaseID for the given base.
	int kbBaseGetIDByIndex(int playerID = -1, int index = -1);

	// Creates a base.
	int kbBaseCreate(int playerID = -1, string name = "NoBaseName", vector position = cInvalidVector, float distance = -1);

	// Finds/Creates a resource base.
	int kbBaseFindCreateResourceBase(int resourceType = -1, int resourceSubType = -1, int parentBaseID = -1);

	// Finds/Creates a 'forward' military base against the given enemy base.
	int kbBaseFindForwardMilitaryBase(int a = -1, int b = -1, int c = -1);

	// Destroys the given base.
	bool kbBaseDestroy(int playerID = -1, int baseID = -1);

	// Destroys all of the bases for the given player.
	void kbBaseDestroyAll(int playerID = -1);

	// Gets the location of the base.
	vector kbBaseGetLocation(vector result, int playerID = -1, int baseID = -1);

	// Gets the last known damage location of the base.
	vector kbBaseGetLastKnownDamageLocation(vector result, int a = -1, int b = -1);

	// Returns the player ID of the specified base's owner.
	int kbBaseGetOwner(int baseID = -1);

	// Sets the front (and back) of the base.
	bool kbBaseSetFrontVector(int playerID = -1, int baseID = -1, vector frontVector = cInvalidVector);

	// Gets the front vector of the base.
	vector kbBaseGetFrontVector(vector result, int playerID = -1, int baseID = -1);

	// Gets the back vector of the base.
	vector kbBaseGetBackVector(vector result, int playerID = -1, int baseID = -1);

	// Returns the number of continuous seconds the base has been under attack.
	int kbBaseGetTimeUnderAttack(int playerID = -1, int baseID = -1);

	// Gets the under attack flag of the base.
	bool kbBaseGetUnderAttack(int playerID = -1, int baseID = -1);

	// Sets the active flag of the base.
	bool kbBaseSetActive(int playerID = -1, int baseID = -1, bool active = true);

	// Gets the active flag of the base.
	bool kbBaseGetActive(int playerID = -1, int baseID = -1);

	// Gets the main base ID for the player.
	int kbBaseGetMainID(int playerID = -1);

	// Sets the main flag of the base.
	bool kbBaseSetMain(int playerID = -1, int baseID = -1, bool main = true);

	// Gets the main flag of the base.
	bool kbBaseGetMain(int playerID = -1, int baseID = -1);

	// Sets the forward flag of the base.
	bool kbBaseSetForward(int playerID = -1, int baseID = -1, bool forward = true);

	// Gets the forward flag of the base.
	bool kbBaseGetForward(int playerID = -1, int baseID = -1);

	// Sets the settlement flag of the base.
	bool kbBaseSetSettlement(int playerID = -1, int baseID = -1, bool settlement = true);

	// Gets the settlement flag of the base.
	bool kbBaseGetSettlement(int playerID = -1, int baseID = -1);

	// Sets the military flag of the base.
	bool kbBaseSetMilitary(int playerID = -1, int baseID = -1, bool military = true);

	// Gets the military flag of the base.
	bool kbBaseGetMilitary(int playerID = -1, int baseID = -1);

	// Gets the military gather point of the base.
	vector kbBaseGetMilitaryGatherPoint(vector result, int playerID = -1, int baseID = -1);

	// Sets the military gather point of the base.
	bool kbBaseSetMilitaryGatherPoint(int playerID = -1, int baseID = -1, vector gatherPoint = cInvalidVector);

	// Sets the economy flag of the base.
	bool kbBaseSetEconomy(int playerID = -1, int baseID = -1, bool Economy = true);

	// Gets the economy flag of the base.
	bool kbBaseGetEconomy(int playerID = -1, int baseID = -1);

	// Gets the maximum resource distance of the base.
	float kbBaseGetMaximumResourceDistance(int playerID = -1, int baseID = -1);

	// Sets the maximum resource distance of the base.
	void kbBaseSetMaximumResourceDistance(int playerID = -1, int baseID = -1, float distance = 100);

	// Adds the given unit to the base.
	bool kbBaseAddUnit(int playerID = -1, int baseID = -1, int unitID = -1);

	// Removes the given unit to the base.
	bool kbBaseRemoveUnit(int playerID = -1, int baseID = -1, int unitID = -1);

	// Returns the number of units that match the criteria.
	int kbBaseGetNumberUnits(int playerID = -1, int baseID = -1, int relation = -1, int unitTypeID = -1);

	// Returns true if the unit is currently visible to the player.
	bool kbUnitVisible(int unitID = -1);

	// Returns true if the location is currently visible to the player.
	bool kbLocationVisible(vector location = cInvalidVector);

	// Returns the position of the cinematic block.
	vector kbGetBlockPosition(vector result, string blockName = "");

	// Returns the UnitID of the cinematic block.
	int kbGetBlockID(string blockName = "");

	// Returns a random, valid PUID that's of the given type.
	int kbGetRandomEnabledPUID(int unitTypeID = -1, int escrowID = -1);

	// Creates a unit pick.
	int kbUnitPickCreate(string name = "NoUPName");

	// Destroys the given unit pick.
	bool kbUnitPickDestroy(int upID = -1);

	// Resets all of the unit pick data.
	bool kbUnitPickResetAll(int upID = -1);

	// Resets the unit pick results.
	bool kbUnitPickResetResults(int upID = -1);

	// Gets the unit pick preference weight.
	float kbUnitPickGetPreferenceWeight(int upID = -1);

	// Sets the unit pick preference weight.
	bool kbUnitPickSetPreferenceWeight(int upID = -1, float v = 0.5);

	// Sets the unit pick enemy player ID.
	bool kbUnitPickSetEnemyPlayerID(int upID = -1, int playerID = -1);

	// Sets the unit pick combat efficiency weight.
	bool kbUnitPickSetCombatEfficiencyWeight(int upID = -1, float a = 0.5);

	// Resets the enemy unit typeIDs for the unit pick combat efficiency calculation.
	bool kbUnitPickResetCombatEfficiencyTypes(int upID = -1);

	// Adds an enemy unit typeID to the unit pick combat efficiency calculation.
	bool kbUnitPickAddCombatEfficiencyType(int upID = -1, int typeID = -1, float weight = 1);

	// Sets the unit pick cost weight.
	bool kbUnitPickSetCostWeight(int upID = -1, float a = 0.5);

	// Sets the unit pick movement type.
	bool kbUnitPickSetMovementType(int upID = -1, int movementType = 1);

	// Sets the unit pick desired number unit types.
	bool kbUnitPickSetDesiredNumberUnitTypes(int upID = -1, int number = 1, int numberBuildings = 1, bool degradeNumberBuildings = false);

	// Gets the unit pick desired number unit types.
	int kbUnitPickGetDesiredNumberUnitTypes(int upID = -1);

	// Sets the unit pick desired number buildings for the index-th unit type.
	bool kbUnitPickSetDesiredNumberBuildings(int upID = -1, int index = 1, int numberBuildings = 1);

	// gets the unit pick desired number buildings for the index-th unit type.
	int kbUnitPickGetDesiredNumberBuildings(int upID = -1, int index = 0);

	// Sets the unit pick desired number unit types.
	bool kbUnitPickSetMinimumNumberUnits(int upID = -1, int number = 1);

	// Gets the unit pick minimum number units.
	int kbUnitPickGetMinimumNumberUnits(int upID = -1);

	// Sets the unit pick desired number unit types.
	bool kbUnitPickSetMaximumNumberUnits(int upID = -1, int number = 1);

	// Gets the unit pick maximum number units.
	int kbUnitPickGetMaximumNumberUnits(int upID = -1);

	// Sets the unit pick desired min pop.
	bool kbUnitPickSetMinimumPop(int upID = -1, int number = 1);

	// Gets the unit pick minimum pop.
	int kbUnitPickGetMinimumPop(int upID = -1);

	// Sets the unit pick desired max pop.
	bool kbUnitPickSetMaximumPop(int upID = -1, int number = 1);

	// Gets the unit pick maximum pop.
	int kbUnitPickGetMaximumPop(int upID = -1);

	// Sets the unit pick attack unit type.
	bool kbUnitPickSetAttackUnitType(int upID = -1, int type = 1);

	// Gets the unit pick attack unit type.
	int kbUnitPickGetAttackUnitType(int upID = -1);

	// Sets the unit pick attack unit type.
	bool kbUnitPickSetGoalCombatEfficiencyType(int upID = -1, int type = 1);

	// Gets the unit pick attack unit type.
	int kbUnitPickGetGoalCombatEfficiencyType(int upID = -1);

	// Sets the preferenceFactor for that unit type.
	bool kbUnitPickSetPreferenceFactor(int upID = -1, int unitTypeID = -1, float preferenceFactor = 0);

	// Adjusts the preferenceFactor for that unit type (uses 50.0 as the base if the UP doesn't exist yet).
	bool kbUnitPickAdjustPreferenceFactor(int upID = -1, int unitTypeID = -1, float baseFactorAdjustment = 0);

	// Runs the unit pick.
	int kbUnitPickRun(int upID = -1);

	// Returns the number of unit pick results.
	int kbUnitPickGetNumberResults(int upID = -1);

	// Returns the index-th ProtoUnitID.
	int kbUnitPickGetResult(int upID = -1, int index = -1);

	// returns the visible area group that matches the given criteria.
	int kbFindAreaGroup(int groupType = -1, float surfaceAreaRatio = 1, int compareAreaID = -1);

	// returns the visible area group that matches the given criteria.
	int kbFindAreaGroupByLocation(int groupType = -1, float relativeX = 0.5, float relativeZ = 0.5);

	// returns the id of the best building to repair.
	int kbFindBestBuildingToRepair(vector position = cInvalidVector, float distance = 50, float healthRatio = 1, int repairUnderAttackUnitTypeID = -1);

	// set the explicit position that every forward base will use.
	void kbSetForwardBasePosition(vector position = cInvalidVector);

	// sets the TargetSelector Factor value.
	void kbSetTargetSelectorFactor(int type = -1, float val = 50);

	// gets the TargetSelector Factor value.
	float kbGetTargetSelectorFactor(int type = -1);

	// Returns the name of the tech ID.
	string kbGetTechName(int techID = -1);

	// Returns the name of the protounit ID.
	string kbGetProtoUnitName(int protoUnitTypeID = -1);

	// Returns the base type ID of the unit.
	int kbGetUnitBaseTypeID(int unitID = -1);

	// Returns the name of the unit type.
	string kbGetUnitTypeName(int unitTypeID = -1);

	// Creates a unit progression of the given name.
	int kbCreateUnitProgression(string unitName = "", string name = "");

	// Creates a tech progression of the given name.
	int kbCreateTechProgression(string techName = "", string name = "");

	// gets cheapest researchable unit upgrade, optionally for specified unit/unit line.
	int kbTechTreeGetCheapestUnitUpgrade(int unitTypeID = -1);

	// gets cheapest researchable econ upgrade, optionally for specified resource unit type.
	int kbTechTreeGetCheapestEconUpgrade(int resourceUnitTypeID = -1);

	// Dumps the current state of the KBTT.
	void kbTechTreeDump();

	// Returns the total number of steps to complete the progression.
	int kbProgressionGetTotalNodes(int progressionID = -1);

	// Returns the total cost of the given resource for this progressionID. A resourceID of -1 will return the total Cost.
	float kbProgessionGetTotalResourceCost(int progressionID = -1, int resourceID = -1);

	// Returns the type of node at the given index, either Unit type or Tech type.
	int kbProgressionGetNodeType(int progressionID = -1, int nodeIndex = -1);

	// Returns the data at nodeIndex, either UnitID or TechID, depending on the type.
	int kbProgressionGetNodeData(int progressionID = -1, int nodeIndex = -1);

	// adds a rule to the runtime to be activated on the next update.
	void trDelayedRuleActivation(string rulename = "None");

	// Returns the current gametime in Seconds.
	int trTime();

	// Returns the current gametime in Milliseconds.
	int trTimeMS();

	// Clears the units in the trigger selection system.
	void trUnitSelectClear();

	// 'Selects' the unit in the trigger selection system.
	void trUnitSelect(string unitScenarioName = "None");

	// 'Selects' the unit in the trigger selection system.
	void trUnitSelectByID(int unitID = -1);

	// Returns true if the specified player is built on the specified socket.
	bool trPlayerControlsSocket(int playerID = -1, string objectScenarioName = "None");

	// Returns true if the current player is looking at (visiting) the home city of the player specified by the player ID passed in.
	bool trIsPlayerVisitingHC(int targetHCPlayerID = -1);

	// Returns true if the current player is selecting the building in their HC which has the specified name.
	bool trIsPlayerSelectingHCBuilding(string hcBuildingName = "None");

	// Returns true when the player has sent a shipment from the home city.
	bool trHasPlayerSentHCShipment(int targetHCPlayerID = -1);

	// Returns true when the player sends a shipment from home city.
	bool trIsPlayerSendingHCShipment(int targetHCPlayerID = -1);

	// Returns true if the object is currently being worked.
	bool trObjectGettingWorked(string objectScenarioName = "None");

	// Moves the selected unit(s) to the given position.
	bool trUnitMoveToPoint(float x = -1, float y = -1, float z = -1, int eventID = -1, bool bAttackMove = false, bool bUnitRun = false, float runSpeedMultiplier = 1);

	// Moves the selected unit(s) to the spot occupied by the given unit.
	bool trUnitMoveToUnit(string unitScenarioName = "None", int eventID = -1, bool bAttackMove = false, bool bUnitRun = false, float runSpeedMultiplier = 1);

	// Finds the specified revealer and sets it to active or inactive.
	void trSetRevealerActiveState(string revealerName = "None", bool active = true);

	// Creates a revealer with the given attributes.
	void trCreateRevealer(int playerID = -1, string revealerName = "None", vector position = cOriginVector, float revealerLOS = 0, bool blackmapOnly = false);

	// Moves all matching units near the selected unit(s) to the given position.
	bool trUnitMoveFromArea(float x = -1, float y = -1, float z = -1, int eventID = -1, bool bAttackMove = false, int player = 1, string unitType = "Unit", float radius = 10);

	// Selects units and makes the build a unit at specified location
	bool trUnitBuildUnit(string protoUnitName = "None", vector BVector = cOriginVector);

	// Tasks the selected unit(s) to perform work on the given unit.
	bool trUnitDoWorkOnUnit(string unitScenarioName = "None", int eventID = -1);

	void trShowDamage(string a = "None", string b = "None", string c = "None", string d = "None");

	// Tasks the selected unit(s) to garrision into another unit.
	bool trUnitGarrison(string unitScenarioName = "None", int eventID = -1);

	// Sets the age of the specified player.
	void trPlayerSetAge(int playerID = -1, int age = -1, bool displayEffect = true);

	// Sets whether the player has access to the HC.
	void trPlayerSetHCAccess(int playerID = -1, bool hcAccess = true);

	// Sets the view to the HC if the player specified is the current player.
	void trShowHCView(int playerID = -1);

	// Sets the view to the world if the player specified is the current player.
	void trShowWorldView(int playerID = -1);

	// Instantly garrisons units inside another unit without considering distance.
	bool trImmediateUnitGarrison(string unitScenarioName = "None");

	// Returns the shortest distance between the trRT units and the point.
	float trUnitDistanceToPoint(float x = -1, float y = -1, float z = -1);

	// Returns the shortest distance between the trRT units and the given unit.
	float trUnitDistanceToUnit(string unitScenarioName = "None");

	// Returns the shortest distance between the trRT units and the given unit.
	float trUnitDistanceToUnitID(int unitID = -1);

	float trCountUnitsInArea(string centerUnit = "None", int matchPlayer = 1, string matchType = "Unit", float range = 10);

	// Removes the current control action so the next thing can take effect immediately.  (For IGC)
	void trUnitCinematicRemoveControlAction();

	// Sets the cinematic animation version for the selected unit(s).
	bool trUnitSetAnimation(string AnimName = "Idle", int versionIndex = -1, bool loop = false, int eventID = -1, bool destroyOnNextControlAction = false);

	// Returns true if all selected units are alive.
	bool trUnitAlive();

	// Returns true if all selected units are dead.
	bool trUnitDead();

	// removes or kills the selected unit(s).
	bool trUnitDelete(bool remove = true);

	// destroys the selected unit(s).
	void trUnitDestroy();

	// creates a new unit.
	bool trUnitCreate(string protoName = "None", string scenarioName = "None", float x = -1, float y = -1, float z = -1, int heading = -1, int playerID = -1);

	// returns the units heading.
	int trUnitGetHeading(string scenarioName = "None");

	// sets the units heading.
	bool trUnitSetHeading(int degrees = -1);

	// set the hitpoints for all selected units.
	int trUnitSetHP(float hitpoints = -1);

	// returns true if the player can see the selected unit, and it is on screen.
	bool trUnitVisToPlayer();

	// returns true if the player can see the selected unit, otherwise returns false.
	bool trUnitHasLOS(int playerID = -1);

	// converts the selected units to player.
	void trUnitConvert(int playerID = -1);

	// returns the percent complete as 0 to 100
	int trUnitPercentComplete();

	// returns the percent damaged as 0 to 100
	int trUnitPercentDamaged();

	// moves units from current position to position specified
	void trUnitTeleport(float a = -1, float b = -1, float c = -1);

	// does something to highlight the units selected.
	void trUnitHighlight(float seconds = 2, bool a = false);

	// changes the proto unit for a given set of units.
	void trUnitChangeProtoUnit(string a = "None");

	// returns the number of units contained.
	int trUnitGetContained();

	// returns true if this unit is contained by the specified protounit.
	bool trUnitGetIsContained(string protounit = "default");

	// ejects all contained units.
	int trUnitEjectContained();

	// returns if the specified unit is selected.
	bool trUnitIsSelected();

	// returns if the specified unit is selected.
	bool trUnitTypeIsSelected(string a = "None");

	// determines if the selected units are owned by the player specified.
	bool trUnitIsOwnedBy(int playerID = -1);

	// set the stance for the given set of units.
	void trUnitSetStance(string a = "None");

	// puts the camera in the specified location.
	void trCameraCut(vector pos = cOriginVector, vector dir = cOriginVector, vector up = cOriginVector, vector right = cOriginVector);

	// Clears the waypoints in the trigger selection system.
	void trWaypointClear();

	// Adds the waypoint into the trigger selection system.
	void trWaypointAddPoint(vector a = cOriginVector);

	// Adds the unit's position as a waypoint in the trigger selection system.
	void trWaypointAddUnit(string unitScenarioName = "None");

	// returns the current player.
	int trCurrentPlayer();

	// sets the current player as active or inactive.
	void trSetCurrentPlayerStatus(bool active = true);

	// sets the player controls on or off.
	void trSetUserControls(bool active = true);

	// returns the number of units for the player.
	int trPlayerUnitCount(int playerID = -1);

	// returns the number of buildings for the player.
	int trPlayerBuildingCount(int playerID = -1);

	// returns the number of units and buildings for the player.
	int trPlayerUnitAndBuildingCount(int playerID = -1);

	// returns the number of units for the player.
	int trPlayerUnitCountSpecific(int playerID = -1, string protoName = "Village Idiot");

	// tributes resources to a player.
	int trPlayerTribute(int from = -1, string resource = "food", int amount = -1, int to = -1);

	// Toggles whether the player's TC can spawn units.
	void trPlayerToggleAllowTCSpawning(int playerID = -1, bool allowSpawning = true);

	// Toggles whether the player can spawn new covered wagons.
	void trPlayerToggleAllowNewCWSpawning(int playerID = -1, bool allowSpawning = true);

	// returns the number of resources for the player.
	int trPlayerResourceCount(int playerID = -1, string resource = "food");

	// Returns the current (not total) XP for the player.
	int trPlayerCurrentXPCount(int playerID = -1);

	// returns true/false if the player has been defeated.
	bool trPlayerDefeated(int playerID = -1);

	// returns true/false if the player is active.
	bool trPlayerActive(int playerID = -1);

	// call this when a player is defeated on the local machine (meaning that this func must be called synchronously on all machines, it will not pass around a command.)
	void trSetPlayerDefeated(int a = -1);

	// call this when a player has won on the local machine (meaning that this func must be called synchronously on all machines, it will not pass around a command.)
	void trSetPlayerWon(int a = -1);

	// Signal that the game has ended.
	void trEndGame();

	// sets the diplomacy status between players.
	void trPlayerSetDiplomacy(int playerID = -1, int player2ID = -1, string status = "ally");

	// gets the diplomacy status between players.
	string trPlayerGetDiplomacy(int playerID = -1, int player2ID = -1);

	// Adds/removes LOS between players.
	void trPlayerModifyLOS(int a = -1, bool b = true, int c = -1);

	// returns true if building is being built.
	int trPlayerCountBuildingInProgress(int playerID = -1, string protoname = "");

	// Returns true if the proto unit specified is on the cursor and is a building.
	bool trBuildingIsOnCursor(string protoname = "");

	// sets the active player.
	int trPlayerSetActive(int playerID = -1);

	// Completes the specified objective.  Forces a reoccurring objective complete if forceComplete is true.
	void trObjectiveComplete(int objectiveID = -1, bool forceComplete = false, bool playSound = true);

	// Hides the specified objective on the UI.
	void trObjectiveHide(int objectiveID = -1);

	// Shows the specified objective on the UI.
	void trObjectiveShow(int objectiveID = -1);

	// 'Discovers' a previously unknown (to the player) objective.
	void trObjectiveDiscover(int objectiveID = -1, bool playSound = true);

	// returns true if player is at pop cap.
	bool trPlayerAtPopCap(int playerID = -1);

	// returns the player population.
	int trPlayerGetPopulation(int playerID = -1);

	// Sets the unit as speaking or not.
	void trSetCinematicUnitSpeaking(string objectScenarioName = "None", bool speaking = false, int duration = 0);

	// sets a handler function for an event id.
	bool trEventSetHandler(int eventID = -1, string handler = "None");

	// cause an event to occur.
	void trEventFire(int eventID = -1);

	// Sets whether or not units can do their idle processing.
	void trSetUnitIdleProcessing(bool a = true);

	// Sets whether or not units can be drawn obscured or not.
	void trSetObscuredUnits(bool a = true);

	// Turns letter box mode on or off.
	void trLetterBox(bool onOff = true);

	// Plays the sound associated with the filename.
	void trSoundPlayFN(string filename = "None", string a = "1", int b = -1, string c = "", string d = "");

	// Plays the sound associated with the filename.
	void trSoundPlayPaused(string filename = "None", string a = "1", int b = -1, string c = "", string d = "");

	// creates a high performance sound timer and passes the eventID as data.
	void trSoundTimer(int milliseconds = -1, int eventID = -1);

	// Fades out current music over a given duration.
	void trFadeOutMusic(float duration = 1);

	// Plays the next song in the music play list.
	void trPlayNextMusicTrack();

	// Fades out all sounds over a given duration
	void trFadeOutAllSounds(float duration = 1);

	// Blocks all sounds from playing from this point forward
	void trBlockAllSounds(bool excludeDialog = true);

	// Unblocks all sounds that were previously blocked from playing
	void trUnblockAllSounds();

	// blocks all ambient sounds from this point forward
	void trBlockAllAmbientSounds();

	// Unblocks all ambient sounds that were previously blocked from playing
	void trUnBlockAllAmbientSounds();

	// Plays the sound associated with the filename.
	void trSoundPlayDialog(string filename = "None", string event = "1", int ignoreOnAbort = -1, bool subtitle = false, string portrait = "", string a = "");

	// Plays the sound associated with the dialogue.
	void trSoundPlayDialogue(string stringID = "", int eventID = -1, bool ignoreOnAbort = false, int seconds = 1);

	// Plays the music file.
	void trMusicPlay(string filename = "None", string duration = "1", float a = 4);

	// Plays the current music.
	void trMusicPlayCurrent();

	// Stops the current music.
	void trMusicStop();

	// sets the current music set.
	void trMusicSetCurrentMusicSet(int a = 0);

	// Changes the music to mood associated with mood id.
	void trMusicSetMood(int moodID = -1);

	// Loads a camera track.
	void trCamTrackLoad(string filename = "None");

	// plays the current camera track.
	void trCamTrackPlay(float duration = -1, int eventID = -1);

	// displays the message text.
	void trMessageSetText(string text = "None", int timeout = -1);

	// Changes the chat status.
	void trChatSetStatus(bool onOff = true);

	// Changes the chat status.
	void trChatSend(int fromID = 1, string message = "Hello");

	// Changes the chat status for one specific player.
	void trChatSendToPlayer(int fromID = 1, int toID = 1, string message = "Hello");

	// Changes the chat status, but does not append player.
	void trChatSendSpoofed(int fromID = 1, string message = "Hello");

	// Changes the chat status, but does not append player.  Goes to specific player.
	void trChatSendSpoofedToPlayer(int fromID = 1, int toID = 1, string message = "Hello");

	// Writes text to the Age3Log
	void trWriteToLog(string message = "Hello");

	// pause or unpause the game.
	void trGamePause(bool pause = true);

	// start a game using scenario.
	void trGameLoadScenario(string scenario = "default");

	// pop up a dialog allowing choice to load a scenario.
	void trBranchScenario(string a = "default");

	// returns true if tech is active for player.
	bool trTechStatusActive(int playerID = -1, int techID = -1);

	// returns true if tech is being researched for player.
	bool trTechStatusResearching(int playerID = -1, int techID = -1);

	// returns true if tech's status is techStatus.
	bool trTechStatusCheck(int playerID = -1, int techID = -1, int techStatus = -1);

	// sets the tech status for the player.
	void trTechSetStatus(int playerID = -1, int techID = -1, int status = -1);

	// player wins.  If you set directToMenu to true, you go directly to Campaign Menu.
	void trYouWin(bool directToMenu = false);

	// player loses, specifies message.
	void trYouLose(string text = "default");

	// message and sound.
	void trShowWinLose(string text = "default", string soundfile = "1", string a = "default", bool b = true);

	// turn sky rendering on/off and set which sky to use.
	void trRenderSky(bool render = true, string skyName = "defaultSkyBox");

	// controls snow rendering.
	void trRenderSnow(float percent = 0);

	// controls rain rendering.
	void trRenderRain(float percent = 0);

	// turn fog and black map on/off.
	void trSetFogAndBlackmap(bool fog = true, bool blackMap = true);

	// add help string.
	void trStartGameRecord(string a = "Default");

	// add help string.
	void trStopGameRecord();

	// selects the units in the army specified.
	void trArmySelect(string army = "Default");

	// selects the units in the army specified.
	void trArmySelectInt(int playerID = -1, int armyID = -1);

	// creates the units in the army specified.
	bool trArmyDispatch(string parameters = "Default", string a = "Default", int b = -1, float c = 0, float d = 0, float e = 0, int f = -1, bool g = true);

	// fades to the specified lighting set over fadetime.
	void trSetLighting(string setname = "default", float fadetime = 5);

	// start a counter that may or may not fire an event.
	void trCounterAddTime(string name = "default", int start = -1, int stop = -1, string message = "default", int event = -1);

	// start a counter that may or may not fire an event.
	void trCounterAddTimeMs(string name = "default", int start = -1, int stop = -1, string message = "default", int event = -1);

	// start a counter that may or may not fire an event.
	void trCounterAddUnit(string name = "default", int playerid = -1, int count = -1, string protounit = "villager", string message = "default", int event = -1);

	// start a counter that may or may not fire an event.
	void trCounterAddXP(string a = "default", int b = -1, int c = -1, string d = "default", int e = -1);

	// abort a counter.
	void trCounterAbort(string name = "default");

	// returns the abort cinematic status.
	bool trCinematicAbort();

	// aborts the cinematic.
	void trCinematicDoAbort();

	// forces models to be in non cinematic mode
	void trForceNonCinematicModels(bool a = true);

	// scales the formation size of formations in the game.
	void trFormationScale(float scale = 1);

	// Returns the number of nuggets gathered by the specified player.
	int trGetNumberNuggetsGathered(int a = -1);

	// Returns true if the nugget has been collected, the playerID is an optional parameter for querying if the specific player has collected it.
	bool trHasNuggetBeenCollected(string a = "default", int b = -1);

	// flashes a UI element.
	void trUIFlash(string gadget = "default", int name = 0, float flashLimit = 0.4, float colorR = 0.4, float colorG = 0.4);

	// stops the flashing of a UI element.
	void trUIStopFlash(string gadget = "default");

	// flashes a UI element (maybe).
	void trUIFlashTech(int a = -1, bool b = true);

	// flashes a UI element (maybe).
	void trUIFlashTrain(string a = "villager", bool b = true);

	// fade in/out using color specified.
	void trUIFadeToColor(int r = 0, int g = 0, int b = 0, int duration = 1000, int delay = 0, bool inout = true, int a = -1);

	// modify construction rate.
	void trRateConstruction(float rate = 0.5);

	// modify training rate.
	void trRateTrain(float rate = 0.5);

	// modify research rate.
	void trRateResearch(float rate = 0.5);

	// restore all rates to normal.
	void trRatesNormal();

	// Sends a Minimap flare to a certain player.
	void trMinimapFlare(int playerID = 0, float duration = 0, vector position = cOriginVector, bool flash = true);

	// Makes the camera shake.
	void trCameraShake(float duration = 0, float strength = 0);

	// Resets the black map for a given HUMAN player.
	void trPlayerResetBlackMap(int playerID = 0);

	// Resets the black map for all HUMAN players.
	void trPlayerResetBlackMapForAllPlayers();

	// Kills all of the units of a given player.
	void trPlayerKillAllUnits(int playerID = 0);

	// Kills all of the buildings of a given player.
	void trPlayerKillAllBuildings(int playerID = 0);

	// returns true if gadget is real.
	bool trIsGadgetVisible(string name = "Default");

	// enters the mode specified.
	void trModeEnter(string name = "Pregame");

	// advances the campaign.
	void trPlayerGrantResources(int player = 0, string resource = "None", int amount = 0);

	// Sets the selected unit as having the fake player with the specified index (0-7)
	void trUnitPlayerFakify(int fakePlayerIndex = 0);

	// Fakifies the army to the specified fake player index.
	void trArmyPlayerFakify(string armyname = "None", int fakeplayerindex = -1);

	// Sets the selected unit as not having a fake player
	void trUnitPlayerDefakify();

	// Defakifies the army.
	void trArmyPlayerDefakify(string armyname = "None");

	// Makes the camera shake.
	void trAIFunc(int playerID = 0, string functionName = "None", int param = 0);

	int trGetNumberSelectedUnitIDs();

	int trGetSelectedUnitID(int index  = -1);

	// removes protounit from the forbidden list
	bool trUnforbidProtounit(int player = -1, string protoname = "default");

	// adds protounit to the forbidden list
	bool trForbidProtounit(int player = -1, string protoname = "default");

	void trSetPauseOnAgeUpgrade(bool a = true);

	void trSetPauseInObjectiveWindow(bool a = true);

	void trSetCounterDisplay(string text = "Default");

	void trClearCounterDisplay();

	// plays movies from the AVI directory
	void trPlayMovie(string fileName = "test.bik");

	// returns false if a movie is currently playing
	bool trIsMovieNotPlaying();

	// shows whole map, similar to how revealed mode works
	void trRevealEntireMap();

	// set an override name for a specific unit
	void trUnitChangeName(string name = "Name");

	// returns whether or not the current chat history has any instance (substring) of this text
	bool trChatHistoryContains(string text = "default", int a = 1);

	// forces the chat history to reset
	void trChatHistoryClear();

	// fetch a stat value from the KB
	int trGetStatValue(int player = 1, int stat = 0);

	// fetch a stat value from the KB and echo to chat
	void trEchoStatValue(int player = 1, int stat = 0);

	// displays a custom image in a dialog, with a subtitle
	void trShowImageDialog(string texture = "default", string subtitle = "text");

	// displays dialog with 2 choices, and activates a trigger in response
	void trShowChoiceDialog(string maintext = "maintext", string choice1 = "text1", int event1 = 0, string choice2 = "text2", int event2 = 1);

	// modifies proto unit data for this scenario only.
	void trModifyProtounit(string unit = "default", int player = 1, int field = 0, float delta = 0);

	// does % percent of a unit's total HP in instant typeless damage.
	void trDamageUnitPercent(float percent = 1);

	// does a specific amount of damage to HP in instant typeless damage.
	void trDamageUnit(float amt = 1);

	// All units within dist of the selected ref object that match type take dmg
	void trDamageUnitsInArea(int player = 1, string unitType = "Unit", float dist = 10, float damage = 10);

	// puts up a big movie-credits style text overlay, optionally in a strange location, and now with a background
	void trOverlayText(string message = "default", float time = 0, int x = -1, int y = -1, int width = -1, string background = "None");

	// sets one of the trigger scratch variables
	void trQuestVarSet(string varname = "QV1", float value = 0);

	// copies value of one of the trigger scratch variables
	void trQuestVarCopy(string var1 = "QV1", string var2 = "QV2");

	// sets one of the trigger scratch variables within a random range
	void trQuestVarSetFromRand(string varname = "QV1", float minval = 0, float maxval = 1, bool round = true);

	// retrieve value of a trigger scratch variable, returns zero if unset
	float trQuestVarGet(string varname = "QV1");

	// chats out the value of one of the trigger scratch variables
	void trQuestVarEcho(string varname = "QV1");

	// Grants a number of Scenario VP to a player
	void trGrantVP(int player = 1, int number = 1);

	// returns the number of victory points for the player.
	int trPlayerVPCount(int playerID = 1);

	// enables/disables the award of VP's each year.
	void trVPAnnualAwards(bool enable = false);

	void trCreateTreaty(int a = 1, int b = 2, int c = 0, bool d = true, bool e = true, float f = 0, float g = 0, float h = 0);

	// returns the current gameplay mode index
	int vcGetGameplayMode();

	// checks for victory by being the last allied-unit alive
	bool vcCheckConquestVictory();

	// Moves the selected unit(s) to face the given unit.
	bool trUnitFaceUnit(string unitScenarioName = "None", int eventID = -1);

	// Orients the camera to the selected unit, and keeps it locked on that unit. ): puts the camera in the specified location.
	void trCameraLockOnUnit(bool enable = true, int time = 0, int to = -1);

	// Moves the camera in the same direction that a particular unit moves.
	void trCameraPanWithUnit(bool enable = true, int trigger = -1);

	// Disables (sets active = false) the trigger specified by the given eventID.
	void trDisableTrigger(int eventID = -1);

	// Makes a unit invulnerable to damage.  Turn it off to return the unit to normal.
	void trUnitMakeInvulnerable(bool enable = true);

	// Makes an action on a unit suspened or not.
	void trUnitSuspendAction(string actionName = "", bool suspend = true);

	// No help 
	void trCreateDefendPlan(string armyName = "", string defendPlanName = "triggerDefendPlan", float defendX = 0, float defendY = 0, float defendZ = 0, float engageRange = 50, int evaluationFrequency = 5, float gatherdistance = 25);

	// No help 
	void trCreateAttackPlan(string armyName = "", string PlanName = "triggerDefendPlan", int attackPlayerID = 2, float attackX = 0, float attackY = 0, float attackZ = 0, float engageRange = 50, int evaluationFrequency = 5);

	// No help 
	void trKillAIPlan(int playerID = -1, string planName = "");

	// Adds the units in the specified army to the specified plan.
	void trAddArmyToPlan(string armyname = "", string planname = "");

	// srcArmy units will defend defendedArmyUnits in the given planname.
	void trDefendUnits(string srcArmyname = "", string defendedArmyname = "", string planname = "", int evaluationFrequency = 5, float gatherdistance = 25);

	// srcArmy units will attack armyToAttack in the given planname.
	void trAttackUnits(string srcArmyname = "", string armyToAttack = "", string planname = "");

	// playerID will attack armyToAttack, sent via player Comms.
	void trAICommsAttackUnits(int playerID = 2, string armyToAttack = "");

	// playerID will defend point(defendX, defendY, defendZ), sent via player Comms.
	void trAICommsDefendPoint(int playerID = 2, float defendX = -1, float defendY = -1, float defendZ = -1);

	// fromPlayerID will send resource of x amount, sent via player Comms.
	void trAICommsRequestTribute(int fromPlayerID = 2, string resource = "food", float amount = 100);

	// tell player sendToPlayerID to cancel order, sent via player Comms.
	void trAICommsCancelOrder(int sendToPlayerID = 2);

	// tell player sendToPlayerID to claim TradePost at (locX, locY, locZ), sent via player Comms.
	void trAICommsClaim(int sendToPlayerID = 2, float a = -1, float b = -1, float c = -1);

	// tell player sendToPlayerID to train Units of type unitTypeName, sent via player Comms.
	void trAICommsTrain(int sendToPlayerID = 2, string unitTypeName = "");

	// Places train on a specified position on the route.
	void trTradeRouteSetPosition(int position = -1, float a = 1);

	// Enable or disables the unit from showing.
	void trTradeRouteToggleState(int position = -1, bool a = true);

	// Sets the specified trade route to the specified level from a trigger.
	void trTradeRouteSetLevel(int traderouteindex = -1, int level = -1);

	// Enable or disables the shadow far clippping plane.
	void trSetShadowFarClip(bool enable = true, float distance = 50);

	// Displays the SPC Note Dlg with the specified title and text.
	void trShowSPCNote(string Title = "Text", string Text = "Title");

	// Overrides the culture used for choosing the player's art.
	void trPlayerOverrideArtCulture(int playerID = -1, string culture = "WesternEurope");

	// Overrides the civilization used for choosing the player's vocal sound effects.
	void trPlayerOverrideSoundCiv(int playerID = -1, string civilization = "");
#endif

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
	struct array {
		T* Array;
		int Count;
	};

	struct civ {
		int Reserved;
		char* Name;
	};

	inline int GetNumberPlayers() {
		return *(int*)(*(int*)(*(int*)0xc66234 + 0x13c) + 0x5c);
	}

	inline array<civ*>* GetCivs() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (array<civ*>*)(_this + 0x24);
	}

	inline array<wchar_t*>* GetTechs() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (array<wchar_t*>*)(_this + 0x3824);
	}

	inline array<wchar_t*>* GetUnitTypes() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (array<wchar_t*>*)(_this + 0x190);
	}

	inline array<wchar_t*>* GetTactics() {
		int _this = *(int*)(*(int*)0xc66234 + 0x140);
		return (array<wchar_t*>*)(_this + 0x1ff0);
	}

	inline int GetMyID() {
		int _this = *(int*)(*(int*)0xc66234 + 0x13c);
		_this = *(int*)(*(int*)(_this + 0x58) + 4 * *(int*)0xc66664);
		int* _thisPlayer = (int*)(*(int*)(_this + 0x80) + 0xc);
		return _thisPlayer[1];
	}

	inline int GetMyCiv() {
		int _this = *(int*)(*(int*)0xc66234 + 0x13c);
		_this = *(int*)(*(int*)(_this + 0x58) + 4 * *(int*)0xc66664);
		int* _thisPlayer = (int*)(*(int*)(_this + 0x80) + 0xc);
		return **(int**)(*_thisPlayer + 0x20);
	}

	inline int GetMyTeam() {
		int _this = *(int*)(*(int*)0xc66234 + 0x13c);
		_this = *(int*)(*(int*)(_this + 0x58) + 4 * *(int*)0xc66664);
		int* _thisPlayer = (int*)(*(int*)(_this + 0x80) + 0xc);
		return *(int*)(*_thisPlayer + 0x10);
	}

}