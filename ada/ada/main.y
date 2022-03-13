%{
    #include <stdio.h>
    #include <string.h>

    #define YYSTYPE char*

    extern int linenumber;

    int isError = 0;
    int yylex(void);
    void yyerror(const char* s);

    int yydebug = 1;
%}

%right ASSIGN
%token ID
%token WITH USE PROCEDURE IS BEG END DIAP SEMICOLON STRLIT NUMLIT WHILE LOOP IF THEN

%token LESS MORE MOREEQUAL LESSEQUAL EQUAL
%left '+' '-'
%left '*' '/'
%token ERR

%start program

%%

program:            importpart mainpart

importpart:         /* empty */
                |   importpart WITH ID SEMICOLON
                |   importpart USE ID SEMICOLON 
;

mainpart:           /* empty */
                |   mainpart proc
;

proc:               PROCEDURE ID IS procdecl BEG procbody END ID SEMICOLON{
                            if(strcmp($2, $8)){
                                printf("Declaring procedure names in start and end must be identical.\n");
                                YYERROR; 
                            } 
                        }
;

procdecl:           importpart declBlock
;

procbody:           opBlock
;

opBlock:            /* empty */
                |   opBlock stmt
;

stmt:               assignment
                |   WHILE condition LOOP opBlock END LOOP SEMICOLON
                |   IF condition THEN opBlock END IF SEMICOLON
                |   proccall
;   

proccall:           ID SEMICOLON
                |   ID '(' arguments ')' SEMICOLON
;

arguments:          expr
                |   arguments ',' expr
;

declBlock:           /* empty */
                |   declBlock varDecl
;

type:               ID
                |   NUMLIT DIAP NUMLIT
;

varDecl:            ID ':' type SEMICOLON
;

assignment:         ID ASSIGN expr SEMICOLON
;

condition:          expr LESS expr
                |   expr LESSEQUAL expr
                |   expr MORE expr
                |   expr MOREEQUAL expr
                |   expr EQUAL expr
;

expr:               ID
                |   NUMLIT
                |   STRLIT
                |   '(' expr ')'
                |   expr '+' expr
                |   expr '-' expr
                |   expr '*' expr
                |   expr '/' expr
                |   condition
;


%%

int main(void){
    int a = yyparse();
    if(isError){
        printf("Code is not valid.\nLine: %d\n", linenumber);
    }
    else printf("Code is valid.\n");

    return 0;
}

void yyerror(const char* s){
    isError = 1;
    printf("%s\n", s);
}
