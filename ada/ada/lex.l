%option noyywrap
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
begin/{EndExpr}                     return BEG;
end/{EndExpr}                       return END;
is/{EndExpr}                        return IS;
procedure/{EndExpr}                 return PROCEDURE;
with/{EndExpr}                      return WITH;
use/{EndExpr}                       return USE;
while/{EndExpr}                     return WHILE;
loop/{EndExpr}                      return LOOP;
if/{EndExpr}                        return IF;
then/{EndExpr}                      return THEN;
".."                                return DIAP;
[0-9]+(\.[0-9]+)?/({EndExpr}|"..")  return NUMLIT;
\'([^\']|(\'\'))*\'                 return STRLIT;
("+"|"-"|"*"|"/"|"("|")"|",")       return (int)yytext[0];
"<"                                 return LESS;
">"                                 return MORE;
"<="                                return LESSEQUAL;
">="                                return MOREEQUAL;
"="                                 return EQUAL;
";"                                 return SEMICOLON;
":="                                return ASSIGN;
":"                                 return ':';
{Identifier}(\.{Identifier})*       yylval = strdup(yytext); return ID;
.                                   return ERR;

%%
