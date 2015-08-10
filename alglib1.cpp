#include <openssl/des.h>
#include <string.h>
#include <ctype.h>

const unsigned char SYS_LOGIN[4]="SYS";
const int SYS_LENGTH=3;
const unsigned char SYSTEM_LOGIN[7]="SYSTEM";
const int SYSTEM_LENGTH=6;

char* stoupper( char* s ){
  char* p = s;
  while (*p = toupper( *p )) p++;
  return s;
}

void HashORACLE10gSYS(unsigned char* pPlain, int nPlainLen, unsigned char pHash[8]){
        char ToEncrypt[256];
        char temp[256];
        DES_cblock iv,iv2;
        DES_key_schedule ks1,ks2;
        unsigned char deskey_fixed[]={ 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
        int i,j;
        stoupper ((char*) pPlain);
        memset (ToEncrypt,0,sizeof(ToEncrypt));

        for (i=1,j=0; j<SYS_LENGTH; i++,j++){
                ToEncrypt[i] = SYS_LOGIN[j];
                i++;
        }
        for (j=0; j<nPlainLen; i++,j++){
                ToEncrypt[i] = pPlain[j];
                i++;
        }
        i=i-1;
        memset (iv,0,8);
        memset (iv2,0,8);
        DES_set_key((DES_cblock*) deskey_fixed, &ks1);
        DES_ncbc_encrypt((unsigned char*) ToEncrypt, (unsigned char*) temp, i, &ks1, &iv, DES_ENCRYPT);
        DES_set_key((DES_cblock*) &iv, &ks2);
        DES_ncbc_encrypt((unsigned char*) ToEncrypt, (unsigned char*) temp, i, &ks2, &iv2, DES_ENCRYPT);
        memcpy (pHash,iv2,8);
}

void HashORACLE10gSYSTEM(unsigned char* pPlain, int nPlainLen, unsigned char pHash[8]){
        char ToEncrypt[256];
        char temp[256];
        DES_cblock iv,iv2;
        DES_key_schedule ks1,ks2;
        unsigned char deskey_fixed[]={ 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
        int i,j;
        stoupper ((char*) pPlain);
        memset (ToEncrypt,0,sizeof(ToEncrypt));

        for (i=1,j=0; j<SYSTEM_LENGTH; i++,j++){
                ToEncrypt[i] = SYSTEM_LOGIN[j];
                i++;
        }
        for (j=0; j<nPlainLen; i++,j++){
                ToEncrypt[i] = pPlain[j];
                i++;
        }
        i=i-1;
        memset (iv,0,8);
        memset (iv2,0,8);
        DES_set_key((DES_cblock*) deskey_fixed, &ks1);
        DES_ncbc_encrypt((unsigned char*) ToEncrypt, (unsigned char*) temp, i, &ks1, &iv, DES_ENCRYPT);
        DES_set_key((DES_cblock*) &iv, &ks2);
        DES_ncbc_encrypt((unsigned char*) ToEncrypt, (unsigned char*) temp, i, &ks2, &iv2, DES_ENCRYPT);
        memcpy (pHash,iv2,8);
}

struct OracleEntry {
	const char *szName; // name of the hash algorithm
	void *pHashAlgorithm; // function pointer to the hash algorithm's implementation
	unsigned int uHashLen; // output length of the hash algorithm
	// input plaintext length range supported by the hash algorithm's implementation
	unsigned int uPlaintextLenMin;
	unsigned int uPlaintextLenMax;
};

struct OracleEntry HashAlgorithms[] = { // this symbol is exported
	{"oracle10g-SYS", (void *)HashORACLE10gSYS, 8, 0, 0x000000ff},
	{"oracle10g-SYSTEM", (void *)HashORACLE10gSYSTEM, 8, 0, 0x000000ff},
	{0, 0, 0, 0, 0}, // terminated by an entry of all zeroes
};
