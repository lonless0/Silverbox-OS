#include <ctype.h>
#include <assert.h>

static_assert(isalnum('a'), "'a' is supposed to be an alphanumeric char");
static_assert(isalnum('Z'), "'Z' is supposed to be an alphanumeric char");
static_assert(isalnum('0'), "'0' is supposed to be an alphanumeric char");
static_assert(isalnum('8'), "'8' is supposed to be an alphanumeric char");
static_assert(isalnum('g'), "'g' is supposed to be an alphanumeric char");
static_assert(isalnum('Q'), "'Q' is supposed to be an alphanumeric char");
static_assert(!isalnum('\0'), "'\\0' is not supposed to be an alphanumeric char");
static_assert(!isalnum('\n'), "'\\n' is not supposed to be an alphanumeric char");
static_assert(!isalnum(u'ᴤ'), u"'ᴤ' is not supposed to be an alphanumeric char");
static_assert(!isalnum(' '), "' ' is not supposed to be an alphanumeric char");
static_assert(!isalnum(0x6161), "0x6161 is not supposed to be an alphanumeric char");


static_assert(isalpha('A'), "'A' is supposed to be an alphabetic char");
static_assert(isalpha('m'), "'m' is supposed to be an alphabetic char");
static_assert(isalpha('L'), "'L' is supposed to be an alphabetic char");
static_assert(isalpha('t'), "'t' is supposed to be an alphabetic char");
static_assert(!isalpha('\n'), "'\\n' is not supposed to be an alphabetic char");
static_assert(!isalpha('4'), "'4' is not supposed to be an alphabetic char");
static_assert(!isalpha('~'), "'~' is not supposed to be an alphabetic char");
static_assert(!isalpha('\x19'), "'\\x19' is not supposed to be an alphabetic char");

static_assert(isctrl('\x03'), "'\\x03' is supposed to be a control char");
static_assert(!isctrl('f'), "'f' is not supposed to be a control char");
static_assert(isctrl('\n'), "'\\n' is supposed to be a control char");
static_assert(isctrl('\x7f'), "'\\x7f' is supposed to be a control char");

static_assert(isdigit('4'), "'4' is supposed to be a digit char");
static_assert(isdigit('3'), "'3' is supposed to be a digit char");
static_assert(!isdigit('J'), "'J' is not supposed to be a digit char");
static_assert(!isdigit('\a'), "'\\a' is not supposed to be a digit char");
static_assert(!isdigit(0x381), "'0x0381 is not supposed to be a digit char");

static_assert(islower('b'), "'b' is supposed to be a lowercase char");
static_assert(islower('z'), "'z' is supposed to be a lowercase char");
static_assert(!islower('B'), "'B' is not supposed to be a lowercase char");
static_assert(!islower('M'), "'M' is not supposed to be a lowercase char");
static_assert(!islower('\v'), "'\\v' not is supposed to be a lowercase char");
static_assert(!islower('!'), "'!' is not supposed to be a lowercase char");

static_assert(!isupper('b'), "'b' is not supposed to be an uppercase char");
static_assert(!isupper('z'), "'z' is not supposed to be an uppercase char");
static_assert(isupper('B'), "'B' is supposed to be an uppercase char");
static_assert(isupper('M'), "'M' is supposed to be an uppercase char");
static_assert(!isupper('\v'), "'\\v' not is supposed to be an uppercase char");
static_assert(!isupper('!'), "'!' is not supposed to be an uppercase char");

static_assert(ispunct(','), "',' is supposed to be a punctuation char");
static_assert(ispunct('.'), "'.' is supposed to be a punctuation char");
static_assert(ispunct('+'), "'+' is supposed to be a punctuation char");
static_assert(ispunct('\\'), "'\\' is supposed to be a punctuation char");
static_assert(!ispunct('b'), "'b' is not supposed to be a punctuation char");
static_assert(!ispunct('Q'), "'Q' is not supposed to be a punctuation char");

static_assert(toupper('y') == 'Y', "Expected 'Y'");
static_assert(toupper('b') == 'B', "Expected 'B'");
static_assert(toupper('K') == 'K', "Expected 'K' (no change)");
static_assert(toupper('&') == '&', "Expected '&' (no change)");
static_assert(toupper(0x9102) == 0x9102, "Expected 0x9102 (no change)");

static_assert(tolower('E') == 'e', "Expected 'e'");
static_assert(tolower('P') == 'p', "Expected 'p'");
static_assert(tolower('c') == 'c', "Expected 'c' (no change)");
static_assert(tolower(',') == ',', "Expected ',' (no change)");
static_assert(tolower(0xFFFF) == 0xFFFF, "Expected 0xFFFF (no change)");

