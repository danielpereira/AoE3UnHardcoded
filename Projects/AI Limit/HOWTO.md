# AI/Civ Limit patch

This patch will make the game, instead of loading a fixed and hardcoded amount of .personality files, load all of the .personality files from the \AI3 directory.

In order to use this patch, the following steps must be taken:
1. Compile the solution in \Patch using Visual Studio 2013
2. Assemble the ai.asm file in Flat Assembler
3. Move the compiled outpout of the previous operations to the root of your AoE3 Directory
4. Inject ai.dll into age3y.exe