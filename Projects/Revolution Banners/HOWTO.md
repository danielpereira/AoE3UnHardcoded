# Revolution banners patch

This patch will make the game load the banner for a Revolution from Art\ui\ingame\politicians\REV_banner_<techname>, where <techname> is the name of te technology of a Revolution, without the "XPRevolution" prefix. 

In order to use this patch, the following steps must be taken:

1. Assemble the revbanners.asm file in Flat Assembler
2. Move the compiled outpout of the previous operations to the root of your AoE3 Directory
3. Inject revbanners.dll into age3y.exe

Note: after applying this patch, the banners for the original revolutions will not show up, since they are named in a different convention. In order to fix this, yuo need to extract them, rename them and put them in the right directories.
