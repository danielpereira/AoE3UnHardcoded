#include "stdafx.h"
#include "syscalls.h"

namespace syscalls
{
	_vector _cInvalidVector(-1, -1, -1);
	_vector _cOriginVector(0, 0, 0);

	_vector* const cInvalidVector = &_cInvalidVector;
	_vector* const cOriginVector = &_cOriginVector;

#ifdef UHC_SYSCALL_POINTERS
	void(*const map)(string, string, string) = reinterpret_cast<void(*)(string, string, string)>(0x5d5e92);
	void(*const echo)(string) = reinterpret_cast<void(*)(string)>(0x4011e6);
	void(*const echoLocalized)(int) = reinterpret_cast<void(*)(int)>(0x7d92f2);
	void(*const echoNum)(int) = reinterpret_cast<void(*)(int)>(0x7d932d);
	void(*const IMEEnable)(bool) = reinterpret_cast<void(*)(bool)>(0x7d9357);
	void(*const console)() = reinterpret_cast<void(*)()>(0x437f1b);
	void(*const pause)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x50f0cb);
	void(*const pause2)(int) = reinterpret_cast<void(*)(int)>(0x7dabac);
	void(*const unpauseNoChecks)() = reinterpret_cast<void(*)()>(0x7dabbc);
	void(*const exit)(bool) = reinterpret_cast<void(*)(bool)>(0x43b1a0);
	void(*const screenshot)() = reinterpret_cast<void(*)()>(0x7da55b);
	void(*const hackscreenshot)(int) = reinterpret_cast<void(*)(int)>(0x7da5e9);
	void(*const res)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7d9c10);
	void(*const resbpp)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7d9c8e);
	void(*const undo)() = reinterpret_cast<void(*)()>(0x7da8b9);
	void(*const redo)() = reinterpret_cast<void(*)()>(0x7da8d3);
	void(*const alignResources)() = reinterpret_cast<void(*)()>(0x7db188);
	void(*const alignSelectedUnits)() = reinterpret_cast<void(*)()>(0x7dd4f5);
	void(*const resourceMarket)(int, string, float, string) = reinterpret_cast<void(*)(int, string, float, string)>(0x7deec5);
	void(*const unitData)(int) = reinterpret_cast<void(*)(int)>(0x7de17b);
	void(*const unitSetVariation)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7dbee6);
	void(*const unitIncVariation)(int) = reinterpret_cast<void(*)(int)>(0x7dbfa0);
	void(*const unitDecVariation)(int) = reinterpret_cast<void(*)(int)>(0x7dc068);
	void(*const unitSetStanceAggressive)() = reinterpret_cast<void(*)()>(0x7dd560);
	void(*const unitSetStanceDefensive)() = reinterpret_cast<void(*)()>(0x7dd5af);
	void(*const unitSetStancePassive)() = reinterpret_cast<void(*)()>(0x7dd5fe);
	void(*const unitSetTactic)(string) = reinterpret_cast<void(*)(string)>(0x7dd64d);
	void(*const unitToggleStealth)() = reinterpret_cast<void(*)()>(0x7dd792);
	void(*const squadMode)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7de67f);
	void(*const setSquadMode)(string) = reinterpret_cast<void(*)(string)>(0x7de808);
	void(*const squadWheel)(float, int) = reinterpret_cast<void(*)(float, int)>(0x7de963);
	void(*const unitTownBell)() = reinterpret_cast<void(*)()>(0x7db365);
	void(*const unitReturnToWork)() = reinterpret_cast<void(*)()>(0x7db37e);
	void(*const obscuredUnitToggle)() = reinterpret_cast<void(*)()>(0x7de2f2);
	void(*const configDump)(string) = reinterpret_cast<void(*)(string)>(0x7d9385);
	void(*const configSet)(string, string) = reinterpret_cast<void(*)(string, string)>(0x7d93bc);
	void(*const configSetInt)(string, int) = reinterpret_cast<void(*)(string, int)>(0x7d93d3);
	void(*const configSetFloat)(string, float) = reinterpret_cast<void(*)(string, float)>(0x7d93ea);
	void(*const configDef)(string) = reinterpret_cast<void(*)(string)>(0x7d9401);
	void(*const configUndef)(string) = reinterpret_cast<void(*)(string)>(0x7d9411);
	void(*const configToggle)(string) = reinterpret_cast<void(*)(string)>(0x7d9421);
	void(*const config)(string) = reinterpret_cast<void(*)(string)>(0x7d9ea3);
	void(*const configGetByID)(int) = reinterpret_cast<void(*)(int)>(0x7d9431);
	void(*const configHelp)(string) = reinterpret_cast<void(*)(string)>(0x7d9453);
	void(*const configHelpPrefix)(string) = reinterpret_cast<void(*)(string)>(0x7d946a);
	void(*const saveGame)(string) = reinterpret_cast<void(*)(string)>(0x7dc130);
	void(*const saveScenario)(string) = reinterpret_cast<void(*)(string)>(0x7d9798);
	void(*const loadGame)(string) = reinterpret_cast<void(*)(string)>(0x7dac6e);
	void(*const loadScenario)(string) = reinterpret_cast<void(*)(string)>(0x516fc5);
	void(*const loadTutorial)(string, int, string, int, bool) = reinterpret_cast<void(*)(string, int, string, int, bool)>(0x7d9851);
	void(*const loadCampaignScenario)(string) = reinterpret_cast<void(*)(string)>(0x7d99f9);
	void(*const loadRecentFile)(string) = reinterpret_cast<void(*)(string)>(0x7d9afc);
	void(*const saveCamera)(string) = reinterpret_cast<void(*)(string)>(0x7daf53);
	void(*const saveCurrentHomeCityCamera)() = reinterpret_cast<void(*)()>(0x7dafe2);
	void(*const saveCurrentHomeCityWidescreenCamera)() = reinterpret_cast<void(*)()>(0x7db055);
	void(*const loadCamera)(string) = reinterpret_cast<void(*)(string)>(0x7db0f9);
	void(*const restart)() = reinterpret_cast<void(*)()>(0x7d9bbd);
	void(*const terrainFilter)() = reinterpret_cast<void(*)()>(0x7d9dba);
	void(*const terrainFilterArea)(int, int, int, int) = reinterpret_cast<void(*)(int, int, int, int)>(0x7d9d74);
	void(*const terrainFlatten)(float) = reinterpret_cast<void(*)(float)>(0x7d9e71);
	void(*const terrainFlattenArea)(int, int, int, int) = reinterpret_cast<void(*)(int, int, int, int)>(0x7d9e2e);
	void(*const terrainSetType)(int) = reinterpret_cast<void(*)(int)>(0x7da633);
	void(*const terrainSetSubtype)(int) = reinterpret_cast<void(*)(int)>(0x7da64d);
	void(*const terrainSetMix)(int) = reinterpret_cast<void(*)(int)>(0x7da664);
	void(*const terrainPaint)(string) = reinterpret_cast<void(*)(string)>(0x7daddd);
	void(*const terrainPaintMix)(string) = reinterpret_cast<void(*)(string)>(0x7dae6d);
	void(*const terrainAmbient)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dd499);
	void(*const terrainAdjustGlobalHeight)(float) = reinterpret_cast<void(*)(float)>(0x7da67a);
	void(*const cameraRotate)(int) = reinterpret_cast<void(*)(int)>(0x7d9d1f);
	void(*const cameraNice)() = reinterpret_cast<void(*)()>(0x7d9d64);
	void(*const cameraForward)(int) = reinterpret_cast<void(*)(int)>(0x7d9fc5);
	void(*const cameraWorldForward)(int) = reinterpret_cast<void(*)(int)>(0x7d9ff9);
	void(*const cameraWorldForwardLeft)(int) = reinterpret_cast<void(*)(int)>(0x7da02d);
	void(*const cameraWorldForwardRight)(int) = reinterpret_cast<void(*)(int)>(0x7da087);
	void(*const cameraBackward)(int) = reinterpret_cast<void(*)(int)>(0x7da0e1);
	void(*const cameraWorldBackward)(int) = reinterpret_cast<void(*)(int)>(0x7da115);
	void(*const cameraWorldBackwardLeft)(int) = reinterpret_cast<void(*)(int)>(0x7da149);
	void(*const cameraWorldBackwardRight)(int) = reinterpret_cast<void(*)(int)>(0x7da1a3);
	void(*const cameraRight)(int) = reinterpret_cast<void(*)(int)>(0x7da1fd);
	void(*const cameraLeft)(int) = reinterpret_cast<void(*)(int)>(0x7da231);
	void(*const cameraUp)(int) = reinterpret_cast<void(*)(int)>(0x7da265);
	void(*const cameraDown)(int) = reinterpret_cast<void(*)(int)>(0x7da2c2);
	void(*const cameraPitchForward)(int) = reinterpret_cast<void(*)(int)>(0x7da31f);
	void(*const cameraPitchBackward)(int) = reinterpret_cast<void(*)(int)>(0x7da353);
	void(*const cameraRollLeft)(int) = reinterpret_cast<void(*)(int)>(0x7da3bb);
	void(*const cameraRollRight)(int) = reinterpret_cast<void(*)(int)>(0x7da387);
	void(*const cameraYawRight)(int) = reinterpret_cast<void(*)(int)>(0x7da3ef);
	void(*const cameraYawLeft)(int) = reinterpret_cast<void(*)(int)>(0x7da458);
	void(*const cameraLocalYawRight)(int) = reinterpret_cast<void(*)(int)>(0x7da4c1);
	void(*const cameraLocalYawLeft)(int) = reinterpret_cast<void(*)(int)>(0x7da504);
	void(*const cameraDump)() = reinterpret_cast<void(*)()>(0x7da547);
	void(*const trackLoad)(string) = reinterpret_cast<void(*)(string)>(0x7dc24a);
	void(*const trackSave)(string) = reinterpret_cast<void(*)(string)>(0x7dc76c);
	void(*const trackClear)() = reinterpret_cast<void(*)()>(0x7dc483);
	void(*const trackStepForward)() = reinterpret_cast<void(*)()>(0x7dc3cb);
	void(*const trackStepBackward)() = reinterpret_cast<void(*)()>(0x7dc427);
	void(*const trackToggleShow)() = reinterpret_cast<void(*)()>(0x7dc4d4);
	void(*const trackAddWaypoint)() = reinterpret_cast<void(*)()>(0x7dc5b4);
	void(*const trackEditWaypoint)() = reinterpret_cast<void(*)()>(0x7dc605);
	void(*const trackSetSelectedWaypoint)(int) = reinterpret_cast<void(*)(int)>(0x7dc656);
	void(*const trackGotoSelectedWaypoint)(int) = reinterpret_cast<void(*)(int)>(0x7dc6ab);
	void(*const trackRemoveWaypoint)() = reinterpret_cast<void(*)()>(0x7dc71b);
	void(*const trackInsert)() = reinterpret_cast<void(*)()>(0x7dc2a8);
	void(*const trackRemove)() = reinterpret_cast<void(*)()>(0x7dc307);
	void(*const trackPlay)(float, int) = reinterpret_cast<void(*)(float, int)>(0x7dc358);
	void(*const trackPause)() = reinterpret_cast<void(*)()>(0x7dc380);
	void(*const trackStop)() = reinterpret_cast<void(*)()>(0x7dc397);
	void(*const trackAdvance)(float) = reinterpret_cast<void(*)(float)>(0x7dc3ae);
	void(*const trackGotoSelectedEvent)(int) = reinterpret_cast<void(*)(int)>(0x7dc7fd);
	void(*const areaIncrementAreaToRender)(int) = reinterpret_cast<void(*)(int)>(0x7da7e7);
	void(*const toggleShadows)() = reinterpret_cast<void(*)()>(0x7d9503);
	void(*const setShadowQuality)(int) = reinterpret_cast<void(*)(int)>(0x7d9481);
	void(*const setShadowBiasMul)(float) = reinterpret_cast<void(*)(float)>(0x7d94a1);
	void(*const setShadowSnapping)(int) = reinterpret_cast<void(*)(int)>(0x7d94bf);
	void(*const setShadowRotationOp)(int) = reinterpret_cast<void(*)(int)>(0x7d94e1);
	void(*const renderWindow)(int) = reinterpret_cast<void(*)(int)>(0x7d9f22);
	void(*const renderBaseID)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7da7b1);
	void(*const renderAreas)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7da6ac);
	void(*const renderAreaDangerLevels)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7da71b);
	void(*const renderAreaID)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dc9a6);
	void(*const renderAreaGroupID)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dc85f);
	void(*const renderAnisotropic)(int) = reinterpret_cast<void(*)(int)>(0x7d951a);
	void(*const setHDRMultisampleFactor)(int) = reinterpret_cast<void(*)(int)>(0x7d952f);
	void(*const setSuperSampleFactors)(float, float) = reinterpret_cast<void(*)(float, float)>(0x7d954d);
	void(*const setSuperSampleFilterScales)(float, float) = reinterpret_cast<void(*)(float, float)>(0x7d9570);
	void(*const setSuperSampleFilterIndex)(int) = reinterpret_cast<void(*)(int)>(0x7d9593);
	void(*const renderTrilinear)(int) = reinterpret_cast<void(*)(int)>(0x7d95b1);
	void(*const renderFriendOrFoe)(int) = reinterpret_cast<void(*)(int)>(0x7d95ed);
	void(*const ambientColor)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dcb3a);
	void(*const ambientGetColor)() = reinterpret_cast<void(*)()>(0x7da8ed);
	void(*const resetAmbientColor)() = reinterpret_cast<void(*)()>(0x7dcbf2);
	void(*const ambientColor2)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dcb96);
	void(*const shadowDarkness)(float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dcc01);
	void(*const sunColor)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dccd5);
	void(*const sunGetColor)() = reinterpret_cast<void(*)()>(0x7da907);
	void(*const resetSunColor)() = reinterpret_cast<void(*)()>(0x7dcd3a);
	void(*const fakeSunParams)(float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dcd52);
	void(*const setHemiLight)(float, float, float, float, float, float, float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, float, float, float)>(0x7da92a);
	void(*const setSceneLightParams)(float, float, float, float, float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, float)>(0x7dcd8c);
	void(*const setFogParams)(float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dce98);
	void(*const setBumpScale)(float) = reinterpret_cast<void(*)(float)>(0x7dcf32);
	void(*const unitPlayerFakify)(int) = reinterpret_cast<void(*)(int)>(0x7dcf53);
	void(*const unitPlayerDefakify)() = reinterpret_cast<void(*)()>(0x7dcfd8);
	void(*const setToneMapParams)(float, float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float, float)>(0x7dd05c);
	void(*const setBloomParams)(float, float, float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float, float, float)>(0x7dd10a);
	void(*const setLDRBloomParams)(float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dd1f7);
	void(*const setBloomStreakParams)(float, float, float, float, float, float, float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, float, float)>(0x7dd291);
	void(*const setBloomFeedbackParams)(float, float) = reinterpret_cast<void(*)(float, float)>(0x7dd3e7);
	void(*const setTerrainLightingParams)(float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float)>(0x7dd425);
	void(*const applyLightingSet)(string) = reinterpret_cast<void(*)(string)>(0x90b775);
	void(*const saveLightingSet)(string) = reinterpret_cast<void(*)(string)>(0x7da9cc);
	void(*const loadLightingSet)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x7da9fa);
	void(*const brushCircularSize)(float) = reinterpret_cast<void(*)(float)>(0x7da5ee);
	void(*const musicStop)() = reinterpret_cast<void(*)()>(0x7da83c);
	void(*const musicSetVolume)(float) = reinterpret_cast<void(*)(float)>(0x7da85e);
	void(*const musicPlaySong)(string, float) = reinterpret_cast<void(*)(string, float)>(0x7dca90);
	void(*const musicToggleBattleMode)() = reinterpret_cast<void(*)()>(0x7da88c);
	void(*const displayType)(int) = reinterpret_cast<void(*)(int)>(0x7d9ecd);
	void(*const player)(int) = reinterpret_cast<void(*)(int)>(0x7dc1fe);
	void(*const fog)(int) = reinterpret_cast<void(*)(int)>(0x7d9644);
	void(*const blackmap)(int) = reinterpret_cast<void(*)(int)>(0x7d96ee);
	void(*const modeEnter)(string) = reinterpret_cast<void(*)(string)>(0x56b23a);
	void(*const startCampaign)(string) = reinterpret_cast<void(*)(string)>(0x7daa64);
	void(*const uiEnterGameMenuModeIfNotResigned)() = reinterpret_cast<void(*)()>(0x7daae9);
	void(*const modeToggleBetweenIfNotMP)(string, string) = reinterpret_cast<void(*)(string, string)>(0x7dab97);
	void(*const helpPrefix)(string) = reinterpret_cast<void(*)(string)>(0x7de41d);
	void(*const help)(string) = reinterpret_cast<void(*)(string)>(0x7de4db);
	void(*const helpText)(string) = reinterpret_cast<void(*)(string)>(0x7de598);
	void(*const lookAt)(float, float) = reinterpret_cast<void(*)(float, float)>(0x7db393);
	void(*const lookAtArmy)(int, string) = reinterpret_cast<void(*)(int, string)>(0x7db3c4);
	void(*const resetDefaultPlayerColors)() = reinterpret_cast<void(*)()>(0x7db42c);
	void(*const setMinimapUnitFilter)(int) = reinterpret_cast<void(*)(int)>(0x7dd911);
	void(*const setGraphicDetail)(int) = reinterpret_cast<void(*)(int)>(0x7db440);
	void(*const setWorldDifficulty)(int) = reinterpret_cast<void(*)(int)>(0x7db453);
	void(*const startAutoPatcher)(bool) = reinterpret_cast<void(*)(bool)>(0x7db502);
	void(*const cancelAutoPatcher)() = reinterpret_cast<void(*)()>(0x7db638);
	void(*const confirmAutoPatcher)() = reinterpret_cast<void(*)()>(0x7db65c);
	void(*const playMovie)(string) = reinterpret_cast<void(*)(string)>(0x7db744);
	void(*const toggleHomeCityView)() = reinterpret_cast<void(*)()>(0x7dd94a);
	void(*const toggleHomeCityViewTech)() = reinterpret_cast<void(*)()>(0x7db768);
	void(*const lookAtHomeCityBuilding)(int) = reinterpret_cast<void(*)(int)>(0x7db7fb);
	void(*const homeCityTrain)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7db987);
	void(*const homeCityTrain2)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7db9be);
	void(*const homeCityTransport)(int) = reinterpret_cast<void(*)(int)>(0x7dba5f);
	void(*const fourOfAKind)() = reinterpret_cast<void(*)()>(0x7dba88);
	void(*const relicCapture)() = reinterpret_cast<void(*)()>(0x7dbab3);
	void(*const kothVictory)() = reinterpret_cast<void(*)()>(0x7dbade);
	void(*const tradeRouteCommand)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7db846);
	void(*const tradeRouteTrain)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7db879);
	void(*const commandResearch)(int, int, int, int) = reinterpret_cast<void(*)(int, int, int, int)>(0x7db932);
	void(*const mercTrain)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7db9f2);
	void(*const homeCityShipEject)(int, int, int, int) = reinterpret_cast<void(*)(int, int, int, int)>(0x7dba27);
	void(*const loadGrouping)(string) = reinterpret_cast<void(*)(string)>(0x7dd9b8);
	void(*const loadUserDefinedGrouping)(string) = reinterpret_cast<void(*)(string)>(0x7ddacc);
	void(*const loadGroupingUnicode)(string) = reinterpret_cast<void(*)(string)>(0x7dbb09);
	void(*const loadGroupingUnicodeLUA)(int, string) = reinterpret_cast<void(*)(int, string)>(0x7dbb7b);
	void(*const repairUnit)(int) = reinterpret_cast<void(*)(int)>(0x7decea);
	void(*const cancelRepairUnit)(int) = reinterpret_cast<void(*)(int)>(0x7debdc);
	void(*const setHomeCityGatherUnit)(int) = reinterpret_cast<void(*)(int)>(0x7ddbd4);
	void(*const convertCoveredWagon)() = reinterpret_cast<void(*)()>(0x7dedcc);
	void(*const breakTreaty)() = reinterpret_cast<void(*)()>(0x7dbc07);
	void(*const ransomExplorer)() = reinterpret_cast<void(*)()>(0x7dea71);
	void(*const toggleWorldTooltipClipRect)() = reinterpret_cast<void(*)()>(0x7db1a5);
	void(*const drawWorldTooltipClipRect)() = reinterpret_cast<void(*)()>(0x7db1cd);
	void(*const setWorldTooltipRectDims1024)(int, int, int, int) = reinterpret_cast<void(*)(int, int, int, int)>(0x7db1f5);
	void(*const upgradeTradeRoute)(int) = reinterpret_cast<void(*)(int)>(0x7dbbef);
	void(*const spawnUnits)(string, int, int) = reinterpret_cast<void(*)(string, int, int)>(0x7db8ac);
	void(*const ability)(int, int, bool) = reinterpret_cast<void(*)(int, int, bool)>(0x7ddc52);
	void(*const doAbilityInType)(string, string) = reinterpret_cast<void(*)(string, string)>(0x7ddd9d);
	void(*const doAbilityInSelected)(string) = reinterpret_cast<void(*)(string)>(0x7ddf31);
	void(*const doCommandInSelected)(string) = reinterpret_cast<void(*)(string)>(0x7df08b);
	void(*const specialPower)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7dbc39);
	void(*const vsync)(int) = reinterpret_cast<void(*)(int)>(0x7dbd58);
	void(*const startMoviePlayback)(string, int, float, float) = reinterpret_cast<void(*)(string, int, float, float)>(0x7db680);
	void(*const trainReinforcement)(int) = reinterpret_cast<void(*)(int)>(0x7dbd9a);
	void(*const cancelTrainReinforcement)(int) = reinterpret_cast<void(*)(int)>(0x7dbdca);
	void(*const setDropDefaultMips)(int) = reinterpret_cast<void(*)(int)>(0x7dbe4e);
	void(*const setDropTerrainMips)(int) = reinterpret_cast<void(*)(int)>(0x7dbe87);
	void(*const showSPCNote)(string, string) = reinterpret_cast<void(*)(string, string)>(0x7dbdfa);
	void(*const renderForceReset)() = reinterpret_cast<void(*)()>(0x7dbec0);
	void(*const editorSetTechStatus)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x7df22a);
	void(*const editorUpdateUnitVisuals)() = reinterpret_cast<void(*)()>(0x7de0a7);
	void(*const editorSetAllTradeRoutesToDef)(string) = reinterpret_cast<void(*)(string)>(0x7de0ed);
	void(*const researchByID)(int, int, int, bool) = reinterpret_cast<void(*)(int, int, int, bool)>(0x7df3f9);
	void(*const researchTechInSelected)(string) = reinterpret_cast<void(*)(string)>(0x7df54d);
	void(*const trainByID)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x7df6af);
	void(*const trainInSelected)(string, int) = reinterpret_cast<void(*)(string, int)>(0x7dfccf);
	void(*const cancelTrainInSelected)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7df99d);
	void(*const cancelResearchInSelected)(int) = reinterpret_cast<void(*)(int)>(0x7dfb9b);
	void(*const trainInSelectedByID)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7df808);
	void(*const click)() = reinterpret_cast<void(*)()>(0x7df2d5);
	void(*const homeCityResearch)(int, string) = reinterpret_cast<void(*)(int, string)>(0x7dfd22);
	void(*const homeCityResearchByID)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7df32f);
	void(*const homeCityMakeActiveByID)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7df2f9);
	void(*const homeCityResearchByIDOutsideGame)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7df365);
	void(*const homeCityResearchByIDPregame)(int) = reinterpret_cast<void(*)(int)>(0x7df3c9);
	void(*const editMode)(string) = reinterpret_cast<void(*)(string)>(0x7dfdde);
	void(*const uiBuildAtPointer)() = reinterpret_cast<void(*)()>(0x7e6de8);
	void(*const uiFormationOrientation)() = reinterpret_cast<void(*)()>(0x7dfe09);
	void(*const uiBuildWallAtPointer)(bool) = reinterpret_cast<void(*)(bool)>(0x7dfe31);
	void(*const uiCreateRiverToggleWaypointMode)() = reinterpret_cast<void(*)()>(0x7dfe64);
	void(*const uiPlaceRiverWaypoint)() = reinterpret_cast<void(*)()>(0x7dfe88);
	void(*const uiRemoveRiverWaypoint)() = reinterpret_cast<void(*)()>(0x7dfeaf);
	void(*const uiCreateRiver)() = reinterpret_cast<void(*)()>(0x7dfed6);
	void(*const uiCreateRandomRiver)() = reinterpret_cast<void(*)()>(0x7dfefa);
	void(*const uiPlaceRiverShallow)() = reinterpret_cast<void(*)()>(0x7dff1e);
	void(*const uiRemoveRiverShallow)() = reinterpret_cast<void(*)()>(0x7dff45);
	void(*const uiWheelRotateRiverShallow)(int) = reinterpret_cast<void(*)(int)>(0x7dff6c);
	void(*const uiSetGatherPointAtPointer)(bool, bool) = reinterpret_cast<void(*)(bool, bool)>(0x7dffcd);
	void(*const uiSetHomeCityWaterSpawnPointAtPointer)() = reinterpret_cast<void(*)()>(0x7dffe9);
	void(*const uiClearGatherPoint)() = reinterpret_cast<void(*)()>(0x7e705e);
	void(*const uiTransformSelectedUnit)(string) = reinterpret_cast<void(*)(string)>(0x7e7193);
	void(*const uiFlareAtPointer)() = reinterpret_cast<void(*)()>(0x7dfff9);
	void(*const uiCommsFlareAtPointer)() = reinterpret_cast<void(*)()>(0x7e009d);
	void(*const uiHelpAtPointer)() = reinterpret_cast<void(*)()>(0x7e4056);
	void(*const uiGarrisonToPointer)() = reinterpret_cast<void(*)()>(0x7e7455);
	void(*const uiRepairAtPointer)() = reinterpret_cast<void(*)()>(0x7e745e);
	void(*const uiEmpowerAtPointer)() = reinterpret_cast<void(*)()>(0x7e7467);
	void(*const uiSetProtoCursor)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x7e00f5);
	void(*const uiSetProtoCursorID)(int) = reinterpret_cast<void(*)(int)>(0x7e00de);
	void(*const uiEnterContext)(string) = reinterpret_cast<void(*)(string)>(0x7e01b7);
	void(*const uiLeaveContext)(string) = reinterpret_cast<void(*)(string)>(0x7e01d0);
	void(*const uiClearCursor)() = reinterpret_cast<void(*)()>(0x7e01e9);
	void(*const uiYawUnitRight)(int) = reinterpret_cast<void(*)(int)>(0x7e021b);
	void(*const uiYawUnitLeft)(int) = reinterpret_cast<void(*)(int)>(0x7e0278);
	void(*const uiPitchUnitUp)(int) = reinterpret_cast<void(*)(int)>(0x7e02d5);
	void(*const uiPitchUnitDown)(int) = reinterpret_cast<void(*)(int)>(0x7e0332);
	void(*const uiRollUnitRight)(int) = reinterpret_cast<void(*)(int)>(0x7e038f);
	void(*const uiRollUnitLeft)(int) = reinterpret_cast<void(*)(int)>(0x7e03ec);
	void(*const uiMoveUnitForward)(int) = reinterpret_cast<void(*)(int)>(0x7e0449);
	void(*const uiMoveUnitBackward)(int) = reinterpret_cast<void(*)(int)>(0x7e04a6);
	void(*const uiMoveUnitRight)(int) = reinterpret_cast<void(*)(int)>(0x7e061a);
	void(*const uiMoveUnitLeft)(int) = reinterpret_cast<void(*)(int)>(0x7e05bd);
	void(*const uiMoveUnitUp)(int) = reinterpret_cast<void(*)(int)>(0x7e0503);
	void(*const uiMoveUnitDown)(int) = reinterpret_cast<void(*)(int)>(0x7e0560);
	void(*const uiWheelRotatePlacedUnit)(int) = reinterpret_cast<void(*)(int)>(0x7e0677);
	void(*const uiSelectWaterAtPointer)() = reinterpret_cast<void(*)()>(0x7e0708);
	void(*const uiUnSelectWater)() = reinterpret_cast<void(*)()>(0x7e0722);
	void(*const uiPaintWaterObjects)() = reinterpret_cast<void(*)()>(0x7e074b);
	void(*const uiRotateWaterLeft)(int) = reinterpret_cast<void(*)(int)>(0x7e084d);
	void(*const uiRotateWaterRight)(int) = reinterpret_cast<void(*)(int)>(0x7e0891);
	void(*const uiSelectionButtonDown)() = reinterpret_cast<void(*)()>(0x7e0978);
	void(*const uiSelectionButtonUp)() = reinterpret_cast<void(*)()>(0x7e098b);
	void(*const uiCreateNumberGroup)(int) = reinterpret_cast<void(*)(int)>(0x7e099e);
	void(*const uiClearNumberGroup)(int) = reinterpret_cast<void(*)(int)>(0x7e09ff);
	void(*const uiSelectNumberGroup)(int) = reinterpret_cast<void(*)(int)>(0x7e0a5b);
	void(*const uiAddSelectNumberGroup)(int) = reinterpret_cast<void(*)(int)>(0x7e0ae8);
	void(*const uiRemoveFromAnyNumberGroup)() = reinterpret_cast<void(*)()>(0x7e0b94);
	void(*const uiDoubleClickSelect)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e1de7);
	void(*const uiAddSelectionButtonDown)() = reinterpret_cast<void(*)()>(0x7e1e1f);
	void(*const uiAddSelectionButtonUp)() = reinterpret_cast<void(*)()>(0x7e1e4c);
	void(*const uiToggleSelectionButton)() = reinterpret_cast<void(*)()>(0x7e1e5f);
	void(*const uiRotateSelection)(int) = reinterpret_cast<void(*)(int)>(0x7e0955);
	void(*const uiMoveSelectionButtonDown)() = reinterpret_cast<void(*)()>(0x7e08d5);
	void(*const uiMoveSelectionButtonUp)() = reinterpret_cast<void(*)()>(0x7e08f5);
	void(*const uiMoveSelectionAddButtonDown)() = reinterpret_cast<void(*)()>(0x7e0915);
	void(*const uiMoveSelectionAddButtonUp)() = reinterpret_cast<void(*)()>(0x7e0935);
	void(*const uiWorkAtPointer)() = reinterpret_cast<void(*)()>(0x7e1f29);
	void(*const uiWheelRotate)(int) = reinterpret_cast<void(*)(int)>(0x7e1897);
	void(*const uiWheelRotateCamera)(int) = reinterpret_cast<void(*)(int)>(0x7e1908);
	void(*const uiChangeElevationToSample)(int) = reinterpret_cast<void(*)(int)>(0x7e0e07);
	void(*const uiSampleElevationAtPointer)() = reinterpret_cast<void(*)()>(0x7e0f50);
	void(*const uiSampleCliffElevationAtPointer)() = reinterpret_cast<void(*)()>(0x7e50ee);
	void(*const uiPaintTerrainToSample)(int) = reinterpret_cast<void(*)(int)>(0x7e0f6e);
	void(*const uiSampleTerrainAtPointer)() = reinterpret_cast<void(*)()>(0x7e10ea);
	void(*const uiDeleteSelectedUnit)() = reinterpret_cast<void(*)()>(0x7e5197);
	void(*const uiDeleteSelectedUnit2)() = reinterpret_cast<void(*)()>(0x7e540a);
	void(*const uiDeleteAllSelectedUnits)() = reinterpret_cast<void(*)()>(0x7e1108);
	void(*const uiRemoveSelectedUnit)(int) = reinterpret_cast<void(*)(int)>(0x7e540f);
	void(*const uiStopSelectedUnits)() = reinterpret_cast<void(*)()>(0x7e0dfc);
	void(*const uiRaiseElevation)(int) = reinterpret_cast<void(*)(int)>(0x7e1116);
	void(*const uiLowerElevation)(int) = reinterpret_cast<void(*)(int)>(0x7e12c8);
	void(*const uiUniformRaiseElevation)(int) = reinterpret_cast<void(*)(int)>(0x7e147a);
	void(*const uiUniformLowerElevation)(int) = reinterpret_cast<void(*)(int)>(0x7e14ba);
	void(*const uiSmooth)(int) = reinterpret_cast<void(*)(int)>(0x7e14fa);
	void(*const uiPaintWater)(int) = reinterpret_cast<void(*)(int)>(0x7e1747);
	void(*const uiPaintWaterArea)(int) = reinterpret_cast<void(*)(int)>(0x7e176a);
	void(*const uiPaintCliff)(int) = reinterpret_cast<void(*)(int)>(0x7e178d);
	void(*const uiTerrainSelection)(int) = reinterpret_cast<void(*)(int)>(0x7e17b0);
	void(*const uiRaiseTerrainSelection)(int) = reinterpret_cast<void(*)(int)>(0x7e17e6);
	void(*const uiLowerTerrainSelection)(int) = reinterpret_cast<void(*)(int)>(0x7e1821);
	void(*const uiFlattenTerrainSelection)() = reinterpret_cast<void(*)()>(0x7e185b);
	void(*const uiFilterTerrainSelection)() = reinterpret_cast<void(*)()>(0x7e1879);
	void(*const uiOpenScenarioBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e54fb);
	void(*const uiSaveScenarioBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e5681);
	void(*const uiSaveAsScenarioBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e55d1);
	void(*const uiOpenGrandConquestBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e5714);
	void(*const uiScenarioLoad)() = reinterpret_cast<void(*)()>(0x7e2748);
	void(*const uiStartScenarioTest)() = reinterpret_cast<void(*)()>(0x7e1a09);
	void(*const uiStopScenarioTest)() = reinterpret_cast<void(*)()>(0x7e1a29);
	void(*const uiStartBuildCinematic)() = reinterpret_cast<void(*)()>(0x7e57c0);
	void(*const uiStopBuildCinematic)() = reinterpret_cast<void(*)()>(0x7e1a49);
	void(*const uiClearCinematicInfo)() = reinterpret_cast<void(*)()>(0x7e5801);
	void(*const uiClearAllCinematicInfo)() = reinterpret_cast<void(*)()>(0x7e5845);
	void(*const uiOpenCameraTrackBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e5889);
	void(*const uiSaveCameraTrackBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e595f);
	void(*const uiOpenSavedGameBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e5a35);
	void(*const uiSaveSavedGameBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e5b0b);
	void(*const uiZoomToProto)(string) = reinterpret_cast<void(*)(string)>(0x7e5be1);
	void(*const uiOpenRecordGameBrowser)(string) = reinterpret_cast<void(*)(string)>(0x7e5d4d);
	void(*const uiLookAtSelection)() = reinterpret_cast<void(*)()>(0x43a7b3);
	void(*const uiLookAtUnit)(int) = reinterpret_cast<void(*)(int)>(0x7e5e7b);
	void(*const uiLookAtBattle)(int) = reinterpret_cast<void(*)(int)>(0x7e1a69);
	void(*const uiLookAtAndSelectUnit)(int) = reinterpret_cast<void(*)(int)>(0x7e5dfd);
	void(*const uiLookAtUnitByName)(string) = reinterpret_cast<void(*)(string)>(0x7e5edb);
	void(*const uiLookAtProto)(string) = reinterpret_cast<void(*)(string)>(0x7e5f7c);
	void(*const uiLookAtNumberGroup)(int) = reinterpret_cast<void(*)(int)>(0x7e1aa4);
	void(*const uiRoughen)(int) = reinterpret_cast<void(*)(int)>(0x7e1af9);
	void(*const uiDeleteUnits)(int) = reinterpret_cast<void(*)(int)>(0x7e1b34);
	void(*const uiPaint)(bool, bool) = reinterpret_cast<void(*)(bool, bool)>(0x7e1b6f);
	void(*const uiPaintForest)(bool, bool) = reinterpret_cast<void(*)(bool, bool)>(0x7e1cc8);
	void(*const uiPaintTerrainOverlay)(int) = reinterpret_cast<void(*)(int)>(0x7e1d83);
	void(*const uiPlaceAtPointer)(bool) = reinterpret_cast<void(*)(bool)>(0x7e06db);
	void(*const uiSetProtoID)(int) = reinterpret_cast<void(*)(int)>(0x7e016a);
	void(*const uiIncPlaceVariation)() = reinterpret_cast<void(*)()>(0x7e0194);
	void(*const uiBuildMode)(int) = reinterpret_cast<void(*)(int)>(0x7e48e0);
	void(*const uiFindIdleType)(string) = reinterpret_cast<void(*)(string)>(0x7e7a50);
	void(*const uiFindAllOfSelectedType)() = reinterpret_cast<void(*)()>(0x7e49c2);
	void(*const uiFindAllOfType)(string) = reinterpret_cast<void(*)(string)>(0x7e7ab9);
	void(*const uiFindAllOfTypeIdle)(string) = reinterpret_cast<void(*)(string)>(0x7e7be9);
	void(*const uiHandleIdleBanner)(string) = reinterpret_cast<void(*)(string)>(0x7e7dce);
	void(*const uiFindTownBellTC)(string) = reinterpret_cast<void(*)(string)>(0x7e4e31);
	void(*const uiFindType)(string) = reinterpret_cast<void(*)(string)>(0x7e774a);
	void(*const uiCycleGadget)(int) = reinterpret_cast<void(*)(int)>(0x7e0c83);
	void(*const uiCloseFieldSet)() = reinterpret_cast<void(*)()>(0x7e4f99);
	void(*const uiCloseDialog)() = reinterpret_cast<void(*)()>(0x7e501f);
	void(*const uiMessageBox)(string, string) = reinterpret_cast<void(*)(string, string)>(0x7e0c88);
	void(*const uiMessageBox2)(int, string) = reinterpret_cast<void(*)(int, string)>(0x7e0ce9);
	void(*const uiCopyToClipboard)() = reinterpret_cast<void(*)()>(0x7e0d4a);
	void(*const uiPasteFromClipboard)() = reinterpret_cast<void(*)()>(0x7e0d6e);
	void(*const uiSetClipboardRotation)(float) = reinterpret_cast<void(*)(float)>(0x7e0d92);
	void(*const uiRotateClipboard)(int) = reinterpret_cast<void(*)(int)>(0x7e0dbc);
	void(*const uiEjectGarrisonedUnits)() = reinterpret_cast<void(*)()>(0x7e429c);
	void(*const uiEjectAtPointer)() = reinterpret_cast<void(*)()>(0x7e411f);
	void(*const uiPatrolAtPointer)() = reinterpret_cast<void(*)()>(0x7e7470);
	void(*const uiApplyLightingSet)(int) = reinterpret_cast<void(*)(int)>(0x7e1dc1);
	void(*const uiSetBrushType)(string, float, float, float, float) = reinterpret_cast<void(*)(string, float, float, float, float)>(0x7e1f39);
	void(*const uiChangeBrushType)(string) = reinterpret_cast<void(*)(string)>(0x7e1fa8);
	void(*const uiChangeBrushSize)(float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float)>(0x7e2003);
	void(*const uiScrollBrushSize)(int) = reinterpret_cast<void(*)(int)>(0x7e2039);
	void(*const uiChangeBrushCornerMode)(int) = reinterpret_cast<void(*)(int)>(0x7e207a);
	void(*const uiChangeCliffModMode)(int) = reinterpret_cast<void(*)(int)>(0x7e20b5);
	void(*const uiScrollCliffHeight)(int) = reinterpret_cast<void(*)(int)>(0x7e609a);
	void(*const uiIgnoreNextKey)() = reinterpret_cast<void(*)()>(0x512dd4);
	void(*const uiCycleCurrentActivate)() = reinterpret_cast<void(*)()>(0x7e24c3);
	void(*const uiClearMenu)(string) = reinterpret_cast<void(*)(string)>(0x7e621b);
	void(*const uiClearSelection)() = reinterpret_cast<void(*)()>(0x7e24c8);
	void(*const uiDumpKeyMappings)(string) = reinterpret_cast<void(*)(string)>(0x7e2537);
	void(*const uiDumpAllUnitHotKeyMappings)(string) = reinterpret_cast<void(*)(string)>(0x7e2583);
	void(*const uiDumpUnmappedKeys)(string) = reinterpret_cast<void(*)(string)>(0x7e26eb);
	void(*const uiFindKeyMapping)(string) = reinterpret_cast<void(*)(string)>(0x7e2731);
	void(*const uiHandleUserTab)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7e50a5);
	void(*const uiCoverTerrainWithWater)(float, float, string) = reinterpret_cast<void(*)(float, float, string)>(0x7e27b3);
	bool(*const uiSetCliffType)(string) = reinterpret_cast<bool(*)(string)>(0x7e2859);
	bool(*const uiSetCliffTypeNum)(int) = reinterpret_cast<bool(*)(int)>(0x7e2894);
	bool(*const uiSetWaterType)(string) = reinterpret_cast<bool(*)(string)>(0x7e28be);
	bool(*const uiSetWaterTypeNum)(int) = reinterpret_cast<bool(*)(int)>(0x7e28f9);
	bool(*const uiSetForestType)(string) = reinterpret_cast<bool(*)(string)>(0x7e2923);
	bool(*const uiSetForestTypeNum)(int) = reinterpret_cast<bool(*)(int)>(0x7e2a0d);
	void(*const uiSelectForestAtPointer)() = reinterpret_cast<void(*)()>(0x7e2ada);
	void(*const uiUnselectForest)() = reinterpret_cast<void(*)()>(0x7e2af4);
	void(*const uiSelectCliffAtPointer)() = reinterpret_cast<void(*)()>(0x7e2b0e);
	void(*const uiUnselectCliff)() = reinterpret_cast<void(*)()>(0x7e2b28);
	void(*const uiToggleCliff)() = reinterpret_cast<void(*)()>(0x7e2b42);
	void(*const gadgetScrollUp)(string) = reinterpret_cast<void(*)(string)>(0x7e20e8);
	void(*const gadgetScrollDown)(string) = reinterpret_cast<void(*)(string)>(0x7e213f);
	void(*const gadgetScrollLeft)(string) = reinterpret_cast<void(*)(string)>(0x7e2196);
	void(*const gadgetScrollRight)(string) = reinterpret_cast<void(*)(string)>(0x7e21ed);
	void(*const gadgetReal)(string) = reinterpret_cast<void(*)(string)>(0x7e2244);
	void(*const gadgetUnreal)(string) = reinterpret_cast<void(*)(string)>(0x442be7);
	void(*const gadgetToggle)(string) = reinterpret_cast<void(*)(string)>(0x7e2278);
	void(*const gadgetToggleIfNotMP)(string) = reinterpret_cast<void(*)(string)>(0x7e22ac);
	void(*const gadgetRefresh)(string) = reinterpret_cast<void(*)(string)>(0x7e22f0);
	void(*const gadgetFlash)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x7e61ac);
	void(*const techFlash)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e2332);
	void(*const trainFlash)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e235b);
	void(*const categoryFlash)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x98160f);
	void(*const fadeToColor)(int, int, int, int, int, bool) = reinterpret_cast<void(*)(int, int, int, int, int, bool)>(0x7e2384);
	void(*const setGameFadeIn)(int, int, int, int, int, bool) = reinterpret_cast<void(*)(int, int, int, int, int, bool)>(0x7e242d);
	void(*const uiLoadTriggers)(string) = reinterpret_cast<void(*)(string)>(0x7e627c);
	void(*const uiSaveTriggers)(string) = reinterpret_cast<void(*)(string)>(0x7e2b5c);
	void(*const uiImportTriggers)(string) = reinterpret_cast<void(*)(string)>(0x7e63cc);
	void(*const doTriggerImport)(string) = reinterpret_cast<void(*)(string)>(0x7e64ae);
	void(*const uiExportTriggers)(string) = reinterpret_cast<void(*)(string)>(0x7e62ea);
	void(*const uiTriggerSelectLocation)() = reinterpret_cast<void(*)()>(0x7e2b86);
	void(*const uiTriggerResetParameters)() = reinterpret_cast<void(*)()>(0x7e2bf1);
	void(*const uiTriggerResetSounds)() = reinterpret_cast<void(*)()>(0x7e2c15);
	void(*const uiExportGrouping)(string) = reinterpret_cast<void(*)(string)>(0x7e651c);
	void(*const uiSaveGrouping)(string) = reinterpret_cast<void(*)(string)>(0x7e2c39);
	void(*const uiSaveGroupingLUA)(int, string) = reinterpret_cast<void(*)(int, string)>(0x7e2ca0);
	void(*const uiHideCursor)(bool) = reinterpret_cast<void(*)(bool)>(0x7e2d42);
	void(*const uiLeaveModeOnUnshift)() = reinterpret_cast<void(*)()>(0x7e2d2b);
	void(*const uiToggleBrushMask)(int) = reinterpret_cast<void(*)(int)>(0x7e65fe);
	void(*const uiToggleTerrainPasteMode)(int) = reinterpret_cast<void(*)(int)>(0x7e2d57);
	void(*const uiUnitDetailHelp)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7e665d);
	void(*const uiTechDetailHelp)(int) = reinterpret_cast<void(*)(int)>(0x7e2da4);
	void(*const uiTechCivDetailHelp)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7e2dea);
	void(*const uiTopicDetailHelp)(string) = reinterpret_cast<void(*)(string)>(0x7e2e33);
	void(*const uiLastDetailHelp)() = reinterpret_cast<void(*)()>(0x7e2e6e);
	void(*const AIDebugInfoRefresh)() = reinterpret_cast<void(*)()>(0x7e2e86);
	void(*const AIDebugInfoToggle)() = reinterpret_cast<void(*)()>(0x7e2eaf);
	void(*const AIDebugOutputToggle)() = reinterpret_cast<void(*)()>(0x7e2f7b);
	void(*const AIDebugGathererToggle)() = reinterpret_cast<void(*)()>(0x7e2fee);
	void(*const AIDebugPopToggle)() = reinterpret_cast<void(*)()>(0x7e3061);
	void(*const AIDebugPastResourceNeedToggle)() = reinterpret_cast<void(*)()>(0x7e30d4);
	void(*const AIDebugTimedStatsToggle)() = reinterpret_cast<void(*)()>(0x7e3147);
	void(*const AIDebugShowBasesToggle)() = reinterpret_cast<void(*)()>(0x7e31ba);
	void(*const AIDebugToggleBPText)() = reinterpret_cast<void(*)()>(0x7e76c9);
	void(*const uiShowAIDebugInfoPlan)(int) = reinterpret_cast<void(*)(int)>(0x7e31c6);
	void(*const uiShowAIDebugInfoPlacement)(int) = reinterpret_cast<void(*)(int)>(0x7e325c);
	void(*const uiShowAIDebugInfoProgression)(int) = reinterpret_cast<void(*)(int)>(0x7e32a3);
	void(*const uiShowAIDebugInfoKBUnit)(int) = reinterpret_cast<void(*)(int)>(0x7e32d3);
	void(*const uiShowAIDebugInfoBase)(int) = reinterpret_cast<void(*)(int)>(0x7e3329);
	void(*const uiShowAIDebugInfoArea)(int) = reinterpret_cast<void(*)(int)>(0x7e3353);
	void(*const uiShowAIDebugInfoAreaGroup)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7e339c);
	void(*const uiSetKBAttackRouteRender)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e677d);
	void(*const uiShowAIDebugInfoAttackRoute)(int) = reinterpret_cast<void(*)(int)>(0x7e682c);
	void(*const uiSetKBResourceRender)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e33ef);
	void(*const uiShowAIDebugInfoKBResource)(int) = reinterpret_cast<void(*)(int)>(0x7e34b3);
	void(*const uiSetKBArmyRender)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e34f5);
	void(*const uiShowAIDebugInfoKBArmy)(int) = reinterpret_cast<void(*)(int)>(0x7e3568);
	void(*const uiShowAIDebugInfoKBUnitPick)(int) = reinterpret_cast<void(*)(int)>(0x7e35aa);
	void(*const uiShowAIDebugInfoEscrow)(int) = reinterpret_cast<void(*)(int)>(0x7e35d4);
	void(*const uiSetBuildingPlacementRender)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e31f6);
	void(*const uiChatScrollBack)(int) = reinterpret_cast<void(*)(int)>(0x7e35fe);
	void(*const uiChatScrollForward)(int) = reinterpret_cast<void(*)(int)>(0x7e3644);
	void(*const uiChatDisplayModeToggle)() = reinterpret_cast<void(*)()>(0x7e3689);
	void(*const uiChatDisplayModeToRecent)() = reinterpret_cast<void(*)()>(0x7e36a1);
	void(*const uiChatDisplayModeToHistory)() = reinterpret_cast<void(*)()>(0x7e36b9);
	void(*const uiClearChat)(bool) = reinterpret_cast<void(*)(bool)>(0x7e36d1);
	void(*const uiAddChatNotification)(int, int, int, int) = reinterpret_cast<void(*)(int, int, int, int)>(0x7e36ee);
	void(*const uiSetHCNotifyText)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7e376d);
	void(*const uiShowChatWindow)() = reinterpret_cast<void(*)()>(0x512be7);
	void(*const uiReleaseDownKeys)() = reinterpret_cast<void(*)()>(0x7e37e3);
	void(*const uiSpewDownKeys)() = reinterpret_cast<void(*)()>(0x7e37fb);
	void(*const uiShowVoteDialog)() = reinterpret_cast<void(*)()>(0x7e3813);
	void(*const uiSendIngameChat)() = reinterpret_cast<void(*)()>(0x7e3848);
	void(*const uiPoliticianUI)(int, int, bool) = reinterpret_cast<void(*)(int, int, bool)>(0x7e686e);
	void(*const uiPoliticianUIInSelected)(string) = reinterpret_cast<void(*)(string)>(0x7e7ec1);
	void(*const uiConsulateUI)(int, int) = reinterpret_cast<void(*)(int, int)>(0x7e6a36);
	void(*const uiConsulateUIInSelected)() = reinterpret_cast<void(*)()>(0x7e6b26);
	void(*const enterAttackMoveMode)() = reinterpret_cast<void(*)()>(0x7e6c5e);
	void(*const uiShowObjectivesDialog)() = reinterpret_cast<void(*)()>(0x7e38e9);
	void(*const uiExpireCurrentObjectiveNotification)(bool) = reinterpret_cast<void(*)(bool)>(0x7e391e);
	void(*const uiPlaceTradeRouteWaypoint)() = reinterpret_cast<void(*)()>(0x7e38a1);
	void(*const uiRemoveTradeRouteWaypoint)() = reinterpret_cast<void(*)()>(0x7e38c5);
	void(*const uiSelectTransportUnit)() = reinterpret_cast<void(*)()>(0x7e3942);
	void(*const uiFindResourceGatherers)(string) = reinterpret_cast<void(*)(string)>(0x7e7d38);
	void(*const uiFindGatherersNotGathering)() = reinterpret_cast<void(*)()>(0x7e7dae);
	void(*const uiFindDancers)() = reinterpret_cast<void(*)()>(0x7e7d9e);
	void(*const uiSelectFirepit)() = reinterpret_cast<void(*)()>(0x7e0bf6);
	void(*const uiFindAlliedNatives)() = reinterpret_cast<void(*)()>(0x7e7dbe);
	void(*const uiVPAccelClick)(int) = reinterpret_cast<void(*)(int)>(0x7e6cb8);
	void(*const incrementUSP2SelectedUnitStack)() = reinterpret_cast<void(*)()>(0x7e6d5a);
	void(*const decrementUSP2SelectedUnitStack)() = reinterpret_cast<void(*)()>(0x7e6da1);
	void(*const uiSetCameraStartLoc)() = reinterpret_cast<void(*)()>(0x7e192e);
	void(*const uiShowCameraStartLoc)() = reinterpret_cast<void(*)()>(0x7e19b6);
	void(*const uiDeleteCameraStartLoc)() = reinterpret_cast<void(*)()>(0x7e19ce);
	void(*const uiCameraScroll)(bool, float, float) = reinterpret_cast<void(*)(bool, float, float)>(0x7e3a43);
	void(*const uiCameraControl)(float, float) = reinterpret_cast<void(*)(float, float)>(0x7e3a63);
	void(*const uiMapPointerControl)(float, float, bool) = reinterpret_cast<void(*)(float, float, bool)>(0x7e3bec);
	void(*const uiMapPointerGoto)(bool) = reinterpret_cast<void(*)(bool)>(0x7e3ac0);
	void(*const uiCircleSelect)(bool, bool, bool) = reinterpret_cast<void(*)(bool, bool, bool)>(0x7e3e66);
	void(*const uiCircleSelectResize)(float, float) = reinterpret_cast<void(*)(float, float)>(0x7e3e9e);
	void(*const uiCenterPointer)() = reinterpret_cast<void(*)()>(0x7e3eba);
	void(*const uiForceShift)(bool) = reinterpret_cast<void(*)(bool)>(0x7e3f00);
	void(*const uiScreenSelect)(bool) = reinterpret_cast<void(*)(bool)>(0x7e3f1f);
	void(*const uiResetScreenSelect)() = reinterpret_cast<void(*)()>(0x7e3f36);
	void(*const uiFindCrowd)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7e3f46);
	void(*const uiResetFindCrowd)() = reinterpret_cast<void(*)()>(0x7e3f96);
	void(*const uiShowStatPanel)() = reinterpret_cast<void(*)()>(0x7e39cd);
	void(*const uiShowDetailedHelp)() = reinterpret_cast<void(*)()>(0x7e3956);
	void(*const uiShowCommandPanel)() = reinterpret_cast<void(*)()>(0x7e3a1b);
	void(*const uiMinimizeStats)() = reinterpret_cast<void(*)()>(0x7e397e);
	void(*const uiMoveAllMilitaryAtPointer)() = reinterpret_cast<void(*)()>(0x7e3fa6);
	void(*const sendAttackSentence)(int, int, int, int, float, float) = reinterpret_cast<void(*)(int, int, int, int, float, float)>(0x6f1e6e);
	void(*const sendDefendSentence)(int, int, float, float) = reinterpret_cast<void(*)(int, int, float, float)>(0x6f1bab);
	void(*const sendTributeSentence)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x6f1fee);
	void(*const sendPromptType)(int, int) = reinterpret_cast<void(*)(int, int)>(0x6f0ff6);
	void(*const startRandomGame)(bool) = reinterpret_cast<void(*)(bool)>(0x6f041c);
	void(*const startRandomGame2)(string, int, int, string, bool, int, int, int, bool) = reinterpret_cast<void(*)(string, int, int, string, bool, int, int, int, bool)>(0x6f10fc);
	void(*const startRandomGameMapCode)(string) = reinterpret_cast<void(*)(string)>(0x6f1340);
	void(*const startRandomGameAgeAndMapCode)(int, bool, string) = reinterpret_cast<void(*)(int, bool, string)>(0x6f17f4);
	void(*const restartCurrentGame)() = reinterpret_cast<void(*)()>(0x6f044e);
	void(*const leaveGame)(int, int) = reinterpret_cast<void(*)(int, int)>(0x5683f6);
	void(*const handlePostGame)() = reinterpret_cast<void(*)()>(0x6f046d);
	void(*const showGameFromPostGame)() = reinterpret_cast<void(*)()>(0x6f05b1);
	void(*const postGamePlayAgain)() = reinterpret_cast<void(*)()>(0x6f062a);
	void(*const minimapZoomDelta)(float) = reinterpret_cast<void(*)(float)>(0x6f068b);
	void(*const minimapZoom)(float) = reinterpret_cast<void(*)(float)>(0x6f06a1);
	void(*const minimapRotateMode)(int) = reinterpret_cast<void(*)(int)>(0x6f184a);
	void(*const chat)(string, int) = reinterpret_cast<void(*)(string, int)>(0x6f0652);
	void(*const uiSpecialPowerAtPointer)() = reinterpret_cast<void(*)()>(0x6f06b7);
	void(*const uiToggleGame)() = reinterpret_cast<void(*)()>(0x6f040c);
	void(*const uiZoomToMinimapEvent)() = reinterpret_cast<void(*)()>(0x6f06c7);
	void(*const uiRefreshEditorMenu)() = reinterpret_cast<void(*)()>(0x6f07bf);
	void(*const uiShowTributeDialog)() = reinterpret_cast<void(*)()>(0x6f06ff);
	void(*const uiHideTributeDialog)() = reinterpret_cast<void(*)()>(0x6f0739);
	void(*const uiShowPlayerSummaryDialog)() = reinterpret_cast<void(*)()>(0x6f075f);
	void(*const uiHidePlayerSummaryDialog)() = reinterpret_cast<void(*)()>(0x6f0799);
	void(*const uiNewScenario)() = reinterpret_cast<void(*)()>(0x6f084e);
	void(*const sunIncreaseInclination)(int) = reinterpret_cast<void(*)(int)>(0x6f033c);
	void(*const sunDecreaseInclination)(int) = reinterpret_cast<void(*)(int)>(0x6f0370);
	void(*const sunIncreaseRotation)(int) = reinterpret_cast<void(*)(int)>(0x6f03a4);
	void(*const sunDecreaseRotation)(int) = reinterpret_cast<void(*)(int)>(0x6f03d8);
	void(*const setSunPosition)(float, float, bool) = reinterpret_cast<void(*)(float, float, bool)>(0x6f10ab);
	void(*const abortCinematic)() = reinterpret_cast<void(*)()>(0x6f1cd6);
	void(*const scoreUpdate)() = reinterpret_cast<void(*)()>(0x6f08b3);
	void(*const toggleScore)() = reinterpret_cast<void(*)()>(0x6f08c8);
	void(*const toggleTime)() = reinterpret_cast<void(*)()>(0x6f095d);
	void(*const toggleDebugTime)() = reinterpret_cast<void(*)()>(0x6f0a8f);
	void(*const doSPSetup)(bool) = reinterpret_cast<void(*)(bool)>(0x6f0bb1);
	void(*const doMPSetup)(bool) = reinterpret_cast<void(*)(bool)>(0x6f0caa);
	void(*const exitMPSetupSubScreen)() = reinterpret_cast<void(*)()>(0x6f1921);
	void(*const enterRecordGameMode)(string) = reinterpret_cast<void(*)(string)>(0x6f0dcd);
	void(*const enterGCGameMode)(string) = reinterpret_cast<void(*)(string)>(0x6f1978);
	void(*const showCampaignDialog)(string, string) = reinterpret_cast<void(*)(string, string)>(0x6f0e7a);
	void(*const playerResign)() = reinterpret_cast<void(*)()>(0x6f0ec3);
	void(*const showGameMenu)() = reinterpret_cast<void(*)()>(0x56b16c);
	void(*const hideGameMenu)(bool) = reinterpret_cast<void(*)(bool)>(0x6f0edb);
	void(*const uiSaveCampaignGameBrowser)() = reinterpret_cast<void(*)()>(0x6f1ad7);
	void(*const uiInitOptionsScreenProfileEditDialog)() = reinterpret_cast<void(*)()>(0x6f0f4f);
	void(*const uiBMultiplayerSave)() = reinterpret_cast<void(*)()>(0x6f0f0f);
	void(*const dropToMainMenu)() = reinterpret_cast<void(*)()>(0x6f0f83);
	bool(*const modelLoad)(string) = reinterpret_cast<bool(*)(string)>(0x4474c9);
	void(*const changeCliffType)(string) = reinterpret_cast<void(*)(string)>(0x6f1d3d);
	void(*const uiCommandPanelControl)(bool) = reinterpret_cast<void(*)(bool)>(0x6f102a);
	void(*const uiCommandPanelMove)(float, float) = reinterpret_cast<void(*)(float, float)>(0x6f1041);
	void(*const uiCommandPanelExecute)(bool) = reinterpret_cast<void(*)(bool)>(0x6f105d);
	void(*const winScenario)() = reinterpret_cast<void(*)()>(0x6f0fdd);
	void(*const xsDisableRule)(string) = reinterpret_cast<void(*)(string)>(0xa5d578);
	void(*const xsDisableSelf)() = reinterpret_cast<void(*)()>(0x42f897);
	void(*const xsEnableRule)(string) = reinterpret_cast<void(*)(string)>(0x42f856);
	bool(*const xsIsRuleEnabled)(string) = reinterpret_cast<bool(*)(string)>(0xa5d26c);
	void(*const xsSetRulePriority)(string, int) = reinterpret_cast<void(*)(string, int)>(0xa5d27b);
	void(*const xsSetRulePrioritySelf)(int) = reinterpret_cast<void(*)(int)>(0xa5d590);
	void(*const xsSetRuleMinInterval)(string, int) = reinterpret_cast<void(*)(string, int)>(0x42fd16);
	void(*const xsSetRuleMinIntervalSelf)(int) = reinterpret_cast<void(*)(int)>(0x42e5d7);
	void(*const xsSetRuleMaxInterval)(string, int) = reinterpret_cast<void(*)(string, int)>(0x637c56);
	void(*const xsSetRuleMaxIntervalSelf)(int) = reinterpret_cast<void(*)(int)>(0x427fcc);
	void(*const xsEnableRuleGroup)(string) = reinterpret_cast<void(*)(string)>(0xa5d5be);
	void(*const xsDisableRuleGroup)(string) = reinterpret_cast<void(*)(string)>(0xa5d5a6);
	void(*const xsIsRuleGroupEnabled)(string) = reinterpret_cast<void(*)(string)>(0xa5d29b);
	float(*const xsVectorGetX)(vector) = reinterpret_cast<float(*)(vector)>(0xa5d2aa);
	float(*const xsVectorGetY)(vector) = reinterpret_cast<float(*)(vector)>(0xa5d2bc);
	float(*const xsVectorGetZ)(vector) = reinterpret_cast<float(*)(vector)>(0xa5d2cf);
	vector(*const xsVectorSetX)(vector, vector, float) = reinterpret_cast<vector(*)(vector, vector, float)>(0xa5d5d6);
	vector(*const xsVectorSetY)(vector, vector, float) = reinterpret_cast<vector(*)(vector, vector, float)>(0xa5d625);
	vector(*const xsVectorSetZ)(vector, vector, float) = reinterpret_cast<vector(*)(vector, vector, float)>(0xa5d674);
	vector(*const xsVectorSet)(vector, float, float, float) = reinterpret_cast<vector(*)(vector, float, float, float)>(0xa5d6be);
	float(*const xsVectorLength)(vector) = reinterpret_cast<float(*)(vector)>(0xa5d6f5);
	vector(*const xsVectorNormalize)(vector, vector) = reinterpret_cast<vector(*)(vector, vector)>(0xa5d725);
	int(*const xsArrayCreateInt)(int, int, string) = reinterpret_cast<int(*)(int, int, string)>(0xa5d2e2);
	bool(*const xsArraySetInt)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0xa5d316);
	int(*const xsArrayGetInt)(int, int) = reinterpret_cast<int(*)(int, int)>(0xa5d32f);
	int(*const xsArrayCreateFloat)(int, float, string) = reinterpret_cast<int(*)(int, float, string)>(0xa5d343);
	bool(*const xsArraySetFloat)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0xa5d377);
	float(*const xsArrayGetFloat)(int, int) = reinterpret_cast<float(*)(int, int)>(0xa5d390);
	int(*const xsArrayCreateBool)(int, bool, string) = reinterpret_cast<int(*)(int, bool, string)>(0xa5d3a4);
	bool(*const xsArraySetBool)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0xa5d3d8);
	bool(*const xsArrayGetBool)(int, int) = reinterpret_cast<bool(*)(int, int)>(0xa5d3f1);
	int(*const xsArrayCreateString)(int, string, string) = reinterpret_cast<int(*)(int, string, string)>(0xa5d405);
	bool(*const xsArraySetString)(int, int, string) = reinterpret_cast<bool(*)(int, int, string)>(0xa5d450);
	string(*const xsArrayGetString)(int, int) = reinterpret_cast<string(*)(int, int)>(0xa5d484);
	int(*const xsArrayCreateVector)(int, vector, string) = reinterpret_cast<int(*)(int, vector, string)>(0xa5d498);
	bool(*const xsArraySetVector)(int, int, vector) = reinterpret_cast<bool(*)(int, int, vector)>(0xa5d4cc);
	vector(*const xsArrayGetVector)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0xa5d4e5);
	int(*const xsArrayGetSize)(int) = reinterpret_cast<int(*)(int)>(0xa5d502);
	void(*const xsDumpArrays)() = reinterpret_cast<void(*)()>(0xa5d511);
	int(*const xsGetContextPlayer)() = reinterpret_cast<int(*)()>(0xa5d7c4);
	void(*const xsSetContextPlayer)(int) = reinterpret_cast<void(*)(int)>(0xa5d7ca);
	int(*const xsGetTime)() = reinterpret_cast<int(*)()>(0xa5d7d4);
	bool(*const xsAddRuntimeEvent)(string, string, int) = reinterpret_cast<bool(*)(string, string, int)>(0xa5d51a);
	int(*const xsGetFunctionID)(string) = reinterpret_cast<int(*)(string)>(0xa5d569);
	void(*const rmEchoWarning)(string) = reinterpret_cast<void(*)(string)>(0x9017e5);
	void(*const rmEchoError)(string) = reinterpret_cast<void(*)(string)>(0x9018eb);
	float(*const rmRandFloat)(float, float) = reinterpret_cast<float(*)(float, float)>(0x90b66c);
	int(*const rmRandInt)(int, int) = reinterpret_cast<int(*)(int, int)>(0x90eeac);
	bool(*const rmGetNomadStart)() = reinterpret_cast<bool(*)()>(0x90b683);
	bool(*const rmGetIsFFA)() = reinterpret_cast<bool(*)()>(0x90b69c);
	bool(*const rmGetIsRelicCapture)() = reinterpret_cast<bool(*)()>(0x90b6b5);
	bool(*const rmGetIsKOTH)() = reinterpret_cast<bool(*)()>(0x90b6ce);
	bool(*const rmSetMapSize)(float, float) = reinterpret_cast<bool(*)(float, float)>(0x90b6e7);
	int(*const rmGetMapXSize)() = reinterpret_cast<int(*)()>(0x90b709);
	int(*const rmGetMapZSize)() = reinterpret_cast<int(*)()>(0x90b71d);
	void(*const rmSetSeaLevel)(float) = reinterpret_cast<void(*)(float)>(0x90bee9);
	float(*const rmGetSeaLevel)() = reinterpret_cast<float(*)()>(0x90c195);
	bool(*const rmSetSeaType)(string) = reinterpret_cast<bool(*)(string)>(0x90bf10);
	bool(*const rmSetMapElevationParameters)(int, float, int, float, float) = reinterpret_cast<bool(*)(int, float, int, float, float)>(0x90bf3a);
	bool(*const rmSetBaseTerrainMix)(string) = reinterpret_cast<bool(*)(string)>(0x90bf7f);
	bool(*const rmAddMapTerrainByHeightInfo)(string, float, float, float) = reinterpret_cast<bool(*)(string, float, float, float)>(0x90bfa9);
	bool(*const rmAddMapTerrainByAngleInfo)(string, float, float, float) = reinterpret_cast<bool(*)(string, float, float, float)>(0x90bfff);
	bool(*const rmSetMapElevationHeightBlend)(int) = reinterpret_cast<bool(*)(int)>(0x90c055);
	bool(*const rmPlaceMapClusters)(string, string) = reinterpret_cast<bool(*)(string, string)>(0x90c07e);
	bool(*const rmSetMapClusteringPlacementParams)(float, float, float, int) = reinterpret_cast<bool(*)(float, float, float, int)>(0x90c0e3);
	bool(*const rmSetMapClusteringObjectParams)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x90c124);
	bool(*const rmSetMapClusteringNoiseParams)(float, int, float) = reinterpret_cast<bool(*)(float, int, float)>(0x90c15b);
	int(*const rmAreaFractionToTiles)(float) = reinterpret_cast<int(*)(float)>(0x90c38e);
	float(*const rmAreaTilesToFraction)(int) = reinterpret_cast<float(*)(int)>(0x90c3b8);
	int(*const rmXFractionToTiles)(float) = reinterpret_cast<int(*)(float)>(0x90c3e6);
	float(*const rmXTilesToFraction)(int) = reinterpret_cast<float(*)(int)>(0x90c410);
	int(*const rmZFractionToTiles)(float) = reinterpret_cast<int(*)(float)>(0x90c43e);
	float(*const rmZTilesToFraction)(int) = reinterpret_cast<float(*)(int)>(0x90c468);
	float(*const rmDegreesToRadians)(float) = reinterpret_cast<float(*)(float)>(0x90d640);
	int(*const rmMetersToTiles)(float) = reinterpret_cast<int(*)(float)>(0x90c496);
	float(*const rmXMetersToFraction)(float) = reinterpret_cast<float(*)(float)>(0x90c51c);
	float(*const rmZMetersToFraction)(float) = reinterpret_cast<float(*)(float)>(0x90c54a);
	float(*const rmXFractionToMeters)(float) = reinterpret_cast<float(*)(float)>(0x90c4c0);
	float(*const rmZFractionToMeters)(float) = reinterpret_cast<float(*)(float)>(0x90c4ee);
	int(*const rmCreateArea)(string, int) = reinterpret_cast<int(*)(string, int)>(0x90c1bc);
	bool(*const rmSetAreaSize)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90c1ec);
	bool(*const rmSetAreaEdgeFilling)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90c220);
	bool(*const rmSetAreaLocation)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90c5f9);
	bool(*const rmSetAreaLocPlayer)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90c62d);
	bool(*const rmSetAreaLocTeam)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90c65c);
	bool(*const rmBuildArea)(int) = reinterpret_cast<bool(*)(int)>(0x90c251);
	int(*const rmBuildAllAreas)() = reinterpret_cast<int(*)()>(0x90c27b);
	bool(*const rmSetAreaTerrainType)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90c6ba);
	bool(*const rmSetAreaMix)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90c6e9);
	bool(*const rmPaintAreaTerrain)(int) = reinterpret_cast<bool(*)(int)>(0x90c29e);
	bool(*const rmPaintAreaTerrainByHeight)(int, string, float, float, float) = reinterpret_cast<bool(*)(int, string, float, float, float)>(0x90c2c8);
	bool(*const rmPaintAreaTerrainByAngle)(int, string, float, float, float) = reinterpret_cast<bool(*)(int, string, float, float, float)>(0x90c32b);
	bool(*const rmSetAreaBaseHeight)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90cd38);
	bool(*const rmSetAreaWarnFailure)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90cd67);
	bool(*const rmSetAreaForestType)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90c718);
	bool(*const rmSetAreaForestDensity)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90c747);
	bool(*const rmSetAreaForestClumpiness)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90c776);
	bool(*const rmSetAreaForestUnderbrush)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90c7a5);
	bool(*const rmSetAreaWaterType)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90c7d4);
	vector(*const rmGetAreaClosestPoint)(vector, int, vector, float, int) = reinterpret_cast<vector(*)(vector, int, vector, float, int)>(0x90c803);
	bool(*const rmSetAreaCliffType)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90c863);
	bool(*const rmSetAreaCliffPainting)(int, bool, bool, bool, float, bool) = reinterpret_cast<bool(*)(int, bool, bool, bool, float, bool)>(0x90c892);
	bool(*const rmSetAreaCliffEdge)(int, int, float, float, float, int) = reinterpret_cast<bool(*)(int, int, float, float, float, int)>(0x90c8d5);
	bool(*const rmSetAreaCliffHeight)(int, float, float, float) = reinterpret_cast<bool(*)(int, float, float, float)>(0x90c918);
	bool(*const rmAddAreaCliffEdgeAvoidClass)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x90c951);
	int(*const rmRiverCreate)(int, string, int, int, int, int) = reinterpret_cast<int(*)(int, string, int, int, int, int)>(0x90c9f7);
	bool(*const rmRiverSetConnections)(int, float, float, float, float) = reinterpret_cast<bool(*)(int, float, float, float, float)>(0x90ca3b);
	bool(*const rmRiverConnectRiver)(int, int, float, float, float) = reinterpret_cast<bool(*)(int, int, float, float, float)>(0x90ca79);
	bool(*const rmRiverAddWaypoint)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90cab7);
	bool(*const rmRiverSetBankNoiseParams)(int, float, int, float, float, float, float) = reinterpret_cast<bool(*)(int, float, int, float, float, float, float)>(0x90caeb);
	bool(*const rmRiverSetShallowRadius)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90cb33);
	bool(*const rmRiverAddShallow)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90cb62);
	bool(*const rmRiverAddShallows)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x90cb91);
	bool(*const rmRiverAvoid)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x90cbc5);
	bool(*const rmRiverBuild)(int) = reinterpret_cast<bool(*)(int)>(0x90cbf9);
	bool(*const rmRiverReveal)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90cc23);
	bool(*const rmSetRiverFoundationParams)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90cc52);
	bool(*const rmSetWorldCircleConstraint)(bool) = reinterpret_cast<bool(*)(bool)>(0x90cc73);
	bool(*const rmSetAreaObeyWorldCircleConstraint)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90cc9f);
	bool(*const rmAddAreaTerrainLayer)(int, string, float, float) = reinterpret_cast<bool(*)(int, string, float, float)>(0x90ccd0);
	bool(*const rmSetAreaTerrainLayerVariance)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90cd09);
	bool(*const rmSetAreaMinBlobs)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90cd96);
	bool(*const rmSetAreaMaxBlobs)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90cdc5);
	bool(*const rmSetAreaMinBlobDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90cdf4);
	bool(*const rmSetAreaMaxBlobDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90ce23);
	bool(*const rmSetAreaCoherence)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90ce52);
	bool(*const rmSetAreaSmoothDistance)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90ce81);
	bool(*const rmSetAreaHeightBlend)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90ceb0);
	int(*const rmAreaID)(string) = reinterpret_cast<int(*)(string)>(0x90c578);
	bool(*const rmAddAreaInfluencePoint)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90cedf);
	bool(*const rmAddAreaInfluenceSegment)(int, float, float, float, float) = reinterpret_cast<bool(*)(int, float, float, float, float)>(0x90cf13);
	bool(*const rmAddAreaRemoveType)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90cf51);
	bool(*const rmAddAreaTerrainReplacement)(int, string, string) = reinterpret_cast<bool(*)(int, string, string)>(0x90cf80);
	bool(*const rmSetAreaElevationType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90e853);
	bool(*const rmSetAreaElevationMinFrequency)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e882);
	bool(*const rmSetAreaElevationOctaves)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90e8b1);
	bool(*const rmSetAreaElevationPersistence)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e8e0);
	bool(*const rmSetAreaElevationVariation)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e90f);
	bool(*const rmSetAreaElevationEdgeFalloffDist)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e96d);
	bool(*const rmSetAreaElevationNoiseBias)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e93e);
	bool(*const rmSetAreaReveal)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90e99c);
	void(*const rmSetGlobalSnow)(float) = reinterpret_cast<void(*)(float)>(0x90e9cb);
	void(*const rmSetGlobalRain)(float) = reinterpret_cast<void(*)(float)>(0x90ea19);
	void(*const rmSetGlobalStormLength)(int, int) = reinterpret_cast<void(*)(int, int)>(0x90ea67);
	void(*const rmSetWindMagnitude)(float) = reinterpret_cast<void(*)(float)>(0x90eac9);
	void(*const rmTerrainInitialize)(string, float) = reinterpret_cast<void(*)(string, float)>(0x90b731);
	void(*const rmFillMapCorners)() = reinterpret_cast<void(*)()>(0x90b758);
	void(*const rmDoLightingFade)(string, float) = reinterpret_cast<void(*)(string, float)>(0x90b7b6);
	void(*const rmDoLightingEffect)(string, float, float, float) = reinterpret_cast<void(*)(string, float, float, float)>(0x90b7fa);
	void(*const rmSetGaiaCiv)(int) = reinterpret_cast<void(*)(int)>(0x90b848);
	bool(*const rmAllocateSubCivs)(int) = reinterpret_cast<bool(*)(int)>(0x90b86f);
	bool(*const rmSetSubCiv)(int, string, bool) = reinterpret_cast<bool(*)(int, string, bool)>(0x90b896);
	int(*const rmGetCivID)(string) = reinterpret_cast<int(*)(string)>(0x90b953);
	int(*const rmAddMerc)(string, float, float, float, float, bool) = reinterpret_cast<int(*)(string, float, float, float, float, bool)>(0x90b969);
	bool(*const rmSetPlayerLocation)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90bb8e);
	void(*const rmSetPlayerPlacementArea)(float, float, float, float) = reinterpret_cast<void(*)(float, float, float, float)>(0x90b9c4);
	void(*const rmSetTeamSpacingModifier)(float) = reinterpret_cast<void(*)(float)>(0x90b9fb);
	void(*const rmSetPlacementTeam)(int) = reinterpret_cast<void(*)(int)>(0x90ba22);
	void(*const rmSetPlacementSection)(float, float) = reinterpret_cast<void(*)(float, float)>(0x90ba49);
	bool(*const rmPlacePlayersCircular)(float, float, float) = reinterpret_cast<bool(*)(float, float, float)>(0x90ba76);
	bool(*const rmPlacePlayersSquare)(float, float, float) = reinterpret_cast<bool(*)(float, float, float)>(0x90baaa);
	bool(*const rmPlacePlayersLine)(float, float, float, float, float, float) = reinterpret_cast<bool(*)(float, float, float, float, float, float)>(0x90bade);
	bool(*const rmPlacePlayersRiver)(int, float, float, float) = reinterpret_cast<bool(*)(int, float, float, float)>(0x90bb21);
	bool(*const rmPlacePlayer)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90bb5a);
	bool(*const rmSetPlayerArea)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90c68b);
	float(*const rmPlayerLocXFraction)(int) = reinterpret_cast<float(*)(int)>(0x90bd66);
	float(*const rmPlayerLocZFraction)(int) = reinterpret_cast<float(*)(int)>(0x90bd94);
	int(*const rmAddFairLoc)(string, bool, bool, float, float, float, float, bool, bool) = reinterpret_cast<int(*)(string, bool, bool, float, float, float, float, bool, bool)>(0x90bdc2);
	bool(*const rmPlaceFairLocs)(int) = reinterpret_cast<bool(*)(int)>(0x90be15);
	void(*const rmResetFairLocs)() = reinterpret_cast<void(*)()>(0x90be38);
	int(*const rmGetNumberFairLocs)(int) = reinterpret_cast<int(*)(int)>(0x90be59);
	float(*const rmFairLocXFraction)(int, int) = reinterpret_cast<float(*)(int, int)>(0x90be83);
	float(*const rmFairLocZFraction)(int, int) = reinterpret_cast<float(*)(int, int)>(0x90beb6);
	bool(*const rmSetPlayerResource)(int, string, float) = reinterpret_cast<bool(*)(int, string, float)>(0x90bbc2);
	bool(*const rmAddPlayerResource)(int, string, float) = reinterpret_cast<bool(*)(int, string, float)>(0x90bbf6);
	bool(*const rmMultiplyPlayerResource)(int, string, float) = reinterpret_cast<bool(*)(int, string, float)>(0x90bc2a);
	string(*const rmGetPlayerName)(int) = reinterpret_cast<string(*)(int)>(0x90bc5e);
	int(*const rmGetPlayerTeam)(int) = reinterpret_cast<int(*)(int)>(0x90bc8f);
	int(*const rmGetPlayerCiv)(int) = reinterpret_cast<int(*)(int)>(0x90bcb9);
	int(*const rmGetPlayerCulture)(int) = reinterpret_cast<int(*)(int)>(0x90bce3);
	int(*const rmGetNumberPlayersOnTeam)(int) = reinterpret_cast<int(*)(int)>(0x90bd0d);
	bool(*const rmSetTeamArea)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90bd37);
	int(*const rmCreateBoxConstraint)(string, float, float, float, float, float) = reinterpret_cast<int(*)(string, float, float, float, float, float)>(0x90cfb4);
	int(*const rmCreatePieConstraint)(string, float, float, float, float, float, float, float) = reinterpret_cast<int(*)(string, float, float, float, float, float, float, float)>(0x90cff8);
	int(*const rmCreateAreaOverlapConstraint)(string, int) = reinterpret_cast<int(*)(string, int)>(0x90d046);
	int(*const rmCreateAreaConstraint)(string, int) = reinterpret_cast<int(*)(string, int)>(0x90d076);
	int(*const rmCreateAreaDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d0a6);
	int(*const rmCreateAreaMaxDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d1b4);
	int(*const rmCreateEdgeConstraint)(string, int) = reinterpret_cast<int(*)(string, int)>(0x90d1e9);
	int(*const rmCreateEdgeDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d219);
	int(*const rmCreateEdgeMaxDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d24e);
	int(*const rmCreateCliffEdgeConstraint)(string, int) = reinterpret_cast<int(*)(string, int)>(0x90d283);
	int(*const rmCreateCliffEdgeDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d2b3);
	int(*const rmCreateCliffEdgeMaxDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d2e8);
	int(*const rmCreateCliffRampConstraint)(string, int) = reinterpret_cast<int(*)(string, int)>(0x90d31d);
	int(*const rmCreateCliffRampDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d34d);
	int(*const rmCreateCliffRampMaxDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d382);
	int(*const rmCreateClassDistanceConstraint)(string, int, float) = reinterpret_cast<int(*)(string, int, float)>(0x90d3b7);
	int(*const rmCreateTypeDistanceConstraint)(string, string, float) = reinterpret_cast<int(*)(string, string, float)>(0x90d3ec);
	int(*const rmCreateTerrainDistanceConstraint)(string, string, bool, float) = reinterpret_cast<int(*)(string, string, bool, float)>(0x90d421);
	int(*const rmCreateTerrainMaxDistanceConstraint)(string, string, bool, float) = reinterpret_cast<int(*)(string, string, bool, float)>(0x90d45b);
	int(*const rmCreateCornerConstraint)(string, int, bool) = reinterpret_cast<int(*)(string, int, bool)>(0x90d495);
	int(*const rmCreateTradeRouteDistanceConstraint)(string, float) = reinterpret_cast<int(*)(string, float)>(0x90d4ca);
	bool(*const rmAddAreaConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90d52a);
	bool(*const rmCreateHCGPConstraint)(string, float) = reinterpret_cast<bool(*)(string, float)>(0x90d0db);
	bool(*const rmCreateHCGPSelfConstraint)(string, int, float) = reinterpret_cast<bool(*)(string, int, float)>(0x90d10f);
	bool(*const rmCreateHCGPAllyConstraint)(string, int, float) = reinterpret_cast<bool(*)(string, int, float)>(0x90d17d);
	bool(*const rmCreateHCGPEnemyConstraint)(string, int, float) = reinterpret_cast<bool(*)(string, int, float)>(0x90d146);
	int(*const rmCreateMaxHeightConstraint)(string, float) = reinterpret_cast<int(*)(string, float)>(0x90d4fa);
	bool(*const rmAddFairLocConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90d559);
	bool(*const rmAddObjectDefConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90d588);
	int(*const rmDefineClass)(string) = reinterpret_cast<int(*)(string)>(0x90d5b7);
	bool(*const rmAddAreaToClass)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90d5e2);
	bool(*const rmAddObjectDefToClass)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90d611);
	int(*const rmClassID)(string) = reinterpret_cast<int(*)(string)>(0x90c5a3);
	int(*const rmConstraintID)(string) = reinterpret_cast<int(*)(string)>(0x90c5ce);
	int(*const rmCreateObjectDef)(string) = reinterpret_cast<int(*)(string)>(0x90d64b);
	int(*const rmCreateStartingUnitsObjectDef)(float) = reinterpret_cast<int(*)(float)>(0x90d676);
	bool(*const rmSetObjectDefMinDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90d6b8);
	bool(*const rmSetObjectDefMaxDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90d6e7);
	bool(*const rmSetObjectDefGarrisonSecondaryUnits)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90d716);
	bool(*const rmSetObjectDefGarrisonStartingUnits)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90d745);
	bool(*const rmSetObjectDefCreateHerd)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90d774);
	bool(*const rmSetObjectDefHerdAngle)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90d7a3);
	bool(*const rmSetObjectDefAllowOverlap)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90d7d2);
	bool(*const rmSetObjectDefForceFullRotation)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90d801);
	bool(*const rmAddObjectDefItem)(int, string, int, float) = reinterpret_cast<bool(*)(int, string, int, float)>(0x90d830);
	bool(*const rmAddObjectDefItemByTypeID)(int, int, int, float) = reinterpret_cast<bool(*)(int, int, int, float)>(0x90d869);
	int(*const rmPlaceObjectDefAtLoc)(int, int, float, float, int) = reinterpret_cast<int(*)(int, int, float, float, int)>(0x90d8a2);
	int(*const rmPlaceObjectDefAtPoint)(int, int, vector, int) = reinterpret_cast<int(*)(int, int, vector, int)>(0x90d8e0);
	int(*const rmSetObjectDefTradeRouteID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x90d9e0);
	int(*const rmPlaceObjectDefPerPlayer)(int, bool, int) = reinterpret_cast<int(*)(int, bool, int)>(0x90da0f);
	int(*const rmPlaceObjectDefAtAreaLoc)(int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int)>(0x90dab5);
	int(*const rmPlaceObjectDefInArea)(int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int)>(0x90daee);
	int(*const rmPlaceObjectDefAtRandomAreaOfClass)(int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int)>(0x90da43);
	int(*const rmPlaceObjectDefInRandomAreaOfClass)(int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int)>(0x90da7c);
	int(*const rmCreateConnection)(string) = reinterpret_cast<int(*)(string)>(0x90db27);
	int(*const rmSetConnectionType)(int, int, bool, float) = reinterpret_cast<int(*)(int, int, bool, float)>(0x90db52);
	bool(*const rmAddConnectionArea)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90db8b);
	bool(*const rmSetConnectionPositionVariance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90dbba);
	bool(*const rmSetConnectionWidth)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90dbe9);
	bool(*const rmSetConnectionBaseHeight)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90dc1d);
	bool(*const rmSetConnectionCoherence)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90dc4c);
	bool(*const rmSetConnectionWarnFailure)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x90dc7b);
	bool(*const rmSetConnectionHeightBlend)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90dcaa);
	bool(*const rmSetConnectionSmoothDistance)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90dcd9);
	bool(*const rmAddConnectionTerrainReplacement)(int, string, string) = reinterpret_cast<bool(*)(int, string, string)>(0x90dd08);
	bool(*const rmSetConnectionTerrainCost)(int, string, float) = reinterpret_cast<bool(*)(int, string, float)>(0x90dd3c);
	bool(*const rmSetConnectionBaseTerrainCost)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90dd70);
	bool(*const rmBuildConnection)(int) = reinterpret_cast<bool(*)(int)>(0x90de5b);
	bool(*const rmAddConnectionToClass)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90dd9f);
	bool(*const rmAddConnectionConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90ddce);
	bool(*const rmAddConnectionStartConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90ddfd);
	bool(*const rmAddConnectionEndConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90de2c);
	void(*const rmSetStatusText)(string, float) = reinterpret_cast<void(*)(string, float)>(0x90de85);
	float(*const sqrt)(float) = reinterpret_cast<float(*)(float)>(0x90dee8);
	void(*const rmSetVPFile)(string) = reinterpret_cast<void(*)(string)>(0x90deef);
	int(*const rmCreateTrigger)(string) = reinterpret_cast<int(*)(string)>(0x90df16);
	bool(*const rmSwitchToTrigger)(int) = reinterpret_cast<bool(*)(int)>(0x90df73);
	int(*const rmTriggerID)(string) = reinterpret_cast<int(*)(string)>(0x90dfb0);
	int(*const rmSetTriggerPriority)(int) = reinterpret_cast<int(*)(int)>(0x90e008);
	int(*const rmSetTriggerActive)(bool) = reinterpret_cast<int(*)(bool)>(0x90e029);
	int(*const rmSetTriggerRunImmediately)(bool) = reinterpret_cast<int(*)(bool)>(0x90e049);
	int(*const rmSetTriggerLoop)(bool) = reinterpret_cast<int(*)(bool)>(0x90e06a);
	int(*const rmAddTriggerCondition)(string) = reinterpret_cast<int(*)(string)>(0x90e08b);
	bool(*const rmSetTriggerConditionParam)(string, string, bool) = reinterpret_cast<bool(*)(string, string, bool)>(0x90eede);
	bool(*const rmSetTriggerConditionParamInt)(string, int, bool) = reinterpret_cast<bool(*)(string, int, bool)>(0x90ef8f);
	bool(*const rmSetTriggerConditionParamFloat)(string, float, bool) = reinterpret_cast<bool(*)(string, float, bool)>(0x90efb8);
	bool(*const rmSetTriggerConditionParamArmy)(string, int, int, bool) = reinterpret_cast<bool(*)(string, int, int, bool)>(0x90efe6);
	bool(*const rmAddTriggerEffect)(string) = reinterpret_cast<bool(*)(string)>(0x90e127);
	int(*const rmSetTriggerEffectParam)(string, string, bool) = reinterpret_cast<int(*)(string, string, bool)>(0x90f01c);
	bool(*const rmSetTriggerEffectParamInt)(string, int, bool) = reinterpret_cast<bool(*)(string, int, bool)>(0x90f0cd);
	bool(*const rmSetTriggerEffectParamFloat)(string, float, bool) = reinterpret_cast<bool(*)(string, float, bool)>(0x90f0f6);
	bool(*const rmSetTriggerEffectParamArmy)(string, int, int, bool) = reinterpret_cast<bool(*)(string, int, int, bool)>(0x90f124);
	int(*const rmCreateArmy)(int, string) = reinterpret_cast<int(*)(int, string)>(0x90e1c3);
	bool(*const rmAddUnitsToArmy)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x90e1ff);
	int(*const rmGetNumberUnitsPlaced)(int) = reinterpret_cast<int(*)(int)>(0x90e233);
	int(*const rmGetUnitPlaced)(int, int) = reinterpret_cast<int(*)(int, int)>(0x90e25d);
	int(*const rmGetUnitPlacedOfPlayer)(int, int) = reinterpret_cast<int(*)(int, int)>(0x90e28c);
	bool(*const rmDefineConstant)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x90e2bb);
	void(*const rmSetIgnoreForceToGaia)(bool) = reinterpret_cast<void(*)(bool)>(0x90e35f);
	int(*const rmCreateGrouping)(string, string) = reinterpret_cast<int(*)(string, string)>(0x90e386);
	bool(*const rmAddGroupingConstraint)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90e3ea);
	int(*const rmPlaceGroupingAtLoc)(int, int, float, float, int) = reinterpret_cast<int(*)(int, int, float, float, int)>(0x90e419);
	int(*const rmPlaceGroupingAtPoint)(int, int, vector, int) = reinterpret_cast<int(*)(int, int, vector, int)>(0x90e457);
	int(*const rmPlaceGroupingInArea)(int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int)>(0x90e4d3);
	bool(*const rmSetGroupingMinDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e50c);
	bool(*const rmSetGroupingMaxDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x90e53b);
	bool(*const rmAddGroupingToClass)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x90e56a);
	int(*const rmCreateTradeRoute)() = reinterpret_cast<int(*)()>(0x90e599);
	bool(*const rmAddTradeRouteWaypoint)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90e5bd);
	bool(*const rmAddTradeRouteWaypointVector)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x90e5f1);
	bool(*const rmAddRandomTradeRouteWaypoints)(int, float, float, int, float) = reinterpret_cast<bool(*)(int, float, float, int, float)>(0x90e6a1);
	bool(*const rmAddRandomTradeRouteWaypointsVector)(int, vector, int, float) = reinterpret_cast<bool(*)(int, vector, int, float)>(0x90e6df);
	bool(*const rmCreateTradeRouteWaypointsInArea)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x90e79a);
	vector(*const rmGetTradeRouteWayPoint)(vector, int, float) = reinterpret_cast<vector(*)(vector, int, float)>(0x90e7ce);
	bool(*const rmBuildTradeRoute)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x90e824);
	bool(*const rmSetHomeCityGatherPoint)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x90edbf);
	bool(*const rmSetHomeCityWaterSpawnPoint)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x90edfb);
	int(*const rmGetLowHomeCityLevel)() = reinterpret_cast<int(*)()>(0x90eaed);
	int(*const rmGetAverageHomeCityLevel)() = reinterpret_cast<int(*)()>(0x90eb03);
	int(*const rmGetHighHomeCityLevel)() = reinterpret_cast<int(*)()>(0x90eb19);
	int(*const rmGetHomeCityLevel)(int) = reinterpret_cast<int(*)(int)>(0x90eb2f);
	vector(*const rmGetUnitPosition)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x90f15a);
	void(*const rmSetMapType)(string) = reinterpret_cast<void(*)(string)>(0x90f1ec);
	bool(*const rmIsMapType)(string) = reinterpret_cast<bool(*)(string)>(0x90f267);
	bool(*const rmAddClosestPointConstraint)(int) = reinterpret_cast<bool(*)(int)>(0x90eb4c);
	void(*const rmClearClosestPointConstraints)() = reinterpret_cast<void(*)()>(0x90eb76);
	vector(*const rmFindClosestPoint)(vector, float, float, float) = reinterpret_cast<vector(*)(vector, float, float, float)>(0x90eb97);
	vector(*const rmFindClosestPointVector)(vector, vector, float) = reinterpret_cast<vector(*)(vector, vector, float)>(0x90ec6d);
	int(*const rmFindCloserArea)(float, float, int, int) = reinterpret_cast<int(*)(float, float, int, int)>(0x90ecc3);
	bool(*const rmAddAreaCliffWaypoint)(int, float, float) = reinterpret_cast<bool(*)(int, float, float)>(0x90c985);
	bool(*const rmAddAreaCliffRandomWaypoints)(int, float, float, int, float) = reinterpret_cast<bool(*)(int, float, float, int, float)>(0x90c9b9);
	void(*const rmSetNuggetDifficulty)(int, int) = reinterpret_cast<void(*)(int, int)>(0x90ee37);
	void(*const rmSetOceanReveal)(bool) = reinterpret_cast<void(*)(bool)>(0x90ee81);
	bool(*const hcSetXSHandler)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x63758e);
	bool(*const hcSetUnitXSHandler)(int, string, int) = reinterpret_cast<bool(*)(int, string, int)>(0x6366dc);
	int(*const hcRandInt)(int) = reinterpret_cast<int(*)(int)>(0x42e4f6);
	vector(*const hcRandPosition)(vector) = reinterpret_cast<vector(*)(vector)>(0x8697a7);
	int(*const hcGetMyUnitID)() = reinterpret_cast<int(*)()>(0x42d930);
	int(*const hcUnitGetGroupID)(int) = reinterpret_cast<int(*)(int)>(0x430ae5);
	vector(*const hcUnitGetPosition)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x42fd86);
	int(*const hcUnitGetActionType)(int) = reinterpret_cast<int(*)(int)>(0x42d9f5);
	bool(*const hcUnitGoIdle)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x430585);
	string(*const hcUnitGetScript)(int) = reinterpret_cast<string(*)(int)>(0x8697e2);
	int(*const hcGetNumUnlockedUnits)(bool, bool) = reinterpret_cast<int(*)(bool, bool)>(0x86981d);
	int(*const hcGetUnlockedUnitProtoUnitID)(int, bool, bool) = reinterpret_cast<int(*)(int, bool, bool)>(0x869839);
	string(*const hcGetUnlockedUnitVisualFilename)(int, bool, bool) = reinterpret_cast<string(*)(int, bool, bool)>(0x86985a);
	string(*const hcGetUnlockedUnitScriptFilename)(int, bool, bool) = reinterpret_cast<string(*)(int, bool, bool)>(0x86987b);
	vector(*const hcUnitGetPerformPosFromGroup)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x430e64);
	vector(*const hcUnitGetPerformForwardFromGroup)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x869d1c);
	int(*const hcUnitCreateUsingPos)(int, string, string, vector, vector, bool) = reinterpret_cast<int(*)(int, string, string, vector, vector, bool)>(0x86989c);
	int(*const hcUnitCreate)(int, string, string, int) = reinterpret_cast<int(*)(int, string, string, int)>(0x869941);
	int(*const hcUnitCreateAtBone)(int, string, string, string) = reinterpret_cast<int(*)(int, string, string, string)>(0x86998c);
	void(*const hcPopulateHomeCity)() = reinterpret_cast<void(*)()>(0x6373d7);
	float(*const hcUnitGetInitialPauseTime)(int) = reinterpret_cast<float(*)(int)>(0x869a60);
	void(*const hcUnitSetInitialPauseTime)(int, float) = reinterpret_cast<void(*)(int, float)>(0x869a84);
	bool(*const hcUnitSetFlag)(int, int, bool, bool) = reinterpret_cast<bool(*)(int, int, bool, bool)>(0x4304ee);
	int(*const hcCreatePerformerGroup)(int, float) = reinterpret_cast<int(*)(int, float)>(0x636a0e);
	bool(*const hcReservePerformerArea)(int) = reinterpret_cast<bool(*)(int)>(0x430c18);
	int(*const hcGetNumPerformerGroups)() = reinterpret_cast<int(*)()>(0x869da0);
	void(*const hcAddUnitToPerformerGroup)(int, int) = reinterpret_cast<void(*)(int, int)>(0x63666c);
	bool(*const hcUnitExit)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x869aa5);
	void(*const hcUnitDestroyAll)() = reinterpret_cast<void(*)()>(0x869ad3);
	bool(*const hcUnitPlayAnim)(int, string, float, int, bool) = reinterpret_cast<bool(*)(int, string, float, int, bool)>(0x42f172);
	bool(*const hcUnitMoveToWPID)(int, int, int, float, float, bool) = reinterpret_cast<bool(*)(int, int, int, float, float, bool)>(0x42eb2a);
	bool(*const hcUnitMoveToPos)(int, int, vector, float, float, bool) = reinterpret_cast<bool(*)(int, int, vector, float, float, bool)>(0x430b70);
	bool(*const hcUnitTurn)(int, vector, float, bool) = reinterpret_cast<bool(*)(int, vector, float, bool)>(0x431195);
	bool(*const hcUnitTeleportToWPID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x869ae4);
	bool(*const hcUnitFollow)(int, int, float, bool) = reinterpret_cast<bool(*)(int, int, float, bool)>(0x869b82);
	bool(*const hcUnitExitBuilding)(int, int, float, float, bool) = reinterpret_cast<bool(*)(int, int, float, float, bool)>(0x869bba);
	bool(*const hcUnitEnterBuilding)(int, int, float, bool) = reinterpret_cast<bool(*)(int, int, float, bool)>(0x869bf7);
	bool(*const hcUnitSetVisible)(int, bool, bool) = reinterpret_cast<bool(*)(int, bool, bool)>(0x4303f8);
	bool(*const hcUnitWait)(int, float, bool) = reinterpret_cast<bool(*)(int, float, bool)>(0x869c2f);
	void(*const hcUnitFreeWPID)(int, int, bool) = reinterpret_cast<void(*)(int, int, bool)>(0x43127e);
	void(*const hcOccupyWPID)(int) = reinterpret_cast<void(*)(int)>(0x431210);
	int(*const hcGetNumberUnitsWithAI)(string) = reinterpret_cast<int(*)(string)>(0x869c62);
	int(*const hcGetUnitWithAI)(string, int) = reinterpret_cast<int(*)(string, int)>(0x869c9c);
	int(*const hcGetPerformerInProximity)(int) = reinterpret_cast<int(*)(int)>(0x42ddfc);
	int(*const hcGetNumberWaypoints)() = reinterpret_cast<int(*)()>(0x869db4);
	vector(*const hcGetWaypointPos)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x869dc5);
	vector(*const hcGetWaypointDir)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x430f93);
	int(*const hcGetNearestWPID)(vector) = reinterpret_cast<int(*)(vector)>(0x42fe01);
	int(*const hcGetRandomWPID)(int) = reinterpret_cast<int(*)(int)>(0x42edab);
	int(*const hcGetRandomFreeWPID)(int) = reinterpret_cast<int(*)(int)>(0x430f4c);
	int(*const hcGetBuildingIDByName)(string) = reinterpret_cast<int(*)(string)>(0x869cde);
	void(*const aiEcho)(string) = reinterpret_cast<void(*)(string)>(0x7286df);
	void(*const aiErrorMessage)(string) = reinterpret_cast<void(*)(string)>(0x728826);
	void(*const aiRandSetSeed)(int) = reinterpret_cast<void(*)(int)>(0x722cee);
	int(*const aiRandInt)(int) = reinterpret_cast<int(*)(int)>(0x722d0a);
	vector(*const aiRandLocation)(vector) = reinterpret_cast<vector(*)(vector)>(0x722d2b);
	void(*const aiSet)(string, int) = reinterpret_cast<void(*)(string, int)>(0x722dfe);
	void(*const aiBreakpointSet)(int, string, int, bool) = reinterpret_cast<void(*)(int, string, int, bool)>(0x722e61);
	void(*const aiBreakpointGo)(int) = reinterpret_cast<void(*)(int)>(0x722ed4);
	string(*const aiGetPersonality)() = reinterpret_cast<string(*)()>(0x722f20);
	float(*const aiPersonalityGetRushBoom)() = reinterpret_cast<float(*)()>(0x722f53);
	int(*const aiPersonalityGetNumberPlayerHistories)() = reinterpret_cast<int(*)()>(0x72680a);
	int(*const aiPersonalityCreatePlayerHistory)(string) = reinterpret_cast<int(*)(string)>(0x72938e);
	bool(*const aiPersonalityResetPlayerHistory)(int) = reinterpret_cast<bool(*)(int)>(0x7291f0);
	string(*const aiPersonalityGetPlayerHistoryName)(int) = reinterpret_cast<string(*)(int)>(0x726859);
	int(*const aiPersonalityGetPlayerHistoryIndex)(string) = reinterpret_cast<int(*)(string)>(0x7268c4);
	float(*const aiPersonalityGetPlayerUserVar)(int, string) = reinterpret_cast<float(*)(int, string)>(0x728ad8);
	bool(*const aiPersonalitySetPlayerUserVar)(int, string, float) = reinterpret_cast<bool(*)(int, string, float)>(0x7292cc);
	int(*const aiPersonalityGetPlayerGamesPlayed)(int, int) = reinterpret_cast<int(*)(int, int)>(0x726982);
	float(*const aiPersonalityGetGameResource)(int, int, int) = reinterpret_cast<float(*)(int, int, int)>(0x726a1f);
	bool(*const aiPersonalityGetDidIWinLastGameVS)(int) = reinterpret_cast<bool(*)(int)>(0x726b31);
	int(*const aiPersonalityGetGameUnitCount)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x726bc8);
	int(*const aiPersonalityGetGameFirstAttackTime)(int, int) = reinterpret_cast<int(*)(int, int)>(0x726ce9);
	int(*const aiPersonalityGetTotalGameWins)(int, int) = reinterpret_cast<int(*)(int, int)>(0x726d93);
	int(*const aiGetMostHatedPlayerID)() = reinterpret_cast<int(*)()>(0x722fa6);
	int(*const aiCalculateMostHatedPlayerID)(int) = reinterpret_cast<int(*)(int)>(0x722fd7);
	void(*const aiSetMostHatedPlayerID)(int) = reinterpret_cast<void(*)(int)>(0x723011);
	int(*const aiGetAvailableEconomyPop)() = reinterpret_cast<int(*)()>(0x723042);
	int(*const aiGetCurrentEconomyPop)() = reinterpret_cast<int(*)()>(0x723075);
	int(*const aiGetEconomyPop)() = reinterpret_cast<int(*)()>(0x7230a8);
	void(*const aiSetEconomyPop)(int) = reinterpret_cast<void(*)(int)>(0x7230d8);
	int(*const aiGetAvailableMilitaryPop)() = reinterpret_cast<int(*)()>(0x723109);
	int(*const aiGetMilitaryPop)() = reinterpret_cast<int(*)()>(0x72313c);
	void(*const aiSetMilitaryPop)(int) = reinterpret_cast<void(*)(int)>(0x72316c);
	float(*const aiGetEconomyPercentage)() = reinterpret_cast<float(*)()>(0x72319d);
	void(*const aiSetEconomyPercentage)(float) = reinterpret_cast<void(*)(float)>(0x7231d1);
	float(*const aiGetMilitaryPercentage)() = reinterpret_cast<float(*)()>(0x723202);
	void(*const aiSetMilitaryPercentage)(float) = reinterpret_cast<void(*)(float)>(0x723236);
	float(*const aiGetAttackResponseDistance)() = reinterpret_cast<float(*)()>(0x723267);
	void(*const aiSetAttackResponseDistance)(float) = reinterpret_cast<void(*)(float)>(0x72329b);
	int(*const aiGoalGetNumber)(int, int, bool) = reinterpret_cast<int(*)(int, int, bool)>(0x7232cc);
	int(*const aiGoalGetIDByIndex)(int, int, bool, int) = reinterpret_cast<int(*)(int, int, bool, int)>(0x723310);
	int(*const aiPlanGetNumber)(int, int, bool) = reinterpret_cast<int(*)(int, int, bool)>(0x723359);
	int(*const aiPlanGetIDByIndex)(int, int, bool, int) = reinterpret_cast<int(*)(int, int, bool, int)>(0x72339d);
	int(*const aiPlanCreate)(string, int) = reinterpret_cast<int(*)(string, int)>(0x7233e6);
	bool(*const aiPlanDestroy)(int) = reinterpret_cast<bool(*)(int)>(0x723431);
	bool(*const aiPlanDestroyByName)(string) = reinterpret_cast<bool(*)(string)>(0x72346b);
	int(*const aiPlanGetID)(string) = reinterpret_cast<int(*)(string)>(0x7234a5);
	int(*const aiPlanGetIDSubStr)(string) = reinterpret_cast<int(*)(string)>(0x7234e2);
	int(*const aiPlanGetIDByTypeAndVariableType)(int, int, int, bool) = reinterpret_cast<int(*)(int, int, int, bool)>(0x72351f);
	int(*const aiPlanGetIDByActiveIndex)(int) = reinterpret_cast<int(*)(int)>(0x723569);
	string(*const aiPlanGetName)(int) = reinterpret_cast<string(*)(int)>(0x7235ad);
	int(*const aiPlanGetType)(int) = reinterpret_cast<int(*)(int)>(0x7235f1);
	int(*const aiPlanGetState)(int) = reinterpret_cast<int(*)(int)>(0x723633);
	int(*const aiPlanGetActualPriority)(int) = reinterpret_cast<int(*)(int)>(0x723679);
	int(*const aiPlanGetDesiredPriority)(int) = reinterpret_cast<int(*)(int)>(0x7236bb);
	bool(*const aiPlanSetDesiredPriority)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x7236fd);
	bool(*const aiPlanAddUnitType)(int, int, int, int, int) = reinterpret_cast<bool(*)(int, int, int, int, int)>(0x723755);
	int(*const aiPlanGetNumberUnits)(int, int) = reinterpret_cast<int(*)(int, int)>(0x7237b0);
	bool(*const aiPlanAddUnit)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x7237fc);
	vector(*const aiPlanGetLocation)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x72383a);
	vector(*const aiPlanGetInitialPosition)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x7238a8);
	void(*const aiPlanSetInitialPosition)(int, vector) = reinterpret_cast<void(*)(int, vector)>(0x723921);
	bool(*const aiPlanSetWaypoints)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x726e39);
	bool(*const aiPlanAddWaypoint)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x723973);
	int(*const aiPlanGetNumberVariableValues)(int, int) = reinterpret_cast<int(*)(int, int)>(0x7239c1);
	bool(*const aiPlanSetNumberVariableValues)(int, int, int, bool) = reinterpret_cast<bool(*)(int, int, int, bool)>(0x723a0c);
	bool(*const aiPlanRemoveVariableValue)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x723ac0);
	bool(*const aiPlanSetVariableInt)(int, int, int, int) = reinterpret_cast<bool(*)(int, int, int, int)>(0x723b10);
	int(*const aiPlanGetVariableInt)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x723b9f);
	bool(*const aiPlanSetVariableFloat)(int, int, int, float) = reinterpret_cast<bool(*)(int, int, int, float)>(0x723c02);
	float(*const aiPlanGetVariableFloat)(int, int, int) = reinterpret_cast<float(*)(int, int, int)>(0x723c91);
	bool(*const aiPlanSetVariableVector)(int, int, int, vector) = reinterpret_cast<bool(*)(int, int, int, vector)>(0x723cf7);
	vector(*const aiPlanGetVariableVector)(vector, int, int, int) = reinterpret_cast<vector(*)(vector, int, int, int)>(0x723d93);
	bool(*const aiPlanSetVariableBool)(int, int, int, bool) = reinterpret_cast<bool(*)(int, int, int, bool)>(0x723e44);
	bool(*const aiPlanGetVariableBool)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x723ed3);
	bool(*const aiPlanSetVariableString)(int, int, int, string) = reinterpret_cast<bool(*)(int, int, int, string)>(0x723f35);
	string(*const aiPlanGetVariableString)(int, int) = reinterpret_cast<string(*)(int, int)>(0x726ec6);
	int(*const aiPlanGetNumberUserVariableValues)(int, int) = reinterpret_cast<int(*)(int, int)>(0x723fd1);
	bool(*const aiPlanSetNumberUserVariableValues)(int, int, int, bool) = reinterpret_cast<bool(*)(int, int, int, bool)>(0x72401f);
	bool(*const aiPlanRemoveUserVariables)(int) = reinterpret_cast<bool(*)(int)>(0x724077);
	bool(*const aiPlanRemoveUserVariable)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x7240c2);
	bool(*const aiPlanRemoveUserVariableValue)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x724110);
	bool(*const aiPlanAddUserVariableInt)(int, int, string, int) = reinterpret_cast<bool(*)(int, int, string, int)>(0x724163);
	bool(*const aiPlanSetUserVariableInt)(int, int, int, int) = reinterpret_cast<bool(*)(int, int, int, int)>(0x7241bb);
	int(*const aiPlanGetUserVariableInt)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x724213);
	bool(*const aiPlanAddUserVariableFloat)(int, int, string, int) = reinterpret_cast<bool(*)(int, int, string, int)>(0x724279);
	bool(*const aiPlanSetUserVariableFloat)(int, int, int, float) = reinterpret_cast<bool(*)(int, int, int, float)>(0x7242d1);
	float(*const aiPlanGetUserVariableFloat)(int, int, int) = reinterpret_cast<float(*)(int, int, int)>(0x724329);
	bool(*const aiPlanAddUserVariableVector)(int, int, string, int) = reinterpret_cast<bool(*)(int, int, string, int)>(0x724392);
	bool(*const aiPlanSetUserVariableVector)(int, int, int, vector) = reinterpret_cast<bool(*)(int, int, int, vector)>(0x7243ea);
	vector(*const aiPlanGetUserVariableVector)(vector, int, int, int) = reinterpret_cast<vector(*)(vector, int, int, int)>(0x724446);
	bool(*const aiPlanAddUserVariableBool)(int, int, string, int) = reinterpret_cast<bool(*)(int, int, string, int)>(0x7244fa);
	bool(*const aiPlanSetUserVariableBool)(int, int, int, bool) = reinterpret_cast<bool(*)(int, int, int, bool)>(0x724552);
	bool(*const aiPlanGetUserVariableBool)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x7245aa);
	bool(*const aiPlanAddUserVariableString)(int, int, string, int) = reinterpret_cast<bool(*)(int, int, string, int)>(0x72460f);
	bool(*const aiPlanSetUserVariableString)(int, int, int, string) = reinterpret_cast<bool(*)(int, int, int, string)>(0x724667);
	string(*const aiPlanGetUserVariableString)(int, int, int) = reinterpret_cast<string(*)(int, int, int)>(0x726f41);
	bool(*const aiPlanGetActive)(int) = reinterpret_cast<bool(*)(int)>(0x726fbf);
	bool(*const aiPlanSetActive)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x7246c3);
	bool(*const aiPlanGetNoMoreUnits)(int) = reinterpret_cast<bool(*)(int)>(0x72706c);
	bool(*const aiPlanSetNoMoreUnits)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x72475f);
	bool(*const aiPlanGetOrphan)(int) = reinterpret_cast<bool(*)(int)>(0x727015);
	bool(*const aiPlanSetOrphan)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x724711);
	bool(*const aiPlanGetAllowUnderAttackResponse)(int) = reinterpret_cast<bool(*)(int)>(0x7270c3);
	bool(*const aiPlanSetAllowUnderAttackResponse)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x7247ad);
	int(*const aiPlanGetUnitStance)(int) = reinterpret_cast<int(*)(int)>(0x7247fb);
	bool(*const aiPlanSetUnitStance)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x724841);
	bool(*const aiPlanSetRequiresAllNeedUnits)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x72488b);
	bool(*const aiPlanSetEventHandler)(int, int, string) = reinterpret_cast<bool(*)(int, int, string)>(0x7248d9);
	bool(*const aiPlanSetEscrowID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x724973);
	int(*const aiPlanGetEscrowID)(int) = reinterpret_cast<int(*)(int)>(0x7249bd);
	bool(*const aiPlanGetEconomy)(int) = reinterpret_cast<bool(*)(int)>(0x72711c);
	bool(*const aiPlanSetEconomy)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x724a02);
	bool(*const aiPlanGetMilitary)(int) = reinterpret_cast<bool(*)(int)>(0x727173);
	bool(*const aiPlanSetMilitary)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x724a66);
	bool(*const aiPlanGetAttack)(int) = reinterpret_cast<bool(*)(int)>(0x7271ca);
	bool(*const aiPlanSetAttack)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x724aca);
	bool(*const aiPlanSetBaseID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x724b18);
	int(*const aiPlanGetBaseID)(int) = reinterpret_cast<int(*)(int)>(0x724b66);
	int(*const aiGetNumberIdlePlans)(int) = reinterpret_cast<int(*)(int)>(0x724baa);
	float(*const aiPlanGetUnitCost)(int, bool) = reinterpret_cast<float(*)(int, bool)>(0x728b69);
	void(*const aiCommsAllowChat)(bool) = reinterpret_cast<void(*)(bool)>(0x724be3);
	int(*const aiCommsSendStatement)(int, int) = reinterpret_cast<int(*)(int, int)>(0x724c0d);
	int(*const aiCommsSendStatementWithVector)(int, int, vector) = reinterpret_cast<int(*)(int, int, vector)>(0x724c56);
	bool(*const aiCommsSetEventHandler)(string) = reinterpret_cast<bool(*)(string)>(0x724ca2);
	int(*const aiCommsGetSendingPlayer)(int) = reinterpret_cast<int(*)(int)>(0x727220);
	int(*const aiCommsGetChatVerb)(int) = reinterpret_cast<int(*)(int)>(0x727263);
	int(*const aiCommsGetChatTargetType)(int) = reinterpret_cast<int(*)(int)>(0x7272a6);
	int(*const aiCommsGetTargetListCount)(int) = reinterpret_cast<int(*)(int)>(0x7272e9);
	int(*const aiCommsGetTargetListItem)(int, int) = reinterpret_cast<int(*)(int, int)>(0x72732d);
	vector(*const aiCommsGetTargetLocation)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x727381);
	void(*const aiCommsSendReply)(int, int) = reinterpret_cast<void(*)(int, int)>(0x728cb8);
	bool(*const aiSetHandler)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x724d3b);
	bool(*const aiTaskUnitMove)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x724db5);
	bool(*const aiTaskUnitWork)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x724e46);
	bool(*const aiTaskUnitBuild)(int, int, vector) = reinterpret_cast<bool(*)(int, int, vector)>(0x724ed0);
	bool(*const aiTaskUnitTrain)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x7273fc);
	bool(*const aiTaskUnitResearch)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x72748d);
	bool(*const aiTaskUnitDelete)(int) = reinterpret_cast<bool(*)(int)>(0x724f9e);
	bool(*const aiTribute)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x724fca);
	bool(*const aiSellResourceOnMarket)(int) = reinterpret_cast<bool(*)(int)>(0x72500d);
	bool(*const aiBuyResourceOnMarket)(int) = reinterpret_cast<bool(*)(int)>(0x72504b);
	float(*const aiGetMarketBuyCost)(int) = reinterpret_cast<float(*)(int)>(0x7290d2);
	float(*const aiGetMarketSellCost)(int) = reinterpret_cast<float(*)(int)>(0x72912c);
	float(*const aiGetResourceGathererPercentageWeight)(int) = reinterpret_cast<float(*)(int)>(0x725089);
	void(*const aiSetResourceGathererPercentageWeight)(int, float) = reinterpret_cast<void(*)(int, float)>(0x7250c6);
	void(*const aiNormalizeResourceGathererPercentageWeights)() = reinterpret_cast<void(*)()>(0x725101);
	float(*const aiGetResourceGathererPercentage)(int, int) = reinterpret_cast<float(*)(int, int)>(0x725132);
	void(*const aiSetResourceGathererPercentage)(int, float, bool, int) = reinterpret_cast<void(*)(int, float, bool, int)>(0x725174);
	void(*const aiNormalizeResourceGathererPercentages)(int) = reinterpret_cast<void(*)(int)>(0x7251b9);
	int(*const aiGetResourceBreakdownNumberPlans)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x7251ef);
	int(*const aiGetResourceBreakdownPlanPriority)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x725235);
	float(*const aiGetResourceBreakdownPercentage)(int, int, int) = reinterpret_cast<float(*)(int, int, int)>(0x72527b);
	bool(*const aiSetResourceBreakdown)(int, int, int, int, float, int) = reinterpret_cast<bool(*)(int, int, int, int, float, int)>(0x7252c5);
	bool(*const aiRemoveResourceBreakdown)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x725317);
	int(*const aiGetAutoGatherEscrowID)() = reinterpret_cast<int(*)()>(0x72535a);
	void(*const aiSetAutoGatherEscrowID)(int) = reinterpret_cast<void(*)(int)>(0x72538e);
	int(*const aiGetAutoFarmEscrowID)() = reinterpret_cast<int(*)()>(0x7253c2);
	void(*const aiSetAutoFarmEscrowID)(int) = reinterpret_cast<void(*)(int)>(0x7253f6);
	int(*const aiGetFarmLimit)() = reinterpret_cast<int(*)()>(0x72542a);
	void(*const aiSetFarmLimit)(int) = reinterpret_cast<void(*)(int)>(0x72545e);
	bool(*const aiGetAllowBuildings)() = reinterpret_cast<bool(*)()>(0x725492);
	void(*const aiSetAllowBuildings)(bool) = reinterpret_cast<void(*)(bool)>(0x7254c5);
	void(*const aiChat)(int, string) = reinterpret_cast<void(*)(int, string)>(0x728db6);
	int(*const aiNumberUnassignedUnits)(int) = reinterpret_cast<int(*)(int)>(0x7254f9);
	int(*const aiNumberUnassignedUnitsByGoal)(int) = reinterpret_cast<int(*)(int)>(0x725532);
	int(*const aiCreateOpportunity)(int, int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int, int)>(0x72556b);
	void(*const aiActivateOpportunity)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x7255da);
	void(*const aiDestroyOpportunity)(int) = reinterpret_cast<void(*)(int)>(0x725626);
	void(*const aiFindBestOpportunity)() = reinterpret_cast<void(*)()>(0x725660);
	int(*const aiGetOpportunitySourceID)(int) = reinterpret_cast<int(*)(int)>(0x725695);
	int(*const aiGetOpportunitySourceType)(int) = reinterpret_cast<int(*)(int)>(0x7256da);
	float(*const aiGetOpportunityRadius)(float) = reinterpret_cast<float(*)(float)>(0x72571f);
	int(*const aiGetOpportunityTargetPlayerID)(int) = reinterpret_cast<int(*)(int)>(0x725767);
	int(*const aiGetOpportunityTargetType)(int) = reinterpret_cast<int(*)(int)>(0x7257ac);
	int(*const aiGetOpportunityType)(int) = reinterpret_cast<int(*)(int)>(0x7257f1);
	vector(*const aiGetOpportunityLocation)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x725836);
	int(*const aiGetOpportunityTargetID)(int) = reinterpret_cast<int(*)(int)>(0x7258d7);
	void(*const aiSetOpportunityTargetType)(int, int) = reinterpret_cast<void(*)(int, int)>(0x72591c);
	void(*const aiSetOpportunityTargetID)(int, int) = reinterpret_cast<void(*)(int, int)>(0x725961);
	void(*const aiSetOpportunityRadius)(int, float) = reinterpret_cast<void(*)(int, float)>(0x7259a6);
	void(*const aiSetOpportunityLocation)(int, vector) = reinterpret_cast<void(*)(int, vector)>(0x7259eb);
	bool(*const aiSetOpportunityScore)(int, int, float, float, float, float) = reinterpret_cast<bool(*)(int, int, float, float, float, float)>(0x725a3b);
	bool(*const aiCastGodPowerAtPosition)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x728e6f);
	int(*const aiGetGodPowerTechIDForSlot)(int) = reinterpret_cast<int(*)(int)>(0x725aa7);
	int(*const aiGetGodPowerProtoIDForTechID)(int) = reinterpret_cast<int(*)(int)>(0x882556);
	int(*const aiGetGodPowerType)(int) = reinterpret_cast<int(*)(int)>(0x725ac2);
	int(*const aiFindBestAttackGodPowerPlan)() = reinterpret_cast<int(*)()>(0x725ae8);
	int(*const aiFindBestTownDefenseGodPowerPlan)() = reinterpret_cast<int(*)()>(0x725b1d);
	int(*const aiGetWorldDifficulty)() = reinterpret_cast<int(*)()>(0x725b52);
	void(*const aiSetWorldDifficulty)(int) = reinterpret_cast<void(*)(int)>(0x725b6e);
	string(*const aiGetWorldDifficultyName)(int) = reinterpret_cast<string(*)(int)>(0x725b88);
	int(*const aiGetGameMode)() = reinterpret_cast<int(*)()>(0x725bd0);
	int(*const aiGetCaptainPlayerID)(int) = reinterpret_cast<int(*)(int)>(0x725bea);
	bool(*const aiGetAutosaveOn)() = reinterpret_cast<bool(*)()>(0x58ea6b);
	float(*const aiGetCurrentResourceNeed)(int) = reinterpret_cast<float(*)(int)>(0x725c2b);
	bool(*const aiSetAutoGatherMilitaryUnits)(bool) = reinterpret_cast<bool(*)(bool)>(0x725c7a);
	bool(*const aiSetExploreDangerThreshold)(float) = reinterpret_cast<bool(*)(float)>(0x725cb3);
	float(*const aiGetExploreDangerThreshold)() = reinterpret_cast<float(*)()>(0x725cec);
	void(*const aiSetRandomMap)(bool) = reinterpret_cast<void(*)(bool)>(0x725d23);
	void(*const aiSetPauseAllAgeUpgrades)(bool) = reinterpret_cast<void(*)(bool)>(0x725d57);
	bool(*const aiGetPauseAllAgeUpgrades)(bool) = reinterpret_cast<bool(*)(bool)>(0x725d8b);
	void(*const aiSetMinArmySize)(int) = reinterpret_cast<void(*)(int)>(0x725dbe);
	void(*const aiSetMinNumberNeedForGatheringAggressvies)(int) = reinterpret_cast<void(*)(int)>(0x725df2);
	int(*const aiGetMinNumberNeedForGatheringAggressives)() = reinterpret_cast<int(*)()>(0x725e26);
	void(*const aiSetMinNumberWantForGatheringAggressives)(int) = reinterpret_cast<void(*)(int)>(0x725e5a);
	int(*const aiGetMinNumberWantForGatheringAggressives)() = reinterpret_cast<int(*)()>(0x725e8e);
	void(*const aiResign)() = reinterpret_cast<void(*)()>(0x725ec2);
	void(*const aiAttemptResign)(int) = reinterpret_cast<void(*)(int)>(0x72751e);
	void(*const aiSetMaxLOSProtoUnitLimit)(int) = reinterpret_cast<void(*)(int)>(0x725f60);
	int(*const aiGetMaxLOSProtoUnitLimit)() = reinterpret_cast<int(*)()>(0x725f94);
	int(*const aiGetPopNeeds)() = reinterpret_cast<int(*)()>(0x725fc8);
	void(*const aiSwitchMainBase)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x725ffb);
	void(*const aiSetDefaultStance)(int) = reinterpret_cast<void(*)(int)>(0x726036);
	void(*const aiSetWaterMap)(bool) = reinterpret_cast<void(*)(bool)>(0x72605b);
	bool(*const aiGetWaterMap)() = reinterpret_cast<bool(*)()>(0x72608f);
	bool(*const aiIsMapType)(string) = reinterpret_cast<bool(*)(string)>(0x729186);
	int(*const aiHCCardsGetTotal)() = reinterpret_cast<int(*)()>(0x727854);
	bool(*const aiHCCardsIsCardBought)(int) = reinterpret_cast<bool(*)(int)>(0x727887);
	bool(*const aiHCCardsCanIBuyThisCard)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x7278e1);
	bool(*const aiHCCardsBuyCard)(int) = reinterpret_cast<bool(*)(int)>(0x7279a7);
	int(*const aiHCCardsGetCardAgePrereq)(int) = reinterpret_cast<int(*)(int)>(0x727a36);
	int(*const aiHCCardsGetCardLevel)(int) = reinterpret_cast<int(*)(int)>(0x727a87);
	int(*const aiHCCardsGetCardTechID)(int) = reinterpret_cast<int(*)(int)>(0x727ad8);
	int(*const aiHCCardsGetCardUnitType)(int) = reinterpret_cast<int(*)(int)>(0x727b28);
	int(*const aiHCCardsGetCardUnitCount)(int) = reinterpret_cast<int(*)(int)>(0x727b82);
	int(*const aiHCCardsGetCardCount)(int) = reinterpret_cast<int(*)(int)>(0x727bd8);
	int(*const aiHCCardsFindBestCard)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x7260c2);
	int(*const aiHCGetNumberDecks)() = reinterpret_cast<int(*)()>(0x727c2c);
	int(*const aiHCDeckCreate)(string) = reinterpret_cast<int(*)(string)>(0x726110);
	bool(*const aiHCDeckActivate)(int) = reinterpret_cast<bool(*)(int)>(0x726177);
	bool(*const aiHCDeckAddCardToDeck)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x727c5f);
	int(*const aiHCDeckGetNumberCards)(int) = reinterpret_cast<int(*)(int)>(0x727cb8);
	bool(*const aiHCDeckPlayCard)(int) = reinterpret_cast<bool(*)(int)>(0x7261db);
	int(*const aiHCDeckGetCardAgePrereq)(int, int) = reinterpret_cast<int(*)(int, int)>(0x727cca);
	int(*const aiHCDeckGetCardLevel)(int, int) = reinterpret_cast<int(*)(int, int)>(0x727cf6);
	int(*const aiHCDeckGetCardTechID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x727d22);
	int(*const aiHCDeckGetCardUnitType)(int, int) = reinterpret_cast<int(*)(int, int)>(0x727d72);
	int(*const aiHCDeckGetCardUnitCount)(int, int) = reinterpret_cast<int(*)(int, int)>(0x727dda);
	bool(*const aiHCDeckCanPlayCard)(int) = reinterpret_cast<bool(*)(int)>(0x727e3e);
	int(*const aiHCDeckCardGetCardCount)(int, int) = reinterpret_cast<int(*)(int, int)>(0x727ff5);
	vector(*const aiGetHCGatherPoint)(vector) = reinterpret_cast<vector(*)(vector)>(0x728050);
	bool(*const aiSetHCGatherPoint)() = reinterpret_cast<bool(*)()>(0x726236);
	int(*const aiGetScore)(int) = reinterpret_cast<int(*)(int)>(0x72626c);
	int(*const aiGetNumberTeams)() = reinterpret_cast<int(*)()>(0x7280f9);
	void(*const aiQueueAutoSavegame)(int) = reinterpret_cast<void(*)(int)>(0x72629b);
	bool(*const aiIsMultiplayer)() = reinterpret_cast<bool(*)()>(0x7262d1);
	int(*const aiGetFallenExplorerID)() = reinterpret_cast<int(*)()>(0x728ec5);
	bool(*const aiRansomExplorer)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x728117);
	bool(*const aiBuildWall)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x72823a);
	bool(*const aiCanBuildWall)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x728332);
	float(*const aiGetWallRadius)(int) = reinterpret_cast<float(*)(int)>(0x728fbd);
	bool(*const aiDoesWallExist)(int) = reinterpret_cast<bool(*)(int)>(0x729048);
	int(*const aiGetGameType)() = reinterpret_cast<int(*)()>(0x726386);
	bool(*const aiUnitSetTactic)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x7283f9);
	int(*const aiUnitGetTactic)(int) = reinterpret_cast<int(*)(int)>(0x728477);
	void(*const aiResourceLock)(int) = reinterpret_cast<void(*)(int)>(0x7262dc);
	void(*const aiResourceUnlock)(int) = reinterpret_cast<void(*)(int)>(0x726313);
	bool(*const aiResourceIsLocked)(int) = reinterpret_cast<bool(*)(int)>(0x72634a);
	bool(*const aiBreakTreaty)(int) = reinterpret_cast<bool(*)(int)>(0x726392);
	bool(*const aiTreatyActive)() = reinterpret_cast<bool(*)()>(0x726438);
	void(*const aiSetPoliticianChoice)(int, int) = reinterpret_cast<void(*)(int, int)>(0x72645d);
	int(*const aiGetPoliticianChoice)(int) = reinterpret_cast<int(*)(int)>(0x726498);
	bool(*const aiPopulatePoliticianList)() = reinterpret_cast<bool(*)()>(0x7264d2);
	int(*const aiGetPoliticianListCount)(int) = reinterpret_cast<int(*)(int)>(0x726505);
	int(*const aiGetPoliticianListByIndex)(int, int) = reinterpret_cast<int(*)(int, int)>(0x72653f);
	int(*const aiGetLastCollectedNuggetType)(int) = reinterpret_cast<int(*)(int)>(0x72657e);
	int(*const aiGetLastCollectedNuggetEffect)(int) = reinterpret_cast<int(*)(int)>(0x7284ce);
	int(*const aiGetNumberTradePostsControlled)(int) = reinterpret_cast<int(*)(int)>(0x7265c5);
	int(*const aiGetNumberTradePostsNeededForMonopoly)() = reinterpret_cast<int(*)()>(0x72660c);
	bool(*const aiReadyForTradeMonopoly)() = reinterpret_cast<bool(*)()>(0x726636);
	bool(*const aiDoTradeMonopoly)() = reinterpret_cast<bool(*)()>(0x726664);
	bool(*const aiIsMonopolyAllowed)() = reinterpret_cast<bool(*)()>(0x726691);
	int(*const aiGetNumberRelicsControlled)(int) = reinterpret_cast<int(*)(int)>(0x7266f8);
	int(*const aiGetNumberRelicsNeededForVictory)() = reinterpret_cast<int(*)()>(0x72673f);
	bool(*const aiIsRelicCaptureAllowed)() = reinterpret_cast<bool(*)()>(0x7266de);
	bool(*const aiIsKOTHAllowed)() = reinterpret_cast<bool(*)()>(0x72674f);
	int(*const aiGetKOTHController)() = reinterpret_cast<int(*)()>(0x72862c);
	bool(*const aiIsTeamKOTH)(int) = reinterpret_cast<bool(*)(int)>(0x72679c);
	void(*const kbDump)(int, int) = reinterpret_cast<void(*)(int, int)>(0x88112c);
	void(*const kbDumpType)(int, int, string) = reinterpret_cast<void(*)(int, int, string)>(0x88116b);
	void(*const kbLookAtAllUnitsOnMap)() = reinterpret_cast<void(*)()>(0x8811af);
	int(*const kbGetPop)() = reinterpret_cast<int(*)()>(0x8811e0);
	int(*const kbGetPopCap)() = reinterpret_cast<int(*)()>(0x881213);
	int(*const kbGetAge)() = reinterpret_cast<int(*)()>(0x881246);
	int(*const kbGetAgeForPlayer)(int) = reinterpret_cast<int(*)(int)>(0x88127a);
	int(*const kbGetCulture)() = reinterpret_cast<int(*)()>(0x88129f);
	int(*const kbGetCultureForPlayer)(int) = reinterpret_cast<int(*)(int)>(0x8812d3);
	string(*const kbGetCultureName)(int) = reinterpret_cast<string(*)(int)>(0x8812fb);
	int(*const kbGetCiv)() = reinterpret_cast<int(*)()>(0x881311);
	int(*const kbGetCivForPlayer)(int) = reinterpret_cast<int(*)(int)>(0x881345);
	string(*const kbGetCivName)(int) = reinterpret_cast<string(*)(int)>(0x88136d);
	int(*const kbUnitQueryCreate)(string) = reinterpret_cast<int(*)(string)>(0x881383);
	bool(*const kbUnitQueryResetData)(int) = reinterpret_cast<bool(*)(int)>(0x8813bc);
	bool(*const kbUnitQueryResetResults)(int) = reinterpret_cast<bool(*)(int)>(0x8813f5);
	bool(*const kbUnitQueryDestroy)(int) = reinterpret_cast<bool(*)(int)>(0x88142e);
	int(*const kbUnitQueryNumberResults)(int) = reinterpret_cast<int(*)(int)>(0x881467);
	int(*const kbUnitQueryGetResult)(int, int) = reinterpret_cast<int(*)(int, int)>(0x8814a0);
	bool(*const kbUnitQuerySetPlayerID)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x8814df);
	bool(*const kbUnitQuerySetPlayerRelation)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x881522);
	bool(*const kbUnitQuerySetUnitType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x881560);
	bool(*const kbUnitQuerySetActionType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x88159e);
	bool(*const kbUnitQuerySetState)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8815dc);
	bool(*const kbUnitQuerySetPosition)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x88161a);
	bool(*const kbUnitQuerySetMaximumDistance)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x881658);
	bool(*const kbUnitQuerySetIgnoreKnockedOutUnits)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x881696);
	bool(*const kbUnitQuerySetAscendingSort)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x8816d4);
	bool(*const kbUnitQuerySetBaseID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x881721);
	bool(*const kbUnitQuerySetAreaID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x88175f);
	bool(*const kbUnitQuerySetAreaGroupID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x88179d);
	bool(*const kbUnitQuerySetArmyID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8817db);
	bool(*const kbUnitQuerySetSeeableOnly)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x881819);
	int(*const kbUnitQueryExecute)(int) = reinterpret_cast<int(*)(int)>(0x881857);
	int(*const kbUnitQueryExecuteOnQuery)(int, int) = reinterpret_cast<int(*)(int, int)>(0x881890);
	int(*const kbUnitQueryExecuteOnQueryByName)(int, string) = reinterpret_cast<int(*)(int, string)>(0x8818ce);
	float(*const kbUnitQueryGetUnitCost)(int, bool) = reinterpret_cast<float(*)(int, bool)>(0x8859ca);
	float(*const kbUnitQueryGetUnitHitpoints)(int, bool) = reinterpret_cast<float(*)(int, bool)>(0x885b00);
	int(*const kbUnitGetPlayerID)(int) = reinterpret_cast<int(*)(int)>(0x88190c);
	int(*const kbUnitGetPlanID)(int) = reinterpret_cast<int(*)(int)>(0x881961);
	int(*const kbUnitGetBaseID)(int) = reinterpret_cast<int(*)(int)>(0x88199b);
	int(*const kbUnitGetAreaID)(int) = reinterpret_cast<int(*)(int)>(0x8819d5);
	int(*const kbUnitGetArmyID)(int) = reinterpret_cast<int(*)(int)>(0x881a0f);
	int(*const kbUnitGetMovementType)(int) = reinterpret_cast<int(*)(int)>(0x881a49);
	float(*const kbUnitGetCurrentHitpoints)(int) = reinterpret_cast<float(*)(int)>(0x881a83);
	float(*const kbUnitGetMaximumHitpoints)(int) = reinterpret_cast<float(*)(int)>(0x881ac0);
	float(*const kbUnitGetHealth)(int) = reinterpret_cast<float(*)(int)>(0x881afd);
	float(*const kbUnitGetCurrentAICost)(int) = reinterpret_cast<float(*)(int)>(0x881b3a);
	float(*const kbUnitGetMaximumAICost)(int) = reinterpret_cast<float(*)(int)>(0x881b77);
	vector(*const kbUnitGetPosition)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x881bb4);
	bool(*const kbUnitIsType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x881c14);
	int(*const kbUnitGetActionType)(int) = reinterpret_cast<int(*)(int)>(0x881c52);
	int(*const kbUnitGetTargetUnitID)(int) = reinterpret_cast<int(*)(int)>(0x881c8c);
	int(*const kbUnitGetNumberWorkers)(int) = reinterpret_cast<int(*)(int)>(0x881cc6);
	int(*const kbUnitGetWorkerID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x881cff);
	int(*const kbGetBuildLimit)(int, int) = reinterpret_cast<int(*)(int, int)>(0x881d3e);
	int(*const kbGetPopCapAddition)(int, int) = reinterpret_cast<int(*)(int, int)>(0x881d7f);
	int(*const kbGetPopSlots)(int, int) = reinterpret_cast<int(*)(int, int)>(0x881db6);
	int(*const kbGetPopulationSlotsByUnitTypeID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x881ded);
	int(*const kbGetPopulationSlotsByQueryID)(int) = reinterpret_cast<int(*)(int)>(0x881e2b);
	int(*const kbUnitCount)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x881e64);
	void(*const kbUnitCountConsole)(int, int, string, string) = reinterpret_cast<void(*)(int, int, string, string)>(0x885c10);
	vector(*const kbGetMapCenter)(vector) = reinterpret_cast<vector(*)(vector)>(0x881ea9);
	float(*const kbGetMapXSize)() = reinterpret_cast<float(*)()>(0x881f04);
	float(*const kbGetMapZSize)() = reinterpret_cast<float(*)()>(0x881f3c);
	void(*const kbAreaCalculate)(float, bool, vector, vector, vector, vector) = reinterpret_cast<void(*)(float, bool, vector, vector, vector, vector)>(0x881f74);
	int(*const kbAreaGetNumber)() = reinterpret_cast<int(*)()>(0x8850ac);
	int(*const kbAreaGetIDByPosition)(vector) = reinterpret_cast<int(*)(vector)>(0x8820b6);
	int(*const kbAreaGroupGetIDByPosition)(vector) = reinterpret_cast<int(*)(vector)>(0x8820f0);
	vector(*const kbAreaGroupGetCenter)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x88212a);
	vector(*const kbAreaGetCenter)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x8821a8);
	int(*const kbAreaGetNumberTiles)(int) = reinterpret_cast<int(*)(int)>(0x882226);
	int(*const kbAreaGetNumberBlackTiles)(int) = reinterpret_cast<int(*)(int)>(0x88225f);
	int(*const kbAreaGetNumberVisibleTiles)(int) = reinterpret_cast<int(*)(int)>(0x882298);
	int(*const kbAreaGetNumberFogTiles)(int) = reinterpret_cast<int(*)(int)>(0x8822d1);
	int(*const kbAreaGetVisibilityChangeTime)(int) = reinterpret_cast<int(*)(int)>(0x88230a);
	int(*const kbAreaGetNumberUnits)(int) = reinterpret_cast<int(*)(int)>(0x882343);
	int(*const kbAreaGetUnitID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x88237c);
	int(*const kbAreaGetNumberBorderAreas)(int) = reinterpret_cast<int(*)(int)>(0x8823bb);
	int(*const kbAreaGetBorderAreaID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x8823f4);
	int(*const kbAreaGetType)(int) = reinterpret_cast<int(*)(int)>(0x882433);
	int(*const kbAreaGetVPSiteID)(int) = reinterpret_cast<int(*)(int)>(0x88246d);
	int(*const kbVPSiteQuery)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x8824a7);
	void(*const kbDumpVPSiteInfo)() = reinterpret_cast<void(*)()>(0x8824eb);
	int(*const kbVPSiteGetType)(int) = reinterpret_cast<int(*)(int)>(0x8850e6);
	vector(*const kbVPSiteGetLocation)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x88513a);
	int(*const kbVPSiteGetOwnerPlayerID)(int) = reinterpret_cast<int(*)(int)>(0x8851ba);
	int(*const kbVPSiteGetState)(int) = reinterpret_cast<int(*)(int)>(0x885208);
	int(*const kbGetVPGeneratorByScoreType)(int) = reinterpret_cast<int(*)(int)>(0x88251c);
	int(*const kbAreaGetClosetArea)(vector, int, int, float) = reinterpret_cast<int(*)(vector, int, int, float)>(0x88255a);
	int(*const kbPathCreate)(string) = reinterpret_cast<int(*)(string)>(0x8825a3);
	bool(*const kbPathDestroy)(int) = reinterpret_cast<bool(*)(int)>(0x8825dd);
	int(*const kbPathGetNumber)() = reinterpret_cast<int(*)()>(0x885259);
	int(*const kbPathGetIDByIndex)(int) = reinterpret_cast<int(*)(int)>(0x882616);
	string(*const kbPathGetName)(int) = reinterpret_cast<string(*)(int)>(0x882650);
	float(*const kbPathGetLength)(int) = reinterpret_cast<float(*)(int)>(0x882689);
	int(*const kbPathGetNumberWaypoints)(int) = reinterpret_cast<int(*)(int)>(0x8826c6);
	bool(*const kbPathAddWaypoint)(int, vector) = reinterpret_cast<bool(*)(int, vector)>(0x8826ff);
	vector(*const kbPathGetWaypoint)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x88273d);
	bool(*const kbCanSimPath)(vector, vector, int, float) = reinterpret_cast<bool(*)(vector, vector, int, float)>(0x88277e);
	bool(*const kbCanPath2)(vector, vector, int, float) = reinterpret_cast<bool(*)(vector, vector, int, float)>(0x8827cc);
	int(*const kbCreateAttackRoute)(string, int, int, int) = reinterpret_cast<int(*)(string, int, int, int)>(0x882825);
	int(*const kbCreateAttackRouteWithPath)(string, vector, vector) = reinterpret_cast<int(*)(string, vector, vector)>(0x882894);
	bool(*const kbDestroyAttackRoute)(int) = reinterpret_cast<bool(*)(int)>(0x8828e5);
	bool(*const kbAddAttackRouteSector)(int) = reinterpret_cast<bool(*)(int)>(0x88291e);
	bool(*const kbAddAttackRouteIgnoreID)(int) = reinterpret_cast<bool(*)(int)>(0x882957);
	bool(*const kbAddAttackRouteIgnoreType)(int) = reinterpret_cast<bool(*)(int)>(0x882990);
	bool(*const kbAttackRouteAddPath)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8829c9);
	bool(*const kbMakeAttackRoutes)() = reinterpret_cast<bool(*)()>(0x882a07);
	int(*const kbGetNumAttackRoutes)(int, int) = reinterpret_cast<int(*)(int, int)>(0x88528c);
	int(*const kbGetAttackRouteID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x882a3a);
	int(*const kbEscrowCreate)(string, int, float, int) = reinterpret_cast<int(*)(string, int, float, int)>(0x882a7e);
	bool(*const kbEscrowDestroy)(int, bool) = reinterpret_cast<bool(*)(int, bool)>(0x882ac7);
	int(*const kbEscrowGetID)(string) = reinterpret_cast<int(*)(string)>(0x882b05);
	float(*const kbEscrowGetPercentage)(int, int) = reinterpret_cast<float(*)(int, int)>(0x882b3f);
	bool(*const kbEscrowSetPercentage)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x882b81);
	bool(*const kbEscrowSetCap)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x882bc4);
	float(*const kbEscrowGetAmount)(int, int) = reinterpret_cast<float(*)(int, int)>(0x882c07);
	bool(*const kbEscrowFlush)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x882c49);
	bool(*const kbEscrowAllocateCurrentResources)() = reinterpret_cast<bool(*)()>(0x882c8c);
	int(*const kbBuildingPlacementCreate)(string) = reinterpret_cast<int(*)(string)>(0x882cc2);
	bool(*const kbBuildingPlacementDestroy)(int) = reinterpret_cast<bool(*)(int)>(0x882cfc);
	bool(*const kbBuildingPlacementResetResults)() = reinterpret_cast<bool(*)()>(0x882d35);
	bool(*const kbBuildingPlacementSelect)(int) = reinterpret_cast<bool(*)(int)>(0x882d68);
	bool(*const kbBuildingPlacementSetEventHandler)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x882da1);
	bool(*const kbBuildingPlacementSetBuildingType)(int) = reinterpret_cast<bool(*)(int)>(0x882e3e);
	bool(*const kbBuildingPlacementSetBaseID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x882e77);
	bool(*const kbBuildingPlacementAddAreaID)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x882eb5);
	bool(*const kbBuildingPlacementAddAreaGroupID)(int) = reinterpret_cast<bool(*)(int)>(0x882ef8);
	bool(*const kbBuildingPlacementSetCenterPosition)(vector, float, float) = reinterpret_cast<bool(*)(vector, float, float)>(0x882f31);
	bool(*const kbBuildingPlacementAddUnitInfluence)(int, float, float, int) = reinterpret_cast<bool(*)(int, float, float, int)>(0x882f74);
	bool(*const kbBuildingPlacementAddPositionInfluence)(vector, float, float) = reinterpret_cast<bool(*)(vector, float, float)>(0x882fbc);
	bool(*const kbBuildingPlacementSetMinimumValue)(float) = reinterpret_cast<bool(*)(float)>(0x882fff);
	bool(*const kbBuildingPlacementStart)() = reinterpret_cast<bool(*)()>(0x883038);
	vector(*const kbBuildingPlacementGetResultPosition)(vector, int) = reinterpret_cast<vector(*)(vector, int)>(0x88306b);
	float(*const kbBuildingPlacementGetResultValue)(int) = reinterpret_cast<float(*)(int)>(0x8830da);
	int(*const kbTargetSelectorCreate)(string) = reinterpret_cast<int(*)(string)>(0x883117);
	bool(*const kbTargetSelectorDestroy)(int) = reinterpret_cast<bool(*)(int)>(0x883151);
	bool(*const kbTargetSelectorResetResults)() = reinterpret_cast<bool(*)()>(0x88318a);
	bool(*const kbTargetSelectorSelect)(int) = reinterpret_cast<bool(*)(int)>(0x8831bd);
	bool(*const kbTargetSelectorAddUnitType)(int) = reinterpret_cast<bool(*)(int)>(0x8831f6);
	bool(*const kbTargetSelectorAddQueryResults)(int) = reinterpret_cast<bool(*)(int)>(0x88322f);
	int(*const kbTargetSelectorGetNumberResults)() = reinterpret_cast<int(*)()>(0x883268);
	int(*const kbTargetSelectorGetResultValue)(int) = reinterpret_cast<int(*)(int)>(0x88329b);
	bool(*const kbTargetSelectorStart)() = reinterpret_cast<bool(*)()>(0x8832d5);
	bool(*const kbSetupForResource)(int, int, float, float) = reinterpret_cast<bool(*)(int, int, float, float)>(0x883308);
	int(*const kbGetHCLevel)(int) = reinterpret_cast<int(*)(int)>(0x883350);
	int(*const kbResourceGetXP)(int) = reinterpret_cast<int(*)(int)>(0x883378);
	float(*const kbResourceGet)(int) = reinterpret_cast<float(*)(int)>(0x8833a0);
	float(*const kbMaximumResourceGet)(int) = reinterpret_cast<float(*)(int)>(0x8833dd);
	float(*const kbTotalResourceGet)(int) = reinterpret_cast<float(*)(int)>(0x88341a);
	int(*const kbGetNumberValidResourcesByPlan)(int, int) = reinterpret_cast<int(*)(int, int)>(0x883457);
	int(*const kbGetNumberValidResources)(int, int, int, float) = reinterpret_cast<int(*)(int, int, int, float)>(0x883495);
	float(*const kbGetAmountValidResources)(int, int, int, float) = reinterpret_cast<float(*)(int, int, int, float)>(0x8834dd);
	float(*const kbGetResourceIncome)(int, float, bool) = reinterpret_cast<float(*)(int, float, bool)>(0x883529);
	bool(*const kbProtoUnitAvailable)(int) = reinterpret_cast<bool(*)(int)>(0x883570);
	int(*const kbGetProtoUnitID)(string) = reinterpret_cast<int(*)(string)>(0x8835b6);
	int(*const kbUnitGetProtoUnitID)(int) = reinterpret_cast<int(*)(int)>(0x8852d1);
	bool(*const kbCanAffordUnit)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8835d3);
	float(*const kbUnitCostPerResource)(int, int) = reinterpret_cast<float(*)(int, int)>(0x883613);
	bool(*const kbCanAffordTech)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x883689);
	float(*const kbTechCostPerResource)(int, int) = reinterpret_cast<float(*)(int, int)>(0x8836c7);
	bool(*const kbProtoUnitIsType)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x883710);
	int(*const kbTechGetStatus)(int) = reinterpret_cast<int(*)(int)>(0x883753);
	float(*const kbGetTechPercentComplete)(int) = reinterpret_cast<float(*)(int)>(0x88378e);
	float(*const kbGetCombatEfficiency)(int, int, int, int) = reinterpret_cast<float(*)(int, int, int, int)>(0x8837c7);
	float(*const kbGetAICostWeight)(int) = reinterpret_cast<float(*)(int)>(0x883813);
	bool(*const kbSetAICostWeight)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x883850);
	float(*const kbGetProtoUnitAICost)(int) = reinterpret_cast<float(*)(int)>(0x88388e);
	float(*const kbGetTechAICost)(int) = reinterpret_cast<float(*)(int)>(0x8838cb);
	bool(*const kbIsPlayerResigned)(int) = reinterpret_cast<bool(*)(int)>(0x883908);
	bool(*const kbHasPlayerLost)(int) = reinterpret_cast<bool(*)(int)>(0x883937);
	int(*const kbGetPlayerTeam)(int) = reinterpret_cast<int(*)(int)>(0x88396e);
	string(*const kbGetPlayerName)(int) = reinterpret_cast<string(*)(int)>(0x883999);
	bool(*const kbIsPlayerEnemy)(int) = reinterpret_cast<bool(*)(int)>(0x8839ce);
	bool(*const kbIsPlayerNeutral)(int) = reinterpret_cast<bool(*)(int)>(0x883a27);
	bool(*const kbIsPlayerAlly)(int) = reinterpret_cast<bool(*)(int)>(0x883a5d);
	bool(*const kbIsPlayerMutualAlly)(int) = reinterpret_cast<bool(*)(int)>(0x883ab6);
	int(*const kbGetNumberMutualAllies)() = reinterpret_cast<int(*)()>(0x88530e);
	bool(*const kbIsPlayerValid)(int) = reinterpret_cast<bool(*)(int)>(0x88537b);
	bool(*const kbIsPlayerHuman)(int) = reinterpret_cast<bool(*)(int)>(0x883aec);
	float(*const kbGetPlayerHandicap)(int) = reinterpret_cast<float(*)(int)>(0x883b20);
	void(*const kbSetPlayerHandicap)(int, float) = reinterpret_cast<void(*)(int, float)>(0x883b4b);
	bool(*const kbIsGameOver)() = reinterpret_cast<bool(*)()>(0x883b73);
	vector(*const kbGetTownLocation)(vector) = reinterpret_cast<vector(*)(vector)>(0x883b86);
	int(*const kbGetTownAreaID)() = reinterpret_cast<int(*)()>(0x883bf0);
	bool(*const kbSetTownLocation)(vector) = reinterpret_cast<bool(*)(vector)>(0x883c24);
	bool(*const kbGetAutoBaseCreate)() = reinterpret_cast<bool(*)()>(0x883c5f);
	void(*const kbSetAutoBaseCreate)(bool) = reinterpret_cast<void(*)(bool)>(0x883c92);
	float(*const kbGetAutoBaseCreateDistance)() = reinterpret_cast<float(*)()>(0x883cc6);
	void(*const kbSetAutoBaseCreateDistance)(float) = reinterpret_cast<void(*)(float)>(0x883cfd);
	bool(*const kbGetAutoBaseDetect)() = reinterpret_cast<bool(*)()>(0x883d31);
	void(*const kbSetAutoBaseDetect)(bool) = reinterpret_cast<void(*)(bool)>(0x883d64);
	float(*const kbGetAutoBaseDetectDistance)() = reinterpret_cast<float(*)()>(0x883d98);
	void(*const kbSetAutoBaseDetectDistance)(float) = reinterpret_cast<void(*)(float)>(0x883dcf);
	int(*const kbFindClosestBase)(int, vector) = reinterpret_cast<int(*)(int, vector)>(0x883e03);
	int(*const kbBaseGetNextID)() = reinterpret_cast<int(*)()>(0x883e53);
	int(*const kbBaseGetNumber)(int) = reinterpret_cast<int(*)(int)>(0x883e86);
	int(*const kbBaseGetIDByIndex)(int, int) = reinterpret_cast<int(*)(int, int)>(0x883ebf);
	int(*const kbBaseCreate)(int, string, vector, float) = reinterpret_cast<int(*)(int, string, vector, float)>(0x883f03);
	int(*const kbBaseFindCreateResourceBase)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x883f51);
	int(*const kbBaseFindForwardMilitaryBase)(int, int, int) = reinterpret_cast<int(*)(int, int, int)>(0x883f9a);
	bool(*const kbBaseDestroy)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x883fe3);
	void(*const kbBaseDestroyAll)(int) = reinterpret_cast<void(*)(int)>(0x884021);
	vector(*const kbBaseGetLocation)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x884057);
	vector(*const kbBaseGetLastKnownDamageLocation)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x8840d2);
	int(*const kbBaseGetOwner)(int) = reinterpret_cast<int(*)(int)>(0x88539d);
	bool(*const kbBaseSetFrontVector)(int, int, vector) = reinterpret_cast<bool(*)(int, int, vector)>(0x885446);
	vector(*const kbBaseGetFrontVector)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x88414f);
	vector(*const kbBaseGetBackVector)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x8841ca);
	int(*const kbBaseGetTimeUnderAttack)(int, int) = reinterpret_cast<int(*)(int, int)>(0x884245);
	bool(*const kbBaseGetUnderAttack)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x885508);
	bool(*const kbBaseSetActive)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x885560);
	bool(*const kbBaseGetActive)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8855b5);
	int(*const kbBaseGetMainID)(int) = reinterpret_cast<int(*)(int)>(0x88429a);
	bool(*const kbBaseSetMain)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x88560d);
	bool(*const kbBaseGetMain)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x885662);
	bool(*const kbBaseSetForward)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x8856ba);
	bool(*const kbBaseGetForward)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x88570f);
	bool(*const kbBaseSetSettlement)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x885767);
	bool(*const kbBaseGetSettlement)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8857bc);
	bool(*const kbBaseSetMilitary)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x885814);
	bool(*const kbBaseGetMilitary)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x885869);
	vector(*const kbBaseGetMilitaryGatherPoint)(vector, int, int) = reinterpret_cast<vector(*)(vector, int, int)>(0x8842d4);
	bool(*const kbBaseSetMilitaryGatherPoint)(int, int, vector) = reinterpret_cast<bool(*)(int, int, vector)>(0x884351);
	bool(*const kbBaseSetEconomy)(int, int, bool) = reinterpret_cast<bool(*)(int, int, bool)>(0x8858c1);
	bool(*const kbBaseGetEconomy)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x885916);
	float(*const kbBaseGetMaximumResourceDistance)(int, int) = reinterpret_cast<float(*)(int, int)>(0x88439f);
	void(*const kbBaseSetMaximumResourceDistance)(int, int, float) = reinterpret_cast<void(*)(int, int, float)>(0x8843e9);
	bool(*const kbBaseAddUnit)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x884430);
	bool(*const kbBaseRemoveUnit)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x884492);
	int(*const kbBaseGetNumberUnits)(int, int, int, int) = reinterpret_cast<int(*)(int, int, int, int)>(0x8844f4);
	bool(*const kbUnitVisible)(int) = reinterpret_cast<bool(*)(int)>(0x88596e);
	bool(*const kbLocationVisible)(vector) = reinterpret_cast<bool(*)(vector)>(0x88454b);
	vector(*const kbGetBlockPosition)(vector, string) = reinterpret_cast<vector(*)(vector, string)>(0x88457a);
	int(*const kbGetBlockID)(string) = reinterpret_cast<int(*)(string)>(0x8845d6);
	int(*const kbGetRandomEnabledPUID)(int, int) = reinterpret_cast<int(*)(int, int)>(0x8845fb);
	int(*const kbUnitPickCreate)(string) = reinterpret_cast<int(*)(string)>(0x884748);
	bool(*const kbUnitPickDestroy)(int) = reinterpret_cast<bool(*)(int)>(0x884787);
	bool(*const kbUnitPickResetAll)(int) = reinterpret_cast<bool(*)(int)>(0x88463a);
	bool(*const kbUnitPickResetResults)(int) = reinterpret_cast<bool(*)(int)>(0x88467e);
	float(*const kbUnitPickGetPreferenceWeight)(int) = reinterpret_cast<float(*)(int)>(0x8846c2);
	bool(*const kbUnitPickSetPreferenceWeight)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x884704);
	bool(*const kbUnitPickSetEnemyPlayerID)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x8847c0);
	bool(*const kbUnitPickSetCombatEfficiencyWeight)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x884804);
	bool(*const kbUnitPickResetCombatEfficiencyTypes)(int) = reinterpret_cast<bool(*)(int)>(0x884848);
	bool(*const kbUnitPickAddCombatEfficiencyType)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x88488c);
	bool(*const kbUnitPickSetCostWeight)(int, float) = reinterpret_cast<bool(*)(int, float)>(0x8848da);
	bool(*const kbUnitPickSetMovementType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x88491e);
	bool(*const kbUnitPickSetDesiredNumberUnitTypes)(int, int, int, bool) = reinterpret_cast<bool(*)(int, int, int, bool)>(0x884962);
	int(*const kbUnitPickGetDesiredNumberUnitTypes)(int) = reinterpret_cast<int(*)(int)>(0x8849b5);
	bool(*const kbUnitPickSetDesiredNumberBuildings)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x8849f4);
	int(*const kbUnitPickGetDesiredNumberBuildings)(int, int) = reinterpret_cast<int(*)(int, int)>(0x884a42);
	bool(*const kbUnitPickSetMinimumNumberUnits)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x884a8a);
	int(*const kbUnitPickGetMinimumNumberUnits)(int) = reinterpret_cast<int(*)(int)>(0x884ace);
	bool(*const kbUnitPickSetMaximumNumberUnits)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x884b0d);
	int(*const kbUnitPickGetMaximumNumberUnits)(int) = reinterpret_cast<int(*)(int)>(0x884b51);
	bool(*const kbUnitPickSetMinimumPop)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x884b90);
	int(*const kbUnitPickGetMinimumPop)(int) = reinterpret_cast<int(*)(int)>(0x884bd4);
	bool(*const kbUnitPickSetMaximumPop)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x884c13);
	int(*const kbUnitPickGetMaximumPop)(int) = reinterpret_cast<int(*)(int)>(0x884c57);
	bool(*const kbUnitPickSetAttackUnitType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x884c96);
	int(*const kbUnitPickGetAttackUnitType)(int) = reinterpret_cast<int(*)(int)>(0x884cdd);
	bool(*const kbUnitPickSetGoalCombatEfficiencyType)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x884d1f);
	int(*const kbUnitPickGetGoalCombatEfficiencyType)(int) = reinterpret_cast<int(*)(int)>(0x884d66);
	bool(*const kbUnitPickSetPreferenceFactor)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x884da8);
	bool(*const kbUnitPickAdjustPreferenceFactor)(int, int, float) = reinterpret_cast<bool(*)(int, int, float)>(0x884df6);
	int(*const kbUnitPickRun)(int) = reinterpret_cast<int(*)(int)>(0x884e44);
	int(*const kbUnitPickGetNumberResults)(int) = reinterpret_cast<int(*)(int)>(0x884e85);
	int(*const kbUnitPickGetResult)(int, int) = reinterpret_cast<int(*)(int, int)>(0x884ec6);
	int(*const kbFindAreaGroup)(int, float, int) = reinterpret_cast<int(*)(int, float, int)>(0x884f0d);
	int(*const kbFindAreaGroupByLocation)(int, float, float) = reinterpret_cast<int(*)(int, float, float)>(0x884f5c);
	int(*const kbFindBestBuildingToRepair)(vector, float, float, int) = reinterpret_cast<int(*)(vector, float, float, int)>(0x884fa0);
	void(*const kbSetForwardBasePosition)(vector) = reinterpret_cast<void(*)(vector)>(0x884fed);
	void(*const kbSetTargetSelectorFactor)(int, float) = reinterpret_cast<void(*)(int, float)>(0x885034);
	float(*const kbGetTargetSelectorFactor)(int) = reinterpret_cast<float(*)(int)>(0x88506f);
	string(*const kbGetTechName)(int) = reinterpret_cast<string(*)(int)>(0x897a7d);
	string(*const kbGetProtoUnitName)(int) = reinterpret_cast<string(*)(int)>(0x897804);
	int(*const kbGetUnitBaseTypeID)(int) = reinterpret_cast<int(*)(int)>(0x897a40);
	string(*const kbGetUnitTypeName)(int) = reinterpret_cast<string(*)(int)>(0x897aaf);
	int(*const kbCreateUnitProgression)(string, string) = reinterpret_cast<int(*)(string, string)>(0x897823);
	int(*const kbCreateTechProgression)(string, string) = reinterpret_cast<int(*)(string, string)>(0x897ae1);
	int(*const kbTechTreeGetCheapestUnitUpgrade)(int) = reinterpret_cast<int(*)(int)>(0x897867);
	int(*const kbTechTreeGetCheapestEconUpgrade)(int) = reinterpret_cast<int(*)(int)>(0x8978a8);
	void(*const kbTechTreeDump)() = reinterpret_cast<void(*)()>(0x8978e9);
	int(*const kbProgressionGetTotalNodes)(int) = reinterpret_cast<int(*)(int)>(0x8926b6);
	float(*const kbProgessionGetTotalResourceCost)(int, int) = reinterpret_cast<float(*)(int, int)>(0x89253b);
	int(*const kbProgressionGetNodeType)(int, int) = reinterpret_cast<int(*)(int, int)>(0x892605);
	int(*const kbProgressionGetNodeData)(int, int) = reinterpret_cast<int(*)(int, int)>(0x89265e);
	void(*const trDelayedRuleActivation)(string) = reinterpret_cast<void(*)(string)>(0x97f4ea);
	int(*const trTime)() = reinterpret_cast<int(*)()>(0x97f558);
	int(*const trTimeMS)() = reinterpret_cast<int(*)()>(0x97f57c);
	void(*const trUnitSelectClear)() = reinterpret_cast<void(*)()>(0x982194);
	void(*const trUnitSelect)(string) = reinterpret_cast<void(*)(string)>(0x97f601);
	void(*const trUnitSelectByID)(int) = reinterpret_cast<void(*)(int)>(0x9821bb);
	bool(*const trPlayerControlsSocket)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x982203);
	bool(*const trIsPlayerVisitingHC)(int) = reinterpret_cast<bool(*)(int)>(0x97f636);
	bool(*const trIsPlayerSelectingHCBuilding)(string) = reinterpret_cast<bool(*)(string)>(0x97f687);
	bool(*const trHasPlayerSentHCShipment)(int) = reinterpret_cast<bool(*)(int)>(0x97f6f3);
	bool(*const trIsPlayerSendingHCShipment)(int) = reinterpret_cast<bool(*)(int)>(0x97f734);
	bool(*const trObjectGettingWorked)(string) = reinterpret_cast<bool(*)(string)>(0x982299);
	bool(*const trUnitMoveToPoint)(float, float, float, int, bool, bool, float) = reinterpret_cast<bool(*)(float, float, float, int, bool, bool, float)>(0x98674c);
	bool(*const trUnitMoveToUnit)(string, int, bool, bool, float) = reinterpret_cast<bool(*)(string, int, bool, bool, float)>(0x986909);
	void(*const trSetRevealerActiveState)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x97f7df);
	void(*const trCreateRevealer)(int, string, vector, float, bool) = reinterpret_cast<void(*)(int, string, vector, float, bool)>(0x97f844);
	bool(*const trUnitMoveFromArea)(float, float, float, int, bool, int, string, float) = reinterpret_cast<bool(*)(float, float, float, int, bool, int, string, float)>(0x987fd5);
	bool(*const trUnitBuildUnit)(string, vector) = reinterpret_cast<bool(*)(string, vector)>(0x986ac3);
	bool(*const trUnitDoWorkOnUnit)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x986d85);
	void(*const trShowDamage)(string, string, string, string) = reinterpret_cast<void(*)(string, string, string, string)>(0x986f58);
	bool(*const trUnitGarrison)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x98750f);
	void(*const trPlayerSetAge)(int, int, bool) = reinterpret_cast<void(*)(int, int, bool)>(0x97f8ba);
	void(*const trPlayerSetHCAccess)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x97f8eb);
	void(*const trShowHCView)(int) = reinterpret_cast<void(*)(int)>(0x97f93c);
	void(*const trShowWorldView)(int) = reinterpret_cast<void(*)(int)>(0x97f97d);
	bool(*const trImmediateUnitGarrison)(string) = reinterpret_cast<bool(*)(string)>(0x9876da);
	float(*const trUnitDistanceToPoint)(float, float, float) = reinterpret_cast<float(*)(float, float, float)>(0x9822cc);
	float(*const trUnitDistanceToUnit)(string) = reinterpret_cast<float(*)(string)>(0x982440);
	float(*const trUnitDistanceToUnitID)(int) = reinterpret_cast<float(*)(int)>(0x98246e);
	float(*const trCountUnitsInArea)(string, int, string, float) = reinterpret_cast<float(*)(string, int, string, float)>(0x98832f);
	void(*const trUnitCinematicRemoveControlAction)() = reinterpret_cast<void(*)()>(0x9824b1);
	bool(*const trUnitSetAnimation)(string, int, bool, int, bool) = reinterpret_cast<bool(*)(string, int, bool, int, bool)>(0x98251a);
	bool(*const trUnitAlive)() = reinterpret_cast<bool(*)()>(0x982651);
	bool(*const trUnitDead)() = reinterpret_cast<bool(*)()>(0x9826df);
	bool(*const trUnitDelete)(bool) = reinterpret_cast<bool(*)(bool)>(0x982771);
	void(*const trUnitDestroy)() = reinterpret_cast<void(*)()>(0x98282f);
	bool(*const trUnitCreate)(string, string, float, float, float, int, int) = reinterpret_cast<bool(*)(string, string, float, float, float, int, int)>(0x97f9b6);
	int(*const trUnitGetHeading)(string) = reinterpret_cast<int(*)(string)>(0x97fb54);
	bool(*const trUnitSetHeading)(int) = reinterpret_cast<bool(*)(int)>(0x9828fc);
	int(*const trUnitSetHP)(float) = reinterpret_cast<int(*)(float)>(0x982a23);
	bool(*const trUnitVisToPlayer)() = reinterpret_cast<bool(*)()>(0x982ae9);
	bool(*const trUnitHasLOS)(int) = reinterpret_cast<bool(*)(int)>(0x982ba5);
	void(*const trUnitConvert)(int) = reinterpret_cast<void(*)(int)>(0x982c42);
	int(*const trUnitPercentComplete)() = reinterpret_cast<int(*)()>(0x982cd1);
	int(*const trUnitPercentDamaged)() = reinterpret_cast<int(*)()>(0x982d39);
	void(*const trUnitTeleport)(float, float, float) = reinterpret_cast<void(*)(float, float, float)>(0x982da7);
	void(*const trUnitHighlight)(float, bool) = reinterpret_cast<void(*)(float, bool)>(0x982e9e);
	void(*const trUnitChangeProtoUnit)(string) = reinterpret_cast<void(*)(string)>(0x982f9e);
	int(*const trUnitGetContained)() = reinterpret_cast<int(*)()>(0x9831d8);
	bool(*const trUnitGetIsContained)(string) = reinterpret_cast<bool(*)(string)>(0x98320d);
	int(*const trUnitEjectContained)() = reinterpret_cast<int(*)()>(0x98328c);
	bool(*const trUnitIsSelected)() = reinterpret_cast<bool(*)()>(0x9832d1);
	bool(*const trUnitTypeIsSelected)(string) = reinterpret_cast<bool(*)(string)>(0x983333);
	bool(*const trUnitIsOwnedBy)(int) = reinterpret_cast<bool(*)(int)>(0x9833f2);
	void(*const trUnitSetStance)(string) = reinterpret_cast<void(*)(string)>(0x983489);
	void(*const trCameraCut)(vector, vector, vector, vector) = reinterpret_cast<void(*)(vector, vector, vector, vector)>(0x97fbca);
	void(*const trWaypointClear)() = reinterpret_cast<void(*)()>(0x983598);
	void(*const trWaypointAddPoint)(vector) = reinterpret_cast<void(*)(vector)>(0x97fc78);
	void(*const trWaypointAddUnit)(string) = reinterpret_cast<void(*)(string)>(0x97fcb8);
	int(*const trCurrentPlayer)() = reinterpret_cast<int(*)()>(0x96db85);
	void(*const trSetCurrentPlayerStatus)(bool) = reinterpret_cast<void(*)(bool)>(0x97f5ca);
	void(*const trSetUserControls)(bool) = reinterpret_cast<void(*)(bool)>(0x97f5e4);
	int(*const trPlayerUnitCount)(int) = reinterpret_cast<int(*)(int)>(0x98081a);
	int(*const trPlayerBuildingCount)(int) = reinterpret_cast<int(*)(int)>(0x980893);
	int(*const trPlayerUnitAndBuildingCount)(int) = reinterpret_cast<int(*)(int)>(0x980782);
	int(*const trPlayerUnitCountSpecific)(int, string) = reinterpret_cast<int(*)(int, string)>(0x9808e2);
	int(*const trPlayerTribute)(int, string, int, int) = reinterpret_cast<int(*)(int, string, int, int)>(0x9884a5);
	void(*const trPlayerToggleAllowTCSpawning)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x980969);
	void(*const trPlayerToggleAllowNewCWSpawning)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x98098c);
	int(*const trPlayerResourceCount)(int, string) = reinterpret_cast<int(*)(int, string)>(0x988538);
	int(*const trPlayerCurrentXPCount)(int) = reinterpret_cast<int(*)(int)>(0x9809af);
	bool(*const trPlayerDefeated)(int) = reinterpret_cast<bool(*)(int)>(0x980a06);
	bool(*const trPlayerActive)(int) = reinterpret_cast<bool(*)(int)>(0x980a35);
	void(*const trSetPlayerDefeated)(int) = reinterpret_cast<void(*)(int)>(0x980a63);
	void(*const trSetPlayerWon)(int) = reinterpret_cast<void(*)(int)>(0x9843ff);
	void(*const trEndGame)() = reinterpret_cast<void(*)()>(0x980a86);
	void(*const trPlayerSetDiplomacy)(int, int, string) = reinterpret_cast<void(*)(int, int, string)>(0x980a94);
	string(*const trPlayerGetDiplomacy)(int, int) = reinterpret_cast<string(*)(int, int)>(0x980b55);
	void(*const trPlayerModifyLOS)(int, bool, int) = reinterpret_cast<void(*)(int, bool, int)>(0x984488);
	int(*const trPlayerCountBuildingInProgress)(int, string) = reinterpret_cast<int(*)(int, string)>(0x980ba2);
	bool(*const trBuildingIsOnCursor)(string) = reinterpret_cast<bool(*)(string)>(0x9885ce);
	int(*const trPlayerSetActive)(int) = reinterpret_cast<int(*)(int)>(0x9844cc);
	void(*const trObjectiveComplete)(int, bool, bool) = reinterpret_cast<void(*)(int, bool, bool)>(0x980bf8);
	void(*const trObjectiveHide)(int) = reinterpret_cast<void(*)(int)>(0x980c55);
	void(*const trObjectiveShow)(int) = reinterpret_cast<void(*)(int)>(0x980c83);
	void(*const trObjectiveDiscover)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x980cb1);
	bool(*const trPlayerAtPopCap)(int) = reinterpret_cast<bool(*)(int)>(0x980ce4);
	int(*const trPlayerGetPopulation)(int) = reinterpret_cast<int(*)(int)>(0x980d2c);
	void(*const trSetCinematicUnitSpeaking)(string, bool, int) = reinterpret_cast<void(*)(string, bool, int)>(0x97f775);
	bool(*const trEventSetHandler)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x97fced);
	void(*const trEventFire)(int) = reinterpret_cast<void(*)(int)>(0x97fd19);
	void(*const trSetUnitIdleProcessing)(bool) = reinterpret_cast<void(*)(bool)>(0x97f596);
	void(*const trSetObscuredUnits)(bool) = reinterpret_cast<void(*)(bool)>(0x97f5b0);
	void(*const trLetterBox)(bool) = reinterpret_cast<void(*)(bool)>(0x97fda3);
	void(*const trSoundPlayFN)(string, string, int, string, string) = reinterpret_cast<void(*)(string, string, int, string, string)>(0x9835bf);
	void(*const trSoundPlayPaused)(string, string, int, string, string) = reinterpret_cast<void(*)(string, string, int, string, string)>(0x9836bd);
	void(*const trSoundTimer)(int, int) = reinterpret_cast<void(*)(int, int)>(0x9837bb);
	void(*const trFadeOutMusic)(float) = reinterpret_cast<void(*)(float)>(0x97fe22);
	void(*const trPlayNextMusicTrack)() = reinterpret_cast<void(*)()>(0x97fe42);
	void(*const trFadeOutAllSounds)(float) = reinterpret_cast<void(*)(float)>(0x97fe62);
	void(*const trBlockAllSounds)(bool) = reinterpret_cast<void(*)(bool)>(0x97fe99);
	void(*const trUnblockAllSounds)() = reinterpret_cast<void(*)()>(0x97fec8);
	void(*const trBlockAllAmbientSounds)() = reinterpret_cast<void(*)()>(0x97fee7);
	void(*const trUnBlockAllAmbientSounds)() = reinterpret_cast<void(*)()>(0x97ff09);
	void(*const trSoundPlayDialog)(string, string, int, bool, string, string) = reinterpret_cast<void(*)(string, string, int, bool, string, string)>(0x98395c);
	void(*const trSoundPlayDialogue)(string, int, bool, int) = reinterpret_cast<void(*)(string, int, bool, int)>(0x983a5a);
	void(*const trMusicPlay)(string, string, float) = reinterpret_cast<void(*)(string, string, float)>(0x983877);
	void(*const trMusicPlayCurrent)() = reinterpret_cast<void(*)()>(0x97ff2b);
	void(*const trMusicStop)() = reinterpret_cast<void(*)()>(0x97ff4d);
	void(*const trMusicSetCurrentMusicSet)(int) = reinterpret_cast<void(*)(int)>(0x97ff68);
	void(*const trMusicSetMood)(int) = reinterpret_cast<void(*)(int)>(0x97ff94);
	void(*const trCamTrackLoad)(string) = reinterpret_cast<void(*)(string)>(0x97ffb7);
	void(*const trCamTrackPlay)(float, int) = reinterpret_cast<void(*)(float, int)>(0x983f5b);
	void(*const trMessageSetText)(string, int) = reinterpret_cast<void(*)(string, int)>(0x983fcd);
	void(*const trChatSetStatus)(bool) = reinterpret_cast<void(*)(bool)>(0x97ffce);
	void(*const trChatSend)(int, string) = reinterpret_cast<void(*)(int, string)>(0x984019);
	void(*const trChatSendToPlayer)(int, int, string) = reinterpret_cast<void(*)(int, int, string)>(0x98405e);
	void(*const trChatSendSpoofed)(int, string) = reinterpret_cast<void(*)(int, string)>(0x9840b3);
	void(*const trChatSendSpoofedToPlayer)(int, int, string) = reinterpret_cast<void(*)(int, int, string)>(0x98419d);
	void(*const trWriteToLog)(string) = reinterpret_cast<void(*)(string)>(0x97ffdf);
	void(*const trGamePause)(bool) = reinterpret_cast<void(*)(bool)>(0x97fff8);
	void(*const trGameLoadScenario)(string) = reinterpret_cast<void(*)(string)>(0x980016);
	void(*const trBranchScenario)(string) = reinterpret_cast<void(*)(string)>(0x984289);
	bool(*const trTechStatusActive)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x98005c);
	bool(*const trTechStatusResearching)(int, int) = reinterpret_cast<bool(*)(int, int)>(0x98008f);
	bool(*const trTechStatusCheck)(int, int, int) = reinterpret_cast<bool(*)(int, int, int)>(0x9800c2);
	void(*const trTechSetStatus)(int, int, int) = reinterpret_cast<void(*)(int, int, int)>(0x980124);
	void(*const trYouWin)(bool) = reinterpret_cast<void(*)(bool)>(0x980180);
	void(*const trYouLose)(string) = reinterpret_cast<void(*)(string)>(0x98434c);
	void(*const trShowWinLose)(string, string, string, bool) = reinterpret_cast<void(*)(string, string, string, bool)>(0x9843a2);
	void(*const trRenderSky)(bool, string) = reinterpret_cast<void(*)(bool, string)>(0x980653);
	void(*const trRenderSnow)(float) = reinterpret_cast<void(*)(float)>(0x98068c);
	void(*const trRenderRain)(float) = reinterpret_cast<void(*)(float)>(0x9806ed);
	void(*const trSetFogAndBlackmap)(bool, bool) = reinterpret_cast<void(*)(bool, bool)>(0x98074e);
	void(*const trStartGameRecord)(string) = reinterpret_cast<void(*)(string)>(0x980db3);
	void(*const trStopGameRecord)() = reinterpret_cast<void(*)()>(0x980dec);
	void(*const trArmySelect)(string) = reinterpret_cast<void(*)(string)>(0x980dfb);
	void(*const trArmySelectInt)(int, int) = reinterpret_cast<void(*)(int, int)>(0x980e4a);
	bool(*const trArmyDispatch)(string, string, int, float, float, float, int, bool) = reinterpret_cast<bool(*)(string, string, int, float, float, float, int, bool)>(0x980e73);
	void(*const trSetLighting)(string, float) = reinterpret_cast<void(*)(string, float)>(0x981040);
	void(*const trCounterAddTime)(string, int, int, string, int) = reinterpret_cast<void(*)(string, int, int, string, int)>(0x981f80);
	void(*const trCounterAddTimeMs)(string, int, int, string, int) = reinterpret_cast<void(*)(string, int, int, string, int)>(0x9820b4);
	void(*const trCounterAddUnit)(string, int, int, string, string, int) = reinterpret_cast<void(*)(string, int, int, string, string, int)>(0x986462);
	void(*const trCounterAddXP)(string, int, int, string, int) = reinterpret_cast<void(*)(string, int, int, string, int)>(0x9865ee);
	void(*const trCounterAbort)(string) = reinterpret_cast<void(*)(string)>(0x97f436);
	bool(*const trCinematicAbort)() = reinterpret_cast<bool(*)()>(0x981088);
	void(*const trCinematicDoAbort)() = reinterpret_cast<void(*)()>(0x9810a1);
	void(*const trForceNonCinematicModels)(bool) = reinterpret_cast<void(*)(bool)>(0x97fd67);
	void(*const trFormationScale)(float) = reinterpret_cast<void(*)(float)>(0x97fd85);
	int(*const trGetNumberNuggetsGathered)(int) = reinterpret_cast<int(*)(int)>(0x98159a);
	bool(*const trHasNuggetBeenCollected)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x9815c1);
	void(*const trUIFlash)(string, int, float, float, float) = reinterpret_cast<void(*)(string, int, float, float, float)>(0x9856f8);
	void(*const trUIStopFlash)(string) = reinterpret_cast<void(*)(string)>(0x9858c6);
	void(*const trUIFlashTech)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x981527);
	void(*const trUIFlashTrain)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x981550);
	void(*const trUIFadeToColor)(int, int, int, int, int, bool, int) = reinterpret_cast<void(*)(int, int, int, int, int, bool, int)>(0x9810fb);
	void(*const trRateConstruction)(float) = reinterpret_cast<void(*)(float)>(0x9811dd);
	void(*const trRateTrain)(float) = reinterpret_cast<void(*)(float)>(0x981228);
	void(*const trRateResearch)(float) = reinterpret_cast<void(*)(float)>(0x981273);
	void(*const trRatesNormal)() = reinterpret_cast<void(*)()>(0x9812be);
	void(*const trMinimapFlare)(int, float, vector, bool) = reinterpret_cast<void(*)(int, float, vector, bool)>(0x9812eb);
	void(*const trCameraShake)(float, float) = reinterpret_cast<void(*)(float, float)>(0x98136f);
	void(*const trPlayerResetBlackMap)(int) = reinterpret_cast<void(*)(int)>(0x980d57);
	void(*const trPlayerResetBlackMapForAllPlayers)() = reinterpret_cast<void(*)()>(0x9844f9);
	void(*const trPlayerKillAllUnits)(int) = reinterpret_cast<void(*)(int)>(0x9878a6);
	void(*const trPlayerKillAllBuildings)(int) = reinterpret_cast<void(*)(int)>(0x9879a4);
	bool(*const trIsGadgetVisible)(string) = reinterpret_cast<bool(*)(string)>(0x981631);
	void(*const trModeEnter)(string) = reinterpret_cast<void(*)(string)>(0x981677);
	void(*const trPlayerGrantResources)(int, string, int) = reinterpret_cast<void(*)(int, string, int)>(0x988669);
	void(*const trUnitPlayerFakify)(int) = reinterpret_cast<void(*)(int)>(0x984589);
	void(*const trArmyPlayerFakify)(string, int) = reinterpret_cast<void(*)(string, int)>(0x984612);
	void(*const trUnitPlayerDefakify)() = reinterpret_cast<void(*)()>(0x9846e6);
	void(*const trArmyPlayerDefakify)(string) = reinterpret_cast<void(*)(string)>(0x98475e);
	void(*const trAIFunc)(int, string, int) = reinterpret_cast<void(*)(int, string, int)>(0x9813c1);
	int(*const trGetNumberSelectedUnitIDs)() = reinterpret_cast<int(*)()>(0x98452c);
	int(*const trGetSelectedUnitID)(int) = reinterpret_cast<int(*)(int)>(0x98454c);
	bool(*const trUnforbidProtounit)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x98169f);
	bool(*const trForbidProtounit)(int, string) = reinterpret_cast<bool(*)(int, string)>(0x981740);
	void(*const trSetPauseOnAgeUpgrade)(bool) = reinterpret_cast<void(*)(bool)>(0x981afc);
	void(*const trSetPauseInObjectiveWindow)(bool) = reinterpret_cast<void(*)(bool)>(0x981b1a);
	void(*const trSetCounterDisplay)(string) = reinterpret_cast<void(*)(string)>(0x9859c3);
	void(*const trClearCounterDisplay)() = reinterpret_cast<void(*)()>(0x981b38);
	void(*const trPlayMovie)(string) = reinterpret_cast<void(*)(string)>(0x981b84);
	bool(*const trIsMovieNotPlaying)() = reinterpret_cast<bool(*)()>(0x981b6f);
	void(*const trRevealEntireMap)() = reinterpret_cast<void(*)()>(0x981b98);
	void(*const trUnitChangeName)(string) = reinterpret_cast<void(*)(string)>(0x985a8f);
	bool(*const trChatHistoryContains)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x985bcc);
	void(*const trChatHistoryClear)() = reinterpret_cast<void(*)()>(0x981bc1);
	int(*const trGetStatValue)(int, int) = reinterpret_cast<int(*)(int, int)>(0x985c47);
	void(*const trEchoStatValue)(int, int) = reinterpret_cast<void(*)(int, int)>(0x985e08);
	void(*const trShowImageDialog)(string, string) = reinterpret_cast<void(*)(string, string)>(0x985e8d);
	void(*const trShowChoiceDialog)(string, string, int, string, int) = reinterpret_cast<void(*)(string, string, int, string, int)>(0x985ece);
	void(*const trModifyProtounit)(string, int, int, float) = reinterpret_cast<void(*)(string, int, int, float)>(0x985f6a);
	void(*const trDamageUnitPercent)(float) = reinterpret_cast<void(*)(float)>(0x98605a);
	void(*const trDamageUnit)(float) = reinterpret_cast<void(*)(float)>(0x98618b);
	void(*const trDamageUnitsInArea)(int, string, float, float) = reinterpret_cast<void(*)(int, string, float, float)>(0x988937);
	void(*const trOverlayText)(string, float, int, int, int, string) = reinterpret_cast<void(*)(string, float, int, int, int, string)>(0x98629a);
	void(*const trQuestVarSet)(string, float) = reinterpret_cast<void(*)(string, float)>(0x9817ef);
	void(*const trQuestVarCopy)(string, string) = reinterpret_cast<void(*)(string, string)>(0x98186a);
	void(*const trQuestVarSetFromRand)(string, float, float, bool) = reinterpret_cast<void(*)(string, float, float, bool)>(0x981946);
	float(*const trQuestVarGet)(string) = reinterpret_cast<float(*)(string)>(0x981a06);
	void(*const trQuestVarEcho)(string) = reinterpret_cast<void(*)(string)>(0x981a77);
	void(*const trGrantVP)(int, int) = reinterpret_cast<void(*)(int, int)>(0x981bdb);
	int(*const trPlayerVPCount)(int) = reinterpret_cast<int(*)(int)>(0x981cc3);
	void(*const trVPAnnualAwards)(bool) = reinterpret_cast<void(*)(bool)>(0x981d08);
	void(*const trCreateTreaty)(int, int, int, bool, bool, float, float, float) = reinterpret_cast<void(*)(int, int, int, bool, bool, float, float, float)>(0x981d2c);
	int(*const vcGetGameplayMode)() = reinterpret_cast<int(*)()>(0x981688);
	bool(*const vcCheckConquestVictory)() = reinterpret_cast<bool(*)()>(0x987c2a);
	bool(*const trUnitFaceUnit)(string, int) = reinterpret_cast<bool(*)(string, int)>(0x984819);
	void(*const trCameraLockOnUnit)(bool, int, int) = reinterpret_cast<void(*)(bool, int, int)>(0x984943);
	void(*const trCameraPanWithUnit)(bool, int) = reinterpret_cast<void(*)(bool, int)>(0x984997);
	void(*const trDisableTrigger)(int) = reinterpret_cast<void(*)(int)>(0x98140f);
	void(*const trUnitMakeInvulnerable)(bool) = reinterpret_cast<void(*)(bool)>(0x9849e5);
	void(*const trUnitSuspendAction)(string, bool) = reinterpret_cast<void(*)(string, bool)>(0x984a71);
	void(*const trCreateDefendPlan)(string, string, float, float, float, float, int, float) = reinterpret_cast<void(*)(string, string, float, float, float, float, int, float)>(0x984b77);
	void(*const trCreateAttackPlan)(string, string, int, float, float, float, float, int) = reinterpret_cast<void(*)(string, string, int, float, float, float, float, int)>(0x984d45);
	void(*const trKillAIPlan)(int, string) = reinterpret_cast<void(*)(int, string)>(0x9814d2);
	void(*const trAddArmyToPlan)(string, string) = reinterpret_cast<void(*)(string, string)>(0x984f2a);
	void(*const trDefendUnits)(string, string, string, int, float) = reinterpret_cast<void(*)(string, string, string, int, float)>(0x985038);
	void(*const trAttackUnits)(string, string, string) = reinterpret_cast<void(*)(string, string, string)>(0x985260);
	void(*const trAICommsAttackUnits)(int, string) = reinterpret_cast<void(*)(int, string)>(0x987aa1);
	void(*const trAICommsDefendPoint)(int, float, float, float) = reinterpret_cast<void(*)(int, float, float, float)>(0x985475);
	void(*const trAICommsRequestTribute)(int, string, float) = reinterpret_cast<void(*)(int, string, float)>(0x9886c0);
	void(*const trAICommsCancelOrder)(int) = reinterpret_cast<void(*)(int)>(0x98555a);
	void(*const trAICommsClaim)(int, float, float, float) = reinterpret_cast<void(*)(int, float, float, float)>(0x98561b);
	void(*const trAICommsTrain)(int, string) = reinterpret_cast<void(*)(int, string)>(0x988823);
	void(*const trTradeRouteSetPosition)(int, float) = reinterpret_cast<void(*)(int, float)>(0x981def);
	void(*const trTradeRouteToggleState)(int, bool) = reinterpret_cast<void(*)(int, bool)>(0x981e2f);
	void(*const trTradeRouteSetLevel)(int, int) = reinterpret_cast<void(*)(int, int)>(0x988ba4);
	void(*const trSetShadowFarClip)(bool, float) = reinterpret_cast<void(*)(bool, float)>(0x981e75);
	void(*const trShowSPCNote)(string, string) = reinterpret_cast<void(*)(string, string)>(0x986375);
	void(*const trPlayerOverrideArtCulture)(int, string) = reinterpret_cast<void(*)(int, string)>(0x9863da);
	void(*const trPlayerOverrideSoundCiv)(int, string) = reinterpret_cast<void(*)(int, string)>(0x981e9d);
#else
	void map(string eventString, string contextString, string commandString) {
		reinterpret_cast<void(*)(string, string, string)>(0x5d5e92)(eventString, contextString, commandString);
	}

	void echo(string stringMessage) {
		reinterpret_cast<void(*)(string)>(0x4011e6)(stringMessage);
	}

	void echoLocalized(int stringID) {
		reinterpret_cast<void(*)(int)>(0x7d92f2)(stringID);
	}

	void echoNum(int stringMessage) {
		reinterpret_cast<void(*)(int)>(0x7d932d)(stringMessage);
	}

	void IMEEnable(bool enable) {
		reinterpret_cast<void(*)(bool)>(0x7d9357)(enable);
	}

	void console() {
		reinterpret_cast<void(*)()>(0x437f1b)();
	}

	void pause(int integerState, bool checkForAllowPause) {
		reinterpret_cast<void(*)(int, bool)>(0x50f0cb)(integerState, checkForAllowPause);
	}

	void pause2(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7dabac)(integerState);
	}

	void unpauseNoChecks() {
		reinterpret_cast<void(*)()>(0x7dabbc)();
	}

	void exit(bool a) {
		reinterpret_cast<void(*)(bool)>(0x43b1a0)(a);
	}

	void screenshot() {
		reinterpret_cast<void(*)()>(0x7da55b)();
	}

	void hackscreenshot(int a) {
		reinterpret_cast<void(*)(int)>(0x7da5e9)(a);
	}

	void res(int integerXRes, int integerYRes) {
		reinterpret_cast<void(*)(int, int)>(0x7d9c10)(integerXRes, integerYRes);
	}

	void resbpp(int integerXRes, int integerYRes, int integerBPP) {
		reinterpret_cast<void(*)(int, int, int)>(0x7d9c8e)(integerXRes, integerYRes, integerBPP);
	}

	void undo() {
		reinterpret_cast<void(*)()>(0x7da8b9)();
	}

	void redo() {
		reinterpret_cast<void(*)()>(0x7da8d3)();
	}

	void alignResources() {
		reinterpret_cast<void(*)()>(0x7db188)();
	}

	void alignSelectedUnits() {
		reinterpret_cast<void(*)()>(0x7dd4f5)();
	}

	void resourceMarket(int intPlayerID, string stringResourceTo, float floatAmount, string stringResourceFrom) {
		reinterpret_cast<void(*)(int, string, float, string)>(0x7deec5)(intPlayerID, stringResourceTo, floatAmount, stringResourceFrom);
	}

	void unitData(int intUnitID) {
		reinterpret_cast<void(*)(int)>(0x7de17b)(intUnitID);
	}

	void unitSetVariation(int Variation, int UnitID) {
		reinterpret_cast<void(*)(int, int)>(0x7dbee6)(Variation, UnitID);
	}

	void unitIncVariation(int UnitID) {
		reinterpret_cast<void(*)(int)>(0x7dbfa0)(UnitID);
	}

	void unitDecVariation(int a) {
		reinterpret_cast<void(*)(int)>(0x7dc068)(a);
	}

	void unitSetStanceAggressive() {
		reinterpret_cast<void(*)()>(0x7dd560)();
	}

	void unitSetStanceDefensive() {
		reinterpret_cast<void(*)()>(0x7dd5af)();
	}

	void unitSetStancePassive() {
		reinterpret_cast<void(*)()>(0x7dd5fe)();
	}

	void unitSetTactic(string a) {
		reinterpret_cast<void(*)(string)>(0x7dd64d)(a);
	}

	void unitToggleStealth() {
		reinterpret_cast<void(*)()>(0x7dd792)();
	}

	void squadMode(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x7de67f)(a, b);
	}

	void setSquadMode(string a) {
		reinterpret_cast<void(*)(string)>(0x7de808)(a);
	}

	void squadWheel(float angle, int squadID) {
		reinterpret_cast<void(*)(float, int)>(0x7de963)(angle, squadID);
	}

	void unitTownBell() {
		reinterpret_cast<void(*)()>(0x7db365)();
	}

	void unitReturnToWork() {
		reinterpret_cast<void(*)()>(0x7db37e)();
	}

	void obscuredUnitToggle() {
		reinterpret_cast<void(*)()>(0x7de2f2)();
	}

	void configDump(string a) {
		reinterpret_cast<void(*)(string)>(0x7d9385)(a);
	}

	void configSet(string stringName, string stringValue) {
		reinterpret_cast<void(*)(string, string)>(0x7d93bc)(stringName, stringValue);
	}

	void configSetInt(string stringName, int integerValue) {
		reinterpret_cast<void(*)(string, int)>(0x7d93d3)(stringName, integerValue);
	}

	void configSetFloat(string stringName, float floatValue) {
		reinterpret_cast<void(*)(string, float)>(0x7d93ea)(stringName, floatValue);
	}

	void configDef(string stringName) {
		reinterpret_cast<void(*)(string)>(0x7d9401)(stringName);
	}

	void configUndef(string stringName) {
		reinterpret_cast<void(*)(string)>(0x7d9411)(stringName);
	}

	void configToggle(string stringName) {
		reinterpret_cast<void(*)(string)>(0x7d9421)(stringName);
	}

	void config(string stringToken) {
		reinterpret_cast<void(*)(string)>(0x7d9ea3)(stringToken);
	}

	void configGetByID(int intValue) {
		reinterpret_cast<void(*)(int)>(0x7d9431)(intValue);
	}

	void configHelp(string symbolFilter) {
		reinterpret_cast<void(*)(string)>(0x7d9453)(symbolFilter);
	}

	void configHelpPrefix(string symbolFilter) {
		reinterpret_cast<void(*)(string)>(0x7d946a)(symbolFilter);
	}

	void saveGame(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7dc130)(stringFilename);
	}

	void saveScenario(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7d9798)(stringFilename);
	}

	void loadGame(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7dac6e)(stringFilename);
	}

	void loadScenario(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x516fc5)(stringFilename);
	}

	void loadTutorial(string stringFilename, int loadMode, string loadImage, int textID, bool isAge3Scenario) {
		reinterpret_cast<void(*)(string, int, string, int, bool)>(0x7d9851)(stringFilename, loadMode, loadImage, textID, isAge3Scenario);
	}

	void loadCampaignScenario(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7d99f9)(stringFilename);
	}

	void loadRecentFile(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7d9afc)(stringFilename);
	}

	void saveCamera(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7daf53)(stringFilename);
	}

	void saveCurrentHomeCityCamera() {
		reinterpret_cast<void(*)()>(0x7dafe2)();
	}

	void saveCurrentHomeCityWidescreenCamera() {
		reinterpret_cast<void(*)()>(0x7db055)();
	}

	void loadCamera(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7db0f9)(stringFilename);
	}

	void restart() {
		reinterpret_cast<void(*)()>(0x7d9bbd)();
	}

	void terrainFilter() {
		reinterpret_cast<void(*)()>(0x7d9dba)();
	}

	void terrainFilterArea(int integerX1, int integerY1, int integerX2, int integerY2) {
		reinterpret_cast<void(*)(int, int, int, int)>(0x7d9d74)(integerX1, integerY1, integerX2, integerY2);
	}

	void terrainFlatten(float a) {
		reinterpret_cast<void(*)(float)>(0x7d9e71)(a);
	}

	void terrainFlattenArea(int integerX1, int integerY1, int integerX2, int integerY2) {
		reinterpret_cast<void(*)(int, int, int, int)>(0x7d9e2e)(integerX1, integerY1, integerX2, integerY2);
	}

	void terrainSetType(int integerType) {
		reinterpret_cast<void(*)(int)>(0x7da633)(integerType);
	}

	void terrainSetSubtype(int integerType) {
		reinterpret_cast<void(*)(int)>(0x7da64d)(integerType);
	}

	void terrainSetMix(int integerType) {
		reinterpret_cast<void(*)(int)>(0x7da664)(integerType);
	}

	void terrainPaint(string a) {
		reinterpret_cast<void(*)(string)>(0x7daddd)(a);
	}

	void terrainPaintMix(string a) {
		reinterpret_cast<void(*)(string)>(0x7dae6d)(a);
	}

	void terrainAmbient(int integerR, int integerG, int integerB) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dd499)(integerR, integerG, integerB);
	}

	void terrainAdjustGlobalHeight(float meters) {
		reinterpret_cast<void(*)(float)>(0x7da67a)(meters);
	}

	void cameraRotate(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d9d1f)(integerState);
	}

	void cameraNice() {
		reinterpret_cast<void(*)()>(0x7d9d64)();
	}

	void cameraForward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7d9fc5)(integerKeyState);
	}

	void cameraWorldForward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7d9ff9)(integerKeyState);
	}

	void cameraWorldForwardLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da02d)(integerKeyState);
	}

	void cameraWorldForwardRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da087)(integerKeyState);
	}

	void cameraBackward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da0e1)(integerKeyState);
	}

	void cameraWorldBackward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da115)(integerKeyState);
	}

	void cameraWorldBackwardLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da149)(integerKeyState);
	}

	void cameraWorldBackwardRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da1a3)(integerKeyState);
	}

	void cameraRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da1fd)(integerKeyState);
	}

	void cameraLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da231)(integerKeyState);
	}

	void cameraUp(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da265)(integerKeyState);
	}

	void cameraDown(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da2c2)(integerKeyState);
	}

	void cameraPitchForward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da31f)(integerKeyState);
	}

	void cameraPitchBackward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da353)(integerKeyState);
	}

	void cameraRollLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da3bb)(integerKeyState);
	}

	void cameraRollRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da387)(integerKeyState);
	}

	void cameraYawRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da3ef)(integerKeyState);
	}

	void cameraYawLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da458)(integerKeyState);
	}

	void cameraLocalYawRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da4c1)(integerKeyState);
	}

	void cameraLocalYawLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7da504)(integerKeyState);
	}

	void cameraDump() {
		reinterpret_cast<void(*)()>(0x7da547)();
	}

	void trackLoad(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7dc24a)(stringFilename);
	}

	void trackSave(string stringFilename) {
		reinterpret_cast<void(*)(string)>(0x7dc76c)(stringFilename);
	}

	void trackClear() {
		reinterpret_cast<void(*)()>(0x7dc483)();
	}

	void trackStepForward() {
		reinterpret_cast<void(*)()>(0x7dc3cb)();
	}

	void trackStepBackward() {
		reinterpret_cast<void(*)()>(0x7dc427)();
	}

	void trackToggleShow() {
		reinterpret_cast<void(*)()>(0x7dc4d4)();
	}

	void trackAddWaypoint() {
		reinterpret_cast<void(*)()>(0x7dc5b4)();
	}

	void trackEditWaypoint() {
		reinterpret_cast<void(*)()>(0x7dc605)();
	}

	void trackSetSelectedWaypoint(int index) {
		reinterpret_cast<void(*)(int)>(0x7dc656)(index);
	}

	void trackGotoSelectedWaypoint(int index) {
		reinterpret_cast<void(*)(int)>(0x7dc6ab)(index);
	}

	void trackRemoveWaypoint() {
		reinterpret_cast<void(*)()>(0x7dc71b)();
	}

	void trackInsert() {
		reinterpret_cast<void(*)()>(0x7dc2a8)();
	}

	void trackRemove() {
		reinterpret_cast<void(*)()>(0x7dc307)();
	}

	void trackPlay(float duration, int eventID) {
		reinterpret_cast<void(*)(float, int)>(0x7dc358)(duration, eventID);
	}

	void trackPause() {
		reinterpret_cast<void(*)()>(0x7dc380)();
	}

	void trackStop() {
		reinterpret_cast<void(*)()>(0x7dc397)();
	}

	void trackAdvance(float a) {
		reinterpret_cast<void(*)(float)>(0x7dc3ae)(a);
	}

	void trackGotoSelectedEvent(int index) {
		reinterpret_cast<void(*)(int)>(0x7dc7fd)(index);
	}

	void areaIncrementAreaToRender(int playerID) {
		reinterpret_cast<void(*)(int)>(0x7da7e7)(playerID);
	}

	void toggleShadows() {
		reinterpret_cast<void(*)()>(0x7d9503)();
	}

	void setShadowQuality(int qualityLevel) {
		reinterpret_cast<void(*)(int)>(0x7d9481)(qualityLevel);
	}

	void setShadowBiasMul(float biasMultiplier) {
		reinterpret_cast<void(*)(float)>(0x7d94a1)(biasMultiplier);
	}

	void setShadowSnapping(int a) {
		reinterpret_cast<void(*)(int)>(0x7d94bf)(a);
	}

	void setShadowRotationOp(int a) {
		reinterpret_cast<void(*)(int)>(0x7d94e1)(a);
	}

	void renderWindow(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d9f22)(integerState);
	}

	void renderBaseID(int playerID, int areaID, int integerState) {
		reinterpret_cast<void(*)(int, int, int)>(0x7da7b1)(playerID, areaID, integerState);
	}

	void renderAreas(int playerID, int integerState) {
		reinterpret_cast<void(*)(int, int)>(0x7da6ac)(playerID, integerState);
	}

	void renderAreaDangerLevels(int playerID, int state) {
		reinterpret_cast<void(*)(int, int)>(0x7da71b)(playerID, state);
	}

	void renderAreaID(int playerID, int areaID, int integerState) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dc9a6)(playerID, areaID, integerState);
	}

	void renderAreaGroupID(int playerID, int areaGroupID, int integerState) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dc85f)(playerID, areaGroupID, integerState);
	}

	void renderAnisotropic(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d951a)(integerState);
	}

	void setHDRMultisampleFactor(int a) {
		reinterpret_cast<void(*)(int)>(0x7d952f)(a);
	}

	void setSuperSampleFactors(float floatX, float floatY) {
		reinterpret_cast<void(*)(float, float)>(0x7d954d)(floatX, floatY);
	}

	void setSuperSampleFilterScales(float floatX, float floatY) {
		reinterpret_cast<void(*)(float, float)>(0x7d9570)(floatX, floatY);
	}

	void setSuperSampleFilterIndex(int a) {
		reinterpret_cast<void(*)(int)>(0x7d9593)(a);
	}

	void renderTrilinear(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d95b1)(integerState);
	}

	void renderFriendOrFoe(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d95ed)(integerState);
	}

	void ambientColor(int integerR, int integerG, int integerB) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dcb3a)(integerR, integerG, integerB);
	}

	void ambientGetColor() {
		reinterpret_cast<void(*)()>(0x7da8ed)();
	}

	void resetAmbientColor() {
		reinterpret_cast<void(*)()>(0x7dcbf2)();
	}

	void ambientColor2(int integerR, int integerG, int integerB) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dcb96)(integerR, integerG, integerB);
	}

	void shadowDarkness(float integerDarkness, float pcfFilterScalar, float biasNV, float biasATI, float slope) {
		reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dcc01)(integerDarkness, pcfFilterScalar, biasNV, biasATI, slope);
	}

	void sunColor(int integerR, int integerG, int integerB) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dccd5)(integerR, integerG, integerB);
	}

	void sunGetColor() {
		reinterpret_cast<void(*)()>(0x7da907)();
	}

	void resetSunColor() {
		reinterpret_cast<void(*)()>(0x7dcd3a)();
	}

	void fakeSunParams(float intensity, float specIntensity, float specPower, float inclination, float rotation) {
		reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dcd52)(intensity, specIntensity, specPower, inclination, rotation);
	}

	void setHemiLight(float topColorR, float topColorG, float topColorB, float bottomColorR, float bottomColorG, float bottomColorB, float axisYaw, float axisPitch, float intensity, float unitIntensity, float terrainIntensity) {
		reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, float, float, float)>(0x7da92a)(topColorR, topColorG, topColorB, bottomColorR, bottomColorG, bottomColorB, axisYaw, axisPitch, intensity, unitIntensity, terrainIntensity);
	}

	void setSceneLightParams(float sunIntensity, float power, float specIntensity, float metalness, float fogColorR, float fogColorG, float fogColorB, float fogDensity, float fogStart) {
		reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, float)>(0x7dcd8c)(sunIntensity, power, specIntensity, metalness, fogColorR, fogColorG, fogColorB, fogDensity, fogStart);
	}

	void setFogParams(float planarfogColorR, float planarfogColorG, float planarfogColorB, float planarfogDensity, float planarfogHeight) {
		reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dce98)(planarfogColorR, planarfogColorG, planarfogColorB, planarfogDensity, planarfogHeight);
	}

	void setBumpScale(float scale) {
		reinterpret_cast<void(*)(float)>(0x7dcf32)(scale);
	}

	void unitPlayerFakify(int a) {
		reinterpret_cast<void(*)(int)>(0x7dcf53)(a);
	}

	void unitPlayerDefakify() {
		reinterpret_cast<void(*)()>(0x7dcfd8)();
	}

	void setToneMapParams(float exposure, float dispGamma, float greyFStops, float kneeLow, float kneeHigh, float ditherNoiseInten) {
		reinterpret_cast<void(*)(float, float, float, float, float, float)>(0x7dd05c)(exposure, dispGamma, greyFStops, kneeLow, kneeHigh, ditherNoiseInten);
	}

	void setBloomParams(float bloomThreshold, float bloomColorR, float bloomColorG, float bloomColorB, float bloomIntensity, float bloomPass, float bloomSigma) {
		reinterpret_cast<void(*)(float, float, float, float, float, float, float)>(0x7dd10a)(bloomThreshold, bloomColorR, bloomColorG, bloomColorB, bloomIntensity, bloomPass, bloomSigma);
	}

	void setLDRBloomParams(float bloomColorR, float bloomColorG, float bloomColorB, float bloomIntensity, float bloomSigma) {
		reinterpret_cast<void(*)(float, float, float, float, float)>(0x7dd1f7)(bloomColorR, bloomColorG, bloomColorB, bloomIntensity, bloomSigma);
	}

	void setBloomStreakParams(float streakCount, float Passes, float ElementOffset, float Exposure, float Intensity, float Falloff, float streakRed, float streakGreen, float streakBlue, float threshold) {
		reinterpret_cast<void(*)(float, float, float, float, float, float, float, float, float, float)>(0x7dd291)(streakCount, Passes, ElementOffset, Exposure, Intensity, Falloff, streakRed, streakGreen, streakBlue, threshold);
	}

	void setBloomFeedbackParams(float currentFrameContribution, float lastFrameContribution) {
		reinterpret_cast<void(*)(float, float)>(0x7dd3e7)(currentFrameContribution, lastFrameContribution);
	}

	void setTerrainLightingParams(float bumpScale, float specularPower, float specularIntensity, float terrainMetalness) {
		reinterpret_cast<void(*)(float, float, float, float)>(0x7dd425)(bumpScale, specularPower, specularIntensity, terrainMetalness);
	}

	void applyLightingSet(string name) {
		reinterpret_cast<void(*)(string)>(0x90b775)(name);
	}

	void saveLightingSet(string name) {
		reinterpret_cast<void(*)(string)>(0x7da9cc)(name);
	}

	void loadLightingSet(string name, bool apply) {
		reinterpret_cast<void(*)(string, bool)>(0x7da9fa)(name, apply);
	}

	void brushCircularSize(float floatValue) {
		reinterpret_cast<void(*)(float)>(0x7da5ee)(floatValue);
	}

	void musicStop() {
		reinterpret_cast<void(*)()>(0x7da83c)();
	}

	void musicSetVolume(float volume) {
		reinterpret_cast<void(*)(float)>(0x7da85e)(0.0f - 1.0f);
	}

	void musicPlaySong(string songname, float fadetime) {
		reinterpret_cast<void(*)(string, float)>(0x7dca90)(songname, fadetime);
	}

	void musicToggleBattleMode() {
		reinterpret_cast<void(*)()>(0x7da88c)();
	}

	void displayType(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d9ecd)(integerState);
	}

	void player(int integerPlayer) {
		reinterpret_cast<void(*)(int)>(0x7dc1fe)(integerPlayer);
	}

	void fog(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d9644)(integerState);
	}

	void blackmap(int integerState) {
		reinterpret_cast<void(*)(int)>(0x7d96ee)(integerState);
	}

	void modeEnter(string stringMode) {
		reinterpret_cast<void(*)(string)>(0x56b23a)(stringMode);
	}

	void startCampaign(string campaignName) {
		reinterpret_cast<void(*)(string)>(0x7daa64)(campaignName);
	}

	void uiEnterGameMenuModeIfNotResigned() {
		reinterpret_cast<void(*)()>(0x7daae9)();
	}

	void modeToggleBetweenIfNotMP(string stringMode1, string stringMode2) {
		reinterpret_cast<void(*)(string, string)>(0x7dab97)(stringMode1, stringMode2);
	}

	void helpPrefix(string a) {
		reinterpret_cast<void(*)(string)>(0x7de41d)(a);
	}

	void help(string a) {
		reinterpret_cast<void(*)(string)>(0x7de4db)(a);
	}

	void helpText(string a) {
		reinterpret_cast<void(*)(string)>(0x7de598)(a);
	}

	void lookAt(float x, float z) {
		reinterpret_cast<void(*)(float, float)>(0x7db393)(x, z);
	}

	void lookAtArmy(int playerID, string armyName) {
		reinterpret_cast<void(*)(int, string)>(0x7db3c4)(playerID, armyName);
	}

	void resetDefaultPlayerColors() {
		reinterpret_cast<void(*)()>(0x7db42c)();
	}

	void setMinimapUnitFilter(int a) {
		reinterpret_cast<void(*)(int)>(0x7dd911)(a);
	}

	void setGraphicDetail(int detailLevel) {
		reinterpret_cast<void(*)(int)>(0x7db440)(detailLevel);
	}

	void setWorldDifficulty(int v) {
		reinterpret_cast<void(*)(int)>(0x7db453)(v);
	}

	void startAutoPatcher(bool manualMode) {
		reinterpret_cast<void(*)(bool)>(0x7db502)(manualMode);
	}

	void cancelAutoPatcher() {
		reinterpret_cast<void(*)()>(0x7db638)();
	}

	void confirmAutoPatcher() {
		reinterpret_cast<void(*)()>(0x7db65c)();
	}

	void playMovie(string a) {
		reinterpret_cast<void(*)(string)>(0x7db744)(a);
	}

	void toggleHomeCityView() {
		reinterpret_cast<void(*)()>(0x7dd94a)();
	}

	void toggleHomeCityViewTech() {
		reinterpret_cast<void(*)()>(0x7db768)();
	}

	void lookAtHomeCityBuilding(int building) {
		reinterpret_cast<void(*)(int)>(0x7db7fb)(building);
	}

	void homeCityTrain(int playerID, int buildingID, int puid) {
		reinterpret_cast<void(*)(int, int, int)>(0x7db987)(playerID, buildingID, puid);
	}

	void homeCityTrain2(int playerID, int cardIndex) {
		reinterpret_cast<void(*)(int, int)>(0x7db9be)(playerID, cardIndex);
	}

	void homeCityTransport(int playerID) {
		reinterpret_cast<void(*)(int)>(0x7dba5f)(playerID);
	}

	void fourOfAKind() {
		reinterpret_cast<void(*)()>(0x7dba88)();
	}

	void relicCapture() {
		reinterpret_cast<void(*)()>(0x7dbab3)();
	}

	void kothVictory() {
		reinterpret_cast<void(*)()>(0x7dbade)();
	}

	void tradeRouteCommand(int playerID, int tradeRoutUnit, int commandID) {
		reinterpret_cast<void(*)(int, int, int)>(0x7db846)(playerID, tradeRoutUnit, commandID);
	}

	void tradeRouteTrain(int playerID, int tradeRoutUnit, int puid) {
		reinterpret_cast<void(*)(int, int, int)>(0x7db879)(playerID, tradeRoutUnit, puid);
	}

	void commandResearch(int commandID, int unitID, int a, int b) {
		reinterpret_cast<void(*)(int, int, int, int)>(0x7db932)(commandID, unitID, a, b);
	}

	void mercTrain(int playerID, int buildingID, int puid) {
		reinterpret_cast<void(*)(int, int, int)>(0x7db9f2)(playerID, buildingID, puid);
	}

	void homeCityShipEject(int playerID, int buildingID, int puid, int index) {
		reinterpret_cast<void(*)(int, int, int, int)>(0x7dba27)(playerID, buildingID, puid, index);
	}

	void loadGrouping(string groupingName) {
		reinterpret_cast<void(*)(string)>(0x7dd9b8)(groupingName);
	}

	void loadUserDefinedGrouping(string groupingName) {
		reinterpret_cast<void(*)(string)>(0x7ddacc)(groupingName);
	}

	void loadGroupingUnicode(string a) {
		reinterpret_cast<void(*)(string)>(0x7dbb09)(a);
	}

	void loadGroupingUnicodeLUA(int a, string b) {
		reinterpret_cast<void(*)(int, string)>(0x7dbb7b)(a, b);
	}

	void repairUnit(int unitID) {
		reinterpret_cast<void(*)(int)>(0x7decea)(unitID);
	}

	void cancelRepairUnit(int unitID) {
		reinterpret_cast<void(*)(int)>(0x7debdc)(unitID);
	}

	void setHomeCityGatherUnit(int unitID) {
		reinterpret_cast<void(*)(int)>(0x7ddbd4)(unitID);
	}

	void convertCoveredWagon() {
		reinterpret_cast<void(*)()>(0x7dedcc)();
	}

	void breakTreaty() {
		reinterpret_cast<void(*)()>(0x7dbc07)();
	}

	void ransomExplorer() {
		reinterpret_cast<void(*)()>(0x7dea71)();
	}

	void toggleWorldTooltipClipRect() {
		reinterpret_cast<void(*)()>(0x7db1a5)();
	}

	void drawWorldTooltipClipRect() {
		reinterpret_cast<void(*)()>(0x7db1cd)();
	}

	void setWorldTooltipRectDims1024(int minX, int minY, int maxX, int maxY) {
		reinterpret_cast<void(*)(int, int, int, int)>(0x7db1f5)(minX, minY, maxX, maxY);
	}

	void upgradeTradeRoute(int unitID) {
		reinterpret_cast<void(*)(int)>(0x7dbbef)(unitID);
	}

	void spawnUnits(string protoname, int count, int unitID) {
		reinterpret_cast<void(*)(string, int, int)>(0x7db8ac)(protoname, count, unitID);
	}

	void ability(int abilityId, int unitID, bool doWhenNotSelected) {
		reinterpret_cast<void(*)(int, int, bool)>(0x7ddc52)(abilityId, unitID, doWhenNotSelected);
	}

	void doAbilityInType(string protoPowerName, string a) {
		reinterpret_cast<void(*)(string, string)>(0x7ddd9d)(protoPowerName, a);
	}

	void doAbilityInSelected(string protoPowerName) {
		reinterpret_cast<void(*)(string)>(0x7ddf31)(protoPowerName);
	}

	void doCommandInSelected(string a) {
		reinterpret_cast<void(*)(string)>(0x7df08b)(a);
	}

	void specialPower(int playerID, int powerEntryIndex, int powerID) {
		reinterpret_cast<void(*)(int, int, int)>(0x7dbc39)(playerID, powerEntryIndex, powerID);
	}

	void vsync(int state) {
		reinterpret_cast<void(*)(int)>(0x7dbd58)(state);
	}

	void startMoviePlayback(string filename, int sizing, float fadeIn, float fadeOut) {
		reinterpret_cast<void(*)(string, int, float, float)>(0x7db680)(filename, sizing, fadeIn, fadeOut);
	}

	void trainReinforcement(int armyID) {
		reinterpret_cast<void(*)(int)>(0x7dbd9a)(armyID);
	}

	void cancelTrainReinforcement(int armyID) {
		reinterpret_cast<void(*)(int)>(0x7dbdca)(armyID);
	}

	void setDropDefaultMips(int num) {
		reinterpret_cast<void(*)(int)>(0x7dbe4e)(num);
	}

	void setDropTerrainMips(int num) {
		reinterpret_cast<void(*)(int)>(0x7dbe87)(num);
	}

	void showSPCNote(string title, string text) {
		reinterpret_cast<void(*)(string, string)>(0x7dbdfa)(title, text);
	}

	void renderForceReset() {
		reinterpret_cast<void(*)()>(0x7dbec0)();
	}

	void editorSetTechStatus(string techToActivate, bool active) {
		reinterpret_cast<void(*)(string, bool)>(0x7df22a)(techToActivate, active);
	}

	void editorUpdateUnitVisuals() {
		reinterpret_cast<void(*)()>(0x7de0a7)();
	}

	void editorSetAllTradeRoutesToDef(string newDefName) {
		reinterpret_cast<void(*)(string)>(0x7de0ed)(newDefName);
	}

	void researchByID(int TechID, int ResearchingUnitID, int Player, bool a) {
		reinterpret_cast<void(*)(int, int, int, bool)>(0x7df3f9)(TechID, ResearchingUnitID, Player, a);
	}

	void researchTechInSelected(string techName) {
		reinterpret_cast<void(*)(string)>(0x7df54d)(techName);
	}

	void trainByID(int ProtoUnitID, int TrainingUnitID, int Player) {
		reinterpret_cast<void(*)(int, int, int)>(0x7df6af)(ProtoUnitID, TrainingUnitID, Player);
	}

	void trainInSelected(string stringProtoName, int traincount) {
		reinterpret_cast<void(*)(string, int)>(0x7dfccf)(stringProtoName, traincount);
	}

	void cancelTrainInSelected(int ProtoUnitID, bool All) {
		reinterpret_cast<void(*)(int, bool)>(0x7df99d)(ProtoUnitID, All);
	}

	void cancelResearchInSelected(int TechID) {
		reinterpret_cast<void(*)(int)>(0x7dfb9b)(TechID);
	}

	void trainInSelectedByID(int protoID, int traincount) {
		reinterpret_cast<void(*)(int, int)>(0x7df808)(protoID, traincount);
	}

	void click() {
		reinterpret_cast<void(*)()>(0x7df2d5)();
	}

	void homeCityResearch(int playerID, string techName) {
		reinterpret_cast<void(*)(int, string)>(0x7dfd22)(playerID, techName);
	}

	void homeCityResearchByID(int playerID, int techName) {
		reinterpret_cast<void(*)(int, int)>(0x7df32f)(playerID, techName);
	}

	void homeCityMakeActiveByID(int playerID, int techName) {
		reinterpret_cast<void(*)(int, int)>(0x7df2f9)(playerID, techName);
	}

	void homeCityResearchByIDOutsideGame(int playerID, int techName) {
		reinterpret_cast<void(*)(int, int)>(0x7df365)(playerID, techName);
	}

	void homeCityResearchByIDPregame(int techID) {
		reinterpret_cast<void(*)(int)>(0x7df3c9)(techID);
	}

	void editMode(string symbolModeName) {
		reinterpret_cast<void(*)(string)>(0x7dfdde)(symbolModeName);
	}

	void uiBuildAtPointer() {
		reinterpret_cast<void(*)()>(0x7e6de8)();
	}

	void uiFormationOrientation() {
		reinterpret_cast<void(*)()>(0x7dfe09)();
	}

	void uiBuildWallAtPointer(bool a) {
		reinterpret_cast<void(*)(bool)>(0x7dfe31)(a);
	}

	void uiCreateRiverToggleWaypointMode() {
		reinterpret_cast<void(*)()>(0x7dfe64)();
	}

	void uiPlaceRiverWaypoint() {
		reinterpret_cast<void(*)()>(0x7dfe88)();
	}

	void uiRemoveRiverWaypoint() {
		reinterpret_cast<void(*)()>(0x7dfeaf)();
	}

	void uiCreateRiver() {
		reinterpret_cast<void(*)()>(0x7dfed6)();
	}

	void uiCreateRandomRiver() {
		reinterpret_cast<void(*)()>(0x7dfefa)();
	}

	void uiPlaceRiverShallow() {
		reinterpret_cast<void(*)()>(0x7dff1e)();
	}

	void uiRemoveRiverShallow() {
		reinterpret_cast<void(*)()>(0x7dff45)();
	}

	void uiWheelRotateRiverShallow(int a) {
		reinterpret_cast<void(*)(int)>(0x7dff6c)(a);
	}

	void uiSetGatherPointAtPointer(bool homeCity, bool water) {
		reinterpret_cast<void(*)(bool, bool)>(0x7dffcd)(homeCity, water);
	}

	void uiSetHomeCityWaterSpawnPointAtPointer() {
		reinterpret_cast<void(*)()>(0x7dffe9)();
	}

	void uiClearGatherPoint() {
		reinterpret_cast<void(*)()>(0x7e705e)();
	}

	void uiTransformSelectedUnit(string a) {
		reinterpret_cast<void(*)(string)>(0x7e7193)(a);
	}

	void uiFlareAtPointer() {
		reinterpret_cast<void(*)()>(0x7dfff9)();
	}

	void uiCommsFlareAtPointer() {
		reinterpret_cast<void(*)()>(0x7e009d)();
	}

	void uiHelpAtPointer() {
		reinterpret_cast<void(*)()>(0x7e4056)();
	}

	void uiGarrisonToPointer() {
		reinterpret_cast<void(*)()>(0x7e7455)();
	}

	void uiRepairAtPointer() {
		reinterpret_cast<void(*)()>(0x7e745e)();
	}

	void uiEmpowerAtPointer() {
		reinterpret_cast<void(*)()>(0x7e7467)();
	}

	void uiSetProtoCursor(string stringProtoName, bool setPlacement) {
		reinterpret_cast<void(*)(string, bool)>(0x7e00f5)(stringProtoName, setPlacement);
	}

	void uiSetProtoCursorID(int integerProtoID) {
		reinterpret_cast<void(*)(int)>(0x7e00de)(integerProtoID);
	}

	void uiEnterContext(string stringContext) {
		reinterpret_cast<void(*)(string)>(0x7e01b7)(stringContext);
	}

	void uiLeaveContext(string stringContext) {
		reinterpret_cast<void(*)(string)>(0x7e01d0)(stringContext);
	}

	void uiClearCursor() {
		reinterpret_cast<void(*)()>(0x7e01e9)();
	}

	void uiYawUnitRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e021b)(integerKeyState);
	}

	void uiYawUnitLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0278)(integerKeyState);
	}

	void uiPitchUnitUp(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e02d5)(integerKeyState);
	}

	void uiPitchUnitDown(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0332)(integerKeyState);
	}

	void uiRollUnitRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e038f)(integerKeyState);
	}

	void uiRollUnitLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e03ec)(integerKeyState);
	}

	void uiMoveUnitForward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0449)(integerKeyState);
	}

	void uiMoveUnitBackward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e04a6)(integerKeyState);
	}

	void uiMoveUnitRight(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e061a)(integerKeyState);
	}

	void uiMoveUnitLeft(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e05bd)(integerKeyState);
	}

	void uiMoveUnitUp(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0503)(integerKeyState);
	}

	void uiMoveUnitDown(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0560)(integerKeyState);
	}

	void uiWheelRotatePlacedUnit(int a) {
		reinterpret_cast<void(*)(int)>(0x7e0677)(a);
	}

	void uiSelectWaterAtPointer() {
		reinterpret_cast<void(*)()>(0x7e0708)();
	}

	void uiUnSelectWater() {
		reinterpret_cast<void(*)()>(0x7e0722)();
	}

	void uiPaintWaterObjects() {
		reinterpret_cast<void(*)()>(0x7e074b)();
	}

	void uiRotateWaterLeft(int a) {
		reinterpret_cast<void(*)(int)>(0x7e084d)(a);
	}

	void uiRotateWaterRight(int a) {
		reinterpret_cast<void(*)(int)>(0x7e0891)(a);
	}

	void uiSelectionButtonDown() {
		reinterpret_cast<void(*)()>(0x7e0978)();
	}

	void uiSelectionButtonUp() {
		reinterpret_cast<void(*)()>(0x7e098b)();
	}

	void uiCreateNumberGroup(int integerGroup) {
		reinterpret_cast<void(*)(int)>(0x7e099e)(integerGroup);
	}

	void uiClearNumberGroup(int integerGroup) {
		reinterpret_cast<void(*)(int)>(0x7e09ff)(integerGroup);
	}

	void uiSelectNumberGroup(int integerGroup) {
		reinterpret_cast<void(*)(int)>(0x7e0a5b)(integerGroup);
	}

	void uiAddSelectNumberGroup(int integerGroup) {
		reinterpret_cast<void(*)(int)>(0x7e0ae8)(integerGroup);
	}

	void uiRemoveFromAnyNumberGroup() {
		reinterpret_cast<void(*)()>(0x7e0b94)();
	}

	void uiDoubleClickSelect(int integerAdd, bool checkAction) {
		reinterpret_cast<void(*)(int, bool)>(0x7e1de7)(integerAdd, checkAction);
	}

	void uiAddSelectionButtonDown() {
		reinterpret_cast<void(*)()>(0x7e1e1f)();
	}

	void uiAddSelectionButtonUp() {
		reinterpret_cast<void(*)()>(0x7e1e4c)();
	}

	void uiToggleSelectionButton() {
		reinterpret_cast<void(*)()>(0x7e1e5f)();
	}

	void uiRotateSelection(int a) {
		reinterpret_cast<void(*)(int)>(0x7e0955)(a);
	}

	void uiMoveSelectionButtonDown() {
		reinterpret_cast<void(*)()>(0x7e08d5)();
	}

	void uiMoveSelectionButtonUp() {
		reinterpret_cast<void(*)()>(0x7e08f5)();
	}

	void uiMoveSelectionAddButtonDown() {
		reinterpret_cast<void(*)()>(0x7e0915)();
	}

	void uiMoveSelectionAddButtonUp() {
		reinterpret_cast<void(*)()>(0x7e0935)();
	}

	void uiWorkAtPointer() {
		reinterpret_cast<void(*)()>(0x7e1f29)();
	}

	void uiWheelRotate(int a) {
		reinterpret_cast<void(*)(int)>(0x7e1897)(a);
	}

	void uiWheelRotateCamera(int a) {
		reinterpret_cast<void(*)(int)>(0x7e1908)(a);
	}

	void uiChangeElevationToSample(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0e07)(integerKeyState);
	}

	void uiSampleElevationAtPointer() {
		reinterpret_cast<void(*)()>(0x7e0f50)();
	}

	void uiSampleCliffElevationAtPointer() {
		reinterpret_cast<void(*)()>(0x7e50ee)();
	}

	void uiPaintTerrainToSample(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e0f6e)(integerKeyState);
	}

	void uiSampleTerrainAtPointer() {
		reinterpret_cast<void(*)()>(0x7e10ea)();
	}

	void uiDeleteSelectedUnit() {
		reinterpret_cast<void(*)()>(0x7e5197)();
	}

	void uiDeleteSelectedUnit2() {
		reinterpret_cast<void(*)()>(0x7e540a)();
	}

	void uiDeleteAllSelectedUnits() {
		reinterpret_cast<void(*)()>(0x7e1108)();
	}

	void uiRemoveSelectedUnit(int unitID) {
		reinterpret_cast<void(*)(int)>(0x7e540f)(unitID);
	}

	void uiStopSelectedUnits() {
		reinterpret_cast<void(*)()>(0x7e0dfc)();
	}

	void uiRaiseElevation(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e1116)(integerKeyState);
	}

	void uiLowerElevation(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e12c8)(integerKeyState);
	}

	void uiUniformRaiseElevation(int a) {
		reinterpret_cast<void(*)(int)>(0x7e147a)(a);
	}

	void uiUniformLowerElevation(int a) {
		reinterpret_cast<void(*)(int)>(0x7e14ba)(a);
	}

	void uiSmooth(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e14fa)(integerKeyState);
	}

	void uiPaintWater(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e1747)(integerKeyState);
	}

	void uiPaintWaterArea(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e176a)(integerKeyState);
	}

	void uiPaintCliff(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e178d)(integerKeyState);
	}

	void uiTerrainSelection(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e17b0)(integerKeyState);
	}

	void uiRaiseTerrainSelection(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e17e6)(integerKeyState);
	}

	void uiLowerTerrainSelection(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e1821)(integerKeyState);
	}

	void uiFlattenTerrainSelection() {
		reinterpret_cast<void(*)()>(0x7e185b)();
	}

	void uiFilterTerrainSelection() {
		reinterpret_cast<void(*)()>(0x7e1879)();
	}

	void uiOpenScenarioBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e54fb)(a);
	}

	void uiSaveScenarioBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5681)(a);
	}

	void uiSaveAsScenarioBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e55d1)(a);
	}

	void uiOpenGrandConquestBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5714)(a);
	}

	void uiScenarioLoad() {
		reinterpret_cast<void(*)()>(0x7e2748)();
	}

	void uiStartScenarioTest() {
		reinterpret_cast<void(*)()>(0x7e1a09)();
	}

	void uiStopScenarioTest() {
		reinterpret_cast<void(*)()>(0x7e1a29)();
	}

	void uiStartBuildCinematic() {
		reinterpret_cast<void(*)()>(0x7e57c0)();
	}

	void uiStopBuildCinematic() {
		reinterpret_cast<void(*)()>(0x7e1a49)();
	}

	void uiClearCinematicInfo() {
		reinterpret_cast<void(*)()>(0x7e5801)();
	}

	void uiClearAllCinematicInfo() {
		reinterpret_cast<void(*)()>(0x7e5845)();
	}

	void uiOpenCameraTrackBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5889)(a);
	}

	void uiSaveCameraTrackBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e595f)(a);
	}

	void uiOpenSavedGameBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5a35)(a);
	}

	void uiSaveSavedGameBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5b0b)(a);
	}

	void uiZoomToProto(string stringProto) {
		reinterpret_cast<void(*)(string)>(0x7e5be1)(stringProto);
	}

	void uiOpenRecordGameBrowser(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5d4d)(a);
	}

	void uiLookAtSelection() {
		reinterpret_cast<void(*)()>(0x43a7b3)();
	}

	void uiLookAtUnit(int a) {
		reinterpret_cast<void(*)(int)>(0x7e5e7b)(a);
	}

	void uiLookAtBattle(int a) {
		reinterpret_cast<void(*)(int)>(0x7e1a69)(a);
	}

	void uiLookAtAndSelectUnit(int a) {
		reinterpret_cast<void(*)(int)>(0x7e5dfd)(a);
	}

	void uiLookAtUnitByName(string scenarioName) {
		reinterpret_cast<void(*)(string)>(0x7e5edb)(scenarioName);
	}

	void uiLookAtProto(string a) {
		reinterpret_cast<void(*)(string)>(0x7e5f7c)(a);
	}

	void uiLookAtNumberGroup(int integerGroup) {
		reinterpret_cast<void(*)(int)>(0x7e1aa4)(integerGroup);
	}

	void uiRoughen(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e1af9)(integerKeyState);
	}

	void uiDeleteUnits(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e1b34)(integerKeyState);
	}

	void uiPaint(bool integerKeyState, bool a) {
		reinterpret_cast<void(*)(bool, bool)>(0x7e1b6f)(integerKeyState, a);
	}

	void uiPaintForest(bool paint, bool offset) {
		reinterpret_cast<void(*)(bool, bool)>(0x7e1cc8)(paint, offset);
	}

	void uiPaintTerrainOverlay(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e1d83)(integerKeyState);
	}

	void uiPlaceAtPointer(bool boolChangeVariation) {
		reinterpret_cast<void(*)(bool)>(0x7e06db)(boolChangeVariation);
	}

	void uiSetProtoID(int integerType) {
		reinterpret_cast<void(*)(int)>(0x7e016a)(integerType);
	}

	void uiIncPlaceVariation() {
		reinterpret_cast<void(*)()>(0x7e0194)();
	}

	void uiBuildMode(int integerType) {
		reinterpret_cast<void(*)(int)>(0x7e48e0)(integerType);
	}

	void uiFindIdleType(string typeName) {
		reinterpret_cast<void(*)(string)>(0x7e7a50)(typeName);
	}

	void uiFindAllOfSelectedType() {
		reinterpret_cast<void(*)()>(0x7e49c2)();
	}

	void uiFindAllOfType(string a) {
		reinterpret_cast<void(*)(string)>(0x7e7ab9)(a);
	}

	void uiFindAllOfTypeIdle(string a) {
		reinterpret_cast<void(*)(string)>(0x7e7be9)(a);
	}

	void uiHandleIdleBanner(string typeName) {
		reinterpret_cast<void(*)(string)>(0x7e7dce)(typeName);
	}

	void uiFindTownBellTC(string a) {
		reinterpret_cast<void(*)(string)>(0x7e4e31)(a);
	}

	void uiFindType(string typeName) {
		reinterpret_cast<void(*)(string)>(0x7e774a)(typeName);
	}

	void uiCycleGadget(int integerDelta) {
		reinterpret_cast<void(*)(int)>(0x7e0c83)(integerDelta);
	}

	void uiCloseFieldSet() {
		reinterpret_cast<void(*)()>(0x7e4f99)();
	}

	void uiCloseDialog() {
		reinterpret_cast<void(*)()>(0x7e501f)();
	}

	void uiMessageBox(string stringText, string stringCommand) {
		reinterpret_cast<void(*)(string, string)>(0x7e0c88)(stringText, stringCommand);
	}

	void uiMessageBox2(int stringID, string stringCommand) {
		reinterpret_cast<void(*)(int, string)>(0x7e0ce9)(stringID, stringCommand);
	}

	void uiCopyToClipboard() {
		reinterpret_cast<void(*)()>(0x7e0d4a)();
	}

	void uiPasteFromClipboard() {
		reinterpret_cast<void(*)()>(0x7e0d6e)();
	}

	void uiSetClipboardRotation(float degrees) {
		reinterpret_cast<void(*)(float)>(0x7e0d92)(degrees);
	}

	void uiRotateClipboard(int degrees) {
		reinterpret_cast<void(*)(int)>(0x7e0dbc)(degrees);
	}

	void uiEjectGarrisonedUnits() {
		reinterpret_cast<void(*)()>(0x7e429c)();
	}

	void uiEjectAtPointer() {
		reinterpret_cast<void(*)()>(0x7e411f)();
	}

	void uiPatrolAtPointer() {
		reinterpret_cast<void(*)()>(0x7e7470)();
	}

	void uiApplyLightingSet(int integerIndex) {
		reinterpret_cast<void(*)(int)>(0x7e1dc1)(integerIndex);
	}

	void uiSetBrushType(string name, float p1, float p2, float p3, float p4) {
		reinterpret_cast<void(*)(string, float, float, float, float)>(0x7e1f39)(name, p1, p2, p3, p4);
	}

	void uiChangeBrushType(string name) {
		reinterpret_cast<void(*)(string)>(0x7e1fa8)(name);
	}

	void uiChangeBrushSize(float p1, float p2, float p3, float p4) {
		reinterpret_cast<void(*)(float, float, float, float)>(0x7e2003)(p1, p2, p3, p4);
	}

	void uiScrollBrushSize(int a) {
		reinterpret_cast<void(*)(int)>(0x7e2039)(a);
	}

	void uiChangeBrushCornerMode(int a) {
		reinterpret_cast<void(*)(int)>(0x7e207a)(a);
	}

	void uiChangeCliffModMode(int a) {
		reinterpret_cast<void(*)(int)>(0x7e20b5)(a);
	}

	void uiScrollCliffHeight(int a) {
		reinterpret_cast<void(*)(int)>(0x7e609a)(a);
	}

	void uiIgnoreNextKey() {
		reinterpret_cast<void(*)()>(0x512dd4)();
	}

	void uiCycleCurrentActivate() {
		reinterpret_cast<void(*)()>(0x7e24c3)();
	}

	void uiClearMenu(string a) {
		reinterpret_cast<void(*)(string)>(0x7e621b)(a);
	}

	void uiClearSelection() {
		reinterpret_cast<void(*)()>(0x7e24c8)();
	}

	void uiDumpKeyMappings(string stringContext) {
		reinterpret_cast<void(*)(string)>(0x7e2537)(stringContext);
	}

	void uiDumpAllUnitHotKeyMappings(string a) {
		reinterpret_cast<void(*)(string)>(0x7e2583)(a);
	}

	void uiDumpUnmappedKeys(string stringContext) {
		reinterpret_cast<void(*)(string)>(0x7e26eb)(stringContext);
	}

	void uiFindKeyMapping(string stringKeyname) {
		reinterpret_cast<void(*)(string)>(0x7e2731)(stringKeyname);
	}

	void uiHandleUserTab(int listSel, int parent) {
		reinterpret_cast<void(*)(int, int)>(0x7e50a5)(listSel, parent);
	}

	void uiCoverTerrainWithWater(float floatWaterHeight, float floatDepth, string waterName) {
		reinterpret_cast<void(*)(float, float, string)>(0x7e27b3)(floatWaterHeight, floatDepth, waterName);
	}

	bool uiSetCliffType(string stringCliffName) {
		return reinterpret_cast<bool(*)(string)>(0x7e2859)(stringCliffName);
	}

	bool uiSetCliffTypeNum(int longCliffType) {
		return reinterpret_cast<bool(*)(int)>(0x7e2894)(longCliffType);
	}

	bool uiSetWaterType(string stringWaterName) {
		return reinterpret_cast<bool(*)(string)>(0x7e28be)(stringWaterName);
	}

	bool uiSetWaterTypeNum(int longWaterType) {
		return reinterpret_cast<bool(*)(int)>(0x7e28f9)(longWaterType);
	}

	bool uiSetForestType(string stringForestName) {
		return reinterpret_cast<bool(*)(string)>(0x7e2923)(stringForestName);
	}

	bool uiSetForestTypeNum(int a) {
		return reinterpret_cast<bool(*)(int)>(0x7e2a0d)(a);
	}

	void uiSelectForestAtPointer() {
		reinterpret_cast<void(*)()>(0x7e2ada)();
	}

	void uiUnselectForest() {
		reinterpret_cast<void(*)()>(0x7e2af4)();
	}

	void uiSelectCliffAtPointer() {
		reinterpret_cast<void(*)()>(0x7e2b0e)();
	}

	void uiUnselectCliff() {
		reinterpret_cast<void(*)()>(0x7e2b28)();
	}

	void uiToggleCliff() {
		reinterpret_cast<void(*)()>(0x7e2b42)();
	}

	void gadgetScrollUp(string a) {
		reinterpret_cast<void(*)(string)>(0x7e20e8)(a);
	}

	void gadgetScrollDown(string a) {
		reinterpret_cast<void(*)(string)>(0x7e213f)(a);
	}

	void gadgetScrollLeft(string a) {
		reinterpret_cast<void(*)(string)>(0x7e2196)(a);
	}

	void gadgetScrollRight(string a) {
		reinterpret_cast<void(*)(string)>(0x7e21ed)(a);
	}

	void gadgetReal(string stringName) {
		reinterpret_cast<void(*)(string)>(0x7e2244)(stringName);
	}

	void gadgetUnreal(string stringName) {
		reinterpret_cast<void(*)(string)>(0x442be7)(stringName);
	}

	void gadgetToggle(string stringName) {
		reinterpret_cast<void(*)(string)>(0x7e2278)(stringName);
	}

	void gadgetToggleIfNotMP(string a) {
		reinterpret_cast<void(*)(string)>(0x7e22ac)(a);
	}

	void gadgetRefresh(string stringName) {
		reinterpret_cast<void(*)(string)>(0x7e22f0)(stringName);
	}

	void gadgetFlash(string stringName, bool flash) {
		reinterpret_cast<void(*)(string, bool)>(0x7e61ac)(stringName, flash);
	}

	void techFlash(int techID, bool flash) {
		reinterpret_cast<void(*)(int, bool)>(0x7e2332)(techID, flash);
	}

	void trainFlash(int protoID, bool flash) {
		reinterpret_cast<void(*)(int, bool)>(0x7e235b)(protoID, flash);
	}

	void categoryFlash(int ID, bool flash) {
		reinterpret_cast<void(*)(int, bool)>(0x98160f)(ID, flash);
	}

	void fadeToColor(int r, int g, int b, int duration, int delay, bool inout) {
		reinterpret_cast<void(*)(int, int, int, int, int, bool)>(0x7e2384)(r, g, b, duration, delay, inout);
	}

	void setGameFadeIn(int r, int g, int b, int duration, int delay, bool inout) {
		reinterpret_cast<void(*)(int, int, int, int, int, bool)>(0x7e242d)(r, g, b, duration, delay, inout);
	}

	void uiLoadTriggers(string a) {
		reinterpret_cast<void(*)(string)>(0x7e627c)(a);
	}

	void uiSaveTriggers(string a) {
		reinterpret_cast<void(*)(string)>(0x7e2b5c)(a);
	}

	void uiImportTriggers(string a) {
		reinterpret_cast<void(*)(string)>(0x7e63cc)(a);
	}

	void doTriggerImport(string a) {
		reinterpret_cast<void(*)(string)>(0x7e64ae)(a);
	}

	void uiExportTriggers(string a) {
		reinterpret_cast<void(*)(string)>(0x7e62ea)(a);
	}

	void uiTriggerSelectLocation() {
		reinterpret_cast<void(*)()>(0x7e2b86)();
	}

	void uiTriggerResetParameters() {
		reinterpret_cast<void(*)()>(0x7e2bf1)();
	}

	void uiTriggerResetSounds() {
		reinterpret_cast<void(*)()>(0x7e2c15)();
	}

	void uiExportGrouping(string a) {
		reinterpret_cast<void(*)(string)>(0x7e651c)(a);
	}

	void uiSaveGrouping(string a) {
		reinterpret_cast<void(*)(string)>(0x7e2c39)(a);
	}

	void uiSaveGroupingLUA(int a, string b) {
		reinterpret_cast<void(*)(int, string)>(0x7e2ca0)(a, b);
	}

	void uiHideCursor(bool a) {
		reinterpret_cast<void(*)(bool)>(0x7e2d42)(a);
	}

	void uiLeaveModeOnUnshift() {
		reinterpret_cast<void(*)()>(0x7e2d2b)();
	}

	void uiToggleBrushMask(int a) {
		reinterpret_cast<void(*)(int)>(0x7e65fe)(a);
	}

	void uiToggleTerrainPasteMode(int a) {
		reinterpret_cast<void(*)(int)>(0x7e2d57)(a);
	}

	void uiUnitDetailHelp(int protoID, int civID) {
		reinterpret_cast<void(*)(int, int)>(0x7e665d)(protoID, civID);
	}

	void uiTechDetailHelp(int techID) {
		reinterpret_cast<void(*)(int)>(0x7e2da4)(techID);
	}

	void uiTechCivDetailHelp(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x7e2dea)(a, b);
	}

	void uiTopicDetailHelp(string topicName) {
		reinterpret_cast<void(*)(string)>(0x7e2e33)(topicName);
	}

	void uiLastDetailHelp() {
		reinterpret_cast<void(*)()>(0x7e2e6e)();
	}

	void AIDebugInfoRefresh() {
		reinterpret_cast<void(*)()>(0x7e2e86)();
	}

	void AIDebugInfoToggle() {
		reinterpret_cast<void(*)()>(0x7e2eaf)();
	}

	void AIDebugOutputToggle() {
		reinterpret_cast<void(*)()>(0x7e2f7b)();
	}

	void AIDebugGathererToggle() {
		reinterpret_cast<void(*)()>(0x7e2fee)();
	}

	void AIDebugPopToggle() {
		reinterpret_cast<void(*)()>(0x7e3061)();
	}

	void AIDebugPastResourceNeedToggle() {
		reinterpret_cast<void(*)()>(0x7e30d4)();
	}

	void AIDebugTimedStatsToggle() {
		reinterpret_cast<void(*)()>(0x7e3147)();
	}

	void AIDebugShowBasesToggle() {
		reinterpret_cast<void(*)()>(0x7e31ba)();
	}

	void AIDebugToggleBPText() {
		reinterpret_cast<void(*)()>(0x7e76c9)();
	}

	void uiShowAIDebugInfoPlan(int a) {
		reinterpret_cast<void(*)(int)>(0x7e31c6)(a);
	}

	void uiShowAIDebugInfoPlacement(int a) {
		reinterpret_cast<void(*)(int)>(0x7e325c)(a);
	}

	void uiShowAIDebugInfoProgression(int a) {
		reinterpret_cast<void(*)(int)>(0x7e32a3)(a);
	}

	void uiShowAIDebugInfoKBUnit(int a) {
		reinterpret_cast<void(*)(int)>(0x7e32d3)(a);
	}

	void uiShowAIDebugInfoBase(int a) {
		reinterpret_cast<void(*)(int)>(0x7e3329)(a);
	}

	void uiShowAIDebugInfoArea(int a) {
		reinterpret_cast<void(*)(int)>(0x7e3353)(a);
	}

	void uiShowAIDebugInfoAreaGroup(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x7e339c)(a, b);
	}

	void uiSetKBAttackRouteRender(int a, bool b) {
		reinterpret_cast<void(*)(int, bool)>(0x7e677d)(a, b);
	}

	void uiShowAIDebugInfoAttackRoute(int a) {
		reinterpret_cast<void(*)(int)>(0x7e682c)(a);
	}

	void uiSetKBResourceRender(int resID, bool set) {
		reinterpret_cast<void(*)(int, bool)>(0x7e33ef)(resID, set);
	}

	void uiShowAIDebugInfoKBResource(int a) {
		reinterpret_cast<void(*)(int)>(0x7e34b3)(a);
	}

	void uiSetKBArmyRender(int id, bool set) {
		reinterpret_cast<void(*)(int, bool)>(0x7e34f5)(id, set);
	}

	void uiShowAIDebugInfoKBArmy(int a) {
		reinterpret_cast<void(*)(int)>(0x7e3568)(a);
	}

	void uiShowAIDebugInfoKBUnitPick(int a) {
		reinterpret_cast<void(*)(int)>(0x7e35aa)(a);
	}

	void uiShowAIDebugInfoEscrow(int a) {
		reinterpret_cast<void(*)(int)>(0x7e35d4)(a);
	}

	void uiSetBuildingPlacementRender(int id, bool on) {
		reinterpret_cast<void(*)(int, bool)>(0x7e31f6)(id, on);
	}

	void uiChatScrollBack(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e35fe)(integerKeyState);
	}

	void uiChatScrollForward(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x7e3644)(integerKeyState);
	}

	void uiChatDisplayModeToggle() {
		reinterpret_cast<void(*)()>(0x7e3689)();
	}

	void uiChatDisplayModeToRecent() {
		reinterpret_cast<void(*)()>(0x7e36a1)();
	}

	void uiChatDisplayModeToHistory() {
		reinterpret_cast<void(*)()>(0x7e36b9)();
	}

	void uiClearChat(bool clearOnly) {
		reinterpret_cast<void(*)(bool)>(0x7e36d1)(clearOnly);
	}

	void uiAddChatNotification(int a, int b, int c, int d) {
		reinterpret_cast<void(*)(int, int, int, int)>(0x7e36ee)(a, b, c, d);
	}

	void uiSetHCNotifyText(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x7e376d)(a, b);
	}

	void uiShowChatWindow() {
		reinterpret_cast<void(*)()>(0x512be7)();
	}

	void uiReleaseDownKeys() {
		reinterpret_cast<void(*)()>(0x7e37e3)();
	}

	void uiSpewDownKeys() {
		reinterpret_cast<void(*)()>(0x7e37fb)();
	}

	void uiShowVoteDialog() {
		reinterpret_cast<void(*)()>(0x7e3813)();
	}

	void uiSendIngameChat() {
		reinterpret_cast<void(*)()>(0x7e3848)();
	}

	void uiPoliticianUI(int a, int b, bool c) {
		reinterpret_cast<void(*)(int, int, bool)>(0x7e686e)(a, b, c);
	}

	void uiPoliticianUIInSelected(string a) {
		reinterpret_cast<void(*)(string)>(0x7e7ec1)(a);
	}

	void uiConsulateUI(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x7e6a36)(a, b);
	}

	void uiConsulateUIInSelected() {
		reinterpret_cast<void(*)()>(0x7e6b26)();
	}

	void enterAttackMoveMode() {
		reinterpret_cast<void(*)()>(0x7e6c5e)();
	}

	void uiShowObjectivesDialog() {
		reinterpret_cast<void(*)()>(0x7e38e9)();
	}

	void uiExpireCurrentObjectiveNotification(bool a) {
		reinterpret_cast<void(*)(bool)>(0x7e391e)(a);
	}

	void uiPlaceTradeRouteWaypoint() {
		reinterpret_cast<void(*)()>(0x7e38a1)();
	}

	void uiRemoveTradeRouteWaypoint() {
		reinterpret_cast<void(*)()>(0x7e38c5)();
	}

	void uiSelectTransportUnit() {
		reinterpret_cast<void(*)()>(0x7e3942)();
	}

	void uiFindResourceGatherers(string typeName) {
		reinterpret_cast<void(*)(string)>(0x7e7d38)(typeName);
	}

	void uiFindGatherersNotGathering() {
		reinterpret_cast<void(*)()>(0x7e7dae)();
	}

	void uiFindDancers() {
		reinterpret_cast<void(*)()>(0x7e7d9e)();
	}

	void uiSelectFirepit() {
		reinterpret_cast<void(*)()>(0x7e0bf6)();
	}

	void uiFindAlliedNatives() {
		reinterpret_cast<void(*)()>(0x7e7dbe)();
	}

	void uiVPAccelClick(int unitID) {
		reinterpret_cast<void(*)(int)>(0x7e6cb8)(unitID);
	}

	void incrementUSP2SelectedUnitStack() {
		reinterpret_cast<void(*)()>(0x7e6d5a)();
	}

	void decrementUSP2SelectedUnitStack() {
		reinterpret_cast<void(*)()>(0x7e6da1)();
	}

	void uiSetCameraStartLoc() {
		reinterpret_cast<void(*)()>(0x7e192e)();
	}

	void uiShowCameraStartLoc() {
		reinterpret_cast<void(*)()>(0x7e19b6)();
	}

	void uiDeleteCameraStartLoc() {
		reinterpret_cast<void(*)()>(0x7e19ce)();
	}

	void uiCameraScroll(bool fast, float x, float y) {
		reinterpret_cast<void(*)(bool, float, float)>(0x7e3a43)(fast, x, y);
	}

	void uiCameraControl(float x, float y) {
		reinterpret_cast<void(*)(float, float)>(0x7e3a63)(x, y);
	}

	void uiMapPointerControl(float x, float y, bool doGoto) {
		reinterpret_cast<void(*)(float, float, bool)>(0x7e3bec)(x, y, doGoto);
	}

	void uiMapPointerGoto(bool activeCheck) {
		reinterpret_cast<void(*)(bool)>(0x7e3ac0)(activeCheck);
	}

	void uiCircleSelect(bool on, bool doubleClick, bool leaveSelected) {
		reinterpret_cast<void(*)(bool, bool, bool)>(0x7e3e66)(on, doubleClick, leaveSelected);
	}

	void uiCircleSelectResize(float x, float y) {
		reinterpret_cast<void(*)(float, float)>(0x7e3e9e)(x, y);
	}

	void uiCenterPointer() {
		reinterpret_cast<void(*)()>(0x7e3eba)();
	}

	void uiForceShift(bool on) {
		reinterpret_cast<void(*)(bool)>(0x7e3f00)(on);
	}

	void uiScreenSelect(bool modifier) {
		reinterpret_cast<void(*)(bool)>(0x7e3f1f)(modifier);
	}

	void uiResetScreenSelect() {
		reinterpret_cast<void(*)()>(0x7e3f36)();
	}

	void uiFindCrowd(int a, bool b) {
		reinterpret_cast<void(*)(int, bool)>(0x7e3f46)(a, b);
	}

	void uiResetFindCrowd() {
		reinterpret_cast<void(*)()>(0x7e3f96)();
	}

	void uiShowStatPanel() {
		reinterpret_cast<void(*)()>(0x7e39cd)();
	}

	void uiShowDetailedHelp() {
		reinterpret_cast<void(*)()>(0x7e3956)();
	}

	void uiShowCommandPanel() {
		reinterpret_cast<void(*)()>(0x7e3a1b)();
	}

	void uiMinimizeStats() {
		reinterpret_cast<void(*)()>(0x7e397e)();
	}

	void uiMoveAllMilitaryAtPointer() {
		reinterpret_cast<void(*)()>(0x7e3fa6)();
	}

	void sendAttackSentence(int sendingPlayer, int receivingPlayer, int targetPlayer, int targetUnit, float xPos, float zPos) {
		reinterpret_cast<void(*)(int, int, int, int, float, float)>(0x6f1e6e)(sendingPlayer, receivingPlayer, targetPlayer, targetUnit, xPos, zPos);
	}

	void sendDefendSentence(int sendingPlayer, int receivingPlayer, float xPos, float zPos) {
		reinterpret_cast<void(*)(int, int, float, float)>(0x6f1bab)(sendingPlayer, receivingPlayer, xPos, zPos);
	}

	void sendTributeSentence(int sendingPlayer, int receivingPlayer, int resourceID) {
		reinterpret_cast<void(*)(int, int, int)>(0x6f1fee)(sendingPlayer, receivingPlayer, resourceID);
	}

	void sendPromptType(int sendingPlayer, int promptType) {
		reinterpret_cast<void(*)(int, int)>(0x6f0ff6)(sendingPlayer, promptType);
	}

	void startRandomGame(bool a) {
		reinterpret_cast<void(*)(bool)>(0x6f041c)(a);
	}

	void startRandomGame2(string filename, int players, int random, string seed, bool scenarioFilename, int debug, int teamCount, int mapsize, bool resources) {
		reinterpret_cast<void(*)(string, int, int, string, bool, int, int, int, bool)>(0x6f10fc)(filename, players, random, seed, scenarioFilename, debug, teamCount, mapsize, resources);
	}

	void startRandomGameMapCode(string mapcode) {
		reinterpret_cast<void(*)(string)>(0x6f1340)(mapcode);
	}

	void startRandomGameAgeAndMapCode(int startingage, bool nomad, string mapcode) {
		reinterpret_cast<void(*)(int, bool, string)>(0x6f17f4)(startingage, nomad, mapcode);
	}

	void restartCurrentGame() {
		reinterpret_cast<void(*)()>(0x6f044e)();
	}

	void leaveGame(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x5683f6)(a, b);
	}

	void handlePostGame() {
		reinterpret_cast<void(*)()>(0x6f046d)();
	}

	void showGameFromPostGame() {
		reinterpret_cast<void(*)()>(0x6f05b1)();
	}

	void postGamePlayAgain() {
		reinterpret_cast<void(*)()>(0x6f062a)();
	}

	void minimapZoomDelta(float floatZoomDelta) {
		reinterpret_cast<void(*)(float)>(0x6f068b)(floatZoomDelta);
	}

	void minimapZoom(float floatZoom) {
		reinterpret_cast<void(*)(float)>(0x6f06a1)(floatZoom);
	}

	void minimapRotateMode(int integerMode) {
		reinterpret_cast<void(*)(int)>(0x6f184a)(integerMode);
	}

	void chat(string stringText, int integerPlayer) {
		reinterpret_cast<void(*)(string, int)>(0x6f0652)(stringText, integerPlayer);
	}

	void uiSpecialPowerAtPointer() {
		reinterpret_cast<void(*)()>(0x6f06b7)();
	}

	void uiToggleGame() {
		reinterpret_cast<void(*)()>(0x6f040c)();
	}

	void uiZoomToMinimapEvent() {
		reinterpret_cast<void(*)()>(0x6f06c7)();
	}

	void uiRefreshEditorMenu() {
		reinterpret_cast<void(*)()>(0x6f07bf)();
	}

	void uiShowTributeDialog() {
		reinterpret_cast<void(*)()>(0x6f06ff)();
	}

	void uiHideTributeDialog() {
		reinterpret_cast<void(*)()>(0x6f0739)();
	}

	void uiShowPlayerSummaryDialog() {
		reinterpret_cast<void(*)()>(0x6f075f)();
	}

	void uiHidePlayerSummaryDialog() {
		reinterpret_cast<void(*)()>(0x6f0799)();
	}

	void uiNewScenario() {
		reinterpret_cast<void(*)()>(0x6f084e)();
	}

	void sunIncreaseInclination(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x6f033c)(integerKeyState);
	}

	void sunDecreaseInclination(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x6f0370)(integerKeyState);
	}

	void sunIncreaseRotation(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x6f03a4)(integerKeyState);
	}

	void sunDecreaseRotation(int integerKeyState) {
		reinterpret_cast<void(*)(int)>(0x6f03d8)(integerKeyState);
	}

	void setSunPosition(float a, float b, bool c) {
		reinterpret_cast<void(*)(float, float, bool)>(0x6f10ab)(a, b, c);
	}

	void abortCinematic() {
		reinterpret_cast<void(*)()>(0x6f1cd6)();
	}

	void scoreUpdate() {
		reinterpret_cast<void(*)()>(0x6f08b3)();
	}

	void toggleScore() {
		reinterpret_cast<void(*)()>(0x6f08c8)();
	}

	void toggleTime() {
		reinterpret_cast<void(*)()>(0x6f095d)();
	}

	void toggleDebugTime() {
		reinterpret_cast<void(*)()>(0x6f0a8f)();
	}

	void doSPSetup(bool a) {
		reinterpret_cast<void(*)(bool)>(0x6f0bb1)(a);
	}

	void doMPSetup(bool useESO) {
		reinterpret_cast<void(*)(bool)>(0x6f0caa)(useESO);
	}

	void exitMPSetupSubScreen() {
		reinterpret_cast<void(*)()>(0x6f1921)();
	}

	void enterRecordGameMode(string name) {
		reinterpret_cast<void(*)(string)>(0x6f0dcd)(name);
	}

	void enterGCGameMode(string name) {
		reinterpret_cast<void(*)(string)>(0x6f1978)(name);
	}

	void showCampaignDialog(string name, string msg) {
		reinterpret_cast<void(*)(string, string)>(0x6f0e7a)(name, msg);
	}

	void playerResign() {
		reinterpret_cast<void(*)()>(0x6f0ec3)();
	}

	void showGameMenu() {
		reinterpret_cast<void(*)()>(0x56b16c)();
	}

	void hideGameMenu(bool a) {
		reinterpret_cast<void(*)(bool)>(0x6f0edb)(a);
	}

	void uiSaveCampaignGameBrowser() {
		reinterpret_cast<void(*)()>(0x6f1ad7)();
	}

	void uiInitOptionsScreenProfileEditDialog() {
		reinterpret_cast<void(*)()>(0x6f0f4f)();
	}

	void uiBMultiplayerSave() {
		reinterpret_cast<void(*)()>(0x6f0f0f)();
	}

	void dropToMainMenu() {
		reinterpret_cast<void(*)()>(0x6f0f83)();
	}

	bool modelLoad(string a) {
		return reinterpret_cast<bool(*)(string)>(0x4474c9)(a);
	}

	void changeCliffType(string cliffName) {
		reinterpret_cast<void(*)(string)>(0x6f1d3d)(cliffName);
	}

	void uiCommandPanelControl(bool on) {
		reinterpret_cast<void(*)(bool)>(0x6f102a)(on);
	}

	void uiCommandPanelMove(float x, float y) {
		reinterpret_cast<void(*)(float, float)>(0x6f1041)(x, y);
	}

	void uiCommandPanelExecute(bool a) {
		reinterpret_cast<void(*)(bool)>(0x6f105d)(a);
	}

	void winScenario() {
		reinterpret_cast<void(*)()>(0x6f0fdd)();
	}

	void xsDisableRule(string ruleName) {
		reinterpret_cast<void(*)(string)>(0xa5d578)(ruleName);
	}

	void xsDisableSelf() {
		reinterpret_cast<void(*)()>(0x42f897)();
	}

	void xsEnableRule(string ruleName) {
		reinterpret_cast<void(*)(string)>(0x42f856)(ruleName);
	}

	bool xsIsRuleEnabled(string ruleName) {
		return reinterpret_cast<bool(*)(string)>(0xa5d26c)(ruleName);
	}

	void xsSetRulePriority(string ruleName, int priority) {
		reinterpret_cast<void(*)(string, int)>(0xa5d27b)(ruleName, priority);
	}

	void xsSetRulePrioritySelf(int priority) {
		reinterpret_cast<void(*)(int)>(0xa5d590)(priority);
	}

	void xsSetRuleMinInterval(string ruleName, int interval) {
		reinterpret_cast<void(*)(string, int)>(0x42fd16)(ruleName, interval);
	}

	void xsSetRuleMinIntervalSelf(int interval) {
		reinterpret_cast<void(*)(int)>(0x42e5d7)(interval);
	}

	void xsSetRuleMaxInterval(string ruleName, int interval) {
		reinterpret_cast<void(*)(string, int)>(0x637c56)(ruleName, interval);
	}

	void xsSetRuleMaxIntervalSelf(int interval) {
		reinterpret_cast<void(*)(int)>(0x427fcc)(interval);
	}

	void xsEnableRuleGroup(string ruleGroupName) {
		reinterpret_cast<void(*)(string)>(0xa5d5be)(ruleGroupName);
	}

	void xsDisableRuleGroup(string ruleGroupName) {
		reinterpret_cast<void(*)(string)>(0xa5d5a6)(ruleGroupName);
	}

	void xsIsRuleGroupEnabled(string ruleGroupName) {
		reinterpret_cast<void(*)(string)>(0xa5d29b)(ruleGroupName);
	}

	float xsVectorGetX(vector v) {
		return reinterpret_cast<float(*)(vector)>(0xa5d2aa)(v);
	}

	float xsVectorGetY(vector v) {
		return reinterpret_cast<float(*)(vector)>(0xa5d2bc)(v);
	}

	float xsVectorGetZ(vector v) {
		return reinterpret_cast<float(*)(vector)>(0xa5d2cf)(v);
	}

	vector xsVectorSetX(vector result, vector v, float x) {
		return reinterpret_cast<vector(*)(vector, vector, float)>(0xa5d5d6)(result, v, x);
	}

	vector xsVectorSetY(vector result, vector v, float y) {
		return reinterpret_cast<vector(*)(vector, vector, float)>(0xa5d625)(result, v, y);
	}

	vector xsVectorSetZ(vector result, vector v, float z) {
		return reinterpret_cast<vector(*)(vector, vector, float)>(0xa5d674)(result, v, z);
	}

	vector xsVectorSet(vector result, float x, float y, float z) {
		return reinterpret_cast<vector(*)(vector, float, float, float)>(0xa5d6be)(result, x, y, z);
	}

	float xsVectorLength(vector v) {
		return reinterpret_cast<float(*)(vector)>(0xa5d6f5)(v);
	}

	vector xsVectorNormalize(vector result, vector v) {
		return reinterpret_cast<vector(*)(vector, vector)>(0xa5d725)(result, v);
	}

	int xsArrayCreateInt(int size, int defaultValue, string name) {
		return reinterpret_cast<int(*)(int, int, string)>(0xa5d2e2)(size, defaultValue, name);
	}

	bool xsArraySetInt(int arrayID, int index, int value) {
		return reinterpret_cast<bool(*)(int, int, int)>(0xa5d316)(arrayID, index, value);
	}

	int xsArrayGetInt(int arrayID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0xa5d32f)(arrayID, index);
	}

	int xsArrayCreateFloat(int size, float defaultValue, string name) {
		return reinterpret_cast<int(*)(int, float, string)>(0xa5d343)(size, defaultValue, name);
	}

	bool xsArraySetFloat(int arrayID, int index, float value) {
		return reinterpret_cast<bool(*)(int, int, float)>(0xa5d377)(arrayID, index, value);
	}

	float xsArrayGetFloat(int arrayID, int index) {
		return reinterpret_cast<float(*)(int, int)>(0xa5d390)(arrayID, index);
	}

	int xsArrayCreateBool(int size, bool defaultValue, string name) {
		return reinterpret_cast<int(*)(int, bool, string)>(0xa5d3a4)(size, defaultValue, name);
	}

	bool xsArraySetBool(int arrayID, int index, bool value) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0xa5d3d8)(arrayID, index, value);
	}

	bool xsArrayGetBool(int a, int b) {
		return reinterpret_cast<bool(*)(int, int)>(0xa5d3f1)(a, b);
	}

	int xsArrayCreateString(int size, string defaultValue, string name) {
		return reinterpret_cast<int(*)(int, string, string)>(0xa5d405)(size, defaultValue, name);
	}

	bool xsArraySetString(int arrayID, int index, string value) {
		return reinterpret_cast<bool(*)(int, int, string)>(0xa5d450)(arrayID, index, value);
	}

	string xsArrayGetString(int arrayID, int index) {
		return reinterpret_cast<string(*)(int, int)>(0xa5d484)(arrayID, index);
	}

	int xsArrayCreateVector(int size, vector defaultValue, string name) {
		return reinterpret_cast<int(*)(int, vector, string)>(0xa5d498)(size, defaultValue, name);
	}

	bool xsArraySetVector(int arrayID, int index, vector value) {
		return reinterpret_cast<bool(*)(int, int, vector)>(0xa5d4cc)(arrayID, index, value);
	}

	vector xsArrayGetVector(vector result, int arrayID, int index) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0xa5d4e5)(result, arrayID, index);
	}

	int xsArrayGetSize(int arrayID) {
		return reinterpret_cast<int(*)(int)>(0xa5d502)(arrayID);
	}

	void xsDumpArrays() {
		reinterpret_cast<void(*)()>(0xa5d511)();
	}

	int xsGetContextPlayer() {
		return reinterpret_cast<int(*)()>(0xa5d7c4)();
	}

	void xsSetContextPlayer(int playerID) {
		reinterpret_cast<void(*)(int)>(0xa5d7ca)(playerID);
	}

	int xsGetTime() {
		return reinterpret_cast<int(*)()>(0xa5d7d4)();
	}

	bool xsAddRuntimeEvent(string foo, string bar, int something) {
		return reinterpret_cast<bool(*)(string, string, int)>(0xa5d51a)(foo, bar, something);
	}

	int xsGetFunctionID(string a) {
		return reinterpret_cast<int(*)(string)>(0xa5d569)(a);
	}

	void rmEchoWarning(string echoString) {
		reinterpret_cast<void(*)(string)>(0x9017e5)(echoString);
	}

	void rmEchoError(string echoString) {
		reinterpret_cast<void(*)(string)>(0x9018eb)(echoString);
	}

	float rmRandFloat(float min, float max) {
		return reinterpret_cast<float(*)(float, float)>(0x90b66c)(min, max);
	}

	int rmRandInt(int min, int max) {
		return reinterpret_cast<int(*)(int, int)>(0x90eeac)(min, max);
	}

	bool rmGetNomadStart() {
		return reinterpret_cast<bool(*)()>(0x90b683)();
	}

	bool rmGetIsFFA() {
		return reinterpret_cast<bool(*)()>(0x90b69c)();
	}

	bool rmGetIsRelicCapture() {
		return reinterpret_cast<bool(*)()>(0x90b6b5)();
	}

	bool rmGetIsKOTH() {
		return reinterpret_cast<bool(*)()>(0x90b6ce)();
	}

	bool rmSetMapSize(float x, float z) {
		return reinterpret_cast<bool(*)(float, float)>(0x90b6e7)(x, z);
	}

	int rmGetMapXSize() {
		return reinterpret_cast<int(*)()>(0x90b709)();
	}

	int rmGetMapZSize() {
		return reinterpret_cast<int(*)()>(0x90b71d)();
	}

	void rmSetSeaLevel(float a) {
		reinterpret_cast<void(*)(float)>(0x90bee9)(a);
	}

	float rmGetSeaLevel() {
		return reinterpret_cast<float(*)()>(0x90c195)();
	}

	bool rmSetSeaType(string name) {
		return reinterpret_cast<bool(*)(string)>(0x90bf10)(name);
	}

	bool rmSetMapElevationParameters(int type, float freq, int octaves, float persistence, float variation) {
		return reinterpret_cast<bool(*)(int, float, int, float, float)>(0x90bf3a)(type, freq, octaves, persistence, variation);
	}

	bool rmSetBaseTerrainMix(string mixName) {
		return reinterpret_cast<bool(*)(string)>(0x90bf7f)(mixName);
	}

	bool rmAddMapTerrainByHeightInfo(string terrain, float minHeight, float maxHeight, float outerRange) {
		return reinterpret_cast<bool(*)(string, float, float, float)>(0x90bfa9)(terrain, minHeight, maxHeight, outerRange);
	}

	bool rmAddMapTerrainByAngleInfo(string terrain, float minSlope, float maxSlope, float outerRange) {
		return reinterpret_cast<bool(*)(string, float, float, float)>(0x90bfff)(terrain, minSlope, maxSlope, outerRange);
	}

	bool rmSetMapElevationHeightBlend(int blend) {
		return reinterpret_cast<bool(*)(int)>(0x90c055)(blend);
	}

	bool rmPlaceMapClusters(string terrain, string protounit) {
		return reinterpret_cast<bool(*)(string, string)>(0x90c07e)(terrain, protounit);
	}

	bool rmSetMapClusteringPlacementParams(float paintThreshold, float placeMinVal, float placeMaxVal, int type) {
		return reinterpret_cast<bool(*)(float, float, float, int)>(0x90c0e3)(paintThreshold, placeMinVal, placeMaxVal, type);
	}

	bool rmSetMapClusteringObjectParams(int minObjectCount, int maxObjectCount, float maxPosOffset) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x90c124)(minObjectCount, maxObjectCount, maxPosOffset);
	}

	bool rmSetMapClusteringNoiseParams(float minFrequency, int octaves, float persistence) {
		return reinterpret_cast<bool(*)(float, int, float)>(0x90c15b)(minFrequency, octaves, persistence);
	}

	int rmAreaFractionToTiles(float fraction) {
		return reinterpret_cast<int(*)(float)>(0x90c38e)(fraction);
	}

	float rmAreaTilesToFraction(int tiles) {
		return reinterpret_cast<float(*)(int)>(0x90c3b8)(tiles);
	}

	int rmXFractionToTiles(float fraction) {
		return reinterpret_cast<int(*)(float)>(0x90c3e6)(fraction);
	}

	float rmXTilesToFraction(int tiles) {
		return reinterpret_cast<float(*)(int)>(0x90c410)(tiles);
	}

	int rmZFractionToTiles(float fraction) {
		return reinterpret_cast<int(*)(float)>(0x90c43e)(fraction);
	}

	float rmZTilesToFraction(int tiles) {
		return reinterpret_cast<float(*)(int)>(0x90c468)(tiles);
	}

	float rmDegreesToRadians(float degrees) {
		return reinterpret_cast<float(*)(float)>(0x90d640)(degrees);
	}

	int rmMetersToTiles(float meters) {
		return reinterpret_cast<int(*)(float)>(0x90c496)(meters);
	}

	float rmXMetersToFraction(float meters) {
		return reinterpret_cast<float(*)(float)>(0x90c51c)(meters);
	}

	float rmZMetersToFraction(float meters) {
		return reinterpret_cast<float(*)(float)>(0x90c54a)(meters);
	}

	float rmXFractionToMeters(float meters) {
		return reinterpret_cast<float(*)(float)>(0x90c4c0)(meters);
	}

	float rmZFractionToMeters(float meters) {
		return reinterpret_cast<float(*)(float)>(0x90c4ee)(meters);
	}

	int rmCreateArea(string name, int parentAreaID) {
		return reinterpret_cast<int(*)(string, int)>(0x90c1bc)(name, parentAreaID);
	}

	bool rmSetAreaSize(int minFraction, float maxFraction, float a) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90c1ec)(minFraction, maxFraction, a);
	}

	bool rmSetAreaEdgeFilling(int areaID, int borderSize) {
		return reinterpret_cast<bool(*)(int, int)>(0x90c220)(areaID, borderSize);
	}

	bool rmSetAreaLocation(int areaID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90c5f9)(areaID, xFraction, zFraction);
	}

	bool rmSetAreaLocPlayer(int areaID, int playerID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90c62d)(areaID, playerID);
	}

	bool rmSetAreaLocTeam(int areaID, int teamID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90c65c)(areaID, teamID);
	}

	bool rmBuildArea(int areaID) {
		return reinterpret_cast<bool(*)(int)>(0x90c251)(areaID);
	}

	int rmBuildAllAreas() {
		return reinterpret_cast<int(*)()>(0x90c27b)();
	}

	bool rmSetAreaTerrainType(int areaID, string terrainTypeName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90c6ba)(areaID, terrainTypeName);
	}

	bool rmSetAreaMix(int areaID, string mixName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90c6e9)(areaID, mixName);
	}

	bool rmPaintAreaTerrain(int areaID) {
		return reinterpret_cast<bool(*)(int)>(0x90c29e)(areaID);
	}

	bool rmPaintAreaTerrainByHeight(int areaID, string terrain, float minHeight, float maxHeight, float outerRange) {
		return reinterpret_cast<bool(*)(int, string, float, float, float)>(0x90c2c8)(areaID, terrain, minHeight, maxHeight, outerRange);
	}

	bool rmPaintAreaTerrainByAngle(int areaID, string terrain, float minAngle, float maxAngle, float outerRange) {
		return reinterpret_cast<bool(*)(int, string, float, float, float)>(0x90c32b)(areaID, terrain, minAngle, maxAngle, outerRange);
	}

	bool rmSetAreaBaseHeight(int areaID, float height) {
		return reinterpret_cast<bool(*)(int, float)>(0x90cd38)(areaID, height);
	}

	bool rmSetAreaWarnFailure(int areaID, bool warn) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90cd67)(areaID, warn);
	}

	bool rmSetAreaForestType(int areaID, string forestName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90c718)(areaID, forestName);
	}

	bool rmSetAreaForestDensity(int areaID, float density) {
		return reinterpret_cast<bool(*)(int, float)>(0x90c747)(areaID, density);
	}

	bool rmSetAreaForestClumpiness(int areaID, float density) {
		return reinterpret_cast<bool(*)(int, float)>(0x90c776)(areaID, density);
	}

	bool rmSetAreaForestUnderbrush(int areaID, float density) {
		return reinterpret_cast<bool(*)(int, float)>(0x90c7a5)(areaID, density);
	}

	bool rmSetAreaWaterType(int areaID, string waterName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90c7d4)(areaID, waterName);
	}

	vector rmGetAreaClosestPoint(vector result, int areaID, vector point, float pullback, int constraintID) {
		return reinterpret_cast<vector(*)(vector, int, vector, float, int)>(0x90c803)(result, areaID, point, pullback, constraintID);
	}

	bool rmSetAreaCliffType(int areaID, string cliffName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90c863)(areaID, cliffName);
	}

	bool rmSetAreaCliffPainting(int areaID, bool paintGround, bool paintOutsideEdge, bool paintSide, float minSideHeight, bool paintInsideEdge) {
		return reinterpret_cast<bool(*)(int, bool, bool, bool, float, bool)>(0x90c892)(areaID, paintGround, paintOutsideEdge, paintSide, minSideHeight, paintInsideEdge);
	}

	bool rmSetAreaCliffEdge(int areaID, int count, float size, float variance, float spacing, int mapEdge) {
		return reinterpret_cast<bool(*)(int, int, float, float, float, int)>(0x90c8d5)(areaID, count, size, variance, spacing, mapEdge);
	}

	bool rmSetAreaCliffHeight(int areaID, float val, float variance, float ramp) {
		return reinterpret_cast<bool(*)(int, float, float, float)>(0x90c918)(areaID, val, variance, ramp);
	}

	bool rmAddAreaCliffEdgeAvoidClass(int areaID, int avoidID, float minDist) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x90c951)(areaID, avoidID, minDist);
	}

	int rmRiverCreate(int areaID, string waterType, int breaks, int offset, int minR, int maxR) {
		return reinterpret_cast<int(*)(int, string, int, int, int, int)>(0x90c9f7)(areaID, waterType, breaks, offset, minR, maxR);
	}

	bool rmRiverSetConnections(int a, float b, float c, float d, float e) {
		return reinterpret_cast<bool(*)(int, float, float, float, float)>(0x90ca3b)(a, b, c, d, e);
	}

	bool rmRiverConnectRiver(int a, int b, float c, float d, float e) {
		return reinterpret_cast<bool(*)(int, int, float, float, float)>(0x90ca79)(a, b, c, d, e);
	}

	bool rmRiverAddWaypoint(int riverID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90cab7)(riverID, xFraction, zFraction);
	}

	bool rmRiverSetBankNoiseParams(int a, float b, int c, float d, float e, float f, float g) {
		return reinterpret_cast<bool(*)(int, float, int, float, float, float, float)>(0x90caeb)(a, b, c, d, e, f, g);
	}

	bool rmRiverSetShallowRadius(int a, int b) {
		return reinterpret_cast<bool(*)(int, int)>(0x90cb33)(a, b);
	}

	bool rmRiverAddShallow(int a, float b) {
		return reinterpret_cast<bool(*)(int, float)>(0x90cb62)(a, b);
	}

	bool rmRiverAddShallows(int a, int b, int c) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x90cb91)(a, b, c);
	}

	bool rmRiverAvoid(int a, int b, float c) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x90cbc5)(a, b, c);
	}

	bool rmRiverBuild(int a) {
		return reinterpret_cast<bool(*)(int)>(0x90cbf9)(a);
	}

	bool rmRiverReveal(int a, int b) {
		return reinterpret_cast<bool(*)(int, int)>(0x90cc23)(a, b);
	}

	bool rmSetRiverFoundationParams(int tileBuffer, float heightOffset) {
		return reinterpret_cast<bool(*)(int, float)>(0x90cc52)(tileBuffer, heightOffset);
	}

	bool rmSetWorldCircleConstraint(bool constrain) {
		return reinterpret_cast<bool(*)(bool)>(0x90cc73)(constrain);
	}

	bool rmSetAreaObeyWorldCircleConstraint(int areaID, bool constrain) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90cc9f)(areaID, constrain);
	}

	bool rmAddAreaTerrainLayer(int areaID, string terrain, float minDist, float maxDist) {
		return reinterpret_cast<bool(*)(int, string, float, float)>(0x90ccd0)(areaID, terrain, minDist, maxDist);
	}

	bool rmSetAreaTerrainLayerVariance(int areaID, bool variance) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90cd09)(areaID, variance);
	}

	bool rmSetAreaMinBlobs(int areaID, int blobs) {
		return reinterpret_cast<bool(*)(int, int)>(0x90cd96)(areaID, blobs);
	}

	bool rmSetAreaMaxBlobs(int areaID, int blobs) {
		return reinterpret_cast<bool(*)(int, int)>(0x90cdc5)(areaID, blobs);
	}

	bool rmSetAreaMinBlobDistance(int areaID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90cdf4)(areaID, dist);
	}

	bool rmSetAreaMaxBlobDistance(int areaID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90ce23)(areaID, dist);
	}

	bool rmSetAreaCoherence(int areaID, float coherence) {
		return reinterpret_cast<bool(*)(int, float)>(0x90ce52)(areaID, coherence);
	}

	bool rmSetAreaSmoothDistance(int areaID, int smoothDistance) {
		return reinterpret_cast<bool(*)(int, int)>(0x90ce81)(areaID, smoothDistance);
	}

	bool rmSetAreaHeightBlend(int areaID, int heightBlend) {
		return reinterpret_cast<bool(*)(int, int)>(0x90ceb0)(areaID, heightBlend);
	}

	int rmAreaID(string name) {
		return reinterpret_cast<int(*)(string)>(0x90c578)(name);
	}

	bool rmAddAreaInfluencePoint(int areaID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90cedf)(areaID, xFraction, zFraction);
	}

	bool rmAddAreaInfluenceSegment(int areaID, float xFraction1, float zFraction1, float xFraction2, float zFraction2) {
		return reinterpret_cast<bool(*)(int, float, float, float, float)>(0x90cf13)(areaID, xFraction1, zFraction1, xFraction2, zFraction2);
	}

	bool rmAddAreaRemoveType(int areaID, string typeName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90cf51)(areaID, typeName);
	}

	bool rmAddAreaTerrainReplacement(int areaID, string terrainTypeName, string newTypeName) {
		return reinterpret_cast<bool(*)(int, string, string)>(0x90cf80)(areaID, terrainTypeName, newTypeName);
	}

	bool rmSetAreaElevationType(int areaID, int type) {
		return reinterpret_cast<bool(*)(int, int)>(0x90e853)(areaID, type);
	}

	bool rmSetAreaElevationMinFrequency(int areaID, float freq) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e882)(areaID, freq);
	}

	bool rmSetAreaElevationOctaves(int areaID, int octaves) {
		return reinterpret_cast<bool(*)(int, int)>(0x90e8b1)(areaID, octaves);
	}

	bool rmSetAreaElevationPersistence(int areaID, float persistence) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e8e0)(areaID, persistence);
	}

	bool rmSetAreaElevationVariation(int areaID, float variation) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e90f)(areaID, variation);
	}

	bool rmSetAreaElevationEdgeFalloffDist(int areaID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e96d)(areaID, dist);
	}

	bool rmSetAreaElevationNoiseBias(int areaID, float bias) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e93e)(areaID, bias);
	}

	bool rmSetAreaReveal(int areaID, int tiles) {
		return reinterpret_cast<bool(*)(int, int)>(0x90e99c)(areaID, tiles);
	}

	void rmSetGlobalSnow(float percent) {
		reinterpret_cast<void(*)(float)>(0x90e9cb)(percent);
	}

	void rmSetGlobalRain(float percent) {
		reinterpret_cast<void(*)(float)>(0x90ea19)(percent);
	}

	void rmSetGlobalStormLength(int length, int timeBetweenStorms) {
		reinterpret_cast<void(*)(int, int)>(0x90ea67)(length, timeBetweenStorms);
	}

	void rmSetWindMagnitude(float magnitude) {
		reinterpret_cast<void(*)(float)>(0x90eac9)(magnitude);
	}

	void rmTerrainInitialize(string baseTerrain, float height) {
		reinterpret_cast<void(*)(string, float)>(0x90b731)(baseTerrain, height);
	}

	void rmFillMapCorners() {
		reinterpret_cast<void(*)()>(0x90b758)();
	}

	void rmDoLightingFade(string lightSetName, float fadeTime) {
		reinterpret_cast<void(*)(string, float)>(0x90b7b6)(lightSetName, fadeTime);
	}

	void rmDoLightingEffect(string lightSetName, float blendInTime, float effectTime, float blendOutTime) {
		reinterpret_cast<void(*)(string, float, float, float)>(0x90b7fa)(lightSetName, blendInTime, effectTime, blendOutTime);
	}

	void rmSetGaiaCiv(int civ) {
		reinterpret_cast<void(*)(int)>(0x90b848)(civ);
	}

	bool rmAllocateSubCivs(int number) {
		return reinterpret_cast<bool(*)(int)>(0x90b86f)(number);
	}

	bool rmSetSubCiv(int index, string civName, bool big) {
		return reinterpret_cast<bool(*)(int, string, bool)>(0x90b896)(index, civName, big);
	}

	int rmGetCivID(string civName) {
		return reinterpret_cast<int(*)(string)>(0x90b953)(civName);
	}

	int rmAddMerc(string unitName, float count, float minCount, float maxCount, float countIncrement, bool multipleUses) {
		return reinterpret_cast<int(*)(string, float, float, float, float, bool)>(0x90b969)(unitName, count, minCount, maxCount, countIncrement, multipleUses);
	}

	bool rmSetPlayerLocation(int playerID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90bb8e)(playerID, xFraction, zFraction);
	}

	void rmSetPlayerPlacementArea(float minX, float minZ, float maxX, float maxZ) {
		reinterpret_cast<void(*)(float, float, float, float)>(0x90b9c4)(minX, minZ, maxX, maxZ);
	}

	void rmSetTeamSpacingModifier(float modifier) {
		reinterpret_cast<void(*)(float)>(0x90b9fb)(modifier);
	}

	void rmSetPlacementTeam(int teamID) {
		reinterpret_cast<void(*)(int)>(0x90ba22)(teamID);
	}

	void rmSetPlacementSection(float fromPercent, float toPercent) {
		reinterpret_cast<void(*)(float, float)>(0x90ba49)(fromPercent, toPercent);
	}

	bool rmPlacePlayersCircular(float minFraction, float maxFraction, float angleVariation) {
		return reinterpret_cast<bool(*)(float, float, float)>(0x90ba76)(minFraction, maxFraction, angleVariation);
	}

	bool rmPlacePlayersSquare(float dist, float distVariation, float spacingVariationfloat) {
		return reinterpret_cast<bool(*)(float, float, float)>(0x90baaa)(dist, distVariation, spacingVariationfloat);
	}

	bool rmPlacePlayersLine(float x1, float z1, float x2, float z2, float distVariation, float spacingVariation) {
		return reinterpret_cast<bool(*)(float, float, float, float, float, float)>(0x90bade)(x1, z1, x2, z2, distVariation, spacingVariation);
	}

	bool rmPlacePlayersRiver(int riverID, float distVariation, float spacingVariation, float edgeDistance) {
		return reinterpret_cast<bool(*)(int, float, float, float)>(0x90bb21)(riverID, distVariation, spacingVariation, edgeDistance);
	}

	bool rmPlacePlayer(int playerID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90bb5a)(playerID, xFraction, zFraction);
	}

	bool rmSetPlayerArea(int playerID, int areaID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90c68b)(playerID, areaID);
	}

	float rmPlayerLocXFraction(int playerID) {
		return reinterpret_cast<float(*)(int)>(0x90bd66)(playerID);
	}

	float rmPlayerLocZFraction(int playerID) {
		return reinterpret_cast<float(*)(int)>(0x90bd94)(playerID);
	}

	int rmAddFairLoc(string unitName, bool forward, bool inside, float minPlayerDist, float maxPlayerDist, float locDist, float edgeDist, bool playerArea, bool teamArea) {
		return reinterpret_cast<int(*)(string, bool, bool, float, float, float, float, bool, bool)>(0x90bdc2)(unitName, forward, inside, minPlayerDist, maxPlayerDist, locDist, edgeDist, playerArea, teamArea);
	}

	bool rmPlaceFairLocs(int a) {
		return reinterpret_cast<bool(*)(int)>(0x90be15)(a);
	}

	void rmResetFairLocs() {
		reinterpret_cast<void(*)()>(0x90be38)();
	}

	int rmGetNumberFairLocs(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x90be59)(playerID);
	}

	float rmFairLocXFraction(int playerID, int index) {
		return reinterpret_cast<float(*)(int, int)>(0x90be83)(playerID, index);
	}

	float rmFairLocZFraction(int playerID, int index) {
		return reinterpret_cast<float(*)(int, int)>(0x90beb6)(playerID, index);
	}

	bool rmSetPlayerResource(int playerID, string resourceName, float amount) {
		return reinterpret_cast<bool(*)(int, string, float)>(0x90bbc2)(playerID, resourceName, amount);
	}

	bool rmAddPlayerResource(int playerID, string resourceName, float amount) {
		return reinterpret_cast<bool(*)(int, string, float)>(0x90bbf6)(playerID, resourceName, amount);
	}

	bool rmMultiplyPlayerResource(int playerID, string resourceName, float factor) {
		return reinterpret_cast<bool(*)(int, string, float)>(0x90bc2a)(playerID, resourceName, factor);
	}

	string rmGetPlayerName(int playerID) {
		return reinterpret_cast<string(*)(int)>(0x90bc5e)(playerID);
	}

	int rmGetPlayerTeam(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x90bc8f)(playerID);
	}

	int rmGetPlayerCiv(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x90bcb9)(playerID);
	}

	int rmGetPlayerCulture(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x90bce3)(playerID);
	}

	int rmGetNumberPlayersOnTeam(int teamID) {
		return reinterpret_cast<int(*)(int)>(0x90bd0d)(teamID);
	}

	bool rmSetTeamArea(int teamID, int areaID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90bd37)(teamID, areaID);
	}

	int rmCreateBoxConstraint(string name, float startX, float startZ, float endX, float endZ, float bufferFraction) {
		return reinterpret_cast<int(*)(string, float, float, float, float, float)>(0x90cfb4)(name, startX, startZ, endX, endZ, bufferFraction);
	}

	int rmCreatePieConstraint(string name, float xFraction, float zFraction, float insideRadius, float outsideRadius, float minAngle, float maxAngle, float bufferFraction) {
		return reinterpret_cast<int(*)(string, float, float, float, float, float, float, float)>(0x90cff8)(name, xFraction, zFraction, insideRadius, outsideRadius, minAngle, maxAngle, bufferFraction);
	}

	int rmCreateAreaOverlapConstraint(string name, int areaID) {
		return reinterpret_cast<int(*)(string, int)>(0x90d046)(name, areaID);
	}

	int rmCreateAreaConstraint(string name, int areaID) {
		return reinterpret_cast<int(*)(string, int)>(0x90d076)(name, areaID);
	}

	int rmCreateAreaDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d0a6)(name, areaID, distance);
	}

	int rmCreateAreaMaxDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d1b4)(name, areaID, distance);
	}

	int rmCreateEdgeConstraint(string name, int areaID) {
		return reinterpret_cast<int(*)(string, int)>(0x90d1e9)(name, areaID);
	}

	int rmCreateEdgeDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d219)(name, areaID, distance);
	}

	int rmCreateEdgeMaxDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d24e)(name, areaID, distance);
	}

	int rmCreateCliffEdgeConstraint(string name, int areaID) {
		return reinterpret_cast<int(*)(string, int)>(0x90d283)(name, areaID);
	}

	int rmCreateCliffEdgeDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d2b3)(name, areaID, distance);
	}

	int rmCreateCliffEdgeMaxDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d2e8)(name, areaID, distance);
	}

	int rmCreateCliffRampConstraint(string name, int areaID) {
		return reinterpret_cast<int(*)(string, int)>(0x90d31d)(name, areaID);
	}

	int rmCreateCliffRampDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d34d)(name, areaID, distance);
	}

	int rmCreateCliffRampMaxDistanceConstraint(string name, int areaID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d382)(name, areaID, distance);
	}

	int rmCreateClassDistanceConstraint(string name, int classID, float distance) {
		return reinterpret_cast<int(*)(string, int, float)>(0x90d3b7)(name, classID, distance);
	}

	int rmCreateTypeDistanceConstraint(string name, string classID, float distance) {
		return reinterpret_cast<int(*)(string, string, float)>(0x90d3ec)(name, classID, distance);
	}

	int rmCreateTerrainDistanceConstraint(string name, string type, bool passable, float distance) {
		return reinterpret_cast<int(*)(string, string, bool, float)>(0x90d421)(name, type, passable, distance);
	}

	int rmCreateTerrainMaxDistanceConstraint(string name, string type, bool passable, float distance) {
		return reinterpret_cast<int(*)(string, string, bool, float)>(0x90d45b)(name, type, passable, distance);
	}

	int rmCreateCornerConstraint(string name, int corner, bool outside) {
		return reinterpret_cast<int(*)(string, int, bool)>(0x90d495)(name, corner, outside);
	}

	int rmCreateTradeRouteDistanceConstraint(string name, float minDistance) {
		return reinterpret_cast<int(*)(string, float)>(0x90d4ca)(name, minDistance);
	}

	bool rmAddAreaConstraint(int areaID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90d52a)(areaID, constraintID);
	}

	bool rmCreateHCGPConstraint(string name, float minDistance) {
		return reinterpret_cast<bool(*)(string, float)>(0x90d0db)(name, minDistance);
	}

	bool rmCreateHCGPSelfConstraint(string name, int playerID, float minDistance) {
		return reinterpret_cast<bool(*)(string, int, float)>(0x90d10f)(name, playerID, minDistance);
	}

	bool rmCreateHCGPAllyConstraint(string name, int playerID, float minDistance) {
		return reinterpret_cast<bool(*)(string, int, float)>(0x90d17d)(name, playerID, minDistance);
	}

	bool rmCreateHCGPEnemyConstraint(string name, int playerID, float minDistance) {
		return reinterpret_cast<bool(*)(string, int, float)>(0x90d146)(name, playerID, minDistance);
	}

	int rmCreateMaxHeightConstraint(string name, float height) {
		return reinterpret_cast<int(*)(string, float)>(0x90d4fa)(name, height);
	}

	bool rmAddFairLocConstraint(int fairLocID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90d559)(fairLocID, constraintID);
	}

	bool rmAddObjectDefConstraint(int defID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90d588)(defID, constraintID);
	}

	int rmDefineClass(string className) {
		return reinterpret_cast<int(*)(string)>(0x90d5b7)(className);
	}

	bool rmAddAreaToClass(int areaID, int classID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90d5e2)(areaID, classID);
	}

	bool rmAddObjectDefToClass(int objectDefID, int classID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90d611)(objectDefID, classID);
	}

	int rmClassID(string name) {
		return reinterpret_cast<int(*)(string)>(0x90c5a3)(name);
	}

	int rmConstraintID(string name) {
		return reinterpret_cast<int(*)(string)>(0x90c5ce)(name);
	}

	int rmCreateObjectDef(string name) {
		return reinterpret_cast<int(*)(string)>(0x90d64b)(name);
	}

	int rmCreateStartingUnitsObjectDef(float clusterDistance) {
		return reinterpret_cast<int(*)(float)>(0x90d676)(clusterDistance);
	}

	bool rmSetObjectDefMinDistance(int defID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90d6b8)(defID, dist);
	}

	bool rmSetObjectDefMaxDistance(int defID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90d6e7)(defID, dist);
	}

	bool rmSetObjectDefGarrisonSecondaryUnits(int defID, bool on) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90d716)(defID, on);
	}

	bool rmSetObjectDefGarrisonStartingUnits(int defID, bool on) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90d745)(defID, on);
	}

	bool rmSetObjectDefCreateHerd(int defID, bool on) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90d774)(defID, on);
	}

	bool rmSetObjectDefHerdAngle(int defID, float angle) {
		return reinterpret_cast<bool(*)(int, float)>(0x90d7a3)(defID, angle);
	}

	bool rmSetObjectDefAllowOverlap(int defID, bool on) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90d7d2)(defID, on);
	}

	bool rmSetObjectDefForceFullRotation(int defID, bool on) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90d801)(defID, on);
	}

	bool rmAddObjectDefItem(int defID, string unitName, int count, float clusterDistance) {
		return reinterpret_cast<bool(*)(int, string, int, float)>(0x90d830)(defID, unitName, count, clusterDistance);
	}

	bool rmAddObjectDefItemByTypeID(int defID, int unitTypeID, int count, float clusterDistance) {
		return reinterpret_cast<bool(*)(int, int, int, float)>(0x90d869)(defID, unitTypeID, count, clusterDistance);
	}

	int rmPlaceObjectDefAtLoc(int defID, int playerID, float xFraction, float zFraction, int placeCount) {
		return reinterpret_cast<int(*)(int, int, float, float, int)>(0x90d8a2)(defID, playerID, xFraction, zFraction, placeCount);
	}

	int rmPlaceObjectDefAtPoint(int defID, int playerID, vector point, int placeCount) {
		return reinterpret_cast<int(*)(int, int, vector, int)>(0x90d8e0)(defID, playerID, point, placeCount);
	}

	int rmSetObjectDefTradeRouteID(int defID, int tradeRouteID) {
		return reinterpret_cast<int(*)(int, int)>(0x90d9e0)(defID, tradeRouteID);
	}

	int rmPlaceObjectDefPerPlayer(int defID, bool playerOwned, int placeCount) {
		return reinterpret_cast<int(*)(int, bool, int)>(0x90da0f)(defID, playerOwned, placeCount);
	}

	int rmPlaceObjectDefAtAreaLoc(int defID, int playerID, int areaID, int placeCount) {
		return reinterpret_cast<int(*)(int, int, int, int)>(0x90dab5)(defID, playerID, areaID, placeCount);
	}

	int rmPlaceObjectDefInArea(int defID, int playerID, int areaID, int placeCount) {
		return reinterpret_cast<int(*)(int, int, int, int)>(0x90daee)(defID, playerID, areaID, placeCount);
	}

	int rmPlaceObjectDefAtRandomAreaOfClass(int defID, int playerID, int classID, int placeCount) {
		return reinterpret_cast<int(*)(int, int, int, int)>(0x90da43)(defID, playerID, classID, placeCount);
	}

	int rmPlaceObjectDefInRandomAreaOfClass(int defID, int playerID, int classID, int placeCount) {
		return reinterpret_cast<int(*)(int, int, int, int)>(0x90da7c)(defID, playerID, classID, placeCount);
	}

	int rmCreateConnection(string name) {
		return reinterpret_cast<int(*)(string)>(0x90db27)(name);
	}

	int rmSetConnectionType(int connectionID, int connectionType, bool connectAll, float connectPercentage) {
		return reinterpret_cast<int(*)(int, int, bool, float)>(0x90db52)(connectionID, connectionType, connectAll, connectPercentage);
	}

	bool rmAddConnectionArea(int connectionID, int areaID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90db8b)(connectionID, areaID);
	}

	bool rmSetConnectionPositionVariance(int connectionID, float variance) {
		return reinterpret_cast<bool(*)(int, float)>(0x90dbba)(connectionID, variance);
	}

	bool rmSetConnectionWidth(int connectionID, float width, float variance) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90dbe9)(connectionID, width, variance);
	}

	bool rmSetConnectionBaseHeight(int connectionID, float width) {
		return reinterpret_cast<bool(*)(int, float)>(0x90dc1d)(connectionID, width);
	}

	bool rmSetConnectionCoherence(int connectionID, float width) {
		return reinterpret_cast<bool(*)(int, float)>(0x90dc4c)(connectionID, width);
	}

	bool rmSetConnectionWarnFailure(int connectionID, bool warn) {
		return reinterpret_cast<bool(*)(int, bool)>(0x90dc7b)(connectionID, warn);
	}

	bool rmSetConnectionHeightBlend(int connectionID, int width) {
		return reinterpret_cast<bool(*)(int, int)>(0x90dcaa)(connectionID, width);
	}

	bool rmSetConnectionSmoothDistance(int connectionID, int width) {
		return reinterpret_cast<bool(*)(int, int)>(0x90dcd9)(connectionID, width);
	}

	bool rmAddConnectionTerrainReplacement(int connectionID, string terrainTypeName, string newTypeName) {
		return reinterpret_cast<bool(*)(int, string, string)>(0x90dd08)(connectionID, terrainTypeName, newTypeName);
	}

	bool rmSetConnectionTerrainCost(int connectionID, string terrainTypeName, float cost) {
		return reinterpret_cast<bool(*)(int, string, float)>(0x90dd3c)(connectionID, terrainTypeName, cost);
	}

	bool rmSetConnectionBaseTerrainCost(int connectionID, float cost) {
		return reinterpret_cast<bool(*)(int, float)>(0x90dd70)(connectionID, cost);
	}

	bool rmBuildConnection(int connectionID) {
		return reinterpret_cast<bool(*)(int)>(0x90de5b)(connectionID);
	}

	bool rmAddConnectionToClass(int connectionID, int classID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90dd9f)(connectionID, classID);
	}

	bool rmAddConnectionConstraint(int connectionID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90ddce)(connectionID, constraintID);
	}

	bool rmAddConnectionStartConstraint(int connectionID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90ddfd)(connectionID, constraintID);
	}

	bool rmAddConnectionEndConstraint(int connectionID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90de2c)(connectionID, constraintID);
	}

	void rmSetStatusText(string status, float progress) {
		reinterpret_cast<void(*)(string, float)>(0x90de85)(status, progress);
	}

	float sqrt(float x) {
		return reinterpret_cast<float(*)(float)>(0x90dee8)(x);
	}

	void rmSetVPFile(string a) {
		reinterpret_cast<void(*)(string)>(0x90deef)(a);
	}

	int rmCreateTrigger(string a) {
		return reinterpret_cast<int(*)(string)>(0x90df16)(a);
	}

	bool rmSwitchToTrigger(int a) {
		return reinterpret_cast<bool(*)(int)>(0x90df73)(a);
	}

	int rmTriggerID(string a) {
		return reinterpret_cast<int(*)(string)>(0x90dfb0)(a);
	}

	int rmSetTriggerPriority(int a) {
		return reinterpret_cast<int(*)(int)>(0x90e008)(a);
	}

	int rmSetTriggerActive(bool a) {
		return reinterpret_cast<int(*)(bool)>(0x90e029)(a);
	}

	int rmSetTriggerRunImmediately(bool a) {
		return reinterpret_cast<int(*)(bool)>(0x90e049)(a);
	}

	int rmSetTriggerLoop(bool a) {
		return reinterpret_cast<int(*)(bool)>(0x90e06a)(a);
	}

	int rmAddTriggerCondition(string a) {
		return reinterpret_cast<int(*)(string)>(0x90e08b)(a);
	}

	bool rmSetTriggerConditionParam(string a, string b, bool c) {
		return reinterpret_cast<bool(*)(string, string, bool)>(0x90eede)(a, b, c);
	}

	bool rmSetTriggerConditionParamInt(string a, int b, bool c) {
		return reinterpret_cast<bool(*)(string, int, bool)>(0x90ef8f)(a, b, c);
	}

	bool rmSetTriggerConditionParamFloat(string a, float b, bool c) {
		return reinterpret_cast<bool(*)(string, float, bool)>(0x90efb8)(a, b, c);
	}

	bool rmSetTriggerConditionParamArmy(string a, int b, int c, bool d) {
		return reinterpret_cast<bool(*)(string, int, int, bool)>(0x90efe6)(a, b, c, d);
	}

	bool rmAddTriggerEffect(string a) {
		return reinterpret_cast<bool(*)(string)>(0x90e127)(a);
	}

	int rmSetTriggerEffectParam(string a, string b, bool c) {
		return reinterpret_cast<int(*)(string, string, bool)>(0x90f01c)(a, b, c);
	}

	bool rmSetTriggerEffectParamInt(string a, int b, bool c) {
		return reinterpret_cast<bool(*)(string, int, bool)>(0x90f0cd)(a, b, c);
	}

	bool rmSetTriggerEffectParamFloat(string a, float b, bool c) {
		return reinterpret_cast<bool(*)(string, float, bool)>(0x90f0f6)(a, b, c);
	}

	bool rmSetTriggerEffectParamArmy(string a, int b, int c, bool d) {
		return reinterpret_cast<bool(*)(string, int, int, bool)>(0x90f124)(a, b, c, d);
	}

	int rmCreateArmy(int a, string b) {
		return reinterpret_cast<int(*)(int, string)>(0x90e1c3)(a, b);
	}

	bool rmAddUnitsToArmy(int a, int b, int c) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x90e1ff)(a, b, c);
	}

	int rmGetNumberUnitsPlaced(int a) {
		return reinterpret_cast<int(*)(int)>(0x90e233)(a);
	}

	int rmGetUnitPlaced(int a, int b) {
		return reinterpret_cast<int(*)(int, int)>(0x90e25d)(a, b);
	}

	int rmGetUnitPlacedOfPlayer(int a, int b) {
		return reinterpret_cast<int(*)(int, int)>(0x90e28c)(a, b);
	}

	bool rmDefineConstant(string a, int b) {
		return reinterpret_cast<bool(*)(string, int)>(0x90e2bb)(a, b);
	}

	void rmSetIgnoreForceToGaia(bool a) {
		reinterpret_cast<void(*)(bool)>(0x90e35f)(a);
	}

	int rmCreateGrouping(string name, string filename) {
		return reinterpret_cast<int(*)(string, string)>(0x90e386)(name, filename);
	}

	bool rmAddGroupingConstraint(int GroupingID, int constraintID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90e3ea)(GroupingID, constraintID);
	}

	int rmPlaceGroupingAtLoc(int groupingID, int playerID, float xFraction, float zFraction, int placeCount) {
		return reinterpret_cast<int(*)(int, int, float, float, int)>(0x90e419)(groupingID, playerID, xFraction, zFraction, placeCount);
	}

	int rmPlaceGroupingAtPoint(int groupingID, int playerID, vector point, int placeCount) {
		return reinterpret_cast<int(*)(int, int, vector, int)>(0x90e457)(groupingID, playerID, point, placeCount);
	}

	int rmPlaceGroupingInArea(int groupingID, int playerID, int areaID, int placeCount) {
		return reinterpret_cast<int(*)(int, int, int, int)>(0x90e4d3)(groupingID, playerID, areaID, placeCount);
	}

	bool rmSetGroupingMinDistance(int defID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e50c)(defID, dist);
	}

	bool rmSetGroupingMaxDistance(int defID, float dist) {
		return reinterpret_cast<bool(*)(int, float)>(0x90e53b)(defID, dist);
	}

	bool rmAddGroupingToClass(int GroupingID, int classID) {
		return reinterpret_cast<bool(*)(int, int)>(0x90e56a)(GroupingID, classID);
	}

	int rmCreateTradeRoute() {
		return reinterpret_cast<int(*)()>(0x90e599)();
	}

	bool rmAddTradeRouteWaypoint(int tradeRouteID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90e5bd)(tradeRouteID, xFraction, zFraction);
	}

	bool rmAddTradeRouteWaypointVector(int tradeRouteID, vector v) {
		return reinterpret_cast<bool(*)(int, vector)>(0x90e5f1)(tradeRouteID, v);
	}

	bool rmAddRandomTradeRouteWaypoints(int tradeRouteID, float endXFraction, float endZFraction, int count, float maxVariation) {
		return reinterpret_cast<bool(*)(int, float, float, int, float)>(0x90e6a1)(tradeRouteID, endXFraction, endZFraction, count, maxVariation);
	}

	bool rmAddRandomTradeRouteWaypointsVector(int tradeRouteID, vector v, int count, float maxVariation) {
		return reinterpret_cast<bool(*)(int, vector, int, float)>(0x90e6df)(tradeRouteID, v, count, maxVariation);
	}

	bool rmCreateTradeRouteWaypointsInArea(int tradeRouteID, int areaID, float length) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x90e79a)(tradeRouteID, areaID, length);
	}

	vector rmGetTradeRouteWayPoint(vector result, int tradeRouteID, float fraction) {
		return reinterpret_cast<vector(*)(vector, int, float)>(0x90e7ce)(result, tradeRouteID, fraction);
	}

	bool rmBuildTradeRoute(int tradeRouteID, string terrainTypeName) {
		return reinterpret_cast<bool(*)(int, string)>(0x90e824)(tradeRouteID, terrainTypeName);
	}

	bool rmSetHomeCityGatherPoint(int playerID, vector point) {
		return reinterpret_cast<bool(*)(int, vector)>(0x90edbf)(playerID, point);
	}

	bool rmSetHomeCityWaterSpawnPoint(int playerID, vector point) {
		return reinterpret_cast<bool(*)(int, vector)>(0x90edfb)(playerID, point);
	}

	int rmGetLowHomeCityLevel() {
		return reinterpret_cast<int(*)()>(0x90eaed)();
	}

	int rmGetAverageHomeCityLevel() {
		return reinterpret_cast<int(*)()>(0x90eb03)();
	}

	int rmGetHighHomeCityLevel() {
		return reinterpret_cast<int(*)()>(0x90eb19)();
	}

	int rmGetHomeCityLevel(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x90eb2f)(playerID);
	}

	vector rmGetUnitPosition(vector result, int unitID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x90f15a)(result, unitID);
	}

	void rmSetMapType(string type) {
		reinterpret_cast<void(*)(string)>(0x90f1ec)(type);
	}

	bool rmIsMapType(string type) {
		return reinterpret_cast<bool(*)(string)>(0x90f267)(type);
	}

	bool rmAddClosestPointConstraint(int constraintID) {
		return reinterpret_cast<bool(*)(int)>(0x90eb4c)(constraintID);
	}

	void rmClearClosestPointConstraints() {
		reinterpret_cast<void(*)()>(0x90eb76)();
	}

	vector rmFindClosestPoint(vector result, float xFraction, float zFraction, float maxDistance) {
		return reinterpret_cast<vector(*)(vector, float, float, float)>(0x90eb97)(result, xFraction, zFraction, maxDistance);
	}

	vector rmFindClosestPointVector(vector result, vector a, float b) {
		return reinterpret_cast<vector(*)(vector, vector, float)>(0x90ec6d)(result, a, b);
	}

	int rmFindCloserArea(float xFraction, float zFraction, int area1, int area2) {
		return reinterpret_cast<int(*)(float, float, int, int)>(0x90ecc3)(xFraction, zFraction, area1, area2);
	}

	bool rmAddAreaCliffWaypoint(int areaID, float xFraction, float zFraction) {
		return reinterpret_cast<bool(*)(int, float, float)>(0x90c985)(areaID, xFraction, zFraction);
	}

	bool rmAddAreaCliffRandomWaypoints(int areaID, float endXFraction, float endZFraction, int count, float maxVariation) {
		return reinterpret_cast<bool(*)(int, float, float, int, float)>(0x90c9b9)(areaID, endXFraction, endZFraction, count, maxVariation);
	}

	void rmSetNuggetDifficulty(int minLevel, int maxLevel) {
		reinterpret_cast<void(*)(int, int)>(0x90ee37)(minLevel, maxLevel);
	}

	void rmSetOceanReveal(bool a) {
		reinterpret_cast<void(*)(bool)>(0x90ee81)(a);
	}

	bool hcSetXSHandler(string handlerFunctionName, int type) {
		return reinterpret_cast<bool(*)(string, int)>(0x63758e)(handlerFunctionName, type);
	}

	bool hcSetUnitXSHandler(int unitID, string handlerFunctionName, int type) {
		return reinterpret_cast<bool(*)(int, string, int)>(0x6366dc)(unitID, handlerFunctionName, type);
	}

	int hcRandInt(int max) {
		return reinterpret_cast<int(*)(int)>(0x42e4f6)(max);
	}

	vector hcRandPosition(vector result) {
		return reinterpret_cast<vector(*)(vector)>(0x8697a7)(result);
	}

	int hcGetMyUnitID() {
		return reinterpret_cast<int(*)()>(0x42d930)();
	}

	int hcUnitGetGroupID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x430ae5)(unitID);
	}

	vector hcUnitGetPosition(vector result, int unitID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x42fd86)(result, unitID);
	}

	int hcUnitGetActionType(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x42d9f5)(unitID);
	}

	bool hcUnitGoIdle(int unitID, bool queue) {
		return reinterpret_cast<bool(*)(int, bool)>(0x430585)(unitID, queue);
	}

	string hcUnitGetScript(int unitID) {
		return reinterpret_cast<string(*)(int)>(0x8697e2)(unitID);
	}

	int hcGetNumUnlockedUnits(bool regularUnits, bool performerUnits) {
		return reinterpret_cast<int(*)(bool, bool)>(0x86981d)(regularUnits, performerUnits);
	}

	int hcGetUnlockedUnitProtoUnitID(int unitIndex, bool regularUnits, bool performerUnits) {
		return reinterpret_cast<int(*)(int, bool, bool)>(0x869839)(unitIndex, regularUnits, performerUnits);
	}

	string hcGetUnlockedUnitVisualFilename(int unitIndex, bool regularUnits, bool performerUnits) {
		return reinterpret_cast<string(*)(int, bool, bool)>(0x86985a)(unitIndex, regularUnits, performerUnits);
	}

	string hcGetUnlockedUnitScriptFilename(int unitIndex, bool regularUnits, bool performerUnits) {
		return reinterpret_cast<string(*)(int, bool, bool)>(0x86987b)(unitIndex, regularUnits, performerUnits);
	}

	vector hcUnitGetPerformPosFromGroup(vector result, int groupID, int unitID) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x430e64)(result, groupID, unitID);
	}

	vector hcUnitGetPerformForwardFromGroup(vector result, int groupID, int unitID) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x869d1c)(result, groupID, unitID);
	}

	int hcUnitCreateUsingPos(int protoUnitID, string visualFilename, string aiFilename, vector position, vector forward, bool visible) {
		return reinterpret_cast<int(*)(int, string, string, vector, vector, bool)>(0x86989c)(protoUnitID, visualFilename, aiFilename, position, forward, visible);
	}

	int hcUnitCreate(int protoUnitID, string visualFilename, string aiFilename, int waypoint) {
		return reinterpret_cast<int(*)(int, string, string, int)>(0x869941)(protoUnitID, visualFilename, aiFilename, waypoint);
	}

	int hcUnitCreateAtBone(int protoUnitID, string visualFilename, string aiFilename, string boneName) {
		return reinterpret_cast<int(*)(int, string, string, string)>(0x86998c)(protoUnitID, visualFilename, aiFilename, boneName);
	}

	void hcPopulateHomeCity() {
		reinterpret_cast<void(*)()>(0x6373d7)();
	}

	float hcUnitGetInitialPauseTime(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x869a60)(unitID);
	}

	void hcUnitSetInitialPauseTime(int unitID, float pauseTime) {
		reinterpret_cast<void(*)(int, float)>(0x869a84)(unitID, pauseTime);
	}

	bool hcUnitSetFlag(int unitID, int unitFlag, bool enable, bool queue) {
		return reinterpret_cast<bool(*)(int, int, bool, bool)>(0x4304ee)(unitID, unitFlag, enable, queue);
	}

	int hcCreatePerformerGroup(int numPerformers, float attentionRadius) {
		return reinterpret_cast<int(*)(int, float)>(0x636a0e)(numPerformers, attentionRadius);
	}

	bool hcReservePerformerArea(int groupID) {
		return reinterpret_cast<bool(*)(int)>(0x430c18)(groupID);
	}

	int hcGetNumPerformerGroups() {
		return reinterpret_cast<int(*)()>(0x869da0)();
	}

	void hcAddUnitToPerformerGroup(int groupID, int unitID) {
		reinterpret_cast<void(*)(int, int)>(0x63666c)(groupID, unitID);
	}

	bool hcUnitExit(int unitID, bool queue) {
		return reinterpret_cast<bool(*)(int, bool)>(0x869aa5)(unitID, queue);
	}

	void hcUnitDestroyAll() {
		reinterpret_cast<void(*)()>(0x869ad3)();
	}

	bool hcUnitPlayAnim(int unitID, string animation, float seconds, int loop, bool queue) {
		return reinterpret_cast<bool(*)(int, string, float, int, bool)>(0x42f172)(unitID, animation, seconds, loop, queue);
	}

	bool hcUnitMoveToWPID(int unitID, int startWPID, int goalWPID, float speed, float goalTolerance, bool queue) {
		return reinterpret_cast<bool(*)(int, int, int, float, float, bool)>(0x42eb2a)(unitID, startWPID, goalWPID, speed, goalTolerance, queue);
	}

	bool hcUnitMoveToPos(int unitID, int startWPID, vector BVector, float goalPos, float speed, bool goalTolerance) {
		return reinterpret_cast<bool(*)(int, int, vector, float, float, bool)>(0x430b70)(unitID, startWPID, BVector, goalPos, speed, goalTolerance);
	}

	bool hcUnitTurn(int unitID, vector BVector, float forward, bool turnRateInDegreesPerSec) {
		return reinterpret_cast<bool(*)(int, vector, float, bool)>(0x431195)(unitID, BVector, forward, turnRateInDegreesPerSec);
	}

	bool hcUnitTeleportToWPID(int unitID, int WPID) {
		return reinterpret_cast<bool(*)(int, int)>(0x869ae4)(unitID, WPID);
	}

	bool hcUnitFollow(int unitID, int unitToFollowID, float speed, bool queue) {
		return reinterpret_cast<bool(*)(int, int, float, bool)>(0x869b82)(unitID, unitToFollowID, speed, queue);
	}

	bool hcUnitExitBuilding(int unitID, int buildingID, float pauseTime, float speed, bool queue) {
		return reinterpret_cast<bool(*)(int, int, float, float, bool)>(0x869bba)(unitID, buildingID, pauseTime, speed, queue);
	}

	bool hcUnitEnterBuilding(int unitID, int buildingID, float speed, bool queue) {
		return reinterpret_cast<bool(*)(int, int, float, bool)>(0x869bf7)(unitID, buildingID, speed, queue);
	}

	bool hcUnitSetVisible(int unitID, bool state, bool queue) {
		return reinterpret_cast<bool(*)(int, bool, bool)>(0x4303f8)(unitID, state, queue);
	}

	bool hcUnitWait(int unitID, float pauseTime, bool queue) {
		return reinterpret_cast<bool(*)(int, float, bool)>(0x869c2f)(unitID, pauseTime, queue);
	}

	void hcUnitFreeWPID(int unitID, int wpid, bool queue) {
		reinterpret_cast<void(*)(int, int, bool)>(0x43127e)(unitID, wpid, queue);
	}

	void hcOccupyWPID(int wpid) {
		reinterpret_cast<void(*)(int)>(0x431210)(wpid);
	}

	int hcGetNumberUnitsWithAI(string aiFilename) {
		return reinterpret_cast<int(*)(string)>(0x869c62)(aiFilename);
	}

	int hcGetUnitWithAI(string aiFilename, int index) {
		return reinterpret_cast<int(*)(string, int)>(0x869c9c)(aiFilename, index);
	}

	int hcGetPerformerInProximity(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x42ddfc)(unitID);
	}

	int hcGetNumberWaypoints() {
		return reinterpret_cast<int(*)()>(0x869db4)();
	}

	vector hcGetWaypointPos(vector result, int waypoint) {
		return reinterpret_cast<vector(*)(vector, int)>(0x869dc5)(result, waypoint);
	}

	vector hcGetWaypointDir(vector result, int waypoint) {
		return reinterpret_cast<vector(*)(vector, int)>(0x430f93)(result, waypoint);
	}

	int hcGetNearestWPID(vector position) {
		return reinterpret_cast<int(*)(vector)>(0x42fe01)(position);
	}

	int hcGetRandomWPID(int waypointMask) {
		return reinterpret_cast<int(*)(int)>(0x42edab)(waypointMask);
	}

	int hcGetRandomFreeWPID(int waypointMask) {
		return reinterpret_cast<int(*)(int)>(0x430f4c)(waypointMask);
	}

	int hcGetBuildingIDByName(string buildingName) {
		return reinterpret_cast<int(*)(string)>(0x869cde)(buildingName);
	}

	void aiEcho(string echoString) {
		reinterpret_cast<void(*)(string)>(0x7286df)(echoString);
	}

	void aiErrorMessage(string errorString) {
		reinterpret_cast<void(*)(string)>(0x728826)(errorString);
	}

	void aiRandSetSeed(int seed) {
		reinterpret_cast<void(*)(int)>(0x722cee)(seed);
	}

	int aiRandInt(int max) {
		return reinterpret_cast<int(*)(int)>(0x722d0a)(max);
	}

	vector aiRandLocation(vector result) {
		return reinterpret_cast<vector(*)(vector)>(0x722d2b)(result);
	}

	void aiSet(string filename, int playerID) {
		reinterpret_cast<void(*)(string, int)>(0x722dfe)(filename, playerID);
	}

	void aiBreakpointSet(int a, string b, int c, bool d) {
		reinterpret_cast<void(*)(int, string, int, bool)>(0x722e61)(a, b, c, d);
	}

	void aiBreakpointGo(int a) {
		reinterpret_cast<void(*)(int)>(0x722ed4)(a);
	}

	string aiGetPersonality() {
		return reinterpret_cast<string(*)()>(0x722f20)();
	}

	float aiPersonalityGetRushBoom() {
		return reinterpret_cast<float(*)()>(0x722f53)();
	}

	int aiPersonalityGetNumberPlayerHistories() {
		return reinterpret_cast<int(*)()>(0x72680a)();
	}

	int aiPersonalityCreatePlayerHistory(string a) {
		return reinterpret_cast<int(*)(string)>(0x72938e)(a);
	}

	bool aiPersonalityResetPlayerHistory(int playerHistoryIndex) {
		return reinterpret_cast<bool(*)(int)>(0x7291f0)(playerHistoryIndex);
	}

	string aiPersonalityGetPlayerHistoryName(int index) {
		return reinterpret_cast<string(*)(int)>(0x726859)(index);
	}

	int aiPersonalityGetPlayerHistoryIndex(string searchPlayerName) {
		return reinterpret_cast<int(*)(string)>(0x7268c4)(searchPlayerName);
	}

	float aiPersonalityGetPlayerUserVar(int playerHistoryIndex, string userVarName) {
		return reinterpret_cast<float(*)(int, string)>(0x728ad8)(playerHistoryIndex, userVarName);
	}

	bool aiPersonalitySetPlayerUserVar(int playerHistoryIndex, string userVarName, float val) {
		return reinterpret_cast<bool(*)(int, string, float)>(0x7292cc)(playerHistoryIndex, userVarName, val);
	}

	int aiPersonalityGetPlayerGamesPlayed(int playerHistoryIndex, int playerRelation) {
		return reinterpret_cast<int(*)(int, int)>(0x726982)(playerHistoryIndex, playerRelation);
	}

	float aiPersonalityGetGameResource(int playerHistoryIndex, int gameIndex, int resourceID) {
		return reinterpret_cast<float(*)(int, int, int)>(0x726a1f)(playerHistoryIndex, gameIndex, resourceID);
	}

	bool aiPersonalityGetDidIWinLastGameVS(int a) {
		return reinterpret_cast<bool(*)(int)>(0x726b31)(a);
	}

	int aiPersonalityGetGameUnitCount(int playerHistoryIndex, int gameIndex, int unitType) {
		return reinterpret_cast<int(*)(int, int, int)>(0x726bc8)(playerHistoryIndex, gameIndex, unitType);
	}

	int aiPersonalityGetGameFirstAttackTime(int playerHistoryIndex, int gameIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x726ce9)(playerHistoryIndex, gameIndex);
	}

	int aiPersonalityGetTotalGameWins(int playerHistoryIndex, int playerRelation) {
		return reinterpret_cast<int(*)(int, int)>(0x726d93)(playerHistoryIndex, playerRelation);
	}

	int aiGetMostHatedPlayerID() {
		return reinterpret_cast<int(*)()>(0x722fa6)();
	}

	int aiCalculateMostHatedPlayerID(int comparePlayerID) {
		return reinterpret_cast<int(*)(int)>(0x722fd7)(comparePlayerID);
	}

	void aiSetMostHatedPlayerID(int v) {
		reinterpret_cast<void(*)(int)>(0x723011)(v);
	}

	int aiGetAvailableEconomyPop() {
		return reinterpret_cast<int(*)()>(0x723042)();
	}

	int aiGetCurrentEconomyPop() {
		return reinterpret_cast<int(*)()>(0x723075)();
	}

	int aiGetEconomyPop() {
		return reinterpret_cast<int(*)()>(0x7230a8)();
	}

	void aiSetEconomyPop(int v) {
		reinterpret_cast<void(*)(int)>(0x7230d8)(v);
	}

	int aiGetAvailableMilitaryPop() {
		return reinterpret_cast<int(*)()>(0x723109)();
	}

	int aiGetMilitaryPop() {
		return reinterpret_cast<int(*)()>(0x72313c)();
	}

	void aiSetMilitaryPop(int v) {
		reinterpret_cast<void(*)(int)>(0x72316c)(v);
	}

	float aiGetEconomyPercentage() {
		return reinterpret_cast<float(*)()>(0x72319d)();
	}

	void aiSetEconomyPercentage(float v) {
		reinterpret_cast<void(*)(float)>(0x7231d1)(v);
	}

	float aiGetMilitaryPercentage() {
		return reinterpret_cast<float(*)()>(0x723202)();
	}

	void aiSetMilitaryPercentage(float v) {
		reinterpret_cast<void(*)(float)>(0x723236)(v);
	}

	float aiGetAttackResponseDistance() {
		return reinterpret_cast<float(*)()>(0x723267)();
	}

	void aiSetAttackResponseDistance(float v) {
		reinterpret_cast<void(*)(float)>(0x72329b)(v);
	}

	int aiGoalGetNumber(int goalType, int goalState, bool active) {
		return reinterpret_cast<int(*)(int, int, bool)>(0x7232cc)(goalType, goalState, active);
	}

	int aiGoalGetIDByIndex(int goalType, int goalState, bool active, int index) {
		return reinterpret_cast<int(*)(int, int, bool, int)>(0x723310)(goalType, goalState, active, index);
	}

	int aiPlanGetNumber(int planType, int planState, bool active) {
		return reinterpret_cast<int(*)(int, int, bool)>(0x723359)(planType, planState, active);
	}

	int aiPlanGetIDByIndex(int planType, int planState, bool active, int index) {
		return reinterpret_cast<int(*)(int, int, bool, int)>(0x72339d)(planType, planState, active, index);
	}

	int aiPlanCreate(string planName, int typeName) {
		return reinterpret_cast<int(*)(string, int)>(0x7233e6)(planName, typeName);
	}

	bool aiPlanDestroy(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x723431)(planID);
	}

	bool aiPlanDestroyByName(string name) {
		return reinterpret_cast<bool(*)(string)>(0x72346b)(name);
	}

	int aiPlanGetID(string name) {
		return reinterpret_cast<int(*)(string)>(0x7234a5)(name);
	}

	int aiPlanGetIDSubStr(string searchStr) {
		return reinterpret_cast<int(*)(string)>(0x7234e2)(searchStr);
	}

	int aiPlanGetIDByTypeAndVariableType(int planType, int varType, int varID, bool active) {
		return reinterpret_cast<int(*)(int, int, int, bool)>(0x72351f)(planType, varType, varID, active);
	}

	int aiPlanGetIDByActiveIndex(int activeIndex) {
		return reinterpret_cast<int(*)(int)>(0x723569)(activeIndex);
	}

	string aiPlanGetName(int planID) {
		return reinterpret_cast<string(*)(int)>(0x7235ad)(planID);
	}

	int aiPlanGetType(int planID) {
		return reinterpret_cast<int(*)(int)>(0x7235f1)(planID);
	}

	int aiPlanGetState(int planID) {
		return reinterpret_cast<int(*)(int)>(0x723633)(planID);
	}

	int aiPlanGetActualPriority(int planID) {
		return reinterpret_cast<int(*)(int)>(0x723679)(planID);
	}

	int aiPlanGetDesiredPriority(int planID) {
		return reinterpret_cast<int(*)(int)>(0x7236bb)(planID);
	}

	bool aiPlanSetDesiredPriority(int planID, int priority) {
		return reinterpret_cast<bool(*)(int, int)>(0x7236fd)(planID, priority);
	}

	bool aiPlanAddUnitType(int planID, int unitTypeID, int numberNeed, int numberWant, int numberMax) {
		return reinterpret_cast<bool(*)(int, int, int, int, int)>(0x723755)(planID, unitTypeID, numberNeed, numberWant, numberMax);
	}

	int aiPlanGetNumberUnits(int planID, int unitTypeID) {
		return reinterpret_cast<int(*)(int, int)>(0x7237b0)(planID, unitTypeID);
	}

	bool aiPlanAddUnit(int planID, int unitID) {
		return reinterpret_cast<bool(*)(int, int)>(0x7237fc)(planID, unitID);
	}

	vector aiPlanGetLocation(vector result, int planID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x72383a)(result, planID);
	}

	vector aiPlanGetInitialPosition(vector result, int planID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x7238a8)(result, planID);
	}

	void aiPlanSetInitialPosition(int planID, vector initialPosition) {
		reinterpret_cast<void(*)(int, vector)>(0x723921)(planID, initialPosition);
	}

	bool aiPlanSetWaypoints(int planID, int pathID) {
		return reinterpret_cast<bool(*)(int, int)>(0x726e39)(planID, pathID);
	}

	bool aiPlanAddWaypoint(int planID, vector waypoint) {
		return reinterpret_cast<bool(*)(int, vector)>(0x723973)(planID, waypoint);
	}

	int aiPlanGetNumberVariableValues(int planID, int planVariableIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x7239c1)(planID, planVariableIndex);
	}

	bool aiPlanSetNumberVariableValues(int planID, int planVariableIndex, int numberValues, bool clearCurrentValues) {
		return reinterpret_cast<bool(*)(int, int, int, bool)>(0x723a0c)(planID, planVariableIndex, numberValues, clearCurrentValues);
	}

	bool aiPlanRemoveVariableValue(int planID, int planVariableIndex, int variableIndex) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x723ac0)(planID, planVariableIndex, variableIndex);
	}

	bool aiPlanSetVariableInt(int planID, int planVariableIndex, int valueIndex, int value) {
		return reinterpret_cast<bool(*)(int, int, int, int)>(0x723b10)(planID, planVariableIndex, valueIndex, value);
	}

	int aiPlanGetVariableInt(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<int(*)(int, int, int)>(0x723b9f)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanSetVariableFloat(int planID, int planVariableIndex, int valueIndex, float value) {
		return reinterpret_cast<bool(*)(int, int, int, float)>(0x723c02)(planID, planVariableIndex, valueIndex, value);
	}

	float aiPlanGetVariableFloat(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<float(*)(int, int, int)>(0x723c91)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanSetVariableVector(int planID, int planVariableIndex, int valueIndex, vector value) {
		return reinterpret_cast<bool(*)(int, int, int, vector)>(0x723cf7)(planID, planVariableIndex, valueIndex, value);
	}

	vector aiPlanGetVariableVector(vector result, int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<vector(*)(vector, int, int, int)>(0x723d93)(result, planID, planVariableIndex, valueIndex);
	}

	bool aiPlanSetVariableBool(int planID, int planVariableIndex, int valueIndex, bool value) {
		return reinterpret_cast<bool(*)(int, int, int, bool)>(0x723e44)(planID, planVariableIndex, valueIndex, value);
	}

	bool aiPlanGetVariableBool(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x723ed3)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanSetVariableString(int planID, int planVariableIndex, int valueIndex, string value) {
		return reinterpret_cast<bool(*)(int, int, int, string)>(0x723f35)(planID, planVariableIndex, valueIndex, value);
	}

	string aiPlanGetVariableString(int planID, int planVariableIndex) {
		return reinterpret_cast<string(*)(int, int)>(0x726ec6)(planID, planVariableIndex);
	}

	int aiPlanGetNumberUserVariableValues(int planID, int planVariableIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x723fd1)(planID, planVariableIndex);
	}

	bool aiPlanSetNumberUserVariableValues(int planID, int planVariableIndex, int numberValues, bool clearCurrentValues) {
		return reinterpret_cast<bool(*)(int, int, int, bool)>(0x72401f)(planID, planVariableIndex, numberValues, clearCurrentValues);
	}

	bool aiPlanRemoveUserVariables(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x724077)(planID);
	}

	bool aiPlanRemoveUserVariable(int planID, int planVariableIndex) {
		return reinterpret_cast<bool(*)(int, int)>(0x7240c2)(planID, planVariableIndex);
	}

	bool aiPlanRemoveUserVariableValue(int planID, int planVariableIndex, int variableIndex) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x724110)(planID, planVariableIndex, variableIndex);
	}

	bool aiPlanAddUserVariableInt(int planID, int planVariableIndex, string name, int numberValues) {
		return reinterpret_cast<bool(*)(int, int, string, int)>(0x724163)(planID, planVariableIndex, name, numberValues);
	}

	bool aiPlanSetUserVariableInt(int planID, int planVariableIndex, int valueIndex, int value) {
		return reinterpret_cast<bool(*)(int, int, int, int)>(0x7241bb)(planID, planVariableIndex, valueIndex, value);
	}

	int aiPlanGetUserVariableInt(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<int(*)(int, int, int)>(0x724213)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanAddUserVariableFloat(int planID, int planVariableIndex, string name, int numberValues) {
		return reinterpret_cast<bool(*)(int, int, string, int)>(0x724279)(planID, planVariableIndex, name, numberValues);
	}

	bool aiPlanSetUserVariableFloat(int planID, int planVariableIndex, int valueIndex, float value) {
		return reinterpret_cast<bool(*)(int, int, int, float)>(0x7242d1)(planID, planVariableIndex, valueIndex, value);
	}

	float aiPlanGetUserVariableFloat(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<float(*)(int, int, int)>(0x724329)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanAddUserVariableVector(int planID, int planVariableIndex, string name, int numberValues) {
		return reinterpret_cast<bool(*)(int, int, string, int)>(0x724392)(planID, planVariableIndex, name, numberValues);
	}

	bool aiPlanSetUserVariableVector(int planID, int planVariableIndex, int valueIndex, vector value) {
		return reinterpret_cast<bool(*)(int, int, int, vector)>(0x7243ea)(planID, planVariableIndex, valueIndex, value);
	}

	vector aiPlanGetUserVariableVector(vector result, int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<vector(*)(vector, int, int, int)>(0x724446)(result, planID, planVariableIndex, valueIndex);
	}

	bool aiPlanAddUserVariableBool(int planID, int planVariableIndex, string name, int numberValues) {
		return reinterpret_cast<bool(*)(int, int, string, int)>(0x7244fa)(planID, planVariableIndex, name, numberValues);
	}

	bool aiPlanSetUserVariableBool(int planID, int planVariableIndex, int valueIndex, bool value) {
		return reinterpret_cast<bool(*)(int, int, int, bool)>(0x724552)(planID, planVariableIndex, valueIndex, value);
	}

	bool aiPlanGetUserVariableBool(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x7245aa)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanAddUserVariableString(int planID, int planVariableIndex, string name, int numberValues) {
		return reinterpret_cast<bool(*)(int, int, string, int)>(0x72460f)(planID, planVariableIndex, name, numberValues);
	}

	bool aiPlanSetUserVariableString(int planID, int planVariableIndex, int valueIndex, string value) {
		return reinterpret_cast<bool(*)(int, int, int, string)>(0x724667)(planID, planVariableIndex, valueIndex, value);
	}

	string aiPlanGetUserVariableString(int planID, int planVariableIndex, int valueIndex) {
		return reinterpret_cast<string(*)(int, int, int)>(0x726f41)(planID, planVariableIndex, valueIndex);
	}

	bool aiPlanGetActive(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x726fbf)(planID);
	}

	bool aiPlanSetActive(int planID, bool active) {
		return reinterpret_cast<bool(*)(int, bool)>(0x7246c3)(planID, active);
	}

	bool aiPlanGetNoMoreUnits(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x72706c)(planID);
	}

	bool aiPlanSetNoMoreUnits(int planID, bool v) {
		return reinterpret_cast<bool(*)(int, bool)>(0x72475f)(planID, v);
	}

	bool aiPlanGetOrphan(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x727015)(planID);
	}

	bool aiPlanSetOrphan(int planID, bool orphan) {
		return reinterpret_cast<bool(*)(int, bool)>(0x724711)(planID, orphan);
	}

	bool aiPlanGetAllowUnderAttackResponse(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x7270c3)(planID);
	}

	bool aiPlanSetAllowUnderAttackResponse(int planID, bool uAR) {
		return reinterpret_cast<bool(*)(int, bool)>(0x7247ad)(planID, uAR);
	}

	int aiPlanGetUnitStance(int planID) {
		return reinterpret_cast<int(*)(int)>(0x7247fb)(planID);
	}

	bool aiPlanSetUnitStance(int planID, int stance) {
		return reinterpret_cast<bool(*)(int, int)>(0x724841)(planID, stance);
	}

	bool aiPlanSetRequiresAllNeedUnits(int planID, bool rANU) {
		return reinterpret_cast<bool(*)(int, bool)>(0x72488b)(planID, rANU);
	}

	bool aiPlanSetEventHandler(int planID, int eventType, string handlerName) {
		return reinterpret_cast<bool(*)(int, int, string)>(0x7248d9)(planID, eventType, handlerName);
	}

	bool aiPlanSetEscrowID(int planID, int escrowID) {
		return reinterpret_cast<bool(*)(int, int)>(0x724973)(planID, escrowID);
	}

	int aiPlanGetEscrowID(int planID) {
		return reinterpret_cast<int(*)(int)>(0x7249bd)(planID);
	}

	bool aiPlanGetEconomy(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x72711c)(planID);
	}

	bool aiPlanSetEconomy(int planID, bool v) {
		return reinterpret_cast<bool(*)(int, bool)>(0x724a02)(planID, v);
	}

	bool aiPlanGetMilitary(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x727173)(planID);
	}

	bool aiPlanSetMilitary(int planID, bool v) {
		return reinterpret_cast<bool(*)(int, bool)>(0x724a66)(planID, v);
	}

	bool aiPlanGetAttack(int planID) {
		return reinterpret_cast<bool(*)(int)>(0x7271ca)(planID);
	}

	bool aiPlanSetAttack(int planID, bool v) {
		return reinterpret_cast<bool(*)(int, bool)>(0x724aca)(planID, v);
	}

	bool aiPlanSetBaseID(int planID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x724b18)(planID, baseID);
	}

	int aiPlanGetBaseID(int planID) {
		return reinterpret_cast<int(*)(int)>(0x724b66)(planID);
	}

	int aiGetNumberIdlePlans(int planType) {
		return reinterpret_cast<int(*)(int)>(0x724baa)(planType);
	}

	float aiPlanGetUnitCost(int planID, bool considerHitPoints) {
		return reinterpret_cast<float(*)(int, bool)>(0x728b69)(planID, considerHitPoints);
	}

	void aiCommsAllowChat(bool flag) {
		reinterpret_cast<void(*)(bool)>(0x724be3)(flag);
	}

	int aiCommsSendStatement(int targetPlayerID, int promptType) {
		return reinterpret_cast<int(*)(int, int)>(0x724c0d)(targetPlayerID, promptType);
	}

	int aiCommsSendStatementWithVector(int targetPlayerID, int promptType, vector v) {
		return reinterpret_cast<int(*)(int, int, vector)>(0x724c56)(targetPlayerID, promptType, v);
	}

	bool aiCommsSetEventHandler(string handlerFunctionName) {
		return reinterpret_cast<bool(*)(string)>(0x724ca2)(handlerFunctionName);
	}

	int aiCommsGetSendingPlayer(int sentenceID) {
		return reinterpret_cast<int(*)(int)>(0x727220)(sentenceID);
	}

	int aiCommsGetChatVerb(int sentenceID) {
		return reinterpret_cast<int(*)(int)>(0x727263)(sentenceID);
	}

	int aiCommsGetChatTargetType(int sentenceID) {
		return reinterpret_cast<int(*)(int)>(0x7272a6)(sentenceID);
	}

	int aiCommsGetTargetListCount(int sentenceID) {
		return reinterpret_cast<int(*)(int)>(0x7272e9)(sentenceID);
	}

	int aiCommsGetTargetListItem(int sentenceID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x72732d)(sentenceID, index);
	}

	vector aiCommsGetTargetLocation(vector result, int sentenceID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x727381)(result, sentenceID);
	}

	void aiCommsSendReply(int sentenceID, int responseID) {
		reinterpret_cast<void(*)(int, int)>(0x728cb8)(sentenceID, responseID);
	}

	bool aiSetHandler(string handlerFunctionName, int type) {
		return reinterpret_cast<bool(*)(string, int)>(0x724d3b)(handlerFunctionName, type);
	}

	bool aiTaskUnitMove(int unitID, vector position) {
		return reinterpret_cast<bool(*)(int, vector)>(0x724db5)(unitID, position);
	}

	bool aiTaskUnitWork(int unitID, int targetUnitID) {
		return reinterpret_cast<bool(*)(int, int)>(0x724e46)(unitID, targetUnitID);
	}

	bool aiTaskUnitBuild(int unitID, int buildingTypeID, vector position) {
		return reinterpret_cast<bool(*)(int, int, vector)>(0x724ed0)(unitID, buildingTypeID, position);
	}

	bool aiTaskUnitTrain(int unitID, int unitTypeID) {
		return reinterpret_cast<bool(*)(int, int)>(0x7273fc)(unitID, unitTypeID);
	}

	bool aiTaskUnitResearch(int unitID, int techID) {
		return reinterpret_cast<bool(*)(int, int)>(0x72748d)(unitID, techID);
	}

	bool aiTaskUnitDelete(int unitID) {
		return reinterpret_cast<bool(*)(int)>(0x724f9e)(unitID);
	}

	bool aiTribute(int playerID, int resourceID, float amount) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x724fca)(playerID, resourceID, amount);
	}

	bool aiSellResourceOnMarket(int resourceID) {
		return reinterpret_cast<bool(*)(int)>(0x72500d)(resourceID);
	}

	bool aiBuyResourceOnMarket(int resourceID) {
		return reinterpret_cast<bool(*)(int)>(0x72504b)(resourceID);
	}

	float aiGetMarketBuyCost(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x7290d2)(resourceID);
	}

	float aiGetMarketSellCost(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x72912c)(resourceID);
	}

	float aiGetResourceGathererPercentageWeight(int rgpIndex) {
		return reinterpret_cast<float(*)(int)>(0x725089)(rgpIndex);
	}

	void aiSetResourceGathererPercentageWeight(int rgpIndex, float weight) {
		reinterpret_cast<void(*)(int, float)>(0x7250c6)(rgpIndex, weight);
	}

	void aiNormalizeResourceGathererPercentageWeights() {
		reinterpret_cast<void(*)()>(0x725101)();
	}

	float aiGetResourceGathererPercentage(int resourceID, int rgpIndex) {
		return reinterpret_cast<float(*)(int, int)>(0x725132)(resourceID, rgpIndex);
	}

	void aiSetResourceGathererPercentage(int resourceID, float value, bool normalize, int rgpIndex) {
		reinterpret_cast<void(*)(int, float, bool, int)>(0x725174)(resourceID, value, normalize, rgpIndex);
	}

	void aiNormalizeResourceGathererPercentages(int rgpIndex) {
		reinterpret_cast<void(*)(int)>(0x7251b9)(rgpIndex);
	}

	int aiGetResourceBreakdownNumberPlans(int resourceTypeID, int resourceSubTypeID, int baseID) {
		return reinterpret_cast<int(*)(int, int, int)>(0x7251ef)(resourceTypeID, resourceSubTypeID, baseID);
	}

	int aiGetResourceBreakdownPlanPriority(int resourceTypeID, int resourceSubTypeID, int baseID) {
		return reinterpret_cast<int(*)(int, int, int)>(0x725235)(resourceTypeID, resourceSubTypeID, baseID);
	}

	float aiGetResourceBreakdownPercentage(int resourceTypeID, int resourceSubTypeID, int baseID) {
		return reinterpret_cast<float(*)(int, int, int)>(0x72527b)(resourceTypeID, resourceSubTypeID, baseID);
	}

	bool aiSetResourceBreakdown(int resourceTypeID, int resourceSubTypeID, int numberPlans, int planPriority, float percentage, int baseID) {
		return reinterpret_cast<bool(*)(int, int, int, int, float, int)>(0x7252c5)(resourceTypeID, resourceSubTypeID, numberPlans, planPriority, percentage, baseID);
	}

	bool aiRemoveResourceBreakdown(int resourceTypeID, int resourceSubTypeID, int baseID) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x725317)(resourceTypeID, resourceSubTypeID, baseID);
	}

	int aiGetAutoGatherEscrowID() {
		return reinterpret_cast<int(*)()>(0x72535a)();
	}

	void aiSetAutoGatherEscrowID(int escrowID) {
		reinterpret_cast<void(*)(int)>(0x72538e)(escrowID);
	}

	int aiGetAutoFarmEscrowID() {
		return reinterpret_cast<int(*)()>(0x7253c2)();
	}

	void aiSetAutoFarmEscrowID(int escrowID) {
		reinterpret_cast<void(*)(int)>(0x7253f6)(escrowID);
	}

	int aiGetFarmLimit() {
		return reinterpret_cast<int(*)()>(0x72542a)();
	}

	void aiSetFarmLimit(int limit) {
		reinterpret_cast<void(*)(int)>(0x72545e)(limit);
	}

	bool aiGetAllowBuildings() {
		return reinterpret_cast<bool(*)()>(0x725492)();
	}

	void aiSetAllowBuildings(bool v) {
		reinterpret_cast<void(*)(bool)>(0x7254c5)(v);
	}

	void aiChat(int playerID, string chatString) {
		reinterpret_cast<void(*)(int, string)>(0x728db6)(playerID, chatString);
	}

	int aiNumberUnassignedUnits(int typeID) {
		return reinterpret_cast<int(*)(int)>(0x7254f9)(typeID);
	}

	int aiNumberUnassignedUnitsByGoal(int goalID) {
		return reinterpret_cast<int(*)(int)>(0x725532)(goalID);
	}

	int aiCreateOpportunity(int type, int targettype, int targetID, int targetPlayerID, int source) {
		return reinterpret_cast<int(*)(int, int, int, int, int)>(0x72556b)(type, targettype, targetID, targetPlayerID, source);
	}

	void aiActivateOpportunity(int opportunityID, bool flag) {
		reinterpret_cast<void(*)(int, bool)>(0x7255da)(opportunityID, flag);
	}

	void aiDestroyOpportunity(int opportunityID) {
		reinterpret_cast<void(*)(int)>(0x725626)(opportunityID);
	}

	void aiFindBestOpportunity() {
		reinterpret_cast<void(*)()>(0x725660)();
	}

	int aiGetOpportunitySourceID(int opportunityID) {
		return reinterpret_cast<int(*)(int)>(0x725695)(opportunityID);
	}

	int aiGetOpportunitySourceType(int opportunityID) {
		return reinterpret_cast<int(*)(int)>(0x7256da)(opportunityID);
	}

	float aiGetOpportunityRadius(float opportunityID) {
		return reinterpret_cast<float(*)(float)>(0x72571f)(opportunityID);
	}

	int aiGetOpportunityTargetPlayerID(int opportunityID) {
		return reinterpret_cast<int(*)(int)>(0x725767)(opportunityID);
	}

	int aiGetOpportunityTargetType(int opportunityID) {
		return reinterpret_cast<int(*)(int)>(0x7257ac)(opportunityID);
	}

	int aiGetOpportunityType(int opportunityID) {
		return reinterpret_cast<int(*)(int)>(0x7257f1)(opportunityID);
	}

	vector aiGetOpportunityLocation(vector result, int opportunityID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x725836)(result, opportunityID);
	}

	int aiGetOpportunityTargetID(int opportunityID) {
		return reinterpret_cast<int(*)(int)>(0x7258d7)(opportunityID);
	}

	void aiSetOpportunityTargetType(int opportunityID, int targetType) {
		reinterpret_cast<void(*)(int, int)>(0x72591c)(opportunityID, targetType);
	}

	void aiSetOpportunityTargetID(int opportunityID, int targetType) {
		reinterpret_cast<void(*)(int, int)>(0x725961)(opportunityID, targetType);
	}

	void aiSetOpportunityRadius(int opportunityID, float radius) {
		reinterpret_cast<void(*)(int, float)>(0x7259a6)(opportunityID, radius);
	}

	void aiSetOpportunityLocation(int opportunityID, vector location) {
		reinterpret_cast<void(*)(int, vector)>(0x7259eb)(opportunityID, location);
	}

	bool aiSetOpportunityScore(int oppID, int permission, float affordable, float classscore, float instance, float total) {
		return reinterpret_cast<bool(*)(int, int, float, float, float, float)>(0x725a3b)(oppID, permission, affordable, classscore, instance, total);
	}

	bool aiCastGodPowerAtPosition(int godPowerTechID, vector pos) {
		return reinterpret_cast<bool(*)(int, vector)>(0x728e6f)(godPowerTechID, pos);
	}

	int aiGetGodPowerTechIDForSlot(int slotID) {
		return reinterpret_cast<int(*)(int)>(0x725aa7)(slotID);
	}

	int aiGetGodPowerProtoIDForTechID(int techID) {
		return reinterpret_cast<int(*)(int)>(0x882556)(techID);
	}

	int aiGetGodPowerType(int protoPowerID) {
		return reinterpret_cast<int(*)(int)>(0x725ac2)(protoPowerID);
	}

	int aiFindBestAttackGodPowerPlan() {
		return reinterpret_cast<int(*)()>(0x725ae8)();
	}

	int aiFindBestTownDefenseGodPowerPlan() {
		return reinterpret_cast<int(*)()>(0x725b1d)();
	}

	int aiGetWorldDifficulty() {
		return reinterpret_cast<int(*)()>(0x725b52)();
	}

	void aiSetWorldDifficulty(int v) {
		reinterpret_cast<void(*)(int)>(0x725b6e)(v);
	}

	string aiGetWorldDifficultyName(int level) {
		return reinterpret_cast<string(*)(int)>(0x725b88)(level);
	}

	int aiGetGameMode() {
		return reinterpret_cast<int(*)()>(0x725bd0)();
	}

	int aiGetCaptainPlayerID(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x725bea)(playerID);
	}

	bool aiGetAutosaveOn() {
		return reinterpret_cast<bool(*)()>(0x58ea6b)();
	}

	float aiGetCurrentResourceNeed(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x725c2b)(resourceID);
	}

	bool aiSetAutoGatherMilitaryUnits(bool v) {
		return reinterpret_cast<bool(*)(bool)>(0x725c7a)(v);
	}

	bool aiSetExploreDangerThreshold(float value) {
		return reinterpret_cast<bool(*)(float)>(0x725cb3)(value);
	}

	float aiGetExploreDangerThreshold() {
		return reinterpret_cast<float(*)()>(0x725cec)();
	}

	void aiSetRandomMap(bool v) {
		reinterpret_cast<void(*)(bool)>(0x725d23)(v);
	}

	void aiSetPauseAllAgeUpgrades(bool v) {
		reinterpret_cast<void(*)(bool)>(0x725d57)(v);
	}

	bool aiGetPauseAllAgeUpgrades(bool a) {
		return reinterpret_cast<bool(*)(bool)>(0x725d8b)(a);
	}

	void aiSetMinArmySize(int v) {
		reinterpret_cast<void(*)(int)>(0x725dbe)(v);
	}

	void aiSetMinNumberNeedForGatheringAggressvies(int v) {
		reinterpret_cast<void(*)(int)>(0x725df2)(v);
	}

	int aiGetMinNumberNeedForGatheringAggressives() {
		return reinterpret_cast<int(*)()>(0x725e26)();
	}

	void aiSetMinNumberWantForGatheringAggressives(int v) {
		reinterpret_cast<void(*)(int)>(0x725e5a)(v);
	}

	int aiGetMinNumberWantForGatheringAggressives() {
		return reinterpret_cast<int(*)()>(0x725e8e)();
	}

	void aiResign() {
		reinterpret_cast<void(*)()>(0x725ec2)();
	}

	void aiAttemptResign(int a) {
		reinterpret_cast<void(*)(int)>(0x72751e)(a);
	}

	void aiSetMaxLOSProtoUnitLimit(int limit) {
		reinterpret_cast<void(*)(int)>(0x725f60)(limit);
	}

	int aiGetMaxLOSProtoUnitLimit() {
		return reinterpret_cast<int(*)()>(0x725f94)();
	}

	int aiGetPopNeeds() {
		return reinterpret_cast<int(*)()>(0x725fc8)();
	}

	void aiSwitchMainBase(int newBaseID, bool force) {
		reinterpret_cast<void(*)(int, bool)>(0x725ffb)(newBaseID, force);
	}

	void aiSetDefaultStance(int defaultStance) {
		reinterpret_cast<void(*)(int)>(0x726036)(defaultStance);
	}

	void aiSetWaterMap(bool v) {
		reinterpret_cast<void(*)(bool)>(0x72605b)(v);
	}

	bool aiGetWaterMap() {
		return reinterpret_cast<bool(*)()>(0x72608f)();
	}

	bool aiIsMapType(string mapType) {
		return reinterpret_cast<bool(*)(string)>(0x729186)(mapType);
	}

	int aiHCCardsGetTotal() {
		return reinterpret_cast<int(*)()>(0x727854)();
	}

	bool aiHCCardsIsCardBought(int cardIndex) {
		return reinterpret_cast<bool(*)(int)>(0x727887)(cardIndex);
	}

	bool aiHCCardsCanIBuyThisCard(int deckIndex, int cardIndex) {
		return reinterpret_cast<bool(*)(int, int)>(0x7278e1)(deckIndex, cardIndex);
	}

	bool aiHCCardsBuyCard(int cardIndex) {
		return reinterpret_cast<bool(*)(int)>(0x7279a7)(cardIndex);
	}

	int aiHCCardsGetCardAgePrereq(int cardIndex) {
		return reinterpret_cast<int(*)(int)>(0x727a36)(cardIndex);
	}

	int aiHCCardsGetCardLevel(int cardIndex) {
		return reinterpret_cast<int(*)(int)>(0x727a87)(cardIndex);
	}

	int aiHCCardsGetCardTechID(int a) {
		return reinterpret_cast<int(*)(int)>(0x727ad8)(a);
	}

	int aiHCCardsGetCardUnitType(int a) {
		return reinterpret_cast<int(*)(int)>(0x727b28)(a);
	}

	int aiHCCardsGetCardUnitCount(int a) {
		return reinterpret_cast<int(*)(int)>(0x727b82)(a);
	}

	int aiHCCardsGetCardCount(int a) {
		return reinterpret_cast<int(*)(int)>(0x727bd8)(a);
	}

	int aiHCCardsFindBestCard(int cardType, int levelPref, int resourcePref) {
		return reinterpret_cast<int(*)(int, int, int)>(0x7260c2)(cardType, levelPref, resourcePref);
	}

	int aiHCGetNumberDecks() {
		return reinterpret_cast<int(*)()>(0x727c2c)();
	}

	int aiHCDeckCreate(string a) {
		return reinterpret_cast<int(*)(string)>(0x726110)(a);
	}

	bool aiHCDeckActivate(int deckIndex) {
		return reinterpret_cast<bool(*)(int)>(0x726177)(deckIndex);
	}

	bool aiHCDeckAddCardToDeck(int deckIndex, int cardIndex) {
		return reinterpret_cast<bool(*)(int, int)>(0x727c5f)(deckIndex, cardIndex);
	}

	int aiHCDeckGetNumberCards(int deckIndex) {
		return reinterpret_cast<int(*)(int)>(0x727cb8)(deckIndex);
	}

	bool aiHCDeckPlayCard(int cardIndex) {
		return reinterpret_cast<bool(*)(int)>(0x7261db)(cardIndex);
	}

	int aiHCDeckGetCardAgePrereq(int deckIndex, int cardIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x727cca)(deckIndex, cardIndex);
	}

	int aiHCDeckGetCardLevel(int deckIndex, int cardIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x727cf6)(deckIndex, cardIndex);
	}

	int aiHCDeckGetCardTechID(int deckIndex, int cardIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x727d22)(deckIndex, cardIndex);
	}

	int aiHCDeckGetCardUnitType(int deckIndex, int cardIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x727d72)(deckIndex, cardIndex);
	}

	int aiHCDeckGetCardUnitCount(int deckIndex, int cardIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x727dda)(deckIndex, cardIndex);
	}

	bool aiHCDeckCanPlayCard(int cardIndex) {
		return reinterpret_cast<bool(*)(int)>(0x727e3e)(cardIndex);
	}

	int aiHCDeckCardGetCardCount(int deskIndex, int cardIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x727ff5)(deskIndex, cardIndex);
	}

	vector aiGetHCGatherPoint(vector result) {
		return reinterpret_cast<vector(*)(vector)>(0x728050)(result);
	}

	bool aiSetHCGatherPoint() {
		return reinterpret_cast<bool(*)()>(0x726236)();
	}

	int aiGetScore(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x72626c)(playerID);
	}

	int aiGetNumberTeams() {
		return reinterpret_cast<int(*)()>(0x7280f9)();
	}

	void aiQueueAutoSavegame(int saveNumber) {
		reinterpret_cast<void(*)(int)>(0x72629b)(saveNumber);
	}

	bool aiIsMultiplayer() {
		return reinterpret_cast<bool(*)()>(0x7262d1)();
	}

	int aiGetFallenExplorerID() {
		return reinterpret_cast<int(*)()>(0x728ec5)();
	}

	bool aiRansomExplorer(int explorerID, int escrowID, int sourceBuildingID) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x728117)(explorerID, escrowID, sourceBuildingID);
	}

	bool aiBuildWall(int buildingID, int escrowID) {
		return reinterpret_cast<bool(*)(int, int)>(0x72823a)(buildingID, escrowID);
	}

	bool aiCanBuildWall(int buildingID, int escrowID) {
		return reinterpret_cast<bool(*)(int, int)>(0x728332)(buildingID, escrowID);
	}

	float aiGetWallRadius(int buildingID) {
		return reinterpret_cast<float(*)(int)>(0x728fbd)(buildingID);
	}

	bool aiDoesWallExist(int buildingID) {
		return reinterpret_cast<bool(*)(int)>(0x729048)(buildingID);
	}

	int aiGetGameType() {
		return reinterpret_cast<int(*)()>(0x726386)();
	}

	bool aiUnitSetTactic(int unitID, int tacticID) {
		return reinterpret_cast<bool(*)(int, int)>(0x7283f9)(unitID, tacticID);
	}

	int aiUnitGetTactic(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x728477)(unitID);
	}

	void aiResourceLock(int resourceID) {
		reinterpret_cast<void(*)(int)>(0x7262dc)(resourceID);
	}

	void aiResourceUnlock(int resourceID) {
		reinterpret_cast<void(*)(int)>(0x726313)(resourceID);
	}

	bool aiResourceIsLocked(int resourceID) {
		return reinterpret_cast<bool(*)(int)>(0x72634a)(resourceID);
	}

	bool aiBreakTreaty(int escrowID) {
		return reinterpret_cast<bool(*)(int)>(0x726392)(escrowID);
	}

	bool aiTreatyActive() {
		return reinterpret_cast<bool(*)()>(0x726438)();
	}

	void aiSetPoliticianChoice(int age, int puid) {
		reinterpret_cast<void(*)(int, int)>(0x72645d)(age, puid);
	}

	int aiGetPoliticianChoice(int age) {
		return reinterpret_cast<int(*)(int)>(0x726498)(age);
	}

	bool aiPopulatePoliticianList() {
		return reinterpret_cast<bool(*)()>(0x7264d2)();
	}

	int aiGetPoliticianListCount(int age) {
		return reinterpret_cast<int(*)(int)>(0x726505)(age);
	}

	int aiGetPoliticianListByIndex(int age, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x72653f)(age, index);
	}

	int aiGetLastCollectedNuggetType(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x72657e)(playerID);
	}

	int aiGetLastCollectedNuggetEffect(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x7284ce)(playerID);
	}

	int aiGetNumberTradePostsControlled(int teamID) {
		return reinterpret_cast<int(*)(int)>(0x7265c5)(teamID);
	}

	int aiGetNumberTradePostsNeededForMonopoly() {
		return reinterpret_cast<int(*)()>(0x72660c)();
	}

	bool aiReadyForTradeMonopoly() {
		return reinterpret_cast<bool(*)()>(0x726636)();
	}

	bool aiDoTradeMonopoly() {
		return reinterpret_cast<bool(*)()>(0x726664)();
	}

	bool aiIsMonopolyAllowed() {
		return reinterpret_cast<bool(*)()>(0x726691)();
	}

	int aiGetNumberRelicsControlled(int teamID) {
		return reinterpret_cast<int(*)(int)>(0x7266f8)(teamID);
	}

	int aiGetNumberRelicsNeededForVictory() {
		return reinterpret_cast<int(*)()>(0x72673f)();
	}

	bool aiIsRelicCaptureAllowed() {
		return reinterpret_cast<bool(*)()>(0x7266de)();
	}

	bool aiIsKOTHAllowed() {
		return reinterpret_cast<bool(*)()>(0x72674f)();
	}

	int aiGetKOTHController() {
		return reinterpret_cast<int(*)()>(0x72862c)();
	}

	bool aiIsTeamKOTH(int teamID) {
		return reinterpret_cast<bool(*)(int)>(0x72679c)(teamID);
	}

	void kbDump(int player1, int player2) {
		reinterpret_cast<void(*)(int, int)>(0x88112c)(player1, player2);
	}

	void kbDumpType(int player1, int player2, string typeName) {
		reinterpret_cast<void(*)(int, int, string)>(0x88116b)(player1, player2, typeName);
	}

	void kbLookAtAllUnitsOnMap() {
		reinterpret_cast<void(*)()>(0x8811af)();
	}

	int kbGetPop() {
		return reinterpret_cast<int(*)()>(0x8811e0)();
	}

	int kbGetPopCap() {
		return reinterpret_cast<int(*)()>(0x881213)();
	}

	int kbGetAge() {
		return reinterpret_cast<int(*)()>(0x881246)();
	}

	int kbGetAgeForPlayer(int id) {
		return reinterpret_cast<int(*)(int)>(0x88127a)(id);
	}

	int kbGetCulture() {
		return reinterpret_cast<int(*)()>(0x88129f)();
	}

	int kbGetCultureForPlayer(int a) {
		return reinterpret_cast<int(*)(int)>(0x8812d3)(a);
	}

	string kbGetCultureName(int a) {
		return reinterpret_cast<string(*)(int)>(0x8812fb)(a);
	}

	int kbGetCiv() {
		return reinterpret_cast<int(*)()>(0x881311)();
	}

	int kbGetCivForPlayer(int a) {
		return reinterpret_cast<int(*)(int)>(0x881345)(a);
	}

	string kbGetCivName(int civID) {
		return reinterpret_cast<string(*)(int)>(0x88136d)(civID);
	}

	int kbUnitQueryCreate(string name) {
		return reinterpret_cast<int(*)(string)>(0x881383)(name);
	}

	bool kbUnitQueryResetData(int queryID) {
		return reinterpret_cast<bool(*)(int)>(0x8813bc)(queryID);
	}

	bool kbUnitQueryResetResults(int queryID) {
		return reinterpret_cast<bool(*)(int)>(0x8813f5)(queryID);
	}

	bool kbUnitQueryDestroy(int queryID) {
		return reinterpret_cast<bool(*)(int)>(0x88142e)(queryID);
	}

	int kbUnitQueryNumberResults(int queryID) {
		return reinterpret_cast<int(*)(int)>(0x881467)(queryID);
	}

	int kbUnitQueryGetResult(int queryID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x8814a0)(queryID, index);
	}

	bool kbUnitQuerySetPlayerID(int queryID, int playerID, bool resetQueryData) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x8814df)(queryID, playerID, resetQueryData);
	}

	bool kbUnitQuerySetPlayerRelation(int queryID, int playerRelation) {
		return reinterpret_cast<bool(*)(int, int)>(0x881522)(queryID, playerRelation);
	}

	bool kbUnitQuerySetUnitType(int queryID, int unitTypeID) {
		return reinterpret_cast<bool(*)(int, int)>(0x881560)(queryID, unitTypeID);
	}

	bool kbUnitQuerySetActionType(int queryID, int actionTypeID) {
		return reinterpret_cast<bool(*)(int, int)>(0x88159e)(queryID, actionTypeID);
	}

	bool kbUnitQuerySetState(int queryID, int state) {
		return reinterpret_cast<bool(*)(int, int)>(0x8815dc)(queryID, state);
	}

	bool kbUnitQuerySetPosition(int queryID, vector v) {
		return reinterpret_cast<bool(*)(int, vector)>(0x88161a)(queryID, v);
	}

	bool kbUnitQuerySetMaximumDistance(int queryID, float distance) {
		return reinterpret_cast<bool(*)(int, float)>(0x881658)(queryID, distance);
	}

	bool kbUnitQuerySetIgnoreKnockedOutUnits(int queryID, bool v) {
		return reinterpret_cast<bool(*)(int, bool)>(0x881696)(queryID, v);
	}

	bool kbUnitQuerySetAscendingSort(int queryID, bool v) {
		return reinterpret_cast<bool(*)(int, bool)>(0x8816d4)(queryID, v);
	}

	bool kbUnitQuerySetBaseID(int queryID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x881721)(queryID, baseID);
	}

	bool kbUnitQuerySetAreaID(int queryID, int areaID) {
		return reinterpret_cast<bool(*)(int, int)>(0x88175f)(queryID, areaID);
	}

	bool kbUnitQuerySetAreaGroupID(int queryID, int areaGroupID) {
		return reinterpret_cast<bool(*)(int, int)>(0x88179d)(queryID, areaGroupID);
	}

	bool kbUnitQuerySetArmyID(int queryID, int armyID) {
		return reinterpret_cast<bool(*)(int, int)>(0x8817db)(queryID, armyID);
	}

	bool kbUnitQuerySetSeeableOnly(int queryID, bool seeableOnly) {
		return reinterpret_cast<bool(*)(int, bool)>(0x881819)(queryID, seeableOnly);
	}

	int kbUnitQueryExecute(int queryID) {
		return reinterpret_cast<int(*)(int)>(0x881857)(queryID);
	}

	int kbUnitQueryExecuteOnQuery(int currentQueryID, int previousQueryID) {
		return reinterpret_cast<int(*)(int, int)>(0x881890)(currentQueryID, previousQueryID);
	}

	int kbUnitQueryExecuteOnQueryByName(int currentQueryID, string previousQueryName) {
		return reinterpret_cast<int(*)(int, string)>(0x8818ce)(currentQueryID, previousQueryName);
	}

	float kbUnitQueryGetUnitCost(int queryID, bool considerHealth) {
		return reinterpret_cast<float(*)(int, bool)>(0x8859ca)(queryID, considerHealth);
	}

	float kbUnitQueryGetUnitHitpoints(int queryID, bool considerHealth) {
		return reinterpret_cast<float(*)(int, bool)>(0x885b00)(queryID, considerHealth);
	}

	int kbUnitGetPlayerID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x88190c)(unitID);
	}

	int kbUnitGetPlanID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x881961)(unitID);
	}

	int kbUnitGetBaseID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x88199b)(unitID);
	}

	int kbUnitGetAreaID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x8819d5)(unitID);
	}

	int kbUnitGetArmyID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x881a0f)(unitID);
	}

	int kbUnitGetMovementType(int unitTypeID) {
		return reinterpret_cast<int(*)(int)>(0x881a49)(unitTypeID);
	}

	float kbUnitGetCurrentHitpoints(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x881a83)(unitID);
	}

	float kbUnitGetMaximumHitpoints(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x881ac0)(unitID);
	}

	float kbUnitGetHealth(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x881afd)(unitID);
	}

	float kbUnitGetCurrentAICost(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x881b3a)(unitID);
	}

	float kbUnitGetMaximumAICost(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x881b77)(unitID);
	}

	vector kbUnitGetPosition(vector result, int unitID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x881bb4)(result, unitID);
	}

	bool kbUnitIsType(int unitID, int unitTypeID) {
		return reinterpret_cast<bool(*)(int, int)>(0x881c14)(unitID, unitTypeID);
	}

	int kbUnitGetActionType(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x881c52)(unitID);
	}

	int kbUnitGetTargetUnitID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x881c8c)(unitID);
	}

	int kbUnitGetNumberWorkers(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x881cc6)(unitID);
	}

	int kbUnitGetWorkerID(int unitID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x881cff)(unitID, index);
	}

	int kbGetBuildLimit(int player, int unitTypeID) {
		return reinterpret_cast<int(*)(int, int)>(0x881d3e)(player, unitTypeID);
	}

	int kbGetPopCapAddition(int player, int unitTypeID) {
		return reinterpret_cast<int(*)(int, int)>(0x881d7f)(player, unitTypeID);
	}

	int kbGetPopSlots(int player, int unitTypeID) {
		return reinterpret_cast<int(*)(int, int)>(0x881db6)(player, unitTypeID);
	}

	int kbGetPopulationSlotsByUnitTypeID(int playerID, int unitTypeID) {
		return reinterpret_cast<int(*)(int, int)>(0x881ded)(playerID, unitTypeID);
	}

	int kbGetPopulationSlotsByQueryID(int queryID) {
		return reinterpret_cast<int(*)(int)>(0x881e2b)(queryID);
	}

	int kbUnitCount(int player, int unitTypeID, int stateID) {
		return reinterpret_cast<int(*)(int, int, int)>(0x881e64)(player, unitTypeID, stateID);
	}

	void kbUnitCountConsole(int playerID1, int playerID2, string unitType, string state) {
		reinterpret_cast<void(*)(int, int, string, string)>(0x885c10)(playerID1, playerID2, unitType, state);
	}

	vector kbGetMapCenter(vector result) {
		return reinterpret_cast<vector(*)(vector)>(0x881ea9)(result);
	}

	float kbGetMapXSize() {
		return reinterpret_cast<float(*)()>(0x881f04)();
	}

	float kbGetMapZSize() {
		return reinterpret_cast<float(*)()>(0x881f3c)();
	}

	void kbAreaCalculate(float a, bool b, vector c, vector d, vector e, vector f) {
		reinterpret_cast<void(*)(float, bool, vector, vector, vector, vector)>(0x881f74)(a, b, c, d, e, f);
	}

	int kbAreaGetNumber() {
		return reinterpret_cast<int(*)()>(0x8850ac)();
	}

	int kbAreaGetIDByPosition(vector position) {
		return reinterpret_cast<int(*)(vector)>(0x8820b6)(position);
	}

	int kbAreaGroupGetIDByPosition(vector position) {
		return reinterpret_cast<int(*)(vector)>(0x8820f0)(position);
	}

	vector kbAreaGroupGetCenter(vector result, int groupID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x88212a)(result, groupID);
	}

	vector kbAreaGetCenter(vector result, int areaID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x8821a8)(result, areaID);
	}

	int kbAreaGetNumberTiles(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x882226)(areaID);
	}

	int kbAreaGetNumberBlackTiles(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x88225f)(areaID);
	}

	int kbAreaGetNumberVisibleTiles(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x882298)(areaID);
	}

	int kbAreaGetNumberFogTiles(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x8822d1)(areaID);
	}

	int kbAreaGetVisibilityChangeTime(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x88230a)(areaID);
	}

	int kbAreaGetNumberUnits(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x882343)(areaID);
	}

	int kbAreaGetUnitID(int areaID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x88237c)(areaID, index);
	}

	int kbAreaGetNumberBorderAreas(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x8823bb)(areaID);
	}

	int kbAreaGetBorderAreaID(int areaID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x8823f4)(areaID, index);
	}

	int kbAreaGetType(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x882433)(areaID);
	}

	int kbAreaGetVPSiteID(int areaID) {
		return reinterpret_cast<int(*)(int)>(0x88246d)(areaID);
	}

	int kbVPSiteQuery(int scoreType, int playerRelationOrID, int siteState) {
		return reinterpret_cast<int(*)(int, int, int)>(0x8824a7)(scoreType, playerRelationOrID, siteState);
	}

	void kbDumpVPSiteInfo() {
		reinterpret_cast<void(*)()>(0x8824eb)();
	}

	int kbVPSiteGetType(int siteID) {
		return reinterpret_cast<int(*)(int)>(0x8850e6)(siteID);
	}

	vector kbVPSiteGetLocation(vector result, int siteID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x88513a)(result, siteID);
	}

	int kbVPSiteGetOwnerPlayerID(int siteID) {
		return reinterpret_cast<int(*)(int)>(0x8851ba)(siteID);
	}

	int kbVPSiteGetState(int siteID) {
		return reinterpret_cast<int(*)(int)>(0x885208)(siteID);
	}

	int kbGetVPGeneratorByScoreType(int siteType) {
		return reinterpret_cast<int(*)(int)>(0x88251c)(siteType);
	}

	int kbAreaGetClosetArea(vector position, int areaType, int areaType1, float minDistance) {
		return reinterpret_cast<int(*)(vector, int, int, float)>(0x88255a)(position, areaType, areaType1, minDistance);
	}

	int kbPathCreate(string name) {
		return reinterpret_cast<int(*)(string)>(0x8825a3)(name);
	}

	bool kbPathDestroy(int pathID) {
		return reinterpret_cast<bool(*)(int)>(0x8825dd)(pathID);
	}

	int kbPathGetNumber() {
		return reinterpret_cast<int(*)()>(0x885259)();
	}

	int kbPathGetIDByIndex(int index) {
		return reinterpret_cast<int(*)(int)>(0x882616)(index);
	}

	string kbPathGetName(int pathID) {
		return reinterpret_cast<string(*)(int)>(0x882650)(pathID);
	}

	float kbPathGetLength(int pathID) {
		return reinterpret_cast<float(*)(int)>(0x882689)(pathID);
	}

	int kbPathGetNumberWaypoints(int pathID) {
		return reinterpret_cast<int(*)(int)>(0x8826c6)(pathID);
	}

	bool kbPathAddWaypoint(int pathID, vector waypoint) {
		return reinterpret_cast<bool(*)(int, vector)>(0x8826ff)(pathID, waypoint);
	}

	vector kbPathGetWaypoint(vector result, int pathID, int waypointNumber) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x88273d)(result, pathID, waypointNumber);
	}

	bool kbCanSimPath(vector pointA, vector pointB, int protoUnitTypeID, float range) {
		return reinterpret_cast<bool(*)(vector, vector, int, float)>(0x88277e)(pointA, pointB, protoUnitTypeID, range);
	}

	bool kbCanPath2(vector pointA, vector pointB, int protoUnitTypeID, float range) {
		return reinterpret_cast<bool(*)(vector, vector, int, float)>(0x8827cc)(pointA, pointB, protoUnitTypeID, range);
	}

	int kbCreateAttackRoute(string name, int startAreaID, int goalAreaID, int numInitialRoutes) {
		return reinterpret_cast<int(*)(string, int, int, int)>(0x882825)(name, startAreaID, goalAreaID, numInitialRoutes);
	}

	int kbCreateAttackRouteWithPath(string name, vector startPt, vector endPt) {
		return reinterpret_cast<int(*)(string, vector, vector)>(0x882894)(name, startPt, endPt);
	}

	bool kbDestroyAttackRoute(int routeID) {
		return reinterpret_cast<bool(*)(int)>(0x8828e5)(routeID);
	}

	bool kbAddAttackRouteSector(int sector) {
		return reinterpret_cast<bool(*)(int)>(0x88291e)(sector);
	}

	bool kbAddAttackRouteIgnoreID(int ignoreAreaID) {
		return reinterpret_cast<bool(*)(int)>(0x882957)(ignoreAreaID);
	}

	bool kbAddAttackRouteIgnoreType(int ignoreAreaTypeID) {
		return reinterpret_cast<bool(*)(int)>(0x882990)(ignoreAreaTypeID);
	}

	bool kbAttackRouteAddPath(int attackRouteID, int pathID) {
		return reinterpret_cast<bool(*)(int, int)>(0x8829c9)(attackRouteID, pathID);
	}

	bool kbMakeAttackRoutes() {
		return reinterpret_cast<bool(*)()>(0x882a07)();
	}

	int kbGetNumAttackRoutes(int startAreaID, int goalAreaID) {
		return reinterpret_cast<int(*)(int, int)>(0x88528c)(startAreaID, goalAreaID);
	}

	int kbGetAttackRouteID(int startAreaID, int goalAreaID) {
		return reinterpret_cast<int(*)(int, int)>(0x882a3a)(startAreaID, goalAreaID);
	}

	int kbEscrowCreate(string name, int resourceID, float percentage, int parentID) {
		return reinterpret_cast<int(*)(string, int, float, int)>(0x882a7e)(name, resourceID, percentage, parentID);
	}

	bool kbEscrowDestroy(int escrowID, bool promoteChildren) {
		return reinterpret_cast<bool(*)(int, bool)>(0x882ac7)(escrowID, promoteChildren);
	}

	int kbEscrowGetID(string name) {
		return reinterpret_cast<int(*)(string)>(0x882b05)(name);
	}

	float kbEscrowGetPercentage(int escrowID, int resourceID) {
		return reinterpret_cast<float(*)(int, int)>(0x882b3f)(escrowID, resourceID);
	}

	bool kbEscrowSetPercentage(int escrowID, int resourceID, float percentage) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x882b81)(escrowID, resourceID, percentage);
	}

	bool kbEscrowSetCap(int escrowID, int resourceID, float cap) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x882bc4)(escrowID, resourceID, cap);
	}

	float kbEscrowGetAmount(int escrowID, int resourceID) {
		return reinterpret_cast<float(*)(int, int)>(0x882c07)(escrowID, resourceID);
	}

	bool kbEscrowFlush(int escrowID, int resourceID, bool flushChildren) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x882c49)(escrowID, resourceID, flushChildren);
	}

	bool kbEscrowAllocateCurrentResources() {
		return reinterpret_cast<bool(*)()>(0x882c8c)();
	}

	int kbBuildingPlacementCreate(string name) {
		return reinterpret_cast<int(*)(string)>(0x882cc2)(name);
	}

	bool kbBuildingPlacementDestroy(int id) {
		return reinterpret_cast<bool(*)(int)>(0x882cfc)(id);
	}

	bool kbBuildingPlacementResetResults() {
		return reinterpret_cast<bool(*)()>(0x882d35)();
	}

	bool kbBuildingPlacementSelect(int id) {
		return reinterpret_cast<bool(*)(int)>(0x882d68)(id);
	}

	bool kbBuildingPlacementSetEventHandler(int eventType, string handlerName) {
		return reinterpret_cast<bool(*)(int, string)>(0x882da1)(eventType, handlerName);
	}

	bool kbBuildingPlacementSetBuildingType(int buildingTypeID) {
		return reinterpret_cast<bool(*)(int)>(0x882e3e)(buildingTypeID);
	}

	bool kbBuildingPlacementSetBaseID(int baseID, int locationPref) {
		return reinterpret_cast<bool(*)(int, int)>(0x882e77)(baseID, locationPref);
	}

	bool kbBuildingPlacementAddAreaID(int areaID, int numberBorderAreaLayers, bool addCenterInfluence) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x882eb5)(areaID, numberBorderAreaLayers, addCenterInfluence);
	}

	bool kbBuildingPlacementAddAreaGroupID(int areaGroupID) {
		return reinterpret_cast<bool(*)(int)>(0x882ef8)(areaGroupID);
	}

	bool kbBuildingPlacementSetCenterPosition(vector position, float distance, float obstructionRadius) {
		return reinterpret_cast<bool(*)(vector, float, float)>(0x882f31)(position, distance, obstructionRadius);
	}

	bool kbBuildingPlacementAddUnitInfluence(int typeID, float value, float distance, int kbResourceID) {
		return reinterpret_cast<bool(*)(int, float, float, int)>(0x882f74)(typeID, value, distance, kbResourceID);
	}

	bool kbBuildingPlacementAddPositionInfluence(vector position, float value, float distance) {
		return reinterpret_cast<bool(*)(vector, float, float)>(0x882fbc)(position, value, distance);
	}

	bool kbBuildingPlacementSetMinimumValue(float minimumValue) {
		return reinterpret_cast<bool(*)(float)>(0x882fff)(minimumValue);
	}

	bool kbBuildingPlacementStart() {
		return reinterpret_cast<bool(*)()>(0x883038)();
	}

	vector kbBuildingPlacementGetResultPosition(vector result, int bpID) {
		return reinterpret_cast<vector(*)(vector, int)>(0x88306b)(result, bpID);
	}

	float kbBuildingPlacementGetResultValue(int bpID) {
		return reinterpret_cast<float(*)(int)>(0x8830da)(bpID);
	}

	int kbTargetSelectorCreate(string name) {
		return reinterpret_cast<int(*)(string)>(0x883117)(name);
	}

	bool kbTargetSelectorDestroy(int id) {
		return reinterpret_cast<bool(*)(int)>(0x883151)(id);
	}

	bool kbTargetSelectorResetResults() {
		return reinterpret_cast<bool(*)()>(0x88318a)();
	}

	bool kbTargetSelectorSelect(int id) {
		return reinterpret_cast<bool(*)(int)>(0x8831bd)(id);
	}

	bool kbTargetSelectorAddUnitType(int protoUnitTypeID) {
		return reinterpret_cast<bool(*)(int)>(0x8831f6)(protoUnitTypeID);
	}

	bool kbTargetSelectorAddQueryResults(int queryID) {
		return reinterpret_cast<bool(*)(int)>(0x88322f)(queryID);
	}

	int kbTargetSelectorGetNumberResults() {
		return reinterpret_cast<int(*)()>(0x883268)();
	}

	int kbTargetSelectorGetResultValue(int index) {
		return reinterpret_cast<int(*)(int)>(0x88329b)(index);
	}

	bool kbTargetSelectorStart() {
		return reinterpret_cast<bool(*)()>(0x8832d5)();
	}

	bool kbSetupForResource(int baseID, int resourceID, float distance, float amount) {
		return reinterpret_cast<bool(*)(int, int, float, float)>(0x883308)(baseID, resourceID, distance, amount);
	}

	int kbGetHCLevel(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x883350)(playerID);
	}

	int kbResourceGetXP(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x883378)(playerID);
	}

	float kbResourceGet(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x8833a0)(resourceID);
	}

	float kbMaximumResourceGet(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x8833dd)(resourceID);
	}

	float kbTotalResourceGet(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x88341a)(resourceID);
	}

	int kbGetNumberValidResourcesByPlan(int planID, int baseID) {
		return reinterpret_cast<int(*)(int, int)>(0x883457)(planID, baseID);
	}

	int kbGetNumberValidResources(int baseID, int resourceTypeID, int resourceSubTypeID, float distance) {
		return reinterpret_cast<int(*)(int, int, int, float)>(0x883495)(baseID, resourceTypeID, resourceSubTypeID, distance);
	}

	float kbGetAmountValidResources(int baseID, int resourceTypeID, int resourceSubTypeID, float distance) {
		return reinterpret_cast<float(*)(int, int, int, float)>(0x8834dd)(baseID, resourceTypeID, resourceSubTypeID, distance);
	}

	float kbGetResourceIncome(int resourceID, float seconds, bool relative) {
		return reinterpret_cast<float(*)(int, float, bool)>(0x883529)(resourceID, seconds, relative);
	}

	bool kbProtoUnitAvailable(int protoUnitID) {
		return reinterpret_cast<bool(*)(int)>(0x883570)(protoUnitID);
	}

	int kbGetProtoUnitID(string name) {
		return reinterpret_cast<int(*)(string)>(0x8835b6)(name);
	}

	int kbUnitGetProtoUnitID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x8852d1)(unitID);
	}

	bool kbCanAffordUnit(int protoUnitTypeID, int escrowID) {
		return reinterpret_cast<bool(*)(int, int)>(0x8835d3)(protoUnitTypeID, escrowID);
	}

	float kbUnitCostPerResource(int protoUnitID, int resourceID) {
		return reinterpret_cast<float(*)(int, int)>(0x883613)(protoUnitID, resourceID);
	}

	bool kbCanAffordTech(int techID, int escrowID) {
		return reinterpret_cast<bool(*)(int, int)>(0x883689)(techID, escrowID);
	}

	float kbTechCostPerResource(int techID, int resourceID) {
		return reinterpret_cast<float(*)(int, int)>(0x8836c7)(techID, resourceID);
	}

	bool kbProtoUnitIsType(int playerID, int protoUnitID, int unitTypeID) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x883710)(playerID, protoUnitID, unitTypeID);
	}

	int kbTechGetStatus(int techID) {
		return reinterpret_cast<int(*)(int)>(0x883753)(techID);
	}

	float kbGetTechPercentComplete(int techID) {
		return reinterpret_cast<float(*)(int)>(0x88378e)(techID);
	}

	float kbGetCombatEfficiency(int playerID1, int unitTypeID1, int playerID2, int unitTypeID2) {
		return reinterpret_cast<float(*)(int, int, int, int)>(0x8837c7)(playerID1, unitTypeID1, playerID2, unitTypeID2);
	}

	float kbGetAICostWeight(int resourceID) {
		return reinterpret_cast<float(*)(int)>(0x883813)(resourceID);
	}

	bool kbSetAICostWeight(int resourceID, float weight) {
		return reinterpret_cast<bool(*)(int, float)>(0x883850)(resourceID, weight);
	}

	float kbGetProtoUnitAICost(int protoUnitTypeID) {
		return reinterpret_cast<float(*)(int)>(0x88388e)(protoUnitTypeID);
	}

	float kbGetTechAICost(int techID) {
		return reinterpret_cast<float(*)(int)>(0x8838cb)(techID);
	}

	bool kbIsPlayerResigned(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x883908)(playerID);
	}

	bool kbHasPlayerLost(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x883937)(playerID);
	}

	int kbGetPlayerTeam(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x88396e)(playerID);
	}

	string kbGetPlayerName(int playerID) {
		return reinterpret_cast<string(*)(int)>(0x883999)(playerID);
	}

	bool kbIsPlayerEnemy(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x8839ce)(playerID);
	}

	bool kbIsPlayerNeutral(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x883a27)(playerID);
	}

	bool kbIsPlayerAlly(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x883a5d)(playerID);
	}

	bool kbIsPlayerMutualAlly(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x883ab6)(playerID);
	}

	int kbGetNumberMutualAllies() {
		return reinterpret_cast<int(*)()>(0x88530e)();
	}

	bool kbIsPlayerValid(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x88537b)(playerID);
	}

	bool kbIsPlayerHuman(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x883aec)(playerID);
	}

	float kbGetPlayerHandicap(int playerID) {
		return reinterpret_cast<float(*)(int)>(0x883b20)(playerID);
	}

	void kbSetPlayerHandicap(int playerID, float handicap) {
		reinterpret_cast<void(*)(int, float)>(0x883b4b)(playerID, handicap);
	}

	bool kbIsGameOver() {
		return reinterpret_cast<bool(*)()>(0x883b73)();
	}

	vector kbGetTownLocation(vector result) {
		return reinterpret_cast<vector(*)(vector)>(0x883b86)(result);
	}

	int kbGetTownAreaID() {
		return reinterpret_cast<int(*)()>(0x883bf0)();
	}

	bool kbSetTownLocation(vector location) {
		return reinterpret_cast<bool(*)(vector)>(0x883c24)(location);
	}

	bool kbGetAutoBaseCreate() {
		return reinterpret_cast<bool(*)()>(0x883c5f)();
	}

	void kbSetAutoBaseCreate(bool v) {
		reinterpret_cast<void(*)(bool)>(0x883c92)(v);
	}

	float kbGetAutoBaseCreateDistance() {
		return reinterpret_cast<float(*)()>(0x883cc6)();
	}

	void kbSetAutoBaseCreateDistance(float v) {
		reinterpret_cast<void(*)(float)>(0x883cfd)(v);
	}

	bool kbGetAutoBaseDetect() {
		return reinterpret_cast<bool(*)()>(0x883d31)();
	}

	void kbSetAutoBaseDetect(bool v) {
		reinterpret_cast<void(*)(bool)>(0x883d64)(v);
	}

	float kbGetAutoBaseDetectDistance() {
		return reinterpret_cast<float(*)()>(0x883d98)();
	}

	void kbSetAutoBaseDetectDistance(float v) {
		reinterpret_cast<void(*)(float)>(0x883dcf)(v);
	}

	int kbFindClosestBase(int playerRelation, vector location) {
		return reinterpret_cast<int(*)(int, vector)>(0x883e03)(playerRelation, location);
	}

	int kbBaseGetNextID() {
		return reinterpret_cast<int(*)()>(0x883e53)();
	}

	int kbBaseGetNumber(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x883e86)(playerID);
	}

	int kbBaseGetIDByIndex(int playerID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x883ebf)(playerID, index);
	}

	int kbBaseCreate(int playerID, string name, vector position, float distance) {
		return reinterpret_cast<int(*)(int, string, vector, float)>(0x883f03)(playerID, name, position, distance);
	}

	int kbBaseFindCreateResourceBase(int resourceType, int resourceSubType, int parentBaseID) {
		return reinterpret_cast<int(*)(int, int, int)>(0x883f51)(resourceType, resourceSubType, parentBaseID);
	}

	int kbBaseFindForwardMilitaryBase(int a, int b, int c) {
		return reinterpret_cast<int(*)(int, int, int)>(0x883f9a)(a, b, c);
	}

	bool kbBaseDestroy(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x883fe3)(playerID, baseID);
	}

	void kbBaseDestroyAll(int playerID) {
		reinterpret_cast<void(*)(int)>(0x884021)(playerID);
	}

	vector kbBaseGetLocation(vector result, int playerID, int baseID) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x884057)(result, playerID, baseID);
	}

	vector kbBaseGetLastKnownDamageLocation(vector result, int a, int b) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x8840d2)(result, a, b);
	}

	int kbBaseGetOwner(int baseID) {
		return reinterpret_cast<int(*)(int)>(0x88539d)(baseID);
	}

	bool kbBaseSetFrontVector(int playerID, int baseID, vector frontVector) {
		return reinterpret_cast<bool(*)(int, int, vector)>(0x885446)(playerID, baseID, frontVector);
	}

	vector kbBaseGetFrontVector(vector result, int playerID, int baseID) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x88414f)(result, playerID, baseID);
	}

	vector kbBaseGetBackVector(vector result, int playerID, int baseID) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x8841ca)(result, playerID, baseID);
	}

	int kbBaseGetTimeUnderAttack(int playerID, int baseID) {
		return reinterpret_cast<int(*)(int, int)>(0x884245)(playerID, baseID);
	}

	bool kbBaseGetUnderAttack(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x885508)(playerID, baseID);
	}

	bool kbBaseSetActive(int playerID, int baseID, bool active) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x885560)(playerID, baseID, active);
	}

	bool kbBaseGetActive(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x8855b5)(playerID, baseID);
	}

	int kbBaseGetMainID(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x88429a)(playerID);
	}

	bool kbBaseSetMain(int playerID, int baseID, bool main) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x88560d)(playerID, baseID, main);
	}

	bool kbBaseGetMain(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x885662)(playerID, baseID);
	}

	bool kbBaseSetForward(int playerID, int baseID, bool forward) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x8856ba)(playerID, baseID, forward);
	}

	bool kbBaseGetForward(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x88570f)(playerID, baseID);
	}

	bool kbBaseSetSettlement(int playerID, int baseID, bool settlement) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x885767)(playerID, baseID, settlement);
	}

	bool kbBaseGetSettlement(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x8857bc)(playerID, baseID);
	}

	bool kbBaseSetMilitary(int playerID, int baseID, bool military) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x885814)(playerID, baseID, military);
	}

	bool kbBaseGetMilitary(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x885869)(playerID, baseID);
	}

	vector kbBaseGetMilitaryGatherPoint(vector result, int playerID, int baseID) {
		return reinterpret_cast<vector(*)(vector, int, int)>(0x8842d4)(result, playerID, baseID);
	}

	bool kbBaseSetMilitaryGatherPoint(int playerID, int baseID, vector gatherPoint) {
		return reinterpret_cast<bool(*)(int, int, vector)>(0x884351)(playerID, baseID, gatherPoint);
	}

	bool kbBaseSetEconomy(int playerID, int baseID, bool Economy) {
		return reinterpret_cast<bool(*)(int, int, bool)>(0x8858c1)(playerID, baseID, Economy);
	}

	bool kbBaseGetEconomy(int playerID, int baseID) {
		return reinterpret_cast<bool(*)(int, int)>(0x885916)(playerID, baseID);
	}

	float kbBaseGetMaximumResourceDistance(int playerID, int baseID) {
		return reinterpret_cast<float(*)(int, int)>(0x88439f)(playerID, baseID);
	}

	void kbBaseSetMaximumResourceDistance(int playerID, int baseID, float distance) {
		reinterpret_cast<void(*)(int, int, float)>(0x8843e9)(playerID, baseID, distance);
	}

	bool kbBaseAddUnit(int playerID, int baseID, int unitID) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x884430)(playerID, baseID, unitID);
	}

	bool kbBaseRemoveUnit(int playerID, int baseID, int unitID) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x884492)(playerID, baseID, unitID);
	}

	int kbBaseGetNumberUnits(int playerID, int baseID, int relation, int unitTypeID) {
		return reinterpret_cast<int(*)(int, int, int, int)>(0x8844f4)(playerID, baseID, relation, unitTypeID);
	}

	bool kbUnitVisible(int unitID) {
		return reinterpret_cast<bool(*)(int)>(0x88596e)(unitID);
	}

	bool kbLocationVisible(vector location) {
		return reinterpret_cast<bool(*)(vector)>(0x88454b)(location);
	}

	vector kbGetBlockPosition(vector result, string blockName) {
		return reinterpret_cast<vector(*)(vector, string)>(0x88457a)(result, blockName);
	}

	int kbGetBlockID(string blockName) {
		return reinterpret_cast<int(*)(string)>(0x8845d6)(blockName);
	}

	int kbGetRandomEnabledPUID(int unitTypeID, int escrowID) {
		return reinterpret_cast<int(*)(int, int)>(0x8845fb)(unitTypeID, escrowID);
	}

	int kbUnitPickCreate(string name) {
		return reinterpret_cast<int(*)(string)>(0x884748)(name);
	}

	bool kbUnitPickDestroy(int upID) {
		return reinterpret_cast<bool(*)(int)>(0x884787)(upID);
	}

	bool kbUnitPickResetAll(int upID) {
		return reinterpret_cast<bool(*)(int)>(0x88463a)(upID);
	}

	bool kbUnitPickResetResults(int upID) {
		return reinterpret_cast<bool(*)(int)>(0x88467e)(upID);
	}

	float kbUnitPickGetPreferenceWeight(int upID) {
		return reinterpret_cast<float(*)(int)>(0x8846c2)(upID);
	}

	bool kbUnitPickSetPreferenceWeight(int upID, float v) {
		return reinterpret_cast<bool(*)(int, float)>(0x884704)(upID, v);
	}

	bool kbUnitPickSetEnemyPlayerID(int upID, int playerID) {
		return reinterpret_cast<bool(*)(int, int)>(0x8847c0)(upID, playerID);
	}

	bool kbUnitPickSetCombatEfficiencyWeight(int upID, float a) {
		return reinterpret_cast<bool(*)(int, float)>(0x884804)(upID, a);
	}

	bool kbUnitPickResetCombatEfficiencyTypes(int upID) {
		return reinterpret_cast<bool(*)(int)>(0x884848)(upID);
	}

	bool kbUnitPickAddCombatEfficiencyType(int upID, int typeID, float weight) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x88488c)(upID, typeID, weight);
	}

	bool kbUnitPickSetCostWeight(int upID, float a) {
		return reinterpret_cast<bool(*)(int, float)>(0x8848da)(upID, a);
	}

	bool kbUnitPickSetMovementType(int upID, int movementType) {
		return reinterpret_cast<bool(*)(int, int)>(0x88491e)(upID, movementType);
	}

	bool kbUnitPickSetDesiredNumberUnitTypes(int upID, int number, int numberBuildings, bool degradeNumberBuildings) {
		return reinterpret_cast<bool(*)(int, int, int, bool)>(0x884962)(upID, number, numberBuildings, degradeNumberBuildings);
	}

	int kbUnitPickGetDesiredNumberUnitTypes(int upID) {
		return reinterpret_cast<int(*)(int)>(0x8849b5)(upID);
	}

	bool kbUnitPickSetDesiredNumberBuildings(int upID, int index, int numberBuildings) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x8849f4)(upID, index, numberBuildings);
	}

	int kbUnitPickGetDesiredNumberBuildings(int upID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x884a42)(upID, index);
	}

	bool kbUnitPickSetMinimumNumberUnits(int upID, int number) {
		return reinterpret_cast<bool(*)(int, int)>(0x884a8a)(upID, number);
	}

	int kbUnitPickGetMinimumNumberUnits(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884ace)(upID);
	}

	bool kbUnitPickSetMaximumNumberUnits(int upID, int number) {
		return reinterpret_cast<bool(*)(int, int)>(0x884b0d)(upID, number);
	}

	int kbUnitPickGetMaximumNumberUnits(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884b51)(upID);
	}

	bool kbUnitPickSetMinimumPop(int upID, int number) {
		return reinterpret_cast<bool(*)(int, int)>(0x884b90)(upID, number);
	}

	int kbUnitPickGetMinimumPop(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884bd4)(upID);
	}

	bool kbUnitPickSetMaximumPop(int upID, int number) {
		return reinterpret_cast<bool(*)(int, int)>(0x884c13)(upID, number);
	}

	int kbUnitPickGetMaximumPop(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884c57)(upID);
	}

	bool kbUnitPickSetAttackUnitType(int upID, int type) {
		return reinterpret_cast<bool(*)(int, int)>(0x884c96)(upID, type);
	}

	int kbUnitPickGetAttackUnitType(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884cdd)(upID);
	}

	bool kbUnitPickSetGoalCombatEfficiencyType(int upID, int type) {
		return reinterpret_cast<bool(*)(int, int)>(0x884d1f)(upID, type);
	}

	int kbUnitPickGetGoalCombatEfficiencyType(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884d66)(upID);
	}

	bool kbUnitPickSetPreferenceFactor(int upID, int unitTypeID, float preferenceFactor) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x884da8)(upID, unitTypeID, preferenceFactor);
	}

	bool kbUnitPickAdjustPreferenceFactor(int upID, int unitTypeID, float baseFactorAdjustment) {
		return reinterpret_cast<bool(*)(int, int, float)>(0x884df6)(upID, unitTypeID, baseFactorAdjustment);
	}

	int kbUnitPickRun(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884e44)(upID);
	}

	int kbUnitPickGetNumberResults(int upID) {
		return reinterpret_cast<int(*)(int)>(0x884e85)(upID);
	}

	int kbUnitPickGetResult(int upID, int index) {
		return reinterpret_cast<int(*)(int, int)>(0x884ec6)(upID, index);
	}

	int kbFindAreaGroup(int groupType, float surfaceAreaRatio, int compareAreaID) {
		return reinterpret_cast<int(*)(int, float, int)>(0x884f0d)(groupType, surfaceAreaRatio, compareAreaID);
	}

	int kbFindAreaGroupByLocation(int groupType, float relativeX, float relativeZ) {
		return reinterpret_cast<int(*)(int, float, float)>(0x884f5c)(groupType, relativeX, relativeZ);
	}

	int kbFindBestBuildingToRepair(vector position, float distance, float healthRatio, int repairUnderAttackUnitTypeID) {
		return reinterpret_cast<int(*)(vector, float, float, int)>(0x884fa0)(position, distance, healthRatio, repairUnderAttackUnitTypeID);
	}

	void kbSetForwardBasePosition(vector a) {
		reinterpret_cast<void(*)(vector)>(0x884fed)(a);
	}

	void kbSetTargetSelectorFactor(int type, float val) {
		reinterpret_cast<void(*)(int, float)>(0x885034)(type, val);
	}

	float kbGetTargetSelectorFactor(int type) {
		return reinterpret_cast<float(*)(int)>(0x88506f)(type);
	}

	string kbGetTechName(int techID) {
		return reinterpret_cast<string(*)(int)>(0x897a7d)(techID);
	}

	string kbGetProtoUnitName(int protoUnitTypeID) {
		return reinterpret_cast<string(*)(int)>(0x897804)(protoUnitTypeID);
	}

	int kbGetUnitBaseTypeID(int unitID) {
		return reinterpret_cast<int(*)(int)>(0x897a40)(unitID);
	}

	string kbGetUnitTypeName(int unitTypeID) {
		return reinterpret_cast<string(*)(int)>(0x897aaf)(unitTypeID);
	}

	int kbCreateUnitProgression(string unitName, string name) {
		return reinterpret_cast<int(*)(string, string)>(0x897823)(unitName, name);
	}

	int kbCreateTechProgression(string techName, string name) {
		return reinterpret_cast<int(*)(string, string)>(0x897ae1)(techName, name);
	}

	int kbTechTreeGetCheapestUnitUpgrade(int unitTypeID) {
		return reinterpret_cast<int(*)(int)>(0x897867)(unitTypeID);
	}

	int kbTechTreeGetCheapestEconUpgrade(int resourceUnitTypeID) {
		return reinterpret_cast<int(*)(int)>(0x8978a8)(resourceUnitTypeID);
	}

	void kbTechTreeDump() {
		reinterpret_cast<void(*)()>(0x8978e9)();
	}

	int kbProgressionGetTotalNodes(int progressionID) {
		return reinterpret_cast<int(*)(int)>(0x8926b6)(progressionID);
	}

	float kbProgessionGetTotalResourceCost(int progressionID, int resourceID) {
		return reinterpret_cast<float(*)(int, int)>(0x89253b)(progressionID, resourceID);
	}

	int kbProgressionGetNodeType(int progressionID, int nodeIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x892605)(progressionID, nodeIndex);
	}

	int kbProgressionGetNodeData(int progressionID, int nodeIndex) {
		return reinterpret_cast<int(*)(int, int)>(0x89265e)(progressionID, nodeIndex);
	}

	void trDelayedRuleActivation(string rulename) {
		reinterpret_cast<void(*)(string)>(0x97f4ea)(rulename);
	}

	int trTime() {
		return reinterpret_cast<int(*)()>(0x97f558)();
	}

	int trTimeMS() {
		return reinterpret_cast<int(*)()>(0x97f57c)();
	}

	void trUnitSelectClear() {
		reinterpret_cast<void(*)()>(0x982194)();
	}

	void trUnitSelect(string unitScenarioName) {
		reinterpret_cast<void(*)(string)>(0x97f601)(unitScenarioName);
	}

	void trUnitSelectByID(int unitID) {
		reinterpret_cast<void(*)(int)>(0x9821bb)(unitID);
	}

	bool trPlayerControlsSocket(int playerID, string objectScenarioName) {
		return reinterpret_cast<bool(*)(int, string)>(0x982203)(playerID, objectScenarioName);
	}

	bool trIsPlayerVisitingHC(int targetHCPlayerID) {
		return reinterpret_cast<bool(*)(int)>(0x97f636)(targetHCPlayerID);
	}

	bool trIsPlayerSelectingHCBuilding(string hcBuildingName) {
		return reinterpret_cast<bool(*)(string)>(0x97f687)(hcBuildingName);
	}

	bool trHasPlayerSentHCShipment(int targetHCPlayerID) {
		return reinterpret_cast<bool(*)(int)>(0x97f6f3)(targetHCPlayerID);
	}

	bool trIsPlayerSendingHCShipment(int targetHCPlayerID) {
		return reinterpret_cast<bool(*)(int)>(0x97f734)(targetHCPlayerID);
	}

	bool trObjectGettingWorked(string objectScenarioName) {
		return reinterpret_cast<bool(*)(string)>(0x982299)(objectScenarioName);
	}

	bool trUnitMoveToPoint(float x, float y, float z, int eventID, bool bAttackMove, bool bUnitRun, float runSpeedMultiplier) {
		return reinterpret_cast<bool(*)(float, float, float, int, bool, bool, float)>(0x98674c)(x, y, z, eventID, bAttackMove, bUnitRun, runSpeedMultiplier);
	}

	bool trUnitMoveToUnit(string unitScenarioName, int eventID, bool bAttackMove, bool bUnitRun, float runSpeedMultiplier) {
		return reinterpret_cast<bool(*)(string, int, bool, bool, float)>(0x986909)(unitScenarioName, eventID, bAttackMove, bUnitRun, runSpeedMultiplier);
	}

	void trSetRevealerActiveState(string revealerName, bool active) {
		reinterpret_cast<void(*)(string, bool)>(0x97f7df)(revealerName, active);
	}

	void trCreateRevealer(int playerID, string revealerName, vector position, float revealerLOS, bool blackmapOnly) {
		reinterpret_cast<void(*)(int, string, vector, float, bool)>(0x97f844)(playerID, revealerName, position, revealerLOS, blackmapOnly);
	}

	bool trUnitMoveFromArea(float x, float y, float z, int eventID, bool bAttackMove, int player, string unitType, float radius) {
		return reinterpret_cast<bool(*)(float, float, float, int, bool, int, string, float)>(0x987fd5)(x, y, z, eventID, bAttackMove, player, unitType, radius);
	}

	bool trUnitBuildUnit(string protoUnitName, vector BVector) {
		return reinterpret_cast<bool(*)(string, vector)>(0x986ac3)(protoUnitName, BVector);
	}

	bool trUnitDoWorkOnUnit(string unitScenarioName, int eventID) {
		return reinterpret_cast<bool(*)(string, int)>(0x986d85)(unitScenarioName, eventID);
	}

	void trShowDamage(string a, string b, string c, string d) {
		reinterpret_cast<void(*)(string, string, string, string)>(0x986f58)(a, b, c, d);
	}

	bool trUnitGarrison(string unitScenarioName, int eventID) {
		return reinterpret_cast<bool(*)(string, int)>(0x98750f)(unitScenarioName, eventID);
	}

	void trPlayerSetAge(int playerID, int age, bool displayEffect) {
		reinterpret_cast<void(*)(int, int, bool)>(0x97f8ba)(playerID, age, displayEffect);
	}

	void trPlayerSetHCAccess(int playerID, bool hcAccess) {
		reinterpret_cast<void(*)(int, bool)>(0x97f8eb)(playerID, hcAccess);
	}

	void trShowHCView(int playerID) {
		reinterpret_cast<void(*)(int)>(0x97f93c)(playerID);
	}

	void trShowWorldView(int playerID) {
		reinterpret_cast<void(*)(int)>(0x97f97d)(playerID);
	}

	bool trImmediateUnitGarrison(string unitScenarioName) {
		return reinterpret_cast<bool(*)(string)>(0x9876da)(unitScenarioName);
	}

	float trUnitDistanceToPoint(float x, float y, float z) {
		return reinterpret_cast<float(*)(float, float, float)>(0x9822cc)(x, y, z);
	}

	float trUnitDistanceToUnit(string unitScenarioName) {
		return reinterpret_cast<float(*)(string)>(0x982440)(unitScenarioName);
	}

	float trUnitDistanceToUnitID(int unitID) {
		return reinterpret_cast<float(*)(int)>(0x98246e)(unitID);
	}

	float trCountUnitsInArea(string a, int b, string c, float d) {
		return reinterpret_cast<float(*)(string, int, string, float)>(0x98832f)(a, b, c, d);
	}

	void trUnitCinematicRemoveControlAction() {
		reinterpret_cast<void(*)()>(0x9824b1)();
	}

	bool trUnitSetAnimation(string AnimName, int versionIndex, bool loop, int eventID, bool destroyOnNextControlAction) {
		return reinterpret_cast<bool(*)(string, int, bool, int, bool)>(0x98251a)(AnimName, versionIndex, loop, eventID, destroyOnNextControlAction);
	}

	bool trUnitAlive() {
		return reinterpret_cast<bool(*)()>(0x982651)();
	}

	bool trUnitDead() {
		return reinterpret_cast<bool(*)()>(0x9826df)();
	}

	bool trUnitDelete(bool remove) {
		return reinterpret_cast<bool(*)(bool)>(0x982771)(remove);
	}

	void trUnitDestroy() {
		reinterpret_cast<void(*)()>(0x98282f)();
	}

	bool trUnitCreate(string protoName, string scenarioName, float x, float y, float z, int heading, int playerID) {
		return reinterpret_cast<bool(*)(string, string, float, float, float, int, int)>(0x97f9b6)(protoName, scenarioName, x, y, z, heading, playerID);
	}

	int trUnitGetHeading(string scenarioName) {
		return reinterpret_cast<int(*)(string)>(0x97fb54)(scenarioName);
	}

	bool trUnitSetHeading(int degrees) {
		return reinterpret_cast<bool(*)(int)>(0x9828fc)(degrees);
	}

	int trUnitSetHP(float hitpoints) {
		return reinterpret_cast<int(*)(float)>(0x982a23)(hitpoints);
	}

	bool trUnitVisToPlayer() {
		return reinterpret_cast<bool(*)()>(0x982ae9)();
	}

	bool trUnitHasLOS(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x982ba5)(playerID);
	}

	void trUnitConvert(int playerID) {
		reinterpret_cast<void(*)(int)>(0x982c42)(playerID);
	}

	int trUnitPercentComplete() {
		return reinterpret_cast<int(*)()>(0x982cd1)();
	}

	int trUnitPercentDamaged() {
		return reinterpret_cast<int(*)()>(0x982d39)();
	}

	void trUnitTeleport(float a, float b, float c) {
		reinterpret_cast<void(*)(float, float, float)>(0x982da7)(a, b, c);
	}

	void trUnitHighlight(float seconds, bool a) {
		reinterpret_cast<void(*)(float, bool)>(0x982e9e)(seconds, a);
	}

	void trUnitChangeProtoUnit(string a) {
		reinterpret_cast<void(*)(string)>(0x982f9e)(a);
	}

	int trUnitGetContained() {
		return reinterpret_cast<int(*)()>(0x9831d8)();
	}

	bool trUnitGetIsContained(string protounit) {
		return reinterpret_cast<bool(*)(string)>(0x98320d)(protounit);
	}

	int trUnitEjectContained() {
		return reinterpret_cast<int(*)()>(0x98328c)();
	}

	bool trUnitIsSelected() {
		return reinterpret_cast<bool(*)()>(0x9832d1)();
	}

	bool trUnitTypeIsSelected(string a) {
		return reinterpret_cast<bool(*)(string)>(0x983333)(a);
	}

	bool trUnitIsOwnedBy(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x9833f2)(playerID);
	}

	void trUnitSetStance(string a) {
		reinterpret_cast<void(*)(string)>(0x983489)(a);
	}

	void trCameraCut(vector pos, vector dir, vector up, vector right) {
		reinterpret_cast<void(*)(vector, vector, vector, vector)>(0x97fbca)(pos, dir, up, right);
	}

	void trWaypointClear() {
		reinterpret_cast<void(*)()>(0x983598)();
	}

	void trWaypointAddPoint(vector a) {
		reinterpret_cast<void(*)(vector)>(0x97fc78)(a);
	}

	void trWaypointAddUnit(string unitScenarioName) {
		reinterpret_cast<void(*)(string)>(0x97fcb8)(unitScenarioName);
	}

	int trCurrentPlayer() {
		return reinterpret_cast<int(*)()>(0x96db85)();
	}

	void trSetCurrentPlayerStatus(bool active) {
		reinterpret_cast<void(*)(bool)>(0x97f5ca)(active);
	}

	void trSetUserControls(bool active) {
		reinterpret_cast<void(*)(bool)>(0x97f5e4)(active);
	}

	int trPlayerUnitCount(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x98081a)(playerID);
	}

	int trPlayerBuildingCount(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x980893)(playerID);
	}

	int trPlayerUnitAndBuildingCount(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x980782)(playerID);
	}

	int trPlayerUnitCountSpecific(int playerID, string protoName) {
		return reinterpret_cast<int(*)(int, string)>(0x9808e2)(playerID, protoName);
	}

	int trPlayerTribute(int from, string resource, int amount, int to) {
		return reinterpret_cast<int(*)(int, string, int, int)>(0x9884a5)(from, resource, amount, to);
	}

	void trPlayerToggleAllowTCSpawning(int playerID, bool allowSpawning) {
		reinterpret_cast<void(*)(int, bool)>(0x980969)(playerID, allowSpawning);
	}

	void trPlayerToggleAllowNewCWSpawning(int playerID, bool allowSpawning) {
		reinterpret_cast<void(*)(int, bool)>(0x98098c)(playerID, allowSpawning);
	}

	int trPlayerResourceCount(int playerID, string resource) {
		return reinterpret_cast<int(*)(int, string)>(0x988538)(playerID, resource);
	}

	int trPlayerCurrentXPCount(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x9809af)(playerID);
	}

	bool trPlayerDefeated(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x980a06)(playerID);
	}

	bool trPlayerActive(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x980a35)(playerID);
	}

	void trSetPlayerDefeated(int a) {
		reinterpret_cast<void(*)(int)>(0x980a63)(a);
	}

	void trSetPlayerWon(int a) {
		reinterpret_cast<void(*)(int)>(0x9843ff)(a);
	}

	void trEndGame() {
		reinterpret_cast<void(*)()>(0x980a86)();
	}

	void trPlayerSetDiplomacy(int playerID, int player2ID, string status) {
		reinterpret_cast<void(*)(int, int, string)>(0x980a94)(playerID, player2ID, status);
	}

	string trPlayerGetDiplomacy(int playerID, int player2ID) {
		return reinterpret_cast<string(*)(int, int)>(0x980b55)(playerID, player2ID);
	}

	void trPlayerModifyLOS(int a, bool b, int c) {
		reinterpret_cast<void(*)(int, bool, int)>(0x984488)(a, b, c);
	}

	int trPlayerCountBuildingInProgress(int playerID, string protoname) {
		return reinterpret_cast<int(*)(int, string)>(0x980ba2)(playerID, protoname);
	}

	bool trBuildingIsOnCursor(string protoname) {
		return reinterpret_cast<bool(*)(string)>(0x9885ce)(protoname);
	}

	int trPlayerSetActive(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x9844cc)(playerID);
	}

	void trObjectiveComplete(int objectiveID, bool forceComplete, bool playSound) {
		reinterpret_cast<void(*)(int, bool, bool)>(0x980bf8)(objectiveID, forceComplete, playSound);
	}

	void trObjectiveHide(int objectiveID) {
		reinterpret_cast<void(*)(int)>(0x980c55)(objectiveID);
	}

	void trObjectiveShow(int objectiveID) {
		reinterpret_cast<void(*)(int)>(0x980c83)(objectiveID);
	}

	void trObjectiveDiscover(int objectiveID, bool playSound) {
		reinterpret_cast<void(*)(int, bool)>(0x980cb1)(objectiveID, playSound);
	}

	bool trPlayerAtPopCap(int playerID) {
		return reinterpret_cast<bool(*)(int)>(0x980ce4)(playerID);
	}

	int trPlayerGetPopulation(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x980d2c)(playerID);
	}

	void trSetCinematicUnitSpeaking(string objectScenarioName, bool speaking, int duration) {
		reinterpret_cast<void(*)(string, bool, int)>(0x97f775)(objectScenarioName, speaking, duration);
	}

	bool trEventSetHandler(int eventID, string handler) {
		return reinterpret_cast<bool(*)(int, string)>(0x97fced)(eventID, handler);
	}

	void trEventFire(int eventID) {
		reinterpret_cast<void(*)(int)>(0x97fd19)(eventID);
	}

	void trSetUnitIdleProcessing(bool a) {
		reinterpret_cast<void(*)(bool)>(0x97f596)(a);
	}

	void trSetObscuredUnits(bool a) {
		reinterpret_cast<void(*)(bool)>(0x97f5b0)(a);
	}

	void trLetterBox(bool onOff) {
		reinterpret_cast<void(*)(bool)>(0x97fda3)(onOff);
	}

	void trSoundPlayFN(string filename, string a, int b, string c, string d) {
		reinterpret_cast<void(*)(string, string, int, string, string)>(0x9835bf)(filename, a, b, c, d);
	}

	void trSoundPlayPaused(string filename, string a, int b, string c, string d) {
		reinterpret_cast<void(*)(string, string, int, string, string)>(0x9836bd)(filename, a, b, c, d);
	}

	void trSoundTimer(int a, int b) {
		reinterpret_cast<void(*)(int, int)>(0x9837bb)(a, b);
	}

	void trFadeOutMusic(float duration) {
		reinterpret_cast<void(*)(float)>(0x97fe22)(duration);
	}

	void trPlayNextMusicTrack() {
		reinterpret_cast<void(*)()>(0x97fe42)();
	}

	void trFadeOutAllSounds(float duration) {
		reinterpret_cast<void(*)(float)>(0x97fe62)(duration);
	}

	void trBlockAllSounds(bool excludeDialog) {
		reinterpret_cast<void(*)(bool)>(0x97fe99)(excludeDialog);
	}

	void trUnblockAllSounds() {
		reinterpret_cast<void(*)()>(0x97fec8)();
	}

	void trBlockAllAmbientSounds() {
		reinterpret_cast<void(*)()>(0x97fee7)();
	}

	void trUnBlockAllAmbientSounds() {
		reinterpret_cast<void(*)()>(0x97ff09)();
	}

	void trSoundPlayDialog(string filename, string event, int ignoreOnAbort, bool subtitle, string portrait, string a) {
		reinterpret_cast<void(*)(string, string, int, bool, string, string)>(0x98395c)(filename, event, ignoreOnAbort, subtitle, portrait, a);
	}

	void trSoundPlayDialogue(string stringID, int eventID, bool ignoreOnAbort, int seconds) {
		reinterpret_cast<void(*)(string, int, bool, int)>(0x983a5a)(stringID, eventID, ignoreOnAbort, seconds);
	}

	void trMusicPlay(string filename, string duration, float a) {
		reinterpret_cast<void(*)(string, string, float)>(0x983877)(filename, duration, a);
	}

	void trMusicPlayCurrent() {
		reinterpret_cast<void(*)()>(0x97ff2b)();
	}

	void trMusicStop() {
		reinterpret_cast<void(*)()>(0x97ff4d)();
	}

	void trMusicSetCurrentMusicSet(int a) {
		reinterpret_cast<void(*)(int)>(0x97ff68)(a);
	}

	void trMusicSetMood(int moodID) {
		reinterpret_cast<void(*)(int)>(0x97ff94)(moodID);
	}

	void trCamTrackLoad(string filename) {
		reinterpret_cast<void(*)(string)>(0x97ffb7)(filename);
	}

	void trCamTrackPlay(float duration, int eventID) {
		reinterpret_cast<void(*)(float, int)>(0x983f5b)(duration, eventID);
	}

	void trMessageSetText(string text, int timeout) {
		reinterpret_cast<void(*)(string, int)>(0x983fcd)(text, timeout);
	}

	void trChatSetStatus(bool onOff) {
		reinterpret_cast<void(*)(bool)>(0x97ffce)(onOff);
	}

	void trChatSend(int fromID, string message) {
		reinterpret_cast<void(*)(int, string)>(0x984019)(fromID, message);
	}

	void trChatSendToPlayer(int fromID, int toID, string message) {
		reinterpret_cast<void(*)(int, int, string)>(0x98405e)(fromID, toID, message);
	}

	void trChatSendSpoofed(int fromID, string message) {
		reinterpret_cast<void(*)(int, string)>(0x9840b3)(fromID, message);
	}

	void trChatSendSpoofedToPlayer(int fromID, int toID, string message) {
		reinterpret_cast<void(*)(int, int, string)>(0x98419d)(fromID, toID, message);
	}

	void trWriteToLog(string message) {
		reinterpret_cast<void(*)(string)>(0x97ffdf)(message);
	}

	void trGamePause(bool pause) {
		reinterpret_cast<void(*)(bool)>(0x97fff8)(pause);
	}

	void trGameLoadScenario(string scenario) {
		reinterpret_cast<void(*)(string)>(0x980016)(scenario);
	}

	void trBranchScenario(string a) {
		reinterpret_cast<void(*)(string)>(0x984289)(a);
	}

	bool trTechStatusActive(int playerID, int techID) {
		return reinterpret_cast<bool(*)(int, int)>(0x98005c)(playerID, techID);
	}

	bool trTechStatusResearching(int playerID, int techID) {
		return reinterpret_cast<bool(*)(int, int)>(0x98008f)(playerID, techID);
	}

	bool trTechStatusCheck(int playerID, int techID, int techStatus) {
		return reinterpret_cast<bool(*)(int, int, int)>(0x9800c2)(playerID, techID, techStatus);
	}

	void trTechSetStatus(int playerID, int techID, int status) {
		reinterpret_cast<void(*)(int, int, int)>(0x980124)(playerID, techID, status);
	}

	void trYouWin(bool directToMenu) {
		reinterpret_cast<void(*)(bool)>(0x980180)(directToMenu);
	}

	void trYouLose(string text) {
		reinterpret_cast<void(*)(string)>(0x98434c)(text);
	}

	void trShowWinLose(string text, string soundfile, string a, bool b) {
		reinterpret_cast<void(*)(string, string, string, bool)>(0x9843a2)(text, soundfile, a, b);
	}

	void trRenderSky(bool render, string skyName) {
		reinterpret_cast<void(*)(bool, string)>(0x980653)(render, skyName);
	}

	void trRenderSnow(float percent) {
		reinterpret_cast<void(*)(float)>(0x98068c)(percent);
	}

	void trRenderRain(float percent) {
		reinterpret_cast<void(*)(float)>(0x9806ed)(percent);
	}

	void trSetFogAndBlackmap(bool fog, bool blackMap) {
		reinterpret_cast<void(*)(bool, bool)>(0x98074e)(fog, blackMap);
	}

	void trStartGameRecord(string a) {
		reinterpret_cast<void(*)(string)>(0x980db3)(a);
	}

	void trStopGameRecord() {
		reinterpret_cast<void(*)()>(0x980dec)();
	}

	void trArmySelect(string army) {
		reinterpret_cast<void(*)(string)>(0x980dfb)(army);
	}

	void trArmySelectInt(int playerID, int armyID) {
		reinterpret_cast<void(*)(int, int)>(0x980e4a)(playerID, armyID);
	}

	bool trArmyDispatch(string parameters, string a, int b, float c, float d, float e, int f, bool g) {
		return reinterpret_cast<bool(*)(string, string, int, float, float, float, int, bool)>(0x980e73)(parameters, a, b, c, d, e, f, g);
	}

	void trSetLighting(string setname, float fadetime) {
		reinterpret_cast<void(*)(string, float)>(0x981040)(setname, fadetime);
	}

	void trCounterAddTime(string name, int start, int stop, string message, int event) {
		reinterpret_cast<void(*)(string, int, int, string, int)>(0x981f80)(name, start, stop, message, event);
	}

	void trCounterAddTimeMs(string name, int start, int stop, string message, int event) {
		reinterpret_cast<void(*)(string, int, int, string, int)>(0x9820b4)(name, start, stop, message, event);
	}

	void trCounterAddUnit(string name, int playerid, int count, string protounit, string message, int event) {
		reinterpret_cast<void(*)(string, int, int, string, string, int)>(0x986462)(name, playerid, count, protounit, message, event);
	}

	void trCounterAddXP(string a, int b, int c, string d, int e) {
		reinterpret_cast<void(*)(string, int, int, string, int)>(0x9865ee)(a, b, c, d, e);
	}

	void trCounterAbort(string name) {
		reinterpret_cast<void(*)(string)>(0x97f436)(name);
	}

	bool trCinematicAbort() {
		return reinterpret_cast<bool(*)()>(0x981088)();
	}

	void trCinematicDoAbort() {
		reinterpret_cast<void(*)()>(0x9810a1)();
	}

	void trForceNonCinematicModels(bool a) {
		reinterpret_cast<void(*)(bool)>(0x97fd67)(a);
	}

	void trFormationScale(float scale) {
		reinterpret_cast<void(*)(float)>(0x97fd85)(scale);
	}

	int trGetNumberNuggetsGathered(int a) {
		return reinterpret_cast<int(*)(int)>(0x98159a)(a);
	}

	bool trHasNuggetBeenCollected(string a, int b) {
		return reinterpret_cast<bool(*)(string, int)>(0x9815c1)(a, b);
	}

	void trUIFlash(string gadget, int name, float flashLimit, float colorR, float colorG) {
		reinterpret_cast<void(*)(string, int, float, float, float)>(0x9856f8)(gadget, name, flashLimit, colorR, colorG);
	}

	void trUIStopFlash(string gadget) {
		reinterpret_cast<void(*)(string)>(0x9858c6)(gadget);
	}

	void trUIFlashTech(int a, bool b) {
		reinterpret_cast<void(*)(int, bool)>(0x981527)(a, b);
	}

	void trUIFlashTrain(string a, bool b) {
		reinterpret_cast<void(*)(string, bool)>(0x981550)(a, b);
	}

	void trUIFadeToColor(int r, int g, int b, int duration, int delay, bool inout, int a) {
		reinterpret_cast<void(*)(int, int, int, int, int, bool, int)>(0x9810fb)(r, g, b, duration, delay, inout, a);
	}

	void trRateConstruction(float rate) {
		reinterpret_cast<void(*)(float)>(0x9811dd)(rate);
	}

	void trRateTrain(float rate) {
		reinterpret_cast<void(*)(float)>(0x981228)(rate);
	}

	void trRateResearch(float rate) {
		reinterpret_cast<void(*)(float)>(0x981273)(rate);
	}

	void trRatesNormal() {
		reinterpret_cast<void(*)()>(0x9812be)();
	}

	void trMinimapFlare(int playerID, float duration, vector position, bool flash) {
		reinterpret_cast<void(*)(int, float, vector, bool)>(0x9812eb)(playerID, duration, position, flash);
	}

	void trCameraShake(float duration, float strength) {
		reinterpret_cast<void(*)(float, float)>(0x98136f)(duration, strength);
	}

	void trPlayerResetBlackMap(int playerID) {
		reinterpret_cast<void(*)(int)>(0x980d57)(playerID);
	}

	void trPlayerResetBlackMapForAllPlayers() {
		reinterpret_cast<void(*)()>(0x9844f9)();
	}

	void trPlayerKillAllUnits(int a) {
		reinterpret_cast<void(*)(int)>(0x9878a6)(a);
	}

	void trPlayerKillAllBuildings(int a) {
		reinterpret_cast<void(*)(int)>(0x9879a4)(a);
	}

	bool trIsGadgetVisible(string name) {
		return reinterpret_cast<bool(*)(string)>(0x981631)(name);
	}

	void trModeEnter(string name) {
		reinterpret_cast<void(*)(string)>(0x981677)(name);
	}

	void trPlayerGrantResources(int player, string resource, int amount) {
		reinterpret_cast<void(*)(int, string, int)>(0x988669)(player, resource, amount);
	}

	void trUnitPlayerFakify(int fakePlayerIndex) {
		reinterpret_cast<void(*)(int)>(0x984589)(fakePlayerIndex);
	}

	void trArmyPlayerFakify(string armyname, int fakeplayerindex) {
		reinterpret_cast<void(*)(string, int)>(0x984612)(armyname, fakeplayerindex);
	}

	void trUnitPlayerDefakify() {
		reinterpret_cast<void(*)()>(0x9846e6)();
	}

	void trArmyPlayerDefakify(string armyname) {
		reinterpret_cast<void(*)(string)>(0x98475e)(armyname);
	}

	void trAIFunc(int playerID, string functionName, int param) {
		reinterpret_cast<void(*)(int, string, int)>(0x9813c1)(playerID, functionName, param);
	}

	int trGetNumberSelectedUnitIDs() {
		return reinterpret_cast<int(*)()>(0x98452c)();
	}

	int trGetSelectedUnitID(int a) {
		return reinterpret_cast<int(*)(int)>(0x98454c)(a);
	}

	bool trUnforbidProtounit(int player, string protoname) {
		return reinterpret_cast<bool(*)(int, string)>(0x98169f)(player, protoname);
	}

	bool trForbidProtounit(int player, string protoname) {
		return reinterpret_cast<bool(*)(int, string)>(0x981740)(player, protoname);
	}

	void trSetPauseOnAgeUpgrade(bool a) {
		reinterpret_cast<void(*)(bool)>(0x981afc)(a);
	}

	void trSetPauseInObjectiveWindow(bool a) {
		reinterpret_cast<void(*)(bool)>(0x981b1a)(a);
	}

	void trSetCounterDisplay(string a) {
		reinterpret_cast<void(*)(string)>(0x9859c3)(a);
	}

	void trClearCounterDisplay() {
		reinterpret_cast<void(*)()>(0x981b38)();
	}

	void trPlayMovie(string a) {
		reinterpret_cast<void(*)(string)>(0x981b84)(a);
	}

	bool trIsMovieNotPlaying() {
		return reinterpret_cast<bool(*)()>(0x981b6f)();
	}

	void trRevealEntireMap() {
		reinterpret_cast<void(*)()>(0x981b98)();
	}

	void trUnitChangeName(string name) {
		reinterpret_cast<void(*)(string)>(0x985a8f)(name);
	}

	bool trChatHistoryContains(string text, int a) {
		return reinterpret_cast<bool(*)(string, int)>(0x985bcc)(text, a);
	}

	void trChatHistoryClear() {
		reinterpret_cast<void(*)()>(0x981bc1)();
	}

	int trGetStatValue(int player, int stat) {
		return reinterpret_cast<int(*)(int, int)>(0x985c47)(player, stat);
	}

	void trEchoStatValue(int player, int stat) {
		reinterpret_cast<void(*)(int, int)>(0x985e08)(player, stat);
	}

	void trShowImageDialog(string texture, string subtitle) {
		reinterpret_cast<void(*)(string, string)>(0x985e8d)(texture, subtitle);
	}

	void trShowChoiceDialog(string maintext, string choice1, int event1, string choice2, int event2) {
		reinterpret_cast<void(*)(string, string, int, string, int)>(0x985ece)(maintext, choice1, event1, choice2, event2);
	}

	void trModifyProtounit(string unit, int player, int field, float delta) {
		reinterpret_cast<void(*)(string, int, int, float)>(0x985f6a)(unit, player, field, delta);
	}

	void trDamageUnitPercent(float percent) {
		reinterpret_cast<void(*)(float)>(0x98605a)(percent);
	}

	void trDamageUnit(float amt) {
		reinterpret_cast<void(*)(float)>(0x98618b)(amt);
	}

	void trDamageUnitsInArea(int player, string unitType, float dist, float damage) {
		reinterpret_cast<void(*)(int, string, float, float)>(0x988937)(player, unitType, dist, damage);
	}

	void trOverlayText(string message, float time, int x, int y, int width, string background) {
		reinterpret_cast<void(*)(string, float, int, int, int, string)>(0x98629a)(message, time, x, y, width, background);
	}

	void trQuestVarSet(string varname, float value) {
		reinterpret_cast<void(*)(string, float)>(0x9817ef)(varname, value);
	}

	void trQuestVarCopy(string var1, string var2) {
		reinterpret_cast<void(*)(string, string)>(0x98186a)(var1, var2);
	}

	void trQuestVarSetFromRand(string varname, float minval, float maxval, bool round) {
		reinterpret_cast<void(*)(string, float, float, bool)>(0x981946)(varname, minval, maxval, round);
	}

	float trQuestVarGet(string varname) {
		return reinterpret_cast<float(*)(string)>(0x981a06)(varname);
	}

	void trQuestVarEcho(string varname) {
		reinterpret_cast<void(*)(string)>(0x981a77)(varname);
	}

	void trGrantVP(int player, int number) {
		reinterpret_cast<void(*)(int, int)>(0x981bdb)(player, number);
	}

	int trPlayerVPCount(int playerID) {
		return reinterpret_cast<int(*)(int)>(0x981cc3)(playerID);
	}

	void trVPAnnualAwards(bool enable) {
		reinterpret_cast<void(*)(bool)>(0x981d08)(enable);
	}

	void trCreateTreaty(int a, int b, int c, bool d, bool e, float f, float g, float h) {
		reinterpret_cast<void(*)(int, int, int, bool, bool, float, float, float)>(0x981d2c)(a, b, c, d, e, f, g, h);
	}

	int vcGetGameplayMode() {
		return reinterpret_cast<int(*)()>(0x981688)();
	}

	bool vcCheckConquestVictory() {
		return reinterpret_cast<bool(*)()>(0x987c2a)();
	}

	bool trUnitFaceUnit(string unitScenarioName, int eventID) {
		return reinterpret_cast<bool(*)(string, int)>(0x984819)(unitScenarioName, eventID);
	}

	void trCameraLockOnUnit(bool enable, int time, int to) {
		reinterpret_cast<void(*)(bool, int, int)>(0x984943)(enable, time, to);
	}

	void trCameraPanWithUnit(bool enable, int trigger) {
		reinterpret_cast<void(*)(bool, int)>(0x984997)(enable, trigger);
	}

	void trDisableTrigger(int eventID) {
		reinterpret_cast<void(*)(int)>(0x98140f)(eventID);
	}

	void trUnitMakeInvulnerable(bool enable) {
		reinterpret_cast<void(*)(bool)>(0x9849e5)(enable);
	}

	void trUnitSuspendAction(string actionName, bool suspend) {
		reinterpret_cast<void(*)(string, bool)>(0x984a71)(actionName, suspend);
	}

	void trCreateDefendPlan(string armyName, string defendPlanName, float defendX, float defendY, float defendZ, float engageRange, int evaluationFrequency, float gatherdistance) {
		reinterpret_cast<void(*)(string, string, float, float, float, float, int, float)>(0x984b77)(armyName, defendPlanName, defendX, defendY, defendZ, engageRange, evaluationFrequency, gatherdistance);
	}

	void trCreateAttackPlan(string armyName, string PlanName, int attackPlayerID, float attackX, float attackY, float attackZ, float engageRange, int evaluationFrequency) {
		reinterpret_cast<void(*)(string, string, int, float, float, float, float, int)>(0x984d45)(armyName, PlanName, attackPlayerID, attackX, attackY, attackZ, engageRange, evaluationFrequency);
	}

	void trKillAIPlan(int playerID, string planName) {
		reinterpret_cast<void(*)(int, string)>(0x9814d2)(playerID, planName);
	}

	void trAddArmyToPlan(string armyname, string planname) {
		reinterpret_cast<void(*)(string, string)>(0x984f2a)(armyname, planname);
	}

	void trDefendUnits(string srcArmyname, string defendedArmyname, string planname, int evaluationFrequency, float gatherdistance) {
		reinterpret_cast<void(*)(string, string, string, int, float)>(0x985038)(srcArmyname, defendedArmyname, planname, evaluationFrequency, gatherdistance);
	}

	void trAttackUnits(string srcArmyname, string armyToAttack, string planname) {
		reinterpret_cast<void(*)(string, string, string)>(0x985260)(srcArmyname, armyToAttack, planname);
	}

	void trAICommsAttackUnits(int playerID, string armyToAttack) {
		reinterpret_cast<void(*)(int, string)>(0x987aa1)(playerID, armyToAttack);
	}

	void trAICommsDefendPoint(int playerID, float defendX, float defendY, float defendZ) {
		reinterpret_cast<void(*)(int, float, float, float)>(0x985475)(playerID, defendX, defendY, defendZ);
	}

	void trAICommsRequestTribute(int fromPlayerID, string resource, float amount) {
		reinterpret_cast<void(*)(int, string, float)>(0x9886c0)(fromPlayerID, resource, amount);
	}

	void trAICommsCancelOrder(int sendToPlayerID) {
		reinterpret_cast<void(*)(int)>(0x98555a)(sendToPlayerID);
	}

	void trAICommsClaim(int sendToPlayerID, float a, float b, float c) {
		reinterpret_cast<void(*)(int, float, float, float)>(0x98561b)(sendToPlayerID, a, b, c);
	}

	void trAICommsTrain(int sendToPlayerID, string unitTypeName) {
		reinterpret_cast<void(*)(int, string)>(0x988823)(sendToPlayerID, unitTypeName);
	}

	void trTradeRouteSetPosition(int position, float a) {
		reinterpret_cast<void(*)(int, float)>(0x981def)(position, a);
	}

	void trTradeRouteToggleState(int position, bool a) {
		reinterpret_cast<void(*)(int, bool)>(0x981e2f)(position, a);
	}

	void trTradeRouteSetLevel(int traderouteindex, int level) {
		reinterpret_cast<void(*)(int, int)>(0x988ba4)(traderouteindex, level);
	}

	void trSetShadowFarClip(bool enable, float distance) {
		reinterpret_cast<void(*)(bool, float)>(0x981e75)(enable, distance);
	}

	void trShowSPCNote(string Title, string Text) {
		reinterpret_cast<void(*)(string, string)>(0x986375)(Title, Text);
	}

	void trPlayerOverrideArtCulture(int playerID, string culture) {
		reinterpret_cast<void(*)(int, string)>(0x9863da)(playerID, culture);
	}

	void trPlayerOverrideSoundCiv(int playerID, string civilization) {
		reinterpret_cast<void(*)(int, string)>(0x981e9d)(playerID, civilization);
	}

#endif

	const int cUnitStanceAggressive = 0;
	const int cUnitStanceDefensive = 1;
	const int cUnitStancePassive = 2;
	const int cUnitStanceStandGround = 3;
	const int cGameModeSupremacy = 0;
	const int cGameModeConquest = 2;
	const int cGameModeLightning = 3;
	const int cGameModeDeathmatch = 1;
	const int cDifficultySandbox = 0;
	const int cDifficultyEasy = 1;
	const int cDifficultyModerate = 2;
	const int cDifficultyHard = 3;
	const int cDifficultyExpert = 4;
	const int cAge1 = 0;
	const int cAge2 = 1;
	const int cAge3 = 2;
	const int cAge4 = 3;
	const int cAge5 = 4;
	const int cPlayerRelationAny = 99999;
	const int cPlayerRelationSelf = 100000;
	const int cPlayerRelationEnemy = 100002;
	const int cPlayerRelationAlly = 100001;
	const int cPlayerRelationEnemyNotGaia = 100004;
	const int cHCCardTypeEcon = 0;
	const int cHCCardTypeMilitary = 1;
	const int cHCCardTypeWagon = 2;
	const int cHCCardTypeTeam = 3;
	const int cRGPScript = 0;
	const int cRGPCost = 1;
	const int cRGPActual = 2;
	const int cNuggetTypeAdjustResource = 1;
	const int cNuggetTypeSpawnUnit = 2;
	const int cNuggetTypeGiveLOS = 3;
	const int cNuggetTypeAdjustSpeed = 4;
	const int cNuggetTypeAdjustHP = 5;
	const int cNuggetTypeConvertUnit = 6;
	const int cNuggetTypeGiveTech = 7;
	const int cAIResourceSubTypeEasy = 0;
	const int cAIResourceSubTypeHerdable = 1;
	const int cAIResourceSubTypeHunt = 2;
	const int cAIResourceSubTypeHuntAggressive = 3;
	const int cAIResourceSubTypeFarm = 4;
	const int cAIResourceSubTypeFish = 5;
	const int cAIResourceSubTypeTrade = 6;
	const int cMaxSettlersPerMine = 20;
	const int cMaxSettlersPerMill = 10;
	const int cTSFactorDistance = 0;
	const int cTSFactorPoint = 1;
	const int cTSFactorTimeToDone = 2;
	const int cTSFactorBase = 3;
	const int cTSFactorDanger = 4;
	const int cRootEscrowID = 0;
	const int cEconomyEscrowID = 1;
	const int cMilitaryEscrowID = 2;
	const int cEmergencyEscrowID = -2;
	const int cPlanMove = 0;
	const int cPlanAttack = 1;
	const int cPlanBuild = 2;
	const int cPlanTrain = 3;
	const int cPlanResearch = 4;
	const int cPlanWork = 5;
	const int cPlanGather = 6;
	const int cPlanExplore = 7;
	const int cPlanData = 8;
	const int cPlanProgression = 9;
	const int cPlanFarm = 10;
	const int cPlanHunt = 11;
	const int cPlanHuntAggressive = 12;
	const int cPlanFish = 13;
	const int cPlanHerd = 14;
	const int cPlanTransport = 15;
	const int cPlanAttackStrategy = 16;
	const int cPlanRemoved1 = 17;
	const int cPlanDefend = 18;
	const int cPlanReserve = 19;
	const int cPlanGoal = 20;
	const int cPlanGatherGoal = 21;
	const int cPlanTrade = 22;
	const int cPlanGatherNuggets = 23;
	const int cPlanMission = 24;
	const int cPlanBuildWall = 25;
	const int cPlanTownBell = 26;
	const int cPlanTower = 27;
	const int cPlanNativeResearch = 28;
	const int cOpportunitySourceAutoGenerated = 0;
	const int cOpportunitySourceAllyRequest = 1;
	const int cOpportunitySourceTrigger = 2;
	const int cOpportunityTypeDestroy = 0;
	const int cOpportunityTypeClaim = 1;
	const int cOpportunityTypeRaid = 2;
	const int cOpportunityTypeDefend = 3;
	const int cOpportunityTypeRescueExplorer = 4;
	const int cOpportunityTargetTypeBase = 0;
	const int cOpportunityTargetTypeVPSite = 1;
	const int cOpportunityTargetTypeResource = 2;
	const int cOpportunityTargetTypePointRadius = 3;
	const int cOpportunityTargetTypeUnitList = 4;
	const int cMissionTypeNone = -1;
	const int cMissionTypeAttack = 0;
	const int cMissionTypeDefend = 1;
	const int cMissionTypeClaim = 2;
	const int cMissionTypeRaid = 3;
	const int cPlanStateNone = 0;
	const int cPlanStateDone = 1;
	const int cPlanStateFailed = 2;
	const int cPlanStateBuild = 3;
	const int cPlanStateGather = 4;
	const int cPlanStatePlace = 5;
	const int cPlanStateExplore = 6;
	const int cPlanStateTrain = 7;
	const int cPlanStateResearch = 8;
	const int cPlanStateAttack = 9;
	const int cPlanStateGoto = 10;
	const int cPlanStateEmpower = 11;
	const int cPlanStateEnter = 12;
	const int cPlanStateExit = 13;
	const int cPlanStateEvaluate = 14;
	const int cPlanStatePatrol = 15;
	const int cPlanStateRetreat = 16;
	const int cPlanStateWorking = 17;
	const int cPlanStateTransport = 18;
	const int cPlanStateDualPlace = 19;
	const int cPlanStateWait = 20;
	const int cPlanStateCast = 21;
	const int cPlanStateVillagerAttack = 22;
	const int cPlanStateClaimNugget = 23;
	const int cPlanStateGatherResources = 24;
	const int cPlanStateIdle = 25;
	const int cPlanEventDone = 0;
	const int cPlanEventFailed = 1;
	const int cPlanEventPoll = 2;
	const int cPlanEventIdle = 3;
	const int cPlanEventStateChange = 4;
	const int cGatherPlanKBResourceID = 0;
	const int cGatherPlanResourceID = 1;
	const int cGatherPlanResourceType = 2;
	const int cGatherPlanResourceSubType = 3;
	const int cGatherPlanBreakDownID = 4;
	const int cGatherPlanResourceUnitTypeFilter = 5;
	const int cGatherPlanFindNewResourceTimeOut = 6;
	const int cBuildPlanBuildingPlacementID = 0;
	const int cBuildPlanBuildingTypeID = 1;
	const int cBuildPlanInfluenceUnitTypeID = 2;
	const int cBuildPlanInfluenceUnitDistance = 3;
	const int cBuildPlanInfluenceUnitValue = 4;
	const int cBuildPlanInfluenceUnitFalloff = 5;
	const int cBuildPlanAreaID = 6;
	const int cBuildPlanCenterPosition = 7;
	const int cBuildPlanCenterPositionDistance = 8;
	const int cBuildPlanVPSiteID = 9;
	const int cBuildPlanSocketID = 10;
	const int cBuildPlanBuildUnitID = 11;
	const int cBuildPlanFoundationID = 12;
	const int cBuildPlanInfluencePosition = 13;
	const int cBuildPlanInfluencePositionDistance = 14;
	const int cBuildPlanInfluencePositionValue = 15;
	const int cBuildPlanInfluencePositionFalloff = 16;
	const int cBuildPlanDockPlacementPoint = 17;
	const int cBuildPlanNumAreaBorderLayers = 18;
	const int cBuildPlanBuildingBufferSpace = 19;
	const int cBuildPlanFailOnUnaffordable = 20;
	const int cBuildPlanInfluenceKBResourceID = 21;
	const int cBuildPlanRandomBPValue = 22;
	const int cBuildPlanInfluenceAtBuilderPosition = 23;
	const int cBuildPlanInfluenceBuilderPositionValue = 24;
	const int cBuildPlanInfluenceBuilderPositionDistance = 25;
	const int cBuildPlanInfluenceBuilderPositionFalloff = 26;
	const int cBuildPlanRetries = 27;
	const int cBuildPlanMaxRetries = 28;
	const int cBuildPlanPendingCommands = 29;
	const int cBuildPlanFailureCause = 30;
	const int cBuildPlanFailureCauseFloat = 31;
	const int cBuildPlanMaxCanPaths = 32;
	const int cBuildPlanCanPathStartIndex = 33;
	const int cBuildPlanInfluenceVPSiteType = 34;
	const int cBuildPlanInfluenceVPSiteTypeValue = 35;
	const int cBuildPlanInfluenceVPSiteTypeDistance = 36;
	const int cBuildPlanInfluenceVPSiteTypeFalloff = 37;
	const int cTrainPlanBuildingID = 0;
	const int cTrainPlanIntoArmyID = 1;
	const int cTrainPlanIntoPlanID = 2;
	const int cTrainPlanIntoBaseID = 3;
	const int cTrainPlanNumberToTrain = 4;
	const int cTrainPlanNumberToMaintain = 5;
	const int cTrainPlanNumberTrained = 6;
	const int cTrainPlanUnitType = 7;
	const int cTrainPlanBuildFromType = 8;
	const int cTrainPlanTrainedUnitID = 9;
	const int cTrainPlanFrequency = 10;
	const int cTrainPlanUseMultipleBuildings = 11;
	const int cTrainPlanGatherPoint = 12;
	const int cTrainPlanGatherTargetID = 13;
	const int cTrainPlanMaintainBaseID = 14;
	const int cTrainPlanMaintainAreaID = 15;
	const int cTrainPlanBatchSize = 16;
	const int cTrainPlanMaxQueueSize = 17;
	const int cExplorePlanLOSMultiplier = 0;
	const int cExplorePlanDoLoops = 1;
	const int cExplorePlanDoneLoops = 2;
	const int cExplorePlanNumberOfLoops = 3;
	const int cExplorePlanPointsInLoop = 4;
	const int cExplorePlanAvoidingAttackedAreas = 5;
	const int cExplorePlanReExploreAreas = 6;
	const int cExplorePlanLOSProtoUnitID = 7;
	const int cExplorePlanBuildPosition = 8;
	const int cExplorePlanBuilderUnitType = 9;
	const int cExplorePlanCanBuildLOSProto = 10;
	const int cExplorePlanHandleDamageTime = 11;
	const int cExplorePlanHandleDamageFrequency = 12;
	const int cExplorePlanQuitWhenPointIsVisible = 13;
	const int cExplorePlanQuitWhenPointIsVisiblePt = 14;
	const int cExplorePlanCurrentNuggetID = 15;
	const int cExplorePlanNuggetsToGather = 16;
	const int cExplorePlanOkToGatherNuggets = 17;
	const int cResearchPlanBuildingID = 0;
	const int cResearchPlanBuildingTypeID = 1;
	const int cResearchPlanTechID = 2;
	const int cResearchPlanBuildingAbstractTypeID = 3;
	const int cAttackPlanPlayerID = 0;
	const int cAttackPlanSpecificTargetID = 1;
	const int cAttackPlanTargetTypeID = 2;
	const int cAttackPlanQueryID = 3;
	const int cAttackPlanAttackRouteID = 4;
	const int cAttackPlanAttackRoutePattern = 5;
	const int cAttackPlanGatherPoint = 6;
	const int cAttackPlanGatherDistance = 7;
	const int cAttackPlanTargetID = 8;
	const int cAttackPlanMoveAttack = 9;
	const int cAttackPlanNumberAttacks = 10;
	const int cAttackPlanRefreshFrequency = 11;
	const int cAttackPlanLastRefreshTime = 12;
	const int cAttackPlanHandleDamageTime = 13;
	const int cAttackPlanHandleDamageFrequency = 14;
	const int cAttackPlanBaseAttackMode = 15;
	const int cAttackPlanPathID = 16;
	const int cAttackPlanFromGoalID = 17;
	const int cAttackPlanRetreatMode = 18;
	const int cAttackPlanTargetAreaGroups = 19;
	const int cAttackPlanTeleportLocation = 20;
	const int cAttackPlanAutoUseGPs = 21;
	const int cAttackPlanPowerID = 22;
	const int cAttackPlanGatherStartTime = 23;
	const int cAttackPlanTargetResourceType = 24;
	const int cAttackPlanAttackPoint = 25;
	const int cAttackPlanAttackPointEngageRange = 26;
	const int cAttackPlanAttackExplicitBaseID = 27;
	const int cAttackPlanGatherWaitTime = 28;
	const int cAttackPlanAttackRoutePatternLRU = 0;
	const int cAttackPlanAttackRoutePatternMRU = 1;
	const int cAttackPlanAttackRoutePatternRandom = 2;
	const int cAttackPlanAttackRoutePatternBest = 3;
	const int cAttackPlanBaseAttackModeNone = 0;
	const int cAttackPlanBaseAttackModeWeakest = 1;
	const int cAttackPlanBaseAttackModeStrongest = 2;
	const int cAttackPlanBaseAttackModeLRU = 3;
	const int cAttackPlanBaseAttackModeMRU = 4;
	const int cAttackPlanBaseAttackModeRandom = 5;
	const int cAttackPlanBaseAttackModeClosest = 6;
	const int cAttackPlanBaseAttackModeFarthest = 7;
	const int cAttackPlanBaseAttackModeExplicit = 8;
	const int cAttackPlanRetreatModeNone = 0;
	const int cAttackPlanRetreatModeOutnumbered = 1;
	const int cAttackPlanRetreatModeWillLose = 2;
	const int cProgressionPlanPollingTime = 0;
	const int cProgressionPlanProgressionID = 1;
	const int cProgressionPlanTrainUnitAtEnd = 2;
	const int cProgressionPlanNumGoalUnitsToBuild = 3;
	const int cProgressionPlanGoalUnitID = 4;
	const int cProgressionPlanGoalTechID = 5;
	const int cProgressionPlanBuildAreaID = 6;
	const int cProgressionPlanCurrentGoalID = 7;
	const int cProgressionPlanCurrentGoalType = 8;
	const int cProgressionPlanCurrentStep = 9;
	const int cProgressionPlanCurrentStepPlanID = 10;
	const int cProgressionPlanPaused = 11;
	const int cProgressionPlanAdvanceOneStep = 12;
	const int cProgressionPlanRunInParallel = 13;
	const int cProgressionPlanChildProgressions = 14;
	const int cProgressionPlanBuildingPref = 15;
	const int cHerdPlanBuildingID = 0;
	const int cHerdPlanBuildingTypeID = 1;
	const int cHerdPlanDistance = 2;
	const int cFishPlanLandPoint = 0;
	const int cFishPlanWaterPoint = 1;
	const int cFishPlanLandGroupID = 2;
	const int cFishPlanWaterGroupID = 3;
	const int cFishPlanAutoTrainBoats = 4;
	const int cFishPlanNumberInTraining = 5;
	const int cFishPlanDockID = 6;
	const int cFishPlanMaximumDockDist = 7;
	const int cFishPlanPlaceRetries = 8;
	const int cFishPlanMaxPlaceRetries = 9;
	const int cFishPlanBuildDock = 10;
	const int cTransportPlanTransportID = 0;
	const int cTransportPlanTransportTypeID = 1;
	const int cTransportPlanGatherPoint = 2;
	const int cTransportPlanTargetPoint = 3;
	const int cTransportPlanGatherAreaGroup = 4;
	const int cTransportPlanTargetAreaGroup = 5;
	const int cTransportPlanGatherArea = 6;
	const int cTransportPlanTargetArea = 7;
	const int cTransportPlanPathType = 8;
	const int cTransportPlanPathPlanned = 9;
	const int cTransportPlanReturnWhenDone = 10;
	const int cTransportPlanMaximizeXportMovement = 11;
	const int cTransportPlanUnitsMoved = 12;
	const int cTransportPlanIgnoreAreaIDs = 13;
	const int cTransportPlanBestDangerArea = 14;
	const int cTransportPlanBestDangerValue = 15;
	const int cTransportPlanDropOffPoint = 16;
	const int cTransportPlanPersistent = 17;
	const int cTransportPlanMiddleAreaGroups = 18;
	const int cTransportPlanTakeMoreUnits = 19;
	const int cTradePlanTargetUnitTypeID = 0;
	const int cTradePlanTargetUnitID = 1;
	const int cTradePlanStartPosition = 2;
	const int cTradePlanTradeUnitType = 3;
	const int cTradePlanTradeUnitTypeMax = 4;
	const int cTradePlanMarketID = 5;
	const int cTowerPlanCenterLocation = 0;
	const int cTowerPlanAreaID = 1;
	const int cTowerPlanDistanceFromCenter = 2;
	const int cTowerPlanMaximizeLOS = 3;
	const int cTowerPlanMaximizeAttack = 4;
	const int cTowerPlanNumberToBuild = 5;
	const int cTowerPlanBuildLocations = 6;
	const int cTowerPlanProtoIDToBuild = 7;
	const int cTowerPlanAttackLOSModifier = 8;
	const int cTowerPlanLOSModifier = 9;
	const int cAttackStrategyPlanPlayerID = 0;
	const int cAttackStrategyPlanNumberTotalAttacks = 1;
	const int cDefendPlanDefendTargetID = 0;
	const int cDefendPlanDefendAreaID = 1;
	const int cDefendPlanDefendBaseID = 2;
	const int cDefendPlanDefendPoint = 3;
	const int cDefendPlanEngageRange = 4;
	const int cDefendPlanPatrol = 5;
	const int cDefendPlanPatrolWaypoint = 6;
	const int cDefendPlanCurrentWaypoint = 7;
	const int cDefendPlanTargetID = 8;
	const int cDefendPlanGatherDistance = 9;
	const int cDefendPlanRefreshFrequency = 10;
	const int cDefendPlanLastRefreshTime = 11;
	const int cDefendPlanAttackTypeID = 12;
	const int cDefendPlanGatherPercentage = 13;
	const int cDefendPlanNoTargetTimeout = 14;
	const int cDefendPlanNoTargetTimer = 15;
	const int cDefendPlanStopTakingUnits = 16;
	const int cDefendPlanStopTakingUnitTime = 17;
	const int cNuggetPlanGatherDistance = 0;
	const int cNuggetPlanGatherPercentage = 1;
	const int cNuggetPlanMaxGuardianStrength = 2;
	const int cNuggetPlanTargetNuggetID = 3;
	const int cNuggetPlanTargetGatherPosition = 4;
	const int cReservePlanPlanType = 0;
	const int cGoalPlanGoalType = 0;
	const int cGoalPlanGoalSubType = 1;
	const int cGoalPlanMinTime = 2;
	const int cGoalPlanMaxTime = 3;
	const int cGoalPlanMinAge = 4;
	const int cGoalPlanMaxAge = 5;
	const int cGoalPlanRepeat = 6;
	const int cGoalPlanExecuteCount = 7;
	const int cGoalPlanDoneGoal = 8;
	const int cGoalPlanFailGoal = 9;
	const int cGoalPlanExecuteGoal = 10;
	const int cGoalPlanAutoUpdateState = 11;
	const int cGoalPlanAutoUpdateBase = 12;
	const int cGoalPlanAutoUpdateAttackPlayerID = 13;
	const int cGoalPlanTargetType = 14;
	const int cGoalPlanTarget = 15;
	const int cGoalPlanTargetPoint = 16;
	const int cGoalPlanTargetNumber = 17;
	const int cGoalPlanMinUnitNumber = 18;
	const int cGoalPlanMaxUnitNumber = 19;
	const int cGoalPlanUnitPickerID = 20;
	const int cGoalPlanUnitPickerFrequency = 21;
	const int cGoalPlanUnitPickerTime = 22;
	const int cGoalPlanAttackPlayerID = 23;
	const int cGoalPlanAttackStartFrequency = 24;
	const int cGoalPlanAttackStartTime = 25;
	const int cGoalPlanUnitTypeID = 26;
	const int cGoalPlanBaseID = 27;
	const int cGoalPlanAllowRetreat = 28;
	const int cGoalPlanUpgradeBuilding = 29;
	const int cGoalPlanSetAreaGroups = 30;
	const int cGoalPlanIdleAttack = 31;
	const int cGoalPlanAreaGroupID = 32;
	const int cGoalPlanFunctionID = 33;
	const int cGoalPlanFunctionParm = 34;
	const int cGoalPlanBuildingTypeID = 35;
	const int cGoalPlanBuildingPlacementID = 36;
	const int cGoalPlanBuildingSearchID = 37;
	const int cGoalPlanActiveHealthTypeID = 38;
	const int cGoalPlanActiveHealth = 39;
	const int cGoalPlanAttackRoutePatternType = 40;
	const int cGoalPlanUpgradeFilterType = 41;
	const int cGoalPlanReservePlanID = 42;
	const int cGoalPlanFindBestOpp = 43;
	const int cGoalPlanMinOppScoreForGo = 44;
	const int cGoalPlanGoalTypeForwardBase = 0;
	const int cGoalPlanGoalTypeCreateBase = 1;
	const int cGoalPlanGoalTypeMainBase = 2;
	const int cGoalPlanGoalTypeAttack = 3;
	const int cGoalPlanGoalTypeDefend = 4;
	const int cGoalPlanGoalTypeTrain = 5;
	const int cGoalPlanGoalTypeMaintain = 6;
	const int cGoalPlanGoalTypeResearch = 7;
	const int cGoalPlanGoalTypeAge = 8;
	const int cGoalPlanGoalTypeCallback = 9;
	const int cGoalPlanGoalTypeBuilding = 10;
	const int cGoalPlanGoalSubTypeEmpty1 = 0;
	const int cGoalPlanGoalSubTypeEmpty2 = 1;
	const int cGoalPlanTargetTypeArea = 0;
	const int cGoalPlanTargetTypeAreaGroup = 1;
	const int cGoalPlanTargetTypePoint = 2;
	const int cGoalPlanTargetTypeUnitType = 3;
	const int cGoalPlanTargetTypeUnit = 4;
	const int cGoalPlanTargetTypePlayer = 5;
	const int cGoalPlanTargetTypePlayerRelation = 6;
	const int cGoalPlanTargetTypeTech = 7;
	const int cGatherGoalPlanScriptRPGPct = 0;
	const int cGatherGoalPlanCostRPGPct = 1;
	const int cGatherGoalPlanGathererPct = 2;
	const int cGatherGoalPlanNumFoodPlans = 3;
	const int cGatherGoalPlanNumWoodPlans = 4;
	const int cGatherGoalPlanNumGoldPlans = 5;
	const int cGatherGoalPlanMinResourceAmt = 6;
	const int cGatherGoalPlanResourceCostWeight = 7;
	const int cGatherGoalPlanFarmLimitPerPlan = 8;
	const int cGatherGoalPlanMaxFarmLimit = 9;
	const int cGatherGoalPlanResourceSkew = 10;
	const int cBuildWallPlanWallType = 0;
	const int cBuildWallPlanWallStart = 1;
	const int cBuildWallPlanWallEnd = 2;
	const int cBuildWallPlanWallRingCenterPoint = 3;
	const int cBuildWallPlanWallRingRadius = 4;
	const int cBuildWallPlanNumberOfGates = 5;
	const int cBuildWallPlanAreaIDs = 6;
	const int cBuildWallPlanFoundationID = 7;
	const int cBuildWallPlanGateIndices = 8;
	const int cBuildWallPlanGateProtoIDs = 9;
	const int cBuildWallPlanEdgeOfMapBuffer = 10;
	const int cBuildWallPlanPieces = 11;
	const int cBuildWallPlanPiecePositions = 12;
	const int cBuildWallPlanPieceRotations = 13;
	const int cBuildWallPlanEnRoute = 14;
	const int cBuildWallPlanWallTypeStraight = 0;
	const int cBuildWallPlanWallTypeRing = 1;
	const int cBuildWallPlanWallTypeArea = 2;
	const int cMissionPlanPlanID = 0;
	const int cMissionPlanType = 1;
	const int cMissionPlanStartTime = 2;
	const int cMissionPlanTarget = 3;
	const int cMissionPlanVector1 = 4;
	const int cMissionPlanVector2 = 5;
	const int cMissionPlanFloat1 = 6;
	const int cMissionPlanFloat2 = 7;
	const int cMissionPlanOpportunityID = 8;
	const int cTransportPathTypePoints = 0;
	const int cTransportPathTypeAreas = 1;
	const int cNativeResearchPlanBuildingID = 0;
	const int cNativeResearchPlanTacticID = 1;
	const int cResignGatherers = 0;
	const int cResignTeammates = 2;
	const int cResignMilitaryPop = 3;
	const int cMovementTypeNone = 0;
	const int cMovementTypeLand = 1;
	const int cMovementTypeWater = 2;
	const int cMovementTypeAir = 4;
	const int cMovementTypeNonSolid = 8;
	const int cUnitStateNone = 0;
	const int cUnitStateBuilding = 1;
	const int cUnitStateAlive = 2;
	const int cUnitStateDead = 4;
	const int cUnitStateQueued = 8;
	const int cUnitStateAny = 255;
	const int cUnitStateABQ = 11;
	const int cBuildingPlacementEventDone = 0;
	const int cBuildingPlacementEventFailed = 1;
	const int cUnitQueryNoArmy = -1;
	const int cUnitQueryInvalidArmy = -1002;
	const int cBuildingPlacementPreferenceNone = -1;
	const int cBuildingPlacementPreferenceBack = 0;
	const int cBuildingPlacementPreferenceFront = 1;
	const int cBuildingPlacementPreferenceLeft = 2;
	const int cBPIFalloffLinear = 0;
	const int cBPIFalloffNone = 1;
	const int cBPIFalloffLinearInverse = 2;
	const int cResourceGold = 0;
	const int cResourceWood = 1;
	const int cResourceFood = 2;
	const int cResourceFame = 3;
	const int cResourceSkillPoints = 4;
	const int cResourceXP = 5;
	const int cResourceShips = 6;
	const int cResourceTrade = 7;
	const int cAllResources = -1234;
	const int cTechStatusUnobtainable = 0;
	const int cTechStatusObtainable = 1;
	const int cTechStatusActive = 2;
	const int cAttackRouteFrontRight = 0;
	const int cAttackRouteRightFront = 1;
	const int cAttackRouteRightBack = 2;
	const int cAttackRouteBackRight = 3;
	const int cAttackRouteBackLeft = 4;
	const int cAttackRouteLeftBack = 5;
	const int cAttackRouteLeftFront = 6;
	const int cAttackRouteFrontLeft = 7;
	const int cAreaTypeForest = 1;
	const int cAreaTypeWater = 2;
	const int cAreaTypeImpassableLand = 3;
	const int cAreaTypeVPSite = 5;
	const int cAreaGroupTypeLand = 0;
	const int cAreaGroupTypeWater = 1;
	const int cAreaGroupTypeImpassableLand = 2;
	const int cXSAgeHandler = 0;
	const int cXSPowerHandler = 1;
	const int cXSRetreatHandler = 2;
	const int cXSResignHandler = 3;
	const int cXSBuildHandler = 4;
	const int cXSHomeCityTransportArriveHandler = 5;
	const int cXSHomeCityTransportReturnHandler = 6;
	const int cXSHomeCityLevelUpHandler = 7;
	const int cXSTreatyBrokenHandler = 8;
	const int cXSShipResourceGranted = 9;
	const int cXSAutoCreatePlanHandler = 10;
	const int cXSNuggetHandler = 11;
	const int cXSPlayerAgeHandler = 12;
	const int cXSScoreOppHandler = 13;
	const int cXSMissionStartHandler = 14;
	const int cXSMissionEndHandler = 15;
	const int cXSGameOverHandler = 16;
	const int cXSMonopolyStartHandler = 17;
	const int cXSMonopolyEndHandler = 18;
	const int cXSWonderVictoryStartHandler = 19;
	const int cXSWonderVictoryEndHandler = 20;
	const int cXSRelicVictoryStartHandler = 21;
	const int cXSRelicVictoryEndHandler = 22;
	const int cXSKOTHVictoryStartHandler = 23;
	const int cXSKOTHVictoryEndHandler = 24;
	const int cPlayerChatVerbInvalid = 0;
	const int cPlayerChatVerbAttack = 1;
	const int cPlayerChatVerbDefend = 2;
	const int cPlayerChatVerbTribute = 3;
	const int cPlayerChatVerbFeed = 4;
	const int cPlayerChatVerbCancel = 5;
	const int cPlayerChatVerbClaim = 6;
	const int cPlayerChatVerbTrain = 7;
	const int cPlayerChatVerbStrategy = 8;
	const int cPlayerChatTargetTypeInvalid = 0;
	const int cPlayerChatTargetTypePlayers = 1;
	const int cPlayerChatTargetTypeUnits = 2;
	const int cPlayerChatTargetTypeUnitTypes = 3;
	const int cPlayerChatTargetTypeResource = 4;
	const int cPlayerChatTargetTypeLocation = 5;
	const int cPlayerChatTargetStrategyInvalid = 0;
	const int cPlayerChatTargetStrategyRush = 1;
	const int cPlayerChatTargetStrategyBoom = 2;
	const int cPlayerChatTargetStrategyTurtle = 3;
	const int cPlayerChatResponseTypeYes = 0;
	const int cPlayerChatResponseTypeNo = 1;
	const int cVPInvalid = -2;
	const int cVPAll = -1;
	const int cVPNative = 0;
	const int cVPSecret = 1;
	const int cVPTrade = 2;
	const int cVPConqueror = 3;
	const int cVPGranted = 4;
	const int cVPStateAny = -1;
	const int cVPStateNone = 0;
	const int cVPStateSite = 1;
	const int cVPStateBuilding = 2;
	const int cVPStateCompleted = 3;
	const int cGameTypeScenario = 0;
	const int cGameTypeSaved = 1;
	const int cGameTypeRandom = 2;
	const int cGameTypeCampaign = 4;
}