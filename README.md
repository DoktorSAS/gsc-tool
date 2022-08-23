[![Build status](https://ci.appveyor.com/api/projects/status/defmhg4753c1ap1o?svg=true)](https://ci.appveyor.com/project/xensik/gsc-tool)
![license](https://img.shields.io/github/license/xensik/gsc-tool.svg)
[![GitHub issues](https://img.shields.io/github/issues/xensik/gsc-tool)](https://github.com/xensik/gsc-tool/issues)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/xensik/gsc-tool)](https://github.com/xensik/gsc-tool/releases)

# GSC Tool
A utility to compile & decompile IW engine game scripts.

## Supported Games
- **IW5** *(Call of Duty: Modern Warfare 3)* *(PC, PS3, XBOX 360)*
- **IW6** *(Call of Duty: Ghosts)*
- **IW7** *(Call of Duty: Infinite Warfare)*
- **IW8** *(Call of Duty: Modern Warfare (2019))*
- **S1** *(Call of Duty: Advanced Warfare)*
- **S2** *(Call of Duty: WWII)*
- **S4** *(Call of Duty: Vanguard)*
- **H1** *(Call of Duty: Modern Warfare Remastered)*
- **H2** *(Call of Duty: Modern Warfare 2 Campaign Remastered)*
- **T4** *(Call of Duty: World at War)* ***\*WIP\****
- **T5** *(Call of Duty: Black Ops)* ***\*WIP\****
- **T6** *(Call of Duty: Black Ops II)*
- **T7** *(Call of Duty: Black Ops III)* ***\*WIP\****

## Usage
``./gsc-tool.exe <mode> <game> <path>``

**modes**: `asm`, `disasm`, `comp`, `decomp`

**games**: `iw5c`, `iw5`, `iw6`, `iw7`, `iw8`, `s1`, `s2`, `s4`, `h1`, `h2`, `t6`

**paths**: `file`, `directory` (recursive process all files inside dir)

for zonetool files (*.cgsc*, *.cgsc.stack*) use: `zasm`, `zdisasm`, `zcomp`, `zdecomp` modes

Example: ``./gsc-tool.exe comp iw5 ./data/iw5/my_fancy_script.gsc``

| Mode     |Description                | Output      |
|:---------|:--------------------------|:------------|
|`asm`     |assemble a `file.gscasm`   |`file.gscbin`|
|`disasm`  |dissasemble a `file.gscbin`|`file.gscasm`|
|`comp`    |compile a `file.gsc`       |`file.gscbin`|
|`decomp`  |decompile a `file.gscbin`  |`file.gsc`   |

## File Format
If you need to extract scripts from fastfiles or game memory, use [Zonetool](https://github.com/ZoneTool/zonetool) or [Jekyll](https://github.com/EthanC/Jekyll).

- gsc-tool ``.gscbin`` format is a serialized ScriptFile struct: <br/>
***name***: null-terminated string <br/>
***compressedLen***: 4 byte uint <br/>
***len***: 4 byte uint <br/>
***bytecodeLen***: 4 byte uint <br/>
***buffer***: byte array[compressedLen] <br/>
***bytecode***: byte array[bytecodeLen] <br/>

- zonetool (IW5) format made of bytecode file ``.cgsc`` and decompressed stack buffer ``.cgsc.stack``.

- treyarch (T6) format is a single buffer with gscobj data ``.gsc`` or ``.csc``.

## Credits
This project is based on  [*RektInator's* gsc-asm](https://github.com/ZoneTool/gsc-asm). Special thanks to **RektInator**, **JTAG** & **Dasfonia**.

## Disclaimer
This software has been created purely for the purposes of academic research. Project maintainers are not responsible or liable for misuse of the software. Use responsibly.
