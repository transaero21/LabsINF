#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

void printErrorMsg(const char *, ...);
void printSuccessMsg(const char *msg, ...);
void printMsg(const char *msg, va_list args);
void freeCharPtr(int count, ...);
int getLength(char *str);
void appendString(char *src, int srcSize, const char *dest);

#endif //INCLUDE_UTILS_H
