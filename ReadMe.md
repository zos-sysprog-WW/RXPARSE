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
    page 167 and following)  
* OOREXX (Open Object Rexx 4.2.0) under Debian Linux  
    (results identical)

Test cases

* from TSO/E REXX Reference  
* from TSO/E REXX User's Guide  
* own  

<u>Why is MAXLNGTOK missing from the interface here?</u>  
The length of the string is known in the subroutine because
the IBM PL/I compiler passes metadata along with the parameter
(dimension of array, length of string, ...; IBM calls it a dope vector),
unlike the Linux PL/I compiler and C (and other programming languages).

## Linux

Compiled with
[Iron Spring Software](http://www.iron-spring.com)
PL/I Compiler 1.4.0a under Debian Linux, test as well.

This compiler has certain limitations, hence own versions

* RXPARSE_linux  
* RXPATST_linux  
    (output RXPATST_linux.out)

## C

Implementation in C:

* rxpaif.h  
* rxparse.c  
* rxpatst.c  
    (output rxpatst.out)

The PL/1 data type CHARACTER VARYING (variable length string) has been implemented in C. Example:

* dcl vs char(10) var init('ABC');
* struct  
  {  
&nbsp;&nbsp;&nbsp;short lng = 3;  
&nbsp;&nbsp;&nbsp;char dat[10] = "ABC";  
  } vs;

Compiled with
gcc version 12.2.0 on Debian Linux; test as well.
