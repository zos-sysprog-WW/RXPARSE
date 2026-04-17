   #ifndef RXPAIF_H
   #define RXPAIF_H

     #ifndef _STRLNG
       #define _STRLNG 100
     #endif

     #ifndef _TEMLNG
       #define _TEMLNG 100
     #endif

     #ifndef _TOKDIM
       #define _TOKDIM 50
     #endif

     #ifndef _TOKLNG
       #define _TOKLNG 100
     #endif

     #define _VARSTR(name,maxlng) \
       struct \
       { \
         short lng; \
         char  dat[maxlng]; \
       } name;

     typedef _VARSTR(_STRING,_STRLNG)

     typedef _VARSTR(_TEMPLATE,_TEMLNG)

     typedef _VARSTR(_TOKEN,_TOKLNG)

     typedef struct
     {
       short ntokens;
       short retcode;
       short xtokens;
       short xtemplate;
       char qtemplate;
       char varprefix;
       short maxlngtok;
     } _MISC;

     extern void rxparse(const _STRING *string,
                         const _TEMPLATE *template,
                         _TOKEN tokens[],
                         _MISC *misc);

   #endif
