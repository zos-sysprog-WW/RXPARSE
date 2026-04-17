/* rxparse.c */

   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <string.h>
   #include "rxpaif.h"

/**********************************************************************/

   short min(const short v1, const short v2)
   {
     if(v1 <= v2)
       return v1;
     else
       return v2;
   }

/**********************************************************************/

   short max(const short v1, const short v2)
   {
     if(v1 >= v2)
       return v1;
     else
       return v2;
   }

/**********************************************************************/

   void vscpy(void *varstr, const void *str, const short len, short x)
   {
     _VARSTR(*vs,)

     vs = varstr;
     vs->lng = len;
     strncpy(vs->dat, str, (size_t)len);

     return;
   }

/**********************************************************************/

   short vsindex(const void *varstr1, const void *varstr2)
   {
     _VARSTR(const *vs1,)
     _VARSTR(const *vs2,)

     vs1 = varstr1;
     vs2 = varstr2;
     if(vs2->lng > vs1->lng)
       return -1;

     if(vs2->lng == vs1->lng)
       if(strncmp(vs1->dat, vs2->dat, (size_t)vs1->lng) == 0)
         return 0;

     for(short i = 0; i <= (vs1->lng - vs2->lng); ++i)
       if(strncmp(&vs1->dat[i], vs2->dat, (size_t)vs2->lng) == 0)
         return i;

     return -1;
   }

/**********************************************************************/

   _Bool vsblank(const void *varstr)
   {
     _VARSTR(const *vs,)
     short i;

     vs = varstr;
     if(vs->lng == 0)
       return true;

     for(i = 0; i < vs->lng; ++i)
       if(vs->dat[i] != ' ')
         return false;

     return true;
   }

/**********************************************************************/

   void vsstripl(void *varstr)
   {
     _VARSTR(*vs,)
     short i, j;

     vs = varstr;
     j = vs->lng;
     for(i = 0; i < j; ++i)
       if(vs->dat[i] != ' ')
       {
         if(i > 0)
           vscpy(vs, &vs->dat[i], j - i,  1);
         break;
       }
     if(i >= j)
       vs->lng = 0;

     return;
   }

/**********************************************************************/

   short vsvernum(const void *varstr)
   {
     _VARSTR(const *vs,)
     short i;

     vs = varstr;
     for(i = 0; i < vs->lng; ++i)
       if(vs->dat[i] < '0' || vs->dat[i] > '9')
         return i;

     return -1;
   }

