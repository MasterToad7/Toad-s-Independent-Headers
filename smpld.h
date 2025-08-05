#ifndef SMPLD_H
#define SMPLD_H

/*
SMPLDR is a shortened name for simple loader
which is a independent header file designed to
make loading fies in a project a little less
repetitive

To use this "independent header" simply define TIH_SMPLD_DEFINITIONS
somewhere in the project then include the header

*VERY IMPORTANT* 
Make sure to only define TIH_SMPLD_DEFINITIONS in one c file
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct smpld_file_t
{
    char* filedata;
    size_t filesize;
} smpld_file_t;

smpld_file_t smpld_loadfile(const char* filepath);

#ifdef TIH_SMPLD_DEFINITIONS

smpld_file_t smpld_loadfile(const char* filepath)
{
    smpld_file_t tempFile;

    FILE *fptr;
    fptr = fopen(filepath, "rb");
    fseek(fptr, 0, SEEK_END);
    tempFile.filesize = ftell(fptr);
    rewind(fptr);
    tempFile.filedata = malloc(tempFile.filesize+1);
    if(fptr != NULL)
    {
        fread(tempFile.filedata, 1, tempFile.filesize, fptr);
        tempFile.filedata[tempFile.filesize] = '\0';
        tempFile.filesize += 1;
    } else 
    {
        printf("Cannot open file\n");
    }
    fclose(fptr);

    return tempFile;
}

#endif
#endif