static_assert(isprint('b'), "'b' is supposed to be a printable char");
static_assert(isprint(')'), "')' is supposed to be a printable char");
static_assert(isprint('$'), "'$' is supposed to be a printable char");
static_assert(isprint('L'), "'L' is supposed to be a printable char");
static_assert(isprint(' '), "' ' is supposed to be a printable char");
static_assert(!isprint('\n'), "'\\n' is not supposed to be a printable char");
static_assert(!isprint('\r'), "'\\r' is not supposed to be a printable char");
static_assert(!isprint('\0'), "'\\0' is not supposed to be a printable char");
static_assert(!isprint('\x7F'), "'\\x7F' is not supposed to be a printable char");
static_assert(!isprint(0xD3), "'\xD3' is not supposed to be a printable char");

static_assert(isgraph('b'), "'b' is supposed to be a graphic char");
static_assert(isgraph(')'), "')' is supposed to be a graphic char");
static_assert(isgraph('$'), "'$' is supposed to be a graphic char");
static_assert(isgraph('L'), "'L' is supposed to be a graphic char");
static_assert(!isgraph(' '), "' ' is supposed to be a graphic char");
static_assert(!isgraph('\n'), "'\\n' is not supposed to be a graphic char");
static_assert(!isgraph('\r'), "'\\r' is not supposed to be a graphic char");
static_assert(!isgraph('\0'), "'\\0' is not supposed to be a graphic char");
static_assert(!isgraph('\x7F'), "'\\x7F' is not supposed to be a graphic char");
static_assert(!isgraph(0xD3), "'\xD3' is not supposed to be a graphic char");

static_assert(isspace(' '), "' ' is supposed to be a space char");
static_assert(isspace('\n'), "'\\n' is supposed to be a space char");
static_assert(isspace('\v'), "'\\v' is supposed to be a space char");
static_assert(!isspace('\a'), "'\\a' is not supposed to be a space char");
static_assert(isspace('\f'), "'\\f' is supposed to be a space char");
static_assert(isspace('\t'), "'\\t' is supposed to be a space char");
static_assert(!isspace('t'), "'t' is not supposed to be a space char");
static_assert(!isspace('H'), "'H' is not supposed to be a space char");
static_assert(!isspace('*'), "'*' is not supposed to be a space char");
static_assert(!isspace(0x87), "'\x87' is not supposed to be a space char");
static_assert(!isspace('\0'), "'\\0' is not supposed to be a space char");

static_assert(isxdigit('a'), "'a' is supposed to be a hexadecimal digit char");
static_assert(isxdigit('6'), "'6' is supposed to be a hexadecimal digit char");
static_assert(isxdigit('E'), "'E' is supposed to be a hexadecimal digit char");
static_assert(!isxdigit('G'), "'G' is not supposed to be a hexadecimal digit char");
static_assert(!isxdigit('z'), "'z' is not supposed to be a hexadecimal digit char");
static_assert(isxdigit('D'), "'D' is supposed to be a hexadecimal digit char");
static_assert(isxdigit('0'), "'0' is supposed to be a hexadecimal digit char");
static_assert(!isxdigit('\v'), "'\\v' is not supposed to be a hexadecimal digit char");
static_assert(!isxdigit('&'), "'&' is not supposed to be a hexadecimal digit char");
static_assert(!isxdigit(0x99), "'\\x99' is not supposed to be a hexadecimal digit char");
static_assert(!isxdigit(0xFF), "'\\xFF' is not supposed to be a hexadecimal digit char");

int isalnum(int c)
{
  return isalpha(c) || isdigit(c);
}

int isalpha(int c)
{
  return isupper(c) || islower(c);
}

int iscntrl(int c)
{
  return ((c >= 0x00 && c <= 0x1F) || c == 0x7F);
}

int isdigit(int c)
{
  return (c >= '0' && c <= '9');
}

int islower(int c)
{
  return (c >= 'a' && c <= 'z');
}

int isspace(int c)
{
  return (c == 0x20 || (c >= 0x09 && c <= 0x0D));
}

int isupper(int c)
{
  return (c >= 'A' && c <= 'Z');
}

int isxdigit(int c)
{
  return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'F'));
}

int isprint(int c)
{
  return !iscntrl(c);
}

int ispunct(int c)
{
  return ((c >= 0x21 && c <= 0x2F) || (c >= 0x3a && c <= 0x40) ||
          (c >= 0x5b && c <= 0x60) || (c >= 0x7b && c <= 0x7e));
}

int isgraph(int c)
{
  return isprint(c) && c != ' ';
}

int tolower(int c)
{
  return (isupper(c) ? c - ('A' - 'a') : c);
}

int toupper(int c)
{
  return (islower(c) ? c + ('A' - 'a') : c);
}
