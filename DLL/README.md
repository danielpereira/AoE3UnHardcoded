# AoE3UnHardcode Patch Configuration File

The UHC Configuration file is a file that is read before the game starts up and that allows modders to define which UHC Patch features should be loaded and to extend or change hardcoded properties that can't be generalized just by pure coding, like farming animations, proper market behavior, maximum population capacity and so on...

By default, it should be located at <AoE3 Path>\Startup\uhc.cfg


File Structure
--------------

The UHC Configuration file should follow the following structure:

    multiValueProperty1 Value1 Value2 ...
    multiValueProperty2 Value1 Value2 ...
    singleValueProperty=Value3
    patchSetting1
    patchSetting2
    ...

    
Where multiValuePropertyX is the name of a property that accepts more than one value and Value* are values associated with that property, singleValueProperty is the name of a property that only accepts a single value and Value3 is the value assigned to it and patchSetting1 is a property related to one of the patch settings. The type and the meaning of those values and their amount will depend on the property.

As for UHC Patch v1.5, colons (“:”) should not be used to denote property names and the name of some properties have been changed. The Patcher should be able to convert a pre-v1.5 configuration file, so it can be read by the latest version of the UHC Patch, but, in case it doesn’t, such file will have to be manually converted.



Supported Properties
--------------------

The code for the following properties is already implemented into the parser and the wrapper:
*enableFarmAnim - Defines the (additional) buildings in which settlers would walk through it while gathering a resource from it, like AoE3 Mills and Plantations.
*rectFarmAnim - Defines the (additional) buildings which would have a behaviour similar to the rectangular Farms of the TWC civilizations.
*marketUnits - Defines which (additional) buildings should support a proper market behaviour.
*asianCivs - Defines which civilizations should get export UI, plus support wonder age up.
*nativeCivs - Defines which civilizations should get the fire pit UI, plus support council age up
*basePop - Defines the maximum base population to be used by the game. If it’s not set, the default value is 200
*extraPop - Defines the maximum extra population to be used by the game. If it’s not set, the default value is 50
*deckCardCount - Defines the maximum possible number of cards in a deck. If it’s not set, the default value is 25
*noAILimit - Removes the hardcoded 14 AI/Civilization limit by making the game read all .personality files in the from the AI directory defined in the .exe (which should be \AI3, by default)
*customRevolutionBanners - Allows new revolutions to have banners above the revolutionary’s portrait in the Revolution UI.
*ignoreRegistryPath - Makes the game read the AoE3 files from the folder in which the AoE3 .exe is located, instead of looking for a working path in the registry
*enableAllTeams - Enables team options 3 and 4 for Single Player and Multiplayer games
*customSyscalls - Allows the UHC Patch to load and register custom syscalls implemented through plugins
*customCheats - Allows the UHC Patch to load and register custom cheats implemented through plugins



Planned Properties
------------------

The following properties are planned, but were not coded yet:

* ExportUICivs - Defines which civilizations should get export UI, but not get any of the behaviour of Asian civs
* FirePitUICivs - Defines which civilizations should get fire pit UI, but not get any of the behaviour of Native civs

