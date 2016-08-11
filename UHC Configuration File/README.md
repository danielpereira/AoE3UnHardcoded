# AoE3UnHardcode Patch Configuration File

The UHC Configuration file is a file that is read before the game starts up and that allows modders to extend or change hardcoded properties that can't be generalized just by pure coding, like farming animations, proper market behaviour, maximum population capacity and so on...

By default, it should be located at <AoE3 Path>\Startup\uhc.cfg


File Structure
--------------

The UHC Configuration file should follow the following structure:

    Property1: Value1 Value2 ...
    Property2: Value1 Value2 ...
    ...
    
Where PropetyX is the name of a property and Value* are values associated with that property. The type and the meaning of those values and their amount will depend on the property.


Supported Properties
--------------------

The code for the following properties is already implemented into the parser and the wrapper:
* FarmAnim - Defines the (additional) buildings in which settlers would walk through it while gathering a resource from it, like AoE3 Mills and Plantations
* RectFarmAnim - Defines the (additional) buildings which would have a behaviour similar to the rectangular Farms that TWC civilizations have


Planned Properties
------------------

The following properties are planned, but were not coded yet:
* MarketUnits - Defines which (additional) buildings should support a proper market behaviour
* BasePop - Defines the base maximum population capacity
* ExtraPop - Defines the maximum extra population capacity
* AsianCivs - Defines which civilizations should get export UI, plus support wonder age up
* NativeCivs - Defines which civilizations should get the fire pit UI, plus support council age up


How to use
----------

In order to use the UHC Configuration File feature, the following steps must be taken:
* Assemble the wrapper library (\Wrapper\uhc_wrapper.asm) in the Flat Assembler
* Compile the parsing library (which sourcecode can be found at \Parser) in MinGW or Visual Studio
* Move the compiled output of the previous operations to the root of your AoE3 installation
* Create a valid UHC configuration file and place it the Startup folder of your AoE3 installation
* Inject uhc_wrapper.dll into age3y.exe

