// roster.h

#define MODID 110
#define NAMELONG "Roster 6.8.0"
#define NAMESHORT "ROSTER"

#define DEFAULT_DEBUG 1

#define BUFLEN 4096

#define DATALEN 3
enum {
    C_READ_VERSION, C_COMPUTE_HASH, C_COPY_PLAYER_DATA,
};
DWORD dtaArray[][DATALEN] = {
    // PES6
    {
        0xb76526, 0xb766ae, 0x860deb,
    },
    // PES6 1.10
    {
        0, 0, 0,
    },
    // WE2007
    {
        0, 0, 0,
    },
};
DWORD dta[DATALEN];

