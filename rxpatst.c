/* rxpatst.c */

   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <string.h>

   #define _STRLNG 55
   #define _TEMLNG 55
   #define _TOKDIM 6
   #define _TOKLNG 55
   #include "rxpaif.h"

/**********************************************************************/

   void z2vs(void *varstr, const short max, const char init[])
   {
     _VARSTR(*vs,)
     short i;

     vs = varstr;
     vs->lng = 0;
     for(i = 0; i < max; ++i)
     {
       if(init[i] == '\0')
         break;
       ++vs->lng;
       vs->dat[i] = init[i];
     }
     for(; i < max; ++i)
       vs->dat[i] = ' ';

     return;
   }

/**********************************************************************/

   char *vs2z(void *varstr, char ret[])
   {
     _VARSTR(*vs,)
     short i;

     vs = varstr;
     i = vs->lng;
     strncpy(ret, vs->dat, (size_t)vs->lng);
     ret[i] = '\0';

     return ret;
   }

/**********************************************************************/

   _Bool vscmp(void *varstr1, void *varstr2)
   {
     _VARSTR(*vs1,)
     _VARSTR(*vs2,)

     vs1 = varstr1;
     vs2 = varstr2;
     if(vs1->lng == vs2->lng)
       if(strncmp(vs1->dat, vs2->dat, (size_t)vs1->lng) == 0)
         return true;

     return false;
   }

/**********************************************************************/

   char *blankz(const int l, char ret[])
   {
     int k;

     for(k = 0; k < l; ++k)
       ret[k] = ' ';
     ret[k] = '\0';

     return ret;
   }