/**********************************************************************/

   void rxparse(const _STRING *string,
                const _TEMPLATE *template,
                _TOKEN tokens[],
                _MISC *misc)
   {
     struct
     {
       short pos;
       short len;
       short num;
       char  typ;
     } tt[(template->lng + 1) / 2];
     short ntt = -1;

     short i, j, k, l;
     _Bool q = false, x = false;
     char c;
     _VARSTR(tstr, template->lng)
     _VARSTR(temp, template->lng + 1)
     _VARSTR(patt, template->lng)
     short sl, ms, me, ii;
     short ss, se, ts, te;
     _VARSTR(work, string->lng)

     short lvs = misc->maxlngtok % sizeof(short);
     if(lvs > 0)
       lvs = sizeof(short) - lvs;
     lvs = sizeof(short) + misc->maxlngtok + lvs;

/**********************************************************************/

     void err(const char et, const short ei)
     {
       if(et == 'q')
         misc->retcode = 12; /* unmatched quote in template */
       else
       if(et == 't')
         misc->retcode = 8;  /* invalid template */
       else
       if(et == 'n')
         misc->retcode = 16; /* more '?n' in template than tokens */
       misc->xtemplate = ei + 1;

       return;
     }

/**********************************************************************/

     void ttok(const short tpos, const short tlen)
     {
       char c, cq;
       short i, v;
       char wrk[string->lng];

       ++ntt;
       tt[ntt].pos = tpos;
       tt[ntt].len = tlen;
       tt[ntt].num = 0;
       c = template->dat[tpos];

       if(c == misc->qtemplate)
       {
         tt[ntt].pos = tstr.lng;
         tt[ntt].len = 0;
         tt[ntt].typ = 's';
         vscpy(&patt, &template->dat[tpos + 1], tlen - 2,  2);
         ++patt.lng;
         patt.dat[patt.lng] = ' ';
         for(i = 0; i < (patt.lng - 1); ++i)
         {
           cq = patt.dat[i];
           tstr.dat[tstr.lng] = cq;
           ++tstr.lng;
           ++tt[ntt].len;
           if(cq == c)
             if(patt.dat[i + 1] == c)
               ++i;
         }
       }

       else
       if(c == misc->varprefix)
       {
         tt[ntt].typ = '?';
         if(tlen > 5)
           err('t', tpos - 1 + tlen);
         else
         {
           vscpy(&patt, &template->dat[tpos + 1], tlen - 1,  3);
           v = vsvernum(&patt);
           if(v >= 0)
             err('t', tpos + 1 + v);
         }
         if(misc->retcode == 0)
         {
           strncpy(wrk, patt.dat, (size_t)patt.lng);
           wrk[patt.lng] = '\0';
           sscanf(wrk, "%hi", &tt[ntt].num);
           if(tt[ntt].num > misc->ntokens)
             err('n', tpos + 1);
           else
             misc->xtokens = max(tt[ntt].num, misc->xtokens);
         }
       }

       else
       if(c == '.')
       {
         tt[ntt].typ = '.';
         if(tlen > 1)
           err('t', tpos + 1);
       }

       else
       if(c >= '0' && c <= '9')
       {
         tt[ntt].typ = 'p';
         if(tlen > 4)
           err('t', tpos - 1 + tlen);
         else
         {
           vscpy(&patt, &template->dat[tpos], tlen,  4);
           v = vsvernum(&patt);
           if(v >= 0)
             err('t', tpos + v);
         }
         if(misc->retcode == 0)
         {
           strncpy(wrk, patt.dat, (size_t)patt.lng);
           wrk[patt.lng] = '\0';
           sscanf(wrk, "%hi", &tt[ntt].num);
         }
       }

       else
       if(c == '=')
       {
         tt[ntt].typ = 'p';
         if(tlen < 2 || tlen > 5)
           err('t', tpos - 1 + tlen);
         else
         {
           vscpy(&patt, &template->dat[tpos + 1], tlen - 1,  5);
           v = vsvernum(&patt);
           if(v >= 0)
             err('t', tpos + 1 + v);
         }
         if(misc->retcode == 0)
         {
           strncpy(wrk, patt.dat, (size_t)patt.lng);
           wrk[patt.lng] = '\0';
           sscanf(wrk, "%hi", &tt[ntt].num);
         }
       }

       else
       if(c == '+' || c == '-')
       {
         tt[ntt].typ = 'o';
         if(tlen < 2 || tlen > 5)
           err('t', tpos - 1 + tlen);
         else
         {
           vscpy(&patt, &template->dat[tpos + 1], tlen - 1,  6);
           v = vsvernum(&patt);
           if(v >= 0)
             err('t', tpos + 1 + v);
         }
         if(misc->retcode == 0)
         {
           strncpy(wrk, patt.dat, (size_t)patt.lng);
           wrk[patt.lng] = '\0';
           sscanf(wrk, "%hi", &tt[ntt].num);
           if(c == '-')
             tt[ntt].num = -tt[ntt].num;
         }
       }

       else
         err('t', tpos);

       return;
     }

/**********************************************************************/

     void words(const short ss, const short se, \
                const short ts, const short te, const char ty)
     {
       _VARSTR(part, string->lng)
       short i, j;
       char wtyp;

       void *vs0, *vs;
       _TOKEN *token;
       vs0 = tokens;

       if(se > ss)
         vscpy(&part, &string->dat[ss], se - ss,  7);
       else
         if(ty == 's')
           part.lng = 0;
         else
           vscpy(&part, &string->dat[ss], sl + 1 - ss,  8);

       for(i = ts; i <= te; ++i)
       {
         wtyp = tt[i].typ;
         if(wtyp == '?')
         {
           vs = vs0 + ((tt[i].num - 1) * lvs);
           token = vs;
         }

         if(i == te)
           if(wtyp == '?')
             vscpy(token, part.dat, part.lng,  9);
           else;

         else
         if(vsblank(&part))
         {
           if(te == ts)
             if(wtyp == '?')
               vscpy(token, part.dat, part.lng, 10);
             else;
           else
             if(wtyp == '?')
               token->lng = 0;
           part.lng = 0;
         }

         else
         {
           vsstripl(&part);
           work.lng = 1;
           work.dat[0] = ' ';
           j = vsindex(&part, &work);
           if(j == -1)
           {
             if(wtyp == '?')
               vscpy(token, part.dat, part.lng, 11);
             part.lng = 0;
           }
           else
           {
             if(wtyp == '?')
               vscpy(token, part.dat, j, 12);
             if((j + 1) < part.lng)
               vscpy(&part, &part.dat[j + 1], part.lng - j - 1, 13);
             else
               part.lng = 0;
           }
         }
       }

       return;
     }

/**********************************************************************/

     misc->retcode   = 0;
     misc->xtokens   = 0;
     misc->xtemplate = 0;
     if(misc->qtemplate != '\'' && misc->qtemplate != '"')
       misc->qtemplate = '\'';
     if(misc->varprefix == ' ')
       misc->varprefix = '?';

     void *vs;
     _TOKEN *token;
     vs = tokens; token = vs;
     for(i = 0; i < misc->ntokens; ++i)
     {
       token->lng = 0;
       vs = vs + lvs; token = vs;
     }

     tstr.lng = 0;
     vscpy(&temp, template->dat, template->lng + 1, 14);
     temp.dat[template->lng] = ' ';

     j = -1;
     for(i = 0; i < temp.lng; ++i)
     {
       if(x) break;
       c = temp.dat[i];

       if(c == misc->qtemplate)
       {
         if(!q)
         {
           q = true;
           j = i;
         }
         else
         {
           if(temp.dat[i + 1] == misc->qtemplate)
             ++i;
           else
             q = false;
         }
       }

       else
       if(c == ' ')
       {
         if(!q)
           if(j > -1)
           {
             l = i - j;
             ttok(j, l);
             if(misc->retcode > 0)
               x = true;
             j = -1;
           }
       }

       else
       if(!q)
         if(j == -1)
           j = i;
     }

     if(misc->retcode > 0)
       return;
     if(q)
     {
       l = temp.lng - 1;
       err('q', l);
       return;
     }

/**********************************************************************/

     sl = string->lng - 1;
     ms = 0;
     me = 0;
     ii = -1;

     for(i = 0; i <= ntt; ++i)
     {
       if(tt[i].typ == 'o')
       {
         ss = ms;
         ts = ii + 1;
         if(tt[i].num >= 0)
           ms = min(sl + 1, ms + tt[i].num);
         else
           ms = max(0, ms + tt[i].num);
         me = ms;
         se = ms;
         te = i - 1;
         words(ss, se, ts, te, 'o');
         ii = i;
       }

       else
       if(tt[i].typ == 'p')
       {
         ss = me;
         ts = ii + 1;
         ms = min(sl + 1, tt[i].num - 1);
         me = ms;
         se = ms;
         te = i - 1;
         words(ss, se, ts, te, 'p');
         ii = i;
       }

       else
       if(tt[i].typ == 's')
       {
         vscpy(&patt, &tstr.dat[tt[i].pos], tt[i].len, 15);
         vscpy(&work, &string->dat[me], sl + 1 - me, 16);
         k = vsindex(&work, &patt);
         if(k >= 0)
         {
           ss = me;
           ts = ii + 1;
           ms = k + me;
           me = ms + tt[i].len;
         }
         else
         {
           ss = me;
           ts = ii + 1;
           ms = sl + 1;
           me = ms;
         }
         se = ms;
         te = i - 1;
         words(ss, se, ts, te, 's');
         ii = i;
       }
     }

     ss = me;
     ts = ii + 1;
     se = sl + 1;
     te = ntt;
     words(ss, se, ts, te, ' ');

/**********************************************************************/

     return;
   }
