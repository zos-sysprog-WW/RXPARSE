# RXPARSE: Unterprogramm analog Kommando PARSE in REXX

siehe IBM Handbücher:  
[TSO/E REXX Reference](https://www.ibm.com/docs/en/SSLTBW_3.1.0/pdf/ikja300_v3r1.pdf)  
[TSO/E REXX User's Guide](https://www.ibm.com/docs/en/SSLTBW_3.1.0/pdf/ikjc300_v3r1.pdf)

Umwandlung mit IBM PL/I (F) Compiler unter MVS 3.8, Test ebenso;  
sollte unter späteren IBM PL/I Compilern und neueren Versionen von
MVS und z/OS auch funktionieren.

Testprogramm RXPATST
(Ausgabe RXPATST.out);  
Vergleich der Ergebnisse mit denen von REXX-Prozedur TSTPARS,
ausgeführt mit

* BREXX/370 V2R5M3 unter MVS 3.8  
    (Ausgabe TSTPARS.out;  
    Differenzen bei den Testfällen 7 16 24 36 54 56 69 wegen eines
    Implementierungsfehlers in BREXX, zeigt TSO/E REXX Reference
    Seite 167 und folgende)  
* OOREXX (Open Object Rexx 4.2.0) unter Debian Linux  
    (Ergebnisse identisch)

Testfälle

* aus TSO/E REXX Reference  
* aus TSO/E REXX User's Guide  
* eigene

Warum fehlt MAXLNGTOK hier in der Schnittstelle?  
*Länge der Zeichenkette ist im Unterprogramm bekannt weil
der IBM PL/I Compiler Metadaten zusammen mit dem Parameter
(Dimension von Bereich, Länge von Zeichenkette, ...; IBM nennt es dope vector)
übergibt, im Gegensatz zum Linux PL/I Compiler und C (und anderen Programmiersprachen).*

## Linux

Umwandlung mit
[Iron Spring Software](http://www.iron-spring.com)
PL/I Compiler 1.4.0a unter Debian Linux, Test ebenso.

Dieser Compiler hat gewisse Einschränkungen, darum eigene Versionen

* RXPARSE_linux  
* RXPATST_linux  
    (Ausgabe RXPATST_linux.out)

## C

Implementierung in C:

* rxpaif.h  
* rxparse.c  
* rxpatst.c  
    (Ausgabe rxpatst.out)


Der Datentyp CHARACTER VARYING (Zeichenkette variabler Länge) von PL/1 wurde in C
nachgebildet. Beispiel:

* dcl vs char(10) var init('ABC');
* struct  
  {  
&nbsp;&nbsp;&nbsp;short lng = 3;  
&nbsp;&nbsp;&nbsp;char dat[10] = "ABC";  
  } vs;

Umwandlung mit
gcc version 12.2.0 unter Debian Linux, Test ebenso.


