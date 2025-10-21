
#include "framebuffer.h"


void _log(
    const char* str)
{
    printf("\n\n   ___ %s ___   \n\n", str);
}


bool fbInit(
    int* fbfd, 
    struct fb_fix_screeninfo* finfo, 
    struct fb_var_screeninfo* vinfo)
{
    *fbfd = open ("/dev/fb0", O_RDWR);

    if (*fbfd <= 0) return printf ("failed to open framebuffer \n\n"), false;
    else printf ("fbfd = %i \n\n", *fbfd); // 3

    ioctl (*fbfd, FBIOGET_FSCREENINFO, finfo);
    ioctl (*fbfd, FBIOGET_VSCREENINFO, vinfo);

    return true;
}


void fbClear(
    char* const img, 
    const int Size)
{
    memset (img, 0, Size);
}


void putPixel(
    char* const  img,
    const int    W,  // byte
    const int    X,  // px
    const int    Y,  // px
    const char   b,
    const char   g,
    const char   r )
{
    char* p = img + W*Y + X*4;
    *p++    = b;
    *p++    = g;
    *p++    = r;
    *p      = 0;
}


char wait() 
{
    // TERMinal I/O Settings 
    //
        struct termios oldT, newT;
    //

    // get input
    //
        char ch;
    //

    // terminal -> oldT
    //
        tcgetattr(0, &oldT);
        // stdin - 0
    //

    // then:
    // edit terminal <=> edit newT
    //
        newT = oldT;
        newT.c_lflag &= ~(ICANON | ECHO);
        //  off: Input CANONical, off: ECHO
    //

    // newT -> terminal
    //
        tcsetattr(0, TCSANOW, &newT);
        //  stdin - 0, Terminal Control Set Attributes NOW
    //

    // File Descriptors SET
    //
        fd_set set;
        FD_ZERO(&set);
    //

    // (fd) stdin -> set
    //
        FD_SET(0, &set);
    //

    // wait changes:
    //
        select(1, &set, NULL, NULL, NULL);
        // (num, read, write, except, timeout)
    //

    // read what changed:
    //
        read(0, &ch, 1);
        // (stdin, &ch, 1 byte)
    //

    // undo changes
    //
        tcsetattr(0, TCSANOW, &oldT);
    //

    return ch;
}


// void drawBlinds(
//     char* const  img,
//     const int    W, 
//     const int    w, 
//     const int    h,
//     const int    Size )
// {
//     int i = 0;
//     char col;
//     for (int y = 0; y < h; ++y)
//     for (int x = 0; x < w; ++x)
//     {
//         col = i++ % 256;
//         putPixel(img, W, x, y, col, col, col);
//     }
//     while (true)
//     {
//         for (int j = 0; j < Size; ++j) img[j] += 27;
//         sleep(1);
//     }
// }


#define MAX_RADIUS_2         300
#define MAX_ITERATION_DEPTH  300

void getColor(
    int iteration,
    int maxIterations,
    char col[3])
{

    if (iteration >= maxIterations)
    {
        col[0] &= 0;
        col[1] &= 0;
        col[2] &= 0;
        return;
    }

    const float colorScale = 255.0f / maxIterations;
    const float iterNormalized = iteration * colorScale;

    col[2] = iterNormalized / 4;
    col[0] = iterNormalized;
    col[1] = iterNormalized * 3 + 7;
}

void drawFractal(
    char* const  img,
    const int    W, 
    const int    w, 
    const int    h,
    const int    Size )
{
    char col[3];

    for (int scr_y = 0; scr_y < h; ++scr_y)
    for (int scr_x = 0; scr_x < w; ++scr_x)
    {
        // [0, w] x [0, h] -> [-1, 1] x [-1, 1]
        float c_y = -1.0f + scr_y * (2.0f / h);
        float c_x = -1.0f + scr_x * (2.0f / w);

        float z_x = 0.0f, z_x2 = 0.0f,
                z_y = 0.0f, z_y2 = 0.0f;

        int iterations = 0;

        while (z_x2 + z_y2 < MAX_RADIUS_2 &&
                iterations < MAX_ITERATION_DEPTH) 
        {
            z_y = 2 * z_x * z_y + c_y;
            z_x = z_x2 - z_y2 + c_x;

            z_x2 = z_x * z_x;
            z_y2 = z_y * z_y;

            ++iterations;
        }

        getColor(iterations, 256, col);
        
        putPixel(img, W, scr_x, scr_y, col[0], col[1], col[2]);
    }

    while (true)
    {
        for (int j = 0; j < Size; ++j) img[j] += 27;
        sleep(0.5);
    }
}
