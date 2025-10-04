# RXPARSE: Subroutine analogous command PARSE in REXX

See IBM manuals:  
[TSO/E REXX Reference](https://www.ibm.com/docs/en/SSLTBW_3.1.0/pdf/ikja300_v3r1.pdf)  
[TSO/E REXX User's Guide](https://www.ibm.com/docs/en/SSLTBW_3.1.0/pdf/ikjc300_v3r1.pdf)

Compiled with IBM PL/I (F) Compiler under MVS 3.8, test as well;  
should also work under later IBM PL/I compilers and newer
versions of MVS and z/OS.

Test program RXPATST
(output RXPATST.out);  
Comparison of results with those of REXX procedure TSTPARS,
executed with  
* BREXX/370 V2R5M3 under MVS 3.8  
    (output TSTPARS.out;  
    Differences in test cases 7 16 24 36 54 56 69 due to an
    implementation error in BREXX, see TSO/E REXX Reference
    page 167 ff.)  
* OOREXX (Open Object Rexx 4.2.0) under Debian Linux  
    (results identical)

Test cases  
* from TSO/E REXX Reference  
* from TSO/E REXX User's Guide  
* own  

## Linux

Compiled with
[Iron Spring Software](http://www.iron-spring.com)
PL/I Compiler 1.4.0a under Debian Linux, test as well.

This compiler has certain limitations, hence own versions  
* RXPARSE_linux  
* RXPATST_linux  
    (output RXPATST_linux.out)
