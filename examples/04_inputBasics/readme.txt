freemlib for Neo-Geo Example 04: Input Basics
================================================================================
[Introduction]
In the example 2, there was a quickly hacked together input routine, but now
it's time to go a little more in depth.

Since this is "Input Basics", this example won't cover the Mahjong controller,
nor will it deal with the Trackball controller from The Irritating Maze, or the
spinner controller from Pop'n Bounce/Gapporin.

Four-player support is an exercise left to the reader to implement.

================================================================================
[Files]
(In the directory)
04_inputBasics.asm		Main file
header_68k.inc			68000 Vectors
header_cart.inc			Neo-Geo cartridge header
header_cd.inc			Neo-Geo CD header
IPL.TXT					Initial Program Load for Neo-Geo CD
Makefile				GNU Make makefile
paldata.inc				Palette data
ram_user.inc			User space RAM ($100000-$10F2FF)
readme.txt				This file!

(Sub-directories)
fixtiles/				fix layer tilesets
	202-s1.pal			Palette file (used with YY-CHR)
	202-s1.s1			Fix Layer S ROM
	PALBASIC.FIX		.FIX file for CD (same as 202-s1.s1, just me being lazy)
sprtiles/
	202-c1.c1			C ROM 1/2
	202-c2.c2			C ROM 2/2
	in.smc				Source of C ROM (SNES format graphics; convert with recode16)

(Included from outside the directory)
../../src/inc/neogeo.inc		Neo-Geo hardware defines
../../src/inc/ram_bios.inc		Neo-Geo BIOS RAM location defines
../../src/inc/mess_macro.inc	Macros for MESS_OUT

================================================================================
[Setup]
The initialization sequence is similar to the previous three examples.
Palettes are loaded in a similar fashion to Example 3.

The primary setup routine is InitDisplay, which just throws a bunch of static
messages up for MESS_OUT. Everything serious will be done in the VBlank between
the calls to SYSTEM_IO and MESS_OUT.

================================================================================
[Process]
This example is meant to show you the input values from the BIOS, as well as how
they map to the buttons and directions.

(wip)
