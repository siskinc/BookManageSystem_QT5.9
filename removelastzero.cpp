#include "removelastzero.h"
char * removeLastZero(char const* str)
{
    char * numstr = new char[strlen(str)+1];
    memset(numstr,0x00,sizeof(numstr));
    strcpy(numstr,str);
    if (NULL == strchr(numstr, '.'))
        return numstr;
    int length = strlen(numstr);
    for (int i = length - 1; i > 0; --i) {
        if ('\0' == numstr[i]) {
            continue;
        } else if ('0' == numstr[i]) {
            numstr[i] = '\0';
        } else if ('.' == numstr[i]){ // 小数点之后全为零
            numstr[i] = '\0'; break;
        } else { // 小数点后有非零数字
            break;
        }
    }
    return numstr;
}
