# RainbowCrackPlugin
Plugin for RainbowCrack (see [http://project-rainbowcrack.com/documentation.htm](http://project-rainbowcrack.com/documentation.htm]) for development)

Tested with rainbowcrack 1.6.1 on x64 Linux.

### Algorithm(s) implemented:
* Oracle <= 10g. You can choose the Oracle username (*SYS* in the source code).

### Usage
* Set the username in *alglib1.cpp* (*login*) and the length (*loginLg*)
* Compile the souce code:
```bash
./compile_alglib1.sh
```
* Put *alglib1.so* next to *RainbowCrack* binaries (ex: *rcrack*)
