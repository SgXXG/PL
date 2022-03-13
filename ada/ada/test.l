%option main
%{
    #include <string.h>

    #define YYSTYPE char*

    #include "main.tab.h"
    int linenumber = 1;
%}

Identifier  [a-zA-Z_][a-zA-Z0-9_]*
EndExpr     [^a-zA-Z0-9_]

%%

\n                                  linenumber++;
[\t ]+                              /* skip */
begin/{EndExpr}                     printf("%s ", "BEG");
end/{EndExpr}                       printf("%s ", "END");
is/{EndExpr}                        printf("%s ", "IS");
procedure/{EndExpr}                 printf("%s ", "PROCEDURE");
with/{EndExpr}                      printf("%s ", "WITH");
use/{EndExpr}                       printf("%s ", "USE");
while/{EndExpr}                     printf("%s ", "WHILE");
loop/{EndExpr}                      printf("%s ", "LOOP");
".."/{EndExpr}                      printf("%s ", "DIAP");
[0-9]+(\.[0-9]+)?/{EndExpr}         printf("%s ", "NUMLIT");
\'([^\']|(\'\'))*\'                 printf("%s ", "STRLIT");
("+"|"-"|"*"|"/"|"("|")"|",")       printf("%s ", "+-*/()");
"<"                                 printf("%s ", "LESS");
">"                                 printf("%s ", "MORE");
"<="                                printf("%s ", "LESSEQUAL");
">="                                printf("%s ", "MOREEQUAL");
"="                                 printf("%s ", "EQUAL");
";"                                 printf("%s ", "SEMICOLON");
":="                                printf("%s ", "ASSIGN");
":"                                 printf("%s ", ":");
{Identifier}(\.{Identifier})*       printf("%s ", "ID");
.                                   printf("%s ", "ERR");

%%
