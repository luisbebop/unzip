#ifndef _UNZIP_H_
#define _UNZIP_H_

/* includes */
/* specific types for each plataform */
#define Int8	signed char		
#define Uint8	unsigned char	
#define Int16	signed short
#define Uint16	unsigned short
#define Int32	signed int		
#define Uint32	unsigned int	
#define Byte	unsigned char	
#define Word	unsigned short
#define Dword	unsigned int	
#define Bool	char			
#define Const	const
#define true	1
#define false	0

/* utils */
/* setup endianness */
#define HOSTISLITTLEENDIAN

#ifdef HOSTISBIGENDIAN
/* Host is BIG ENDIAN Architecture */
#define _SWAPS(x) 	((unsigned short)( \
						((((unsigned short) x) & 0x000000FF) << 8) | \
						((((unsigned short) x) & 0x0000FF00) >> 8)   \
					))
#define _SWAPI(x) 	((unsigned int)( \
						((((unsigned int) x) & 0x000000FF) << 24) | \
						((((unsigned int) x) & 0x0000FF00) <<  8) | \
						((((unsigned int) x) & 0x00FF0000) >>  8) | \
						((((unsigned int) x) & 0xFF000000) >> 24) \
					))
#else
/* Host is NOT BIG ENDIAN Architecture */
/* Checks for LITTLE ENDIAN define */
#ifndef HOSTISLITTLEENDIAN
#error "You must define HOSTISBIGENDIAN or HOSTISLITTLEENDIAN!"
#endif
#define _SWAPS(x) (((unsigned short) x))
#define _SWAPI(x) (((unsigned int) x))
#endif

#define MAKEWORD(a, b)      ((Word)(((Byte)((a) & 0xff)) | ((Word)((Byte)((b) & 0xff))) << 8))
#define MAKELONG(low,high)	((Int32)(((Word)(low)) | (((Uint32)((Word)(high))) << 16)))
#define LOWORD(l)           ((Word)((l) & 0xffff))
#define HIWORD(l)           ((Word)((l) >> 16))
#define LOBYTE(w)           ((Byte)((w) & 0xff))
#define HIBYTE(w)           ((Byte)((w) >> 8))
#define HH(x)				HIBYTE(HIWORD( x ))
#define HL(x)				LOBYTE(HIWORD( x ))
#define LH(x)				HIBYTE(LOWORD( x ))
#define LL(x)				LOBYTE(LOWORD( x ))
#define LONIBLE(x)			(((Byte)x) & 0x0F )
#define HINIBLE(x)			((((Byte)x) * 0xF0)>>4)

/* unzip functions */

/* specific for each plataform */

/* common */
int UnzipFile(char * filename);
Bool process_headers(void);
Bool process_local_file_header(void);
void process_central_file_header(void);
void process_end_central_dir(void);
void get_string(int len, char * s);
Bool extract_member(void);
Bool InflateBuffer(void);
void ReadByte(int * x);
void OutByte(int c);

#endif //_UNZIP_H_