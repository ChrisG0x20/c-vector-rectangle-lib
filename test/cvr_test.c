#include <stdio.h>
#include <stdint.h>
#ifndef _WIN32
#include <wchar.h>
#endif
#include <cvr_vector.h>
#include <cvr_rectangle.h>

#if defined _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4711 ) // Turn off automatic function inlining warnings. This warning is informational only.
#endif

#define BUFFER_LENGTH 1024u

int main(int argc, char *argv[])
{
    char buffer[BUFFER_LENGTH];
    vec2f v1 = vec2f_zero();
    rectf r1 = rectf_zero();

    (void)(argc), (void)(argv); // unreferenced parameters

    vec2f_snprintf(buffer, BUFFER_LENGTH, &v1);
    printf("%s\n", buffer);

    rectf_snprintf(buffer, BUFFER_LENGTH, &r1);
    printf("%s\n", buffer);

    // pause for keypress
    printf("press any key to exit...");
    getchar();

    return 0;
}

#if defined _MSC_VER
#pragma warning( pop ) // 4711
#endif
