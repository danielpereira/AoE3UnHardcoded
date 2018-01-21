# AoE3UnHardcode Patch Configuration File

The UHC Configuration file is a file that is read before the game starts up and that allows modders to define which UHC Patch features should be loaded and to extend or change hardcoded properties that can't be generalized just by pure coding, like farming animations, proper market behavior, maximum population capacity and so on...

By default, it should be located at <AoE3 Path>\Startup\uhc.cfg

An example UHC Configuration File can be found at _Docs/Examples/Configuration File/uhc.cfg_ in this repository.

File Structure
--------------

The UHC Configuration file should follow the following structure:

    multiValueProperty1 Value1 Value2 ...
    multiValueProperty2 Value1 Value2 ...
    singleValueProperty=Value3
    structProperty ItemIndexA Value1A Value2A ...
    patchSetting1
    patchSetting2
    ...

As for UHC Patch v1.5, colons (“:”) should not be used to denote property names and the name of some properties have been changed. The Patcher should be able to convert a pre-v1.5 configuration file, so it can be read by the latest version of the UHC Patch, but, in case it doesn’t, such file will have to be manually converted.

Each one of the available properties of the UHC Configuration Files belongs to one of the following categories:
* **Multi-value properties** - Accept a finite set of items and are used to assign a property (or a set of properties) to the given set of items, which may represent units or civilizations.
* **Single-value properties** - Accept only one value and are used to assign a particular value to one of the settings of the patch or of the game itself. Those properties are denoted by an equal (“=”) sign, that explicitly indicates that a single particular value should be read and assigned to that property, as seen in the example code above. 
* **Struct properties** - Used to define properties that require more than one argument per item
* **Patch Settings** - Enable a particular setting or option of the UHC Patch, and are usually set in the UHC Configuration File by the UHC Patcher.


Supported Properties
--------------------

### Multi-value properties
* **enableFarmAnim** - Defines the (additional) buildings in which settlers would walk through it while gathering a resource from it, like AoE3 Mills and Plantations.
* **rectFarmAnim** - Defines the (additional) buildings which would have a behaviour similar to the rectangular Farms of the TWC civilizations.
* **marketUnits** - Defines which (additional) buildings should support a proper market behaviour.
* **asianCivs** - Defines which civilizations should get export UI, plus support wonder age up.
* **nativeCivs** - Defines which civilizations should get the fire pit UI, plus support council age up.
* **tacticSwitching** - Defines the (additional) buildings that should support tactic switching through ProtoUnitCommands, like the Factory and the Rice Paddy do, in the original game.

### Single-value properties
* **basePop** - Defines the maximum base population to be used by the game. If it’s not set, the default value is 200.
* **extraPop** - Defines the maximum extra population to be used by the game. If it’s not set, the default value is 50.
* **deckCardCount** - Defines the maximum possible number of cards in a deck. If it’s not set, the default value is 25.

### Struct properties
* **farmingRadius** - Defines the maximum area in which villagers should be able to walk, while gathering resources from particular buildings defined in the _enableFarmAnim_ property.
* **attackTypeIcons** - Assigns UI icons and stringtable IDs to existing attack types in the game.
* **explorerUnits** - Defines units which should receive custom explorer or monk names and/or should deliver a knockout message once they are killed, in case they are heroes.

### Patch Settings
* **noAILimit** - Removes the hardcoded 14 AI/Civilization limit by making the game read all .personality files in the from the AI directory defined in the .exe (which should be \AI3, by default).
* **customRevolutionBanners** - Allows new revolutions to have banners above the revolutionary’s portrait in the Revolution UI.
* **ignoreRegistryPath** - Makes the game read the AoE3 files from the folder in which the AoE3 .exe is located, instead of looking for a working path in the registry.
* **enableAllTeams** - Enables team options 3 and 4 for Single Player and Multiplayer games.
* **customSyscalls** - Allows the UHC Patch to load and register custom syscalls implemented through plugins.
* **customCheats** - Allows the UHC Patch to load and register custom cheats implemented through plugins.
* **removeFameRestriction** - Allows the usage of the Fame Resource in ProtoActions, like AutoGather and ModifyGather, and enables proper displaying of Fame, Experience and Shipment costs in the politicians screen and HC cards



Planned Properties
------------------

* **exportUICivs** - Defines which civilizations should get export UI, but not get any of the behaviour of Asian civs
* **firePitUICivs** - Defines which civilizations should get fire pit UI, but not get any of the behaviour of Native civs

