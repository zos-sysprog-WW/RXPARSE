   dcl string char(strlng) var;
   dcl template char(temlng) var;
   dcl tokens(tokdim) char(toklng) var;
   dcl 1 misc,
         2 ntokens fixed bin(15),
         2 retcode fixed bin(15),
         2 xtokens fixed bin(15),
         2 xtemplate fixed bin(15),
         2 qtemplate char(1),
         2 varprefix char(1),
         2 maxlngtok fixed bin(15);
