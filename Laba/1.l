%option main

%{
	#include <stdlib.h>
%}

%%
\%[0-9,A-F]+	printf("%c", (int)strtol(yytext+1, NULL, 16));
%%