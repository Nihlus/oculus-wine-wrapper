/*
   HWND to X11 Window ID Remapper for Wine

   (C) 2016 Jarl Gullberg <jarl.gullberg@gmail.com>

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <windows.h>
#include <X11/Xlib.h>
#include <X11/Xresource.h>

////

static const char whole_window_prop[] = "__wine_x11_whole_window";

int main(int argc, char** argv)
{
    // Verify the input argument
    char* endptr;
    long int hwnd = strtol(argv[1], &endptr, 10);
    if (!*argv[1] || *endptr)
    {
        // Invalid input, probably not a number
        return -1;
    }

    // Grab the window property via the HWND and return the X Window ID
    //return (Window)GetPropA( hwnd, whole_window_prop );   
}
