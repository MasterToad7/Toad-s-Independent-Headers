#define TIH_SMPLD_DEFINITIONS
#include <smpld.h>
#include <stdio.h>

int main()
{
    smpld_file_t file = smpld_loadfile("test.txt");
    printf("filedata: %s\nfilesize %d\n", file.filedata, file.filesize);
    return 0;
}