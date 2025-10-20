
#include "fb_include.h"

void test(const char* str);

bool fbInit(int* fbfd, struct fb_fix_screeninfo* finfo, struct fb_var_screeninfo* vinfo);
void putPixel(char* img, const int W, const int X, const int Y, const char b, const char g, const char r);
char wait();
void fbClear(char* const img, const int Size);

void drawFractal(char* img, const int W, const int w, const int h, const int Size);
