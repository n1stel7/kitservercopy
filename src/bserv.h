// bserv.h

#define MODID 103
#define NAMELONG "Ballserver 6.8.0"
#define NAMESHORT "BSERV"

#define DEFAULT_DEBUG 1

#define BUFLEN 4096

#define CODELEN 1
enum {
    C_SETBALLNAME_CS,
};

static DWORD codeArray[][CODELEN] = {
	// PES6
	{
        0x7834b8,
    },
	// PES6 1.10
	{
        0x783688,
    },
	// WE2007
	{
        0x783538,
    },
};

#define DATALEN 6
enum {
    AFS_PAGELEN_TABLE, NUM_BALL_FILES, NOT_A_BALL_FILE,
    TEAM_IDS, SAVED_TEAM_HOME, SAVED_TEAM_AWAY,
};

static DWORD dtaArray[][DATALEN] = {
	// PES6
	{
	 0x3b5cbc0, 49, 38,
	 0x3be0940, 0x1131fd4, 0x1131fd8,
    },
	// PES6 1.10
	{
	 0x3b5dbc0, 49, 38,
	 0x3be1940, 0x1132fd4, 0x1132fd8,
    },
	// WE2007
	{
	 0x3b57640, 51, 40,
	 0x3bdb3c0, 0x112ca5c, 0x112ca60,
    },
};


static DWORD code[CODELEN];
static DWORD dta[DATALEN];
	

#define SWAPBYTES(dw) \
    (dw<<24 & 0xff000000) | (dw<<8  & 0x00ff0000) | \
    (dw>>8  & 0x0000ff00) | (dw>>24 & 0x000000ff)

#define MAX_ITERATIONS 1000

//#define KeyNextBall 0x42
//#define KeyPrevBall 0x56
//#define KeyResetBall 0x43
//#define KeyRandomBall 0x52
//#define KeyResetBall 0x37
//#define KeyRandomBall 0x38
//#define KeyPrevBall 0x39
//#define KeyNextBall 0x30

typedef struct _BALLS {
	LPTSTR display;
	LPTSTR model;
	LPTSTR texture;
} BALLS;

#ifndef _INFOBLOCK_
#define _INFOBLOCK_
typedef struct _INFOBLOCK {
	BYTE reserved1[0x54];
	DWORD FileID; //0x54
	BYTE reserved2[8];
	DWORD src; //0x60
	DWORD dest; //0x64
} INFOBLOCK;
#endif

typedef struct _DECBUFFERHEADER {
	DWORD dwSig;
	DWORD numTexs;
	DWORD dwDecSize;
	BYTE reserved1[4];
	WORD bitsOffset;
	WORD paletteOffset;
	WORD texWidth;
	WORD texHeight;
	BYTE reserved2[2];
	BYTE bitsPerPixel;
	BYTE reserved3[13];
	WORD blockWidth;
	WORD blockHeight;
	BYTE other[84];
} DECBUFFERHEADER;

typedef struct _PNG_CHUNK_HEADER {
    DWORD dwSize;
    DWORD dwName;
} PNG_CHUNK_HEADER;

typedef struct _BSERV_CFG {
    int selectedBall;
    BOOL previewEnabled;
} BSERV_CFG;

#define BALL_GAME_CHOICE 0
#define BALL_SELECT 1
#define BALL_HOME_TEAM 2

#define HOME 0
#define AWAY 1

