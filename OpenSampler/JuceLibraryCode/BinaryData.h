/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   script_png;
    const int            script_pngSize = 4080;

    extern const char*   midi_png;
    const int            midi_pngSize = 14207;

    extern const char*   files_png;
    const int            files_pngSize = 2166;

    extern const char*   piano_png;
    const int            piano_pngSize = 2826;

    extern const char*   internet_png;
    const int            internet_pngSize = 5979;

    extern const char*   list_png;
    const int            list_pngSize = 2555;

    extern const char*   lock_png;
    const int            lock_pngSize = 3261;

    extern const char*   waveform_png;
    const int            waveform_pngSize = 2371;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 8;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
