/* REXX */
   arg par 'TRACE(' trc ')'
   if trc <> '' then,
     trace value strip(trc)
 
   s.1  = 'a b c'
   t.1  = '"a" ?1 .'
 
   s.2  = 'a b c'
   t.2  = '"a" ?1 "b" ?2'
 
   s.3  = 'a b c'
   t.3  = '"a" ?1 "c" ?2'
 
   s.4  = 'a b c'
   t.4  = '?1 5 ?2'
 
   s.5  = 'a b c'
   t.5  = '1 ?1 5 ?2'
 
   s.6  = 'a b c'
   t.6  = '?1 +2 ?2 +2 .'
 
   s.7  = 'a   b c  '
   t.7  = '?1 ?2'
 
   s.8  = '  a  '
   t.8  = '?1'
 
   s.9  = 'a b c'
   t.9  = '. ?1 .'
 
   s.10 = 'a,b, c'
   t.10 = '?1 "," ?2 "," ?3'
 
   s.11 = 'a b c '
   t.11 = '?1 =3 ?2 =4 ?3'
 
   s.12 = 'a b c '
   t.12 = '3 ?1 1 ?2 5 ?3 6'
 
   s.13 = 'a b c '
   t.13 = '3 ?1 4 1 ?2 2 5 ?3 6'
 
   s.14 = 'a b  c '
   t.14 = '?1 +2 ?2 +3 ?3 -3 ?4 .'
 
   s.15 = 'a b c d'
   t.15 = '?1 ?2 5 ?3 7 ?4'
 
   s.16 = 'a b c d'
   t.16 = '"a" ?1 ?2 5 ?3 7 ?4'
 
   s.17 = 'a b c d'
   t.17 = '?1 "b" +2 ?2 +2 ?3'
 
   s.18 = 'a b c d'
   t.18 = '?1 "b" +2 ?2 +2 ?3 -6 ?4 .'
 
   s.19 = 'a b c d'
   t.19 = '?6 "b" +2 ?4 +2 ?3 -6 ?2 .',
 
   s.20 = 'a b c d'
   t.20 = '1 ?1 0 1 ?2 1 5 ?3 4 ?4 4'
 
   s.21 = 'Sirius Polaris Rigil'
   t.21 = '?1 ?2 ?3'
 
   s.22 = 'moon'
   t.22 = '?1 ?2'
 
   s.23 = 'moon Io Europa Callisto...'
   t.23 = '?1 ?2'
 
   s.24 = 'Mercury Venus   Earth   Mars    Jupiter '
   t.24 = '?1 ?2 ?3 ?4'
 
   s.25 = '    Pluto   '
   t.25 = '?1'
 
   s.26 = 'Arcturus Betelgeuse Sirius Rigil'
   t.26 = '. . ?1 .'
 
   s.27 = 'Smith, John'
   t.27 = '?1 ?2'
 
   s.28 = 'Smith, John'
   t.28 = '?1 ", " ?2'
 
   s.29 = 'Clemens    Samuel    Mark Twain          '
   t.29 = '?1 11 ?2 21 ?3'
 
   s.30 = 'Clemens    Samuel    Mark Twain          '
   t.30 = '1 ?1 11 ?2 21 ?3'
 
   s.31 = 'Clemens    Samuel    Mark Twain          '
   t.31 = '?1 =11 ?2 =21 ?3'
 
   s.32 = 'Clemens    Samuel    Mark Twain          '
   t.32 = '?1 +10 ?2 +10 ?3'
 
   s.33 = 'astronomers'
   t.33 = '2 ?1 4 1 ?2 2 4 ?3 5 11 ?4'
 
   s.34 = 'astronomers'
   t.34 = '2 ?1 +2 -3 ?2 +1 +2 ?3 +1 +6 ?4'
 
   s.35 = 'Silas Marner, Felix Holt, Daniel Deronda, Middle'
   t.35 = '1 ?1 1 ?2'
 
   s.36 = '     John      Q.   Public'
   t.36 = '?1 ?2 "." ?3'
 
   s.37 = 'R E X X'
   t.37 = '?1 ?2 4 ?3 6 ?4'
 
   s.38 = '4,Porthos Athos Aramis D''Artagnon'
   t.38 = '?1 "," . . . ?2'
 
   s.39 = 'REstructured eXtended eXecutor'
   t.39 = '?1 3 . "X" ?2 +1 . "X" ?3 +1 .'
 
   s.40 = ''
   t.40 = ''
 
   s.41 = 'a b c'
   t.41 = '"a  ?1 .'
 
   s.42 = 'a b c'
   t.42 = '"a" ?12345 .'
 
   s.43 = 'a b c'
   t.43 = '"a" ?%2 .'
 
   s.44 = 'a b c'
   t.44 = '"a" ?7 .'
 
   s.45 = 'a b c'
   t.45 = '"a" ?1 ..'
 
   s.46 = 'a b c'
   t.46 = '"a" ?1 9999999999 .'
 
   s.47 = 'a b c'
   t.47 = '"a" ?1 3x .'
 
   s.48 = 'a b c'
   t.48 = '"a" ?1 =9999999999 .'
 
   s.49 = 'a b c'
   t.49 = '"a" ?1 =3x .'
 
   s.50 = 'a b c'
   t.50 = '"a" ?1 +9999999999 .'
 
   s.51 = 'a b c'
   t.51 = '"a" ?1 -3x .'
 
   s.52 = 'a b c'
   t.52 = '"a" % .'
 
   s.53 = '  a  x  b  x  c  '
   t.53 = '?1 "x" ?3 "x" ?5'
 
   s.54 = '  a  x  b  x  c  '
   t.54 = '?1 ?2 "x" ?3 ?4 "x" ?5 ?6'
 
   s.55 = '  a  x  b  x  c  '
   t.55 = '?1 . "x" ?3 . "x" ?5 .'
 
   s.56 = '  a  b  x  c  d  z  x  e  f  z  '
   t.56 = '?1 ?2 "x" ?3 ?4  . "x" ?5 ?6'
 
   s.57 = 'LISTC CAT(cat) OUT(dsn) LEVEL(lvl) CLUSTER ALL'
   t.57 = '7 "CAT(" ?1 ")" 7 "OUT(" ?2 ")" 7 "LEVEL(" ?3 ")" ?4 ?5'
 
   s.58 = 'grep -v [aeiou] wordlist.txt'
   t.58 = '5 "-" ?1 " [" ?2 "] " ?3 5 "-" ?4 " ''" ?5 "'' " ?6'
 
   s.59 = 'grep -v ''xyz'' wordlist.txt'
   t.59 = '5 "-" ?4 " [" ?5 "] " ?6 5 "-" ?1 " ''" ?2 "'' " ?3'
 
   s.60 = ''
   t.60 = ''
 
   s.61 = 'Experience is the best teacher.'
   t.61 = '?1 ?2 ?3'
 
   s.62 = 'Experience is the best teacher.'
   t.62 = '?1 ?2 ?3 ?4 ?5 ?6'
 
   s.63 = 'Experience is the best teacher.'
   t.63 = '?1 ?2 . . ?3'
 
   s.64 = 'Experience is the best teacher.'
   t.64 = '?1 5 ?2'
 
   s.65 = 'Experience is the best teacher.'
   t.65 = '?1 ?2 15 ?3 3 ?4'
 
   s.66 = 'Experience is the best teacher.'
   t.66 = '15 ?1 +16 =12 ?2 +2 1 ?3 +10'
 
   s.67 = 'Experience is the best teacher.'
   t.67 = '1 ?1 +11 ?2 +6 ?3 -4 ?4'
 
   s.68 = 'Experience is the best teacher.'
   t.68 = '1 ?1 =7 ?2 +6 ?3'
 
   s.69 = '     x     y    z    '
   t.69 = '?1 "x" ?2 ?3 "y" . ?5 "z" ?6 .'
 
   s.70 = 'a b c'
   t.70 = '1 ?1 1 ?2 "a"'
 
   s.71 = 'a "b"'
   t.71 = '?1 """ ?2'
 
   s.72 = 'a "b"'
   t.72 = '?1 """ ?2 ""'
 
   s.73 = 'a "b"'
   t.73 = '?1 """ ?2 """ "'
 
   s.74 = 'a b c'
   t.74 = '?1 - ?2'
 
   s.75 = 'a b c'
   t.75 = '?1 -9 ?2'
 
   s.76 = 'a b c'
   t.76 = '?1 99 ?2'
 
   s.77 = 'a b c'
   t.77 = '?1 9999999999 ?2'
 
   s.78 = 'a b c'
   t.78 = '?1 .. ?2'
 
   s.79 = 'a b c'
   t.79 = '?1 "a" "c" ?2'
 
   parse var par m n .
   if m = '' then,
     m = 1
   if n = '' then,
     n = 79
 
   signal on syntax
   lgo:
   do i = m to n
     if t.i = '' then,
       iterate
     say '---'i'---'
     say 'S='''s.i''''
     say 'T='''t.i''''
     interpret 'parse var s.i 't.i
     do j = 1 to 7
       if value('?'j) = '?'j then,
         iterate
       interpret 'r = ?'j
       say '?'j'='''r''''
       say 'OK'
       interpret 'drop ?'j
     end
     say ''
   end
   return
 
   syntax:
   say 'error' rc 'line' sigl':' errortext(rc)
   say ''
   m = i + 1
   signal lgo
