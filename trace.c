
#include <stdio.h>
#include <string.h>
// trace_off() Turns off all tracing messages
//   [by default they are turned on]
// void trace_off(void);

// trace_sync() "Syncronizes" tracing and printf output by
//   forcing all of the tracing messages to go to the same
//   stream as printf (stdout)
//   NOTE: this may cause your Marmoset and I/O tests to fail
// void trace_sync(void);

// trace_version() displays the current version of the cs136 tools library
// void trace_version(void);

/****************************************************************************
  I/O TOOLS
 ****************************************************************************/

// The I/O TOOLS (read_int and read_char) are no longer available
// You should be using scanf now

/****************************************************************************
  SYMBOL TOOLS
****************************************************************************/

// symbols follow the same naming convention as identifiers ("names") in C:
//   * they can only contain letters, underscores and numbers
//   * they must start with a letter
//   * they must be <= 63 characters
// at most there can be 255 symbols defined

// when reading or looking up symbols, they are assigned an int ID

// the constant INVALID_SYMBOL is returned by lookup_symbol & read_symbol when:
// * the next symbol in the input or the parameter is invalid
// * the end of the input (e.g., EOF) is encountered (read_symbol)
// * a new symbol is being defined and 255 symbols have already been defined
extern const int INVALID_SYMBOL;

// read_symbol(void) returns the ID for the next valid symbol from input
//   (which may be a new or existing ID) or INVALID_SYMBOL
// effects: reads from input

// 0 == bye;  1 ==
int read_symbol(void)
{
    char str[10];
    scanf("%s", str);
    // printf("%s",str);
    if (strcmp(str, "bye") == 0)
    {
        // printf("read_symbol return bye \n");
        return 1;
    }
    else if (strcmp(str, "reset")==0)
    {
        // printf("read_symbol return 0\n");
        return 2081;
    }
    else if (strcmp(str, "print")==0)
    {
        // printf("read_symbol return 0\n");
        return 2082;
    }
    else if (strcmp(str, "fill")==0)
    {
        // printf("read_symbol return fill \n");
        return 2083;
    }
    else if (strcmp(str, "erase")==0)
    {
        // printf("read_symbol return 0\n");
        return 2084;
    }
    else if (strcmp(str, "choices")==0)
    {
        // printf("read_symbol return 0\n");
        return 2085;
    }  else if (strcmp(str, "solve")==0)
    {
        // printf("read_symbol return 0\n");
        return 2086;
    } else{
        return INVALID_SYMBOL;
    }

    return INVALID_SYMBOL;
}

// lookup_symbol(symbol_string) returns the ID for symbol_string
//   (which may be a new or existing ID) or INVALID_SYMBOL
int lookup_symbol(const char *symbol_string)
{
    // printf("symbol_string is: %s\n", symbol_string);
    int i = strcmp(symbol_string, "bye");
    // printf("is it true?: %d \n", i);
    if (strcmp(symbol_string, "bye")==0)
    {
        // printf("lookup_symbol return bye\n");
        return 1;
    }
    if (strcmp(symbol_string, "reset")==0)
    {
        // printf("read_symbol return 0\n");
        return 2081;
    }
    if (strcmp(symbol_string, "print")==0)
    {
        // printf("read_symbol return 0\n");
        return 2082;
    }
    if (strcmp(symbol_string, "fill")==0)
    {
        // printf("read_symbol return fill\n");
        return 2083;
    }
    if (strcmp(symbol_string, "erase")==0)
    {
        // printf("read_symbol return 0\n");
        return 2084;
    }
    if (strcmp(symbol_string, "choices")==0)
    {
        // printf("read_symbol return 0\n");
        return 2085;
    }
    if (strcmp(symbol_string, "solve")==0)
    {
        // printf("read_symbol return 0\n");
        return 2086;
    }
    return INVALID_SYMBOL;
}

// print_symbol(symbol_id) displays the symbol corresponding to symbol_id
// requires: symbol_id is a valid ID
// effects: displays a message
void print_symbol(int symbol_id)
{
    switch (symbol_id)
    {
    case 2080:
        printf( "bye");
        break;
    case 2081:
    printf( "reset");
        // return "reset";
        break;
    case 2082:
    printf( "print");
        // return "print";
        break;
    case 2083:
    printf( "fill");
        // return "fill";
        break;
    case 2084:
    printf( "erase");
        // return "erase";
        break;
    case 2085:
    printf( "choices");
        // return "choices";
        break;
    case 2086:
    printf( "else");
        // return "else";
        break;

    default:
    printf( "INVALID");
        // return "INVALID";  
        break;
    }
}

/****************************************************************************
  TRACING MACROS
****************************************************************************/

// The following is a collection of macros that should be ignored
// They are an unfortuante but necessary evil to implement our tracing tools
// They are intentionally obfuscated
// Seriously: Go away... there's nothing to see here...

// #define _FFL __FILE__, __func__, __LINE__
// #define _CCP const char *
// #define _DCLT(ctype, TYPE) void _TRACE_##TYPE(_CCP, ctype, _CCP, _CCP, int);
// #define trace_msg(msg) _TRACE_MSG(#msg, "", _FFL);
// #define trace_int(exp) _TRACE_INT(#exp, (exp), _FFL);
// #define trace_bool(exp) _TRACE_STRING(#exp, (exp) ? "true" : "false", _FFL);
// #define trace_char(exp) _TRACE_CHAR(#exp, (exp), _FFL);
// #define trace_double(exp) _TRACE_DOUBLE(#exp, (exp), _FFL);
// #define trace_string(exp) _TRACE_STRING(#exp, (exp), _FFL);
// #define trace_symbol(exp) _TRACE_SYMBOL(#exp, _SYM(exp), _FFL);
// #define trace_ptr(exp) _TRACE_PTR(#exp, (void *)(exp), _FFL);
// #define trace_array_int(exp, len) _TRACE_ARR("int", #exp, exp, len, _FFL);
// #define trace_array_char(exp, len) _TRACE_ARR("char", #exp, exp, len, _FFL);
// #define trace_array_bool(exp, len) _TRACE_ARR("bool", #exp, exp, len, _FFL);
// #define trace_array_double(exp, len) _TRACE_ARR("double", #exp, exp, len, _FFL);
// #define trace_array_symbol(exp, len) _TRACE_ARR("symbol", #exp, exp, len, _FFL);
// void _TRACE_ARR(_CCP, _CCP, void *, int, _CCP, _CCP, int);
// _CCP _SYM(int);
// _DCLT(_CCP, MSG);
// _DCLT(int, INT);
// _DCLT(char, CHAR);
// _DCLT(double, DOUBLE);
// _DCLT(_CCP, STRING);
// _DCLT(_CCP, SYMBOL);
// _DCLT(void *, PTR);

/*****************************************************************************/
