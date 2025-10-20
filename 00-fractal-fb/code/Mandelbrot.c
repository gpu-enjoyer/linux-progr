
#include "framebuffer.h"

//
//!                *                     ____      ___       ___      ____
//            ____ ))                    \   \    /  |   *   |  \    /   / 
//          ______ )))                   / *  |  |  * \  .  / *  |  |  * \ 
//        _______ )))))  _п_              \_  \   \__ /  .  \ __/   /  _/
//         _____ )))))))  G                  \/_____  \ ___ /  _____\/
//           ___ ))))))) /|\                    \ . \  /   \  / .  /
//           ______||____/_\_                    \  /  \ * /  \  /
//?          \______________/                      \__  \ /  __/
//? ~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~     \ / \ /      ~~  ~~~  ~~
//? ~~  ~~~  ~~~  ~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~   ~~~   ~~  ~~~  ~~~  ~~~
//?  ~   ~~~  ~~~  ~~~  ~~~~  ~~~  ~~  ~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~~  ~~~  ~


int main()
{
    // todo: cpp struct screen {}
    //
        int fbfd = -1;

        struct fb_fix_screeninfo finfo;
        struct fb_var_screeninfo vinfo;

        int Size, size  = 0;
        int    W,    w  = 0;
        int          h  = 0;

        int bytePP = 0;

        char* img;
    //

    if (!fbInit(&fbfd, &finfo, &vinfo)) return -1;


    {
        Size = finfo.smem_len;
        printf ("Size   = %i (byte)     \n", Size);
        size = vinfo.xres * vinfo.yres * (vinfo.bits_per_pixel / 8);

        printf ("size   = %i (byte)   \n\n", size);

        W = finfo.line_length;
        printf ("W      = %i (byte)     \n", W);
        w = vinfo.xres;
        printf ("w      = %i (px)     \n\n", w);

        h = Size / W;
        printf ("h      = %i (px)     \n\n", h);

        bytePP = vinfo.bits_per_pixel / 8;
        printf ("bytePP = %i (byte)   \n\n", bytePP);

        printf ("Size   = W * %i + %i \n\n", h, Size % W);
    }
    
    img = mmap
    (
        /* choose automatically */                     0,
        /* real Size allocated */                      Size,
        /* protected_read || protected_write */        PROT_READ | PROT_WRITE,
        /* share with other ( img <-> /dev/fb0 ) */    MAP_SHARED,
        /* (int) 3 - file descriptor of "/dev/fb0" */  fbfd,
        /* (off_t) file offset */                      (off_t)0
    );

    fbClear(img, Size);

    //
        drawFractal(img, W, w, h, Size);
    //

    close (fbfd);
    return 0;
}
