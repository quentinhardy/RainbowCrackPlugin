# RainbowCrackPlugin
Plugin for RainbowCrack (see [http://project-rainbowcrack.com/documentation.htm](http://project-rainbowcrack.com/documentation.htm) for development)

Tested with rainbowcrack 1.6.1 on x64 Linux.

### Algorithm(s) implemented:
* Oracle Database <= 10g. You can choose the Oracle username (*SYS* or *SYSTEM*).

### Usage
* Compile the souce code:
```bash
./compile_alglib1.sh
```
* Put *alglib1.so* next to *RainbowCrack* binaries (ex: *rcrack*)

### Examples
* Crack Oracle <=10g hashes of some SYSTEM users:
```bash
./rcrack ~/oracle10g-SYSTEM_oracle-alpha-numeric-symbol6#1-7/*.rt -l /tmp/passwords.txt
```

---
| __Quentin HARDY__    |
| ------------- |
| __qhardyfr@gmail.com__  |