/**********************************************************************/

   int main(int argc, char *argv[])
   {
     _STRING string;
     _TEMPLATE template;
     _TOKEN tokens[_TOKDIM];
     _MISC misc;

     #define NTEST 80
     _STRING s[NTEST];
     _TEMPLATE t[NTEST];
     _TOKEN e[NTEST][_TOKDIM + 1];

/**********************************************************************/

     z2vs(&s[ 1], _STRLNG, "a b c");
     z2vs(&s[ 2], _STRLNG, "a b c");
     z2vs(&s[ 3], _STRLNG, "a b c");
     z2vs(&s[ 4], _STRLNG, "a b c");
     z2vs(&s[ 5], _STRLNG, "a b c");
     z2vs(&s[ 6], _STRLNG, "a b c");
     z2vs(&s[ 7], _STRLNG, "a   b c  ");
     z2vs(&s[ 8], _STRLNG, "  a  ");
     z2vs(&s[ 9], _STRLNG, "a b c");
     z2vs(&s[10], _STRLNG, "a,b, c");
     z2vs(&s[11], _STRLNG, "a b c ");
     z2vs(&s[12], _STRLNG, "a b c ");
     z2vs(&s[13], _STRLNG, "a b c ");
     z2vs(&s[14], _STRLNG, "a b  c ");
     z2vs(&s[15], _STRLNG, "a b c d");
     z2vs(&s[16], _STRLNG, "a b c d");
     z2vs(&s[17], _STRLNG, "a b c d");
     z2vs(&s[18], _STRLNG, "a b c d");
     z2vs(&s[19], _STRLNG, "a b c d");
     z2vs(&s[20], _STRLNG, "a b c d");
     z2vs(&s[21], _STRLNG, "Sirius Polaris Rigil");
     z2vs(&s[22], _STRLNG, "moon");
     z2vs(&s[23], _STRLNG, "moon Io Europa Callisto...");
     z2vs(&s[24], _STRLNG, "Mercury Venus   Earth   Mars    Jupiter ");
     z2vs(&s[25], _STRLNG, "    Pluto   ");
     z2vs(&s[26], _STRLNG, "Arcturus Betelgeuse Sirius Rigil");
     z2vs(&s[27], _STRLNG, "Smith, John");
     z2vs(&s[28], _STRLNG, "Smith, John");
     z2vs(&s[29], _STRLNG, "Clemens    Samuel    Mark Twain          ");
     z2vs(&s[30], _STRLNG, "Clemens    Samuel    Mark Twain          ");
     z2vs(&s[31], _STRLNG, "Clemens    Samuel    Mark Twain          ");
     z2vs(&s[32], _STRLNG, "Clemens    Samuel    Mark Twain          ");
     z2vs(&s[33], _STRLNG, "astronomers");
     z2vs(&s[34], _STRLNG, "astronomers");
     z2vs(&s[35], _STRLNG, \
          "Silas Marner, Felix Holt, Daniel Deronda, Middle");
     z2vs(&s[36], _STRLNG, "     John      Q.   Public");
     z2vs(&s[37], _STRLNG, "R E X X");
     z2vs(&s[38], _STRLNG, "4,Porthos Athos Aramis D'Artagnon");
     z2vs(&s[39], _STRLNG, "REstructured eXtended eXecutor");
     z2vs(&s[40], _STRLNG, "");
     z2vs(&s[41], _STRLNG, "a b c");
     z2vs(&s[42], _STRLNG, "a b c");
     z2vs(&s[43], _STRLNG, "a b c");
     z2vs(&s[44], _STRLNG, "a b c");
     z2vs(&s[45], _STRLNG, "a b c");
     z2vs(&s[46], _STRLNG, "a b c");
     z2vs(&s[47], _STRLNG, "a b c");
     z2vs(&s[48], _STRLNG, "a b c");
     z2vs(&s[49], _STRLNG, "a b c");
     z2vs(&s[50], _STRLNG, "a b c");
     z2vs(&s[51], _STRLNG, "a b c");
     z2vs(&s[52], _STRLNG, "a b c");
     z2vs(&s[53], _STRLNG, "  a  x  b  x  c  ");
     z2vs(&s[54], _STRLNG, "  a  x  b  x  c  ");
     z2vs(&s[55], _STRLNG, "  a  x  b  x  c  ");
     z2vs(&s[56], _STRLNG, "  a  b  x  c  d  z  x  e  f  z  ");
     z2vs(&s[57], _STRLNG, \
          "LISTC CAT(cat) OUT(dsn) LEVEL(lvl) CLUSTER ALL");
     z2vs(&s[58], _STRLNG, "grep -v [aeiou] wordlist.txt");
     z2vs(&s[59], _STRLNG, "grep -v \"xyz\" wordlist.txt");
     z2vs(&s[60], _STRLNG, "");
     z2vs(&s[61], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[62], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[63], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[64], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[65], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[66], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[67], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[68], _STRLNG, "Experience is the best teacher.");
     z2vs(&s[69], _STRLNG, "     x     y    z    ");
     z2vs(&s[70], _STRLNG, "a b c");
     z2vs(&s[71], _STRLNG, "a 'b'");
     z2vs(&s[72], _STRLNG, "a 'b'");
     z2vs(&s[73], _STRLNG, "a 'b'");
     z2vs(&s[74], _STRLNG, "a b c");
     z2vs(&s[75], _STRLNG, "a b c");
     z2vs(&s[76], _STRLNG, "a b c");
     z2vs(&s[77], _STRLNG, "a b c");
     z2vs(&s[78], _STRLNG, "a b c");
     z2vs(&s[79], _STRLNG, "a b c");

     z2vs(&t[ 1], _TEMLNG, "'a' ?1 .");
     z2vs(&t[ 2], _TEMLNG, "'a' ?1 'b' ?2");
     z2vs(&t[ 3], _TEMLNG, "'a' ?1 'c' ?2");
     z2vs(&t[ 4], _TEMLNG, "?1 5 ?2");
     z2vs(&t[ 5], _TEMLNG, "1 ?1 5 ?2");
     z2vs(&t[ 6], _TEMLNG, "?1 +2 ?2 +2 .");
     z2vs(&t[ 7], _TEMLNG, "?1 ?2");
     z2vs(&t[ 8], _TEMLNG, "?1");
     z2vs(&t[ 9], _TEMLNG, ". ?1 .");
     z2vs(&t[10], _TEMLNG, "?1 ',' ?2 ',' ?3");
     z2vs(&t[11], _TEMLNG, "?1 =3 ?2 =4 ?3");
     z2vs(&t[12], _TEMLNG, "3 ?1 1 ?2 5 ?3 6");
     z2vs(&t[13], _TEMLNG, "3 ?1 4 1 ?2 2 5 ?3 6");
     z2vs(&t[14], _TEMLNG, "?1 +2 ?2 +3 ?3 -3 ?4 .");
     z2vs(&t[15], _TEMLNG, "?1 ?2 5 ?3 7 ?4");
     z2vs(&t[16], _TEMLNG, "'a' ?1 ?2 5 ?3 7 ?4");
     z2vs(&t[17], _TEMLNG, "?1 'b' +2 ?2 +2 ?3");
     z2vs(&t[18], _TEMLNG, "?1 'b' +2 ?2 +2 ?3 -6 ?4 .");
     z2vs(&t[19], _TEMLNG, "?6 'b' +2 ?4 +2 ?3 -6 ?2 .");
     z2vs(&t[20], _TEMLNG, "1 ?1 0 1 ?2 1 5 ?3 4 ?4 4");
     z2vs(&t[21], _TEMLNG, "?1 ?2 ?3");
     z2vs(&t[22], _TEMLNG, "?1 ?2");
     z2vs(&t[23], _TEMLNG, "?1 ?2");
     z2vs(&t[24], _TEMLNG, "?1 ?2 ?3 ?4");
     z2vs(&t[25], _TEMLNG, "?1");
     z2vs(&t[26], _TEMLNG, ". . ?1 .");
     z2vs(&t[27], _TEMLNG, "?1 ?2");
     z2vs(&t[28], _TEMLNG, "?1 ', ' ?2");
     z2vs(&t[29], _TEMLNG, "?1 11 ?2 21 ?3");
     z2vs(&t[30], _TEMLNG, "1 ?1 11 ?2 21 ?3");
     z2vs(&t[31], _TEMLNG, "?1 =11 ?2 =21 ?3");
     z2vs(&t[32], _TEMLNG, "?1 +10 ?2 +10 ?3");
     z2vs(&t[33], _TEMLNG, "2 ?1 4 1 ?2 2 4 ?3 5 11 ?4");
     z2vs(&t[34], _TEMLNG, "2 ?1 +2 -3 ?2 +1 +2 ?3 +1 +6 ?4");
     z2vs(&t[35], _TEMLNG, "1 ?1 1 ?2");
     z2vs(&t[36], _TEMLNG, "?1 ?2 '.' ?3");
     z2vs(&t[37], _TEMLNG, "?1 ?2 4 ?3 6 ?4");
     z2vs(&t[38], _TEMLNG, "?1 ',' . . . ?2");
     z2vs(&t[39], _TEMLNG, "?1 3 . 'X' ?2 +1 . 'X' ?3 +1 .");
     z2vs(&t[40], _TEMLNG, "");
     z2vs(&t[41], _TEMLNG, "'a  ?1 .");
     z2vs(&t[42], _TEMLNG, "'a' ?12345 .");
     z2vs(&t[43], _TEMLNG, "'a' ?x2 .");
     z2vs(&t[44], _TEMLNG, "'a' ?7 .");
     z2vs(&t[45], _TEMLNG, "'a' ?1 ..");
     z2vs(&t[46], _TEMLNG, "'a' ?1 12345 .");
     z2vs(&t[47], _TEMLNG, "'a' ?1 3x .");
     z2vs(&t[48], _TEMLNG, "'a' ?1 =12345 .");
     z2vs(&t[49], _TEMLNG, "'a' ?1 =3x .");
     z2vs(&t[50], _TEMLNG, "'a' ?1 +12345 .");
     z2vs(&t[51], _TEMLNG, "'a' ?1 -3x .");
     z2vs(&t[52], _TEMLNG, "'a' x .");
     z2vs(&t[53], _TEMLNG, "?1 'x' ?3 'x' ?5");
     z2vs(&t[54], _TEMLNG, "?1 ?2 'x' ?3 ?4 'x' ?5 ?6");
     z2vs(&t[55], _TEMLNG, "?1 . 'x' ?3 . 'x' ?5 .");
     z2vs(&t[56], _TEMLNG, "?1 ?2 'x' ?3 ?4  . 'x' ?5 ?6");
     z2vs(&t[57], _TEMLNG, \
          "7 'CAT(' ?1 ')' 7 'OUT(' ?2 ')' 7 'LEVEL(' ?3 ')' ?4 ?5");
     z2vs(&t[58], _TEMLNG, \
          "5 '-' ?1 ' [' ?2 '] ' ?3 5 '-' ?4 ' \"' ?5 '\" ' ?6");
     z2vs(&t[59], _TEMLNG, \
          "5 '-' ?4 ' [' ?5 '] ' ?6 5 '-' ?1 ' \"' ?2 '\" ' ?3");
     z2vs(&t[60], _TEMLNG, "");
     z2vs(&t[61], _TEMLNG, "?1 ?2 ?3");
     z2vs(&t[62], _TEMLNG, "?1 ?2 ?3 ?4 ?5 ?6");
     z2vs(&t[63], _TEMLNG, "?1 ?2 . . ?3");
     z2vs(&t[64], _TEMLNG, "?1 5 ?2");
     z2vs(&t[65], _TEMLNG, "?1 ?2 15 ?3 3 ?4");
     z2vs(&t[66], _TEMLNG, "15 ?1 +16 =12 ?2 +2 1 ?3 +10");
     z2vs(&t[67], _TEMLNG, "1 ?1 +11 ?2 +6 ?3 -4 ?4");
     z2vs(&t[68], _TEMLNG, "1 ?1 =7 ?2 +6 ?3");
     z2vs(&t[69], _TEMLNG, "?1 'x' ?2 ?3 'y' . ?5 'z' ?6 .");
     z2vs(&t[70], _TEMLNG, "1 ?1 1 ?2 'a'");
     z2vs(&t[71], _TEMLNG, "?1 ''' ?2");
     z2vs(&t[72], _TEMLNG, "?1 ''' ?2 ''");
     z2vs(&t[73], _TEMLNG, "?1 ''' ?2 ''' '");
     z2vs(&t[74], _TEMLNG, "?1 - ?2");
     z2vs(&t[75], _TEMLNG, "?1 -9 ?2");
     z2vs(&t[76], _TEMLNG, "?1 99 ?2");
     z2vs(&t[77], _TEMLNG, "?1 9999999999 ?2");
     z2vs(&t[78], _TEMLNG, "?1 .. ?2");
     z2vs(&t[79], _TEMLNG, "?1 'a' 'c' ?2");

     z2vs(&e[ 1][1], _TOKLNG, "b");
     z2vs(&e[ 1][2], _TOKLNG, "");
     z2vs(&e[ 1][3], _TOKLNG, "");
     z2vs(&e[ 1][4], _TOKLNG, "");
     z2vs(&e[ 1][5], _TOKLNG, "");
     z2vs(&e[ 1][6], _TOKLNG, "");
     z2vs(&e[ 2][1], _TOKLNG, " ");
     z2vs(&e[ 2][2], _TOKLNG, " c");
     z2vs(&e[ 2][3], _TOKLNG, "");
     z2vs(&e[ 2][4], _TOKLNG, "");
     z2vs(&e[ 2][5], _TOKLNG, "");
     z2vs(&e[ 2][6], _TOKLNG, "");
     z2vs(&e[ 3][1], _TOKLNG, " b ");
     z2vs(&e[ 3][2], _TOKLNG, "");
     z2vs(&e[ 3][3], _TOKLNG, "");
     z2vs(&e[ 3][4], _TOKLNG, "");
     z2vs(&e[ 3][5], _TOKLNG, "");
     z2vs(&e[ 3][6], _TOKLNG, "");
     z2vs(&e[ 4][1], _TOKLNG, "a b ");
     z2vs(&e[ 4][2], _TOKLNG, "c");
     z2vs(&e[ 4][3], _TOKLNG, "");
     z2vs(&e[ 4][4], _TOKLNG, "");
     z2vs(&e[ 4][5], _TOKLNG, "");
     z2vs(&e[ 4][6], _TOKLNG, "");
     z2vs(&e[ 5][1], _TOKLNG, "a b ");
     z2vs(&e[ 5][2], _TOKLNG, "c");
     z2vs(&e[ 5][3], _TOKLNG, "");
     z2vs(&e[ 5][4], _TOKLNG, "");
     z2vs(&e[ 5][5], _TOKLNG, "");
     z2vs(&e[ 5][6], _TOKLNG, "");
     z2vs(&e[ 6][1], _TOKLNG, "a ");
     z2vs(&e[ 6][2], _TOKLNG, "b ");
     z2vs(&e[ 6][3], _TOKLNG, "");
     z2vs(&e[ 6][4], _TOKLNG, "");
     z2vs(&e[ 6][5], _TOKLNG, "");
     z2vs(&e[ 6][6], _TOKLNG, "");
     z2vs(&e[ 7][1], _TOKLNG, "a");
     z2vs(&e[ 7][2], _TOKLNG, "  b c  ");
     z2vs(&e[ 7][3], _TOKLNG, "");
     z2vs(&e[ 7][4], _TOKLNG, "");
     z2vs(&e[ 7][5], _TOKLNG, "");
     z2vs(&e[ 7][6], _TOKLNG, "");
     z2vs(&e[ 8][1], _TOKLNG, "  a  ");
     z2vs(&e[ 8][2], _TOKLNG, "");
     z2vs(&e[ 8][3], _TOKLNG, "");
     z2vs(&e[ 8][4], _TOKLNG, "");
     z2vs(&e[ 8][5], _TOKLNG, "");
     z2vs(&e[ 8][6], _TOKLNG, "");
     z2vs(&e[ 9][1], _TOKLNG, "b");
     z2vs(&e[ 9][2], _TOKLNG, "");
     z2vs(&e[ 9][3], _TOKLNG, "");
     z2vs(&e[ 9][4], _TOKLNG, "");
     z2vs(&e[ 9][5], _TOKLNG, "");
     z2vs(&e[ 9][6], _TOKLNG, "");
     z2vs(&e[10][1], _TOKLNG, "a");
     z2vs(&e[10][2], _TOKLNG, "b");
     z2vs(&e[10][3], _TOKLNG, " c");
     z2vs(&e[10][4], _TOKLNG, "");
     z2vs(&e[10][5], _TOKLNG, "");
     z2vs(&e[10][6], _TOKLNG, "");
     z2vs(&e[11][1], _TOKLNG, "a ");
     z2vs(&e[11][2], _TOKLNG, "b");
     z2vs(&e[11][3], _TOKLNG, " c ");
     z2vs(&e[11][4], _TOKLNG, "");
     z2vs(&e[11][5], _TOKLNG, "");
     z2vs(&e[11][6], _TOKLNG, "");
     z2vs(&e[12][1], _TOKLNG, "b c ");
     z2vs(&e[12][2], _TOKLNG, "a b ");
     z2vs(&e[12][3], _TOKLNG, "c");
     z2vs(&e[12][4], _TOKLNG, "");
     z2vs(&e[12][5], _TOKLNG, "");
     z2vs(&e[12][6], _TOKLNG, "");
     z2vs(&e[13][1], _TOKLNG, "b");
     z2vs(&e[13][2], _TOKLNG, "a");
     z2vs(&e[13][3], _TOKLNG, "c");
     z2vs(&e[13][4], _TOKLNG, "");
     z2vs(&e[13][5], _TOKLNG, "");
     z2vs(&e[13][6], _TOKLNG, "");
     z2vs(&e[14][1], _TOKLNG, "a ");
     z2vs(&e[14][2], _TOKLNG, "b  ");
     z2vs(&e[14][3], _TOKLNG, "c ");
     z2vs(&e[14][4], _TOKLNG, "b");
     z2vs(&e[14][5], _TOKLNG, "");
     z2vs(&e[14][6], _TOKLNG, "");
     z2vs(&e[15][1], _TOKLNG, "a");
     z2vs(&e[15][2], _TOKLNG, "b ");
     z2vs(&e[15][3], _TOKLNG, "c ");
     z2vs(&e[15][4], _TOKLNG, "d");
     z2vs(&e[15][5], _TOKLNG, "");
     z2vs(&e[15][6], _TOKLNG, "");
     z2vs(&e[16][1], _TOKLNG, "b");
     z2vs(&e[16][2], _TOKLNG, "");
     z2vs(&e[16][3], _TOKLNG, "c ");
     z2vs(&e[16][4], _TOKLNG, "d");
     z2vs(&e[16][5], _TOKLNG, "");
     z2vs(&e[16][6], _TOKLNG, "");
     z2vs(&e[17][1], _TOKLNG, "a ");
     z2vs(&e[17][2], _TOKLNG, "c ");
     z2vs(&e[17][3], _TOKLNG, "d");
     z2vs(&e[17][4], _TOKLNG, "");
     z2vs(&e[17][5], _TOKLNG, "");
     z2vs(&e[17][6], _TOKLNG, "");
     z2vs(&e[18][1], _TOKLNG, "a ");
     z2vs(&e[18][2], _TOKLNG, "c ");
     z2vs(&e[18][3], _TOKLNG, "d");
     z2vs(&e[18][4], _TOKLNG, "a");
     z2vs(&e[18][5], _TOKLNG, "");
     z2vs(&e[18][6], _TOKLNG, "");
     z2vs(&e[19][1], _TOKLNG, "");
     z2vs(&e[19][2], _TOKLNG, "a");
     z2vs(&e[19][3], _TOKLNG, "d");
     z2vs(&e[19][4], _TOKLNG, "c ");
     z2vs(&e[19][5], _TOKLNG, "");
     z2vs(&e[19][6], _TOKLNG, "a ");
     z2vs(&e[20][1], _TOKLNG, "a b c d");
     z2vs(&e[20][2], _TOKLNG, "a b c d");
     z2vs(&e[20][3], _TOKLNG, "c d");
     z2vs(&e[20][4], _TOKLNG, " c d");
     z2vs(&e[20][5], _TOKLNG, "");
     z2vs(&e[20][6], _TOKLNG, "");
     z2vs(&e[21][1], _TOKLNG, "Sirius");
     z2vs(&e[21][2], _TOKLNG, "Polaris");
     z2vs(&e[21][3], _TOKLNG, "Rigil");
     z2vs(&e[21][4], _TOKLNG, "");
     z2vs(&e[21][5], _TOKLNG, "");
     z2vs(&e[21][6], _TOKLNG, "");
     z2vs(&e[22][1], _TOKLNG, "moon");
     z2vs(&e[22][2], _TOKLNG, "");
     z2vs(&e[22][3], _TOKLNG, "");
     z2vs(&e[22][4], _TOKLNG, "");
     z2vs(&e[22][5], _TOKLNG, "");
     z2vs(&e[22][6], _TOKLNG, "");
     z2vs(&e[23][1], _TOKLNG, "moon");
     z2vs(&e[23][2], _TOKLNG, "Io Europa Callisto...");
     z2vs(&e[23][3], _TOKLNG, "");
     z2vs(&e[23][4], _TOKLNG, "");
     z2vs(&e[23][5], _TOKLNG, "");
     z2vs(&e[23][6], _TOKLNG, "");
     z2vs(&e[24][1], _TOKLNG, "Mercury");
     z2vs(&e[24][2], _TOKLNG, "Venus");
     z2vs(&e[24][3], _TOKLNG, "Earth");
     z2vs(&e[24][4], _TOKLNG, "  Mars    Jupiter ");
     z2vs(&e[24][5], _TOKLNG, "");
     z2vs(&e[24][6], _TOKLNG, "");
     z2vs(&e[25][1], _TOKLNG, "    Pluto   ");
     z2vs(&e[25][2], _TOKLNG, "");
     z2vs(&e[25][3], _TOKLNG, "");
     z2vs(&e[25][4], _TOKLNG, "");
     z2vs(&e[25][5], _TOKLNG, "");
     z2vs(&e[25][6], _TOKLNG, "");
     z2vs(&e[26][1], _TOKLNG, "Sirius");
     z2vs(&e[26][2], _TOKLNG, "");
     z2vs(&e[26][3], _TOKLNG, "");
     z2vs(&e[26][4], _TOKLNG, "");
     z2vs(&e[26][5], _TOKLNG, "");
     z2vs(&e[26][6], _TOKLNG, "");
     z2vs(&e[27][1], _TOKLNG, "Smith,");
     z2vs(&e[27][2], _TOKLNG, "John");
     z2vs(&e[27][3], _TOKLNG, "");
     z2vs(&e[27][4], _TOKLNG, "");
     z2vs(&e[27][5], _TOKLNG, "");
     z2vs(&e[27][6], _TOKLNG, "");
     z2vs(&e[28][1], _TOKLNG, "Smith");
     z2vs(&e[28][2], _TOKLNG, "John");
     z2vs(&e[28][3], _TOKLNG, "");
     z2vs(&e[28][4], _TOKLNG, "");
     z2vs(&e[28][5], _TOKLNG, "");
     z2vs(&e[28][6], _TOKLNG, "");
     z2vs(&e[29][1], _TOKLNG, "Clemens   ");
     z2vs(&e[29][2], _TOKLNG, " Samuel   ");
     z2vs(&e[29][3], _TOKLNG, " Mark Twain          ");
     z2vs(&e[29][4], _TOKLNG, "");
     z2vs(&e[29][5], _TOKLNG, "");
     z2vs(&e[29][6], _TOKLNG, "");
     z2vs(&e[30][1], _TOKLNG, "Clemens   ");
     z2vs(&e[30][2], _TOKLNG, " Samuel   ");
     z2vs(&e[30][3], _TOKLNG, " Mark Twain          ");
     z2vs(&e[30][4], _TOKLNG, "");
     z2vs(&e[30][5], _TOKLNG, "");
     z2vs(&e[30][6], _TOKLNG, "");
     z2vs(&e[31][1], _TOKLNG, "Clemens   ");
     z2vs(&e[31][2], _TOKLNG, " Samuel   ");
     z2vs(&e[31][3], _TOKLNG, " Mark Twain          ");
     z2vs(&e[31][4], _TOKLNG, "");
     z2vs(&e[31][5], _TOKLNG, "");
     z2vs(&e[31][6], _TOKLNG, "");
     z2vs(&e[32][1], _TOKLNG, "Clemens   ");
     z2vs(&e[32][2], _TOKLNG, " Samuel   ");
     z2vs(&e[32][3], _TOKLNG, " Mark Twain          ");
     z2vs(&e[32][4], _TOKLNG, "");
     z2vs(&e[32][5], _TOKLNG, "");
     z2vs(&e[32][6], _TOKLNG, "");
     z2vs(&e[33][1], _TOKLNG, "st");
     z2vs(&e[33][2], _TOKLNG, "a");
     z2vs(&e[33][3], _TOKLNG, "r");
     z2vs(&e[33][4], _TOKLNG, "s");
     z2vs(&e[33][5], _TOKLNG, "");
     z2vs(&e[33][6], _TOKLNG, "");
     z2vs(&e[34][1], _TOKLNG, "st");
     z2vs(&e[34][2], _TOKLNG, "a");
     z2vs(&e[34][3], _TOKLNG, "r");
     z2vs(&e[34][4], _TOKLNG, "s");
     z2vs(&e[34][5], _TOKLNG, "");
     z2vs(&e[34][6], _TOKLNG, "");
     z2vs(&e[35][1], _TOKLNG, \
          "Silas Marner, Felix Holt, Daniel Deronda, Middle");
     z2vs(&e[35][2], _TOKLNG, \
          "Silas Marner, Felix Holt, Daniel Deronda, Middle");
     z2vs(&e[35][3], _TOKLNG, "");
     z2vs(&e[35][4], _TOKLNG, "");
     z2vs(&e[35][5], _TOKLNG, "");
     z2vs(&e[35][6], _TOKLNG, "");
     z2vs(&e[36][1], _TOKLNG, "John");
     z2vs(&e[36][2], _TOKLNG, "     Q");
     z2vs(&e[36][3], _TOKLNG, "   Public");
     z2vs(&e[36][4], _TOKLNG, "");
     z2vs(&e[36][5], _TOKLNG, "");
     z2vs(&e[36][6], _TOKLNG, "");
     z2vs(&e[37][1], _TOKLNG, "R");
     z2vs(&e[37][2], _TOKLNG, "E");
     z2vs(&e[37][3], _TOKLNG, " X");
     z2vs(&e[37][4], _TOKLNG, " X");
     z2vs(&e[37][5], _TOKLNG, "");
     z2vs(&e[37][6], _TOKLNG, "");
     z2vs(&e[38][1], _TOKLNG, "4");
     z2vs(&e[38][2], _TOKLNG, "D'Artagnon");
     z2vs(&e[38][3], _TOKLNG, "");
     z2vs(&e[38][4], _TOKLNG, "");
     z2vs(&e[38][5], _TOKLNG, "");
     z2vs(&e[38][6], _TOKLNG, "");
     z2vs(&e[39][1], _TOKLNG, "RE");
     z2vs(&e[39][2], _TOKLNG, "X");
     z2vs(&e[39][3], _TOKLNG, "X");
     z2vs(&e[39][4], _TOKLNG, "");
     z2vs(&e[39][5], _TOKLNG, "");
     z2vs(&e[39][6], _TOKLNG, "");
     z2vs(&e[40][1], _TOKLNG, "");
     z2vs(&e[40][2], _TOKLNG, "");
     z2vs(&e[40][3], _TOKLNG, "");
     z2vs(&e[40][4], _TOKLNG, "");
     z2vs(&e[40][5], _TOKLNG, "");
     z2vs(&e[40][6], _TOKLNG, "");
     z2vs(&e[41][1], _TOKLNG, "");
     z2vs(&e[41][2], _TOKLNG, "");
     z2vs(&e[41][3], _TOKLNG, "");
     z2vs(&e[41][4], _TOKLNG, "");
     z2vs(&e[41][5], _TOKLNG, "");
     z2vs(&e[41][6], _TOKLNG, "");
     z2vs(&e[42][1], _TOKLNG, "");
     z2vs(&e[42][2], _TOKLNG, "");
     z2vs(&e[42][3], _TOKLNG, "");
     z2vs(&e[42][4], _TOKLNG, "");
     z2vs(&e[42][5], _TOKLNG, "");
     z2vs(&e[42][6], _TOKLNG, "");
     z2vs(&e[43][1], _TOKLNG, "");
     z2vs(&e[43][2], _TOKLNG, "");
     z2vs(&e[43][3], _TOKLNG, "");
     z2vs(&e[43][4], _TOKLNG, "");
     z2vs(&e[43][5], _TOKLNG, "");
     z2vs(&e[43][6], _TOKLNG, "");
     z2vs(&e[44][1], _TOKLNG, "");
     z2vs(&e[44][2], _TOKLNG, "");
     z2vs(&e[44][3], _TOKLNG, "");
     z2vs(&e[44][4], _TOKLNG, "");
     z2vs(&e[44][5], _TOKLNG, "");
     z2vs(&e[44][6], _TOKLNG, "");
     z2vs(&e[45][1], _TOKLNG, "");
     z2vs(&e[45][2], _TOKLNG, "");
     z2vs(&e[45][3], _TOKLNG, "");
     z2vs(&e[45][4], _TOKLNG, "");
     z2vs(&e[45][5], _TOKLNG, "");
     z2vs(&e[45][6], _TOKLNG, "");
     z2vs(&e[46][1], _TOKLNG, "");
     z2vs(&e[46][2], _TOKLNG, "");
     z2vs(&e[46][3], _TOKLNG, "");
     z2vs(&e[46][4], _TOKLNG, "");
     z2vs(&e[46][5], _TOKLNG, "");
     z2vs(&e[46][6], _TOKLNG, "");
     z2vs(&e[47][1], _TOKLNG, "");
     z2vs(&e[47][2], _TOKLNG, "");
     z2vs(&e[47][3], _TOKLNG, "");
     z2vs(&e[47][4], _TOKLNG, "");
     z2vs(&e[47][5], _TOKLNG, "");
     z2vs(&e[47][6], _TOKLNG, "");
     z2vs(&e[48][1], _TOKLNG, "");
     z2vs(&e[48][2], _TOKLNG, "");
     z2vs(&e[48][3], _TOKLNG, "");
     z2vs(&e[48][4], _TOKLNG, "");
     z2vs(&e[48][5], _TOKLNG, "");
     z2vs(&e[48][6], _TOKLNG, "");
     z2vs(&e[49][1], _TOKLNG, "");
     z2vs(&e[49][2], _TOKLNG, "");
     z2vs(&e[49][3], _TOKLNG, "");
     z2vs(&e[49][4], _TOKLNG, "");
     z2vs(&e[49][5], _TOKLNG, "");
     z2vs(&e[49][6], _TOKLNG, "");
     z2vs(&e[50][1], _TOKLNG, "");
     z2vs(&e[50][2], _TOKLNG, "");
     z2vs(&e[50][3], _TOKLNG, "");
     z2vs(&e[50][4], _TOKLNG, "");
     z2vs(&e[50][5], _TOKLNG, "");
     z2vs(&e[50][6], _TOKLNG, "");
     z2vs(&e[51][1], _TOKLNG, "");
     z2vs(&e[51][2], _TOKLNG, "");
     z2vs(&e[51][3], _TOKLNG, "");
     z2vs(&e[51][4], _TOKLNG, "");
     z2vs(&e[51][5], _TOKLNG, "");
     z2vs(&e[51][6], _TOKLNG, "");
     z2vs(&e[52][1], _TOKLNG, "");
     z2vs(&e[52][2], _TOKLNG, "");
     z2vs(&e[52][3], _TOKLNG, "");
     z2vs(&e[52][4], _TOKLNG, "");
     z2vs(&e[52][5], _TOKLNG, "");
     z2vs(&e[52][6], _TOKLNG, "");
     z2vs(&e[53][1], _TOKLNG, "  a  ");
     z2vs(&e[53][2], _TOKLNG, "");
     z2vs(&e[53][3], _TOKLNG, "  b  ");
     z2vs(&e[53][4], _TOKLNG, "");
     z2vs(&e[53][5], _TOKLNG, "  c  ");
     z2vs(&e[53][6], _TOKLNG, "");
     z2vs(&e[54][1], _TOKLNG, "a");
     z2vs(&e[54][2], _TOKLNG, " ");
     z2vs(&e[54][3], _TOKLNG, "b");
     z2vs(&e[54][4], _TOKLNG, " ");
     z2vs(&e[54][5], _TOKLNG, "c");
     z2vs(&e[54][6], _TOKLNG, " ");
     z2vs(&e[55][1], _TOKLNG, "a");
     z2vs(&e[55][2], _TOKLNG, "");
     z2vs(&e[55][3], _TOKLNG, "b");
     z2vs(&e[55][4], _TOKLNG, "");
     z2vs(&e[55][5], _TOKLNG, "c");
     z2vs(&e[55][6], _TOKLNG, "");
     z2vs(&e[56][1], _TOKLNG, "a");
     z2vs(&e[56][2], _TOKLNG, " b  ");
     z2vs(&e[56][3], _TOKLNG, "c");
     z2vs(&e[56][4], _TOKLNG, "d");
     z2vs(&e[56][5], _TOKLNG, "e");
     z2vs(&e[56][6], _TOKLNG, " f  z  ");
     z2vs(&e[57][1], _TOKLNG, "cat");
     z2vs(&e[57][2], _TOKLNG, "dsn");
     z2vs(&e[57][3], _TOKLNG, "lvl");
     z2vs(&e[57][4], _TOKLNG, "CLUSTER");
     z2vs(&e[57][5], _TOKLNG, "ALL");
     z2vs(&e[57][6], _TOKLNG, "");
     z2vs(&e[58][1], _TOKLNG, "v");
     z2vs(&e[58][2], _TOKLNG, "aeiou");
     z2vs(&e[58][3], _TOKLNG, "wordlist.txt");
     z2vs(&e[58][4], _TOKLNG, "v [aeiou] wordlist.txt");
     z2vs(&e[58][5], _TOKLNG, "");
     z2vs(&e[58][6], _TOKLNG, "");
     z2vs(&e[59][1], _TOKLNG, "v");
     z2vs(&e[59][2], _TOKLNG, "xyz");
     z2vs(&e[59][3], _TOKLNG, "wordlist.txt");
     z2vs(&e[59][4], _TOKLNG, "v \"xyz\" wordlist.txt");
     z2vs(&e[59][5], _TOKLNG, "");
     z2vs(&e[59][6], _TOKLNG, "");
     z2vs(&e[60][1], _TOKLNG, "");
     z2vs(&e[60][2], _TOKLNG, "");
     z2vs(&e[60][3], _TOKLNG, "");
     z2vs(&e[60][4], _TOKLNG, "");
     z2vs(&e[60][5], _TOKLNG, "");
     z2vs(&e[60][6], _TOKLNG, "");
     z2vs(&e[61][1], _TOKLNG, "Experience");
     z2vs(&e[61][2], _TOKLNG, "is");
     z2vs(&e[61][3], _TOKLNG, "the best teacher.");
     z2vs(&e[61][4], _TOKLNG, "");
     z2vs(&e[61][5], _TOKLNG, "");
     z2vs(&e[61][6], _TOKLNG, "");
     z2vs(&e[62][1], _TOKLNG, "Experience");
     z2vs(&e[62][2], _TOKLNG, "is");
     z2vs(&e[62][3], _TOKLNG, "the");
     z2vs(&e[62][4], _TOKLNG, "best");
     z2vs(&e[62][5], _TOKLNG, "teacher.");
     z2vs(&e[62][6], _TOKLNG, "");
     z2vs(&e[63][1], _TOKLNG, "Experience");
     z2vs(&e[63][2], _TOKLNG, "is");
     z2vs(&e[63][3], _TOKLNG, "teacher.");
     z2vs(&e[63][4], _TOKLNG, "");
     z2vs(&e[63][5], _TOKLNG, "");
     z2vs(&e[63][6], _TOKLNG, "");
     z2vs(&e[64][1], _TOKLNG, "Expe");
     z2vs(&e[64][2], _TOKLNG, "rience is the best teacher.");
     z2vs(&e[64][3], _TOKLNG, "");
     z2vs(&e[64][4], _TOKLNG, "");
     z2vs(&e[64][5], _TOKLNG, "");
     z2vs(&e[64][6], _TOKLNG, "");
     z2vs(&e[65][1], _TOKLNG, "Experience");
     z2vs(&e[65][2], _TOKLNG, "is ");
     z2vs(&e[65][3], _TOKLNG, "the best teacher.");
     z2vs(&e[65][4], _TOKLNG, "perience is the best teacher.");
     z2vs(&e[65][5], _TOKLNG, "");
     z2vs(&e[65][6], _TOKLNG, "");
     z2vs(&e[66][1], _TOKLNG, "the best teacher");
     z2vs(&e[66][2], _TOKLNG, "is");
     z2vs(&e[66][3], _TOKLNG, "Experience");
     z2vs(&e[66][4], _TOKLNG, "");
     z2vs(&e[66][5], _TOKLNG, "");
     z2vs(&e[66][6], _TOKLNG, "");
     z2vs(&e[67][1], _TOKLNG, "Experience ");
     z2vs(&e[67][2], _TOKLNG, "is the");
     z2vs(&e[67][3], _TOKLNG, " best teacher.");
     z2vs(&e[67][4], _TOKLNG, " the best teacher.");
     z2vs(&e[67][5], _TOKLNG, "");
     z2vs(&e[67][6], _TOKLNG, "");
     z2vs(&e[68][1], _TOKLNG, "Experi");
     z2vs(&e[68][2], _TOKLNG, "ence i");
     z2vs(&e[68][3], _TOKLNG, "s the best teacher.");
     z2vs(&e[68][4], _TOKLNG, "");
     z2vs(&e[68][5], _TOKLNG, "");
     z2vs(&e[68][6], _TOKLNG, "");
     z2vs(&e[69][1], _TOKLNG, "     ");
     z2vs(&e[69][2], _TOKLNG, "");
     z2vs(&e[69][3], _TOKLNG, "");
     z2vs(&e[69][4], _TOKLNG, "");
     z2vs(&e[69][5], _TOKLNG, "");
     z2vs(&e[69][6], _TOKLNG, "");
     z2vs(&e[70][1], _TOKLNG, "a b c");
     z2vs(&e[70][2], _TOKLNG, "");
     z2vs(&e[70][3], _TOKLNG, "");
     z2vs(&e[70][4], _TOKLNG, "");
     z2vs(&e[70][5], _TOKLNG, "");
     z2vs(&e[70][6], _TOKLNG, "");
     z2vs(&e[71][1], _TOKLNG, "");
     z2vs(&e[71][2], _TOKLNG, "");
     z2vs(&e[71][3], _TOKLNG, "");
     z2vs(&e[71][4], _TOKLNG, "");
     z2vs(&e[71][5], _TOKLNG, "");
     z2vs(&e[71][6], _TOKLNG, "");
     z2vs(&e[72][1], _TOKLNG, "");
     z2vs(&e[72][2], _TOKLNG, "");
     z2vs(&e[72][3], _TOKLNG, "");
     z2vs(&e[72][4], _TOKLNG, "");
     z2vs(&e[72][5], _TOKLNG, "");
     z2vs(&e[72][6], _TOKLNG, "");
     z2vs(&e[73][1], _TOKLNG, "");
     z2vs(&e[73][2], _TOKLNG, "");
     z2vs(&e[73][3], _TOKLNG, "");
     z2vs(&e[73][4], _TOKLNG, "");
     z2vs(&e[73][5], _TOKLNG, "");
     z2vs(&e[73][6], _TOKLNG, "");
     z2vs(&e[74][1], _TOKLNG, "");
     z2vs(&e[74][2], _TOKLNG, "");
     z2vs(&e[74][3], _TOKLNG, "");
     z2vs(&e[74][4], _TOKLNG, "");
     z2vs(&e[74][5], _TOKLNG, "");
     z2vs(&e[74][6], _TOKLNG, "");
     z2vs(&e[75][1], _TOKLNG, "a b c");
     z2vs(&e[75][2], _TOKLNG, "a b c");
     z2vs(&e[75][3], _TOKLNG, "");
     z2vs(&e[75][4], _TOKLNG, "");
     z2vs(&e[75][5], _TOKLNG, "");
     z2vs(&e[75][6], _TOKLNG, "");
     z2vs(&e[76][1], _TOKLNG, "a b c");
     z2vs(&e[76][2], _TOKLNG, "");
     z2vs(&e[76][3], _TOKLNG, "");
     z2vs(&e[76][4], _TOKLNG, "");
     z2vs(&e[76][5], _TOKLNG, "");
     z2vs(&e[76][6], _TOKLNG, "");
     z2vs(&e[77][1], _TOKLNG, "");
     z2vs(&e[77][2], _TOKLNG, "");
     z2vs(&e[77][3], _TOKLNG, "");
     z2vs(&e[77][4], _TOKLNG, "");
     z2vs(&e[77][5], _TOKLNG, "");
     z2vs(&e[77][6], _TOKLNG, "");
     z2vs(&e[78][1], _TOKLNG, "");
     z2vs(&e[78][2], _TOKLNG, "");
     z2vs(&e[78][3], _TOKLNG, "");
     z2vs(&e[78][4], _TOKLNG, "");
     z2vs(&e[78][5], _TOKLNG, "");
     z2vs(&e[78][6], _TOKLNG, "");
     z2vs(&e[79][1], _TOKLNG, "");
     z2vs(&e[79][2], _TOKLNG, "");
     z2vs(&e[79][3], _TOKLNG, "");
     z2vs(&e[79][4], _TOKLNG, "");
     z2vs(&e[79][5], _TOKLNG, "");
     z2vs(&e[79][6], _TOKLNG, "");

     misc.ntokens   = _TOKDIM;
     misc.qtemplate = '\'';
     misc.varprefix = '?';
     misc.maxlngtok = _TOKLNG;

     int maxlng = _STRLNG;
     if(_TEMLNG > maxlng) maxlng = _TEMLNG;
     if(_TOKLNG > maxlng) maxlng = _TOKLNG;
     char *z = malloc(++maxlng);

/**********************************************************************/

     short itok(const short n)
     {
       char c[10] = "0123456789";
       char s[3];
       char *p;

       s[0] = misc.varprefix;
       s[1] = c[n];
       s[2] = '\0';
       vs2z(&template, z);
       p = strstr(z, s);

       if(p == NULL)
         return 0;
       else
         return(p - z + 1);
     }

/**********************************************************************/

     short m = 1, n = 79;
     if(argc > 1)
     {
       sscanf(argv[1], "%hi", &m);
       if(argc > 2)
         sscanf(argv[2], "%hi", &n);
       else
         n = m;
     }

     char q;
     if(misc.qtemplate == '"')
       q = '\'';
     else
       q = '"';

     short i;
     for(i = m; i <= n; ++i)
     {
       if(t[i].lng > 0)
       {
         printf("\n---%i---", i);
         string = s[i];
         template = t[i];

         printf("\nS=%c%s%c", q, vs2z(&string, z), q);
         rxparse(&string,
                 &template,
                 tokens,
                 &misc);
         printf("\nT=%c%s%c", q, vs2z(&template, z), q);

         if(misc.retcode != 0)
         {
           switch(misc.retcode)
           {
             case 20 :
               printf("\n%i: LENGTH(TEMPLATE) > %5i !", \
                      misc.retcode, misc.xtemplate);
               break;
             case 24 :
               printf("\n%i: NTOKENS > %5i !", \
                      misc.retcode, misc.xtokens);
               printf("\n");
               i = n + 1;
               break;
             case 28 :
               printf("\n%i: LENGTH(TOKENS) > %5i !", \
                      misc.retcode, misc.maxlngtok);
               printf("\n");
               i = n + 1;
               break;
             default :
               if(misc.xtemplate != 0)
                 printf("\n%2i:%s!", \
                        misc.retcode, blankz(misc.xtemplate - 1, z));
               break;
           }
         }

         else
         {
           short j, jj;
           for(j = 1; j <= misc.xtokens; ++j)
           {
             jj = j - 1;
             if(itok(j) > 0)
             {
               printf("\n%c%i=%c%s%c", \
                      misc.varprefix, j, q, vs2z(&tokens[jj], z), q);
               if(vscmp(&tokens[jj], &e[i][j]))
                 printf("\nOK");
               else
                 printf("\n!!=%c%s%c", q, vs2z(&e[i][j], z), q);
             }
           }
         }

         printf("\n");
       }
     }

     printf("\n");
     free(z);
     return 0;
   }
